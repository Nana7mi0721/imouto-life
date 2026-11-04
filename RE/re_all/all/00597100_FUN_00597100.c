
undefined4 FUN_00597100(int param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_2 != (int *)0x0) {
    *param_2 = -1;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0xffffffff;
  }
  if (*(int *)(param_1 + 8) == 0) {
    if ((-1 < *(int *)(param_1 + 0x56)) && (-1 < *(int *)(param_1 + 0x5a))) {
      if (param_2 != (int *)0x0) {
        *param_2 = *(int *)(param_1 + 0x56);
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = *(undefined4 *)(param_1 + 0x5a);
      }
      return 0;
    }
  }
  else if (*(int *)(param_1 + 8) == 1) {
    uVar1 = FUN_005fa200(param_1,param_2,param_3);
    return uVar1;
  }
  return 0xffffffff;
}

