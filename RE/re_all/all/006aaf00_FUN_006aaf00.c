
/* WARNING: Removing unreachable block (ram,0x006ab1f8) */
/* WARNING: Removing unreachable block (ram,0x006ab17f) */
/* WARNING: Removing unreachable block (ram,0x006ab1be) */
/* WARNING: Removing unreachable block (ram,0x006ab236) */

int FUN_006aaf00(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
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
  iVar4 = FUN_006aa5b0(param_1,param_2,param_3);
  if ((iVar4 < 0) || (iVar4 = FUN_005f9590(param_1), iVar4 != 0)) {
    return iVar4;
  }
LAB_006aaf3d:
  while( true ) {
    iVar4 = param_1 + 0x78;
    iVar5 = FUN_006a8ef0(iVar4,local_20);
    if (iVar5 < 1) break;
    iVar5 = FUN_006ac510(*(int *)(param_1 + 0x60) * 0x20 + *(int *)(param_1 + 0x48),local_20);
    if (iVar5 < 0) {
      FUN_006a8d90(iVar4,0);
    }
    else {
      if (local_38 != 0) {
        uVar8 = *(uint *)(param_1 + 0x50);
        uVar6 = local_38 + iVar5 >> 2;
        *(uint *)(param_1 + 0x50) = uVar8 + uVar6;
        *(uint *)(param_1 + 0x54) =
             *(int *)(param_1 + 0x54) + (local_38 + iVar5 >> 0x1f) + (uint)CARRY4(uVar8,uVar6);
      }
      iVar7 = FUN_006aba60(*(undefined4 *)(param_1 + 0x48),1);
      uVar8 = iVar7 + iVar5 >> 2;
      iVar7 = (iVar7 + iVar5 >> 0x1f) + *(int *)(param_1 + 0x54) +
              (uint)CARRY4(uVar8,*(uint *)(param_1 + 0x50));
      if ((param_3 < iVar7) ||
         ((param_3 <= iVar7 && (param_2 <= uVar8 + *(uint *)(param_1 + 0x50))))) {
LAB_006ab137:
        *(undefined4 *)(param_1 + 0x68) = 0;
        *(undefined4 *)(param_1 + 0x70) = 0;
        *(undefined4 *)(param_1 + 0x6c) = 0;
        *(undefined4 *)(param_1 + 0x74) = 0;
        bVar3 = FUN_006ac590(*(undefined4 *)(param_1 + 0x48));
        __allshr();
        local_30[0] = __allshl();
        if (*(longlong *)(param_1 + 0x50) < local_30[0]) {
          do {
            lVar12 = __allshr();
            iVar4 = FUN_006ad4e0(param_1 + 0x1e0,0);
            if (lVar12 < iVar4) {
              iVar4 = (int)lVar12;
            }
            FUN_006ad540(param_1 + 0x1e0,iVar4);
            uVar6 = iVar4 << (bVar3 & 0x1f);
            uVar8 = *(uint *)(param_1 + 0x50);
            *(uint *)(param_1 + 0x50) = uVar8 + uVar6;
            *(uint *)(param_1 + 0x54) =
                 *(int *)(param_1 + 0x54) + ((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar8,uVar6);
            if (iVar4 < lVar12) {
              iVar4 = FUN_006ab250(param_1,0,1,1);
              if (iVar4 < 1) {
                uVar13 = FUN_006aa140(param_1,0xffffffff);
                *(undefined8 *)(param_1 + 0x50) = uVar13;
              }
            }
          } while (*(longlong *)(param_1 + 0x50) < local_30[0]);
        }
        return 0;
      }
      FUN_006a8d90(iVar4,0);
      FUN_006ac420(param_1 + 0x250,local_20);
      FUN_006ace60(param_1 + 0x1e0,param_1 + 0x250);
      if ((-2 < (int)local_c) && (local_c < 0x80000000)) {
        iVar4 = *(int *)(param_1 + 0x60);
        iVar7 = *(int *)(param_1 + 0x44);
        puVar9 = (uint *)(iVar4 * 0x10 + iVar7);
        uVar8 = *puVar9;
        iVar1 = *(int *)(iVar4 * 0x10 + 4 + iVar7);
        *(uint *)(param_1 + 0x50) = local_10 - *puVar9;
        *(uint *)(param_1 + 0x54) = (local_c - iVar1) - (uint)(local_10 < uVar8);
        if ((*(int *)(param_1 + 0x54) < 1) && (*(int *)(param_1 + 0x54) < 0)) {
          *(undefined4 *)(param_1 + 0x50) = 0;
          *(undefined4 *)(param_1 + 0x54) = 0;
        }
        if (0 < iVar4) {
          puVar9 = (uint *)(iVar7 + 8);
          do {
            uVar8 = *puVar9;
            uVar6 = *(uint *)(param_1 + 0x50);
            uVar2 = puVar9[1];
            *(uint *)(param_1 + 0x50) = uVar6 + uVar8;
            puVar9 = puVar9 + 4;
            iVar4 = iVar4 + -1;
            *(uint *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + uVar2 + (uint)CARRY4(uVar6,uVar8)
            ;
          } while (iVar4 != 0);
        }
      }
      local_38 = iVar5;
    }
  }
  if (((iVar5 < 0) && (iVar5 != -3)) ||
     (FUN_006a94d0(param_1,local_30,0xffffffff,0xffffffff), extraout_EDX < 0)) goto LAB_006ab137;
  iVar4 = FUN_006a8260(local_30);
  if (iVar4 != 0) {
    FUN_006aa580(param_1);
  }
  if (*(int *)(param_1 + 0x58) < 3) goto code_r0x006ab0bd;
  goto LAB_006ab122;
code_r0x006ab0bd:
  iVar5 = FUN_006a8360(local_30);
  iVar4 = *(int *)(param_1 + 0x34);
  iVar7 = 0;
  if (0 < iVar4) {
    piVar11 = *(int **)(param_1 + 0x40);
    do {
      if (*piVar11 == iVar5) break;
      iVar7 = iVar7 + 1;
      piVar11 = piVar11 + 1;
    } while (iVar7 < iVar4);
  }
  if (iVar7 != iVar4) {
    *(int *)(param_1 + 0x60) = iVar7;
    *(undefined4 *)(param_1 + 0x58) = 3;
    uVar10 = FUN_006a8360(local_30);
    *(undefined4 *)(param_1 + 0x5c) = uVar10;
    FUN_006a8d60(param_1 + 0x78,iVar5);
    iVar4 = FUN_005f9590(param_1);
    if (iVar4 != 0) {
      return iVar4;
    }
    local_38 = 0;
LAB_006ab122:
    FUN_006a89a0(param_1 + 0x78,local_30);
  }
  goto LAB_006aaf3d;
}

