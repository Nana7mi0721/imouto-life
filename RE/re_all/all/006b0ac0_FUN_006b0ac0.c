
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_006b0ac0(int *param_1,float *param_2,float *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  float *pfVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  int aiStack_34 [3];
  int *local_10;
  int local_c;
  
  if (0 < param_1[2]) {
    iVar4 = param_4 / *param_1;
    aiStack_34[2] = 0x6b0af5;
    aiStack_34[2 - iVar4] = 0x6b0b04;
    piVar3 = aiStack_34 + iVar4 * -2 + 3;
    local_c = 0;
    if (0 < iVar4) {
      local_10 = piVar3;
      do {
        param_4 = param_1[10];
        aiStack_34[iVar4 * -2 + 2] = param_1[9];
        aiStack_34[iVar4 * -2 + 1] = (int)param_3;
        aiStack_34[iVar4 * -2] = 0x6b0b36;
        iVar5 = FUN_00797700();
        if (iVar5 < 0) {
          iVar5 = param_1[2];
          uVar11 = 0;
LAB_006b0b83:
          aiStack_34[iVar4 * -2 + 2] = param_4;
          aiStack_34[iVar4 * -2 + 1] = (int)param_3;
          aiStack_34[iVar4 * -2] = 0x6b0b90;
          iVar6 = FUN_00797700();
          if (iVar6 < 0) {
            do {
              if (param_4 < 2) {
                if (iVar6 < 0) goto LAB_006b0c29;
                break;
              }
              param_4 = param_4 + -1;
              aiStack_34[iVar4 * -2 + 2] = param_4;
              aiStack_34[iVar4 * -2 + 1] = (int)param_3;
              aiStack_34[iVar4 * -2] = 0x6b0ba7;
              iVar6 = FUN_00797700();
            } while (iVar6 < 0);
          }
          aiStack_34[iVar4 * -2 + 2] = iVar6;
          aiStack_34[iVar4 * -2 + 1] = 0x6b0bc0;
          uVar7 = FUN_006b05c0();
          iVar6 = iVar5 - uVar11;
          if (1 < iVar6) {
            do {
              uVar10 = iVar6 >> 1;
              uVar2 = (uint)(uVar7 < *(uint *)(param_1[5] + (uVar10 + uVar11) * 4));
              iVar5 = iVar5 - (-uVar2 & uVar10);
              uVar11 = uVar11 + (uVar2 - 1 & uVar10);
              iVar6 = iVar5 - uVar11;
            } while (1 < iVar6);
          }
          if (param_4 < *(char *)(param_1[7] + uVar11)) {
            aiStack_34[iVar4 * -2 + 2] = param_4;
            aiStack_34[iVar4 * -2 + 1] = (int)param_3;
            aiStack_34[iVar4 * -2] = 0x6b0c26;
            FUN_007977d0();
LAB_006b0c29:
            uVar11 = 0xffffffff;
          }
          else {
            aiStack_34[iVar4 * -2 + 2] = (int)*(char *)(param_1[7] + uVar11);
            aiStack_34[iVar4 * -2 + 1] = (int)param_3;
            aiStack_34[iVar4 * -2] = 0x6b0c15;
            FUN_007977d0();
          }
        }
        else {
          uVar7 = *(uint *)(param_1[8] + iVar5 * 4);
          if ((uVar7 & 0x80000000) != 0) {
            uVar11 = (int)uVar7 >> 0xf & 0x7fff;
            iVar5 = param_1[2] - (uVar7 & 0x7fff);
            goto LAB_006b0b83;
          }
          aiStack_34[iVar4 * -2 + 2] = (int)*(char *)(param_1[7] + -1 + uVar7);
          aiStack_34[iVar4 * -2 + 1] = (int)param_3;
          aiStack_34[iVar4 * -2] = 0x6b0b75;
          FUN_007977d0();
          uVar11 = uVar7 - 1;
        }
        *(uint *)((int)aiStack_34 + (iVar4 * -4 - (int)piVar3) + 0xc + (int)local_10) = uVar11;
        if (uVar11 == 0xffffffff) {
          return 0xffffffff;
        }
        *local_10 = param_1[4] + *param_1 * uVar11 * 4;
        local_c = local_c + 1;
        local_10 = local_10 + 1;
      } while (local_c < iVar4);
    }
    iVar5 = 0;
    if (0 < *param_1) {
      param_3 = param_2;
      do {
        if (0 < iVar4) {
          pfVar8 = param_3;
          piVar9 = piVar3;
          iVar6 = iVar4;
          do {
            iVar1 = *piVar9;
            piVar9 = piVar9 + 1;
            iVar6 = iVar6 + -1;
            *pfVar8 = *(float *)(iVar1 + iVar5 * 4) + *pfVar8;
            pfVar8 = pfVar8 + 1;
          } while (iVar6 != 0);
        }
        param_3 = param_3 + iVar4;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *param_1);
    }
  }
  return 0;
}

