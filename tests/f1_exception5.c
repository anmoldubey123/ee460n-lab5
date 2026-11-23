/* F1 unit test: eval_exception() with EXCMODE, access decoder and PTE checks. Run from the lab folder. */
#define main sim_main
#include "../lc3bsim5.c"
#undef main

int fails = 0;
void check(int n, const char *what, int state, int ir, int ret, int va, int psr15, int mdr, int want_exc, int want_vec) {
  memcpy(CURRENT_LATCHES.MICROINSTRUCTION, CONTROL_STORE[state], sizeof(int) * CONTROL_STORE_BITS);
  CURRENT_LATCHES.IR = ir;  CURRENT_LATCHES.RET = ret;  CURRENT_LATCHES.VA = va;
  CURRENT_LATCHES.PSR15 = psr15;  CURRENT_LATCHES.MDR = mdr;
  eval_exception();
  if (EXC == want_exc && EXC_VECTOR == want_vec)
    printf("PASS %2d %-40s EXC=%d vec=x%02X\n", n, what, EXC, EXC_VECTOR);
  else { printf("FAIL %2d %-40s got EXC=%d vec=x%02X, want EXC=%d vec=x%02X\n", n, what, EXC, EXC_VECTOR, want_exc, want_vec); fails++; }
}

int main(void) {
  init_control_store("ucode5");
  /*     n  case                                      state  IR      RET VA      PSR15 MDR(PTE) EXC vec */
  check( 1, "10: opcode 1010 -> unknown",               10, 0xA000,  0, 0x0000, 1, 0x0000, 1, 0x05);
  check( 2, "11: opcode 1011 -> unknown",               11, 0xB000,  0, 0x0000, 1, 0x0000, 1, 0x05);
  check( 3, "57: LDW xC001 -> unaligned",               57, 0x6400, 25, 0xC001, 1, 0x0000, 1, 0x03);
  check( 4, "57: STW xC015 -> unaligned",               57, 0x7200, 23, 0xC015, 1, 0x0000, 1, 0x03);
  check( 5, "57: LDB xC001 (byte) -> none",             57, 0x2400, 29, 0xC001, 1, 0x0000, 0, 0x00);
  check( 6, "57: fetch x0053 -> none (fetch unchecked)",57, 0x6400, 33, 0x0053, 1, 0x0000, 0, 0x00);
  check( 7, "57: handler fetch, IR still 1010 -> none", 57, 0xA000, 33, 0x1C00, 0, 0x0000, 0, 0x00);
  check( 8, "62: user fetch x0052, P=0 -> protection",  62, 0xC140, 33, 0x0052, 1, 0x0004, 1, 0x04);
  check( 9, "62: user TRAP vector read -> none",        62, 0xF025, 28, 0x004A, 1, 0x0004, 0, 0x00);
  check(10, "62: supervisor, P=0 -> none",              62, 0x6400, 25, 0x1000, 0, 0x1004, 0, 0x00);
  check(11, "62: user, P=1 V=0 -> page fault",          62, 0x6400, 25, 0x4000, 1, 0x0008, 1, 0x02);
  check(12, "62: user, P=0 V=0 -> protection wins",     62, 0x6400, 25, 0x4000, 1, 0x0000, 1, 0x04);
  check(13, "62: user, valid user page -> none",        62, 0x6400, 25, 0xC014, 1, 0x380C, 0, 0x00);
  check(14, "62: supervisor, V=0 -> page fault",        62, 0x6400, 25, 0x4000, 0, 0x0008, 1, 0x02);
  check(15, "25: EXCMODE 0, bad inputs -> none",        25, 0xA000, 25, 0xC001, 1, 0x0000, 0, 0x00);
  printf("%s: %d failure(s)\n", fails ? "F1 FAILED" : "F1 ALL PASS", fails);
  return fails;
}
