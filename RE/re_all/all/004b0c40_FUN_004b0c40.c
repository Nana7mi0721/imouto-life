
undefined4 __thiscall FUN_004b0c40(int *param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 uStack_d4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_d0;
  undefined1 auStack_cc [12];
  undefined4 uStack_c0;
  undefined4 local_9c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_80 [28];
  undefined1 *local_64;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_60 [28];
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  char *local_28;
  short local_24 [2];
  uint local_20;
  char local_19;
  void *local_18;
  short local_14 [2];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b022e;
  local_10 = ExceptionList;
  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
    DAT_00a117e4 = 1;
    uVar3 = 0;
  }
  else {
    DAT_00a0f844 = 4;
    uStack_c0 = 0x4b0cbb;
    ExceptionList = &local_10;
    _memcpy(param_1 + 0x9b,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a0f828 < DAT_00a0f820 + 1) {
      DAT_00a117e4 = 1;
      uVar3 = 0;
    }
    else {
      DAT_00a0f844 = 1;
      uStack_c0 = 0x4b0d1e;
      _memcpy(param_1 + 0x9e,(void *)(DAT_00a0f824 + DAT_00a0f820),1);
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      if (DAT_00a0f828 < DAT_00a0f820 + 1) {
        DAT_00a117e4 = 1;
        uVar3 = 0;
      }
      else {
        DAT_00a0f844 = 1;
        uStack_c0 = 0x4b0d7f;
        _memcpy((void *)((int)param_1 + 0x279),(void *)(DAT_00a0f824 + DAT_00a0f820),1);
        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
        if (DAT_00a0f828 < DAT_00a0f820 + 2) {
          DAT_00a117e4 = 1;
          uVar3 = 0;
        }
        else {
          DAT_00a0f844 = 2;
          uStack_c0 = 0x4b0de1;
          _memcpy(param_1 + 0x9a,(void *)(DAT_00a0f824 + DAT_00a0f820),2);
          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
          if (DAT_00a0f828 < DAT_00a0f820 + 1) {
            DAT_00a117e4 = 1;
            uVar3 = 0;
          }
          else {
            DAT_00a0f844 = 1;
            uStack_c0 = 0x4b0e44;
            _memcpy(param_1 + 0x99,(void *)(DAT_00a0f824 + DAT_00a0f820),1);
            DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
            if (DAT_00a0f828 < DAT_00a0f820 + 1) {
              DAT_00a117e4 = 1;
              uVar3 = 0;
            }
            else {
              DAT_00a0f844 = 1;
              uStack_c0 = 0x4b0ea5;
              _memcpy((void *)((int)param_1 + 0x265),(void *)(DAT_00a0f824 + DAT_00a0f820),1);
              DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
              if ((char)param_1[0x99] == '\0') {
                if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                  DAT_00a117e4 = 1;
                  ExceptionList = local_10;
                  return 0;
                }
                DAT_00a0f844 = 2;
                uStack_c0 = 0x4b114f;
                _memcpy(local_24,(void *)(DAT_00a0f824 + DAT_00a0f820),2);
                DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                local_28 = _malloc((int)local_24[0] + 2);
                if (DAT_00a0f828 < local_24[0] + DAT_00a0f820) {
                  DAT_00a117e4 = 1;
                  ExceptionList = local_10;
                  return 0;
                }
                DAT_00a0f844 = (size_t)local_24[0];
                uStack_c0 = 0x4b11bd;
                _memcpy(local_28,(void *)(DAT_00a0f824 + DAT_00a0f820),DAT_00a0f844);
                DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                          ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                           (param_1 + 0x5b),local_28);
                _free(local_28);
              }
              else {
                if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                  DAT_00a117e4 = 1;
                  ExceptionList = local_10;
                  return 0;
                }
                DAT_00a0f844 = 2;
                uStack_c0 = 0x4b0f14;
                _memcpy(local_14,(void *)(DAT_00a0f824 + DAT_00a0f820),2);
                DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                local_18 = _malloc((int)local_14[0] + 2);
                if (DAT_00a0f828 < local_14[0] + DAT_00a0f820) {
                  DAT_00a117e4 = 1;
                  ExceptionList = local_10;
                  return 0;
                }
                DAT_00a0f844 = (size_t)local_14[0];
                uStack_c0 = 0x4b0f80;
                _memcpy(local_18,(void *)(DAT_00a0f824 + DAT_00a0f820),DAT_00a0f844);
                DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                bVar1 = DAT_00a0f84c < 0x7d;
                if (bVar1) {
                  local_64 = auStack_cc;
                  pbStack_d0 = local_18;
                  uStack_d4 = 0x4b0ff4;
                  basic_string<>();
                  pbStack_d0 = local_80;
                  uStack_d4 = 0x4b1003;
                  local_9c = FUN_00429250();
                }
                else {
                  local_9c = basic_string<>();
                }
                local_8 = (uint)bVar1;
                local_44 = local_9c;
                FUN_004cb840();
                local_8 = 0;
                if (bVar1) {
                  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            (local_80);
                }
                local_8 = 0xffffffff;
                if (!bVar1) {
                  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            (local_60);
                }
                iVar4 = FUN_004cbbc0();
                if (iVar4 != -1) {
                  local_20 = 0;
                  while (uVar5 = FUN_004e5650(), local_20 < uVar5) {
                    pcVar6 = std::
                             basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             ::operator[]((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                           *)(param_1 + 9),local_20);
                    local_19 = *pcVar6 + '\x01';
                    local_20 = local_20 + 1;
                  }
                }
                _free(local_18);
              }
              if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                DAT_00a117e4 = 1;
                uVar3 = 0;
              }
              else {
                DAT_00a0f844 = 4;
                uStack_c0 = 0x4b123e;
                _memcpy(param_1 + 0x62,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                  DAT_00a117e4 = 1;
                  uVar3 = 0;
                }
                else {
                  DAT_00a0f844 = 4;
                  uStack_c0 = 0x4b12a1;
                  _memcpy(param_1 + 100,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                    DAT_00a117e4 = 1;
                    uVar3 = 0;
                  }
                  else {
                    DAT_00a0f844 = 4;
                    uStack_c0 = 0x4b1302;
                    _memcpy(param_1 + 0x9c,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                      DAT_00a117e4 = 1;
                      uVar3 = 0;
                    }
                    else {
                      DAT_00a0f844 = 4;
                      uStack_c0 = 0x4b1364;
                      _memcpy(param_1 + 0x9d,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                      if ((((char)param_1[0x99] == '\0') && (param_2 != '\0')) &&
                         (cVar2 = operator!=<>(), cVar2 != '\0')) {
                        if (*(char *)((int)param_1 + 0x265) == '\0') {
                          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                      *)&uStack_d4,
                                     (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                                      *)(param_1 + 0x5b));
                          FUN_00477140();
                          if (*param_1 != 0) {
                            *(undefined1 *)((int)param_1 + 0x27a) = 0;
                            uStack_c0 = 0x4b150a;
                            FUN_00515880();
                          }
                        }
                        else {
                          local_30 = param_1[0x9c];
                          local_2c = param_1[0x9d];
                          pcVar6 = (char *)FUN_004cbb30();
                          if (*pcVar6 == '<') {
                            *(undefined1 *)((int)param_1 + 0x27a) = 0;
                          }
                          else {
                            std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                            basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                      ((basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                        *)&uStack_d4,
                                       (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                                        *)(param_1 + 0x5b));
                            FUN_00477140();
                            if (*param_1 != 0) {
                              *(undefined1 *)((int)param_1 + 0x27a) = 0;
                            }
                          }
                          param_1[0x9c] = local_30;
                          param_1[0x9d] = local_2c;
                        }
                      }
                      else if (((char)param_1[0x99] != '\0') && (param_2 != '\0')) {
                        *(undefined1 *)((int)param_1 + 0x27a) = 0;
                        *(double *)(param_1 + 0x22) = (double)DAT_00a18adc;
                        local_38 = 0;
                        local_34 = 0;
                        FUN_004a1c60();
                        param_1[0x70] = local_38;
                        param_1[0x72] = local_34;
                        param_1[0x71] = local_38;
                        param_1[0x73] = local_34;
                      }
                      if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                        DAT_00a117e4 = 1;
                        uVar3 = 0;
                      }
                      else {
                        DAT_00a0f844 = 4;
                        uStack_c0 = 0x4b15fb;
                        _memcpy(param_1 + 0x66,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                          DAT_00a117e4 = 1;
                          uVar3 = 0;
                        }
                        else {
                          DAT_00a0f844 = 4;
                          uStack_c0 = 0x4b165e;
                          _memcpy(param_1 + 0x68,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                            DAT_00a117e4 = 1;
                            uVar3 = 0;
                          }
                          else {
                            DAT_00a0f844 = 4;
                            uStack_c0 = 0x4b16bf;
                            _memcpy(param_1 + 0x6a,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                            DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                            if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                              DAT_00a117e4 = 1;
                              uVar3 = 0;
                            }
                            else {
                              DAT_00a0f844 = 4;
                              uStack_c0 = 0x4b1721;
                              _memcpy(param_1 + 0x6c,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                              DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                              if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                DAT_00a117e4 = 1;
                                uVar3 = 0;
                              }
                              else {
                                DAT_00a0f844 = 4;
                                uStack_c0 = 0x4b1784;
                                _memcpy(param_1 + 0x6d,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                  DAT_00a117e4 = 1;
                                  uVar3 = 0;
                                }
                                else {
                                  DAT_00a0f844 = 4;
                                  uStack_c0 = 0x4b17e5;
                                  _memcpy(param_1 + 0x74,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                    DAT_00a117e4 = 1;
                                    uVar3 = 0;
                                  }
                                  else {
                                    DAT_00a0f844 = 4;
                                    uStack_c0 = 0x4b1847;
                                    _memcpy(param_1 + 0x76,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                      DAT_00a117e4 = 1;
                                      uVar3 = 0;
                                    }
                                    else {
                                      DAT_00a0f844 = 4;
                                      uStack_c0 = 0x4b18aa;
                                      _memcpy(param_1 + 0x6e,(void *)(DAT_00a0f824 + DAT_00a0f820),4
                                             );
                                      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                      for (local_3c = 0; local_3c < 2; local_3c = local_3c + 1) {
                                        for (local_40 = 0; local_40 < 3; local_40 = local_40 + 1) {
                                          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                            DAT_00a117e4 = 1;
                                            ExceptionList = local_10;
                                            return 0;
                                          }
                                          DAT_00a0f844 = 4;
                                          uStack_c0 = 0x4b194c;
                                          _memcpy(param_1 + local_3c * 3 + local_40 + 0x78,
                                                  (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        }
                                      }
                                      if (0x68 < DAT_00a0f84c) {
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b19c9;
                                        _memcpy(param_1 + 0xaf,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b1a2b;
                                        _memcpy(param_1 + 0xb0,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b1a8e;
                                        _memcpy(param_1 + 0xb2,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b1aef;
                                        _memcpy(param_1 + 0xb1,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b1b51;
                                        _memcpy(param_1 + 0xb3,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b1bb4;
                                        _memcpy(param_1 + 0xb5,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b1c15;
                                        _memcpy(param_1 + 0xb4,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b1c77;
                                        _memcpy(param_1 + 0xb6,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b1cda;
                                        _memcpy(param_1 + 0xb8,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b1d3b;
                                        _memcpy(param_1 + 0xb7,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b1d9d;
                                        _memcpy(param_1 + 0xc0,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b1e00;
                                        _memcpy(param_1 + 0xc1,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b1e61;
                                        _memcpy(param_1 + 0xc2,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b1ec3;
                                        _memcpy(param_1 + 0xc3,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b1f26;
                                        _memcpy(param_1 + 199,(void *)(DAT_00a0f824 + DAT_00a0f820),
                                                4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b1f87;
                                        _memcpy(param_1 + 0xc6,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b1fe9;
                                        _memcpy(param_1 + 0xc4,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b204c;
                                        _memcpy(param_1 + 0xc5,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                      }
                                      if (0x6a < DAT_00a0f84c) {
                                        if (DAT_00a0f828 < DAT_00a0f820 + 1) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 1;
                                        uStack_c0 = 0x4b20b9;
                                        _memcpy((void *)((int)param_1 + 0x266),
                                                (void *)(DAT_00a0f824 + DAT_00a0f820),1);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                      }
                                      if (0x71 < DAT_00a0f84c) {
                                        if (DAT_00a0f828 < DAT_00a0f820 + 1) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 1;
                                        uStack_c0 = 0x4b212a;
                                        _memcpy((void *)((int)param_1 + 0x267),
                                                (void *)(DAT_00a0f824 + DAT_00a0f820),1);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 1) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 1;
                                        uStack_c0 = 0x4b218b;
                                        _memcpy(param_1 + 0x90,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,1);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b21ed;
                                        _memcpy(param_1 + 0x80,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b2250;
                                        _memcpy(param_1 + 0x81,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b22b1;
                                        _memcpy(param_1 + 0x82,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b2313;
                                        _memcpy(param_1 + 0x83,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b2376;
                                        _memcpy(param_1 + 0x88,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b23d7;
                                        _memcpy(param_1 + 0x89,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b2439;
                                        _memcpy(param_1 + 0x8a,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b249c;
                                        _memcpy(param_1 + 0x8b,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                      }
                                      if (0x72 < DAT_00a0f84c) {
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b250d;
                                        _memcpy(param_1 + 200,(void *)(DAT_00a0f824 + DAT_00a0f820),
                                                4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b256e;
                                        _memcpy(param_1 + 0xc9,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b25d0;
                                        _memcpy(param_1 + 0xca,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b2633;
                                        _memcpy(param_1 + 0xcb,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (0x73 < DAT_00a0f84c) {
                                          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                            DAT_00a117e4 = 1;
                                            ExceptionList = local_10;
                                            return 0;
                                          }
                                          DAT_00a0f844 = 4;
                                          uStack_c0 = 0x4b26a4;
                                          _memcpy(param_1 + 0xcc,
                                                  (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                            DAT_00a117e4 = 1;
                                            ExceptionList = local_10;
                                            return 0;
                                          }
                                          DAT_00a0f844 = 4;
                                          uStack_c0 = 0x4b2705;
                                          _memcpy(param_1 + 0xcd,
                                                  (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                            DAT_00a117e4 = 1;
                                            ExceptionList = local_10;
                                            return 0;
                                          }
                                          DAT_00a0f844 = 4;
                                          uStack_c0 = 0x4b2767;
                                          _memcpy(param_1 + 0xce,
                                                  (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                            DAT_00a117e4 = 1;
                                            ExceptionList = local_10;
                                            return 0;
                                          }
                                          DAT_00a0f844 = 4;
                                          uStack_c0 = 0x4b27ca;
                                          _memcpy(param_1 + 0xcf,
                                                  (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                            DAT_00a117e4 = 1;
                                            ExceptionList = local_10;
                                            return 0;
                                          }
                                          DAT_00a0f844 = 4;
                                          uStack_c0 = 0x4b282b;
                                          _memcpy(param_1 + 0xd0,
                                                  (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        }
                                        if (0x74 < DAT_00a0f84c) {
                                          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                            DAT_00a117e4 = 1;
                                            ExceptionList = local_10;
                                            return 0;
                                          }
                                          DAT_00a0f844 = 4;
                                          uStack_c0 = 0x4b289e;
                                          _memcpy(param_1 + 0xd1,
                                                  (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                            DAT_00a117e4 = 1;
                                            ExceptionList = local_10;
                                            return 0;
                                          }
                                          DAT_00a0f844 = 4;
                                          uStack_c0 = 0x4b2900;
                                          _memcpy(param_1 + 0xd2,
                                                  (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                            DAT_00a117e4 = 1;
                                            ExceptionList = local_10;
                                            return 0;
                                          }
                                          DAT_00a0f844 = 4;
                                          uStack_c0 = 0x4b2963;
                                          _memcpy(param_1 + 0xd3,
                                                  (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                            DAT_00a117e4 = 1;
                                            ExceptionList = local_10;
                                            return 0;
                                          }
                                          DAT_00a0f844 = 4;
                                          uStack_c0 = 0x4b29c4;
                                          _memcpy(param_1 + 0xd4,
                                                  (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                            DAT_00a117e4 = 1;
                                            ExceptionList = local_10;
                                            return 0;
                                          }
                                          DAT_00a0f844 = 4;
                                          uStack_c0 = 0x4b2a26;
                                          _memcpy(param_1 + 0xd5,
                                                  (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                            DAT_00a117e4 = 1;
                                            ExceptionList = local_10;
                                            return 0;
                                          }
                                          DAT_00a0f844 = 4;
                                          uStack_c0 = 0x4b2a89;
                                          _memcpy(param_1 + 0xd6,
                                                  (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        }
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b2aea;
                                        _memcpy(param_1 + 0xd8,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b2b4c;
                                        _memcpy(param_1 + 0xd9,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b2baf;
                                        _memcpy(param_1 + 0xda,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b2c10;
                                        _memcpy(param_1 + 0xdc,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b2c72;
                                        _memcpy(param_1 + 0xdd,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b2cd5;
                                        _memcpy(param_1 + 0xde,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                      }
                                      if (0x75 < DAT_00a0f84c) {
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b2d46;
                                        _memcpy(param_1 + 0xdf,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b2da7;
                                        _memcpy(param_1 + 0xe0,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                          DAT_00a117e4 = 1;
                                          ExceptionList = local_10;
                                          return 0;
                                        }
                                        DAT_00a0f844 = 4;
                                        uStack_c0 = 0x4b2e06;
                                        _memcpy(param_1 + 0xe1,(void *)(DAT_00a0f824 + DAT_00a0f820)
                                                ,4);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                      }
                                      uVar3 = 1;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  ExceptionList = local_10;
  return uVar3;
}

