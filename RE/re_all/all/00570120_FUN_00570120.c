
undefined4 FUN_00570120(int *param_1)

{
  int *piVar1;
  
  if (*param_1 == 0) {
    FUN_0052de00(param_1[2]);
    FUN_0056e1d0(param_1);
    return 0;
  }
  FUN_0056e1d0(param_1[2]);
  piVar1 = (int *)(&DAT_00afed08)[param_1[1]];
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    *piVar1 = *piVar1 + -1;
  }
  FUN_0056e1d0(param_1);
  return 0;
}

