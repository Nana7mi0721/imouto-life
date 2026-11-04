
int FUN_006ab250(int param_1,undefined1 *param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int extraout_EDX;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  int *piVar10;
  bool bVar11;
  int local_48;
  uint local_3c;
  undefined1 local_38 [4];
  int local_34;
  undefined1 local_28 [36];
  
  do {
    do {
      if ((*(int *)(param_1 + 0x58) == 3) && (iVar2 = FUN_005f9590(param_1), iVar2 < 0)) {
        return iVar2;
      }
      if (*(int *)(param_1 + 0x58) == 4) {
        bVar1 = FUN_006ac590(*(undefined4 *)(param_1 + 0x48));
        while( true ) {
          puVar9 = param_2;
          if (param_2 == (undefined1 *)0x0) {
            puVar9 = local_28;
          }
          iVar2 = FUN_006a8d90(param_1 + 0x78,puVar9);
          param_2 = (undefined1 *)0x0;
          if (iVar2 == -1) {
            return -3;
          }
          if (iVar2 < 1) break;
          local_3c = *(uint *)(puVar9 + 0x14);
          uVar7 = *(uint *)(puVar9 + 0x10);
          iVar2 = FUN_006ac280(param_1 + 0x250,puVar9);
          if (iVar2 == 0) {
            iVar2 = FUN_006ad4e0(param_1 + 0x1e0,0);
            if (iVar2 != 0) {
              return -0x81;
            }
            FUN_006ace60(param_1 + 0x1e0,param_1 + 0x250);
            iVar2 = FUN_006ad4e0(param_1 + 0x1e0,0);
            *(double *)(param_1 + 0x70) =
                 (double)(iVar2 << (bVar1 & 0x1f)) + *(double *)(param_1 + 0x70);
            *(double *)(param_1 + 0x68) =
                 (double)(*(int *)(puVar9 + 4) << 3) + *(double *)(param_1 + 0x68);
            if (((uVar7 & local_3c) != 0xffffffff) && (*(int *)(puVar9 + 0xc) == 0)) {
              if (*(int *)(param_1 + 4) == 0) {
                local_48 = 0;
              }
              else {
                local_48 = *(int *)(param_1 + 0x60);
                if (0 < local_48) {
                  puVar4 = (uint *)(local_48 * 0x10 + *(int *)(param_1 + 0x44));
                  uVar5 = *puVar4;
                  bVar11 = uVar7 < uVar5;
                  uVar7 = uVar7 - uVar5;
                  local_3c = (local_3c - puVar4[1]) - (uint)bVar11;
                }
              }
              if (((int)local_3c < 1) && ((int)local_3c < 0)) {
                uVar7 = 0;
                local_3c = 0;
              }
              iVar2 = FUN_006ad4e0(param_1 + 0x1e0,0);
              uVar5 = iVar2 << (bVar1 & 0x1f);
              uVar8 = uVar7 - uVar5;
              iVar2 = (local_3c - ((int)uVar5 >> 0x1f)) - (uint)(uVar7 < uVar5);
              if (0 < local_48) {
                puVar4 = (uint *)(*(int *)(param_1 + 0x44) + 8);
                do {
                  bVar11 = CARRY4(uVar8,*puVar4);
                  uVar8 = uVar8 + *puVar4;
                  iVar2 = iVar2 + puVar4[1] + (uint)bVar11;
                  puVar4 = puVar4 + 4;
                  local_48 = local_48 + -1;
                } while (local_48 != 0);
              }
              *(uint *)(param_1 + 0x50) = uVar8;
              *(int *)(param_1 + 0x54) = iVar2;
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
          FUN_006a94d0(param_1,local_38,0xffffffff,0xffffffff);
          if (extraout_EDX < 0) {
            return -2;
          }
          *(double *)(param_1 + 0x68) = (double)(local_34 * 8) + *(double *)(param_1 + 0x68);
          if ((*(int *)(param_1 + 0x58) != 4) ||
             (iVar2 = FUN_006a8360(local_38), *(int *)(param_1 + 0x5c) == iVar2)) goto LAB_006ab395;
          iVar2 = FUN_006a8260(local_38);
        } while (iVar2 == 0);
        if (param_4 == 0) {
          return -2;
        }
        FUN_006aa580(param_1);
        if (*(int *)(param_1 + 4) == 0) {
          FUN_006abab0(*(undefined4 *)(param_1 + 0x48));
          FUN_006ab9f0(*(undefined4 *)(param_1 + 0x4c));
        }
      }
LAB_006ab395:
      if ((*(int *)(param_1 + 0x58) == 4) || (2 < *(int *)(param_1 + 0x58))) goto LAB_006ab42a;
      if (*(int *)(param_1 + 4) == 0) {
        iVar2 = FUN_006a9220(param_1,*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x4c)
                             ,0,0,local_38);
        if (iVar2 != 0) {
          return iVar2;
        }
        *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 0x1c8);
        *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
        goto LAB_006ab42a;
      }
      iVar3 = FUN_006a8360(local_38);
      iVar2 = *(int *)(param_1 + 0x34);
      iVar6 = 0;
      if (0 < iVar2) {
        piVar10 = *(int **)(param_1 + 0x40);
        do {
          if (*piVar10 == iVar3) break;
          iVar6 = iVar6 + 1;
          piVar10 = piVar10 + 1;
        } while (iVar6 < iVar2);
      }
    } while (iVar6 == iVar2);
    *(int *)(param_1 + 0x5c) = iVar3;
    *(int *)(param_1 + 0x60) = iVar6;
    FUN_006a8d60(param_1 + 0x78,iVar3);
    *(undefined4 *)(param_1 + 0x58) = 3;
LAB_006ab42a:
    FUN_006a89a0(param_1 + 0x78,local_38);
  } while( true );
}

