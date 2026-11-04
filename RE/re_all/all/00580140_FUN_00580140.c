
undefined4 FUN_00580140(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  
  DAT_00ca3d24 = 0x20;
  if (DAT_00ca3d28 == 0) {
    DAT_00ca3d28 = param_1 + -1;
    if (DAT_00ca3d28 < 1) {
      DAT_00ca3d28 = 1;
    }
  }
  else {
    FUN_005800e0(DAT_00ca3d28);
  }
  FUN_0056d380(&DAT_00ca3d2c,0,0x500);
  iVar4 = 0;
  puVar3 = &DAT_00ca3d2c;
  if (0 < DAT_00ca3d24) {
    do {
      iVar1 = FUN_0056db00(puVar3,(&PTR_LAB_0085e4f8)[iVar4],0);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      FUN_0056d970(puVar3,0);
      *(undefined4 *)(puVar3 + 0x1c) = 1;
      uVar2 = FUN_00550060(0);
      *(undefined4 *)(puVar3 + 0x20) = uVar2;
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 0x28;
    } while (iVar4 < DAT_00ca3d24);
  }
  FUN_0056da20(0x10);
  return 0;
}

