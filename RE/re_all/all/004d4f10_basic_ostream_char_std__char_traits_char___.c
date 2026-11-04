
/* Library Function - Single Match
    public: __thiscall std::basic_ostream<char,struct std::char_traits<char>
   >::basic_ostream<char,struct std::char_traits<char> >(class std::basic_streambuf<char,struct
   std::char_traits<char> > *,bool)
   
   Library: Visual Studio 2003 Debug */

basic_ostream<char,std::char_traits<char>_> * __thiscall
std::basic_ostream<char,std::char_traits<char>_>::basic_ostream<char,std::char_traits<char>_>
          (basic_ostream<char,std::char_traits<char>_> *this,
          basic_streambuf<char,std::char_traits<char>_> *param_1,bool param_2)

{
  int in_stack_0000000c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b119c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_stack_0000000c != 0) {
    ExceptionList = &local_10;
    *(undefined **)this = &DAT_007d21dc;
    basic_ios<>(this,0);
    local_8 = 0;
  }
  *(undefined ***)(this + *(int *)(*(int *)this + 4)) =
       &PTR_FID_conflict__scalar_deleting_destructor__007d2170;
  basic_ios<char,std::char_traits<char>_>::init
            ((basic_ios<char,std::char_traits<char>_> *)(this + *(int *)(*(int *)this + 4)),param_1,
             param_2);
  ExceptionList = local_10;
  return this;
}

