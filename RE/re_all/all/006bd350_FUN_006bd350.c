
undefined4 FUN_006bd350(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  void *_Memory;
  uint uVar6;
  undefined4 *puVar7;
  byte bVar8;
  byte bVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  undefined4 *puVar18;
  int iVar19;
  uint uVar20;
  undefined4 *puVar21;
  int iVar22;
  int *local_28;
  int local_24;
  int *local_20;
  
  if (((int)param_2 < 3) || (6 < (int)param_2)) {
    return 0xfffffff6;
  }
  iVar1 = *(int *)(param_1 + 4);
  uVar14 = iVar1 + 0x20;
  bVar8 = (byte)~*(uint *)(param_1 + 0x30) & 1;
  uVar15 = *(int *)(param_1 + 8) + 0x20;
  bVar9 = (byte)(~*(uint *)(param_1 + 0x30) >> 1) & 1;
  uVar4 = uVar15 * uVar14;
  uVar20 = ((int)uVar14 >> bVar8) + 0xfU & 0xfffffff0;
  uVar16 = ((int)uVar15 >> bVar9) * uVar20;
  iVar17 = (0x10 >> bVar9) * uVar20 + (0x10 >> bVar8);
  uVar6 = uVar16 * 2 + 0x10;
  uVar10 = uVar6 + uVar4;
  if ((((uVar4 / uVar14 != uVar15) || (uVar6 < uVar16)) || (uVar10 < uVar4)) ||
     ((uVar10 * (int)param_2) / (uint)param_2 != uVar10)) {
    return 0xffffffe9;
  }
  iVar5 = FUN_006b8dd0(uVar10 * (int)param_2,0x10);
  _Memory = _malloc(*(int *)(param_1 + 0xb4) << 2);
  *(void **)(param_1 + 0xac) = _Memory;
  if ((iVar5 == 0) || (_Memory == (void *)0x0)) {
    _free(_Memory);
    FUN_006b8e20(iVar5);
    return 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_1 + 8);
  *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 4);
  *(uint *)(param_1 + 0xf4) = uVar14;
  uVar6 = *(uint *)(param_1 + 4) >> bVar8;
  *(uint *)(param_1 + 0x114) = uVar20;
  *(uint *)(param_1 + 0x104) = uVar20;
  *(uint *)(param_1 + 0x10c) = uVar6;
  *(uint *)(param_1 + 0xfc) = uVar6;
  uVar6 = *(uint *)(param_1 + 8) >> bVar9;
  *(uint *)(param_1 + 0x110) = uVar6;
  *(uint *)(param_1 + 0x100) = uVar6;
  if (1 < (int)param_2) {
    iVar13 = (int)param_2 - 1;
    puVar7 = (undefined4 *)(param_1 + 0x11c);
    do {
      iVar13 = iVar13 + -1;
      puVar18 = (undefined4 *)(param_1 + 0xec);
      puVar21 = puVar7;
      for (iVar11 = 0xc; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar21 = *puVar18;
        puVar18 = puVar18 + 1;
        puVar21 = puVar21 + 1;
      }
      puVar7 = puVar7 + 0xc;
    } while (iVar13 != 0);
  }
  *(int *)(param_1 + 0x23c) = iVar5;
  if (0 < (int)param_2) {
    local_28 = (int *)(param_1 + 0x108);
    do {
      local_28[-4] = (iVar1 + 0x21) * 0x10 + iVar5;
      iVar5 = iVar5 + (-iVar17 & 0xfU) + uVar4;
      *local_28 = iVar5 + iVar17;
      iVar5 = iVar5 + uVar16;
      local_28[4] = iVar5 + iVar17;
      iVar5 = iVar5 + 0x10 + (uVar16 - (-iVar17 & 0xfU));
      FUN_006b8e40(local_28 + -7,local_28 + -7);
      local_28 = local_28 + 0xc;
      param_2 = (int *)((int)param_2 - 1);
    } while (param_2 != (int *)0x0);
  }
  iVar1 = *(int *)(param_1 + 0xf8);
  param_2 = (int *)(param_1 + 0xf4);
  local_20 = (int *)(param_1 + 0x50);
  *(uint *)(param_1 + 0x240) = -uVar14;
  *(uint *)(param_1 + 0x248) = -uVar20;
  *(uint *)(param_1 + 0x244) = -uVar20;
  iVar17 = 0;
  local_24 = 3;
  do {
    iVar13 = local_20[1];
    iVar11 = *local_20;
    iVar5 = param_2[1];
    iVar2 = local_20[-2];
    iVar3 = *param_2;
    while (iVar17 < iVar13 + iVar11) {
      if (iVar17 < iVar2 + iVar17) {
        iVar22 = (iVar2 + iVar17) - iVar17;
        iVar19 = iVar17 * 4;
        iVar17 = iVar17 + iVar22;
        piVar12 = (int *)((int)_Memory + iVar19);
        iVar19 = iVar5;
        do {
          iVar22 = iVar22 + -1;
          *piVar12 = iVar19 - iVar1;
          piVar12 = piVar12 + 1;
          iVar19 = iVar19 + 8;
        } while (iVar22 != 0);
      }
      iVar5 = iVar5 + iVar3 * 8;
    }
    param_2 = param_2 + 4;
    local_20 = local_20 + 8;
    local_24 = local_24 + -1;
  } while (local_24 != 0);
  *(undefined4 *)(param_1 + 0x218) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x214) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x220) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x21c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x210) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x230) = 0;
  *(undefined4 *)(param_1 + 0x22c) = 0;
  *(undefined4 *)(param_1 + 0x238) = 0;
  *(undefined4 *)(param_1 + 0x234) = 0;
  *(undefined4 *)(param_1 + 0x228) = 0;
  *(undefined4 *)(param_1 + 0x224) = 0;
  return 0;
}

