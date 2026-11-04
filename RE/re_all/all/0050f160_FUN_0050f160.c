
undefined4 FUN_0050f160(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != -1) {
    DAT_00a210ac = param_1;
  }
  if ((DAT_00a210ac == 1) ||
     ((((DAT_00a20bec != (HWND)0x0 && (DAT_00a24d60 != 0)) && (DAT_00a24d70 != 1)) &&
      (((DAT_00a24d78 == 1 || (DAT_00a20c40 != 0)) || (DAT_00a24d7c != 0)))))) {
    iVar3 = 1;
  }
  else {
    iVar3 = 0;
  }
  if ((param_1 == -1) || (iVar3 != DAT_00a210b0)) {
    if (iVar3 == 0) {
      do {
        uVar1 = ShowCursor(0);
      } while (uVar1 < 0x80000000);
    }
    else {
      do {
        iVar2 = ShowCursor(1);
      } while (iVar2 < 0);
    }
    PostMessageW(DAT_00a20bec,0x20,(WPARAM)DAT_00a20bec,0);
    DAT_00a210b0 = iVar3;
  }
  return 0;
}

