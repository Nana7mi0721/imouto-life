
undefined4 FUN_00521cd0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  puVar2 = &DAT_00a38358;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_00584ff0(&DAT_00a383d8,&DAT_00a38358);
  DAT_00a387d8 = 0;
  FUN_00519a50();
  if (DAT_00a37d78 != 0) {
    FUN_00567bf0(&DAT_00a383d8);
    DAT_00a38350 = 1;
  }
  return 0;
}

