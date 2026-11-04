
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00519580(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = FUN_00543f70(0xff,0xff,0xff);
  uVar3 = _DAT_00a38114;
  uVar1 = DAT_00a380d0;
  if (_DAT_00a38114 != 0xffffff) {
    _DAT_00a38114 = 0xffffff;
    if (DAT_00a37d78 == 0) {
      FUN_00581200(0xffffff);
    }
    else {
      FUN_00567b70();
    }
  }
  FUN_005160d0(3,0xff);
  FUN_00568ff0(*param_1,param_1[1],param_1[2],param_1[3],uVar2);
  uVar3 = uVar3 & 0xffffff;
  if (_DAT_00a38114 != uVar3) {
    _DAT_00a38114 = uVar3;
    if (DAT_00a37d78 != 0) {
      FUN_00567b70();
      FUN_005160d0(5,uVar1);
      return;
    }
    FUN_00581200(uVar3);
  }
  FUN_005160d0(5,uVar1);
  return;
}

