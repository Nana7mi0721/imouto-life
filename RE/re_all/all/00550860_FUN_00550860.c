
undefined4 FUN_00550860(int param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  undefined1 local_400 [1024];
  
  puVar7 = (undefined1 *)0x0;
  if (param_1 != 0) {
    iVar5 = FUN_005773c0(0x4b0,param_1);
    uVar1 = iVar5 + 0x10;
    if (uVar1 < 0x201) {
      puVar7 = local_400;
    }
    else {
      puVar7 = (undefined1 *)
               FUN_0056e030(uVar1 * 2,
                            "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxSystemWin.cpp",0x361)
      ;
      if (puVar7 == (undefined1 *)0x0) {
        return 0xffffffff;
      }
    }
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    iVar3 = DAT_00aba250;
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    iVar4 = DAT_00aba250;
    FUN_005764b0(param_1,iVar5,0x4b0,puVar7,uVar1 * 2,iVar3);
    thunk_FUN_00572ac0(iVar4);
  }
  FUN_005507e0(puVar7);
  pcVar2 = (code *)swi(3);
  uVar6 = (*pcVar2)();
  return uVar6;
}

