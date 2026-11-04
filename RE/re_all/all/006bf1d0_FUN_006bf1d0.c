
void FUN_006bf1d0(int param_1,int param_2,short *param_3)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 8;
  do {
    iVar4 = 0;
    do {
      sVar1 = *param_3;
      sVar2 = *param_3;
      param_3 = param_3 + 1;
      *(byte *)(iVar4 + param_1) =
           (-(0xff < sVar1 + 0x80) | (char)sVar2 + 0x80U) & (sVar1 + 0x80 < 0) - 1U;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 8);
    param_1 = param_1 + param_2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

