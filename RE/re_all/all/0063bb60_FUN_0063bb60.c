
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0063bb60(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  if (*(float *)(param_1 + 0x150) != _DAT_007d5344) {
    fVar3 = _DAT_00804108 / *(float *)(param_1 + 0x150);
    fVar1 = param_2[1];
    fVar2 = param_2[2];
    *(float *)(param_1 + 0x174) = fVar3 * *param_2;
    *(float *)(param_1 + 0x178) = fVar3 * fVar1;
    *(float *)(param_1 + 0x17c) = fVar3 * fVar2;
    *(undefined4 *)(param_1 + 0x180) = 0;
  }
  *(float *)(param_1 + 0x184) = *param_2;
  *(float *)(param_1 + 0x188) = param_2[1];
  *(float *)(param_1 + 0x18c) = param_2[2];
  *(float *)(param_1 + 400) = param_2[3];
  return;
}

