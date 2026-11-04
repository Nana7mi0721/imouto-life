
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005de570(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00519300(DAT_00a38120,0);
  if ((DAT_00ca39f4 != 0) && (DAT_00f3a188 != 0)) {
    if (iVar1 == 0) {
      if (DAT_00ef1b58 == 0) {
        DAT_00f3a1b0 = DAT_00ee9bc4;
        DAT_00f3a1a8 = DAT_00ee9b90;
        _DAT_00f3a1ac = DAT_00ee9bc0;
      }
      else {
        DAT_00f3a1b0 = DAT_00ef1b5c;
        DAT_00f3a1a8 = DAT_00ef1b58;
        _DAT_00f3a1ac = DAT_00ef1b60;
      }
    }
    else {
      DAT_00f3a1a8 = *(int *)(**(int **)(iVar1 + 0x100) + 4);
      _DAT_00f3a1ac = *(undefined4 *)(**(int **)(iVar1 + 0x100) + 8);
      DAT_00f3a1b0 = *(undefined4 *)(*(int *)(**(int **)(iVar1 + 0x100) + 0xc) + DAT_00a38140 * 4);
    }
    FUN_005caf30(DAT_00f3a1a8,_DAT_00f3a1ac,param_1,DAT_00f3a188,DAT_00f3a190,param_1,0,0,0,0,0,0,0,
                 0);
  }
  return 0;
}

