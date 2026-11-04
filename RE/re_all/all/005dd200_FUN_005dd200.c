
undefined4 FUN_005dd200(undefined4 param_1,int param_2,byte param_3)

{
  int iVar1;
  
  if ((param_3 & 8) == 0) {
    iVar1 = FUN_005dbd80(param_1);
    if (iVar1 == 0) {
      return 0;
    }
    (**(code **)(param_2 + 4))(*(undefined4 *)(param_2 + 0x18),0,0,0);
  }
  if (((param_3 & 0x10) == 0) && (iVar1 = FUN_005dc1e0(param_1), iVar1 == 0)) {
    return 0;
  }
  if (((param_3 & 0x20) == 0) && (iVar1 = FUN_005f70b0(param_1), iVar1 == 0)) {
    return 0;
  }
  if ((param_3 & 0x40) == 0) {
    iVar1 = FUN_005dcba0(param_1);
    if (iVar1 == 0) {
      return 0;
    }
    (**(code **)(param_2 + 4))(*(undefined4 *)(param_2 + 0x18),0,0,0);
  }
  return 0xffffffff;
}

