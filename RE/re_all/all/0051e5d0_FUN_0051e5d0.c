
undefined4
FUN_0051e5d0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            undefined4 param_7,undefined4 param_8)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int local_18;
  int local_10;
  
  iVar2 = DAT_00a37d78;
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
        uVar3 = FUN_0051d550(param_1,param_2,param_3,param_8);
        return uVar3;
      }
      uVar3 = FUN_005690d0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
      return uVar3;
    }
  }
  local_18 = 0;
  iVar4 = 0;
  if (0 < param_1) {
    iVar4 = param_1;
  }
  if (0 < param_2) {
    local_18 = param_2;
  }
  local_10 = 0xffffff;
  if (param_1 < 0xffffff) {
    local_10 = param_1;
  }
  iVar5 = 0xffffff;
  if (param_2 < 0xffffff) {
    iVar5 = param_2;
  }
  if (iVar4 < param_3) {
    iVar4 = param_3;
  }
  if (local_18 < param_4) {
    local_18 = param_4;
  }
  if (param_3 < local_10) {
    local_10 = param_3;
  }
  if (param_4 < iVar5) {
    iVar5 = param_4;
  }
  if (iVar4 < param_5) {
    iVar4 = param_5;
  }
  if (local_18 < param_6) {
    local_18 = param_6;
  }
  if (param_5 < local_10) {
    local_10 = param_5;
  }
  if (param_6 < iVar5) {
    iVar5 = param_6;
  }
  if ((int)((local_18 - DAT_00a381a0) - 1U & (iVar4 - DAT_00a3819c) - 1U &
            (DAT_00a38198 - iVar5) - 1U & (DAT_00a38194 - local_10) - 1U) < 0) {
  }
  else {
    if (local_10 < DAT_00a38194) {
      local_10 = DAT_00a38194;
    }
    if (iVar4 < DAT_00a38194) {
      iVar4 = DAT_00a38194;
    }
    if (DAT_00a3819c < local_10) {
      local_10 = DAT_00a3819c;
    }
    if (DAT_00a3819c < iVar4) {
      iVar4 = DAT_00a3819c;
    }
    if (iVar5 < DAT_00a38198) {
      iVar5 = DAT_00a38198;
    }
    if (local_18 < DAT_00a38198) {
      local_18 = DAT_00a38198;
    }
    else {
    }
    if (DAT_00a381a0 < iVar5) {
      iVar5 = DAT_00a381a0;
    }
    if (DAT_00a381a0 < local_18) {
      local_18 = DAT_00a381a0;
    }
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057b170(local_10,iVar5,iVar4,local_18);
  }
  if (bVar1) {
    FUN_00519580();
    uVar3 = FUN_005690d0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    FUN_00519650();
  }
  else if (iVar2 == 0) {
    uVar3 = FUN_0051d550(param_1,param_2,param_3,param_8);
  }
  else {
    uVar3 = FUN_005690d0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057ae10(local_10,iVar5,iVar4,local_18);
  }
  return uVar3;
}

