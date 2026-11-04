
/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   & __thiscall std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::insert(unsigned int,unsigned int,char)
   
   Library: Visual Studio 2003 Debug */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::insert
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this,uint param_1,
          uint param_2,char param_3)

{
  bool bVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  
  if (*(uint *)(this + 0x14) < param_1) {
    FUN_0050d50e();
  }
  if ((uint)(DAT_007d0624 - *(int *)(this + 0x14)) <= param_2) {
    FUN_0050d54e();
  }
  if (param_2 != 0) {
    uVar5 = *(int *)(this + 0x14) + param_2;
    bVar1 = _Grow(this,uVar5,false);
    if (bVar1) {
      uVar2 = *(int *)(this + 0x14) - param_1;
      pcVar3 = basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Myptr
                         ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)this);
      pcVar3 = pcVar3 + param_1;
      pcVar4 = basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Myptr
                         ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)this);
      char_traits<char>::move(pcVar4 + param_2 + param_1,pcVar3,uVar2);
      pcVar3 = basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Myptr
                         ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)this);
      char_traits<char>::assign(pcVar3 + param_1,param_2,param_3);
      basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)this,
                 uVar5);
    }
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
}

