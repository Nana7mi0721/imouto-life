
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0056c2c0(void)

{
  if (DAT_00aba0c8 == (HMODULE)0x0) {
    DAT_00aba0c8 = LoadLibraryW(L"ws2_32.dll");
    DAT_00aba0cc = GetProcAddress(DAT_00aba0c8,"WSAGetLastError");
    _DAT_00aba0d0 = GetProcAddress(DAT_00aba0c8,"WSAStartup");
    DAT_00aba0d4 = GetProcAddress(DAT_00aba0c8,"WSACleanup");
    DAT_00aba0d8 = GetProcAddress(DAT_00aba0c8,"WSAAsyncSelect");
    _DAT_00aba0dc = GetProcAddress(DAT_00aba0c8,"getaddrinfo");
    _DAT_00aba0e0 = GetProcAddress(DAT_00aba0c8,"gethostbyaddr");
    _DAT_00aba0e4 = GetProcAddress(DAT_00aba0c8,"gethostbyname");
    _DAT_00aba0e8 = GetProcAddress(DAT_00aba0c8,"gethostname");
    _DAT_00aba0ec = GetProcAddress(DAT_00aba0c8,"ntohs");
    _DAT_00aba0f0 = GetProcAddress(DAT_00aba0c8,"htons");
    _DAT_00aba0f4 = GetProcAddress(DAT_00aba0c8,"connect");
    _DAT_00aba0f8 = GetProcAddress(DAT_00aba0c8,"socket");
    DAT_00aba0fc = GetProcAddress(DAT_00aba0c8,"send");
    _DAT_00aba100 = GetProcAddress(DAT_00aba0c8,"sendto");
    _DAT_00aba104 = GetProcAddress(DAT_00aba0c8,"recvfrom");
    DAT_00aba108 = GetProcAddress(DAT_00aba0c8,"accept");
    _DAT_00aba10c = GetProcAddress(DAT_00aba0c8,"closesocket");
    _DAT_00aba110 = GetProcAddress(DAT_00aba0c8,"shutdown");
    _DAT_00aba114 = GetProcAddress(DAT_00aba0c8,"listen");
    _DAT_00aba118 = GetProcAddress(DAT_00aba0c8,"bind");
    _DAT_00aba11c = GetProcAddress(DAT_00aba0c8,"inet_addr");
    DAT_00aba120 = GetProcAddress(DAT_00aba0c8,"recv");
    _DAT_00aba124 = GetProcAddress(DAT_00aba0c8,"setsockopt");
  }
  if (DAT_00aba128 == (HMODULE)0x0) {
    DAT_00aba128 = LoadLibraryW(L"Imm32.dll");
    DAT_00aba12c = GetProcAddress(DAT_00aba128,"ImmGetContext");
    DAT_00aba130 = GetProcAddress(DAT_00aba128,"ImmReleaseContext");
    DAT_00aba134 = GetProcAddress(DAT_00aba128,"ImmGetOpenStatus");
    _DAT_00aba138 = GetProcAddress(DAT_00aba128,"ImmGetConversionStatus");
    DAT_00aba13c = GetProcAddress(DAT_00aba128,"ImmNotifyIME");
    DAT_00aba140 = GetProcAddress(DAT_00aba128,"ImmSetOpenStatus");
    DAT_00aba144 = GetProcAddress(DAT_00aba128,"ImmGetCandidateListW");
    _DAT_00aba148 = GetProcAddress(DAT_00aba128,"ImmGetCandidateListCountW");
    DAT_00aba14c = GetProcAddress(DAT_00aba128,"ImmGetCompositionStringW");
    DAT_00aba150 = GetProcAddress(DAT_00aba128,"ImmSetCompositionStringW");
  }
  if (DAT_00aba154 == (HMODULE)0x0) {
    DAT_00aba154 = LoadLibraryW(L"winmm.dll");
    DAT_00aba158 = GetProcAddress(DAT_00aba154,"timeSetEvent");
    DAT_00aba15c = GetProcAddress(DAT_00aba154,"timeKillEvent");
    DAT_00aba160 = GetProcAddress(DAT_00aba154,"timeBeginPeriod");
    DAT_00aba164 = GetProcAddress(DAT_00aba154,"timeEndPeriod");
    DAT_00aba168 = GetProcAddress(DAT_00aba154,"timeGetTime");
    DAT_00aba16c = GetProcAddress(DAT_00aba154,"timeGetDevCaps");
    DAT_00aba170 = GetProcAddress(DAT_00aba154,"joyGetPosEx");
    DAT_00aba174 = GetProcAddress(DAT_00aba154,"joyGetDevCapsW");
    DAT_00aba178 = GetProcAddress(DAT_00aba154,"mciSendCommandW");
  }
  if (DAT_00aba17c == (HMODULE)0x0) {
    DAT_00aba17c = LoadLibraryW(L"kernel32.dll");
    DAT_00aba180 = GetProcAddress(DAT_00aba17c,"GetModuleHandleW");
    DAT_00aba184 = GetProcAddress(DAT_00aba17c,"VerifyVersionInfoW");
    DAT_00aba188 = GetProcAddress(DAT_00aba17c,"VerSetConditionMask");
  }
  if (DAT_00aba18c == (HMODULE)0x0) {
    DAT_00aba18c = LoadLibraryW(L"ole32.dll");
    DAT_00aba190 = GetProcAddress(DAT_00aba18c,"CoCreateInstance");
    DAT_00aba194 = GetProcAddress(DAT_00aba18c,"CoTaskMemAlloc");
    DAT_00aba198 = GetProcAddress(DAT_00aba18c,"CoTaskMemFree");
    DAT_00aba19c = GetProcAddress(DAT_00aba18c,"CoInitializeEx");
    DAT_00aba1a0 = GetProcAddress(DAT_00aba18c,"CoFreeUnusedLibraries");
    DAT_00aba1a4 = GetProcAddress(DAT_00aba18c,"CoUninitialize");
  }
  if (DAT_00aba1a8 == (HMODULE)0x0) {
    DAT_00aba1a8 = LoadLibraryW(L"oleaut32.dll");
    DAT_00aba1ac = GetProcAddress(DAT_00aba1a8,"SysFreeString");
  }
  if (DAT_00aba1b0 == (HMODULE)0x0) {
    DAT_00aba1b0 = LoadLibraryW(L"comctl32.dll");
    if (DAT_00aba1b0 != (HMODULE)0x0) {
      _DAT_00aba1b4 = GetProcAddress(DAT_00aba1b0,"InitCommonControls");
    }
  }
  if (DAT_00aba1b8 == (HMODULE)0x0) {
    DAT_00aba1b8 = LoadLibraryW(L"User32.dll");
    DAT_00aba1bc = GetProcAddress(DAT_00aba1b8,"WINNLSEnableIME");
    DAT_00aba1c0 = GetProcAddress(DAT_00aba1b8,"UpdateLayeredWindow");
    DAT_00aba1c4 = GetProcAddress(DAT_00aba1b8,"CreateWindowExW");
    DAT_00aba1c8 = GetProcAddress(DAT_00aba1b8,"EnumDisplayDevicesW");
    DAT_00aba1e0 = GetProcAddress(DAT_00aba1b8,"ShutdownBlockReasonCreate");
    DAT_00aba1e4 = GetProcAddress(DAT_00aba1b8,"ShutdownBlockReasonDestroy");
    DAT_00aba1e8 = GetProcAddress(DAT_00aba1b8,"SetTimer");
    DAT_00aba1cc = GetProcAddress(DAT_00aba1b8,"CloseTouchInputHandle");
    DAT_00aba1d0 = GetProcAddress(DAT_00aba1b8,"GetTouchInputInfo");
    _DAT_00aba1d4 = GetProcAddress(DAT_00aba1b8,"IsTouchWindow");
    DAT_00aba1d8 = GetProcAddress(DAT_00aba1b8,"RegisterTouchWindow");
    _DAT_00aba1dc = GetProcAddress(DAT_00aba1b8,"UnregisterTouchWindow");
  }
  if (DAT_00aba1ec == (HMODULE)0x0) {
    DAT_00aba1ec = LoadLibraryW(L"gdi32.dll");
    if (DAT_00aba1ec != (HMODULE)0x0) {
      _DAT_00aba1f0 = GetProcAddress(DAT_00aba1ec,"AddFontMemResourceEx");
      _DAT_00aba1f4 = GetProcAddress(DAT_00aba1ec,"RemoveFontMemResourceEx");
      DAT_00aba1f8 = GetProcAddress(DAT_00aba1ec,"GetFontUnicodeRanges");
    }
  }
  if (DAT_00aba1fc == (HMODULE)0x0) {
    DAT_00aba1fc = LoadLibraryW(L"ntdll.dll");
    if (DAT_00aba1fc != (HMODULE)0x0) {
      DAT_00aba200 = GetProcAddress(DAT_00aba1fc,"RtlGetVersion");
    }
  }
  if (DAT_00aba204 == (HMODULE)0x0) {
    DAT_00aba204 = LoadLibraryW(L"Mfplat.dll");
    if (DAT_00aba204 != (HMODULE)0x0) {
      DAT_00aba208 = GetProcAddress(DAT_00aba204,"MFStartup");
      DAT_00aba20c = GetProcAddress(DAT_00aba204,"MFShutdown");
      DAT_00aba210 = GetProcAddress(DAT_00aba204,"MFCreateMediaType");
      DAT_00aba214 = GetProcAddress(DAT_00aba204,"MFCreateWaveFormatExFromMFMediaType");
      DAT_00aba218 = GetProcAddress(DAT_00aba204,"MFCreateAttributes");
      DAT_00aba21c = GetProcAddress(DAT_00aba204,"MFCreateAsyncResult");
      DAT_00aba220 = GetProcAddress(DAT_00aba204,"MFInvokeCallback");
    }
  }
  if (DAT_00aba224 == (HMODULE)0x0) {
    DAT_00aba224 = LoadLibraryW(L"Mfreadwrite.dll");
    if (DAT_00aba224 != (HMODULE)0x0) {
      DAT_00aba228 = GetProcAddress(DAT_00aba224,"MFCreateSourceReaderFromURL");
      DAT_00aba22c = GetProcAddress(DAT_00aba224,"MFCreateSourceReaderFromByteStream");
    }
  }
  if (DAT_00aba230 == (HMODULE)0x0) {
    DAT_00aba230 = LoadLibraryW(L"Propsys.dll");
    if (DAT_00aba230 != (HMODULE)0x0) {
      _DAT_00aba234 = GetProcAddress(DAT_00aba230,"PropVariantToInt64");
    }
  }
  if (DAT_00aba238 == (HMODULE)0x0) {
    DAT_00aba238 = LoadLibraryW(L"dwmapi.dll");
    if (DAT_00aba238 != (HMODULE)0x0) {
      DAT_00aba23c = GetProcAddress(DAT_00aba238,"DwmEnableComposition");
      _DAT_00aba240 = GetProcAddress(DAT_00aba238,"DwmGetWindowAttribute");
    }
  }
  return 0;
}

