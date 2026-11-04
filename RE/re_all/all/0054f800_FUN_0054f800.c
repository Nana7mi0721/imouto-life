
undefined4 FUN_0054f800(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = (param_1 & 0xffffefff) - 1;
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if (DAT_00a72a60 == 0) {
    uVar1 = FUN_0056a010();
    return uVar1;
  }
  if ((iVar2 < 0) || (DAT_00a74b80 <= iVar2)) {
    return 0xffffffff;
  }
  uVar1 = FUN_0056b2a0(param_1);
  return uVar1;
}

