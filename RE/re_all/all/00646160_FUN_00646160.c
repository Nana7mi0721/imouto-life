
void __thiscall FUN_00646160(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x44);
  if (iVar5 == 0) {
    *param_2 = 0.0;
    param_2[1] = 0.0;
    param_2[2] = 0.0;
    param_2[3] = 0.0;
    return;
  }
  fVar1 = *(float *)(iVar5 + 0x144);
  fVar2 = *(float *)(param_1 + 0x14);
  fVar3 = *(float *)(iVar5 + 0x148);
  fVar4 = *(float *)(param_1 + 0x18);
  *param_2 = *(float *)(param_1 + 0x10) + *(float *)(iVar5 + 0x140);
  param_2[1] = fVar1 + fVar2;
  param_2[2] = fVar3 + fVar4;
  param_2[3] = 0.0;
  return;
}

