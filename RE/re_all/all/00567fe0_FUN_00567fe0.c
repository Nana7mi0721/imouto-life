
undefined4 FUN_00567fe0(void)

{
  int iVar1;
  SIZE_T SVar2;
  HANDLE pvVar3;
  HDC hdc;
  int iVar4;
  DWORD *pDVar5;
  LPCWSTR lpszDeviceName;
  uint uVar6;
  undefined4 *puVar7;
  DWORD DVar8;
  uint local_4c0;
  uint uStack_4bc;
  _OSVERSIONINFOA local_4b8;
  DEVMODEW DStack_424;
  undefined4 local_348;
  WCHAR aWStack_344 [418];
  
  FUN_0056bca0(&DAT_007d6e6c);
  FUN_0056bfd0();
  FUN_0056d380(&local_4b8,0,0x94);
  local_4b8.dwOSVersionInfoSize = 0x94;
  GetVersionExA(&local_4b8);
  if ((local_4b8.dwPlatformId < 2) || (local_4b8.dwMajorVersion < 5)) {
    DAT_00a37ef4 = 1;
    local_4c0 = 1;
  }
  else {
    FUN_0056d380(&local_348,0,0x348);
    local_348 = 0x348;
    DAT_00a37ef4 = 0;
    EnumDisplayMonitors((HDC)0x0,(LPCRECT)0x0,(MONITORENUMPROC)&LAB_00567ea0,0);
    if (DAT_00aba1c8 == (code *)0x0) {
      FUN_0056c2c0();
    }
    uVar6 = 0;
    local_4c0 = 0;
    iVar1 = (*DAT_00aba1c8)(0,0,&local_348,0);
    if (iVar1 != 0) {
      do {
        uVar6 = uVar6 + 1;
        iVar1 = (*DAT_00aba1c8)(0,uVar6,&local_348,0);
      } while (iVar1 != 0);
      local_4c0 = uVar6;
    }
  }
  FUN_0056bca0(&DAT_007d6e34,DAT_00a37ef4,local_4c0);
  SVar2 = DAT_00a37ef4 * 0x130;
  DVar8 = 0;
  pvVar3 = GetProcessHeap();
  DAT_00a37ef8 = HeapAlloc(pvVar3,DVar8,SVar2);
  if (DAT_00a37ef8 == (undefined4 *)0x0) {
    FUN_0056bca0(&DAT_007d6df8);
    FUN_0056bfe0();
    return 0xffffffff;
  }
  FUN_0056d380(DAT_00a37ef8,0,DAT_00a37ef4 * 0x130);
  puVar7 = DAT_00a37ef8;
  if ((local_4b8.dwPlatformId < 2) || (local_4b8.dwMajorVersion < 5)) {
    hdc = GetDC((HWND)0x0);
    iVar1 = GetDeviceCaps(hdc,8);
    puVar7[4] = iVar1;
    iVar1 = GetDeviceCaps(hdc,10);
    puVar7[5] = iVar1;
    puVar7[6] = puVar7[4];
    puVar7[7] = iVar1;
    iVar1 = GetDeviceCaps(hdc,0xe);
    iVar4 = GetDeviceCaps(hdc,0xc);
    puVar7[8] = iVar1 * iVar4;
    iVar1 = GetDeviceCaps(hdc,0x74);
    puVar7[9] = iVar1;
    ReleaseDC((HWND)0x0,hdc);
    *puVar7 = 0;
    puVar7[1] = 0;
    puVar7[2] = puVar7[4];
    puVar7[3] = puVar7[5];
    FUN_0056cf10(puVar7 + 10,L"DISPLAY");
    FUN_0056bca0(&DAT_007d6d80,0,puVar7 + 10,puVar7[4],puVar7[5],puVar7[8],puVar7[9]);
  }
  else {
    DAT_00a37ef4 = 0;
    EnumDisplayMonitors((HDC)0x0,(LPCRECT)0x0,(MONITORENUMPROC)&LAB_00567ea0,0);
  }
  uStack_4bc = 0;
  if (local_4c0 != 0) {
    do {
      if ((local_4b8.dwPlatformId < 2) || (local_4b8.dwMajorVersion < 5)) {
        lpszDeviceName = (LPCWSTR)0x0;
        puVar7 = DAT_00a37ef8;
LAB_0056827f:
        uVar6 = 0;
        puVar7[0x4a] = 0;
        FUN_0056d380(&DStack_424,0,0xdc);
        iVar1 = EnumDisplaySettingsW(lpszDeviceName,0,&DStack_424);
        while (iVar1 != 0) {
          if (0xf < DStack_424.dmBitsPerPel) {
            puVar7[0x4a] = puVar7[0x4a] + 1;
          }
          uVar6 = uVar6 + 1;
          FUN_0056d380(&DStack_424,0,0xdc);
          iVar1 = EnumDisplaySettingsW(lpszDeviceName,uVar6,&DStack_424);
        }
        SVar2 = puVar7[0x4a] << 4;
        DVar8 = 0;
        pvVar3 = GetProcessHeap();
        pDVar5 = HeapAlloc(pvVar3,DVar8,SVar2);
        puVar7[0x4b] = pDVar5;
        if (pDVar5 == (DWORD *)0x0) {
          puVar7[0x4a] = 0;
          return 0xffffffff;
        }
        DVar8 = 0;
        if (uVar6 != 0) {
          do {
            FUN_0056d380(&DStack_424,0,0xdc);
            EnumDisplaySettingsW(lpszDeviceName,DVar8,&DStack_424);
            if (0xf < DStack_424.dmBitsPerPel) {
              *pDVar5 = DStack_424.dmPelsWidth;
              pDVar5[1] = DStack_424.dmPelsHeight;
              pDVar5[2] = DStack_424.dmBitsPerPel;
              pDVar5[3] = DStack_424.dmDisplayFrequency;
              pDVar5 = pDVar5 + 4;
            }
            DVar8 = DVar8 + 1;
          } while (DVar8 < uVar6);
        }
      }
      else {
        (*DAT_00aba1c8)(0,uStack_4bc,&local_348,0);
        uVar6 = 0;
        lpszDeviceName = aWStack_344;
        puVar7 = DAT_00a37ef8;
        if (DAT_00a37ef4 != 0) {
          do {
            iVar1 = FUN_0056d130(puVar7 + 10,aWStack_344);
            if (iVar1 == 0) break;
            uVar6 = uVar6 + 1;
            puVar7 = puVar7 + 0x4c;
          } while (uVar6 < DAT_00a37ef4);
        }
        if (uVar6 != DAT_00a37ef4) goto LAB_0056827f;
      }
      uStack_4bc = uStack_4bc + 1;
    } while (uStack_4bc < local_4c0);
  }
  FUN_0056bfe0();
  FUN_0056bca0(&DAT_007d6dc4);
  return 0;
}

