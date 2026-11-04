
undefined4 FUN_0052df70(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined **ppuVar3;
  
  uVar1 = 0;
  if (param_1 != (undefined4 *)0x0) {
    ppuVar3 = &PTR_FUN_0084c9d0;
    for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppuVar3 = (undefined *)*param_1;
      param_1 = param_1 + 1;
      ppuVar3 = ppuVar3 + 1;
    }
    return uVar1;
  }
  if (DAT_00a496f8 == 1) {
    PTR_FUN_0084c9d0 = FUN_0052db80;
    PTR_FUN_0084c9d4 = FUN_0052dbe0;
    PTR_FUN_0084c9d8 = FUN_0052dc10;
    PTR_FUN_0084c9dc = FUN_0052dc20;
    PTR_FUN_0084c9e0 = FUN_0052dcb0;
    PTR_DAT_0084c9e4 = &LAB_0052dd40;
    PTR_LAB_0084c9e8 = thunk_FUN_005954e0;
    DAT_0084c9ec = (code *)&LAB_0052dd60;
    PTR_FUN_0084c9f0 = &LAB_0052dd70;
    PTR_FUN_0084c9f4 = &LAB_0052dd90;
    DAT_0084c9f8 = FUN_0052dda0;
    PTR_DAT_0084c9fc = &LAB_0052ddf0;
    PTR_FUN_0084ca00 = FUN_0052de00;
    return uVar1;
  }
  PTR_FUN_0084c9d0 = FUN_00572540;
  PTR_FUN_0084c9d4 = FUN_00571d20;
  PTR_FUN_0084c9d8 = FUN_00571dd0;
  PTR_FUN_0084c9dc = FUN_00571e10;
  PTR_FUN_0084c9e0 = FUN_00571e60;
  PTR_DAT_0084c9e4 = &DAT_00571eb0;
  PTR_LAB_0084c9e8 = &LAB_005715a0;
  DAT_0084c9ec = FUN_005700d0;
  PTR_FUN_0084c9f0 = FUN_005700e0;
  PTR_FUN_0084c9f4 = FUN_00570100;
  DAT_0084c9f8 = (code *)&LAB_005727c0;
  PTR_DAT_0084c9fc = &DAT_005715e0;
  PTR_FUN_0084ca00 = FUN_00570120;
  return uVar1;
}

