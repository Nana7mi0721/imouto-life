
undefined4 FUN_00563ac0(undefined2 param_1)

{
  if ((DAT_00aa57e8 + 1 == DAT_00aa57e4) || ((DAT_00aa57e4 == 0 && (DAT_00aa57e8 == 0x400)))) {
    return 0xffffffff;
  }
  (&DAT_00aa4fe0)[DAT_00aa57e8] = param_1;
  DAT_00aa57e8 = DAT_00aa57e8 + 1;
  if (DAT_00aa57e8 == 0x401) {
    DAT_00aa57e8 = 0;
  }
  return 0;
}

