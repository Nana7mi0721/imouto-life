
/* WARNING: Removing unreachable block (ram,0x006c3863) */
/* WARNING: Removing unreachable block (ram,0x006c38c2) */
/* WARNING: Removing unreachable block (ram,0x006c3629) */
/* WARNING: Removing unreachable block (ram,0x006c354f) */
/* WARNING: Removing unreachable block (ram,0x006c3404) */
/* WARNING: Removing unreachable block (ram,0x006c3826) */
/* WARNING: Removing unreachable block (ram,0x006c3b46) */
/* WARNING: Removing unreachable block (ram,0x006c3b09) */
/* WARNING: Removing unreachable block (ram,0x006c3ae6) */
/* WARNING: Removing unreachable block (ram,0x006c3ba8) */
/* WARNING: Removing unreachable block (ram,0x006c3c14) */

uint FUN_006c3170(int param_1,uint param_2,uint param_3,int param_4)

{
  ulonglong *puVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined1 *puVar15;
  int iVar16;
  int iVar17;
  longlong lVar18;
  ulonglong uVar19;
  longlong lVar20;
  longlong lVar21;
  ulonglong uVar22;
  uint local_a8;
  uint local_a4;
  uint local_98;
  int local_94;
  uint local_88;
  int local_84;
  uint local_78;
  uint local_74;
  uint local_68;
  uint local_64;
  undefined8 local_60;
  undefined8 local_58;
  int local_50;
  uint local_4c;
  uint local_48;
  int local_44;
  undefined8 local_40;
  uint local_38;
  undefined4 local_34;
  longlong local_30;
  int local_28;
  longlong local_24;
  undefined1 local_1c [16];
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  iVar17 = param_4 * 0x160 + *(int *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  bVar4 = false;
  local_a8 = *(uint *)(iVar17 + 0x20);
  local_a4 = *(uint *)(iVar17 + 0x24);
  local_74 = *(uint *)(iVar17 + 0x1c);
  local_78 = *(uint *)(iVar17 + 0x18);
  uVar14 = *(uint *)(iVar17 + 8);
  iVar16 = *(int *)(iVar17 + 0xc);
  local_28 = *(int *)(iVar17 + 0x28);
  local_48 = uVar14;
  local_44 = iVar16;
  local_40._0_4_ = local_a8;
  local_40._4_4_ = local_a4;
  local_c = iVar17;
  iVar12 = FUN_006bff30(&param_2,param_2,param_3,0xfffff100);
  if ((iVar12 < 0) || (iVar12 = FUN_006c0d50(param_2,param_3,local_a8,local_a4), iVar12 < 0)) {
    param_2 = local_a8;
    param_3 = local_a4;
  }
  FUN_006bff30(&local_8,local_a8,local_a4,*(undefined4 *)(iVar17 + 0x34));
  iVar12 = FUN_006c0d50(param_2,param_3,local_8,local_4);
  local_98 = uVar14;
  local_94 = iVar16;
  if (iVar12 < 0) {
    local_88 = uVar14;
    local_84 = iVar16;
  }
  else {
    local_88 = *(uint *)(iVar17 + 0x10);
    local_84 = *(int *)(iVar17 + 0x14);
    if ((param_4 == *(int *)(param_1 + 0x60)) && (3 < *(int *)(param_1 + 0x5c))) {
      iVar12 = *(int *)(param_1 + 0x34);
      uVar13 = *(uint *)(param_1 + 0x30);
      if (((0 < *(int *)(param_1 + 0x21d4)) && (iVar12 <= local_84)) &&
         ((iVar12 < local_84 || (uVar13 <= local_88)))) {
        iVar17 = (*(int *)(param_1 + 0x21d4) + 0xf) * 0x20;
        uVar2 = *(uint *)(iVar17 + param_1);
        uVar3 = *(uint *)(iVar17 + 4 + param_1);
        if (((uVar2 & uVar3) != 0xffffffff) &&
           ((iVar17 = FUN_006c0d50(local_a8,local_a4,uVar2,uVar3), iVar17 < 0 &&
            (iVar17 = FUN_006c0d50(local_78,local_74,uVar2,uVar3), 0 < iVar17)))) {
          FUN_006c0c50(&local_68,uVar2,uVar3,param_2,param_3);
          if (((int)local_64 < 1) && ((int)local_64 < 0)) {
            lVar18 = __allshr();
            local_38 = uVar13 - uVar14;
            if ((lVar18 <= CONCAT44((iVar12 - iVar16) - (uint)(uVar13 < uVar14),local_38)) ||
               ((-2 < (int)local_64 && ((local_64 < 0x80000000 || (0xffa81c00 < local_68)))))) {
              iVar16 = iVar12;
              uVar14 = uVar13;
              local_a8 = uVar2;
              local_a4 = uVar3;
              local_48 = uVar13;
              local_44 = iVar12;
              local_40._0_4_ = uVar2;
              local_40._4_4_ = uVar3;
              if (*(int *)(param_1 + 0x94) < *(int *)(param_1 + 0x90)) {
                bVar4 = true;
                local_98 = *(uint *)(param_1 + 0x70);
                local_94 = *(int *)(param_1 + 0x74);
              }
              else {
                bVar4 = true;
                local_98 = uVar13;
                local_94 = iVar12;
              }
            }
          }
          else {
            iVar17 = FUN_006c0e70(*(undefined4 *)(param_1 + 0x1f0),*(undefined4 *)(param_1 + 500));
            FUN_006bff30(&local_58,*(undefined4 *)(param_1 + 0x200),*(undefined4 *)(param_1 + 0x204)
                         ,-iVar17);
            iVar17 = FUN_006c0d50((undefined4)local_58,local_58._4_4_,param_2,param_3);
            if (iVar17 < 1) {
              *(undefined4 *)(param_1 + 0x68) = (undefined4)local_58;
              *(undefined4 *)(param_1 + 0x21d0) = 0;
              *(undefined4 *)(param_1 + 0x2200) = 0;
              *(undefined4 *)(param_1 + 0x6c) = local_58._4_4_;
              *(undefined4 *)(param_1 + 0x5c) = 3;
              uVar14 = FUN_006c0f60(param_1);
              return uVar14;
            }
            lVar18 = __allshr();
            local_38 = uVar13 - uVar14;
            if ((CONCAT44((iVar12 - iVar16) - (uint)(uVar13 < uVar14),local_38) <= lVar18) ||
               (((int)local_64 < 1 && (((int)local_64 < 0 || (local_68 < 0x57e400)))))) {
              local_88 = uVar13;
              local_84 = iVar12;
              local_78 = uVar2;
              local_74 = uVar3;
            }
          }
        }
      }
    }
  }
  uVar5 = CONCAT44(local_94,local_98);
  uVar22 = CONCAT44(local_84,local_88);
  FUN_006c26a0(param_1);
  if (!bVar4) {
    FUN_006a8d60(param_1 + 0x88,local_28);
  }
  lVar20 = CONCAT44(local_40._4_4_,(uint)local_40);
  lVar18 = CONCAT44(local_60._4_4_,(undefined4)local_60);
  *(int *)(param_1 + 0x60) = param_4;
  *(undefined4 *)(param_1 + 0x5c) = 3;
  iVar12 = (local_84 - iVar16) - (uint)(local_88 < uVar14);
  local_24 = CONCAT44(iVar12,local_88 - uVar14);
  local_4c = 0;
  local_58 = CONCAT44(iVar12,local_88 - uVar14);
  local_30 = local_24;
  local_60 = CONCAT44(local_60._4_4_,(undefined4)local_60);
  uVar19 = 0xffffffffffffffff;
  local_40 = CONCAT44(local_40._4_4_,(uint)local_40);
  uVar9 = CONCAT44(local_94,local_98);
  if ((iVar16 <= local_84) &&
     ((uVar7 = CONCAT44(local_84,local_88), local_60 = lVar18, lVar8 = CONCAT44(local_74,local_78),
      lVar18 = CONCAT44(local_a4,local_a8), local_58 = local_24, local_40 = lVar20, uVar9 = uVar5,
      iVar16 < local_84 ||
      (uVar19 = 0xffffffffffffffff, uVar7 = uVar22, lVar8 = CONCAT44(local_74,local_78),
      lVar18 = CONCAT44(local_a4,local_a8), uVar14 < local_88)))) {
    do {
      uVar5 = CONCAT44(iVar16,uVar14);
      if (0xffff < (longlong)(uVar7 - uVar5)) {
        lVar20 = __allshr();
        local_58 = lVar20;
        lVar20 = __allshr();
        local_24 = lVar20;
        lVar20 = __allshr();
        local_30 = lVar20;
        if (local_4c == 0) {
          FUN_006c0c50(&local_68,param_2,param_3,lVar18);
          FUN_006c0c50(&local_38,lVar8,lVar18);
          lVar20 = FUN_006c23f0(local_68,local_64,local_38,local_34,uVar7 - uVar5);
          uVar19 = lVar20 + CONCAT44(iVar16 - (uint)(uVar14 < 0x10000),uVar14 - 0x10000);
        }
        else {
          uVar19 = lVar20 + uVar5;
        }
        iVar12 = (int)(uVar19 >> 0x20) - (uint)((uint)uVar19 < 0x10000);
        if ((iVar12 <= iVar16) && ((iVar12 < iVar16 || ((uint)uVar19 - 0x10000 < uVar14)))) {
          uVar19 = uVar5;
        }
        local_4c = 0;
        uVar5 = uVar19;
      }
      if (((int)uVar5 != *(int *)(param_1 + 0x30)) ||
         ((int)(uVar5 >> 0x20) != *(int *)(param_1 + 0x34))) {
        if (bVar4) {
          FUN_006a8d00(param_1 + 0x88);
        }
        bVar4 = false;
        uVar13 = FUN_006c16b0(param_1,uVar5);
        if ((int)uVar13 < 0) {
          return uVar13;
        }
      }
      local_50 = 0x10000;
      uVar10 = uVar22;
LAB_006c37c0:
      uVar6 = CONCAT44(iVar16,uVar14);
      uVar19 = FUN_006c03f0(param_1,local_1c,uVar10);
      uVar13 = (uint)uVar19;
      if (((longlong)uVar19 < 0x100000000) && ((longlong)uVar19 < 0)) {
        if ((longlong)uVar19 < -0x100000000) {
          return uVar13;
        }
        if ((0x7fffffffffffffff < uVar19) && (uVar13 != 0xffffffff)) {
          return uVar13;
        }
        if ((longlong)uVar5 <= CONCAT44(iVar16 + (uint)(0xfffffffe < uVar14),uVar14 + 1)) break;
        if (bVar4) {
          FUN_006a8d00(param_1 + 0x88);
        }
        bVar4 = false;
        if ((longlong)uVar6 < (longlong)(uVar5 - (longlong)local_50)) {
          uVar6 = uVar5 - (longlong)local_50;
        }
        uVar13 = FUN_006c16b0(param_1,uVar6);
        if ((int)uVar13 < 0) {
          return uVar13;
        }
        local_50 = local_50 * 2;
        uVar5 = uVar6;
        uVar10 = uVar22;
        if (0xfffff < local_50) {
          local_50 = 0x100000;
        }
        goto LAB_006c3ad6;
      }
      if ((longlong)uVar19 < (longlong)uVar22) {
        uVar22 = uVar19;
      }
      iVar12 = FUN_006a8360(local_1c);
      if (local_28 != iVar12) goto LAB_006c3ad6;
      iVar12 = FUN_006a83c0(local_1c);
      lVar20 = local_60;
      if (0 >= iVar12) {
LAB_006c392f:
        local_60 = lVar20;
        if (bVar4) {
          if (0 < iVar12) {
            FUN_006a8d00(param_1 + 0x88);
            bVar4 = false;
          }
          else {
            FUN_006a89a0(param_1 + 0x88,local_1c);
          }
        }
LAB_006c3ad6:
        if ((longlong)uVar7 <= CONCAT44(iVar16,uVar14)) break;
        goto LAB_006c37c0;
      }
      lVar20 = FUN_006a8280(local_1c);
      if (lVar20 == -1) goto LAB_006c392f;
      local_60 = lVar20;
      iVar12 = FUN_006c0d50(lVar20,param_2,param_3);
      if (iVar12 < 0) {
        puVar1 = (ulonglong *)(param_1 + 0x30);
        uVar14 = *(uint *)puVar1;
        iVar16 = *(int *)(param_1 + 0x34);
        uVar11 = *puVar1;
        uVar6 = *puVar1;
        iVar12 = FUN_006c0d50(lVar18,local_60);
        uVar5 = uVar7;
        if (iVar12 < 1) {
          iVar12 = FUN_006c0d50(lVar8,local_60);
          if (-1 < iVar12) {
            local_48 = uVar14;
            local_44 = iVar16;
            if (bVar4) {
              FUN_006a8d00(param_1 + 0x88);
            }
            iVar12 = FUN_006c3d40(local_1c);
            lVar18 = local_60;
            uVar9 = uVar11;
            if (iVar12 != 0) {
              FUN_006c3d60(param_1,local_1c);
              lVar18 = local_60;
              uVar9 = uVar19;
            }
            bVar4 = true;
            local_60 = lVar18;
            local_40 = lVar18;
            FUN_006c0c50(&local_68,param_2,param_3,lVar18);
            if (((int)local_64 < 1) && (((int)local_64 < 0 || (local_68 < 0xbb81)))) {
              uVar5 = uVar6;
              goto LAB_006c3ad6;
            }
          }
        }
      }
      else {
        if ((longlong)uVar5 <= CONCAT44(iVar16 + (uint)(0xfffffffe < uVar14),uVar14 + 1)) break;
        lVar21 = __allmul(local_58,2,0);
        lVar20 = local_60;
        local_4c = (uint)(lVar21 < (longlong)(uVar5 - uVar6));
        iVar12 = FUN_006c0d50(lVar8,local_60);
        uVar10 = uVar22;
        if (0 < iVar12) {
          iVar12 = FUN_006c0d50(lVar18,lVar20);
          if (iVar12 < 1) {
            lVar8 = lVar20;
          }
        }
      }
      uVar7 = uVar5;
      uVar22 = uVar10;
    } while (CONCAT44(iVar16,uVar14) < (longlong)uVar5);
  }
  local_94 = (int)(uVar9 >> 0x20);
  local_98 = (uint)uVar9;
  if (bVar4) {
    lVar18 = local_40;
  }
  else {
    if (uVar19 != uVar9) {
      uVar19 = 0xffffffffffffffff;
      uVar14 = FUN_006c16b0(param_1,uVar9);
      if ((int)uVar14 < 0) {
        return uVar14;
      }
    }
    lVar18 = local_40;
    if ((longlong)uVar9 < CONCAT44(local_44,local_48)) {
      if (((int)(uVar19 >> 0x20) < 1) && ((longlong)uVar19 < 0)) {
        uVar22 = FUN_006c03f0(param_1,local_1c,*(undefined4 *)(local_c + 0x10),
                              *(undefined4 *)(local_c + 0x14));
        uVar14 = (uint)uVar22;
        if (0x7fffffffffffffff < uVar22) {
          if ((longlong)uVar22 < -0x100000000) {
            return uVar14;
          }
          if (uVar14 != 0xffffffff) {
            return uVar14;
          }
        }
        if (uVar22 != uVar9) {
          return 0xffffff77;
        }
      }
      FUN_006c3d60(param_1,local_1c);
      uVar19 = 0xffffffffffffffff;
      lVar18 = local_40;
    }
  }
  local_40._4_4_ = (uint)((ulonglong)lVar18 >> 0x20);
  local_40._0_4_ = (uint)lVar18;
  *(uint *)(param_1 + 0x68) = (uint)local_40;
  *(uint *)(param_1 + 0x70) = local_98;
  *(uint *)(param_1 + 0x6c) = local_40._4_4_;
  *(int *)(param_1 + 0x74) = local_94;
  if (((longlong)uVar19 < 0x100000000) && ((longlong)uVar19 < 0)) {
    puVar15 = (undefined1 *)0x0;
  }
  else {
    puVar15 = local_1c;
  }
  local_40 = lVar18;
  iVar16 = FUN_006c26f0(param_1,puVar15,uVar19,1,0,1);
  if (iVar16 < 1) {
    return 0xffffff77;
  }
  iVar16 = FUN_006c0d50(*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x6c),param_2,
                        param_3);
  return (iVar16 < 1) - 1 & 0xffffff77;
}

