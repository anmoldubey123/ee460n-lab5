/* C1 unit test: Lab 5 control bits, getters and the RET latch. Run from the lab folder. */
#define main sim_main
#include "../lc3bsim5.c"
#undef main

int fails = 0;
void expect(const char *what, int got, int want) {
  if (got != want) { printf("FAIL %-28s got %d want %d\n", what, got, want); fails++; }
  else             printf("PASS %-28s = %d\n", what, got);
}

int main(void) {
  int *r;
  init_control_store("ucode5");
  expect("CONTROL_STORE_BITS", CONTROL_STORE_BITS, 56);

  r = CONTROL_STORE[57];
  expect("57 EXCMODE", GetEXCMODE(r), 2);  expect("57 TRMUX", GetTRMUX(r), 0);
  expect("57 GATE_TRANS", GetGATE_TRANS(r), 1);  expect("57 J", GetJ(r), 60);
  r = CONTROL_STORE[62];
  expect("62 EXCMODE", GetEXCMODE(r), 3);  expect("62 TRMUX", GetTRMUX(r), 1);
  expect("62 GATE_TRANS", GetGATE_TRANS(r), 1);  expect("62 J", GetJ(r), 61);
  r = CONTROL_STORE[63];
  expect("63 COND3", GetCOND3(r), 6);  expect("63 TRMUX", GetTRMUX(r), 2);
  expect("63 GATE_TRANS", GetGATE_TRANS(r), 1);
  r = CONTROL_STORE[18];
  expect("18 LD_VA", GetLD_VA(r), 1);  expect("18 CALL", GetCALL(r), 1);
  expect("18 COND3", GetCOND3(r), 4);  expect("18 J", GetJ(r), 33);
  r = CONTROL_STORE[6];
  expect("6 LD_VA", GetLD_VA(r), 1);  expect("6 CALL", GetCALL(r), 1);  expect("6 J", GetJ(r), 25);
  r = CONTROL_STORE[10];
  expect("10 EXCMODE", GetEXCMODE(r), 1);
  r = CONTROL_STORE[25];
  expect("25 EXCMODE", GetEXCMODE(r), 0);

  CURRENT_LATCHES.RET = 25;
  expect("RET latch holds a value", CURRENT_LATCHES.RET, 25);

  printf("%s: %d failure(s)\n", fails ? "C1 FAILED" : "C1 ALL PASS", fails);
  return fails;
}
