
undefined4
FUN_00540540(undefined4 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
            undefined4 param_5,undefined4 param_6,int param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 *local_408;
  undefined1 local_400 [1024];
  
  local_408 = (undefined1 *)0x0;
  if (param_7 == -2) {
    FUN_00530d80();
    param_7 = DAT_00a4bca8;
  }
  iVar1 = FUN_0052f1d0(param_7);
  if (iVar1 < 0) {
    return 0xffffffff;
  }
  uVar2 = FUN_005773c0(iVar1,param_5);
  if (uVar2 < 0x1f9) {
    puVar3 = local_400;
  }
  else {
    puVar3 = (undefined1 *)
             FUN_0056e030(uVar2 * 2 + 0x20,"..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",
                          0x3739);
    if (puVar3 == (undefined1 *)0x0) {
      return 0xffffffff;
    }
    local_408 = puVar3;
  }
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar4 = DAT_00aba250;
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar4 = FUN_005764b0(param_5,0xffffffff,iVar1,puVar3,uVar2 * 2 + 0x20,iVar4);
  iVar1 = thunk_FUN_00572ac0();
  iVar4 = iVar4 / iVar1;
  if (iVar4 != 0) {
    iVar4 = iVar4 + -1;
  }
  uVar5 = FUN_0053fc40(param_1,param_2,param_3,param_4,puVar3,iVar4,param_6,param_7,param_8,param_9)
  ;
  if (local_408 != (undefined1 *)0x0) {
    FUN_0056e1d0(local_408);
  }
  return uVar5;
}

