
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
FUN_0047cf40(int param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  int in_stack_00000020;
  int in_stack_00000024;
  long in_stack_00000028;
  long in_stack_0000002c;
  long in_stack_00000030;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *in_stack_00000034;
  int iStack_1f8;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_1f0 [4];
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  int iStack_1e4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_1e0;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbStack_1dc;
  int local_1c4;
  int local_1bc;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_154 [28];
  undefined1 *local_138;
  undefined1 *local_134;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_130 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_114 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_f8 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_dc [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_c0 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_a4 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_88 [28];
  int local_6c;
  int local_68;
  char local_61;
  long local_60;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_5c [28];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_40 [28];
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007af290;
  local_10 = ExceptionList;
  local_24 = DAT_0084b484;
  local_8 = 0;
  pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&param_2;
  pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                0x47cf82;
  ExceptionList = &local_10;
  cVar1 = FUN_004ec750();
  if (cVar1 != '\0') {
    FUN_0047db00();
    local_6c = -10;
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
    ExceptionList = local_10;
    return local_6c;
  }
  DAT_00a14358 = in_stack_0000002c;
  local_1c = 0;
  local_18 = (&DAT_00a14328)[in_stack_00000020] + (&DAT_00a14334)[in_stack_00000020];
  pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x47cfed;
  iVar2 = FUN_004717c0();
  if (iVar2 <= local_18) {
    pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                  (in_stack_00000020 + 1);
    pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x47d00a;
    FUN_004779b0();
  }
  while( true ) {
    pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_007d0c58;
    pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x47d019;
    local_1c = FUN_004cbbc0();
    if (local_1c == DAT_007d0624) break;
    pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x1;
    iStack_1e4 = 0x47d03a;
    pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  local_1c;
    FUN_004cba30();
  }
  pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&param_2;
  pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                0x47d04a;
  cVar1 = FUN_004ec750();
  if (cVar1 == '\0') {
    pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_007d0c54;
    pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x47d063;
    uVar3 = FUN_004cbbc0();
    if (1 < uVar3) {
      pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x47d080;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                (local_5c,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)&param_2);
      local_8._0_1_ = 1;
      pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x47d090;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                (local_40,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)&param_2);
      local_8._0_1_ = 2;
      pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_007d0c54
      ;
      pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x47d0a3;
      local_1c = FUN_004cbbc0();
      if (local_1c != DAT_007d0624) {
        pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x0;
        pbStack_1e0 = local_88;
        iStack_1e4 = 0x47d0ca;
        FUN_004cbc20();
        local_8._0_1_ = 3;
        pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x47d0ef;
        FUN_004cb840();
        local_8._0_1_ = 2;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_88);
        pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x0;
        pbStack_1e0 = local_a4;
        iStack_1e4 = 0x47d113;
        FUN_004cbc20();
        local_8._0_1_ = 4;
        pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x47d138;
        FUN_004cb840();
        local_8._0_1_ = 2;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_a4);
        local_14 = local_1c;
        pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                      &DAT_007d0c54;
        pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x47d161;
        local_1c = FUN_004cbbc0();
        if (local_1c == DAT_007d0624) {
          FUN_004e5650();
          pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                        (local_14 + 1);
          pbStack_1e0 = local_130;
          iStack_1e4 = 0x47d351;
          FUN_004cbc20();
          local_8._0_1_ = 9;
          pcVar4 = (char *)FUN_004cbb30();
          pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x47d378;
          in_stack_0000002c = _atol(pcVar4);
          local_8._0_1_ = 2;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_130);
        }
        else {
          pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                        (local_14 + 1);
          pbStack_1e0 = local_c0;
          iStack_1e4 = 0x47d193;
          FUN_004cbc20();
          local_8._0_1_ = 5;
          pcVar4 = (char *)FUN_004cbb30();
          pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x47d1ba;
          in_stack_0000002c = _atol(pcVar4);
          local_8._0_1_ = 2;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_c0);
          DAT_00a14358 = in_stack_0000002c;
          local_14 = local_1c;
          pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                        &DAT_007d0c54;
          pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x47d1f2;
          local_1c = FUN_004cbbc0();
          if (local_1c == DAT_007d0624) {
            FUN_004e5650();
            pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          (local_14 + 1);
            pbStack_1e0 = local_114;
            iStack_1e4 = 0x47d2ee;
            FUN_004cbc20();
            local_8._0_1_ = 8;
            pcVar4 = (char *)FUN_004cbb30();
            pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          0x47d315;
            in_stack_00000030 = _atol(pcVar4);
            local_8._0_1_ = 2;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_114);
          }
          else {
            pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          (local_14 + 1);
            pbStack_1e0 = local_dc;
            iStack_1e4 = 0x47d224;
            FUN_004cbc20();
            local_8._0_1_ = 6;
            pcVar4 = (char *)FUN_004cbb30();
            pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          0x47d24b;
            in_stack_00000030 = _atol(pcVar4);
            local_8._0_1_ = 2;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_dc);
            local_14 = local_1c;
            FUN_004e5650();
            pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          (local_14 + 1);
            pbStack_1e0 = local_f8;
            iStack_1e4 = 0x47d28b;
            FUN_004cbc20();
            local_8._0_1_ = 7;
            pcVar4 = (char *)FUN_004cbb30();
            pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          0x47d2b2;
            in_stack_00000028 = _atol(pcVar4);
            local_8._0_1_ = 2;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_f8);
          }
        }
      }
      if (in_stack_00000034 !=
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0) {
        local_134 = abStack_1f0;
        iStack_1f8 = 0x47d3ac;
        iStack_1f8 = FUN_004cbb30();
        FUN_004ec870(abStack_1f0);
        FUN_0047e8b0();
      }
      pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                    in_stack_00000020;
      local_138 = (undefined1 *)&iStack_1f8;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&iStack_1f8,
                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_5c);
      FUN_0047df80();
      pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x47d402;
      pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                    FUN_004cbb30();
      pbStack_1e0 = local_154;
      iStack_1e4 = 0x47d40f;
      FUN_004ec870();
      local_8._0_1_ = 10;
      pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x47d446;
      piVar5 = (int *)FUN_004cc680();
      local_20 = *piVar5;
      local_8 = CONCAT31(local_8._1_3_,2);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_154);
      if (in_stack_00000020 == 0) {
        if (*(char *)(param_1 + 0x11c) == '\0') {
LAB_0047d489:
          if (((*(char *)(param_1 + 0x11c) != '\0') || (local_20 == 0)) ||
             (*(int *)(param_1 + 0x60) != local_20)) goto LAB_0047d4ae;
        }
        else {
          pbStack_1dc = local_5c;
          pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x47d47f;
          cVar1 = FUN_004ec8f0();
          if (cVar1 == '\0') goto LAB_0047d489;
        }
LAB_0047d4ca:
        if (in_stack_00000020 == 0) {
          if (in_stack_00000024 + 1 < 1) {
            local_1bc = 1;
          }
          else {
            local_1bc = in_stack_00000024 + 1;
          }
          *(int *)(param_1 + 0x6c) = local_1bc;
          *(int *)(param_1 + 0x74) = local_1bc;
          *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 0x80);
          *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x80);
          *(int *)(param_1 + 0x80) = (in_stack_0000002c * DAT_00a18b88) / 100;
          *(long *)(param_1 + 0x8c) = in_stack_00000030;
          local_60 = in_stack_00000030;
          if (*(char *)(param_1 + 0x11c) == '\0') {
            if (in_stack_00000034 !=
                (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0) {
              pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                            0x47d606;
              FUN_0055f370();
              pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                            in_stack_00000034;
              pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x47d61c;
              FUN_0055d2a0();
              pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x3;
              pbStack_1e0 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              **)(param_1 + 0x60);
              iStack_1e4 = 0x47d632;
              FUN_00561a00();
            }
            pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          (param_1 + 0x60);
            pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x47d657;
            piVar5 = (int *)FUN_004cc020();
            pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          ((local_60 * *piVar5) / 100);
            pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x47d66d;
            FUN_0055d100();
          }
          else {
            *(undefined4 *)(param_1 + 0x138) = 0xffffffff;
            pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          0x47d5b1;
            FUN_00401000();
            pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          0x47d5b8;
            FUN_004014e0();
            if (in_stack_00000034 !=
                (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x0) {
              pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                            0x47d5c5;
              FUN_00401000();
              pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                            0x47d5cc;
              FUN_00401470();
              pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x0;
              pbStack_1e0 = in_stack_00000034;
              iStack_1e4 = *(undefined4 *)(param_1 + 0x134);
              uStack_1e8 = 1;
              uStack_1ec = 0x47d5e8;
              FUN_00401000();
              uStack_1ec = 0x47d5ef;
              FUN_00401430();
            }
          }
          DAT_00a18bcc = *(undefined4 *)(param_1 + 0x80);
          DAT_00a18bd0 = *(undefined4 *)(param_1 + 0x8c);
          local_8._0_1_ = 1;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_40);
          local_8 = (uint)local_8._1_3_ << 8;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_5c);
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
          ExceptionList = local_10;
          return -10;
        }
        if (in_stack_00000020 == 1) {
          if (in_stack_00000024 + 1 < 1) {
            local_1c4 = 1;
          }
          else {
            local_1c4 = in_stack_00000024 + 1;
          }
          *(int *)(param_1 + 0x70) = local_1c4;
          *(int *)(param_1 + 0x78) = local_1c4;
          *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0x88);
          *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x88);
          *(int *)(param_1 + 0x88) = (in_stack_0000002c * DAT_00a18b8c) / 100;
          *(long *)(param_1 + 0x90) = in_stack_00000030;
          pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                        (param_1 + 0x68);
          pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x47d799;
          piVar5 = (int *)FUN_004cc020();
          pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                        ((in_stack_00000030 * *piVar5) / 100);
          pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x47d7af;
          FUN_0055d100();
          DAT_00a18bd8 = *(undefined4 *)(param_1 + 0x88);
          DAT_00a18bdc = *(undefined4 *)(param_1 + 0x90);
          local_8._0_1_ = 1;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_40);
          local_8 = (uint)local_8._1_3_ << 8;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_5c);
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
          ExceptionList = local_10;
          return -10;
        }
      }
      else {
LAB_0047d4ae:
        if ((in_stack_00000020 == 1) && (*(int *)(param_1 + 0x68) == local_20)) goto LAB_0047d4ca;
      }
      if (in_stack_00000020 == 2) {
        cVar1 = FUN_004ce0c0();
        if (cVar1 == '\0') {
          pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x47d842;
          piVar5 = (int *)FUN_004ce990();
          if (*piVar5 != 0) {
            pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          in_stack_00000020;
            pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x47d85a;
            FUN_0047c760();
            pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          0x47d86c;
            puVar6 = (undefined4 *)FUN_004ce990();
            *puVar6 = 0;
            goto LAB_0047d934;
          }
        }
        pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x47d88c;
        FUN_004cc020();
        pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x47d894;
        iVar2 = FUN_00560f10();
        if (iVar2 != 0) {
          local_61 = '\x01';
          local_68 = 0;
          while (iVar2 = FUN_004ce080(), local_68 < iVar2) {
            pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          0x47d8e0;
            piVar5 = (int *)FUN_004ce990();
            pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          0x47d8f7;
            piVar7 = (int *)FUN_004cc020();
            if (*piVar5 == *piVar7) {
              local_61 = '\0';
              break;
            }
            local_68 = local_68 + 1;
          }
          if (local_61 != '\0') {
            pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          0x47d922;
            FUN_004cc020();
            pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          0x47d934;
            FUN_004ce160();
          }
        }
      }
