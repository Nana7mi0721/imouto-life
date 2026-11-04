
/* Library Function - Single Match
    __free_osfhnd
   
   Library: Visual Studio 2003 Release */

int __cdecl __free_osfhnd(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  DWORD nStdHandle;
  
  if ((uint)param_1 < DAT_00f48b64) {
    iVar3 = (param_1 & 0x1fU) * 0x24;
    piVar1 = (int *)((&DAT_00f48b80)[param_1 >> 5] + iVar3);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_0084b6e4 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_0050a455;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_0050a455:
      *(undefined4 *)(iVar3 + (&DAT_00f48b80)[param_1 >> 5]) = 0xffffffff;
      return 0;
    }
  }
  puVar2 = (undefined4 *)FUN_00501f2f();
  *puVar2 = 9;
  puVar2 = (undefined4 *)FUN_00501f38();
  *puVar2 = 0;
  return -1;
}

