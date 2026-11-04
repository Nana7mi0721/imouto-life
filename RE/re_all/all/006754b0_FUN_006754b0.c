
void FUN_006754b0(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  undefined4 local_1c;
  int local_18;
  int local_14;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = *(int *)(param_1 + 0x298);
  if (iVar2 != 0) {
    if (iVar2 == 1) {
      FUN_00673140(param_1,param_3);
      return;
    }
    *(int *)(param_1 + 0x298) = iVar2 + -1;
    if (iVar2 + -1 == 1) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(param_1,s_no_space_in_chunk_cache_00a0d0a0);
      return;
    }
  }
  if ((*(byte *)(param_1 + 0x74) & 1) == 0) {
    FUN_00668a30(param_1,s_missing_IHDR_00a0ce1c);
  }
  uVar1 = param_3;
  if ((*(uint *)(param_1 + 0x74) & 4) != 0) {
    *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 8;
  }
  iVar2 = FUN_00674040(param_1,param_3,2);
  if (iVar2 == 0) {
    FUN_00673140(param_1);
    FUN_00668b90(param_1,s_out_of_memory_00a0ce9c);
    return;
  }
  FUN_00673110(param_1,iVar2,uVar1);
  iVar3 = FUN_00673140(param_1,0);
  if (iVar3 != 0) {
    return;
  }
  uVar5 = 0;
  if (uVar1 != 0) {
    do {
      if (*(char *)(uVar5 + iVar2) == '\0') break;
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
    if ((uVar5 < 0x50) && (uVar5 != 0)) {
      if (uVar1 < uVar5 + 3) {
        pcVar4 = s_truncated_00a0bd48;
      }
      else if (*(char *)(uVar5 + 1 + iVar2) == '\0') {
        param_3 = 0xffffffff;
        iVar2 = FUN_00675660(param_1,uVar1,uVar5 + 2,&param_3,1);
        if (iVar2 == 1) {
          local_18 = *(int *)(param_1 + 0x2b8);
          *(undefined1 *)(param_3 + uVar5 + 2 + local_18) = 0;
          local_14 = uVar5 + 2 + local_18;
          local_1c = 0;
          local_c = 0;
          local_8 = 0;
          local_4 = 0;
          local_10 = param_3;
          iVar2 = FUN_00672780(param_1,param_2,&local_1c,1);
          if (iVar2 == 0) {
            return;
          }
          pcVar4 = s_insufficient_memory_00a0bd54;
        }
        else {
          pcVar4 = *(char **)(param_1 + 0x9c);
        }
      }
      else {
        pcVar4 = s_unknown_compression_type_00a0d0b8;
      }
      goto LAB_0067564a;
    }
  }
  pcVar4 = s_bad_keyword_00a0ce78;
LAB_0067564a:
  if (pcVar4 != (char *)0x0) {
    FUN_00668b90(param_1,pcVar4);
  }
  return;
}

