
undefined4 __fastcall FUN_0045d1c0(int param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  
  iVar1 = FUN_004ce080();
  if ((iVar1 < 1) ||
     (pwVar2 = std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::back
                         ((basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>
                           *)(param_1 + 0x840)), 0 < *(int *)pwVar2)) {
    FUN_0045cfe0();
    return 1;
  }
  FUN_0045d090();
  return 1;
}

