/* F3 unit test: translation unit (TRANS_OUT) and GateTRANS in drive_bus(). Run from the lab folder. */
#define main sim_main
#include "../lc3bsim5.c"
#undef main

int fails = 0;
void check(int n, const char *what, int state, int va, int mdr, int ret, int want_bus) {
  memcpy(CURRENT_LATCHES.MICROINSTRUCTION, CONTROL_STORE[state], sizeof(int) * CONTROL_STORE_BITS);
  CURRENT_LATCHES.PTBR = 0x1000;  CURRENT_LATCHES.VA = va;  CURRENT_LATCHES.MDR = mdr;
  CURRENT_LATCHES.RET = ret;      CURRENT_LATCHES.PC = 0x3000;  CURRENT_LATCHES.IR = 0;
  eval_bus_drivers();
  drive_bus();
  if (BUS == want_bus) printf("PASS %2d %-38s BUS=x%04X\n", n, what, BUS);
  else { printf("FAIL %2d %-38s got BUS=x%04X want x%04X\n", n, what, BUS, want_bus); fails++; }
}

int main(void) {
  init_control_store("ucode5");
  /*     n  case                                    state VA      MDR     RET  BUS */
  check( 1, "57 PTE addr, VA xC014 (page 96)",        57, 0xC014, 0x0000, 23, 0x10C0);
  check( 2, "57 PTE addr, VA x3006 (page 24)",        57, 0x3006, 0x0000, 33, 0x1030);
  check( 3, "57 PTE addr, VA xFE00 (page 127)",       57, 0xFE00, 0x0000, 25, 0x10FE);
  check( 4, "57 PTE addr, VA x0052 (page 0)",         57, 0x0052, 0x0000, 33, 0x1000);
  check( 5, "62 update, STW -> R and M",              62, 0xC014, 0x380C, 23, 0x380F);
  check( 6, "62 update, STB -> R and M",              62, 0xC015, 0x380C, 24, 0x380F);
  check( 7, "62 update, LDW -> R only",               62, 0xC014, 0x380C, 25, 0x380D);
  check( 8, "62 update, LDB -> R only",               62, 0xC014, 0x380C, 29, 0x380D);
  check( 9, "62 update, fetch -> R only",             62, 0x3006, 0x320C, 33, 0x320D);
  check(10, "62 update, R/M already set -> same",     62, 0xC014, 0x380F, 25, 0x380F);
  check(11, "63 PA, frame 28 + x014",                 63, 0xC014, 0x380F, 23, 0x3814);
  check(12, "63 PA, frame 25 + x006",                 63, 0x3006, 0x320D, 33, 0x3206);
  check(13, "63 PA, frame 29 + x1FE",                 63, 0xFDFE, 0x3A0D, 25, 0x3BFE);
  check(14, "18 GatePC still works",                  18, 0x0000, 0x0000,  0, 0x3000);
  printf("%s: %d failure(s)\n", fails ? "F3 FAILED" : "F3 ALL PASS", fails);
  return fails;
}
