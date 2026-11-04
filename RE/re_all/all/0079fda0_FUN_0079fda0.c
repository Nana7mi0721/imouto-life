
void FUN_0079fda0(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = param_2 + -1;
  iVar1 = param_3 - 0x10000;
  piVar2 = param_1;
  if (0 < iVar3) {
    do {
      *piVar2 = ((*piVar2 >> 0xf) + 1 >> 1) * param_3 +
                ((int)((param_3 & 0xffff) * (int)(short)*piVar2) >> 0x10) +
                ((int)param_3 >> 0x10) * (int)(short)*piVar2;
      param_3 = param_3 + (((int)(iVar1 * param_3) >> 0xf) + 1 >> 1);
      iVar3 = iVar3 + -1;
      piVar2 = piVar2 + 1;
    } while (iVar3 != 0);
  }
  param_1[param_2 + -1] =
       ((param_1[param_2 + -1] >> 0xf) + 1 >> 1) * param_3 +
       ((int)((param_3 & 0xffff) * (int)(short)param_1[param_2 + -1]) >> 0x10) +
       ((int)param_3 >> 0x10) * (int)(short)param_1[param_2 + -1];
  return;
}

