
undefined4
FUN_00530810(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *local_40c;
  undefined1 local_400 [1024];
  
  puVar8 = (undefined1 *)0x0;
  local_40c = (undefined1 *)0x0;
  puVar7 = (undefined1 *)0x0;
  if (param_1 != 0) {
    if (DAT_00aba24c == 0) {
      FUN_0057a980();
    }
    iVar5 = FUN_005773c0(DAT_00aba24c,param_1);
    uVar1 = iVar5 + 0x10;
    if (uVar1 < 0x201) {
      puVar8 = local_400;
    }
    else {
      puVar8 = (undefined1 *)
               FUN_0056e030(uVar1 * 2,"..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",0x1ad5);
      if (puVar8 == (undefined1 *)0x0) {
        return 0xffffffff;
      }
      local_40c = puVar8;
    }
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    iVar3 = DAT_00aba250;
    if (DAT_00aba24c == 0) {
      FUN_0057a980();
    }
    iVar2 = DAT_00aba24c;
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    iVar4 = DAT_00aba250;
    FUN_005764b0(param_1,iVar5,iVar2,puVar8,uVar1 * 2,iVar3);
    thunk_FUN_00572ac0(iVar4);
    puVar7 = local_40c;
  }
  uVar6 = FUN_005307a0(puVar8,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if (puVar7 != (undefined1 *)0x0) {
    FUN_0056e1d0(puVar7);
  }
  return uVar6;
}

