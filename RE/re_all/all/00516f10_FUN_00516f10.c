
uint FUN_00516f10(int param_1)

{
  byte bVar1;
  
  switch(*(undefined1 *)(param_1 + 8)) {
  case 1:
    return 0xc;
  case 2:
    return 0xd;
  case 3:
    return 0xe;
  case 4:
    return 0xf;
  case 5:
    return 0x10;
  case 6:
    return 0x11;
  case 7:
    return 0x12;
  case 8:
    return 0x13;
  case 9:
    return 0x14;
  }
  if (*(char *)(param_1 + 0xd) == '\x01') {
    bVar1 = *(byte *)(param_1 + 0xe);
    if (*(char *)(param_1 + 3) != '\0') {
      if (*(char *)(param_1 + 0xb) == '\0') {
        if (bVar1 == 0) {
          return 0x28 - (*(byte *)(param_1 + 0xc) < 0x10);
        }
        return 0x28 - (bVar1 < 0x10);
      }
      if (bVar1 == 0) {
        return 0x2a - (*(byte *)(param_1 + 0xc) < 0x20);
      }
      return 0x2a - (bVar1 < 0x20);
    }
    if (*(char *)(param_1 + 0xb) == '\0') {
      if (bVar1 == 0) {
        return 0x1a - (*(byte *)(param_1 + 0xc) < 0x10);
      }
      return 0x1a - (bVar1 < 0x10);
    }
    if (bVar1 == 0) {
      return 0x1c - (*(byte *)(param_1 + 0xc) < 0x20);
    }
    return 0x1c - (bVar1 < 0x20);
  }
  if (*(char *)(param_1 + 0xd) == '\x02') {
    bVar1 = *(byte *)(param_1 + 0xe);
    if (*(char *)(param_1 + 3) != '\0') {
      if (*(char *)(param_1 + 0xb) == '\0') {
        if (bVar1 == 0) {
          return 0x2c - (*(byte *)(param_1 + 0xc) < 0x20);
        }
        return 0x2c - (bVar1 < 0x10);
      }
      if (bVar1 == 0) {
        return 0x2e - (*(byte *)(param_1 + 0xc) < 0x40);
      }
      return 0x2e - (bVar1 < 0x20);
    }
    if (*(char *)(param_1 + 0xb) == '\0') {
      if (bVar1 == 0) {
        return 0x1e - (*(byte *)(param_1 + 0xc) < 0x20);
      }
      return 0x1e - (bVar1 < 0x10);
    }
    if (bVar1 == 0) {
      return 0x20 - (*(byte *)(param_1 + 0xc) < 0x40);
    }
    return 0x20 - (bVar1 < 0x20);
  }
  bVar1 = *(byte *)(param_1 + 0xc);
  if (bVar1 == 4) {
    if (*(char *)(param_1 + 2) == '\0') {
      return -(uint)(*(char *)(param_1 + 10) != '\0') & 4;
    }
    return 2;
  }
  if (bVar1 == 8) {
    if (*(char *)(param_1 + 2) == '\0') {
      return (uint)(*(char *)(param_1 + 10) != '\0') * 4 + 1;
    }
    return 3;
  }
  if (*(char *)(param_1 + 3) != '\0') {
    if (*(char *)(param_1 + 0xb) != '\0') {
      if (*(byte *)(param_1 + 0xe) == 0) {
        return 0x26 - (bVar1 < 0x80);
      }
      return 0x26 - (*(byte *)(param_1 + 0xe) < 0x20);
    }
    if (8 < *(byte *)(param_1 + 0xe)) {
      return 0x24;
    }
    if ((*(char *)(param_1 + 2) == '\x01') || (*(char *)(param_1 + 10) == '\x01')) {
      return 0x23;
    }
    return (bVar1 != 0x10) + 0x21;
  }
  if (*(char *)(param_1 + 0xb) != '\0') {
    if (*(byte *)(param_1 + 0xe) == 0) {
      return 0x18 - (bVar1 < 0x80);
    }
    return 0x18 - (*(byte *)(param_1 + 0xe) < 0x20);
  }
  if (8 < *(byte *)(param_1 + 0xe)) {
    return 0x16;
  }
  if (*(char *)(param_1 + 2) != '\0') {
    return (bVar1 != 0x10) + 8;
  }
  if (*(char *)(param_1 + 10) == '\0') {
    return (bVar1 != 0x10) + 6;
  }
  return (bVar1 != 0x10) + 10;
}

