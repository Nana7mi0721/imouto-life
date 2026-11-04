
void FUN_0066ad80(int param_1,uint param_2,uint param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8)

{
  bool bVar1;
  char *pcVar2;
  
  bVar1 = false;
  if (param_2 == 0) {
    pcVar2 = s_Image_width_is_zero_in_IHDR_00a0c43c;
LAB_0066adbc:
    FUN_006687b0(param_1,pcVar2);
    bVar1 = true;
  }
  else {
    if (0x7fffffff < param_2) {
      pcVar2 = s_Invalid_image_width_in_IHDR_00a0c420;
      goto LAB_0066adbc;
    }
    if (*(uint *)(param_1 + 0x290) < param_2) {
      pcVar2 = s_Image_width_exceeds_user_limit_i_00a0c3f8;
      goto LAB_0066adbc;
    }
  }
  if (param_3 == 0) {
    pcVar2 = s_Image_height_is_zero_in_IHDR_00a0c3d8;
LAB_0066adf4:
    FUN_006687b0(param_1,pcVar2);
    bVar1 = true;
  }
  else {
    if (0x7fffffff < param_3) {
      pcVar2 = s_Invalid_image_height_in_IHDR_00a0c3b8;
      goto LAB_0066adf4;
    }
    if (*(uint *)(param_1 + 0x294) < param_3) {
      pcVar2 = s_Image_height_exceeds_user_limit_i_00a0c390;
      goto LAB_0066adf4;
    }
  }
  if ((((param_4 != 1) && (param_4 != 2)) && (param_4 != 4)) &&
     ((param_4 != 8 && (param_4 != 0x10)))) {
    FUN_006687b0(param_1,s_Invalid_bit_depth_in_IHDR_00a0c374);
    bVar1 = true;
  }
  if (((param_5 < 0) || (param_5 == 1)) || ((param_5 == 5 || (6 < param_5)))) {
    FUN_006687b0(param_1,s_Invalid_color_type_in_IHDR_00a0c358);
    bVar1 = true;
  }
  if (param_5 == 3) {
    if (param_4 < 9) goto LAB_0066ae8f;
  }
  else if ((((param_5 != 2) && (param_5 != 4)) && (param_5 != 6)) || (7 < param_4))
  goto LAB_0066ae8f;
  FUN_006687b0(param_1,s_Invalid_color_type_bit_depth_com_00a0c324);
  bVar1 = true;
LAB_0066ae8f:
  if (1 < param_6) {
    FUN_006687b0(param_1,s_Unknown_interlace_method_in_IHDR_00a0c300);
    bVar1 = true;
  }
  if (param_7 != 0) {
    FUN_006687b0(param_1,s_Unknown_compression_method_in_IH_00a0c2dc);
    bVar1 = true;
  }
  if (((*(uint *)(param_1 + 0x74) & 0x1000) != 0) && (*(int *)(param_1 + 0x268) != 0)) {
    FUN_006687b0(param_1,s_MNG_features_are_not_allowed_in_a_00a0c2a8);
  }
  if (param_8 != 0) {
    if ((((*(byte *)(param_1 + 0x268) & 4) == 0) || (param_8 != 0x40)) ||
       (((*(uint *)(param_1 + 0x74) & 0x1000) != 0 || ((param_5 != 2 && (param_5 != 6)))))) {
      FUN_006687b0(param_1,s_Unknown_filter_method_in_IHDR_00a0c288);
      bVar1 = true;
    }
    if ((*(uint *)(param_1 + 0x74) & 0x1000) != 0) {
      FUN_006687b0(param_1,s_Invalid_filter_method_in_IHDR_00a0c268);
      FUN_00668620(param_1,s_Invalid_IHDR_data_00a0c254);
      return;
    }
  }
  if (bVar1) {
    FUN_00668620(param_1,s_Invalid_IHDR_data_00a0c254);
  }
  return;
}

