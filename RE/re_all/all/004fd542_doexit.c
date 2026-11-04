
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x004fd5f6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 2003 Release */

void __cdecl doexit(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  UINT uExitCode;
  
  __lock(8);
  if (DAT_00a1fc04 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_00a1fc00 = 1;
  DAT_00a1fbfc = (undefined1)param_3;
  if (param_2 == 0) {
    if (DAT_00f49cb8 != (undefined4 *)0x0) {
      while (DAT_00f49cb4 = DAT_00f49cb4 + -1, DAT_00f49cb8 <= DAT_00f49cb4) {
        if ((code *)*DAT_00f49cb4 != (code *)0x0) {
          (*(code *)*DAT_00f49cb4)();
        }
      }
    }
    __initterm(&DAT_0084b1f0);
  }
  __initterm(&DAT_0084b1fc);
  FUN_004fd5f1();
  if (param_3 == 0) {
    DAT_00a1fc04 = 1;
    ___crtExitProcess(param_1);
    return;
  }
  return;
}

