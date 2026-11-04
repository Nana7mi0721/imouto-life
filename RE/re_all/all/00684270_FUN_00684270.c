
void FUN_00684270(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1[5] != 100) {
    *(undefined4 *)(*param_1 + 0x14) = 0x15;
    *(int *)(*param_1 + 0x18) = param_1[5];
    (**(code **)*param_1)(param_1);
  }
  if (param_1[0x15] == 0) {
    iVar1 = (**(code **)param_1[1])(param_1,0,0x370);
    param_1[0x15] = iVar1;
  }
  param_1[0xe] = 1;
  param_1[0xf] = 1;
  param_1[0x12] = 8;
  FUN_00684250(param_1,0x4b,1);
  FUN_00684380(param_1);
  piVar2 = param_1 + 0x2a;
  do {
    *(undefined1 *)(piVar2 + -4) = 0;
    *(undefined1 *)piVar2 = 1;
    *(undefined1 *)(piVar2 + 4) = 5;
    piVar2 = (int *)((int)piVar2 + 1);
  } while ((int)((-0xa8 - (int)param_1) + (int)piVar2) < 0x10);
  param_1[0x33] = 0;
  param_1[0x32] = 0;
  *(undefined1 *)(param_1 + 0x34) = 0;
  *(undefined1 *)((int)param_1 + 0xd1) = 0;
  *(undefined1 *)((int)param_1 + 0xd2) = 0;
  if (8 < param_1[0x12]) {
    *(undefined1 *)((int)param_1 + 0xd2) = 1;
  }
  *(undefined1 *)((int)param_1 + 0xd3) = 0;
  *(undefined1 *)(param_1 + 0x35) = 1;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  *(undefined1 *)((int)param_1 + 0xe9) = 1;
  *(undefined1 *)((int)param_1 + 0xea) = 1;
  *(undefined1 *)((int)param_1 + 0xeb) = 0;
  *(undefined2 *)(param_1 + 0x3b) = 1;
  *(undefined2 *)((int)param_1 + 0xee) = 1;
  param_1[0x3d] = 0;
  FUN_00684480(param_1);
  return;
}

