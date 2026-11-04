
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    protected: bool __thiscall std::basic_filebuf<char,struct std::char_traits<char>
   >::_Endwrite(void)
   
   Library: Visual Studio 2003 Debug */

bool __thiscall
std::basic_filebuf<char,std::char_traits<char>_>::_Endwrite
          (basic_filebuf<char,std::char_traits<char>_> *this)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  void *_Str;
  size_t sVar4;
  size_t sVar5;
  size_t _Count;
  int *piVar6;
  FILE *_File;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_38 [28];
  undefined4 local_1c;
  int local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007afdf8;
  local_10 = ExceptionList;
  local_1c = DAT_0084b484;
  if ((*(int *)(this + 0x3c) != 0) &&
     (this[0x4c] != (basic_filebuf<char,std::char_traits<char>_>)0x0)) {
    local_18[1] = 8;
    ExceptionList = &local_10;
    iVar1 = char_traits<char>::eof();
    (**(code **)(*(int *)this + 4))(iVar1);
    basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>(local_38,8,'\0');
    local_8 = 0;
    while( true ) {
      piVar6 = local_18;
      basic_string<char,std::char_traits<char>,std::allocator<char>_>::begin(local_38);
      iVar1 = FUN_004d95b0(piVar6);
      iVar2 = FUN_004e5650();
      iVar1 = iVar1 + iVar2;
      basic_string<char,std::char_traits<char>,std::allocator<char>_>::begin(local_38);
      uVar3 = FUN_004d95b0(iVar1);
      iVar1 = unshift(this + 0x50,uVar3,iVar1,piVar6);
      if (iVar1 == 0) {
        this[0x4c] = (basic_filebuf<char,std::char_traits<char>_>)0x0;
      }
      else if (iVar1 != 1) {
        if (iVar1 == 3) {
          local_8 = 0xffffffff;
          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_38);
          ExceptionList = local_10;
          return true;
        }
        local_8 = 0xffffffff;
        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_38);
        ExceptionList = local_10;
        return false;
      }
      basic_string<char,std::char_traits<char>,std::allocator<char>_>::begin(local_38);
      iVar1 = FUN_004d95b0();
      sVar5 = local_18[0] - iVar1;
      if (sVar5 != 0) {
        _File = *(FILE **)(this + 0x58);
        _Count = 1;
        sVar4 = sVar5;
        basic_string<char,std::char_traits<char>,std::allocator<char>_>::begin(local_38);
        _Str = (void *)FUN_004d95b0();
        sVar4 = _fwrite(_Str,sVar4,_Count,_File);
        if (sVar5 != sVar4) {
          local_8 = 0xffffffff;
          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_38);
          ExceptionList = local_10;
          return false;
        }
      }
      if (this[0x4c] == (basic_filebuf<char,std::char_traits<char>_>)0x0) break;
      basic_string<char,std::char_traits<char>,std::allocator<char>_>::append(local_38,8,'\0');
    }
    local_8 = 0xffffffff;
    basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_38
              );
  }
  ExceptionList = local_10;
  return true;
}

