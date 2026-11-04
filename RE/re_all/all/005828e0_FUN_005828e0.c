
void FUN_005828e0(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[4];
  param_1[2] = param_2[8];
  param_1[3] = 0;
  param_1[4] = param_2[1];
  param_1[5] = param_2[5];
  param_1[6] = param_2[9];
  param_1[7] = 0;
  param_1[8] = param_2[2];
  param_1[9] = param_2[6];
  param_1[10] = param_2[10];
  param_1[0xb] = 0;
  param_1[0xc] = param_2[3];
  param_1[0xd] = param_2[7];
  param_1[0xe] = param_2[0xb];
  param_1[0xf] = 0x3f800000;
  return;
}

