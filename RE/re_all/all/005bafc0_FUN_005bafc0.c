
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005bafc0(float param_1,float param_2)

{
  bool bVar1;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  bVar1 = false;
  if ((_DAT_00f0736c != param_1) || (DAT_00ef7324 == 1)) {
    _DAT_00f0736c = param_1;
    bVar1 = true;
  }
  if ((_DAT_00f07370 != param_2) || (DAT_00ef7324 == 1)) {
    _DAT_00f07370 = param_2;
    FUN_005baf50();
    DAT_00ef72cc = 1;
    return 0;
  }
  if (bVar1) {
    FUN_005baf50();
  }
  DAT_00ef72cc = 1;
  return 0;
}

