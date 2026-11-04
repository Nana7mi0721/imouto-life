
void __thiscall FUN_00797350(int param_1,float *param_2,ushort *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  ushort uVar5;
  ushort uVar6;
  
  uVar5 = param_3[1];
  uVar6 = param_3[2];
  fVar1 = *(float *)(param_1 + 0x28);
  fVar2 = *(float *)(param_1 + 0x2c);
  fVar3 = *(float *)(param_1 + 8);
  fVar4 = *(float *)(param_1 + 0xc);
  *param_2 = (float)*param_3 / *(float *)(param_1 + 0x24) + *(float *)(param_1 + 4);
  param_2[1] = (float)uVar5 / fVar1 + fVar3;
  param_2[2] = (float)uVar6 / fVar2 + fVar4;
  param_2[3] = 0.0;
  return;
}

