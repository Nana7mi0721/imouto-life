
int FUN_00668e30(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  byte local_8 [8];
  
  local_8[0] = 0x89;
  local_8[1] = 0x50;
  local_8[2] = 0x4e;
  local_8[3] = 0x47;
  local_8[4] = 0xd;
  local_8[5] = 10;
  local_8[6] = 0x1a;
  local_8[7] = 10;
  if (param_3 < 9) {
    if (param_3 == 0) {
      return -1;
    }
  }
  else {
    param_3 = 8;
  }
  if (7 < param_2) {
    return -1;
  }
  if (8 < param_2 + param_3) {
    param_3 = 8 - param_2;
  }
  bVar4 = false;
  iVar1 = 0;
  bVar5 = true;
  pbVar2 = (byte *)(param_1 + param_2);
  pbVar3 = local_8 + param_2;
  do {
    if (param_3 == 0) break;
    param_3 = param_3 - 1;
    bVar4 = *pbVar2 < *pbVar3;
    bVar5 = *pbVar2 == *pbVar3;
    pbVar2 = pbVar2 + 1;
    pbVar3 = pbVar3 + 1;
  } while (bVar5);
  if (!bVar5) {
    iVar1 = (1 - (uint)bVar4) - (uint)(bVar4 != 0);
  }
  return iVar1;
}

