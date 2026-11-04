
uint FUN_005424f0(char *param_1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  
  if ((*param_1 != '\0') || (param_1[4] != '\x01')) {
    return 0xffffffff;
  }
  pbVar5 = *(byte **)(param_1 + 0x434);
  iVar4 = 0;
  bVar2 = 0;
  if (0 < *(int *)(param_1 + 0x42c)) {
    do {
      iVar6 = 0;
      pbVar3 = pbVar5;
      if (0 < *(int *)(param_1 + 0x428)) {
        do {
          bVar1 = *pbVar3;
          if (bVar1 == 0xff) {
            return 0xff;
          }
          if (bVar2 < bVar1) {
            bVar2 = bVar1;
          }
          iVar6 = iVar6 + 1;
          pbVar3 = pbVar3 + 1;
        } while (iVar6 < *(int *)(param_1 + 0x428));
      }
      pbVar5 = pbVar5 + *(int *)(param_1 + 0x430);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x42c));
  }
  return (uint)bVar2;
}

