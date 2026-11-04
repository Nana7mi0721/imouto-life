
void FUN_007a29c0(float *param_1,float param_2,float param_3,int param_4,float param_5,float param_6
                 ,float param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  float local_4;
  
  iVar6 = (int)param_3;
  iVar5 = (int)param_2;
  local_4 = *(float *)((int)param_2 - ((int)param_3 * 4 + 8));
  pfVar7 = (float *)((int)param_2 + (int)param_3 * -4);
  param_3 = *(float *)((int)param_2 - ((int)param_3 * 4 + 4));
  if (0 < param_4) {
    iVar9 = (int)param_2 - (int)param_1;
    iVar8 = 0;
    fVar1 = pfVar7[1];
    param_2 = *pfVar7;
    do {
      fVar2 = fVar1;
      param_4 = param_4 + -1;
      fVar1 = *(float *)(iVar8 + iVar6 * -4 + 8 + iVar5);
      fVar3 = fVar2 + param_3;
      fVar4 = fVar1 + local_4;
      local_4 = param_3;
      param_3 = param_2;
      *param_1 = param_2 * param_5 + fVar4 * param_7 + fVar3 * param_6 +
                 *(float *)(iVar9 + -4 + (int)(param_1 + 1));
      param_1 = param_1 + 1;
      iVar8 = iVar8 + 4;
      param_2 = fVar2;
    } while (param_4 != 0);
  }
  return;
}

