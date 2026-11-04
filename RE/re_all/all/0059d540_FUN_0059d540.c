
undefined4 FUN_0059d540(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if ((param_1 != 0) && (*(char *)(*(int *)(param_1 + 0x4c) + 8) != '\0')) {
    puVar1 = *(undefined4 **)(param_1 + 0x100);
    FUN_0059bd80(*(undefined4 *)*puVar1,puVar1[5],puVar1[6]);
    FUN_0059bbd0(param_2,param_3);
    return 0;
  }
  DAT_00a380d4 = 0xffffffff;
  if (DAT_00e39a54 == 0) {
    if (DAT_00e39a50 == 0) {
      DAT_00a380d4 = 0xffffffff;
      return 0;
    }
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
  }
  if (DAT_00e39a50 != 0) {
    DAT_00e39a18 = 1;
  }
  DAT_00e39a50 = 0;
  DAT_00e39a1c = 1;
  DAT_00e39a00 = 1;
  return 0;
}

