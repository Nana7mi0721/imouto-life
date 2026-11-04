
undefined4 FUN_0054fd70(uint param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = (param_1 & 0xffffefff) - 1;
  puVar3 = &DAT_00a74b84 + iVar2 * 0x4d4;
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if (DAT_00a72a60 == 0) {
    uVar1 = FUN_0056a010();
    return uVar1;
  }
  if ((-1 < iVar2) && (iVar2 < DAT_00a74b80)) {
    if (param_2 < 0) {
      FUN_0054fd70(param_1,0);
      FUN_0054fd70(param_1,1);
      return 0;
    }
    if (param_2 < 2) {
      iVar2 = FUN_0056b270(puVar3,param_2);
      if ((iVar2 != 0) && (param_2 = param_2 * 0x20, *(int *)(puVar3 + param_2 + 4) != 0)) {
        *(undefined4 *)(puVar3 + param_2 + 4) = 0;
        *(undefined4 *)(puVar3 + param_2 + 8) = 10000;
        FUN_0054f890();
      }
    }
  }
  return 0;
}

