
undefined4 FUN_005619b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_0057e0e0();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  do {
    puVar2 = DAT_00a839fc;
    while( true ) {
      if (puVar2[3] == 0) {
        return 0;
      }
      iVar1 = FUN_00560f10(*puVar2);
      if (iVar1 == 0) break;
      puVar2 = (undefined4 *)puVar2[3];
    }
    FUN_00580b80(*puVar2);
  } while( true );
}

