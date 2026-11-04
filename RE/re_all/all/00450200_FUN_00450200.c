
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __thiscall FUN_00450200(int param_1,CBitmapButton param_2)

{
  char cVar1;
  uint *puVar2;
  int iVar3;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar4;
  bool bVar5;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_94 [20];
  undefined4 uStack_80;
  int iStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_60;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_3c [28];
  undefined4 local_20;
  int local_1c;
  int local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007ad975;
  local_10 = ExceptionList;
  local_20 = DAT_0084b484;
  local_8 = 0;
  pbStack_60 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x450237
  ;
  ExceptionList = &local_10;
  puVar2 = (uint *)FUN_004ce990();
  DAT_00a14038 = *puVar2 & 0xf;
  DAT_00a140c5 = 0;
  local_11 = '\x01';
  for (local_18 = 0; local_18 < 10; local_18 = local_18 + 1) {
    FUN_004cb9c0();
  }
  local_1c = 0;
  while( true ) {
    iVar3 = FUN_004cc430();
    if (iVar3 <= local_1c) break;
    pbStack_60 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0;
    uStack_64 = 0;
    uStack_68 = 0;
    uStack_6c = 0;
    uStack_70 = *(undefined4 *)(param_1 + 0x10);
    uStack_74 = *(undefined4 *)(param_1 + 0x18);
    uStack_78 = *(undefined4 *)(param_1 + 0x14);
    iStack_7c = local_1c;
    uStack_80 = 0x4502c5;
    pbVar4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             FUN_004cc4c0();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_94,pbVar4);
    FUN_00424670(local_3c);
    local_8._0_1_ = 1;
    pbStack_60 = local_3c;
    uStack_64 = 0x4502f7;
    cVar1 = operator!=<>();
    if (cVar1 != '\0') {
      local_11 = '\0';
    }
    pbStack_60 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x450313;
    FUN_004cb880();
    pbStack_60 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x450328;
    FUN_004cb840();
    pbStack_60 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x450337;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a14014,"\n"
              );
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3c);
    local_1c = local_1c + 1;
  }
  *(undefined1 *)(param_1 + 0xc) = 1;
  pbStack_60 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x450359
  ;
  puVar2 = (uint *)FUN_004ce990();
  DAT_00a1403c = ((int)(*puVar2 & 0xf0) >> 4) + -2;
  pbStack_60 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x45037b
  ;
  puVar2 = (uint *)FUN_004ce990();
  DAT_00a14040 = (int)(*puVar2 & 0xf00) >> 8;
  bVar5 = local_11 == '\0';
  if (bVar5) {
    pbStack_60 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 (int)*(char *)(*(int *)(param_1 + 0x898) + 0x10);
    uStack_64 = 0x450428;
    FUN_00487210();
    local_8 = 0xffffffff;
    CBitmapButton::~CBitmapButton(&param_2);
  }
  else {
    DAT_00a140c5 = 1;
    DAT_00a140b9 = 0;
    cVar1 = *(char *)(*(int *)(param_1 + 0x898) + 0x10);
    pbStack_60 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x4503c8;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a14014,"");
    uStack_64 = 0x4503da;
    pbStack_60 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 (int)cVar1;
    FUN_00487210();
    pbStack_60 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 0x4503ee;
    FUN_00487240();
    local_8 = 0xffffffff;
    CBitmapButton::~CBitmapButton(&param_2);
  }
  ExceptionList = local_10;
  return bVar5;
}

