
/* WARNING: Removing unreachable block (ram,0x006c1935) */
/* WARNING: Removing unreachable block (ram,0x006c19c4) */
/* WARNING: Removing unreachable block (ram,0x006c1b92) */

int FUN_006c1710(int param_1,uint param_2,int param_3,int param_4,int param_5,undefined4 *param_6,
                undefined4 *param_7,undefined4 *param_8)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined1 *puVar14;
  void *pvVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  ulonglong *puVar19;
  undefined4 *puVar20;
  int iVar21;
  size_t _NewSize;
  longlong lVar22;
  ulonglong uVar23;
  ulonglong uVar24;
  ulonglong uVar25;
  void *local_84;
  int local_78;
  int local_74;
  int local_70;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_30;
  int local_2c;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  undefined1 local_10 [16];
  
  uVar10 = CONCAT44(local_48,local_4c);
  local_84 = *(void **)(param_1 + 0x1c);
  local_74 = *(int *)(param_1 + 0x18);
  local_20 = 0;
  local_1c = 0;
  local_78 = local_74 * 0x160;
  local_70 = 1;
  local_2c = local_74;
  do {
    uVar1 = *param_6;
    uVar2 = *param_7;
    if (local_2c <= local_74) {
      if (0x3fffffff < local_2c) {
        return -0x81;
      }
      local_2c = local_2c * 2 + 1;
      local_84 = _realloc(local_84,local_2c * 0x160);
      if (local_84 == (void *)0x0) {
        return -0x81;
      }
      *(void **)(param_1 + 0x1c) = local_84;
    }
    iVar21 = 0;
    if (local_70 < 1) {
LAB_006c1d30:
      _NewSize = local_74 * 0x160;
      if (((*(uint *)((_NewSize - 0x148) + (int)local_84) &
           *(uint *)((_NewSize - 0x144) + (int)local_84)) == 0xffffffff) &&
         (iVar21 = FUN_006c1e10(param_1,uVar1,uVar2,(_NewSize - 0x160) + (int)local_84,
                                *(undefined4 *)(param_4 + 8),*(undefined4 *)(param_4 + 0xc),
                                *(undefined4 *)(param_4 + 0x14),*(undefined4 *)(param_4 + 0x18),
                                *(undefined4 *)(param_4 + 0x1c),&local_20), iVar21 < 0)) {
        return iVar21;
      }
      pvVar15 = _realloc(local_84,_NewSize);
      if (pvVar15 != (void *)0x0) {
        *(void **)(param_1 + 0x1c) = pvVar15;
      }
      _free((void *)*param_6);
      *param_6 = 0;
      *param_7 = 0;
      *param_8 = 0;
      return 0;
    }
    puVar20 = (undefined4 *)(param_4 + 0x14);
    do {
      iVar11 = FUN_006c08a0(*puVar20,uVar1,uVar2);
      if (iVar11 != 0) break;
      iVar21 = iVar21 + 1;
      puVar20 = puVar20 + 8;
    } while (iVar21 < local_70);
    if (iVar21 < 1) goto LAB_006c1d30;
    iVar18 = param_4 + iVar21 * 0x20;
    uVar3 = *(uint *)(iVar18 + -0x20);
    iVar11 = *(int *)(iVar18 + -0x1c);
    uVar7 = *(ulonglong *)(iVar18 + -0x20);
    puVar19 = (ulonglong *)(iVar18 + -0x18);
    uVar24 = *puVar19;
    uVar6 = *puVar19;
    uVar9 = *puVar19;
    local_58 = 0xffffffff;
    local_54 = 0xffffffff;
    if (iVar21 < local_70) {
      uVar4 = *(uint *)(iVar18 + 0x10);
      param_2 = uVar4 + *(uint *)(iVar18 + 8);
      param_3 = ((int)uVar4 >> 0x1f) + *(int *)(iVar18 + 0xc) +
                (uint)CARRY4(uVar4,*(uint *)(iVar18 + 8));
      if (*(int *)(iVar18 + 0x14) == *(int *)(local_78 + -0x138 + (int)local_84)) {
        local_54 = *(undefined4 *)(iVar18 + 0x1c);
        local_58 = *(undefined4 *)(iVar18 + 0x18);
        uVar10 = *(ulonglong *)(iVar18 + 8);
      }
    }
    uVar25 = 0xffffffffffffffff;
    if (0x160 < local_78) {
      uVar4 = *(uint *)(local_78 + -0x160 + (int)local_84);
      iVar5 = *(int *)(local_78 + -0x15c + (int)local_84);
      lVar22 = __alldiv(uVar4,iVar5,local_74 + -1,local_74 + -1 >> 0x1f);
      iVar13 = (int)((ulonglong)lVar22 >> 0x20);
      uVar12 = (uint)lVar22;
      uVar17 = (uVar3 - uVar12) - 0x10000;
      iVar16 = ((iVar11 - iVar13) - (uint)(uVar3 < uVar12)) - (uint)(uVar3 - uVar12 < 0x10000);
      local_18 = param_2 - uVar12;
      iVar13 = (param_3 - iVar13) - (uint)(param_2 < uVar12);
      uVar25 = 0xffffffffffffffff;
      if (((iVar13 <= iVar5) &&
          ((((iVar13 < iVar5 || (uVar25 = 0xffffffffffffffff, local_18 < uVar4)) &&
            (uVar25 = 0xffffffffffffffff, iVar5 <= iVar16)) &&
           ((iVar5 < iVar16 || (uVar25 = 0xffffffffffffffff, uVar4 < uVar17)))))) &&
         (uVar25 = lVar22 + CONCAT44(iVar5,uVar4),
         lVar22 + CONCAT44(iVar5,uVar4) < CONCAT44(iVar16,uVar17))) {
        uVar25 = lVar22 + uVar25;
      }
    }
    local_70 = iVar21;
    uVar8 = CONCAT44(local_54,local_58);
    uVar23 = 0xffffffffffffffff;
    if (param_3 <= iVar11) {
      uVar8 = CONCAT44(local_54,local_58);
      if (iVar11 <= param_3) {
        uVar9 = uVar6;
        uVar23 = 0xffffffffffffffff;
        if (uVar3 <= param_2) goto LAB_006c1ba5;
      }
      puVar19 = (ulonglong *)(iVar18 + 8);
      uVar9 = uVar24;
      do {
        uVar6 = CONCAT44(param_3,param_2);
        if (uVar25 == 0xffffffffffffffff) {
          lVar22 = __allshr();
          uVar25 = lVar22 + uVar6;
        }
        if (0xffff < (longlong)(uVar25 - uVar6)) {
          uVar8 = 0xffffffffffffffff;
          uVar6 = uVar25;
        }
        iVar21 = FUN_006c16b0(param_1,uVar6);
        if (iVar21 < 0) {
          return iVar21;
        }
        uVar23 = FUN_006c03f0(param_1,local_10,(int)puVar19[-4],
                              *(undefined4 *)((int)puVar19 + -0x1c));
        iVar21 = (int)uVar23;
        if (((longlong)uVar23 < -0x100000000) || ((0x7fffffffffffffff < uVar23 && (iVar21 != -1))))
        {
          return iVar21;
        }
        local_30 = 0;
        if (uVar23 == 0xffffffffffffffff) {
          uVar7 = uVar6;
        }
        else {
          iVar11 = FUN_006a8360(local_10);
          uVar24 = FUN_006a8280(local_10);
          iVar18 = FUN_006c08a0(iVar11,uVar1,uVar2);
          if (iVar18 == 0) {
            uVar7 = uVar6;
            uVar9 = uVar23;
            if (local_70 < param_5) {
              puVar19[-1] = uVar6;
              *puVar19 = uVar23;
              *(int *)(puVar19 + 1) = *(int *)(param_1 + 0x30) - iVar21;
              *(int *)((int)puVar19 + 0xc) = iVar11;
              puVar19[2] = uVar24;
              local_70 = local_70 + 1;
              puVar19 = puVar19 + 4;
            }
          }
          else {
            local_30 = 0x10000;
            param_2 = *(uint *)(param_1 + 0x30);
            param_3 = *(int *)(param_1 + 0x34);
            if (iVar11 == *(int *)(local_78 + -0x138 + (int)local_84)) {
              uVar8 = uVar24;
              uVar10 = uVar23;
            }
          }
        }
        uVar25 = FUN_006c2180(param_4,local_70,param_2,param_3,uVar7,local_30);
      } while (CONCAT44(param_3,param_2) < (longlong)uVar7);
    }
LAB_006c1ba5:
    puVar19 = (ulonglong *)(local_78 + (int)local_84);
    if ((*(uint *)(local_78 + -0x148 + (int)local_84) & *(uint *)(local_78 + -0x144 + (int)local_84)
        ) == 0xffffffff) {
      if (uVar8 == 0xffffffffffffffff) {
        uVar23 = 0xffffffffffffffff;
        uVar10 = uVar9;
      }
      iVar21 = FUN_006c1e10(param_1,uVar1,uVar2,puVar19 + -0x2c,uVar10,(int)puVar19[-0x27],uVar8,
                            &local_20);
      if (iVar21 < 0) {
        return iVar21;
      }
    }
    if (uVar9 == uVar23) {
      puVar14 = local_10;
    }
    else {
      iVar21 = FUN_006c16b0(param_1,uVar9);
      if (iVar21 < 0) {
        return iVar21;
      }
      puVar14 = (undefined1 *)0x0;
    }
    iVar21 = FUN_006c0350(param_1,(int)puVar19 + 0x2c,(int)puVar19 + 0x14c,param_6,param_7,param_8,
                          puVar14);
    if (iVar21 < 0) {
      return iVar21;
    }
    *puVar19 = uVar9;
    *(undefined4 *)(puVar19 + 1) = *(undefined4 *)(param_1 + 0x30);
    *(undefined4 *)((int)puVar19 + 0xc) = *(undefined4 *)(param_1 + 0x34);
    *(undefined4 *)(puVar19 + 5) = *(undefined4 *)(param_1 + 0x1d8);
    *(undefined4 *)(puVar19 + 3) = 0xffffffff;
    *(undefined4 *)((int)puVar19 + 0x1c) = 0xffffffff;
    iVar21 = FUN_006c08d0(param_1,puVar19,0);
    if (iVar21 < 0) {
      return iVar21;
    }
    param_2 = *(uint *)(param_1 + 0x30);
    param_3 = *(int *)(param_1 + 0x34);
    local_74 = local_74 + 1;
    local_78 = local_78 + 0x160;
    *(int *)(param_1 + 0x18) = local_74;
  } while( true );
}

