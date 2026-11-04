
undefined4 FUN_005cae60(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 == 0) || (param_3 == 0)) {
    return 0xffffffff;
  }
  if (0xff < param_1) {
    return 0xffffffff;
  }
  iVar2 = -1;
  iVar1 = 0;
  do {
    if ((&DAT_00f1370c)[iVar1] == (&DAT_00ee9b90)[param_1 * 0x20]) {
      FUN_005c2b20(0,0,iVar1);
      iVar2 = iVar1;
      break;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  FUN_005b8530(param_1);
  iVar1 = FUN_005d2750((&DAT_00ee9b4c)[param_1 * 0x20],2,param_2,param_3,0x1c,0);
  if (iVar1 == 0) {
    iVar1 = FUN_005b8480(param_1);
    if (-1 < iVar1) {
      if (iVar2 != -1) {
        FUN_005c2b20((&DAT_00ee9b90)[param_1 * 0x20],(&DAT_00ee9bc4)[param_1 * 0x20],iVar2);
      }
      return 0;
    }
  }
  else {
    FUN_0056bb10(&DAT_007ff0a8);
  }
  return 0xffffffff;
}

