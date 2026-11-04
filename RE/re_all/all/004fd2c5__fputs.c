
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _fputs
   
   Library: Visual Studio 2003 Release */

int __cdecl _fputs(char *_Str,FILE *_File)

{
  size_t sVar1;
  int _Flag;
  size_t sVar2;
  
  sVar1 = _strlen(_Str);
  __lock_file(_File);
  _Flag = __stbuf(_File);
  sVar2 = __fwrite_lk(_Str,1,sVar1,_File);
  __ftbuf(_Flag,_File);
  FUN_004fd32c();
  return (sVar2 == sVar1) - 1;
}

