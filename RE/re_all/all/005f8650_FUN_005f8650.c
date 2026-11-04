
/* WARNING: Removing unreachable block (ram,0x005f88ab) */

void FUN_005f8650(int param_1,undefined4 param_2,undefined4 param_3)

{
  longlong *plVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int extraout_EDX;
  int extraout_EDX_00;
  int iVar8;
  int iVar9;
  bool bVar10;
  longlong lVar11;
  longlong lVar12;
  uint local_38;
  int local_34;
  undefined1 local_30 [16];
  undefined1 local_20 [32];
  
  pvVar3 = _realloc(*(void **)(param_1 + 0x48),*(int *)(param_1 + 0x34) << 5);
  *(void **)(param_1 + 0x48) = pvVar3;
  pvVar3 = _realloc(*(void **)(param_1 + 0x4c),*(int *)(param_1 + 0x34) << 4);
  *(void **)(param_1 + 0x4c) = pvVar3;
  pvVar3 = _malloc(*(int *)(param_1 + 0x34) << 2);
  *(void **)(param_1 + 0x40) = pvVar3;
  pvVar3 = _malloc(*(int *)(param_1 + 0x34) << 3);
  *(void **)(param_1 + 0x3c) = pvVar3;
  pvVar3 = _malloc(*(int *)(param_1 + 0x34) << 4);
  *(void **)(param_1 + 0x44) = pvVar3;
  iVar9 = 0;
  if (0 < *(int *)(param_1 + 0x34)) {
    do {
      if (iVar9 == 0) {
        **(undefined4 **)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x5c);
        puVar2 = *(undefined4 **)(param_1 + 0x3c);
        *puVar2 = param_2;
        puVar2[1] = param_3;
        iVar4 = FUN_006a9a90(param_1,param_2,param_3);
        if (iVar4 != 0) {
          puVar2 = *(undefined4 **)(param_1 + 0x3c);
          *puVar2 = 0xffffffff;
          puVar2[1] = 0xffffffff;
        }
      }
      else {
        iVar4 = FUN_006a9a90(param_1,*(undefined4 *)(*(int *)(param_1 + 0x38) + iVar9 * 8),
                             *(undefined4 *)(*(int *)(param_1 + 0x38) + 4 + iVar9 * 8));
        if (iVar4 == 0) {
          iVar4 = FUN_005f7cc0(param_1,iVar9 * 0x20 + *(int *)(param_1 + 0x48),
                               iVar9 * 0x10 + *(int *)(param_1 + 0x4c),
                               *(int *)(param_1 + 0x40) + iVar9 * 4,0);
          if (iVar4 < 0) {
            iVar4 = *(int *)(param_1 + 0x3c);
            *(undefined4 *)(iVar4 + iVar9 * 8) = 0xffffffff;
            *(undefined4 *)(iVar4 + 4 + iVar9 * 8) = 0xffffffff;
          }
          else {
            iVar4 = *(int *)(param_1 + 0x3c);
            *(undefined4 *)(iVar4 + iVar9 * 8) = *(undefined4 *)(param_1 + 8);
            *(undefined4 *)(iVar4 + 4 + iVar9 * 8) = *(undefined4 *)(param_1 + 0xc);
          }
        }
        else {
          iVar4 = *(int *)(param_1 + 0x3c);
          *(undefined4 *)(iVar4 + iVar9 * 8) = 0xffffffff;
          *(undefined4 *)(iVar4 + 4 + iVar9 * 8) = 0xffffffff;
        }
      }
      if ((*(uint *)(*(int *)(param_1 + 0x3c) + iVar9 * 8) &
          *(uint *)(*(int *)(param_1 + 0x3c) + 4 + iVar9 * 8)) != 0xffffffff) {
        iVar4 = param_1 + 0x78;
        local_38 = 0;
        local_34 = 0;
        lVar11 = 0;
        iVar8 = -1;
        FUN_006a8d60(iVar4,*(undefined4 *)(*(int *)(param_1 + 0x40) + iVar9 * 4));
        FUN_005f7ef0(param_1,local_30,0xffffffff,0xffffffff);
        if (-1 < extraout_EDX) {
          do {
            lVar11 = CONCAT44(local_34,local_38);
            iVar5 = FUN_006a8260(local_30);
            if (iVar5 != 0) break;
            iVar5 = FUN_006a8360(local_30);
            if (iVar5 == *(int *)(*(int *)(param_1 + 0x40) + iVar9 * 4)) {
              FUN_006a89a0(iVar4,local_30);
              iVar5 = FUN_006a8d90(iVar4,local_20);
              while (iVar5 != 0) {
                iVar6 = iVar8;
                if ((0 < iVar5) &&
                   (iVar6 = FUN_006ac510(iVar9 * 0x20 + *(int *)(param_1 + 0x48),local_20),
                   iVar8 != -1)) {
                  uVar7 = iVar6 + iVar8 >> 2;
                  bVar10 = CARRY4(local_38,uVar7);
                  local_38 = local_38 + uVar7;
                  local_34 = local_34 + (iVar6 + iVar8 >> 0x1f) + (uint)bVar10;
                }
                iVar5 = FUN_006a8d90(iVar4,local_20);
                iVar8 = iVar6;
              }
              lVar11 = FUN_006a8280(local_30);
              if (lVar11 != -1) {
                lVar11 = FUN_006a8280(local_30);
                lVar11 = lVar11 - CONCAT44(local_34,local_38);
                break;
              }
            }
            lVar11 = CONCAT44(local_34,local_38);
            FUN_005f7ef0(param_1,local_30,0xffffffff,0xffffffff);
          } while ((0 < extraout_EDX_00) || (-1 < extraout_EDX_00));
          local_34 = (int)((ulonglong)lVar11 >> 0x20);
          if ((local_34 < 1) && (lVar11 < 0)) {
            lVar11 = 0;
          }
        }
        *(longlong *)(iVar9 * 0x10 + *(int *)(param_1 + 0x44)) = lVar11;
      }
      iVar4 = FUN_006a9a90(param_1,*(undefined4 *)(*(int *)(param_1 + 0x38) + 8 + iVar9 * 8),
                           *(undefined4 *)(*(int *)(param_1 + 0x38) + 0xc + iVar9 * 8));
      if (iVar4 == 0) {
        lVar11 = FUN_005f8150(param_1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                              local_30);
        while (-1 < lVar11) {
          do {
            iVar4 = FUN_006a8360(local_30);
            if ((iVar4 == *(int *)(*(int *)(param_1 + 0x40) + iVar9 * 4)) &&
               (lVar12 = FUN_006a8280(local_30), lVar12 != -1)) {
              plVar1 = (longlong *)(iVar9 * 0x10 + *(int *)(param_1 + 0x44));
              lVar11 = FUN_006a8280(local_30);
              plVar1[1] = lVar11 - *plVar1;
              goto LAB_005f8a00;
            }
            *(longlong *)(param_1 + 8) = lVar11;
            lVar11 = FUN_005f8150(param_1,lVar11,local_30);
          } while (0 < (int)((ulonglong)lVar11 >> 0x20));
        }
        FUN_006abab0(iVar9 * 0x20 + *(int *)(param_1 + 0x48));
        FUN_006ab9f0(iVar9 * 0x10 + *(int *)(param_1 + 0x4c));
      }
      else {
        FUN_006abab0(iVar9 * 0x20 + *(int *)(param_1 + 0x48));
        FUN_006ab9f0(iVar9 * 0x10 + *(int *)(param_1 + 0x4c));
      }
LAB_005f8a00:
      iVar9 = iVar9 + 1;
    } while (iVar9 < *(int *)(param_1 + 0x34));
  }
  return;
}

