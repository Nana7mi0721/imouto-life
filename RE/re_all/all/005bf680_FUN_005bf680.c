
undefined4 FUN_005bf680(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int local_18 [4];
  undefined4 local_8;
  undefined4 local_4;
  
  local_18[0] = *(int *)(param_1 + 0x34) * param_2;
  local_18[3] = (param_2 + param_4) * *(int *)(param_1 + 0x34);
  local_8 = 1;
  local_4 = 1;
  local_18[1] = 0;
  local_18[2] = 0;
  FUN_005d52f0(**(undefined4 **)(param_1 + 0x40),0,local_18,param_3,0,0,0);
  return 0;
}

