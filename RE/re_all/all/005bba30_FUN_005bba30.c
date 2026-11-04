
undefined4 __thiscall FUN_005bba30(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  iVar3 = 0;
  iVar6 = -1;
  iVar4 = 0;
  bVar2 = false;
  if (0 < param_3) {
    piVar5 = &DAT_00f13454 + param_2;
    do {
      iVar1 = *(int *)(param_4 + iVar3 * 4);
      if ((*piVar5 != iVar1) || (DAT_00ef7324 != 0)) {
        if (!bVar2) {
          bVar2 = true;
          iVar6 = iVar3 + param_2;
          param_1 = iVar3;
        }
        iVar4 = (iVar3 - param_1) + 1;
        *piVar5 = iVar1;
      }
      iVar3 = iVar3 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar3 < param_3);
    if (bVar2) {
      FUN_005d2b50(iVar6,iVar4,param_4 + param_1 * 4);
    }
  }
  return 0;
}

