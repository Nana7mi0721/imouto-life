// anchor: *.ttf

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00469820(undefined4 param_1,undefined4 param_2,char *param_3)

{
  POINT pt;
  char cVar1;
  int iVar2;
  char *pcVar3;
  LPCSTR pCVar4;
  BOOL BVar5;
  LPCSTR pCVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined1 *puStack_13a50;
  undefined1 *puStack_13a4c;
  undefined1 *puStack_13a48;
  undefined1 *puStack_13a44;
  undefined1 *puStack_13a40;
  undefined1 *puStack_13a3c;
  undefined4 uStack_13a38;
  undefined1 *puStack_13a30;
  undefined4 uStack_13a18;
  undefined4 *puStack_13a14;
  undefined1 *puStack_13a10;
  UINT UVar9;
  CMiniDockFrameWnd local_f800 [4816];
  undefined1 *local_e530;
  undefined1 *local_e51c;
  undefined1 *local_e518;
  undefined1 *local_e514;
  undefined4 local_e510;
  undefined1 *local_e50c;
  undefined1 *local_e508;
  void *local_e504;
  undefined1 *local_e500;
  undefined1 *local_e4fc;
  undefined1 *local_e4f8;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_e4f4 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_e4d8 [28];
  undefined1 *local_e4bc;
  LPSTR local_e4b8;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_e4b4 [28];
  undefined1 *local_e498;
  undefined1 *local_e494;
  undefined1 *local_e490;
  int local_e48c;
  int local_e488;
  char *local_e484;
  int local_e480;
  int local_e47c;
  tagMONITORINFO local_e478;
  void *local_e430;
  int local_e42c;
  undefined4 local_e428;
  HMONITOR local_e424;
  tagPOINT local_e420;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_e418 [28];
  undefined4 local_e3fc;
  int local_e3f8;
  int local_e3f4;
  HANDLE local_e3f0;
  int local_e3ec;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_3f30 [28];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_3f14 [28];
  undefined4 local_3ef8;
  int local_3ef4;
  _WIN32_FIND_DATAA local_3ef0;
  char local_3dad;
  undefined4 local_3dac;
  char local_3da8 [512];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_3ba8 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_3b8c [28];
  char *local_3b70;
  int local_3b6c;
  HDC local_3b68;
  int local_3b64;
  char local_3b60 [512];
  char local_3960 [516];
  LPSTR local_375c;
  uint local_3758;
  char local_3754 [24];
  int local_373c;
  char local_3738 [256];
  char local_3638 [512];
  char local_3438 [256];
  undefined1 local_3338 [256];
  undefined1 local_3238 [256];
  undefined1 local_3138 [256];
  undefined1 local_3038 [256];
  undefined1 local_2f38 [256];
  undefined1 local_2e38 [256];
  undefined1 local_2d38 [256];
  undefined1 local_2c38 [256];
  undefined1 local_2b38 [256];
  undefined1 local_2a38 [256];
  undefined1 local_2938 [256];
  undefined1 local_2838 [256];
  undefined1 local_2738 [256];
  undefined1 local_2638 [256];
  undefined1 local_2538 [256];
  undefined1 local_2438 [256];
  undefined1 local_2338 [256];
  undefined1 local_2238 [256];
  undefined1 local_2138 [256];
  undefined1 local_2038 [256];
  undefined1 local_1f38 [256];
  undefined1 local_1e38 [256];
  undefined1 local_1d38 [256];
  undefined1 local_1c38 [256];
  undefined1 local_1b38 [256];
  undefined1 local_1a38 [256];
  undefined1 local_1938 [256];
  undefined1 local_1838 [256];
  undefined1 local_1738 [256];
  undefined1 local_1638 [256];
  undefined1 local_1538 [256];
  undefined1 local_1438 [256];
  undefined1 local_1338 [256];
  undefined local_1238 [512];
  undefined1 local_1038 [1536];
  undefined1 local_a38 [256];
  undefined4 local_938 [64];
  undefined1 local_838 [1536];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_238 [28];
  int local_21c;
  CHAR local_218 [516];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae6c4;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a143b8,
             param_3);
  basic_string<>();
  local_8 = 0;
  DAT_00a117a8 = 0;
  DAT_00a0f81c = param_1;
  if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
    puStack_13a10 = local_838;
    puStack_13a14 = local_938;
    uStack_13a18 = local_a38;
    puStack_13a30 = local_1038;
    uStack_13a38 = local_1238;
    puStack_13a3c = local_1338;
    puStack_13a40 = local_1438;
    puStack_13a44 = local_1538;
    puStack_13a48 = local_1638;
    puStack_13a4c = local_1738;
    puStack_13a50 = local_1838;
    _sscanf(param_3,
            "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s"
            ,local_3438,local_3338,local_3238,local_3138,local_3038,local_2f38,local_2e38,local_2d38
            ,local_2c38,local_2b38,local_2a38,local_2938,local_2838,local_2738,local_2638,local_2538
            ,local_2438,local_2338,local_2238,local_2138,local_2038,local_1f38,local_1e38,local_1d38
            ,local_1c38,local_1b38,local_1a38,local_1938);
    for (local_3b6c = 0; local_3b6c < 0x28; local_3b6c = local_3b6c + 1) {
      local_3b70 = local_3438 + local_3b6c * 0x100;
      iVar2 = _strcmp(local_3438 + local_3b6c * 0x100,"");
      if (iVar2 == 0) break;
      iVar2 = _strcmp(local_3438 + local_3b6c * 0x100,"Test_Of_Main");
      if (iVar2 == 0) {
        DAT_00a117a8 = 1;
      }
      iVar2 = _strcmp(local_3438 + local_3b6c * 0x100,"-b");
      if (iVar2 == 0) {
        local_3b6c = local_3b6c + 1;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a14c34,
                   local_3438 + local_3b6c * 0x100);
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a14c34,
                   "/");
      }
    }
  }
  FUN_0056c000();
  local_3b68 = GetDC((HWND)0x0);
  iVar2 = GetDeviceCaps(local_3b68,0xe);
  local_21c = GetDeviceCaps(local_3b68,0xc);
  local_21c = iVar2 * local_21c;
  ReleaseDC((HWND)0x0,local_3b68);
  FUN_0056b2c0();
  FUN_0050eac0();
  FUN_00516940();
  DAT_0084b240 = 1;
  GetModuleFileNameA((HMODULE)0x0,local_218,0x400);
  puStack_13a10 = (undefined1 *)0x469bac;
  __splitpath(local_218,local_3b60,local_3960,(char *)0x0,(char *)0x0);
  _sprintf(local_3638,"%s%s");
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a14b78,
             local_3638);
  local_3b64 = 4;
  while (local_3b64 = FUN_004cbbc0(), local_3b64 != -1) {
    FUN_004cbb30();
    iVar2 = FUN_0046f680();
    if (iVar2 == 0) {
      FUN_004cba30();
    }
    local_3b64 = local_3b64 + 1;
  }
  FUN_004cbb30();
  FUN_004cbb30();
  _sprintf(local_3638,"%s%s");
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a14c70,
             local_3638);
  if (DAT_00a117a8 != 0) {
    _memset(&DAT_00a0f850,8000,0);
  }
  FUN_004cbb30();
  FUN_004cbb30();
  puStack_13a10 = (undefined1 *)0x469cdc;
  _sprintf(local_3738,"%s%sBasicData/%s");
  FUN_0052e940();
  FUN_0042b080();
  puStack_13a10 = (undefined1 *)0x4f;
  puStack_13a14 = (undefined4 *)0x72;
  uStack_13a18 = (char *)0x28;
  puStack_13a30 = (undefined1 *)0x469d15;
  _sprintf(local_3754,"%c%c%c%c%c%c%c%c%c%c%c");
  FUN_0052db00();
  thunk_FUN_00570070();
  cVar1 = FUN_004b9e90();
  if (cVar1 == '\0') {
    puStack_13a10 = (undefined1 *)0xffffff9b;
    puStack_13a14 = (undefined4 *)0x28;
    uStack_13a18 = (char *)0xffffffb7;
    puStack_13a30 = (undefined1 *)0x469d77;
    _sprintf(local_3754,"%c%c%c%c%c%c%c%c%c%c%c");
    thunk_FUN_00570070();
    cVar1 = FUN_004b9e90();
    if (cVar1 == '\0') {
      puStack_13a10 = (undefined1 *)0x3e;
      puStack_13a14 = (undefined4 *)0xffffffe1;
      uStack_13a18 = (char *)0x53;
      _sprintf(local_3754,"%c%c%c%c%c%c%c%c%c");
      thunk_FUN_00570070();
    }
  }
  local_3758 = 1;
  DAT_0084b218 = 1;
  cVar1 = FUN_004b9e90();
  if (cVar1 == '\0') {
    local_e490 = (undefined1 *)&puStack_13a14;
    uStack_13a18 = &DAT_007d022b;
    basic_string<>();
    local_8._0_1_ = 1;
    uStack_13a18 = (char *)0x0;
    local_e494 = (undefined1 *)((int)register0x00000010 + -0x13a34);
    uStack_13a38 = &DAT_007d022c;
    puStack_13a3c = (undefined1 *)0x469e48;
    basic_string<>();
    local_8._0_1_ = 2;
    local_e498 = (undefined1 *)&puStack_13a50;
    basic_string<>(&DAT_007d0231);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0041a570(local_e4b4);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_e4b4);
  }
  cVar1 = FUN_004b9ed0();
  if (cVar1 == '\0') {
    FUN_004cbb30();
    _sprintf(local_3738,"%s%s");
    local_3758 = FUN_004b9ed0();
    local_3758 = local_3758 & 0xff;
    if (local_3758 == 0) {
      FUN_004cbb30();
      FUN_004cbb30();
      puStack_13a10 = (undefined1 *)0x469f30;
      _sprintf(local_3738,"%s%sBasicData/%s");
      FUN_004b9ed0();
    }
  }
  if (*DAT_00a16714 < 0xd3) {
    FUN_00551410();
  }
  else {
    FUN_00551410();
  }
  local_375c = (LPSTR)0x0;
  local_373c = GetLocaleInfoA(0x800,0x1001,(LPSTR)0x0,0);
  if (0 < local_373c) {
    local_e4b8 = operator_new(local_373c + 1);
    local_375c = local_e4b8;
    _memset(local_e4b8,0,local_373c + 1);
    GetLocaleInfoA(0x800,0x1001,local_375c,local_373c + 1);
  }
  basic_string<>();
  local_8._0_1_ = 3;
  basic_string<>();
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004cb840();
  switch(*DAT_00a166b8) {
  case 2:
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              (local_3ba8,"Korean");
    break;
  case 3:
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              (local_3ba8,"Chinese (Traditional)");
    break;
  case 4:
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              (local_3ba8,"Chinese (Simplified)");
    break;
  case 0xff:
  case 0:
  case 1:
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_3ba8,"");
  }
  cVar1 = operator!=<>();
  if ((cVar1 != '\0') && (iVar2 = AddRequestHeaders(), iVar2 == DAT_007d0624)) {
    FUN_004cbb30();
    FUN_004cbb30();
    FUN_004cbb30();
    local_e4bc = (undefined1 *)((int)register0x00000010 + -0x13a20);
    basic_string<>();
    pcVar3 = (char *)FUN_00401c50();
    puStack_13a10 = (undefined1 *)0x46a14a;
    _sprintf(local_3da8,pcVar3);
    MessageBoxA((HWND)0x0,local_3da8,"Warning!",0);
  }
  cVar1 = operator!=<>();
  if ((cVar1 != '\0') && (cVar1 = operator!=<>(), cVar1 != '\0')) {
    DAT_0084b218 = 1;
  }
  local_8._0_1_ = 3;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3b8c);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_3ba8
            );
  if (local_3758 == 0) {
LAB_0046b5eb:
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_238);
  }
  else {
    FUN_004cc250();
    pCVar4 = (LPCSTR)FUN_004cbb30();
    SetCurrentDirectoryA(pCVar4);
    for (local_e3f4 = 0; local_e3f4 < 2; local_e3f4 = local_e3f4 + 1) {
      if (local_e3f4 == 0) {
        local_e3f0 = FindFirstFileA("*.ttf",&local_3ef0);
      }
      if (local_e3f4 == 1) {
        local_e3f0 = FindFirstFileA("*.ttc",&local_3ef0);
      }
      if (local_e3f0 != (HANDLE)0xffffffff) {
        do {
          basic_string<>();
          local_8._0_1_ = 5;
          FUN_004cc500();
          local_8 = (uint)local_8._1_3_ << 8;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_e4d8);
          AddFontResourceExA(local_3ef0.cFileName,0x10,(PVOID)0x0);
          BVar5 = FindNextFileA(local_e3f0,&local_3ef0);
        } while (BVar5 != 0);
        FindClose(local_e3f0);
      }
    }
    SetCurrentDirectoryA(local_3638);
    basic_string<>();
    local_8 = CONCAT31(local_8._1_3_,6);
    for (local_e3f8 = 0; local_e3f8 < 2; local_e3f8 = local_e3f8 + 1) {
      if (local_e3f8 == 0) {
        local_e3f0 = FindFirstFileA("*.ttf",&local_3ef0);
      }
      if (local_e3f8 == 1) {
        local_e3f0 = FindFirstFileA("*.ttc",&local_3ef0);
      }
      if (local_e3f0 != (HANDLE)0xffffffff) {
        do {
          pcVar3 = (char *)FUN_004cbb30();
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                    (local_3f30,pcVar3);
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                    (local_3f30,local_3ef0.cFileName);
          FUN_004cbb30();
          basic_string<>();
          local_8._0_1_ = 7;
          FUN_004cc500();
          local_8 = CONCAT31(local_8._1_3_,6);
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_e4f4);
          AddFontResourceExA(local_3ef0.cFileName,0x10,(PVOID)0x0);
          BVar5 = FindNextFileA(local_e3f0,&local_3ef0);
        } while (BVar5 != 0);
        FindClose(local_e3f0);
      }
    }
    pCVar4 = (LPCSTR)FUN_004cbb30();
    SetCurrentDirectoryA(pCVar4);
    FUN_0050eab0();
    if (*DAT_00a166b0 < '\x04') {
      cVar1 = '\x04';
    }
    else {
      cVar1 = *DAT_00a166b0;
    }
    *DAT_00a166b0 = cVar1;
    if (*DAT_00a166b4 < '\x04') {
      cVar1 = '\x04';
    }
    else {
      cVar1 = *DAT_00a166b4;
    }
    *DAT_00a166b4 = cVar1;
    DAT_00a117b0 = 1;
    local_3dac = 0x20;
    if (local_21c == 0x10) {
      local_3dac = 0x10;
    }
    DAT_0084b248 = 1;
    if (*DAT_00a16674 == '(') {
      DAT_0084b264 = 0x28;
    }
    else if (*DAT_00a16674 == ' ') {
      DAT_0084b264 = 0x20;
    }
    else if (*DAT_00a16674 == '\x10') {
      DAT_0084b264 = 0x10;
    }
    if ((*DAT_00a16718 == 0x140) && (*DAT_00a1671c == 0xf0)) {
      DAT_0084b248 = 2;
    }
    DAT_0084b230 = *DAT_00a16718 * DAT_0084b248;
    DAT_0084b234 = *DAT_00a1671c * DAT_0084b248;
    FUN_00521e70();
    FUN_00511980();
    if (*DAT_00a166bc == '\x01') {
      FUN_005166f0();
    }
    else {
      FUN_005166f0();
    }
    FUN_005166d0();
    if (DAT_00a117b4 == -1) {
      FUN_005166d0();
      DAT_00a117c8 = 1;
    }
    DAT_0084b244 = (undefined4)(0x3c / (longlong)(int)*DAT_00a16684);
    FUN_00472140();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>(local_3f14,DAT_00a16734);
    local_8 = CONCAT31(local_8._1_3_,8);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_3f14,"  ")
    ;
    local_e4f8 = (undefined1 *)&puStack_13a14;
    uStack_13a18 = &DAT_007d0358;
    basic_string<>();
    uStack_13a18 = (char *)0x46a649;
    pcVar3 = (char *)FUN_00401c50();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              (local_3f14,pcVar3);
    FUN_004cbb30();
    FUN_00511800();
    puStack_13a10 = (undefined1 *)0x0;
    puStack_13a14 = &DAT_00a117bc;
    uStack_13a18 = (char *)&local_3ef4;
    local_3ef8 = FUN_0042b1d0();
    if ((local_21c == 0x18) && (DAT_00a117b4 == 1)) {
      DAT_00a117b4 = 0;
      UVar9 = 0;
      local_e4fc = (undefined1 *)&uStack_13a18;
      basic_string<>();
      pCVar4 = (LPCSTR)FUN_00401c50();
      local_e500 = (undefined1 *)((int)register0x00000010 + -0x13a1c);
      basic_string<>();
      pCVar6 = (LPCSTR)FUN_00401c50();
      MessageBoxA((HWND)0x0,pCVar6,pCVar4,UVar9);
    }
    local_e3fc = FUN_00516810();
    if (DAT_00a117a0 < 1) {
      local_e504 = operator_new(0x200);
      local_e428 = 0x20;
      local_e42c = 0;
      local_e430 = local_e504;
      GetCursorPos(&local_e420);
      pt.y = local_e420.y;
      pt.x = local_e420.x;
      local_e424 = MonitorFromPoint(pt,2);
      local_e478.cbSize = 0x48;
      EnumDisplayMonitors((HDC)0x0,(LPCRECT)0x0,FUN_00417970,(LPARAM)&local_e430);
      GetMonitorInfoA(local_e424,&local_e478);
      basic_string<>();
      local_8._0_1_ = 9;
      for (local_e47c = 0; local_e47c < local_e42c; local_e47c = local_e47c + 1) {
        if ((((*(int *)((int)local_e430 + local_e47c * 0x10 + 0xc) == local_e478.rcMonitor.bottom)
             && (*(int *)((int)local_e430 + local_e47c * 0x10 + 4) == local_e478.rcMonitor.top)) &&
            (*(int *)((int)local_e430 + local_e47c * 0x10) == local_e478.rcMonitor.left)) &&
           (*(int *)((int)local_e430 + local_e47c * 0x10 + 8) == local_e478.rcMonitor.right)) {
          FUN_00516980();
          _DAT_0084b238 = local_e478.rcWork.right - local_e478.rcWork.left;
          _DAT_0084b23c = local_e478.rcWork.bottom - local_e478.rcWork.top;
          puVar8 = (undefined4 *)(local_e47c * 0x10 + (int)local_e430);
          _DAT_00a0f834 = *puVar8;
          _DAT_00a0f838 = puVar8[1];
          DAT_00a0f83c = puVar8[2];
          _DAT_00a0f840 = puVar8[3];
          break;
        }
      }
      local_8 = CONCAT31(local_8._1_3_,8);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_e418);
    }
    else {
      FUN_00516980();
    }
    FUN_00511770();
    if (DAT_00a117c0 == 1) {
      FUN_00567690();
    }
    if ((local_3ef4 == 1) || (DAT_00a117bc == 1)) {
      FUN_0042baa0();
      DAT_00a117bc = 1;
      FUN_00516940();
      DAT_0084b240 = 1;
      FUN_00567670();
      FUN_005157d0();
    }
    else {
      FUN_0042baa0();
    }
    FUN_00511940();
    iVar2 = FUN_0052ec40();
    if (iVar2 != -1) {
      DAT_00a0f804 = FUN_0050e7c0();
      FUN_0050eb00();
      FUN_005157f0();
      FUN_0041a480();
      _DAT_0084b220 = thunk_FUN_00568960();
      FUN_0050eb10();
      local_e514 = (undefined1 *)&puStack_13a14;
      uStack_13a18 = &DAT_007d04d8;
      basic_string<>();
      uStack_13a18 = (char *)0x46aada;
      FUN_00401c50();
      thunk_FUN_00511800();
      for (local_e480 = 0; local_e480 < 0x28; local_e480 = local_e480 + 1) {
        local_e484 = local_3438 + local_e480 * 0x100;
        iVar2 = _strcmp(local_3438 + local_e480 * 0x100,"");
        if (iVar2 == 0) break;
        iVar2 = _strcmp(local_3438 + local_e480 * 0x100,"Use_Debug_Window");
        if ((iVar2 == 0) && (DAT_00a117b4 != 0)) {
          FUN_004176d0();
        }
      }
      if (*DAT_00a16680 == '\x01') {
        local_e3ec = FUN_004010f0();
        if (local_e3ec == 0) {
          if (*DAT_00a1668c == '\0') {
            FUN_00401000();
            FUN_00401380();
          }
          else {
            FUN_00401000();
            FUN_00401380();
          }
        }
        else {
          UVar9 = 1;
          local_e518 = (undefined1 *)&uStack_13a18;
          basic_string<>();
          pCVar4 = (LPCSTR)FUN_00401c50();
          local_e51c = (undefined1 *)((int)register0x00000010 + -0x13a1c);
          basic_string<>();
          pCVar6 = (LPCSTR)FUN_00401c50();
          MessageBoxA((HWND)0x0,pCVar6,pCVar4,UVar9);
          DAT_00a117b0 = 0;
        }
      }
      FUN_0042baa0();
      local_3dad = '\x01';
      FUN_004822d0();
      FUN_00484bb0();
      FUN_004bd360();
      local_8 = CONCAT31(local_8._1_3_,10);
      FUN_00527110();
      do {
        FUN_00423060();
        FUN_005157a0();
        FUN_00476150();
        FUN_00472b10();
        FUN_004c1410();
        FUN_004cbb30();
        FUN_004cbb30();
        puStack_13a10 = (undefined1 *)0x46ad0a;
        _sprintf(local_3738,"%s%sBasicData/%s");
        cVar1 = FUN_004b9ed0();
        if (cVar1 == '\0') {
          FUN_004cbb30();
          _sprintf(local_3738,"%s%s");
          FUN_004b9ed0();
        }
        cVar1 = operator!=<>();
        if ((cVar1 != '\0') && (cVar1 = operator!=<>(), cVar1 != '\0')) {
          DAT_0084b218 = 1;
        }
        DAT_00a117d0 = (int)*DAT_00a166bc;
        FUN_0050eab0();
        DAT_00a117a4 = (int)*DAT_00a166c0;
        FUN_0050f160();
        FUN_004ccc40();
        FUN_004ccc40();
        FUN_00471820();
        local_8._0_1_ = 0xb;
        FUN_00473710();
        local_8 = CONCAT31(local_8._1_3_,10);
        FUN_0047a000();
        local_e530 = (undefined1 *)&puStack_13a14;
        uStack_13a18 = "BasicData/CommonEvent.dat";
        basic_string<>();
        uStack_13a18 = (char *)0x46ae52;
        cVar1 = FUN_0047ecc0();
        if (cVar1 == '\0') {
          uStack_13a18 = (char *)0x46ae68;
          FUN_0046b640();
        }
        uStack_13a18 = (char *)0x46ae72;
        FUN_004ccc40();
        local_e488 = 0;
        while( true ) {
          uStack_13a18 = (char *)0x46ae97;
          iVar2 = FUN_004cfab0();
          if (iVar2 <= local_e488) break;
          uStack_13a18 = &DAT_007d05da;
          FUN_004cfb40();
          cVar1 = operator!=<>();
          if (cVar1 != '\0') {
            uStack_13a18 = (char *)local_e488;
            iVar2 = FUN_004cfb40();
            uStack_13a18 = (char *)(iVar2 + 4);
            piVar7 = (int *)FUN_004cc680();
            *piVar7 = local_e488;
          }
          local_e488 = local_e488 + 1;
        }
        uStack_13a18 = (char *)0x0;
        FUN_0047a5d0();
        uStack_13a18 = (char *)0x0;
        FUN_0047a5d0();
        uStack_13a18 = (char *)0x0;
        FUN_0047a5d0();
        uStack_13a18 = (char *)0x46af31;
        FUN_004bb030();
        uStack_13a18 = (char *)0x46af3b;
        FUN_004bb030();
        uStack_13a18 = "j";
        FUN_004bb030();
        uStack_13a18 = (char *)0x0;
        FUN_00550c60();
        uStack_13a18 = (char *)0x46af5a;
        uStack_13a18 = (char *)FUN_00472810();
        local_8._0_1_ = 0xc;
        FUN_00474bc0();
        local_8._0_1_ = 10;
        uStack_13a18 = (char *)0x46af90;
        FUN_004baed0();
        uStack_13a18 = (char *)0x46af9a;
        FUN_0047cda0();
        uStack_13a18 = (char *)0x46afa4;
        FUN_004bb030();
        DAT_00a117ae = 0;
        if (DAT_00a117ac == '\0') {
          uStack_13a18 = (char *)0x46afc1;
          uStack_13a18 = (char *)FUN_004a6770();
          local_8._0_1_ = 0xd;
          FUN_004b36a0();
          local_8._0_1_ = 10;
          uStack_13a18 = (char *)0x46aff7;
          FUN_004b3550();
        }
        else {
          uStack_13a18 = (char *)0x0;
          puVar8 = (undefined4 *)FUN_004ce990();
          uStack_13a18 = (char *)*puVar8;
          FUN_004174a0();
        }
        if ((local_3dad == '\0') || (DAT_00a117a8 != 0)) {
          uStack_13a18 = (char *)0x0;
          FUN_004822d0();
        }
        local_3dad = '\0';
        uStack_13a18 = (char *)0x46b043;
        FUN_004bb9b0();
        uStack_13a18 = (char *)0x46b04d;
        FUN_00475570();
        uStack_13a18 = (char *)0x46b057;
        FUN_00476150();
        uStack_13a18 = (char *)0x46b062;
        uStack_13a18 = (char *)FUN_00472290();
        local_8._0_1_ = 0xe;
        FUN_004744e0();
        local_8._0_1_ = 10;
        uStack_13a18 = (char *)0x46b098;
        FUN_004bae00();
        uStack_13a18 = (char *)0x46b0a2;
        FUN_004bada0();
        uStack_13a18 = (char *)0x46b0ad;
        uStack_13a18 = (char *)FUN_004718a0();
        local_8._0_1_ = 0xf;
        FUN_00472740();
        local_8._0_1_ = 10;
        uStack_13a18 = (char *)0x46b0e3;
        FUN_00484b30();
        uStack_13a18 = "BasicData/CDataBase";
        FUN_004825c0();
        uStack_13a18 = (char *)0x46b0fd;
        uStack_13a18 = (char *)FUN_00436790();
        local_8._0_1_ = 0x10;
        FUN_004ab5b0();
        local_8._0_1_ = 10;
        uStack_13a18 = (char *)0x46b133;
        FUN_004a68c0();
        uStack_13a18 = (char *)0x46b13e;
        uStack_13a18 = (char *)FUN_00471bd0();
        local_8._0_1_ = 0x11;
        FUN_00472eb0();
        local_8._0_1_ = 10;
        uStack_13a18 = (char *)0x46b174;
        FUN_004a6aa0();
        uStack_13a18 = (char *)0x46b17f;
        uStack_13a18 = (char *)FUN_004441f0();
        local_8._0_1_ = 0x12;
        FUN_004736a0();
        local_8._0_1_ = 10;
        uStack_13a18 = (char *)0x46b1b5;
        CMiniDockFrameWnd::~CMiniDockFrameWnd(local_f800);
        uStack_13a38 = (undefined *)0x46b1cc;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&puStack_13a30
                   ,DAT_00a16750);
        FUN_004787b0();
        uStack_13a18 = (char *)0x46b1e7;
        uStack_13a18 = (char *)FUN_00447840();
        local_8._0_1_ = 0x13;
        FUN_00473f10();
        local_8._0_1_ = 10;
        uStack_13a18 = "j";
        FUN_004a6940();
        uStack_13a18 = (char *)0x0;
        uStack_13a18 = (char *)FUN_00472ab0();
        local_8._0_1_ = 0x14;
        FUN_00474330();
        local_8._0_1_ = 10;
        uStack_13a18 = (char *)0x46b260;
        FUN_004a6be0();
        uStack_13a18 = (char *)0x46b26a;
        FUN_0042bd10();
        DAT_00a16440 = &DAT_00a18178;
        uStack_13a18 = (char *)0xffffffff;
        FUN_0043e5f0();
        uStack_13a18 = (char *)0xffffffff;
        FUN_0043e5f0();
        uStack_13a18 = (char *)0xffffffff;
        FUN_0043e5f0();
        uStack_13a18 = (char *)0xffffffff;
        FUN_0043e5f0();
        uStack_13a18 = (char *)0x46b2b6;
        FUN_00440e60();
        uStack_13a18 = (char *)0xfffffffe;
        FUN_0052a4a0();
        DAT_00a18a8c = DAT_00a117b8;
        uStack_13a18 = (char *)DAT_00a117b8;
        FUN_0042f720();
        uStack_13a18 = (char *)0x46b2e6;
        uStack_13a18 = (char *)FUN_004bd130();
        local_8._0_1_ = 0x15;
        FUN_004cb620();
        local_8 = CONCAT31(local_8._1_3_,10);
        uStack_13a18 = (char *)0x46b31c;
        FUN_004bd270();
        DAT_00a13fa0 = 1;
        DAT_00a17eb8 = 0xffffffff;
        DAT_00a14061 = 0;
        uStack_13a18 = (char *)0x0;
        DAT_00a14068 = FUN_0046f7f0();
        uStack_13a18 = (char *)0x0;
        iVar2 = FUN_0046f7f0();
        DAT_00a1406c = iVar2 << 1;
        uStack_13a18 = (char *)0x0;
        iVar2 = FUN_0046f7f0();
        DAT_00a14070 = iVar2 << 1;
        uStack_13a18 = (char *)0x46b38a;
        FUN_00476150();
        uStack_13a18 = "BasicData/TileSetData.dat";
        FUN_00481430();
        if (DAT_00a117a8 == 0) {
          DAT_00a140bc = 0xfffffff6;
        }
        else {
          uStack_13a18 = (char *)0x46b3ac;
          FUN_00484bb0();
          DAT_00a140bc = 1;
        }
        uStack_13a18 = "j\x01j";
        FUN_00436d00();
        FUN_0044ea60();
        _DAT_00a143e0 = &DAT_00a143d8;
        _DAT_00a143e4 = &DAT_00a14bb8;
        _DAT_00a143e8 = &DAT_00a16538;
        _DAT_00a14bc0 = &DAT_00a143d8;
        _DAT_00a14bc4 = &DAT_00a14bb8;
        _DAT_00a14bc8 = &DAT_00a16538;
        _DAT_00a16540 = &DAT_00a143d8;
        _DAT_00a16544 = &DAT_00a14bb8;
        _DAT_00a16548 = &DAT_00a16538;
        local_e48c = 0;
        while ((local_e48c < 0x32 &&
               (iVar2 = _strcmp(local_3438 + local_e48c * 0x100,""), iVar2 != 0))) {
          iVar2 = _strcmp(local_3438 + local_e48c * 0x100,"-vinput");
          if (iVar2 == 0) {
            _atol(local_3438 + (local_e48c + 2) * 0x100);
            _atol(local_3438 + (local_e48c + 1) * 0x100);
            FUN_00438f70();
            local_e48c = local_e48c + 2;
          }
          else {
            iVar2 = _strcmp(local_3438 + local_e48c * 0x100,"-sinput");
            if (iVar2 == 0) {
              basic_string<>();
              _atol(local_3438 + (local_e48c + 1) * 0x100);
              FUN_0043a2c0();
              local_e48c = local_e48c + 2;
            }
          }
          local_e48c = local_e48c + 1;
        }
LAB_0046b588:
        iVar2 = FUN_0052ece0();
        if (iVar2 != 0) goto LAB_0046b5be;
        FUN_004cb580();
        if (DAT_00a13fa0 != 0) goto LAB_0046b5b1;
        DAT_00a140a9 = 1;
      } while( true );
    }
    UVar9 = 0;
    local_e508 = (undefined1 *)&uStack_13a18;
    basic_string<>();
    pCVar4 = (LPCSTR)FUN_00401c50();
    local_e50c = (undefined1 *)((int)register0x00000010 + -0x13a1c);
    basic_string<>();
    pCVar6 = (LPCSTR)FUN_00401c50();
    MessageBoxA((HWND)0x0,pCVar6,pCVar4,UVar9);
    FUN_0042baa0();
    local_e510 = 0xffffffff;
    local_8._0_1_ = 6;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
               local_3f14);
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
               local_3f30);
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_238);
  }
  ExceptionList = local_10;
  return;
LAB_0046b5b1:
  if (DAT_00a13fa0 == -1) {
LAB_0046b5be:
    local_8._0_1_ = 8;
    FUN_004cb5a0();
    local_8._0_1_ = 6;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
               local_3f14);
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
               local_3f30);
    goto LAB_0046b5eb;
  }
  goto LAB_0046b588;
}

