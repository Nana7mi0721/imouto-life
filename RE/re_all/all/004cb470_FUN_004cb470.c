
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cb470(void)

{
  bool bVar1;
  undefined4 extraout_var;
  
  bVar1 = false;
  DAT_00a14061 = 0;
  if (DAT_00a17eb8 != DAT_00a14068) {
    FUN_0047dcf0(0);
    FUN_00449500(DAT_00a14068);
    if (DAT_00a13fa0 == -1) {
      return;
    }
    bVar1 = true;
    FUN_00449cc0();
  }
  FUN_004cb530(DAT_00a1406c,DAT_00a14070,1);
  FUN_00485cb0(extraout_var);
  _DAT_00a144f4 = 0xffff;
  DAT_00a1809c = 1;
  FUN_0044b650();
  if (bVar1) {
    FUN_00423060();
    FUN_004c0d40();
  }
  FUN_00446640();
  return;
}

