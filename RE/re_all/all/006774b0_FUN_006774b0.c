
void FUN_006774b0(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8)

{
  byte bVar1;
  uint uVar2;
  char cVar3;
  char *pcVar4;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  char local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  
  switch(param_5) {
  case 0:
    switch(param_4) {
    case 1:
    case 2:
    case 4:
    case 8:
    case 0x10:
switchD_0067751c_caseD_1:
      *(undefined1 *)(param_1 + 0x15b) = 1;
      goto LAB_00677593;
    default:
      pcVar4 = s_Invalid_bit_depth_for_grayscale_i_00a0d3ec;
    }
    break;
  default:
    pcVar4 = s_Invalid_image_color_type_specifi_00a0d330;
    break;
  case 2:
    if ((param_4 != 8) && (param_4 != 0x10)) {
      FUN_00668620(param_1,s_Invalid_bit_depth_for_RGB_image_00a0d3cc);
    }
    *(undefined1 *)(param_1 + 0x15b) = 3;
    goto LAB_00677593;
  case 3:
    switch(param_4) {
    case 1:
    case 2:
    case 4:
    case 8:
      goto switchD_0067751c_caseD_1;
    default:
      pcVar4 = s_Invalid_bit_depth_for_paletted_i_00a0d3a4;
    }
    break;
  case 4:
    if ((param_4 != 8) && (param_4 != 0x10)) {
      FUN_00668620(param_1,s_Invalid_bit_depth_for_grayscale__00a0d378);
    }
    *(undefined1 *)(param_1 + 0x15b) = 2;
    goto LAB_00677593;
  case 6:
    if ((param_4 != 8) && (param_4 != 0x10)) {
      FUN_00668620(param_1,s_Invalid_bit_depth_for_RGBA_image_00a0d354);
    }
    *(undefined1 *)(param_1 + 0x15b) = 4;
    goto LAB_00677593;
  }
  FUN_00668620(param_1,pcVar4);
LAB_00677593:
  if (param_6 != 0) {
    FUN_006687b0(param_1,s_Invalid_compression_type_specifi_00a0d30c);
    param_6 = 0;
  }
  if ((((((*(byte *)(param_1 + 0x268) & 4) == 0) || ((*(uint *)(param_1 + 0x74) & 0x1000) != 0)) ||
       ((param_5 != 2 && (param_5 != 6)))) || (param_7 != 0x40)) && (param_7 != 0)) {
    FUN_006687b0(param_1,s_Invalid_filter_type_specified_00a0d2ec);
    param_7 = 0;
  }
  if ((param_8 != 0) && (param_8 != 1)) {
    FUN_006687b0(param_1,s_Invalid_interlace_type_specified_00a0d2c8);
    param_8 = 1;
  }
  *(char *)(param_1 + 0x154) = (char)param_8;
  *(undefined1 *)(param_1 + 0x157) = (undefined1)param_5;
  *(undefined1 *)(param_1 + 0x26c) = (undefined1)param_7;
  cVar3 = (char)param_4;
  bVar1 = *(char *)(param_1 + 0x15b) * cVar3;
  *(undefined1 *)(param_1 + 0x28c) = (undefined1)param_6;
  *(char *)(param_1 + 0x158) = cVar3;
  *(int *)(param_1 + 0x100) = param_2;
  *(undefined4 *)(param_1 + 0x104) = param_3;
  *(byte *)(param_1 + 0x15a) = bVar1;
  if (bVar1 < 8) {
    uVar2 = (uint)bVar1 * param_2 + 7 >> 3;
  }
  else {
    uVar2 = (uint)(bVar1 >> 3) * param_2;
  }
  *(char *)(param_1 + 0x15c) = *(char *)(param_1 + 0x15b);
  *(uint *)(param_1 + 0x110) = uVar2;
  *(int *)(param_1 + 0x10c) = param_2;
  *(char *)(param_1 + 0x159) = cVar3;
  FUN_00677240(local_10,param_2);
  FUN_00677240(local_c,param_3);
  local_6 = (undefined1)param_6;
  local_7 = (undefined1)param_5;
  local_5 = (undefined1)param_7;
  local_8 = cVar3;
  local_4 = (char)param_8;
  FUN_00677430(param_1,0x49484452,local_10,0xd);
  if (*(char *)(param_1 + 0x156) == '\0') {
    if ((*(char *)(param_1 + 0x157) != '\x03') && (7 < *(byte *)(param_1 + 0x158))) {
      *(undefined1 *)(param_1 + 0x156) = 0xf8;
      *(undefined4 *)(param_1 + 0x74) = 1;
      return;
    }
    *(undefined1 *)(param_1 + 0x156) = 8;
  }
  *(undefined4 *)(param_1 + 0x74) = 1;
  return;
}

