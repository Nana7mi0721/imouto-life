
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005a00b0(void)

{
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if (DAT_00e39a54 == 0) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
  }
  FUN_005d3ad0(0,1,DAT_00e8065c);
  FUN_005d3ad0(0,2,DAT_00e8069c);
  FUN_005d3ad0(1,1,DAT_00e80660);
  FUN_005d3ad0(1,2,DAT_00e806a0);
  FUN_005d3ad0(2,1,DAT_00e80664);
  FUN_005d3ad0(2,2,DAT_00e806a4);
  FUN_005d3ad0(3,1,DAT_00e80668);
  FUN_005d3ad0(3,2,DAT_00e806a8);
  FUN_005d3ab0(0,0xb,0);
  FUN_005d3ab0(1,0xb,1);
  FUN_005d3ab0(2,0xb,1);
  FUN_005d3ab0(3,0xb,0);
  DAT_00e796c8 = 0;
  DAT_00e796e0 = 1;
  _DAT_00e796f8 = 1;
  _DAT_00e79710 = 0;
  if (DAT_00ddb4b8 != 0) {
    FUN_005d3ab0(0,0x1c,1);
    FUN_005d3ab0(1,0x1c,1);
    FUN_005d3ab0(2,0x1c,1);
    FUN_005d3ab0(3,0x1c,1);
    DAT_00e796cc = 0;
    DAT_00e796e4 = 0;
    _DAT_00e796fc = 0;
    _DAT_00e79714 = 0;
  }
  FUN_005d3a70(9,DAT_00e80638);
  FUN_005d3a70(0x89,DAT_00e804a0);
  FUN_005d3a70(0x16,1);
  FUN_005d3a70(0x1a,0);
  FUN_0059cb80(&DAT_00ddb600,0,0,0,&DAT_0085fbd0,1,1);
  FUN_0059cb80(&DAT_00ddb600,3,0,0,&DAT_0085fbc0,1,1);
  FUN_0059b780(0);
  if (((DAT_00e39a54 != 0) || (DAT_00e80624 != 0)) && (DAT_00f3a04c != 0)) {
    if ((DAT_00e39a54 != 0) || (DAT_00e80624 != 0)) {
      FUN_005d3d20(0);
      DAT_00e80624 = 0;
    }
    DAT_00e80620 = 0;
    DAT_00e39a00 = 1;
  }
  if ((((DAT_00e80630 != 0) || (DAT_00e80634 != 0)) || (DAT_00e39a54 != 0)) && (DAT_00f3a04c != 0))
  {
    DAT_00e80630 = 0;
    DAT_00e80634 = 0;
  }
  if (((DAT_00e80618 != 0) || (DAT_00e39a54 != 0)) && (DAT_00f3a04c != 0)) {
    DAT_00e80618 = 0;
  }
  return 0;
}

