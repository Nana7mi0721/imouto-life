
void FUN_0055d830(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  param_1 = param_1 + 0x10;
  local_10 = 0;
  uVar1 = FUN_0057fbc0(param_1,&local_10);
  uVar2 = FUN_0057fbc0(param_1,&local_10);
  uVar3 = FUN_0057fbc0(param_1,&local_10);
  local_4 = FUN_0057fbc0(param_1,&local_10);
  local_8 = FUN_0057fbc0(param_1,&local_10);
  local_c = FUN_0057fbc0(param_1,&local_10);
  uVar4 = FUN_0057fbc0(param_1,&local_10);
  FUN_0057fbc0(param_1,&local_10);
  iVar5 = FUN_0055d770(uVar2,uVar3,local_4,local_8,local_c,uVar4);
  FUN_00580f70(uVar1);
  if (iVar5 < 0) {
    FUN_00580b80(uVar1);
  }
  return;
}

