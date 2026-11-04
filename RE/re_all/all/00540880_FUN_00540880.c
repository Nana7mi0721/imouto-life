
uint FUN_00540880(uint param_1)

{
  uint in_EAX;
  uint uVar1;
  
  if ((param_1 == 0) || (uVar1 = (param_1 >> 0x17 & 0xff) - 0x70, (int)uVar1 < 0)) {
    return in_EAX & 0xffff0000;
  }
  if (0x1f < (int)uVar1) {
    uVar1 = 0x1f;
  }
  return (param_1 >> 3 & 0x10000000 | param_1 & 0x7fe000) >> 0xd | (uVar1 & 0x1f) << 10;
}

