
int __thiscall
FUN_00606ea0(int param_1,uint param_2,undefined4 param_3,uint param_4,uint param_5,
            undefined4 *param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uStack_14;
  
  if (param_6 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x10))();
  if ((((param_2 & iVar1 - 1U) != 0) ||
      (iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x10))(), (param_4 & iVar1 - 1U) != 0)) ||
     (iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x10))(), (param_5 & iVar1 - 1U) != 0)) {
    return -0x7ffbfdf2;
  }
  iVar1 = FUN_00606a70(param_1,*(undefined4 *)(param_1 + 0x18),param_2,param_3,param_4,1,param_5,
                       param_7,0);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = FUN_00606ac0();
  *param_6 = uStack_14;
  return iVar1;
}

