
/* Library Function - Single Match
    ___get_qualified_locale
   
   Library: Visual Studio 2003 Release */

BOOL __cdecl ___get_qualified_locale(LPLC_STRINGS _LpInStr,UINT *_LpCodePage,LPLC_STRINGS _LpOutStr)

{
  LCID LVar1;
  undefined2 uVar2;
  int iVar3;
  uint _Value;
  BOOL BVar4;
  
  if (DAT_00a1fdf4 == (code *)0x0) {
    if (DAT_00a1fbc4 == 2) {
      DAT_00a1fdf4 = GetLocaleInfoA_exref;
    }
    else {
      DAT_00a1fdf4 = crtGetLocaleInfoA;
    }
  }
  if (_LpInStr == (LPLC_STRINGS)0x0) {
LAB_005060ad:
    _GetLcidFromDefault();
LAB_005060b2:
    if (DAT_00a1fdd4 == 0) {
      return 0;
    }
  }
  else {
    DAT_00a1fde8 = _LpInStr->szLanguage + 0x20;
    DAT_00a1fdf0 = _LpInStr;
    if ((DAT_00a1fde8 != (wchar_t *)0x0) && ((char)*DAT_00a1fde8 != '\0')) {
      _TranslateName(&PTR_s_america_007d37b0,0x16,&DAT_00a1fde8);
    }
    DAT_00a1fdd4 = 0;
    if ((DAT_00a1fdf0 == (LPLC_STRINGS)0x0) || ((char)DAT_00a1fdf0->szLanguage[0] == '\0')) {
      if ((DAT_00a1fde8 == (wchar_t *)0x0) || ((char)*DAT_00a1fde8 == '\0')) goto LAB_005060ad;
      _GetLcidFromCountry();
      goto LAB_005060b2;
    }
    if ((DAT_00a1fde8 == (wchar_t *)0x0) || ((char)*DAT_00a1fde8 == '\0')) {
      _GetLcidFromLanguage();
    }
    else {
      _GetLcidFromLangCountry();
    }
    if (DAT_00a1fdd4 == 0) {
      iVar3 = _TranslateName(&PTR_s_american_007d3960,0x40,&DAT_00a1fdf0);
      if (iVar3 != 0) {
        if ((DAT_00a1fde8 == (wchar_t *)0x0) || ((char)*DAT_00a1fde8 == '\0')) {
          _GetLcidFromLanguage();
        }
        else {
          _GetLcidFromLangCountry();
        }
      }
      goto LAB_005060b2;
    }
  }
  _Value = _ProcessCodePage();
  if (((_Value == 0) || (BVar4 = IsValidCodePage(_Value & 0xffff), BVar4 == 0)) ||
     (BVar4 = IsValidLocale(DAT_00a1fdd8,1), LVar1 = DAT_00a1fdd8, BVar4 == 0)) {
LAB_00506182:
    BVar4 = 0;
  }
  else {
    if (_LpCodePage != (UINT *)0x0) {
      uVar2 = (undefined2)DAT_00a1fddc;
      *(short *)_LpCodePage = (short)DAT_00a1fdd8;
      *(undefined2 *)((int)_LpCodePage + 2) = uVar2;
      *(short *)(_LpCodePage + 1) = (short)_Value;
    }
    if (_LpOutStr != (LPLC_STRINGS)0x0) {
      if ((short)*_LpCodePage == 0x814) {
        FUN_004fd700(_LpOutStr,"Norwegian-Nynorsk");
      }
      else {
        iVar3 = (*DAT_00a1fdf4)(LVar1,0x1001,_LpOutStr,0x40);
        if (iVar3 == 0) goto LAB_00506182;
      }
      iVar3 = (*DAT_00a1fdf4)(DAT_00a1fddc,0x1002,_LpOutStr->szLanguage + 0x20,0x40);
      if (iVar3 == 0) goto LAB_00506182;
      __itoa(_Value,(char *)_LpOutStr->szCountry,10);
    }
    BVar4 = 1;
  }
  return BVar4;
}

