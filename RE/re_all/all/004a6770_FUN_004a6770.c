
undefined1 * __fastcall FUN_004a6770(undefined1 *param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007afc66;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004cf7a0();
  local_8 = 0;
  FUN_004ce850();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004cd870();
  FUN_004ce950();
  *param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  uVar1 = FUN_004174a0(1,0);
  FUN_004a6820(uVar1);
  *(undefined4 *)(param_1 + 0x30) = 0;
  ExceptionList = local_10;
  return param_1;
}

