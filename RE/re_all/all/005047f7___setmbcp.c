
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __setmbcp
   
   Library: Visual Studio 2003 Release */

int __cdecl __setmbcp(int _CodePage)

{
  int *_Memory;
  int iVar1;
  int local_24;
  
  local_24 = -1;
  __lock(0xd);
  DAT_00a1fdc4 = 0;
  if (_CodePage == -2) {
    DAT_00a1fdc4 = 1;
    _CodePage = GetOEMCP();
  }
  else if (_CodePage == -3) {
    DAT_00a1fdc4 = 1;
    _CodePage = GetACP();
  }
  else if (_CodePage == -4) {
    DAT_00a1fdc4 = 1;
    _CodePage = DAT_00a1fe10;
  }
  if (_CodePage == DAT_00f48a24) {
    local_24 = 0;
  }
  else {
    if ((DAT_00f488fc == (int *)0x0) || (_Memory = DAT_00f488fc, *DAT_00f488fc != 0)) {
      _Memory = _malloc(0x220);
    }
    if (_Memory != (int *)0x0) {
      local_24 = __setmbcp_lk(_CodePage);
      if (local_24 == 0) {
        *_Memory = 0;
        _Memory[1] = DAT_00f48a24;
        _Memory[2] = DAT_00f48900;
        _Memory[3] = DAT_00f488f8;
        for (iVar1 = 0; iVar1 < 5; iVar1 = iVar1 + 1) {
          *(undefined2 *)((int)_Memory + iVar1 * 2 + 0x10) = (&DAT_00f48a30)[iVar1];
        }
        for (iVar1 = 0; iVar1 < 0x101; iVar1 = iVar1 + 1) {
          *(undefined1 *)(iVar1 + 0x1c + (int)_Memory) = (&DAT_00f48920)[iVar1];
        }
        for (iVar1 = 0; iVar1 < 0x100; iVar1 = iVar1 + 1) {
          *(undefined1 *)(iVar1 + 0x11d + (int)_Memory) = (&DAT_00f48a40)[iVar1];
        }
        DAT_00f488fc = _Memory;
      }
    }
    if ((local_24 == -1) && (_Memory != DAT_00f488fc)) {
      _free(_Memory);
    }
  }
  FUN_0050493e();
  return local_24;
}

