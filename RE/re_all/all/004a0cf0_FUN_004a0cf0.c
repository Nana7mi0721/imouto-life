
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
FUN_004a0cf0(int param_1,int *param_2,int *param_3,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_4,
            undefined4 *param_5,undefined4 *param_6,undefined4 *param_7,undefined4 *param_8,
            undefined4 *param_9,undefined4 *param_10,undefined4 *param_11,undefined4 *param_12,
            undefined4 *param_13,undefined4 *param_14,undefined4 *param_15,undefined4 *param_16)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_478 [2];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_476 [14];
  undefined4 uStack_468;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_460 [4];
  undefined4 uStack_45c;
  undefined4 uStack_458;
  undefined4 uStack_454;
  undefined4 uStack_450;
  undefined4 uStack_44c;
  undefined1 *puStack_448;
  undefined4 uStack_444;
  undefined4 uStack_440;
  undefined4 uStack_43c;
  undefined1 *puStack_438;
  undefined1 *puStack_434;
  int *piStack_430;
  undefined1 local_3e4 [4];
  undefined1 local_3e0 [4];
  undefined1 local_3dc [912];
  undefined1 *local_4c;
  undefined1 *local_48;
  undefined1 *local_44;
  undefined1 *local_40;
  int local_3c;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_38 [28];
  undefined4 local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007afa79;
  local_10 = ExceptionList;
  local_1c = DAT_0084b484;
  piStack_430 = (int *)0x4a0d2d;
  ExceptionList = &local_10;
  iVar1 = FUN_004febf1();
  if (9999 < iVar1) {
    basic_string<>();
    local_8 = 0;
    piStack_430 = (int *)0x4a0d55;
    pcVar2 = (char *)FUN_0041b5f0();
    piStack_430 = (int *)0x4a0d61;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_38,pcVar2)
    ;
    piStack_430 = (int *)0x4a0d6e;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_38," - ");
    piStack_430 = (int *)0x4a0d79;
    pcVar2 = (char *)FUN_0041b5f0();
    piStack_430 = (int *)0x4a0d85;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_38,pcVar2)
    ;
    local_40 = (undefined1 *)&uStack_444;
    puStack_448 = (undefined1 *)&uStack_444;
    uStack_44c = 0x4a0d93;
    FUN_00438b60();
    local_8._0_1_ = 1;
    local_44 = abStack_460;
    uStack_468 = 0x4a0dbd;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              (abStack_460,
               (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_38);
    local_8._0_1_ = 2;
    local_4c = abStack_478 + -4;
    basic_string<>(&DAT_007d1098);
    uVar3 = FUN_00401c50();
    local_48 = abStack_478 + -4;
    basic_string<>(uVar3);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0042bed0();
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_38
              );
  }
  local_18 = 0;
  piStack_430 = param_2;
  puStack_434 = (undefined1 *)0x4a0e48;
  FUN_0049b960();
  local_14 = 0;
  local_3c = local_18;
  do {
    if (((local_18 + *param_3) - *param_2) + 1 <= local_3c) {
      FUN_0049ed50();
      ExceptionList = local_10;
      return;
    }
    uVar3 = FUN_004d3180();
    *(undefined4 *)(param_1 + 0x10) = uVar3;
    if (local_3c < *(int *)(param_1 + 0x10)) {
      piStack_430 = (int *)0x4a0eb3;
      iVar1 = FUN_004d31e0();
      if (*(int *)(iVar1 + 0x26c) != *param_2 + local_14) goto LAB_004a0ec7;
      piStack_430 = (int *)0x4a1009;
      iVar1 = FUN_004d31e0();
      if (*(int *)(iVar1 + 0x26c) == *param_2 + local_14) {
        piStack_430 = (int *)*param_16;
        puStack_434 = (undefined1 *)*param_15;
        puStack_438 = (undefined1 *)*param_14;
        uStack_43c = *param_13;
        uStack_440 = *param_12;
        uStack_444 = *param_11;
        puStack_448 = (undefined1 *)*param_10;
        uStack_44c = *param_9;
        uStack_450 = *param_8;
        uStack_454 = *param_7;
        uStack_458 = *param_6;
        uStack_45c = *param_5;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_478,param_4);
        local_8 = 5;
        FUN_004d31e0();
        local_8 = 0xffffffff;
        FUN_004a1150();
      }
    }
    else {
LAB_004a0ec7:
      piStack_430 = (int *)0x4a0ed4;
      FUN_0049bf10();
      local_8 = 3;
      piStack_430 = (int *)local_3c;
      puStack_434 = local_3e0;
      puStack_438 = local_3dc;
      uStack_43c = 0x4a0f11;
      FUN_004ce060();
      puStack_438 = (undefined1 *)0x4a0f18;
      puVar4 = (undefined4 *)FUN_004d3330();
      piStack_430 = (int *)*puVar4;
      puStack_434 = local_3e4;
      puStack_438 = (undefined1 *)0x4a0f2d;
      FUN_004d3220();
      local_8 = 0xffffffff;
      FUN_0049eca0();
      iVar5 = *param_2 + local_14;
      piStack_430 = (int *)0x4a0f56;
      iVar1 = FUN_004d31e0();
      *(int *)(iVar1 + 0x26c) = iVar5;
      piStack_430 = (int *)*param_16;
      puStack_434 = (undefined1 *)*param_15;
      puStack_438 = (undefined1 *)*param_14;
      uStack_43c = *param_13;
      uStack_440 = *param_12;
      uStack_444 = *param_11;
      puStack_448 = (undefined1 *)*param_10;
      uStack_44c = *param_9;
      uStack_450 = *param_8;
      uStack_454 = *param_7;
      uStack_458 = *param_6;
      uStack_45c = *param_5;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_478,param_4);
      local_8 = 4;
      FUN_004d31e0();
      local_8 = 0xffffffff;
      FUN_004a1150();
    }
    piStack_430 = (int *)0x4a10c5;
    iVar1 = FUN_004d31e0();
    *(undefined4 *)(iVar1 + 0x35c) = DAT_00a17eb8;
    piStack_430 = (int *)0x4a10e0;
    iVar1 = FUN_004d31e0();
    *(undefined4 *)(iVar1 + 0x360) = DAT_00a0f818;
    piStack_430 = (int *)0x4a10fb;
    iVar1 = FUN_004d31e0();
    *(undefined4 *)(iVar1 + 0x364) = DAT_00a11794;
    piStack_430 = (int *)0x4a1116;
    iVar1 = FUN_004d31e0();
    *(undefined4 *)(iVar1 + 0x368) = DAT_00a0f814;
    local_3c = local_3c + 1;
    local_14 = local_14 + 1;
  } while( true );
}

