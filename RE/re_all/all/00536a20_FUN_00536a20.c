
undefined4 FUN_00536a20(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 local_200 [512];
  
  puVar5 = (undefined1 *)0x0;
  iVar2 = FUN_0056d0a0(param_1);
  if (iVar2 * 2 < 0x100) {
    puVar3 = local_200;
  }
  else {
    puVar3 = (undefined1 *)
             FUN_0056e030(iVar2 * 4 + 2,"..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",0x1d7d);
    if (puVar3 == (undefined1 *)0x0) {
      return 0xffffffff;
    }
    puVar5 = puVar3;
  }
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar1 = DAT_00aba250;
  if (DAT_00aba24c == 0) {
    FUN_0057a980();
  }
  FUN_005764b0(param_1,iVar2,DAT_00aba24c,puVar3,iVar2 * 4 + 2,iVar1);
  uVar4 = FUN_005369c0(puVar3,param_2);
  if (puVar5 != (undefined1 *)0x0) {
    FUN_0056e1d0(puVar5);
  }
  return uVar4;
}

