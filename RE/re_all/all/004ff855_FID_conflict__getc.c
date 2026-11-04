
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Different Base Names
    _fgetc
    _getc
   
   Library: Visual Studio 2003 Release */

int __cdecl FID_conflict__getc(FILE *_File)

{
  int *piVar1;
  uint uVar2;
  
  __lock_file(_File);
  piVar1 = &_File->_cnt;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    uVar2 = __filbuf(_File);
  }
  else {
    uVar2 = (uint)(byte)*_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  FUN_004ff89d();
  return uVar2;
}

