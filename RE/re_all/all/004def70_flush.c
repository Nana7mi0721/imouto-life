
/* Library Function - Multiple Matches With Same Base Name
    public: class std::basic_ostream<char,struct std::char_traits<char> > & __thiscall
   std::basic_ostream<char,struct std::char_traits<char> >::flush(void)
    public: class std::basic_ostream<unsigned short,struct std::char_traits<unsigned short> > &
   __thiscall std::basic_ostream<unsigned short,struct std::char_traits<unsigned short>
   >::flush(void)
    public: class std::basic_ostream<wchar_t,struct std::char_traits<wchar_t> > & __thiscall
   std::basic_ostream<wchar_t,struct std::char_traits<wchar_t> >::flush(void)
   
   Library: Visual Studio 2003 Debug */

int * __fastcall flush(int *param_1)

{
  bool bVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  bVar1 = std::ios_base::fail((ios_base *)((int)param_1 + *(int *)(*param_1 + 4)));
  if (!bVar1) {
    FUN_004cbdb0();
    iVar2 = pubsync();
    if (iVar2 == -1) {
      local_8 = 4;
    }
  }
  std::basic_ios<char,std::char_traits<char>_>::setstate
            ((basic_ios<char,std::char_traits<char>_> *)((int)param_1 + *(int *)(*param_1 + 4)),
             local_8,false);
  return param_1;
}

