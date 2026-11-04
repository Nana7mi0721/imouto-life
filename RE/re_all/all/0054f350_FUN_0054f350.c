
undefined4 FUN_0054f350(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (DAT_00a72a60 == 0) {
    DAT_00a72a60 = 1;
    iVar1 = FUN_00569760();
    if (iVar1 != 0) {
      DAT_00a72a60 = 0;
      return 0xffffffff;
    }
    puVar2 = &DAT_00a74bec;
    do {
      *puVar2 = 0xffffffff;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0xffffffff;
      puVar2 = puVar2 + 0x135;
    } while ((int)puVar2 < 0xa7992c);
  }
  return 0;
}

