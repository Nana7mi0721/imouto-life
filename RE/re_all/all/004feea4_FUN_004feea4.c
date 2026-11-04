
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_004feea4(int param_1)

{
  ushort uVar1;
  uint uVar2;
  undefined1 in_ZF;
  ushort in_FPUStatusWord;
  unkbyte10 extraout_ST0;
  float10 fVar3;
  
  uVar2 = __fload_withFB();
  if ((bool)in_ZF) {
    if (((uVar2 & 0xfffff) == 0) && (param_1 == 0)) {
      in_FPUStatusWord = 1;
    }
    else {
      in_FPUStatusWord = FUN_0050723c();
    }
    if (DAT_00a1fbb8 == 0) {
      uVar1 = __startOneArgErrorHandling();
      return uVar1;
    }
  }
  else {
    fVar3 = (float10)fcos(extraout_ST0);
    if ((in_FPUStatusWord & 0x400) != 0) {
      do {
        fVar3 = fVar3 - ROUND(fVar3 / _DAT_007d404a) * _DAT_007d404a;
      } while ((in_FPUStatusWord & 0x400) != 0);
      fcos(fVar3);
    }
    if (DAT_00a1fbb8 == 0) {
      uVar1 = __math_exit();
      return uVar1;
    }
  }
  return in_FPUStatusWord;
}

