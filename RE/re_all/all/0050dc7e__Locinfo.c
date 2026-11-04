
/* Library Function - Single Match
    public: __thiscall std::_Locinfo::_Locinfo(char const *)
   
   Library: Visual Studio 2003 Release */

int __thiscall std::_Locinfo::_Locinfo(_Locinfo *this,char *param_1)

{
  char *pcVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_006c5130();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0050d92b(0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  basic_string<>();
  basic_string<>();
  basic_string<>();
  basic_string<>();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  pcVar1 = _setlocale(0,(char *)0x0);
  basic_string<char,std::char_traits<char>,std::allocator<char>_>::assign
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
             (extraout_ECX + 0x3c),pcVar1);
  if (*(int *)(unaff_EBP + 8) != 0) {
    pcVar1 = _setlocale(0,*(char **)(unaff_EBP + 8));
    if (pcVar1 != (char *)0x0) goto LAB_0050dcec;
  }
  pcVar1 = "*";
LAB_0050dcec:
  basic_string<char,std::char_traits<char>,std::allocator<char>_>::assign
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
             (extraout_ECX + 0x58),pcVar1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

