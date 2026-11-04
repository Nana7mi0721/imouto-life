
void FUN_0057fb30(int param_1,int *param_2,short *param_3)

{
  short sVar1;
  int iVar2;
  
  if (param_3 == (short *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    sVar1 = *param_3;
    while (sVar1 != 0) {
      iVar2 = iVar2 + 1;
      sVar1 = param_3[iVar2];
    }
    iVar2 = iVar2 * 2 + 2;
  }
  if (param_1 == 0) {
    *param_2 = *param_2 + iVar2 + 2;
    return;
  }
  *(short *)(param_1 + *param_2) = (short)iVar2 + 2;
  if (iVar2 != 0) {
    FUN_0056d420(*param_2 + 2 + param_1,param_3,iVar2);
  }
  *param_2 = *param_2 + iVar2 + 2;
  return;
}

