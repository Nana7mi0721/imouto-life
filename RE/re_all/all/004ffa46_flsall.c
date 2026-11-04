
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _flsall
   
   Library: Visual Studio 2003 Release */

int __cdecl flsall(int param_1)

{
  void *_File;
  int iVar1;
  int _Index;
  int local_28;
  int local_20;
  
  local_20 = 0;
  local_28 = 0;
  __lock(1);
  for (_Index = 0; _Index < DAT_00f49ca0; _Index = _Index + 1) {
    _File = *(void **)(DAT_00f48c80 + _Index * 4);
    if ((_File != (void *)0x0) && ((*(byte *)((int)_File + 0xc) & 0x83) != 0)) {
      __lock_file2(_Index,_File);
      iVar1 = *(int *)(DAT_00f48c80 + _Index * 4);
      if ((*(uint *)(iVar1 + 0xc) & 0x83) != 0) {
        if (param_1 == 1) {
          iVar1 = __fflush_lk(iVar1);
          if (iVar1 != -1) {
            local_20 = local_20 + 1;
          }
        }
        else if ((param_1 == 0) && ((*(uint *)(iVar1 + 0xc) & 2) != 0)) {
          iVar1 = __fflush_lk(iVar1);
          if (iVar1 == -1) {
            local_28 = -1;
          }
        }
      }
      FUN_004ffae6();
    }
  }
  FUN_004ffb12();
  if (param_1 != 1) {
    local_20 = local_28;
  }
  return local_20;
}

