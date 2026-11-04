
undefined4 * __thiscall FUN_00602a90(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  param_1[2] = param_2;
  param_1[1] = 0;
  param_1[4] = 1;
  *param_1 = &PTR_LAB_0080343c;
  (**(code **)(*(int *)(param_2 + 0xc) + 4))((int *)(param_2 + 0xc));
  if (param_2 == 0) {
    uVar1 = (**(code **)(*(int *)param_1[2] + 0x10))();
    param_1[3] = uVar1;
    return param_1;
  }
  param_1[1] = *(undefined4 *)(param_2 + 4);
  param_1[3] = *(undefined4 *)(param_2 + 0xc);
  return param_1;
}

