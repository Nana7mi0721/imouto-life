
void FUN_00515110(int param_1)

{
  int *in_EAX;
  
  if (*in_EAX != 0) {
    FUN_005421c0(in_EAX + 2);
    FUN_005421c0(in_EAX + 0x112);
    return;
  }
  if (*(int *)(param_1 + 0x188) == 1) {
    FUN_00541150(in_EAX[0x222]);
    if (in_EAX[0x223] != 0) {
      FUN_00541150(in_EAX[0x223]);
    }
  }
  return;
}

