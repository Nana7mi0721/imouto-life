
void FUN_00675370(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 local_1c;
  char *local_18;
  char *local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar3 = *(int *)(param_1 + 0x298);
  if (iVar3 != 0) {
    if (iVar3 == 1) {
      FUN_00673140(param_1,param_3);
      return;
    }
    *(int *)(param_1 + 0x298) = iVar3 + -1;
    if (iVar3 + -1 == 1) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(param_1,s_no_space_in_chunk_cache_00a0d0a0);
      return;
    }
  }
  if ((*(byte *)(param_1 + 0x74) & 1) == 0) {
    FUN_00668a30(param_1,s_missing_IHDR_00a0ce1c);
  }
  if ((*(uint *)(param_1 + 0x74) & 4) != 0) {
    *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 8;
  }
  pcVar2 = (char *)FUN_00674040(param_1,param_3 + 1,1);
  if (pcVar2 == (char *)0x0) {
    FUN_00668b90(param_1,s_out_of_memory_00a0ce9c);
    return;
  }
  FUN_00673110(param_1,pcVar2,param_3);
  iVar3 = FUN_00673140(param_1,0);
  if (iVar3 == 0) {
    pcVar2[param_3] = '\0';
    cVar1 = *pcVar2;
    local_14 = pcVar2;
    while (cVar1 != '\0') {
      pcVar5 = local_14 + 1;
      local_14 = local_14 + 1;
      cVar1 = *pcVar5;
    }
    if (local_14 != pcVar2 + param_3) {
      local_14 = local_14 + 1;
    }
    uVar4 = 0xffffffff;
    local_1c = 0xffffffff;
    local_8 = 0;
    local_4 = 0;
    local_c = 0;
    pcVar5 = local_14;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    local_10 = ~uVar4 - 1;
    local_18 = pcVar2;
    iVar3 = FUN_00672780(param_1,param_2,&local_1c,1);
    if (iVar3 != 0) {
      FUN_006687b0(param_1,s_Insufficient_memory_to_process_t_00a0d074);
    }
  }
  return;
}

