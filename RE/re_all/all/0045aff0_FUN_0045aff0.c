
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0045aff0(void)

{
  undefined1 auStack_128 [20];
  undefined4 uStack_114;
  undefined *puStack_110;
  undefined1 auStack_10c [20];
  undefined4 uStack_f8;
  undefined1 *puStack_f4;
  undefined1 auStack_f0 [80];
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined1 *local_58;
  undefined1 *local_54;
  undefined1 *local_50;
  undefined1 *local_4c;
  undefined1 *local_48;
  undefined4 local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ade2e;
  local_10 = ExceptionList;
  local_20 = DAT_0084b484;
  local_48 = auStack_f0;
  puStack_f4 = auStack_f0;
  uStack_f8 = 0x45b027;
  ExceptionList = &local_10;
  local_84 = FUN_00438b60();
  local_8 = 0;
  local_50 = auStack_10c;
  puStack_110 = &DAT_007cf338;
  uStack_114 = 0x45b04c;
  local_80 = local_84;
  local_88 = basic_string<>();
  puStack_110 = (undefined *)0x45b057;
  puStack_110 = (undefined *)FUN_00401c50();
  uStack_114 = 0x45b074;
  local_8c = puStack_110;
  local_4c = auStack_10c;
  local_94 = basic_string<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  local_58 = auStack_128;
  local_90 = local_94;
  local_98 = basic_string<>(&DAT_007cf358);
  local_9c = FUN_00401c50();
  local_54 = auStack_128;
  local_a0 = basic_string<>(local_9c);
  local_8 = 0xffffffff;
  FUN_0042bed0();
  ExceptionList = local_10;
  return 1;
}

