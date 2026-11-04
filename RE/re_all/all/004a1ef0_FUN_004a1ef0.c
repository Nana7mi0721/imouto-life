
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
FUN_004a1ef0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            undefined4 param_7,int param_8,int param_9,int param_10,uint param_11,int param_12,
            int param_13)

{
  undefined4 uVar1;
  int iVar2;
  char *_Format;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_174 [44];
  char local_148 [260];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007afb5c;
  local_10 = ExceptionList;
  local_44 = DAT_0084b484;
  if (param_12 < 1) {
    ExceptionList = &local_10;
    FUN_0049ec50();
    if (*(char *)(param_1 + 0x240) == '\0') {
      if (*(int *)(param_1 + 0x1b0) < 1) {
        *(undefined4 *)(param_1 + 0x18c) = *(undefined4 *)(param_1 + 0x188);
        *(undefined4 *)(param_1 + 0x194) = *(undefined4 *)(param_1 + 400);
        *(undefined4 *)(param_1 + 0x19c) = *(undefined4 *)(param_1 + 0x198);
        *(undefined4 *)(param_1 + 0x1a4) = *(undefined4 *)(param_1 + 0x1a0);
        *(undefined4 *)(param_1 + 0x1ac) = *(undefined4 *)(param_1 + 0x1a8);
        *(undefined4 *)(param_1 + 0x1d4) = *(undefined4 *)(param_1 + 0x1d0);
        *(undefined4 *)(param_1 + 0x1dc) = *(undefined4 *)(param_1 + 0x1d8);
        *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 0x1b8);
        for (local_18 = 0; local_18 < 3; local_18 = local_18 + 1) {
          *(undefined4 *)(param_1 + 0x1ec + local_18 * 4) =
               *(undefined4 *)(param_1 + 0x1e0 + local_18 * 4);
        }
      }
      else {
        *(int *)(param_1 + 0x18c) =
             ((*(int *)(param_1 + 0x18c) - *(int *)(param_1 + 0x188)) * *(int *)(param_1 + 0x1b0)) /
             *(int *)(param_1 + 0x1b4) + *(int *)(param_1 + 0x188);
        *(int *)(param_1 + 0x194) =
             ((*(int *)(param_1 + 0x194) - *(int *)(param_1 + 400)) * *(int *)(param_1 + 0x1b0)) /
             *(int *)(param_1 + 0x1b4) + *(int *)(param_1 + 400);
        *(int *)(param_1 + 0x1d4) =
             ((*(int *)(param_1 + 0x1d4) - *(int *)(param_1 + 0x1d0)) * *(int *)(param_1 + 0x1b0)) /
             *(int *)(param_1 + 0x1b4) + *(int *)(param_1 + 0x1d0);
        *(int *)(param_1 + 0x1dc) =
             ((*(int *)(param_1 + 0x1dc) - *(int *)(param_1 + 0x1d8)) * *(int *)(param_1 + 0x1b0)) /
             *(int *)(param_1 + 0x1b4) + *(int *)(param_1 + 0x1d8);
        *(int *)(param_1 + 0x1bc) =
             ((*(int *)(param_1 + 0x1bc) - *(int *)(param_1 + 0x1b8)) * *(int *)(param_1 + 0x1b0)) /
             *(int *)(param_1 + 0x1b4) + *(int *)(param_1 + 0x1b8);
        *(int *)(param_1 + 0x1a4) =
             ((*(int *)(param_1 + 0x1a4) - *(int *)(param_1 + 0x1a0)) * *(int *)(param_1 + 0x1b0)) /
             *(int *)(param_1 + 0x1b4) + *(int *)(param_1 + 0x1a0);
        for (local_14 = 0; local_14 < 3; local_14 = local_14 + 1) {
          *(int *)(param_1 + 0x1ec + local_14 * 4) =
               ((*(int *)(param_1 + 0x1ec + local_14 * 4) - *(int *)(param_1 + 0x1e0 + local_14 * 4)
                ) * *(int *)(param_1 + 0x1b0)) / *(int *)(param_1 + 0x1b4) +
               *(int *)(param_1 + 0x1e0 + local_14 * 4);
        }
      }
      *(undefined2 *)(param_1 + 0x26a) = *(undefined2 *)(param_1 + 0x268);
      if (param_13 == 0) {
        *(int *)(param_1 + 0x188) = param_2;
        *(int *)(param_1 + 400) = param_3;
      }
      else {
        *(int *)(param_1 + 0x188) = *(int *)(param_1 + 0x18c) + param_2;
        *(int *)(param_1 + 400) = *(int *)(param_1 + 0x194) + param_3;
      }
    }
    else {
      if (*(int *)(param_1 + 0x1b0) < 1) {
        for (local_24 = 0; local_24 < 4; local_24 = local_24 + 1) {
          *(undefined4 *)(param_1 + 0x210 + local_24 * 4) =
               *(undefined4 *)(param_1 + 0x200 + local_24 * 4);
          *(undefined4 *)(param_1 + 0x230 + local_24 * 4) =
               *(undefined4 *)(param_1 + 0x220 + local_24 * 4);
        }
        *(undefined4 *)(param_1 + 0x19c) = *(undefined4 *)(param_1 + 0x198);
        *(undefined4 *)(param_1 + 0x1a4) = *(undefined4 *)(param_1 + 0x1a0);
        *(undefined4 *)(param_1 + 0x1ac) = *(undefined4 *)(param_1 + 0x1a8);
        *(undefined4 *)(param_1 + 0x1d4) = *(undefined4 *)(param_1 + 0x1d0);
        *(undefined4 *)(param_1 + 0x1dc) = *(undefined4 *)(param_1 + 0x1d8);
        *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 0x1b8);
        for (local_28 = 0; local_28 < 3; local_28 = local_28 + 1) {
          *(undefined4 *)(param_1 + 0x1ec + local_28 * 4) =
               *(undefined4 *)(param_1 + 0x1e0 + local_28 * 4);
        }
      }
      else {
        for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
          *(int *)(param_1 + 0x210 + local_1c * 4) =
               ((*(int *)(param_1 + 0x210 + local_1c * 4) - *(int *)(param_1 + 0x200 + local_1c * 4)
                ) * *(int *)(param_1 + 0x1b0)) / *(int *)(param_1 + 0x1b4) +
               *(int *)(param_1 + 0x200 + local_1c * 4);
          *(int *)(param_1 + 0x230 + local_1c * 4) =
               ((*(int *)(param_1 + 0x230 + local_1c * 4) - *(int *)(param_1 + 0x220 + local_1c * 4)
                ) * *(int *)(param_1 + 0x1b0)) / *(int *)(param_1 + 0x1b4) +
               *(int *)(param_1 + 0x220 + local_1c * 4);
        }
        *(int *)(param_1 + 0x1d4) =
             ((*(int *)(param_1 + 0x1d4) - *(int *)(param_1 + 0x1d0)) * *(int *)(param_1 + 0x1b0)) /
             *(int *)(param_1 + 0x1b4) + *(int *)(param_1 + 0x1d0);
        *(int *)(param_1 + 0x1dc) =
             ((*(int *)(param_1 + 0x1dc) - *(int *)(param_1 + 0x1d8)) * *(int *)(param_1 + 0x1b0)) /
             *(int *)(param_1 + 0x1b4) + *(int *)(param_1 + 0x1d8);
        iVar2 = FUN_004fe844();
        *(int *)(param_1 + 0x1bc) = iVar2 + *(int *)(param_1 + 0x1b8);
        for (local_20 = 0; local_20 < 3; local_20 = local_20 + 1) {
          *(int *)(param_1 + 0x1ec + local_20 * 4) =
               ((*(int *)(param_1 + 0x1ec + local_20 * 4) - *(int *)(param_1 + 0x1e0 + local_20 * 4)
                ) * *(int *)(param_1 + 0x1b0)) / *(int *)(param_1 + 0x1b4) +
               *(int *)(param_1 + 0x1e0 + local_20 * 4);
        }
      }
      *(undefined2 *)(param_1 + 0x26a) = *(undefined2 *)(param_1 + 0x268);
      if (param_13 == 0) {
        iVar2 = *(int *)(param_1 + 0x210) + *(int *)(param_1 + 0x214) + *(int *)(param_1 + 0x218) +
                *(int *)(param_1 + 0x21c);
        local_30 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
        iVar2 = *(int *)(param_1 + 0x230) + *(int *)(param_1 + 0x234) + *(int *)(param_1 + 0x238) +
                *(int *)(param_1 + 0x23c);
        local_34 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
        local_2c = param_2 - local_30;
        local_38 = param_3 - local_34;
        *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x210) + local_2c;
        *(int *)(param_1 + 0x204) = *(int *)(param_1 + 0x214) + local_2c;
        *(int *)(param_1 + 0x208) = *(int *)(param_1 + 0x218) + local_2c;
        *(int *)(param_1 + 0x20c) = *(int *)(param_1 + 0x21c) + local_2c;
        *(int *)(param_1 + 0x220) = *(int *)(param_1 + 0x230) + local_38;
        *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x234) + local_38;
        *(int *)(param_1 + 0x228) = *(int *)(param_1 + 0x238) + local_38;
        *(int *)(param_1 + 0x22c) = *(int *)(param_1 + 0x23c) + local_38;
      }
      else {
        *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x210) + param_2;
        *(int *)(param_1 + 0x204) = *(int *)(param_1 + 0x214) + param_2;
        *(int *)(param_1 + 0x208) = *(int *)(param_1 + 0x218) + param_2;
        *(int *)(param_1 + 0x20c) = *(int *)(param_1 + 0x21c) + param_2;
        *(int *)(param_1 + 0x220) = *(int *)(param_1 + 0x230) + param_3;
        *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x234) + param_3;
        *(int *)(param_1 + 0x228) = *(int *)(param_1 + 0x238) + param_3;
        *(int *)(param_1 + 0x22c) = *(int *)(param_1 + 0x23c) + param_3;
      }
    }
    if (param_4 != -1000000) {
      *(int *)(param_1 + 0x198) = param_4;
    }
    if (param_5 != -1000000) {
      *(int *)(param_1 + 0x1a0) = param_5;
    }
    if (param_6 != 0xf) {
      *(int *)(param_1 + 0x1a8) = param_6;
    }
    if ((param_8 != -1000000) && (param_9 != -1000000)) {
      *(int *)(param_1 + 0x1d0) = param_8;
    }
    if ((param_8 != -1000000) && (param_9 != -1000000)) {
      *(int *)(param_1 + 0x1d8) = param_9;
    }
    if (param_10 != -1000000) {
      *(int *)(param_1 + 0x1b8) = param_10;
    }
    if ((param_11 & 0x1000000) == 0) {
      uVar1 = FUN_004fe844();
      *(undefined4 *)(param_1 + 0x1e0) = uVar1;
      uVar1 = FUN_004fe844();
      *(undefined4 *)(param_1 + 0x1e4) = uVar1;
      uVar1 = FUN_004fe844();
      *(undefined4 *)(param_1 + 0x1e8) = uVar1;
    }
    if (*(char *)(param_1 + 0x264) != '\0') {
      local_40 = 0;
      local_3c = 0;
      FUN_004a1c60();
      *(undefined4 *)(param_1 + 0x1c0) = local_40;
      *(undefined4 *)(param_1 + 0x1c8) = local_3c;
    }
    if ((((*(char *)(param_1 + 0x264) == '\0') && (*(char *)(param_1 + 0x265) == '\0')) &&
        (iVar2 = FUN_004ce080(), iVar2 < *(int *)(param_1 + 0x198))) &&
       (iVar2 = FUN_004ce080(), iVar2 != 0)) {
      FUN_004ce080();
      basic_string<>();
      _Format = (char *)FUN_00401c50();
      _sprintf(local_148,_Format);
      FUN_00438b60();
      local_8 = 2;
      basic_string<>();
      FUN_00401c50();
      basic_string<>();
      local_8 = CONCAT31(local_8._1_3_,3);
      basic_string<>(local_148);
      local_8 = 0xffffffff;
      FUN_0042bed0();
    }
    else {
      *(undefined4 *)(param_1 + 0x1b0) = param_7;
      *(undefined4 *)(param_1 + 0x1b4) = param_7;
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
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_174);
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
  }
  ExceptionList = local_10;
  return;
}

