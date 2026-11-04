
void __thiscall FUN_0063d070(int param_1,float *param_2)

{
  float fVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  
  iVar4 = 0;
  pfVar2 = (float *)(param_1 + 0x4f0);
  do {
    if (*(char *)(param_1 + 0x4e8 + iVar4) != '\0') {
      fVar1 = (pfVar2[-0xb] - *pfVar2) * pfVar2[6];
      pfVar2[-0x79] = ((pfVar2[0xc] * *param_2) / (float)(int)param_2[0xc]) * fVar1;
      pfVar2[-0x75] = ABS(fVar1) / *param_2;
    }
    iVar4 = iVar4 + 1;
    pfVar2 = pfVar2 + 1;
  } while (iVar4 < 3);
  iVar4 = 0;
  pfVar2 = (float *)(param_1 + 0x364);
  pfVar3 = (float *)(param_1 + 0x4fc);
  do {
    if (*(char *)(param_1 + 0x4eb + iVar4) != '\0') {
      fVar1 = -((pfVar3[-0x1e] - *pfVar3) * pfVar3[6]);
      pfVar2[-1] = ((pfVar3[0xc] * *param_2) / (float)(int)param_2[0xc]) * fVar1;
      *pfVar2 = ABS(fVar1) / *param_2;
    }
    iVar4 = iVar4 + 1;
    pfVar3 = pfVar3 + 1;
    pfVar2 = pfVar2 + 0xe;
  } while (iVar4 < 3);
  return;
}

