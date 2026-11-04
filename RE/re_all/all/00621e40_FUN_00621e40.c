
undefined4 * __thiscall
FUN_00621e40(undefined4 *param_1,int *param_2,int *param_3,undefined4 param_4,undefined4 param_5)

{
  float10 fVar1;
  
  *param_1 = &PTR_LAB_00804524;
  param_1[1] = 0;
  param_1[2] = 0x3f800000;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[6] = param_4;
  param_1[5] = param_5;
  param_1[7] = param_2;
  param_1[8] = param_3;
  param_1[9] = param_2[1];
  param_1[10] = param_3[1];
  fVar1 = (float10)(**(code **)(*param_2 + 0x28))();
  param_1[0xb] = (float)fVar1;
  fVar1 = (float10)(**(code **)(*param_3 + 0x28))();
  param_1[0xc] = (float)fVar1;
  *(undefined1 *)(param_1 + 0xd) = 0;
  param_1[0xf] = 0xffffffff;
  param_1[0x12] = 1;
  *param_1 = &PTR_LAB_00804670;
  return param_1;
}

