
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    _LangCountryEnumProc@4
   
   Library: Visual Studio 2003 Release */

uint _LangCountryEnumProc_4(void)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  undefined4 uVar4;
  char local_80 [120];
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  iVar1 = _LcidFromHexString();
  iVar2 = (*DAT_00a1fdf4)(iVar1,(-(uint)(DAT_00a1fde4 != 0) & 0xfffff005) + 0x1002,local_80,0x78);
  if (iVar2 == 0) {
    DAT_00a1fdd4 = 0;
    return 1;
  }
  iVar2 = __stricmp(DAT_00a1fde8,local_80);
  if (iVar2 == 0) {
    iVar2 = (*DAT_00a1fdf4)(iVar1,(-(uint)(DAT_00a1fde0 != 0) & 0xfffff002) + 0x1001,local_80,0x78);
    if (iVar2 == 0) {
      DAT_00a1fdd4 = 0;
      return 1;
    }
    iVar2 = __stricmp(DAT_00a1fdf0,local_80);
    if (iVar2 == 0) {
      DAT_00a1fdd4 = DAT_00a1fdd4 | 0x304;
      DAT_00a1fdd8 = iVar1;
LAB_00505d01:
      DAT_00a1fddc = iVar1;
    }
    else if ((DAT_00a1fdd4 & 2) == 0) {
      if ((DAT_00a1fdec == 0) ||
         (iVar2 = __strnicmp(DAT_00a1fdf0,local_80,DAT_00a1fdec), iVar2 != 0)) {
        if (((DAT_00a1fdd4 & 1) == 0) && (iVar2 = _TestDefaultCountry(iVar1), iVar2 != 0)) {
          DAT_00a1fdd4 = DAT_00a1fdd4 | 1;
          goto LAB_00505d01;
        }
      }
      else {
        DAT_00a1fdd4 = DAT_00a1fdd4 | 2;
        DAT_00a1fddc = iVar1;
        sVar3 = _strlen(DAT_00a1fdf0);
        if (sVar3 == DAT_00a1fdec) {
          DAT_00a1fdd8 = iVar1;
        }
      }
    }
  }
  if ((DAT_00a1fdd4 & 0x300) == 0x300) goto LAB_00505dda;
  iVar2 = (*DAT_00a1fdf4)(iVar1,(-(uint)(DAT_00a1fde0 != 0) & 0xfffff002) + 0x1001,local_80,0x78);
  if (iVar2 == 0) {
    DAT_00a1fdd4 = 0;
    return 1;
  }
  iVar2 = __stricmp(DAT_00a1fdf0,local_80);
  if (iVar2 == 0) {
    DAT_00a1fdd4 = DAT_00a1fdd4 | 0x200;
    if (((DAT_00a1fde0 == 0) && (DAT_00a1fdec != 0)) &&
       (sVar3 = _strlen(DAT_00a1fdf0), sVar3 == DAT_00a1fdec)) {
      uVar4 = 1;
      goto LAB_00505db9;
    }
  }
  else {
    if (((DAT_00a1fde0 != 0) || (DAT_00a1fdec == 0)) ||
       (iVar2 = __strnicmp(DAT_00a1fdf0,local_80,DAT_00a1fdec), iVar2 != 0)) goto LAB_00505dda;
    uVar4 = 0;
LAB_00505db9:
    iVar2 = _TestDefaultLanguage(iVar1,uVar4);
    if (iVar2 == 0) goto LAB_00505dda;
  }
  DAT_00a1fdd4 = DAT_00a1fdd4 | 0x100;
  if (DAT_00a1fdd8 == 0) {
    DAT_00a1fdd8 = iVar1;
  }
LAB_00505dda:
  return ~(DAT_00a1fdd4 >> 2) & 1;
}

