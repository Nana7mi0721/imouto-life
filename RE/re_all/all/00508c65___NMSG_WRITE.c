
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */
/* Library Function - Single Match
    __NMSG_WRITE
   
   Library: Visual Studio 2003 Release */

void __cdecl __NMSG_WRITE(int param_1)

{
  int iVar1;
  uint uVar2;
  DWORD DVar3;
  size_t sVar4;
  size_t sVar5;
  HANDLE hFile;
  int iVar6;
  char *_Str;
  undefined4 uStackY_14c;
  UINT aUStackY_148 [3];
  undefined1 auStackY_13c [4];
  undefined4 uStackY_138;
  undefined4 uStackY_134;
  LPCVOID lpBuffer;
  LPDWORD lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  CHAR local_110 [2];
  CHAR aCStack_10e [258];
  undefined1 local_c;
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  uVar2 = 0;
  do {
    if (param_1 == (&DAT_0084c098)[uVar2 * 2]) break;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x13);
  iVar6 = uVar2 * 8;
  if (param_1 == (&DAT_0084c098)[uVar2 * 2]) {
    if ((DAT_00a1fc40 == 1) || ((DAT_00a1fc40 == 0 && (DAT_0084b6e4 == 1)))) {
      lpOverlapped = (LPOVERLAPPED)0x0;
      lpNumberOfBytesWritten = (LPDWORD)&param_1;
      sVar4 = _strlen(*(char **)(iVar6 + 0x84c09c));
      lpBuffer = *(LPCVOID *)(iVar6 + 0x84c09c);
      uStackY_134 = 0x508db9;
      hFile = GetStdHandle(0xfffffff4);
      uStackY_134 = 0x508dc0;
      WriteFile(hFile,lpBuffer,sVar4,lpNumberOfBytesWritten,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      local_c = 0;
      DVar3 = GetModuleFileNameA((HMODULE)0x0,local_110,0x104);
      if (DVar3 == 0) {
        FUN_004fd700();
      }
      _Str = local_110;
      sVar4 = _strlen(_Str);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen(_Str);
        _Str = (char *)((int)aUStackY_148 + (sVar4 - 3));
        _strncpy(_Str,"...",3);
      }
      sVar4 = _strlen(_Str);
      sVar5 = _strlen(*(char **)(iVar6 + 0x84c09c));
      iVar1 = -(sVar4 + sVar5 + 0x1f & 0xfffffffc);
      *(char **)(local_110 + iVar1 + -0x10) = "Runtime Error!\n\nProgram: ";
      *(CHAR **)(local_110 + iVar1 + -0x14) = local_110 + iVar1 + -0xc;
      *(undefined4 *)(auStackY_13c + iVar1 + 0x14) = 0x508d65;
      FUN_004fd700();
      *(char **)(auStackY_13c + iVar1 + 0x14) = _Str;
      *(CHAR **)(auStackY_13c + iVar1 + 0x10) = local_110 + iVar1 + -0xc;
      *(undefined4 *)(auStackY_13c + iVar1 + 0xc) = 0x508d6c;
      FUN_004fd710();
      *(undefined **)(auStackY_13c + iVar1 + 0xc) = &DAT_007d1be8;
      *(CHAR **)(auStackY_13c + iVar1 + 8) = local_110 + iVar1 + -0xc;
      *(undefined4 *)(auStackY_13c + iVar1 + 4) = 0x508d77;
      FUN_004fd710();
      *(undefined4 *)(auStackY_13c + iVar1 + 4) = *(undefined4 *)(iVar6 + 0x84c09c);
      *(CHAR **)(auStackY_13c + iVar1) = local_110 + iVar1 + -0xc;
      *(undefined4 *)((int)aUStackY_148 + iVar1 + 8) = 0x508d83;
      FUN_004fd710();
      *(undefined4 *)((int)aUStackY_148 + iVar1 + 8) = 0x12010;
      *(char **)((int)aUStackY_148 + iVar1 + 4) = "Microsoft Visual C++ Runtime Library";
      *(CHAR **)((int)aUStackY_148 + iVar1) = local_110 + iVar1 + -0xc;
      *(undefined4 *)((int)aUStackY_148 + iVar1 + -4) = 0x508d93;
      ___crtMessageBoxA(*(LPCSTR *)((int)aUStackY_148 + iVar1),
                        *(LPCSTR *)((int)aUStackY_148 + iVar1 + 4),
                        *(UINT *)((int)aUStackY_148 + iVar1 + 8));
    }
  }
  return;
}

