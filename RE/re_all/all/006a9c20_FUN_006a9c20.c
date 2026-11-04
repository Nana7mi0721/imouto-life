
/* WARNING: Removing unreachable block (ram,0x006a9e40) */
/* WARNING: Removing unreachable block (ram,0x006a9f0f) */

int FUN_006a9c20(int param_1,void *param_2,undefined4 param_3,uint param_4,int param_5,uint param_6,
                int param_7,undefined4 param_8,int param_9,int param_10,undefined4 param_11,
                undefined4 param_12,int param_13)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined8 uVar13;
  longlong lVar14;
  longlong lVar15;
  undefined4 local_68;
  int local_64;
  undefined8 local_60;
  uint local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30 [16];
  undefined4 local_20 [8];
  
  uVar3 = param_6;
  iVar5 = param_1;
  local_60._4_4_ = param_7;
  local_54 = param_7;
  local_50 = 0xffffffff;
  local_4c = 0xffffffff;
  iVar8 = *(int *)(param_1 + 0x1c8);
  local_60._0_4_ = param_6;
  local_58 = param_6;
  local_64 = iVar8;
  iVar6 = FUN_006a9690(param_10,param_11,param_12);
  uVar2 = param_12;
  lVar14 = CONCAT44(local_60._4_4_,(uint)local_60);
  iVar10 = param_7;
  iVar4 = param_13;
  uVar11 = uVar3;
  if (iVar6 != 0) {
    while (param_13 = iVar4, param_10 != iVar8) {
      param_10 = iVar8;
      uVar13 = FUN_006a98a0(iVar5,uVar11,iVar10,param_11,uVar2,&param_10,&param_8);
      iVar10 = (int)((ulonglong)uVar13 >> 0x20);
      iVar4 = param_13;
      uVar11 = (uint)uVar13;
    }
    iVar8 = iVar4 + 1;
    *(int *)(iVar5 + 0x34) = iVar8;
    if (*(void **)(iVar5 + 0x38) != (void *)0x0) {
      _free(*(void **)(iVar5 + 0x38));
    }
    if (*(void **)(iVar5 + 0x40) != (void *)0x0) {
      _free(*(void **)(iVar5 + 0x40));
    }
    if (*(void **)(iVar5 + 0x3c) != (void *)0x0) {
      _free(*(void **)(iVar5 + 0x3c));
    }
    pvVar7 = _malloc(*(int *)(iVar5 + 0x34) * 8 + 8);
    *(void **)(iVar5 + 0x38) = pvVar7;
    pvVar7 = _realloc(*(void **)(iVar5 + 0x48),*(int *)(iVar5 + 0x34) << 5);
    *(void **)(iVar5 + 0x48) = pvVar7;
    pvVar7 = _realloc(*(void **)(iVar5 + 0x4c),*(int *)(iVar5 + 0x34) << 4);
    *(void **)(iVar5 + 0x4c) = pvVar7;
    pvVar7 = _malloc(*(int *)(iVar5 + 0x34) << 2);
    *(void **)(iVar5 + 0x40) = pvVar7;
    pvVar7 = _malloc(*(int *)(iVar5 + 0x34) << 3);
    *(void **)(iVar5 + 0x3c) = pvVar7;
    pvVar7 = _malloc(*(int *)(iVar5 + 0x34) << 4);
    iVar10 = *(int *)(iVar5 + 0x38);
    *(void **)(iVar5 + 0x44) = pvVar7;
    *(uint *)(iVar10 + iVar8 * 8) = uVar3;
    *(int *)(iVar10 + 4 + iVar8 * 8) = param_7;
    iVar8 = *(int *)(iVar5 + 0x38);
    *(void **)(iVar8 + iVar4 * 8) = param_2;
    *(undefined4 *)(iVar8 + 4 + iVar4 * 8) = param_3;
    if ((param_9 < 1) && (param_9 < 0)) {
      param_8 = 0;
      param_9 = 0;
    }
    iVar8 = *(int *)(iVar5 + 0x44);
    *(undefined4 *)(iVar4 * 0x10 + 8 + iVar8) = param_8;
    *(int *)(iVar4 * 0x10 + 0xc + iVar8) = param_9;
    return 0;
  }
  param_2 = (void *)0x0;
  local_68 = 0;
  param_1 = iVar8 + 1;
  iVar10 = local_54;
  iVar4 = local_54;
  if (param_5 <= param_7) {
    local_60 = CONCAT44(local_60._4_4_,(uint)local_60);
    if (param_7 <= param_5) {
      local_60 = lVar14;
      if (param_6 <= param_4) goto joined_r0x006a9f38;
    }
    do {
      lVar14 = CONCAT44(param_5,param_4);
      if (0xffff < local_60 - lVar14) {
        lVar14 = __alldiv(local_60 + lVar14,2,0);
      }
      iVar8 = FUN_006a9a90(iVar5,lVar14);
      if (iVar8 != 0) {
        return iVar8;
      }
      lVar15 = FUN_006a94d0(iVar5,local_30,0xffffffff,0xffffffff);
      local_48 = (uint)lVar15;
      if (lVar15 == -0x80) {
        return -0x80;
      }
      if (lVar15 < 0) {
LAB_006a9ee0:
        if (-1 < lVar15) {
          local_58 = local_48;
          local_54 = (int)((ulonglong)lVar15 >> 0x20);
        }
      }
      else {
        iVar8 = FUN_006a9670(local_30,param_11,param_12);
        if (iVar8 == 0) goto LAB_006a9ee0;
        param_4 = *(uint *)(iVar5 + 8);
        param_5 = *(int *)(iVar5 + 0xc);
        lVar14 = local_60;
      }
      uVar3 = local_58;
      iVar10 = local_54;
      iVar4 = local_54;
      iVar8 = local_64;
      uVar11 = local_58;
      local_60 = lVar14;
    } while (CONCAT44(param_5,param_4) < lVar14);
  }
