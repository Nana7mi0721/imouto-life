
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _vfprintf
   
   Library: Visual Studio 2003 Release */

int __cdecl _vfprintf(FILE *_File,char *_Format,va_list _ArgList)

{
  int _Flag;
  int iVar1;
  
  __lock_file(_File);
  _Flag = __stbuf(_File);
  iVar1 = __output(_File,_Format,_ArgList);
  __ftbuf(_Flag,_File);
  FUN_006c5a82();
  return iVar1;
}

