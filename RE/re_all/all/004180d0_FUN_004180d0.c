
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0041846e) */

undefined1 __thiscall FUN_004180d0(int param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  LPCSTR pCVar3;
  size_t sVar4;
  void *_Dst;
  int *piVar5;
  int *piVar6;
  undefined1 uStack00000000;
  UINT UVar7;
  undefined1 local_491;
  undefined1 local_435;
  undefined1 local_3f1;
  int local_3e4;
  int local_3e0;
  int local_3dc;
  int local_3d8;
  int local_3d4;
  char local_3d0 [516];
  int local_1cc;
  char local_1c8 [304];
  char local_98;
  char local_97;
  char local_96;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_94 [31];
  char local_75;
  char local_74;
  char local_73;
  char local_72;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007abb76;
  local_10 = ExceptionList;
  local_1c = DAT_0084b484;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_94,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)&DAT_00a14c70);
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_94,param_2);
  FUN_004cbb30();
  local_14 = FUN_0052e3c0();
  if (local_14 == 0) {
    iVar1 = _strcmp(param_2,"");
    if (iVar1 == 0) {
      basic_string<>();
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_1c8,pcVar2);
    }
    else {
      FUN_004cbb30();
      basic_string<>();
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_1c8,pcVar2);
    }
    UVar7 = 1;
    basic_string<>();
    pCVar3 = (LPCSTR)FUN_00401c50();
    MessageBoxA((HWND)0x0,local_1c8,pCVar3,UVar7);
    local_3f1 = 0;
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_94
              );
  }
  else {
    DAT_00a11790 = 0;
    if (DAT_00a117ec == 0) {
      FUN_004cbb30();
      sVar4 = FUN_0052c9a0();
      DAT_00a0f830 = _malloc(sVar4);
      FUN_004cbb30();
      sVar4 = FUN_0052c9a0();
      _memset(DAT_00a0f830,0,sVar4);
    }
    FUN_004cbb30();
    local_18 = FUN_0052c9a0();
    FUN_0052cde0();
    thunk_FUN_00580b80();
    for (local_1cc = 0; local_1cc < 0x1400; local_1cc = local_1cc + 1) {
      *(undefined1 *)(param_1 + local_1cc) = 0;
    }
    FUN_0046cc80();
    local_8._0_1_ = 1;
    FUN_0046f4c0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_004d4160();
    FUN_004cdbe0();
    FUN_004cf3a0();
    DAT_00a11790 = DAT_00a11790 + 0x14;
    local_74 = *DAT_00a0f830;
    local_73 = DAT_00a0f830[3];
    local_72 = DAT_00a0f830[9];
    local_98 = DAT_00a0f830[2];
    local_97 = DAT_00a0f830[6];
    local_96 = DAT_00a0f830[8];
    if ((((DAT_00a0f830[10] != 'W') || (DAT_00a0f830[0xb] != 'O')) || (DAT_00a0f830[0xc] != 'L')) ||
       ((DAT_00a0f830[0xd] != 'F' || (DAT_00a0f830[0xe] != 'M')))) {
      basic_string<>(param_2);
      FUN_0041b9e0();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&DAT_00a0f800,DAT_00a0f830 + DAT_00a11790,4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    if (&uStack00000000 == (undefined1 *)0x75) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy(&local_75,DAT_00a0f830 + DAT_00a11790,1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if (local_75 == 'e') {
      FUN_0046cd20();
      FUN_0046f390();
      for (local_3d4 = 0; local_3d4 < 3; local_3d4 = local_3d4 + 1) {
        for (local_3d8 = 0; local_3d8 < *(int *)(param_1 + 0x1420); local_3d8 = local_3d8 + 1) {
          for (local_3dc = 0; local_3dc < *(int *)(param_1 + 0x1424); local_3dc = local_3dc + 1) {
            FUN_004cde80();
            FUN_004cde80();
            iVar1 = FUN_004ce990();
            if (iVar1 == 0) {
              __CxxThrowException_8();
            }
            if (DAT_00a117ec == 0) {
              DAT_00a1179c = 4;
              sVar4 = 4;
              pcVar2 = DAT_00a0f830 + DAT_00a11790;
              FUN_004cde80();
              FUN_004cde80();
              _Dst = (void *)FUN_004ce990();
              _memcpy(_Dst,pcVar2,sVar4);
            }
            DAT_00a11790 = DAT_00a11790 + 4;
          }
        }
      }
      FUN_0046cff0();
      local_8._0_1_ = 2;
      for (local_3e0 = 0; local_3e0 < *(int *)(param_1 + 0x1428); local_3e0 = local_3e0 + 1) {
        FUN_0046cff0();
        local_8._0_1_ = 3;
        FUN_004cf620();
        local_8._0_1_ = 2;
        FUN_0046f510();
        FUN_004cf5e0();
        FUN_0046d5a0();
        for (local_3e4 = local_3e0; 0 < local_3e4; local_3e4 = local_3e4 + -1) {
          piVar5 = (int *)FUN_004cf5e0();
          piVar6 = (int *)FUN_004cf5e0();
          if (*piVar6 <= *piVar5) break;
          FUN_004cf5e0();
          FUN_0046f560();
          FUN_004cf5e0();
          FUN_004cf5e0();
          FUN_0046f560();
          FUN_004cf5e0();
          FUN_0046f560();
        }
      }
      if (&uStack00000000 == (undefined1 *)0x75) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 1;
        _memcpy(&local_75,DAT_00a0f830 + DAT_00a11790,1);
      }
      DAT_00a11790 = DAT_00a11790 + 1;
      if (((local_74 != '\0') || (local_73 != '\0')) || (local_72 != '\0')) {
        basic_string<>(param_2);
        FUN_0041b9e0();
      }
      if (DAT_00a117ec == 0) {
        _free(DAT_00a0f830);
      }
      local_491 = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0046f510();
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_94);
      local_3f1 = local_491;
    }
    else {
      basic_string<>();
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_3d0,pcVar2);
      UVar7 = 0;
      basic_string<>();
      pCVar3 = (LPCSTR)FUN_00401c50();
      MessageBoxA((HWND)0x0,local_3d0,pCVar3,UVar7);
      local_435 = 0;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_94);
      local_3f1 = local_435;
    }
  }
  ExceptionList = local_10;
  return local_3f1;
}

