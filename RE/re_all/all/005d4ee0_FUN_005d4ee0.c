
void FUN_005d4ee0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined1 *local_4c [3];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  
  if (param_4 != 0) {
    local_4c[0] = &LAB_005d1c00;
    local_40 = param_1;
    local_3c = param_2;
    local_38 = param_3;
    FUN_0057ffd0(local_4c);
    return;
  }
  iVar1 = (**(code **)(*DAT_00f3a070 + 0x14))(DAT_00f3a070,param_1,param_2,param_3);
  if (iVar1 == 0) {
    DAT_00f3a084 = DAT_00f3a084 + 1;
  }
  return;
}

