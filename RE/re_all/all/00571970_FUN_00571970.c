
undefined4 FUN_00571970(undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  if ((param_1[8] == 1) && (param_1[9] != 0)) {
    iVar1 = FUN_00571330(param_1);
    while (iVar1 == 0) {
      FUN_0056da20(1);
      iVar1 = FUN_00571330(param_1);
    }
  }
  if (*(int *)*param_1 == 0) {
    uVar2 = *(uint *)(param_1[1] + 0x30);
    iVar1 = *(int *)(param_1[1] + 0x34);
  }
  else {
    uVar2 = *(uint *)(param_1[1] + 0x24);
    iVar1 = 0;
  }
  if (param_4 == 1) {
    bVar3 = CARRY4(param_2,param_1[6]);
    param_2 = param_2 + param_1[6];
    param_3 = param_3 + param_1[7] + (uint)bVar3;
  }
  else if (param_4 == 2) {
    bVar3 = CARRY4(param_2,uVar2);
    param_2 = param_2 + uVar2;
    param_3 = param_3 + iVar1 + (uint)bVar3;
  }
  if ((iVar1 <= param_3) && ((iVar1 < param_3 || (uVar2 < param_2)))) {
    param_2 = uVar2;
    param_3 = iVar1;
  }
  if ((param_3 < 1) && (param_3 < 0)) {
    param_2 = 0;
    param_3 = 0;
  }
  param_1[6] = param_2;
  param_1[7] = param_3;
  param_1[5] = 0;
  return 0;
}

