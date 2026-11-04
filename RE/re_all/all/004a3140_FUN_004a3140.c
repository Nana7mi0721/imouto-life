
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004a3140(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,int param_11,int param_12,undefined4 param_13,
            int param_14,int param_15,int param_16,uint param_17,int param_18,int param_19)

{
  undefined4 uVar1;
  int iVar2;
  char *_Format;
  undefined4 local_180;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_154 [44];
  char local_128 [256];
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007afb9c;
  local_10 = ExceptionList;
  local_28 = DAT_0084b484;
  if (param_18 < 1) {
    if ((*(char *)(param_1 + 0x264) == '\0') && (*(char *)(param_1 + 0x265) == '\0')) {
      ExceptionList = &local_10;
      if (*(char *)(param_1 + 0x240) == '\0') {
        if (*(int *)(param_1 + 0x1b4) < 1) {
          local_180 = 1;
        }
        else {
          local_180 = *(undefined4 *)(param_1 + 0x1b4);
        }
        local_14 = local_180;
        if (*(int *)(param_1 + 0x1b0) == -1) {
          if (*(short *)(param_1 + 0x268) < 3) {
            ExceptionList = &local_10;
            uVar1 = FUN_004fe844();
            *(undefined4 *)(param_1 + 0x27c) = uVar1;
            uVar1 = FUN_004fe844();
            *(undefined4 *)(param_1 + 0x284) = uVar1;
            uVar1 = FUN_004fe844();
            *(undefined4 *)(param_1 + 0x280) = uVar1;
            uVar1 = FUN_004fe844();
            *(undefined4 *)(param_1 + 0x288) = uVar1;
          }
          else {
            ExceptionList = &local_10;
            if (2 < *(short *)(param_1 + 0x268)) {
              ExceptionList = &local_10;
              uVar1 = FUN_004fe844();
              *(undefined4 *)(param_1 + 0x27c) = uVar1;
              uVar1 = FUN_004fe844();
              *(undefined4 *)(param_1 + 0x284) = uVar1;
              uVar1 = FUN_004fe844();
              *(undefined4 *)(param_1 + 0x280) = uVar1;
              uVar1 = FUN_004fe844();
              *(undefined4 *)(param_1 + 0x288) = uVar1;
            }
          }
        }
        else if (*(short *)(param_1 + 0x268) < 3) {
          ExceptionList = &local_10;
          uVar1 = FUN_004fe844();
          *(undefined4 *)(param_1 + 0x27c) = uVar1;
          uVar1 = FUN_004fe844();
          *(undefined4 *)(param_1 + 0x284) = uVar1;
          uVar1 = FUN_004fe844();
          *(undefined4 *)(param_1 + 0x280) = uVar1;
          uVar1 = FUN_004fe844();
          *(undefined4 *)(param_1 + 0x288) = uVar1;
        }
        else {
          ExceptionList = &local_10;
          if (2 < *(short *)(param_1 + 0x268)) {
            ExceptionList = &local_10;
            uVar1 = FUN_004fe844();
            *(undefined4 *)(param_1 + 0x27c) = uVar1;
            uVar1 = FUN_004fe844();
            *(undefined4 *)(param_1 + 0x284) = uVar1;
            uVar1 = FUN_004fe844();
            *(undefined4 *)(param_1 + 0x280) = uVar1;
            uVar1 = FUN_004fe844();
            *(undefined4 *)(param_1 + 0x288) = uVar1;
          }
        }
        *(undefined4 *)(param_1 + 0x200) = *(undefined4 *)(param_1 + 0x27c);
        *(undefined4 *)(param_1 + 0x220) = *(undefined4 *)(param_1 + 0x284);
        *(undefined4 *)(param_1 + 0x204) = *(undefined4 *)(param_1 + 0x280);
        *(undefined4 *)(param_1 + 0x224) = *(undefined4 *)(param_1 + 0x284);
        *(undefined4 *)(param_1 + 0x208) = *(undefined4 *)(param_1 + 0x27c);
        *(undefined4 *)(param_1 + 0x228) = *(undefined4 *)(param_1 + 0x288);
        *(undefined4 *)(param_1 + 0x20c) = *(undefined4 *)(param_1 + 0x280);
        *(undefined4 *)(param_1 + 0x22c) = *(undefined4 *)(param_1 + 0x288);
      }
      FUN_0049ec50();
      if (*(int *)(param_1 + 0x1b0) < 1) {
        for (local_20 = 0; local_20 < 4; local_20 = local_20 + 1) {
          *(undefined4 *)(param_1 + 0x210 + local_20 * 4) =
               *(undefined4 *)(param_1 + 0x200 + local_20 * 4);
          *(undefined4 *)(param_1 + 0x230 + local_20 * 4) =
               *(undefined4 *)(param_1 + 0x220 + local_20 * 4);
        }
        *(undefined4 *)(param_1 + 0x19c) = *(undefined4 *)(param_1 + 0x198);
        *(undefined4 *)(param_1 + 0x1a4) = *(undefined4 *)(param_1 + 0x1a0);
        *(undefined4 *)(param_1 + 0x1ac) = *(undefined4 *)(param_1 + 0x1a8);
        *(undefined4 *)(param_1 + 0x1d4) = *(undefined4 *)(param_1 + 0x1d0);
        *(undefined4 *)(param_1 + 0x1dc) = *(undefined4 *)(param_1 + 0x1d8);
        *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 0x1b8);
        for (local_24 = 0; local_24 < 3; local_24 = local_24 + 1) {
          *(undefined4 *)(param_1 + 0x1ec + local_24 * 4) =
               *(undefined4 *)(param_1 + 0x1e0 + local_24 * 4);
        }
      }
      else {
        for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
          *(int *)(param_1 + 0x210 + local_18 * 4) =
               ((*(int *)(param_1 + 0x210 + local_18 * 4) - *(int *)(param_1 + 0x200 + local_18 * 4)
                ) * *(int *)(param_1 + 0x1b0)) / *(int *)(param_1 + 0x1b4) +
               *(int *)(param_1 + 0x200 + local_18 * 4);
          *(int *)(param_1 + 0x230 + local_18 * 4) =
               ((*(int *)(param_1 + 0x230 + local_18 * 4) - *(int *)(param_1 + 0x220 + local_18 * 4)
                ) * *(int *)(param_1 + 0x1b0)) / *(int *)(param_1 + 0x1b4) +
               *(int *)(param_1 + 0x220 + local_18 * 4);
        }
        *(int *)(param_1 + 0x1d4) =
             ((*(int *)(param_1 + 0x1d4) - *(int *)(param_1 + 0x1d0)) * *(int *)(param_1 + 0x1b0)) /
             *(int *)(param_1 + 0x1b4) + *(int *)(param_1 + 0x1d0);
        *(int *)(param_1 + 0x1dc) =
             ((*(int *)(param_1 + 0x1dc) - *(int *)(param_1 + 0x1d8)) * *(int *)(param_1 + 0x1b0)) /
             *(int *)(param_1 + 0x1b4) + *(int *)(param_1 + 0x1d8);
        iVar2 = FUN_004fe844();
        *(int *)(param_1 + 0x1bc) = iVar2 + *(int *)(param_1 + 0x1b8);
        for (local_1c = 0; local_1c < 3; local_1c = local_1c + 1) {
          *(int *)(param_1 + 0x1ec + local_1c * 4) =
               ((*(int *)(param_1 + 0x1ec + local_1c * 4) - *(int *)(param_1 + 0x1e0 + local_1c * 4)
                ) * *(int *)(param_1 + 0x1b0)) / *(int *)(param_1 + 0x1b4) +
               *(int *)(param_1 + 0x1e0 + local_1c * 4);
        }
      }
      *(undefined2 *)(param_1 + 0x26a) = *(undefined2 *)(param_1 + 0x268);
      if (param_19 == 0) {
        *(int *)(param_1 + 0x200) = param_2;
        *(int *)(param_1 + 0x204) = param_4;
        *(int *)(param_1 + 0x208) = param_6;
        *(int *)(param_1 + 0x20c) = param_8;
        *(int *)(param_1 + 0x220) = param_3;
        *(int *)(param_1 + 0x224) = param_5;
        *(int *)(param_1 + 0x228) = param_7;
        *(int *)(param_1 + 0x22c) = param_9;
      }
      else {
        *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x210) + param_2;
        *(int *)(param_1 + 0x204) = *(int *)(param_1 + 0x214) + param_4;
        *(int *)(param_1 + 0x208) = *(int *)(param_1 + 0x218) + param_6;
        *(int *)(param_1 + 0x20c) = *(int *)(param_1 + 0x21c) + param_8;
        *(int *)(param_1 + 0x220) = *(int *)(param_1 + 0x230) + param_3;
        *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x234) + param_5;
        *(int *)(param_1 + 0x228) = *(int *)(param_1 + 0x238) + param_7;
        *(int *)(param_1 + 0x22c) = *(int *)(param_1 + 0x23c) + param_9;
      }
      if (param_10 != -1000000) {
        *(int *)(param_1 + 0x198) = param_10;
      }
      if (param_11 != -1000000) {
        *(int *)(param_1 + 0x1a0) = param_11;
      }
      if (param_12 != 0xf) {
        *(int *)(param_1 + 0x1a8) = param_12;
      }
      if ((param_14 != -1000000) && (param_15 != -1000000)) {
        *(int *)(param_1 + 0x1d0) = param_14;
      }
      if ((param_14 != -1000000) && (param_15 != -1000000)) {
        *(int *)(param_1 + 0x1d8) = param_15;
      }
      if (param_16 != -1000000) {
        *(int *)(param_1 + 0x1b8) = param_16;
      }
      if ((param_17 & 0x1000000) == 0) {
        uVar1 = FUN_004fe844();
        *(undefined4 *)(param_1 + 0x1e0) = uVar1;
        uVar1 = FUN_004fe844();
        *(undefined4 *)(param_1 + 0x1e4) = uVar1;
        uVar1 = FUN_004fe844();
        *(undefined4 *)(param_1 + 0x1e8) = uVar1;
      }
      if ((((*(char *)(param_1 + 0x264) == '\0') && (*(char *)(param_1 + 0x265) == '\0')) &&
          (iVar2 = FUN_004ce080(), iVar2 < *(int *)(param_1 + 0x198))) &&
         (iVar2 = FUN_004ce080(), iVar2 != 0)) {
        FUN_004ce080();
        basic_string<>();
        _Format = (char *)FUN_00401c50();
        _sprintf(local_128,_Format);
        FUN_00438b60();
        local_8 = 2;
        basic_string<>();
        FUN_00401c50();
        basic_string<>();
        local_8 = CONCAT31(local_8._1_3_,3);
        basic_string<>(local_128);
        local_8 = 0xffffffff;
        FUN_0042bed0();
      }
      else {
        *(undefined4 *)(param_1 + 0x1b0) = param_13;
        *(undefined4 *)(param_1 + 0x1b4) = param_13;
        *(undefined1 *)(param_1 + 0x240) = 1;
      }
    }
    else {
      ExceptionList = &local_10;
      FUN_004a1ef0();
    }
  }
  else {
    ExceptionList = &local_10;
    FUN_004cdf50();
    local_8 = 0;
    FUN_004cd3f0();
    local_8 = 0xffffffff;
    FUN_004ce950();
    basic_string<>();
    local_8 = 1;
    FUN_004cc500();
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_154);
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
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
    FUN_004cd340();
    FUN_004cde80();
    FUN_004ce160();
  }
  ExceptionList = local_10;
  return;
}

