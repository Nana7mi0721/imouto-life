
void FUN_00686f60(int *param_1)

{
  if ((param_1[0x3d] != 1) || (param_1[0x13] < 3)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x1c;
    (**(code **)*param_1)(param_1);
  }
  FUN_00686af0(param_1,0xf8);
  FUN_00686b50(param_1,0x18);
  FUN_00686b10(param_1,0xd);
  FUN_00686b50(param_1,0xff);
  FUN_00686b10(param_1,3);
  FUN_00686b10(param_1,*(undefined4 *)(param_1[0x15] + 0x58));
  FUN_00686b10(param_1,*(undefined4 *)param_1[0x15]);
  FUN_00686b10(param_1,*(undefined4 *)(param_1[0x15] + 0xb0));
  FUN_00686b10(param_1,0x80);
  FUN_00686b50(param_1,0);
  FUN_00686b50(param_1,0);
  FUN_00686b10(param_1,0);
  FUN_00686b50(param_1,1);
  FUN_00686b50(param_1,0);
  FUN_00686b10(param_1,0);
  FUN_00686b50(param_1,1);
  FUN_00686b50(param_1,0);
  return;
}

