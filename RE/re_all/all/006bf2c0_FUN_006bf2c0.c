
void FUN_006bf2c0(int param_1,int param_2,byte *param_3,int param_4,short *param_5)

{
  int iVar1;
  short sVar2;
  int iVar3;
  byte *pbVar4;
  short *psVar5;
  int local_8;
  
  local_8 = 8;
  psVar5 = param_5;
  do {
    param_5 = (short *)0x8;
    pbVar4 = param_3;
    do {
      sVar2 = *psVar5;
      iVar3 = (int)((uint)pbVar4[param_2 - (int)param_3] + (uint)*pbVar4) >> 1;
      iVar1 = *psVar5 + iVar3;
      psVar5 = psVar5 + 1;
      pbVar4[param_1 - (int)param_3] =
           (-(0xff < iVar1) | (char)sVar2 + (char)iVar3) & (iVar1 < 0) - 1U;
      pbVar4 = pbVar4 + 1;
      param_5 = (short *)((int)param_5 + -1);
    } while (param_5 != (short *)0x0);
    param_1 = param_1 + param_4;
    param_2 = param_2 + param_4;
    param_3 = param_3 + param_4;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  return;
}

