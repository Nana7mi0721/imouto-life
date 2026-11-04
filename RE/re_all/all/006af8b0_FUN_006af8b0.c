
void FUN_006af8b0(int param_1,float param_2,float param_3,int param_4,int param_5,
                 undefined4 *param_6,int param_7,int param_8)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (0 < param_8) {
    iVar4 = param_5 - (int)param_6;
    do {
      if (iVar3 < param_1 - param_7) {
        fVar2 = param_2;
      }
      else {
        fVar2 = param_3;
      }
      pfVar1 = (float *)(iVar4 + (int)param_6);
      if (fVar2 <= ABS(*(float *)((int)pfVar1 + (param_4 - param_5))) / *pfVar1) {
        *param_6 = 1;
      }
      else {
        *param_6 = 0;
      }
      iVar3 = iVar3 + 1;
      param_6 = param_6 + 1;
    } while (iVar3 < param_8);
  }
  return;
}

