
void __thiscall FUN_004dacd0(undefined4 param_1,uint param_2,undefined1 param_3)

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
  
  puStack_c = &LAB_007b1418;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  uVar1 = FUN_004d0530(param_1);
  if (uVar1 < param_2) {
    puVar4 = &param_3;
    iVar2 = FUN_004d0530(puVar4);
    iVar2 = param_2 - iVar2;
    puVar3 = (undefined4 *)FUN_004e38e0(local_14);
    FUN_004daed0(*puVar3,iVar2,puVar4);
  }
  else {
    uVar1 = FUN_004d0530(param_1);
    if (param_2 < uVar1) {
      puVar3 = (undefined4 *)FUN_004e38e0(local_18);
      uVar5 = *puVar3;
      puVar4 = local_20;
      FUN_004ce060(local_1c);
      puVar3 = (undefined4 *)FUN_004d0720(puVar4,param_2);
      FUN_004e4b10(local_24,*puVar3,uVar5);
    }
  }
  local_8 = 0xffffffff;
  FUN_004ada90();
  ExceptionList = local_10;
  return;
}

