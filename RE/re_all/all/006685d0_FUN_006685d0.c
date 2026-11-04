
void FUN_006685d0(int param_1,undefined4 param_2,int param_3)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x60) = param_2;
    if (param_3 == 0) {
      *(code **)(param_1 + 0x5c) = FUN_00668590;
    }
    else {
      *(int *)(param_1 + 0x5c) = param_3;
    }
    if (*(int *)(param_1 + 0x58) != 0) {
      *(undefined4 *)(param_1 + 0x58) = 0;
      FUN_006687b0(param_1,s_Can_t_set_both_read_data_fn_and_w_00a0bba0);
    }
    *(undefined4 *)(param_1 + 0x17c) = 0;
  }
  return;
}

