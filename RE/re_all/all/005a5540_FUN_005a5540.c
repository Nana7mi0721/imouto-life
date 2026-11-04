
undefined4
FUN_005a5540(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  iVar1 = FUN_005d35f0();
  if ((iVar1 != 0) && (DAT_00e79688 != 0)) {
    FUN_005d3950();
    DAT_00e79688 = 0;
  }
  if (DAT_00f3a04c != 0) {
    if (DAT_00e39a4c == 0) {
      if (DAT_00e39a54 == 0) goto LAB_005a55eb;
    }
    else if ((DAT_00e39a54 == 0) && (FUN_00568ca0(0), DAT_00dda46c != 0)) {
      FUN_00584d70();
    }
    DAT_00e39a1c = 1;
    if (DAT_00e39a4c != 0) {
      DAT_00e39a18 = 1;
    }
    DAT_00e39a4c = 0;
    DAT_00e39a00 = 1;
  }
LAB_005a55eb:
  if ((param_5 != 0) && (iVar1 = **(int **)(param_5 + 0x100), *(int *)(iVar1 + 0x1c) != 0)) {
    FUN_005d3850(*(undefined4 *)(iVar1 + 0x1c),0,*(undefined4 *)(iVar1 + 4 + param_2 * 4),0,0);
  }
  if ((DAT_00ca39f4 != 0) && (iVar1 = DAT_00f3a154, DAT_00f3a154 != 0)) {
LAB_005a5696:
    FUN_005a0bd0(iVar1,0);
    thunk_FUN_00567d80();
    return 0;
  }
  if (param_6 == 0) {
    if (param_4 == 0) {
      iVar1 = DAT_00ddb5c4;
      if (DAT_00ddb5c4 == 0) {
        iVar1 = DAT_00ddb5b4;
      }
      goto LAB_005a5696;
    }
    iVar1 = *(int *)(**(int **)(param_4 + 0x100) + 0x1c);
    if (iVar1 == 0) {
      FUN_005a0bd0(*(undefined4 *)(**(int **)(param_4 + 0x100) + 4 + DAT_00a38140 * 4),0);
      thunk_FUN_00567d80();
      return 0;
    }
  }
  else {
    iVar1 = *(int *)(*(int *)(param_6 + 0x450) + 4);
  }
  FUN_005a0bd0(iVar1,0);
  thunk_FUN_00567d80();
  return 0;
}

