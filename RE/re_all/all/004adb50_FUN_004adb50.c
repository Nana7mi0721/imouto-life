
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __fastcall FUN_004adb50(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *this;
  void *_Dst;
  void *_Src;
  undefined1 auStack_142c [12];
  undefined4 uStack_1420;
  char *pcVar4;
  size_t _Size;
  undefined4 local_1404;
  undefined4 local_13ec;
  undefined4 local_13d4;
  undefined4 local_13bc;
  undefined4 local_13a4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1390 [28];
  undefined1 *local_1374;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1370 [28];
  undefined4 local_1354;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1350 [28];
  undefined1 *local_1334;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1330 [28];
  undefined4 local_1314;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1310 [28];
  undefined1 *local_12f4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_12f0 [28];
  undefined4 local_12d4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_12d0 [28];
  undefined1 *local_12b4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_12b0 [28];
  undefined4 local_1294;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1290 [28];
  undefined1 *local_1274;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1270 [28];
  undefined4 local_1254;
  undefined1 local_1250 [1028];
  short local_e4c [2];
  undefined1 local_e48 [1028];
  short local_a44 [2];
  char local_a40 [1028];
  short local_63c [2];
  char local_638 [1028];
  short local_234 [2];
  int local_230;
  int local_22c;
  size_t local_228;
  int local_224;
  char local_220 [512];
  undefined4 local_20;
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b01e3;
  local_10 = ExceptionList;
  local_14 = 0x4adb72;
  local_20 = DAT_0084b484;
  if (DAT_00a0f828 < DAT_00a0f820 + 1) {
    DAT_00a117e4 = 1;
    uVar2 = 0;
  }
  else {
    DAT_00a0f844 = 1;
    uStack_1420 = 0x4adbd7;
    ExceptionList = &local_10;
    _memcpy((void *)(param_1 + 0x8ac),(void *)(DAT_00a0f824 + DAT_00a0f820),1);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a0f828 < DAT_00a0f820 + 1) {
      DAT_00a117e4 = 1;
      uVar2 = 0;
    }
    else {
      DAT_00a0f844 = 1;
      uStack_1420 = 0x4adc3a;
      _memcpy((void *)(param_1 + 0x8ad),(void *)(DAT_00a0f824 + DAT_00a0f820),1);
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      if (DAT_00a0f828 < DAT_00a0f820 + 4) {
        DAT_00a117e4 = 1;
        uVar2 = 0;
      }
      else {
        DAT_00a0f844 = 4;
        uStack_1420 = 0x4adc9b;
        _memcpy((void *)(param_1 + 0x8b0),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
          DAT_00a117e4 = 1;
          uVar2 = 0;
        }
        else {
          DAT_00a0f844 = 4;
          uStack_1420 = 0x4adcfd;
          _memcpy((void *)(param_1 + 0x8b4),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
            DAT_00a117e4 = 1;
            uVar2 = 0;
          }
          else {
            DAT_00a0f844 = 4;
            uStack_1420 = 0x4add60;
            _memcpy((void *)(param_1 + 0x8bc),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
            DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
            if (DAT_00a0f828 < DAT_00a0f820 + 4) {
              DAT_00a117e4 = 1;
              uVar2 = 0;
            }
            else {
              DAT_00a0f844 = 4;
              uStack_1420 = 0x4addc1;
              _memcpy((void *)(param_1 + 0x8c0),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
              DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
              if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                DAT_00a117e4 = 1;
                uVar2 = 0;
              }
              else {
                DAT_00a0f844 = 4;
                uStack_1420 = 0x4ade1b;
                _memcpy(&local_14,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                  DAT_00a117e4 = 1;
                  uVar2 = 0;
                }
                else {
                  DAT_00a0f844 = 4;
                  uStack_1420 = 0x4ade75;
                  _memcpy(local_18,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                    DAT_00a117e4 = 1;
                    uVar2 = 0;
                  }
                  else {
                    DAT_00a0f844 = 4;
                    uStack_1420 = 0x4aded6;
                    _memcpy((void *)(param_1 + 0x8cc),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                      DAT_00a117e4 = 1;
                      uVar2 = 0;
                    }
                    else {
                      DAT_00a0f844 = 4;
                      uStack_1420 = 0x4adf38;
                      _memcpy((void *)(param_1 + 0x8d0),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                      if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                        DAT_00a117e4 = 1;
                        uVar2 = 0;
                      }
                      else {
                        DAT_00a0f844 = 4;
                        uStack_1420 = 0x4adf9b;
                        _memcpy((void *)(param_1 + 0x8d4),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                          DAT_00a117e4 = 1;
                          uVar2 = 0;
                        }
                        else {
                          DAT_00a0f844 = 4;
                          uStack_1420 = 0x4adffc;
                          _memcpy((void *)(param_1 + 0x8d8),(void *)(DAT_00a0f824 + DAT_00a0f820),4)
                          ;
                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                            DAT_00a117e4 = 1;
                            uVar2 = 0;
                          }
                          else {
                            DAT_00a0f844 = 4;
                            uStack_1420 = 0x4ae05e;
                            _memcpy((void *)(param_1 + 0x8dc),(void *)(DAT_00a0f824 + DAT_00a0f820),
                                    4);
                            DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                            if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                              DAT_00a117e4 = 1;
                              uVar2 = 0;
                            }
                            else {
                              DAT_00a0f844 = 4;
                              uStack_1420 = 0x4ae0c1;
                              _memcpy((void *)(param_1 + 0x8e0),
                                      (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                              DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                              if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                DAT_00a117e4 = 1;
                                uVar2 = 0;
                              }
                              else {
                                DAT_00a0f844 = 4;
                                uStack_1420 = 0x4ae122;
                                _memcpy((void *)(param_1 + 0x8e4),
                                        (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                  DAT_00a117e4 = 1;
                                  uVar2 = 0;
                                }
                                else {
                                  DAT_00a0f844 = 4;
                                  uStack_1420 = 0x4ae184;
                                  _memcpy((void *)(param_1 + 0x8e8),
                                          (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                    DAT_00a117e4 = 1;
                                    uVar2 = 0;
                                  }
                                  else {
                                    DAT_00a0f844 = 4;
                                    uStack_1420 = 0x4ae1e7;
                                    _memcpy((void *)(param_1 + 0x8ec),
                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                    if (DAT_00a0f828 < DAT_00a0f820 + 0x12) {
                                      DAT_00a117e4 = 1;
                                      uVar2 = 0;
                                    }
                                    else {
                                      DAT_00a0f844 = 0x12;
                                      uStack_1420 = 0x4ae248;
                                      _memcpy((void *)(param_1 + 0x8f0),
                                              (void *)(DAT_00a0f824 + DAT_00a0f820),0x12);
                                      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                      if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                        DAT_00a117e4 = 1;
                                        uVar2 = 0;
                                      }
                                      else {
                                        DAT_00a0f844 = 2;
                                        uStack_1420 = 0x4ae2aa;
                                        _memcpy((void *)(param_1 + 0x902),
                                                (void *)(DAT_00a0f824 + DAT_00a0f820),2);
                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                        if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                          DAT_00a117e4 = 1;
                                          uVar2 = 0;
                                        }
                                        else {
                                          DAT_00a0f844 = 2;
                                          uStack_1420 = 0x4ae30d;
                                          _memcpy((void *)(param_1 + 0x904),
                                                  (void *)(DAT_00a0f824 + DAT_00a0f820),2);
                                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                          if (DAT_00a0f828 < DAT_00a0f820 + 6) {
                                            DAT_00a117e4 = 1;
                                            uVar2 = 0;
                                          }
                                          else {
                                            DAT_00a0f844 = 6;
                                            uStack_1420 = 0x4ae36e;
                                            _memcpy((void *)(param_1 + 0x906),
                                                    (void *)(DAT_00a0f824 + DAT_00a0f820),6);
                                            DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                            if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                              DAT_00a117e4 = 1;
                                              uVar2 = 0;
                                            }
                                            else {
                                              DAT_00a0f844 = 2;
                                              uStack_1420 = 0x4ae3d0;
                                              _memcpy((void *)(param_1 + 0x90c),
                                                      (void *)(DAT_00a0f824 + DAT_00a0f820),2);
                                              DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                              if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                                DAT_00a117e4 = 1;
                                                uVar2 = 0;
                                              }
                                              else {
                                                DAT_00a0f844 = 2;
                                                uStack_1420 = 0x4ae433;
                                                _memcpy((void *)(param_1 + 0x90e),
                                                        (void *)(DAT_00a0f824 + DAT_00a0f820),2);
                                                DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                  DAT_00a117e4 = 1;
                                                  uVar2 = 0;
                                                }
                                                else {
                                                  DAT_00a0f844 = 4;
                                                  uStack_1420 = 0x4ae494;
                                                  _memcpy((void *)(param_1 + 0x918),
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                    DAT_00a117e4 = 1;
                                                    uVar2 = 0;
                                                  }
                                                  else {
                                                    DAT_00a0f844 = 4;
                                                    uStack_1420 = 0x4ae4f6;
                                                    _memcpy((void *)(param_1 + 0x91c),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      uVar2 = 0;
                                                    }
                                                    else {
                                                      DAT_00a0f844 = 4;
                                                      uStack_1420 = 0x4ae559;
                                                      _memcpy((void *)(param_1 + 0x920),
                                                              (void *)(DAT_00a0f824 + DAT_00a0f820),
                                                              4);
                                                      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                      if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                        DAT_00a117e4 = 1;
                                                        uVar2 = 0;
                                                      }
                                                      else {
                                                        DAT_00a0f844 = 4;
                                                        uStack_1420 = 0x4ae5ba;
                                                        _memcpy((void *)(param_1 + 0x924),
                                                                (void *)(DAT_00a0f824 + DAT_00a0f820
                                                                        ),4);
                                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                          DAT_00a117e4 = 1;
                                                          uVar2 = 0;
                                                        }
                                                        else {
                                                          DAT_00a0f844 = 4;
                                                          uStack_1420 = 0x4ae61c;
                                                          _memcpy((void *)(param_1 + 0x928),
                                                                  (void *)(DAT_00a0f824 +
                                                                          DAT_00a0f820),4);
                                                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844
                                                          ;
                                                          if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                            DAT_00a117e4 = 1;
                                                            uVar2 = 0;
                                                          }
                                                          else {
                                                            DAT_00a0f844 = 4;
                                                            uStack_1420 = 0x4ae67f;
                                                            _memcpy((void *)(param_1 + 0x92c),
                                                                    (void *)(DAT_00a0f824 +
                                                                            DAT_00a0f820),4);
                                                            DAT_00a0f820 = DAT_00a0f820 +
                                                                           DAT_00a0f844;
                                                            if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                              DAT_00a117e4 = 1;
                                                              uVar2 = 0;
                                                            }
                                                            else {
                                                              DAT_00a0f844 = 4;
                                                              uStack_1420 = 0x4ae6e0;
                                                              _memcpy((void *)(param_1 + 0x930),
                                                                      (void *)(DAT_00a0f824 +
                                                                              DAT_00a0f820),4);
                                                              DAT_00a0f820 = DAT_00a0f820 +
                                                                             DAT_00a0f844;
                                                              if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                                DAT_00a117e4 = 1;
                                                                uVar2 = 0;
                                                              }
                                                              else {
                                                                DAT_00a0f844 = 4;
                                                                uStack_1420 = 0x4ae742;
                                                                _memcpy((void *)(param_1 + 0x934),
                                                                        (void *)(DAT_00a0f824 +
                                                                                DAT_00a0f820),4);
                                                                DAT_00a0f820 = DAT_00a0f820 +
                                                                               DAT_00a0f844;
                                                                if (DAT_00a0f828 < DAT_00a0f820 + 4)
                                                                {
                                                                  DAT_00a117e4 = 1;
                                                                  uVar2 = 0;
                                                                }
                                                                else {
                                                                  DAT_00a0f844 = 4;
                                                                  uStack_1420 = 0x4ae7a5;
                                                                  _memcpy((void *)(param_1 + 0x938),
                                                                          (void *)(DAT_00a0f824 +
                                                                                  DAT_00a0f820),4);
                                                                  DAT_00a0f820 = DAT_00a0f820 +
                                                                                 DAT_00a0f844;
                                                                  if (DAT_00a0f828 <
                                                                      DAT_00a0f820 + 1) {
                                                                    DAT_00a117e4 = 1;
                                                                    uVar2 = 0;
                                                                  }
                                                                  else {
                                                                    DAT_00a0f844 = 1;
                                                                    uStack_1420 = 0x4ae806;
                                                                    _memcpy((void *)(param_1 + 0x94c
                                                                                    ),
                                                                            (void *)(DAT_00a0f824 +
                                                                                    DAT_00a0f820),1)
                                                                    ;
                                                                    DAT_00a0f820 = DAT_00a0f820 +
                                                                                   DAT_00a0f844;
                                                                    if (DAT_00a0f828 <
                                                                        DAT_00a0f820 + 2) {
                                                                      DAT_00a117e4 = 1;
                                                                      uVar2 = 0;
                                                                    }
                                                                    else {
                                                                      DAT_00a0f844 = 2;
                                                                      uStack_1420 = 0x4ae868;
                                                                      _memcpy((void *)(param_1 +
                                                                                      0x93c),
                                                                              (void *)(DAT_00a0f824
                                                                                      + DAT_00a0f820
                                                                                      ),2);
                                                                      DAT_00a0f820 = DAT_00a0f820 +
                                                                                     DAT_00a0f844;
                                                                      if (DAT_00a0f828 <
                                                                          DAT_00a0f820 + 4) {
                                                                        DAT_00a117e4 = 1;
                                                                        uVar2 = 0;
                                                                      }
                                                                      else {
                                                                        DAT_00a0f844 = 4;
                                                                        uStack_1420 = 0x4ae8cb;
                                                                        _memcpy((void *)(param_1 +
                                                                                        0x940),
                                                                                (void *)(
                                                  DAT_00a0f824 + DAT_00a0f820),4);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                    DAT_00a117e4 = 1;
                                                    uVar2 = 0;
                                                  }
                                                  else {
                                                    DAT_00a0f844 = 4;
                                                    uStack_1420 = 0x4ae92c;
                                                    _memcpy((void *)(param_1 + 0x944),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                                      DAT_00a117e4 = 1;
                                                      uVar2 = 0;
                                                    }
                                                    else {
                                                      DAT_00a0f844 = 2;
                                                      uStack_1420 = 0x4ae98e;
                                                      _memcpy((void *)(param_1 + 0x94e),
                                                              (void *)(DAT_00a0f824 + DAT_00a0f820),
                                                              2);
                                                      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                      if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                                        DAT_00a117e4 = 1;
                                                        uVar2 = 0;
                                                      }
                                                      else {
                                                        DAT_00a0f844 = 2;
                                                        uStack_1420 = 0x4ae9f1;
                                                        _memcpy((void *)(param_1 + 0x950),
                                                                (void *)(DAT_00a0f824 + DAT_00a0f820
                                                                        ),2);
                                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                        if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                                          DAT_00a117e4 = 1;
                                                          uVar2 = 0;
                                                        }
                                                        else {
                                                          DAT_00a0f844 = 2;
                                                          uStack_1420 = 0x4aea52;
                                                          _memcpy((void *)(param_1 + 0x95c),
                                                                  (void *)(DAT_00a0f824 +
                                                                          DAT_00a0f820),2);
                                                          DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844
                                                          ;
                                                          if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                                            DAT_00a117e4 = 1;
                                                            uVar2 = 0;
                                                          }
                                                          else {
                                                            DAT_00a0f844 = 2;
                                                            uStack_1420 = 0x4aeab4;
                                                            _memcpy((void *)(param_1 + 0x95e),
                                                                    (void *)(DAT_00a0f824 +
                                                                            DAT_00a0f820),2);
                                                            DAT_00a0f820 = DAT_00a0f820 +
                                                                           DAT_00a0f844;
                                                            if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                              DAT_00a117e4 = 1;
                                                              uVar2 = 0;
                                                            }
                                                            else {
                                                              DAT_00a0f844 = 4;
                                                              uStack_1420 = 0x4aeb17;
                                                              _memcpy((void *)(param_1 + 0x960),
                                                                      (void *)(DAT_00a0f824 +
                                                                              DAT_00a0f820),4);
                                                              DAT_00a0f820 = DAT_00a0f820 +
                                                                             DAT_00a0f844;
                                                              if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                                DAT_00a117e4 = 1;
                                                                uVar2 = 0;
                                                              }
                                                              else {
                                                                DAT_00a0f844 = 4;
                                                                uStack_1420 = 0x4aeb78;
                                                                _memcpy((void *)(param_1 + 0x964),
                                                                        (void *)(DAT_00a0f824 +
                                                                                DAT_00a0f820),4);
                                                                DAT_00a0f820 = DAT_00a0f820 +
                                                                               DAT_00a0f844;
                                                                if (DAT_00a0f828 < DAT_00a0f820 + 4)
                                                                {
                                                                  DAT_00a117e4 = 1;
                                                                  uVar2 = 0;
                                                                }
                                                                else {
                                                                  DAT_00a0f844 = 4;
                                                                  uStack_1420 = 0x4aebda;
                                                                  _memcpy((void *)(param_1 + 0x968),
                                                                          (void *)(DAT_00a0f824 +
                                                                                  DAT_00a0f820),4);
                                                                  DAT_00a0f820 = DAT_00a0f820 +
                                                                                 DAT_00a0f844;
                                                                  if (DAT_00a0f828 <
                                                                      DAT_00a0f820 + 1) {
                                                                    DAT_00a117e4 = 1;
                                                                    uVar2 = 0;
                                                                  }
                                                                  else {
                                                                    DAT_00a0f844 = 1;
                                                                    uStack_1420 = 0x4aec3d;
                                                                    _memcpy((void *)(param_1 + 0x96c
                                                                                    ),
                                                                            (void *)(DAT_00a0f824 +
                                                                                    DAT_00a0f820),1)
                                                                    ;
                                                                    DAT_00a0f820 = DAT_00a0f820 +
                                                                                   DAT_00a0f844;
                                                                    if (DAT_00a0f84c < 0x61) {
                                                                      if (DAT_00a0f828 <
                                                                          DAT_00a0f820 + 4) {
                                                                        DAT_00a117e4 = 1;
                                                                        ExceptionList = local_10;
                                                                        return 0;
                                                                      }
                                                                      DAT_00a0f844 = 4;
                                                                      uStack_1420 = 0x4aeca1;
                                                                      _memcpy(local_1c,(void *)(
                                                  DAT_00a0f824 + DAT_00a0f820),4);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  }
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                    DAT_00a117e4 = 1;
                                                    uVar2 = 0;
                                                  }
                                                  else {
                                                    DAT_00a0f844 = 4;
                                                    uStack_1420 = 0x4aed02;
                                                    _memcpy((void *)(param_1 + 0x970),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if (0x61 < DAT_00a0f84c) {
                                                      if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                        DAT_00a117e4 = 1;
                                                        ExceptionList = local_10;
                                                        return 0;
                                                      }
                                                      DAT_00a0f844 = 4;
                                                      uStack_1420 = 0x4aed75;
                                                      _memcpy((void *)(param_1 + 0x974),
                                                              (void *)(DAT_00a0f824 + DAT_00a0f820),
                                                              4);
                                                      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                      if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                        DAT_00a117e4 = 1;
                                                        ExceptionList = local_10;
                                                        return 0;
                                                      }
                                                      DAT_00a0f844 = 4;
                                                      uStack_1420 = 0x4aedd7;
                                                      _memcpy((void *)(param_1 + 0x978),
                                                              (void *)(DAT_00a0f824 + DAT_00a0f820),
                                                              4);
                                                      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    }
                                                    if (99 < DAT_00a0f84c) {
                                                      if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                        DAT_00a117e4 = 1;
                                                        ExceptionList = local_10;
                                                        return 0;
                                                      }
                                                      DAT_00a0f844 = 4;
                                                      uStack_1420 = 0x4aee49;
                                                      _memcpy((void *)(param_1 + 0x97c),
                                                              (void *)(DAT_00a0f824 + DAT_00a0f820),
                                                              4);
                                                      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                      if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                        DAT_00a117e4 = 1;
                                                        ExceptionList = local_10;
                                                        return 0;
                                                      }
                                                      DAT_00a0f844 = 4;
                                                      uStack_1420 = 0x4aeeac;
                                                      _memcpy((void *)(param_1 + 0x980),
                                                              (void *)(DAT_00a0f824 + DAT_00a0f820),
                                                              4);
                                                      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                      if (DAT_00a0f828 < DAT_00a0f820 + 1) {
                                                        DAT_00a117e4 = 1;
                                                        ExceptionList = local_10;
                                                        return 0;
                                                      }
                                                      DAT_00a0f844 = 1;
                                                      uStack_1420 = 0x4aef0d;
                                                      _memcpy((void *)(param_1 + 0x984),
                                                              (void *)(DAT_00a0f824 + DAT_00a0f820),
                                                              1);
                                                      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                      if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                        DAT_00a117e4 = 1;
                                                        ExceptionList = local_10;
                                                        return 0;
                                                      }
                                                      DAT_00a0f844 = 4;
                                                      uStack_1420 = 0x4aef6a;
                                                      _memcpy(&local_224,
                                                              (void *)(DAT_00a0f824 + DAT_00a0f820),
                                                              4);
                                                      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                      iVar3 = FUN_004cc430();
                                                      if (iVar3 < local_224) {
                                                        FUN_004cc400();
                                                      }
                                                      for (local_22c = 0; local_22c < local_224;
                                                          local_22c = local_22c + 1) {
                                                        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                          DAT_00a117e4 = 1;
                                                          ExceptionList = local_10;
                                                          return 0;
                                                        }
                                                        DAT_00a0f844 = 4;
                                                        uStack_1420 = 0x4af025;
                                                        _memcpy(&local_228,
                                                                (void *)(DAT_00a0f824 + DAT_00a0f820
                                                                        ),4);
                                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                        if (DAT_00a0f828 <
                                                            (int)(DAT_00a0f820 + local_228)) {
                                                          DAT_00a117e4 = 1;
                                                          ExceptionList = local_10;
                                                          return 0;
                                                        }
                                                        DAT_00a0f844 = local_228;
                                                        uStack_1420 = 0x4af085;
                                                        _memcpy(local_220,
                                                                (void *)(DAT_00a0f824 + DAT_00a0f820
                                                                        ),local_228);
                                                        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                        pcVar4 = local_220;
                                                        this = (
                                                  basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                                  *)FUN_004cc4c0();
                                                  std::
                                                  basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                                  ::operator=(this,pcVar4);
                                                  }
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = 4;
                                                  uStack_1420 = 0x4af10b;
                                                  _memcpy(&local_224,
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  iVar3 = FUN_004ce080();
                                                  if (iVar3 < local_224) {
                                                    FUN_004ce970();
                                                  }
                                                  for (local_230 = 0; local_230 < local_224;
                                                      local_230 = local_230 + 1) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    _Size = 4;
                                                    _Src = (void *)(DAT_00a0f824 + DAT_00a0f820);
                                                    uStack_1420 = 0x4af1ce;
                                                    _Dst = (void *)FUN_004ce990();
                                                    uStack_1420 = 0x4af1d4;
                                                    _memcpy(_Dst,_Src,_Size);
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  }
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = 4;
                                                  uStack_1420 = 0x4af23a;
                                                  _memcpy((void *)(param_1 + 0x9a8),
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = 4;
                                                  uStack_1420 = 0x4af29c;
                                                  _memcpy((void *)(param_1 + 0x9ac),
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = 4;
                                                  uStack_1420 = 0x4af2ff;
                                                  _memcpy((void *)(param_1 + 0x9b0),
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = 4;
                                                  uStack_1420 = 0x4af360;
                                                  _memcpy((void *)(param_1 + 0x9b4),
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = 4;
                                                  uStack_1420 = 0x4af3c2;
                                                  _memcpy((void *)(param_1 + 0x9b8),
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  }
                                                  if (100 < DAT_00a0f84c) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    uStack_1420 = 0x4af434;
                                                    _memcpy((void *)(param_1 + 0x9bc),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    uStack_1420 = 0x4af497;
                                                    _memcpy((void *)(param_1 + 0x9c8),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    uStack_1420 = 0x4af4f8;
                                                    _memcpy((void *)(param_1 + 0x9c0),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    uStack_1420 = 0x4af55a;
                                                    _memcpy((void *)(param_1 + 0x9cc),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    uStack_1420 = 0x4af5bd;
                                                    _memcpy((void *)(param_1 + 0x9c4),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    uStack_1420 = 0x4af61e;
                                                    _memcpy((void *)(param_1 + 0x9d0),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  }
                                                  if (0x65 < DAT_00a0f84c) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 2;
                                                    uStack_1420 = 0x4af68d;
                                                    _memcpy((void *)(param_1 + 0x954),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),2)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  }
                                                  if (0x66 < DAT_00a0f84c) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 2;
                                                    uStack_1420 = 0x4af6fa;
                                                    _memcpy(local_234,
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),2)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if (DAT_00a0f828 < local_234[0] + DAT_00a0f820)
                                                    {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = (size_t)local_234[0];
                                                    uStack_1420 = 0x4af75e;
                                                    _memcpy(local_638,
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),
                                                            DAT_00a0f844);
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    std::
                                                  basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                                  ::operator=((
                                                  basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                                  *)(param_1 + 0x9d8),local_638);
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = 2;
                                                  uStack_1420 = 0x4af7d3;
                                                  _memcpy(local_234,
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),2);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  if (DAT_00a0f828 < local_234[0] + DAT_00a0f820) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = (size_t)local_234[0];
                                                  uStack_1420 = 0x4af837;
                                                  _memcpy(local_638,
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),
                                                          DAT_00a0f844);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  std::
                                                  basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                                  ::operator=((
                                                  basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                                  *)(param_1 + 0x9f4),local_638);
                                                  }
                                                  if (0x67 < DAT_00a0f84c) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    uStack_1420 = 0x4af8be;
                                                    _memcpy((void *)(param_1 + 0x9d4),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  }
                                                  if (0x69 < DAT_00a0f84c) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    uStack_1420 = 0x4af92f;
                                                    _memcpy((void *)(param_1 + 0xa10),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    uStack_1420 = 0x4af990;
                                                    _memcpy((void *)(param_1 + 0xa14),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    uStack_1420 = 0x4af9f2;
                                                    _memcpy((void *)(param_1 + 0xa18),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  }
                                                  if (0x6b < DAT_00a0f84c) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 2;
                                                    uStack_1420 = 0x4afa5f;
                                                    _memcpy(local_63c,
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),2)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if (DAT_00a0f828 < local_63c[0] + DAT_00a0f820)
                                                    {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = (size_t)local_63c[0];
                                                    uStack_1420 = 0x4afac3;
                                                    _memcpy(local_a40,
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),
                                                            DAT_00a0f844);
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    std::
                                                  basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                                  ::operator=((
                                                  basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                                  *)(param_1 + 0xa1c),local_a40);
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = 4;
                                                  uStack_1420 = 0x4afb3d;
                                                  _memcpy((void *)(param_1 + 0xa54),
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = 4;
                                                  uStack_1420 = 0x4afba0;
                                                  _memcpy((void *)(param_1 + 0xa58),
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = 4;
                                                  uStack_1420 = 0x4afc01;
                                                  _memcpy((void *)(param_1 + 0xa5c),
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = 2;
                                                  uStack_1420 = 0x4afc5e;
                                                  _memcpy(local_63c,
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),2);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  if (DAT_00a0f828 < local_63c[0] + DAT_00a0f820) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = (size_t)local_63c[0];
                                                  uStack_1420 = 0x4afcc2;
                                                  _memcpy(local_a40,
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),
                                                          DAT_00a0f844);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  std::
                                                  basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                                  ::operator=((
                                                  basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                                  *)(param_1 + 0xa38),local_a40);
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = 4;
                                                  uStack_1420 = 0x4afd3c;
                                                  _memcpy((void *)(param_1 + 0xa60),
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = 4;
                                                  uStack_1420 = 0x4afd9f;
                                                  _memcpy((void *)(param_1 + 0xa64),
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = 4;
                                                  uStack_1420 = 0x4afe00;
                                                  _memcpy((void *)(param_1 + 0xa68),
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),4);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  }
                                                  if (0x6c < DAT_00a0f84c) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 2;
                                                    uStack_1420 = 0x4afe6d;
                                                    _memcpy(local_a44,
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),2)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if (DAT_00a0f828 < local_a44[0] + DAT_00a0f820)
                                                    {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = (size_t)local_a44[0];
                                                    uStack_1420 = 0x4afed1;
                                                    _memcpy(local_e48,
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),
                                                            DAT_00a0f844);
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    bVar1 = DAT_00a0f84c < 0x7d;
                                                    if (bVar1) {
                                                      local_1274 = auStack_142c;
                                                      basic_string<>(local_e48);
                                                      local_13a4 = FUN_00429250(local_1290);
                                                    }
                                                    else {
                                                      local_13a4 = basic_string<>();
                                                    }
                                                    local_8 = (uint)bVar1;
                                                    local_1254 = local_13a4;
                                                    FUN_004cb840();
                                                    local_8 = 0;
                                                    if (bVar1) {
                                                      std::
                                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                  ::
                                                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                            (local_1290);
                                                  }
                                                  local_8 = 0xffffffff;
                                                  if (!bVar1) {
                                                    std::
                                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                  ::
                                                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                            (local_1270);
                                                  }
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = 2;
                                                  uStack_1420 = 0x4b004e;
                                                  _memcpy(local_a44,
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),2);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  if (DAT_00a0f828 < local_a44[0] + DAT_00a0f820) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = (size_t)local_a44[0];
                                                  uStack_1420 = 0x4b00b0;
                                                  _memcpy(local_e48,
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),
                                                          DAT_00a0f844);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  bVar1 = DAT_00a0f84c < 0x7d;
                                                  if (bVar1) {
                                                    local_12b4 = auStack_142c;
                                                    basic_string<>(local_e48);
                                                    local_13bc = FUN_00429250(local_12d0);
                                                    local_8 = 3;
                                                  }
                                                  else {
                                                    local_13bc = basic_string<>();
                                                    local_8 = 2;
                                                  }
                                                  local_1294 = local_13bc;
                                                  FUN_004cb840();
                                                  local_8 = 2;
                                                  if (bVar1) {
                                                    std::
                                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                  ::
                                                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                            (local_12d0);
                                                  }
                                                  local_8 = 0xffffffff;
                                                  if (!bVar1) {
                                                    std::
                                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                  ::
                                                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                            (local_12b0);
                                                  }
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 1) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = 1;
                                                  uStack_1420 = 0x4b0230;
                                                  _memcpy((void *)(param_1 + 0xaf8),
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),1);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  FUN_0050f160();
                                                  }
                                                  if (0x6d < DAT_00a0f84c) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 1) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 1;
                                                    uStack_1420 = 0x4b02b5;
                                                    _memcpy((void *)(param_1 + 0xaf9),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),1)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  }
                                                  if (0x76 < DAT_00a0f84c) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 2;
                                                    uStack_1420 = 0x4b0320;
                                                    _memcpy(local_e4c,
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),2)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if (DAT_00a0f828 < local_e4c[0] + DAT_00a0f820)
                                                    {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = (size_t)local_e4c[0];
                                                    uStack_1420 = 0x4b0382;
                                                    _memcpy(local_1250,
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),
                                                            DAT_00a0f844);
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    bVar1 = DAT_00a0f84c < 0x7d;
                                                    if (bVar1) {
                                                      local_12f4 = auStack_142c;
                                                      basic_string<>(local_1250);
                                                      local_13d4 = FUN_00429250(local_1310);
                                                      local_8 = 5;
                                                    }
                                                    else {
                                                      local_13d4 = basic_string<>();
                                                      local_8 = 4;
                                                    }
                                                    local_12d4 = local_13d4;
                                                    FUN_004cb840();
                                                    local_8 = 4;
                                                    if (bVar1) {
                                                      std::
                                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                  ::
                                                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                            (local_1310);
                                                  }
                                                  local_8 = 0xffffffff;
                                                  if (!bVar1) {
                                                    std::
                                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                  ::
                                                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                            (local_12f0);
                                                  }
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = 2;
                                                  uStack_1420 = 0x4b04fd;
                                                  _memcpy(local_e4c,
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),2);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  if (DAT_00a0f828 < local_e4c[0] + DAT_00a0f820) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = (size_t)local_e4c[0];
                                                  uStack_1420 = 0x4b0561;
                                                  _memcpy(local_1250,
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),
                                                          DAT_00a0f844);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  bVar1 = DAT_00a0f84c < 0x7d;
                                                  if (bVar1) {
                                                    local_1334 = auStack_142c;
                                                    basic_string<>(local_1250);
                                                    local_13ec = FUN_00429250(local_1350);
                                                    local_8 = 7;
                                                  }
                                                  else {
                                                    local_13ec = basic_string<>();
                                                    local_8 = 6;
                                                  }
                                                  local_1314 = local_13ec;
                                                  FUN_004cb840();
                                                  local_8 = 6;
                                                  if (bVar1) {
                                                    std::
                                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                  ::
                                                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                            (local_1350);
                                                  }
                                                  local_8 = 0xffffffff;
                                                  if (!bVar1) {
                                                    std::
                                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                  ::
                                                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                            (local_1330);
                                                  }
                                                  if (DAT_00a0f828 < DAT_00a0f820 + 2) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = 2;
                                                  uStack_1420 = 0x4b06e6;
                                                  _memcpy(local_e4c,
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),2);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  if (DAT_00a0f828 < local_e4c[0] + DAT_00a0f820) {
                                                    DAT_00a117e4 = 1;
                                                    ExceptionList = local_10;
                                                    return 0;
                                                  }
                                                  DAT_00a0f844 = (size_t)local_e4c[0];
                                                  uStack_1420 = 0x4b0748;
                                                  _memcpy(local_1250,
                                                          (void *)(DAT_00a0f824 + DAT_00a0f820),
                                                          DAT_00a0f844);
                                                  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  bVar1 = DAT_00a0f84c < 0x7d;
                                                  if (bVar1) {
                                                    local_1374 = auStack_142c;
                                                    basic_string<>(local_1250);
                                                    local_1404 = FUN_00429250(local_1390);
                                                    local_8 = 9;
                                                  }
                                                  else {
                                                    local_1404 = basic_string<>();
                                                    local_8 = 8;
                                                  }
                                                  local_1354 = local_1404;
                                                  FUN_004cb840();
                                                  local_8 = 8;
                                                  if (bVar1) {
                                                    std::
                                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                  ::
                                                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                            (local_1390);
                                                  }
                                                  local_8 = 0xffffffff;
                                                  if (!bVar1) {
                                                    std::
                                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                  ::
                                                  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                                            (local_1370);
                                                  }
                                                  }
                                                  if (0x78 < DAT_00a0f84c) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    uStack_1420 = 0x4b08ea;
                                                    _memcpy((void *)(param_1 + 0xafc),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if ((*DAT_00a16628 < 15000) ||
                                                       (0x3c8b < *DAT_00a16628)) {
                                                      *(undefined4 *)(param_1 + 0xafc) = 0;
                                                    }
                                                  }
                                                  if (0x79 < DAT_00a0f84c) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    uStack_1420 = 0x4b0988;
                                                    _memcpy((void *)(param_1 + 0xb00),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  }
                                                  if (0x7b < DAT_00a0f84c) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    uStack_1420 = 0x4b09fa;
                                                    _memcpy((void *)(param_1 + 0xb04),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                    if ((*DAT_00a16628 < 15000) ||
                                                       (0x3c8b < *DAT_00a16628)) {
                                                      *(undefined4 *)(param_1 + 0xb04) = 0;
                                                    }
                                                  }
                                                  if (0x7d < DAT_00a0f84c) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    uStack_1420 = 0x4b0a9a;
                                                    _memcpy((void *)(param_1 + 0xb08),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  }
                                                  if (0x7f < DAT_00a0f84c) {
                                                    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
                                                      DAT_00a117e4 = 1;
                                                      ExceptionList = local_10;
                                                      return 0;
                                                    }
                                                    DAT_00a0f844 = 4;
                                                    uStack_1420 = 0x4b0b07;
                                                    _memcpy((void *)(param_1 + 0xb0c),
                                                            (void *)(DAT_00a0f824 + DAT_00a0f820),4)
                                                    ;
                                                    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
                                                  }
                                                  uVar2 = 1;
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
  ExceptionList = local_10;
  return uVar2;
}

