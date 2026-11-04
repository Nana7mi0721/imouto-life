
void __thiscall
FUN_004a1150(undefined4 *param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_stack_00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  int in_stack_0000002c;
  uint in_stack_00000030;
  undefined4 in_stack_00000034;
  int in_stack_00000038;
  int in_stack_0000003c;
  int in_stack_00000040;
  undefined2 in_stack_00000044;
  uint in_stack_00000048;
  int in_stack_0000004c;
  int in_stack_00000050;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_8c [24];
  undefined4 uStack_74;
  undefined4 *puStack_70;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007afb20;
  local_10 = ExceptionList;
  local_8 = 0;
  if (in_stack_0000004c < 1) {
    ExceptionList = &local_10;
    *(undefined1 *)((int)param_1 + 0x27a) = 0;
    *(undefined1 *)(param_1 + 0x9e) = 0;
    *(undefined1 *)((int)param_1 + 0x279) = 0;
    *(undefined1 *)(param_1 + 0x99) = 1;
    *(undefined1 *)((int)param_1 + 0x265) = 0;
    param_1[0xdf] = 0xffffffff;
    param_1[0xe1] = 1;
    if ((in_stack_00000030 & 0x100) != 0) {
      if ((in_stack_00000050 == 0) ||
         ((in_stack_00000050 != 0 && (*(char *)((int)param_1 + 0x266) == '\0')))) {
        in_stack_00000020 =
             ((int)(DAT_00a17ebc + (DAT_00a17ebc >> 0x1f & 3U)) >> 2) + in_stack_00000020;
        in_stack_00000024 =
             ((int)(DAT_00a17ec0 + (DAT_00a17ec0 >> 0x1f & 3U)) >> 2) + in_stack_00000024;
      }
      *(undefined1 *)((int)param_1 + 0x266) = 1;
    }
    if (((*(char *)((int)param_1 + 0x266) != '\0') && ((in_stack_00000030 & 0x100) == 0)) &&
       (*(undefined1 *)((int)param_1 + 0x266) = 0, in_stack_00000050 != 0)) {
      in_stack_00000020 =
           in_stack_00000020 - ((int)(DAT_00a17ebc + (DAT_00a17ebc >> 0x1f & 3U)) >> 2);
      in_stack_00000024 =
           in_stack_00000024 - ((int)(DAT_00a17ec0 + (DAT_00a17ec0 >> 0x1f & 3U)) >> 2);
    }
    in_stack_00000030 = in_stack_00000030 & 0xf;
    *(undefined1 *)(param_1 + 0x28) = 0;
    puStack_70 = (undefined4 *)0x4a1589;
    FUN_004cb840();
    puStack_70 = (undefined4 *)0x4a1599;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x10),
               "");
    puStack_70 = param_1 + 0x54;
    uStack_74 = 0x4a15ac;
    cVar1 = operator!=<>();
    if (cVar1 != '\0') {
      puStack_70 = (undefined4 *)0x1;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                (abStack_8c,
                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 (param_1 + 0x54));
      FUN_004361d0();
    }
    puStack_70 = (undefined4 *)0x4a15ef;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x54),
               "");
    puStack_70 = (undefined4 *)0x4a1602;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x5b),
               "");
    param_1[1] = 0;
    *param_1 = 0;
    FUN_0049ec50();
    if ((int)param_1[0x6c] < 1) {
      param_1[99] = param_1[0x62];
      param_1[0x65] = param_1[100];
      param_1[0x67] = param_1[0x66];
      param_1[0x69] = 0;
      param_1[0x6b] = param_1[0x6a];
      param_1[0x75] = param_1[0x74];
      param_1[0x77] = param_1[0x76];
      param_1[0x6f] = param_1[0x6e];
      for (local_20 = 0; local_20 < 3; local_20 = local_20 + 1) {
        param_1[local_20 + 0x7b] = param_1[local_20 + 0x78];
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
      param_1[0x6f] =
           (int)((param_1[0x6f] - param_1[0x6e]) * param_1[0x6c]) / (int)param_1[0x6d] +
           param_1[0x6e];
      for (local_1c = 0; local_1c < 3; local_1c = local_1c + 1) {
        param_1[local_1c + 0x7b] =
             (int)((param_1[local_1c + 0x7b] - param_1[local_1c + 0x78]) * param_1[0x6c]) /
             (int)param_1[0x6d] + param_1[local_1c + 0x78];
      }
    }
    *(undefined2 *)((int)param_1 + 0x26a) = *(undefined2 *)(param_1 + 0x9a);
    if (in_stack_00000050 == 0) {
      param_1[0x62] = in_stack_00000020;
      param_1[100] = in_stack_00000024;
    }
    else {
      param_1[0x62] = param_1[99] + in_stack_00000020;
      param_1[100] = param_1[0x65] + in_stack_00000024;
    }
    if (in_stack_00000028 != -1000000) {
      param_1[0x66] = in_stack_00000028;
    }
    if (in_stack_0000002c != -1000000) {
      param_1[0x68] = in_stack_0000002c;
    }
    if (in_stack_00000030 != 0xf) {
      param_1[0x6a] = in_stack_00000030;
    }
    if (in_stack_00000038 != -1000000) {
      param_1[0x74] = in_stack_00000038;
    }
    if (in_stack_0000003c != -1000000) {
      param_1[0x76] = in_stack_0000003c;
    }
    if (in_stack_00000040 != -1000000) {
      param_1[0x6e] = in_stack_00000040;
    }
    *(undefined2 *)(param_1 + 0x9a) = in_stack_00000044;
    if ((in_stack_00000048 & 0x1000000) == 0) {
      uVar3 = FUN_004fe844();
      param_1[0x78] = uVar3;
      uVar3 = FUN_004fe844();
      param_1[0x79] = uVar3;
      uVar3 = FUN_004fe844();
      param_1[0x7a] = uVar3;
    }
    if (param_1[1] == 0) {
      param_1[99] = in_stack_00000020;
      param_1[0x65] = in_stack_00000024;
      param_1[0x67] = in_stack_00000028;
      param_1[0x69] = 0;
      param_1[0x6b] = in_stack_00000030;
      param_1[0x75] = param_1[0x74];
      param_1[0x77] = param_1[0x76];
      param_1[0x6f] = in_stack_00000040;
      *(undefined2 *)((int)param_1 + 0x26a) = *(undefined2 *)(param_1 + 0x9a);
      if ((in_stack_00000048 & 0x1000000) == 0) {
        uVar3 = FUN_004fe844();
        param_1[0x7b] = uVar3;
        uVar3 = FUN_004fe844();
        param_1[0x7c] = uVar3;
        uVar3 = FUN_004fe844();
        param_1[0x7d] = uVar3;
      }
    }
    param_1[0x17] = (float)(int)param_1[99];
    param_1[0x18] = (float)(int)param_1[0x65];
    param_1[0x6c] = in_stack_00000034;
    param_1[0x6d] = in_stack_00000034;
    param_1[0x71] = param_1[0x70];
    param_1[0x73] = param_1[0x72];
    *(double *)(param_1 + 0x22) = (double)DAT_00a18adc;
    local_18 = 0;
    local_14 = 0;
    puStack_70 = &local_18;
    uStack_74 = 0x4a1bba;
    FUN_004a1c60();
    param_1[0x70] = local_18;
    param_1[0x72] = local_14;
    if (param_1[1] == 0) {
      param_1[0x71] = param_1[0x70];
      param_1[0x73] = param_1[0x72];
    }
    param_1[0x71] = param_1[0x70];
    param_1[0x73] = param_1[0x72];
    param_1[0x7f] = 0;
    param_1[0x7e] = 0;
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  }
  else {
    puStack_70 = (undefined4 *)0x4a118a;
    ExceptionList = &local_10;
    FUN_004cdf50();
    local_8._0_1_ = 1;
    puStack_70 = (undefined4 *)0x4a11a9;
    FUN_004cd3f0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_004ce950();
    puStack_70 = (undefined4 *)0x4a11c7;
    FUN_004cc500();
    FUN_004cd340();
    puStack_70 = (undefined4 *)0x4a11e7;
    FUN_004cde80();
    FUN_004ce950();
    puStack_70 = (undefined4 *)0x4a1200;
    iVar2 = FUN_004cd340();
    puStack_70 = (undefined4 *)(iVar2 + -1);
    uStack_74 = 0x4a1212;
    FUN_004cde80();
    puStack_70 = (undefined4 *)0x4a1219;
    FUN_004ce160();
    puStack_70 = (undefined4 *)0x4a1232;
    iVar2 = FUN_004cd340();
    puStack_70 = (undefined4 *)(iVar2 + -1);
    uStack_74 = 0x4a1244;
    FUN_004cde80();
    puStack_70 = (undefined4 *)0x4a124b;
    FUN_004ce160();
    puStack_70 = (undefined4 *)0x4a125d;
    iVar2 = FUN_004cd340();
    puStack_70 = (undefined4 *)(iVar2 + -1);
    uStack_74 = 0x4a126f;
    FUN_004cde80();
    puStack_70 = (undefined4 *)0x4a1276;
    FUN_004ce160();
    puStack_70 = (undefined4 *)0x4a1288;
    iVar2 = FUN_004cd340();
    puStack_70 = (undefined4 *)(iVar2 + -1);
    uStack_74 = 0x4a129a;
    FUN_004cde80();
    puStack_70 = (undefined4 *)0x4a12a1;
    FUN_004ce160();
    puStack_70 = (undefined4 *)0x4a12b3;
    iVar2 = FUN_004cd340();
    puStack_70 = (undefined4 *)(iVar2 + -1);
    uStack_74 = 0x4a12c5;
    FUN_004cde80();
    puStack_70 = (undefined4 *)0x4a12cc;
    FUN_004ce160();
    puStack_70 = (undefined4 *)0x4a12de;
    iVar2 = FUN_004cd340();
    puStack_70 = (undefined4 *)(iVar2 + -1);
    uStack_74 = 0x4a12f0;
    FUN_004cde80();
    puStack_70 = (undefined4 *)0x4a12f7;
    FUN_004ce160();
    puStack_70 = (undefined4 *)0x4a1309;
    iVar2 = FUN_004cd340();
    puStack_70 = (undefined4 *)(iVar2 + -1);
    uStack_74 = 0x4a131b;
    FUN_004cde80();
    puStack_70 = (undefined4 *)0x4a1322;
    FUN_004ce160();
    puStack_70 = (undefined4 *)0x4a1334;
    iVar2 = FUN_004cd340();
    puStack_70 = (undefined4 *)(iVar2 + -1);
    uStack_74 = 0x4a1346;
    FUN_004cde80();
    puStack_70 = (undefined4 *)0x4a134d;
    FUN_004ce160();
    puStack_70 = (undefined4 *)0x4a135f;
    iVar2 = FUN_004cd340();
    puStack_70 = (undefined4 *)(iVar2 + -1);
    uStack_74 = 0x4a1371;
    FUN_004cde80();
    puStack_70 = (undefined4 *)0x4a1378;
    FUN_004ce160();
    puStack_70 = (undefined4 *)0x4a138a;
    iVar2 = FUN_004cd340();
    puStack_70 = (undefined4 *)(iVar2 + -1);
    uStack_74 = 0x4a139c;
    FUN_004cde80();
    puStack_70 = (undefined4 *)0x4a13a3;
    FUN_004ce160();
    puStack_70 = (undefined4 *)0x4a13b5;
    iVar2 = FUN_004cd340();
    puStack_70 = (undefined4 *)(iVar2 + -1);
    uStack_74 = 0x4a13c7;
    FUN_004cde80();
    puStack_70 = (undefined4 *)0x4a13ce;
    FUN_004ce160();
    puStack_70 = (undefined4 *)0x4a13e0;
    iVar2 = FUN_004cd340();
    puStack_70 = (undefined4 *)(iVar2 + -1);
    uStack_74 = 0x4a13f2;
    FUN_004cde80();
    puStack_70 = (undefined4 *)0x4a13f9;
    FUN_004ce160();
    puStack_70 = (undefined4 *)0x4a140b;
    iVar2 = FUN_004cd340();
    puStack_70 = (undefined4 *)(iVar2 + -1);
    uStack_74 = 0x4a141d;
    FUN_004cde80();
    puStack_70 = (undefined4 *)0x4a1424;
    FUN_004ce160();
    puStack_70 = (undefined4 *)0x4a1442;
    iVar2 = FUN_004cd340();
    puStack_70 = (undefined4 *)(iVar2 + -1);
    uStack_74 = 0x4a1454;
    FUN_004cde80();
    puStack_70 = (undefined4 *)0x4a145b;
    FUN_004ce160();
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  }
  ExceptionList = local_10;
  return;
}

