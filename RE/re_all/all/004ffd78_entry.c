
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int entry(void)

{
  HMODULE pHVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  _OSVERSIONINFOA local_114;
  _STARTUPINFOA local_74;
  int local_30;
  int local_2c;
  undefined4 local_24;
  uint local_20;
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_007d2708;
  uStack_c = 0x4ffd84;
  local_114.szCSDVersion[0x7c] = -0x70;
  local_114.szCSDVersion[0x7d] = -3;
  local_114.szCSDVersion[0x7e] = 'O';
  local_114.szCSDVersion[0x7f] = '\0';
  local_1c = (undefined1 *)&local_114;
  local_114.dwOSVersionInfoSize = 0x94;
  GetVersionExA(&local_114);
  DAT_00a1fbc4 = local_114.dwPlatformId;
  DAT_00a1fbd0 = local_114.dwMajorVersion;
  _DAT_00a1fbd4 = local_114.dwMinorVersion;
  _DAT_00a1fbc8 = local_114.dwBuildNumber & 0x7fff;
  if (local_114.dwPlatformId != 2) {
    _DAT_00a1fbc8 = _DAT_00a1fbc8 | 0x8000;
  }
  _DAT_00a1fbcc = local_114.dwMajorVersion * 0x100 + local_114.dwMinorVersion;
  pHVar1 = GetModuleHandleA((LPCSTR)0x0);
  if (((short)pHVar1->unused == 0x5a4d) &&
     (piVar5 = (int *)((int)&pHVar1->unused + pHVar1[0xf].unused), *piVar5 == 0x4550)) {
    if ((short)piVar5[6] == 0x10b) {
      if (0xe < (uint)piVar5[0x1d]) {
        iVar2 = piVar5[0x3a];
        goto LAB_004ffe39;
      }
    }
    else if (((short)piVar5[6] == 0x20b) && (0xe < (uint)piVar5[0x21])) {
      iVar2 = piVar5[0x3e];
LAB_004ffe39:
      local_20 = (uint)(iVar2 != 0);
      goto LAB_004ffe3f;
    }
  }
  local_20 = 0;
LAB_004ffe3f:
  iVar2 = __heap_init();
  if (iVar2 == 0) {
    fast_error_exit(0x1c);
  }
  iVar2 = __mtinit();
  if (iVar2 == 0) {
    fast_error_exit(0x10);
  }
  __RTC_Initialize();
  local_8 = (undefined *)0x0;
  iVar2 = __ioinit();
  if (iVar2 < 0) {
    __amsg_exit(0x1b);
  }
  DAT_00f49ca4 = GetCommandLineA();
  DAT_00a1fc38 = ___crtGetEnvironmentStringsA();
  iVar2 = __setargv();
  if (iVar2 < 0) {
    __amsg_exit(8);
  }
  iVar2 = __setenvp();
  if (iVar2 < 0) {
    __amsg_exit(9);
  }
  local_2c = __cinit(1);
  if (local_2c != 0) {
    __amsg_exit(local_2c);
  }
  local_74.dwFlags = 0;
  GetStartupInfoA(&local_74);
  uVar3 = __wincmdln();
  if ((local_74.dwFlags & 1) == 0) {
    uVar4 = 10;
  }
  else {
    uVar4 = (uint)local_74.wShowWindow;
  }
  uVar6 = 0;
  local_24 = uVar3;
  pHVar1 = GetModuleHandleA((LPCSTR)0x0);
  iVar2 = FUN_004697e0(pHVar1,uVar6,uVar3,uVar4);
  local_30 = iVar2;
  if (local_20 == 0) {
                    /* WARNING: Subroutine does not return */
    _exit(iVar2);
  }
  __cexit();
  return iVar2;
}

