
void FUN_007a0290(short *param_1,int param_2)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  int iVar5;
  
  if (1 < param_2) {
    iVar5 = 0;
    psVar3 = param_1;
    do {
      psVar4 = psVar3 + 1;
      sVar1 = *psVar4;
      iVar2 = iVar5;
      if (-1 < iVar5) {
        do {
          if (*psVar3 <= sVar1) break;
          psVar3[1] = *psVar3;
          iVar2 = iVar2 + -1;
          psVar3 = psVar3 + -1;
        } while (-1 < iVar2);
      }
      param_1[iVar2 + 1] = sVar1;
      iVar2 = iVar5 + 2;
      iVar5 = iVar5 + 1;
      psVar3 = psVar4;
    } while (iVar2 < param_2);
  }
  return;
}

