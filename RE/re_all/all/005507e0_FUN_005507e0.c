
void FUN_005507e0(undefined4 param_1)

{
  undefined4 *puVar1;
  
  FUN_0056bb00(param_1);
  FUN_0056bb00(&DAT_007d4b08);
  FUN_005506d0();
  if (DAT_00a37a48 == 1) {
    DAT_00a37a48 = 0;
    puVar1 = &DAT_00a2fa4c;
    do {
      if ((HANDLE)*puVar1 != (HANDLE)0x0) {
        CloseHandle((HANDLE)*puVar1);
      }
      *puVar1 = 0;
      puVar1 = puVar1 + 2;
    } while ((int)puVar1 < 0xa37a4c);
    FUN_0056da50(&DAT_00a37a50);
  }
                    /* WARNING: Subroutine does not return */
  ExitProcess(0xffffffff);
}

