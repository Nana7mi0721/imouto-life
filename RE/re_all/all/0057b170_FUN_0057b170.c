
undefined4 FUN_0057b170(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  
  if (DAT_00ca39e8 != 0) {
    if (DAT_00ca39f4 != 0) {
      FUN_0057ae10(DAT_00a38194,DAT_00a38198,DAT_00a3819c,DAT_00a381a0);
    }
    DAT_00ca39e8 = 0;
  }
  DAT_00ca39f8 = DAT_00ca39f8 + 1;
  if (DAT_00ca39f8 == 1) {
    FUN_00514e10(&param_1,&DAT_00a38194);
    if (DAT_00a37d78 != 0) {
      FUN_005d9170(&param_1);
      return 0;
    }
    iVar1 = FUN_00519300(DAT_00a38120,0);
    if (DAT_00ca39f4 != 0) {
      if (iVar1 == 0) {
        puVar2 = &DAT_00a37df8;
      }
      else {
        puVar2 = (undefined *)(iVar1 + 0x88);
      }
      FUN_005812b0(&DAT_00ca3a00,puVar2,&param_1,param_1,param_2);
    }
  }
  return 0;
}

