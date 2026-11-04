
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __read
   
   Library: Visual Studio 2003 Release */

int __cdecl __read(int _FileHandle,void *_DstBuf,uint _MaxCharCount)

{
  undefined4 *puVar1;
  int iVar2;
  int local_20;
  
  if ((uint)_FileHandle < DAT_00f48b64) {
    iVar2 = (_FileHandle & 0x1fU) * 0x24;
    if ((*(byte *)((&DAT_00f48b80)[_FileHandle >> 5] + 4 + iVar2) & 1) != 0) {
      __lock_fhandle(_FileHandle);
      if ((*(byte *)((&DAT_00f48b80)[_FileHandle >> 5] + 4 + iVar2) & 1) == 0) {
        puVar1 = (undefined4 *)FUN_00501f2f();
        *puVar1 = 9;
        puVar1 = (undefined4 *)FUN_00501f38();
        *puVar1 = 0;
        local_20 = -1;
      }
      else {
        local_20 = __read_lk(_FileHandle,_DstBuf,_MaxCharCount);
      }
      FUN_00502419();
      return local_20;
    }
  }
  puVar1 = (undefined4 *)FUN_00501f2f();
  *puVar1 = 9;
  puVar1 = (undefined4 *)FUN_00501f38();
  *puVar1 = 0;
  return -1;
}

