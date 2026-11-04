
void * FUN_006c0eb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   int *param_5)

{
  void *_Memory;
  int iVar1;
  
  _Memory = (void *)FUN_006c0000(param_1,param_2,param_3,param_4,param_5);
  if (_Memory != (void *)0x0) {
    iVar1 = FUN_006c0f00(_Memory);
    if (-1 < iVar1) {
      return _Memory;
    }
    if (param_5 != (int *)0x0) {
      *param_5 = iVar1;
    }
    _free(_Memory);
  }
  return (void *)0x0;
}

