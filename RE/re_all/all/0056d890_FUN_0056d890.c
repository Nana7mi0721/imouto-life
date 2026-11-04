
void FUN_0056d890(int param_1)

{
  DAT_00aba24c = param_1;
  if (param_1 < 0x3b7) {
    if (param_1 == 0x3b6) {
      DAT_00aba248 = 3;
      goto LAB_0056d923;
    }
    if (param_1 != 0x3a4) {
      if (param_1 == 0x3a8) {
        DAT_00aba248 = 4;
        goto LAB_0056d923;
      }
      if (param_1 == 0x3b5) {
        DAT_00aba248 = 2;
        goto LAB_0056d923;
      }
      goto LAB_0056d8ec;
    }
  }
  else {
    if (param_1 == 0x4e4) {
      DAT_00aba248 = 5;
      goto LAB_0056d923;
    }
    if (param_1 == 0x7ffc) {
      DAT_00aba248 = 6;
      goto LAB_0056d923;
    }
    if (param_1 == 0xfde9) {
      DAT_00aba248 = 7;
      goto LAB_0056d923;
    }
LAB_0056d8ec:
    if (DAT_00aba248 != 0) goto LAB_0056d923;
  }
  DAT_00aba248 = 1;
LAB_0056d923:
  if (DAT_00aba250 == 0) {
    DAT_00aba250 = 0x4b0;
  }
  return;
}

