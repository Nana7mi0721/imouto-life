
void __thiscall FUN_007960c0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  if (*(char *)(param_1 + 0x3c) == '\0') {
    FUN_007953c0(param_2,param_3,param_4,&local_10,&local_20,0,*(undefined4 *)(param_1 + 0x38));
    return;
  }
  FUN_00795870(param_2,param_3,param_4,&local_10,&local_20,0,*(undefined4 *)(param_1 + 0x38));
  return;
}

