
void FUN_005d5950(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined1 *local_4c [3];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  
  if (param_4 == 0) {
    (**(code **)(*DAT_00f3a04c + 0x8c))(DAT_00f3a04c,param_1,param_2,param_3);
    return;
  }
  local_4c[0] = &LAB_005d30a0;
  local_40 = param_1;
  local_3c = param_2;
  local_38 = param_3;
  FUN_0057ffd0(local_4c);
  return;
}

