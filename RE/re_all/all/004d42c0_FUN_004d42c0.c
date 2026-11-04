
_String_val<char,std::allocator<char>_> * __thiscall
FUN_004d42c0(_String_val<char,std::allocator<char>_> *param_1,
            basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>
            *param_2,uint param_3,uint param_4)

{
  allocator<char> aaStack_a [6];
  
  std::allocator<char>::allocator<char>(aaStack_a + -6);
  std::_String_val<char,std::allocator<char>_>::_String_val<char,std::allocator<char>_>(param_1);
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Tidy
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)param_1,
             false,0);
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)param_1,
             param_2,param_3,param_4);
  return param_1;
}

