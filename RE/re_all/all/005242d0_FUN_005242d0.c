
void FUN_005242d0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  undefined4 local_4;
  
  param_1 = param_1 + 0x10;
  local_10 = 0;
  uVar1 = FUN_0057fba0(param_1,&local_10);
  uVar2 = FUN_0057fbc0(param_1,&local_10);
  uVar3 = FUN_0057fbc0(param_1,&local_10);
  local_4 = FUN_0057fbc0(param_1,&local_10);
  local_8 = FUN_0057fbc0(param_1,&local_10);
  local_c = FUN_0057fbc0(param_1,&local_10);
  uVar4 = FUN_0057fbc0(param_1,&local_10);
  uVar5 = FUN_0057fbc0(param_1,&local_10);
  iVar6 = FUN_00522dc0(uVar1,uVar2,uVar3,local_4,local_8 == 0,uVar5,local_c,uVar4,0,0xffffffff,1);
  FUN_00580f70(uVar2);
  if ((int)((iVar6 != -1) - 1) < 0) {
    FUN_00580b80(uVar2);
  }
  return;
}

