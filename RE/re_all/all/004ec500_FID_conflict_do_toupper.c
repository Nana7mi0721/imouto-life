
/* Library Function - Multiple Matches With Different Base Names
    protected: virtual char const * __thiscall std::ctype<char>::do_tolower(char *,char const
   *)const 
    protected: virtual char const * __thiscall std::ctype<char>::do_toupper(char *,char const
   *)const 
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2015 Release */

char * __thiscall FID_conflict_do_toupper(void *this,char *param_1,char *param_2)

{
  int iVar1;
  
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    iVar1 = __Toupper((uint)(byte)*param_1,(_Ctypevec *)((int)this + 8));
    *param_1 = (char)iVar1;
  }
  return param_1;
}

