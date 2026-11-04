
void FUN_00649120(uint param_1,uint *param_2,undefined4 param_3,undefined4 param_4,uint param_5,
                 uint param_6,int param_7,int param_8,byte *param_9)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  int local_4;
  
  uVar7 = (uint)*(ushort *)(param_1 + 0x1a);
  if (param_6 != 0) {
    local_4 = param_6;
    do {
      param_1 = param_5;
      if (7 < param_5) {
        param_6 = param_5 >> 3;
        puVar6 = param_2;
        do {
          uVar4 = 0xff - param_9[3] & 0xffff;
          pbVar2 = param_9 + uVar7;
          *puVar6 = (((int)((0xff - (uint)param_9[2]) * uVar4) / 0xff & 0xffffU | 0xffffff00) << 8 |
                    (int)((0xff - (uint)param_9[1]) * uVar4) / 0xff & 0xffffU) << 8 |
                    (int)((0xff - (uint)*param_9) * uVar4) / 0xff & 0xffffU;
          uVar4 = 0xff - pbVar2[3] & 0xffff;
          pbVar3 = pbVar2 + uVar7;
          puVar6[1] = (((int)((0xff - (uint)pbVar2[2]) * uVar4) / 0xff & 0xffffU | 0xffffff00) << 8
                      | (int)((0xff - (uint)pbVar2[1]) * uVar4) / 0xff & 0xffffU) << 8 |
                      (int)((0xff - (uint)*pbVar2) * uVar4) / 0xff & 0xffffU;
          uVar4 = 0xff - pbVar3[3] & 0xffff;
          pbVar2 = pbVar3 + uVar7;
          puVar6[2] = (((int)((0xff - (uint)pbVar3[2]) * uVar4) / 0xff & 0xffffU | 0xffffff00) << 8
                      | (int)((0xff - (uint)pbVar3[1]) * uVar4) / 0xff & 0xffffU) << 8 |
                      (int)((0xff - (uint)*pbVar3) * uVar4) / 0xff & 0xffffU;
          uVar4 = 0xff - pbVar2[3] & 0xffff;
          pbVar3 = pbVar2 + uVar7;
          puVar6[3] = (((int)((0xff - (uint)pbVar2[2]) * uVar4) / 0xff & 0xffffU | 0xffffff00) << 8
                      | (int)((0xff - (uint)pbVar2[1]) * uVar4) / 0xff & 0xffffU) << 8 |
                      (int)((0xff - (uint)*pbVar2) * uVar4) / 0xff & 0xffffU;
          uVar4 = 0xff - pbVar3[3] & 0xffff;
          pbVar2 = pbVar3 + uVar7;
          puVar6[4] = (((int)((0xff - (uint)pbVar3[2]) * uVar4) / 0xff & 0xffffU | 0xffffff00) << 8
                      | (int)((0xff - (uint)pbVar3[1]) * uVar4) / 0xff & 0xffffU) << 8 |
                      (int)((0xff - (uint)*pbVar3) * uVar4) / 0xff & 0xffffU;
          uVar4 = 0xff - pbVar2[3] & 0xffff;
          pbVar3 = pbVar2 + uVar7;
          puVar6[5] = (((int)((0xff - (uint)pbVar2[2]) * uVar4) / 0xff & 0xffffU | 0xffffff00) << 8
                      | (int)((0xff - (uint)pbVar2[1]) * uVar4) / 0xff & 0xffffU) << 8 |
                      (int)((0xff - (uint)*pbVar2) * uVar4) / 0xff & 0xffffU;
          uVar4 = 0xff - pbVar3[3] & 0xffff;
          pbVar2 = pbVar3 + uVar7;
          puVar6[6] = (((int)((0xff - (uint)pbVar3[2]) * uVar4) / 0xff & 0xffffU | 0xffffff00) << 8
                      | (int)((0xff - (uint)pbVar3[1]) * uVar4) / 0xff & 0xffffU) << 8 |
                      (int)((0xff - (uint)*pbVar3) * uVar4) / 0xff & 0xffffU;
          uVar4 = 0xff - pbVar2[3] & 0xffff;
          param_2 = puVar6 + 8;
          param_9 = pbVar2 + uVar7;
          puVar6[7] = (((int)((0xff - (uint)pbVar2[2]) * uVar4) / 0xff & 0xffffU | 0xffffff00) << 8
                      | (int)((0xff - (uint)pbVar2[1]) * uVar4) / 0xff & 0xffffU) << 8 |
                      (int)((0xff - (uint)*pbVar2) * uVar4) / 0xff & 0xffffU;
          param_1 = param_1 - 8;
          param_6 = param_6 - 1;
          puVar6 = param_2;
        } while (param_6 != 0);
      }
      if (param_1 != 0) {
        puVar6 = param_2;
        puVar5 = param_2;
        switch(param_1) {
        case 7:
          uVar4 = 0xff - param_9[3] & 0xffff;
          puVar5 = param_2 + 1;
          param_9 = param_9 + uVar7;
          *param_2 = (((int)((0xff - (uint)param_9[2]) * uVar4) / 0xff & 0xffffU | 0xffffff00) << 8
                     | (int)((0xff - (uint)param_9[1]) * uVar4) / 0xff & 0xffffU) << 8 |
                     (int)((0xff - (uint)*param_9) * uVar4) / 0xff & 0xffffU;
        case 6:
          pbVar2 = param_9 + 2;
          uVar4 = 0xff - param_9[3] & 0xffff;
          puVar6 = puVar5 + 1;
          pbVar3 = param_9 + 1;
          bVar1 = *param_9;
          param_9 = param_9 + uVar7;
          *puVar5 = (((int)((0xff - (uint)*pbVar2) * uVar4) / 0xff & 0xffffU | 0xffffff00) << 8 |
                    (int)((0xff - (uint)*pbVar3) * uVar4) / 0xff & 0xffffU) << 8 |
                    (int)((0xff - (uint)bVar1) * uVar4) / 0xff & 0xffffU;
        case 5:
          pbVar2 = param_9 + 2;
          uVar4 = 0xff - param_9[3] & 0xffff;
          param_2 = puVar6 + 1;
          pbVar3 = param_9 + 1;
          bVar1 = *param_9;
          param_9 = param_9 + uVar7;
          *puVar6 = (((int)((0xff - (uint)*pbVar2) * uVar4) / 0xff & 0xffffU | 0xffffff00) << 8 |
                    (int)((0xff - (uint)*pbVar3) * uVar4) / 0xff & 0xffffU) << 8 |
                    (int)((0xff - (uint)bVar1) * uVar4) / 0xff & 0xffffU;
        case 4:
          pbVar2 = param_9 + 2;
          uVar4 = 0xff - param_9[3] & 0xffff;
          puVar6 = param_2 + 1;
          pbVar3 = param_9 + 1;
          bVar1 = *param_9;
          param_9 = param_9 + uVar7;
          *param_2 = (((int)((0xff - (uint)*pbVar2) * uVar4) / 0xff & 0xffffU | 0xffffff00) << 8 |
                     (int)((0xff - (uint)*pbVar3) * uVar4) / 0xff & 0xffffU) << 8 |
                     (int)((0xff - (uint)bVar1) * uVar4) / 0xff & 0xffffU;
        case 3:
          pbVar2 = param_9 + 2;
          uVar4 = 0xff - param_9[3] & 0xffff;
          param_2 = puVar6 + 1;
          pbVar3 = param_9 + 1;
          bVar1 = *param_9;
          param_9 = param_9 + uVar7;
          *puVar6 = (((int)((0xff - (uint)*pbVar2) * uVar4) / 0xff & 0xffffU | 0xffffff00) << 8 |
                    (int)((0xff - (uint)*pbVar3) * uVar4) / 0xff & 0xffffU) << 8 |
                    (int)((0xff - (uint)bVar1) * uVar4) / 0xff & 0xffffU;
        case 2:
          pbVar2 = param_9 + 2;
          uVar4 = 0xff - param_9[3] & 0xffff;
          puVar6 = param_2 + 1;
          pbVar3 = param_9 + 1;
          bVar1 = *param_9;
          param_9 = param_9 + uVar7;
          *param_2 = (((int)((0xff - (uint)*pbVar2) * uVar4) / 0xff & 0xffffU | 0xffffff00) << 8 |
                     (int)((0xff - (uint)*pbVar3) * uVar4) / 0xff & 0xffffU) << 8 |
                     (int)((0xff - (uint)bVar1) * uVar4) / 0xff & 0xffffU;
        case 1:
          uVar4 = 0xff - param_9[3] & 0xffff;
          param_2 = puVar6 + 1;
          *puVar6 = (((int)((0xff - (uint)param_9[2]) * uVar4) / 0xff & 0xffffU | 0xffffff00) << 8 |
                    (int)((0xff - (uint)param_9[1]) * uVar4) / 0xff & 0xffffU) << 8 |
                    (int)((0xff - (uint)*param_9) * uVar4) / 0xff & 0xffffU;
          param_9 = param_9 + uVar7;
        }
      }
      param_9 = param_9 + uVar7 * param_7;
      param_2 = param_2 + param_8;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}

