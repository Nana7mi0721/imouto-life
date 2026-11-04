
undefined4
FUN_005406b0(undefined4 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined4 param_8,int param_9,
            undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 *local_44c;
  undefined1 local_440 [1084];
  
  local_44c = (undefined1 *)0x0;
  if (param_9 == -2) {
    FUN_00530d80();
    param_9 = DAT_00a4bca8;
  }
  iVar1 = FUN_0052f1d0(param_9);
  if (iVar1 < 0) {
    return 0xffffffff;
  }
  uVar2 = FUN_005773c0(iVar1,param_12);
  if (uVar2 < 0x1f9) {
    puVar3 = local_440;
  }
  else {
    puVar3 = (undefined1 *)
             FUN_0056e030(uVar2 * 2 + 0x20,"..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",
                          0x3868);
    if (puVar3 == (undefined1 *)0x0) {
      return 0xffffffff;
    }
    local_44c = puVar3;
  }
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar4 = DAT_00aba250;
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar4 = FUN_005764b0(param_12,0xffffffff,iVar1,puVar3,uVar2 * 2 + 0x20,iVar4);
  iVar1 = thunk_FUN_00572ac0();
  iVar4 = iVar4 / iVar1;
  if (iVar4 != 0) {
    iVar4 = iVar4 + -1;
  }
  uVar5 = FUN_00540020(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10,param_11,puVar3,iVar4);
  if (local_44c != (undefined1 *)0x0) {
    FUN_0056e1d0(local_44c);
  }
  return uVar5;
}

