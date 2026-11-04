
undefined4 FUN_005cac90(void)

{
  int iVar1;
  undefined *puVar2;
  
  FUN_005c0470();
  FUN_0056bb10(&DAT_007ff080);
  DAT_00a37dc8 = 1;
  iVar1 = FUN_005b6ca0();
  if (iVar1 == 0) {
    FUN_0056bca0(&DAT_007fc8d4);
    DAT_00a37dc8 = 0;
    return 0xffffffff;
  }
  iVar1 = FUN_005b83c0(&DAT_00f22470,&DAT_00ef1bac,7);
  if (iVar1 < 0) {
    iVar1 = -1 - iVar1;
    puVar2 = &DAT_007ff020;
    goto LAB_005cae3c;
  }
  iVar1 = FUN_005b8410(&DAT_00f224a8,&DAT_00ef1bc8,0xe);
  if (iVar1 < 0) {
    iVar1 = -1 - iVar1;
    puVar2 = &DAT_007fefa8;
    goto LAB_005cae3c;
  }
  iVar1 = FUN_005b8410(&DAT_00f22518,&DAT_00ef1c00,0xe0);
  if (iVar1 < 0) {
    iVar1 = -1 - iVar1;
    puVar2 = &DAT_007fef30;
    goto LAB_005cae3c;
  }
  iVar1 = FUN_005b8410(&DAT_00f22c18,&DAT_00ef1f80,1);
  if (iVar1 < 0) {
LAB_005cad67:
    iVar1 = -1 - iVar1;
    puVar2 = &DAT_007feed8;
  }
  else {
    iVar1 = FUN_005b8410(&DAT_00f22c20,&DAT_00ef1f84,1);
    if (-1 < iVar1) {
      iVar1 = FUN_005b8410(&DAT_00f22c28,&DAT_00ef1f88,4);
      if (iVar1 < 0) goto LAB_005cad67;
      iVar1 = FUN_005b8410(&DAT_00f22c48,&DAT_00ef1f98,4);
      if (-1 < iVar1) {
        iVar1 = FUN_005b83c0(&DAT_00f22c68,&DAT_00ef1fc0,1);
        if (iVar1 < 0) {
          iVar1 = -1 - iVar1;
          puVar2 = &DAT_007fee28;
        }
        else {
          iVar1 = FUN_005b83c0(&DAT_00f22c70,&DAT_00ef1fc4,1);
          if (iVar1 < 0) {
            iVar1 = -1 - iVar1;
            puVar2 = &DAT_007fedc8;
          }
          else {
            iVar1 = FUN_005b8410(&DAT_00f22c78,&DAT_00ef1fc8,1);
            if (-1 < iVar1) {
              FUN_0056bb10(&DAT_007d4974);
              return 0;
            }
            iVar1 = -1 - iVar1;
            puVar2 = &DAT_007fed78;
          }
        }
        goto LAB_005cae3c;
      }
    }
    iVar1 = -1 - iVar1;
    puVar2 = &DAT_007fee78;
  }
LAB_005cae3c:
  FUN_0056bca0(puVar2,iVar1);
  DAT_00a37dc8 = 0;
  return 0xffffffff;
}

