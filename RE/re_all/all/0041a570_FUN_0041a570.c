
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_0041a570(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_2)

{
  byte bVar1;
  char *pcVar2;
  void *pvVar3;
  __time32_t _Var4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  undefined1 uStack00000000;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> bStack00000024;
  int in_stack_00000040;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> bStack00000044;
  size_t sVar8;
  char *pcVar9;
  uint local_104;
  int local_100;
  int local_fc;
  char local_ed;
  undefined1 local_ec [24];
  FILE *local_d4;
  size_t local_d0;
  char local_cc [24];
  FILE *local_b4;
  int local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  char local_9d;
  int local_9c;
  uint local_98;
  undefined1 local_92;
  undefined1 local_91;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_90 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_74 [28];
  int local_58;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_54 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_38 [28];
  undefined4 local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007abd32;
  local_10 = ExceptionList;
  local_1c = DAT_0084b484;
  local_8 = 3;
  ExceptionList = &local_10;
  FUN_0041b8f0(local_90);
  local_8._0_1_ = 4;
  pcVar2 = (char *)FUN_004cbb30();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_90,pcVar2);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_90,"GameFile.");
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_90,"data");
  local_58 = 10;
  local_14 = 0x14;
  local_18 = 0x4529;
  basic_string<>();
  local_8._0_1_ = 5;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::resize(local_54,10);
  pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
           operator[]((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_54,0);
  *pcVar2 = -0x1b;
  pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
           operator[]((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_54,1);
  *pcVar2 = -0x13;
  pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
           operator[]((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_54,2);
  *pcVar2 = -0x5f;
  pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
           operator[]((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_54,3);
  *pcVar2 = -100;
  pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
           operator[]((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_54,4);
  *pcVar2 = -0x46;
  pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
           operator[]((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_54,5);
  *pcVar2 = '_';
  pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
           operator[]((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_54,6);
  *pcVar2 = -0x66;
  pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
           operator[]((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_54,7);
  *pcVar2 = 'c';
  pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
           operator[]((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_54,8);
  *pcVar2 = '\x0f';
  basic_string<>();
  local_8._0_1_ = 6;
  basic_string<>();
  local_8._0_1_ = 7;
  if (in_stack_00000040 == 1) {
    DAT_00a11790 = 0;
    if (DAT_00a117ec == 0) {
      DAT_00a0f830 = _malloc(0xfa000);
      _memset(DAT_00a0f830,0,0xfa000);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = FUN_004e5650();
      sVar8 = DAT_00a1179c;
      pvVar3 = (void *)FUN_004cbb30();
      _memcpy((void *)((int)DAT_00a0f830 + DAT_00a11790),pvVar3,sVar8);
    }
    FUN_004e5650();
    DAT_00a11790 = local_58 + -1;
    local_91 = FUN_004e5650();
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy((void *)((int)DAT_00a0f830 + DAT_00a11790),&local_91,1);
    }
    DAT_00a11790 = local_58 + -2;
    local_91 = FUN_004e5650();
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy((void *)((int)DAT_00a0f830 + DAT_00a11790),&local_91,1);
    }
    DAT_00a11790 = local_58;
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = FUN_004e5650();
      sVar8 = DAT_00a1179c;
      pvVar3 = (void *)FUN_004cbb30();
      _memcpy((void *)((int)DAT_00a0f830 + DAT_00a11790),pvVar3,sVar8);
    }
    FUN_004e5650();
    DAT_00a11790 = local_14;
    _Var4 = FID_conflict___time32((__time32_t *)0x0);
    FUN_004fcb44(_Var4);
    for (local_9c = 0; local_9c < local_18; local_9c = local_9c + 1) {
      iVar5 = _rand();
      local_9d = (char)(iVar5 % 0xff) + '\x01';
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 1;
        _memcpy((void *)((int)DAT_00a0f830 + DAT_00a11790),&local_9d,1);
      }
      DAT_00a11790 = DAT_00a11790 + 1;
    }
    uVar7 = local_18 - 1000;
    local_98 = FUN_004e5650();
    local_98 = uVar7 / local_98;
    local_a4 = 0;
    while (uVar7 = FUN_004e5650(), local_a4 < uVar7) {
      pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               operator[](&param_2,local_a4);
      *(char *)((int)DAT_00a0f830 + local_98 * local_a4 + local_14) = *pcVar2;
      local_a4 = local_a4 + 1;
    }
    local_a8 = 0;
    while (uVar7 = FUN_004e5650(), local_a8 < uVar7) {
      pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               operator[](&bStack00000044,local_a8);
      *(char *)((int)DAT_00a0f830 + local_14 + local_98 * local_a8 + 0x20) = *pcVar2;
      local_a8 = local_a8 + 1;
    }
    local_ac = 0;
    while (uVar7 = FUN_004e5650(), local_ac < uVar7) {
      pbVar6 = (byte *)std::
                       basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                       operator[](&bStack00000044,local_ac);
      *(byte *)((int)DAT_00a0f830 + local_14 + local_98 * local_ac + 0x40) = *pbVar6 ^ 0xff;
      local_ac = local_ac + 1;
    }
    FUN_004fcb44(*(undefined1 *)((int)DAT_00a0f830 + 4));
    for (local_b0 = local_58; local_b0 < local_14 + local_18; local_b0 = local_b0 + 1) {
      bVar1 = *(byte *)((int)DAT_00a0f830 + local_b0);
      uVar7 = _rand();
      *(byte *)((int)DAT_00a0f830 + local_b0) = bVar1 ^ (byte)((int)(uVar7 & 0xff000) >> 0xc);
    }
    local_92 = 0x91;
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy((void *)((int)DAT_00a0f830 + DAT_00a11790),&local_92,1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    pcVar9 = "wb";
    pcVar2 = (char *)FUN_004cbb30();
    local_b4 = _fopen(pcVar2,pcVar9);
    if (local_b4 == (FILE *)0x0) {
      if (DAT_00a117ec == 0) {
        _free(DAT_00a0f830);
      }
      basic_string<>("FILE CAN\'T OPEN.");
      local_8._0_1_ = 6;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_38);
      local_8._0_1_ = 5;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_74);
      local_8._0_1_ = 4;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_54);
      local_8._0_1_ = 3;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_90);
      local_8._0_1_ = 2;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
      local_8._0_1_ = 1;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000024);
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000044);
      ExceptionList = local_10;
      return param_1;
    }
    _fwrite(DAT_00a0f830,DAT_00a11790,1,local_b4);
    _fclose(local_b4);
    if (DAT_00a117ec == 0) {
      _free(DAT_00a0f830);
    }
    basic_string<>(&DAT_007cbacc);
    local_8._0_1_ = 6;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_38);
    local_8._0_1_ = 5;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_74);
    local_8._0_1_ = 4;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_54
              );
    local_8._0_1_ = 3;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_90
              );
    local_8._0_1_ = 2;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
    local_8._0_1_ = 1;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000024);
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000044);
    ExceptionList = local_10;
    return param_1;
  }
  if ((in_stack_00000040 == 0) || (in_stack_00000040 == 10)) {
    pcVar9 = "rb";
    pcVar2 = (char *)FUN_004cbb30();
    local_d4 = _fopen(pcVar2,pcVar9);
    if (local_d4 == (FILE *)0x0) {
      basic_string<>(&DAT_007cbad3);
      local_8._0_1_ = 6;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_38);
      local_8._0_1_ = 5;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_74);
      local_8._0_1_ = 4;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_54);
      local_8._0_1_ = 3;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_90);
      local_8._0_1_ = 2;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
      local_8._0_1_ = 1;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000024);
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000044);
      ExceptionList = local_10;
      return param_1;
    }
    _fseek(local_d4,0,2);
    local_d0 = _ftell(local_d4);
    _fseek(local_d4,0,0);
    DAT_00a11790 = 0;
    if (DAT_00a117ec == 0) {
      DAT_00a0f830 = _malloc(local_d0);
      _memset(DAT_00a0f830,0,local_d0);
    }
    _fread(DAT_00a0f830,local_d0,1,local_d4);
    _fclose(local_d4);
    DAT_00a11790 = local_14;
    FUN_004fcb44(*(undefined1 *)((int)DAT_00a0f830 + 4));
    for (local_fc = local_58; local_fc < local_14 + local_18; local_fc = local_fc + 1) {
      bVar1 = *(byte *)((int)DAT_00a0f830 + local_fc);
      uVar7 = _rand();
      *(byte *)((int)DAT_00a0f830 + local_fc) = bVar1 ^ (byte)((int)(uVar7 & 0xff000) >> 0xc);
    }
    FUN_004cb9c0();
    bVar1 = *(byte *)((int)DAT_00a0f830 + local_58 + -1);
    iVar5 = local_18 + -1000;
    for (local_100 = 0; local_100 < (int)(uint)*(byte *)((int)DAT_00a0f830 + local_58 + -1);
        local_100 = local_100 + 1) {
      FUN_004cbb00(*(undefined1 *)
                    ((int)DAT_00a0f830 + (iVar5 / (int)(uint)bVar1) * local_100 + local_14));
    }
    DAT_00a11790 = local_14 + local_18;
    if (&uStack00000000 == (undefined1 *)0xed) {
      __CxxThrowException_8(0xffffffe5,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy(&local_ed,(void *)((int)DAT_00a0f830 + DAT_00a11790),1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if (local_ed != -0x6f) {
      if (DAT_00a117ec == 0) {
        _free(DAT_00a0f830);
      }
      basic_string<>(&DAT_007cbad4);
      local_8._0_1_ = 6;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_38);
      local_8._0_1_ = 5;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_74);
      local_8._0_1_ = 4;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_54);
      local_8._0_1_ = 3;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_90);
      local_8._0_1_ = 2;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
      local_8._0_1_ = 1;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000024);
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000044);
      ExceptionList = local_10;
      return param_1;
    }
    _memcpy(local_ec,(void *)((int)DAT_00a0f830 + local_58),5);
    if (DAT_00a117ec == 0) {
      _free(DAT_00a0f830);
    }
    for (local_104 = 0; uVar7 = FUN_004e5650(), local_104 < uVar7; local_104 = local_104 + 1) {
      pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               operator[](local_74,local_104);
      local_cc[local_104] = *pcVar2;
      local_cc[local_104 + 1] = '\0';
    }
    FUN_0052db00(local_ec);
    thunk_FUN_00570070(local_cc);
    if (in_stack_00000040 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                (param_1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                          *)local_74);
      local_8._0_1_ = 6;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_38);
      local_8._0_1_ = 5;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_74);
      local_8._0_1_ = 4;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_54);
      local_8._0_1_ = 3;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_90);
      local_8._0_1_ = 2;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
      local_8._0_1_ = 1;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000024);
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000044);
      ExceptionList = local_10;
      return param_1;
    }
    if (in_stack_00000040 == 10) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                (param_1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                          *)local_38);
      local_8._0_1_ = 6;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_38);
      local_8._0_1_ = 5;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_74);
      local_8._0_1_ = 4;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_54);
      local_8._0_1_ = 3;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_90);
      local_8._0_1_ = 2;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
      local_8._0_1_ = 1;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000024);
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000044);
      ExceptionList = local_10;
      return param_1;
    }
  }
  basic_string<>(&DAT_007cbad5);
  local_8._0_1_ = 6;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_38);
  local_8._0_1_ = 5;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_74);
  local_8._0_1_ = 4;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_54);
  local_8._0_1_ = 3;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_90);
  local_8._0_1_ = 2;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  local_8._0_1_ = 1;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000024);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000044);
  ExceptionList = local_10;
  return param_1;
}

