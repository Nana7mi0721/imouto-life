
undefined4 FUN_0051d7b0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
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
        uVar3 = FUN_00515640(param_4,param_5);
        return uVar3;
      }
      uVar3 = FUN_00568ff0(param_1,param_2,param_3,param_4,param_5);
      return uVar3;
    }
  }
  local_10 = param_1;
  local_c = param_2;
  local_8 = param_3;
  local_4 = param_4;
  if (-1 < (int)((param_4 - DAT_00a381a0) - 1U & (param_3 - DAT_00a3819c) - 1U &
                 (DAT_00a38198 - param_2) - 1U & (DAT_00a38194 - param_1) - 1U)) {
    if (param_1 < DAT_00a38194) {
      local_10 = DAT_00a38194;
    }
    if (param_3 < DAT_00a38194) {
      local_8 = DAT_00a38194;
    }
    if (DAT_00a3819c < local_10) {
      local_10 = DAT_00a3819c;
    }
    if (DAT_00a3819c < local_8) {
      local_8 = DAT_00a3819c;
    }
    if (param_2 < DAT_00a38198) {
      local_c = DAT_00a38198;
    }
    if (param_4 < DAT_00a38198) {
      local_4 = DAT_00a38198;
    }
    if (DAT_00a381a0 < local_c) {
      local_c = DAT_00a381a0;
    }
    if (DAT_00a381a0 < local_4) {
      local_4 = DAT_00a381a0;
    }
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057b170(local_10,local_c,local_8,local_4);
  }
  if (bVar1) {
    FUN_00519580();
    uVar3 = FUN_00568ff0(param_1,param_2,param_3,param_4,param_5);
    FUN_00519650();
  }
  else if (iVar2 == 0) {
    uVar3 = FUN_00515640(param_4,param_5);
  }
  else {
    uVar3 = FUN_00568ff0(param_1,param_2,param_3,param_4,param_5);
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057ae10(local_10,local_c,local_8,local_4);
  }
  return uVar3;
}

