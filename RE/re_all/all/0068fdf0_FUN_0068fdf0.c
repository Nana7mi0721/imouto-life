
void FUN_0068fdf0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1[0x61];
  *(undefined4 *)(iVar1 + 8) = 0;
  FUN_0068fea0(param_1);
  if (param_2 == 0) {
    if (*(int *)(iVar1 + 0x40) != 0) {
      *(undefined4 *)(*param_1 + 0x14) = 3;
      (**(code **)*param_1)(param_1);
    }
    *(undefined **)(iVar1 + 4) = &DAT_0068fef0;
    return;
  }
  if (param_2 == 2) {
    if (*(int *)(iVar1 + 0x40) == 0) {
      *(undefined4 *)(*param_1 + 0x14) = 3;
      (**(code **)*param_1)(param_1);
    }
    *(code **)(iVar1 + 4) = FUN_006903f0;
    return;
  }
  if (param_2 != 3) {
    *(undefined4 *)(*param_1 + 0x14) = 3;
    (**(code **)*param_1)(param_1);
    return;
  }
  if (*(int *)(iVar1 + 0x40) == 0) {
    *(undefined4 *)(*param_1 + 0x14) = 3;
    (**(code **)*param_1)(param_1);
  }
  *(undefined1 **)(iVar1 + 4) = &LAB_00690170;
  return;
}

