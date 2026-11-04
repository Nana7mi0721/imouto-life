
/* WARNING: Removing unreachable block (ram,0x006aaa23) */
/* WARNING: Removing unreachable block (ram,0x006aa7a9) */
/* WARNING: Removing unreachable block (ram,0x006aa625) */
/* WARNING: Removing unreachable block (ram,0x006aa93e) */
/* WARNING: Removing unreachable block (ram,0x006aad4d) */
/* WARNING: Removing unreachable block (ram,0x006aaa56) */

uint FUN_006aa5b0(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  bool bVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint extraout_EDX;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  longlong lVar19;
  longlong lVar20;
  longlong lVar21;
  longlong lVar22;
  uint local_a4;
  uint local_a0;
  int local_9c;
  int local_98;
  int local_94;
  uint local_90;
  int local_8c;
  uint local_88;
  int local_84;
  uint local_68;
  int local_64;
  undefined8 local_50;
  int local_40;
  int iStack_3c;
  undefined1 local_38 [16];
  undefined8 local_28;
  undefined1 local_20 [16];
  uint local_10;
  uint local_c;
  
  uVar16 = 0;
  lVar19 = FUN_006aa140(param_1,0xffffffff);
  if (*(int *)(param_1 + 0x58) < 2) {
    return 0xffffff7d;
  }
  if (*(int *)(param_1 + 4) == 0) {
    return 0xffffff76;
  }
  if (param_3 < 0) {
    return 0xffffff7d;
  }
  if (lVar19 < CONCAT44(param_3,param_2)) {
    return 0xffffff7d;
  }
  local_94 = *(int *)(param_1 + 0x34) + -1;
  lVar3 = lVar19;
  if (-1 < local_94) {
    puVar11 = (uint *)(*(int *)(param_1 + 0x44) + 8 + local_94 * 0x10);
    do {
      uVar15 = (uint)lVar19;
      iVar14 = ((int)((ulonglong)lVar19 >> 0x20) - puVar11[1]) - (uint)(uVar15 < *puVar11);
      lVar3 = lVar19 - *(longlong *)puVar11;
      lVar19 = lVar19 - *(longlong *)puVar11;
      if ((iVar14 < param_3) || ((iVar14 <= param_3 && (uVar15 - *puVar11 <= param_2)))) break;
      local_94 = local_94 + -1;
      puVar11 = puVar11 + -4;
    } while (-1 < local_94);
  }
  local_8c = (int)((ulonglong)lVar3 >> 0x20);
  local_90 = (uint)lVar3;
  bVar2 = false;
  uVar15 = *(uint *)(*(int *)(param_1 + 0x38) + 8 + local_94 * 8);
  uVar18 = *(uint *)(*(int *)(param_1 + 0x38) + 0xc + local_94 * 8);
  local_a4 = *(uint *)(*(int *)(param_1 + 0x3c) + local_94 * 8);
  iVar14 = local_94 * 8;
  local_a0 = *(uint *)(*(int *)(param_1 + 0x3c) + 4 + iVar14);
  puVar11 = (uint *)(local_94 * 0x10 + *(int *)(param_1 + 0x44));
  uVar10 = *puVar11;
  lVar21 = *(longlong *)puVar11;
  lVar19 = *(longlong *)puVar11;
  iVar17 = puVar11[2] + uVar10;
  iVar12 = puVar11[3] + puVar11[1] + (uint)CARRY4(puVar11[2],uVar10);
  uVar13 = (uVar10 - local_90) + param_2;
  iVar9 = ((puVar11[1] - local_8c) - (uint)(uVar10 < local_90)) + param_3 +
          (uint)CARRY4(uVar10 - local_90,param_2);
  if ((local_a4 == uVar15) && (local_a0 == uVar18)) {
    uVar16 = FUN_006a9a90(param_1,local_a4,local_a0);
    if (uVar16 != 0) goto LAB_006aad7c;
    lVar20 = FUN_006a94d0(param_1,local_38,1,0);
    uVar16 = (uint)lVar20;
    if (lVar20 < 0) goto LAB_006aad7c;
    bVar2 = true;
  }
  lVar20 = CONCAT44(local_50._4_4_,(undefined4)local_50);
  local_50 = CONCAT44(local_50._4_4_,(undefined4)local_50);
  local_28 = CONCAT44(local_28._4_4_,(undefined4)local_28);
  if ((int)local_a0 <= (int)uVar18) {
    lVar4 = -1;
    lVar5 = CONCAT44(iVar12,iVar17);
    lVar7 = CONCAT44(uVar18,uVar15);
    local_50 = lVar20;
    if ((int)uVar18 <= (int)local_a0) {
      lVar19 = lVar21;
      lVar4 = -1;
      lVar5 = CONCAT44(iVar12,iVar17);
      lVar7 = CONCAT44(uVar18,uVar15);
      local_28 = CONCAT44(local_28._4_4_,(undefined4)local_28);
      if (uVar15 <= local_a4) goto LAB_006aaa79;
    }
    do {
      local_64 = (int)((ulonglong)lVar19 >> 0x20);
      local_68 = (uint)lVar19;
      local_28 = lVar7 - CONCAT44(local_a0,local_a4);
      if (local_28 < 0x10000) {
        uVar15 = local_a4;
        uVar18 = local_a0;
      }
      else {
        local_40 = uVar13 - local_68;
        iStack_3c = (iVar9 - local_64) - (uint)(uVar13 < local_68);
        local_50 = lVar5 - lVar19;
        lVar21 = __ftol();
        lVar21 = lVar21 + CONCAT44(local_a0,local_a4);
        uVar16 = (uint)lVar21;
        uVar15 = uVar16 - 0x10000;
        uVar18 = (int)((ulonglong)lVar21 >> 0x20) - (uint)(uVar16 < 0x10000);
        iVar12 = local_a0 + (0xfffeffff < local_a4);
        if ((int)uVar18 <= iVar12) {
          if (iVar12 <= (int)uVar18) {
            if (local_a4 + 0x10000 <= uVar15) goto LAB_006aa837;
          }
          uVar15 = local_a4;
          uVar18 = local_a0;
        }
      }
LAB_006aa837:
      uVar16 = FUN_006a9a90(param_1,uVar15,uVar18);
      if (uVar16 != 0) goto LAB_006aad7c;
LAB_006aa84f:
      lVar21 = CONCAT44(uVar18,uVar15);
      local_98 = (int)((ulonglong)lVar7 >> 0x20);
      local_9c = (int)lVar7;
      local_84 = (int)((ulonglong)lVar4 >> 0x20);
      local_88 = (uint)lVar4;
      lVar20 = FUN_006a94d0(param_1,local_38,lVar7 - *(longlong *)(param_1 + 8));
      uVar16 = (uint)lVar20;
      if (lVar20 == -0x80) goto LAB_006aad7c;
      lVar6 = lVar4;
      if ((lVar20 < 0x100000000) && (lVar20 < 0)) {
        uVar10 = local_a0 + (0xfffffffe < local_a4);
        if (((int)uVar18 < (int)uVar10) ||
           (((int)uVar18 <= (int)uVar10 && (uVar15 <= local_a4 + 1)))) break;
        if (uVar15 == 0 && uVar18 == 0) goto LAB_006aad7c;
        uVar16 = uVar15 - 0x10000;
        uVar18 = (uVar18 - 1) + (uint)(0xffff < uVar15);
        uVar15 = uVar16;
        if (((int)uVar18 <= (int)local_a0) &&
           (((int)uVar18 < (int)local_a0 || (uVar16 <= local_a4)))) {
          uVar15 = local_a4 + 1;
          uVar18 = uVar10;
        }
        uVar16 = FUN_006a9a90(param_1,uVar15,uVar18);
joined_r0x006aa8ec:
        lVar8 = CONCAT44(local_84,uVar16);
        if (uVar16 != 0) goto LAB_006aad7c;
LAB_006aaa11:
        local_84 = (int)((ulonglong)lVar8 >> 0x20);
        uVar16 = (uint)lVar8;
        lVar4 = CONCAT44(local_84,local_88);
        lVar6 = CONCAT44(local_84,local_88);
        if (lVar7 <= CONCAT44(local_a0,local_a4)) break;
        goto LAB_006aa84f;
      }
      bVar2 = true;
      iVar12 = FUN_006a8360(local_38);
      lVar8 = CONCAT44(local_84,uVar16);
      if (iVar12 != *(int *)(*(int *)(param_1 + 0x40) + local_94 * 4)) goto LAB_006aaa11;
      lVar22 = FUN_006a8280(local_38);
      lVar8 = CONCAT44(local_84,uVar16);
      if (lVar22 == -1) goto LAB_006aaa11;
      if (lVar22 < CONCAT44(iVar9,uVar13)) {
        uVar15 = *(uint *)(param_1 + 8);
        uVar18 = *(uint *)(param_1 + 0xc);
        iVar12 = (iVar9 - (int)((ulonglong)lVar22 >> 0x20)) - (uint)(uVar13 < (uint)lVar22);
        local_a4 = uVar15;
        local_a0 = uVar18;
        lVar19 = lVar22;
        lVar4 = lVar20;
        lVar21 = lVar7;
        if ((0 < iVar12) || ((-1 < iVar12 && (0xac44 < uVar13 - (uint)lVar22)))) goto LAB_006aaa44;
        local_88 = uVar16;
        lVar8 = lVar20;
        goto LAB_006aaa11;
      }
      uVar10 = local_a0 + (0xfffffffe < local_a4);
      if (((int)uVar18 < (int)uVar10) || (((int)uVar18 <= (int)uVar10 && (uVar15 <= local_a4 + 1))))
      break;
      if ((local_9c == *(int *)(param_1 + 8)) && (local_98 == *(int *)(param_1 + 0xc))) {
        uVar16 = uVar15 - 0x10000;
        uVar18 = (uVar18 - 1) + (uint)(0xffff < uVar15);
        uVar15 = uVar16;
        if (((int)uVar18 <= (int)local_a0) &&
           (((int)uVar18 < (int)local_a0 || (uVar16 <= local_a4)))) {
          uVar15 = local_a4 + 1;
          uVar18 = uVar10;
        }
        uVar16 = FUN_006a9a90(param_1,uVar15,uVar18);
        lVar7 = lVar20;
        goto joined_r0x006aa8ec;
      }
      lVar5 = lVar22;
LAB_006aaa44:
      lVar6 = lVar4;
      lVar7 = lVar21;
    } while (CONCAT44(local_a0,local_a4) < lVar21);
    local_84 = (int)((ulonglong)lVar6 >> 0x20);
    local_88 = (uint)lVar6;
    if (lVar6 != -1) {
      uVar16 = FUN_006a9a90(param_1,lVar6);
      *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
      if (uVar16 == 0) {
        lVar19 = FUN_006a94d0(param_1,&local_50,0xffffffff,0xffffffff);
        uVar16 = (uint)lVar19;
        if (-1 < lVar19) {
          if (local_94 == *(int *)(param_1 + 0x60)) {
            FUN_006acdb0(param_1 + 0x1e0);
          }
          else {
            FUN_006aa580(param_1);
            *(int *)(param_1 + 0x60) = local_94;
            uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x40) + local_94 * 4);
            *(undefined4 *)(param_1 + 0x58) = 3;
            *(undefined4 *)(param_1 + 0x5c) = uVar1;
          }
          FUN_006a8d60(param_1 + 0x78,*(undefined4 *)(param_1 + 0x5c));
          FUN_006a89a0(param_1 + 0x78,&local_50);
          do {
            iVar12 = FUN_006a8ef0(param_1 + 0x78,local_20);
            iVar9 = iVar12 >> 0x1f;
            if (iVar12 == 0) {
              puVar11 = (uint *)(*(int *)(param_1 + 0x3c) + iVar14);
              uVar16 = puVar11[1];
              iVar9 = local_84;
              if (((int)uVar16 <= local_84) &&
                 ((lVar19 = lVar6, (int)uVar16 < local_84 || (*puVar11 < local_88)))) {
                do {
                  lVar19 = FUN_006aadb0(param_1,lVar19,&local_50);
                  iVar9 = (int)((ulonglong)lVar19 >> 0x20);
                  uVar16 = (uint)lVar19;
                  if (lVar19 < 0) goto LAB_006aad7c;
                  iVar12 = FUN_006a8360(&local_50);
                  if (iVar12 == *(int *)(param_1 + 0x5c)) {
                    FUN_006a8280(&local_50);
                    if (extraout_EDX < 0x80000000) {
LAB_006aacb6:
                      uVar16 = FUN_006aa1b0(param_1,lVar19);
                      return uVar16;
                    }
                    iVar12 = FUN_006a8250(&local_50);
                    if (iVar12 == 0) goto LAB_006aacb6;
                  }
                  puVar11 = (uint *)(*(int *)(param_1 + 0x3c) + iVar14);
                  uVar15 = puVar11[1];
                } while (((int)uVar15 < iVar9) || (((int)uVar15 <= iVar9 && (*puVar11 < uVar16))));
              }
            }
            if (iVar9 < 0) {
              uVar16 = 0xffffff78;
              break;
            }
            if ((local_10 & local_c) != 0xffffffff) goto LAB_006aacd6;
            FUN_006a8d90(param_1 + 0x78,0);
          } while( true );
        }
      }
      goto LAB_006aad7c;
    }
  }
