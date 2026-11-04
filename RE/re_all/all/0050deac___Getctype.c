
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __Getctype
   
   Library: Visual Studio 2003 Release */

_Ctypevec * __cdecl __Getctype(_Ctypevec *__return_storage_ptr__)

{
  uint uVar1;
  LONG *pLVar2;
  int iVar3;
  short *psVar4;
  void *_Src;
  bool bVar5;
  size_t _Size;
  void *local_28;
  wchar_t *local_24;
  
  pLVar2 = (LONG *)FUN_004fd92e();
  InterlockedIncrement(pLVar2);
  iVar3 = FUN_004fd928();
  if (iVar3 != 0) {
    pLVar2 = (LONG *)FUN_004fd92e();
    InterlockedDecrement(pLVar2);
    __lock(0xc);
  }
  iVar3 = ____lc_handle_func();
  uVar1 = *(uint *)(iVar3 + 4);
  psVar4 = (short *)____lc_codepage_func();
  local_28 = _malloc(0x200);
  bVar5 = local_28 == (void *)0x0;
  if (bVar5) {
    local_28 = (void *)FUN_00504a64();
  }
  else {
    _Size = 0x200;
    _Src = (void *)FUN_00504a64();
    _memcpy(local_28,_Src,_Size);
  }
  local_24 = (wchar_t *)(uint)!bVar5;
  FUN_0050df5a();
  __return_storage_ptr__->_Page = uVar1;
  __return_storage_ptr__->_Table = psVar4;
  __return_storage_ptr__->_Delfl = (int)local_28;
  __return_storage_ptr__->_LocaleName = local_24;
  return __return_storage_ptr__;
}