joined_r0x006a9f38:
  while( true ) {
    iVar6 = local_54;
    local_54 = iVar4;
    local_60 = lVar14;
    if (param_1 == iVar8) break;
    param_1 = iVar8;
    uVar13 = FUN_006a98a0(iVar5,uVar3,iVar10,param_11,param_12,&param_1,&local_50);
    uVar3 = (uint)uVar13;
    iVar10 = (int)((ulonglong)uVar13 >> 0x20);
    iVar4 = local_54;
    local_54 = iVar6;
    lVar14 = local_60;
  }
  iVar8 = FUN_006a9a90(iVar5,uVar11,iVar6);
  if (iVar8 == 0) {
    iVar8 = FUN_006a9220(iVar5,local_20,&local_40,&param_2,&local_68,0);
    if (iVar8 == 0) {
      param_4 = *(undefined4 *)(iVar5 + 8);
      param_5 = *(undefined4 *)(iVar5 + 0xc);
      uVar2 = *(undefined4 *)(iVar5 + 0x1c8);
      uVar13 = FUN_006a9b00(iVar5,local_20);
      iVar10 = param_13 + 1;
      local_60 = uVar13;
      iVar8 = FUN_006a9c20(iVar5,uVar11,local_54,*(undefined4 *)(iVar5 + 8),
                           *(undefined4 *)(iVar5 + 0xc),param_6,param_7,param_8,param_9,param_10,
                           param_2,local_68,iVar10);
      if (iVar8 == 0) {
        uVar13 = local_60;
        if (param_2 != (void *)0x0) {
          _free(param_2);
          uVar13 = local_60;
        }
        local_60._4_4_ = (int)((ulonglong)uVar13 >> 0x20);
        local_60._0_4_ = (uint)uVar13;
        iVar8 = *(int *)(iVar5 + 0x38);
        *(uint *)(iVar8 + iVar10 * 8) = uVar11;
        *(int *)(iVar8 + 4 + iVar10 * 8) = local_54;
        *(undefined4 *)(*(int *)(iVar5 + 0x40) + iVar10 * 4) = uVar2;
        iVar8 = *(int *)(iVar5 + 0x3c);
        *(uint *)(iVar8 + iVar10 * 8) = param_4;
        *(int *)(iVar8 + 4 + iVar10 * 8) = param_5;
        puVar9 = local_20;
        puVar12 = (undefined4 *)(iVar10 * 0x20 + *(int *)(iVar5 + 0x48));
        for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar12 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar12 = puVar12 + 1;
        }
        iVar10 = iVar10 * 0x10;
        puVar9 = (undefined4 *)(*(int *)(iVar5 + 0x4c) + iVar10);
        *puVar9 = local_40;
        puVar9[1] = local_3c;
        puVar9[2] = local_38;
        puVar9[3] = local_34;
        iVar8 = *(int *)(iVar5 + 0x44);
        param_13 = param_13 * 0x10;
        *(undefined4 *)(iVar8 + 8 + param_13) = local_50;
        *(undefined4 *)(iVar8 + 0xc + param_13) = local_4c;
        iVar8 = *(int *)(iVar5 + 0x44);
        *(uint *)(iVar8 + iVar10) = (uint)local_60;
        *(int *)(iVar8 + 4 + iVar10) = local_60._4_4_;
        uVar3 = *(uint *)(*(int *)(iVar5 + 0x44) + 0x18 + param_13);
        piVar1 = (int *)(*(int *)(iVar5 + 0x44) + 0x18 + param_13);
        *piVar1 = uVar3 - (uint)local_60;
        piVar1[1] = (piVar1[1] - local_60._4_4_) - (uint)(uVar3 < (uint)local_60);
        iVar8 = *(int *)(*(int *)(iVar5 + 0x44) + 0x1c + param_13);
        puVar9 = (undefined4 *)(*(int *)(iVar5 + 0x44) + 0x18 + param_13);
        if ((iVar8 < 1) && (iVar8 < 0)) {
          *puVar9 = 0;
          puVar9[1] = 0;
        }
        iVar8 = 0;
      }
    }
  }
  return iVar8;
}

