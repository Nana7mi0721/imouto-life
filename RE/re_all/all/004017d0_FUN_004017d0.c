
int __thiscall FUN_004017d0(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(int *)(param_2 + 0x10) == 0) {
    iVar1 = (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x1c),param_3,param_1);
    if (iVar1 == -1) {
      iVar1 = -1;
    }
  }
  else {
    iVar1 = (**(code **)(param_2 + 0xc))(*(undefined4 *)(param_2 + 0x1c),param_3);
  }
  return iVar1;
}

