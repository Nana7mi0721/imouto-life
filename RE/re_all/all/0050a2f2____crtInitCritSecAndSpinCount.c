
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___crtInitCritSecAndSpinCount
   
   Library: Visual Studio 2003 Release */

void ___crtInitCritSecAndSpinCount(undefined4 param_1,undefined4 param_2)

{
  HMODULE hModule;
  
  if (DAT_00a20074 == (code *)0x0) {
    if (DAT_00a1fbc4 != 1) {
      hModule = GetModuleHandleA("kernel32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_00a20074 = GetProcAddress(hModule,"InitializeCriticalSectionAndSpinCount");
        if (DAT_00a20074 != (FARPROC)0x0) goto LAB_0050a33e;
      }
    }
    DAT_00a20074 = ___crtInitCritSecNoSpinCount_8;
  }
LAB_0050a33e:
  (*DAT_00a20074)(param_1,param_2);
  return;
}

