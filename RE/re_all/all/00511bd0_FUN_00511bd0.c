
undefined4 FUN_00511bd0(void)

{
  undefined4 uVar1;
  int local_8 [2];
  
  local_8[1] = 0;
  local_8[0] = 0;
  if (DAT_00a20c40 != 1) {
    FUN_0054f460(local_8 + 1,local_8);
    if (DAT_00a37d78 == 0) {
      DAT_00a24d7c = (uint)(local_8[0] < 0x3c);
      uVar1 = FUN_005677a0();
      FUN_00567750(uVar1);
      FUN_0050f160(DAT_00a210ac);
      FUN_00511b30(DAT_00a24d70 == 0);
    }
    else {
      if ((DAT_00a24d58 != (HMENU)0x0) && (DAT_00a24d5c == 0)) {
        SetMenu(DAT_00a20bec,DAT_00a24d58);
        DAT_00a24d5c = 1;
      }
      if (0x3c < local_8[0]) {
        FUN_0050f160(DAT_00a210ac);
        return 0;
      }
    }
  }
  return 0;
}

