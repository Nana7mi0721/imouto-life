
undefined4 FUN_0059be30(ushort *param_1,int param_2,uint param_3,int param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  ushort *puVar6;
  ushort uVar7;
  int iVar8;
  ushort uVar9;
  ushort *puVar10;
  
  if (param_4 == 0) {
    return 0;
  }
  iVar8 = *(int *)(param_1 + 0x200);
  param_4 = param_3 + param_4;
  iVar4 = 0;
  bVar2 = true;
  bVar1 = false;
  puVar10 = param_1;
  if (0 < iVar8) {
    do {
      if ((int)(uint)*puVar10 <= param_4) break;
      iVar4 = iVar4 + 1;
      puVar10 = puVar10 + 2;
    } while (iVar4 < iVar8);
  }
  if (iVar4 != iVar8) {
    iVar4 = 0;
    bVar2 = false;
    puVar10 = param_1;
    if (0 < iVar8) {
      do {
        if ((int)param_3 < (int)(uint)puVar10[1]) break;
        iVar4 = iVar4 + 1;
        puVar10 = puVar10 + 2;
      } while (iVar4 < iVar8);
    }
    if (param_4 < (int)(uint)*puVar10) {
      bVar1 = true;
    }
  }
  uVar9 = (ushort)param_4;
  uVar7 = (ushort)param_3;
  if (param_2 == 0) {
    if (iVar4 == iVar8) {
      return 0;
    }
    if (bVar1) {
      return 0;
    }
    if (((int)(uint)*puVar10 < (int)param_3) && (param_4 < (int)(uint)puVar10[1])) {
      FUN_0056d460(puVar10 + 2,puVar10,(iVar8 - iVar4) * 4);
      puVar10[1] = uVar7;
      puVar10[2] = uVar9;
      *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x200) + 1;
      return 0;
    }
    if ((int)(uint)*puVar10 < (int)param_3) {
      puVar10[1] = uVar7;
      puVar10 = puVar10 + 2;
      iVar4 = iVar4 + 1;
    }
    iVar8 = 0;
    if (iVar4 < *(int *)(param_1 + 0x200)) {
      puVar5 = puVar10 + 1;
      do {
        if (param_4 < (int)(uint)*puVar5) break;
        iVar4 = iVar4 + 1;
        iVar8 = iVar8 + 1;
        puVar5 = puVar5 + 2;
      } while (iVar4 < *(int *)(param_1 + 0x200));
      if ((0 < iVar8) && (0 < *(int *)(param_1 + 0x200) - iVar4)) {
        FUN_0056d460(puVar10,puVar10 + iVar8 * 2,(*(int *)(param_1 + 0x200) - iVar4) * 4);
      }
    }
    *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x200) - iVar8;
    if (*(int *)(param_1 + 0x200) < 1) {
      return 0;
    }
    if ((int)(uint)*puVar10 < param_4) {
      *puVar10 = uVar9;
      return 0;
    }
    return 0;
  }
  if (iVar4 == iVar8) {
    if ((0 < iVar4) && (puVar10[-1] == param_3)) {
LAB_0059bfa8:
      puVar10[-1] = uVar9;
      return 0;
    }
    if (!bVar2) goto LAB_0059bfd1;
    puVar10 = param_1;
  }
  else {
    if (!bVar1) {
      if ((0 < iVar4) && (puVar10[-1] == param_3)) {
        puVar10 = puVar10 + -2;
        iVar4 = iVar4 + -1;
      }
      if ((int)param_3 < (int)(uint)*puVar10) {
        *puVar10 = uVar7;
      }
      if (param_4 <= (int)(uint)puVar10[1]) {
        return 0;
      }
      puVar10[1] = uVar9;
      iVar4 = iVar4 + 1;
      puVar5 = puVar10 + 2;
      iVar8 = 0;
      if (iVar4 < *(int *)(param_1 + 0x200)) {
        puVar6 = puVar10 + 3;
        do {
          if (param_4 < (int)(uint)*puVar6) break;
          iVar4 = iVar4 + 1;
          iVar8 = iVar8 + 1;
          puVar6 = puVar6 + 2;
        } while (iVar4 < *(int *)(param_1 + 0x200));
        if ((iVar4 < *(int *)(param_1 + 0x200)) && ((int)(uint)puVar5[iVar8 * 2] <= param_4)) {
          iVar3 = iVar8 * 2;
          iVar8 = iVar8 + 1;
          puVar10[1] = puVar10[iVar3 + 3];
          iVar4 = iVar4 + 1;
        }
      }
      if ((0 < iVar8) && (0 < *(int *)(param_1 + 0x200) - iVar4)) {
        FUN_0056d460(puVar5,puVar5 + iVar8 * 2,(*(int *)(param_1 + 0x200) - iVar4) * 4);
      }
      *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x200) - iVar8;
      return 0;
    }
    if ((0 < iVar4) && (puVar10[-1] == param_3)) goto LAB_0059bfa8;
    iVar8 = iVar8 - iVar4;
  }
  FUN_0056d460(puVar10 + 2,puVar10,iVar8 * 4);
LAB_0059bfd1:
  *puVar10 = uVar7;
  puVar10[1] = uVar9;
  *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x200) + 1;
  return 0;
}

