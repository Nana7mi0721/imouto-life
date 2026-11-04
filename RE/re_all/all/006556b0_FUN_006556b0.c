
int FUN_006556b0(short *param_1,int param_2,short *param_3)

{
  short sVar1;
  short sVar2;
  int iVar3;
  short *psVar4;
  
  psVar4 = param_1;
  if ((*(int *)(param_2 + 0xc) == 0) && (*(uint *)(param_2 + 8) < (uint)(ushort)param_1[0x31])) {
    return 1;
  }
  iVar3 = FUN_00654cb0(param_1,param_2,&param_1);
  if (iVar3 != 0) {
    return iVar3;
  }
  sVar2 = psVar4[0x31] + -1;
  sVar1 = *param_1;
  *param_3 = sVar1;
  iVar3 = 0;
  psVar4 = param_1;
  if (sVar2 != 0) {
    while (psVar4 = psVar4 + 1, *psVar4 == sVar1) {
      sVar2 = sVar2 + -1;
      if (sVar2 == 0) {
        FUN_006507e0(param_1);
        return 0;
      }
    }
    iVar3 = 5;
  }
  FUN_006507e0(param_1);
  return iVar3;
}

