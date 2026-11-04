
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0044f7d7) */

void __fastcall FUN_0044ef40(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_44c [4];
  undefined4 uStack_448;
  char local_3a8 [308];
  int local_274;
  int local_270;
  int local_26c;
  int local_268;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_264 [284];
  char local_148 [308];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad95b;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  if (DAT_00a117ae == '\0') {
    DAT_00a0f818 = *(undefined4 *)(param_1 + 0x14);
    DAT_00a11794 = *(undefined4 *)(param_1 + 0x18);
    DAT_00a0f814 = *(undefined4 *)(param_1 + 8);
    ExceptionList = &local_10;
    while( true ) {
      DAT_00a1434c = DAT_00a1434c + 1;
      if (500000 < DAT_00a1434c) {
        DAT_00a1434c = 0;
        basic_string<>();
        pcVar2 = (char *)FUN_00401c50();
        uStack_448 = 0x44f038;
        _sprintf(local_148,pcVar2);
        basic_string<>();
        local_8 = 0;
        basic_string<>();
        local_8 = CONCAT31(local_8._1_3_,1);
        basic_string<>(local_148);
        local_8 = 0xffffffff;
        FUN_0042bed0();
        param_1[0x20] = '\x05';
        param_1[0x21] = '\0';
        param_1[0x22] = '\0';
        param_1[0x23] = '\0';
      }
      cVar1 = FUN_004d2230();
      if (cVar1 == '\0') {
        FUN_004d2250();
        FUN_0044ef40();
        if (DAT_00a117ae != '\0') {
          ExceptionList = local_10;
          return;
        }
        if (DAT_00a13fa0 < 1) {
          ExceptionList = local_10;
          return;
        }
        cVar1 = FUN_004d2230();
        if (cVar1 == '\0') {
          FUN_004d2250();
          cVar1 = FUN_00486cd0();
          if (cVar1 == '\0') {
            if (*(int *)(param_1 + 0x89c) != 0) {
              if ((*(int *)(param_1 + 0x8a0) % 100 < 5) || (9 < *(int *)(param_1 + 0x8a0) % 100)) {
                FUN_00487080();
                FUN_00486e50();
              }
              else {
                FUN_00487160();
                FUN_00486bf0();
              }
              param_1[0x89c] = '\0';
              param_1[0x89d] = '\0';
              param_1[0x89e] = '\0';
              param_1[0x89f] = '\0';
              param_1[0x8a0] = '\0';
              param_1[0x8a1] = '\0';
              param_1[0x8a2] = '\0';
              param_1[0x8a3] = '\0';
            }
            FUN_004ce060();
            FUN_004d2290();
          }
        }
        cVar1 = FUN_004d2230();
        if (cVar1 == '\0') {
          ExceptionList = local_10;
          return;
        }
      }
      if (*(int *)(param_1 + 0x85c) != 0) {
        if ((((0xca < *DAT_00a16714) || (DAT_00a14ae6 == '\0')) &&
            ((*(int *)(param_1 + 0x880) != 0 || (DAT_00a14ae6 == '\0')))) &&
           (iVar3 = FUN_00564640(), iVar3 == 0)) {
          ExceptionList = local_10;
          return;
        }
        DAT_00a14314 = 0;
        if ((DAT_00a14ae6 == '\0') && (iVar3 = FUN_00564640(), iVar3 != 2)) {
          DAT_00a18ad0 = 0;
          FUN_005647d0();
          FUN_00564510();
          basic_string<>();
          local_8 = 2;
          local_268 = 0;
          while (local_268 = FUN_004cbbc0(), local_268 != DAT_007d0624) {
            FUN_004cbb30();
            iVar3 = FUN_0046f680();
            if (iVar3 == 0) {
              FUN_004cba30();
              local_268 = local_268 + 1;
            }
            local_268 = local_268 + 1;
          }
          FUN_004cb880();
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                    (abStack_44c,
                     (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )(param_1 + 0x864));
          FUN_00486bf0();
          param_1[0x85c] = '\0';
          param_1[0x85d] = '\0';
          param_1[0x85e] = '\0';
          param_1[0x85f] = '\0';
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_264);
        }
        else {
          FUN_00564510();
          DAT_00a18ad0 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                    (abStack_44c,
                     (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )(param_1 + 0x864));
          FUN_00486bf0();
          param_1[0x85c] = '\0';
          param_1[0x85d] = '\0';
          param_1[0x85e] = '\0';
          param_1[0x85f] = '\0';
          param_1[0x880] = '\0';
          param_1[0x881] = '\0';
          param_1[0x882] = '\0';
          param_1[0x883] = '\0';
        }
      }
      if (*(int *)(param_1 + 0x890) != 0) {
        ExceptionList = local_10;
        return;
      }
      if (param_1[0xc] != '\0') {
        ExceptionList = local_10;
        return;
      }
      if (param_1[0x850] == '\0') break;
      if (DAT_00a14062 != '\0') {
        if (DAT_00a14093 != '\0') {
          ExceptionList = local_10;
          return;
        }
        if (DAT_00a140a8 != '\0') {
          ExceptionList = local_10;
          return;
        }
      }
      if (*(int *)(param_1 + 0x894) != -1000) {
        FUN_004ce990();
        local_26c = FUN_00452590();
        if (local_26c == 0) {
          param_1[0x894] = '\x18';
          param_1[0x895] = -4;
          param_1[0x896] = -1;
          param_1[0x897] = -1;
        }
        else if (*(char *)(local_26c + 0x52) != '\0') {
          ExceptionList = local_10;
          return;
        }
        param_1[0x894] = '\x18';
        param_1[0x895] = -4;
        param_1[0x896] = -1;
        param_1[0x897] = -1;
      }
      if (param_1[0xd] != '\0') {
        if (DAT_00a1448a != '\0') {
          ExceptionList = local_10;
          return;
        }
        local_270 = 0;
        while (iVar3 = FUN_004d25e0(), local_270 < iVar3) {
          iVar3 = FUN_004d2620();
          if (*(char *)(iVar3 + 0x52) != '\0') {
            ExceptionList = local_10;
            return;
          }
          local_270 = local_270 + 1;
        }
        local_274 = 0;
        while (iVar3 = FUN_004d29a0(), local_274 < iVar3) {
          iVar3 = FUN_004d2a00();
          if (*(char *)(iVar3 + 0x52) != '\0') {
            ExceptionList = local_10;
            return;
          }
          local_274 = local_274 + 1;
        }
        param_1[0xd] = '\0';
      }
      if (param_1[0x8a4] != '\0') {
        cVar1 = FUN_00486e10();
        if (cVar1 != '\0') {
          ExceptionList = local_10;
          return;
        }
        param_1[0x8a4] = '\0';
      }
      if (param_1[0xe] != '\0') {
        FUN_0044f9f0();
        ExceptionList = local_10;
        return;
      }
      if (0 < *(int *)(param_1 + 0x1c)) {
        FUN_0044f9f0();
        ExceptionList = local_10;
        return;
      }
      if (0 < *(int *)(param_1 + 0x20)) {
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) - DAT_0084b244;
        ExceptionList = local_10;
        return;
      }
      if (DAT_00a13fa0 == 0) {
        ExceptionList = local_10;
        return;
      }
      if (*(int *)(param_1 + 0x808) == 0) {
        if ((*param_1 != '\0') && (*(int *)(param_1 + 4) == 0)) {
          FUN_0044ed30();
        }
        if (*(int *)(param_1 + 0x808) == 0) {
          ExceptionList = local_10;
          return;
        }
      }
      DAT_00a0f818 = *(undefined4 *)(param_1 + 0x14);
      DAT_00a11794 = *(undefined4 *)(param_1 + 0x18);
      DAT_00a0f814 = *(undefined4 *)(param_1 + 8);
      DAT_00a1809c = 1;
      cVar1 = FUN_00450460();
      if (cVar1 == '\0') {
        ExceptionList = local_10;
        return;
      }
      if (DAT_00a13fa0 < 1) {
        ExceptionList = local_10;
        return;
      }
      if (0 < DAT_00a117cc) {
        basic_string<>();
        pcVar2 = (char *)FUN_00401c50();
        uStack_448 = 0x44f88b;
        _sprintf(local_3a8,pcVar2);
        basic_string<>();
        local_8 = 3;
        basic_string<>();
        local_8 = CONCAT31(local_8._1_3_,4);
        basic_string<>(local_3a8);
        local_8 = 0xffffffff;
        FUN_0042bed0();
        iVar3 = FUN_004d21f0();
        if (0 < iVar3) {
          FUN_004d2250();
          FUN_004d2250();
          FUN_004d2250();
          basic_string<>();
          pcVar2 = (char *)FUN_00401c50();
          uStack_448 = 0x44f99d;
          _sprintf(local_3a8,pcVar2);
        }
        DAT_00a117cc = 0;
      }
      if (DAT_00a117ae != '\0') {
        ExceptionList = local_10;
        return;
      }
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    param_1[0x850] = '\x01';
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  ExceptionList = local_10;
  return;
}

