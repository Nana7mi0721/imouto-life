
undefined4 FUN_004369a0(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (16000000 < param_1) {
    if ((999999999 < param_1) && (param_1 < 1100000000)) {
      uVar2 = FUN_00477870((param_1 % 1000000000) / 1000000,(param_1 % 1000000) / 100,param_1 % 100,
                           1);
      return uVar2;
    }
    if ((1099999999 < param_1) && (param_1 < 1200000000)) {
      uVar2 = FUN_00477870((param_1 % 1100000000) / 1000000,(param_1 % 1000000) / 100,param_1 % 100,
                           1);
      return uVar2;
    }
    if ((param_1 < 1300000000) || (1399999999 < param_1)) {
      return 0;
    }
    uVar2 = FUN_00477870((param_1 % 1300000000) / 1000000,(param_1 % 1000000) / 100,param_1 % 100,1)
    ;
    return uVar2;
  }
  if (((1999999 < param_1) && (param_1 < 3000000)) &&
     (iVar1 = FUN_004cd340(), (param_1 + -2000000) / 100000 < iVar1)) {
    FUN_004cde80((param_1 + -2000000) / 100000);
    iVar1 = FUN_004ce080();
    if (param_1 % 100000 < iVar1) {
      iVar1 = param_1 % 100000;
      FUN_004cde80((param_1 + -2000000) / 100000);
      uVar2 = FUN_004ce990(iVar1);
      return uVar2;
    }
    return 0;
  }
  if (-1 < (int)param_2) {
    if ((0x186a04 < param_1) && (param_1 < 0x186a0a)) {
      return 0;
    }
    if ((1599999 < param_1) && (param_1 < 0x186a64)) {
      uVar3 = FUN_004cd340();
      if (param_2 < uVar3) {
        FUN_004cde80(param_2);
        uVar3 = FUN_004ce080();
        if ((uint)(param_1 % 100) < uVar3) {
          param_1 = param_1 % 100;
          FUN_004cde80(param_2);
          uVar2 = FUN_004ce990(param_1);
          return uVar2;
        }
      }
      return 0;
    }
    if ((14999999 < param_1) && (param_1 < 16000000)) {
      if ((4 < param_1 % 100) && (param_1 % 100 < 10)) {
        return 0;
      }
      uVar3 = FUN_004cd340();
      if ((uint)(param_1 / 100) < uVar3) {
        FUN_004cde80(param_2);
        uVar3 = FUN_004ce080();
        if ((uint)(param_1 % 100) < uVar3) {
          iVar1 = param_1 % 100;
          FUN_004cde80(param_1 / 100);
          uVar2 = FUN_004ce990(iVar1);
          return uVar2;
        }
      }
      return 0;
    }
  }
  return 0;
}

