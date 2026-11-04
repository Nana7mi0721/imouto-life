
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00564050(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
            uint param_7,uint param_8,uint param_9,uint param_10,uint param_11,uint param_12,
            uint param_13,uint param_14,uint param_15,uint param_16,uint param_17,uint param_18,
            uint param_19,uint param_20,uint param_21,uint param_22,uint param_23,uint param_24,
            uint param_25,uint param_26,uint param_27,uint param_28,uint param_29,uint param_30,
            uint param_31,uint param_32,uint param_33,uint param_34)

{
  if ((param_1 & param_2) != 0xffffffff) {
    DAT_00aa8434 = param_1;
    DAT_00aa8474 = param_1;
  }
  if ((param_3 & param_4) != 0xffffffff) {
    DAT_00aa843c = param_3;
  }
  if ((param_5 & param_6) != 0xffffffff) {
    DAT_00aa8458 = param_5;
  }
  if ((param_7 & param_8) != 0xffffffff) {
    DAT_00aa845c = param_7;
  }
  if ((param_9 & param_10) != 0xffffffff) {
    DAT_00aa8460 = param_9;
  }
  if ((param_11 & param_12) != 0xffffffff) {
    DAT_00aa8470 = param_11;
    DAT_00aa847c = param_11;
  }
  if ((param_13 & param_14) != 0xffffffff) {
    _DAT_00aa8494 = param_13;
  }
  if ((param_15 & param_16) != 0xffffffff) {
    DAT_00aa8438 = param_15;
    DAT_00aa8478 = param_15;
  }
  if ((param_17 & param_18) != 0xffffffff) {
    DAT_00aa8480 = param_17;
  }
  if ((param_19 & param_20) != 0xffffffff) {
    _DAT_00aa8498 = param_19;
  }
  if ((param_21 & param_22) == 0xffffffff) {
    if ((param_5 & param_6) != 0xffffffff) {
      DAT_00aa848c = DAT_00aa8458;
    }
  }
  else {
    DAT_00aa848c = param_21;
  }
  if ((param_23 & param_24) == 0xffffffff) {
    param_23 = FUN_00543f70(0,0,0);
  }
  DAT_00aa8490 = param_23;
  if ((param_25 & param_26) == 0xffffffff) {
    param_25 = FUN_00543f70(0xff,0xff,0xff);
  }
  DAT_00aa8448 = param_25;
  if ((param_27 & param_28) == 0xffffffff) {
    param_27 = FUN_00543f70(0,0,0);
  }
  DAT_00aa8440 = param_27;
  if ((param_29 & param_30) == 0xffffffff) {
    param_29 = FUN_00543f70(0x80,0x80,0x80);
  }
  DAT_00aa8444 = param_29;
  if ((param_31 & param_32) != 0xffffffff) {
    DAT_00aa844c = param_31;
  }
  if ((param_33 & param_34) != 0xffffffff) {
    DAT_00aa8450 = 1;
    DAT_00aa8454 = param_33;
  }
  return 0;
}

