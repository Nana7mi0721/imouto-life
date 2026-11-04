
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_00465000(int param_1)

{
  char cVar1;
  uint *puVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar6;
  int iVar7;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_438 [12];
  undefined4 uStack_42c;
  char *pcStack_428;
  undefined4 uStack_424;
  undefined4 uStack_420;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_41c;
  undefined4 uStack_418;
  undefined4 uStack_414;
  undefined4 uStack_410;
  undefined4 uStack_408;
  undefined4 uStack_404;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_400;
  undefined4 uStack_3fc;
  undefined4 uStack_3f8;
  undefined *puStack_3f4;
  undefined1 *puStack_3f0;
  undefined4 uStack_3ec;
  undefined4 uStack_3e8;
  undefined4 uStack_3e4;
  int iStack_3e0;
  int local_3c0;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2fc [28];
  undefined1 *local_2e0;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2dc [28];
  undefined1 *local_2c0;
  undefined1 *local_2bc;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2b8 [28];
  undefined1 *local_29c;
  undefined1 *local_298;
  undefined1 *local_294;
  undefined1 *local_290;
  undefined1 *local_28c;
  undefined1 *local_288;
  undefined1 *local_284;
  undefined1 *local_280;
  undefined1 *local_27c;
  undefined1 *local_278;
  undefined1 *local_274;
  undefined1 *local_270;
  undefined1 *local_26c;
  undefined1 *local_268;
  undefined1 *local_25c;
  undefined1 *local_258;
  undefined1 *local_254;
  undefined1 *local_250;
  undefined1 *local_244;
  undefined1 *local_240;
  undefined1 *local_23c;
  undefined1 *local_238;
  int local_234;
  char local_230 [256];
  char local_130 [256];
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae3b8;
  local_10 = ExceptionList;
  local_30 = DAT_0084b484;
  local_14 = 1100000000;
  ExceptionList = &local_10;
  FUN_004ce990();
  local_24 = FUN_00487080();
  FUN_004ce990();
  local_20 = FUN_00487080();
  local_18 = (undefined *)0x0;
  puVar2 = (uint *)FUN_004ce990();
  iVar3 = (int)(*puVar2 & 0xf00) >> 8;
  if (iVar3 == 0) {
    local_18 = &DAT_00a16538;
  }
  else if (iVar3 == 1) {
    local_18 = &DAT_00a143d8;
  }
  else {
    if (iVar3 != 2) {
      local_238 = (undefined1 *)&uStack_3ec;
      puStack_3f0 = &DAT_007cfdce;
      puStack_3f4 = (undefined *)0x465105;
      basic_string<>();
      local_8 = 0;
      local_23c = (undefined1 *)&uStack_408;
      uStack_410 = 0x46512f;
      FUN_00438b60();
      local_8 = CONCAT31(local_8._1_3_,1);
      local_244 = (undefined1 *)&uStack_424;
      pcStack_428 = &DAT_007cfdd0;
      uStack_42c = 0x46515d;
      basic_string<>();
      pcStack_428 = (char *)0x465168;
      pcStack_428 = (char *)FUN_00401c50();
      uStack_42c = 0x465188;
      local_240 = (undefined1 *)&uStack_424;
      basic_string<>();
      local_8 = 0xffffffff;
      pcStack_428 = (char *)0x46519a;
      FUN_0042bed0();
      ExceptionList = local_10;
      return;
    }
    local_18 = &DAT_00a14bb8;
  }
  puVar2 = (uint *)FUN_004ce990();
  if (((*puVar2 & 0xf0000) != 0) && (iVar3 = FUN_004cc430(), 3 < iVar3)) {
    puVar2 = (uint *)FUN_004ce990();
    local_2c = (int)(*puVar2 & 0xf00) >> 8;
    FUN_004e9510();
    puVar2 = (uint *)FUN_004ce990();
    if ((*puVar2 & 0x10000) != 0) {
      FUN_004cc4c0();
      puVar4 = (undefined4 *)FUN_004ccca0();
      local_28 = *puVar4;
      FUN_004ce060();
      cVar1 = const_iterator__operator__();
      if (cVar1 == '\0') {
        local_250 = (undefined1 *)&puStack_3f0;
        puStack_3f4 = &DAT_007cfe04;
        uStack_3f8 = 0x4652ba;
        basic_string<>();
        puStack_3f4 = (undefined *)0x4652c5;
        pcVar5 = (char *)FUN_00401c50();
        iStack_3e0 = 0x4652e1;
        _sprintf(local_130,pcVar5);
        local_254 = (undefined1 *)&uStack_3ec;
        puStack_3f0 = (undefined1 *)&uStack_3ec;
        puStack_3f4 = (undefined *)0x4652f5;
        FUN_00438b60();
        local_8 = 2;
        puStack_3f0 = (undefined1 *)0x1;
        puStack_3f4 = (undefined *)0x465327;
        pbVar6 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 FUN_004cc4c0();
        local_258 = (undefined1 *)&uStack_408;
        uStack_410 = 0x465338;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_408,
                   pbVar6);
        local_8 = CONCAT31(local_8._1_3_,3);
        local_25c = (undefined1 *)&uStack_424;
        pcStack_428 = local_130;
        uStack_42c = 0x465365;
        basic_string<>();
        local_8 = 0xffffffff;
        pcStack_428 = (char *)0x465377;
        FUN_0042bed0();
        ExceptionList = local_10;
        return;
      }
      iVar3 = FUN_004d07e0();
      local_24 = *(int *)(iVar3 + 0x1c);
    }
    puVar2 = (uint *)FUN_004ce990();
    if ((*puVar2 & 0x20000) != 0) {
      FUN_004cc4c0();
      iStack_3e0 = 0x4653d3;
      FUN_004cd030();
      puVar4 = (undefined4 *)FUN_004ccca0();
      local_28 = *puVar4;
      FUN_004cd030();
      FUN_004ce060();
      cVar1 = const_iterator__operator__();
      if (cVar1 == '\0') {
        local_268 = (undefined1 *)&puStack_3f0;
        puStack_3f4 = &DAT_007cfe2c;
        uStack_3f8 = 0x46543e;
        basic_string<>();
        puStack_3f4 = (undefined *)0x465449;
        pcVar5 = (char *)FUN_00401c50();
        iStack_3e0 = 0x465465;
        _sprintf(local_230,pcVar5);
        local_26c = (undefined1 *)&uStack_3ec;
        puStack_3f0 = (undefined1 *)&uStack_3ec;
        puStack_3f4 = (undefined *)0x465479;
        FUN_00438b60();
        local_8 = 4;
        puStack_3f0 = (undefined1 *)0x2;
        puStack_3f4 = (undefined *)0x4654ab;
        pbVar6 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 FUN_004cc4c0();
        local_270 = (undefined1 *)&uStack_408;
        uStack_410 = 0x4654bc;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_408,
                   pbVar6);
        local_8 = CONCAT31(local_8._1_3_,5);
        local_274 = (undefined1 *)&uStack_424;
        pcStack_428 = local_230;
        uStack_42c = 0x4654e9;
        basic_string<>();
        local_8 = 0xffffffff;
        pcStack_428 = (char *)0x4654fb;
        FUN_0042bed0();
        ExceptionList = local_10;
        return;
      }
      iVar3 = FUN_004d07e0();
      local_20 = *(int *)(iVar3 + 0x1c);
    }
  }
  if (local_24 < 0) {
    local_278 = (undefined1 *)&uStack_3ec;
    puStack_3f0 = &DAT_007cfe62;
    puStack_3f4 = (undefined *)0x465522;
    basic_string<>();
    local_8 = 6;
    local_27c = (undefined1 *)&uStack_408;
    uStack_410 = 0x46554c;
    FUN_00438b60();
    local_8 = CONCAT31(local_8._1_3_,7);
    local_284 = (undefined1 *)&uStack_424;
    pcStack_428 = &DAT_007cfe64;
    uStack_42c = 0x46557a;
    basic_string<>();
    pcStack_428 = (char *)0x465585;
    pcStack_428 = (char *)FUN_00401c50();
    uStack_42c = 0x4655a5;
    local_280 = (undefined1 *)&uStack_424;
    basic_string<>();
    local_8 = 0xffffffff;
    pcStack_428 = (char *)0x4655b7;
    FUN_0042bed0();
  }
  if (local_20 < 0) {
    local_288 = (undefined1 *)&uStack_3ec;
    puStack_3f0 = &DAT_007cfe87;
    puStack_3f4 = (undefined *)0x4655d9;
    basic_string<>();
    local_8 = 8;
    local_28c = (undefined1 *)&uStack_408;
    uStack_410 = 0x465603;
    FUN_00438b60();
    local_8 = CONCAT31(local_8._1_3_,9);
    local_294 = (undefined1 *)&uStack_424;
    pcStack_428 = &DAT_007cfe88;
    uStack_42c = 0x465631;
    basic_string<>();
    pcStack_428 = (char *)0x46563c;
    pcStack_428 = (char *)FUN_00401c50();
    uStack_42c = 0x46565c;
    local_290 = (undefined1 *)&uStack_424;
    basic_string<>();
    local_8 = 0xffffffff;
    pcStack_428 = (char *)0x46566e;
    FUN_0042bed0();
  }
  FUN_004ce990();
  local_1c = FUN_00487080();
  if (0 < local_1c) {
    puVar2 = (uint *)FUN_004ce990();
    iVar3 = (int)(*puVar2 & 0xf000) >> 0xc;
    if (iVar3 == 0) {
      iVar7 = local_1c + local_20;
      iVar3 = FUN_004717c0();
      if (iVar3 <= iVar7) {
        iStack_3e0 = local_24;
        local_298 = (undefined1 *)&uStack_3fc;
        pbStack_400 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x0;
        uStack_404 = 0;
        uStack_408 = 0;
        uStack_410 = 0;
        uStack_414 = *(undefined4 *)(param_1 + 0x10);
        uStack_418 = *(undefined4 *)(param_1 + 0x18);
        pbStack_41c = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **
                       )(param_1 + 0x14);
        uStack_420 = 0;
        uStack_424 = 0x465758;
        pbVar6 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 FUN_004cc4c0();
        local_29c = abStack_438;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_438,pbVar6);
        FUN_00424670(&uStack_3fc);
        pbStack_400 = local_2b8;
        uStack_404 = 0x465796;
        FUN_004293c0();
        local_8 = 10;
        uStack_3e4 = 0x4657bd;
        uStack_3e4 = FUN_004cbb30();
        uStack_3e8 = 0x4657c6;
        local_234 = FUN_004b6080();
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2b8);
        iVar7 = local_234 + local_20;
        iVar3 = FUN_004717c0();
        if (iVar3 <= iVar7) {
          FUN_004779b0();
        }
      }
      iStack_3e0 = local_24;
      local_2bc = (undefined1 *)&uStack_3fc;
      pbStack_400 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0
      ;
      uStack_404 = 0;
      uStack_408 = 0;
      uStack_410 = 0;
      uStack_414 = *(undefined4 *)(param_1 + 0x10);
      uStack_418 = *(undefined4 *)(param_1 + 0x18);
      pbStack_41c = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **)
                     (param_1 + 0x14);
      uStack_420 = 0;
      uStack_424 = 0x465864;
      pbVar6 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               FUN_004cc4c0();
      local_2c0 = abStack_438;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_438,pbVar6);
      FUN_00424670(&uStack_3fc);
      pbStack_400 = local_2dc;
      uStack_404 = 0x4658a2;
      FUN_004293c0();
      local_8 = 0xb;
      uStack_3e4 = 0x4658c9;
      uStack_3e4 = FUN_004cbb30();
      uStack_3e8 = 0x4658d2;
      FUN_004b6080();
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2dc);
    }
    else if (iVar3 == 1) {
      iVar3 = FUN_004717c0();
      if (local_1c < iVar3 - local_20) {
        local_3c0 = local_1c;
      }
      else {
        local_3c0 = FUN_004717c0();
        local_3c0 = local_3c0 - local_20;
      }
      local_1c = local_3c0;
      iStack_3e0 = 0;
      uStack_3e4 = 0;
      uStack_3e8 = 0;
      uStack_3ec = 0;
      puStack_3f0 = (undefined1 *)0x0;
      puStack_3f4 = *(undefined **)(param_1 + 0x10);
      uStack_3f8 = *(undefined4 *)(param_1 + 0x18);
      uStack_3fc = *(undefined4 *)(param_1 + 0x14);
      pbStack_400 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0
      ;
      uStack_404 = 0x465970;
      FUN_004cc4c0();
      pbStack_400 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x465977;
      pbStack_41c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    FUN_004cbb30();
      local_2e0 = (undefined1 *)&uStack_418;
      uStack_420 = 0x465988;
      basic_string<>();
      pbStack_41c = local_2fc;
      uStack_420 = 0x46599a;
      FUN_00424670();
      local_8 = 0xc;
      iStack_3e0 = 0x4659c1;
      iStack_3e0 = FUN_004cbb30();
      uStack_3e4 = 0x4659ca;
      FUN_004b62b0();
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2fc);
    }
  }
  ExceptionList = local_10;
  return;
}

