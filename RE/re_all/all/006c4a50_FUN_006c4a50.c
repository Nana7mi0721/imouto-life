
int FUN_006c4a50(int *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  int *piVar8;
  int *piVar9;
  byte *pbVar10;
  bool bVar11;
  
  if (param_3 < 8) {
    return -0x84;
  }
  iVar5 = 2;
  bVar11 = true;
  piVar8 = param_2;
  piVar9 = (int *)s_OpusTags_00a0f3a8;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar11 = *piVar8 == *piVar9;
    piVar8 = piVar8 + 1;
    piVar9 = piVar9 + 1;
  } while (bVar11);
  if (!bVar11) {
    return -0x84;
  }
  if (param_3 < 0x10) {
    return -0x85;
  }
  uVar1 = FUN_006c4940(param_2 + 2);
  if (param_3 - 0xc < uVar1) {
    return -0x85;
  }
  if (param_1 != (int *)0x0) {
    iVar5 = FUN_006c4ce0(param_2 + 3,uVar1);
    param_1[3] = iVar5;
    if (iVar5 == 0) {
      return -0x81;
    }
  }
  uVar6 = (param_3 - 0xc) - uVar1;
  iVar5 = (int)(param_2 + 3) + uVar1;
  if (uVar6 < 4) {
    return -0x85;
  }
  uVar1 = FUN_006c4940(iVar5);
  uVar6 = uVar6 - 4;
  pbVar7 = (byte *)(iVar5 + 4);
  if (uVar6 >> 2 < uVar1) {
    return -0x85;
  }
  if (0x7ffffffe < uVar1) {
    return -0x81;
  }
  if ((param_1 != (int *)0x0) && (iVar5 = FUN_006c4c20(param_1,uVar1), iVar5 < 0)) {
    return iVar5;
  }
  iVar5 = 0;
  if (0 < (int)uVar1) {
    do {
      if (uVar6 >> 2 < uVar1 - iVar5) {
        return -0x85;
      }
      uVar2 = FUN_006c4940(pbVar7);
      if (uVar6 - 4 < uVar2) {
        return -0x85;
      }
      if (0x7fffffff < uVar2) {
        return -0x81;
      }
      if (param_1 != (int *)0x0) {
        uVar3 = FUN_006c4ce0(pbVar7 + 4,uVar2);
        *(undefined4 *)(*param_1 + iVar5 * 4) = uVar3;
        if (*(int *)(*param_1 + iVar5 * 4) == 0) {
          return -0x81;
        }
        *(uint *)(param_1[1] + iVar5 * 4) = uVar2;
        param_1[2] = iVar5 + 1;
      }
      pbVar7 = pbVar7 + 4 + uVar2;
      uVar6 = (uVar6 - 4) - uVar2;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)uVar1);
  }
  if ((uVar6 != 0) && ((*pbVar7 & 1) != 0)) {
    if (0x7fffffff < uVar6) {
      return -0x81;
    }
    pvVar4 = _malloc(uVar6);
    *(void **)(*param_1 + uVar1 * 4) = pvVar4;
    pbVar10 = *(byte **)(*param_1 + uVar1 * 4);
    if (pbVar10 == (byte *)0x0) {
      return -0x81;
    }
    for (uVar2 = uVar6 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined4 *)pbVar10 = *(undefined4 *)pbVar7;
      pbVar7 = pbVar7 + 4;
      pbVar10 = pbVar10 + 4;
    }
    for (uVar2 = uVar6 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pbVar10 = *pbVar7;
      pbVar7 = pbVar7 + 1;
      pbVar10 = pbVar10 + 1;
    }
    *(uint *)(param_1[1] + uVar1 * 4) = uVar6;
  }
  return 0;
}

