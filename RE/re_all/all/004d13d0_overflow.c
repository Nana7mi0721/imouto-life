
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    protected: virtual int __thiscall std::basic_filebuf<char,struct std::char_traits<char>
   >::overflow(int)
   
   Library: Visual Studio 2003 Debug */

int __thiscall
std::basic_filebuf<char,std::char_traits<char>_>::overflow
          (basic_filebuf<char,std::char_traits<char>_> *this,int param_1)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  void *_Str;
  size_t sVar7;
  size_t _Size;
  _iobuf *p_Var8;
  char **ppcVar9;
  FILE *_File;
  int local_78;
  int local_70;
  int local_48;
  size_t local_44;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_40 [28];
  undefined4 local_24;
  char *local_20;
  char local_19;
  char local_18 [4];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b10d8;
  local_10 = ExceptionList;
  local_24 = DAT_0084b484;
  ExceptionList = &local_10;
  local_48 = char_traits<char>::eof();
  bVar1 = char_traits<char>::eq_int_type(&local_48,&param_1);
  if (bVar1) {
    local_70 = char_traits<char>::not_eof(&param_1);
  }
  else {
    pcVar3 = basic_streambuf<char,std::char_traits<char>_>::pptr
                       ((basic_streambuf<char,std::char_traits<char>_> *)this);
    if (pcVar3 != (char *)0x0) {
      pcVar3 = basic_streambuf<char,std::char_traits<char>_>::pptr
                         ((basic_streambuf<char,std::char_traits<char>_> *)this);
      pcVar4 = basic_streambuf<char,std::char_traits<char>_>::epptr
                         ((basic_streambuf<char,std::char_traits<char>_> *)this);
      if (pcVar3 < pcVar4) {
        cVar2 = char_traits<char>::to_char_type(&param_1);
        pcVar3 = basic_streambuf<char,std::char_traits<char>_>::_Pninc
                           ((basic_streambuf<char,std::char_traits<char>_> *)this);
        *pcVar3 = cVar2;
        ExceptionList = local_10;
        return param_1;
      }
    }
    if (*(int *)(this + 0x58) == 0) {
      local_70 = char_traits<char>::eof();
    }
    else if (*(int *)(this + 0x3c) == 0) {
      p_Var8 = *(_iobuf **)(this + 0x58);
      cVar2 = char_traits<char>::to_char_type(&param_1);
      bVar1 = _Fputc<char>(cVar2,p_Var8);
      if (bVar1) {
        local_70 = param_1;
      }
      else {
        local_70 = char_traits<char>::eof();
      }
    }
    else {
      local_18[0] = '\b';
      local_18[1] = '\0';
      local_18[2] = '\0';
      local_18[3] = '\0';
      local_19 = char_traits<char>::to_char_type(&param_1);
      basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase
                (*(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **)
                  (this + 0x48),0,DAT_007d0624);
      basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(local_40,8,'\0');
      local_8 = 0;
      while( true ) {
        ppcVar9 = &local_20;
        basic_string<char,std::char_traits<char>,std::allocator<char>_>::begin(local_40);
        iVar5 = FUN_004d95b0();
        iVar6 = FUN_004e5650();
        pcVar4 = (char *)(iVar5 + iVar6);
        basic_string<char,std::char_traits<char>,std::allocator<char>_>::begin(local_40);
        pcVar3 = (char *)FUN_004d95b0();
        iVar5 = codecvt<char,char,int>::out
                          (*(codecvt<char,char,int> **)(this + 0x3c),(int *)(this + 0x50),&local_19,
                           local_18,&local_14,pcVar3,pcVar4,ppcVar9);
        if (iVar5 < 0) break;
        if (1 < iVar5) {
          if (iVar5 == 3) {
            bVar1 = _Fputc<char>(local_19,*(_iobuf **)(this + 0x58));
            if (bVar1) {
              local_78 = param_1;
            }
            else {
              local_78 = char_traits<char>::eof();
            }
            local_8 = 0xffffffff;
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                       local_40);
            ExceptionList = local_10;
            return local_78;
          }
          break;
        }
        basic_string<char,std::char_traits<char>,std::allocator<char>_>::begin(local_40);
        iVar5 = FUN_004d95b0();
        sVar7 = (int)local_20 - iVar5;
        local_44 = sVar7;
        if (sVar7 != 0) {
          _File = *(FILE **)(this + 0x58);
          _Size = 1;
          basic_string<char,std::char_traits<char>,std::allocator<char>_>::begin(local_40);
          _Str = (void *)FUN_004d95b0();
          sVar7 = _fwrite(_Str,_Size,sVar7,_File);
          if (local_44 != sVar7) {
            iVar5 = char_traits<char>::eof();
            local_8 = 0xffffffff;
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                       local_40);
            ExceptionList = local_10;
            return iVar5;
          }
        }
        iVar5 = param_1;
        this[0x4c] = (basic_filebuf<char,std::char_traits<char>_>)0x1;
        if (local_14 != &local_19) {
          local_8 = 0xffffffff;
          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_40);
          ExceptionList = local_10;
          return iVar5;
        }
        if (local_44 == 0) {
          basic_string<char,std::char_traits<char>,std::allocator<char>_>::append(local_40,8,'\0');
        }
      }
      local_70 = char_traits<char>::eof();
      local_8 = 0xffffffff;
      basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_40);
    }
  }
  ExceptionList = local_10;
  return local_70;
}

