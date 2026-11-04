
undefined4 FUN_00567de0(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_00aaf0dc == 0) {
    if (param_1 == -4) {
      uVar1 = FUN_0050e7c0(0x7fff,0x20,&LAB_005d3da0);
      (*DAT_00aba1e8)(uVar1);
    }
  }
  else {
    if (DAT_00aaf0dc == 1) {
      uVar1 = FUN_0059d8f0();
      return uVar1;
    }
    if (DAT_00aaf0dc == 2) {
      uVar1 = FUN_005bda30();
      return uVar1;
    }
  }
  return 0;
}

