
int __thiscall FUN_00605300(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0xd8) + 0x28))(param_2);
  if (iVar1 == 0) {
    iVar1 = (*(int **)(param_1 + 0xd8))[0x24];
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0xd8) + 0x2c))(param_2,iVar1 + 0x34);
      return iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}

