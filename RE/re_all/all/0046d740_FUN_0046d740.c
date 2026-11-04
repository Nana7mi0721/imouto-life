
undefined4 __fastcall FUN_0046d740(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  void *_Dst;
  void *_Src;
  undefined1 uStack00000000;
  size_t _Size;
  undefined4 local_84;
  undefined4 local_80;
  CBitmapButton local_7c [84];
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  undefined1 local_15;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae828;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (&uStack00000000 == (undefined1 *)0x15) {
    local_24 = 0xffffffff;
    ExceptionList = &local_10;
    __CxxThrowException_8(0xfffffff1,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy(&local_15,(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  FUN_0046dab0();
  FUN_0046ddf0();
  FUN_0046df90(0);
  if (param_1 == -100) {
    local_28 = 0xffffffff;
    __CxxThrowException_8(&local_28,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)(param_1 + 100),(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  FUN_004cee50();
  for (local_1c = 0; local_1c < *(int *)(param_1 + 100); local_1c = local_1c + 1) {
    uVar1 = FUN_0046d3c0();
    local_8 = 0;
    FUN_004ced60(uVar1);
    local_8 = 0xffffffff;
    CBitmapButton::~CBitmapButton(local_7c);
    FUN_004cecd0(local_1c);
    FUN_0046eac0();
  }
  uVar1 = 0;
  FUN_004cecd0(*(int *)(param_1 + 100) + -1);
  puVar2 = (undefined4 *)FUN_004ce990(uVar1);
  *puVar2 = 0xffffffff;
  if (&uStack00000000 == (undefined1 *)0x14) {
    local_80 = 0xffffffff;
    __CxxThrowException_8(0xffffff94,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy(&local_14,(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  iVar3 = FUN_004cd730();
  if (iVar3 < local_14) {
    FUN_004cf7d0(local_14);
  }
  for (local_20 = 0; local_20 < local_14; local_20 = local_20 + 1) {
    iVar3 = FUN_004cd7c0(local_20);
    if (iVar3 == 0) {
      local_84 = 0xffffffff;
      __CxxThrowException_8(&local_84,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _Size = 1;
      _Src = (void *)(DAT_00a0f830 + DAT_00a11790);
      _Dst = (void *)FUN_004cd7c0(local_20);
      _memcpy(_Dst,_Src,_Size);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
  }
  if (&uStack00000000 == (undefined1 *)0x15) {
    __CxxThrowException_8(0xffffff8d,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy(&local_15,(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  ExceptionList = local_10;
  return 1;
}

