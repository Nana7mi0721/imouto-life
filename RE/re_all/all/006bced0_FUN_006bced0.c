
void FUN_006bced0(int param_1,int param_2,int *param_3,int param_4)

{
  undefined4 *puVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined1 *local_18;
  uint local_14;
  int local_10;
  uint local_c;
  
  pcVar2 = (code *)(&PTR_LAB_00832320)[param_4];
  local_c = 0;
  local_10 = 0;
  if (0 < param_3[1]) {
    do {
      local_14 = 0;
      if (0 < *param_3) {
        do {
          param_4 = 0;
          local_18 = &DAT_00831e30;
          do {
            iVar6 = 0;
            uVar3 = param_4 * 2 | local_c;
            do {
              uVar5 = (uint)(byte)local_18[iVar6] | local_10 * 4;
              uVar7 = iVar6 * 2 | local_14;
              puVar1 = (undefined4 *)(uVar5 * 0x30 + param_1);
              puVar8 = puVar1;
              for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
                *puVar8 = 0xffffffff;
                puVar8 = puVar8 + 1;
              }
              if (((int)uVar7 < *param_3) && ((int)uVar3 < param_3[1])) {
                FUN_006bd010(puVar1,param_3,uVar7,uVar3);
                (*pcVar2)(puVar1,param_3,uVar7,uVar3);
              }
              else {
                *(undefined1 *)(uVar5 + param_2) = 0xff;
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 < 2);
            local_18 = local_18 + 2;
            param_4 = param_4 + 1;
          } while ((int)local_18 < 0x831e34);
          local_14 = local_14 + 4;
          local_10 = local_10 + 1;
        } while ((int)local_14 < *param_3);
      }
      local_c = local_c + 4;
    } while ((int)local_c < param_3[1]);
  }
  return;
}

