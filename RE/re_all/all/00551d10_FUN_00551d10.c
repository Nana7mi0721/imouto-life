
undefined4 FUN_00551d10(int *param_1,uint param_2)

{
  int iVar1;
  
  if (*param_1 != 0) {
    if (DAT_00a83c64 != 0) {
      param_1[0x15] = param_2 / *(ushort *)(param_1 + 0xf);
      param_1[0x16] = param_1[0x15];
      return 0;
    }
    iVar1 = FUN_0057ee40(param_1,param_2);
    if (-1 < iVar1) {
      return 0;
    }
  }
  return 0xffffffff;
}