LAB_006aaa79:
  if (((!bVar2) || (puVar11 = (uint *)(*(int *)(param_1 + 0x3c) + iVar14), local_a4 != *puVar11)) ||
     (local_a0 != puVar11[1])) goto LAB_006aad7c;
  iVar14 = FUN_006a8360(local_38);
  if (iVar14 != *(int *)(*(int *)(param_1 + 0x40) + local_94 * 4)) goto LAB_006aad7c;
  *(longlong *)(param_1 + 0x50) = lVar3;
  if (local_94 == *(int *)(param_1 + 0x60)) {
    FUN_006acdb0(param_1 + 0x1e0);
  }
  else {
    FUN_006aa580(param_1);
    *(int *)(param_1 + 0x60) = local_94;
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x40) + local_94 * 4);
    *(undefined4 *)(param_1 + 0x58) = 3;
    *(undefined4 *)(param_1 + 0x5c) = uVar1;
  }
  FUN_006a8d60(param_1 + 0x78,*(undefined4 *)(param_1 + 0x5c));
  FUN_006a89a0(param_1 + 0x78,local_38);
LAB_006aad1e:
  if ((*(int *)(param_1 + 0x54) <= param_3) &&
     ((*(int *)(param_1 + 0x54) < param_3 || (*(uint *)(param_1 + 0x50) <= param_2)))) {
    lVar19 = FUN_006aa140(param_1,0xffffffff);
    if (CONCAT44(param_3,param_2) <= lVar19) {
      *(undefined4 *)(param_1 + 0x68) = 0;
      *(undefined4 *)(param_1 + 0x70) = 0;
      *(undefined4 *)(param_1 + 0x6c) = 0;
      *(undefined4 *)(param_1 + 0x74) = 0;
      return 0;
    }
  }
  uVar16 = 0xffffff7f;
LAB_006aad7c:
  *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
  FUN_006aa580(param_1);
  return uVar16;
LAB_006aacd6:
  puVar11 = (uint *)(*(int *)(param_1 + 0x60) * 0x10 + *(int *)(param_1 + 0x44));
  uVar16 = *puVar11;
  uVar15 = puVar11[1];
  *(uint *)(param_1 + 0x50) = local_10 - *puVar11;
  iVar14 = (local_c - uVar15) - (uint)(local_10 < uVar16);
  *(int *)(param_1 + 0x54) = iVar14;
  if ((iVar14 < 1) && (iVar14 < 0)) {
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  uVar16 = *(uint *)(param_1 + 0x50);
  *(uint *)(param_1 + 0x50) = uVar16 + local_90;
  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + local_8c + (uint)CARRY4(uVar16,local_90);
  goto LAB_006aad1e;
}

