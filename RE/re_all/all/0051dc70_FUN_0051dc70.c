
undefined4
FUN_0051dc70(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,int param_6)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_8;
  
  iVar2 = DAT_00a37d78;
  if (DAT_00a37fd0 != 0) {
    return 0;
  }
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if (param_3 < 0) {
    return 0;
  }
  if ((DAT_00a381c4 == 0) && (DAT_00a37d78 != 0)) {
    FUN_005198b0();
  }
  if (param_6 == 1) {
    if (((DAT_00a380cc == 3) && (DAT_00a37d8c == 0)) && (iVar2 != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
      if (DAT_00ca39f4 == 0) {
        if (iVar2 == 0) {
          uVar3 = FUN_005156a0(param_1,param_2,param_3,param_4);
          return uVar3;
        }
        uVar3 = FUN_00569090(param_1,param_2,param_3,param_4,param_5,0,0);
        return uVar3;
      }
    }
    local_8 = param_1 + 1 + param_3;
    iVar4 = param_2 + 1 + param_3;
    iVar6 = (param_2 - param_3) + -1;
    iVar5 = (param_1 - param_3) + -1;
    if (-1 < (int)((iVar4 - DAT_00a381a0) - 1U & (local_8 - DAT_00a3819c) - 1U &
                   (DAT_00a38198 - iVar6) - 1U & (DAT_00a38194 - iVar5) - 1U)) {
      if (iVar5 < DAT_00a38194) {
        iVar5 = DAT_00a38194;
      }
      if (local_8 < DAT_00a38194) {
        local_8 = DAT_00a38194;
      }
      if (DAT_00a3819c < iVar5) {
        iVar5 = DAT_00a3819c;
      }
      if (DAT_00a3819c < local_8) {
        local_8 = DAT_00a3819c;
      }
      if (iVar6 < DAT_00a38198) {
        iVar6 = DAT_00a38198;
      }
      if (iVar4 < DAT_00a38198) {
        iVar4 = DAT_00a38198;
      }
      if (DAT_00a381a0 < iVar6) {
        iVar6 = DAT_00a381a0;
      }
      if (DAT_00a381a0 < iVar4) {
        iVar4 = DAT_00a381a0;
      }
    }
    if (DAT_00ca39f4 != 0) {
      FUN_0057b170(iVar5,iVar6,local_8,iVar4);
    }
    if (bVar1) {
      FUN_00519580();
      uVar3 = FUN_00569090(param_1,param_2,param_3,param_4,param_5,0,0);
      FUN_00519650();
    }
    else if (iVar2 == 0) {
      uVar3 = FUN_005156a0(param_1,param_2,param_3,param_4);
    }
    else {
      uVar3 = FUN_00569090(param_1,param_2,param_3,param_4,param_5,0,0);
    }
    if (DAT_00ca39f4 == 0) {
      return uVar3;
    }
  }
  else {
    if (((DAT_00a380cc == 3) && (DAT_00a37d8c == 0)) && (iVar2 != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
      if (DAT_00ca39f4 == 0) {
        if (iVar2 == 0) {
          uVar3 = FUN_0051d2c0(param_1,param_2,param_3,param_4,param_6);
          return uVar3;
        }
        uVar3 = FUN_00569050();
        return uVar3;
      }
    }
    local_8 = param_1 + 1 + param_3;
    iVar4 = param_2 + 1 + param_3;
    iVar6 = (param_2 - param_3) + -1;
    iVar5 = (param_1 - param_3) + -1;
    if (-1 < (int)((iVar4 - DAT_00a381a0) - 1U & (local_8 - DAT_00a3819c) - 1U &
                   (DAT_00a38198 - iVar6) - 1U & (DAT_00a38194 - iVar5) - 1U)) {
      if (iVar5 < DAT_00a38194) {
        iVar5 = DAT_00a38194;
      }
      if (local_8 < DAT_00a38194) {
        local_8 = DAT_00a38194;
      }
      if (DAT_00a3819c < iVar5) {
        iVar5 = DAT_00a3819c;
      }
      if (DAT_00a3819c < local_8) {
        local_8 = DAT_00a3819c;
      }
      if (iVar6 < DAT_00a38198) {
        iVar6 = DAT_00a38198;
      }
      if (iVar4 < DAT_00a38198) {
        iVar4 = DAT_00a38198;
      }
      if (DAT_00a381a0 < iVar6) {
        iVar6 = DAT_00a381a0;
      }
      if (DAT_00a381a0 < iVar4) {
        iVar4 = DAT_00a381a0;
      }
    }
    if (DAT_00ca39f4 != 0) {
      FUN_0057b170(iVar5,iVar6,local_8,iVar4);
    }
    if (bVar1) {
      FUN_00519580();
      uVar3 = FUN_00569050(param_1,param_2,param_3,param_4,param_6);
      FUN_00519650();
    }
    else if (iVar2 == 0) {
      uVar3 = FUN_0051d2c0(param_1,param_2,param_3,param_4,param_6);
    }
    else {
      uVar3 = FUN_00569050(param_1,param_2,param_3,param_4,param_6);
    }
    if (DAT_00ca39f4 == 0) {
      return uVar3;
    }
  }
  FUN_0057ae10(iVar5,iVar6,local_8,iVar4);
  return uVar3;
}

