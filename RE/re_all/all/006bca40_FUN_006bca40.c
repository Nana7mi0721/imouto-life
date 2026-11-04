
undefined4 FUN_006bca40(int param_1)

{
  size_t _Count;
  uint uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  int iVar6;
  size_t _Count_00;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int *piVar15;
  
  uVar12 = *(uint *)(param_1 + 4) >> 3;
  uVar5 = ~*(uint *)(param_1 + 0x30) & 1;
  uVar1 = ~*(uint *)(param_1 + 0x30) >> 1 & 1;
  uVar13 = *(uint *)(param_1 + 8) >> 3;
  iVar10 = (int)(uVar5 + uVar12) >> (sbyte)uVar5;
  iVar2 = (int)(uVar1 + uVar13) >> (sbyte)uVar1;
  iVar14 = uVar13 * uVar12;
  iVar6 = iVar2 * iVar10;
  _Count_00 = iVar6 * 2 + iVar14;
  uVar7 = (int)(uVar12 + 3) >> 2;
  iVar3 = iVar2 + 3 >> 2;
  iVar11 = iVar10 + 3 >> 2;
  uVar1 = iVar3 * iVar11;
  uVar8 = (int)(uVar13 + 3) >> 2;
  uVar9 = uVar8 * uVar7;
  uVar5 = uVar1 * 2 + uVar9;
  _Count = uVar9 * 4;
  if ((((iVar14 / (int)uVar12 != uVar13) || (iVar6 * 2 < iVar6)) || ((int)_Count_00 < iVar14)) ||
     (((uVar9 / uVar7 != uVar8 || (uVar1 * 2 < uVar1)) ||
      ((uVar5 < uVar9 || ((uVar9 & 0x3fffffff) != uVar9)))))) {
    return 0xffffffe9;
  }
  *(uint *)(param_1 + 0x48) = uVar12;
  *(uint *)(param_1 + 0x5c) = uVar8;
  *(int *)(param_1 + 0x88) = iVar10;
  *(int *)(param_1 + 0x68) = iVar10;
  *(uint *)(param_1 + 0x4c) = uVar13;
  *(int *)(param_1 + 0x8c) = iVar2;
  *(int *)(param_1 + 0x6c) = iVar2;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(int *)(param_1 + 0x54) = iVar14;
  *(int *)(param_1 + 0x70) = iVar14;
  *(int *)(param_1 + 0x94) = iVar6;
  *(int *)(param_1 + 0x74) = iVar6;
  *(int *)(param_1 + 0x90) = iVar14 + iVar6;
  *(uint *)(param_1 + 100) = uVar9;
  *(int *)(param_1 + 0x98) = iVar11;
  *(int *)(param_1 + 0x78) = iVar11;
  *(uint *)(param_1 + 0x80) = uVar9;
  *(uint *)(param_1 + 0x58) = uVar7;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(int *)(param_1 + 0x9c) = iVar3;
  *(int *)(param_1 + 0x7c) = iVar3;
  *(uint *)(param_1 + 0xa0) = uVar9 + uVar1;
  *(uint *)(param_1 + 0xa4) = uVar1;
  *(uint *)(param_1 + 0x84) = uVar1;
  *(size_t *)(param_1 + 0xb4) = _Count_00;
  pvVar4 = _calloc(_Count_00,4);
  *(void **)(param_1 + 0xa8) = pvVar4;
  pvVar4 = _malloc(_Count_00 * 2);
  *(void **)(param_1 + 0xb0) = pvVar4;
  *(uint *)(param_1 + 0xc0) = uVar5;
  pvVar4 = _malloc(uVar5 * 0x40);
  *(void **)(param_1 + 0xb8) = pvVar4;
  pvVar4 = _calloc(uVar5,1);
  *(void **)(param_1 + 0xbc) = pvVar4;
  *(uint *)(param_1 + 0xcc) = uVar7 * 2;
  *(uint *)(param_1 + 0xd0) = uVar8 * 2;
  *(size_t *)(param_1 + 0xd4) = _Count;
  pvVar4 = _calloc(_Count,0x30);
  *(void **)(param_1 + 0xc4) = pvVar4;
  pvVar4 = _calloc(_Count,1);
  *(void **)(param_1 + 200) = pvVar4;
  pvVar4 = _malloc(_Count_00 * 4);
  *(void **)(param_1 + 0xd8) = pvVar4;
  if ((((*(int *)(param_1 + 0xa8) == 0) || (*(int *)(param_1 + 0xb0) == 0)) ||
      ((*(int *)(param_1 + 0xb8) == 0 ||
       (((*(int *)(param_1 + 0xbc) == 0 || (*(int *)(param_1 + 0xc4) == 0)) ||
        (*(int *)(param_1 + 200) == 0)))))) || (pvVar4 == (void *)0x0)) {
    return 0xffffffff;
  }
  piVar15 = (int *)(param_1 + 0x60);
  iVar2 = 3;
  do {
    FUN_006bcd40(*piVar15 * 0x40 + *(int *)(param_1 + 0xb8),*piVar15 + *(int *)(param_1 + 0xbc),
                 piVar15[-4],piVar15[-6],piVar15[-5]);
    piVar15 = piVar15 + 8;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_006bced0(*(undefined4 *)(param_1 + 0xc4),*(undefined4 *)(param_1 + 200),param_1 + 0x48,
               *(undefined4 *)(param_1 + 0x30));
  FUN_006bd060(param_1);
  return 0;
}

