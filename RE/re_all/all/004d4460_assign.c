
/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> > & __thiscall std::basic_string<char,struct
   std::char_traits<char>,class std::_DebugHeapAllocator<char> >::assign(class
   std::basic_string<char,struct std::char_traits<char>,class std::_DebugHeapAllocator<char> > const
   &,unsigned int,unsigned int)
   
   Library: Visual Studio 2003 Debug */

basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> * __thiscall
std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *this,
          basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>
          *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  uint local_8;
  
  uVar2 = FUN_004e5650();
  if (uVar2 < param_2) {
    FUN_0050d50e();
  }
  iVar3 = FUN_004e5650();
  local_8 = iVar3 - param_2;
  if (param_3 < local_8) {
    local_8 = param_3;
  }
  if (this == (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)param_1)
  {
    erase(this,param_2 + local_8,DAT_007d0624);
    erase(this,0,param_2);
  }
  else {
    bVar1 = basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Grow
                      ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)this,
                       local_8,false);
    if (bVar1) {
      uVar2 = local_8;
      pcVar4 = _Myptr((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      param_1);
      pcVar4 = pcVar4 + param_2;
      pcVar5 = _Myptr(this);
      char_traits<char>::copy(pcVar5,pcVar4,uVar2);
      _Eos(this,local_8);
    }
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> *)
         this;
}

