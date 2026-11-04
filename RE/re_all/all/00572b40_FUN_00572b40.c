
int FUN_00572b40(byte *param_1,int param_2)

{
  byte bVar1;
  
  if (param_2 < 0x4b2) {
    if (param_2 == 0x4b1) {
      return (uint)((*param_1 & 0xfc) == 0xd8) * 2 + 2;
    }
    if (param_2 < 0x3b7) {
      if (param_2 < 0x3b5) {
        if (param_2 == 0x3a4) {
          return ((byte)((*param_1 ^ 0x20) + 0x5f) < 0x3c) + 1;
        }
        if (param_2 != 0x3a8) {
          return -1;
        }
      }
      return ((*param_1 & 0x80) != 0) + 1;
    }
    if (param_2 == 0x4b0) {
      return (uint)((param_1[1] & 0xfc) == 0xd8) * 2 + 2;
    }
  }
  else if (param_2 < 0x8000) {
    if (0x7ffd < param_2) {
      return 4;
    }
    if ((param_2 == 0x4e4) || ((0x7ffb < param_2 && (param_2 < 0x7ffe)))) {
      return 1;
    }
  }
  else if (param_2 == 0xfde9) {
    bVar1 = *param_1;
    if (-1 < (char)bVar1) {
      return 1;
    }
    if ((bVar1 & 0xe0) == 0xc0) {
      return 2;
    }
    if ((bVar1 & 0xf0) == 0xe0) {
      return 3;
    }
    if ((bVar1 & 0xf8) == 0xf0) {
      return 4;
    }
    if ((bVar1 & 0xfc) == 0xf8) {
      return 5;
    }
    if ((bVar1 & 0xfe) == 0xfc) {
      return 6;
    }
  }
  return -1;
}

