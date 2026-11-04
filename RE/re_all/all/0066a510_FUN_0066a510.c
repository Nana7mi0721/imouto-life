
undefined4
FUN_0066a510(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,
            undefined1 *param_5,byte param_6)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  bool bVar6;
  char *pcVar7;
  
  uVar1 = CONCAT31(CONCAT21(CONCAT11(*param_5,param_5[1]),param_5[2]),param_5[3]);
  if (uVar1 != param_4) {
    pcVar7 = s_length_does_not_match_profile_00a0c114;
LAB_0066a5ef:
    uVar2 = FUN_0066a2d0(param_1,param_2,param_3,uVar1,pcVar7);
    return uVar2;
  }
  if ((3 < (byte)param_5[8]) && ((param_4 & 3) != 0)) {
    uVar2 = FUN_0066a2d0(param_1,param_2,param_3,param_4,s_invalid_length_00a0c104);
    return uVar2;
  }
  uVar1 = CONCAT31(CONCAT21(CONCAT11(param_5[0x80],param_5[0x81]),param_5[0x82]),param_5[0x83]);
  if ((0x1555554a < uVar1) || (param_4 < (uVar1 * 3 + 0x21) * 4)) {
    pcVar7 = s_tag_count_too_large_00a0bf54;
LAB_0066a830:
    uVar2 = FUN_0066a2d0(param_1,param_2,param_3,uVar1,pcVar7);
    return uVar2;
  }
  uVar1 = CONCAT31(CONCAT21(CONCAT11(param_5[0x40],param_5[0x41]),param_5[0x42]),param_5[0x43]);
  if (0xfffe < uVar1) {
    pcVar7 = s_invalid_rendering_intent_00a0c0e8;
    goto LAB_0066a5ef;
  }
  if (3 < uVar1) {
    FUN_0066a2d0(param_1,0,param_3,uVar1,s_intent_outside_defined_range_00a0c0c8);
  }
  uVar1 = CONCAT31(CONCAT21(CONCAT11(param_5[0x24],param_5[0x25]),param_5[0x26]),param_5[0x27]);
  if (uVar1 != 0x61637370) {
    pcVar7 = s_invalid_signature_00a0c0b4;
    goto LAB_0066a830;
  }
  iVar3 = 3;
  bVar6 = true;
  piVar4 = (int *)(param_5 + 0x44);
  piVar5 = &DAT_0081e31c;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *piVar4 == *piVar5;
    piVar4 = piVar4 + 1;
    piVar5 = piVar5 + 1;
  } while (bVar6);
  if (!bVar6) {
    FUN_0066a2d0(param_1,0,param_3,0,s_PCS_illuminant_is_not_D50_00a0c098);
  }
  iVar3 = CONCAT31(CONCAT21(CONCAT11(param_5[0x10],param_5[0x11]),param_5[0x12]),param_5[0x13]);
  if (iVar3 == 0x47524159) {
    if ((param_6 & 2) != 0) {
      uVar2 = FUN_0066a2d0(param_1,param_2,param_3,0x47524159,
                           s_Gray_color_space_not_permitted_o_00a0c01c);
      return uVar2;
    }
  }
  else {
    if (iVar3 != 0x52474220) {
      uVar2 = FUN_0066a2d0(param_1,param_2,param_3,iVar3,s_invalid_ICC_profile_color_space_00a0c078)
      ;
      return uVar2;
    }
    if ((param_6 & 2) == 0) {
      uVar2 = FUN_0066a2d0(param_1,param_2,param_3,0x52474220,
                           s_RGB_color_space_not_permitted_on_00a0c048);
      return uVar2;
    }
  }
  uVar1 = CONCAT31(CONCAT21(CONCAT11(param_5[0xc],param_5[0xd]),param_5[0xe]),param_5[0xf]);
  if (uVar1 < 0x6e6d636d) {
    if (uVar1 != 0x6e6d636c) {
      if (uVar1 == 0x61627374) {
        uVar2 = FUN_0066a2d0(param_1,param_2,param_3,0x61627374,
                             s_invalid_embedded_Abstract_ICC_pr_00a0bfcc);
        return uVar2;
      }
      if (uVar1 == 0x6c696e6b) {
        uVar2 = FUN_0066a2d0(param_1,param_2,param_3,0x6c696e6b,
                             s_unexpected_DeviceLink_ICC_profil_00a0bff4);
        return uVar2;
      }
      if (uVar1 == 0x6d6e7472) goto LAB_0066a7d2;
      goto LAB_0066a7c0;
    }
    pcVar7 = s_unexpected_NamedColor_ICC_profil_00a0bfa4;
    uVar1 = 0x6e6d636c;
  }
  else {
    if (((uVar1 == 0x70727472) || (uVar1 == 0x73636e72)) || (uVar1 == 0x73706163))
    goto LAB_0066a7d2;
LAB_0066a7c0:
    pcVar7 = s_unrecognized_ICC_profile_class_00a0bf84;
  }
  FUN_0066a2d0(param_1,0,param_3,uVar1,pcVar7);
LAB_0066a7d2:
  iVar3 = CONCAT31(CONCAT21(CONCAT11(param_5[0x14],param_5[0x15]),param_5[0x16]),param_5[0x17]);
  if ((iVar3 == 0x4c616220) || (iVar3 == 0x58595a20)) {
    return 1;
  }
  uVar2 = FUN_0066a2d0(param_1,param_2,param_3,iVar3,s_unexpected_ICC_PCS_encoding_00a0bf68);
  return uVar2;
}

