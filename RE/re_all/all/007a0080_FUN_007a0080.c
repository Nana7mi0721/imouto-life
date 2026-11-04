
void FUN_007a0080(undefined2 *param_1,short *param_2,int param_3)

{
  short *psVar1;
  int iVar2;
  short *psVar3;
  undefined2 *puVar4;
  int iVar5;
  uint local_4;
  
  iVar2 = (int)*param_2;
  iVar5 = iVar2;
  if (iVar2 < 2) {
    iVar5 = 1;
  }
  iVar2 = param_2[1] - iVar2;
  if (iVar2 < 2) {
    iVar2 = 1;
  }
  iVar2 = (int)(0x20000 / (longlong)iVar2);
  iVar5 = iVar2 + (int)(0x20000 / (longlong)iVar5);
  if (0x7ffe < iVar5) {
    iVar5 = 0x7fff;
  }
  *param_1 = (short)iVar5;
  if (1 < (int)(param_3 - 1U)) {
    puVar4 = param_1 + 1;
    local_4 = param_3 - 1U >> 1;
    psVar1 = param_2;
    do {
      psVar3 = psVar1 + 2;
      iVar5 = (int)*psVar3 - (int)psVar1[1];
      if (iVar5 < 2) {
        iVar5 = 1;
      }
      iVar5 = (int)(0x20000 / (longlong)iVar5);
      iVar2 = iVar2 + iVar5;
      if (0x7ffe < iVar2) {
        iVar2 = 0x7fff;
      }
      *puVar4 = (short)iVar2;
      iVar2 = (int)psVar1[3] - (int)*psVar3;
      if (iVar2 < 2) {
        iVar2 = 1;
      }
      iVar2 = (int)(0x20000 / (longlong)iVar2);
      iVar5 = iVar2 + iVar5;
      if (0x7ffe < iVar5) {
        iVar5 = 0x7fff;
      }
      *(short *)((int)psVar3 + ((int)param_1 - (int)param_2)) = (short)iVar5;
      puVar4 = puVar4 + 2;
      local_4 = local_4 - 1;
      psVar1 = psVar3;
    } while (local_4 != 0);
  }
  iVar5 = 0x8000 - param_2[param_3 + -1];
  if (iVar5 < 2) {
    iVar5 = 1;
  }
  iVar2 = (int)(0x20000 / (longlong)iVar5) + iVar2;
  if (0x7ffe < iVar2) {
    iVar2 = 0x7fff;
  }
  param_1[param_3 + -1] = (short)iVar2;
  return;
}

