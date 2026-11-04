
undefined4 __thiscall
FUN_004d4650(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,
            undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  
  puVar1 = (undefined4 *)
           std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::begin(param_1);
  uVar2 = FUN_004e0410(param_3,*puVar1);
  uVar3 = FUN_004e0410(param_4,param_3);
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)param_1,
             uVar2,uVar3);
  pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Myptr
                     ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      param_1);
  FUN_004e92a0(pcVar4 + uVar2);
  return param_2;
}

