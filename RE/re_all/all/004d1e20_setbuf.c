
/* Library Function - Single Match
    protected: virtual class std::basic_streambuf<char,struct std::char_traits<char> > * __thiscall
   std::basic_filebuf<char,struct std::char_traits<char> >::setbuf(char *,int)
   
   Library: Visual Studio 2003 Debug */

basic_streambuf<char,std::char_traits<char>_> * __thiscall
std::basic_filebuf<char,std::char_traits<char>_>::setbuf
          (basic_filebuf<char,std::char_traits<char>_> *this,char *param_1,int param_2)

{
  int iVar1;
  int local_c;
  
  if (*(int *)(this + 0x58) != 0) {
    if ((param_1 == (char *)0x0) && (param_2 == 0)) {
      local_c = 4;
    }
    else {
      local_c = 0;
    }
    iVar1 = _setvbuf(*(FILE **)(this + 0x58),param_1,local_c,param_2);
    if (iVar1 == 0) {
      return (basic_streambuf<char,std::char_traits<char>_> *)this;
    }
  }
  return (basic_streambuf<char,std::char_traits<char>_> *)0x0;
}

