
void FUN_00671110(int param_1,undefined4 param_2,int param_3,int param_4)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x60) = param_2;
    if (param_3 == 0) {
      *(code **)(param_1 + 0x58) = FUN_00671090;
    }
    else {
      *(int *)(param_1 + 0x58) = param_3;
    }
    if (param_4 == 0) {
      *(undefined1 **)(param_1 + 0x17c) = &LAB_006710f0;
    }
    else {
      *(int *)(param_1 + 0x17c) = param_4;
    }
    if (*(int *)(param_1 + 0x5c) != 0) {
      *(undefined4 *)(param_1 + 0x5c) = 0;
      FUN_006687b0(param_1,s_Can_t_set_both_read_data_fn_and_w_00a0bba0);
    }
  }
  return;
}

