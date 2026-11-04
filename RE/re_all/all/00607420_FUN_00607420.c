
void __thiscall FUN_00607420(int param_1,uint param_2,undefined4 param_3,uint param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x10))();
  uVar1 = param_5;
  if ((param_2 & iVar2 - 1U) == 0) {
    iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x10))();
    if ((param_4 & iVar2 - 1U) == 0) {
      iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x10))();
      if ((uVar1 & iVar2 - 1U) == 0) {
        FUN_00606ea0(param_2,param_3,param_4,uVar1,&param_5,0);
        return;
      }
    }
  }
  iVar2 = FUN_00606a70(param_1,*(undefined4 *)(param_1 + 0x18),param_2,param_3,param_4,0,uVar1,0,0);
  if (-1 < iVar2) {
    FUN_00606ac0();
  }
  return;
}

