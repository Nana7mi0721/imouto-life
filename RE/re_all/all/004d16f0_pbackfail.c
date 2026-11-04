
/* Library Function - Single Match
    protected: virtual int __thiscall std::basic_filebuf<char,struct std::char_traits<char>
   >::pbackfail(int)
   
   Library: Visual Studio 2003 Debug */

int __thiscall
std::basic_filebuf<char,std::char_traits<char>_>::pbackfail
          (basic_filebuf<char,std::char_traits<char>_> *this,int param_1)

{
  bool bVar1;
  basic_filebuf<char,std::char_traits<char>_> bVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  basic_filebuf<char,std::char_traits<char>_> *pbVar6;
  char local_11;
  int local_10;
  int local_c;
  int local_8;
  
  pcVar3 = basic_streambuf<char,std::char_traits<char>_>::gptr
                     ((basic_streambuf<char,std::char_traits<char>_> *)this);
  if (pcVar3 != (char *)0x0) {
    pcVar3 = basic_streambuf<char,std::char_traits<char>_>::eback
                       ((basic_streambuf<char,std::char_traits<char>_> *)this);
    pcVar4 = basic_streambuf<char,std::char_traits<char>_>::gptr
                       ((basic_streambuf<char,std::char_traits<char>_> *)this);
    if (pcVar3 < pcVar4) {
      local_8 = char_traits<char>::eof();
      bVar1 = char_traits<char>::eq_int_type(&local_8,&param_1);
      if (!bVar1) {
        pcVar3 = basic_streambuf<char,std::char_traits<char>_>::gptr
                           ((basic_streambuf<char,std::char_traits<char>_> *)this);
        local_c = char_traits<char>::to_int_type(pcVar3 + -1);
        bVar1 = char_traits<char>::eq_int_type(&local_c,&param_1);
        if (!bVar1) goto LAB_004d1782;
      }
      basic_streambuf<char,std::char_traits<char>_>::_Gndec
                ((basic_streambuf<char,std::char_traits<char>_> *)this);
      iVar5 = char_traits<char>::not_eof(&param_1);
      return iVar5;
    }
  }
LAB_004d1782:
  if (*(int *)(this + 0x58) != 0) {
    local_10 = char_traits<char>::eof();
    bVar1 = char_traits<char>::eq_int_type(&local_10,&param_1);
    if (!bVar1) {
      if (*(int *)(this + 0x3c) == 0) {
        local_11 = char_traits<char>::to_char_type(&param_1);
        bVar1 = _Ungetc<char>(&local_11,*(_iobuf **)(this + 0x58));
        if (bVar1) {
          return param_1;
        }
      }
      pbVar6 = (basic_filebuf<char,std::char_traits<char>_> *)
               basic_streambuf<char,std::char_traits<char>_>::gptr
                         ((basic_streambuf<char,std::char_traits<char>_> *)this);
      if (pbVar6 == this + 0x44) {
        iVar5 = char_traits<char>::eof();
        return iVar5;
      }
      bVar2 = (basic_filebuf<char,std::char_traits<char>_>)char_traits<char>::to_char_type(&param_1)
      ;
      this[0x44] = bVar2;
      basic_streambuf<char,std::char_traits<char>_>::setg
                ((basic_streambuf<char,std::char_traits<char>_> *)this,(char *)(this + 0x44),
                 (char *)(this + 0x44),(char *)(this + 0x45));
      return param_1;
    }
  }
  iVar5 = char_traits<char>::eof();
  return iVar5;
}

