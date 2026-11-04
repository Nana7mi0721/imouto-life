
undefined4 FUN_005b9b80(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if ((DAT_00f07618 != param_1) || (DAT_00ef7324 != 0)) {
    iVar1 = *(int *)(DAT_00ef1b8c + 8);
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    DAT_00f07618 = param_1;
    if (param_1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0x3f800000;
    }
    *(undefined4 *)(iVar1 + 0xf8) = uVar2;
    *(undefined4 *)(DAT_00ef1b8c + 0xc) = 1;
    DAT_00ef72cc = 1;
  }
  return 0;
}

