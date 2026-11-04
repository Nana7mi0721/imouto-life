
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00494480(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *param_1,
            char param_2,double param_3,double param_4,double param_5)

{
  byte bVar1;
  byte bVar2;
  double dVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char cVar6;
  char *pcVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int iVar11;
  byte *pbVar12;
  int *piVar13;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  undefined8 uStack_888;
  undefined8 uStack_87c;
  undefined4 uStack_874;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_870;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_86c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_868;
  int local_858;
  int local_718;
  int local_714;
  int local_710;
  int local_70c;
  int local_5d0;
  int local_5cc;
  int local_5c8;
  int local_39c;
  int local_2a0;
  int local_29c;
  int local_284;
  undefined4 local_280;
  undefined4 local_27c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_258 [28];
  undefined1 *local_23c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_238 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_21c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_200 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1e4 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1c8 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1ac [28];
  int local_190;
  int local_18c;
  int local_188;
  int local_184;
  int local_180;
  int local_17c;
  int local_178;
  undefined4 local_174;
  undefined4 local_170;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_16c [28];
  int local_150;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *local_14c;
  char local_145;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  undefined4 local_134;
  int local_130;
  int local_12c;
  int local_128;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_124 [28];
  int local_108;
  int local_104;
  int local_100;
  undefined4 local_fc;
  int local_f8;
  undefined1 local_f1;
  int local_f0;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_ec [28];
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  uint local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  uint local_a0;
  int local_9c;
  int local_98;
  LPSTR local_94;
  int local_90;
  char local_89;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_88 [28];
  int local_6c;
  undefined4 local_68;
  int local_64;
  int local_60;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *local_5c;
  int local_58;
  undefined4 local_54;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_50 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *local_34;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af7ff;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  pbStack_868 = param_1 + 0x1c;
  pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                0x4944c2;
  ExceptionList = &local_10;
  cVar6 = FUN_004ec750();
  if (cVar6 != '\0') {
    ExceptionList = local_10;
    return;
  }
  pbStack_868 = param_1 + 0x1c;
  pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                0x4944ea;
  cVar6 = operator!=<>();
  if (cVar6 == '\0') {
    pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x494501;
    pcVar7 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
             operator[](param_1,0);
    if (*pcVar7 != '\0') goto LAB_00494513;
  }
  FUN_0049b230();
LAB_00494513:
  if (*DAT_00a16714 < 0xe6) {
    param_5 = _DAT_007d0a60;
  }
  param_3 = (double)(DAT_00a1928c / 100) * param_3;
  param_4 = (double)(DAT_00a1928c / 100) * param_4;
  if (param_1[0x104] !=
      (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>)0x0) {
    param_1[0x104] = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>)0x0;
    pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x494598;
    FUN_004ce970();
    pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x4945a4;
    FUN_004ce970();
    pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x4945b0;
    FUN_004ce970();
    pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x4945bc;
    FUN_004ce970();
    pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x4945c8;
    FUN_004717c0();
    pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x4945da;
    FUN_004ce970();
    local_a8 = 0;
    while( true ) {
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x494601;
      iVar8 = FUN_004717c0();
      if (iVar8 <= local_a8) break;
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x2
      ;
      pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    local_a8;
      pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0xc
      ;
      uStack_874 = 0x494624;
      iVar8 = FUN_0046f7f0();
      if (-1 < iVar8) {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x2;
        pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_a8;
        pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0xc;
        uStack_874 = 0x49464b;
        FUN_0046f7f0();
      }
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x1
      ;
      pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    local_a8;
      pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0xc
      ;
      uStack_874 = 0x494668;
      iVar8 = FUN_0046f7f0();
      if (iVar8 < 0) {
        local_27c = 0;
      }
      else {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x1;
        pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_a8;
        pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0xc;
        uStack_874 = 0x49468f;
        local_27c = FUN_0046f7f0();
      }
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0
      ;
      pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    local_a8;
      pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0xc
      ;
      uStack_874 = 0x4946ac;
      iVar8 = FUN_0046f7f0();
      if (iVar8 < 0) {
        local_280 = 0;
      }
      else {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x0;
        pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_a8;
        pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0xc;
        uStack_874 = 0x4946d3;
        local_280 = FUN_0046f7f0();
      }
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    local_27c;
      pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    local_280;
      pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4946f3;
      uVar9 = FUN_00543f70();
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x494710;
      puVar10 = (undefined4 *)FUN_004ce990();
      *puVar10 = uVar9;
      local_a8 = local_a8 + 1;
    }
  }
  local_a0 = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  local_5c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             FUN_004cbb30();
  basic_string<>();
  local_8 = 0;
  basic_string<>();
  local_8._0_1_ = 1;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                0x494796;
  uVar9 = FUN_0049b440();
  *(undefined4 *)(param_1 + 0x74) = uVar9;
  *(undefined4 *)(param_1 + 0x108) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x10c) = 0xffffffff;
  pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **)
                 (param_1 + 0x78);
  pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                0x4947d6;
  pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                FUN_0049b1c0();
  pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **)
                 (param_1 + 0x74);
  uStack_874 = *(undefined4 *)(param_1 + 0xdc);
  uStack_87c._4_4_ = 0x4947f8;
  FUN_0049adc0();
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  local_58 = 0;
  local_54 = DAT_00a1922c;
  local_9c = (int)*DAT_00a1669c;
  local_98 = 0;
  local_6c = -1000000;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  local_68 = 0;
  local_89 = '\0';
  local_94 = (LPSTR)0x0;
  local_90 = 0;
  local_64 = 0;
  *(int *)(param_1 + 0x100) = DAT_0084b248 << 1;
  if (DAT_00a14350 == 1) {
    local_284 = 2;
  }
  else {
    local_284 = DAT_0084b248 << 1;
  }
  local_60 = local_284;
  if (DAT_00a1928c == 200) {
    *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) / 2;
    local_60 = local_284 / 2;
  }
  local_a4 = 100;
  basic_string<>();
  local_8._0_1_ = 2;
LAB_0049492c:
  do {
    iVar8 = FUN_004e5650();
    if ((iVar8 <= *(int *)(param_1 + 0x68)) ||
       ((0 < *(int *)(param_1 + 0xe8) && (*(int *)(param_1 + 0xe4) + -1 <= *(int *)(param_1 + 0x68))
        ))) {
LAB_0049accf:
      local_8._0_1_ = 1;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_50);
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_30);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_88);
      ExceptionList = local_10;
      return;
    }
    local_34 = local_5c;
    local_a0 = *(uint *)(param_1 + 0x68);
    if (*DAT_00a166b8 < '\x06') {
      pbStack_868 = local_5c;
      pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4949e8;
      local_94 = (LPSTR)FUN_00417a40();
      local_90 = (int)local_94 - (int)local_5c;
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + local_90;
      pbStack_868 = local_34;
      pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x494a23;
      local_5c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 FUN_00417a40();
    }
    else {
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4949a1;
      local_94 = CharNextA((LPCSTR)local_5c);
      local_90 = (int)local_94 - (int)local_5c;
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + local_90;
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4949d8;
      local_5c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 CharNextA((LPCSTR)local_34);
    }
    if (((param_2 != '\0') && (local_89 != '\0')) &&
       (*(double *)(param_1 + 0x88) <
        (double)*(int *)(param_1 + 0x68) - (double)*(int *)(param_1 + 0xf8))) {
      *(double *)(param_1 + 0x88) =
           (double)*(int *)(param_1 + 0x68) - (double)*(int *)(param_1 + 0xf8);
    }
    if ((param_2 != '\0') && (local_89 == '\0')) {
      iVar8 = FUN_004fe844();
      if (iVar8 + *(int *)(param_1 + 0xf8) < *(int *)(param_1 + 0x68)) goto LAB_0049accf;
    }
    if ((param_1[0xe2] !=
         (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>)0x0) &&
       (*(int *)(param_1 + 0xec) < *(int *)(param_1 + 0x68))) goto LAB_0049accf;
    pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x494b04;
    pcVar7 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
             operator[](param_1,local_a0);
    local_ac = (int)*pcVar7;
    pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  local_a0;
    pbStack_86c = local_1ac;
    pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x494b36;
    FUN_004cbc20();
    local_8._0_1_ = 3;
    pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x494b5e;
    FUN_004cb840();
    local_8._0_1_ = 2;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1ac);
    pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x494b7a;
    pcVar7 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
             operator[](local_88,0);
    uVar4 = uStack_874;
    dVar3 = uStack_87c;
    uStack_87c._4_4_ = SUB84(param_5,0);
    uVar9 = uStack_87c._4_4_;
    uStack_874 = (undefined4)((ulonglong)param_5 >> 0x20);
    uVar5 = uStack_874;
    uStack_874 = uVar4;
    uStack_87c = dVar3;
    if (*pcVar7 != '\x01') goto switchD_00494c87_caseD_8;
    local_34 = local_5c;
    pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **)
                   (param_1 + 0x68);
    *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 2;
    local_5c = local_5c + 2;
    pbStack_86c = local_1c8;
    pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x494be2;
    local_a0 = (uint)pbStack_868;
    FUN_004cbc20();
    local_8._0_1_ = 4;
    pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x494c0a;
    FUN_004cb840();
    local_8._0_1_ = 2;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1c8);
    pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x494c2b;
    pcVar7 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
             operator[](param_1,local_a0);
    local_b0 = (int)*pcVar7;
    *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 3;
    pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x494c5c;
    pcVar7 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
             operator[](local_88,1);
    switch(*pcVar7) {
    case '\x01':
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x494c9e;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_88,"\\");
    default:
