
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005dd710(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00519300(DAT_00a38120,0);
  if ((DAT_00ca39f4 != 0) && (DAT_00f3a154 != 0)) {
    _DAT_00f3a164 = DAT_00f3a154;
    if (iVar1 == 0) {
      DAT_00f3a168 = DAT_00ddb5c4;
      if (DAT_00ddb5c4 == 0) {
        DAT_00f3a168 = DAT_00ddb5b4;
      }
    }
    else {
      DAT_00f3a168 = *(int *)(*(int *)(*(int *)(iVar1 + 0x4c) + 0x3c) + 4 + DAT_00a38140 * 4);
    }
    FUN_005d3850(DAT_00f3a168,param_1,DAT_00f3a154,param_1,0);
  }
  return 0;
}

