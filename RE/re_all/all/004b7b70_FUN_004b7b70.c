
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __fastcall FUN_004b7b70(int param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  void *pvVar6;
  int iVar7;
  LPCSTR lpNewFileName;
  LPCSTR lpExistingFileName;
  undefined *puStack_f1c;
  undefined *puStack_f18;
  undefined4 uStack_f14;
  undefined4 uStack_f10;
  char *pcStack_f0c;
  BOOL BVar8;
  int local_eec;
  int local_ee8;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_eb8 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_e9c [28];
  undefined4 local_e80;
  undefined1 *local_e7c;
  undefined4 local_e78;
  undefined1 *local_e74;
  undefined4 local_e70;
  undefined4 local_e6c;
  undefined1 *local_e68;
  undefined4 local_e64;
  undefined1 *local_e60;
  undefined1 *local_e5c;
  char local_e58 [1031];
  char local_a51;
  char local_a50 [512];
  char local_850 [256];
  char local_750 [256];
  char local_650 [256];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_550 [28];
  int local_534;
  char local_52d;
  undefined4 local_52c;
  undefined4 local_528;
  char local_524 [4];
  char local_520 [4];
  char local_51c [4];
  char local_518 [4];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_514 [28];
  undefined4 local_4f8;
  long local_4f4;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_4f0 [28];
  undefined4 local_4d4;
  char local_4d0 [128];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_450 [28];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_434 [28];
  char local_418 [1024];
  undefined4 local_18;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b076d;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_434,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (param_1 + 0x14d0));
  local_8 = 0;
  basic_string<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  cVar1 = FUN_004ec750();
  if (cVar1 == '\0') {
    cVar1 = operator!=<>();
    if (cVar1 != '\0') {
      FUN_004cb840();
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_4f0,":")
      ;
      FUN_004cb880();
    }
  }
  else {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_4f0,"NO");
  }
  local_524[0] = s_Accept______007d1a1c[0];
  local_524[1] = s_Accept______007d1a1c[1];
  local_524[2] = s_Accept______007d1a1c[2];
  local_524[3] = s_Accept______007d1a1c[3];
  local_520[0] = s_Accept______007d1a1c[4];
  local_520[1] = s_Accept______007d1a1c[5];
  local_520[2] = s_Accept______007d1a1c[6];
  local_520[3] = s_Accept______007d1a1c[7];
  local_51c[0] = s_Accept______007d1a1c[8];
  local_51c[1] = s_Accept______007d1a1c[9];
  local_51c[2] = s_Accept______007d1a1c[10];
  local_51c[3] = s_Accept______007d1a1c[0xb];
  local_518[0] = s_Accept______007d1a1c[0xc];
  local_518[1] = s_Accept______007d1a1c[0xd];
  local_518[2] = s_Accept______007d1a1c[0xe];
  local_518[3] = s_Accept______007d1a1c[0xf];
  local_534 = 0;
  while( true ) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              (local_550,
               (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (param_1 + 0x14d0));
    local_8._0_1_ = 2;
    if (local_534 != 0) {
      pcVar2 = (char *)FUN_0041b5f0();
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                (local_550,pcVar2);
    }
    pcStack_f0c = (char *)0x0;
    uStack_f10 = 0x40000000;
    uStack_f14 = 0x4b7ce0;
    uStack_f14 = FUN_004cbb30();
    puStack_f18 = (undefined *)0x4b7cf2;
    uVar3 = FUN_004b8a40();
    *(undefined4 *)(param_1 + 0x1504) = uVar3;
    if (-1 < *(int *)(param_1 + 0x1504)) break;
    local_534 = local_534 + 1;
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
               local_550);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_550)
  ;
  if (local_534 != 0) {
    pcVar2 = (char *)FUN_0041b5f0();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x14d0)
               ,pcVar2);
    FUN_004cb840();
  }
  if (*(int *)(param_1 + 0x1504) < 0) {
    *(undefined4 *)(param_1 + 0x1404) = 0xffffffff;
    local_e5c = (undefined1 *)&uStack_f14;
    puStack_f18 = &DAT_007d19e4;
    puStack_f1c = (undefined *)0x4b7dbb;
    basic_string<>();
    puStack_f18 = (undefined *)0x4b7dc6;
    pcVar2 = (char *)FUN_00401c50();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x1724)
               ,pcVar2);
    puStack_f18 = &DAT_007d19bc;
    puStack_f1c = (undefined *)0x4b7dfc;
    local_e60 = (undefined1 *)&uStack_f14;
    basic_string<>();
    puStack_f18 = (undefined *)0x4b7e07;
    FUN_00401c50();
    pcVar2 = (char *)FUN_004cbb30();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x1740)
               ,pcVar2);
    local_e64 = 0;
    local_8 = local_8 & 0xffffff00;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
               local_4f0);
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
               local_434);
  }
  else {
    local_4d4 = 0;
    cVar1 = operator!=<>();
    if (cVar1 != '\0') {
      local_4d4 = 3;
    }
    cVar1 = FUN_004ec750();
    if (cVar1 != '\0') {
      local_4d4 = 1;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_4f0,"");
    }
    cVar1 = FUN_004ec750();
    if (cVar1 == '\0') {
      FUN_004cbb30();
    }
    pcStack_f0c = "WOLF RPG EDITOR";
    uStack_f10 = 0x4b7f16;
    uVar3 = InternetOpenA();
    *(undefined4 *)(param_1 + 0x14f8) = uVar3;
    if (*(int *)(param_1 + 0x14f8) == 0) {
      local_e68 = (undefined1 *)&puStack_f18;
      puStack_f1c = &DAT_007d1980;
      basic_string<>();
      puStack_f1c = (undefined *)0x4b7f5f;
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_650,pcVar2);
      FUN_004cbb30();
      _sprintf(local_750,"%s");
      *(undefined4 *)(param_1 + 0x1404) = 0xffffffff;
      local_e6c = 0;
      local_8 = local_8 & 0xffffff00;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_4f0);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_434);
      local_e64 = local_e6c;
    }
    else {
      local_528 = 0x80;
      lstrlenA(local_524);
      pcStack_f0c = (char *)0x4b8021;
      pcStack_f0c = (char *)FUN_004cbb30();
      uStack_f10 = *(undefined4 *)(param_1 + 0x14f8);
      uStack_f14 = 0x4b8035;
      uVar3 = InternetOpenUrlA();
      *(undefined4 *)(param_1 + 0x14fc) = uVar3;
      pcStack_f0c = *(char **)(param_1 + 0x14fc);
      uStack_f10 = 0x4b8066;
      HttpQueryInfoA();
      local_4f4 = _atol(local_4d0);
      if (*(int *)(param_1 + 0x14fc) == 0) {
        *(undefined4 *)(param_1 + 0x1404) = 0xffffffff;
        local_e70 = 0;
        local_8 = local_8 & 0xffffff00;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_4f0);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_434);
        local_e64 = local_e70;
      }
      else {
        DAT_00a14364 = local_4f4;
        if (local_4f4 == 200) {
          local_4f8 = 0x400;
          pcStack_f0c = *(char **)(param_1 + 0x14fc);
          uStack_f10 = 0x4b81b0;
          iVar4 = HttpQueryInfoA();
          local_52d = iVar4 != 0;
          *(undefined4 *)(param_1 + 0x1408) = 0;
          lVar5 = _atol(local_418);
          *(long *)(param_1 + 0x140c) = lVar5;
          if (local_52d == '\0') {
            *(undefined4 *)(param_1 + 0x140c) = 100000000;
          }
          *(undefined4 *)(param_1 + 0x1710) = 0;
          pvVar6 = _malloc(*(int *)(param_1 + 0x140c) + 10);
          *(void **)(param_1 + 0x170c) = pvVar6;
          _memset(*(void **)(param_1 + 0x170c),0,*(int *)(param_1 + 0x140c) + 10);
          *(undefined4 *)(param_1 + 0x1404) = 0;
          *(undefined4 *)(param_1 + 0x1714) = 0;
          local_11 = 0;
          local_52c = FUN_00550060();
          if ((*DAT_00a16628 < 15000) || (0x3c8b < *DAT_00a16628)) {
            FUN_0052eb30();
          }
          do {
            pcStack_f0c = (char *)0x4b8305;
            uVar3 = InternetReadFile();
            *(undefined4 *)(param_1 + 0x14ec) = uVar3;
            if (*(int *)(param_1 + 0x14ec) == 0) break;
            *(int *)(param_1 + 0x1408) = *(int *)(param_1 + 0x1408) + *(int *)(param_1 + 0x14f0);
            iVar4 = FUN_00550060();
            *(int *)(param_1 + 0x1418) = (iVar4 - *(int *)(param_1 + 0x1414)) / 1000;
            if (*(int *)(param_1 + 0x1418) < 1) {
              local_ee8 = 1;
            }
            else {
              local_ee8 = *(int *)(param_1 + 0x1418);
            }
            *(int *)(param_1 + 0x1410) = *(int *)(param_1 + 0x1408) / local_ee8;
            if (*(int *)(param_1 + 0x140c) != 100000000) {
              if (*(int *)(param_1 + 0x1410) < 1) {
                local_eec = 1;
              }
              else {
                local_eec = *(int *)(param_1 + 0x1410);
              }
              *(int *)(param_1 + 0x141c) =
                   (*(int *)(param_1 + 0x140c) - *(int *)(param_1 + 0x1408)) / local_eec;
            }
            *(undefined4 *)(param_1 + 0x1404) = 0;
            if (*(int *)(param_1 + 0x14f0) == 0) {
              local_11 = 1;
              if ((*DAT_00a16628 < 15000) || (0x3c8b < *DAT_00a16628)) {
                FUN_0052eb30();
                if (DAT_00a18a28 + -0x1e <= *(int *)(param_1 + 0x14ac)) {
                  FUN_0052eb30();
                }
                if (DAT_00a18a28 + -0x1e <= *(int *)(param_1 + 0x14b0)) {
                  FUN_0052eb30();
                }
                if (DAT_00a18a28 + -0x1e <= *(int *)(param_1 + 0x14b8)) {
                  FUN_0052eb30();
                }
                if (DAT_00a18a28 + -0x1e <= *(int *)(param_1 + 0x14bc)) {
                  FUN_0052eb30();
                }
                if (DAT_00a18a28 + -0x1e <= *(int *)(param_1 + 0x14c0)) {
                  FUN_0052eb30();
                }
              }
              if (0 < *(int *)(param_1 + 0x144c)) {
                std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                          ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                           (param_1 + 0x1778),*(char **)(param_1 + 0x170c));
              }
              if (*(char *)(param_1 + 0x1401) == '\0') {
                uVar3 = FUN_004b8ad0();
                *(undefined4 *)(param_1 + 0x1504) = uVar3;
              }
              uVar3 = FUN_004b8b20();
              *(undefined4 *)(param_1 + 0x1504) = uVar3;
              FUN_00476080();
              FUN_00472e80();
              InternetCloseHandle();
              InternetCloseHandle();
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
              basic_string<char,std::char_traits<char>,std::allocator<char>_>
                        (local_450,
                         (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                          *)(param_1 + 0x14d0));
              local_8._0_1_ = 3;
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
              basic_string<char,std::char_traits<char>,std::allocator<char>_>
                        (local_514,
                         (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                          *)(param_1 + 0x1450));
              local_8 = CONCAT31(local_8._1_3_,4);
              iVar4 = FUN_004cbbf0();
              iVar7 = FUN_004e5650();
              if (iVar4 != iVar7 + -1) {
                iVar4 = FUN_004cbbf0();
                iVar7 = FUN_004e5650();
                if (iVar4 != iVar7 + -1) goto LAB_004b87d9;
              }
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                        (local_514,"/");
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                        (local_514,(char *)(param_1 + 1));
LAB_004b87d9:
              if (*(int *)(param_1 + 0x144c) == -2) {
                FUN_004cb840();
                std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                          (local_514,"\\");
                FUN_004cbb30();
                basic_string<>();
                local_8._0_1_ = 5;
                FUN_004cbb30();
                basic_string<>();
                local_8._0_1_ = 6;
                FUN_004fb8a0();
                local_8._0_1_ = 5;
                std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          (local_eb8);
                local_8 = CONCAT31(local_8._1_3_,4);
                std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          (local_e9c);
                FUN_004cbb30();
                FUN_004fd29b();
              }
              else if (*(char *)(param_1 + 0x1401) == '\0') {
                local_a51 = 0;
                BVar8 = 0;
                lpNewFileName = (LPCSTR)FUN_004cbb30();
                lpExistingFileName = (LPCSTR)FUN_004cbb30();
                BVar8 = CopyFileA(lpExistingFileName,lpNewFileName,BVar8);
                local_a51 = BVar8 != 0;
                if (!(bool)local_a51) {
                  _sprintf(local_e58,&DAT_007d18a0);
                  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                             (param_1 + 0x1724),local_e58);
                  FUN_004cb840();
                }
                FUN_004cbb30();
                FUN_004fd29b();
                if (local_a51 == '\0') {
                  *(undefined4 *)(param_1 + 0x1404) = 0xffffffff;
                  local_8._0_1_ = 3;
                  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              *)local_514);
                  local_8._0_1_ = 1;
                  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              *)local_450);
                  local_8 = (uint)local_8._1_3_ << 8;
                  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              *)local_4f0);
                  local_8 = 0xffffffff;
                  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              *)local_434);
                  ExceptionList = local_10;
                  return 0;
                }
              }
              else {
                FUN_004cbb30();
                FUN_004fd29b();
              }
              *(undefined4 *)(param_1 + 0x1404) = 1;
              local_8._0_1_ = 3;
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                        ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          *)local_514);
              local_8._0_1_ = 1;
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                        ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          *)local_450);
              local_8 = (uint)local_8._1_3_ << 8;
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                        ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          *)local_4f0);
              local_8 = 0xffffffff;
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                        ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          *)local_434);
              ExceptionList = local_10;
              return 0;
            }
            _memcpy((void *)(*(int *)(param_1 + 0x170c) + *(int *)(param_1 + 0x1710)),
                    (void *)(param_1 + 0x1508),*(size_t *)(param_1 + 0x14f0));
            *(int *)(param_1 + 0x1710) = *(int *)(param_1 + 0x1710) + *(int *)(param_1 + 0x14f0);
          } while (-1 < *(int *)(param_1 + 0x1504));
          local_e7c = (undefined1 *)&puStack_f18;
          puStack_f1c = &DAT_007d1914;
          basic_string<>();
          puStack_f1c = (undefined *)0x4b84ed;
          pcVar2 = (char *)FUN_00401c50();
          _sprintf(local_a50,pcVar2);
          *(undefined4 *)(param_1 + 0x1404) = 0xffffffff;
          local_e80 = 0;
          local_8 = local_8 & 0xffffff00;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_4f0);
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_434);
          local_e64 = local_e80;
        }
        else {
          local_e74 = (undefined1 *)&puStack_f1c;
          basic_string<>(&DAT_007d194c);
          pcVar2 = (char *)FUN_00401c50();
          pcStack_f0c = (char *)0x4b8138;
          _sprintf(local_850,pcVar2);
          *(undefined4 *)(param_1 + 0x1404) = 0xffffffff;
          local_e78 = 0;
          local_8 = local_8 & 0xffffff00;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_4f0);
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_434);
          local_e64 = local_e78;
        }
      }
    }
  }
  ExceptionList = local_10;
  return local_e64;
}

