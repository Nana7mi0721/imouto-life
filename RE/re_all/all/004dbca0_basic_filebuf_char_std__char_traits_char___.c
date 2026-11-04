
/* Library Function - Single Match
    public: __thiscall std::basic_filebuf<char,struct std::char_traits<char>
   >::basic_filebuf<char,struct std::char_traits<char> >(struct _iobuf *)
   
   Library: Visual Studio 2003 Debug */

basic_filebuf<char,std::char_traits<char>_> * __thiscall
std::basic_filebuf<char,std::char_traits<char>_>::basic_filebuf<char,std::char_traits<char>_>
          (basic_filebuf<char,std::char_traits<char>_> *this,_iobuf *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1478;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004e0520();
  local_8 = 0;
  *(undefined ***)this = &PTR_FUN_007d2174;
  *(undefined4 *)(this + 0x48) = 0;
  _Init(this,param_1,0);
  ExceptionList = local_10;
  return this;
}

