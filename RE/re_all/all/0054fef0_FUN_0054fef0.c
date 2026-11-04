
int FUN_0054fef0(byte param_1)

{
  int iVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (DAT_00a20bec == 0) {
    return -1;
  }
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if (DAT_00a72a60 == 0) {
    iVar1 = FUN_0056a010();
    return iVar1;
  }
  if ((param_1 & 1) != 0) {
    FUN_0054f860(1);
    iVar1 = 0;
    do {
      if ((((((&DAT_00a72a6c)[iVar1] & 0x80) != 0) && (iVar1 != 0x94)) && (iVar1 != 0x3a)) &&
         (iVar1 != 0x70)) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x100);
    if (DAT_00a798c8 != 0) {
      return 0x44;
    }
  }
  if (((param_1 & 2) != 0) && (iVar1 = 0, 0 < DAT_00a74b80)) {
    do {
      iVar1 = iVar1 + 1;
      iVar2 = FUN_0054f980(iVar1);
      if (iVar2 != 0) {
        return -1;
      }
    } while (iVar1 < DAT_00a74b80);
  }
  if ((param_1 & 4) != 0) {
    if ((DAT_00a82788 < 1) || (DAT_00a82778 < 0)) {
      FUN_0050f3d0(&local_18,&local_14);
    }
    else {
      local_18 = (&DAT_00a82794)[DAT_00a8277c * 4];
      local_14 = (&DAT_00a82798)[DAT_00a8277c * 4];
    }
    FUN_005111b0(&local_10);
    if (((((-1 < local_18) && (-1 < local_14)) && (iVar1 = FUN_0050e880(), iVar1 != 0)) &&
        ((local_18 <= local_8 - local_10 && (local_14 <= local_4 - local_c)))) &&
       (iVar1 = FUN_0054f4c0(), iVar1 != 0)) {
      return -1;
    }
  }
  return 0;
}

