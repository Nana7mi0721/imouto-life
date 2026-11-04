
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_00442fb0(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  int local_25c;
  int local_258;
  char local_218 [256];
  char local_118 [260];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad62b;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  ExceptionList = &local_10;
  iVar1 = FUN_0047a490();
  if (param_2 / (param_4 + 1) < iVar1) {
    iVar1 = FUN_0047a4b0();
    if (param_3 / (param_4 + 1) < iVar1) goto LAB_004431c4;
  }
  basic_string<>();
  pcVar2 = (char *)FUN_00401c50();
  _sprintf(local_118,pcVar2);
  FUN_0047a4b0();
  FUN_0047a490();
  basic_string<>();
  pcVar2 = (char *)FUN_00401c50();
  _sprintf(local_218,pcVar2);
  FUN_00438b60();
  local_8 = 0;
  basic_string<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  basic_string<>(local_118);
  local_8 = 0xffffffff;
  FUN_0042bed0();
  iVar1 = FUN_0047a490();
  if (iVar1 + -1 < param_2) {
    local_258 = FUN_0047a490();
    local_258 = local_258 + -1;
  }
  else {
    local_258 = param_2;
  }
  param_2 = local_258;
  iVar1 = FUN_0047a4b0();
  if (iVar1 + -1 < param_3) {
    local_25c = FUN_0047a4b0();
    local_25c = local_25c + -1;
  }
  else {
    local_25c = param_3;
  }
  param_3 = local_25c;
LAB_004431c4:
  iVar1 = FUN_0047a490();
  *(int *)(param_1 + 0x28) = (param_2 % (iVar1 << 1)) * (2 - param_4);
  iVar1 = FUN_0047a4b0();
  *(int *)(param_1 + 0x2c) = (param_3 % (iVar1 << 1)) * (2 - param_4);
  *(int *)(param_1 + 0x38) = DAT_0084b264 * 2 * *(int *)(param_1 + 0x28);
  *(int *)(param_1 + 0x3c) = DAT_0084b264 * 2 * *(int *)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x74) = 0;
  ExceptionList = local_10;
  return;
}

