
undefined4
FUN_0054f180(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 local_a0 [160];
  
  local_a4 = 0;
  local_a8 = 0;
  FUN_00540930(local_a0,0);
  iVar3 = FUN_0054ee60(local_a0,param_1,param_2,param_3,param_4,1,0,0,&local_a8,&local_a4);
  uVar2 = local_a4;
  uVar1 = local_a8;
  if (iVar3 == -1) {
    return 0;
  }
  uVar4 = FUN_005448b0(local_a8,local_a4,param_5,param_6);
  FUN_0056e1d0(uVar2);
  FUN_0056e1d0(uVar1);
  return uVar4;
}

