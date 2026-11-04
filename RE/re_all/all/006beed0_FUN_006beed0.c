
int FUN_006beed0(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  
  iVar2 = param_1;
  sVar1 = *(short *)(param_1 + param_2 * 2);
  param_1 = FUN_006bee20((int)sVar1);
  bVar4 = (byte)sVar1;
  iVar5 = 0;
  do {
    iVar3 = (int)*(short *)(iVar2 + (param_2 + 1 + iVar5) * 2);
    if (iVar3 < 1) {
      iVar5 = iVar5 + (1 << (bVar4 - (char)((uint)-iVar3 >> 8) & 0x1f));
    }
    else {
      iVar3 = FUN_006beed0(iVar2,iVar3);
      param_1 = param_1 + iVar3;
      iVar5 = iVar5 + 1;
    }
  } while (iVar5 < 1 << (bVar4 & 0x1f));
  return param_1;
}

