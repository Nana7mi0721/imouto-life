
int FUN_005f9290(int param_1,undefined1 *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int extraout_EDX;
  uint uVar6;
  uint uVar7;
  undefined1 *puVar8;
  int *piVar9;
  bool bVar10;
  int local_44;
  uint local_3c;
  undefined1 local_38 [4];
  int local_34;
  undefined1 local_28 [36];
  
  do {
    if (*(int *)(param_1 + 0x58) == 4) {
      while( true ) {
        puVar8 = param_2;
        if (param_2 == (undefined1 *)0x0) {
          puVar8 = local_28;
        }
        iVar1 = FUN_006a8d90(param_1 + 0x78,puVar8);
        param_2 = (undefined1 *)0x0;
        if (iVar1 == -1) {
          return -3;
        }
        if (iVar1 < 1) break;
        local_3c = *(uint *)(puVar8 + 0x14);
        uVar6 = *(uint *)(puVar8 + 0x10);
        iVar1 = FUN_006ac280(param_1 + 0x250,puVar8);
        if (iVar1 == 0) {
          iVar1 = FUN_006ad4e0(param_1 + 0x1e0,0);
          if (iVar1 != 0) {
            return -0x81;
          }
          FUN_006ace60(param_1 + 0x1e0,param_1 + 0x250);
          iVar1 = FUN_006ad4e0(param_1 + 0x1e0,0);
          *(double *)(param_1 + 0x70) = (double)iVar1 + *(double *)(param_1 + 0x70);
          *(double *)(param_1 + 0x68) =
               (double)(*(int *)(puVar8 + 4) << 3) + *(double *)(param_1 + 0x68);
          if (((uVar6 & local_3c) != 0xffffffff) && (*(int *)(puVar8 + 0xc) == 0)) {
            if (*(int *)(param_1 + 4) == 0) {
              local_44 = 0;
            }
            else {
              local_44 = *(int *)(param_1 + 0x60);
              if (0 < local_44) {
                puVar3 = (uint *)(local_44 * 0x10 + *(int *)(param_1 + 0x44));
                uVar4 = *puVar3;
                bVar10 = uVar6 < uVar4;
                uVar6 = uVar6 - uVar4;
                local_3c = (local_3c - puVar3[1]) - (uint)bVar10;
              }
            }
            if (((int)local_3c < 1) && ((int)local_3c < 0)) {
              uVar6 = 0;
              local_3c = 0;
            }
            uVar4 = FUN_006ad4e0(param_1 + 0x1e0,0);
            uVar7 = uVar6 - uVar4;
            iVar1 = (local_3c - ((int)uVar4 >> 0x1f)) - (uint)(uVar6 < uVar4);
            if (0 < local_44) {
              puVar3 = (uint *)(*(int *)(param_1 + 0x44) + 8);
              do {
                bVar10 = CARRY4(uVar7,*puVar3);
                uVar7 = uVar7 + *puVar3;
                iVar1 = iVar1 + puVar3[1] + (uint)bVar10;
                puVar3 = puVar3 + 4;
                local_44 = local_44 + -1;
              } while (local_44 != 0);
            }
            *(uint *)(param_1 + 0x50) = uVar7;
            *(int *)(param_1 + 0x54) = iVar1;
          }
          return 1;
        }
      }
    }
    if (1 < *(int *)(param_1 + 0x58)) {
      do {
        if (param_3 == 0) {
          return 0;
        }
        FUN_005f7ef0(param_1,local_38,0xffffffff,0xffffffff);
        if (extraout_EDX < 0) {
          return -2;
        }
        *(double *)(param_1 + 0x68) = (double)(local_34 * 8) + *(double *)(param_1 + 0x68);
        if ((*(int *)(param_1 + 0x58) != 4) ||
           (iVar1 = FUN_006a8360(local_38), *(int *)(param_1 + 0x5c) == iVar1)) goto LAB_005f93ae;
        iVar1 = FUN_006a8260(local_38);
      } while (iVar1 == 0);
      if (param_4 == 0) {
        return -2;
      }
      FUN_006aa580(param_1);
      if (*(int *)(param_1 + 4) == 0) {
        FUN_006abab0(*(undefined4 *)(param_1 + 0x48));
        FUN_006ab9f0(*(undefined4 *)(param_1 + 0x4c));
      }
    }
LAB_005f93ae:
    if (*(int *)(param_1 + 0x58) == 4) goto LAB_005f9443;
    if (2 < *(int *)(param_1 + 0x58)) goto LAB_005f9432;
    if (*(int *)(param_1 + 4) == 0) {
      iVar1 = FUN_005f7cc0(param_1,*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x4c),
                           param_1 + 0x5c,local_38);
      if (iVar1 != 0) {
        return iVar1;
      }
      *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
      goto LAB_005f9432;
    }
    iVar2 = FUN_006a8360(local_38);
    iVar1 = *(int *)(param_1 + 0x34);
    iVar5 = 0;
    if (0 < iVar1) {
      piVar9 = *(int **)(param_1 + 0x40);
      do {
        if (*piVar9 == iVar2) break;
        iVar5 = iVar5 + 1;
        piVar9 = piVar9 + 1;
      } while (iVar5 < iVar1);
    }
    if (iVar5 != iVar1) {
      *(int *)(param_1 + 0x60) = iVar5;
      *(int *)(param_1 + 0x5c) = iVar2;
      FUN_006a8d60(param_1 + 0x78,iVar2);
      *(undefined4 *)(param_1 + 0x58) = 3;
LAB_005f9432:
      iVar1 = FUN_005f9590(param_1);
      if (iVar1 < 0) {
        return iVar1;
      }
LAB_005f9443:
      FUN_006a89a0(param_1 + 0x78,local_38);
    }
  } while( true );
}

