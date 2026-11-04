
void FUN_006742e0(int param_1,undefined4 param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  char *pcVar7;
  byte *pbVar8;
  byte *pbVar9;
  char *local_10;
  char local_c;
  int local_8;
  uint local_4;
  
  iVar4 = *(int *)(param_1 + 0x298);
  if (iVar4 != 0) {
    if (iVar4 == 1) {
      FUN_00673140(param_1,param_3);
      return;
    }
    *(int *)(param_1 + 0x298) = iVar4 + -1;
    if (iVar4 + -1 == 1) {
      FUN_006687b0(param_1,s_No_space_in_chunk_cache_for_sPLT_00a0cf80);
      FUN_00673140(param_1,param_3);
      return;
    }
  }
  if ((*(uint *)(param_1 + 0x74) & 1) == 0) {
    FUN_00668a30(param_1,s_missing_IHDR_00a0ce1c);
  }
  else if ((*(uint *)(param_1 + 0x74) & 4) != 0) {
    FUN_00673140(param_1,param_3);
    FUN_00668b90(param_1,s_out_of_place_00a0cdb4);
    return;
  }
  pcVar3 = (char *)FUN_00674040(param_1,param_3 + 1,2);
  if (pcVar3 == (char *)0x0) {
    FUN_00673140(param_1);
    FUN_00668b90(param_1,s_out_of_memory_00a0ce9c);
    return;
  }
  FUN_00673110(param_1,pcVar3,param_3);
  iVar4 = FUN_00673140(param_1,0);
  if (iVar4 == 0) {
    pcVar3[param_3] = '\0';
    cVar2 = *pcVar3;
    pcVar7 = pcVar3;
    while (cVar2 != '\0') {
      pcVar1 = pcVar7 + 1;
      pcVar7 = pcVar7 + 1;
      cVar2 = *pcVar1;
    }
    if (pcVar3 + param_3 + -2 < pcVar7 + 1) {
      FUN_006687b0(param_1,s_malformed_sPLT_chunk_00a0cf68);
      return;
    }
    local_c = pcVar7[1];
    pbVar8 = (byte *)(pcVar7 + 2);
    local_4 = (-(uint)(local_c != '\b') & 4) + 6;
    if ((uint)(pcVar3 + (param_3 - (int)pbVar8)) % local_4 != 0) {
      FUN_006687b0(param_1,s_sPLT_chunk_has_bad_length_00a0cf4c);
      return;
    }
    local_4 = (uint)(pcVar3 + (param_3 - (int)pbVar8)) / local_4;
    if (0x19999999 < local_4) {
      FUN_006687b0(param_1,s_sPLT_chunk_too_long_00a0cf38);
      return;
    }
    local_8 = FUN_0066cb30(param_1,local_4 * 10);
    if (local_8 == 0) {
      FUN_006687b0(param_1,s_sPLT_chunk_requires_too_much_mem_00a0cf14);
      return;
    }
    iVar4 = 0;
    if (0 < (int)local_4) {
      iVar6 = 0;
      do {
        puVar5 = (ushort *)(local_8 + iVar6);
        if (local_c == '\b') {
          *puVar5 = (ushort)*pbVar8;
          puVar5[1] = (ushort)pbVar8[1];
          puVar5[2] = (ushort)pbVar8[2];
          puVar5[3] = (ushort)pbVar8[3];
          pbVar9 = pbVar8 + 4;
        }
        else {
          *puVar5 = CONCAT11(*pbVar8,pbVar8[1]);
          puVar5[1] = CONCAT11(pbVar8[2],pbVar8[3]);
          puVar5[2] = CONCAT11(pbVar8[4],pbVar8[5]);
          pbVar9 = pbVar8 + 8;
          puVar5[3] = CONCAT11(pbVar8[6],pbVar8[7]);
        }
        pbVar8 = pbVar9 + 2;
        puVar5[4] = CONCAT11(*pbVar9,pbVar9[1]);
        iVar4 = iVar4 + 1;
        iVar6 = iVar6 + 10;
      } while (iVar4 < (int)local_4);
    }
    local_10 = pcVar3;
    FUN_00672c30(param_1,param_2,&local_10,1);
    FUN_0066cb60(param_1,local_8);
  }
  return;
}

