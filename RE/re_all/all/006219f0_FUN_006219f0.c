
void FUN_006219f0(int param_1,int param_2,float *param_3)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = (int)param_3 - param_2;
  pfVar2 = (float *)(param_2 + 0x10);
  iVar5 = param_1 - (int)param_3;
  iVar4 = 3;
  do {
    if (pfVar2[-4] <= *(float *)(iVar5 + (int)param_3)) {
      fVar1 = pfVar2[-4];
    }
    else {
      fVar1 = *(float *)(iVar5 + (int)param_3);
    }
    *param_3 = fVar1;
    if (*(float *)((param_1 - param_2) + (int)pfVar2) <= *pfVar2) {
      fVar1 = *pfVar2;
    }
    else {
      fVar1 = *(float *)((param_1 - param_2) + (int)pfVar2);
    }
    *(float *)(iVar3 + (int)pfVar2) = fVar1;
    param_3 = param_3 + 1;
    pfVar2 = pfVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}

