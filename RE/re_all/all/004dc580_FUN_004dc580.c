
void __thiscall FUN_004dc580(undefined4 param_1,uint param_2,undefined1 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007b14f8;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  uVar1 = FUN_004d29a0(param_1);
  if (uVar1 < param_2) {
    iVar2 = FUN_004d29a0(&param_3);
    iVar2 = param_2 - iVar2;
    puVar3 = (undefined4 *)FUN_004e38e0(local_14);
    FUN_004e6380(*puVar3,iVar2);
  }
  else {
    uVar1 = FUN_004d29a0(param_1);
    if (param_2 < uVar1) {
      puVar3 = (undefined4 *)FUN_004e38e0(local_18);
      uVar5 = *puVar3;
      puVar4 = local_20;
      FUN_004ce060(local_1c);
      puVar3 = (undefined4 *)FUN_004df2e0(puVar4,param_2);
      FUN_004e6310(local_24,*puVar3,uVar5);
    }
  }
  local_8 = 0xffffffff;
  FUN_0047a350();
  ExceptionList = local_10;
  return;
}

