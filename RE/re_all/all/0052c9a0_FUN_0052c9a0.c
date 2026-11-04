
undefined8 FUN_0052c9a0(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  undefined1 *local_40c;
  undefined1 local_400 [1024];
  
  puVar7 = (undefined1 *)0x0;
  local_40c = (undefined1 *)0x0;
  puVar6 = (undefined1 *)0x0;
  if (param_1 != 0) {
    if (DAT_00aba24c == 0) {
      FUN_0057a980();
    }
    iVar5 = FUN_005773c0(DAT_00aba24c,param_1);
    uVar1 = iVar5 + 0x10;
    if (uVar1 < 0x201) {
      puVar7 = local_400;
    }
    else {
      puVar7 = (undefined1 *)
               FUN_0056e030(uVar1 * 2,"..\\..\\..\\..\\Source\\Library\\Main\\DxFile.cpp",0x3d5);
      if (puVar7 == (undefined1 *)0x0) {
        return 0xffffffffffffffff;
      }
      local_40c = puVar7;
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
    FUN_005764b0(param_1,iVar5,iVar2,puVar7,uVar1 * 2,iVar3);
    thunk_FUN_00572ac0(iVar4);
    puVar6 = local_40c;
  }
  iVar5 = (*(code *)PTR_FUN_0084c9d0)(puVar7,0,1,0);
  if (puVar6 != (undefined1 *)0x0) {
    FUN_0056e1d0(puVar6);
  }
  if (iVar5 == 0) {
    return 0xffffffffffffffff;
  }
  (*(code *)PTR_FUN_0084c9dc)(iVar5,0,0,2);
  uVar8 = (*(code *)PTR_FUN_0084c9d8)(iVar5);
  (*(code *)PTR_FUN_0084c9d4)(iVar5);
  return uVar8;
}

