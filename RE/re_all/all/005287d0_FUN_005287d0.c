
undefined4
FUN_005287d0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = DAT_00a37d78;
  if (1 < param_6) {
    uVar3 = FUN_00528360(param_1,param_2,param_3,param_4,param_6);
    return uVar3;
  }
  if (DAT_00a37fd0 != 0) {
    return 0;
  }
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if ((DAT_00a381c4 == 0) && (DAT_00a37d78 != 0)) {
    FUN_005198b0();
  }
  if (((DAT_00a380cc == 3) && (DAT_00a37d8c == 0)) && (iVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
    if (DAT_00ca39f4 == 0) {
      if (iVar2 == 0) {
        uVar3 = FUN_00515680(param_1,param_2);
        return uVar3;
      }
      uVar3 = FUN_00569030(param_1,param_2,param_3,param_4,param_5);
      return uVar3;
    }
  }
  iVar5 = param_3;
  iVar6 = param_1;
  if (param_3 < param_1) {
    iVar5 = param_1;
    iVar6 = param_3;
  }
  iVar4 = param_4;
  iVar7 = param_2;
  if (param_4 < param_2) {
    iVar4 = param_2;
    iVar7 = param_4;
  }
  iVar5 = iVar5 + 1 + param_6;
  iVar6 = iVar6 - param_6;
  iVar7 = iVar7 - param_6;
  iVar4 = iVar4 + 1 + param_6;
  if (-1 < (int)((iVar4 - DAT_00a381a0) - 1U & (iVar5 - DAT_00a3819c) - 1U &
                 (DAT_00a38198 - iVar7) - 1U & (DAT_00a38194 - iVar6) - 1U)) {
    if (iVar6 < DAT_00a38194) {
      iVar6 = DAT_00a38194;
    }
    if (iVar5 < DAT_00a38194) {
      iVar5 = DAT_00a38194;
    }
    if (DAT_00a3819c < iVar6) {
      iVar6 = DAT_00a3819c;
    }
    if (DAT_00a3819c < iVar5) {
      iVar5 = DAT_00a3819c;
    }
    if (iVar7 < DAT_00a38198) {
      iVar7 = DAT_00a38198;
    }
    if (iVar4 < DAT_00a38198) {
      iVar4 = DAT_00a38198;
    }
    if (DAT_00a381a0 < iVar7) {
      iVar7 = DAT_00a381a0;
    }
    if (DAT_00a381a0 < iVar4) {
      iVar4 = DAT_00a381a0;
    }
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057b170(iVar6,iVar7,iVar5,iVar4);
  }
  if (bVar1) {
    FUN_00519580();
    param_6 = FUN_00569030(param_1,param_2,param_3,param_4,param_5);
    FUN_00519650();
  }
  else if (iVar2 == 0) {
    param_6 = FUN_00515680(param_1,param_2);
  }
  else {
    param_6 = FUN_00569030(param_1,param_2,param_3,param_4,param_5);
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057ae10(iVar6,iVar7,iVar5,iVar4);
  }
  return param_6;
}

