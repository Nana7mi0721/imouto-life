
int FUN_006093a0(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_00607d40(param_1,param_2,param_3);
  if (-1 < iVar1) {
    iVar1 = *(int *)(param_1 + 0x58);
    piVar2 = (int *)(iVar1 + 0xec);
    if (param_2[2] != *(int *)(iVar1 + 0xf4)) {
      return -0x7ffbfdf2;
    }
    if (param_2[3] != *(int *)(iVar1 + 0xf8)) {
      return -0x7fffbffb;
    }
    if (*(int *)(iVar1 + 0xf0) < param_2[1]) {
      return -0x7fffbffb;
    }
    if (*piVar2 < *param_2) {
      return -0x7fffbffb;
    }
    *param_3 = *piVar2;
    param_3[1] = *(int *)(iVar1 + 0xf0);
    param_3[2] = *(int *)(iVar1 + 0xf4);
    param_3[3] = *(int *)(iVar1 + 0xf8);
    *(int *)(param_1 + 0x2c) = *piVar2;
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(iVar1 + 0xf0);
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(iVar1 + 0xf4);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(iVar1 + 0xf8);
    iVar1 = 0;
  }
  return iVar1;
}

