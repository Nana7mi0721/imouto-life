
undefined4
FUN_00530c20(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 local_400 [1024];
  
  puVar6 = (undefined1 *)0x0;
  if (param_1 == -2) {
    FUN_00530d80();
    param_1 = DAT_00a4bca8;
  }
  iVar3 = FUN_0052f1d0(param_1);
  if (iVar3 < 0) {
    return 0xffffffff;
  }
  uVar4 = FUN_005773c0(iVar3,param_2);
  if (uVar4 < 0x1f9) {
    puVar7 = local_400;
  }
  else {
    puVar6 = (undefined1 *)
             FUN_0056e030(uVar4 * 2 + 0x20,"..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",
                          0x1c13);
    if (puVar6 == (undefined1 *)0x0) {
      return 0xffffffff;
    }
    puVar7 = puVar6;
  }
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar1 = DAT_00aba250;
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar2 = DAT_00aba250;
  FUN_005764b0(param_2,0xffffffff,iVar3,puVar7,uVar4 * 2 + 0x20,iVar1);
  thunk_FUN_00572ac0(iVar2);
  uVar5 = FUN_00530ac0(param_1,puVar7,param_3,param_4,param_5,param_6);
  if (puVar6 != (undefined1 *)0x0) {
    FUN_0056e1d0(puVar6);
  }
  return uVar5;
}

