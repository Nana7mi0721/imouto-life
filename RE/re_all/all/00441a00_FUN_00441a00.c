
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __fastcall FUN_00441a00(int param_1)

{
  undefined4 uVar1;
  void *_Dst;
  void *_Src;
  size_t _Size;
  int local_118;
  undefined1 local_114 [260];
  undefined4 local_10;
  short local_c [2];
  int local_8;
  
  local_10 = DAT_0084b484;
  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
    DAT_00a117e4 = 1;
    uVar1 = 0;
  }
  else {
    DAT_00a0f844 = 4;
    _memcpy((void *)(param_1 + 0x24),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
      DAT_00a117e4 = 1;
      uVar1 = 0;
    }
    else {
      DAT_00a0f844 = 4;
      _memcpy((void *)(param_1 + 0x28),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      if (DAT_00a0f828 < DAT_00a0f820 + 4) {
        DAT_00a117e4 = 1;
        uVar1 = 0;
      }
      else {
        DAT_00a0f844 = 4;
        _memcpy((void *)(param_1 + 0x2c),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
          DAT_00a117e4 = 1;
          uVar1 = 0;
        }
        else {
          DAT_00a0f844 = 4;
          _memcpy((void *)(param_1 + 0xc4),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
          if (DAT_00a0f828 < DAT_00a0f820 + 1) {
            DAT_00a117e4 = 1;
            uVar1 = 0;
          }
          else {
            DAT_00a0f844 = 1;
            _memcpy((void *)(param_1 + 0xbe),(void *)(DAT_00a0f824 + DAT_00a0f820),1);
            DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
            *(int *)(param_1 + 0x38) = DAT_0084b264 * 2 * *(int *)(param_1 + 0x28);
            *(int *)(param_1 + 0x3c) = DAT_0084b264 * 2 * *(int *)(param_1 + 0x2c);
            if (DAT_00a0f828 < DAT_00a0f820 + 4) {
              DAT_00a117e4 = 1;
              uVar1 = 0;
            }
            else {
              DAT_00a0f844 = 4;
              _memcpy((void *)(param_1 + 0x40),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
              DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
              if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                DAT_00a117e4 = 1;
                uVar1 = 0;
              }
              else {
                DAT_00a0f844 = 2;
                _memcpy(local_c,(void *)(DAT_00a0f824 + DAT_00a0f820),2);
                DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                if (DAT_00a0f828 < local_c[0] + DAT_00a0f820) {
                  DAT_00a117e4 = 1;
                  uVar1 = 0;
                }
                else {
                  DAT_00a0f844 = (size_t)local_c[0];
                  _memcpy(local_114,(void *)(DAT_00a0f824 + DAT_00a0f820),DAT_00a0f844);
                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                  basic_string<>(local_114);
                  FUN_004787b0();
                  if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                    DAT_00a117e4 = 1;
                    uVar1 = 0;
                  }
                  else {
                    DAT_00a0f844 = 2;
                    _memcpy((void *)(param_1 + 0x44),(void *)(DAT_00a0f824 + DAT_00a0f820),2);
                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                    if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                      DAT_00a117e4 = 1;
                      uVar1 = 0;
                    }
                    else {
                      DAT_00a0f844 = 2;
                      _memcpy((void *)(param_1 + 0x46),(void *)(DAT_00a0f824 + DAT_00a0f820),2);
                      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                      if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                        DAT_00a117e4 = 1;
                        uVar1 = 0;
                      }
                      else {
                        DAT_00a0f844 = 2;
                        _memcpy((void *)(param_1 + 0x48),(void *)(DAT_00a0f824 + DAT_00a0f820),2);
                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                        if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                          DAT_00a117e4 = 1;
                          uVar1 = 0;
                        }
                        else {
                          DAT_00a0f844 = 2;
                          _memcpy((void *)(param_1 + 0x4a),(void *)(DAT_00a0f824 + DAT_00a0f820),2);
                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                          if (DAT_00a0f828 < DAT_00a0f820 + 1) {
                            DAT_00a117e4 = 1;
                            uVar1 = 0;
                          }
                          else {
                            DAT_00a0f844 = 1;
                            _memcpy((void *)(param_1 + 0x52),(void *)(DAT_00a0f824 + DAT_00a0f820),1
                                   );
                            DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                            if (DAT_00a0f828 < DAT_00a0f820 + 1) {
                              DAT_00a117e4 = 1;
                              uVar1 = 0;
                            }
                            else {
                              DAT_00a0f844 = 1;
                              _memcpy((void *)(param_1 + 0x53),(void *)(DAT_00a0f824 + DAT_00a0f820)
                                      ,1);
                              DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                              FUN_0046df90();
                              FUN_0046df90();
                              if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                DAT_00a117e4 = 1;
                                uVar1 = 0;
                              }
                              else {
                                DAT_00a0f844 = 2;
                                _memcpy((void *)(param_1 + 0x58),
                                        (void *)(DAT_00a0f824 + DAT_00a0f820),2);
                                DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                  DAT_00a117e4 = 1;
                                  uVar1 = 0;
                                }
                                else {
                                  DAT_00a0f844 = 2;
                                  _memcpy((void *)(param_1 + 0x5a),
                                          (void *)(DAT_00a0f824 + DAT_00a0f820),2);
                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                  if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                    DAT_00a117e4 = 1;
                                    uVar1 = 0;
                                  }
                                  else {
                                    DAT_00a0f844 = 2;
                                    _memcpy((void *)(param_1 + 0x5e),
                                            (void *)(DAT_00a0f824 + DAT_00a0f820),2);
                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                    if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                      DAT_00a117e4 = 1;
                                      uVar1 = 0;
                                    }
                                    else {
                                      DAT_00a0f844 = 2;
                                      _memcpy((void *)(param_1 + 0x5c),
                                              (void *)(DAT_00a0f824 + DAT_00a0f820),2);
                                      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                      if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                        DAT_00a117e4 = 1;
                                        uVar1 = 0;
                                      }
                                      else {
                                        DAT_00a0f844 = 2;
                                        _memcpy((void *)(param_1 + 0xa8),
                                                (void *)(DAT_00a0f824 + DAT_00a0f820),2);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                          DAT_00a117e4 = 1;
                                          uVar1 = 0;
                                        }
                                        else {
                                          DAT_00a0f844 = 2;
                                          _memcpy((void *)(param_1 + 0xaa),
                                                  (void *)(DAT_00a0f824 + DAT_00a0f820),2);
                                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                          if (DAT_00a0f828 < DAT_00a0f820 + 1) {
                                            DAT_00a117e4 = 1;
                                            uVar1 = 0;
                                          }
                                          else {
                                            DAT_00a0f844 = 1;
                                            _memcpy((void *)(param_1 + 0xae),
                                                    (void *)(DAT_00a0f824 + DAT_00a0f820),1);
                                            DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                            if (DAT_00a0f828 < DAT_00a0f820 + 1) {
                                              DAT_00a117e4 = 1;
                                              uVar1 = 0;
                                            }
                                            else {
                                              DAT_00a0f844 = 1;
                                              _memcpy((void *)(param_1 + 0xaf),
                                                      (void *)(DAT_00a0f824 + DAT_00a0f820),1);
                                              DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                              if (DAT_00a0f828 < DAT_00a0f820 + 1) {
                                                DAT_00a117e4 = 1;
                                                uVar1 = 0;
                                              }
                                              else {
                                                DAT_00a0f844 = 1;
                                                _memcpy((void *)(param_1 + 0xb0),
                                                        (void *)(DAT_00a0f824 + DAT_00a0f820),1);
                                                DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                  DAT_00a117e4 = 1;
                                                  uVar1 = 0;
                                                }
                                                else {
                                                  DAT_00a0f844 = 4;
                                                  _memcpy(&local_8,(void *)(DAT_00a0f824 +
                                                                           DAT_00a0f820),4);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  FUN_004ce970();
                                                  for (local_118 = 0; local_118 < local_8;
                                                      local_118 = local_118 + 1) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    _Size = 4;
                                                    _Src = (void *)(DAT_00a0f824 + DAT_00a0f820);
                                                    _Dst = (void *)FUN_004ce990();
                                                    _memcpy(_Dst,_Src,_Size);
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  }
                                                  if (0x6f < DAT_00a0f84c) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 1) {
                                                      DAT_00a117e4 = 1;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 1;
                                                    _memcpy((void *)(param_1 + 0xac),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),1)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 1) {
                                                      DAT_00a117e4 = 1;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 1;
                                                    _memcpy((void *)(param_1 + 0xad),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),1)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  }
                                                  if (0x72 < DAT_00a0f84c) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    _memcpy((void *)(param_1 + 0x108),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    _memcpy((void *)(param_1 + 0x10c),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    _memcpy((void *)(param_1 + 0x110),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    _memcpy((void *)(param_1 + 0x114),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  }
                                                  if (0x77 < DAT_00a0f84c) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    _memcpy((void *)(param_1 + 0xb4),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  }
                                                  uVar1 = 1;
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
            }
          }
        }
      }
    }
  }
  return uVar1;
}

