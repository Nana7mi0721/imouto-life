
void FUN_006b8130(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  float *pfVar5;
  int iVar6;
  float *pfVar7;
  
  iVar1 = param_3;
  uVar3 = param_5 - param_4;
  iVar6 = param_3 - param_2;
  iVar2 = (int)uVar3 / iVar6;
  if ((int)uVar3 < 0) {
    param_3 = iVar2 + -1;
  }
  else {
    param_3 = iVar2 + 1;
  }
  param_5 = 0;
  uVar4 = iVar2 * iVar6 >> 0x1f;
  if (iVar1 < param_1) {
    param_1 = iVar1;
  }
  if (param_2 < param_1) {
    *(float *)(param_6 + param_2 * 4) =
         (float)(&DAT_00831910)[param_4] * *(float *)(param_6 + param_2 * 4);
  }
  param_2 = param_2 + 1;
  if (param_2 < param_1) {
    param_1 = param_1 - param_2;
    pfVar5 = (float *)(&DAT_00831910 + param_4);
    pfVar7 = (float *)(param_6 + param_2 * 4);
    do {
      param_5 = param_5 + (((uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f)) -
                          ((iVar2 * iVar6 ^ uVar4) - uVar4));
      if (param_5 < iVar6) {
        iVar1 = iVar2 << 2;
      }
      else {
        param_5 = param_5 - iVar6;
        iVar1 = param_3 * 4;
      }
      pfVar5 = (float *)((int)pfVar5 + iVar1);
      param_1 = param_1 + -1;
      *pfVar7 = *pfVar5 * *pfVar7;
      pfVar7 = pfVar7 + 1;
    } while (param_1 != 0);
  }
  return;
}

