
void FUN_006c4970(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2];
  if (*param_1 != 0) {
    iVar1 = iVar1 + 1;
  }
  while (0 < iVar1) {
    iVar1 = iVar1 + -1;
    _free(*(void **)(*param_1 + iVar1 * 4));
  }
  _free((void *)*param_1);
  _free((void *)param_1[1]);
  _free((void *)param_1[3]);
  return;
}

