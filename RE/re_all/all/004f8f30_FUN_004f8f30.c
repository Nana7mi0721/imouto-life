
int FUN_004f8f30(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  undefined8 uVar1;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_10 = 0;
  local_14 = FUN_004f8e00(param_1,param_2,&local_10);
  local_8 = (int)local_10 >> 0x1f;
  local_c = local_10;
  if (local_14 == 0) {
    local_14 = FUN_004f8e00(param_1,param_2,&local_10);
  }
  uVar1 = __allshl();
  local_c = (uint)uVar1 | local_c;
  local_8 = (uint)((ulonglong)uVar1 >> 0x20) | local_8;
  if (local_14 == 0) {
    local_14 = FUN_004f8e00(param_1,param_2,&local_10);
  }
  uVar1 = __allshl();
  local_c = (uint)uVar1 | local_c;
  local_8 = (uint)((ulonglong)uVar1 >> 0x20) | local_8;
  if (local_14 == 0) {
    local_14 = FUN_004f8e00(param_1,param_2,&local_10);
  }
  uVar1 = __allshl();
  local_c = (uint)uVar1 | local_c;
  local_8 = (uint)((ulonglong)uVar1 >> 0x20) | local_8;
  if (local_14 == 0) {
    local_14 = FUN_004f8e00(param_1,param_2,&local_10);
  }
  uVar1 = __allshl();
  local_c = (uint)uVar1 | local_c;
  local_8 = (uint)((ulonglong)uVar1 >> 0x20) | local_8;
  if (local_14 == 0) {
    local_14 = FUN_004f8e00(param_1,param_2,&local_10);
  }
  uVar1 = __allshl();
  local_c = (uint)uVar1 | local_c;
  local_8 = (uint)((ulonglong)uVar1 >> 0x20) | local_8;
  if (local_14 == 0) {
    local_14 = FUN_004f8e00(param_1,param_2,&local_10);
  }
  uVar1 = __allshl();
  local_c = (uint)uVar1 | local_c;
  local_8 = (uint)((ulonglong)uVar1 >> 0x20) | local_8;
  if (local_14 == 0) {
    local_14 = FUN_004f8e00(param_1,param_2,&local_10);
  }
  uVar1 = __allshl();
  if (local_14 == 0) {
    *param_3 = (uint)uVar1 | local_c;
    param_3[1] = (uint)((ulonglong)uVar1 >> 0x20) | local_8;
  }
  else {
    *param_3 = 0;
    param_3[1] = 0;
  }
  return local_14;
}

