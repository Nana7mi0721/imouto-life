
void * FUN_00797ad0(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                   int *param_6)

{
  size_t _Size;
  void *_Memory;
  int iVar1;
  
  if ((((0xff < param_2) || (param_2 < 1)) || (param_3 < param_4)) ||
     (((param_3 < 1 || (param_4 < 0)) || (0xff - param_4 < param_3)))) {
    if (param_6 != (int *)0x0) {
      *param_6 = -1;
    }
    return (void *)0x0;
  }
  _Size = FUN_00797960(param_3,param_4);
  _Memory = _malloc(_Size);
  if (_Memory != (void *)0x0) {
    iVar1 = FUN_007979c0(_Memory,param_1,param_2,param_3,param_4,param_5);
    if (param_6 != (int *)0x0) {
      *param_6 = iVar1;
    }
    if (iVar1 != 0) {
      _free(_Memory);
      _Memory = (void *)0x0;
    }
    return _Memory;
  }
  if (param_6 == (int *)0x0) {
    return (void *)0x0;
  }
  *param_6 = -7;
  return (void *)0x0;
}

