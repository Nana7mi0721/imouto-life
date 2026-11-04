
basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_0043be80(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,int param_2,
            undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar3;
  undefined1 auStack_d8 [20];
  undefined4 uStack_c4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_c0;
  undefined1 auStack_bc [4];
  undefined4 uStack_b8;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbStack_b4;
  int iStack_b0;
  int iStack_ac;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbStack_a8;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_5c [28];
  undefined1 *local_40;
  undefined1 *local_3c;
  undefined *local_38;
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
  puStack_c = &LAB_007ad3a5;
  local_10 = ExceptionList;
  if ((param_2 < 1500000) || (1599999 < param_2)) {
    if ((param_2 < 0) || (999999 < param_2)) {
      if ((((param_2 < 15000000) || (15999999 < param_2)) || (param_2 % 100 < 5)) ||
         (9 < param_2 % 100)) {
        if ((param_2 < 3000000) || (3999999 < param_2)) {
          if ((param_2 < 9900000) || (9999999 < param_2)) {
            if ((param_2 < 1000000000) || (1099999999 < param_2)) {
              if ((param_2 < 1100000000) || (1199999999 < param_2)) {
                if ((param_2 < 1300000000) || (1399999999 < param_2)) {
                  ExceptionList = &local_10;
                  if ((9099999 < param_2) && (ExceptionList = &local_10, param_2 < 0x8c3a70)) {
                    if (param_2 < 0x8c1360) {
                      pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                    *)0x43c493;
                      ExceptionList = &local_10;
                      iVar2 = FUN_0046f600();
                      if (iVar2 != -1) {
                        pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                      *)0x43c4b8;
                        FUN_0046f600();
                        pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                      *)0x43c4c3;
                        local_38 = (undefined *)FUN_004d2a00();
                        if (param_2 % 10 == 9) {
                          pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                        *)0x43c4f1;
                          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                    (param_1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                                              *)(local_38 + 8));
                          ExceptionList = local_10;
                          return param_1;
                        }
                      }
                    }
                    else {
                      if ((param_2 % 0x8c1360) / 10 == 0) {
                        local_38 = &DAT_00a14438;
                        ExceptionList = &local_10;
                      }
                      else {
                        ExceptionList = &local_10;
                        iVar2 = FUN_004d25e0();
                        if (iVar2 < (param_2 % 0x8c1360) / 10) {
                          param_2 = -0xb;
                        }
                        else {
                          pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                        *)0x43c426;
                          local_38 = (undefined *)FUN_004d2620();
                        }
                      }
                      if (param_2 % 10 == 9) {
                        pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                      *)0x43c45d;
                        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                  (param_1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                                            *)(local_38 + 8));
                        ExceptionList = local_10;
                        return param_1;
                      }
                    }
                  }
                  pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                               0x43c50c;
                  basic_string<>();
                }
                else {
                  iStack_b0 = (param_2 % 1300000000) / 1000000;
                  iStack_ac = (param_2 % 1000000) / 100;
                  pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                               (param_2 % 100);
                  pbStack_b4 = param_1;
                  uStack_b8 = 0x43c377;
                  ExceptionList = &local_10;
                  local_34 = iStack_ac;
                  local_30 = iStack_b0;
                  local_2c = (int)pbStack_a8;
                  FUN_0046ff30();
                }
              }
              else {
                iStack_b0 = (param_2 % 1100000000) / 1000000;
                iStack_ac = (param_2 % 1000000) / 100;
                local_20 = param_2 % 100;
                local_28 = iStack_ac;
                local_24 = iStack_b0;
                if (param_4 == 0) {
                  pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                               0x43c299;
                  ExceptionList = &local_10;
                  iVar2 = FUN_004717c0();
                  if (iVar2 <= local_28) {
                    pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                                 local_24;
                    iStack_ac = 0x43c2b3;
                    FUN_004779b0();
                  }
                  pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                               local_20;
                  iStack_ac = local_28;
                  iStack_b0 = local_24;
                  pbStack_b4 = param_1;
                  uStack_b8 = 0x43c2cf;
                  FUN_0046ff30();
                }
                else {
                  pbStack_b4 = param_1;
                  uStack_b8 = 0x43c2fa;
                  ExceptionList = &local_10;
                  pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                               local_20;
                  FUN_0046ff30();
                }
              }
            }
            else {
              iStack_b0 = (param_2 % 1000000000) / 1000000;
              iStack_ac = (param_2 % 1000000) / 100;
              pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                           (param_2 % 100);
              pbStack_b4 = param_1;
              uStack_b8 = 0x43c21c;
              ExceptionList = &local_10;
              local_1c = iStack_ac;
              local_18 = iStack_b0;
              local_14 = (int)pbStack_a8;
              FUN_0046ff30();
            }
          }
          else {
            pbStack_a8 = param_1;
            iStack_ac = 0x43c19f;
            ExceptionList = &local_10;
            FUN_00440570();
          }
        }
        else {
          ExceptionList = &local_10;
          iVar2 = FUN_004cc430();
          if (param_2 % 1000000 < iVar2) {
            pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x43c13d
            ;
            pbVar3 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )FUN_004cc4c0();
            pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x43c146
            ;
            std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
            basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_1,pbVar3);
          }
          else {
            pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x43c164
            ;
            basic_string<>();
          }
        }
      }
      else {
        ExceptionList = &local_10;
        iVar2 = FUN_004cd340();
        if ((param_2 % 1000000) / 100 < iVar2) {
          pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x43c07e;
          FUN_004cde80();
          iVar2 = FUN_004cc430();
          if (param_2 % 100 + -5 < iVar2) {
            pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                         ((param_2 % 1000000) / 100);
            iStack_ac = 0x43c0b9;
            FUN_004cde80();
            pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x43c0c0
            ;
            pbVar3 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )FUN_004cc4c0();
            pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x43c0c9
            ;
            std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
            basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_1,pbVar3);
            ExceptionList = local_10;
            return param_1;
          }
        }
        pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x43c0e7;
        basic_string<>();
      }
    }
    else {
      pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x43bfd0;
      ExceptionList = &local_10;
      basic_string<>();
    }
  }
  else {
    ExceptionList = &local_10;
    if ((1499999 < param_2) && (ExceptionList = &local_10, param_2 < 1600000)) {
      local_3c = auStack_bc;
      pbStack_c0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   &DAT_007ce889;
      uStack_c4 = 0x43beef;
      ExceptionList = &local_10;
      basic_string<>();
      local_8 = 0;
      pbStack_c0 = local_5c;
      uStack_c4 = 0x43bf08;
      FUN_00438b60();
      local_8._0_1_ = 1;
      pbStack_c0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   0x43bf20;
      FUN_004cbb30();
      local_40 = auStack_d8;
      basic_string<>();
      local_8._0_1_ = 2;
      basic_string<>(&DAT_007ce890);
      uVar1 = FUN_00401c50();
      basic_string<>(uVar1);
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_0042bed0();
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_5c);
    }
    pbStack_a8 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x43bfa3;
    basic_string<>();
  }
  ExceptionList = local_10;
  return param_1;
}

