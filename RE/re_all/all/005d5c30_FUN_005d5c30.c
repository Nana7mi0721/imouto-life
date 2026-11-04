
int FUN_005d5c30(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int param_6)

{
  int iVar1;
  undefined1 *local_4c [3];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  if (param_6 != 0) {
    local_4c[0] = &LAB_005d31e0;
    local_40 = param_1;
    local_3c = param_2;
    local_38 = param_3;
    local_34 = param_4;
    local_30 = param_5;
    iVar1 = FUN_0057ffd0(local_4c);
    return iVar1;
  }
  if (DAT_00f3a04c == (int *)0x0) {
    return -1;
  }
  iVar1 = (**(code **)(*DAT_00f3a04c + 0x6c))
                    (DAT_00f3a04c,param_1,param_2,param_3,param_4,param_5,0);
  return -(uint)(iVar1 != 0);
}

