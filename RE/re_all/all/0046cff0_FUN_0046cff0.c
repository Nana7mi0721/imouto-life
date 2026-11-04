
undefined4 * __thiscall FUN_0046cff0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae714;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0046d530();
  local_8 = 0;
  FUN_004ceea0();
  local_8._0_1_ = 1;
  *param_1 = param_2;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 1),"");
  param_1[8] = 0;
  param_1[9] = 0;
  uVar1 = FUN_0046d0e0();
  local_8._0_1_ = 2;
  FUN_004cf1b0(uVar1);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0046f320();
  param_1[10] = 1;
  ExceptionList = local_10;
  return param_1;
}

