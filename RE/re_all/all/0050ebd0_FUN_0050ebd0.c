
undefined4 FUN_0050ebd0(short *param_1)

{
  short sVar1;
  int iVar2;
  HGLOBAL hMem;
  LPVOID pvVar3;
  BOOL BVar4;
  
  iVar2 = 0;
  sVar1 = *param_1;
  while (sVar1 != 0) {
    iVar2 = iVar2 + 1;
    sVar1 = param_1[iVar2];
  }
  hMem = GlobalAlloc(0,iVar2 * 2 + 2);
  pvVar3 = GlobalLock(hMem);
  FUN_0056cf10(pvVar3,param_1);
  GlobalUnlock(hMem);
  BVar4 = OpenClipboard(DAT_00a20bec);
  if (BVar4 == 0) {
    GlobalFree(hMem);
    return 0;
  }
  EmptyClipboard();
  SetClipboardData(0xd,hMem);
  CloseClipboard();
  return 0;
}

