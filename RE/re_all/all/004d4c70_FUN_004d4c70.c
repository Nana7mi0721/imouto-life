
uint __thiscall
FUN_004d4c70(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *param_1,
            char *param_2,uint param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint local_14;
  uint local_10;
  char *local_8;
  
  if (param_4 == 0) {
    if (param_3 < *(uint *)(param_1 + 0x14)) {
      local_10 = param_3;
    }
    else {
      local_10 = *(uint *)(param_1 + 0x14);
    }
  }
  else {
    if (param_4 <= *(uint *)(param_1 + 0x14)) {
      if (param_3 < *(int *)(param_1 + 0x14) - param_4) {
        local_14 = param_3;
      }
      else {
        local_14 = *(int *)(param_1 + 0x14) - param_4;
      }
      local_8 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                _Myptr(param_1);
      local_8 = local_8 + local_14;
      while( true ) {
        cVar1 = FUN_004d4d50(local_8,param_2);
        if ((cVar1 != '\0') &&
           (iVar2 = std::char_traits<char>::compare(local_8,param_2,param_4), iVar2 == 0)) {
          pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   _Myptr(param_1);
          return (int)local_8 - (int)pcVar3;
        }
        pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 _Myptr(param_1);
        if (local_8 == pcVar3) break;
        local_8 = local_8 + -1;
      }
    }
    local_10 = DAT_007d0624;
  }
  return local_10;
}

