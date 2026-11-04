
char FUN_0067e970(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  while ((param_1[0x1d] != 0 || (FUN_0067d900(param_1), param_1[0x1d] != 0))) {
    param_1[0x18] = 0;
    bVar1 = *(byte *)(param_1[0x1b] + param_1[0xe]);
    *(undefined2 *)(param_1[0x5a9] + param_1[0x5a8] * 2) = 0;
    *(byte *)(param_1[0x5a6] + param_1[0x5a8]) = bVar1;
    param_1[0x5a8] = param_1[0x5a8] + 1;
    *(short *)(param_1 + bVar1 + 0x25) = (short)param_1[bVar1 + 0x25] + 1;
    iVar2 = param_1[0x1b];
    param_1[0x1d] = param_1[0x1d] + -1;
    param_1[0x1b] = iVar2 + 1;
    if (param_1[0x5a8] == param_1[0x5a7] + -1) {
      iVar3 = param_1[0x17];
      if (iVar3 < 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = iVar3 + param_1[0xe];
      }
      FUN_0067f720(param_1,iVar4,(iVar2 + 1) - iVar3,0);
      param_1[0x17] = param_1[0x1b];
      FUN_0067d730(*param_1);
      if (*(int *)(*param_1 + 0x10) == 0) {
        return '\0';
      }
    }
  }
  if (param_2 == 0) {
    return '\0';
  }
  param_1[0x5ad] = 0;
  if (param_2 == 4) {
    iVar2 = param_1[0x17];
    if (iVar2 < 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = param_1[0xe] + iVar2;
    }
    FUN_0067f720(param_1,iVar3,param_1[0x1b] - iVar2,1);
    param_1[0x17] = param_1[0x1b];
    FUN_0067d730(*param_1);
    return (*(int *)(*param_1 + 0x10) != 0) + '\x02';
  }
  if (param_1[0x5a8] != 0) {
    iVar2 = param_1[0x17];
    if (iVar2 < 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = param_1[0xe] + iVar2;
    }
    FUN_0067f720(param_1,iVar3,param_1[0x1b] - iVar2,0);
    param_1[0x17] = param_1[0x1b];
    FUN_0067d730(*param_1);
    if (*(int *)(*param_1 + 0x10) == 0) {
      return '\0';
    }
  }
  return '\x01';
}

