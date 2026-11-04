
uint FUN_00564640(uint param_1)

{
  uint uVar1;
  
  if (((((int)param_1 < 0) || ((param_1 & 0x7c000000) != 0x24000000)) ||
      (uVar1 = param_1 & 0xffff, 0xff < uVar1)) ||
     (((&DAT_00aa84b8)[uVar1 * 0x17] == 0 ||
      ((&DAT_00aa84bc)[uVar1 * 0x17] * 0x10000 != (param_1 & 0x3ff0000))))) {
    return 0xffffffff;
  }
  if (*(int *)(&DAT_00aa84c4 + uVar1 * 0x5c) == 0) {
    return (uint)(*(int *)(&DAT_00aa84c0 + uVar1 * 0x5c) != 0);
  }
  return 2;
}

