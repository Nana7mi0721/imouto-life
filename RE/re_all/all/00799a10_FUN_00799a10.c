
uint FUN_00799a10(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = *param_1;
  if ((bVar1 & 0x80) == 0) {
    if ((bVar1 & 0x60) == 0x60) {
      return (bVar1 & 0x10) >> 4 | 0x450;
    }
    uVar2 = ((bVar1 & 0x60) >> 5) + 0x44d;
  }
  else {
    uVar2 = ((bVar1 & 0x60) >> 5) + 0x44e;
    if (uVar2 == 0x44e) {
      return 0x44d;
    }
  }
  return uVar2;
}

