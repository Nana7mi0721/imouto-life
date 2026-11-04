
/* Library Function - Single Match
    protected: virtual int __thiscall std::basic_filebuf<char,struct std::char_traits<char>
   >::uflow(void)
   
   Library: Visual Studio 2003 Debug */

int __thiscall
std::basic_filebuf<char,std::char_traits<char>_>::uflow
          (basic_filebuf<char,std::char_traits<char>_> *this)

{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *_Src;
  char *pcVar7;
  char **ppcVar8;
  int *piVar9;
  char **ppcVar10;
  size_t _Size;
  int local_38;
  char local_1c;
  char *local_18;
  char local_11;
  int local_10;
  char *local_c;
  char local_5;
  
  pcVar2 = basic_streambuf<char,std::char_traits<char>_>::gptr
                     ((basic_streambuf<char,std::char_traits<char>_> *)this);
  if (pcVar2 != (char *)0x0) {
    pcVar2 = basic_streambuf<char,std::char_traits<char>_>::gptr
                       ((basic_streambuf<char,std::char_traits<char>_> *)this);
    pcVar3 = basic_streambuf<char,std::char_traits<char>_>::egptr
                       ((basic_streambuf<char,std::char_traits<char>_> *)this);
    if (pcVar2 < pcVar3) {
      pcVar2 = basic_streambuf<char,std::char_traits<char>_>::_Gninc
                         ((basic_streambuf<char,std::char_traits<char>_> *)this);
      iVar4 = char_traits<char>::to_int_type(pcVar2);
      return iVar4;
    }
  }
  if (*(int *)(this + 0x58) == 0) {
    iVar5 = char_traits<char>::eof();
  }
  else if (*(int *)(this + 0x3c) == 0) {
    local_5 = '\0';
    bVar1 = _Fgetc<char>(&local_5,*(_iobuf **)(this + 0x58));
    if (bVar1) {
      iVar5 = char_traits<char>::to_int_type(&local_5);
    }
    else {
      iVar5 = char_traits<char>::eof();
    }
  }
  else {
    *(undefined4 *)(this + 0x40) = *(undefined4 *)(this + 0x50);
    basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase
              (*(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **)
                (this + 0x48),0,DAT_007d0624);
    do {
      while( true ) {
        iVar4 = FID_conflict__getc(*(FILE **)(this + 0x58));
        if (iVar4 == -1) {
          iVar4 = char_traits<char>::eof();
          return iVar4;
        }
        local_1c = (char)iVar4;
        basic_string<char,std::char_traits<char>,std::allocator<char>_>::append
                  (*(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)
                    (this + 0x48),1,local_1c);
        ppcVar10 = &local_18;
        piVar9 = &local_10;
        pcVar2 = &local_11;
        ppcVar8 = &local_c;
        basic_string<char,std::char_traits<char>,std::allocator<char>_>::begin
                  (*(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)
                    (this + 0x48));
        iVar4 = FUN_004d95b0();
        iVar6 = FUN_004e5650();
        pcVar7 = (char *)(iVar4 + iVar6);
        basic_string<char,std::char_traits<char>,std::allocator<char>_>::begin
                  (*(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)
                    (this + 0x48));
        pcVar3 = (char *)FUN_004d95b0();
        iVar4 = codecvt<char,char,int>::in
                          (*(codecvt<char,char,int> **)(this + 0x3c),(int *)(this + 0x50),pcVar3,
                           pcVar7,ppcVar8,pcVar2,(char *)piVar9,ppcVar10);
        if (iVar4 == 0) {
          basic_string<char,std::char_traits<char>,std::allocator<char>_>::begin
                    (*(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)
                      (this + 0x48));
          iVar4 = FUN_004d95b0();
          iVar6 = FUN_004e5650();
          local_10 = (iVar4 + iVar6) - (int)local_c;
          while (0 < local_10) {
            local_10 = local_10 + -1;
            _ungetc((int)local_c[local_10],*(FILE **)(this + 0x58));
          }
          iVar4 = char_traits<char>::to_int_type(&local_11);
          return iVar4;
        }
        if (iVar4 != 1) break;
        basic_string<char,std::char_traits<char>,std::allocator<char>_>::begin
                  (*(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)
                    (this + 0x48));
        iVar4 = FUN_004d95b0();
        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase
                  (*(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **)
                    (this + 0x48),0,(int)local_c - iVar4);
      }
      if (iVar4 != 3) {
        iVar4 = char_traits<char>::eof();
        return iVar4;
      }
      iVar4 = FUN_004e5650();
    } while (iVar4 == 0);
    _Size = 1;
    basic_string<char,std::char_traits<char>,std::allocator<char>_>::begin
              (*(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)(this + 0x48));
    _Src = (void *)FUN_004d95b0();
    _memcpy(&local_11,_Src,_Size);
    iVar5 = char_traits<char>::to_int_type(&local_11);
  }
  return iVar5;
}

