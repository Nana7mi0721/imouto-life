
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00513580(void)

{
  ATOM AVar1;
  undefined4 uVar2;
  HWND pHVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  LPRECT lpRect;
  LPPOINT ptVar8;
  int local_b6d4;
  LPCWSTR local_b6cc;
  HICON local_b6c8;
  uint local_b6c4;
  uint local_b674;
  int local_b670;
  int local_b66c;
  tagRECT local_b668;
  int local_b658;
  int local_b654;
  int local_b650;
  int local_b64c;
  int local_b648;
  LARGE_INTEGER local_b644;
  int local_b638;
  LARGE_INTEGER local_b634;
  int local_b628;
  int local_b624;
  _MEMORYSTATUS local_b620;
  FARPROC local_b600;
  undefined4 local_b5fc [2];
  uint local_b5f4;
  int iStack_b5f0;
  uint local_b5ec;
  undefined4 uStack_b5e8;
  int local_b5bc;
  HMODULE local_b5b8;
  WCHAR local_b5b4 [256];
  undefined4 local_b3b4 [2];
  undefined4 local_b3ac;
  undefined4 local_b3a8;
  int local_b3a4;
  int local_b3a0;
  undefined8 local_b39c;
  HWND local_b390;
  undefined4 local_b38c;
  int local_b388;
  undefined4 local_b384;
  int local_b380;
  undefined4 local_b37c;
  int local_b378;
  undefined4 local_b374;
  undefined4 local_b370;
  undefined4 local_b36c;
  int local_b368;
  double local_b364;
  undefined4 local_b358;
  int local_b354;
  int local_b350;
  double local_b34c;
  WNDCLASSEXW local_b344;
  int local_b314;
  int local_b310;
  undefined1 local_b30c [32768];
  undefined4 local_330c;
  undefined4 local_3308;
  undefined4 local_3304;
  int local_3300;
  undefined4 local_32fc;
  undefined4 local_32f8;
  int local_32f4;
  undefined4 local_32f0;
  undefined4 local_32ec;
  int local_32e8;
  undefined4 local_32e4;
  undefined4 local_32e0;
  undefined1 local_32dc [3072];
  undefined1 local_26dc [3072];
  undefined4 local_1adc;
  int local_1ad8;
  int local_1ad4;
  undefined4 local_1ad0;
  undefined4 local_1acc [136];
  undefined1 local_18ac [3072];
  undefined1 local_cac [512];
  HICON local_aac;
  undefined4 local_aa8;
  undefined4 local_aa4;
  undefined4 local_aa0;
  int local_a9c;
  undefined4 local_a98;
  undefined4 local_a94;
  undefined4 local_a90;
  uint local_a8c;
  int local_a88;
  int local_a84;
  undefined4 local_a80;
  int local_a7c;
  undefined4 local_a78;
  int local_a74;
  undefined4 local_a70;
  undefined4 local_a6c;
  undefined4 local_a68;
  undefined4 local_a64;
  undefined4 local_a60;
  undefined4 local_a5c;
  undefined4 local_a58;
  undefined8 local_a54;
  undefined4 local_a48;
  undefined4 local_a44 [648];
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0x51358d;
  local_aa4 = DAT_00a2e8e0;
  local_aa0 = DAT_00a2e8e4;
  local_1adc = DAT_00a2e8d8;
  local_a74 = DAT_00a20c40;
  local_a70 = DAT_00a24d40;
  local_b314 = DAT_00a20c48;
  local_a64 = DAT_00a20c4c;
  local_a80 = DAT_00a20c50;
  local_330c = DAT_00a20c54;
  local_b3ac = DAT_00a20c58;
  local_b3a8 = DAT_00a24d54;
  local_a60 = DAT_00a24d58;
  local_1ad8 = DAT_00a24d60;
  local_a90 = DAT_00a24d68;
  local_3308 = DAT_00a24d6c;
  local_32e4 = DAT_00a24d70;
  local_32e0 = DAT_00a24d78;
  local_1ad4 = DAT_00a20c04;
  local_3304 = DAT_00a20c08;
  local_b374 = DAT_00a20c00;
  local_a8c = _DAT_00a24d48;
  local_aac = DAT_00a24d4c;
  local_a6c = DAT_00a20bf4;
  local_b370 = DAT_00a2e8c4;
  local_b310 = DAT_00a2e8c8;
  local_a9c = DAT_00a238ec;
  local_b384 = DAT_00a2e8e8;
  local_b358 = DAT_00a2ea94;
  local_a88 = DAT_00a2493c;
  local_b380 = DAT_00a2d7c4;
  local_3300 = DAT_00a2d7c8;
  local_b3a4 = DAT_00a2d7cc;
  local_a5c = DAT_00a2d7d0;
  local_a58 = DAT_00a2d7d4;
  local_b36c = DAT_00a2d7d8;
  local_b37c = DAT_00a2d7dc;
  local_20 = DAT_00a2d7e0;
  local_aa8 = DAT_00a2d7e4;
  local_b354 = DAT_00a2d7b4;
  local_1c = DAT_00a2d7b8;
  local_a84 = DAT_00a2d7bc;
  local_b3a0 = DAT_00a2d798;
  local_b350 = DAT_00a2d7b0;
  local_b39c = _DAT_00a2d7a0;
  local_a54 = _DAT_00a2d7a8;
  local_a7c = DAT_00a2d7fc;
  local_18 = DAT_00a2d800;
  local_32fc = DAT_00a210a8;
  local_a98 = DAT_00a21090;
  local_14 = DAT_00a21094;
  local_10 = DAT_00a210a4;
  local_b390 = DAT_00a20bec;
  local_a68 = DAT_00a20bf0;
  local_b378 = DAT_00a20c10;
  local_32f8 = DAT_00a20c14;
  local_1ad0 = DAT_00a2d84c;
  local_32f4 = DAT_00a2e478;
  local_b368 = DAT_00a2e47c;
  local_c = DAT_00a2fa3c;
  local_a78 = DAT_00a2fa40;
  local_b38c = DAT_00a2fa44;
  local_a94 = DAT_00a37a48;
  local_a48 = DAT_00a37a4c;
  puVar6 = &DAT_00a37a50;
  puVar7 = local_1acc;
  for (iVar4 = 0x88; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  FUN_0056d420(local_b30c,&DAT_00a2fa48,0x8000);
  puVar6 = &DAT_00a201c8;
  puVar7 = local_a44;
  for (iVar4 = 0x288; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  local_8 = DAT_00a2e8cc;
  local_24 = DAT_00a2e8d0;
  local_32f0 = DAT_00a2e8d4;
  local_32ec = DAT_00a2e470;
  FUN_0056cf70(local_18ac,0xc00,&DAT_00a23d3c);
  FUN_0056cf70(local_32dc,0xc00,&DAT_00a24940);
  FUN_0056cf70(local_cac,0x200,&DAT_00a24b40);
  FUN_0056cf70(local_26dc,0xc00,&DAT_00a20c5c);
  FUN_0056d380(&DAT_00a201c8,0,0x17aa8);
  FUN_0056cf70(&DAT_00a23d3c,0xc00,local_18ac);
  FUN_0056cf70(&DAT_00a24940,0x200,local_32dc);
  FUN_0056cf70(&DAT_00a24b40,0x200,local_cac);
  FUN_0056cf70(&DAT_00a20c5c,0x400,local_26dc);
  DAT_00a2e8e0 = local_aa4;
  DAT_00a2e8e4 = local_aa0;
  DAT_00a2e8d8 = local_1adc;
  DAT_00a2e8cc = local_8;
  DAT_00a2e8d0 = local_24;
  DAT_00a2e8d4 = local_32f0;
  DAT_00a20c40 = local_a74;
  DAT_00a20c48 = local_b314;
  DAT_00a20c4c = local_a64;
  DAT_00a20c50 = local_a80;
  DAT_00a20c54 = local_330c;
  DAT_00a20c58 = local_b3ac;
  DAT_00a24d54 = local_b3a8;
  DAT_00a24d58 = local_a60;
  DAT_00a24d60 = local_1ad8;
  DAT_00a24d68 = local_a90;
  DAT_00a20c04 = local_1ad4;
  DAT_00a20c08 = local_3304;
  DAT_00a20c00 = local_b374;
  _DAT_00a24d48 = local_a8c;
  DAT_00a24d4c = local_aac;
  DAT_00a20bf4 = local_a6c;
  DAT_00a2e8c4 = local_b370;
  DAT_00a2e8c8 = local_b310;
  DAT_00a24d40 = local_a70;
  DAT_00a238ec = local_a9c;
  DAT_00a2e8e8 = local_b384;
  DAT_00a2ea94 = local_b358;
  DAT_00a2493c = local_a88;
  DAT_00a2d7c4 = local_b380;
  DAT_00a2d7c8 = local_3300;
  DAT_00a2d7cc = local_b3a4;
  DAT_00a2d7d0 = local_a5c;
  DAT_00a2d7d4 = local_a58;
  DAT_00a2d7d8 = local_b36c;
  DAT_00a2d7dc = local_b37c;
  DAT_00a2d7e0 = local_20;
  DAT_00a2d7e4 = local_aa8;
  DAT_00a2d7b4 = local_b354;
  DAT_00a2d7b8 = local_1c;
  DAT_00a2d7bc = local_a84;
  DAT_00a24d6c = local_3308;
  DAT_00a24d70 = local_32e4;
  DAT_00a24d78 = local_32e0;
  DAT_00a2d798 = local_b3a0;
  DAT_00a2d7b0 = local_b350;
  _DAT_00a2d7a0 = local_b39c;
  _DAT_00a2d7a8 = local_a54;
  DAT_00a2d7fc = local_a7c;
  DAT_00a2d800 = local_18;
  DAT_00a210a8 = local_32fc;
  DAT_00a21090 = local_a98;
  DAT_00a21094 = local_14;
  DAT_00a210a4 = local_10;
  DAT_00a20bec = local_b390;
  DAT_00a20bf0 = local_a68;
  DAT_00a20c10 = local_b378;
  DAT_00a20c14 = local_32f8;
  DAT_00a2d84c = local_1ad0;
  DAT_00a2e478 = local_32f4;
  DAT_00a2e47c = local_b368;
  DAT_00a2fa3c = local_c;
  DAT_00a2fa40 = local_a78;
  DAT_00a2fa44 = local_b38c;
  DAT_00a37a48 = local_a94;
  DAT_00a37a4c = local_a48;
  puVar6 = local_1acc;
  puVar7 = &DAT_00a37a50;
  for (iVar4 = 0x88; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  _DAT_00a21084 = 0xffffffff;
  FUN_0056d420(&DAT_00a2fa48,local_b30c,0x8000);
  puVar6 = local_a44;
  puVar7 = &DAT_00a201c8;
  for (iVar4 = 0x288; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  DAT_00a2e470 = local_32ec;
  DAT_00a20be8 = (HINSTANCE)(*DAT_00aba180)(0);
  DAT_00a20c1c = GetCurrentThreadId();
  FUN_0057fa00();
  FUN_0052de90();
  if (DAT_00a24b40 == 0) {
    if (DAT_00a24940 == 0) {
      FUN_0056cf70(&DAT_00a24b40,0x200);
    }
    else {
      FUN_0056cf70(&DAT_00a24b40,0x200);
    }
  }
  if ((0x105 < DAT_00a2e8c8) &&
     (local_b5b8 = LoadLibraryW(L"Kernel32.dll"), local_b5b8 != (HMODULE)0x0)) {
    local_b600 = GetProcAddress(local_b5b8,"GlobalMemoryStatusEx");
    if (local_b600 != (FARPROC)0x0) {
      FUN_0056d380(local_b5fc,0,0x40);
      local_b5fc[0] = 0x40;
      local_b5bc = (*local_b600)();
      FUN_0056bca0(&DAT_007d524c,(double)CONCAT44(iStack_b5f0,local_b5f4) / _DAT_007d5288,
                   (double)CONCAT44(uStack_b5e8,local_b5ec) / _DAT_007d5288);
      _DAT_00a207d0 = local_b5ec;
      _DAT_00a207d4 = uStack_b5e8;
      DAT_00a207d8 = local_b5f4;
      _DAT_00a207dc = iStack_b5f0;
    }
    FreeLibrary(local_b5b8);
  }
  if (DAT_00a207d8 == 0 && _DAT_00a207dc == 0) {
    GlobalMemoryStatus(&local_b620);
    FUN_0056bca0(&DAT_007d524c,(double)local_b620.dwTotalPhys / _DAT_007d5288,
                 (double)local_b620.dwAvailPhys / _DAT_007d5288);
    FUN_0056d310(local_b5b4,0x100,L"%.2fMB\n",(double)local_b620.dwAvailPhys / _DAT_007d5288);
    OutputDebugStringW(local_b5b4);
    _DAT_00a207d0 = local_b620.dwAvailPhys;
    _DAT_00a207d4 = 0;
    DAT_00a207d8 = local_b620.dwTotalPhys;
    _DAT_00a207dc = 0;
  }
  FUN_0050e6b0();
  QueryPerformanceFrequency((LARGE_INTEGER *)&DAT_00a238d8);
  local_b6c4 = (uint)(DAT_00a238d8 != 0 || _DAT_00a238dc != 0);
  DAT_00a238d4 = local_b6c4;
  (*DAT_00aba16c)(local_b3b4,8);
  (*DAT_00aba160)(local_b3b4[0]);
  if (DAT_00a238d4 != 0) {
    FUN_0056bb10(&DAT_007d521c);
    local_b638 = 0;
    local_b628 = 0;
    local_b648 = (*DAT_00aba168)();
    QueryPerformanceCounter(&local_b644);
    local_b64c = (*DAT_00aba168)();
    while (((local_b638 != 0x3c && (local_b628 != 0x3c)) &&
           (iVar4 = (*DAT_00aba168)(), (uint)(iVar4 - local_b64c) < 1000))) {
      QueryPerformanceCounter(&local_b634);
      if ((local_b634.s.LowPart != local_b644.s.LowPart) ||
         (local_b634.s.HighPart != local_b644.s.HighPart)) {
        local_b628 = local_b628 + 1;
        local_b644.s.LowPart = local_b634.s.LowPart;
        local_b644.s.HighPart = local_b634.s.HighPart;
      }
      local_b624 = (*DAT_00aba168)();
      if (local_b624 != local_b648) {
        local_b638 = local_b638 + 1;
        local_b648 = local_b624;
      }
    }
    FUN_0056bca0();
    FUN_0056beb0(&DAT_007d1b94);
    if (local_b628 < local_b638) {
      FUN_0056bca0(&DAT_007d5168,local_b3b4[0]);
      DAT_00a238d4 = 0;
    }
    else {
      FUN_0056bca0();
    }
    FUN_0056beb0(&DAT_007d1b94);
  }
  uVar2 = FUN_00550060(0);
  FUN_005f6b40(uVar2);
  SystemParametersInfoW(0x11,0,(PVOID)0x0,2);
  if (DAT_00a49738 == 0) {
    FUN_0056bb10(&DAT_007d50f4);
    pHVar3 = FindWindowW(&DAT_00a24b40,(LPCWSTR)0x0);
    if (pHVar3 == (HWND)0x0) {
      FUN_0056bb10(&DAT_007d5080);
    }
    else {
      if (DAT_00a238ec == 0) {
        FUN_0056bd30(0x1010002,&DAT_007d50c8);
        DAT_00a21060 = 1;
        FUN_0052ea30();
        return 0xffffffff;
      }
      FUN_0056bb10(&DAT_007d50a4);
    }
    if ((DAT_00a24d60 != 0) && (DAT_00a49738 == 0)) {
      DAT_00a2d284 = 0;
      FUN_0050f0b0(DAT_00a24d58);
    }
    if (DAT_00a20c10 == 1) {
      DAT_00a20c18 = GetWindowLongW(DAT_00a20bec,-4);
    }
    else {
      DAT_00a238e4 = 1;
      FUN_0056d380();
      local_b344.style = 3;
      local_b344.lpfnWndProc = (WNDPROC)&LAB_005120a0;
      local_b344.cbClsExtra = 0;
      local_b344.cbWndExtra = 0;
      local_b344.hInstance = DAT_00a20be8;
      if (DAT_00a24d4c == (HICON)0x0) {
        if (_DAT_00a24d48 == 0) {
          local_b6cc = (LPCWSTR)0x7f00;
        }
        else {
          local_b6cc = (LPCWSTR)(_DAT_00a24d48 & 0xffff);
        }
        local_b6c8 = LoadIconW(DAT_00a20be8,local_b6cc);
      }
      else {
        local_b6c8 = DAT_00a24d4c;
      }
      local_b344.hIcon = local_b6c8;
      local_b344.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
      local_b344.hbrBackground = GetStockObject(5);
      local_b344.lpszMenuName = (LPCWSTR)0x0;
      local_b344.lpszClassName = &DAT_00a24b40;
      local_b344.cbSize = 0x30;
      local_b344.hIconSm = (HICON)0x0;
      FUN_0056bb10(&DAT_007d5058);
      AVar1 = RegisterClassExW(&local_b344);
      if (AVar1 == 0) {
        DAT_00a21060 = 1;
        FUN_0052ea30();
      }
      else {
        FUN_0056bb10(&DAT_007d5040);
      }
      if (DAT_00a2493c == 0) {
        FUN_0056cf70();
      }
      if (DAT_00a20c40 == 0) {
        FUN_0056bb10(&DAT_007d4fcc);
        piVar5 = (int *)((-(uint)(DAT_00a37eec != 0) & _DAT_00a37ef0) * 0x130 + DAT_00a37ef8);
        DAT_00a210ac = 0;
        DAT_00a20bec = (HWND)(*DAT_00aba1c4)(*(undefined4 *)(&DAT_007d4944 + DAT_00a20c04 * 4),
                                             &DAT_00a24b40,&DAT_00a24940,
                                             *(undefined4 *)(&DAT_007d4914 + DAT_00a20c04 * 4),
                                             *piVar5,piVar5[1],*piVar5 + local_32e8,
                                             piVar5[1] + local_b388,0,0,DAT_00a20be8,0);
      }
      else {
        FUN_0056bb10(&DAT_007d5000);
        local_b658 = 0;
        if ((DAT_00a2e478 == 1) || (DAT_00a2e47c == 1)) {
          local_b658 = 0x80000;
        }
        local_b674 = 0;
        if (DAT_00a20c48 == 1) {
          local_b674 = 0x10000;
        }
        if (DAT_00a2d7f8 == 1) {
          local_b674 = local_b674 | 0x10000000;
        }
        if (DAT_00a2d798 == 1) {
          local_b674 = local_b674 | 0x40000;
        }
        DAT_00a210ac = 1;
        if (DAT_00a2d7bc == 1) {
          if (DAT_00a2d7b0 == 0) {
            local_b34c = (double)DAT_00a2d7b4 / (double)local_32e8;
            local_b364 = (double)DAT_00a2d7b8 / (double)local_b388;
            FUN_005119d0(local_b34c,local_b364);
            FUN_0050e8d0(&local_b34c,&local_b364);
            local_32e8 = FUN_0050e240((double)local_32e8 * local_b34c);
            local_b388 = FUN_0050e240((double)local_b388 * local_b364);
          }
          else {
            local_32e8 = DAT_00a2d7b4;
            local_b388 = DAT_00a2d7b8;
          }
        }
        else {
          FUN_0050e8d0(&local_b34c,&local_b364);
          local_32e8 = FUN_0050e240((double)local_32e8 * local_b34c);
          local_b388 = FUN_0050e240((double)local_b388 * local_b364);
        }
        local_b668.left = 0;
        local_b668.top = 0;
        local_b668.right = local_32e8;
        local_b668.bottom = local_b388;
        AdjustWindowRectEx(&local_b668,*(int *)(&DAT_007d48b4 + DAT_00a20c04 * 4) + local_b674,0,
                           *(int *)(&DAT_007d48e4 + DAT_00a20c04 * 4) + local_b658);
        DAT_00a20bfc = -local_b668.top;
        _DAT_00a2d7e8 = -local_b668.left;
        _DAT_00a2d7ec = local_b668.right - local_32e8;
        _DAT_00a2d7f0 = -local_b668.top;
        _DAT_00a2d7f4 = local_b668.bottom - local_b388;
        FUN_0050e7e0(&local_b670,&local_b654,0,0,&local_b650,&local_b66c,0,0);
        local_32e8 = local_b668.right - local_b668.left;
        local_b388 = local_b668.bottom - local_b668.top;
        local_b668.left = (local_b670 - local_32e8) / 2 + local_b650 + local_b668.left;
        local_b668.top = (local_b654 - local_b388) / 2 + local_b66c + local_b668.top;
        local_b668.right = (local_b670 - local_32e8) / 2 + local_b650 + local_b668.right;
        local_b668.bottom = (local_b654 - local_b388) / 2 + local_b66c + local_b668.bottom;
        if (DAT_00a2d7cc == 1) {
          local_b6d4 = DAT_00a2d7c4;
          iVar4 = DAT_00a2d7c8;
        }
        else {
          local_b6d4 = local_b668.left;
          iVar4 = local_b668.top;
        }
        DAT_00a20bec = (HWND)(*DAT_00aba1c4)(*(int *)(&DAT_007d48e4 + DAT_00a20c04 * 4) + local_b658
                                             ,&DAT_00a24b40,&DAT_00a24940,
                                             *(int *)(&DAT_007d48b4 + DAT_00a20c04 * 4) + local_b674
                                             ,local_b6d4,iVar4,local_32e8,local_b388,0,DAT_00a24d58,
                                             DAT_00a20be8,0);
      }
      if (DAT_00a20bec == (HWND)0x0) {
        DAT_00a21060 = 1;
        FUN_0052ea30();
        uVar2 = FUN_0056bd30(0x1010003,&DAT_007d4fa8);
        return uVar2;
      }
      FUN_0056bb10(&DAT_007d4f84);
      if (DAT_00a2d7fc == 0) {
        if (DAT_00a2d800 == 0) {
          FUN_0056bb10(&DAT_007d4f68);
          ShowWindow(DAT_00a20bec,*(int *)(&DAT_007d4884 + DAT_00a20c04 * 4));
          UpdateWindow(DAT_00a20bec);
        }
        else {
          ShowWindow(DAT_00a20bec,6);
          UpdateWindow(DAT_00a20bec);
        }
      }
      else {
        ShowWindow(DAT_00a20bec,0);
      }
      if (DAT_00aba1d8 != (code *)0x0) {
        (*DAT_00aba1d8)(DAT_00a20bec,0);
      }
    }
    DAT_00a21064 = 0;
    DAT_00a21068 = 0;
    DAT_00a21078 = 1;
    if (DAT_00a20c40 == 0) {
      FUN_0056bb10(&DAT_007d4f48);
      SetCursor((HCURSOR)0x0);
    }
    FUN_0056bb10(&DAT_007d4f2c);
    if ((DAT_00a2d800 == 0) && (DAT_00aa7004 == 0)) {
      if (DAT_00aba1bc != (code *)0x0) {
        (*DAT_00aba1bc)(DAT_00a20bec,0);
      }
    }
    else if ((DAT_00aa7004 != 0) && (DAT_00aba1bc != (code *)0x0)) {
      (*DAT_00aba1bc)(DAT_00a20bec,1);
    }
    if (DAT_00a20c40 != 0) {
      lpRect = (LPRECT)&DAT_00a20c30;
      pHVar3 = (HWND)FUN_0050eb30();
      GetClientRect(pHVar3,lpRect);
      ptVar8 = (LPPOINT)&DAT_00a20c30;
      pHVar3 = (HWND)FUN_0050eb30();
      ClientToScreen(pHVar3,ptVar8);
      ptVar8 = (LPPOINT)&DAT_00a20c38;
      pHVar3 = (HWND)FUN_0050eb30();
      ClientToScreen(pHVar3,ptVar8);
    }
    FUN_0050f160(DAT_00a210ac);
    DAT_00a21098 = 0;
    if (DAT_00a20c10 == 0) {
      if ((DAT_00a2d7fc == 0) && (DAT_00a2d800 == 0)) {
        BringWindowToTop(DAT_00a20bec);
      }
      if ((DAT_00a2d7fc == 0) && (DAT_00a2d800 == 0)) {
        FUN_00511c90();
      }
      DAT_00a238e4 = 0;
    }
    DAT_00a2d7cc = 0;
  }
  iVar4 = FUN_00580140(DAT_00a20bf4);
  if (iVar4 < 0) {
    FUN_0056bd30(0x1010004,&DAT_007d4ef0);
    DAT_00a21060 = 1;
    FUN_0052ea30();
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

