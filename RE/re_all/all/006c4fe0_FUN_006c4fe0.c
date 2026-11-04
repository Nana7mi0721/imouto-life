
int FUN_006c4fe0(int param_1,char *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_3) {
    param_1 = param_1 - (int)param_2;
    do {
      iVar1 = (int)param_2[param_1];
      iVar2 = (int)*param_2;
      if ((0x60 < iVar1) && (iVar1 < 0x7b)) {
        iVar1 = iVar1 + -0x20;
      }
      if ((0x60 < iVar2) && (iVar2 < 0x7b)) {
        iVar2 = iVar2 + -0x20;
      }
      if (iVar1 - iVar2 != 0) {
        return iVar1 - iVar2;
      }
      iVar3 = iVar3 + 1;
      param_2 = param_2 + 1;
    } while (iVar3 < param_3);
  }
  return 0;
}

