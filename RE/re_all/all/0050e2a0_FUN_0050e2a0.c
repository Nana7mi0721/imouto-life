
undefined4 FUN_0050e2a0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_00a238e0 != 0) {
    return 0xffffffff;
  }
  FUN_0056bb10(&DAT_007d4984);
  iVar1 = (*DAT_00aba19c)(0,2);
  if (iVar1 < 0) {
    uVar2 = FUN_0056bb10("1YWe\n");
    return uVar2;
  }
  FUN_0056bb10(&DAT_007d4974);
  DAT_00a238e0 = 1;
  return 0;
}

