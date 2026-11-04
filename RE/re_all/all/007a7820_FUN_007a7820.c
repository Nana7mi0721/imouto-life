
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a7820(float *param_1,undefined4 param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  
  if (0 < param_3) {
    pfVar3 = param_1 + 10;
    do {
      fVar1 = pfVar3[-2];
      fVar2 = pfVar3[-1];
      param_3 = param_3 + -1;
      pfVar3[-2] = *param_1 - fVar1;
      pfVar3[-1] = pfVar3[-9] - fVar2;
      *param_1 = fVar1 + *param_1;
      pfVar3[-9] = fVar2 + pfVar3[-9];
      fVar1 = (*pfVar3 + pfVar3[1]) * _DAT_0080451c;
      fVar2 = (pfVar3[1] - *pfVar3) * _DAT_0080451c;
      *pfVar3 = pfVar3[-8] - fVar1;
      pfVar3[1] = pfVar3[-7] - fVar2;
      pfVar3[-8] = fVar1 + pfVar3[-8];
      pfVar3[-7] = fVar2 + pfVar3[-7];
      fVar1 = pfVar3[3];
      fVar2 = pfVar3[2];
      pfVar3[2] = pfVar3[-6] - fVar1;
      pfVar3[3] = pfVar3[-5] - -fVar2;
      pfVar3[-6] = fVar1 + pfVar3[-6];
      pfVar3[-5] = -fVar2 + pfVar3[-5];
      fVar1 = (pfVar3[5] - pfVar3[4]) * _DAT_0080451c;
      fVar2 = (-pfVar3[5] - pfVar3[4]) * _DAT_0080451c;
      pfVar3[4] = pfVar3[-4] - fVar1;
      pfVar3[5] = pfVar3[-3] - fVar2;
      pfVar3[-4] = fVar1 + pfVar3[-4];
      pfVar3[-3] = fVar2 + pfVar3[-3];
      pfVar3 = pfVar3 + 0x10;
      param_1 = param_1 + 0x10;
    } while (param_3 != 0);
  }
  return;
}

