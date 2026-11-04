
int FUN_00798510(byte *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = *param_1;
  if ((bVar1 & 0x80) != 0) {
    return (param_2 << (sbyte)((bVar1 & 0x18) >> 3)) / 400;
  }
  if ((bVar1 & 0x60) == 0x60) {
    if ((bVar1 & 8) == 0) {
      return param_2 / 100;
    }
    return param_2 / 0x32;
  }
  uVar2 = (bVar1 & 0x18) >> 3;
  if (uVar2 == 3) {
    return (param_2 * 0x3c) / 1000;
  }
  return (param_2 << (sbyte)uVar2) / 100;
}

