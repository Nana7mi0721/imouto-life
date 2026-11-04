
/* Library Function - Single Match
    protected: virtual int __thiscall std::basic_streambuf<char,struct std::char_traits<char>
   >::xsgetn(char *,int)
   
   Library: Visual Studio 2003 Debug */

int __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::xsgetn
          (basic_streambuf<char,std::char_traits<char>_> *this,char *param_1,int param_2)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
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
      pcVar3 = gptr(this);
      if (pcVar3 != (char *)0x0) break;
LAB_004d11d4:
      local_10 = (**(code **)(*(int *)this + 0x14))();
      local_14 = char_traits<char>::eof();
      bVar1 = char_traits<char>::eq_int_type(&local_14,&local_10);
      if (bVar1) {
        return local_8;
      }
      cVar2 = char_traits<char>::to_char_type(&local_10);
      *param_1 = cVar2;
      param_1 = param_1 + 1;
      local_8 = local_8 + 1;
      param_2 = param_2 + -1;
    }
    pcVar3 = egptr(this);
    pcVar4 = gptr(this);
    local_c = (int)pcVar3 - (int)pcVar4;
    if ((int)local_c < 1) goto LAB_004d11d4;
    if (param_2 < (int)local_c) {
      local_c = param_2;
    }
    uVar5 = local_c;
    pcVar3 = gptr(this);
    char_traits<char>::copy(param_1,pcVar3,uVar5);
    param_1 = param_1 + local_c;
    local_8 = local_8 + local_c;
    param_2 = param_2 - local_c;
    gbump(this,local_c);
  } while( true );
}

