
uint FUN_004fed8d(uint param_1,uint param_2)

{
  uint uVar1;
  bool in_ZF;
  short in_FPUControlWord;
  
  if (in_ZF) {
    if (((param_2 & 0xfffff) != 0) || (param_1 != 0)) {
      uVar1 = FUN_0050723c();
      goto LAB_004fee0b;
    }
    param_1 = param_2 & 0x80000000;
    param_2 = 0;
joined_r0x004fedfc:
    if (param_1 == 0) {
LAB_004fedae:
      if (DAT_00a1fbb8 == 0) {
        uVar1 = __math_exit();
        return uVar1;
      }
      return param_2;
    }
  }
  else {
    if (in_FPUControlWord != 0x27f) {
      param_2 = FUN_00507225();
    }
    if ((param_2 & 0x80000000) == 0) goto LAB_004fedae;
    if (((param_2 & 0x7ff00000) == 0) && ((param_2 & 0xfffff) == 0)) goto joined_r0x004fedfc;
  }
  uVar1 = 1;
LAB_004fee0b:
  if (DAT_00a1fbb8 == 0) {
    uVar1 = __startOneArgErrorHandling();
    return uVar1;
  }
  return uVar1;
}

