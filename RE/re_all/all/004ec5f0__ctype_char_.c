
/* Library Function - Single Match
    protected: virtual __thiscall std::ctype<char>::~ctype<char>(void)
   
   Library: Visual Studio 2003 Debug */

void __thiscall std::ctype<char>::~ctype<char>(ctype<char> *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007b1aa8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = &PTR_FUN_007d2238;
  local_8 = 0;
  _Tidy(this);
  local_8 = 0xffffffff;
  FUN_004ec330();
  ExceptionList = local_10;
  return;
}

