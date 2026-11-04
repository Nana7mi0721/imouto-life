
void __thiscall FUN_0060f4e0(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  *(float *)(param_1 + 0xc) = ABS(*param_2);
  *(float *)(param_1 + 0x10) = ABS(fVar1);
  *(float *)(param_1 + 0x14) = ABS(fVar2);
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}

