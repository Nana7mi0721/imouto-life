
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall std::logic_error::logic_error(class std::logic_error const &)
    public: __thiscall std::runtime_error::runtime_error(class std::runtime_error const &)
   
   Library: Visual Studio 2003 Debug */

void * __thiscall FID_conflict_runtime_error(void *this,runtime_error *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0f28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  exception::exception(this,(exception *)param_1);
  local_8 = 0;
  *(undefined ***)this = &PTR_FUN_007d4724;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)((int)this + 0xc),
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (param_1 + 0xc));
  ExceptionList = local_10;
  return this;
}

