
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
FUN_00422450(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_1)

{
  char cVar1;
  char *_Format;
  undefined4 uVar2;
  int in_stack_00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  undefined4 uStack_2b0;
  void *pvStack_2ac;
  size_t sStack_2a8;
  int iStack_2a4;
  undefined1 local_22d;
  undefined1 local_1d9;
  undefined1 local_1c1;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1a8 [30];
  undefined1 local_18a;
  undefined1 local_189;
  int local_180;
  int local_17c;
  char local_178 [260];
  void *local_74;
  int local_70;
  int local_6c;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_68 [28];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_4c [28];
  undefined4 local_30;
  size_t local_2c;
  int local_28;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007ac333;
  local_10 = ExceptionList;
  local_30 = DAT_0084b484;
  local_8 = 0;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_68,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)&param_1);
  local_8._0_1_ = 1;
  FUN_004ce060();
  iStack_2a4 = 0x4224b4;
  FUN_004ccca0();
  cVar1 = const_iterator__operator__();
  if (cVar1 == '\0') {
    cVar1 = FUN_004ec750();
    if (cVar1 == '\0') {
      iStack_2a4 = 0x422549;
      FUN_004ec790();
      local_8._0_1_ = 2;
      FUN_004cb840();
      local_8._0_1_ = 1;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1a8);
      FUN_004cbb30();
      local_14 = FUN_0052e3c0();
      if (local_14 == 0) {
        FUN_004cbb30();
        basic_string<>();
        _Format = (char *)FUN_00401c50();
        iStack_2a4 = 0x4225e5;
        _sprintf(local_178,_Format);
        cVar1 = operator!=<>();
        if (cVar1 != '\0') {
          basic_string<>();
          FUN_00401c50();
          basic_string<>();
          local_8._0_1_ = 3;
          basic_string<>();
          local_8._0_1_ = 4;
          basic_string<>(&DAT_007cca50);
          uVar2 = FUN_00401c50();
          basic_string<>(uVar2);
          local_8._0_1_ = 1;
          FUN_0042bed0();
        }
        local_1c1 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_68);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
        local_189 = local_1c1;
      }
      else {
        FUN_004cbb30();
        local_2c = FUN_0052c9a0();
        local_74 = _malloc(local_2c);
        iStack_2a4 = 0x42273a;
        FUN_0052cde0();
        thunk_FUN_00580b80();
        FUN_004cb840();
        iStack_2a4 = 0;
        sStack_2a8 = local_2c;
        pvStack_2ac = local_74;
        uStack_2b0 = 0x42276a;
        local_70 = FUN_0052a200();
        if (local_70 == -1) {
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_2b0,
                     (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )local_68);
          local_8._0_1_ = 5;
          basic_string<>();
          FUN_00401c50();
          basic_string<>();
          local_8._0_1_ = 6;
          basic_string<>(&DAT_007ccadc);
          uVar2 = FUN_00401c50();
          basic_string<>(uVar2);
          local_8._0_1_ = 1;
          FUN_0042bed0();
          local_1d9 = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_68);
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
          local_189 = local_1d9;
        }
        else {
          iStack_2a4 = 0x42288a;
          FUN_00515880();
          if (in_stack_00000028 == 1) {
            in_stack_00000020 = local_28 / in_stack_00000020;
            in_stack_00000024 = local_6c / in_stack_00000024;
          }
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                    (local_4c,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                               *)&param_1);
          local_8._0_1_ = 7;
          FUN_004ce850();
          local_8._0_1_ = 8;
          FUN_004cd340();
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                     ((int)register0x00000010 + -0x2b4),
                     (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )local_4c);
          FUN_004ec810();
          local_8._0_1_ = 9;
          FUN_004eb820();
          local_8._0_1_ = 10;
          FUN_004cc8a0();
          local_8._0_1_ = 9;
          FUN_004d4160();
          local_8 = CONCAT31(local_8._1_3_,8);
          FUN_004d4160();
          FUN_004ce160();
          FUN_004ce160();
          FUN_004cd3f0();
          FUN_004cd340();
          FUN_004cde80();
          FUN_004ce160();
          for (local_17c = 0; local_17c < in_stack_00000024; local_17c = local_17c + 1) {
            for (local_180 = 0; local_180 < in_stack_00000020; local_180 = local_180 + 1) {
              iStack_2a4 = (local_6c / in_stack_00000024) * local_17c;
              sStack_2a8 = (local_28 / in_stack_00000020) * local_180;
              pvStack_2ac = (void *)0x422a2d;
              FUN_0052a120();
              FUN_004cd340();
              FUN_004cd3a0();
              FUN_004ce160();
            }
          }
          _free(local_74);
          local_22d = 1;
          local_8._0_1_ = 7;
          FUN_004ce950();
          local_8._0_1_ = 1;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_4c);
          local_8 = (uint)local_8._1_3_ << 8;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_68);
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
          local_189 = local_22d;
        }
      }
    }
    else {
      local_18a = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_68);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
      local_189 = local_18a;
    }
  }
  else {
    local_189 = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_68
              );
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
  }
  ExceptionList = local_10;
  return local_189;
}

