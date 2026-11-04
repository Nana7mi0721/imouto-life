
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _fprintf
   
   Library: Visual Studio 2003 Release */

int __cdecl _fprintf(FILE *_File,char *_Format,...)

{
  int _Flag;
  int iVar1;
  undefined1 uStack0000000c;
  
  __lock_file(_File);
  _Flag = __stbuf(_File);
  iVar1 = __output(_File,_Format,&uStack0000000c);
  __ftbuf(_Flag,_File);
  FUN_006c5ae0();
  return iVar1;
}

