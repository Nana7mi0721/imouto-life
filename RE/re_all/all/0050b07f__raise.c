
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _raise
   
   Library: Visual Studio 2003 Release */

int __cdecl _raise(int _SigNum)

{
  int iVar1;
  void *extraout_ECX;
  void *_File;
  undefined4 *puVar2;
  code *pcVar3;
  void *local_34;
  void *local_30;
  _ptiddata local_28;
  void *local_20;
  
  local_20 = (void *)0x0;
  if (_SigNum == 2) {
    puVar2 = &DAT_00a20080;
    pcVar3 = DAT_00a20080;
LAB_0050b10c:
    local_20 = (void *)0x1;
  }
  else {
    if (((_SigNum != 4) && (_SigNum != 8)) && (_SigNum != 0xb)) {
      if (_SigNum == 0xf) {
        puVar2 = &DAT_00a2008c;
        pcVar3 = DAT_00a2008c;
      }
      else if (_SigNum == 0x15) {
        puVar2 = &DAT_00a20084;
        pcVar3 = DAT_00a20084;
      }
      else {
        if (_SigNum != 0x16) {
          return -1;
        }
        puVar2 = &DAT_00a20088;
        pcVar3 = DAT_00a20088;
      }
      goto LAB_0050b10c;
    }
    local_28 = __getptd();
    iVar1 = siglookup();
    puVar2 = (undefined4 *)(iVar1 + 8);
    pcVar3 = (code *)*puVar2;
  }
  _File = (void *)0x0;
  if (pcVar3 == (code *)0x1) {
    return 0;
  }
  if (pcVar3 == (code *)0x0) {
    __exit(3);
    _File = extraout_ECX;
  }
  if (local_20 != _File) {
    __lock((int)_File);
    _File = (void *)0x0;
  }
  if (((_SigNum == 8) || (_SigNum == 0xb)) || (_SigNum == 4)) {
    local_30 = local_28->_initarg;
    local_28->_initarg = _File;
    if (_SigNum == 8) {
      local_34 = local_28->_pxcptacttab;
      local_28->_pxcptacttab = (void *)0x8c;
      goto LAB_0050b16b;
    }
  }
  else {
LAB_0050b16b:
    if (_SigNum == 8) {
      for (iVar1 = DAT_0084c088; iVar1 < DAT_0084c08c + DAT_0084c088; iVar1 = iVar1 + 1) {
        *(void **)((int)local_28->_initaddr + iVar1 * 0xc + 8) = _File;
      }
      goto LAB_0050b199;
    }
  }
  *puVar2 = _File;
LAB_0050b199:
  FUN_0050b1ba();
  if (_SigNum == 8) {
    (*pcVar3)(8,local_28->_pxcptacttab);
  }
  else {
    (*pcVar3)(_SigNum);
    if ((_SigNum != 0xb) && (_SigNum != 4)) {
      return 0;
    }
  }
  local_28->_initarg = local_30;
  if (_SigNum == 8) {
    local_28->_pxcptacttab = local_34;
  }
  return 0;
}

