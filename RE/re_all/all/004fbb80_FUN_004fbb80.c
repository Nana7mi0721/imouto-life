
_String_val<char,std::allocator<char>_> * __thiscall
FUN_004fbb80(_String_val<char,std::allocator<char>_> *param_1,char *param_2,char *param_3)

{
  allocator<char> aaStack_a [6];
  
  std::allocator<char>::allocator<char>(aaStack_a + -6);
  std::_String_val<char,std::allocator<char>_>::_String_val<char,std::allocator<char>_>(param_1);
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Tidy
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)param_1,
             false,0);
  if (param_2 != param_3) {
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)param_1,
               param_2,(int)param_3 - (int)param_2);
  }
  return param_1;
}

