
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __lseeki64
   
   Library: Visual Studio 2003 Release */

longlong __cdecl __lseeki64(int _FileHandle,longlong _Offset,int _Origin)

{
  undefined4 *puVar1;
  int iVar2;
  longlong lVar3;
  undefined4 in_stack_00000008;
  
  if ((uint)_FileHandle < DAT_00f48b64) {
    iVar2 = (_FileHandle & 0x1fU) * 0x24;
    if ((*(byte *)((&DAT_00f48b80)[_FileHandle >> 5] + 4 + iVar2) & 1) != 0) {
      __lock_fhandle(_FileHandle);
      if ((*(byte *)((&DAT_00f48b80)[_FileHandle >> 5] + 4 + iVar2) & 1) == 0) {
        puVar1 = (undefined4 *)FUN_00501f2f();
        *puVar1 = 9;
        puVar1 = (undefined4 *)FUN_00501f38();
        *puVar1 = 0;
        lVar3 = -1;
      }
      else {
        lVar3 = __lseeki64_lk(_FileHandle,in_stack_00000008,_Offset);
      }
      FUN_0050a812();
      return lVar3;
    }
  }
  puVar1 = (undefined4 *)FUN_00501f2f();
  *puVar1 = 9;
  puVar1 = (undefined4 *)FUN_00501f38();
  *puVar1 = 0;
  return -1;
}

