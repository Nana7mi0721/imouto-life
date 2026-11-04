
undefined4 FUN_006a8940(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_006a86f0(param_1);
  if (iVar1 == 0) {
    iVar1 = FUN_006a87e0(param_1,param_2);
    while( true ) {
      if (0 < iVar1) {
        return 1;
      }
      if (iVar1 == 0) break;
      if (*(int *)(param_1 + 0x10) == 0) {
        *(undefined4 *)(param_1 + 0x10) = 1;
        return 0xffffffff;
      }
      iVar1 = FUN_006a87e0(param_1,param_2);
    }
  }
  return 0;
}

