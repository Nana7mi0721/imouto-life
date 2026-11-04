
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    private: static class std::locale::_Locimp * __cdecl std::locale::_Init(void)
   
   Library: Visual Studio 2003 Release */

_Locimp * __cdecl std::locale::_Init(void)

{
  _Locimp *p_Var1;
  int unaff_EBP;
  
  FUN_006c5130();
  p_Var1 = DAT_00a20150;
  if (DAT_00a20150 == (_Locimp *)0x0) {
    FUN_0050d92b(0);
    p_Var1 = DAT_00a20150;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (p_Var1 == (_Locimp *)0x0) {
      p_Var1 = operator_new(0x34);
      *(_Locimp **)(unaff_EBP + -0x14) = p_Var1;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      if (p_Var1 == (_Locimp *)0x0) {
        p_Var1 = (_Locimp *)0x0;
      }
      else {
        p_Var1 = (_Locimp *)_Locimp::_Locimp(p_Var1,false);
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      __Setgloballocale(p_Var1);
      *(undefined4 *)(p_Var1 + 0x10) = 0x3f;
      basic_string<char,std::char_traits<char>,std::allocator<char>_>::assign
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(p_Var1 + 0x18),
                 "C");
      DAT_00a20154 = (facet *)p_Var1;
      facet::_Incref((facet *)p_Var1);
      _DAT_00a2015c = DAT_00a20154;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0050d94e();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return p_Var1;
}

