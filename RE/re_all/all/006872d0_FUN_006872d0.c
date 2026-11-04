
void FUN_006872d0(int param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  char local_20 [32];
  
  local_20[0] = '\0';
  local_20[1] = '\0';
  local_20[2] = '\0';
  local_20[3] = '\0';
  local_20[4] = '\0';
  local_20[5] = '\0';
  local_20[6] = '\0';
  local_20[7] = '\0';
  local_20[8] = '\0';
  local_20[9] = '\0';
  local_20[10] = '\0';
  local_20[0xb] = '\0';
  local_20[0x10] = '\0';
  local_20[0x11] = '\0';
  local_20[0x12] = '\0';
  local_20[0x13] = '\0';
  local_20[0xc] = '\0';
  local_20[0xd] = '\0';
  local_20[0xe] = '\0';
  local_20[0xf] = '\0';
  iVar6 = *(int *)(param_1 + 0x114);
  local_20[0x14] = '\0';
  local_20[0x15] = '\0';
  local_20[0x16] = '\0';
  local_20[0x17] = '\0';
  local_20[0x18] = '\0';
  local_20[0x19] = '\0';
  local_20[0x1a] = '\0';
  local_20[0x1b] = '\0';
  local_20[0x1c] = '\0';
  local_20[0x1d] = '\0';
  local_20[0x1e] = '\0';
  local_20[0x1f] = '\0';
  if (0 < iVar6) {
    iVar4 = *(int *)(param_1 + 0x15c);
    iVar2 = *(int *)(param_1 + 0x160);
    piVar5 = (int *)(param_1 + 0x118);
    do {
      iVar3 = *piVar5;
      if ((iVar4 == 0) && (*(int *)(param_1 + 0x164) == 0)) {
        local_20[*(int *)(iVar3 + 0x14)] = '\x01';
      }
      if (iVar2 != 0) {
        local_20[*(int *)(iVar3 + 0x18) + 0x10] = '\x01';
      }
      piVar5 = piVar5 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  iVar6 = 0;
  iVar4 = 0;
  do {
    pcVar1 = local_20 + iVar4;
    iVar2 = iVar4 + 0x10;
    iVar4 = iVar4 + 1;
    iVar6 = *pcVar1 + iVar6 + (int)local_20[iVar2];
  } while (iVar4 < 0x10);
  if (iVar6 != 0) {
    FUN_00686af0(param_1,0xcc);
    FUN_00686b50(param_1,iVar6 * 2 + 2);
    iVar6 = 0;
    do {
      if (local_20[iVar6] != '\0') {
        FUN_00686b10(param_1,iVar6);
        FUN_00686b10(param_1,(uint)*(byte *)(iVar6 + 0xa8 + param_1) * 0x10 +
                             (uint)*(byte *)(iVar6 + 0x98 + param_1));
      }
      if (local_20[iVar6 + 0x10] != '\0') {
        FUN_00686b10(param_1,iVar6 + 0x10);
        FUN_00686b10(param_1,*(undefined1 *)(iVar6 + 0xb8 + param_1));
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x10);
  }
  return;
}

