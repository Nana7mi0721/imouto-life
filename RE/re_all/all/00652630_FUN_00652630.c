
undefined4 FUN_00652630(undefined4 *param_1,uint param_2)

{
  char *pcVar1;
  
  if (param_1[2] == 1) {
    FUN_006512e0(param_1[0x9d],*param_1,s_File_not_open_for_reading_00a06fd4);
    return 0;
  }
  if (((uint)param_1[3] >> 10 & 1) == param_2) {
    return 1;
  }
  pcVar1 = s_Can_not_read_tiles_from_a_stripp_00a06fa8;
  if (param_2 == 0) {
    pcVar1 = s_Can_not_read_scanlines_from_a_ti_00a06f7c;
  }
  FUN_006512e0(param_1[0x9d],*param_1,pcVar1);
  return 0;
}

