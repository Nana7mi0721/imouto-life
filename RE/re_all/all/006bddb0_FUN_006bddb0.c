
void FUN_006bddb0(int param_1,int param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  param_1 = param_1 + param_2 * -2;
  pbVar3 = (byte *)(param_2 * 2 + param_1);
  do {
    bVar1 = *(byte *)(param_1 + param_2 + iVar5);
    cVar2 = *(char *)(((int)((((uint)*pbVar3 - (uint)bVar1) * 3 - (uint)pbVar3[param_2]) + 4 +
                            (uint)*(byte *)(iVar5 + param_1)) >> 3) + param_3);
    iVar4 = (uint)bVar1 + (int)cVar2;
    *(byte *)(param_1 + param_2 + iVar5) = (-(0xff < iVar4) | bVar1 + cVar2) & (iVar4 < 0) - 1U;
    iVar4 = (uint)*pbVar3 - (int)cVar2;
    iVar5 = iVar5 + 1;
    *pbVar3 = (-(0xff < iVar4) | *pbVar3 - cVar2) & (iVar4 < 0) - 1U;
    pbVar3 = pbVar3 + 1;
  } while (iVar5 < 8);
  return;
}

