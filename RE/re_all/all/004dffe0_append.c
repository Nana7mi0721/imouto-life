
/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   & __thiscall std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::append(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   const &,unsigned int,unsigned int)
   
   Library: Visual Studio 2003 Debug */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::append
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this,
          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
          uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar2 = FUN_004e5650();
  if (uVar2 < param_2) {
    FUN_0050d50e();
  }
  iVar3 = FUN_004e5650();
  if (iVar3 - param_2 < param_3) {
    param_3 = iVar3 - param_2;
  }
  if ((uint)(DAT_007d0624 - *(int *)(this + 0x14)) <= param_3) {
    FUN_0050d54e();
  }
  if (param_3 != 0) {
    uVar2 = *(int *)(this + 0x14) + param_3;
    bVar1 = _Grow(this,uVar2,false);
    if (bVar1) {
      pcVar4 = basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Myptr
                         ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)param_1);
      pcVar4 = pcVar4 + param_2;
      pcVar5 = basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Myptr
                         ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)this);
      char_traits<char>::copy(pcVar5 + *(int *)(this + 0x14),pcVar4,param_3);
      basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)this,
                 uVar2);
    }
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
}

