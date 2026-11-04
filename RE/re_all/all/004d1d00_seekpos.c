
/* Library Function - Single Match
    protected: virtual class std::fpos<int> __thiscall std::basic_filebuf<char,struct
   std::char_traits<char> >::seekpos(class std::fpos<int>,int)
   
   Library: Visual Studio 2003 Debug */

fpos<int> * __thiscall
std::basic_filebuf<char,std::char_traits<char>_>::seekpos
          (undefined4 param_1,fpos<int> *param_2,fpos<int> param_3)

{
  bool bVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  basic_streambuf<char,std::char_traits<char>_> *pbVar6;
  basic_filebuf<char,std::char_traits<char>_> *extraout_var;
  basic_filebuf<char,std::char_traits<char>_> *this;
  undefined8 local_c;
  
  local_c = fpos<int>::seekpos(&param_3);
  this = extraout_var;
  lVar2 = fpos<int>::operator_long(&param_3);
  iVar3 = lVar2 - (int)local_c;
  if ((((*(int *)(this + 0x58) != 0) && (bVar1 = _Endwrite(this), bVar1)) &&
      (iVar4 = _fsetpos(*(FILE **)(this + 0x58),&local_c), iVar4 == 0)) &&
     (((iVar3 == 0 || (iVar3 = _fseek(*(FILE **)(this + 0x58),iVar3,1), iVar3 == 0)) &&
      (iVar3 = _fgetpos(*(FILE **)(this + 0x58),&local_c), iVar3 == 0)))) {
    if (*(int *)(this + 0x48) != 0) {
      uVar5 = FUN_004e0470();
      *(undefined4 *)(this + 0x50) = uVar5;
      basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase
                (*(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **)
                  (this + 0x48),0,DAT_007d0624);
    }
    pbVar6 = (basic_streambuf<char,std::char_traits<char>_> *)
             basic_streambuf<char,std::char_traits<char>_>::gptr
                       ((basic_streambuf<char,std::char_traits<char>_> *)this);
    if (pbVar6 == (basic_streambuf<char,std::char_traits<char>_> *)(this + 0x44)) {
      basic_streambuf<char,std::char_traits<char>_>::setg
                ((basic_streambuf<char,std::char_traits<char>_> *)this,(char *)(this + 0x44),
                 (char *)(this + 0x44),(char *)(this + 0x44));
    }
    fpos<int>::fpos<int>(param_2,*(int *)(this + 0x50),CONCAT44(this,local_c._4_4_));
    return param_2;
  }
  fpos<int>::fpos<int>(param_2,DAT_007d476c);
  return param_2;
}

