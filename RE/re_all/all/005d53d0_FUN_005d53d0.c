
void FUN_005d53d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5)

{
  code *local_4c [3];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  uint local_34;
  
  if (param_5 == 0) {
    (**(code **)(*DAT_00f3a074 + 0xd4))(DAT_00f3a074,param_1,param_2,param_3,param_4);
    return;
  }
  local_4c[0] = FUN_005d1e70;
  local_40 = param_1;
  local_34 = param_4 & 0xff;
  local_3c = param_2;
  local_38 = &param_3;
  FUN_0057ffd0(local_4c);
  return;
}

