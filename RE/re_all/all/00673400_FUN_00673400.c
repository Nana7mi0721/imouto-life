
void FUN_00673400(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined1 local_304;
  undefined1 local_303;
  undefined1 local_302;
  undefined1 local_300 [2];
  undefined1 local_2fe [766];
  
  uVar1 = *(uint *)(param_1 + 0x74);
  if ((uVar1 & 1) == 0) {
    pcVar5 = s_missing_IHDR_00a0ce1c;
LAB_00673421:
    FUN_00668a30(param_1,pcVar5);
  }
  else {
    if ((uVar1 & 2) != 0) {
      pcVar5 = s_duplicate_00a0bdf4;
      goto LAB_00673421;
    }
    if ((uVar1 & 4) != 0) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(param_1,s_out_of_place_00a0cdb4);
      return;
    }
  }
  *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 2;
  if ((*(byte *)(param_1 + 0x157) & 2) == 0) {
    FUN_00673140(param_1,param_3);
    FUN_00668b90(param_1,s_ignored_in_grayscale_PNG_00a0ce00);
    return;
  }
  if ((0x300 < param_3) || (param_3 % 3 != 0)) {
    FUN_00673140(param_1,param_3);
    if (*(char *)(param_1 + 0x157) == '\x03') {
      FUN_00668a30(param_1,s_invalid_00a0cdac);
      return;
    }
    FUN_00668b90();
    return;
  }
  iVar2 = (int)param_3 / 3;
  if (0 < iVar2) {
    puVar4 = local_2fe;
    iVar3 = iVar2;
    do {
      FUN_00673110(param_1,&local_304,3);
      puVar4[-2] = local_304;
      puVar4[-1] = local_303;
      *puVar4 = local_302;
      puVar4 = puVar4 + 3;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  FUN_00673140(param_1,0);
  FUN_00672650(param_1,param_2,local_300,iVar2);
  if (*(short *)(param_1 + 0x150) == 0) {
    if (param_2 == 0) {
      return;
    }
    if ((*(byte *)(param_2 + 8) & 0x10) == 0) goto LAB_00673551;
  }
  *(undefined2 *)(param_1 + 0x150) = 0;
  if (param_2 != 0) {
    *(undefined2 *)(param_2 + 0x16) = 0;
  }
  FUN_00668b90(param_1,s_tRNS_must_be_after_00a0cdec);
LAB_00673551:
  if (param_2 != 0) {
    if ((*(byte *)(param_2 + 8) & 0x40) != 0) {
      FUN_00668b90(param_1,s_hIST_must_be_after_00a0cdd8);
    }
    if ((*(byte *)(param_2 + 8) & 0x20) != 0) {
      FUN_00668b90(param_1,s_bKGD_must_be_after_00a0cdc4);
      return;
    }
  }
  return;
}

