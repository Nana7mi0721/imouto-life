
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065ce90(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 double param_5)

{
  uint local_8;
  undefined4 uStack_4;
  
  if (_DAT_007d0a60 < param_5) {
    local_8 = __ftol();
    uStack_4 = 0;
    if ((double)local_8 == param_5) {
      uStack_4 = 1;
    }
    else if (_DAT_00802e18 <= param_5) {
      local_8 = 0xffffffff;
      uStack_4 = __ftol();
    }
    else {
      local_8 = __ftol();
      uStack_4 = 0xffffffff;
    }
  }
  else {
    local_8 = 0;
    uStack_4 = 1;
  }
  if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
    FUN_0065a600(&local_8);
    FUN_0065a600(&uStack_4);
  }
  FUN_0065d3a0(param_1,param_2,param_3,param_4,5,1,8,&local_8);
  return;
}

