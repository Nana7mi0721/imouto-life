
int __thiscall FUN_00616cb0(int param_1,float *param_2)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float local_4;
  
  local_4 = *(float *)(param_1 + 0x2a0) * *(float *)(param_1 + 0x2a0);
  iVar4 = -1;
  iVar3 = 0;
  if (*(int *)(param_1 + 0x29c) < 1) {
    return -1;
  }
  pfVar2 = (float *)(param_1 + 0xc);
  do {
    fVar1 = (pfVar2[-1] - param_2[1]) * (pfVar2[-1] - param_2[1]) +
            (*pfVar2 - param_2[2]) * (*pfVar2 - param_2[2]) +
            (pfVar2[-2] - *param_2) * (pfVar2[-2] - *param_2);
    if (fVar1 < local_4) {
      iVar4 = iVar3;
      local_4 = fVar1;
    }
    iVar3 = iVar3 + 1;
    pfVar2 = pfVar2 + 0x29;
  } while (iVar3 < *(int *)(param_1 + 0x29c));
  return iVar4;
}

