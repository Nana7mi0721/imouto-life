
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setvbuf
   
   Library: Visual Studio 2003 Release */

int __cdecl _setvbuf(FILE *_File,char *_Buf,int _Mode,size_t _Size)

{
  int local_20;
  
  local_20 = 0;
  if ((_Mode != 4) && (((_Size < 2 || (0x7fffffff < _Size)) || ((_Mode != 0 && (_Mode != 0x40))))))
  {
    return -1;
  }
  _Size = _Size & 0xfffffffe;
  __lock_file(_File);
  __flush(_File);
  __freebuf(_File);
  *(ushort *)&_File->_flag = (ushort)_File->_flag & 0xc2f3;
  if ((_Mode & 4U) == 0) {
    if (_Buf == (char *)0x0) {
      _Buf = _malloc(_Size);
      if ((int *)_Buf == (int *)0x0) {
        _DAT_00a1fc58 = _DAT_00a1fc58 + 1;
        local_20 = -1;
        goto LAB_004ff99f;
      }
      *(ushort *)&_File->_flag = (ushort)_File->_flag | 0x408;
    }
    else {
      _File->_flag = _File->_flag | 0x500;
    }
  }
  else {
    _File->_flag = _File->_flag | 4;
    _Buf = (char *)&_File->_charbuf;
    _Size = 2;
  }
  _File->_bufsiz = _Size;
  _File->_base = _Buf;
  _File->_ptr = _Buf;
  _File->_cnt = 0;
LAB_004ff99f:
  FUN_004ff9b1();
  return local_20;
}

