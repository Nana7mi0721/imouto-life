
void FUN_0052ffb0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  param_1 = param_1 + 0x10;
  local_14 = 0;
  uVar1 = FUN_0057fba0(param_1,&local_14);
  uVar2 = FUN_0057fbc0(param_1,&local_14);
  uVar3 = FUN_0057fbe0(param_1,&local_14);
  local_8 = FUN_0057fbc0(param_1,&local_14);
  local_c = FUN_0057fbc0(param_1,&local_14);
  local_4 = FUN_0057fbc0(param_1,&local_14);
  local_10 = FUN_0057fbc0(param_1,&local_14);
  uVar4 = FUN_0057fbc0(param_1,&local_14);
  uVar5 = FUN_0057fbc0(param_1,&local_14);
  iVar6 = FUN_0052fdc0(uVar1,uVar2,uVar3,local_8,local_c,local_10,uVar4,uVar5,1);
  FUN_00580f70(uVar2);
  if (iVar6 < 0) {
    FUN_00580b80(uVar2);
  }
  return;
}

