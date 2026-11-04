
void FUN_006bdd10(int param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  
  pbVar5 = (byte *)(param_1 + -2);
  param_1 = 8;
  do {
    bVar1 = pbVar5[2];
    bVar2 = pbVar5[1];
    cVar3 = *(char *)(((int)((((uint)bVar1 - (uint)bVar2) * 3 - (uint)pbVar5[3]) + 4 + (uint)*pbVar5
                            ) >> 3) + param_3);
    iVar4 = (uint)bVar2 + (int)cVar3;
    iVar6 = (uint)bVar1 - (int)cVar3;
    pbVar5[1] = (-(0xff < iVar4) | bVar2 + cVar3) & (iVar4 < 0) - 1U;
    pbVar5[2] = (-(0xff < iVar6) | bVar1 - cVar3) & (iVar6 < 0) - 1U;
    pbVar5 = pbVar5 + param_2;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  return;
}

