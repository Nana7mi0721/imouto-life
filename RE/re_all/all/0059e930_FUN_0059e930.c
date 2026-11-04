
void FUN_0059e930(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int local_50;
  uint *local_4c;
  int local_48;
  int *local_44;
  int local_40 [16];
  
  if (DAT_00a3ce50 < 4) {
    local_50 = DAT_00a3ce50;
  }
  else {
    local_50 = 3;
  }
  local_48 = 0;
  piVar6 = &DAT_0085fb48;
  iVar5 = 0x7c;
  local_4c = &DAT_00a380f8;
  local_44 = &DAT_0085fb5c;
  do {
    iVar1 = local_44[1];
    local_40[*local_44 + local_44[-1] * 4] = 0x3f800000;
    iVar3 = local_44[3];
    local_40[local_44[2] + iVar1 * 4] = 0x3f800000;
    local_40[local_44[4] + iVar3 * 4] = 0x3f800000;
    if ((((DAT_00cc79c0 == 0) || (uVar2 = *local_4c, (int)uVar2 < 0)) ||
        ((uVar2 & 0x7c000000) != DAT_00cc79e8)) ||
       (((DAT_00cc79f0 <= (int)(uVar2 & 0xffff) ||
         (piVar4 = *(int **)(DAT_00cc79c4 + (uVar2 & 0xffff) * 4), piVar4 == (int *)0x0)) ||
        ((*piVar4 * 0x10000 != (uVar2 & 0x3ff0000) || (piVar4[4] != 0)))))) {
      iVar1 = piVar6[2];
      local_40[piVar6[1] + *piVar6 * 4] = 0x3f800000;
      local_40[piVar6[3] + iVar1 * 4] = 0;
    }
    else {
      iVar1 = piVar6[3];
      local_40[piVar6[1] + *piVar6 * 4] = piVar4[0x7b];
      iVar3 = 0;
      local_40[iVar1 + piVar6[2] * 4] = piVar4[0x7d];
      if (3 < local_50) {
        piVar4 = piVar6 + 5;
        do {
          if (*(int *)(iVar5 + (&DAT_00a38e44)[(&DAT_00a3ce58)[iVar3]]) == 0) {
            local_40[*piVar4 + piVar4[-1] * 4] = 0;
          }
          if (*(int *)(iVar5 + (&DAT_00a38e44)[(&DAT_00a3ce5c)[iVar3]]) == 0) {
            local_40[piVar4[2] + piVar4[1] * 4] = 0;
          }
          if (*(int *)(iVar5 + (&DAT_00a38e44)[(&DAT_00a3ce60)[iVar3]]) == 0) {
            local_40[piVar4[4] + piVar4[3] * 4] = 0;
          }
          if (*(int *)(iVar5 + (&DAT_00a38e44)[(&DAT_00a3ce64)[iVar3]]) == 0) {
            local_40[piVar4[6] + piVar4[5] * 4] = 0;
          }
          iVar3 = iVar3 + 4;
          piVar4 = piVar4 + 8;
        } while (iVar3 < local_50 + -3);
      }
      if (iVar3 < local_50) {
        piVar4 = &DAT_0085fb5c + (local_48 + iVar3) * 2;
        do {
          if (*(int *)(iVar5 + (&DAT_00a38e44)[(&DAT_00a3ce58)[iVar3]]) == 0) {
            local_40[*piVar4 + piVar4[-1] * 4] = 0;
          }
          iVar3 = iVar3 + 1;
          piVar4 = piVar4 + 2;
        } while (iVar3 < local_50);
      }
    }
    local_4c = local_4c + 1;
    local_48 = local_48 + 5;
    local_44 = local_44 + 10;
    iVar5 = iVar5 + 4;
    piVar6 = piVar6 + 10;
  } while ((int)local_44 < 0x85fbd4);
  FUN_0059cb80(&DAT_00ddb600,3,0,0x12,local_40,4,1);
  return;
}

