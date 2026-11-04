
undefined4 FUN_00570070(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    DAT_00b22d90 = param_1;
    return 0;
  }
  DAT_00b22d90 = 1;
  uVar1 = FUN_0056d0a0(param_1);
  if (uVar1 < 0xd) {
    FUN_0056cee0(&DAT_00b22d94,param_1);
    return 0;
  }
  FUN_0056d420(&DAT_00b22d94,param_1,0xc);
  DAT_00b22da0 = 0;
  return 0;
}

