
/* Library Function - Single Match
    protected: void __thiscall std::basic_streambuf<char,struct std::char_traits<char>
   >::_Init(void)
   
   Library: Visual Studio 2003 Debug */

void __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::_Init
          (basic_streambuf<char,std::char_traits<char>_> *this)

{
  *(basic_streambuf<char,std::char_traits<char>_> **)(this + 0x10) = this + 8;
  *(basic_streambuf<char,std::char_traits<char>_> **)(this + 0x14) = this + 0xc;
  *(basic_streambuf<char,std::char_traits<char>_> **)(this + 0x20) = this + 0x18;
  *(basic_streambuf<char,std::char_traits<char>_> **)(this + 0x24) = this + 0x1c;
  *(basic_streambuf<char,std::char_traits<char>_> **)(this + 0x30) = this + 0x28;
  *(basic_streambuf<char,std::char_traits<char>_> **)(this + 0x34) = this + 0x2c;
  setp(this,(char *)0x0,(char *)0x0);
  setg(this,(char *)0x0,(char *)0x0,(char *)0x0);
  return;
}

