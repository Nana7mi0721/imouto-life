
int __thiscall FUN_00418dc0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = 0xffffffff;
  local_14 = FUN_0046f600(param_2);
  if (local_14 == -1) {
    local_10 = 0;
  }
  else {
    local_10 = 0;
    local_8 = -1;
    local_18 = 0;
    local_1c = 0;
    local_c = local_14;
    while( true ) {
      iVar1 = FUN_004cf550();
      if (iVar1 <= local_1c) break;
      piVar2 = (int *)FUN_004cf5e0(local_1c);
      if (*piVar2 != local_8 + 1) {
        local_18 = local_1c;
        local_10 = local_8 + 1;
        break;
      }
      piVar2 = (int *)FUN_004cf5e0(local_1c);
      local_8 = *piVar2;
      local_18 = local_1c + 1;
      piVar2 = (int *)FUN_004cf5e0(local_1c);
      local_10 = *piVar2 + 1;
      local_1c = local_1c + 1;
    }
    uVar3 = FUN_004cf590(local_14);
    puVar5 = local_24;
    iVar1 = local_18;
    FUN_004ce060(local_20);
    puVar4 = (undefined4 *)FUN_004cf770(puVar5,iVar1);
    FUN_004cf690(local_28,*puVar4,uVar3);
    iVar1 = FUN_004cf5e0(local_18);
    *(undefined4 *)(iVar1 + 0x20) = param_3;
    iVar1 = FUN_004cf5e0(local_18);
    *(undefined4 *)(iVar1 + 0x24) = param_4;
    iVar1 = local_10;
    FUN_004cf590(local_18);
    FUN_0046f660(iVar1);
    *(int *)(param_1 + 0x1428) = *(int *)(param_1 + 0x1428) + 1;
  }
  return local_10;
}