switchD_00494c87_caseD_8:
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x49985c;
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    FUN_004cbb30();
      pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x499862;
      iVar8 = FUN_0046f680();
      if (iVar8 == 0) {
        pcVar7 = (char *)FUN_004cbb30();
        if (*pcVar7 == '\n') {
          *(undefined4 *)(param_1 + 0x5c) = 0;
          if ((0xca < *DAT_00a16714) || (local_64 != 0)) {
            if ((param_1[0xe0] ==
                 (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>)0x0) &&
               ((local_98 == 0 && (0xca < *DAT_00a16714)))) {
              local_98 = *(int *)(param_1 + 0x74);
            }
            *(int *)(param_1 + 0x60) =
                 (local_98 * *(int *)(param_1 + 0x100)) / 2 + *(int *)(param_1 + 0x60);
          }
          if (param_1[0xe0] ==
              (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>)0x0) {
            iVar8 = FUN_004ce080();
            if (*(int *)(param_1 + 100) < iVar8) {
              pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x49995a;
              piVar13 = (int *)FUN_004ce990();
              if (*piVar13 != 0) {
                if (local_6c == -1000000) {
                  if (*DAT_00a16674 < '!') {
                    local_710 = (int)*DAT_00a16674;
                  }
                  else {
                    local_710 = 0x20;
                  }
                  *(int *)(param_1 + 0x60) =
                       (((int)(*DAT_00a166a0 * local_710 +
                              (*DAT_00a166a0 * local_710 >> 0x1f & 0x1fU)) >> 5) *
                       *(int *)(param_1 + 0x100)) / 2 + *(int *)(param_1 + 0x60);
                }
                else {
                  if (*DAT_00a16674 < '!') {
                    local_70c = (int)*DAT_00a16674;
                  }
                  else {
                    local_70c = 0x20;
                  }
                  local_70c = ((local_6c * *(int *)(param_1 + 0x100)) / 2) * local_70c;
                  *(int *)(param_1 + 0x60) =
                       ((int)(local_70c + (local_70c >> 0x1f & 0x1fU)) >> 5) +
                       *(int *)(param_1 + 0x60);
                }
              }
            }
          }
          if (param_1[0xe0] !=
              (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>)0x0) {
            iVar8 = FUN_004ce080();
            if (iVar8 <= *(int *)(param_1 + 100)) {
              pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x499a81;
              FUN_004ce970();
            }
            pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x499a9c;
            piVar13 = (int *)FUN_004ce990();
            if (*piVar13 != 0) {
              if (local_6c == -1000000) {
                if (*DAT_00a16674 < '!') {
                  local_718 = (int)*DAT_00a16674;
                }
                else {
                  local_718 = 0x20;
                }
                *(int *)(param_1 + 0x60) =
                     (((int)(*DAT_00a166a4 * local_718 + (*DAT_00a166a4 * local_718 >> 0x1f & 0x1fU)
                            ) >> 5) * *(int *)(param_1 + 0x100)) / 2 + *(int *)(param_1 + 0x60);
              }
              else {
                if (*DAT_00a16674 < '!') {
                  local_714 = (int)*DAT_00a16674;
                }
                else {
                  local_714 = 0x20;
                }
                local_714 = ((local_6c * *(int *)(param_1 + 0x100)) / 2) * local_714;
                *(int *)(param_1 + 0x60) =
                     ((int)(local_714 + (local_714 >> 0x1f & 0x1fU)) >> 5) +
                     *(int *)(param_1 + 0x60);
              }
            }
          }
          *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + 1;
          local_98 = 0;
          if (param_1[0xe0] ==
              (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>)0x0) {
            local_98 = *(int *)(param_1 + 0x74);
            iVar8 = FUN_004ce080();
            if (iVar8 <= *(int *)(param_1 + 100)) {
              pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x499bf1;
              FUN_004ce970();
            }
            if (param_2 == '\0') {
              iVar8 = *(int *)(param_1 + 0x74);
              iVar11 = *(int *)(param_1 + 0x100);
              pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x499c33;
              piVar13 = (int *)FUN_004ce990();
              *piVar13 = (iVar8 * iVar11) / 2;
            }
          }
          break;
        }
        pcVar7 = (char *)FUN_004cbb30();
        if (*pcVar7 == '\r') break;
      }
      if (local_98 < *(int *)(param_1 + 0x74)) {
        local_98 = *(int *)(param_1 + 0x74);
      }
      pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **)
                     (param_1 + 0x78);
      pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x499c8b;
      pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    FUN_0049b1c0();
      pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    ((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
      uStack_874 = *(undefined4 *)(param_1 + 0xdc);
      uStack_87c._4_4_ = 0x499cbf;
      FUN_0049adc0();
      local_64 = local_64 + 1;
      if (param_2 != '\0') {
        if (param_5 == _DAT_007d0a60) {
          iVar8 = FUN_004fe844();
          if ((float)iVar8 + *(float *)(param_1 + 0x58) < (float)(*DAT_00a1671c * DAT_0084b248)) {
            FUN_004fe844();
            iVar8 = FUN_004fe844();
            if ((float10)(-(iVar8 + DAT_0084b264 * 2) * DAT_0084b248) < extraout_ST0_01) {
              pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x499dec;
              FUN_004ce990();
              FUN_004fe844();
              FUN_004fe844();
              iVar8 = FUN_004fe844();
              if ((float10)(-(iVar8 + DAT_0084b264 * 2) * DAT_0084b248) < extraout_ST0_02) {
                pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x499ea1;
                FUN_004ce990();
                FUN_004fe844();
                iVar8 = FUN_004fe844();
                if (extraout_ST0_03 + (float10)iVar8 < (float10)(*DAT_00a16718 * DAT_0084b248))
                goto LAB_00499f28;
              }
            }
          }
        }
        else {
LAB_00499f28:
          local_190 = 0;
          if ((param_5 == _DAT_007d0a60) || (*DAT_00a16714 < 0xe6)) {
            if ((param_3 == 1.0) && (param_4 == 1.0)) {
              if (DAT_00a18aec != 0) {
                pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                **)(param_1 + 0x10c);
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x49a546;
                pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)FUN_0049b1d0();
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x49a595;
                puVar10 = (undefined4 *)FUN_004ce990();
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)*puVar10;
                pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                **)(param_1 + 0x10c);
                uStack_874 = 0x49a5b0;
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)FUN_0049b1d0();
                uStack_874 = 0x49a5bc;
                uStack_874 = FUN_004cbb30();
                uStack_87c._4_4_ = 0x49a5fe;
                uStack_87c._4_4_ = FUN_004fe844();
                uStack_87c._0_4_ = *(undefined4 *)(param_1 + 100);
                FUN_004ce990();
                uStack_87c._0_4_ = 0x49a646;
                FUN_004fe844();
                uStack_87c._0_4_ = 0x49a66f;
                uStack_87c._0_4_ = FUN_004fe844();
                FUN_00540340();
              }
              pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(param_1 + 0x108);
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x49a692;
              pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)FUN_0049b1d0();
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x49a6e1;
              puVar10 = (undefined4 *)FUN_004ce990();
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)*puVar10;
              pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(param_1 + 0x70);
              uStack_874 = 0x49a6ff;
              piVar13 = (int *)FUN_004ce990();
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)*piVar13;
              uStack_874 = 0x49a70d;
              uStack_874 = FUN_004cbb30();
              uStack_87c._4_4_ = 0x49a749;
              uStack_87c._4_4_ = FUN_004fe844();
              uStack_87c._0_4_ = *(undefined4 *)(param_1 + 100);
              FUN_004ce990();
              uStack_87c._0_4_ = 0x49a791;
              FUN_004fe844();
              uStack_87c._0_4_ = 0x49a7b4;
              uStack_87c._0_4_ = FUN_004fe844();
              local_190 = FUN_00540340();
            }
            else if ((param_3 != 1.0) || (param_4 != 1.0)) {
              if (DAT_00a18aec != 0) {
                pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                **)(param_1 + 0x10c);
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x49a811;
                pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)FUN_0049b1d0();
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x49a860;
                puVar10 = (undefined4 *)FUN_004ce990();
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)*puVar10;
                pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                **)(param_1 + 0x10c);
                uStack_874 = 0x49a87b;
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)FUN_0049b1d0();
                uStack_874 = 0x49a887;
                uStack_874 = FUN_004cbb30();
                uStack_888._0_4_ =
                     (float)(*(int *)(param_1 + 0x60) +
                            ((local_98 - *(int *)(param_1 + 0x74)) * local_60) / 2) * (float)param_4
                     + *(float *)(param_1 + 0x58) + (float)DAT_00a18aec;
                uStack_888._4_4_ = param_3._0_4_;
                uStack_87c = param_4;
                FUN_004ce990();
                FUN_004fe844();
                FUN_00540540();
              }
              pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(param_1 + 0x108);
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x49a983;
              pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)FUN_0049b1d0();
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x49a9d2;
              puVar10 = (undefined4 *)FUN_004ce990();
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)*puVar10;
              pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(param_1 + 0x70);
              uStack_874 = 0x49a9f0;
              piVar13 = (int *)FUN_004ce990();
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)*piVar13;
              uStack_874 = 0x49a9fe;
              uStack_874 = FUN_004cbb30();
              uStack_888._0_4_ =
                   (float)(*(int *)(param_1 + 0x60) +
                          ((local_98 - *(int *)(param_1 + 0x74)) * local_60) / 2) * (float)param_4 +
                   *(float *)(param_1 + 0x58);
              uStack_888._4_4_ = param_3._0_4_;
              uStack_87c = param_4;
              FUN_004ce990();
              FUN_004fe844();
              local_190 = FUN_00540540();
            }
          }
          else {
            if (DAT_00a18aec != 0) {
              FUN_004cbb30();
              pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x0;
              pbStack_86c = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(param_1 + 0x10c);
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x499f8f;
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)FUN_0049b1d0();
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
              uStack_874 = 0x499fde;
              piVar13 = (int *)FUN_004ce990();
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)*piVar13;
              uStack_874 = *(undefined4 *)(param_1 + 0x10c);
              uStack_87c._4_4_ = 0x499ff9;
              uStack_874 = FUN_0049b1d0();
              uStack_888._4_4_ = SUB84(_DAT_007d0a60,0);
              uStack_888._0_4_ = (float)((ulonglong)_DAT_007d0a60 >> 0x20);
              uStack_87c._0_4_ = uVar9;
              uStack_87c._4_4_ = uVar5;
              FUN_004feea4();
              FUN_004ce990();
              FUN_004fe844();
              FUN_004fef54();
              FUN_004fe844();
              FUN_004ce990();
              FUN_004fe844();
              FUN_004feea4();
              FUN_004fef54();
              FUN_004fe844();
              FUN_005406b0();
            }
            FUN_004cbb30();
            pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x0;
            pbStack_86c = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            **)(param_1 + 0x108);
            pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x49a251;
            pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)FUN_0049b1d0();
            pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
            uStack_874 = 0x49a2a0;
            piVar13 = (int *)FUN_004ce990();
            pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)*piVar13;
            uStack_874 = *(undefined4 *)(param_1 + 0x70);
            uStack_87c._4_4_ = 0x49a2be;
            puVar10 = (undefined4 *)FUN_004ce990();
            uStack_874 = *puVar10;
            uStack_888._4_4_ = SUB84(_DAT_007d0a60,0);
            uStack_888._0_4_ = (float)((ulonglong)_DAT_007d0a60 >> 0x20);
            uStack_87c._0_4_ = uVar9;
            uStack_87c._4_4_ = uVar5;
            FUN_004feea4();
            FUN_004ce990();
            FUN_004fe844();
            FUN_004fef54();
            FUN_004fe844();
            FUN_004ce990();
            FUN_004fe844();
            FUN_004feea4();
            FUN_004fef54();
            FUN_004fe844();
            local_190 = FUN_005406b0();
          }
          if (local_190 == -1) {
            FUN_004cbb30();
            uStack_888._4_4_ = 0x49ab03;
            basic_string<>();
            local_8._0_1_ = 0xd;
            FUN_004cbb30();
            basic_string<>();
            local_8._0_1_ = 0xe;
            basic_string<>("Can\'t Draw Message.");
            local_8._0_1_ = 2;
            FUN_0042bed0();
          }
        }
      }
      if (*(int *)(param_1 + 0x78) == 0) {
LAB_0049aba2:
        local_858 = 0;
      }
      else {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x49ab8e;
        pcVar7 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 operator[](local_88,0);
        if (*pcVar7 != ' ') goto LAB_0049aba2;
        local_858 = 2;
      }
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    ((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
      pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x49abfe;
      piVar13 = (int *)FUN_004ce990();
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    *piVar13;
      pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    (*(int *)(param_1 + 0x68) - local_a0);
      pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x49ac1c;
      pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    FUN_004cbb30();
      uStack_874 = 0x49ac22;
      iVar8 = FUN_0053f680();
      *(int *)(param_1 + 0x5c) =
           (((iVar8 + local_858) - (local_58 * *(int *)(param_1 + 0x100)) / 2) -
           (int)((*(int *)(param_1 + 0x68) - local_a0) * local_9c * *(int *)(param_1 + 0x100)) / 4)
           + *(int *)(param_1 + 0x5c);
      if (param_2 == '\0') {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x49aca1;
        FUN_0049b6c0();
      }
      if (param_1[0xe0] !=
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>)0x0) {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x49acca;
        FUN_004ce970();
      }
      break;
    case '\x02':
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x494caf;
      iVar8 = FUN_004717c0();
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x494cc9;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(uint *)(param_1 + 0x68));
      bVar1 = *pbVar12;
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x494ced;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(int *)(param_1 + 0x68) + 1);
      bVar2 = *pbVar12;
      iVar11 = FUN_004cbb30();
      if (iVar8 + -1 <
          (int)((bVar1 - 0xe) * 0x1000 + (bVar2 - 0xe) * 0x40 + -0xe +
               (uint)*(byte *)(iVar11 + 2 + *(int *)(param_1 + 0x68)))) {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x494d25;
        local_29c = FUN_004717c0();
        local_29c = local_29c + -1;
      }
      else {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x494d45;
        pbVar12 = (byte *)std::
                          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ::operator[](param_1,*(uint *)(param_1 + 0x68));
        bVar1 = *pbVar12;
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x494d69;
        pbVar12 = (byte *)std::
                          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ::operator[](param_1,*(int *)(param_1 + 0x68) + 1);
        bVar2 = *pbVar12;
        iVar8 = FUN_004cbb30();
        local_29c = (bVar1 - 0xe) * 0x1000 + (bVar2 - 0xe) * 0x40 + -0xe +
                    (uint)*(byte *)(iVar8 + 2 + *(int *)(param_1 + 0x68));
      }
      *(int *)(param_1 + 0x70) = local_29c;
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 4;
      *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 4;
      local_5c = local_5c + 4;
      break;
    case '\x03':
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x494df9;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(uint *)(param_1 + 0x68));
      local_b4 = *pbVar12 - 0xe;
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x494e1d;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(int *)(param_1 + 0x68) + 1);
      local_b8 = *pbVar12 - 0xe;
      if (local_b0 == 4) {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x494e47;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::operator[]
                  (param_1,*(uint *)(param_1 + 0x68));
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x494e59;
        uVar9 = FUN_0049b440();
        *(undefined4 *)(param_1 + 0x74) = uVar9;
      }
      else if (local_b0 == 5) {
        FUN_004cbb30();
        FUN_004cbb30();
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x494eb4;
        uVar9 = FUN_0049b440();
        *(undefined4 *)(param_1 + 0x74) = uVar9;
      }
      if (local_98 < *(int *)(param_1 + 0x74)) {
        local_98 = *(int *)(param_1 + 0x74);
      }
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 3;
      *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 3;
      local_5c = local_5c + 3;
      break;
    case '\x04':
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x494f30;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(uint *)(param_1 + 0x68));
      bVar1 = *pbVar12;
      iVar8 = FUN_004cbb30();
      local_98 = (bVar1 - 0xe) * 0x40 + -0xe + (uint)*(byte *)(iVar8 + 1 + *(int *)(param_1 + 0x68))
      ;
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 3;
      *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 3;
      local_5c = local_5c + 3;
      break;
    case '\x05':
      *(undefined4 *)(param_1 + 0x78) = 1;
      break;
    case '\x06':
      *(undefined4 *)(param_1 + 0x78) = 0;
      break;
    case '\a':
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x494fd3;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(uint *)(param_1 + 0x68));
      local_bc = (uint)*pbVar12;
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x494ff1;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(uint *)(param_1 + 0x68));
      local_58 = *pbVar12 - 0x78;
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 1;
      *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 1;
      local_5c = local_5c + 1;
      break;
    case '\t':
      if (local_98 < *(int *)(param_1 + 0x74)) {
        local_98 = *(int *)(param_1 + 0x74);
      }
      if (param_2 == '\0') {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4951a0;
        FUN_0049b6c0();
      }
      pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **)
                     (param_1 + 0x78);
      pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4951b9;
      pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    FUN_0049b1c0();
      pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    ((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
      uStack_874 = *(undefined4 *)(param_1 + 0xdc);
      uStack_87c._4_4_ = 0x4951ef;
      FUN_0049adc0();
      local_f1 = 0;
      local_f0 = *(int *)(param_1 + 0x74);
      local_fc = *(undefined4 *)(param_1 + 0x70);
      local_c8 = *(int *)(param_1 + 0x5c);
      local_100 = 0;
      while( true ) {
        local_34 = local_5c;
        local_a0 = *(uint *)(param_1 + 0x68);
        pbStack_868 = local_5c;
        pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x49525a;
        iVar8 = FUN_00417a40();
        *(int *)(param_1 + 0x68) = (iVar8 - (int)local_5c) + *(int *)(param_1 + 0x68);
        pbStack_868 = local_34;
        pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x49527d;
        local_5c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   FUN_00417a40();
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_a0;
        pbStack_86c = local_1e4;
        pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4952ac;
        FUN_004cbc20();
        local_8._0_1_ = 5;
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4952d4;
        FUN_004cb840();
        local_8._0_1_ = 2;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1e4);
        local_100 = (*(int *)(param_1 + 0x68) - local_a0) + local_100;
        pbStack_868 = local_88;
        pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x49530f;
        cVar6 = FUN_004ec750();
        if (cVar6 != '\0') break;
        pcVar7 = (char *)FUN_004cbb30();
        if (*pcVar7 == '\0') {
          pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x495340;
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_88,
                     "\\");
        }
        iVar8 = FUN_004e5650();
        if (iVar8 <= (int)(local_a0 + 1)) break;
        if (param_2 != '\0') {
          if ((param_5 == _DAT_007d0a60) || (*DAT_00a16714 < 0xe6)) {
            if ((param_3 == 1.0) && (param_4 == 1.0)) {
              if (DAT_00a18aec != 0) {
                pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                **)(param_1 + 0x10c);
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x495953;
                pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)FUN_0049b1d0();
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x4959a2;
                puVar10 = (undefined4 *)FUN_004ce990();
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)*puVar10;
                pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                **)(param_1 + 0x10c);
                uStack_874 = 0x4959bd;
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)FUN_0049b1d0();
                uStack_874 = 0x4959c9;
                uStack_874 = FUN_004cbb30();
                uStack_87c._4_4_ = 0x495a02;
                uStack_87c._4_4_ = FUN_004fe844();
                uStack_87c._0_4_ = *(undefined4 *)(param_1 + 100);
                FUN_004ce990();
                uStack_87c._0_4_ = 0x495a4a;
                FUN_004fe844();
                uStack_87c._0_4_ = 0x495a73;
                uStack_87c._0_4_ = FUN_004fe844();
                FUN_00540340();
              }
              pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(param_1 + 0x108);
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x495a96;
              pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)FUN_0049b1d0();
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x495ae5;
              puVar10 = (undefined4 *)FUN_004ce990();
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)*puVar10;
              pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(param_1 + 0x70);
              uStack_874 = 0x495b03;
              puVar10 = (undefined4 *)FUN_004ce990();
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)*puVar10;
              uStack_874 = 0x495b11;
              uStack_874 = FUN_004cbb30();
              uStack_87c._4_4_ = 0x495b44;
              uStack_87c._4_4_ = FUN_004fe844();
              uStack_87c._0_4_ = *(undefined4 *)(param_1 + 100);
              FUN_004ce990();
              uStack_87c._0_4_ = 0x495b8c;
              FUN_004fe844();
              uStack_87c._0_4_ = 0x495baf;
              uStack_87c._0_4_ = FUN_004fe844();
              FUN_00540340();
            }
            else {
              if (DAT_00a18aec != 0) {
                pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                **)(param_1 + 0x10c);
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x495be4;
                pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)FUN_0049b1d0();
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x495c33;
                puVar10 = (undefined4 *)FUN_004ce990();
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)*puVar10;
                pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                **)(param_1 + 0x10c);
                uStack_874 = 0x495c4e;
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)FUN_0049b1d0();
                uStack_874 = 0x495c5a;
                uStack_874 = FUN_004cbb30();
                uStack_888._0_4_ =
                     (float)(*(int *)(param_1 + 0x60) + (local_98 - *(int *)(param_1 + 0x74))) *
                     (float)param_4 + *(float *)(param_1 + 0x58) + (float)DAT_00a18aec;
                uStack_888._4_4_ = param_3._0_4_;
                uStack_87c = param_4;
                FUN_004ce990();
                FUN_004fe844();
                FUN_00540540();
              }
              pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(param_1 + 0x108);
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x495d4d;
              pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)FUN_0049b1d0();
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x495d9c;
              puVar10 = (undefined4 *)FUN_004ce990();
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)*puVar10;
              pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(param_1 + 0x70);
              uStack_874 = 0x495dba;
              puVar10 = (undefined4 *)FUN_004ce990();
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)*puVar10;
              uStack_874 = 0x495dc8;
              uStack_874 = FUN_004cbb30();
              uStack_888._0_4_ =
                   (float)(*(int *)(param_1 + 0x60) + (local_98 - *(int *)(param_1 + 0x74))) *
                   (float)param_4 + *(float *)(param_1 + 0x58);
              uStack_888._4_4_ = param_3._0_4_;
              uStack_87c = param_4;
              FUN_004ce990();
              FUN_004fe844();
              FUN_00540540();
            }
          }
          else {
            if (DAT_00a18aec != 0) {
              FUN_004cbb30();
              pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x0;
              pbStack_86c = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(param_1 + 0x10c);
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x4953c6;
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)FUN_0049b1d0();
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
              uStack_874 = 0x495415;
              puVar10 = (undefined4 *)FUN_004ce990();
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)*puVar10;
              uStack_874 = *(undefined4 *)(param_1 + 0x10c);
              uStack_87c._4_4_ = 0x495430;
              uStack_874 = FUN_0049b1d0();
              uStack_888._4_4_ = SUB84(_DAT_007d0a60,0);
              uStack_888._0_4_ = (float)((ulonglong)_DAT_007d0a60 >> 0x20);
              uStack_87c._0_4_ = uVar9;
              uStack_87c._4_4_ = uVar5;
              FUN_004feea4();
              FUN_004ce990();
              FUN_004fe844();
              FUN_004fef54();
              FUN_004fe844();
              FUN_004ce990();
              FUN_004fe844();
              FUN_004feea4();
              FUN_004fef54();
              FUN_004fe844();
              FUN_005406b0();
            }
            FUN_004cbb30();
            pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x0;
            pbStack_86c = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            **)(param_1 + 0x108);
            pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x495676;
            pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)FUN_0049b1d0();
            pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
            uStack_874 = 0x4956c5;
            puVar10 = (undefined4 *)FUN_004ce990();
            pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)*puVar10;
            uStack_874 = *(undefined4 *)(param_1 + 0x70);
            uStack_87c._4_4_ = 0x4956e3;
            puVar10 = (undefined4 *)FUN_004ce990();
            uStack_874 = *puVar10;
            uStack_888._4_4_ = SUB84(_DAT_007d0a60,0);
            uStack_888._0_4_ = (float)((ulonglong)_DAT_007d0a60 >> 0x20);
            uStack_87c._0_4_ = uVar9;
            uStack_87c._4_4_ = uVar5;
            FUN_004feea4();
            FUN_004ce990();
            FUN_004fe844();
            FUN_004fef54();
            FUN_004fe844();
            FUN_004ce990();
            FUN_004fe844();
            FUN_004feea4();
            FUN_004fef54();
            FUN_004fe844();
            FUN_005406b0();
          }
        }
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      ((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
        pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x495ee5;
        puVar10 = (undefined4 *)FUN_004ce990();
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      *puVar10;
        pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      (*(int *)(param_1 + 0x68) - local_a0);
        pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x495f03;
        pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      FUN_004cbb30();
        uStack_874 = 0x495f09;
        iVar8 = FUN_0053f680();
        if ((iVar8 - (local_58 * *(int *)(param_1 + 0x100)) / 2) -
            (int)((*(int *)(param_1 + 0x68) - local_a0) * local_9c * *(int *)(param_1 + 0x100)) / 4
            < 0) {
          local_39c = 0;
        }
        else {
          pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
          pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x495fb7;
          puVar10 = (undefined4 *)FUN_004ce990();
          pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )*puVar10;
          pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )(*(int *)(param_1 + 0x68) - local_a0);
          pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x495fd5;
          pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )FUN_004cbb30();
          uStack_874 = 0x495fdb;
          iVar8 = FUN_0053f680();
          local_39c = (iVar8 - (local_58 * *(int *)(param_1 + 0x100)) / 2) -
                      (int)((*(int *)(param_1 + 0x68) - local_a0) * local_9c *
                           *(int *)(param_1 + 0x100)) / 4;
        }
        *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + local_39c;
      }
      *(undefined4 *)(param_1 + 0x74) = DAT_00a18c80;
      pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **)
                     (param_1 + 0x78);
      pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x496073;
      pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    FUN_0049b1c0();
      pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    ((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
      uStack_874 = *(undefined4 *)(param_1 + 0xdc);
      uStack_87c._4_4_ = 0x4960a9;
      FUN_0049adc0();
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4960b9;
      basic_string<>();
      local_8._0_1_ = 6;
      local_d0 = 0;
      local_104 = *(int *)(param_1 + 0x68);
      local_c4 = 0;
      while( true ) {
        local_34 = local_5c;
        local_a0 = *(uint *)(param_1 + 0x68);
        pbStack_868 = local_5c;
        pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x49610d;
        iVar8 = FUN_00417a40();
        *(int *)(param_1 + 0x68) = (iVar8 - (int)local_5c) + *(int *)(param_1 + 0x68);
        pbStack_868 = local_34;
        pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x496130;
        local_5c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   FUN_00417a40();
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_a0;
        pbStack_86c = local_200;
        pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x49615f;
        FUN_004cbc20();
        local_8._0_1_ = 7;
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x496187;
        FUN_004cb840();
        local_8._0_1_ = 6;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_200);
        pbStack_868 = local_88;
        pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4961a7;
        cVar6 = FUN_004ec750();
        if (cVar6 != '\0') break;
        iVar8 = FUN_004e5650();
        if (iVar8 <= (int)(local_a0 + 1)) break;
        pcVar7 = (char *)FUN_004cbb30();
        if (*pcVar7 == '\0') {
          pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x4961ef;
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_88,
                     "\\");
        }
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x496201;
        FUN_004cb880();
        local_d0 = local_d0 + 1;
      }
      local_c4 = *(int *)(param_1 + 0x68);
      local_cc = local_d0;
      local_d0 = 0;
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    ((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
      pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x49628a;
      piVar13 = (int *)FUN_004ce990();
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    *piVar13;
      pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    (local_c4 - local_104);
      pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4962a5;
      pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    FUN_004cbb30();
      uStack_874 = 0x4962ab;
      local_f8 = FUN_0053f680();
      if (*(int *)(param_1 + 0x5c) - local_c8 < local_f8) {
        local_c8 = (local_c8 + *(int *)(param_1 + 0x5c)) / 2 - local_f8 / 2;
        *(undefined4 *)(param_1 + 0x70) = 0xd;
        local_108 = local_f8;
        if (param_2 != '\0') {
          if ((param_5 == _DAT_007d0a60) || (*DAT_00a16714 < 0xe6)) {
            if ((param_3 == 1.0) && (param_4 == 1.0)) {
              if (DAT_00a18aec != 0) {
                pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                **)(param_1 + 0x10c);
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x496972;
                pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)FUN_0049b1d0();
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x4969c3;
                puVar10 = (undefined4 *)FUN_004ce990();
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)*puVar10;
                pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                **)(param_1 + 0x10c);
                uStack_874 = 0x4969de;
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)FUN_0049b1d0();
                uStack_874 = 0x4969ea;
                uStack_874 = FUN_004cbb30();
                uStack_87c._4_4_ = 0x496a33;
                FUN_004fe844();
                uStack_87c._4_4_ = 0x496a53;
                uStack_87c._4_4_ = FUN_004fe844();
                uStack_87c._0_4_ = *(undefined4 *)(param_1 + 100);
                FUN_004ce990();
                uStack_87c._0_4_ = 0x496a9b;
                FUN_004fe844();
                uStack_87c._0_4_ = 0x496ac3;
                uStack_87c._0_4_ = FUN_004fe844();
                FUN_00540340();
              }
              pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(param_1 + 0x108);
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x496ae6;
              pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)FUN_0049b1d0();
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x496b37;
              piVar13 = (int *)FUN_004ce990();
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)*piVar13;
              pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(param_1 + 0x70);
              uStack_874 = 0x496b55;
              piVar13 = (int *)FUN_004ce990();
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)*piVar13;
              uStack_874 = 0x496b63;
              uStack_874 = FUN_004cbb30();
              uStack_87c._4_4_ = 0x496bae;
              FUN_004fe844();
              uStack_87c._4_4_ = 0x496bc8;
              uStack_87c._4_4_ = FUN_004fe844();
              uStack_87c._0_4_ = *(undefined4 *)(param_1 + 100);
              FUN_004ce990();
              uStack_87c._0_4_ = 0x496c10;
              FUN_004fe844();
              uStack_87c._0_4_ = 0x496c32;
              uStack_87c._0_4_ = FUN_004fe844();
              FUN_00540340();
            }
            else {
              if (DAT_00a18aec != 0) {
                pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                **)(param_1 + 0x10c);
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x496c67;
                pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)FUN_0049b1d0();
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x496cb6;
                puVar10 = (undefined4 *)FUN_004ce990();
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)*puVar10;
                pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                **)(param_1 + 0x10c);
                uStack_874 = 0x496cd1;
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)FUN_0049b1d0();
                uStack_874 = 0x496cdd;
                uStack_874 = FUN_004cbb30();
                uStack_888._0_4_ =
                     (float)((*(int *)(param_1 + 0x60) + (local_98 - local_f0)) -
                            (*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2) *
                     (float)param_4 + *(float *)(param_1 + 0x58) + (float)DAT_00a18aec;
                uStack_888._4_4_ = param_3._0_4_;
                uStack_87c = param_4;
                FUN_004ce990();
                FUN_004fe844();
                FUN_00540540();
              }
              pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(param_1 + 0x108);
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x496deb;
              pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)FUN_0049b1d0();
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x496e3c;
              piVar13 = (int *)FUN_004ce990();
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)*piVar13;
              pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(param_1 + 0x70);
              uStack_874 = 0x496e5a;
              piVar13 = (int *)FUN_004ce990();
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)*piVar13;
              uStack_874 = 0x496e68;
              uStack_874 = FUN_004cbb30();
              uStack_888._0_4_ =
                   (float)((*(int *)(param_1 + 0x60) + (local_98 - local_f0)) -
                          (*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2) *
                   (float)param_4 + *(float *)(param_1 + 0x58);
              uStack_888._4_4_ = param_3._0_4_;
              uStack_87c = param_4;
              FUN_004ce990();
              FUN_004fe844();
              FUN_00540540();
            }
          }
          else {
            if (DAT_00a18aec != 0) {
              FUN_004cbb30();
              pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x0;
              pbStack_86c = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(param_1 + 0x10c);
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x49637d;
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)FUN_0049b1d0();
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
              uStack_874 = 0x4963ce;
              piVar13 = (int *)FUN_004ce990();
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)*piVar13;
              uStack_874 = *(undefined4 *)(param_1 + 0x10c);
              uStack_87c._4_4_ = 0x4963e9;
              uStack_874 = FUN_0049b1d0();
              uStack_888._4_4_ = SUB84(_DAT_007d0a60,0);
              uStack_888._0_4_ = (float)((ulonglong)_DAT_007d0a60 >> 0x20);
              uStack_87c._0_4_ = uVar9;
              uStack_87c._4_4_ = uVar5;
              FUN_004feea4();
              FUN_004ce990();
              FUN_004fe844();
              FUN_004fef54();
              FUN_004fe844();
              FUN_004ce990();
              FUN_004fe844();
              FUN_004feea4();
              FUN_004fef54();
              FUN_004fe844();
              FUN_005406b0();
            }
            FUN_004cbb30();
            pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x0;
            pbStack_86c = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            **)(param_1 + 0x108);
            pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x496661;
            pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)FUN_0049b1d0();
            pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
            uStack_874 = 0x4966b2;
            piVar13 = (int *)FUN_004ce990();
            pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)*piVar13;
            uStack_874 = *(undefined4 *)(param_1 + 0x70);
            uStack_87c._4_4_ = 0x4966d0;
            puVar10 = (undefined4 *)FUN_004ce990();
            uStack_874 = *puVar10;
            uStack_888._4_4_ = SUB84(_DAT_007d0a60,0);
            uStack_888._0_4_ = (float)((ulonglong)_DAT_007d0a60 >> 0x20);
            uStack_87c._0_4_ = uVar9;
            uStack_87c._4_4_ = uVar5;
            FUN_004feea4();
            FUN_004ce990();
            FUN_004fe844();
            FUN_004fef54();
            FUN_004fe844();
            FUN_004ce990();
            FUN_004fe844();
            FUN_004feea4();
            FUN_004fef54();
            FUN_004fe844();
            FUN_005406b0();
          }
        }
      }
      else {
        local_12c = 0;
        local_130 = 0;
        local_128 = FUN_004cbb30();
        basic_string<>();
        local_8._0_1_ = 8;
        for (; local_d0 < local_cc; local_d0 = local_d0 + 1) {
          local_12c = local_130;
          pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )local_128;
          pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x496fb5;
          iVar8 = FUN_00417a40();
          local_130 = (iVar8 - local_128) + local_130;
          pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )local_128;
          pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x496fd8;
          local_128 = FUN_00417a40();
          pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )local_12c;
          pbStack_86c = local_21c;
          pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x497007;
          FUN_004cbc20();
          local_8._0_1_ = 9;
          pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x49702f;
          FUN_004cb840();
          local_8._0_1_ = 8;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_21c);
          pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
          pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x49708e;
          piVar13 = (int *)FUN_004ce990();
          pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )*piVar13;
          pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )(local_130 - local_12c);
          pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x4970a9;
          pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )FUN_004cbb30();
          uStack_874 = 0x4970af;
          local_134 = FUN_0053f680();
          local_138 = FUN_004fe844();
          local_138 = local_138 + local_c8;
          *(undefined4 *)(param_1 + 0x70) = 0xd;
          if (param_2 != '\0') {
            if ((param_5 == _DAT_007d0a60) || (*DAT_00a16714 < 0xe6)) {
              if ((param_3 == 1.0) && (param_4 == 1.0)) {
                if (DAT_00a18aec != 0) {
                  pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  **)(param_1 + 0x10c);
                  pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 *)0x49780c;
                  pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 *)FUN_0049b1d0();
                  pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
                  pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 *)0x49785b;
                  puVar10 = (undefined4 *)FUN_004ce990();
                  pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 *)*puVar10;
                  pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  **)(param_1 + 0x10c);
                  uStack_874 = 0x497876;
                  pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 *)FUN_0049b1d0();
                  uStack_874 = 0x497882;
                  uStack_874 = FUN_004cbb30();
                  uStack_87c._4_4_ = 0x4978cd;
                  FUN_004fe844();
                  uStack_87c._4_4_ = 0x4978ed;
                  uStack_87c._4_4_ = FUN_004fe844();
                  uStack_87c._0_4_ = *(undefined4 *)(param_1 + 100);
                  FUN_004ce990();
                  uStack_87c._0_4_ = 0x497935;
                  FUN_004fe844();
                  uStack_87c._0_4_ = 0x49798a;
                  uStack_87c._0_4_ = FUN_004fe844();
                  FUN_00540340();
                }
                pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                **)(param_1 + 0x108);
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x4979ad;
                pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)FUN_0049b1d0();
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x4979fc;
                piVar13 = (int *)FUN_004ce990();
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)*piVar13;
                pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                **)(param_1 + 0x70);
                uStack_874 = 0x497a1a;
                piVar13 = (int *)FUN_004ce990();
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)*piVar13;
                uStack_874 = 0x497a28;
                uStack_874 = FUN_004cbb30();
                uStack_87c._4_4_ = 0x497a71;
                FUN_004fe844();
                uStack_87c._4_4_ = 0x497a8b;
                uStack_87c._4_4_ = FUN_004fe844();
                uStack_87c._0_4_ = *(undefined4 *)(param_1 + 100);
                FUN_004ce990();
                uStack_87c._0_4_ = 0x497ad3;
                FUN_004fe844();
                uStack_87c._0_4_ = 0x497b22;
                uStack_87c._0_4_ = FUN_004fe844();
                FUN_00540340();
              }
              else {
                if (DAT_00a18aec != 0) {
                  pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  **)(param_1 + 0x10c);
                  pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 *)0x497b57;
                  pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 *)FUN_0049b1d0();
                  pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
                  pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 *)0x497ba6;
                  puVar10 = (undefined4 *)FUN_004ce990();
                  pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 *)*puVar10;
                  pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  **)(param_1 + 0x10c);
                  uStack_874 = 0x497bc1;
                  pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 *)FUN_0049b1d0();
                  uStack_874 = 0x497bcd;
                  uStack_874 = FUN_004cbb30();
                  uStack_888._0_4_ =
                       (float)((*(int *)(param_1 + 0x60) + (local_98 - local_f0)) -
                              (*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2) *
                       (float)param_4 + *(float *)(param_1 + 0x58) + (float)DAT_00a18aec;
                  uStack_888._4_4_ = param_3._0_4_;
                  uStack_87c = param_4;
                  FUN_004ce990();
                  FUN_004fe844();
                  FUN_00540540();
                }
                pbStack_868 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                **)(param_1 + 0x108);
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x497d08;
                pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)FUN_0049b1d0();
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x497d57;
                piVar13 = (int *)FUN_004ce990();
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)*piVar13;
                pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                **)(param_1 + 0x70);
                uStack_874 = 0x497d75;
                piVar13 = (int *)FUN_004ce990();
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)*piVar13;
                uStack_874 = 0x497d83;
                uStack_874 = FUN_004cbb30();
                uStack_888._0_4_ =
                     (float)((*(int *)(param_1 + 0x60) + (local_98 - local_f0)) -
                            (*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2) *
                     (float)param_4 + *(float *)(param_1 + 0x58);
                uStack_888._4_4_ = param_3._0_4_;
                uStack_87c = param_4;
                FUN_004ce990();
                FUN_004fe844();
                FUN_00540540();
              }
            }
            else {
              if (DAT_00a18aec != 0) {
                FUN_004cbb30();
                pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x0;
                pbStack_86c = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                **)(param_1 + 0x10c);
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)0x497169;
                pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)FUN_0049b1d0();
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
                uStack_874 = 0x4971ba;
                piVar13 = (int *)FUN_004ce990();
                pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)*piVar13;
                uStack_874 = *(undefined4 *)(param_1 + 0x10c);
                uStack_87c._4_4_ = 0x4971d5;
                uStack_874 = FUN_0049b1d0();
                uStack_888._4_4_ = SUB84(_DAT_007d0a60,0);
                uStack_888._0_4_ = (float)((ulonglong)_DAT_007d0a60 >> 0x20);
                uStack_87c._0_4_ = uVar9;
                uStack_87c._4_4_ = uVar5;
                FUN_004feea4();
                FUN_004ce990();
                FUN_004fe844();
                FUN_004fef54();
                FUN_004fe844();
                FUN_004ce990();
                FUN_004fe844();
                FUN_004feea4();
                FUN_004fef54();
                FUN_004fe844();
                FUN_005406b0();
              }
              FUN_004cbb30();
              pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x0;
              pbStack_86c = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(param_1 + 0x108);
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x4974a5;
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)FUN_0049b1d0();
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)((*(int *)(param_1 + 0x74) * *(int *)(param_1 + 0x100)) / 2);
              uStack_874 = 0x4974f4;
              piVar13 = (int *)FUN_004ce990();
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)*piVar13;
              uStack_874 = *(undefined4 *)(param_1 + 0x70);
              uStack_87c._4_4_ = 0x497512;
              puVar10 = (undefined4 *)FUN_004ce990();
              uStack_874 = *puVar10;
              uStack_888._4_4_ = SUB84(_DAT_007d0a60,0);
              uStack_888._0_4_ = (float)((ulonglong)_DAT_007d0a60 >> 0x20);
              uStack_87c._0_4_ = uVar9;
              uStack_87c._4_4_ = uVar5;
              FUN_004feea4();
              FUN_004ce990();
              FUN_004fe844();
              FUN_004fef54();
              FUN_004fe844();
              FUN_004ce990();
              FUN_004fe844();
              FUN_004feea4();
              FUN_004fef54();
              FUN_004fe844();
              FUN_005406b0();
            }
          }
        }
        local_8._0_1_ = 6;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_124);
      }
      if ((param_2 != '\0') &&
         (*(double *)(param_1 + 0x88) < (double)(*(int *)(param_1 + 0x68) - local_100))) {
        *(double *)(param_1 + 0x88) = (double)*(int *)(param_1 + 0x68) - (double)local_100;
      }
      *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) - local_100;
      *(undefined4 *)(param_1 + 0x70) = local_fc;
      *(int *)(param_1 + 0x74) = local_f0;
      local_64 = local_64 + 1;
      if (param_2 == '\0') {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x497f6b;
        FUN_0049b6c0();
      }
      local_8._0_1_ = 2;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_ec);
      break;
    case '\v':
      local_89 = '\0';
      break;
    case '\f':
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x495065;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(uint *)(param_1 + 0x68));
      bVar1 = *pbVar12;
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x495089;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(int *)(param_1 + 0x68) + 1);
      bVar2 = *pbVar12;
      iVar8 = FUN_004cbb30();
      local_c0 = (bVar1 - 0xe) * 0x1000 + (bVar2 - 0xe) * 0x40 + -0xe +
                 (uint)*(byte *)(iVar8 + 2 + *(int *)(param_1 + 0x68));
      if ((local_c0 == 0xffff) || (local_c0 == 0)) {
        local_c0 = DAT_00a18adc;
      }
      if (local_c0 < 1) {
        local_2a0 = 1;
      }
      else {
        local_2a0 = local_c0;
      }
      local_c0 = local_2a0;
      if (param_2 != '\0') {
        *(double *)(param_1 + 0x80) = (double)local_2a0;
      }
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 4;
      *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 4;
      local_5c = local_5c + 4;
      local_64 = local_64 + 1;
      break;
    case '\x0e':
      if ((param_2 != '\0') && (*(int *)(param_1 + 0xe4) < *(int *)(param_1 + 0x68))) {
        *(int *)(param_1 + 0xe4) = *(int *)(param_1 + 0x68) + 1;
        *(undefined4 *)(param_1 + 0xe8) = 0x10;
      }
      break;
    case '\x0f':
      if (((param_2 != '\0') && (*(int *)(param_1 + 0xec) < *(int *)(param_1 + 0x68))) &&
         (param_1[0xe0] ==
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>)0x0)) {
        *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 0x68);
        param_1[0xe2] =
             (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>)0x1;
      }
      break;
    case '\x10':
      if (param_2 != '\0') {
        param_1[0xe3] =
             (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>)0x1;
      }
      break;
    case '\x11':
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x498051;
      pcVar7 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               operator[](param_1,*(uint *)(param_1 + 0x68));
      if (*pcVar7 + -0xe < 0) {
        local_5c8 = 0;
      }
      else {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x49807a;
        pcVar7 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 operator[](param_1,*(uint *)(param_1 + 0x68));
        local_5c8 = *pcVar7 + -0xe;
      }
      if (local_5c8 < 4) {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4980b0;
        pcVar7 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 operator[](param_1,*(uint *)(param_1 + 0x68));
        if (*pcVar7 + -0xe < 0) {
          local_5d0 = 0;
        }
        else {
          pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x4980d9;
          pcVar7 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   operator[](param_1,*(uint *)(param_1 + 0x68));
          local_5d0 = *pcVar7 + -0xe;
        }
        local_5cc = local_5d0;
      }
      else {
        local_5cc = 3;
      }
      *(int *)(param_1 + 0xdc) = local_5cc;
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 2;
      *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 2;
      local_5c = local_5c + 2;
      break;
    case '\x12':
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x498156;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(uint *)(param_1 + 0x68));
      bVar1 = *pbVar12;
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x498177;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(int *)(param_1 + 0x68) + 1);
      local_13c = (bVar1 - 0xe) * 0x40 + -0xe + (uint)*pbVar12;
      local_6c = local_13c + -1000;
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 2;
      *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 2;
      local_5c = local_5c + 2;
      break;
    case '\x13':
      local_68 = 0;
      break;
    case '\x14':
      local_68 = 1;
      break;
    case '\x15':
      local_68 = 2;
      break;
    case '\x16':
    case '\x17':
    case '\x1f':
    case '\"':
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x498201;
      pcVar7 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               operator[](local_88,1);
      local_145 = *pcVar7;
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x498216;
      pcVar7 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               operator[](local_88,1);
      switch(*pcVar7) {
      case '\x16':
      case '\x1f':
        iVar8 = FUN_004ce080();
        if (iVar8 <= *(int *)(param_1 + 100)) {
          pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x498289;
          FUN_004ce970();
          pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x4982a4;
          puVar10 = (undefined4 *)FUN_004ce990();
          *puVar10 = 0;
        }
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4982bf;
        pbVar12 = (byte *)std::
                          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ::operator[](param_1,*(uint *)(param_1 + 0x68));
        bVar1 = *pbVar12;
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4982e3;
        pbVar12 = (byte *)std::
                          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ::operator[](param_1,*(int *)(param_1 + 0x68) + 1);
        bVar2 = *pbVar12;
        iVar8 = FUN_004cbb30();
        local_150 = (bVar1 - 0xe) * 0x1000 + (bVar2 - 0xe) * 0x40 + -0xe +
                    (uint)*(byte *)(iVar8 + 2 + *(int *)(param_1 + 0x68));
        *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 3;
        local_5c = local_5c + 3;
        if ((9999 < local_150) || (local_150 < 0)) goto LAB_0049492c;
        iVar8 = FUN_004ce080();
        if (iVar8 <= local_150) goto LAB_0049492c;
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x498371;
        piVar13 = (int *)FUN_004ce990();
        local_14c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    *piVar13;
        if ((int)local_14c < 1) goto LAB_0049492c;
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x498398;
        piVar13 = (int *)FUN_004ce990();
        local_144 = (*piVar13 * local_a4) / 100;
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4983c0;
        piVar13 = (int *)FUN_004ce990();
        local_140 = (*piVar13 * local_a4) / 100;
        break;
      case '\x17':
      case '\"':
        iVar8 = FUN_004ce080();
        if (iVar8 <= *(int *)(param_1 + 100)) {
          pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x498416;
          FUN_004ce970();
          pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x498431;
          puVar10 = (undefined4 *)FUN_004ce990();
          *puVar10 = 0;
        }
        local_174 = *(undefined4 *)(param_1 + 0x68);
        basic_string<>();
        local_8._0_1_ = 10;
        while( true ) {
          local_34 = local_5c;
          local_a0 = *(uint *)(param_1 + 0x68);
          pbStack_868 = local_5c;
          pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x498482;
          iVar8 = FUN_00417a40();
          *(int *)(param_1 + 0x68) = (iVar8 - (int)local_5c) + *(int *)(param_1 + 0x68);
          pbStack_868 = local_34;
          pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x4984a5;
          local_5c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     FUN_00417a40();
          pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )local_a0;
          pbStack_86c = local_238;
          pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x4984d4;
          FUN_004cbc20();
          local_8._0_1_ = 0xb;
          pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x4984fc;
          FUN_004cb840();
          local_8._0_1_ = 10;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_238);
          pbStack_868 = local_88;
          pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x49851c;
          cVar6 = FUN_004ec750();
          if (cVar6 != '\0') break;
          iVar8 = FUN_004e5650();
          if (iVar8 <= (int)(local_a0 + 1)) break;
          pcVar7 = (char *)FUN_004cbb30();
          if (*pcVar7 == '\0') {
            pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x498564;
            std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                      ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_88,
                       "\\");
          }
          pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x498576;
          FUN_004cb880();
        }
        cVar6 = FUN_004cbb70();
        if (cVar6 != '\0') {
          local_8._0_1_ = 2;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_16c);
          goto LAB_0049492c;
        }
        local_23c = (undefined1 *)&uStack_87c;
        uStack_888._4_4_ = 0x4985b8;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_87c,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_16c);
        uStack_888._4_4_ = 0x4985ca;
        FUN_004293c0();
        local_8._0_1_ = 0xc;
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4985f5;
        FUN_004cb840();
        local_8._0_1_ = 10;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_258);
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x1;
        pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x1;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_888,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_16c);
        FUN_00422450();
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x498640;
        puVar10 = (undefined4 *)FUN_004cc680();
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      *puVar10;
        pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x49865b;
        local_170 = pbStack_868;
        FUN_004cde80();
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x498662;
        piVar13 = (int *)FUN_004ce990();
        local_14c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    *piVar13;
        if ((int)local_14c < 1) {
          local_8._0_1_ = 2;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_16c);
          goto LAB_0049492c;
        }
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      &local_144;
        pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4986a1;
        pbStack_86c = local_14c;
        FUN_00515880();
        local_144 = (local_144 * local_a4) / 100;
        local_140 = (local_140 * local_a4) / 100;
        local_8._0_1_ = 2;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_16c);
      }
      if ((param_2 != '\0') && ((local_145 == '\x1f' || (local_145 == '\"')))) {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x498710;
        FUN_005160a0();
      }
      if (local_98 < local_140) {
        local_98 = local_140;
      }
      if (param_2 != '\0') {
        if (param_5 == _DAT_007d0a60) {
          FUN_004fe844();
          iVar8 = FUN_004fe844();
          if ((float10)(-(iVar8 + DAT_0084b264 * 2) * DAT_0084b248) < extraout_ST0) {
            iVar8 = FUN_004fe844();
            if ((float)iVar8 + *(float *)(param_1 + 0x54) < (float)(*DAT_00a16718 * DAT_0084b248)) {
              iVar8 = FUN_004fe844();
              if ((float)iVar8 + *(float *)(param_1 + 0x58) < (float)(*DAT_00a1671c * DAT_0084b248))
              {
                FUN_004fe844();
                iVar8 = FUN_004fe844();
                if ((float10)(-(iVar8 + DAT_0084b264 * 2) * DAT_0084b248) < extraout_ST0_00)
                goto LAB_004988db;
              }
            }
          }
        }
        else {
LAB_004988db:
          uStack_87c._4_4_ = uVar9;
          if (DAT_00a1928c == 200) {
            if (param_5 == _DAT_007d0a60) {
              pbStack_868 = local_14c;
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x498b89;
              pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)FUN_004fe844();
              pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(param_1 + 100);
              uStack_874 = 0x498ba5;
              FUN_004ce990();
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x498bd1;
              FUN_004fe844();
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x498c18;
              pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)FUN_004fe844();
              uStack_874 = 0x498c62;
              uStack_874 = FUN_004fe844();
              uStack_87c._4_4_ = *(undefined4 *)(param_1 + 100);
              uStack_87c._0_4_ = 0x498c7e;
              FUN_004ce990();
              uStack_87c._4_4_ = 0x498caa;
              FUN_004fe844();
              uStack_87c._4_4_ = 0x498cd2;
              uStack_87c._4_4_ = FUN_004fe844();
              uStack_87c._0_4_ = 0x498cd8;
              FUN_0051f060();
            }
            else {
              pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x0;
              pbStack_86c = DAT_0084b240;
              pbStack_870 = local_14c;
              uStack_87c._0_4_ = (undefined4)((ulonglong)((double)DAT_0084b248 * param_4) >> 0x20);
              uStack_888 = (double)DAT_0084b248 * param_3;
              uStack_874 = uVar5;
              FUN_004feea4();
              FUN_004ce990();
              FUN_004fe844();
              FUN_004fef54();
              FUN_004fe844();
              FUN_004ce990();
              FUN_004fe844();
              FUN_004feea4();
              FUN_004fef54();
              FUN_004fe844();
              FUN_005269d0();
            }
            if (local_98 < local_140) {
              local_98 = local_140;
            }
          }
          else if (param_5 == _DAT_007d0a60) {
            pbStack_868 = local_14c;
            pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x498fa3;
            pbStack_86c = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)FUN_004fe844();
            pbStack_870 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            **)(param_1 + 100);
            uStack_874 = 0x498fbf;
            FUN_004ce990();
            pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x498feb;
            FUN_004fe844();
            pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x499039;
            FUN_004fe844();
            pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x49904a;
            pbStack_870 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)FUN_004fe844();
            uStack_874 = 0x499080;
            FUN_004fe844();
            uStack_874 = 0x49909a;
            uStack_874 = FUN_004fe844();
            uStack_87c._4_4_ = *(undefined4 *)(param_1 + 100);
            uStack_87c._0_4_ = 0x4990b6;
            FUN_004ce990();
            uStack_87c._4_4_ = 0x4990e2;
            FUN_004fe844();
            uStack_87c._4_4_ = 0x499108;
            FUN_004fe844();
            uStack_87c._4_4_ = 0x499119;
            uStack_87c._4_4_ = FUN_004fe844();
            uStack_87c._0_4_ = 0x49911f;
            FUN_0051f060();
          }
          else {
            pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x0;
            pbStack_86c = DAT_0084b240;
            pbStack_870 = local_14c;
            uStack_87c._0_4_ = (undefined4)((ulonglong)((double)DAT_0084b248 * param_4) >> 0x20);
            uStack_888 = (double)DAT_0084b248 * param_3;
            uStack_874 = uVar5;
            FUN_004feea4();
            FUN_004ce990();
            FUN_004fe844();
            FUN_004fef54();
            FUN_004fe844();
            FUN_004ce990();
            FUN_004fe844();
            FUN_004feea4();
            FUN_004fef54();
            FUN_004fe844();
            FUN_005269d0();
          }
        }
      }
      if (DAT_00a1928c == 200) {
        local_144 = (int)(2 / (longlong)DAT_0084b248) * local_144;
      }
      *(int *)(param_1 + 0x5c) =
           ((local_144 * *(int *)(param_1 + 0x100)) / 2 - (local_58 * *(int *)(param_1 + 0x100)) / 2
           ) + *(int *)(param_1 + 0x5c);
      local_64 = local_64 + 1;
      if (param_2 == '\0') {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4991ad;
        FUN_0049b6c0();
      }
      else if ((local_145 == '\x1f') || (local_145 == '\"')) {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4991ec;
        FUN_005160a0();
      }
      break;
    case '\x18':
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x499209;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(uint *)(param_1 + 0x68));
      bVar1 = *pbVar12;
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x49922a;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(int *)(param_1 + 0x68) + 1);
      local_178 = (bVar1 - 0xe) * 0x40 + -0x1396 + (uint)*pbVar12;
      *(int *)(param_1 + 0x5c) = (local_178 * 100) / DAT_00a1928c + *(int *)(param_1 + 0x5c);
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 3;
      *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 3;
      local_5c = local_5c + 3;
      if (*DAT_00a16714 < 0xcb) {
        local_64 = local_64 + 1;
      }
      if (param_2 == '\0') {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4992c8;
        FUN_0049b6c0();
      }
      break;
    case '\x19':
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4992e2;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(uint *)(param_1 + 0x68));
      bVar1 = *pbVar12;
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x499303;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(int *)(param_1 + 0x68) + 1);
      local_17c = (bVar1 - 0xe) * 0x40 + -0x1396 + (uint)*pbVar12;
      *(int *)(param_1 + 0x60) = (local_17c * 100) / DAT_00a1928c + *(int *)(param_1 + 0x60);
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 3;
      *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 3;
      local_5c = local_5c + 3;
      if (*DAT_00a16714 < 0xcb) {
        local_64 = local_64 + 1;
      }
      if (param_2 == '\0') {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4993a1;
        FUN_0049b6c0();
      }
      break;
    case '\x1a':
      local_54 = 1;
      break;
    case '\x1b':
      local_54 = 0;
      break;
    case '\x1c':
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4993ce;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_88,"\\");
    case '\x1d':
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4993e3;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(uint *)(param_1 + 0x68));
      bVar1 = *pbVar12;
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x499404;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(int *)(param_1 + 0x68) + 1);
      local_180 = (bVar1 - 0xe) * 0x40 + -0x1396 + (uint)*pbVar12;
      *(int *)(param_1 + 0x5c) = (local_180 * 100) / DAT_00a1928c;
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 3;
      *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 3;
      local_5c = local_5c + 3;
      if (*DAT_00a16714 < 0xcb) {
        local_64 = local_64 + 1;
      }
      if (param_2 == '\0') {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x49949a;
        FUN_0049b6c0();
      }
      break;
    case '\x1e':
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4994b4;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(uint *)(param_1 + 0x68));
      bVar1 = *pbVar12;
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4994d5;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(int *)(param_1 + 0x68) + 1);
      local_184 = (bVar1 - 0xe) * 0x40 + -0x1396 + (uint)*pbVar12;
      *(int *)(param_1 + 0x60) = (local_184 * 100) / DAT_00a1928c;
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 3;
      *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 3;
      local_5c = local_5c + 3;
      if (0xdb < *DAT_00a16714) {
        local_98 = 0;
      }
      if (*DAT_00a16714 < 0xcb) {
        local_64 = local_64 + 1;
      }
      if (param_2 == '\0') {
        pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x499584;
        FUN_0049b6c0();
      }
      break;
    case ' ':
      local_89 = '\x01';
      break;
    case '!':
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x499665;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(uint *)(param_1 + 0x68));
      bVar1 = *pbVar12;
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x499689;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(int *)(param_1 + 0x68) + 1);
      bVar2 = *pbVar12;
      iVar8 = FUN_004cbb30();
      *(uint *)(param_1 + 0x108) =
           (bVar1 - 0xe) * 0x1000 + (bVar2 - 0xe) * 0x40 + -0xf +
           (uint)*(byte *)(iVar8 + 2 + *(int *)(param_1 + 0x68));
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 3;
      *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 3;
      local_5c = local_5c + 3;
      break;
    case '#':
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x49959e;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(uint *)(param_1 + 0x68));
      local_188 = *pbVar12 - 0xe;
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4995c2;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(int *)(param_1 + 0x68) + 1);
      local_18c = *pbVar12 - 0xe;
      iVar8 = FUN_004cbb30();
      bVar1 = *(byte *)(iVar8 + *(int *)(param_1 + 0x68));
      iVar8 = FUN_004cbb30();
      *(uint *)(param_1 + 0x78) =
           (bVar1 - 0xe) * 0x40 + -0xe + (uint)*(byte *)(iVar8 + 1 + *(int *)(param_1 + 0x68));
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 3;
      *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 3;
      local_5c = local_5c + 3;
      break;
    case '$':
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x499712;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(uint *)(param_1 + 0x68));
      bVar1 = *pbVar12;
      pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x499736;
      pbVar12 = (byte *)std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,*(int *)(param_1 + 0x68) + 1);
      bVar2 = *pbVar12;
      iVar8 = FUN_004cbb30();
      *(uint *)(param_1 + 0x10c) =
           (bVar1 - 0xe) * 0x1000 + (bVar2 - 0xe) * 0x40 + -0xf +
           (uint)*(byte *)(iVar8 + 2 + *(int *)(param_1 + 0x68));
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 3;
      *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 3;
      local_5c = local_5c + 3;
      break;
    case '%':
      goto switchD_00494c87_caseD_25;
    }
  } while( true );
switchD_00494c87_caseD_25:
  pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                0x4997bf;
  pbVar12 = (byte *)std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                    operator[](param_1,*(uint *)(param_1 + 0x68));
  bVar1 = *pbVar12;
  pbStack_868 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                0x4997e3;
  pbVar12 = (byte *)std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                    operator[](param_1,*(int *)(param_1 + 0x68) + 1);
  bVar2 = *pbVar12;
  iVar8 = FUN_004cbb30();
  local_a4 = (bVar1 - 0xe) * 0x1000 + (bVar2 - 0xe) * 0x40 + -0xe +
             (uint)*(byte *)(iVar8 + 2 + *(int *)(param_1 + 0x68));
  *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 3;
  *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 3;
  local_5c = local_5c + 3;
  goto LAB_0049492c;
}

