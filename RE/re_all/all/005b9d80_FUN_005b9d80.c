
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b9d80(undefined4 *param_1)

{
  int iVar1;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  iVar1 = FUN_0056d3d0(param_1,&DAT_00f07378,0x10);
  if ((iVar1 != 0) || (DAT_00ef7324 != 0)) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    _DAT_00f07378 = *param_1;
    _DAT_00f0737c = param_1[1];
    _DAT_00f07380 = param_1[2];
    _DAT_00f07384 = param_1[3];
    FUN_005b96d0();
    DAT_00ef72cc = 1;
  }
  return 0;
}

