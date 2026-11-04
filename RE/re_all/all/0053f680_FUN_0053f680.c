
undefined4 FUN_0053f680(undefined1 *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  undefined1 *local_610;
  int local_60c;
  undefined1 local_600 [512];
  undefined1 local_400 [1024];
  
  local_610 = (undefined1 *)0x0;
  if (param_3 == -2) {
    FUN_00530d80();
    param_3 = DAT_00a4bca8;
  }
  if (param_2 < 0) {
    puVar2 = param_1;
  }
  else {
    iVar3 = FUN_0052f1d0(param_3);
    if (iVar3 < 0) {
      return 0xffffffff;
    }
    iVar1 = thunk_FUN_00572ac0(iVar3);
    iVar3 = FUN_005773c0(iVar3,param_1);
    if (iVar3 < param_2) {
      param_2 = iVar3;
    }
    iVar3 = iVar1 * param_2;
    if (iVar3 + 0x10U < 0x200) {
      puVar2 = local_600;
    }
    else {
      puVar2 = (undefined1 *)
               FUN_0056e030(iVar3 + 0x10U,"..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",0x3177
                           );
      if (puVar2 == (undefined1 *)0x0) {
        return 0xffffffff;
      }
      local_610 = puVar2;
    }
    FUN_0056d420(puVar2,param_1,iVar3);
    FUN_0056d380(puVar2 + iVar3,0,iVar1 * 8);
  }
  puVar7 = (undefined1 *)0x0;
  if (param_3 == -2) {
    FUN_00530d80();
    param_3 = DAT_00a4bca8;
  }
  iVar3 = FUN_0052f1d0(param_3);
  if (iVar3 < 0) {
    return 0xffffffff;
  }
  uVar4 = FUN_005773c0(iVar3,puVar2);
  if (uVar4 < 0x1f9) {
    puVar5 = local_400;
  }
  else {
    puVar5 = (undefined1 *)
             FUN_0056e030(uVar4 * 2 + 0x20,"..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",
                          0x3177);
    if (puVar5 == (undefined1 *)0x0) {
      return 0xffffffff;
    }
    puVar7 = puVar5;
  }
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar1 = DAT_00aba250;
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
    local_60c = DAT_00aba250;
  }
  else {
    local_60c = DAT_00aba250;
  }
  DAT_00aba250 = local_60c;
  FUN_005764b0(puVar2,0xffffffff,iVar3,puVar5,uVar4 * 2 + 0x20,iVar1);
  thunk_FUN_00572ac0(local_60c);
  uVar6 = FUN_0053e560(puVar5,param_2,param_3,param_4);
  if (puVar7 != (undefined1 *)0x0) {
    FUN_0056e1d0(puVar7);
  }
  if (local_610 != (undefined1 *)0x0) {
    FUN_0056e1d0(local_610);
  }
  return uVar6;
}

