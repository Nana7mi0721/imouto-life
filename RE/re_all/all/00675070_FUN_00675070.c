
void FUN_00675070(uint param_1,int param_2,uint param_3)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  
  uVar3 = param_3;
  iVar2 = param_1;
  if ((*(uint *)(param_1 + 0x74) & 1) == 0) {
    FUN_00668a30(param_1,s_missing_IHDR_00a0ce1c);
  }
  else {
    if ((*(uint *)(param_1 + 0x74) & 4) != 0) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(iVar2,s_out_of_place_00a0cdb4);
      return;
    }
    if ((param_2 != 0) && ((*(uint *)(param_2 + 8) & 0x4000) != 0)) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(iVar2,s_duplicate_00a0bdf4);
      return;
    }
    if (param_3 < 4) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(iVar2,s_invalid_00a0cdac);
      return;
    }
  }
  pcVar4 = (char *)FUN_00674040(iVar2,uVar3 + 1,2);
  if (pcVar4 == (char *)0x0) {
    FUN_00668b90(iVar2,s_out_of_memory_00a0ce9c);
    FUN_00673140(iVar2,uVar3);
    return;
  }
  FUN_00673110(iVar2,pcVar4,uVar3);
  pcVar4[uVar3] = '\0';
  iVar5 = FUN_00673140(iVar2,0);
  if (iVar5 == 0) {
    if ((*pcVar4 != '\x01') && (*pcVar4 != '\x02')) {
      FUN_00668b90(iVar2,s_invalid_unit_00a0d064);
      return;
    }
    param_3 = 1;
    param_1 = 0;
    iVar5 = FUN_0066af60(pcVar4,uVar3,&param_1,&param_3);
    if ((iVar5 != 0) && (param_3 < uVar3)) {
      pcVar1 = pcVar4 + param_3;
      uVar6 = param_3 + 1;
      param_3 = uVar6;
      if (*pcVar1 == '\0') {
        if ((param_1 & 0x188) != 0x108) {
          FUN_00668b90(iVar2,s_non_positive_width_00a0d050);
          return;
        }
        param_1 = 0;
        iVar5 = FUN_0066af60(pcVar4,uVar3,&param_1,&param_3);
        if ((iVar5 == 0) || (param_3 != uVar3)) {
          FUN_00668b90(iVar2,s_bad_height_format_00a0d028);
          return;
        }
        if ((param_1 & 0x188) == 0x108) {
          FUN_00672490(iVar2,param_2,*pcVar4,pcVar4 + 1,pcVar4 + uVar6);
          return;
        }
        FUN_00668b90(iVar2,s_non_positive_height_00a0d03c);
        return;
      }
    }
    FUN_00668b90(iVar2,s_bad_width_format_00a0d014);
  }
  return;
}

