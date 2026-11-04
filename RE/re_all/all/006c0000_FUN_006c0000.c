
void * FUN_006c0000(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   int *param_5)

{
  void *_Memory;
  int iVar1;
  
  _Memory = _malloc(0x2340);
  iVar1 = -0x81;
  if (_Memory != (void *)0x0) {
    iVar1 = FUN_006c0140(_Memory,param_1,param_2,param_3,param_4);
    if (-1 < iVar1) {
      if (param_5 != (int *)0x0) {
        *param_5 = 0;
      }
      return _Memory;
    }
    *(undefined4 *)((int)_Memory + 0xc) = 0;
    FUN_006c0080(_Memory);
    _free(_Memory);
  }
  if (param_5 != (int *)0x0) {
    *param_5 = iVar1;
  }
  return (void *)0x0;
}

