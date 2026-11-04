
undefined4 FUN_0054f460(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if ((DAT_00a82788 < 1) || (DAT_00a82778 < 0)) {
    uVar1 = FUN_0050f3d0();
    return uVar1;
  }
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (&DAT_00a82794)[DAT_00a8277c * 4];
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = (&DAT_00a82798)[DAT_00a8277c * 4];
  }
  return 0;
}

