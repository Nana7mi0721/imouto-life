
undefined4 FUN_0050ea40(int param_1)

{
  DAT_00a20c40 = param_1;
  if (param_1 == 0) {
    FUN_0056bb10(&DAT_007d49f8);
    if (DAT_00a24d60 == 1) {
      SetMenu(DAT_00a20bec,(HMENU)0x0);
    }
  }
  else {
    FUN_0056bb10(&DAT_007d4a20);
    if (DAT_00a24d60 == 1) {
      SetMenu(DAT_00a20bec,DAT_00a24d58);
      return 0;
    }
  }
  return 0;
}

