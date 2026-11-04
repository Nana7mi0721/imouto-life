
/* WARNING: Removing unreachable block (ram,0x005d4c8f) */

void FUN_005d4bf0(void)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int local_18;
  int local_14;
  int local_10;
  
  DAT_00f3a030 = -1;
  DAT_00f3a034 = -1;
  if (DAT_00f3a028 != (int *)0x0) {
    local_10 = 0;
    local_18 = 0;
    local_14 = 0;
    (**(code **)(*DAT_00f3a028 + 0x58))(DAT_00f3a028,1,0);
    lVar3 = FUN_00550090(0);
    lVar2 = 0;
    do {
      if (0x3b < local_14) break;
      (**(code **)(*DAT_00f3a028 + 0x58))(DAT_00f3a028,1,0);
      lVar4 = FUN_00550090(0);
      lVar1 = lVar4 - lVar3;
      lVar2 = lVar2 - lVar1;
      if (lVar2 < 0x100000000) {
        if (lVar2 < 0) {
          lVar2 = CONCAT44(-((int)((ulonglong)lVar2 >> 0x20) + (uint)((int)lVar2 != 0)),-(int)lVar2)
          ;
        }
        if (999 < lVar2) goto LAB_005d4ca6;
        local_10 = local_10 + (int)lVar1;
        local_18 = local_18 + 1;
      }
      else {
LAB_005d4ca6:
        local_10 = 0;
        local_18 = 0;
      }
      local_14 = local_14 + 1;
      if (9 < local_18) {
        DAT_00f3a030 = local_10 / local_18;
        DAT_00f3a034 = DAT_00f3a030 >> 0x1f;
      }
      Sleep(5);
      lVar3 = lVar4;
      lVar2 = lVar1;
    } while (local_18 < 10);
  }
  FUN_005d1a10();
  return;
}

