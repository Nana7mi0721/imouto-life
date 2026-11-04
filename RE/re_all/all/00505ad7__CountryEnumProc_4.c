
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    _CountryEnumProc@4
   
   Library: Visual Studio 2003 Release */

uint _CountryEnumProc_4(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  char local_80 [120];
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  uVar1 = _LcidFromHexString();
  iVar2 = (*DAT_00a1fdf4)(uVar1,(-(uint)(DAT_00a1fde4 != 0) & 0xfffff005) + 0x1002,local_80,0x78);
  if (iVar2 == 0) {
    DAT_00a1fdd4 = 0;
    uVar3 = 1;
  }
  else {
    iVar2 = __stricmp(DAT_00a1fde8,local_80);
    if (iVar2 == 0) {
      iVar2 = _TestDefaultCountry(uVar1);
      if (iVar2 != 0) {
        DAT_00a1fdd4 = DAT_00a1fdd4 | 4;
        DAT_00a1fdd8 = uVar1;
        DAT_00a1fddc = uVar1;
      }
    }
    uVar3 = ~(DAT_00a1fdd4 >> 2) & 1;
  }
  return uVar3;
}

