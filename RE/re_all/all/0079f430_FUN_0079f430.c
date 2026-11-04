
void FUN_0079f430(short *param_1,int param_2,int param_3)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  
  iVar3 = param_2 + -1;
  iVar1 = param_3 + -0x10000;
  if (0 < iVar3) {
    psVar2 = param_1;
    do {
      *psVar2 = (short)((*psVar2 * param_3 >> 0xf) + 1 >> 1);
      param_3 = param_3 + ((iVar1 * param_3 >> 0xf) + 1 >> 1);
      iVar3 = iVar3 + -1;
      psVar2 = psVar2 + 1;
    } while (iVar3 != 0);
  }
  param_1[param_2 + -1] = (short)((param_1[param_2 + -1] * param_3 >> 0xf) + 1 >> 1);
  return;
}

