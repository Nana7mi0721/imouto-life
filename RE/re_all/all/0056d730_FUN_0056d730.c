
void FUN_0056d730(uint *param_1,int *param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint *puVar8;
  int *piVar9;
  uint *puVar10;
  bool bVar11;
  int local_54 [4];
  int local_44 [8];
  uint local_24 [4];
  uint *local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  puVar8 = local_24;
  for (iVar5 = 4; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar8 = *param_1;
    param_1 = param_1 + 1;
    puVar8 = puVar8 + 1;
  }
  piVar7 = local_54;
  for (iVar5 = 2; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar7 = *param_2;
    param_2 = param_2 + 1;
    piVar7 = piVar7 + 1;
  }
  for (iVar5 = 2; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  piVar7 = local_44 + 4;
  for (iVar5 = 4; local_14 = local_24, local_10 = local_54, local_c = local_44 + 4,
      local_8 = local_44, iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
LAB_0056d780:
  piVar7 = local_10;
  piVar9 = local_8;
  for (iVar5 = 4; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar9 = *piVar7;
    piVar7 = piVar7 + 1;
    piVar9 = piVar9 + 1;
  }
  iVar5 = 0;
  do {
    piVar7 = local_8;
    iVar6 = 4;
    bVar11 = (int *)0xfffffff3 < local_8;
    puVar8 = local_14 + 3;
    puVar10 = (uint *)(local_8 + 3);
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      uVar2 = *puVar10;
      uVar1 = *puVar8;
      bVar11 = uVar1 < uVar2;
      puVar8 = puVar8 + -1;
      puVar10 = puVar10 + -1;
    } while (uVar1 == uVar2);
    if (bVar11) break;
    iVar5 = iVar5 + 1;
    iVar6 = 1;
    do {
      iVar3 = *piVar7;
      *piVar7 = *piVar7 << 1;
      uVar4 = (ulonglong)CONCAT14(iVar3 < 0,piVar7[1]) << 1;
      piVar7[1] = (uint)uVar4 | (uint)(iVar3 < 0);
      bVar11 = (uVar4 & 0x100000000) != 0;
      uVar4 = (ulonglong)CONCAT14(bVar11,piVar7[2]) << 1;
      piVar7[2] = (uint)uVar4 | (uint)bVar11;
      piVar7[3] = piVar7[3] << 1 | (uint)((uVar4 & 0x100000000) != 0);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  } while( true );
  if (iVar5 == 0) {
    for (iVar5 = 2; iVar5 != 0; iVar5 = iVar5 + -1) {
      *param_3 = *local_c;
      local_c = local_c + 1;
      param_3 = param_3 + 1;
    }
    return;
  }
  goto LAB_0056d780;
}

