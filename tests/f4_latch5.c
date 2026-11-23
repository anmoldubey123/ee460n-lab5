/* F4 unit test: LD.VA, plus one full translation (6 -> 57 -> 60 -> 62 -> 61 -> 63 -> 25) cycle by cycle.
   Run from the lab folder. */
#define main sim_main
#include "../lc3bsim5.c"
#undef main

int fails = 0;
void expect(const char *what, int got, int want) {
  if (got != want) { printf("FAIL %-34s got x%04X want x%04X\n", what, got, want); fails++; }
  else             printf("PASS %-34s = x%04X\n", what, got);
}
/* one full cycle: the same calls, in the same order, as cycle() */
void step(void) {
  eval_micro_sequencer(); cycle_memory(); eval_bus_drivers(); drive_bus(); latch_datapath_values();
  CURRENT_LATCHES = NEXT_LATCHES;
}

int main(void) {
  int i;
  init_control_store("ucode5");
  init_memory();
  CURRENT_LATCHES.PTBR = 0x1000;  CURRENT_LATCHES.PSR15 = 1;
  MEMORY[0x10C0 >> 1][0] = 0x0C;  MEMORY[0x10C0 >> 1][1] = 0x38;   /* PTE page 96 = x380C (frame 28, P=1, V=1) */
  MEMORY[0x3814 >> 1][0] = 0x34;  MEMORY[0x3814 >> 1][1] = 0x12;   /* data at PA x3814 = x1234 */
  CURRENT_LATCHES.IR = 0x6202;    CURRENT_LATCHES.REGS[0] = 0xC010; /* LDW R1, R0, #2 */
  CURRENT_LATCHES.VA = 0x0000;    CYCLE_COUNT = 1000;               /* keep the timer away */

  /* state 6 */
  CURRENT_LATCHES.STATE_NUMBER = 6;
  memcpy(CURRENT_LATCHES.MICROINSTRUCTION, CONTROL_STORE[6], sizeof(int) * CONTROL_STORE_BITS);
  NEXT_LATCHES = CURRENT_LATCHES;
  step();
  expect("after 6: VA", CURRENT_LATCHES.VA, 0xC014);
  expect("after 6: MAR", CURRENT_LATCHES.MAR, 0xC014);
  expect("after 6: RET", CURRENT_LATCHES.RET, 25);
  expect("after 6: state", CURRENT_LATCHES.STATE_NUMBER, 57);
  step();                                            /* 57 */
  expect("after 57: MAR (PTE address)", CURRENT_LATCHES.MAR, 0x10C0);
  expect("after 57: VA unchanged", CURRENT_LATCHES.VA, 0xC014);
  for (i = 0; i < 5; i++) step();                    /* 60 x5 */
  expect("after 60: MDR (PTE)", CURRENT_LATCHES.MDR, 0x380C);
  expect("after 60: state", CURRENT_LATCHES.STATE_NUMBER, 62);
  step();                                            /* 62 */
  expect("after 62: MDR (PTE | R)", CURRENT_LATCHES.MDR, 0x380D);
  for (i = 0; i < 5; i++) step();                    /* 61 x5 */
  expect("after 61: M[x10C0] written back", (MEMORY[0x10C0 >> 1][1] << 8) | MEMORY[0x10C0 >> 1][0], 0x380D);
  expect("after 61: state", CURRENT_LATCHES.STATE_NUMBER, 63);
  step();                                            /* 63 */
  expect("after 63: MAR (physical)", CURRENT_LATCHES.MAR, 0x3814);
  expect("after 63: state (RET)", CURRENT_LATCHES.STATE_NUMBER, 25);
  for (i = 0; i < 5; i++) step();                    /* 25 x5 */
  step();                                            /* 27 */
  expect("after 27: R1 loaded from x3814", CURRENT_LATCHES.REGS[1], 0x1234);
  expect("after 27: state", CURRENT_LATCHES.STATE_NUMBER, 18);

  printf("%s: %d failure(s)\n", fails ? "F4 FAILED" : "F4 ALL PASS", fails);
  return fails;
}
