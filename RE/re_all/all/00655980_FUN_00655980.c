
void FUN_00655980(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  char *pcVar1;
  
  if (param_5 != 0) {
    switch(param_2) {
    case 1:
      pcVar1 = s_Incorrect_count_for___s___tag_ig_00a0a130;
      goto LAB_00655a5b;
    case 2:
      pcVar1 = s_Incompatible_type_for___s___tag_i_00a0a108;
      goto LAB_00655aa2;
    case 3:
      pcVar1 = s_IO_error_during_reading_of___s___00a0a0d8;
      goto LAB_00655ac5;
    case 4:
      pcVar1 = s_Incorrect_value_for___s___tag_ig_00a0a0b0;
      break;
    case 5:
      pcVar1 = s_Cannot_handle_different_values_p_00a0a070;
LAB_00655aa2:
      FUN_00653460(*(undefined4 *)(param_1 + 0x274),param_3,pcVar1,param_4);
      return;
    case 6:
      pcVar1 = s_Sanity_check_on_size_of___s__val_00a0a038;
LAB_00655ac5:
      FUN_00653460(*(undefined4 *)(param_1 + 0x274),param_3,pcVar1,param_4);
      return;
    case 7:
      pcVar1 = s_Out_of_memory_reading_of___s___t_00a0a00c;
      break;
    default:
      goto switchD_0065599a_default;
    }
    FUN_00653460(*(undefined4 *)(param_1 + 0x274),param_3,pcVar1,param_4);
switchD_0065599a_default:
    return;
  }
  switch(param_2) {
  case 1:
    pcVar1 = s_Incorrect_count_for___s__00a0a230;
    break;
  case 2:
    pcVar1 = s_Incompatible_type_for___s__00a0a214;
    goto LAB_006559ce;
  case 3:
    pcVar1 = s_IO_error_during_reading_of___s__00a0a1f4;
    goto LAB_00655a5b;
  case 4:
    pcVar1 = s_Incorrect_value_for___s__00a0a1d8;
    break;
  case 5:
    pcVar1 = s_Cannot_handle_different_values_p_00a0a1a4;
LAB_006559ce:
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),param_3,pcVar1,param_4);
    return;
  case 6:
    pcVar1 = s_Sanity_check_on_size_of___s__val_00a0a178;
LAB_00655a5b:
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),param_3,pcVar1,param_4);
    return;
  case 7:
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),param_3,s_Out_of_memory_reading_of___s__00a0a158,
                 param_4);
    return;
  default:
    goto switchD_0065599a_default;
  }
  FUN_006512e0(*(undefined4 *)(param_1 + 0x274),param_3,pcVar1,param_4);
  return;
}

