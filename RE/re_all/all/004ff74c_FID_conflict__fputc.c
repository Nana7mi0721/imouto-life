
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Different Base Names
    _fputc
    _putc
   
   Library: Visual Studio 2003 Release */

int __cdecl FID_conflict__fputc(int _Ch,FILE *_File)

{
  int *piVar1;
  uint uVar2;
  
  __lock_file(_File);
  piVar1 = &_File->_cnt;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    uVar2 = __flsbuf(_Ch,_File);
  }
  else {
    *_File->_ptr = (char)_Ch;
    uVar2 = _Ch & 0xff;
    _File->_ptr = _File->_ptr + 1;
  }
  FUN_004ff79c();
  return uVar2;
}

