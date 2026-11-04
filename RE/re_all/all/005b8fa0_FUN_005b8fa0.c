
undefined4 FUN_005b8fa0(void)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 local_8;
  undefined4 local_4;
  
  bVar1 = false;
  if (DAT_00f13924 != 0) {
    return 0;
  }
  iVar2 = FUN_005d2310();
  if (iVar2 == 0) {
    bVar1 = true;
    iVar2 = FUN_005d21e0();
    if (-1 < iVar2) {
      iVar2 = FUN_005d5440();
      if (-1 < iVar2) goto LAB_005b8fe1;
    }
    return 0xffffffff;
  }
LAB_005b8fe1:
  puVar3 = &DAT_00f1392c;
  DAT_00f13928 = 0;
  do {
    iVar2 = FUN_005d2320(DAT_00f13928,&local_8);
    if (iVar2 != 0) break;
    FUN_005d2380(local_8,puVar3);
    *(undefined4 *)(puVar3 + 0x124) = 0;
    do {
      iVar2 = FUN_005d23a0(local_8,*(undefined4 *)(puVar3 + 0x124),&local_4);
      if (iVar2 != 0) break;
      FUN_005d23c0(local_4,puVar3 + *(int *)(puVar3 + 0x124) * 0x5c + 0x128);
      FUN_005d3370(local_4);
      *(int *)(puVar3 + 0x124) = *(int *)(puVar3 + 0x124) + 1;
    } while (*(int *)(puVar3 + 0x124) < 0x20);
    FUN_005d3370(local_8);
    DAT_00f13928 = DAT_00f13928 + 1;
    puVar3 = puVar3 + 0xca8;
  } while (DAT_00f13928 < 0x10);
  if (bVar1) {
    FUN_005d22e0();
    FUN_005d2240();
  }
  DAT_00f13924 = 1;
  return 0;
}

