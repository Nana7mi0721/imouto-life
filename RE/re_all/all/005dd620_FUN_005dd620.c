
undefined4 FUN_005dd620(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar2 = 0;
  if (DAT_00a38108 == 0) {
    iVar1 = FUN_00519300(DAT_00a38120,0);
  }
  else {
    iVar2 = FUN_0051c790(DAT_00a38120);
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if ((DAT_00ca39f4 == 0) || (iVar3 = DAT_00f3a154, DAT_00f3a154 == 0)) {
    if (iVar2 == 0) {
      if (iVar1 == 0) {
        iVar3 = DAT_00ddb5c4;
        if (DAT_00ddb5c4 == 0) {
          iVar3 = DAT_00ddb5b4;
        }
      }
      else {
        iVar3 = *(int *)(**(int **)(iVar1 + 0x100) + 0x1c);
        if (iVar3 == 0) {
          iVar3 = *(int *)(**(int **)(iVar1 + 0x100) + 4 + DAT_00a38140 * 4);
        }
      }
    }
    else {
      iVar3 = *(int *)(*(int *)(iVar2 + 0x450) + 4);
    }
  }
  FUN_005a0bd0(iVar3,0);
  thunk_FUN_00567d80();
  DAT_00e39a54 = 1;
  FUN_005a0ad0(DAT_00a38194,DAT_00a38198,DAT_00a3819c,DAT_00a381a0);
  DAT_00e39a54 = 0;
  return 0;
}

