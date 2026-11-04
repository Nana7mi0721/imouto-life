
undefined4 FUN_00646d50(uint param_1,char *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint local_4;
  
  uVar1 = param_1;
  if (*(int *)(param_1 + 500) == 0) {
    _sprintf(param_2,s_Sorry__requested_compression_met_00a06468);
    return 0;
  }
  switch(*(ushort *)(param_1 + 0x54)) {
  case 1:
  case 2:
  case 4:
  case 8:
  case 0x10:
    break;
  default:
    _sprintf(param_2,s_Sorry__can_not_handle_images_wit_00a0627c,(uint)*(ushort *)(param_1 + 0x54));
    return 0;
  }
  iVar4 = (uint)*(ushort *)(param_1 + 0x62) - (uint)*(ushort *)(param_1 + 0x9c);
  iVar2 = FUN_0064e2c0(param_1,0x106,&param_1);
  if (iVar2 == 0) {
    if (iVar4 == 1) {
      param_1 = 1;
    }
    else {
      if (iVar4 != 3) {
        _sprintf(param_2,s_Missing_needed__s_tag_00a06450,"PhotometricInterpretation");
        return 0;
      }
      param_1 = 2;
    }
  }
  uVar3 = param_1 & 0xffff;
  if (uVar3 < 0x804d) {
    if (uVar3 == 0x804c) {
      if (*(short *)(uVar1 + 0x58) != -0x788c) {
        _sprintf(param_2,s_Sorry__LogL_data_must_have__s__d_00a06348,s_Compression_00a0636c,0x8774);
        return 0;
      }
    }
    else {
      switch(uVar3) {
      case 0:
      case 1:
      case 3:
        if (((*(short *)(uVar1 + 0x7e) == 1) && (*(ushort *)(uVar1 + 0x62) != 1)) &&
           (*(ushort *)(uVar1 + 0x54) < 8)) {
          _sprintf(param_2,s_Sorry__can_not_handle_contiguous_00a063f0,"PhotometricInterpretation",
                   uVar3,s_Samples_pixel_00a06440,(uint)*(ushort *)(uVar1 + 0x62),
                   (uint)*(ushort *)(uVar1 + 0x54));
          return 0;
        }
        break;
      case 2:
        if (iVar4 < 3) {
          _sprintf(param_2,s_Sorry__can_not_handle_RGB_image_w_00a063b4,s_Color_channels_00a063e0,
                   iVar4);
          return 0;
        }
        break;
      default:
        goto switchD_00646e1e_caseD_4;
      case 5:
        FUN_00651280(uVar1,0x14c,&local_4);
        if ((short)local_4 != 1) {
          _sprintf(param_2,s_Sorry__can_not_handle_separated_i_00a06378,s_InkSet_00a063ac,
                   local_4 & 0xffff);
          return 0;
        }
        if (*(ushort *)(uVar1 + 0x62) < 4) {
          _sprintf(param_2,s_Sorry__can_not_handle_separated_i_00a06378,s_Samples_pixel_00a06440,
                   (uint)*(ushort *)(uVar1 + 0x62));
          return 0;
        }
        break;
      case 6:
      case 8:
        break;
      }
    }
  }
  else {
    if (uVar3 != 0x804d) {
switchD_00646e1e_caseD_4:
      _sprintf(param_2,s_Sorry__can_not_handle_image_with_00a06320,"PhotometricInterpretation",uVar3
              );
      return 0;
    }
    if ((*(short *)(uVar1 + 0x58) != -0x788c) && (*(short *)(uVar1 + 0x58) != -0x788b)) {
      _sprintf(param_2,s_Sorry__LogLuv_data_must_have__s__00a062f4,s_Compression_00a0636c,0x8774,
               0x8775);
      return 0;
    }
    if (*(ushort *)(uVar1 + 0x7e) != 1) {
      _sprintf(param_2,s_Sorry__can_not_handle_LogLuv_ima_00a062b0,s_Planarconfiguration_00a062e0,
               (uint)*(ushort *)(uVar1 + 0x7e));
      return 0;
    }
  }
  return 1;
}

