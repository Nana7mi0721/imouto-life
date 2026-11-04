
void __thiscall FUN_0063aab0(int param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  float fVar2;
  
  if (*(int *)(param_1 + 0x44) != 0) {
    fVar1 = param_2[1];
    fVar2 = param_2[2];
    *(float *)(param_1 + 0x48) = param_4 * *param_2 + *(float *)(param_1 + 0x48);
    *(float *)(param_1 + 0x4c) = param_4 * fVar1 + *(float *)(param_1 + 0x4c);
    *(float *)(param_1 + 0x50) = param_4 * fVar2 + *(float *)(param_1 + 0x50);
    fVar1 = param_3[1];
    fVar2 = param_3[2];
    *(float *)(param_1 + 0x58) =
         param_4 * *(float *)(param_1 + 0x20) * *param_3 + *(float *)(param_1 + 0x58);
    *(float *)(param_1 + 0x5c) =
         param_4 * *(float *)(param_1 + 0x24) * fVar1 + *(float *)(param_1 + 0x5c);
    *(float *)(param_1 + 0x60) =
         param_4 * *(float *)(param_1 + 0x28) * fVar2 + *(float *)(param_1 + 0x60);
  }
  return;
}

