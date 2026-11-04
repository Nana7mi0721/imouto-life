
undefined4 FUN_0058daa0(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_10;
  
  if (DAT_00a37dc8 == 1) {
    FUN_005db960(param_1,param_2);
    return 0;
  }
  iVar1 = FUN_00586970(param_1,1);
  if (iVar1 < 0) {
    return 0xffffffff;
  }
  pcVar3 = *(char **)(param_1 + 0x48c);
  pcVar5 = *(char **)(param_1 + 0xd0c);
  iVar1 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20);
  iVar6 = *(int *)(param_1 + 0x488) + iVar1 * -4;
  local_10 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24);
  iVar7 = *(int *)(param_1 + 0xd08) + iVar1 * -4;
  if (param_2 == 0) {
    do {
      iVar8 = iVar1;
      do {
        pcVar2 = pcVar3 + 4;
        *pcVar5 = -1 - *pcVar3;
        pcVar4 = pcVar5 + 4;
        pcVar5[1] = -1 - pcVar3[1];
        iVar8 = iVar8 + -1;
        pcVar5[2] = -1 - pcVar3[2];
        pcVar5[3] = pcVar3[3];
        pcVar3 = pcVar2;
        pcVar5 = pcVar4;
      } while (iVar8 != 0);
      pcVar3 = pcVar2 + iVar6;
      pcVar5 = pcVar4 + iVar7;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
    FUN_00586b00();
    return 0;
  }
  do {
    iVar8 = iVar1;
    do {
      pcVar2 = pcVar3 + 4;
      *pcVar5 = (&DAT_00a52a60)
                [CONCAT11(-1 - (&DAT_00a62a60)[CONCAT11(*pcVar3,pcVar3[3])],pcVar3[3])];
      pcVar4 = pcVar5 + 4;
      pcVar5[1] = (&DAT_00a52a60)
                  [CONCAT11(-1 - (&DAT_00a62a60)[CONCAT11(pcVar3[1],pcVar3[3])],pcVar3[3])];
      iVar8 = iVar8 + -1;
      pcVar5[2] = (&DAT_00a52a60)
                  [CONCAT11(-1 - (&DAT_00a62a60)[CONCAT11(pcVar3[2],pcVar3[3])],pcVar3[3])];
      pcVar5[3] = pcVar3[3];
      pcVar3 = pcVar2;
      pcVar5 = pcVar4;
    } while (iVar8 != 0);
    pcVar3 = pcVar2 + iVar6;
    pcVar5 = pcVar4 + iVar7;
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  FUN_00586b00();
  return 0;
}

