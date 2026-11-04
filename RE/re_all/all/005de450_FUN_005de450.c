
undefined4 FUN_005de450(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  if (DAT_00a38108 == 0) {
    iVar3 = FUN_00519300(DAT_00a38120,0);
  }
  else {
    iVar2 = FUN_0051c790(DAT_00a38120);
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if ((DAT_00ca39f4 == 0) || (DAT_00f3a188 == 0)) {
    if (iVar2 != 0) {
      iVar1 = (*(int **)(iVar2 + 0x450))[2];
      iVar2 = **(int **)(iVar2 + 0x450);
      goto LAB_005de50a;
    }
    if (iVar3 != 0) {
      iVar1 = *(int *)(*(int *)(**(int **)(iVar3 + 0x100) + 0xc) + DAT_00a38140 * 4);
      iVar2 = *(int *)(**(int **)(iVar3 + 0x100) + 4);
      goto LAB_005de50a;
    }
    if (DAT_00ef1b58 != 0) {
      iVar2 = DAT_00ef1b58;
      iVar1 = DAT_00ef1b5c;
      goto LAB_005de50a;
    }
    iVar2 = DAT_00ee9b90;
    iVar1 = DAT_00ee9bc4;
  }
  else {
    iVar2 = DAT_00f3a188;
    iVar1 = DAT_00f3a190;
  }
LAB_005de50a:
  FUN_005c2b20(iVar2,iVar1,0);
  thunk_FUN_00567d80();
  DAT_00ef7324 = 1;
  FUN_005c2ae0((float)DAT_00a38194,(float)DAT_00a38198,(float)DAT_00a3819c,(float)DAT_00a381a0);
  DAT_00ef7324 = 0;
  return 0;
}

