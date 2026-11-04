
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _printf
   
   Library: Visual Studio 2003 Release */

int __cdecl _printf(char *_Format,...)

{
  int _Flag;
  int iVar1;
  undefined1 uStack00000008;
  
  __lock_file2(1,&DAT_0084b738);
  _Flag = __stbuf((FILE *)&DAT_0084b738);
  iVar1 = __output(&DAT_0084b738,_Format,&uStack00000008);
  __ftbuf(_Flag,(FILE *)&DAT_0084b738);
  FUN_004fee85();
  return iVar1;
}

