
int __thiscall
FUN_00606ca0(int param_1,uint param_2,undefined4 param_3,uint param_4,int param_5,uint param_6,
            undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  void *_Memory;
  
  if (param_5 != 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x10))();
    if ((param_2 & iVar1 - 1U) != 0) {
      return -0x7ffbfdf2;
    }
    iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x10))();
    if ((param_4 & iVar1 - 1U) != 0) {
      return -0x7ffbfdf2;
    }
    iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x10))();
    if ((param_6 & iVar1 - 1U) != 0) {
      return -0x7ffbfdf2;
    }
  }
  _Memory = operator_new(0x28);
  if (_Memory == (void *)0x0) {
    return -0x7ff8fff2;
  }
  iVar1 = FUN_00606a70(param_1,*(undefined4 *)(param_1 + 0x18),param_2,param_3,param_4,param_5,
                       param_6,param_7,param_8);
  if ((iVar1 < 0) || (iVar1 = FUN_00607230(_Memory), iVar1 < 0)) {
    _free(_Memory);
    return iVar1;
  }
  return iVar1;
}

