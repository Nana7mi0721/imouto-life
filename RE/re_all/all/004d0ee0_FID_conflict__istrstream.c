
/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall std::istrstream::~istrstream(void)
    public: virtual __thiscall std::ostrstream::~ostrstream(void)
   
   Library: Visual Studio 2003 Debug */

void __thiscall FID_conflict__istrstream(void *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007b109b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)((int)this + *(int *)(*(int *)((int)this + -0x60) + 4) + -0x60) =
       &PTR__scalar_deleting_destructor__007d2164;
  local_8 = 0;
  FUN_004d0f80();
  local_8 = 0xffffffff;
  std::basic_ostream<char,std::char_traits<char>_>::~basic_ostream<char,std::char_traits<char>_>
            ((basic_ostream<char,std::char_traits<char>_> *)((int)this + -0x5c));
  ExceptionList = local_10;
  return;
}

