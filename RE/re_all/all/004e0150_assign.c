
/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> > & __thiscall std::basic_string<char,struct
   std::char_traits<char>,class std::_DebugHeapAllocator<char> >::assign(char const *,unsigned int)
   
   Library: Visual Studio 2003 Debug */

basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> * __thiscall
std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *this,
          char *param_1,uint param_2)

{
  bool bVar1;
  char *pcVar2;
  uint uVar3;
  
  bVar1 = basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Inside
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)this,param_1
                    );
  if (bVar1) {
    pcVar2 = _Myptr(this);
    this = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
           assign(this,(basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>
                        *)this,(int)param_1 - (int)pcVar2,param_2);
  }
  else {
    bVar1 = basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Grow
                      ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)this,
                       param_2,false);
    if (bVar1) {
      uVar3 = param_2;
      pcVar2 = _Myptr(this);
      char_traits<char>::copy(pcVar2,param_1,uVar3);
      _Eos(this,param_2);
    }
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> *)
         this;
}

