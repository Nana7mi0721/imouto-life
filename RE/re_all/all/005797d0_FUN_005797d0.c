
int FUN_005797d0(int param_1,int param_2,int param_3,int param_4,uint param_5,int param_6,
                uint param_7)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar1 = FUN_00573310(0);
  if (uVar1 == 0) {
    return 0;
  }
  if (param_1 == 0) {
    FUN_00572ff0(0x28);
    FUN_00572ff0(0x6e);
    FUN_00572ff0(0x75);
    FUN_00572ff0(0x6c);
    FUN_00572ff0(0x6c);
    FUN_00572ff0(0x29);
    FUN_00572ff0(0);
  }
  uVar2 = FUN_005773c0();
  if (param_4 < 0) {
    param_4 = 0;
  }
  if (((int)param_5 < 0) || ((int)uVar2 < (int)param_5)) {
    param_5 = uVar2;
  }
  if (param_3 != 0) {
    param_2 = 0;
  }
  param_4 = param_4 - param_5;
  uVar2 = FUN_00572ac0();
  iVar3 = param_4 >> 0x1f;
  if (param_3 != 0) {
    if (param_7 < uVar2 * param_5 + uVar1) {
      param_5 = (param_7 - uVar1) / uVar2;
    }
    FUN_00577020();
    iVar4 = uVar2 * param_5;
    if (param_7 - iVar4 <= uVar1) {
      return iVar4;
    }
    if (param_4 < 1) {
      return iVar4;
    }
    iVar3 = FUN_00577c20(param_4,iVar3,0x20,iVar4 + param_6,param_7 - iVar4);
    return iVar4 + iVar3;
  }
  if (param_2 == 0) {
    if (param_4 < 1) goto LAB_005799f2;
    iVar4 = FUN_00577c20(param_4,iVar3,0x20,param_6,param_7);
  }
  else {
    if (param_4 < 1) goto LAB_005799f2;
    iVar4 = FUN_00577c20(param_4,iVar3,0x30,param_6,param_7);
  }
  if (param_7 - iVar4 <= uVar1) {
    return iVar4;
  }
LAB_005799f2:
  if (param_7 - iVar4 < uVar2 * param_5 + uVar1) {
    param_5 = ((param_7 - uVar1) - iVar4) / uVar2;
  }
  FUN_00577020();
  return iVar4 + uVar2 * param_5;
}

