
int FUN_006b75b0(undefined4 param_1,int param_2,int param_3,uint *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_2 + 0x504);
  iVar2 = 0;
  if (((param_3 == 0) || (param_4 == (uint *)0x0)) ||
     (iVar2 = FUN_006ac620(param_1,iVar3 * 4), iVar3 < 1)) {
    return iVar2;
  }
  param_3 = param_3 - (int)param_4;
  iVar4 = iVar2 - (int)param_4;
  do {
    iVar1 = (*(uint *)(param_3 + (int)param_4) & 0x7fff) * (0x10000 - param_5) + 0x8000 +
            (*param_4 & 0x7fff) * param_5;
    *(int *)(iVar4 + (int)param_4) = iVar1 >> 0x10;
    if (((*(uint *)(param_3 + (int)param_4) & 0x8000) != 0) && ((*param_4 & 0x8000) != 0)) {
      *(uint *)(iVar4 + (int)param_4) = (int)(short)((uint)iVar1 >> 0x10) | 0x8000;
    }
    param_4 = param_4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return iVar2;
}

