
undefined4 FUN_006b1070(int *param_1,undefined4 *param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int local_8;
  int local_4;
  
  if (param_1[2] < 1) {
    if (0 < param_4) {
      for (; param_4 != 0; param_4 = param_4 + -1) {
        *param_2 = 0;
        param_2 = param_2 + 1;
      }
    }
  }
  else {
    iVar8 = 0;
    local_4 = 0;
    if (0 < param_4) {
      do {
        local_8 = param_1[10];
        iVar2 = FUN_00797700(param_3,param_1[9]);
        if (iVar2 < 0) {
          iVar8 = param_1[2];
          uVar7 = 0;
LAB_006b10fb:
          iVar2 = FUN_00797700(param_3,local_8);
          if (iVar2 < 0) {
            do {
              if (local_8 < 2) {
                if (iVar2 < 0) {
                  return 0xffffffff;
                }
                break;
              }
              local_8 = local_8 + -1;
              iVar2 = FUN_00797700(param_3,local_8);
            } while (iVar2 < 0);
          }
          uVar3 = FUN_006b05c0(iVar2);
          iVar2 = iVar8 - uVar7;
          if (1 < iVar2) {
            do {
              uVar6 = iVar2 >> 1;
              uVar1 = (uint)(uVar3 < *(uint *)(param_1[5] + (uVar6 + uVar7) * 4));
              iVar8 = iVar8 - (-uVar1 & uVar6);
              uVar7 = uVar7 + (uVar1 - 1 & uVar6);
              iVar2 = iVar8 - uVar7;
            } while (1 < iVar2);
          }
          if (local_8 < *(char *)(param_1[7] + uVar7)) {
            FUN_007977d0(param_3,local_8);
            return 0xffffffff;
          }
          FUN_007977d0(param_3,(int)*(char *)(param_1[7] + uVar7));
          iVar8 = local_4;
        }
        else {
          uVar3 = *(uint *)(param_1[8] + iVar2 * 4);
          if ((uVar3 & 0x80000000) != 0) {
            uVar7 = (int)uVar3 >> 0xf & 0x7fff;
            iVar8 = param_1[2] - (uVar3 & 0x7fff);
            goto LAB_006b10fb;
          }
          FUN_007977d0(param_3,(int)*(char *)(param_1[7] + -1 + uVar3));
          uVar7 = uVar3 - 1;
        }
        if (uVar7 == 0xffffffff) {
          return 0xffffffff;
        }
        puVar5 = (undefined4 *)(param_1[4] + *param_1 * uVar7 * 4);
        iVar2 = 0;
        if (param_4 <= iVar8) {
          return 0;
        }
        puVar4 = param_2 + iVar8;
        while (iVar2 < *param_1) {
          iVar8 = iVar8 + 1;
          *puVar4 = *puVar5;
          puVar4 = puVar4 + 1;
          iVar2 = iVar2 + 1;
          puVar5 = puVar5 + 1;
          local_4 = iVar8;
          if (param_4 <= iVar8) {
            return 0;
          }
        }
        if (param_4 <= iVar8) {
          return 0;
        }
      } while( true );
    }
  }
  return 0;
}

