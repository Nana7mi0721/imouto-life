
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FUN_004acea0(void)

{
  char *_Format;
  LPCSTR lpCaption;
  size_t sVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined1 uStack00000000;
  UINT uType;
  undefined1 local_65d;
  int local_64c;
  undefined1 local_648 [504];
  int local_450;
  int local_44c;
  char local_448 [1024];
  int local_48;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_44 [28];
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_1d;
  undefined4 local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007aff68;
  local_10 = ExceptionList;
  local_28 = DAT_0084b484;
  DAT_00a0f7f8 = 1;
  if (DAT_00a0f828 < DAT_00a0f820 + 1) {
    DAT_00a117e4 = 1;
    local_65d = 0;
  }
  else {
    DAT_00a0f844 = 1;
    ExceptionList = &local_10;
    _memcpy(&local_1d,(void *)(DAT_00a0f824 + DAT_00a0f820),1);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
      DAT_00a117e4 = 1;
      local_65d = 0;
    }
    else {
      DAT_00a0f844 = 4;
      _memcpy(&local_18,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      FUN_004d00b0();
      for (local_48 = 0; local_48 < local_18; local_48 = local_48 + 1) {
        FUN_004d0120();
        FUN_00483c70();
      }
      DAT_00a0f7f8 = 0;
      FUN_004cbb30();
      basic_string<>();
      local_8 = 0;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                (local_44,"BasicData/CDataBase");
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                (local_44,".project");
      local_24 = FUN_004cbb30();
      local_14 = FUN_0052e3c0();
      if (local_14 == 0) {
        basic_string<>(&DAT_007d0f50);
        _Format = (char *)FUN_00401c50();
        _sprintf(local_448,_Format);
        uType = 0;
        basic_string<>(&DAT_007d0d98);
        lpCaption = (LPCSTR)FUN_00401c50();
        MessageBoxA((HWND)0x0,local_448,lpCaption,uType);
        FUN_0052ec70();
                    /* WARNING: Subroutine does not return */
        _exit(1);
      }
      local_1c = FUN_0052c9a0();
      DAT_00a11790 = 0;
      if (DAT_00a117ec == 0) {
        sVar1 = FUN_0052c9a0();
        DAT_00a0f830 = _malloc(sVar1);
        sVar1 = FUN_0052c9a0();
        _memset(DAT_00a0f830,0,sVar1);
      }
      FUN_0052c9a0();
      FUN_0052cde0();
      thunk_FUN_00580b80();
      if (&uStack00000000 == (undefined1 *)0x18) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        _memcpy(&local_18,(void *)((int)DAT_00a0f830 + DAT_00a11790),4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
      FUN_004d0500();
      for (local_44c = 0; local_44c < local_18; local_44c = local_44c + 1) {
        FUN_004d05c0();
        FUN_00482e20();
      }
      if (DAT_00a117ec == 0) {
        _free(DAT_00a0f830);
      }
      iVar2 = FUN_004d00e0();
      if (0 < iVar2) {
        iVar2 = FUN_004d00e0();
        if (iVar2 < local_18) {
          FUN_004ad670();
        }
        for (local_450 = 0; local_450 < local_18; local_450 = local_450 + 1) {
          FUN_004cde80();
          iVar2 = FUN_004ce080();
          FUN_004d0120();
          iVar3 = FUN_004ce080();
          if (iVar3 < iVar2) {
            local_64c = 0;
            while( true ) {
              FUN_004cde80();
              iVar2 = FUN_004ce080();
              if (iVar2 <= local_64c) break;
              FUN_004cde80();
              piVar4 = (int *)FUN_004ce990();
              local_648[local_64c] = (char)(*piVar4 % 1000);
              local_64c = local_64c + 1;
            }
            FUN_004cde80();
            FUN_004cde80();
            FUN_004ce080();
            FUN_004ad3b0();
          }
        }
      }
      local_65d = 1;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_44);
    }
  }
  ExceptionList = local_10;
  return local_65d;
}

