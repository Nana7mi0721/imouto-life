
basic_string<char,std::char_traits<char>,std::allocator<char>_> * __thiscall
FUN_004d4990(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,uint param_2,
            uint param_3,char *param_4,uint param_5)

{
  bool bVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  
  bVar1 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Inside
                    (param_1,param_4);
  if (bVar1) {
    pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Myptr
                       ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )param_1);
    param_1 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
              FUN_004d46d0(param_2,param_3,param_1,(int)param_4 - (int)pcVar2,param_5);
  }
  else {
    if (*(uint *)(param_1 + 0x14) < param_2) {
      FUN_0050d50e();
    }
    if (*(int *)(param_1 + 0x14) - param_2 < param_3) {
      param_3 = *(int *)(param_1 + 0x14) - param_2;
    }
    if (DAT_007d0624 - param_5 <= *(int *)(param_1 + 0x14) - param_3) {
      FUN_0050d54e();
    }
    uVar3 = (*(int *)(param_1 + 0x14) - param_3) - param_2;
    if (param_5 < param_3) {
      uVar5 = uVar3;
      pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      param_1);
      pcVar2 = pcVar2 + param_3 + param_2;
      pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      param_1);
      std::char_traits<char>::move(pcVar4 + param_5 + param_2,pcVar2,uVar5);
    }
    if ((param_5 != 0) || (param_3 != 0)) {
      uVar5 = (*(int *)(param_1 + 0x14) + param_5) - param_3;
      bVar1 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Grow
                        (param_1,uVar5,false);
      if (bVar1) {
        if (param_3 < param_5) {
          pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)param_1);
          pcVar2 = pcVar2 + param_3 + param_2;
          pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)param_1);
          std::char_traits<char>::move(pcVar4 + param_5 + param_2,pcVar2,uVar3);
        }
        pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )param_1);
        std::char_traits<char>::copy(pcVar2 + param_2,param_4,param_5);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos
                  ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   param_1,uVar5);
      }
    }
  }
  return param_1;
}

