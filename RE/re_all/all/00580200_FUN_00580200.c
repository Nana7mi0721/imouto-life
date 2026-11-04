
undefined4 FUN_00580200(void)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  
  iVar3 = 0;
  DAT_00ca3d20 = 1;
  puVar2 = &DAT_00ca3d2c;
  if (DAT_00ca3d24 < 1) {
    DAT_00ca3d20 = 0;
    return 0;
  }
  do {
    iVar1 = FUN_0056d960(puVar2);
    if (iVar1 != 0) {
      iVar1 = *(int *)(puVar2 + 0x10);
      while (iVar1 == 0) {
        FUN_0057fe80();
        if (DAT_00ca422c == 0) {
          FUN_0057fd00(0);
        }
        FUN_0056da20(1);
        iVar1 = *(int *)(puVar2 + 0x10);
      }
      FUN_0056d940(puVar2);
    }
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 0x28;
  } while (iVar3 < DAT_00ca3d24);
  DAT_00ca3d20 = 0;
  return 0;
}

