
/* Library Function - Single Match
    protected: virtual int __thiscall std::basic_filebuf<char,struct std::char_traits<char>
   >::underflow(void)
   
   Library: Visual Studio 2003 Debug */

int __thiscall
std::basic_filebuf<char,std::char_traits<char>_>::underflow
          (basic_filebuf<char,std::char_traits<char>_> *this)

{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int local_c;
  int local_8;
  
  pcVar2 = basic_streambuf<char,std::char_traits<char>_>::gptr
                     ((basic_streambuf<char,std::char_traits<char>_> *)this);
  if (pcVar2 != (char *)0x0) {
    pcVar2 = basic_streambuf<char,std::char_traits<char>_>::gptr
                       ((basic_streambuf<char,std::char_traits<char>_> *)this);
    pcVar3 = basic_streambuf<char,std::char_traits<char>_>::egptr
                       ((basic_streambuf<char,std::char_traits<char>_> *)this);
    if (pcVar2 < pcVar3) {
      pcVar2 = basic_streambuf<char,std::char_traits<char>_>::gptr
                         ((basic_streambuf<char,std::char_traits<char>_> *)this);
      iVar4 = char_traits<char>::to_int_type(pcVar2);
      return iVar4;
    }
  }
  local_8 = (**(code **)(*(int *)this + 0x14))();
  local_c = char_traits<char>::eof();
  bVar1 = char_traits<char>::eq_int_type(&local_c,&local_8);
  if (!bVar1) {
    (**(code **)(*(int *)this + 8))(local_8);
  }
  return local_8;
}

