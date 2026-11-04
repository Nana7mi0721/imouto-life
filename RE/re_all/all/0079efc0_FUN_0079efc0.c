
void FUN_0079efc0(undefined4 *param_1,int param_2,short *param_3,uint param_4,uint param_5)

{
  short *psVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  short *psVar5;
  uint uVar6;
  short *psVar7;
  undefined2 *local_4;
  
  if ((int)param_5 < (int)param_4) {
    local_4 = (undefined2 *)((int)param_1 + param_5 * 2);
    psVar5 = (short *)(param_2 + -10 + param_5 * 2);
    param_2 = param_4 - param_5;
    do {
      iVar4 = (int)psVar5[-1] * (int)param_3[5] + (int)psVar5[3] * (int)param_3[1] +
              (int)psVar5[2] * (int)param_3[2] + (int)param_3[3] * (int)psVar5[1] +
              (int)*psVar5 * (int)param_3[4] + (int)psVar5[4] * (int)*param_3;
      if (6 < (int)param_5) {
        psVar7 = param_3 + 6;
        param_4 = param_5 - 5 >> 1;
        psVar3 = psVar5;
        do {
          psVar1 = psVar7 + 1;
          sVar2 = *psVar7;
          psVar7 = psVar7 + 2;
          iVar4 = (int)psVar3[-2] * (int)sVar2 + iVar4 + (int)psVar3[-3] * (int)*psVar1;
          param_4 = param_4 - 1;
          psVar3 = psVar3 + -2;
        } while (param_4 != 0);
      }
      iVar4 = (psVar5[5] * 0x1000 - iVar4 >> 0xb) + 1 >> 1;
      if (iVar4 < 0x8000) {
        if (iVar4 < -0x8000) {
          iVar4 = -0x8000;
        }
      }
      else {
        iVar4 = 0x7fff;
      }
      psVar5 = psVar5 + 1;
      *local_4 = (short)iVar4;
      local_4 = local_4 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  for (uVar6 = (param_5 & 0x7fffffff) >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  for (uVar6 = param_5 * 2 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined1 *)param_1 = 0;
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return;
}

