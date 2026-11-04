
/* Library Function - Single Match
    public: __thiscall std::_Locinfo::~_Locinfo(void)
   
   Library: Visual Studio 2003 Release */

void __thiscall std::_Locinfo::~_Locinfo(_Locinfo *this)

{
  _Locinfo *_Locale;
  
  if (*(int *)(this + 0x50) != 0) {
    if (*(uint *)(this + 0x54) < 0x10) {
      _Locale = this + 0x40;
    }
    else {
      _Locale = *(_Locinfo **)(this + 0x40);
    }
    _setlocale(0,(char *)_Locale);
  }
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Tidy
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (this + 0x58),true,0);
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Tidy
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (this + 0x3c),true,0);
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Tidy
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (this + 0x20),true,0);
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Tidy
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)(this + 4)
             ,true,0);
  FUN_0050d94e();
  return;
}

