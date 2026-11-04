
/* Library Function - Single Match
    public: void __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::resize(unsigned int,char)
   
   Library: Visual Studio 2003 Debug */

void __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::resize
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this,uint param_1,
          char param_2)

{
  if (*(uint *)(this + 0x14) < param_1) {
    append(this,param_1 - *(int *)(this + 0x14),param_2);
  }
  else {
    basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)this,
               param_1,DAT_007d0624);
  }
  return;
}

