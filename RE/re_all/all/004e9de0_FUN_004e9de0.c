
undefined4 FUN_004e9de0(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined1 auStackY_cc [128];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b19e0;
  pvStack_10 = ExceptionList;
  local_14 = auStackY_cc + 0x88;
  ExceptionList = &pvStack_10;
  local_1c = FUN_004eb880(1);
  local_18 = 0;
  local_8 = 0;
  local_20 = 0;
  uVar1 = FUN_004e8ab0(local_1c);
  FUN_004f6f20(uVar1,&local_20);
  local_18 = local_18 + 1;
  local_24 = 0;
  uVar1 = FUN_004d6870(local_1c);
  FUN_004f6f20(uVar1,&local_24);
  local_18 = local_18 + 1;
  local_28 = 0;
  uVar1 = FUN_004d6880(local_1c);
  FUN_004f6f20(uVar1,&local_28);
  local_8 = 0xffffffff;
  puVar2 = (undefined1 *)FUN_004e9b50(local_1c);
  *puVar2 = 1;
  puVar2 = (undefined1 *)FUN_004e06d0(local_1c);
  *puVar2 = 0;
  ExceptionList = pvStack_10;
  return local_1c;
}

