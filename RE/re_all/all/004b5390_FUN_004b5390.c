
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_004b5390(int param_1,int param_2,undefined4 param_3,
                 basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_4)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_28a8 [8];
  undefined4 uStack_28a0;
  CMiniDockFrameWnd local_1c08 [6868];
  undefined1 *local_134;
  char local_130 [256];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007b0572;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  local_8 = 0;
  if ((param_2 < 1100000) || (1199999 < param_2)) {
    if ((param_2 < 1600000) || (1699999 < param_2)) {
      local_134 = abStack_28a8;
      ExceptionList = &local_10;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                (abStack_28a8,
                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &param_4);
      FUN_004ab7b0(param_1,0,0);
      if (param_1 < 1) {
        if (param_1 == 0) {
          FUN_004cbb30();
          _sprintf(local_130,"%s");
        }
      }
      else {
        FUN_004cbb30();
        uStack_28a0 = 0x4b5465;
        _sprintf(local_130,"%s%.2i.sav");
      }
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                (local_30,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)&DAT_00a14b78);
      local_8._0_1_ = 1;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                (local_30,local_130);
      pcVar1 = (char *)FUN_004d39f0();
      if (*pcVar1 == '\0') {
        FUN_00447840();
        local_8._0_1_ = 2;
        FUN_004d3570();
        FUN_00473f10();
        local_8._0_1_ = 1;
        FUN_004a6940();
        FUN_00436790();
        local_8._0_1_ = 3;
        FUN_004d3570();
        FUN_004ab5b0();
        local_8._0_1_ = 1;
        FUN_004a68c0();
        FUN_004441f0();
        local_8._0_1_ = 4;
        FUN_004d3570();
        FUN_004736a0();
        local_8._0_1_ = 1;
        CMiniDockFrameWnd::~CMiniDockFrameWnd(local_1c08);
        FUN_00471bd0();
        local_8._0_1_ = 5;
        FUN_004d3570();
        FUN_00472eb0();
        local_8._0_1_ = 1;
        FUN_004a6aa0();
        FUN_00472ab0();
        local_8._0_1_ = 6;
        FUN_004d3570();
        FUN_00474330();
        local_8._0_1_ = 1;
        FUN_004a6be0();
        FUN_004718a0();
        local_8._0_1_ = 7;
        FUN_004d3570();
        FUN_00472740();
        local_8._0_1_ = 1;
        FUN_00484b30();
        iVar2 = FUN_004d3570();
        iVar3 = FUN_004d3570();
        *(int *)(iVar3 + 0x2458) = iVar2 + 0x1918;
      }
      FUN_004d3570();
      uStack_28a0 = 0x4b5729;
      FUN_004d3570();
      FUN_00438f70();
      if (param_1 == 0) {
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  (abStack_28a8,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &param_4);
        FUN_004a5ca0(0,0);
      }
      else {
        basic_string<>("Save/SaveData");
        FUN_004a5ca0(param_1,0);
      }
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_30);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_4);
    }
    else {
      local_8 = 0xffffffff;
      ExceptionList = &local_10;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_4);
    }
  }
  else {
    local_8 = 0xffffffff;
    ExceptionList = &local_10;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_4);
  }
  ExceptionList = local_10;
  return;
}

