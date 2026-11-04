
/* Library Function - Single Match
    protected: void __thiscall std::basic_ios<char,struct std::char_traits<char> >::init(class
   std::basic_streambuf<char,struct std::char_traits<char> > *,bool)
   
   Library: Visual Studio 2003 Debug */

void __thiscall
std::basic_ios<char,std::char_traits<char>_>::init
          (basic_ios<char,std::char_traits<char>_> *this,
          basic_streambuf<char,std::char_traits<char>_> *param_1,bool param_2)

{
  basic_ios<char,std::char_traits<char>_> bVar1;
  
  ios_base::_Init((ios_base *)this);
  *(basic_streambuf<char,std::char_traits<char>_> **)(this + 0x28) = param_1;
  *(undefined4 *)(this + 0x2c) = 0;
  bVar1 = (basic_ios<char,std::char_traits<char>_>)widen(this,' ');
  this[0x30] = bVar1;
  if (*(int *)(this + 0x28) == 0) {
    setstate(this,4,false);
  }
  if (param_2) {
    ios_base::_Addstd((ios_base *)this);
  }
  else {
    *(undefined4 *)(this + 4) = 0;
  }
  return;
}

