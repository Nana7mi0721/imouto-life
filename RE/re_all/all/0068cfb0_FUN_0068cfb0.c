
void FUN_0068cfb0(int param_1,int *param_2,int param_3,int *param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar3 = *(int *)(param_1 + 0x5c);
  iVar4 = *(int *)(*(int *)(param_1 + 0x1bc) + 0x18);
  if (-1 < param_5 + -1) {
    iVar6 = param_3 << 2;
    param_3 = param_5;
    do {
      iVar7 = *param_4;
      piVar1 = (int *)(*param_2 + iVar6);
      piVar2 = (int *)(param_2[2] + iVar6);
      pbVar5 = *(byte **)(iVar6 + param_2[1]);
      param_4 = param_4 + 1;
      iVar6 = iVar6 + 4;
      if (iVar3 != 0) {
        iVar8 = *piVar2 - (int)pbVar5;
        iVar9 = *piVar1 - (int)pbVar5;
        iVar7 = iVar7 - (int)pbVar5;
        param_5 = iVar3;
        do {
          pbVar5[iVar7] =
               (byte)((uint)(*(int *)(iVar4 + 0x800 + (uint)pbVar5[iVar8] * 4) +
                             *(int *)(iVar4 + (uint)pbVar5[iVar9] * 4) +
                            *(int *)(iVar4 + 0x400 + (uint)*pbVar5 * 4)) >> 0x10);
          pbVar5 = pbVar5 + 1;
          param_5 = param_5 + -1;
        } while (param_5 != 0);
      }
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

