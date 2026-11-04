
bool FUN_005d6830(void)

{
  int iVar1;
  
  if (DAT_00a20bec != 0) {
    if (DAT_00a37d78 == 0) {
      iVar1 = thunk_FUN_005d1a00();
      if ((iVar1 != 0) && (DAT_00a20bec != 0)) {
        return true;
      }
    }
    else {
      if (DAT_00aaf0dc == 1) {
        iVar1 = thunk_FUN_005d1a00();
        return iVar1 != 0;
      }
      if (DAT_00aaf0dc == 2) {
        iVar1 = FUN_005d27a0();
        return iVar1 != 0;
      }
    }
  }
  return false;
}

