
void __thiscall FUN_0063da20(int param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(param_1 + param_2 * 4);
  fVar2 = *(float *)(param_1 + 0x10 + param_2 * 4);
  if (fVar1 <= fVar2) {
    if (param_3 < fVar1) {
      *(undefined4 *)(param_1 + 0x80 + param_2 * 4) = 2;
      *(float *)(param_1 + 0x60 + param_2 * 4) = param_3 - fVar1;
      return;
    }
    if (fVar2 < param_3) {
      *(undefined4 *)(param_1 + 0x80 + param_2 * 4) = 1;
      *(float *)(param_1 + 0x60 + param_2 * 4) = param_3 - fVar2;
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x80 + param_2 * 4) = 0;
  *(undefined4 *)(param_1 + 0x60 + param_2 * 4) = 0;
  return;
}

