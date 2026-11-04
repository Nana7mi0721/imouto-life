
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005bb2e0(int param_1)

{
  int iVar1;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if ((DAT_00f1366c != param_1) || (DAT_00ef7324 != 0)) {
    iVar1 = *(int *)(DAT_00ef1ba0 + 8);
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    DAT_00f1366c = param_1;
    *(float *)(iVar1 + 0x14) = (float)param_1 / (float)_DAT_0081ec30;
    *(undefined4 *)(DAT_00ef1ba0 + 0xc) = 1;
  }
  return 0;
}

