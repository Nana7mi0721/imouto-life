
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _calloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl _calloc(size_t _Count,size_t _Size)

{
  int iVar1;
  uint _Size_00;
  uint dwBytes;
  void *_Dst;
  
  _Size_00 = _Count * _Size;
  dwBytes = _Size_00;
  if (_Size_00 == 0) {
    dwBytes = 1;
  }
  do {
    _Dst = (void *)0x0;
    if (dwBytes < 0xffffffe1) {
      if ((DAT_00f48b60 == 3) && (dwBytes = dwBytes + 0xf & 0xfffffff0, _Size_00 <= DAT_00f48b4c)) {
        __lock(4);
        _Dst = (void *)___sbh_alloc_block(_Size_00);
        FUN_005078de();
        if (_Dst != (void *)0x0) {
          _memset(_Dst,0,_Size_00);
          goto LAB_005078a9;
        }
      }
      else {
LAB_005078a9:
        if (_Dst != (void *)0x0) {
          return _Dst;
        }
      }
      _Dst = HeapAlloc(DAT_00f48b5c,8,dwBytes);
    }
    if ((_Dst != (void *)0x0) || (DAT_00a1fdb4 == 0)) {
      return _Dst;
    }
    iVar1 = __callnewh(dwBytes);
    if (iVar1 == 0) {
      return (void *)0x0;
    }
  } while( true );
}

