
/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall std::logic_error::~logic_error(void)
    public: virtual __thiscall std::runtime_error::~runtime_error(void)
   
   Library: Visual Studio 2003 Debug */

void __thiscall FID_conflict__logic_error(void *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007b0f28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = &PTR_FUN_007d4724;
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             ((int)this + 0xc));
  local_8 = 0xffffffff;
  exception::~exception(this);
  ExceptionList = local_10;
  return;
}

