
/* Library Function - Single Match
    protected: char * __thiscall std::basic_streambuf<char,struct std::char_traits<char>
   >::_Pninc(void)
   
   Library: Visual Studio 2003 Debug */

char * __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::_Pninc
          (basic_streambuf<char,std::char_traits<char>_> *this)

{
  char *pcVar1;
  
  **(int **)(this + 0x34) = **(int **)(this + 0x34) + -1;
  pcVar1 = (char *)**(undefined4 **)(this + 0x24);
  **(int **)(this + 0x24) = **(int **)(this + 0x24) + 1;
  return pcVar1;
}

