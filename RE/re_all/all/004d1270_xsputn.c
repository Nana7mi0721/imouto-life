
/* Library Function - Single Match
    protected: virtual int __thiscall std::basic_streambuf<char,struct std::char_traits<char>
   >::xsputn(char const *,int)
   
   Library: Visual Studio 2003 Debug */

int __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::xsputn
          (basic_streambuf<char,std::char_traits<char>_> *this,char *param_1,int param_2)

{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  local_8 = 0;
  do {
    while( true ) {
      if (param_2 < 1) {
        return local_8;
      }
      pcVar2 = pptr(this);
      if (pcVar2 != (char *)0x0) break;
LAB_004d1304:
      iVar4 = char_traits<char>::to_int_type(param_1);
      local_10 = (**(code **)(*(int *)this + 4))(iVar4);
      local_14 = char_traits<char>::eof();
      bVar1 = char_traits<char>::eq_int_type(&local_14,&local_10);
      if (bVar1) {
        return local_8;
      }
      param_1 = param_1 + 1;
      local_8 = local_8 + 1;
      param_2 = param_2 + -1;
    }
    pcVar2 = epptr(this);
    pcVar3 = pptr(this);
    local_c = (int)pcVar2 - (int)pcVar3;
    if ((int)local_c < 1) goto LAB_004d1304;
    if (param_2 < (int)local_c) {
      local_c = param_2;
    }
    pcVar2 = param_1;
    uVar5 = local_c;
    pcVar3 = pptr(this);
    char_traits<char>::copy(pcVar3,pcVar2,uVar5);
    param_1 = param_1 + local_c;
    local_8 = local_8 + local_c;
    param_2 = param_2 - local_c;
    pbump(this,local_c);
  } while( true );
}