LAB_0047d934:
      pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x47d949;
      piVar5 = (int *)FUN_004cc020();
      *piVar5 = local_20;
      if (in_stack_00000020 == 2) {
        iStack_1f8 = 0x47d968;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  (abStack_1f0,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_40);
        iStack_1f8 = local_18;
        FUN_00478010(in_stack_00000020 + 1);
        pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x1;
        pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_18;
        iStack_1e4 = in_stack_00000020 + 1;
        uStack_1e8 = 0x47d9a0;
        FUN_00477f90();
        pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x2;
        pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_18;
        iStack_1e4 = in_stack_00000020 + 1;
        uStack_1e8 = 0x47d9bb;
        FUN_00477f90();
      }
      else {
        iStack_1f8 = 0x47d9d4;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  (abStack_1f0,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_40);
        iStack_1f8 = local_18;
        FUN_00478010(in_stack_00000020 + 1);
        pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x1;
        pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_18;
        iStack_1e4 = in_stack_00000020 + 1;
        uStack_1e8 = 0x47da0c;
        FUN_00477f90();
        pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x2;
        pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_18;
        iStack_1e4 = in_stack_00000020 + 1;
        uStack_1e8 = 0x47da27;
        FUN_00477f90();
        pbStack_1dc = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x3;
        pbStack_1e0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_18;
        iStack_1e4 = in_stack_00000020 + 1;
        uStack_1e8 = 0x47da42;
        FUN_00477f90();
      }
      iStack_1f8 = 0x47da57;
      basic_string<>();
      iStack_1f8 = ((&DAT_00a14334)[in_stack_00000020] + 9) % 10 +
                   (&DAT_00a14328)[in_stack_00000020];
      FUN_00478010(in_stack_00000020 + 1);
      (&DAT_00a14334)[in_stack_00000020] = ((&DAT_00a14334)[in_stack_00000020] + 1) % 10;
      local_8._0_1_ = 1;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_40);
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_5c);
      goto LAB_0047dac7;
    }
  }
  local_18 = -1;
LAB_0047dac7:
  iVar2 = local_18;
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  ExceptionList = local_10;
  return iVar2;
}

