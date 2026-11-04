
void FUN_00581400(int *param_1)

{
  int *piVar1;
  
  if (*param_1 == 0x12345678) {
    *(int *)param_1[5] = *(int *)param_1[5] + -1;
    piVar1 = (int *)param_1[5];
    if (*piVar1 == 0) {
      if ((piVar1[0xe] == 0) && (piVar1[0x11] != 0)) {
        FUN_0056e1d0(piVar1[0x11]);
      }
      piVar1[0x11] = 0;
      if (piVar1[0x12] != 0) {
        FUN_0056e1d0(piVar1[0x12]);
      }
      piVar1[0x12] = 0;
      if (piVar1[0x13] != 0) {
        FUN_0056e1d0(piVar1[0x13]);
      }
      piVar1[0x13] = 0;
      if (piVar1[0xf] != 0) {
        FUN_0056e1d0(piVar1[0xf]);
      }
      piVar1[0xf] = 0;
      piVar1[0x10] = 0;
      FUN_0056e1d0(piVar1);
    }
    param_1[5] = 0;
    *param_1 = 0;
  }
  return;
}

