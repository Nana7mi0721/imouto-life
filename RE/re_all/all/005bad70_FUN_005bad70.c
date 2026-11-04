
undefined4 FUN_005bad70(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (((DAT_00f138e0 != 0) || (param_1 != 0)) || (DAT_00ef7324 != 0)) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    DAT_00f138e0 = param_1;
    if (param_1 == 1) {
      puVar2 = &DAT_00f138e4;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = *param_2;
        param_2 = param_2 + 1;
        puVar2 = puVar2 + 1;
      }
      FUN_005bace0();
      return 0;
    }
    FUN_00585060(&DAT_00f138e4);
    FUN_005bace0();
  }
  return 0;
}

