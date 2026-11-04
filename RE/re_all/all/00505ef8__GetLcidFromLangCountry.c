
/* Library Function - Single Match
    _GetLcidFromLangCountry
   
   Library: Visual Studio 2003 Release */

void _GetLcidFromLangCountry(void)

{
  size_t sVar1;
  
  sVar1 = _strlen(DAT_00a1fdf0);
  DAT_00a1fde0 = (uint)(sVar1 == 3);
  sVar1 = _strlen(DAT_00a1fde8);
  DAT_00a1fde4 = (uint)(sVar1 == 3);
  DAT_00a1fdd8 = 0;
  if (DAT_00a1fde0 == 0) {
    DAT_00a1fdec = _GetPrimaryLen();
  }
  else {
    DAT_00a1fdec = 2;
  }
  EnumSystemLocalesA(_LangCountryEnumProc_4,1);
  if ((((DAT_00a1fdd4 & 0x100) == 0) || ((DAT_00a1fdd4 & 0x200) == 0)) || ((DAT_00a1fdd4 & 7) == 0))
  {
    DAT_00a1fdd4 = 0;
  }
  return;
}

