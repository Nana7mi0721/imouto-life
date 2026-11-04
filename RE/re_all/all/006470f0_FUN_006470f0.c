
undefined4 FUN_006470f0(uint *param_1,uint param_2,uint param_3,char *param_4)

{
  uint *puVar1;
  ushort *puVar2;
  ushort uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *_Format;
  char *pcVar9;
  ushort *local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  uint local_4;
  
  uVar7 = param_2;
  puVar4 = param_1;
  puVar1 = param_1 + 6;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  *(undefined2 *)((int)param_1 + 0x1e) = 4;
  *param_1 = param_2;
  param_1[1] = param_3;
  FUN_00651280(param_2,0x102,puVar1);
  uVar3 = (ushort)*puVar1;
  pcVar9 = (char *)(uint)uVar3;
  switch(uVar3) {
  case 1:
  case 2:
  case 4:
  case 8:
  case 0x10:
    break;
  default:
    _Format = s_Sorry__can_not_handle_images_wit_00a0627c;
LAB_0064761b:
    _sprintf(param_4,_Format,pcVar9);
    goto LAB_00647623;
  }
  puVar2 = (ushort *)((int)puVar4 + 0x1a);
  puVar4[3] = 0;
  FUN_00651280(uVar7,0x115,puVar2);
  FUN_00651280(uVar7,0x152,&param_3,&local_14);
  if ((short)param_3 != 0) {
    uVar3 = *local_14;
    if (uVar3 == 0) {
      if (3 < *puVar2) {
        puVar4[3] = 1;
      }
    }
    else if (uVar3 < 3) {
      puVar4[3] = (uint)uVar3;
    }
  }
  puVar1 = puVar4 + 8;
  iVar5 = FUN_0064e2c0(uVar7,0x106,puVar1);
  if (iVar5 == 0) {
    *(ushort *)puVar1 = 0;
  }
  if ((((short)param_3 == 0) && (*puVar2 == 4)) && ((ushort)*puVar1 == 2)) {
    puVar4[3] = 1;
    param_3 = 1;
  }
  iVar8 = (uint)*puVar2 - (param_3 & 0xffff);
  FUN_00651280(uVar7,0x103,&param_1);
  FUN_00651280(uVar7,0x11c,&param_2);
  iVar5 = FUN_0064e2c0(uVar7,0x106,puVar1);
  if (iVar5 == 0) {
    if (iVar8 == 1) {
      iVar5 = FUN_00647690(uVar7);
      *(ushort *)puVar1 = (ushort)(iVar5 == 0);
    }
    else {
      if (iVar8 != 3) {
        pcVar9 = "PhotometricInterpretation";
        _Format = s_Missing_needed__s_tag_00a06450;
        goto LAB_0064761b;
      }
      *(ushort *)puVar1 = 2;
    }
  }
  uVar6 = (uint)(ushort)*puVar1;
  if (0x804c < uVar6) {
    if (uVar6 != 0x804d) {
switchD_0064727e_caseD_4:
      _sprintf(param_4,s_Sorry__can_not_handle_image_with_00a06320,"PhotometricInterpretation",uVar6
              );
      goto LAB_00647623;
    }
    if (((short)param_1 != -0x788c) && ((short)param_1 != -0x788b)) {
      _sprintf(param_4,s_Sorry__LogLuv_data_must_have__s__00a062f4,s_Compression_00a0636c,0x8774,
               0x8775);
      goto LAB_00647623;
    }
    if ((short)param_2 != 1) {
      _sprintf(param_4,s_Sorry__can_not_handle_LogLuv_ima_00a062b0,s_Planarconfiguration_00a062e0,
               param_2 & 0xffff);
      return 0;
    }
    FUN_0064e1d0(uVar7,0x10018,3);
    *(ushort *)puVar1 = 2;
LAB_00647556:
    *(undefined2 *)(puVar4 + 6) = 8;
    goto switchD_0064727e_caseD_8;
  }
  if (uVar6 == 0x804c) {
    if ((short)param_1 != -0x788c) {
      _sprintf(param_4,s_Sorry__LogL_data_must_have__s__d_00a06348,s_Compression_00a0636c,0x8774);
      goto LAB_00647623;
    }
    FUN_0064e1d0(uVar7,0x10018,3);
    *(ushort *)puVar1 = 1;
    goto LAB_00647556;
  }
  switch(uVar6) {
  case 0:
  case 1:
    goto switchD_0064727e_caseD_0;
  case 2:
    if (iVar8 < 3) {
      _sprintf(param_4,s_Sorry__can_not_handle_RGB_image_w_00a063b4,s_Color_channels_00a063e0,iVar8)
      ;
      goto LAB_00647623;
    }
    break;
  case 3:
    iVar5 = FUN_0064e2c0(uVar7,0x140,&local_10,&local_c,&local_8);
    if (iVar5 == 0) {
      _sprintf(param_4,s_Missing_required__Colormap__tag_00a064dc);
      goto LAB_00647623;
    }
    iVar5 = (1 << ((byte)puVar4[6] & 0x1f)) * 2;
    uVar6 = FUN_006507d0(iVar5);
    puVar4[9] = uVar6;
    uVar6 = FUN_006507d0(iVar5);
    puVar4[10] = uVar6;
    uVar6 = FUN_006507d0(iVar5);
    puVar4[0xb] = uVar6;
    if (((puVar4[9] == 0) || (puVar4[10] == 0)) || (uVar6 == 0)) {
      _sprintf(param_4,s_Out_of_memory_for_colormap_copy_00a064bc);
      goto LAB_00647623;
    }
    FUN_00650840(puVar4[9],local_10,iVar5);
    FUN_00650840(puVar4[10],local_c,iVar5);
    FUN_00650840(puVar4[0xb],local_8,iVar5);
switchD_0064727e_caseD_0:
    if ((((short)param_2 == 1) && (*(ushort *)((int)puVar4 + 0x1a) != 1)) && ((ushort)puVar4[6] < 8)
       ) {
      _sprintf(param_4,s_Sorry__can_not_handle_contiguous_00a063f0,"PhotometricInterpretation",
               (uint)(ushort)*puVar1,s_Samples_pixel_00a06440,(uint)*(ushort *)((int)puVar4 + 0x1a),
               (uint)(ushort)puVar4[6]);
      goto LAB_00647623;
    }
    break;
  default:
    goto switchD_0064727e_caseD_4;
  case 5:
    FUN_00651280(uVar7,0x14c,&local_4);
    if ((short)local_4 != 1) {
      _sprintf(param_4,s_Sorry__can_not_handle_separated_i_00a06378,s_InkSet_00a063ac,
               local_4 & 0xffff);
      goto LAB_00647623;
    }
    if (*(ushort *)((int)puVar4 + 0x1a) < 4) {
      _sprintf(param_4,s_Sorry__can_not_handle_separated_i_00a06378,s_Samples_pixel_00a06440,
               (uint)*(ushort *)((int)puVar4 + 0x1a));
      goto LAB_00647623;
    }
    break;
  case 6:
    if (((short)param_2 == 1) && ((short)param_1 == 7)) {
      FUN_0064e1d0(uVar7,0x10002,1);
      *(ushort *)puVar1 = 2;
    }
    break;
  case 8:
    break;
  }
switchD_0064727e_caseD_8:
  puVar4[0xe] = 0;
  puVar4[0xf] = 0;
  puVar4[0x10] = 0;
  puVar4[0x11] = 0;
  puVar4[0x12] = 0;
  puVar4[0x13] = 0;
  puVar4[0x14] = 0;
  FUN_0064e2c0(uVar7,0x100,puVar4 + 4);
  FUN_0064e2c0(uVar7,0x101,puVar4 + 5);
  FUN_00651280(uVar7,0x112,puVar4 + 7);
  if (((short)param_2 == 2) && (1 < *(ushort *)((int)puVar4 + 0x1a))) {
    uVar7 = 0;
  }
  else {
    uVar7 = 1;
  }
  puVar4[2] = uVar7;
  if (uVar7 == 0) {
    iVar5 = FUN_0064c940(puVar4);
    if (iVar5 != 0) {
      return 1;
    }
    _sprintf(param_4,s_Sorry__can_not_handle_image_00a064a0);
  }
  else {
    iVar5 = FUN_00647750();
    if (iVar5 != 0) {
      return 1;
    }
    _sprintf(param_4,s_Sorry__can_not_handle_image_00a064a0);
  }
LAB_00647623:
  FUN_006507e0(puVar4[9]);
  FUN_006507e0(puVar4[10]);
  FUN_006507e0(puVar4[0xb]);
  puVar4[0xb] = 0;
  puVar4[10] = 0;
  puVar4[9] = 0;
  return 0;
}

