
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f6b40(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar2 = &DAT_00f3e91c;
  do {
    puVar3 = puVar2 + 1;
    *puVar2 = param_1 & 0xffff0000;
    uVar1 = param_1 * 0x10dcd + 1;
    *puVar2 = *puVar2 | uVar1 >> 0x10;
    param_1 = uVar1 * 0x10dcd + 1;
    puVar2 = puVar3;
  } while ((int)puVar3 < 0xf3f2dc);
  DAT_00f3f2e4 = FUN_005f6bb0();
  _DAT_00f3f2e0 = 1;
  FUN_005f6df0();
  return;
}

