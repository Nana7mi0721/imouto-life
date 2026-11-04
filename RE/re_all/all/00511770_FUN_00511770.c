
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00511770(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_0056bb10(&DAT_007d4dec);
  if (param_1 != DAT_00a20c40) {
    DAT_00a2d7f8 = 1;
    _DAT_00a2106c = 0;
    iVar1 = FUN_0050ea40(param_1);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    if ((DAT_00a20bec != 0) && (DAT_00a20c10 != 1)) {
      DAT_00a20c44 = 1;
      FUN_00511210(1);
      uVar2 = FUN_0052bfa0(0xffffffff,0xffffffff,0xffffffff,1,0xffffffff);
      DAT_00a20c44 = 0;
      if (param_1 == 0) {
        DAT_00a24d7c = param_1;
        return uVar2;
      }
      DAT_00a20c44 = 0;
      return uVar2;
    }
  }
  return 0;
}

