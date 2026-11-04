
/* Library Function - Single Match
    _GetLcidFromLanguage
   
   Library: Visual Studio 2003 Release */

void _GetLcidFromLanguage(void)

{
  size_t sVar1;
  
  sVar1 = _strlen(DAT_00a1fdf0);
  DAT_00a1fde0 = (uint)(sVar1 == 3);
  if (sVar1 == 3) {
    DAT_00a1fdec = 2;
  }
  else {
    DAT_00a1fdec = _GetPrimaryLen();
  }
  EnumSystemLocalesA(_LanguageEnumProc_4,1);
  if ((DAT_00a1fdd4 & 4) == 0) {
    DAT_00a1fdd4 = 0;
  }
  return;
}

