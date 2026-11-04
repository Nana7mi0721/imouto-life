
void FUN_0079f980(int *param_1,int *param_2,short *param_3,short *param_4,int *param_5)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = (int)param_5;
  piVar2 = param_1;
  if (0 < (int)param_5) {
    param_5 = param_2;
    param_1 = (int *)iVar3;
    do {
      sVar1 = *param_3;
      param_3 = param_3 + 1;
      iVar3 = sVar1 * 0x100 + *piVar2;
      *param_5 = iVar3;
      uVar4 = iVar3 * 4;
      uVar5 = uVar4 & 0xffff;
      iVar3 = (int)uVar4 >> 0x10;
      *piVar2 = ((int)((int)*param_4 * uVar5) >> 0x10) + iVar3 * *param_4 + piVar2[1];
      param_5 = param_5 + 1;
      param_1 = (int *)((int)param_1 + -1);
      piVar2[1] = ((int)((int)param_4[1] * uVar5) >> 0x10) + param_4[1] * iVar3;
    } while (param_1 != (int *)0x0);
  }
  return;
}

