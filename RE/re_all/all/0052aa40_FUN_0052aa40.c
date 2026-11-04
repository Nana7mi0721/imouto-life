
undefined4 FUN_0052aa40(int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 < 0) || (DAT_00a37da8 <= param_1)) {
    return 0xffffffff;
  }
  if (((param_1 == 0) && (param_3 == 0)) && (param_4 == 0)) {
    uVar1 = FUN_0052a4a0(param_2);
    return uVar1;
  }
  if (DAT_00a37d78 != 0) {
    uVar1 = (&DAT_00a38120)[param_1];
    (&DAT_00a38120)[param_1] = param_2;
    (&DAT_00a38140)[param_1] = param_3;
    (&DAT_00a38160)[param_1] = param_4;
    if (param_1 == 0) {
      FUN_00515880(param_2,&DAT_00a381b4,&DAT_00a381b8);
      if (0 < param_4) {
        FUN_005185c0(DAT_00a381b4,DAT_00a381b8,param_4,&DAT_00a381b4,&DAT_00a381b8);
      }
    }
    FUN_00567d60();
    iVar2 = FUN_00567b50(param_1,param_2,param_3,param_4);
    if (-1 < iVar2) {
      if (param_1 == 0) {
        FUN_00529ed0(uVar1);
      }
      return 0;
    }
  }
  return 0xffffffff;
}

