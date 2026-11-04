
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_006b5370(int param_1,int *param_2,int param_3,int param_4,code *param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int aiStack_50 [3];
  int local_30;
  int local_2c;
  int local_24;
  int local_20;
  int local_18;
  int local_c;
  int local_8;
  
  piVar1 = (int *)*param_2;
  iVar2 = *(int *)param_2[4];
  iVar3 = piVar1[2];
  iVar4 = *(int *)(param_1 + 0x24) >> 1;
  if (piVar1[1] < iVar4) {
    iVar4 = piVar1[1];
  }
  if (0 < iVar4 - *piVar1) {
    iVar4 = (iVar4 - *piVar1) / iVar3;
    aiStack_50[2] = 0x6b53cd;
    piVar10 = aiStack_50 + (3 - param_4);
    piVar7 = aiStack_50 + (3 - param_4);
    if (0 < param_4) {
      iVar8 = param_4;
      do {
        aiStack_50[2 - param_4] = (iVar4 + -1 + iVar2) / iVar2 << 2;
        aiStack_50[1 - param_4] = param_1;
        aiStack_50[-param_4] = 0x6b53e5;
        uVar5 = FUN_006ac620();
        *piVar10 = uVar5;
        piVar10 = piVar10 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    local_c = 0;
    if (0 < param_2[2]) {
      do {
        iVar8 = 0;
        local_18 = 0;
        if (0 < iVar4) {
          local_24 = 0;
          do {
            if ((local_c == 0) && (iVar9 = 0, 0 < param_4)) {
              piVar10 = aiStack_50 + (3 - param_4);
              do {
                *(int *)((int)piVar7 + -4) = param_1 + 4;
                *(int *)((int)piVar7 + -8) = param_2[4];
                *(undefined4 *)((int)piVar7 + -0xc) = 0x6b543b;
                iVar8 = FUN_006b0990();
                if (iVar8 == -1) {
                  return 0;
                }
                if (piVar1[4] <= iVar8) {
                  return 0;
                }
                *(undefined4 *)(local_24 + *piVar10) = *(undefined4 *)(param_2[7] + iVar8 * 4);
                if (*(int *)(local_24 + *piVar10) == 0) {
                  return 0;
                }
                iVar9 = iVar9 + 1;
                piVar10 = piVar10 + 1;
              } while (iVar9 < param_4);
              iVar8 = local_18;
            }
            local_30 = 0;
            if (0 < iVar2) {
              local_8 = 0;
              local_20 = iVar8 * iVar3;
              do {
                if (iVar4 <= iVar8) break;
                local_2c = 0;
                if (0 < param_4) {
                  piVar10 = aiStack_50 + (3 - param_4);
                  do {
                    iVar8 = *piVar1;
                    if (((piVar1[*(int *)(*(int *)(*piVar10 + local_24) + local_8) + 6] &
                         1 << ((byte)local_c & 0x1f)) != 0) &&
                       (iVar9 = *(int *)(*(int *)(param_2[5] +
                                                 *(int *)(*(int *)(*piVar10 + local_24) + local_8) *
                                                 4) + local_c * 4), iVar9 != 0)) {
                      *(int *)((int)piVar7 + -4) = iVar3;
                      *(int *)((int)piVar7 + -8) = param_1 + 4;
                      *(int *)((int)piVar7 + -0xc) =
                           *(int *)((param_3 - (int)(aiStack_50 + (3 - param_4))) + (int)piVar10) +
                           (iVar8 + local_20) * 4;
                      *(int *)((int)piVar7 + -0x10) = iVar9;
                      puVar6 = (undefined1 *)((int)piVar7 + -0x14);
                      *(undefined4 *)((int)piVar7 + -0x14) = 0x6b551c;
                      iVar8 = (*param_5)();
                      piVar7 = (int *)(puVar6 + 0x10);
                      if (iVar8 == -1) {
                        return 0;
                      }
                    }
                    local_2c = local_2c + 1;
                    piVar10 = piVar10 + 1;
                  } while (local_2c < param_4);
                  iVar8 = local_18;
                }
                local_8 = local_8 + 4;
                local_20 = local_20 + iVar3;
                local_30 = local_30 + 1;
                iVar8 = iVar8 + 1;
                local_18 = iVar8;
              } while (local_30 < iVar2);
            }
            local_24 = local_24 + 4;
          } while (iVar8 < iVar4);
        }
        local_c = local_c + 1;
      } while (local_c < param_2[2]);
    }
  }
  return 0;
}

