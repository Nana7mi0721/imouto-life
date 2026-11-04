
undefined4 FUN_0056ba10(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *local_408;
  undefined1 local_400 [1024];
  
  puVar6 = (undefined1 *)0x0;
  local_408 = (undefined1 *)0x0;
  puVar7 = (undefined1 *)0x0;
  if (param_1 != 0) {
    iVar4 = FUN_005773c0(0x3a4,param_1);
    uVar1 = iVar4 + 0x10;
    if (uVar1 < 0x201) {
      puVar6 = local_400;
    }
    else {
      puVar6 = (undefined1 *)
               FUN_0056e030(uVar1 * 2,"..\\..\\..\\..\\Source\\Library\\Main\\DxLog.cpp",0x130);
      if (puVar6 == (undefined1 *)0x0) {
        return 0xffffffff;
      }
      local_408 = puVar6;
    }
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    iVar2 = DAT_00aba250;
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    iVar3 = DAT_00aba250;
    FUN_005764b0(param_1,iVar4,0x3a4,puVar6,uVar1 * 2,iVar2);
    thunk_FUN_00572ac0(iVar3);
    puVar7 = local_408;
  }
  uVar5 = FUN_0056b830(0,puVar6);
  if (puVar7 != (undefined1 *)0x0) {
    FUN_0056e1d0(puVar7);
  }
  return uVar5;
}

