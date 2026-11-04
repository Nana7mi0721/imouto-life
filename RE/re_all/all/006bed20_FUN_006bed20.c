
int FUN_006bed20(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar3 = 0;
  do {
    iVar1 = param_1 + iVar3 * 2;
    iVar2 = (uint)*(byte *)(iVar1 + 1) - param_2;
    if (iVar2 < 0x20) {
      uVar4 = uVar4 + (0x80000000U >> ((byte)iVar2 & 0x1f));
      iVar3 = iVar3 + 1;
    }
    else {
      uVar4 = uVar4 + 1;
      iVar1 = FUN_006bed20(iVar1,param_2 + 0x1f);
      iVar3 = iVar3 + iVar1;
    }
  } while (uVar4 < 0x80000000);
  return iVar3;
}

