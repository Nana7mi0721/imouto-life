
/* Library Function - Multiple Matches With Different Base Names
    public: void __thiscall std::_String_base::_Xlen(void)const 
    public: void __thiscall std::_String_base::_Xran(void)const 
   
   Library: Visual Studio 2003 Debug */

void __thiscall FID_conflict__Xran(void *this)

{
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_54 [28];
  undefined1 local_38 [40];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b11d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  basic_string<>("vector<T> too long");
  local_8 = 0;
  FID_conflict_length_error(local_38,local_54);
  __CxxThrowException_8(local_38,&DAT_00845c30);
  ExceptionList = local_10;
  return;
}

