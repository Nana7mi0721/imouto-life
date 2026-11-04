
/* Library Function - Single Match
    protected: void __thiscall std::basic_streambuf<char,struct std::char_traits<char> >::_Init(char
   * *,char * *,int *,char * *,char * *,int *)
   
   Library: Visual Studio 2003 Debug */

void __thiscall
std::basic_streambuf<char,std::char_traits<char>_>::_Init
          (basic_streambuf<char,std::char_traits<char>_> *this,char **param_1,char **param_2,
          int *param_3,char **param_4,char **param_5,int *param_6)

{
  *(char ***)(this + 0x10) = param_1;
  *(char ***)(this + 0x14) = param_4;
  *(char ***)(this + 0x20) = param_2;
  *(char ***)(this + 0x24) = param_5;
  *(int **)(this + 0x30) = param_3;
  *(int **)(this + 0x34) = param_6;
  return;
}

