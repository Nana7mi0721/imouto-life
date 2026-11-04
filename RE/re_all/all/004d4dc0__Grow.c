
/* Library Function - Single Match
    protected: bool __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::_Grow(unsigned int,bool)
   
   Library: Visual Studio 2003 Debug */

bool __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Grow
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this,uint param_1,
          bool param_2)

{
  uint uVar1;
  uint local_c;
  
  uVar1 = FID_conflict_max_size(this);
  if (uVar1 < param_1) {
    FUN_0050d54e();
  }
  if (*(uint *)(this + 0x18) < param_1) {
    FUN_004e0270(param_1,*(undefined4 *)(this + 0x14));
  }
  else if ((param_2) && (param_1 < 0x10)) {
    if (param_1 < *(uint *)(this + 0x14)) {
      local_c = param_1;
    }
    else {
      local_c = *(uint *)(this + 0x14);
    }
    basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Tidy
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)this,
               true,local_c);
  }
  else if (param_1 == 0) {
    basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)this,0);
  }
  return param_1 != 0;
}

