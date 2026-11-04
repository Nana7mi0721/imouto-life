
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    _LanguageEnumProc@4
   
   Library: Visual Studio 2003 Release */

uint _LanguageEnumProc_4(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  char local_80 [120];
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  uVar1 = _LcidFromHexString();
  iVar2 = (*DAT_00a1fdf4)(uVar1,(-(uint)(DAT_00a1fde0 != 0) & 0xfffff002) + 0x1001,local_80,0x78);
  if (iVar2 == 0) {
    DAT_00a1fdd4 = 0;
    return 1;
  }
  iVar2 = __stricmp(DAT_00a1fdf0,local_80);
  if (iVar2 == 0) {
    if (DAT_00a1fde0 == 0) {
      uVar3 = 1;
      goto LAB_00505e88;
    }
  }
  else {
    if (((DAT_00a1fde0 != 0) || (DAT_00a1fdec == 0)) ||
       (iVar2 = __strnicmp(DAT_00a1fdf0,local_80,DAT_00a1fdec), iVar2 != 0)) goto LAB_00505ea7;
    uVar3 = 0;
LAB_00505e88:
    iVar2 = _TestDefaultLanguage(uVar1,uVar3);
    if (iVar2 == 0) goto LAB_00505ea7;
  }
  DAT_00a1fdd4 = DAT_00a1fdd4 | 4;
  DAT_00a1fdd8 = uVar1;
  DAT_00a1fddc = uVar1;
LAB_00505ea7:
  return ~(DAT_00a1fdd4 >> 2) & 1;
}

