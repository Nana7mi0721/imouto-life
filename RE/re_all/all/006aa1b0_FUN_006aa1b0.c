
undefined4 FUN_006aa1b0(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  longlong lVar9;
  undefined8 uVar10;
  int local_1ac;
  uint local_1a8;
  int local_1a4;
  undefined1 local_1a0 [16];
  uint local_190;
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
      if (2 < *(int *)(param_1 + 0x58)) {
        iVar2 = *(int *)(param_1 + 0x60);
        iVar5 = *(int *)(param_1 + 0x38);
        iVar1 = *(int *)(iVar5 + 4 + iVar2 * 8);
        if ((iVar1 <= param_3) && ((iVar1 < param_3 || (*(uint *)(iVar5 + iVar2 * 8) <= param_2))))
        {
          puVar3 = (uint *)(iVar5 + 8 + iVar2 * 8);
          uVar7 = puVar3[1];
          if ((param_3 < (int)uVar7) || ((param_3 <= (int)uVar7 && (param_2 < *puVar3))))
          goto LAB_006aa248;
        }
        FUN_006aa580(param_1);
      }
LAB_006aa248:
      *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
      FUN_006a8d60(param_1 + 0x78,*(undefined4 *)(param_1 + 0x5c));
      FUN_006acdb0(param_1 + 0x1e0);
      iVar1 = FUN_006a9a90(param_1,param_2,param_3);
      if (iVar1 != 0) {
        *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
        FUN_006a8490(local_168);
        FUN_006aa580(param_1);
        return 0xffffff77;
      }
      local_1ac = 0;
      local_1a8 = 0;
      local_1a4 = 0;
      bVar8 = false;
      FUN_006a83f0(local_168,*(undefined4 *)(param_1 + 0x5c));
      FUN_006a8d00(local_168);
LAB_006aa2d4:
      while ((2 < *(int *)(param_1 + 0x58) && (iVar1 = FUN_006a8d90(local_168,local_188), 0 < iVar1)
             )) {
        iVar1 = *(int *)(param_1 + 0x60) * 0x20 + *(int *)(param_1 + 0x48);
        if (*(int *)(iVar1 + 0x1c) == 0) {
          FUN_006a8d90(param_1 + 0x78,0);
          break;
        }
        iVar1 = FUN_006ac510(iVar1,local_188);
        if (iVar1 < 0) {
          FUN_006a8d90(param_1 + 0x78,0);
          iVar1 = 0;
        }
        else if ((local_1a4 == 0) || (bVar8)) {
          if (local_1ac != 0) {
            local_1a8 = local_1a8 + (local_1ac + iVar1 >> 2);
          }
        }
        else {
          FUN_006a8d90(param_1 + 0x78,0);
        }
        if ((local_178 & local_174) != 0xffffffff) {
          iVar1 = *(int *)(param_1 + 0x60);
          iVar2 = *(int *)(param_1 + 0x44);
          puVar3 = (uint *)(iVar1 * 0x10 + iVar2);
          uVar7 = local_178 - *puVar3;
          iVar5 = (local_174 - *(int *)(iVar1 * 0x10 + 4 + iVar2)) - (uint)(local_178 < *puVar3);
          if ((iVar5 < 1) && (iVar5 < 0)) {
            uVar7 = 0;
            iVar5 = 0;
          }
          if (0 < iVar1) {
            puVar3 = (uint *)(iVar2 + 8);
            do {
              bVar8 = CARRY4(uVar7,*puVar3);
              uVar7 = uVar7 + *puVar3;
              iVar5 = iVar5 + puVar3[1] + (uint)bVar8;
              puVar3 = puVar3 + 4;
              iVar1 = iVar1 + -1;
            } while (iVar1 != 0);
          }
          iVar1 = (iVar5 - ((int)local_1a8 >> 0x1f)) - (uint)(uVar7 < local_1a8);
          *(uint *)(param_1 + 0x50) = uVar7 - local_1a8;
          *(int *)(param_1 + 0x54) = iVar1;
          if ((iVar1 < 1) && (iVar1 < 0)) {
            *(undefined4 *)(param_1 + 0x50) = 0;
            *(undefined4 *)(param_1 + 0x54) = 0;
          }
LAB_006aa53d:
          FUN_006a8490(local_168);
          *(undefined4 *)(param_1 + 0x68) = 0;
          *(undefined4 *)(param_1 + 0x70) = 0;
          *(undefined4 *)(param_1 + 0x6c) = 0;
          *(undefined4 *)(param_1 + 0x74) = 0;
          return 0;
        }
        local_1ac = iVar1;
      }
      if (local_1ac != 0) {
        *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
        goto LAB_006aa53d;
      }
      lVar9 = FUN_006a94d0(param_1,local_1a0,0xffffffff,0xffffffff);
      iVar1 = (int)((ulonglong)lVar9 >> 0x20);
      local_190 = (uint)lVar9;
      if (lVar9 < 0) {
        uVar10 = FUN_006aa140(param_1,0xffffffff);
        *(undefined8 *)(param_1 + 0x50) = uVar10;
        goto LAB_006aa53d;
      }
      if (*(int *)(param_1 + 0x58) < 3) {
LAB_006aa413:
        iVar5 = FUN_006a8360(local_1a0);
        iVar2 = *(int *)(param_1 + 0x34);
        iVar6 = 0;
        if (0 < iVar2) {
          piVar4 = *(int **)(param_1 + 0x40);
          do {
            if (*piVar4 == iVar5) break;
            iVar6 = iVar6 + 1;
            piVar4 = piVar4 + 1;
          } while (iVar6 < iVar2);
        }
        if (iVar6 == iVar2) goto LAB_006aa2d4;
        *(int *)(param_1 + 0x60) = iVar6;
        *(int *)(param_1 + 0x5c) = iVar5;
        FUN_006a8d60(param_1 + 0x78,iVar5);
        FUN_006a8d60(local_168,iVar5);
        *(undefined4 *)(param_1 + 0x58) = 3;
        iVar2 = *(int *)(*(int *)(param_1 + 0x3c) + 4 + iVar6 * 8);
        if ((iVar2 < iVar1) ||
           ((iVar2 <= iVar1 && (*(uint *)(*(int *)(param_1 + 0x3c) + iVar6 * 8) < local_190)))) {
          bVar8 = false;
        }
        else {
          bVar8 = true;
        }
      }
      else {
        iVar2 = FUN_006a8360(local_1a0);
        if ((*(int *)(param_1 + 0x5c) != iVar2) && (iVar2 = FUN_006a8260(local_1a0), iVar2 != 0)) {
          FUN_006aa580(param_1);
          FUN_006a8490(local_168);
        }
        if (*(int *)(param_1 + 0x58) < 3) goto LAB_006aa413;
      }
      FUN_006a89a0(param_1 + 0x78,local_1a0);
      FUN_006a89a0(local_168,local_1a0);
      local_1a4 = FUN_006a8270(local_1a0);
      goto LAB_006aa2d4;
    }
  }
  return 0xffffff7d;
}

