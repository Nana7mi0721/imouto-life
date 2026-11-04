
int __fastcall FUN_004bd390(int param_1)

{
  float10 fVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0a24;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004bd740();
  local_8 = 0;
  FUN_004bd4a0();
  local_8._0_1_ = 1;
  FUN_004bd590();
  local_8 = CONCAT31(local_8._1_3_,2);
  *(undefined4 *)(param_1 + 0xa470) = 0xffffffff;
  fVar1 = (float10)FUN_004bd490();
  *(float *)(param_1 + 0xa46c) = (float)fVar1;
  *(undefined4 *)(param_1 + 0xa478) = 0x10;
  *(undefined4 *)(param_1 + 0xa47c) = 0x10;
  *(undefined4 *)(param_1 + 0xa480) = 0x31;
  *(undefined4 *)(param_1 + 0xa48c) = 0x10;
  *(undefined4 *)(param_1 + 0xa488) = 0x10;
  *(undefined4 *)(param_1 + 0xa484) = 0x10;
  DAT_00a0f848 = param_1 + 0xa2c8;
  DAT_00a0f810 = param_1 + 0xa030;
  ExceptionList = local_10;
  return param_1;
}

