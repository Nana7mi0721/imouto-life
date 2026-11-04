
undefined * Catch_0047f2c9(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined1 auStack_20 [12];
  undefined4 uStack_14;
  
  FUN_004cbb30();
  basic_string<>();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_004cb880();
  FUN_004cbb30();
  *(undefined1 **)(unaff_EBP + -0x2b4) = auStack_20;
  uVar1 = basic_string<>(&DAT_007d0d38);
  *(undefined4 *)(unaff_EBP + -0x2fc) = uVar1;
  uVar1 = FUN_00401c50();
  *(undefined4 *)(unaff_EBP + -0x300) = uVar1;
  _sprintf((char *)(unaff_EBP + -0x260),*(char **)(unaff_EBP + -0x300));
  uStack_14 = 0x47f356;
  MessageBoxA((HWND)0x0,(LPCSTR)(unaff_EBP + -0x260),"Error",0x1000);
  *(undefined1 *)(unaff_EBP + -0x2b5) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (unaff_EBP + -0x27c));
  return &DAT_0047f37b;
}

