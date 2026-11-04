
undefined4 FUN_0059d1e0(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 *local_4c [3];
  int local_40;
  
  if (param_2 != 0) {
    local_4c[0] = &LAB_0059d1c0;
    local_40 = param_1;
    uVar1 = FUN_0057ffd0(local_4c);
    return uVar1;
  }
  if (((&DAT_00ecfb1c)[param_1 * 0x18] != '\0') && ((&DAT_00ecfb1d)[param_1 * 0x18] != '\0')) {
    (&DAT_00ecfb1d)[param_1 * 0x18] = 0;
    uVar1 = FUN_00550060(0);
    (&DAT_00ecfb2c)[param_1 * 6] = uVar1;
  }
  return 0;
}

