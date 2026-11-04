
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0049e9bd) */

void __thiscall
FUN_0049c7a0(undefined4 *param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  int in_stack_00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  int in_stack_0000002c;
  int in_stack_00000030;
  int in_stack_00000034;
  uint in_stack_00000038;
  undefined4 in_stack_0000003c;
  int in_stack_00000040;
  int in_stack_00000044;
  int in_stack_00000048;
  undefined2 uStack0000004c;
  uint in_stack_00000050;
  int in_stack_00000054;
  int in_stack_00000058;
  int in_stack_0000005c;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_774 [8];
  undefined4 uStack_76c;
  undefined *puStack_768;
  undefined4 uStack_760;
  undefined1 *puStack_75c;
  undefined1 auStack_758 [4];
  undefined4 uStack_754;
  int local_648;
  int local_644;
  char local_580 [260];
  int local_47c;
  int local_478;
  int local_474;
  int local_470;
  int local_46c;
  int local_468;
  int local_464;
  int local_460;
  int local_45c;
  int local_458;
  float local_454;
  float local_450;
  int local_44c;
  int local_448;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_444 [28];
  char local_428;
  undefined1 local_427;
  undefined1 local_426;
  undefined1 local_425;
  undefined1 local_424;
  undefined1 local_423;
  undefined1 local_422;
  char local_420;
  undefined1 local_41f;
  undefined1 local_41e;
  undefined1 local_41d;
  undefined1 local_41c;
  undefined1 local_41b;
  undefined1 local_41a;
  char local_418 [512];
  char local_218 [516];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007af9d2;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  local_8 = 0;
  if (0 < in_stack_00000054) {
    ExceptionList = &local_10;
    FUN_004cdf50();
    local_8._0_1_ = 1;
    FUN_004cd3f0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_004ce950();
    FUN_004cc500();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce950();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
    ExceptionList = local_10;
    return;
  }
  ExceptionList = &local_10;
  *(undefined1 *)((int)param_1 + 0x27a) = 0;
  *(undefined1 *)(param_1 + 0x9e) = 0;
  *(undefined1 *)((int)param_1 + 0x279) = 0;
  *(undefined1 *)(param_1 + 0x99) = 0;
  *(bool *)((int)param_1 + 0x265) = in_stack_0000005c == 4;
  param_1[0xe1] = 1;
  if (*(char *)((int)param_1 + 0x265) == '\0') {
    if ((in_stack_00000020 < 1) || (in_stack_00000024 < 1)) {
      if (DAT_00a117a8 != 0) {
        puStack_768 = &DAT_007d1408;
        uStack_76c = 0x49cc53;
        basic_string<>();
        puStack_768 = (undefined *)0x49cc5e;
        pcVar2 = (char *)FUN_00401c50();
        uStack_754 = 0x49cc7a;
        _sprintf(local_218,pcVar2);
        puStack_75c = auStack_758;
        uStack_760 = 0x49cc8e;
        FUN_00438b60();
        local_8._0_1_ = 2;
        basic_string<>();
        FUN_00401c50();
        basic_string<>();
        local_8._0_1_ = 3;
        basic_string<>(local_218);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0042bed0();
      }
      if (in_stack_00000020 < 1) {
        local_644 = 1;
      }
      else {
        local_644 = in_stack_00000020;
      }
      in_stack_00000020 = local_644;
      if (in_stack_00000024 < 1) {
        local_648 = 1;
      }
      else {
        local_648 = in_stack_00000024;
      }
      in_stack_00000024 = local_648;
    }
    if (9999 < in_stack_00000020 * in_stack_00000024) {
      puStack_768 = &DAT_007d1390;
      uStack_76c = 0x49cdab;
      basic_string<>();
      puStack_768 = (undefined *)0x49cdb6;
      pcVar2 = (char *)FUN_00401c50();
      uStack_754 = 0x49cdd2;
      _sprintf(local_418,pcVar2);
      puStack_75c = auStack_758;
      uStack_760 = 0x49cde6;
      FUN_00438b60();
      local_8._0_1_ = 4;
      basic_string<>();
      FUN_00401c50();
      basic_string<>();
      local_8._0_1_ = 5;
      basic_string<>(local_418);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0042bed0();
      *(undefined1 *)((int)param_1 + 0x279) = 1;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
      ExceptionList = local_10;
      return;
    }
    iVar3 = FUN_00515710();
    if (31999 < iVar3 + in_stack_00000020 * in_stack_00000024) {
      puStack_75c = &DAT_007d0621;
      uStack_760 = 0x49cecd;
      basic_string<>();
      local_8._0_1_ = 6;
      FUN_00438b60();
      local_8._0_1_ = 7;
      basic_string<>(&DAT_007d12d0);
      uVar4 = FUN_00401c50();
      basic_string<>(uVar4);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0042bed0();
      *(undefined1 *)((int)param_1 + 0x279) = 1;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
      ExceptionList = local_10;
      return;
    }
  }
  if ((in_stack_00000038 & 0x100) != 0) {
    if ((in_stack_00000058 == 0) ||
       ((in_stack_00000058 != 0 && (*(char *)((int)param_1 + 0x266) == '\0')))) {
      in_stack_00000028 =
           ((int)(DAT_00a17ebc + (DAT_00a17ebc >> 0x1f & 3U)) >> 2) + in_stack_00000028;
      in_stack_0000002c =
           ((int)(DAT_00a17ec0 + (DAT_00a17ec0 >> 0x1f & 3U)) >> 2) + in_stack_0000002c;
    }
    *(undefined1 *)((int)param_1 + 0x266) = 1;
  }
  if (((*(char *)((int)param_1 + 0x266) != '\0') && ((in_stack_00000038 & 0x100) == 0)) &&
     (*(undefined1 *)((int)param_1 + 0x266) = 0, in_stack_00000058 != 0)) {
    in_stack_00000028 = in_stack_00000028 - ((int)(DAT_00a17ebc + (DAT_00a17ebc >> 0x1f & 3U)) >> 2)
    ;
    in_stack_0000002c = in_stack_0000002c - ((int)(DAT_00a17ec0 + (DAT_00a17ec0 >> 0x1f & 3U)) >> 2)
    ;
  }
  *(char *)((int)param_1 + 0x267) = '\x01' - ((in_stack_00000038 & 0x200) != 0x200);
  in_stack_00000038 = in_stack_00000038 & 0xf;
  param_1[1] = *param_1;
  if (*(char *)((int)param_1 + 0x265) == '\0') {
    puStack_768 = (undefined *)0x49d661;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_760,
               (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &param_2);
    cVar1 = FUN_00477140();
    if (cVar1 == '\0') {
      *(undefined1 *)((int)param_1 + 0x279) = 1;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
      ExceptionList = local_10;
      return;
    }
  }
  else {
    pcVar2 = (char *)FUN_004cbb30();
    if (*pcVar2 == '<') {
      iVar3 = FUN_004cbbc0();
      if (iVar3 == 0) {
        param_1[0xdf] = 0;
        iVar3 = FUN_004cbbc0();
        if (iVar3 != -1) {
          param_1[0xe1] = 0;
        }
      }
      else {
        iVar3 = FUN_004cbbc0();
        if (iVar3 == 0) {
          param_1[0xdf] = 1;
        }
        else {
          iVar3 = FUN_004cbbc0();
          if (iVar3 == 0) {
            param_1[0xdf] = 2;
            iVar3 = FUN_004cbbc0();
            if (iVar3 != -1) {
              param_1[0xe1] = 0;
            }
          }
          else {
            iVar3 = FUN_004cbbc0();
            if (iVar3 == 0) {
              param_1[0xdf] = 3;
              iVar3 = FUN_004cbbc0();
              if (iVar3 == 5) {
                param_1[0xe0] = 1;
              }
              else {
                iVar3 = FUN_004cbbc0();
                if (iVar3 == 5) {
                  param_1[0xe0] = 2;
                }
                else {
                  iVar3 = FUN_004cbbc0();
                  if (iVar3 == 5) {
                    param_1[0xe0] = 3;
                  }
                  else {
                    iVar3 = FUN_004cbbc0();
                    if (iVar3 == 5) {
                      param_1[0xe0] = 4;
                    }
                    else {
                      puStack_75c = auStack_758;
                      uStack_760 = 0x49d235;
                      FUN_00438b60();
                      local_8._0_1_ = 8;
                      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                (abStack_774,
                                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                                  *)&param_2);
                      local_8._0_1_ = 9;
                      basic_string<>(&DAT_007d1240);
                      uVar4 = FUN_00401c50();
                      basic_string<>(uVar4);
                      local_8 = (uint)local_8._1_3_ << 8;
                      FUN_0042bed0();
                    }
                  }
                }
              }
              iVar3 = FUN_004cbbc0();
              if (iVar3 != -1) {
                param_1[0xe1] = 0;
              }
            }
            else {
              iVar3 = FUN_004cbbc0();
              if ((iVar3 == 0) && (iVar3 = FUN_004e5650(), iVar3 == 0xf)) {
                param_1[0xdf] = 4;
                iVar3 = FUN_004cbb30();
                local_420 = *(char *)(iVar3 + 7);
                iVar3 = FUN_004cbb30();
                local_41f = *(undefined1 *)(iVar3 + 8);
                iVar3 = FUN_004cbb30();
                local_41e = *(undefined1 *)(iVar3 + 9);
                iVar3 = FUN_004cbb30();
                local_41d = *(undefined1 *)(iVar3 + 0xb);
                iVar3 = FUN_004cbb30();
                local_41c = *(undefined1 *)(iVar3 + 0xc);
                iVar3 = FUN_004cbb30();
                local_41b = *(undefined1 *)(iVar3 + 0xd);
                local_41a = 0;
                lVar5 = _atol(&local_420);
                param_1[0xe0] = lVar5;
              }
              else {
                iVar3 = FUN_004cbbc0();
                if ((iVar3 != 0) || (iVar3 = FUN_004e5650(), iVar3 != 0xf)) {
                  puStack_75c = &DAT_007d11fc;
                  uStack_760 = 0x49d492;
                  basic_string<>();
                  puStack_75c = (undefined1 *)0x49d49d;
                  FUN_00401c50();
                  basic_string<>();
                  local_8._0_1_ = 10;
                  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                            (local_444,"FileName");
                  uStack_760 = 0x49d4dd;
                  puStack_75c = auStack_758;
                  FUN_00438b60();
                  local_8._0_1_ = 0xb;
                  basic_string<>();
                  FUN_00401c50();
                  basic_string<>();
                  local_8._0_1_ = 0xc;
                  uVar4 = FUN_004cbb30();
                  basic_string<>(uVar4);
                  local_8._0_1_ = 10;
                  FUN_0042bed0();
                  *(undefined1 *)((int)param_1 + 0x279) = 1;
                  local_8 = (uint)local_8._1_3_ << 8;
                  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              *)local_444);
                  local_8 = 0xffffffff;
                  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            (&param_2);
                  ExceptionList = local_10;
                  return;
                }
                param_1[0xdf] = 5;
                iVar3 = FUN_004cbb30();
                local_428 = *(char *)(iVar3 + 7);
                iVar3 = FUN_004cbb30();
                local_427 = *(undefined1 *)(iVar3 + 8);
                iVar3 = FUN_004cbb30();
                local_426 = *(undefined1 *)(iVar3 + 9);
                iVar3 = FUN_004cbb30();
                local_425 = *(undefined1 *)(iVar3 + 0xb);
                iVar3 = FUN_004cbb30();
                local_424 = *(undefined1 *)(iVar3 + 0xc);
                iVar3 = FUN_004cbb30();
                local_423 = *(undefined1 *)(iVar3 + 0xd);
                local_422 = 0;
                lVar5 = _atol(&local_428);
                param_1[0xe0] = lVar5;
              }
            }
          }
        }
      }
      param_1[0x9c] = in_stack_00000020;
      param_1[0x9d] = in_stack_00000024;
    }
    else {
      puStack_768 = (undefined *)0x49d5e2;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_760,
                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &param_2);
      cVar1 = FUN_00477140();
      if (cVar1 == '\0') {
        *(undefined1 *)((int)param_1 + 0x279) = 1;
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
        ExceptionList = local_10;
        return;
      }
      param_1[0x9c] = in_stack_00000020;
      param_1[0x9d] = in_stack_00000024;
    }
  }
  cVar1 = operator!=<>();
  if (cVar1 != '\0') {
    puStack_768 = (undefined *)0x49d6f4;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_760,
               (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (param_1 + 0x54));
    FUN_004361d0();
    if (*(char *)(param_1 + 0x90) != '\0') {
      *(undefined1 *)(param_1 + 0x90) = 0;
      if ((int)param_1[0x6c] < 1) {
        for (local_44c = 0; local_44c < 4; local_44c = local_44c + 1) {
          param_1[local_44c + 0x84] = param_1[local_44c + 0x80];
          param_1[local_44c + 0x8c] = param_1[local_44c + 0x88];
        }
      }
      else {
        for (local_448 = 0; local_448 < 4; local_448 = local_448 + 1) {
          param_1[local_448 + 0x84] =
               (int)((param_1[local_448 + 0x84] - param_1[local_448 + 0x80]) * param_1[0x6c]) /
               (int)param_1[0x6d] + param_1[local_448 + 0x80];
          param_1[local_448 + 0x8c] =
               (int)((param_1[local_448 + 0x8c] - param_1[local_448 + 0x88]) * param_1[0x6c]) /
               (int)param_1[0x6d] + param_1[local_448 + 0x88];
        }
      }
      iVar3 = param_1[0x84] + param_1[0x85] + param_1[0x86] + param_1[0x87];
      param_1[99] = (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2;
      param_1[0x62] = param_1[99];
      iVar3 = param_1[0x8c] + param_1[0x8d] + param_1[0x8e] + param_1[0x8f];
      param_1[0x65] = (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2;
      param_1[100] = param_1[0x65];
    }
  }
  FUN_004cb840();
  FUN_004cb840();
  FUN_0049ec50();
  if (*(char *)(param_1 + 0x90) == '\0') {
    if ((int)param_1[0x6c] < 1) {
      param_1[99] = param_1[0x62];
      param_1[0x65] = param_1[100];
      param_1[0x67] = param_1[0x66];
      param_1[0x69] = param_1[0x68];
      param_1[0x6b] = param_1[0x6a];
      param_1[0x75] = param_1[0x74];
      param_1[0x77] = param_1[0x76];
      param_1[0x6f] = param_1[0x6e];
      for (local_45c = 0; local_45c < 3; local_45c = local_45c + 1) {
        param_1[local_45c + 0x7b] = param_1[local_45c + 0x78];
      }
    }
    else {
      param_1[99] = (int)((param_1[99] - param_1[0x62]) * param_1[0x6c]) / (int)param_1[0x6d] +
                    param_1[0x62];
      param_1[0x65] =
           (int)((param_1[0x65] - param_1[100]) * param_1[0x6c]) / (int)param_1[0x6d] + param_1[100]
      ;
      param_1[0x75] =
           (int)((param_1[0x75] - param_1[0x74]) * param_1[0x6c]) / (int)param_1[0x6d] +
           param_1[0x74];
      param_1[0x77] =
           (int)((param_1[0x77] - param_1[0x76]) * param_1[0x6c]) / (int)param_1[0x6d] +
           param_1[0x76];
      iVar3 = FUN_004fe844();
      param_1[0x6f] = iVar3 + param_1[0x6e];
      for (local_458 = 0; local_458 < 3; local_458 = local_458 + 1) {
        param_1[local_458 + 0x7b] =
             (int)((param_1[local_458 + 0x7b] - param_1[local_458 + 0x78]) * param_1[0x6c]) /
             (int)param_1[0x6d] + param_1[local_458 + 0x78];
      }
    }
    *(undefined2 *)((int)param_1 + 0x26a) = *(undefined2 *)(param_1 + 0x9a);
    if (in_stack_00000058 == 0) {
      param_1[0x62] = in_stack_00000028;
      param_1[100] = in_stack_0000002c;
    }
    else {
      param_1[0x62] = param_1[99] + in_stack_00000028;
      param_1[100] = param_1[0x65] + in_stack_0000002c;
    }
    local_454 = 0.0;
    local_450 = 0.0;
    if (param_1[1] != 0) {
      switch(*(undefined2 *)((int)param_1 + 0x26a)) {
      case 1:
        local_454 = (float)((int)param_1[0x70] / 2) + 0.0;
        local_450 = (float)((int)param_1[0x72] / 2) + 0.0;
        break;
      case 2:
        local_450 = (float)(int)param_1[0x72] + 0.0;
        break;
      case 3:
        local_454 = (float)(int)param_1[0x70] + 0.0;
        break;
      case 4:
        local_454 = (float)(int)param_1[0x70] + 0.0;
        local_450 = (float)(int)param_1[0x72] + 0.0;
      }
      switch(_uStack0000004c) {
      case 1:
        local_454 = local_454 - (float)((int)param_1[0x70] / 2);
        local_450 = local_450 - (float)((int)param_1[0x72] / 2);
        break;
      case 2:
        local_450 = local_450 - (float)(int)param_1[0x72];
        break;
      case 3:
        local_454 = local_454 - (float)(int)param_1[0x70];
        break;
      case 4:
        local_454 = local_454 - (float)(int)param_1[0x70];
        local_450 = local_450 - (float)(int)param_1[0x72];
      }
      local_454 = (float)((int)param_1[0x75] / 100) * local_454;
      local_450 = (float)((int)param_1[0x77] / 100) * local_450;
    }
    iVar3 = FUN_004fe844();
    param_1[99] = param_1[99] - iVar3;
    iVar3 = FUN_004fe844();
    param_1[0x65] = param_1[0x65] - iVar3;
  }
  else {
    if ((int)param_1[0x6c] < 1) {
      for (local_468 = 0; local_468 < 4; local_468 = local_468 + 1) {
        param_1[local_468 + 0x84] = param_1[local_468 + 0x80];
        param_1[local_468 + 0x8c] = param_1[local_468 + 0x88];
      }
      param_1[0x67] = param_1[0x66];
      param_1[0x69] = param_1[0x68];
      param_1[0x6b] = param_1[0x6a];
      param_1[0x75] = param_1[0x74];
      param_1[0x77] = param_1[0x76];
      param_1[0x6f] = param_1[0x6e];
      for (local_46c = 0; local_46c < 3; local_46c = local_46c + 1) {
        param_1[local_46c + 0x7b] = param_1[local_46c + 0x78];
      }
    }
    else {
      for (local_460 = 0; local_460 < 4; local_460 = local_460 + 1) {
        param_1[local_460 + 0x84] =
             (int)((param_1[local_460 + 0x84] - param_1[local_460 + 0x80]) * param_1[0x6c]) /
             (int)param_1[0x6d] + param_1[local_460 + 0x80];
        param_1[local_460 + 0x8c] =
             (int)((param_1[local_460 + 0x8c] - param_1[local_460 + 0x88]) * param_1[0x6c]) /
             (int)param_1[0x6d] + param_1[local_460 + 0x88];
      }
      param_1[0x75] =
           (int)((param_1[0x75] - param_1[0x74]) * param_1[0x6c]) / (int)param_1[0x6d] +
           param_1[0x74];
      param_1[0x77] =
           (int)((param_1[0x77] - param_1[0x76]) * param_1[0x6c]) / (int)param_1[0x6d] +
           param_1[0x76];
      iVar3 = FUN_004fe844();
      param_1[0x6f] = iVar3 + param_1[0x6e];
      for (local_464 = 0; local_464 < 3; local_464 = local_464 + 1) {
        param_1[local_464 + 0x7b] =
             (int)((param_1[local_464 + 0x7b] - param_1[local_464 + 0x78]) * param_1[0x6c]) /
             (int)param_1[0x6d] + param_1[local_464 + 0x78];
      }
    }
    *(undefined2 *)((int)param_1 + 0x26a) = *(undefined2 *)(param_1 + 0x9a);
    if (in_stack_00000058 == 0) {
      iVar3 = param_1[0x84] + param_1[0x85] + param_1[0x86] + param_1[0x87];
      local_474 = (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2;
      iVar3 = param_1[0x8c] + param_1[0x8d] + param_1[0x8e] + param_1[0x8f];
      local_478 = (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2;
      local_470 = in_stack_00000028 - local_474;
      local_47c = in_stack_0000002c - local_478;
      param_1[0x80] = param_1[0x84] + local_470;
      param_1[0x81] = param_1[0x85] + local_470;
      param_1[0x82] = param_1[0x86] + local_470;
      param_1[0x83] = param_1[0x87] + local_470;
      param_1[0x88] = param_1[0x8c] + local_47c;
      param_1[0x89] = param_1[0x8d] + local_47c;
      param_1[0x8a] = param_1[0x8e] + local_47c;
      param_1[0x8b] = param_1[0x8f] + local_47c;
    }
    else {
      param_1[0x80] = param_1[0x84] + in_stack_00000028;
      param_1[0x81] = param_1[0x85] + in_stack_00000028;
      param_1[0x82] = param_1[0x86] + in_stack_00000028;
      param_1[0x83] = param_1[0x87] + in_stack_00000028;
      param_1[0x88] = param_1[0x8c] + in_stack_0000002c;
      param_1[0x89] = param_1[0x8d] + in_stack_0000002c;
      param_1[0x8a] = param_1[0x8e] + in_stack_0000002c;
      param_1[0x8b] = param_1[0x8f] + in_stack_0000002c;
    }
  }
  if (in_stack_00000030 != -1000000) {
    param_1[0x66] = in_stack_00000030;
  }
  if (in_stack_00000034 != -1000000) {
    param_1[0x68] = in_stack_00000034;
  }
  if (in_stack_00000038 != 0xf) {
    param_1[0x6a] = in_stack_00000038;
  }
  if (in_stack_00000040 != -1000000) {
    param_1[0x74] = in_stack_00000040;
  }
  if (in_stack_00000044 != -1000000) {
    param_1[0x76] = in_stack_00000044;
  }
  if (in_stack_00000048 != -1000000) {
    param_1[0x6e] = in_stack_00000048;
  }
  *(undefined2 *)(param_1 + 0x9a) = uStack0000004c;
  if ((in_stack_00000050 & 0x1000000) == 0) {
    uVar4 = FUN_004fe844();
    param_1[0x78] = uVar4;
    uVar4 = FUN_004fe844();
    param_1[0x79] = uVar4;
    uVar4 = FUN_004fe844();
    param_1[0x7a] = uVar4;
  }
  if (param_1[1] == 0) {
    param_1[99] = in_stack_00000028;
    param_1[0x65] = in_stack_0000002c;
    param_1[0x67] = in_stack_00000030;
    param_1[0x69] = 0;
    param_1[0x6b] = in_stack_00000038;
    param_1[0x75] = param_1[0x74];
    param_1[0x77] = param_1[0x76];
    param_1[0x6f] = in_stack_00000048;
    param_1[0x71] = param_1[0x70];
    param_1[0x73] = param_1[0x72];
    *(undefined2 *)((int)param_1 + 0x26a) = *(undefined2 *)(param_1 + 0x9a);
    if ((in_stack_00000050 & 0x1000000) == 0) {
      uVar4 = FUN_004fe844();
      param_1[0x7b] = uVar4;
      uVar4 = FUN_004fe844();
      param_1[0x7c] = uVar4;
      uVar4 = FUN_004fe844();
      param_1[0x7d] = uVar4;
    }
  }
  else {
    *(undefined2 *)((int)param_1 + 0x26a) = *(undefined2 *)(param_1 + 0x9a);
    param_1[0x71] = param_1[0x70];
    param_1[0x73] = param_1[0x72];
  }
  if (((*(char *)(param_1 + 0x99) == '\0') && (*(char *)((int)param_1 + 0x265) == '\0')) &&
     ((iVar3 = FUN_004ce080(), iVar3 < (int)param_1[0x66] && (iVar3 = FUN_004ce080(), iVar3 != 0))))
  {
    FUN_004ce080();
    puStack_768 = &DAT_007d1148;
    uStack_76c = 0x49eade;
    basic_string<>();
    puStack_768 = (undefined *)0x49eae9;
    pcVar2 = (char *)FUN_00401c50();
    uStack_754 = 0x49eb05;
    _sprintf(local_580,pcVar2);
    puStack_75c = auStack_758;
    uStack_760 = 0x49eb19;
    FUN_00438b60();
    local_8._0_1_ = 0xd;
    basic_string<>();
    FUN_00401c50();
    basic_string<>();
    local_8._0_1_ = 0xe;
    basic_string<>(local_580);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0042bed0();
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  }
  else {
    param_1[0x7f] = 0;
    param_1[0x7e] = 0;
    param_1[0x6c] = in_stack_0000003c;
    param_1[0x6d] = in_stack_0000003c;
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  }
  ExceptionList = local_10;
  return;
}

