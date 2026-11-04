
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00522bc0(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined8 uVar11;
  
  DAT_00a37ee4 = 1;
  if (DAT_00a496ec != 0) {
    DAT_00a37ee4 = 0;
    return 0;
  }
  if ((DAT_00a49730 == 0) || (iVar8 = FUN_0052ea40(), iVar8 != 0)) {
    DAT_00a37ee4 = 0;
    return 0xffffffff;
  }
  if (DAT_00ca39e8 != 0) {
    if (DAT_00ca39f4 != 0) {
      FUN_0057ae10(DAT_00a38194,DAT_00a38198,DAT_00a3819c,DAT_00a381a0);
    }
    DAT_00ca39e8 = 0;
  }
  iVar8 = FUN_0056c170();
  uVar7 = DAT_00a381a0;
  uVar6 = DAT_00a3819c;
  uVar5 = DAT_00a38198;
  uVar4 = DAT_00a38194;
  uVar3 = DAT_00a380d0;
  uVar9 = DAT_00a380cc;
  if (iVar8 != 0) {
    uVar1 = _DAT_00a38114 >> 0x10;
    uVar2 = _DAT_00a38114 >> 8;
    uVar10 = _DAT_00a38114 & 0xff;
    FUN_005217e0(0,0,DAT_00a37e60,DAT_00a37e64);
    FUN_005160d0(0,0);
    if (((DAT_00a38116 != -1) || (DAT_00a38115 != -1)) || (DAT_00a38114 != -1)) {
      _DAT_00a38114 = CONCAT13(DAT_00a38116_1,0xff0000);
      _DAT_00a38114 = CONCAT22(_DAT_00a38116,0xffff);
      if (DAT_00a37d78 == 0) {
        FUN_00581200(_DAT_00a38114);
      }
      else {
        FUN_00567b70(0xff,0xff,0xff);
      }
    }
    DAT_00a496ec = 1;
    FUN_0056c180();
    DAT_00a496ec = 0;
    FUN_005217e0(uVar4,uVar5,uVar6,uVar7);
    FUN_005160d0(uVar9,uVar3);
    FUN_005161e0(uVar1 & 0xff,uVar2 & 0xff,uVar10);
  }
  uVar9 = FUN_005683e0();
  _DAT_00a37df0 = DAT_00a37de8;
  _DAT_00a37df4 = DAT_00a37dec;
  uVar11 = FUN_00550090(0);
  _DAT_00a37de0 = DAT_00a37de4;
  DAT_00a37de4 = 0;
  DAT_00a37de8 = (int)uVar11;
  DAT_00a37dec = (int)((ulonglong)uVar11 >> 0x20);
  DAT_00a37ee4 = 0;
  return uVar9;
}

