
undefined4 FUN_006bfab0(undefined4 param_1,undefined2 *param_2)

{
  uint *puVar1;
  uint *puVar2;
  bool bVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  void *_Memory;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined2 *puVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int *piVar17;
  undefined4 *puVar18;
  int iVar19;
  void *pvVar20;
  undefined4 *puVar21;
  int local_210;
  int local_20c;
  int local_200 [64];
  int local_100 [64];
  
  uVar6 = FUN_006bf0c0(param_1,3);
  iVar15 = 0;
  do {
    uVar4 = FUN_006bf0c0(param_1,uVar6);
    *(undefined1 *)((int)param_2 + iVar15 + 0x100) = uVar4;
    iVar15 = iVar15 + 1;
  } while (iVar15 < 0x40);
  iVar15 = FUN_006bf0c0(param_1,4);
  puVar12 = param_2 + 0x40;
  iVar19 = 0x40;
  do {
    uVar5 = FUN_006bf0c0(param_1,iVar15 + 1);
    *puVar12 = uVar5;
    puVar12 = puVar12 + 1;
    iVar19 = iVar19 + -1;
  } while (iVar19 != 0);
  iVar15 = FUN_006bf0c0(param_1,4);
  iVar19 = 0x40;
  puVar12 = param_2;
  do {
    uVar5 = FUN_006bf0c0(param_1,iVar15 + 1);
    *puVar12 = uVar5;
    puVar12 = puVar12 + 1;
    iVar19 = iVar19 + -1;
  } while (iVar19 != 0);
  iVar15 = FUN_006bf0c0(param_1,9);
  iVar19 = iVar15 + 1;
  _Memory = _malloc(iVar19 * 0x40);
  if (_Memory == (void *)0x0) {
    return 0xffffffff;
  }
  if (0 < iVar19) {
    pvVar20 = _Memory;
    local_210 = iVar19;
    do {
      iVar16 = 0;
      do {
        uVar4 = FUN_006bf0c0(param_1,8);
        *(undefined1 *)((int)pvVar20 + iVar16) = uVar4;
        iVar16 = iVar16 + 1;
      } while (iVar16 < 0x40);
      pvVar20 = (void *)((int)pvVar20 + 0x40);
      local_210 = local_210 + -1;
    } while (local_210 != 0);
  }
  uVar6 = FUN_006b8db0(iVar15);
  local_20c = 0;
  do {
    iVar15 = local_20c / 3;
    iVar16 = local_20c % 3;
    puVar1 = (uint *)(param_2 + (iVar16 + iVar15 * 3) * 6 + 0xa0);
    if ((local_20c < 1) || (iVar7 = FUN_006bf110(param_1), iVar7 != 0)) {
      local_200[0] = FUN_006bf0c0(param_1,uVar6);
      iVar15 = 0;
      uVar14 = 0;
      do {
        uVar13 = uVar14;
        uVar8 = FUN_006b8db0(0x3e - iVar15);
        iVar16 = FUN_006bf0c0(param_1,uVar8);
        local_100[uVar13] = iVar16 + 1;
        iVar15 = iVar15 + 1 + iVar16;
        uVar14 = uVar13 + 1;
        iVar16 = FUN_006bf0c0(param_1,uVar6);
        local_200[uVar14] = iVar16;
      } while (iVar15 < 0x3f);
      if (0x3f < iVar15) {
LAB_006bfdd1:
        _free(_Memory);
        return 0xffffffec;
      }
      *puVar1 = uVar14;
      piVar9 = _malloc(uVar14 * 4);
      puVar1[1] = (uint)piVar9;
      if (piVar9 == (int *)0x0) {
        _free(_Memory);
        return 0xffffffff;
      }
      piVar17 = local_100;
      for (uVar10 = uVar14 & 0x3fffffff; uVar10 != 0; uVar10 = uVar10 - 1) {
        *piVar9 = *piVar17;
        piVar17 = piVar17 + 1;
        piVar9 = piVar9 + 1;
      }
      for (iVar15 = 0; iVar15 != 0; iVar15 = iVar15 + -1) {
        *(char *)piVar9 = (char)*piVar17;
        piVar17 = (int *)((int)piVar17 + 1);
        piVar9 = (int *)((int)piVar9 + 1);
      }
      pvVar20 = _malloc((uVar13 + 2) * 0x40);
      if (pvVar20 == (void *)0x0) {
        _free(_Memory);
        return 0xffffffff;
      }
      puVar1[2] = (uint)pvVar20;
      puVar11 = (undefined4 *)(uVar14 * 0x40 + (int)pvVar20);
      piVar9 = local_200 + uVar14;
      do {
        if (iVar19 <= *piVar9) goto LAB_006bfdd1;
        puVar18 = (undefined4 *)(*piVar9 * 0x40 + (int)_Memory);
        puVar21 = puVar11;
        for (iVar15 = 0x10; iVar15 != 0; iVar15 = iVar15 + -1) {
          *puVar21 = *puVar18;
          puVar18 = puVar18 + 1;
          puVar21 = puVar21 + 1;
        }
        piVar9 = piVar9 + -1;
        puVar11 = puVar11 + -0x10;
        bVar3 = 0 < (int)uVar14;
        uVar14 = uVar14 - 1;
      } while (bVar3);
    }
    else {
      if ((iVar15 < 1) || (iVar7 = FUN_006bf110(param_1), iVar7 == 0)) {
        iVar15 = (local_20c + -1) / 3;
        iVar16 = (local_20c + -1) % 3;
      }
      else {
        iVar15 = iVar15 + -1;
      }
      puVar2 = (uint *)(param_2 + (iVar16 + iVar15 * 3) * 6 + 0xa0);
      *puVar1 = *puVar2;
      puVar1[1] = puVar2[1];
      puVar1[2] = puVar2[2];
    }
    local_20c = local_20c + 1;
    if (5 < local_20c) {
      _free(_Memory);
      return 0;
    }
  } while( true );
}

