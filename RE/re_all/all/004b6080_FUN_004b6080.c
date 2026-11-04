
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_004b6080(void)

{
  char *_Format;
  undefined4 uVar1;
  int iVar2;
  char local_150 [304];
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0646;
  local_10 = ExceptionList;
  local_20 = DAT_0084b484;
  ExceptionList = &local_10;
  local_14 = FUN_0052e3c0();
  if (local_14 == 0) {
    basic_string<>();
    _Format = (char *)FUN_00401c50();
    _sprintf(local_150,_Format);
    FUN_00438b60();
    local_8 = 0;
    basic_string<>();
    local_8 = CONCAT31(local_8._1_3_,1);
    basic_string<>(&DAT_007d0d98);
    uVar1 = FUN_00401c50();
    basic_string<>(uVar1);
    local_8 = 0xffffffff;
    FUN_0042bed0();
    local_1c = 0;
  }
  else {
    DAT_00a11790 = 0;
    if (DAT_00a117ec == 0) {
      iVar2 = FUN_0052c9a0();
      DAT_00a0f830 = _malloc(iVar2 + 1);
      iVar2 = FUN_0052c9a0();
      _memset(DAT_00a0f830,0,iVar2 + 1);
    }
    local_18 = FUN_0052c9a0();
    FUN_0052cde0();
    thunk_FUN_00580b80();
    *(undefined1 *)((int)DAT_00a0f830 + local_18) = 0;
    local_1c = FUN_004b66a0();
    if (DAT_00a117ec == 0) {
      _free(DAT_00a0f830);
    }
  }
  ExceptionList = local_10;
  return local_1c;
}

