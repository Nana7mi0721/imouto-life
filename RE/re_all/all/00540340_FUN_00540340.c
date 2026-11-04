
undefined4
FUN_00540340(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            ,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 *local_408;
  undefined1 local_400 [1024];
  
  local_408 = (undefined1 *)0x0;
  if (param_5 == -2) {
    FUN_00530d80();
    param_5 = DAT_00a4bca8;
  }
  iVar2 = FUN_0052f1d0(param_5);
  if (iVar2 < 0) {
    return 0xffffffff;
  }
  uVar3 = FUN_005773c0(iVar2,param_3);
  if (uVar3 < 0x1f9) {
    puVar4 = local_400;
  }
  else {
    puVar4 = (undefined1 *)
             FUN_0056e030(uVar3 * 2 + 0x20,"..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",
                          0x351c);
    if (puVar4 == (undefined1 *)0x0) {
      return 0xffffffff;
    }
    local_408 = puVar4;
  }
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar5 = DAT_00aba250;
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar1 = DAT_00aba250;
  iVar5 = FUN_005764b0(param_3,0xffffffff,iVar2,puVar4,uVar3 * 2 + 0x20,iVar5);
  iVar2 = thunk_FUN_00572ac0(iVar1);
  iVar5 = iVar5 / iVar2;
  if (iVar5 != 0) {
    iVar5 = iVar5 + -1;
  }
  uVar6 = FUN_0053f880(param_1,param_2,puVar4,iVar5,param_4,param_5,param_6,param_7);
  if (local_408 != (undefined1 *)0x0) {
    FUN_0056e1d0(local_408);
  }
  return uVar6;
}

