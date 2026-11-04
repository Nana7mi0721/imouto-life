
int FUN_005ffc70(int param_1)

{
  int iVar1;
  
  iVar1 = 1;
  if (0x40000000 < param_1) {
    return 0x8000;
  }
  if (1 < param_1) {
    do {
      iVar1 = iVar1 * 2;
    } while (iVar1 * iVar1 < param_1);
  }
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = (iVar1 * iVar1 + param_1) / (iVar1 * 2);
  if ((-1 < iVar1) && (iVar1 = (iVar1 * iVar1 + param_1) / (iVar1 * 2), -1 < iVar1)) {
    iVar1 = (iVar1 * iVar1 + param_1) / (iVar1 * 2);
  }
  return iVar1;
}

