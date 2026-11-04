
void FUN_00562d70(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  param_1 = param_1 + 0x10;
  local_c = 0;
  FUN_0057fba0(param_1,&local_c);
  local_4 = FUN_0057fbc0(param_1,&local_c);
  uVar1 = FUN_0057fbc0(param_1,&local_c);
  uVar2 = FUN_0057fbc0(param_1,&local_c);
  local_8 = FUN_0057fbc0(param_1,&local_c);
  uVar3 = FUN_0057fbc0(param_1,&local_c);
  uVar4 = FUN_0057fbc0(param_1,&local_c);
  iVar5 = FUN_00562880(uVar1,uVar2,local_8,uVar3,uVar4,1);
  FUN_00580f70(uVar1);
  if ((iVar5 < 0) && (local_4 != 0)) {
    FUN_00580b80(uVar1);
  }
  return;
}

