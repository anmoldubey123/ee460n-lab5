/* F2 unit test: eval_micro_sequencer() CALL / RETURN. Run from the lab folder. */
#define main sim_main
#include "../lc3bsim5.c"
#undef main

int fails = 0;
/* run the sequencer for one state with the given latches; RET in NEXT starts at sentinel 99 */
void check(int n, const char *what, int state, int ir, int intr, int ready, int cur_ret,
           int va, int psr15, int mdr, int want_next, int want_ret) {
  memcpy(CURRENT_LATCHES.MICROINSTRUCTION, CONTROL_STORE[state], sizeof(int) * CONTROL_STORE_BITS);
  CURRENT_LATCHES.IR = ir;  CURRENT_LATCHES.INT = intr;  CURRENT_LATCHES.READY = ready;
  CURRENT_LATCHES.RET = cur_ret;  CURRENT_LATCHES.VA = va;  CURRENT_LATCHES.PSR15 = psr15;
  CURRENT_LATCHES.MDR = mdr;  CURRENT_LATCHES.BEN = 0;
  NEXT_LATCHES = CURRENT_LATCHES;  NEXT_LATCHES.RET = 99;
  CYCLE_COUNT = 0;
  eval_micro_sequencer();
  if (NEXT_LATCHES.STATE_NUMBER == want_next && NEXT_LATCHES.RET == want_ret)
    printf("PASS %2d %-36s next=%2d RET=%2d\n", n, what, NEXT_LATCHES.STATE_NUMBER, NEXT_LATCHES.RET);
  else { printf("FAIL %2d %-36s got next=%2d RET=%2d, want next=%2d RET=%2d\n", n, what,
                NEXT_LATCHES.STATE_NUMBER, NEXT_LATCHES.RET, want_next, want_ret); fails++; }
}

int main(void) {
  init_control_store("ucode5");
  /*     n  case                                  state IR   INT RDY curRET VA     PSR15 MDR     next RET(99=unchanged) */
  check( 1, "18 fetch, INT=0 -> CALL",               18, 0,     0, 0,  0, 0x0000, 1, 0x0000, 57, 33);
  check( 2, "18 fetch, INT=1 -> 41, no CALL",        18, 0,     1, 0,  0, 0x0000, 1, 0x0000, 41, 99);
  check( 3, "19 fetch, INT=0 -> CALL",               19, 0,     0, 0,  0, 0x0000, 1, 0x0000, 57, 33);
  check( 4, "2 LDB -> CALL, RET 29",                  2, 0x2000,0, 0,  0, 0x0000, 1, 0x0000, 57, 29);
  check( 5, "3 STB -> CALL, RET 24",                  3, 0x3000,0, 0,  0, 0x0000, 1, 0x0000, 57, 24);
  check( 6, "6 LDW -> CALL, RET 25",                  6, 0x6000,0, 0,  0, 0x0000, 1, 0x0000, 57, 25);
  check( 7, "7 STW -> CALL, RET 23",                  7, 0x7000,0, 0,  0, 0x0000, 1, 0x0000, 57, 23);
  check( 8, "15 TRAP -> CALL, RET 28",               15, 0xF025,0, 0,  0, 0x0000, 1, 0x0000, 57, 28);
  check( 9, "57 no exception -> 60",                 57, 0,     0, 0, 33, 0x3000, 1, 0x0000, 60, 99);
  check(10, "60 R=0 -> 60 (wait)",                   60, 0,     0, 0, 33, 0x3000, 1, 0x0000, 60, 99);
  check(11, "60 R=1 -> 62",                          60, 0,     0, 1, 33, 0x3000, 1, 0x0000, 62, 99);
  check(12, "62 valid user page -> 61",              62, 0,     0, 0, 33, 0x3000, 1, 0x320C, 61, 99);
  check(13, "61 R=1 -> 63",                          61, 0,     0, 1, 33, 0x3000, 1, 0x320C, 63, 99);
  check(14, "63 RETURN, RET=25 -> 25",               63, 0,     0, 0, 25, 0x3000, 1, 0x320C, 25, 99);
  check(15, "63 RETURN, RET=33 -> 33",               63, 0,     0, 0, 33, 0x3000, 1, 0x320C, 33, 99);
  check(16, "57 unaligned LDW -> 42",                57, 0x6000,0, 0, 25, 0xC001, 1, 0x0000, 42, 99);
  check(17, "62 user fetch of system page -> 42",    62, 0,     0, 0, 33, 0x0052, 1, 0x0004, 42, 99);
  check(18, "35 IR<-MDR -> 32 (no CALL)",            35, 0,     0, 0,  0, 0x0000, 1, 0x0000, 32, 99);
  check(19, "32 decode LDW -> 6",                    32, 0x6000,0, 0,  0, 0x0000, 1, 0x0000,  6, 99);
  printf("%s: %d failure(s)\n", fails ? "F2 FAILED" : "F2 ALL PASS", fails);
  return fails;
}
