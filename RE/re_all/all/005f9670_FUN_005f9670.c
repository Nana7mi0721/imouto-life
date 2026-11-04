
/* WARNING: Removing unreachable block (ram,0x005f9961) */
/* WARNING: Removing unreachable block (ram,0x005f98ec) */
/* WARNING: Removing unreachable block (ram,0x005f9927) */
/* WARNING: Removing unreachable block (ram,0x005f999f) */

int FUN_005f9670(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  undefined4 uVar10;
  int extraout_EDX;
  int *piVar11;
  longlong lVar12;
  undefined8 uVar13;
  int local_38;
  longlong local_30 [2];
  undefined1 local_20 [16];
  uint local_10;
  uint local_c;
  
  local_38 = 0;
  iVar3 = FUN_005f99c0(param_1,param_2,param_3);
  if ((iVar3 < 0) || (iVar3 = FUN_005f9590(param_1), iVar3 != 0)) {
    return iVar3;
  }
LAB_005f96af:
  while( true ) {
    iVar3 = param_1 + 0x78;
    iVar4 = FUN_006a8ef0(iVar3,local_20);
    if (iVar4 < 1) break;
    iVar4 = FUN_006ac510(*(int *)(param_1 + 0x60) * 0x20 + *(int *)(param_1 + 0x48),local_20);
    if (iVar4 < 0) {
      FUN_006a8d90(iVar3,0);
    }
    else {
      if (local_38 != 0) {
        uVar7 = *(uint *)(param_1 + 0x50);
        uVar5 = local_38 + iVar4 >> 2;
        *(uint *)(param_1 + 0x50) = uVar7 + uVar5;
        *(uint *)(param_1 + 0x54) =
             *(int *)(param_1 + 0x54) + (local_38 + iVar4 >> 0x1f) + (uint)CARRY4(uVar7,uVar5);
      }
      iVar6 = FUN_006aba60(*(undefined4 *)(param_1 + 0x48),1);
      uVar7 = iVar6 + iVar4 >> 2;
      iVar6 = (iVar6 + iVar4 >> 0x1f) + *(int *)(param_1 + 0x54) +
              (uint)CARRY4(uVar7,*(uint *)(param_1 + 0x50));
      if ((param_3 < iVar6) ||
         ((param_3 <= iVar6 && (param_2 <= uVar7 + *(uint *)(param_1 + 0x50))))) {
LAB_005f98a2:
        *(undefined4 *)(param_1 + 0x68) = 0;
        *(undefined4 *)(param_1 + 0x70) = 0;
        *(undefined4 *)(param_1 + 0x6c) = 0;
        *(undefined4 *)(param_1 + 0x74) = 0;
        bVar2 = FUN_006ac590(*(undefined4 *)(param_1 + 0x48));
        __allshr();
        local_30[0] = __allshl();
        if (*(longlong *)(param_1 + 0x50) < local_30[0]) {
          do {
            lVar12 = __allshr();
            iVar3 = FUN_006ad4e0(param_1 + 0x1e0,0);
            if (lVar12 < iVar3) {
              iVar3 = (int)lVar12;
            }
            FUN_006ad540(param_1 + 0x1e0,iVar3);
            uVar5 = iVar3 << (bVar2 & 0x1f);
            uVar7 = *(uint *)(param_1 + 0x50);
            *(uint *)(param_1 + 0x50) = uVar7 + uVar5;
            *(uint *)(param_1 + 0x54) =
                 *(int *)(param_1 + 0x54) + ((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar7,uVar5);
            if (iVar3 < lVar12) {
              iVar3 = FUN_005f9290(param_1,0,1,1);
              if (iVar3 < 1) {
                uVar13 = FUN_005f7870(param_1,0xffffffff);
                *(undefined8 *)(param_1 + 0x50) = uVar13;
              }
            }
          } while (*(longlong *)(param_1 + 0x50) < local_30[0]);
        }
        return 0;
      }
      FUN_006a8d90(iVar3,0);
      FUN_006ac420(param_1 + 0x250,local_20);
      FUN_006ace60(param_1 + 0x1e0,param_1 + 0x250);
      if ((-2 < (int)local_c) && (local_c < 0x80000000)) {
        iVar3 = *(int *)(param_1 + 0x60);
        iVar6 = *(int *)(param_1 + 0x44);
        puVar8 = (uint *)(iVar3 * 0x10 + iVar6);
        uVar7 = *puVar8;
        iVar9 = *(int *)(iVar3 * 0x10 + 4 + iVar6);
        *(uint *)(param_1 + 0x50) = local_10 - *puVar8;
        *(uint *)(param_1 + 0x54) = (local_c - iVar9) - (uint)(local_10 < uVar7);
        if ((*(int *)(param_1 + 0x54) < 1) && (*(int *)(param_1 + 0x54) < 0)) {
          *(undefined4 *)(param_1 + 0x50) = 0;
          *(undefined4 *)(param_1 + 0x54) = 0;
        }
        if (0 < iVar3) {
          puVar8 = (uint *)(iVar6 + 8);
          do {
            uVar7 = *puVar8;
            uVar5 = *(uint *)(param_1 + 0x50);
            uVar1 = puVar8[1];
            *(uint *)(param_1 + 0x50) = uVar5 + uVar7;
            puVar8 = puVar8 + 4;
            iVar3 = iVar3 + -1;
            *(uint *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + uVar1 + (uint)CARRY4(uVar5,uVar7)
            ;
          } while (iVar3 != 0);
        }
      }
      local_38 = iVar4;
    }
  }
  if (((iVar4 < 0) && (iVar4 != -3)) ||
     (FUN_005f7ef0(param_1,local_30,0xffffffff,0xffffffff), extraout_EDX < 0)) goto LAB_005f98a2;
  iVar4 = FUN_006a8260(local_30);
  if (iVar4 != 0) {
    FUN_006aa580(param_1);
  }
  if (*(int *)(param_1 + 0x58) < 3) goto code_r0x005f982d;
  goto LAB_005f988f;
code_r0x005f982d:
  iVar6 = FUN_006a8360(local_30);
  iVar4 = *(int *)(param_1 + 0x34);
  iVar9 = 0;
  if (0 < iVar4) {
    piVar11 = *(int **)(param_1 + 0x40);
    do {
      if (*piVar11 == iVar6) break;
      iVar9 = iVar9 + 1;
      piVar11 = piVar11 + 1;
    } while (iVar9 < iVar4);
  }
  if (iVar9 != iVar4) {
    *(int *)(param_1 + 0x60) = iVar9;
    *(undefined4 *)(param_1 + 0x58) = 3;
    uVar10 = FUN_006a8360(local_30);
    *(undefined4 *)(param_1 + 0x5c) = uVar10;
    FUN_006a8d60(iVar3,iVar6);
    iVar4 = FUN_005f9590(param_1);
    if (iVar4 != 0) {
      return iVar4;
    }
    local_38 = 0;
LAB_005f988f:
    FUN_006a89a0(iVar3,local_30);
  }
  goto LAB_005f96af;
}

