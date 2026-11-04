
undefined4 FUN_006a8590(undefined4 *param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  size_t _NewSize;
  
  iVar1 = param_1[1];
  if (iVar1 - param_2 <= (int)param_1[2]) {
    if (0x7fffffff - param_2 < iVar1) {
      FUN_006a8490(param_1);
      return 0xffffffff;
    }
    _NewSize = iVar1 + param_2;
    if ((int)_NewSize < 0x7ffffbff) {
      _NewSize = _NewSize + 0x400;
    }
    pvVar2 = _realloc((void *)*param_1,_NewSize);
    if (pvVar2 == (void *)0x0) {
      FUN_006a8490(param_1);
      return 0xffffffff;
    }
    param_1[1] = _NewSize;
    *param_1 = pvVar2;
  }
  return 0;
}

