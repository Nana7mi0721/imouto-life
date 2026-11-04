
/* Library Function - Single Match
    public: class std::basic_filebuf<char,struct std::char_traits<char> > * __thiscall
   std::basic_filebuf<char,struct std::char_traits<char> >::close(void)
   
   Library: Visual Studio 2003 Debug */

basic_filebuf<char,struct_std::char_traits<char>_> * __thiscall
std::basic_filebuf<char,std::char_traits<char>_>::close
          (basic_filebuf<char,std::char_traits<char>_> *this)

{
  bool bVar1;
  int iVar2;
  
  if (((*(int *)(this + 0x58) != 0) && (bVar1 = _Endwrite(this), bVar1)) &&
     (iVar2 = _fclose(*(FILE **)(this + 0x58)), iVar2 == 0)) {
    _Init(this,(_iobuf *)0x0,2);
    return (basic_filebuf<char,struct_std::char_traits<char>_> *)this;
  }
  return (basic_filebuf<char,struct_std::char_traits<char>_> *)0x0;
}

