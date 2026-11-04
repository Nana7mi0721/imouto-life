
/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   & __thiscall std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::assign(unsigned int,char)
   
   Library: Visual Studio 2003 Debug */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::assign
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this,uint param_1,
          char param_2)

{
  bool bVar1;
  char *pcVar2;
  uint uVar3;
  
  if (param_1 == DAT_007d0624) {
    FUN_0050d54e();
  }
  bVar1 = _Grow(this,param_1,false);
  if (bVar1) {
    uVar3 = param_1;
    pcVar2 = basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Myptr
                       ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )this);
    char_traits<char>::assign(pcVar2,uVar3,param_2);
    basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)this,
               param_1);
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
}

