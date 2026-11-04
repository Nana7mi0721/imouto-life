
void FUN_00674de0(int param_1,int param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  byte bVar11;
  byte bVar12;
  char cVar13;
  uint uVar14;
  char *pcVar15;
  int iVar16;
  char *pcVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  char *pcVar20;
  
  if ((*(uint *)(param_1 + 0x74) & 1) == 0) {
    FUN_00668a30(param_1,s_missing_IHDR_00a0ce1c);
  }
  else {
    if ((*(uint *)(param_1 + 0x74) & 4) != 0) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(param_1,s_out_of_place_00a0cdb4);
      return;
    }
    if ((param_2 != 0) && ((*(uint *)(param_2 + 8) & 0x400) != 0)) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(param_1,s_duplicate_00a0bdf4);
      return;
    }
  }
  pcVar15 = (char *)FUN_00674040(param_1,param_3 + 1,2);
  if (pcVar15 == (char *)0x0) {
    FUN_00673140(param_1);
    FUN_00668b90(param_1,s_out_of_memory_00a0ce9c);
    return;
  }
  FUN_00673110(param_1,pcVar15,param_3);
  iVar16 = FUN_00673140(param_1,0);
  if (iVar16 == 0) {
    pcVar20 = pcVar15 + param_3;
    *pcVar20 = '\0';
    cVar3 = *pcVar15;
    pcVar17 = pcVar15;
    while (cVar3 != '\0') {
      pcVar1 = pcVar17 + 1;
      pcVar17 = pcVar17 + 1;
      cVar3 = *pcVar1;
    }
    if (pcVar20 <= pcVar17 + 0xc) {
      FUN_00668b90(param_1,s_invalid_00a0cdac);
      return;
    }
    cVar3 = pcVar17[1];
    cVar4 = pcVar17[2];
    cVar5 = pcVar17[3];
    pcVar1 = pcVar17 + 0xb;
    cVar6 = pcVar17[4];
    cVar7 = pcVar17[6];
    cVar8 = pcVar17[5];
    cVar9 = pcVar17[7];
    cVar10 = pcVar17[8];
    bVar11 = pcVar17[10];
    bVar12 = pcVar17[9];
    if (bVar12 == 0) {
      if (bVar11 != 2) {
LAB_00674f77:
        FUN_00668b90(param_1,s_invalid_parameter_count_00a0cffc);
        return;
      }
    }
    else if ((bVar12 == 1) || (bVar12 == 2)) {
      if (bVar11 != 3) goto LAB_00674f77;
    }
    else if (bVar12 == 3) {
      if (bVar11 != 4) goto LAB_00674f77;
    }
    else if (3 < bVar12) {
      FUN_00668b90(param_1,s_unrecognized_equation_type_00a0cfe0);
    }
    cVar13 = *pcVar1;
    pcVar17 = pcVar1;
    while (cVar13 != '\0') {
      pcVar2 = pcVar17 + 1;
      pcVar17 = pcVar17 + 1;
      cVar13 = *pcVar2;
    }
    uVar14 = (uint)bVar11;
    puVar18 = (undefined4 *)FUN_0066cb30(param_1,uVar14 * 4);
    if (puVar18 == (undefined4 *)0x0) {
      FUN_00668b90(param_1,s_out_of_memory_00a0ce9c);
      return;
    }
    iVar16 = 0;
    if (bVar11 != 0) {
      puVar19 = puVar18;
      do {
        pcVar17 = pcVar17 + 1;
        *puVar19 = pcVar17;
        while( true ) {
          if (pcVar20 < pcVar17) goto LAB_00675011;
          if (*pcVar17 == '\0') break;
          pcVar17 = pcVar17 + 1;
        }
        if (pcVar20 < pcVar17) {
LAB_00675011:
          FUN_0066cb60(param_1,puVar18);
          FUN_00668b90(param_1,s_invalid_data_00a0cfd0);
          return;
        }
        iVar16 = iVar16 + 1;
        puVar19 = puVar19 + 1;
      } while (iVar16 < (int)uVar14);
    }
    FUN_00672210(param_1,param_2,pcVar15,CONCAT31(CONCAT21(CONCAT11(cVar3,cVar4),cVar5),cVar6),
                 CONCAT31(CONCAT21(CONCAT11(cVar8,cVar7),cVar9),cVar10),bVar12,uVar14,pcVar1,puVar18
                );
    FUN_0066cb60(param_1,puVar18);
  }
  return;
}

