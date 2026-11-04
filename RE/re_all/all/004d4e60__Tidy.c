
/* Library Function - Single Match
    protected: void __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> >::_Tidy(bool,unsigned int)
   
   Library: Visual Studio 2003 Debug */

void __thiscall
std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Tidy
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *this,
          bool param_1,uint param_2)

{
  char *pcVar1;
  
  if ((param_1) && (0xf < *(uint *)(this + 0x18))) {
    pcVar1 = *(char **)(this + 4);
    if (param_2 != 0) {
      char_traits<char>::copy((char *)(this + 4),pcVar1,param_2);
    }
    deallocate(pcVar1,*(int *)(this + 0x18) + 1);
  }
  *(undefined4 *)(this + 0x18) = 0xf;
  _Eos(this,param_2);
  return;
}

