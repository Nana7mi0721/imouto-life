
void FUN_004d28f0(undefined4 param_1)

{
  undefined1 auStack_500 [532];
  undefined4 uStack_2ec;
  undefined4 uStack_2e8;
  undefined1 auStack_2e4 [72];
  undefined4 uStack_29c;
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_290;
  undefined4 local_28c;
  undefined1 *local_284;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b112b;
  local_10 = ExceptionList;
  local_284 = auStack_2e4;
  uStack_2e8 = 0xffffffff;
  uStack_2ec = 0x4d2926;
  ExceptionList = &local_10;
  local_28c = FUN_0046cff0();
  uStack_2e8 = 0xffffffff;
  uStack_2ec = 0x4d2939;
  local_294 = FUN_00446ca0();
  local_8 = 0;
  local_14 = auStack_500;
  local_290 = local_294;
  local_298 = FUN_004d3fe0(local_294);
  FUN_004dc580(param_1);
  local_8 = 0xffffffff;
  uStack_29c = 0x4d2990;
  FUN_0047a350();
  ExceptionList = local_10;
  return;
}

