
undefined4 FUN_006a8600(int param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x18);
  if (iVar2 - param_2 <= *(int *)(param_1 + 0x1c)) {
    if (0x7fffffff - param_2 < iVar2) {
      FUN_006a8490(param_1);
      return 0xffffffff;
    }
    iVar2 = iVar2 + param_2;
    if (iVar2 < 0x7fffffdf) {
      iVar2 = iVar2 + 0x20;
    }
    pvVar1 = _realloc(*(void **)(param_1 + 0x10),iVar2 * 4);
    if (pvVar1 == (void *)0x0) {
      FUN_006a8490(param_1);
      return 0xffffffff;
    }
    *(void **)(param_1 + 0x10) = pvVar1;
    pvVar1 = _realloc(*(void **)(param_1 + 0x14),iVar2 * 8);
    if (pvVar1 == (void *)0x0) {
      FUN_006a8490(param_1);
      return 0xffffffff;
    }
    *(void **)(param_1 + 0x14) = pvVar1;
    *(int *)(param_1 + 0x18) = iVar2;
  }
  return 0;
}

