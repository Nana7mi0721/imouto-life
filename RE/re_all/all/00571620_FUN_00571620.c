
undefined4 FUN_00571620(int *param_1)

{
  int iVar1;
  
  if ((param_1[8] == 1) && (param_1[9] != 0)) {
    iVar1 = FUN_00571330(param_1);
    while (iVar1 == 0) {
      FUN_0056da20(1);
      iVar1 = FUN_00571330(param_1);
    }
  }
  if (param_1[2] != 0) {
    FUN_0056e1d0(param_1[2]);
    param_1[2] = 0;
  }
  if (param_1[3] != 0) {
    FUN_0056e1d0(param_1[3]);
    param_1[3] = 0;
  }
  if (*(int *)(*param_1 + 0x864) == 0) {
    FUN_0052dbe0(param_1[4]);
    param_1[4] = 0;
  }
  FUN_0056d380(param_1,0,0x40);
  return 0;
}

