
void FUN_006b8ed0(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = 0;
    if (0 < param_1[2]) {
      do {
        _free(*(void **)(*param_1 + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_1[2]);
    }
    _free((void *)*param_1);
    _free((void *)param_1[1]);
    _free((void *)param_1[3]);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
  }
  return;
}

