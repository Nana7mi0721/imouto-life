
undefined4 FUN_005f51c0(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)*param_1)(((undefined4 *)*param_1)[6]);
  if (param_1[2] - iVar1 < param_3) {
    param_3 = (**(code **)*param_1)(((undefined4 *)*param_1)[6]);
    param_3 = param_1[2] - param_3;
  }
  if (param_3 == 0) {
    return 0;
  }
  uVar2 = (**(code **)(*param_1 + 8))(param_2,1,param_3,*(undefined4 *)(*param_1 + 0x18));
  return uVar2;
}

