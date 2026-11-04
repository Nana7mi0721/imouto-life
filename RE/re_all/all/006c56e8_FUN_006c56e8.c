
uint FUN_006c56e8(int param_1,uint param_2)

{
  uint in_EAX;
  uint uVar1;
  bool in_ZF;
  unkbyte10 in_ST0;
  
  if (in_ZF) {
    if (((in_EAX & 0xfffff) != 0) || (param_1 != 0)) {
      uVar1 = FUN_0050723c();
      goto LAB_006c5781;
    }
    param_2 = 0;
    if ((in_EAX & 0x80000000) == 0) goto LAB_006c5715;
  }
  else {
    if ((((param_2 & 0x7ff00000) == 0) && ((param_2 & 0xfffff) == 0)) && (param_1 == 0)) {
      uVar1 = 2;
      goto LAB_006c5781;
    }
    if ((param_2 & 0x80000000) == 0) {
      log2(in_ST0);
LAB_006c5715:
      if (DAT_00a1fbb8 == 0) {
        uVar1 = __math_exit();
        return uVar1;
      }
      return param_2;
    }
  }
  uVar1 = 1;
LAB_006c5781:
  if (DAT_00a1fbb8 == 0) {
    uVar1 = __startOneArgErrorHandling();
    return uVar1;
  }
  return uVar1;
}

