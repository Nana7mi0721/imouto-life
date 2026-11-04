
undefined4
FUN_00563eb0(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  uVar2 = FUN_00516960();
  FUN_00516940(0);
  param_4 = param_4 - param_2;
  param_3 = param_3 - param_1;
  FUN_005162d0(&local_10);
  if (param_1 < local_10) {
    param_1 = local_10;
  }
  if (param_2 < local_c) {
    param_2 = local_c;
  }
  if (local_8 < param_1) {
    do {
      param_2 = param_2 + param_5;
      param_1 = param_1 + (local_10 - local_8);
    } while (local_8 < param_1);
  }
  FUN_00526390(param_1,param_2,param_1 + param_3,param_4 + param_2,param_6,param_7);
  local_20 = param_1;
  local_1c = param_2;
  local_18 = param_1 + param_3;
  local_14 = param_2 + param_5;
  FUN_00514e10(&local_20,&local_10);
  iVar5 = (local_20 - local_18) + param_3;
  if (0 < iVar5) {
    iVar3 = param_2 + param_5;
    do {
      iVar4 = (iVar5 - param_3) + local_10;
      iVar1 = param_5 + iVar3;
      FUN_00526390(iVar4,iVar3,iVar4 + param_3,(param_4 - param_5) + iVar1,param_6,param_7);
      local_20 = iVar4;
      local_1c = iVar3;
      local_18 = iVar4 + param_3;
      local_14 = iVar1;
      FUN_00514e10(&local_20,&local_10);
      iVar5 = iVar5 + (local_20 - local_18);
      iVar3 = iVar1;
    } while (0 < iVar5);
  }
  FUN_00516940(uVar2);
  return 0;
}

