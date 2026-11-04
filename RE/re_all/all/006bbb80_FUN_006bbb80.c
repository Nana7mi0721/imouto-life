
void FUN_006bbb80(int param_1,int param_2,int param_3,int param_4,int *param_5)

{
  byte *pbVar1;
  undefined1 *puVar2;
  int iVar3;
  uint *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_2c;
  uint local_28 [10];
  
  iVar7 = param_1 + -1;
  local_2c = 8;
  do {
    iVar3 = 0;
    puVar4 = local_28;
    do {
      pbVar1 = (byte *)(iVar3 + iVar7);
      iVar3 = iVar3 + 1;
      *puVar4 = (uint)*pbVar1;
      puVar4 = puVar4 + 1;
    } while (iVar3 < 10);
    iVar9 = 0;
    iVar8 = 0;
    iVar3 = 4;
    puVar4 = local_28;
    do {
      uVar6 = (int)(puVar4[1] - *puVar4) >> 0x1f;
      iVar8 = iVar8 + ((puVar4[1] - *puVar4 ^ uVar6) - uVar6);
      uVar6 = (int)(puVar4[5] - puVar4[6]) >> 0x1f;
      iVar9 = iVar9 + ((puVar4[5] - puVar4[6] ^ uVar6) - uVar6);
      iVar3 = iVar3 + -1;
      puVar4 = puVar4 + 1;
    } while (iVar3 != 0);
    *param_5 = *param_5 + (-(uint)(iVar8 < 0xff) & iVar8 - 0xffU) + 0xff;
    param_5[1] = param_5[1] + (-(uint)(iVar9 < 0xff) & iVar9 - 0xffU) + 0xff;
    if ((iVar8 < param_4) && (iVar9 < param_4)) {
      if (((int)(local_28[5] - local_28[4]) < param_3) &&
         ((int)(local_28[4] - local_28[5]) < param_3)) {
        param_1 = 4;
        *(char *)(iVar7 + 1) =
             (char)((int)(local_28[0] * 3 + local_28[3] + 4 + local_28[1] * 2 + local_28[2] +
                         local_28[4]) >> 3);
        *(char *)(iVar7 + 2) =
             (char)((int)(local_28[3] + 4 + (local_28[2] + local_28[0]) * 2 + local_28[1] +
                          local_28[4] + local_28[5]) >> 3);
        puVar4 = local_28 + 4;
        puVar2 = (undefined1 *)(iVar7 + 3);
        do {
          puVar5 = puVar2;
          *puVar5 = (char)((int)(puVar4[-4] + 4 + puVar4[-1] * 2 + puVar4[-3] + puVar4[-2] +
                                 puVar4[2] + *puVar4 + puVar4[1]) >> 3);
          param_1 = param_1 + -1;
          puVar4 = puVar4 + 1;
          puVar2 = puVar5 + 1;
        } while (param_1 != 0);
        puVar5[1] = (char)((int)(local_28[8] + 4 + (local_28[7] + local_28[9]) * 2 + local_28[6] +
                                 local_28[4] + local_28[5]) >> 3);
        puVar5[2] = (char)((int)(local_28[7] + local_28[9] * 3 + 4 + local_28[8] * 2 + local_28[6] +
                                local_28[5]) >> 3);
      }
    }
    iVar7 = iVar7 + param_2;
    local_2c = local_2c + -1;
  } while (local_2c != 0);
  return;
}

