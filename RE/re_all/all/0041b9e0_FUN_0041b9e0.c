
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0041ba12) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_0041b9e0(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  char *_Format;
  int in_stack_00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  int in_stack_0000002c;
  int in_stack_00000030;
  uint in_stack_00000034;
  char *in_stack_00000038;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_56c [28];
  int local_550;
  int local_54c;
  int local_548;
  int local_544;
  int local_540;
  int local_53c;
  undefined4 local_538;
  char local_531;
  char local_530 [1304];
  undefined4 local_18;
  char local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007abe5f;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  local_8 = 0;
  local_531 = '\0';
  for (local_53c = 0; local_53c < in_stack_0000002c; local_53c = local_53c + 1) {
    if (*(char *)(in_stack_00000030 + local_53c) != '\0') {
      local_531 = '\x01';
    }
  }
  if ((in_stack_0000002c < 1) || (local_531 != '\0')) {
    local_14 = '\0';
    local_13 = 0;
    local_12 = 0;
    local_11 = 0;
    ExceptionList = &local_10;
    if (0x7fffffff < in_stack_00000034) {
      local_538 = 0;
      for (local_540 = in_stack_00000024; local_540 < in_stack_00000028; local_540 = local_540 + 1)
      {
        local_14 = local_14 + *(char *)(in_stack_00000020 + local_540);
      }
      ExceptionList = &local_10;
      *in_stack_00000038 = local_14;
    }
    if (0 < in_stack_0000002c) {
      FUN_004fcb44();
      for (local_544 = in_stack_00000024; local_544 < in_stack_00000028; local_544 = local_544 + 1)
      {
        bVar1 = *(byte *)(in_stack_00000020 + local_544);
        uVar2 = _rand();
        *(byte *)(in_stack_00000020 + local_544) = bVar1 ^ (byte)((int)(uVar2 & 0xff000) >> 0xc);
      }
    }
    if (1 < in_stack_0000002c) {
      FUN_004fcb44();
      for (local_548 = in_stack_00000024; local_548 < in_stack_00000028; local_548 = local_548 + 2)
      {
        bVar1 = *(byte *)(in_stack_00000020 + local_548);
        uVar2 = _rand();
        *(byte *)(in_stack_00000020 + local_548) = bVar1 ^ (byte)((int)(uVar2 & 0xff000) >> 0xc);
      }
    }
    if (2 < in_stack_0000002c) {
      FUN_004fcb44();
      for (local_54c = in_stack_00000024; local_54c < in_stack_00000028; local_54c = local_54c + 5)
      {
        bVar1 = *(byte *)(in_stack_00000020 + local_54c);
        uVar2 = _rand();
        *(byte *)(in_stack_00000020 + local_54c) = bVar1 ^ (byte)((int)(uVar2 & 0xff000) >> 0xc);
      }
    }
    if (0 < (int)in_stack_00000034) {
      local_538 = 0;
      for (local_550 = in_stack_00000024; local_550 < in_stack_00000028; local_550 = local_550 + 1)
      {
        local_14 = local_14 + *(char *)(in_stack_00000020 + local_550);
      }
      if (local_14 != *in_stack_00000038) {
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  (local_56c,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &param_1);
        local_8 = CONCAT31(local_8._1_3_,1);
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (local_56c,".broken");
        while( true ) {
          FUN_004cbb30();
          FUN_004cbb30();
          iVar3 = FUN_004fd645();
          if (iVar3 == 0) break;
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                    (local_56c,"x");
        }
        FUN_004cbb30();
        basic_string<>();
        _Format = (char *)FUN_00401c50();
        _sprintf(local_530,_Format);
        basic_string<>();
        local_8._0_1_ = 2;
        basic_string<>();
        local_8._0_1_ = 3;
        basic_string<>(local_530);
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_0042bed0();
                    /* WARNING: Subroutine does not return */
        _exit(1);
      }
    }
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
  }
  else {
    local_8 = 0xffffffff;
    ExceptionList = &local_10;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
  }
  ExceptionList = local_10;
  return;
}

