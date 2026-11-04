
int FUN_0050f020(void)

{
  BOOL BVar1;
  HMENU unaff_EBX;
  LPMENUITEMINFOW unaff_ESI;
  UINT unaff_EDI;
  
  FUN_0056d380();
  unaff_ESI->cbSize = 0x30;
  unaff_ESI->fMask = 0x10;
  BVar1 = GetMenuItemInfoW(unaff_EBX,unaff_EDI,1,unaff_ESI);
  if (BVar1 == 0) {
    return -1;
  }
  if ((unaff_ESI->fType & 0x800) == 0) {
    FUN_0056d380();
    unaff_ESI->cbSize = 0x30;
    unaff_ESI->fMask = 0x17;
    unaff_ESI->fType = 0;
    unaff_ESI->dwTypeData = (LPWSTR)&DAT_00a37c70;
    unaff_ESI->cch = 0x80;
    BVar1 = GetMenuItemInfoW(unaff_EBX,unaff_EDI,1,unaff_ESI);
    return (BVar1 != 0) - 1;
  }
  return 1;
}

