
void FUN_006bf230(int param_1,byte *param_2,int param_3,short *param_4)

{
  int iVar1;
  short sVar2;
  short *psVar3;
  byte *pbVar4;
  int local_4;
  
  local_4 = 8;
  psVar3 = param_4;
  do {
    param_4 = (short *)0x8;
    pbVar4 = param_2;
    do {
      iVar1 = (int)*psVar3 + (uint)*pbVar4;
      sVar2 = *psVar3;
      psVar3 = psVar3 + 1;
      pbVar4[param_1 - (int)param_2] = (-(0xff < iVar1) | (char)sVar2 + *pbVar4) & (iVar1 < 0) - 1U;
      pbVar4 = pbVar4 + 1;
      param_4 = (short *)((int)param_4 + -1);
    } while (param_4 != (short *)0x0);
    param_1 = param_1 + param_3;
    param_2 = param_2 + param_3;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  return;
}

