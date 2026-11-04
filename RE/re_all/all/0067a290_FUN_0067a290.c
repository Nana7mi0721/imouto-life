
void FUN_0067a290(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  FUN_00677850(param_1,param_2,param_3,0);
  if (*(int *)(param_1 + 0x120) != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x124);
    *(int *)(param_1 + 0x124) = *(int *)(param_1 + 0x120);
    *(undefined4 *)(param_1 + 0x120) = uVar1;
  }
  FUN_00679300(param_1);
  uVar2 = *(int *)(param_1 + 0x184) + 1;
  *(uint *)(param_1 + 0x184) = uVar2;
  if ((*(uint *)(param_1 + 0x180) != 0) && (*(uint *)(param_1 + 0x180) <= uVar2)) {
    FUN_00671c40(param_1);
  }
  return;
}

