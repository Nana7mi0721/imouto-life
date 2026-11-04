
uint __thiscall
FUN_004d4b50(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *param_1,
            char *param_2,uint param_3,uint param_4)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char *local_10;
  int local_8;
  
  if ((param_4 != 0) || (*(uint *)(param_1 + 0x14) < param_3)) {
    if ((param_3 < *(uint *)(param_1 + 0x14)) && (param_4 <= *(int *)(param_1 + 0x14) - param_3)) {
      local_8 = (*(int *)(param_1 + 0x14) - param_3) - (param_4 - 1);
      local_10 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 _Myptr(param_1);
      local_10 = local_10 + param_3;
      while (pcVar1 = (char *)FUN_004d4c50(local_10,local_8,param_2), pcVar1 != (char *)0x0) {
        iVar2 = std::char_traits<char>::compare(pcVar1,param_2,param_4);
        if (iVar2 == 0) {
          pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   _Myptr(param_1);
          return (int)pcVar1 - (int)pcVar3;
        }
        local_8 = local_8 - (int)(pcVar1 + (1 - (int)local_10));
        local_10 = pcVar1 + 1;
      }
    }
    param_3 = DAT_007d0624;
  }
  return param_3;
}

