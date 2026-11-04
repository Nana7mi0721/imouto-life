
void FUN_005d50c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5)

{
  int iVar1;
  undefined1 *local_4c [3];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  
  if (param_5 != 0) {
    local_4c[0] = &LAB_005d1cf0;
    local_40 = param_1;
    local_3c = param_2;
    local_38 = param_3;
    local_34 = param_4;
    FUN_0057ffd0(local_4c);
    return;
  }
  iVar1 = (**(code **)(*DAT_00f3a070 + 0x30))(DAT_00f3a070,param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    DAT_00f3a09c = DAT_00f3a09c + 1;
  }
  return;
}

