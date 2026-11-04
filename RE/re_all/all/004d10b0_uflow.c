
/* Library Function - Single Match
    protected: virtual int __thiscall std::basic_streambuf<char,struct std::char_traits<char>
   >::uflow(void)
   
   Library: Visual Studio 2003 Debug */

int __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::uflow
          (basic_streambuf<char,std::char_traits<char>_> *this)

{
  bool bVar1;
  char *pcVar2;
  int local_14;
  int local_c;
  int local_8;
  
  local_8 = (**(code **)(*(int *)this + 0x10))();
  local_c = char_traits<char>::eof();
  bVar1 = char_traits<char>::eq_int_type(&local_c,&local_8);
  if (bVar1) {
    local_14 = char_traits<char>::eof();
  }
  else {
    pcVar2 = _Gninc(this);
    local_14 = char_traits<char>::to_int_type(pcVar2);
  }
  return local_14;
}

