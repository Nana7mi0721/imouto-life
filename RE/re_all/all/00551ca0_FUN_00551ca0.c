
undefined4 FUN_00551ca0(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if (*param_1 == 0) {
    return 0xffffffff;
  }
  if ((DAT_00a83c64 == 0) && (iVar1 = FUN_0057ee10(param_1,param_2,param_3), iVar1 != 2)) {
    if (iVar1 < 0) {
      return 0xffffffff;
    }
    return 0;
  }
  if (param_2 != (int *)0x0) {
    *param_2 = param_1[0x15] * (uint)*(ushort *)(param_1 + 0xf);
  }
  if (param_3 != (int *)0x0) {
    *param_3 = param_1[0x15] * (uint)*(ushort *)(param_1 + 0xf);
  }
  return 0;
}

