
/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   & __thiscall std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::append(unsigned int,char)
   
   Library: Visual Studio 2003 Debug */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::append
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this,uint param_1,
          char param_2)

{
  bool bVar1;
  uint uVar2;
  char *pcVar3;
  
  if ((uint)(DAT_007d0624 - *(int *)(this + 0x14)) <= param_1) {
    FUN_0050d54e();
  }
  if (param_1 != 0) {
    uVar2 = *(int *)(this + 0x14) + param_1;
    bVar1 = _Grow(this,uVar2,false);
    if (bVar1) {
      pcVar3 = basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Myptr
                         ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)this);
      char_traits<char>::assign(pcVar3 + *(int *)(this + 0x14),param_1,param_2);
      basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)this,
                 uVar2);
    }
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
}

