
void FUN_00581210(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  param_2 = param_2 + 1;
  iVar4 = 0;
  iVar2 = 0;
  param_1 = ((int)(0x10000 / (longlong)param_2) + 0x100) * param_1;
  iVar3 = 0x100 - ((int)(param_1 + (param_1 >> 0x1f & 0xffU)) >> 8);
  if (0 < iVar3) {
    do {
      iVar1 = iVar2 / param_2 + iVar3;
      if (0xff < iVar1) {
        iVar1 = 0xff;
      }
      (&DAT_00dca2e0)[iVar4] = (char)iVar1;
      iVar2 = iVar2 + 0x100;
      iVar4 = iVar4 + 1;
    } while (iVar2 < 0x10000);
    return;
  }
  do {
    iVar1 = iVar2 / param_2 + iVar3;
    if (iVar1 < 0x100) {
      if (iVar1 < 0) {
        iVar1 = 0;
      }
    }
    else {
      iVar1 = 0xff;
    }
    (&DAT_00dca2e0)[iVar4] = (char)iVar1;
    iVar2 = iVar2 + 0x100;
    iVar4 = iVar4 + 1;
  } while (iVar2 < 0x10000);
  return;
}

