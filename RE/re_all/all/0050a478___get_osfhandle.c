
/* Library Function - Single Match
    __get_osfhandle
   
   Library: Visual Studio 2003 Release */

intptr_t __cdecl __get_osfhandle(int _FileHandle)

{
  intptr_t *piVar1;
  undefined4 *puVar2;
  
  if (((uint)_FileHandle < DAT_00f48b64) &&
     (piVar1 = (intptr_t *)((&DAT_00f48b80)[_FileHandle >> 5] + (_FileHandle & 0x1fU) * 0x24),
     (*(byte *)(piVar1 + 1) & 1) != 0)) {
    return *piVar1;
  }
  puVar2 = (undefined4 *)FUN_00501f2f();
  *puVar2 = 9;
  puVar2 = (undefined4 *)FUN_00501f38();
  *puVar2 = 0;
  return -1;
}

