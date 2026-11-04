
undefined4 FUN_0065dbb0(undefined4 *param_1,int *param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  short sVar10;
  uint uVar11;
  bool bVar12;
  longlong lVar13;
  longlong lVar14;
  uint uStack_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int iStack_38;
  uint local_34;
  uint uStack_30;
  undefined8 local_2c;
  uint uStack_24;
  int iStack_20;
  int local_1c;
  uint local_18;
  undefined2 uStack_14;
  short sStack_12;
  undefined2 uStack_10;
  undefined2 uStack_e;
  uint uStack_c;
  undefined8 uStack_8;
  
  local_34 = (uint)param_2 & 0xffff;
  local_44 = 0;
  local_40 = 0;
  local_1c = 0;
  local_18 = 0;
  local_2c._0_4_ = 0;
  local_2c._4_4_ = 0;
  local_3c = 0;
  FUN_00653760(param_1,local_34,0);
  if ((param_1[3] & 0x800) != 0) {
    FUN_006512e0(param_1[0x9d],"TIFFResetField",s_Memory_mapped_files_not_currentl_00a0a880);
    return 0;
  }
  if (param_1[4] == 0 && param_1[5] == 0) {
    FUN_006512e0(param_1[0x9d],"TIFFResetField",s_Attempt_to_reset_field_on_direct_00a0a844);
    return 0;
  }
  iVar8 = param_1[5];
  uVar11 = param_1[4];
  lVar14 = *(longlong *)(param_1 + 4);
  lVar13 = (*(code *)param_1[0xa0])(param_1[0x9d],uVar11,iVar8,0);
  if (lVar13 != lVar14) {
    FUN_006512e0(param_1[0x9d],"TIFFResetField",s__s__Seek_error_accessing_TIFF_di_00a0a458,*param_1
                );
    return 0;
  }
  if ((param_1[3] & 0x80000) == 0) {
    iVar2 = (*(code *)param_1[0x9e])(param_1[0x9d],&uStack_48,2);
    if (iVar2 != 2) {
      FUN_006512e0(param_1[0x9d],"TIFFResetField",s__s__Can_not_read_TIFF_directory_c_00a0a430,
                   *param_1);
      return 0;
    }
    if ((*(byte *)(param_1 + 3) & 0x80) != 0) {
      FUN_0065a5f0(&uStack_48);
    }
    uVar9 = 0xc;
    bVar12 = 0xfffffffd < uVar11;
    uVar11 = uVar11 + 2;
    iStack_38 = 0xc;
  }
  else {
    iVar2 = (*(code *)param_1[0x9e])(param_1[0x9d],&uStack_24,8);
    if (iVar2 != 8) {
      FUN_006512e0(param_1[0x9d],"TIFFResetField",s__s__Can_not_read_TIFF_directory_c_00a0a430,
                   *param_1);
      return 0;
    }
    if ((*(byte *)(param_1 + 3) & 0x80) != 0) {
      FUN_0065a620(&uStack_24);
    }
    uVar9 = 0x14;
    uStack_48 = uStack_24;
    iStack_38 = 0x14;
    bVar12 = 0xfffffff7 < uVar11;
    uVar11 = uVar11 + 8;
  }
  iVar8 = iVar8 + (uint)bVar12;
  uStack_24 = uVar11;
  iStack_20 = iVar8;
  if ((short)uStack_48 != 0) {
    do {
      uVar3 = (*(code *)param_1[0x9e])(param_1[0x9d],&uStack_14,uVar9);
      if (uVar3 != uVar9) {
        uStack_24 = uVar11;
        iStack_20 = iVar8;
        FUN_006512e0(param_1[0x9d],"TIFFResetField",s__s__Can_not_read_TIFF_directory_e_00a0a800,
                     *param_1);
        return 0;
      }
      local_44 = CONCAT22(sStack_12,uStack_14);
      if ((*(byte *)(param_1 + 3) & 0x80) != 0) {
        FUN_0065a5f0(&local_44);
      }
      if ((short)local_44 == (short)param_2) {
        uStack_24 = uVar11;
        iStack_20 = iVar8;
        goto LAB_0065de46;
      }
      bVar12 = CARRY4(uVar11,uVar9);
      uVar11 = uVar11 + uVar9;
      iVar8 = iVar8 + (uint)bVar12;
    } while ((short)uStack_48 != 0);
    uStack_24 = uVar11;
    iStack_20 = iVar8;
  }
  if ((short)local_44 != (short)param_2) {
    FUN_006512e0(param_1[0x9d],"TIFFResetField",s__s__Could_not_find_tag__d__00a0a828,*param_1,
                 local_34);
    return 0;
  }
LAB_0065de46:
  local_40._0_2_ = sStack_12;
  if ((*(byte *)(param_1 + 3) & 0x80) != 0) {
    FUN_0065a5f0(&local_40);
  }
  uVar11 = param_1[3];
  iVar8 = CONCAT22(uStack_e,uStack_10);
  if ((uVar11 & 0x80000) == 0) {
    param_2 = (int *)iVar8;
    if ((uVar11 & 0x80) != 0) {
      FUN_0065a600(&param_2);
    }
    local_1c = (int)param_2;
    local_18 = 0;
    param_2 = (int *)uStack_c;
    if ((*(byte *)(param_1 + 3) & 0x80) != 0) {
      FUN_0065a600(&param_2);
    }
    local_2c._4_4_ = 0;
    local_2c._0_4_ = (uint)param_2;
  }
  else {
    local_18 = uStack_c;
    local_1c = iVar8;
    if ((uVar11 & 0x80) != 0) {
      FUN_0065a620(&local_1c);
    }
    local_2c._0_4_ = (uint)uStack_8;
    local_2c._4_4_ = uStack_8._4_4_;
    if ((*(byte *)(param_1 + 3) & 0x80) != 0) {
      FUN_0065a620(&local_2c);
    }
  }
  iVar8 = param_3;
  iVar2 = FUN_00653680(param_3);
  if ((iVar2 == 8) && ((param_1[3] & 0x80000) == 0)) {
    if (iVar8 == 0x10) {
      iVar2 = 4;
    }
    else if (iVar8 == 0x11) {
      iVar2 = 9;
    }
    else {
      iVar2 = 0xd;
      if (iVar8 != 0x12) goto LAB_0065df41;
    }
  }
  else {
LAB_0065df41:
    iVar2 = iVar8;
  }
  uVar4 = FUN_00653680(iVar2,s_for_field_buffer__00a0a7ec);
  iVar1 = param_4;
  param_2 = (int *)FUN_00650c00(param_1,param_4,uVar4);
  if (param_2 == (int *)0x0) {
    return 0;
  }
  if (iVar2 == iVar8) {
    iVar8 = FUN_00653680(iVar2);
    piVar5 = param_5;
    piVar7 = param_2;
    for (uVar11 = (uint)(iVar8 * iVar1) >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
      *piVar7 = *piVar5;
      piVar5 = piVar5 + 1;
      piVar7 = piVar7 + 1;
    }
    for (uVar11 = iVar8 * iVar1 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
      *(char *)piVar7 = (char)*piVar5;
      piVar5 = (int *)((int)piVar5 + 1);
      piVar7 = (int *)((int)piVar7 + 1);
    }
  }
  else if (iVar2 == 9) {
    if ((iVar8 == 0x11) && (param_3 = 0, 0 < iVar1)) {
      piVar5 = param_5;
      piVar7 = param_2;
      do {
        iVar8 = *piVar5;
        *piVar7 = iVar8;
        if ((iVar8 != *piVar5) || (iVar8 >> 0x1f != piVar5[1])) {
          FUN_006507e0(param_2);
          FUN_006512e0(param_1[0x9d],"TIFFResetField",s_Value_exceeds_32bit_range_of_out_00a0a7c0);
          return 0;
        }
        piVar7 = piVar7 + 1;
        param_3 = param_3 + 1;
        piVar5 = piVar5 + 2;
      } while (param_3 < iVar1);
    }
  }
  else if (iVar2 == 4) {
    if (iVar8 == 0x10) goto LAB_0065e071;
  }
  else if ((iVar2 == 0xd) && (iVar8 == 0x12)) {
LAB_0065e071:
    iVar8 = 0;
    if (0 < iVar1) {
      piVar5 = param_5;
      piVar7 = param_2;
      do {
        iVar6 = *piVar5;
        *piVar7 = iVar6;
        if ((iVar6 != *piVar5) || (piVar5[1] != 0)) {
          FUN_006507e0(param_2);
          FUN_006512e0(param_1[0x9d],"TIFFResetField",s_Value_exceeds_32bit_range_of_out_00a0a7c0);
          return 0;
        }
        iVar8 = iVar8 + 1;
        piVar7 = piVar7 + 1;
        piVar5 = piVar5 + 2;
      } while (iVar8 < iVar1);
    }
  }
  iVar8 = FUN_00653680(iVar2);
  if ((1 < iVar8) && ((*(byte *)(param_1 + 3) & 0x80) != 0)) {
    iVar8 = FUN_00653680(iVar2);
    if (iVar8 == 2) {
      FUN_0065a660(param_2,iVar1);
    }
    else {
      iVar8 = FUN_00653680(iVar2);
      if (iVar8 == 4) {
        FUN_0065a6c0(param_2,iVar1);
      }
      else {
        iVar8 = FUN_00653680(iVar2);
        if (iVar8 == 8) {
          FUN_0065a700(param_2,iVar1);
        }
      }
    }
  }
  if ((param_1[3] & 0x80000) == 0) {
    iVar8 = FUN_00653680(iVar2);
    if (4 < iVar8 * iVar1) goto LAB_0065e162;
    bVar12 = 0xfffffff7 < uStack_24;
    local_2c._0_4_ = uStack_24 + 8;
  }
  else {
    iVar8 = FUN_00653680(iVar2);
    if (8 < iVar8 * iVar1) goto LAB_0065e162;
    bVar12 = 0xfffffff3 < uStack_24;
    local_2c._0_4_ = uStack_24 + 0xc;
  }
  local_2c._4_4_ = iStack_20 + (uint)bVar12;
  local_3c = 1;
LAB_0065e162:
  uStack_30 = iVar1 >> 0x1f;
  sVar10 = (short)iVar2;
  if (((local_1c == iVar1) && (local_18 == uStack_30)) && ((short)local_40 == sVar10)) {
    lVar14 = (*(code *)param_1[0xa0])(param_1[0x9d],(uint)local_2c,local_2c._4_4_,0);
    if (lVar14 != CONCAT44(local_2c._4_4_,(uint)local_2c)) {
      FUN_006507e0(param_2);
      FUN_006512e0(param_1[0x9d],"TIFFResetField",s__s__Seek_error_accessing_TIFF_di_00a0a458,
                   *param_1);
      return 0;
    }
    iVar8 = FUN_00653680(iVar2);
    piVar5 = param_2;
    param_2 = (int *)(*(code *)param_1[0x9f])(param_1[0x9d],param_2,iVar8 * iVar1);
    iVar8 = FUN_00653680(iVar2);
    if (param_2 != (int *)(iVar8 * iVar1)) {
      FUN_006507e0(piVar5);
      FUN_006512e0(param_1[0x9d],"TIFFResetField",s_Error_writing_directory_link_00a069d4);
      return 0;
    }
    FUN_006507e0(piVar5);
  }
  else {
    if (local_3c == 0) {
      local_2c = (*(code *)param_1[0xa0])(param_1[0x9d],0,0,2);
      iVar8 = FUN_00653680(iVar2);
      iVar8 = (*(code *)param_1[0x9f])(param_1[0x9d],param_2,iVar8 * iVar1);
      iVar6 = FUN_00653680(iVar2);
      if (iVar8 != iVar6 * iVar1) {
        FUN_006507e0(param_2);
        FUN_006512e0(param_1[0x9d],"TIFFResetField",s_Error_writing_directory_link_00a069d4);
        return 0;
      }
      FUN_006507e0(param_2);
    }
    else {
      iVar8 = FUN_00653680(iVar2);
      piVar5 = param_2;
      piVar7 = (int *)&local_2c;
      for (uVar11 = (uint)(iVar8 * iVar1) >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *piVar7 = *piVar5;
        piVar5 = piVar5 + 1;
        piVar7 = piVar7 + 1;
      }
      for (uVar11 = iVar8 * iVar1 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(char *)piVar7 = (char)*piVar5;
        piVar5 = (int *)((int)piVar5 + 1);
        piVar7 = (int *)((int)piVar7 + 1);
      }
    }
    local_40 = iVar2;
    sStack_12 = sVar10;
    if ((*(byte *)(param_1 + 3) & 0x80) != 0) {
      FUN_0065a5f0(&sStack_12);
    }
    uVar11 = param_1[3];
    uStack_10 = (undefined2)local_1c;
    uStack_e = (undefined2)((uint)local_1c >> 0x10);
    if ((uVar11 & 0x80000) == 0) {
      if ((uVar11 & 0x80) != 0) {
        FUN_0065a600(&uStack_10);
      }
      uStack_c = (uint)local_2c;
      uStack_8 = CONCAT44(uStack_8._4_4_,(uint)uStack_8);
      if ((*(byte *)(param_1 + 3) & 0x80) != 0) {
        FUN_0065a600(&uStack_c);
      }
    }
    else {
      uStack_c = local_18;
      if ((uVar11 & 0x80) != 0) {
        FUN_0065a620(&uStack_10);
      }
      uStack_8 = local_2c;
      if ((*(byte *)(param_1 + 3) & 0x80) != 0) {
        FUN_0065a620(&uStack_8);
      }
    }
    lVar14 = CONCAT44(iStack_20,uStack_24);
    lVar13 = (*(code *)param_1[0xa0])(param_1[0x9d],uStack_24,iStack_20,0);
    iVar8 = iStack_38;
    if (lVar13 != lVar14) {
      FUN_006512e0(param_1[0x9d],"TIFFResetField",s__s__Seek_error_accessing_TIFF_di_00a0a458,
                   *param_1);
      return 0;
    }
    iVar2 = (*(code *)param_1[0x9f])(param_1[0x9d],&uStack_14,iStack_38);
    if (iVar2 != iVar8) {
      FUN_006512e0(param_1[0x9d],"TIFFResetField",s__s__Can_not_write_TIFF_directory_00a0a798,
                   *param_1);
      return 0;
    }
  }
  return 1;
}

