
undefined4 FUN_0056f750(int *param_1)

{
  int iVar1;
  
  if ((param_1[0xf] == 0) && (param_1[0x10] == 0)) {
    return 0;
  }
  if (param_1[0x221] == 1) {
    iVar1 = FUN_0056ef10(param_1);
    while (iVar1 == 0) {
      FUN_0056da20(0);
      iVar1 = FUN_0056ef10(param_1);
    }
  }
  if (param_1[0x219] == 1) {
    if (param_1[0x21a] == 1) {
      if (param_1[0x21e] == 0) {
        if (param_1[0x21f] == 0) {
          if (*param_1 == 0) {
            FUN_0056e7c0(param_1,param_1[0x13]);
            FUN_0056e590(param_1[3],0,0,0,param_1 + 0x216);
            FUN_0056d380(param_1,0,0x890);
            return 0;
          }
          if (*(ushort *)((int)param_1 + 10) < 5) {
            FUN_0056e590(param_1[0x21c],param_1[0x21d],0,0,param_1 + 0x216);
            FUN_0056d380(param_1,0,0x890);
            return 0;
          }
          FUN_0056e8a0(param_1,param_1[0x13]);
          FUN_0056e590(param_1[3],0,0,0,param_1 + 0x216);
          FUN_0056d380(param_1,0,0x890);
          return 0;
        }
        if (param_1[0x11] != 0) {
          FUN_0056e1d0(param_1[0x11]);
          param_1[0x11] = 0;
          FUN_0056d380(param_1,0,0x890);
          return 0;
        }
      }
      else if (param_1[0x10] != 0) {
        FUN_0056e1d0(param_1[0x10]);
        param_1[0x10] = 0;
        FUN_0056d380(param_1,0,0x890);
        return 0;
      }
      goto LAB_0056f8fa;
    }
    FUN_0056e1d0(param_1[0x11]);
    iVar1 = param_1[0x10];
  }
  else {
    FUN_0052dbe0(param_1[0xf]);
    iVar1 = param_1[0x11];
  }
  FUN_0056e1d0(iVar1);
LAB_0056f8fa:
  FUN_0056d380(param_1,0,0x890);
  return 0;
}

