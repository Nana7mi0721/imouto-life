
int FUN_0050eb50(int param_1)

{
  BOOL BVar1;
  HANDLE hMem;
  SIZE_T SVar2;
  LPVOID pvVar3;
  
  BVar1 = OpenClipboard(DAT_00a20bec);
  if (BVar1 != 0) {
    BVar1 = IsClipboardFormatAvailable(0xd);
    if (BVar1 != 0) {
      hMem = GetClipboardData(0xd);
      if (param_1 == 0) {
        SVar2 = GlobalSize(hMem);
        CloseClipboard();
        return SVar2 + 1;
      }
      pvVar3 = GlobalLock(hMem);
      FUN_0056cf10(param_1,pvVar3);
      GlobalUnlock(hMem);
      CloseClipboard();
      return 0;
    }
    CloseClipboard();
  }
  return -1;
}

