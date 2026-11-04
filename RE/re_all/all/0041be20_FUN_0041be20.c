
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_0041be20(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 in_stack_00000024;
  undefined4 in_stack_00000028;
  undefined4 in_stack_0000002c;
  int in_stack_00000030;
  int _Radix;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_33c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_320 [31];
  char local_301;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_300 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2e4 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2c8 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2ac [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_290 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_274 [28];
  undefined4 local_258;
  int local_254;
  int local_250;
  long local_24c;
  long local_248;
  int local_244;
  int local_240;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_23c [28];
  char local_220 [516];
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007abef3;
  local_10 = ExceptionList;
  local_1c = DAT_0084b484;
  local_8 = 1;
  local_18 = 0;
  local_244 = 0;
  local_14 = 0;
  local_240 = 0;
  ExceptionList = &local_10;
  basic_string<>();
  local_8._0_1_ = 2;
  cVar1 = FUN_004cbb70();
  if (cVar1 == '\0') {
    while( true ) {
      local_258 = 0;
      iVar2 = FUN_004e5650();
      if (iVar2 <= local_240) break;
      iVar2 = FUN_004cbbc0(&DAT_007cbbdc,0);
      if (iVar2 == DAT_007d0624) {
        iVar2 = FUN_004cbbc0("\\udb[",local_240);
        if (iVar2 == DAT_007d0624) {
          iVar2 = FUN_004cbbc0("\\cdb[",local_240);
          if (iVar2 == DAT_007d0624) {
            iVar2 = FUN_004cbbc0("\\sdb[",local_240);
            if (iVar2 == DAT_007d0624) break;
            local_18 = FUN_004cbbc0("\\sdb[",local_240);
            local_258 = in_stack_00000028;
          }
          else {
            local_18 = FUN_004cbbc0("\\cdb[",local_240);
            local_258 = in_stack_0000002c;
          }
        }
        else {
          local_18 = FUN_004cbbc0("\\udb[",local_240);
          local_258 = in_stack_00000024;
        }
        local_250 = local_18;
        local_240 = local_18 + 1;
        local_244 = FUN_004cbbc0(&DAT_007cbc18,local_18);
        if (local_244 != DAT_007d0624) {
          FUN_004cbc20(local_290,local_18 + 5,local_244);
          local_8._0_1_ = 4;
          pcVar3 = (char *)FUN_004cbb30();
          local_254 = _atol(pcVar3);
          local_8._0_1_ = 2;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_290);
          local_18 = FUN_004cbbc0(&DAT_007cbc1c,local_244 + 1);
          if (local_18 == DAT_007d0624) {
            local_18 = FUN_004cbbc0(&DAT_007cbc20,local_244 + 1);
            if (local_18 != DAT_007d0624) {
              FUN_004cbc20(local_2ac,local_244 + 1,local_18);
              local_8._0_1_ = 5;
              pcVar3 = (char *)FUN_004cbb30();
              local_24c = _atol(pcVar3);
              local_8._0_1_ = 2;
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2ac);
              uVar4 = FUN_004706f0(local_2c8,local_254,local_24c,0);
              local_8._0_1_ = 6;
              FUN_004cb840(uVar4);
              local_8._0_1_ = 2;
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2c8);
              uVar4 = FUN_004cbb30();
              FUN_004cba30(local_250,(local_18 - local_250) + 1,uVar4);
            }
          }
          else {
            FUN_004cbc20(local_2e4,local_244 + 1,local_18);
            local_8._0_1_ = 7;
            pcVar3 = (char *)FUN_004cbb30();
            local_24c = _atol(pcVar3);
            local_8._0_1_ = 2;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2e4);
            local_244 = FUN_004cbbc0(&DAT_007cbc24,local_18 + 1);
            if (local_244 != DAT_007d0624) {
              FUN_004cbc20(local_300,local_18 + 1,local_244);
              local_8._0_1_ = 8;
              pcVar3 = (char *)FUN_004cbb30();
              local_248 = _atol(pcVar3);
              local_8._0_1_ = 2;
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_300);
              uVar4 = FUN_0046ff30(local_320,local_254,local_24c,local_248,0);
              local_8._0_1_ = 9;
              local_301 = FUN_004ec750(uVar4,"<<ERROR>>");
              local_8._0_1_ = 2;
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_320);
              if (local_301 == '\0') {
                uVar4 = FUN_0046ff30(local_33c,local_254,local_24c,local_248,0);
                local_8._0_1_ = 10;
                FUN_004cba00(local_250,(local_244 - local_250) + 1,uVar4);
                local_8._0_1_ = 2;
                std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          (local_33c);
              }
              else {
                _Radix = 10;
                pcVar3 = local_220;
                iVar2 = FUN_0046f7f0(local_254,local_24c,local_248,0);
                __itoa(iVar2,pcVar3,_Radix);
                FUN_004cba30(local_250,(local_244 - local_250) + 1,local_220);
              }
            }
          }
        }
      }
      else {
        local_18 = FUN_004cbbc0(&DAT_007cbbe0,0);
        local_244 = FUN_004cbbc0(&DAT_007cbbe4,local_18);
        if (local_244 == DAT_007d0624) {
          FUN_004cba30(local_18,local_18 + 2,&DAT_007cbbe6);
        }
        else {
          FUN_004cbc20(local_274,local_18 + 3,local_244);
          local_8._0_1_ = 3;
          pcVar3 = (char *)FUN_004cbb30();
          local_254 = _atol(pcVar3);
          local_8._0_1_ = 2;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_274);
          local_254 = in_stack_00000030 + local_254;
          __itoa(local_254,local_220,10);
          FUN_004cba30(local_18,(local_244 - local_18) + 1,local_220);
        }
      }
    }
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              (param_1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)&param_2);
    local_8._0_1_ = 1;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_23c);
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  }
  else {
    basic_string<>(&DAT_007cbbd8);
    local_8._0_1_ = 1;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_23c);
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  }
  ExceptionList = local_10;
  return param_1;
}

