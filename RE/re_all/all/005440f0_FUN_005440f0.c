
int FUN_005440f0(int param_1,int param_2,int param_3,int param_4,byte param_5)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  int local_4;
  
  if (*(char *)(param_1 + 4) != '\x01') {
    if (*(char *)(param_1 + 0xb) == '\0') {
      iVar1 = 0;
    }
    else {
      iVar1 = (uint)(param_5 >> (8U - *(char *)(param_1 + 0xb) & 0x1f)) <<
              (*(byte *)(param_1 + 0xf) & 0x1f);
    }
    return ((uint)((byte)param_4 >> (8U - *(char *)(param_1 + 10) & 0x1f)) <<
           (*(byte *)(param_1 + 0xe) & 0x1f)) +
           ((uint)((byte)param_3 >> (8U - *(char *)(param_1 + 9) & 0x1f)) <<
           (*(byte *)(param_1 + 0xd) & 0x1f)) +
           ((uint)((byte)param_2 >> (8U - *(char *)(param_1 + 8) & 0x1f)) <<
           (*(byte *)(param_1 + 0xc) & 0x1f)) + *(int *)(param_1 + 0x20) + iVar1;
  }
  uVar4 = 0xffffff;
  local_4 = 0;
  pbVar2 = (byte *)(param_1 + 0x28);
  param_1 = 2;
  do {
    uVar3 = ((uint)*pbVar2 - param_4) * ((uint)*pbVar2 - param_4) +
            ((uint)pbVar2[1] - param_3) * ((uint)pbVar2[1] - param_3) +
            ((uint)pbVar2[2] - param_2) * ((uint)pbVar2[2] - param_2);
    if (uVar3 < uVar4) {
      local_4 = param_1 + -2;
      uVar4 = uVar3;
    }
    uVar3 = ((uint)pbVar2[4] - param_4) * ((uint)pbVar2[4] - param_4) +
            ((uint)pbVar2[5] - param_3) * ((uint)pbVar2[5] - param_3) +
            ((uint)pbVar2[6] - param_2) * ((uint)pbVar2[6] - param_2);
    if (uVar3 < uVar4) {
      local_4 = param_1 + -1;
      uVar4 = uVar3;
    }
    uVar3 = ((uint)pbVar2[8] - param_4) * ((uint)pbVar2[8] - param_4) +
            ((uint)pbVar2[9] - param_3) * ((uint)pbVar2[9] - param_3) +
            ((uint)pbVar2[10] - param_2) * ((uint)pbVar2[10] - param_2);
    if (uVar3 < uVar4) {
      local_4 = param_1;
      uVar4 = uVar3;
    }
    uVar3 = ((uint)pbVar2[0xc] - param_4) * ((uint)pbVar2[0xc] - param_4) +
            ((uint)pbVar2[0xd] - param_3) * ((uint)pbVar2[0xd] - param_3) +
            ((uint)pbVar2[0xe] - param_2) * ((uint)pbVar2[0xe] - param_2);
    if (uVar3 < uVar4) {
      local_4 = param_1 + 1;
      uVar4 = uVar3;
    }
    iVar1 = param_1 + 2;
    pbVar2 = pbVar2 + 0x10;
    param_1 = param_1 + 4;
  } while (iVar1 < 0x100);
  return local_4;
}

