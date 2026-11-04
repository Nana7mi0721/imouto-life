
undefined4 FUN_00672780(int param_1,int param_2,uint param_3,int param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  char *pcVar9;
  uint local_c;
  undefined4 *local_8;
  int local_4;
  
  if ((((param_1 != 0) && (param_2 != 0)) && (0 < param_4)) && (param_3 != 0)) {
    iVar3 = *(int *)(param_2 + 0x80);
    if (*(int *)(param_2 + 0x84) - iVar3 < param_4) {
      if (0x7fffffff - iVar3 < param_4) {
LAB_00672812:
        FUN_00668bc0(param_1,s_too_many_text_chunks_00a0cc18,1);
        return 1;
      }
      if (iVar3 + param_4 < 0x7ffffff7) {
        uVar8 = iVar3 + param_4 + 8U & 0xfffffff8;
      }
      else {
        uVar8 = 0x7fffffff;
      }
      iVar3 = FUN_0066ca40(param_1,*(undefined4 *)(param_2 + 0x88),iVar3,uVar8 - iVar3,0x1c);
      if (iVar3 == 0) goto LAB_00672812;
      FUN_0066cb60(param_1,*(undefined4 *)(param_2 + 0x88));
      *(int *)(param_2 + 0x88) = iVar3;
      *(uint *)(param_2 + 0xe8) = *(uint *)(param_2 + 0xe8) | 0x4000;
      *(uint *)(param_2 + 0x84) = uVar8;
    }
    local_4 = 0;
    if (0 < param_4) {
      local_8 = (undefined4 *)(param_3 + 0x14);
      do {
        piVar1 = (int *)(*(int *)(param_2 + 0x88) + *(int *)(param_2 + 0x80) * 0x1c);
        if ((char *)local_8[-4] != (char *)0x0) {
          iVar3 = local_8[-5];
          if ((iVar3 < -1) || (2 < iVar3)) {
            FUN_00668bc0(param_1,s_text_compression_mode_is_out_of_r_00a0cbf0,1);
          }
          else {
            uVar8 = 0xffffffff;
            pcVar9 = (char *)local_8[-4];
            do {
              if (uVar8 == 0) break;
              uVar8 = uVar8 - 1;
              cVar2 = *pcVar9;
              pcVar9 = pcVar9 + 1;
            } while (cVar2 != '\0');
            uVar6 = 0;
            uVar8 = ~uVar8 - 1;
            if (iVar3 < 1) {
              param_3 = 0;
            }
            else {
              if ((char *)*local_8 == (char *)0x0) {
                param_3 = 0;
              }
              else {
                uVar6 = 0xffffffff;
                pcVar9 = (char *)*local_8;
                do {
                  if (uVar6 == 0) break;
                  uVar6 = uVar6 - 1;
                  cVar2 = *pcVar9;
                  pcVar9 = pcVar9 + 1;
                } while (cVar2 != '\0');
                param_3 = ~uVar6 - 1;
              }
              if ((char *)local_8[1] == (char *)0x0) {
                uVar6 = 0;
              }
              else {
                uVar6 = 0xffffffff;
                pcVar9 = (char *)local_8[1];
                do {
                  if (uVar6 == 0) break;
                  uVar6 = uVar6 - 1;
                  cVar2 = *pcVar9;
                  pcVar9 = pcVar9 + 1;
                } while (cVar2 != '\0');
                uVar6 = ~uVar6 - 1;
              }
            }
            pcVar9 = (char *)local_8[-3];
            if ((pcVar9 == (char *)0x0) || (*pcVar9 == '\0')) {
              local_c = 0;
              *piVar1 = ((iVar3 < 1) - 1 & 2) - 1;
            }
            else {
              uVar5 = 0xffffffff;
              do {
                if (uVar5 == 0) break;
                uVar5 = uVar5 - 1;
                cVar2 = *pcVar9;
                pcVar9 = pcVar9 + 1;
              } while (cVar2 != '\0');
              local_c = ~uVar5 - 1;
              *piVar1 = iVar3;
            }
            puVar4 = (undefined4 *)FUN_0066c990(param_1,local_c + uVar6 + param_3 + 4 + uVar8);
            piVar1[1] = (int)puVar4;
            if (puVar4 == (undefined4 *)0x0) {
              FUN_00668bc0(param_1,s_text_chunk__out_of_memory_00a0cbd4,1);
              return 1;
            }
            puVar7 = (undefined4 *)local_8[-4];
            for (uVar5 = uVar8 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
              *puVar4 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar4 = puVar4 + 1;
            }
            for (uVar5 = uVar8 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(undefined1 *)puVar4 = *(undefined1 *)puVar7;
              puVar7 = (undefined4 *)((int)puVar7 + 1);
              puVar4 = (undefined4 *)((int)puVar4 + 1);
            }
            *(undefined1 *)(piVar1[1] + uVar8) = 0;
            if ((int)local_8[-5] < 1) {
              piVar1[5] = 0;
              piVar1[6] = 0;
              piVar1[2] = piVar1[1] + 1 + uVar8;
            }
            else {
              puVar4 = (undefined4 *)(piVar1[1] + 1 + uVar8);
              piVar1[5] = (int)puVar4;
              puVar7 = (undefined4 *)*local_8;
              for (uVar8 = param_3 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                *puVar4 = *puVar7;
                puVar7 = puVar7 + 1;
                puVar4 = puVar4 + 1;
              }
              for (uVar8 = param_3 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                *(undefined1 *)puVar4 = *(undefined1 *)puVar7;
                puVar7 = (undefined4 *)((int)puVar7 + 1);
                puVar4 = (undefined4 *)((int)puVar4 + 1);
              }
              *(undefined1 *)(piVar1[5] + param_3) = 0;
              puVar4 = (undefined4 *)(piVar1[5] + 1 + param_3);
              piVar1[6] = (int)puVar4;
              puVar7 = (undefined4 *)local_8[1];
              for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                *puVar4 = *puVar7;
                puVar7 = puVar7 + 1;
                puVar4 = puVar4 + 1;
              }
              for (uVar8 = uVar6 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                *(undefined1 *)puVar4 = *(undefined1 *)puVar7;
                puVar7 = (undefined4 *)((int)puVar7 + 1);
                puVar4 = (undefined4 *)((int)puVar4 + 1);
              }
              *(undefined1 *)(piVar1[6] + uVar6) = 0;
              piVar1[2] = piVar1[6] + 1 + uVar6;
            }
            if (local_c != 0) {
              puVar4 = (undefined4 *)local_8[-3];
              puVar7 = (undefined4 *)piVar1[2];
              for (uVar8 = local_c >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                *puVar7 = *puVar4;
                puVar4 = puVar4 + 1;
                puVar7 = puVar7 + 1;
              }
              for (uVar8 = local_c & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                *(undefined1 *)puVar7 = *(undefined1 *)puVar4;
                puVar4 = (undefined4 *)((int)puVar4 + 1);
                puVar7 = (undefined4 *)((int)puVar7 + 1);
              }
            }
            *(undefined1 *)(piVar1[2] + local_c) = 0;
            if (*piVar1 < 1) {
              piVar1[3] = local_c;
              piVar1[4] = 0;
            }
            else {
              piVar1[3] = 0;
              piVar1[4] = local_c;
            }
            *(int *)(param_2 + 0x80) = *(int *)(param_2 + 0x80) + 1;
          }
        }
        local_4 = local_4 + 1;
        local_8 = local_8 + 7;
      } while (local_4 < param_4);
    }
  }
  return 0;
}

