
/* WARNING: Removing unreachable block (ram,0x00418c65) */

undefined4 __thiscall FUN_00418a30(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined1 local_7c [4];
  undefined1 local_78 [4];
  undefined1 local_74 [80];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007abb93;
  local_10 = ExceptionList;
  local_20 = 0;
  ExceptionList = &local_10;
  while (iVar1 = FUN_004cf550(), local_20 < iVar1) {
    iVar1 = FUN_004cf590(local_20);
    if ((*(int *)(iVar1 + 0x20) == param_2) &&
       (iVar1 = FUN_004cf590(local_20), *(int *)(iVar1 + 0x24) == param_3)) {
      ExceptionList = local_10;
      return 2;
    }
    local_20 = local_20 + 1;
  }
  if ((param_2 < *(int *)(param_1 + 0x1420)) && (param_3 < *(int *)(param_1 + 0x1424))) {
    local_18 = 0;
    local_14 = -1;
    local_1c = 0;
    local_24 = 0;
    while (iVar1 = FUN_004cf550(), local_24 < iVar1) {
      piVar3 = (int *)FUN_004cf5e0(local_24);
      if (*piVar3 != local_14 + 1) {
        local_1c = local_24;
        local_18 = local_14 + 1;
        break;
      }
      piVar3 = (int *)FUN_004cf5e0(local_24);
      local_14 = *piVar3;
      local_1c = local_24 + 1;
      piVar3 = (int *)FUN_004cf5e0(local_24);
      local_18 = *piVar3 + 1;
      local_24 = local_24 + 1;
    }
    if (local_18 < 0x1400) {
      uVar2 = FUN_0046cff0(local_18);
      local_8 = 0;
      puVar5 = local_78;
      iVar1 = local_1c;
      FUN_004ce060(local_74);
      puVar4 = (undefined4 *)FUN_004cf770(puVar5,iVar1);
      FUN_004cf690(local_7c,*puVar4,uVar2);
      local_8 = 0xffffffff;
      FUN_0046f510();
      iVar1 = FUN_004cf590(local_1c);
      *(int *)(iVar1 + 0x20) = param_2;
      iVar1 = FUN_004cf590(local_1c);
      *(int *)(iVar1 + 0x24) = param_3;
      *(int *)(param_1 + 0x1428) = *(int *)(param_1 + 0x1428) + 1;
      uVar2 = 1;
    }
    else {
      uVar2 = 3;
    }
  }
  else {
    uVar2 = 0;
  }
  ExceptionList = local_10;
  return uVar2;
}

