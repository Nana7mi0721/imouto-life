
int FUN_004f8e60(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int local_10;
  uint local_c;
  uint local_8;
  
  local_c = 0;
  local_10 = FUN_004f8e00(param_1,param_2,&local_c);
  local_8 = local_c;
  if (local_10 == 0) {
    local_10 = FUN_004f8e00(param_1,param_2,&local_c);
  }
  local_8 = local_c << 8 | local_8;
  if (local_10 == 0) {
    local_10 = FUN_004f8e00(param_1,param_2,&local_c);
  }
  local_8 = local_c << 0x10 | local_8;
  if (local_10 == 0) {
    local_10 = FUN_004f8e00(param_1,param_2,&local_c);
  }
  if (local_10 == 0) {
    *param_3 = local_c * 0x1000000 + local_8;
  }
  else {
    *param_3 = 0;
  }
  return local_10;
}

