
int __thiscall FUN_00418f50(int param_1,undefined1 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 in_stack_00000050;
  undefined4 in_stack_00000054;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007abba5;
  local_10 = ExceptionList;
  local_8 = 0;
  local_18 = 0;
  local_14 = -1;
  local_1c = 0;
  local_20 = 0;
  ExceptionList = &local_10;
  do {
    iVar1 = FUN_004cf550();
    if (iVar1 <= local_20) {
LAB_0041901b:
      puVar5 = &param_2;
      puVar4 = local_28;
      iVar1 = local_1c;
      FUN_004ce060(local_24);
      puVar3 = (undefined4 *)FUN_004cf770(puVar4,iVar1);
      FUN_004cf690(local_2c,*puVar3,puVar5);
      iVar1 = FUN_004cf5e0(local_1c);
      *(undefined4 *)(iVar1 + 0x20) = in_stack_00000050;
      iVar1 = FUN_004cf5e0(local_1c);
      *(undefined4 *)(iVar1 + 0x24) = in_stack_00000054;
      iVar1 = local_18;
      FUN_004cf590(local_1c);
      FUN_0046f660(iVar1);
      iVar1 = local_18;
      *(int *)(param_1 + 0x1428) = *(int *)(param_1 + 0x1428) + 1;
      local_8 = 0xffffffff;
      FUN_0046f510();
      ExceptionList = local_10;
      return iVar1;
    }
    piVar2 = (int *)FUN_004cf5e0(local_20);
    if (*piVar2 != local_14 + 1) {
      local_1c = local_20;
      local_18 = local_14 + 1;
      goto LAB_0041901b;
    }
    piVar2 = (int *)FUN_004cf5e0(local_20);
    local_14 = *piVar2;
    local_1c = local_20 + 1;
    piVar2 = (int *)FUN_004cf5e0(local_20);
    local_18 = *piVar2 + 1;
    local_20 = local_20 + 1;
  } while( true );
}

