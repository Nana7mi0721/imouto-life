
undefined4 FUN_005bb280(int param_1)

{
  int iVar1;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if ((DAT_00f13668 != param_1) || (DAT_00ef7324 != 0)) {
    iVar1 = *(int *)(DAT_00ef1ba0 + 8);
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    DAT_00f13668 = param_1;
    *(int *)(iVar1 + 0x20) = param_1;
    *(undefined4 *)(DAT_00ef1ba0 + 0xc) = 1;
  }
  return 0;
}

