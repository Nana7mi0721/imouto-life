
void FUN_006371f0(undefined4 *param_1,uint param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  if (param_2 == 0) {
    param_2 = 0;
  }
  else {
    param_2 = (*(int *)(param_2 + 0xe8) != 2) - 1 & param_2;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  if (param_2 == 0) {
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    param_1[0x11] = 0;
    param_1[8] = 0x3f800000;
    param_1[9] = 0x3f800000;
    param_1[10] = 0x3f800000;
    param_1[0xb] = 0;
    return;
  }
  fVar1 = *(float *)(param_2 + 0x150);
  fVar2 = *(float *)(param_2 + 0x150);
  fVar3 = *(float *)(param_2 + 0x168);
  fVar4 = *(float *)(param_2 + 0x16c);
  param_1[0xc] = *(float *)(param_2 + 0x150) * *(float *)(param_2 + 0x164);
  param_1[0x11] = param_2;
  param_1[0xd] = fVar1 * fVar3;
  param_1[0xe] = fVar2 * fVar4;
  param_1[0xf] = 0;
  param_1[8] = *(undefined4 *)(param_2 + 0x154);
  param_1[9] = *(undefined4 *)(param_2 + 0x158);
  param_1[10] = *(undefined4 *)(param_2 + 0x15c);
  param_1[0xb] = *(undefined4 *)(param_2 + 0x160);
  return;
}

