
basic_string<char,std::char_traits<char>,std::allocator<char>_> * __thiscall
FUN_004d46d0(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,uint param_2,
            uint param_3,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *param_4,
            uint param_5,uint param_6)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_2 <= *(uint *)(param_1 + 0x14)) {
    uVar1 = FUN_004e5650();
    if (param_5 <= uVar1) goto LAB_004d46f9;
  }
  FUN_0050d50e();
LAB_004d46f9:
  if (*(int *)(param_1 + 0x14) - param_2 < param_3) {
    param_3 = *(int *)(param_1 + 0x14) - param_2;
  }
  iVar2 = FUN_004e5650();
  if (iVar2 - param_5 < param_6) {
    param_6 = iVar2 - param_5;
  }
  if (DAT_007d0624 - param_6 <= *(int *)(param_1 + 0x14) - param_3) {
    FUN_0050d54e();
  }
  uVar1 = (*(int *)(param_1 + 0x14) - param_3) - param_2;
  uVar5 = (*(int *)(param_1 + 0x14) + param_6) - param_3;
  if (*(uint *)(param_1 + 0x14) < uVar5) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Grow(param_1,uVar5,false)
    ;
  }
  if (param_1 == (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)param_4) {
    if (param_3 < param_6) {
      if (param_2 < param_5) {
        if (param_5 < param_2 + param_3) {
          uVar6 = param_3;
          pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)param_1);
          pcVar3 = pcVar3 + param_5;
          pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)param_1);
          std::char_traits<char>::move(pcVar4 + param_2,pcVar3,uVar6);
          pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)param_1);
          pcVar3 = pcVar3 + param_3 + param_2;
          pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)param_1);
          std::char_traits<char>::move(pcVar4 + param_6 + param_2,pcVar3,uVar1);
          uVar1 = param_6 - param_3;
          pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)param_1);
          pcVar3 = pcVar3 + param_6 + param_5;
          pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)param_1);
          std::char_traits<char>::move(pcVar4 + param_3 + param_2,pcVar3,uVar1);
        }
        else {
          pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)param_1);
          pcVar3 = pcVar3 + param_3 + param_2;
          pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)param_1);
          std::char_traits<char>::move(pcVar4 + param_6 + param_2,pcVar3,uVar1);
          uVar1 = param_6;
          pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)param_1);
          pcVar3 = pcVar3 + ((param_5 + param_6) - param_3);
          pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)param_1);
          std::char_traits<char>::move(pcVar4 + param_2,pcVar3,uVar1);
        }
      }
      else {
        pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )param_1);
        pcVar3 = pcVar3 + param_3 + param_2;
        pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )param_1);
        std::char_traits<char>::move(pcVar4 + param_6 + param_2,pcVar3,uVar1);
        pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )param_1);
        pcVar3 = pcVar3 + param_5;
        pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )param_1);
        std::char_traits<char>::move(pcVar4 + param_2,pcVar3,param_6);
      }
    }
    else {
      uVar6 = param_6;
      pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      param_1);
      pcVar3 = pcVar3 + param_5;
      pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      param_1);
      std::char_traits<char>::move(pcVar4 + param_2,pcVar3,uVar6);
      pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      param_1);
      pcVar3 = pcVar3 + param_3 + param_2;
      pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      param_1);
      std::char_traits<char>::move(pcVar4 + param_6 + param_2,pcVar3,uVar1);
    }
  }
  else {
    pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Myptr
                       ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )param_1);
    pcVar3 = pcVar3 + param_3 + param_2;
    pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Myptr
                       ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )param_1);
    std::char_traits<char>::move(pcVar4 + param_6 + param_2,pcVar3,uVar1);
    pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Myptr
                       (param_4);
    pcVar3 = pcVar3 + param_5;
    pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Myptr
                       ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )param_1);
    std::char_traits<char>::copy(pcVar4 + param_2,pcVar3,param_6);
  }
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)param_1,
             uVar5);
  return param_1;
}

