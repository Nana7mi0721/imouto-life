
undefined4 __thiscall FUN_00615560(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  undefined4 unaff_retaddr;
  
  DAT_00f3f3d0 = DAT_00f3f3d0 + 1;
  iVar11 = param_2;
  if (*(int *)(param_3 + 0xc) < *(int *)(param_2 + 0xc)) {
    iVar11 = param_3;
    param_3 = param_2;
  }
  iVar12 = *(int *)(param_3 + 0xc);
  uVar6 = *(uint *)(iVar11 + 0xc);
  uVar4 = iVar12 << 0x10 | uVar6;
  uVar4 = uVar4 + ~(uVar4 << 0xf);
  uVar4 = ((int)uVar4 >> 10 ^ uVar4) * 9;
  uVar4 = uVar4 ^ (int)uVar4 >> 6;
  uVar4 = uVar4 + ~(uVar4 << 0xb);
  uVar4 = ((int)uVar4 >> 0x10 ^ uVar4) & param_1[3] - 1U;
  iVar11 = *(int *)(param_1[0xb] + uVar4 * 4);
  if (iVar11 == -1) {
    return 0;
  }
  while (cVar3 = FUN_00616130(iVar11 * 0x10 + param_1[4],uVar6,iVar12), cVar3 == '\0') {
    iVar11 = *(int *)(param_1[0x10] + iVar11 * 4);
    if (iVar11 == -1) {
      return 0;
    }
  }
  if (iVar11 == -1) {
    return 0;
  }
  iVar11 = iVar11 * 0x10 + param_1[4];
  if (iVar11 == 0) {
    return 0;
  }
  (**(code **)(*param_1 + 0x1c))(iVar11,param_4);
  uVar1 = *(undefined4 *)(iVar11 + 0xc);
  piVar8 = (int *)(param_1[0xb] + uVar4 * 4);
  iVar12 = iVar11 - param_1[4] >> 4;
  iVar11 = *piVar8;
  if (iVar11 == iVar12) {
LAB_0061566d:
    *piVar8 = *(int *)(param_1[0x10] + iVar12 * 4);
  }
  else {
    iVar2 = param_1[0x10];
    do {
      iVar5 = iVar11;
      iVar11 = *(int *)(iVar2 + iVar5 * 4);
    } while (iVar11 != iVar12);
    if (iVar5 == -1) goto LAB_0061566d;
    *(undefined4 *)(iVar2 + iVar5 * 4) = *(undefined4 *)(iVar2 + iVar12 * 4);
  }
  iVar11 = param_1[2] + -1;
  if ((int *)param_1[0x12] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x12] + 8))(uVar6,unaff_retaddr,param_4);
  }
  if (iVar11 == iVar12) goto LAB_00615760;
  piVar8 = (int *)(iVar11 * 0x10 + param_1[4]);
  uVar6 = *(int *)(piVar8[1] + 0xc) << 0x10 | *(uint *)(*piVar8 + 0xc);
  uVar6 = uVar6 + ~(uVar6 << 0xf);
  uVar6 = ((int)uVar6 >> 10 ^ uVar6) * 9;
  uVar6 = uVar6 ^ (int)uVar6 >> 6;
  uVar6 = uVar6 + ~(uVar6 << 0xb);
  uVar6 = ((int)uVar6 >> 0x10 ^ uVar6) & param_1[3] - 1U;
  piVar8 = (int *)(param_1[0xb] + uVar6 * 4);
  iVar2 = *piVar8;
  if (iVar2 == iVar11) {
LAB_00615723:
    *piVar8 = *(int *)(param_1[0x10] + iVar11 * 4);
  }
  else {
    iVar5 = param_1[0x10];
    do {
      iVar7 = iVar2;
      iVar2 = *(int *)(iVar5 + iVar7 * 4);
    } while (iVar2 != iVar11);
    if (iVar7 == -1) goto LAB_00615723;
    *(undefined4 *)(iVar5 + iVar7 * 4) = *(undefined4 *)(iVar5 + iVar11 * 4);
  }
  puVar9 = (undefined4 *)(iVar11 * 0x10 + param_1[4]);
  puVar10 = (undefined4 *)(iVar12 * 0x10 + param_1[4]);
  *puVar10 = *puVar9;
  puVar10[1] = puVar9[1];
  puVar10[2] = puVar9[2];
  puVar10[3] = puVar9[3];
  *(undefined4 *)(param_1[0x10] + iVar12 * 4) = *(undefined4 *)(param_1[0xb] + uVar6 * 4);
  *(int *)(param_1[0xb] + uVar6 * 4) = iVar12;
LAB_00615760:
  param_1[2] = param_1[2] + -1;
  return uVar1;
}

