
/* Library Function - Single Match
    struct _iobuf * __cdecl std::_Fiopen(char const *,int,int)
   
   Library: Visual Studio 2003 Release */

_iobuf * __cdecl std::_Fiopen(char *param_1,int param_2,int param_3)

{
  int iVar1;
  FILE *_File;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_2 & 4;
  uVar4 = param_2 & 0x80;
  if ((param_2 & 0x40U) != 0) {
    param_2 = param_2 | 1;
  }
  iVar1 = 0;
  uVar2 = 1;
  do {
    if (uVar2 == (param_2 & 0xffffff3bU)) break;
    uVar2 = (&DAT_007d4808)[iVar1];
    iVar1 = iVar1 + 1;
  } while (uVar2 != 0);
  if (*(int *)(&UNK_007d4804 + iVar1 * 4) != 0) {
    if (((uVar4 == 0) || ((param_2 & 1U) == 0)) ||
       (_File = _fopen(param_1,"r"), _File == (FILE *)0x0)) {
      _File = _fopen(param_1,*(char **)(iVar1 * 4 + 0x84c5d4));
      if (_File == (FILE *)0x0) {
        return (_iobuf *)0x0;
      }
      if ((uVar3 == 0) || (iVar1 = _fseek(_File,0,2), iVar1 == 0)) {
        return _File;
      }
    }
    _fclose(_File);
  }
  return (_iobuf *)0x0;
}

