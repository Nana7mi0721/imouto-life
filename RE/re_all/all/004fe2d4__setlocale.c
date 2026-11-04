
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _setlocale
   
   Library: Visual Studio 2003 Release */

char * __cdecl _setlocale(int _Category,char *_Locale)

{
  undefined4 *_Memory;
  int iVar1;
  char *local_20;
  undefined1 local_14 [8];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_007d2608;
  uStack_c = 0x4fe2e0;
  if ((_Category < 0) || (5 < _Category)) {
    local_20 = (char *)0x0;
  }
  else {
    __lock(0xc);
    local_8 = (undefined *)0x0;
    if (_Locale == (char *)0x0) {
      local_20 = (char *)__setlocale_lk();
      __local_unwind2(local_14,0xffffffff);
    }
    else {
      _Memory = _malloc(0x54);
      if (_Memory == (undefined4 *)0x0) {
        local_20 = (char *)0x0;
      }
      else {
        local_20 = (char *)__setlocale_lk();
        if (local_20 != (char *)0x0) {
          *_Memory = 0;
          _Memory[1] = DAT_00a1fe10;
          _Memory[2] = DAT_00a1fe14;
          for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
            _Memory[iVar1 + 3] = (&DAT_00a1fdf8)[iVar1];
          }
          _Memory[9] = DAT_0084be50;
          _Memory[10] = DAT_0084be60;
          _Memory[0xb] = DAT_00f488f0;
          _Memory[0xc] = DAT_00f488f4;
          _Memory[0xd] = DAT_00f488ec;
          _Memory[0xe] = PTR_PTR_0084be44;
          _Memory[0xf] = DAT_00a1fdd0;
          _Memory[0x10] = DAT_00f488e8;
          _Memory[0x11] = DAT_00f488e4;
          _Memory[0x12] = PTR_DAT_0084be08;
          _Memory[0x13] = PTR_PTR_0084bd48;
          _Memory[0x14] = DAT_00a1fdcc;
          if ((*(int *)PTR_DAT_0084b52c == 0) && ((undefined4 *)PTR_DAT_0084b52c != &DAT_0084b4d8))
          {
            ___freetlocinfo(PTR_DAT_0084b52c);
          }
          PTR_DAT_0084b52c = (undefined *)_Memory;
          ___updatetlocinfo_lk();
        }
      }
      if ((local_20 == (char *)0x0) && (_Memory != (undefined4 *)0x0)) {
        _free(_Memory);
      }
      local_8 = (undefined *)0xffffffff;
      FUN_004fe41d();
    }
  }
  return local_20;
}

