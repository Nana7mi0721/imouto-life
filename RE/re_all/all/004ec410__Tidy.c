
/* Library Function - Single Match
    protected: void __thiscall std::ctype<char>::_Tidy(void)
   
   Library: Visual Studio 2003 Debug */

void __thiscall std::ctype<char>::_Tidy(ctype<char> *this)

{
  if (*(int *)(this + 0x14) < 1) {
    if (*(int *)(this + 0x14) < 0) {
      _free(*(void **)(this + 0x10));
    }
  }
  else {
    _free(*(void **)(this + 0x10));
  }
  return;
}

