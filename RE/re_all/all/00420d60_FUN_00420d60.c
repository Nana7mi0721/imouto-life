
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_00420d60(int param_1)

{
  char *_Format;
  undefined4 uVar1;
  char local_118 [260];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ac29c;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  if (param_1 < 8) {
    if ((param_1 < -0x12) || (-0xb < param_1)) {
      if ((param_1 < 0) || (7 < param_1)) {
        ExceptionList = &local_10;
        basic_string<>();
        _Format = (char *)FUN_00401c50();
        _sprintf(local_118,_Format);
        FUN_00438b60();
        local_8 = 0;
        basic_string<>();
        local_8 = CONCAT31(local_8._1_3_,1);
        basic_string<>(&DAT_007cc6c8);
        uVar1 = FUN_00401c50();
        basic_string<>(uVar1);
        local_8 = 0xffffffff;
        FUN_0042bed0();
        param_1 = 0;
      }
    }
    else {
      param_1 = -3 - param_1;
    }
  }
  else {
    param_1 = param_1 + 8;
  }
  ExceptionList = local_10;
  return param_1;
}

