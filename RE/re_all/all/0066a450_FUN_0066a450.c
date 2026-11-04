
undefined4 FUN_0066a450(uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_0066a4b0(param_1 >> 0x18);
  if (iVar1 != 0) {
    iVar1 = FUN_0066a4b0(param_1 >> 0x10 & 0xff);
    if (iVar1 != 0) {
      iVar1 = FUN_0066a4b0(param_1 >> 8 & 0xff);
      if (iVar1 != 0) {
        iVar1 = FUN_0066a4b0(param_1 & 0xff);
        if (iVar1 != 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}

