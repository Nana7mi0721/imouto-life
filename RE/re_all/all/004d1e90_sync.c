
/* Library Function - Single Match
    protected: virtual int __thiscall std::basic_filebuf<char,struct std::char_traits<char>
   >::sync(void)
   
   Library: Visual Studio 2003 Debug */

int __thiscall
std::basic_filebuf<char,std::char_traits<char>_>::sync
          (basic_filebuf<char,std::char_traits<char>_> *this)

{
  bool bVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (*(int *)(this + 0x58) != 0) {
    iVar2 = char_traits<char>::eof();
    local_8 = (**(code **)(*(int *)this + 4))(iVar2);
    local_c = char_traits<char>::eof();
    bVar1 = char_traits<char>::eq_int_type(&local_c,&local_8);
    if ((!bVar1) && (iVar2 = _fflush(*(FILE **)(this + 0x58)), iVar2 < 0)) {
      return -1;
    }
  }
  return 0;
}

