
undefined4 FUN_00521e70(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = DAT_00a37e74;
  iVar2 = DAT_00a37e70;
  iVar1 = DAT_00a37e64;
  iVar5 = DAT_00a37e60;
  if (param_3 == 0) {
    param_3 = 0x10;
  }
  if (DAT_00a37e78 == 0) {
    if (param_1 < 1) {
      return 0xffffffff;
    }
    if (param_2 < 1) {
      return 0xffffffff;
    }
  }
  else {
    param_1 = 0x140;
    param_2 = 0xf0;
  }
  if ((((param_3 != 0) && (param_3 != 8)) && (param_3 != 0x10)) && (param_3 != 0x20)) {
    return 0xffffffff;
  }
  if (DAT_00a49730 == 0) {
    FUN_005173e0(param_1,param_2);
    DAT_00a37e74 = param_4;
    DAT_00a37e70 = param_3;
    FUN_005811a0(param_3 == 0x20);
    return 0;
  }
  FUN_0052bfa0(param_1,param_2,param_3,0,param_4);
  if ((param_1 == DAT_00a37e60) && (param_2 == DAT_00a37e64)) {
    iVar4 = FUN_0050e7d0();
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = FUN_0050e7d0();
    if (((iVar4 == 1) && (param_3 == DAT_00a37e70)) && (param_4 == DAT_00a37e74)) {
      return 0;
    }
  }
  if (((((iVar5 == DAT_00a37e60) && (iVar1 == DAT_00a37e64)) && (iVar2 == DAT_00a37e70)) &&
      (iVar3 == DAT_00a37e74)) || ((DAT_00a37e60 != 0x280 || (DAT_00a37e64 != 0x1e0)))) {
    return 0xffffffff;
  }
  iVar5 = FUN_0050e7d0();
  if (iVar5 != 0) {
    iVar5 = FUN_0050e7d0();
    if (iVar5 != 1) {
      return 0xffffffff;
    }
    if (DAT_00a37e70 != 0x10) {
      return 0xffffffff;
    }
    if (DAT_00a37e74 != 0) {
      return 0xffffffff;
    }
  }
  return 0xfffffffe;
}

