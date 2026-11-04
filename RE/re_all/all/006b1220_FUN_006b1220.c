
undefined4
FUN_006b1220(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  float *pfVar7;
  uint uVar8;
  uint uVar9;
  int local_8;
  
  local_8 = 0;
  if (0 < param_1[2]) {
    iVar3 = param_6 + param_3;
    iVar4 = 0;
    param_3 = param_3 / param_4;
    iVar1 = local_8;
    while (local_8 = iVar4, param_3 < iVar3 / param_4) {
      param_6 = param_1[10];
      iVar4 = FUN_00797700(param_5,param_1[9]);
      if (iVar4 < 0) {
        iVar4 = param_1[2];
        uVar9 = 0;
LAB_006b12c7:
        iVar5 = FUN_00797700(param_5,param_6);
        if (iVar5 < 0) {
          do {
            if (param_6 < 2) {
              if (iVar5 < 0) {
                return 0xffffffff;
              }
              break;
            }
            param_6 = param_6 + -1;
            iVar5 = FUN_00797700(param_5,param_6);
          } while (iVar5 < 0);
        }
        uVar6 = FUN_006b05c0(iVar5);
        iVar5 = iVar4 - uVar9;
        if (1 < iVar5) {
          do {
            uVar8 = iVar5 >> 1;
            uVar2 = (uint)(uVar6 < *(uint *)(param_1[5] + (uVar8 + uVar9) * 4));
            iVar4 = iVar4 - (-uVar2 & uVar8);
            uVar9 = uVar9 + (uVar2 - 1 & uVar8);
            iVar5 = iVar4 - uVar9;
          } while (1 < iVar5);
        }
        if (param_6 < *(char *)(param_1[7] + uVar9)) {
          FUN_007977d0(param_5,param_6);
          return 0xffffffff;
        }
        FUN_007977d0(param_5,(int)*(char *)(param_1[7] + uVar9));
        local_8 = iVar1;
      }
      else {
        uVar6 = *(uint *)(param_1[8] + iVar4 * 4);
        if ((uVar6 & 0x80000000) != 0) {
          uVar9 = (int)uVar6 >> 0xf & 0x7fff;
          iVar4 = param_1[2] - (uVar6 & 0x7fff);
          goto LAB_006b12c7;
        }
        FUN_007977d0(param_5,(int)*(char *)(param_1[7] + -1 + uVar6));
        uVar9 = uVar6 - 1;
      }
      if (uVar9 == 0xffffffff) {
        return 0xffffffff;
      }
      pfVar7 = (float *)(param_1[4] + *param_1 * uVar9 * 4);
      iVar5 = 0;
      iVar4 = local_8;
      if (0 < *param_1) {
        do {
          iVar1 = *(int *)(param_2 + local_8 * 4);
          local_8 = local_8 + 1;
          *(float *)(iVar1 + param_3 * 4) = *(float *)(iVar1 + param_3 * 4) + *pfVar7;
          if (local_8 == param_4) {
            local_8 = 0;
            param_3 = param_3 + 1;
          }
          iVar5 = iVar5 + 1;
          pfVar7 = pfVar7 + 1;
          iVar4 = local_8;
          iVar1 = local_8;
        } while (iVar5 < *param_1);
      }
    }
  }
  return 0;
}

