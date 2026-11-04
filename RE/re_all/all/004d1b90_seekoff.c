
/* WARNING: Variable defined which should be unmapped: param_1 */
/* Library Function - Single Match
    protected: virtual class std::fpos<int> __thiscall std::basic_filebuf<char,struct
   std::char_traits<char> >::seekoff(long,int,int)
   
   Library: Visual Studio 2003 Debug */

long __thiscall
std::basic_filebuf<char,std::char_traits<char>_>::seekoff
          (basic_filebuf<char,std::char_traits<char>_> *this,long param_1,int param_2,int param_3)

{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  basic_filebuf<char,std::char_traits<char>_> *pbVar4;
  int iVar5;
  undefined4 unaff_ESI;
  FILE *_File;
  uint local_10;
  undefined8 local_c;
  
  pcVar2 = basic_streambuf<char,std::char_traits<char>_>::egptr
                     ((basic_streambuf<char,std::char_traits<char>_> *)this);
  pcVar3 = basic_streambuf<char,std::char_traits<char>_>::gptr
                     ((basic_streambuf<char,std::char_traits<char>_> *)this);
  if (((pcVar3 < pcVar2) &&
      (pbVar4 = (basic_filebuf<char,std::char_traits<char>_> *)
                basic_streambuf<char,std::char_traits<char>_>::gptr
                          ((basic_streambuf<char,std::char_traits<char>_> *)this),
      pbVar4 == this + 0x44)) && (param_3 == 1)) {
    if (*(int *)(this + 0x3c) == 0) {
      param_2 = param_2 + -1;
    }
    else {
      local_10 = FUN_004e5650();
      while (0 < (int)local_10) {
        local_10 = local_10 - 1;
        _File = *(FILE **)(this + 0x58);
        pcVar2 = basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 operator[](*(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(this + 0x48),local_10);
        _ungetc((int)*pcVar2,_File);
      }
      basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase
                (*(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **)
                  (this + 0x48),0,DAT_007d0624);
      *(undefined4 *)(this + 0x50) = *(undefined4 *)(this + 0x40);
    }
  }
  if ((((*(int *)(this + 0x58) == 0) || (bVar1 = _Endwrite(this), !bVar1)) ||
      (((param_2 != 0 || (param_3 != 1)) &&
       (iVar5 = _fseek(*(FILE **)(this + 0x58),param_2,param_3), iVar5 != 0)))) ||
     (iVar5 = _fgetpos(*(FILE **)(this + 0x58),&local_c), iVar5 != 0)) {
    fpos<int>::fpos<int>((fpos<int> *)param_1,DAT_007d476c);
  }
  else {
    pbVar4 = (basic_filebuf<char,std::char_traits<char>_> *)
             basic_streambuf<char,std::char_traits<char>_>::gptr
                       ((basic_streambuf<char,std::char_traits<char>_> *)this);
    if (pbVar4 == this + 0x44) {
      basic_streambuf<char,std::char_traits<char>_>::setg
                ((basic_streambuf<char,std::char_traits<char>_> *)this,(char *)(this + 0x44),
                 (char *)(this + 0x44),(char *)(this + 0x44));
    }
    fpos<int>::fpos<int>
              ((fpos<int> *)param_1,*(int *)(this + 0x50),CONCAT44(unaff_ESI,local_c._4_4_));
  }
  return param_1;
}

