
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00652fb0(int *param_1,undefined4 param_2,int *param_3)

{
  float *pfVar1;
  int iVar2;
  float10 fVar3;
  
  *param_1 = 0x5dc;
  FUN_00650840(param_1 + 7,param_2,0x54);
  iVar2 = 0;
  param_1[1] = (int)(((float)param_1[0x10] - (float)param_1[0x16]) / (float)*param_1);
  if (-1 < *param_1) {
    pfVar1 = (float *)(param_1 + 0x1c);
    do {
      fVar3 = (float10)FUN_006c51d0();
      iVar2 = iVar2 + 1;
      *pfVar1 = (float)(fVar3 * (float10)param_1[0x13]);
      pfVar1 = pfVar1 + 1;
    } while (iVar2 <= *param_1);
  }
  iVar2 = 0;
  param_1[2] = (int)(((float)param_1[0x10] - (float)param_1[0x16]) / (float)*param_1);
  if (-1 < *param_1) {
    pfVar1 = (float *)(param_1 + 0x5f9);
    do {
      fVar3 = (float10)FUN_006c51d0();
      iVar2 = iVar2 + 1;
      *pfVar1 = (float)(fVar3 * (float10)param_1[0x14]);
      pfVar1 = pfVar1 + 1;
    } while (iVar2 <= *param_1);
  }
  iVar2 = 0;
  param_1[3] = (int)(((float)param_1[0x10] - (float)param_1[0x16]) / (float)*param_1);
  if (-1 < *param_1) {
    pfVar1 = (float *)(param_1 + 0xbd6);
    do {
      fVar3 = (float10)FUN_006c51d0();
      iVar2 = iVar2 + 1;
      *pfVar1 = (float)(fVar3 * (float10)param_1[0x15]);
      pfVar1 = pfVar1 + 1;
    } while (iVar2 <= *param_1);
  }
  param_1[4] = *param_3;
  param_1[5] = param_3[1];
  param_1[6] = param_3[2];
  return 0;
}

