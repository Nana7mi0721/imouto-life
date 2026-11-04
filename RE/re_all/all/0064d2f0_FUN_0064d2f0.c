
void FUN_0064d2f0(undefined4 param_1,uint *param_2,undefined4 param_3,undefined4 param_4,
                 uint param_5,uint param_6,int param_7,int param_8,byte *param_9,byte *param_10,
                 byte *param_11)

{
  byte bVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  byte *pbVar5;
  int local_4;
  
  if (param_6 != 0) {
    local_4 = param_6;
    do {
      uVar4 = param_5;
      if (7 < param_5) {
        param_6 = param_5 >> 3;
        puVar3 = param_2;
        do {
          *puVar3 = ((*param_11 | 0xffffff00) << 8 | (uint)*param_10) << 8 | (uint)*param_9;
          puVar3[1] = ((param_11[1] | 0xffffff00) << 8 | (uint)param_10[1]) << 8 | (uint)param_9[1];
          puVar3[2] = ((param_11[2] | 0xffffff00) << 8 | (uint)param_10[2]) << 8 | (uint)param_9[2];
          puVar3[3] = ((param_11[3] | 0xffffff00) << 8 | (uint)param_10[3]) << 8 | (uint)param_9[3];
          puVar3[4] = ((param_11[4] | 0xffffff00) << 8 | (uint)param_10[4]) << 8 | (uint)param_9[4];
          puVar3[5] = ((param_11[5] | 0xffffff00) << 8 | (uint)param_10[5]) << 8 | (uint)param_9[5];
          pbVar5 = param_11 + 7;
          puVar3[6] = ((param_11[6] | 0xffffff00) << 8 | (uint)param_10[6]) << 8 | (uint)param_9[6];
          param_2 = puVar3 + 8;
          param_11 = param_11 + 8;
          puVar3[7] = ((*pbVar5 | 0xffffff00) << 8 | (uint)param_10[7]) << 8 | (uint)param_9[7];
          param_10 = param_10 + 8;
          param_9 = param_9 + 8;
          uVar4 = uVar4 - 8;
          param_6 = param_6 - 1;
          puVar3 = param_2;
        } while (param_6 != 0);
      }
      if (uVar4 != 0) {
        puVar3 = param_2;
        puVar2 = param_2;
        switch(uVar4) {
        case 7:
          puVar2 = param_2 + 1;
          bVar1 = *param_11;
          param_11 = param_11 + 1;
          *param_2 = ((bVar1 | 0xffffff00) << 8 | (uint)*param_10) << 8 | (uint)*param_9;
          param_10 = param_10 + 1;
          param_9 = param_9 + 1;
        case 6:
          puVar3 = puVar2 + 1;
          bVar1 = *param_11;
          param_11 = param_11 + 1;
          *puVar2 = ((bVar1 | 0xffffff00) << 8 | (uint)*param_10) << 8 | (uint)*param_9;
          param_10 = param_10 + 1;
          param_9 = param_9 + 1;
        case 5:
          param_2 = puVar3 + 1;
          bVar1 = *param_11;
          param_11 = param_11 + 1;
          *puVar3 = ((bVar1 | 0xffffff00) << 8 | (uint)*param_10) << 8 | (uint)*param_9;
          param_10 = param_10 + 1;
          param_9 = param_9 + 1;
        case 4:
          puVar3 = param_2 + 1;
          bVar1 = *param_11;
          param_11 = param_11 + 1;
          *param_2 = ((bVar1 | 0xffffff00) << 8 | (uint)*param_10) << 8 | (uint)*param_9;
          param_10 = param_10 + 1;
          param_9 = param_9 + 1;
        case 3:
          param_2 = puVar3 + 1;
          bVar1 = *param_11;
          param_11 = param_11 + 1;
          *puVar3 = ((bVar1 | 0xffffff00) << 8 | (uint)*param_10) << 8 | (uint)*param_9;
          param_10 = param_10 + 1;
          param_9 = param_9 + 1;
        case 2:
          puVar3 = param_2 + 1;
          bVar1 = *param_11;
          param_11 = param_11 + 1;
          *param_2 = ((bVar1 | 0xffffff00) << 8 | (uint)*param_10) << 8 | (uint)*param_9;
          param_10 = param_10 + 1;
          param_9 = param_9 + 1;
        case 1:
          param_2 = puVar3 + 1;
          *puVar3 = ((*param_11 | 0xffffff00) << 8 | (uint)*param_10) << 8 | (uint)*param_9;
          param_11 = param_11 + 1;
          param_10 = param_10 + 1;
          param_9 = param_9 + 1;
        }
      }
      param_9 = param_9 + param_7;
      param_10 = param_10 + param_7;
      param_11 = param_11 + param_7;
      param_2 = param_2 + param_8;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}

