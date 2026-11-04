
/* Library Function - Single Match
    __mtinit
   
   Library: Visual Studio 2003 Release */

int __cdecl __mtinit(void)

{
  int iVar1;
  HMODULE hModule;
  DWORD *pDVar2;
  DWORD DVar3;
  
  iVar1 = __mtinitlocks();
  if (iVar1 == 0) {
    __mtterm();
    return 0;
  }
  hModule = GetModuleHandleA("kernel32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_00a1fc44 = GetProcAddress(hModule,"FlsAlloc");
    DAT_00a1fc48 = GetProcAddress(hModule,"FlsGetValue");
    DAT_00a1fc4c = GetProcAddress(hModule,"FlsSetValue");
    DAT_00a1fc50 = GetProcAddress(hModule,"FlsFree");
    if (DAT_00a1fc48 == (FARPROC)0x0) {
      DAT_00a1fc48 = TlsGetValue_exref;
      DAT_00a1fc4c = TlsSetValue_exref;
      DAT_00a1fc44 = FUN_0050080a;
      DAT_00a1fc50 = TlsFree_exref;
    }
  }
  DAT_0084b6ec = (*DAT_00a1fc44)(__freefls_4);
  if (((DAT_0084b6ec == -1) || (pDVar2 = _calloc(1,0x8c), pDVar2 == (DWORD *)0x0)) ||
     (iVar1 = (*DAT_00a1fc4c)(DAT_0084b6ec,pDVar2), iVar1 == 0)) {
    __mtterm();
    return 0;
  }
  pDVar2[0x15] = (DWORD)&DAT_0084c010;
  pDVar2[5] = 1;
  DVar3 = GetCurrentThreadId();
  pDVar2[1] = 0xffffffff;
  *pDVar2 = DVar3;
  return 1;
}

