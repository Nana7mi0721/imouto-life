
undefined4
FUN_00401750(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    if (param_4 == 0) {
      uVar1 = (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x1c),param_2,param_3,param_5)
      ;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x10))
                      (*(undefined4 *)(param_1 + 0x1c),param_2,param_3,param_4,param_5);
  }
  return uVar1;
}

