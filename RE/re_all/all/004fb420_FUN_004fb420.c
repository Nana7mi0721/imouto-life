
undefined4 FUN_004fb420(int param_1)

{
  int *_Memory;
  undefined4 local_10;
  
  local_10 = 0;
  if (param_1 == 0) {
    local_10 = 0xffffff9a;
  }
  else {
    _Memory = *(int **)(param_1 + 0xe0);
    if (_Memory == (int *)0x0) {
      local_10 = 0xffffff9a;
    }
    else {
      if (((_Memory[0x20] == 0 && _Memory[0x21] == 0) && (_Memory[0x32] == 0)) &&
         (_Memory[0x1c] != _Memory[0x1d])) {
        local_10 = 0xffffff97;
      }
      if (*_Memory != 0) {
        _free((void *)*_Memory);
      }
      *_Memory = 0;
      if (_Memory[0x12] == 8) {
        FUN_0067c510(_Memory + 1);
      }
      _Memory[0x12] = 0;
      if (_Memory != (int *)0x0) {
        _free(_Memory);
      }
      *(undefined4 *)(param_1 + 0xe0) = 0;
    }
  }
  return local_10;
}

