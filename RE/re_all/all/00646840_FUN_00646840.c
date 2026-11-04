
undefined4 * __thiscall FUN_00646840(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  param_1[1] = param_2;
  param_1[2] = 0xffffffff;
  param_1[3] = 0xffffffff;
  *(undefined1 *)(param_1 + 4) = 0;
  param_1[7] = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  param_1[5] = &DAT_00f3f830;
  param_1[6] = &DAT_00f3f830;
  param_1[8] = 0x3e99999a;
  *param_1 = &PTR_LAB_008048bc;
  FUN_0063c260(0,&local_10);
  return param_1;
}

