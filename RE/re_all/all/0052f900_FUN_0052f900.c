
int FUN_0052f900(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int param_6,undefined4 param_7)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  int local_414;
  int local_410;
  int local_40c;
  undefined1 *local_408;
  undefined1 local_400 [1024];
  
  local_40c = -1;
  local_408 = (undefined1 *)0x0;
  if (param_6 != 0) {
    if (DAT_00aba24c == 0) {
      FUN_0057a980();
    }
    iVar4 = FUN_005773c0(DAT_00aba24c,param_6);
    uVar1 = iVar4 + 0x10;
    if (uVar1 < 0x201) {
      puVar5 = local_400;
    }
    else {
      puVar5 = (undefined1 *)
               FUN_0056e030(uVar1 * 2,"..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",0x16d7);
      if (puVar5 == (undefined1 *)0x0) {
        return -1;
      }
      local_408 = puVar5;
    }
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    iVar6 = DAT_00aba250;
    if (DAT_00aba24c == 0) {
      FUN_0057a980();
    }
    iVar2 = DAT_00aba24c;
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    iVar3 = DAT_00aba250;
    iVar4 = FUN_005764b0(param_6,iVar4,iVar2,puVar5,uVar1 * 2,iVar6);
    iVar6 = thunk_FUN_00572ac0(iVar3);
    local_410 = iVar4 / iVar6;
    if (local_410 != 0) {
      local_410 = local_410 + -1;
    }
  }
  if (param_1 == 0) {
    local_414 = 0;
  }
  else {
    local_414 = FUN_0056e030(0x10000000,"..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",0x16db);
    if (local_414 == 0) goto LAB_0052fae3;
    FUN_0056d380(local_414,0,0x10000000);
  }
  local_40c = FUN_0052f840(param_2,param_3,param_5,param_7);
  if (((-1 < local_40c) && (param_1 != 0)) && (0 < local_40c)) {
    iVar4 = local_40c;
    iVar6 = local_414;
    do {
      if (DAT_00aba24c == 0) {
        FUN_0057a980();
      }
      iVar2 = DAT_00aba24c;
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      FUN_005764b0(iVar6,local_410,DAT_00aba250,param_1,0x40,iVar2);
      param_1 = param_1 + 0x40;
      iVar6 = iVar6 + 0x80;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
LAB_0052fae3:
  if (local_408 != (undefined1 *)0x0) {
    FUN_0056e1d0(local_408);
  }
  if (local_414 != 0) {
    FUN_0056e1d0(local_414);
  }
  return local_40c;
}

