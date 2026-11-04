
/* Library Function - Single Match
    public: int __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::compare(unsigned int,unsigned int,char const *,unsigned int)const 
   
   Library: Visual Studio 2003 Debug */

int __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::compare
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this,uint param_1,
          uint param_2,char *param_3,uint param_4)

{
  char *pcVar1;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  
  if (*(uint *)(this + 0x14) < param_1) {
    FUN_0050d50e();
  }
  if (*(int *)(this + 0x14) - param_1 < param_2) {
    param_2 = *(int *)(this + 0x14) - param_1;
  }
  if (param_2 == 0) {
    local_10 = 0;
  }
  else {
    if (param_2 < param_4) {
      local_14 = param_2;
    }
    else {
      local_14 = param_4;
    }
    pcVar1 = basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Myptr
                       ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )this);
    local_10 = char_traits<char>::compare(pcVar1 + param_1,param_3,local_14);
  }
  if (local_10 == 0) {
    if (param_2 < param_4) {
      local_1c = 0xffffffff;
    }
    else {
      local_1c = (uint)(param_2 != param_4);
    }
    local_18 = local_1c;
  }
  else {
    local_18 = local_10;
  }
  return local_18;
}

