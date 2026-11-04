
/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 2003 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  int iVar2;
  undefined1 local_14 [8];
  byte local_c;
  undefined1 local_8 [4];
  
  iVar2 = 0;
  if (DAT_00a2005c == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if ((hModule == (HMODULE)0x0) ||
       (DAT_00a2005c = GetProcAddress(hModule,"MessageBoxA"), DAT_00a2005c == (FARPROC)0x0)) {
      return 0;
    }
    DAT_00a20060 = GetProcAddress(hModule,"GetActiveWindow");
    DAT_00a20064 = GetProcAddress(hModule,"GetLastActivePopup");
    if ((DAT_00a1fbc4 == 2) &&
       (DAT_00a2006c = GetProcAddress(hModule,"GetUserObjectInformationA"),
       DAT_00a2006c != (FARPROC)0x0)) {
      DAT_00a20068 = GetProcAddress(hModule,"GetProcessWindowStation");
    }
  }
  if ((DAT_00a20068 == (FARPROC)0x0) ||
     (((iVar1 = (*DAT_00a20068)(), iVar1 != 0 &&
       (iVar1 = (*DAT_00a2006c)(iVar1,1,local_14,0xc,local_8), iVar1 != 0)) && ((local_c & 1) != 0))
     )) {
    if (((DAT_00a20060 != (FARPROC)0x0) && (iVar2 = (*DAT_00a20060)(), iVar2 != 0)) &&
       (DAT_00a20064 != (FARPROC)0x0)) {
      iVar2 = (*DAT_00a20064)(iVar2);
    }
  }
  else if (DAT_00a1fbd0 < 4) {
    _UType = _UType | 0x40000;
  }
  else {
    _UType = _UType | 0x200000;
  }
  iVar2 = (*DAT_00a2005c)(iVar2,_LpText,_LpCaption,_UType);
  return iVar2;
}

