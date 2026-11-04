
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 __fastcall FUN_00452a50(int param_1)

{
  int iVar1;
  LPCSTR lpText;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_1e4 [20];
  undefined4 uStack_1d0;
  undefined *puStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  char *pcVar3;
  UINT uType;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_170 [28];
  undefined1 *local_154;
  char local_150 [256];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_34 [28];
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ada01;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  ExceptionList = &local_10;
  FUN_004cc4c0();
  iVar1 = FUN_004cbbc0();
  if (iVar1 == 0) {
    _strlen("MessageBox:");
    uStack_1bc = 0x452ad2;
    FUN_004cc4c0();
    FUN_004cbc20();
    local_8 = 0;
    uStack_1bc = 0;
    uStack_1c0 = *(undefined4 *)(param_1 + 0x10);
    uStack_1c4 = *(undefined4 *)(param_1 + 0x18);
    uStack_1c8 = *(undefined4 *)(param_1 + 0x14);
    local_154 = abStack_1e4;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_1e4,local_50);
    FUN_00424670(local_170);
    local_8._0_1_ = 1;
    FUN_004cb840();
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_170);
    uType = 0;
    pcVar3 = "Message";
    lpText = (LPCSTR)FUN_004cbb30();
    uStack_1bc = 0x452b7d;
    MessageBoxA((HWND)0x0,lpText,pcVar3,uType);
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_50
              );
  }
  if (DAT_00a0f82c == 1) {
    uStack_1bc = 0;
    uStack_1c0 = *(undefined4 *)(param_1 + 0x10);
    uStack_1c4 = *(undefined4 *)(param_1 + 0x18);
    uStack_1c8 = *(undefined4 *)(param_1 + 0x14);
    puStack_1cc = (undefined *)0x0;
    uStack_1d0 = 0x452bda;
    pbVar2 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             FUN_004cc4c0();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_1e4,pbVar2);
    FUN_00424670(local_34);
    local_8 = 2;
    local_14 = 0;
    while (local_14 = FUN_004cbbc0(), local_14 != -1) {
      FUN_004cba30();
      local_14 = local_14 + 2;
    }
    FUN_004cb880();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              (local_34," -->[");
    if (DAT_00a0f818 != -1) {
      _sprintf(local_150,"MapEv%d/");
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                (local_34,local_150);
    }
    if (DAT_00a11794 != -1) {
      puStack_1cc = &DAT_007cedf0;
      uStack_1d0 = 0x452cbc;
      basic_string<>();
      puStack_1cc = (undefined *)0x452cc7;
      pcVar3 = (char *)FUN_00401c50();
      _sprintf(local_150,pcVar3);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                (local_34,local_150);
    }
    puStack_1cc = &DAT_007cedf8;
    uStack_1d0 = 0x452d11;
    basic_string<>();
    puStack_1cc = (undefined *)0x452d1c;
    pcVar3 = (char *)FUN_00401c50();
    _sprintf(local_150,pcVar3);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              (local_34,local_150);
    FUN_004cb880();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a164c4,
               "\r\n");
    DAT_00a11798 = 1;
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_34
              );
  }
  ExceptionList = local_10;
  return 1;
}

