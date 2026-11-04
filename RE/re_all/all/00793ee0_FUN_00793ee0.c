
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00793ee0(int param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  float fVar2;
  
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  *(float *)(param_1 + 4) = *param_2 - param_4;
  *(float *)(param_1 + 8) = fVar1 - param_4;
  *(float *)(param_1 + 0xc) = fVar2 - param_4;
  *(undefined4 *)(param_1 + 0x10) = 0;
  fVar1 = param_3[1];
  fVar2 = param_3[2];
  *(float *)(param_1 + 0x14) = param_4 + *param_3;
  *(float *)(param_1 + 0x18) = param_4 + fVar1;
  *(float *)(param_1 + 0x1c) = param_4 + fVar2;
  *(undefined4 *)(param_1 + 0x20) = 0;
  fVar1 = _DAT_00837580 / (*(float *)(param_1 + 0x18) - *(float *)(param_1 + 8));
  *(float *)(param_1 + 0x24) =
       _DAT_00837580 / (*(float *)(param_1 + 0x14) - *(float *)(param_1 + 4));
  fVar2 = _DAT_00837580 / (*(float *)(param_1 + 0x1c) - *(float *)(param_1 + 0xc));
  *(float *)(param_1 + 0x28) = fVar1;
  *(float *)(param_1 + 0x2c) = fVar2;
  *(undefined1 *)(param_1 + 0x3c) = 1;
  *(undefined4 *)(param_1 + 0x30) = 0;
  return;
}

