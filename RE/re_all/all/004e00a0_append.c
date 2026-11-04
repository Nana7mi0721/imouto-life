
/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   & __thiscall std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::append(char const *,unsigned int)
   
   Library: Visual Studio 2003 Debug */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::append
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this,char *param_1,
          uint param_2)

{
  bool bVar1;
  char *pcVar2;
  uint uVar3;
  
  bVar1 = _Inside(this,param_1);
  if (bVar1) {
    pcVar2 = basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Myptr
                       ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )this);
    this = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
           append(this,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)this,(int)param_1 - (int)pcVar2,param_2);
  }
  else {
    if ((uint)(DAT_007d0624 - *(int *)(this + 0x14)) <= param_2) {
      FUN_0050d54e();
    }
    if (param_2 != 0) {
      uVar3 = *(int *)(this + 0x14) + param_2;
      bVar1 = _Grow(this,uVar3,false);
      if (bVar1) {
        pcVar2 = basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Myptr
                           ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)this);
        char_traits<char>::copy(pcVar2 + *(int *)(this + 0x14),param_1,param_2);
        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos
                  ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)this
                   ,uVar3);
      }
    }
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
}

