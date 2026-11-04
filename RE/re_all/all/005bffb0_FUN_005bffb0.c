
undefined4 FUN_005bffb0(void)

{
  if (DAT_00ee9a3c < 0xa001) {
    if (DAT_00ee9a3c == 0xa000) {
      return 400;
    }
    if (((DAT_00ee9a3c == 0x9100) || (DAT_00ee9a3c == 0x9200)) || (DAT_00ee9a3c == 0x9300)) {
      return 200;
    }
  }
  else {
    if (DAT_00ee9a3c == 0xa100) {
      return 400;
    }
    if ((DAT_00ee9a3c == 0xb000) || (DAT_00ee9a3c == 0xb100)) {
      return 500;
    }
  }
  return 0;
}

