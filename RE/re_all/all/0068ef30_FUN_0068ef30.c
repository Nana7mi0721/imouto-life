
void FUN_0068ef30(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x58);
  param_1[0x70] = (int)puVar1;
  *puVar1 = &LAB_0068f3e0;
  puVar1[2] = FUN_0065f670;
  puVar1[3] = &LAB_0068fb60;
  puVar1[0x11] = 0;
  puVar1[0xd] = 0;
  if (4 < param_1[0x19]) {
    *(undefined4 *)(*param_1 + 0x14) = 0x39;
    *(undefined4 *)(*param_1 + 0x18) = 4;
    (**(code **)*param_1)(param_1);
  }
  if (0x100 < param_1[0x15]) {
    *(undefined4 *)(*param_1 + 0x14) = 0x3b;
    *(undefined4 *)(*param_1 + 0x18) = 0x100;
    (**(code **)*param_1)(param_1);
  }
  FUN_0068efd0(param_1);
  FUN_0068f240(param_1);
  if (param_1[0x13] == 2) {
    FUN_0068f3a0(param_1);
  }
  return;
}

