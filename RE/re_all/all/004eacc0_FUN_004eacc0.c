
void __thiscall FUN_004eacc0(void *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint local_1c;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1a40;
  pvStack_10 = ExceptionList;
  local_1c = param_2 | 7;
  ExceptionList = &pvStack_10;
  uVar1 = FID_conflict_max_size(param_1);
  if (uVar1 < local_1c) {
    local_1c = param_2;
  }
  else if (local_1c / 3 < *(uint *)((int)param_1 + 0x18) >> 1) {
    uVar1 = *(uint *)((int)param_1 + 0x18);
    uVar2 = FID_conflict_max_size(param_1);
    if (*(uint *)((int)param_1 + 0x18) <= uVar2 - (uVar1 >> 1)) {
      local_1c = (*(uint *)((int)param_1 + 0x18) >> 1) + *(int *)((int)param_1 + 0x18);
    }
  }
  local_8 = 0;
  allocate(local_1c + 1);
  FUN_004eadb0();
  return;
}

