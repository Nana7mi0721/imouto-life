
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005baf50(void)

{
  int iVar1;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  iVar1 = *(int *)(DAT_00ef1b84 + 8);
  *(float *)(iVar1 + 0x2e0) = _DAT_00f07370 / (_DAT_00f07370 - _DAT_00f0736c);
  *(float *)(iVar1 + 0x2e4) = (float)_DAT_00805148 / (_DAT_00f07370 - _DAT_00f0736c);
  *(undefined4 *)(iVar1 + 0x2e8) = _DAT_00f07374;
  *(undefined4 *)(iVar1 + 0x2ec) = _DAT_007fc510;
  *(undefined4 *)(DAT_00ef1b84 + 0xc) = 1;
  return 0;
}

