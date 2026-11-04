
void FUN_00677be0(byte *param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2 < 0x4001) {
    bVar1 = *param_1;
    if (((bVar1 & 0xf) == 8) && ((bVar1 & 0xf0) < 0x71)) {
      uVar2 = (uint)(bVar1 >> 4);
      uVar3 = 1 << (bVar1 >> 4) + 7;
      if (param_2 <= uVar3) {
        do {
          uVar3 = uVar3 >> 1;
          uVar2 = uVar2 - 1;
          if (uVar2 == 0) break;
        } while (param_2 <= uVar3);
        uVar2 = uVar2 * 0x10 | 8;
        *param_1 = (byte)uVar2;
        param_1[1] = ((char)(param_1[1] & 0xe0) -
                     (char)((uVar2 * 0x100 + (param_1[1] & 0xe0)) % 0x1f)) + 0x1f;
      }
    }
  }
  return;
}

