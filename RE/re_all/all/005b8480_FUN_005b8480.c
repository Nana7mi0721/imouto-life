
undefined4 FUN_005b8480(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (0xff < param_1) {
    return 0xffffffff;
  }
  puVar1 = &DAT_00ee9b90 + param_1 * 0x20;
  iVar2 = FUN_005d26e0((&DAT_00ee9b4c)[param_1 * 0x20],0,&DAT_0085e674,puVar1);
  if (iVar2 != 0) {
    FUN_0056bb10(&DAT_007fd018);
    return 0xffffffff;
  }
  FUN_005d2ee0(*puVar1,&DAT_00ee9b94 + param_1 * 0x20);
  iVar2 = FUN_005d2810(*puVar1,0,&DAT_00ee9bc0 + param_1 * 0x20);
  if (iVar2 != 0) {
    FUN_0056bb10(&DAT_007fcfb0);
    return 0xffffffff;
  }
  iVar2 = FUN_005d2840(*puVar1,0,&DAT_00ee9bc4 + param_1 * 0x20);
  if (iVar2 == 0) {
    return 0;
  }
  FUN_0056bb10(&DAT_007fcf48);
  return 0xffffffff;
}

