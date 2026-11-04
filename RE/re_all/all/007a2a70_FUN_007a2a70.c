
void FUN_007a2a70(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = *(int *)(param_1 + 8);
  if (0 < iVar2) {
    do {
      *param_2 = (int)(((int)*(short *)(*(int *)(param_1 + 0x20) + 2 + iVar1 * 2) -
                        (int)*(short *)(*(int *)(param_1 + 0x20) + iVar1 * 2) <<
                       ((byte)param_3 & 0x1f)) *
                       (*(byte *)((param_4 + -1 + param_3 * 2) * iVar2 + iVar1 +
                                 *(int *)(param_1 + 0x68)) + 0x40) * param_4) >> 2;
      iVar2 = *(int *)(param_1 + 8);
      iVar1 = iVar1 + 1;
      param_2 = param_2 + 1;
    } while (iVar1 < iVar2);
  }
  return;
}

