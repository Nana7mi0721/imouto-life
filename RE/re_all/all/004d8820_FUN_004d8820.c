
void __thiscall FUN_004d8820(undefined4 param_1,uint param_2,undefined1 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  uVar1 = FUN_004ce080(param_1);
  if (uVar1 < param_2) {
    puVar4 = &param_3;
    iVar2 = FUN_004ce080(puVar4);
    iVar2 = param_2 - iVar2;
    puVar3 = (undefined4 *)FUN_004e38e0(local_8);
    FUN_004e2e60(*puVar3,iVar2,puVar4);
  }
  else {
    uVar1 = FUN_004ce080(param_1);
    if (param_2 < uVar1) {
      puVar3 = (undefined4 *)FUN_004e38e0(local_c);
      uVar5 = *puVar3;
      puVar4 = local_14;
      FUN_004ce060(local_10);
      puVar3 = (undefined4 *)iterator__operator_(puVar4,param_2);
      FUN_004e2df0(local_18,*puVar3,uVar5);
    }
  }
  return;
}

