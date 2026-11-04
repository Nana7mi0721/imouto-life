
/* Library Function - Single Match
    public: char __thiscall std::basic_ios<char,struct std::char_traits<char> >::widen(char)const 
   
   Library: Visual Studio 2003 Debug */

char __thiscall
std::basic_ios<char,std::char_traits<char>_>::widen
          (basic_ios<char,std::char_traits<char>_> *this,char param_1)

{
  char cVar1;
  undefined4 uVar2;
  ctype<char> *this_00;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b19c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = ios_base::getloc((ios_base *)this);
  local_8 = 0;
  this_00 = (ctype<char> *)use_facet<>(uVar2);
  local_8 = 0xffffffff;
  FUN_004d3d00();
  cVar1 = ctype<char>::widen(this_00,param_1);
  ExceptionList = local_10;
  return cVar1;
}

