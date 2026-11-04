
/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> > & __thiscall std::basic_string<char,struct
   std::char_traits<char>,class std::_DebugHeapAllocator<char> >::erase(unsigned int,unsigned int)
   
   Library: Visual Studio 2003 Debug */

basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> * __thiscall
std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *this,
          uint param_1,uint param_2)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  
  if (*(uint *)(this + 0x14) < param_1) {
    FUN_0050d50e();
  }
  if (*(int *)(this + 0x14) - param_1 < param_2) {
    param_2 = *(int *)(this + 0x14) - param_1;
  }
  if (param_2 != 0) {
    uVar3 = (*(int *)(this + 0x14) - param_1) - param_2;
    pcVar1 = _Myptr(this);
    pcVar1 = pcVar1 + param_2 + param_1;
    pcVar2 = _Myptr(this);
    char_traits<char>::move(pcVar2 + param_1,pcVar1,uVar3);
    _Eos(this,*(int *)(this + 0x14) - param_2);
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> *)
         this;
}

