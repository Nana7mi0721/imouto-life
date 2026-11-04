
void FUN_00683fa0(int *param_1,char param_2)

{
  if (param_1[5] != 100) {
    *(undefined4 *)(*param_1 + 0x14) = 0x15;
    *(int *)(*param_1 + 0x18) = param_1[5];
    (**(code **)*param_1)(param_1);
  }
  if (param_2 != '\0') {
    FUN_00683e30(param_1,0);
  }
  (**(code **)(*param_1 + 0x10))(param_1);
  (**(code **)(param_1[6] + 8))(param_1);
  FUN_006875b0(param_1);
  (**(code **)param_1[0x5e])(param_1);
  param_1[0x3e] = 0;
  param_1[5] = ((char)param_1[0x34] != '\0') + 0x65;
  return;
}

