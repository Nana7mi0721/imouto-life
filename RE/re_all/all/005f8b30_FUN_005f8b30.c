
undefined4 FUN_005f8b30(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int extraout_EDX;
  int *piVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  undefined8 uVar9;
  int local_1a4;
  uint local_1a0;
  int local_19c;
  undefined1 local_198 [16];
  undefined1 local_188 [16];
  uint local_178;
  uint local_174;
  undefined1 local_168 [360];
  
  if (1 < *(int *)(param_1 + 0x58)) {
    if (*(int *)(param_1 + 4) == 0) {
      return 0xffffff76;
    }
    if (((-1 < param_3) && (param_3 <= *(int *)(param_1 + 0x14))) &&
       ((param_3 < *(int *)(param_1 + 0x14) || (param_2 <= *(uint *)(param_1 + 0x10))))) {
      iVar6 = param_1 + 0x78;
      *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
      FUN_006a8d60(iVar6,*(undefined4 *)(param_1 + 0x5c));
      FUN_006acdb0(param_1 + 0x1e0);
      iVar1 = FUN_006a9a90(param_1,param_2,param_3);
      if (iVar1 != 0) {
        *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
        FUN_006a8490(local_168);
        FUN_006aa580(param_1);
        return 0xffffff77;
      }
      local_1a4 = 0;
      local_1a0 = 0;
      local_19c = 0;
      FUN_006a83f0(local_168,*(undefined4 *)(param_1 + 0x5c));
      FUN_006a8d00(local_168);
LAB_005f8c1c:
      while ((2 < *(int *)(param_1 + 0x58) && (iVar1 = FUN_006a8d90(local_168,local_188), 0 < iVar1)
             )) {
        iVar1 = *(int *)(param_1 + 0x48) + *(int *)(param_1 + 0x60) * 0x20;
        if (*(int *)(iVar1 + 0x1c) == 0) {
          FUN_006a8d90(iVar6,0);
          break;
        }
        iVar1 = FUN_006ac510(iVar1,local_188);
        if (iVar1 < 0) {
          FUN_006a8d90(iVar6,0);
          iVar1 = 0;
        }
        else if (local_19c == 0) {
          if (local_1a4 != 0) {
            local_1a0 = local_1a0 + (iVar1 + local_1a4 >> 2);
          }
        }
        else {
          FUN_006a8d90(iVar6,0);
        }
        if ((local_178 & local_174) != 0xffffffff) {
          iVar6 = *(int *)(param_1 + 0x60);
          iVar1 = *(int *)(param_1 + 0x44);
          puVar3 = (uint *)(iVar6 * 0x10 + iVar1);
          uVar7 = local_178 - *puVar3;
          iVar4 = (local_174 - *(int *)(iVar6 * 0x10 + 4 + iVar1)) - (uint)(local_178 < *puVar3);
          if ((iVar4 < 1) && (iVar4 < 0)) {
            uVar7 = 0;
            iVar4 = 0;
          }
          if (0 < iVar6) {
            puVar3 = (uint *)(iVar1 + 8);
            do {
              bVar8 = CARRY4(uVar7,*puVar3);
              uVar7 = uVar7 + *puVar3;
              iVar4 = iVar4 + puVar3[1] + (uint)bVar8;
              puVar3 = puVar3 + 4;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
          *(uint *)(param_1 + 0x50) = uVar7 - local_1a0;
          *(uint *)(param_1 + 0x54) = (iVar4 - ((int)local_1a0 >> 0x1f)) - (uint)(uVar7 < local_1a0)
          ;
LAB_005f8e27:
          FUN_006a8490(local_168);
          *(undefined4 *)(param_1 + 0x68) = 0;
          *(undefined4 *)(param_1 + 0x70) = 0;
          *(undefined4 *)(param_1 + 0x6c) = 0;
          *(undefined4 *)(param_1 + 0x74) = 0;
          return 0;
        }
        local_1a4 = iVar1;
      }
      if (local_1a4 != 0) {
        *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
        goto LAB_005f8e27;
      }
      FUN_005f7ef0(param_1,local_198,0xffffffff,0xffffffff);
      if (extraout_EDX < 0) {
        uVar9 = FUN_005f7870(param_1,0xffffffff);
        *(undefined8 *)(param_1 + 0x50) = uVar9;
        goto LAB_005f8e27;
      }
      if (*(int *)(param_1 + 0x58) < 3) {
LAB_005f8d43:
        iVar4 = FUN_006a8360(local_198);
        iVar1 = *(int *)(param_1 + 0x34);
        iVar2 = 0;
        if (0 < iVar1) {
          piVar5 = *(int **)(param_1 + 0x40);
          do {
            if (*piVar5 == iVar4) break;
            iVar2 = iVar2 + 1;
            piVar5 = piVar5 + 1;
          } while (iVar2 < iVar1);
        }
        if (iVar2 == iVar1) goto LAB_005f8c1c;
        *(int *)(param_1 + 0x60) = iVar2;
        *(int *)(param_1 + 0x5c) = iVar4;
        FUN_006a8d60(iVar6,iVar4);
        FUN_006a8d60(local_168,iVar4);
        *(undefined4 *)(param_1 + 0x58) = 3;
      }
      else {
        iVar1 = FUN_006a8360(local_198);
        if ((*(int *)(param_1 + 0x5c) != iVar1) && (iVar1 = FUN_006a8260(local_198), iVar1 != 0)) {
          FUN_006aa580(param_1);
          FUN_006a8490(local_168);
        }
        if (*(int *)(param_1 + 0x58) < 3) goto LAB_005f8d43;
      }
      FUN_006a89a0(iVar6,local_198);
      FUN_006a89a0(local_168,local_198);
      local_19c = FUN_006a8270(local_198);
      goto LAB_005f8c1c;
    }
  }
  return 0xffffff7d;
}

