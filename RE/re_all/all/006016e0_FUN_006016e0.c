
uint FUN_006016e0(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,int *param_5)

{
  int *piVar1;
  HMODULE hModule;
  DWORD DVar2;
  FARPROC pFVar3;
  int iVar4;
  uint uVar5;
  int *unaff_ESI;
  undefined1 uStack00000000;
  
  piVar1 = param_5;
  if (param_5 == (int *)0x0) {
    return 0x80004003;
  }
  *param_5 = 0;
  if (param_3 != 0) {
    return 0x8002802b;
  }
  if (*param_1 == 0) {
    hModule = (HMODULE)FUN_006017f0();
    if (hModule == (HMODULE)0x0) {
      DVar2 = GetLastError();
      return DVar2 | 0x80070000;
    }
    pFVar3 = GetProcAddress(hModule,"LoadRegTypeLib");
    if (pFVar3 == (FARPROC)0x0) {
      DVar2 = GetLastError();
      return DVar2 | 0x80070000;
    }
    iVar4 = (*pFVar3)(&DAT_0085ea94,1,0,param_4,&param_5);
    if (iVar4 < 0) {
      pFVar3 = GetProcAddress(hModule,"LoadTypeLib");
      if (pFVar3 == (FARPROC)0x0) {
        DVar2 = GetLastError();
        return DVar2 | 0x80070000;
      }
      uVar5 = (*pFVar3)(L"control.tlb",&uStack00000000);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
    }
    uVar5 = (**(code **)(*_uStack00000000 + 0x18))(_uStack00000000,unaff_ESI,param_1);
    (**(code **)(*unaff_ESI + 8))(unaff_ESI);
    if ((int)uVar5 < 0) {
      return uVar5;
    }
  }
  *piVar1 = *param_1;
  (**(code **)(*(int *)*param_1 + 4))((int *)*param_1);
  return 0;
}

