
void FUN_005d52a0(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined1 *local_4c [3];
  undefined4 local_40;
  undefined4 local_3c;
  
  if (param_3 == 0) {
    (**(code **)(*DAT_00f3a074 + 0x3c))(DAT_00f3a074,param_1,param_2);
    return;
  }
  local_4c[0] = &LAB_005d1dc0;
  local_40 = param_1;
  local_3c = param_2;
  FUN_0057ffd0(local_4c);
  return;
}

