
undefined4 FUN_0050ee50(int param_1)

{
  HANDLE h;
  int iVar1;
  uint uVar2;
  undefined1 local_18 [4];
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  ushort local_6;
  undefined4 local_4;
  
  if (param_1 == 0) {
    if (DAT_00a20c00 != (HRGN)0x0) {
      DeleteObject(DAT_00a20c00);
      DAT_00a20c00 = (HRGN)0x0;
      return 0;
    }
  }
  else {
    h = (HANDLE)FUN_0054f330(param_1,0,0);
    if (h == (HANDLE)0x0) {
      return 0xffffffff;
    }
    GetObjectA(h,0x18,local_18);
    uVar2 = local_c & 0x80000003;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xfffffffc) + 1;
    }
    if (uVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = 4 - uVar2;
    }
    local_c = local_c + iVar1;
    if (DAT_00a20c00 != (HRGN)0x0) {
      DeleteObject(DAT_00a20c00);
    }
    DAT_00a20c00 = (HRGN)FUN_0050ecb0(local_14,local_10,local_4,local_c,local_6 >> 3);
    if (DAT_00a20bec != (HWND)0x0) {
      SetWindowRgn(DAT_00a20bec,DAT_00a20c00,1);
    }
  }
  return 0;
}

