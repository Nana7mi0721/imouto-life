
/* Library Function - Single Match
    protected: char * __thiscall std::basic_streambuf<char,struct std::char_traits<char>
   >::_Gninc(void)
   
   Library: Visual Studio 2003 Debug */

char * __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::_Gninc
          (basic_streambuf<char,std::char_traits<char>_> *this)

{
  char *pcVar1;
  
  **(int **)(this + 0x30) = **(int **)(this + 0x30) + -1;
  pcVar1 = (char *)**(undefined4 **)(this + 0x20);
  **(int **)(this + 0x20) = **(int **)(this + 0x20) + 1;
  return pcVar1;
}

