
/* WARNING: Removing unreachable block (ram,0x005d1a55) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d1a10(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  
  if ((DAT_00f3a030 & DAT_00f3a034) == 0xffffffff) {
    uVar1 = 4000;
    iVar4 = 0;
  }
  else {
    uVar1 = DAT_00f3a030 - 3000;
    iVar4 = DAT_00f3a034 - (DAT_00f3a030 < 3000);
  }
  lVar5 = FUN_00550090(0);
  if (CONCAT44(iVar4,uVar1) <= lVar5 - CONCAT44(_DAT_00f3a03c,_DAT_00f3a038)) {
    (**(code **)(*DAT_00f3a028 + 0x58))(DAT_00f3a028,1,0);
    _DAT_00f3a038 = FUN_00550090(0);
    Sleep(0);
    return;
  }
  Sleep(0);
  lVar5 = FUN_00550090(0);
  lVar5 = lVar5 - CONCAT44(_DAT_00f3a03c,_DAT_00f3a038);
  uVar2 = (uint)lVar5;
  iVar3 = (int)((ulonglong)lVar5 >> 0x20);
  if (iVar3 <= iVar4) {
    if (iVar3 < iVar4) goto LAB_005d1a84;
    do {
      if (uVar1 <= uVar2) break;
LAB_005d1a84:
      do {
        Sleep(1);
        lVar5 = FUN_00550090(0);
        lVar5 = lVar5 - CONCAT44(_DAT_00f3a03c,_DAT_00f3a038);
        uVar2 = (uint)lVar5;
        iVar3 = (int)((ulonglong)lVar5 >> 0x20);
      } while (iVar3 < iVar4);
    } while (iVar3 <= iVar4);
  }
  (**(code **)(*DAT_00f3a028 + 0x58))(DAT_00f3a028,1,0);
  _DAT_00f3a038 = FUN_00550090(0);
  return;
}

