
LONG FUN_006081a0(int *param_1)

{
  LONG LVar1;
  
  if (param_1[0x11] == 1) {
    param_1[0x11] = 0;
  }
  else {
    LVar1 = InterlockedDecrement(param_1 + 0x11);
    if (LVar1 != 0) {
      return LVar1;
    }
  }
  if ((*(byte *)(param_1 + 1) & 8) != 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0);
  }
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0x10] = 0;
  (**(code **)(*(int *)(param_1[6] + 0xc) + 0x20))((int *)(param_1[6] + 0xc),param_1);
  return 0;
}

