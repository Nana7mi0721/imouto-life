
void FUN_005d5a40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5)

{
  undefined1 *local_4c [3];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  
  if (param_5 == 0) {
    (**(code **)(*DAT_00f3a04c + 0x78))(DAT_00f3a04c,param_1,param_2,param_3,param_4);
    return;
  }
  local_4c[0] = &LAB_005d3110;
  local_40 = param_1;
  local_3c = param_2;
  local_38 = param_3;
  local_34 = param_4;
  FUN_0057ffd0(local_4c);
  return;
}

