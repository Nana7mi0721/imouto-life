
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a4d90(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
                 int param_7)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (param_2 < param_3) {
    piVar4 = (int *)(param_5 + param_2 * 4);
    do {
      if (0 < *piVar4) {
        iVar3 = 0;
        do {
          iVar2 = FUN_007a2250(param_6,*piVar4);
          pfVar1 = (float *)(param_4 + (iVar3 * *(int *)(param_1 + 8) + param_2) * 4);
          iVar3 = iVar3 + 1;
          *pfVar1 = (((float)iVar2 + _DAT_007d589c) * (float)(1 << (0xeU - (char)*piVar4 & 0x1f)) *
                     _DAT_0083c7b4 - _DAT_007d589c) + *pfVar1;
        } while (iVar3 < param_7);
      }
      param_2 = param_2 + 1;
      piVar4 = piVar4 + 1;
    } while (param_2 < param_3);
  }
  return;
}

