
void FUN_006ac700(undefined4 *param_1)

{
  void *_Memory;
  undefined4 *puVar1;
  int iVar2;
  
  _Memory = (void *)param_1[0x1a];
  FUN_006ac690(param_1);
  if ((void *)param_1[0x11] != (void *)0x0) {
    _free((void *)param_1[0x11]);
  }
  if (_Memory != (void *)0x0) {
    iVar2 = 0;
    puVar1 = (undefined4 *)((int)_Memory + 0xc);
    do {
      FUN_007976a0(*puVar1);
      if (iVar2 != 7) {
        _free((void *)*puVar1);
      }
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < 0xf);
    _free(_Memory);
  }
  for (iVar2 = 0x1c; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  return;
}

