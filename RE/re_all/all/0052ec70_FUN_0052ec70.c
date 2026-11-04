
undefined4 FUN_0052ec70(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (DAT_00a49730 == 0) {
    return 0;
  }
  FUN_0050e320();
  uVar1 = FUN_005506d0();
  FUN_0050e4a0();
  if (DAT_00a37a48 == 1) {
    DAT_00a37a48 = 0;
    puVar2 = &DAT_00a2fa4c;
    do {
      if ((HANDLE)*puVar2 != (HANDLE)0x0) {
        CloseHandle((HANDLE)*puVar2);
      }
      *puVar2 = 0;
      puVar2 = puVar2 + 2;
    } while ((int)puVar2 < 0xa37a4c);
    FUN_0056da50(&DAT_00a37a50);
  }
  return uVar1;
}

