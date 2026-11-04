
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00448934) */
/* WARNING: Removing unreachable block (ram,0x00448946) */
/* WARNING: Removing unreachable block (ram,0x00448950) */
/* WARNING: Removing unreachable block (ram,0x00448962) */
/* WARNING: Removing unreachable block (ram,0x0044896a) */
/* WARNING: Removing unreachable block (ram,0x0044897c) */
/* WARNING: Removing unreachable block (ram,0x00448984) */
/* WARNING: Removing unreachable block (ram,0x00448995) */
/* WARNING: Removing unreachable block (ram,0x00448973) */
/* WARNING: Removing unreachable block (ram,0x00448959) */
/* WARNING: Removing unreachable block (ram,0x0044893d) */

undefined4 __thiscall FUN_00448570(int param_1,char param_2)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvVar5;
  size_t sVar6;
  int local_264;
  int local_260;
  int local_25c;
  char local_258 [256];
  size_t local_158;
  int local_154;
  char local_150 [256];
  undefined4 local_50;
  size_t local_4c [5];
  undefined4 local_38;
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
  puStack_c = &LAB_007ad773;
  local_10 = ExceptionList;
  local_50 = DAT_0084b484;
  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
    DAT_00a117e4 = 1;
    uVar4 = 0;
  }
  else {
    DAT_00a0f844 = 4;
    ExceptionList = &local_10;
    _memcpy((void *)(param_1 + 0x1658),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (param_2 != '\0') {
      FUN_00449500();
    }
    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
      DAT_00a117e4 = 1;
      uVar4 = 0;
    }
    else {
      DAT_00a0f844 = 4;
      _memcpy((void *)(param_1 + 0x165c),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      if (DAT_00a0f828 < DAT_00a0f820 + 4) {
        DAT_00a117e4 = 1;
        uVar4 = 0;
      }
      else {
        DAT_00a0f844 = 4;
        _memcpy((void *)(param_1 + 0x1660),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
        if (0x68 < DAT_00a0f84c) {
          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
            DAT_00a117e4 = 1;
            ExceptionList = local_10;
            return 0;
          }
          DAT_00a0f844 = 4;
          _memcpy(&local_28,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
            DAT_00a117e4 = 1;
            ExceptionList = local_10;
            return 0;
          }
          DAT_00a0f844 = 4;
          _memcpy(&local_24,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
          *(int *)(param_1 + 0x161c) = local_28;
          *(int *)(param_1 + 0x1620) = local_24;
          FUN_004cdbe0();
          FUN_004cdbb0();
          for (local_2c = 0; local_2c < 3; local_2c = local_2c + 1) {
            FUN_004cde80();
            FUN_004cd310();
            for (local_30 = 0; local_30 < local_28; local_30 = local_30 + 1) {
              FUN_004cde80();
              FUN_004cde80();
              FUN_004ce970();
              for (local_34 = 0; local_34 < local_24; local_34 = local_34 + 1) {
                if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                  DAT_00a117e4 = 1;
                  ExceptionList = local_10;
                  return 0;
                }
                DAT_00a0f844 = 4;
                _memcpy(&local_38,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                FUN_004cde80();
                FUN_004cde80();
                puVar1 = (undefined4 *)FUN_004ce990();
                *puVar1 = local_38;
              }
            }
          }
        }
        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
          DAT_00a117e4 = 1;
          uVar4 = 0;
        }
        else {
          DAT_00a0f844 = 4;
          _memcpy(local_4c,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
          if (DAT_00a0f828 < (int)(DAT_00a0f820 + local_4c[0])) {
            DAT_00a117e4 = 1;
            uVar4 = 0;
          }
          else {
            DAT_00a0f844 = local_4c[0];
            _memcpy(local_150,(void *)(DAT_00a0f824 + DAT_00a0f820),local_4c[0]);
            DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
            std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                      ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                       (param_1 + 0x167c),local_150);
            local_14 = 7;
            if (0x72 < DAT_00a0f84c) {
              local_14 = 0xf;
            }
            for (local_154 = 0; local_154 < local_14; local_154 = local_154 + 1) {
              if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                DAT_00a117e4 = 1;
                ExceptionList = local_10;
                return 0;
              }
              DAT_00a0f844 = 4;
              _memcpy(&local_158,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
              DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
              if (DAT_00a0f828 < (int)(DAT_00a0f820 + local_158)) {
                DAT_00a117e4 = 1;
                ExceptionList = local_10;
                return 0;
              }
              DAT_00a0f844 = local_158;
              _memcpy(local_258,(void *)(DAT_00a0f824 + DAT_00a0f820),local_158);
              DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                        ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                         (param_1 + 0x1698 + local_154 * 0x1c),local_258);
            }
            if (DAT_00a0f828 < DAT_00a0f820 + 4) {
              DAT_00a117e4 = 1;
              uVar4 = 0;
            }
            else {
              DAT_00a0f844 = 4;
              _memcpy(&local_20,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
              DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
              FUN_004ce970();
              for (local_25c = 0; local_25c < local_20; local_25c = local_25c + 1) {
                if (DAT_00a0f84c < 100) {
                  if (DAT_00a0f828 < DAT_00a0f820 + 1) {
                    DAT_00a117e4 = 1;
                    ExceptionList = local_10;
                    return 0;
                  }
                  DAT_00a0f844 = 1;
                  sVar6 = 1;
                  pvVar5 = (void *)(DAT_00a0f824 + DAT_00a0f820);
                  pvVar2 = (void *)FUN_004ce990();
                  _memcpy(pvVar2,pvVar5,sVar6);
                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                }
                else if (99 < DAT_00a0f84c) {
                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                    DAT_00a117e4 = 1;
                    ExceptionList = local_10;
                    return 0;
                  }
                  DAT_00a0f844 = 4;
                  sVar6 = 4;
                  pvVar5 = (void *)(DAT_00a0f824 + DAT_00a0f820);
                  pvVar2 = (void *)FUN_004ce990();
                  _memcpy(pvVar2,pvVar5,sVar6);
                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                }
              }
              if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                DAT_00a117e4 = 1;
                uVar4 = 0;
              }
              else {
                DAT_00a0f844 = 4;
                _memcpy(&local_1c,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                iVar3 = FUN_004d29a0();
                if ((iVar3 < local_1c) && (FUN_004d28f0(), param_2 != '\0')) {
                  basic_string<>();
                  FUN_00401c50();
                  basic_string<>();
                  local_8 = 0;
                  basic_string<>();
                  FUN_00401c50();
                  basic_string<>();
                  local_8 = CONCAT31(local_8._1_3_,1);
                  basic_string<>(&DAT_007ceaa8);
                  uVar4 = FUN_00401c50();
                  basic_string<>(uVar4);
                  local_8 = 0xffffffff;
                  FUN_0042bed0();
                }
                for (local_260 = 0; local_260 < local_1c; local_260 = local_260 + 1) {
                  FUN_004d2a00();
                  FUN_00441a00();
                }
                if (0x71 < DAT_00a0f84c) {
                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                    DAT_00a117e4 = 1;
                    ExceptionList = local_10;
                    return 0;
                  }
                  DAT_00a0f844 = 4;
                  _memcpy((void *)(param_1 + 0x18ec),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                    DAT_00a117e4 = 1;
                    ExceptionList = local_10;
                    return 0;
                  }
                  DAT_00a0f844 = 4;
                  _memcpy((void *)(param_1 + 0x18f0),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                    DAT_00a117e4 = 1;
                    ExceptionList = local_10;
                    return 0;
                  }
                  DAT_00a0f844 = 4;
                  _memcpy((void *)(param_1 + 0x18f4),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                    DAT_00a117e4 = 1;
                    ExceptionList = local_10;
                    return 0;
                  }
                  DAT_00a0f844 = 4;
                  _memcpy((void *)(param_1 + 0x18f8),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                    DAT_00a117e4 = 1;
                    ExceptionList = local_10;
                    return 0;
                  }
                  DAT_00a0f844 = 4;
                  _memcpy((void *)(param_1 + 0x18fc),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                    DAT_00a117e4 = 1;
                    ExceptionList = local_10;
                    return 0;
                  }
                  DAT_00a0f844 = 4;
                  _memcpy((void *)(param_1 + 0x1900),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                    DAT_00a117e4 = 1;
                    ExceptionList = local_10;
                    return 0;
                  }
                  DAT_00a0f844 = 4;
                  _memcpy((void *)(param_1 + 0x1904),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                    DAT_00a117e4 = 1;
                    ExceptionList = local_10;
                    return 0;
                  }
                  DAT_00a0f844 = 4;
                  _memcpy((void *)(param_1 + 0x1908),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                    DAT_00a117e4 = 1;
                    ExceptionList = local_10;
                    return 0;
                  }
                  DAT_00a0f844 = 4;
                  _memcpy((void *)(param_1 + 0x190c),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                    DAT_00a117e4 = 1;
                    ExceptionList = local_10;
                    return 0;
                  }
                  DAT_00a0f844 = 4;
                  _memcpy((void *)(param_1 + 0x1910),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                    DAT_00a117e4 = 1;
                    ExceptionList = local_10;
                    return 0;
                  }
                  DAT_00a0f844 = 4;
                  _memcpy((void *)(param_1 + 0x1914),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                }
                if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                  DAT_00a117e4 = 1;
                  uVar4 = 0;
                }
                else {
                  DAT_00a0f844 = 4;
                  _memcpy(&local_18,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                  for (local_264 = 0; local_264 < local_18; local_264 = local_264 + 1) {
                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                      DAT_00a117e4 = 1;
                      ExceptionList = local_10;
                      return 0;
                    }
                    DAT_00a0f844 = 4;
                    sVar6 = 4;
                    pvVar5 = (void *)(DAT_00a0f824 + DAT_00a0f820);
                    pvVar2 = (void *)FUN_004ce990();
                    _memcpy(pvVar2,pvVar5,sVar6);
                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                  }
                  if (DAT_00a0f84c < 0x73) {
                    FUN_004d0b90();
                    FUN_004743a0();
                    FUN_004f09c0();
                  }
                  uVar4 = 1;
                }
              }
            }
          }
        }
      }
    }
  }
  ExceptionList = local_10;
  return uVar4;
}

