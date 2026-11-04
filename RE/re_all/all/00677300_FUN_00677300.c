
void FUN_00677300(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x2c4) = 0x22;
    FUN_00677240(local_8,param_3);
    FUN_00677240(local_4,param_2);
    FUN_00671060(param_1,local_8,8);
    *(undefined4 *)(param_1 + 0x11c) = param_2;
    FUN_00668f30(param_1);
    FUN_00668f50(param_1,local_4,4);
    *(undefined4 *)(param_1 + 0x2c4) = 0x42;
  }
  return;
}

