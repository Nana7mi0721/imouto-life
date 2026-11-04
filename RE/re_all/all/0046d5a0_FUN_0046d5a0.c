
undefined4 __fastcall FUN_0046d5a0(int param_1)

{
  undefined4 uVar1;
  undefined1 uStack00000000;
  int local_18;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae80b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (&uStack00000000 == (undefined1 *)0x11) {
    ExceptionList = &local_10;
    __CxxThrowException_8(0xfffffff5,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy(&local_11,(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  FUN_0046ee50();
  for (local_18 = 0; local_18 < *(int *)(param_1 + 0x28); local_18 = local_18 + 1) {
    if (local_18 != 0) {
      uVar1 = FUN_0046d0e0();
      local_8 = 0;
      FUN_004cf1b0(uVar1);
      local_8 = 0xffffffff;
      FUN_0046f320();
    }
    FUN_004cf170(local_18);
    FUN_0046d740();
  }
  if (&uStack00000000 == (undefined1 *)0x11) {
    __CxxThrowException_8(0xffffff69,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy(&local_11,(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  ExceptionList = local_10;
  return 1;
}

