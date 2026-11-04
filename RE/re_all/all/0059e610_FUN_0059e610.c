
undefined4 FUN_0059e610(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x34) == 0) {
    if (*(int *)(param_1 + 0x38) == 0x10) {
      *(undefined4 *)(param_1 + 0x3c) = 0x28;
      *(undefined4 *)(param_1 + 0x40) = 0;
      goto LAB_0059e655;
    }
  }
  else if (*(int *)(param_1 + 0x38) == 0x10) {
    *(undefined4 *)(param_1 + 0x3c) = 0x29;
    *(undefined4 *)(param_1 + 0x40) = 0;
    goto LAB_0059e655;
  }
  *(undefined4 *)(param_1 + 0x40) = 2;
  *(undefined4 *)(param_1 + 0x3c) = 0x2a;
LAB_0059e655:
  if (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 0x3c) * 4) == 0) {
    FUN_0056bb10(&DAT_007fc460);
    return 0xffffffff;
  }
  piVar1 = (int *)(*(int *)(param_1 + 0x450) + 8);
  if (*piVar1 == 0) {
    iVar2 = FUN_005d5780(*(undefined4 *)(param_1 + 0x120),*(undefined4 *)(param_1 + 0x124),
                         (&DAT_00ddb598)[*(int *)(param_1 + 0x40)],0,0,0,piVar1,0,param_2);
    if (iVar2 != 0) {
      FUN_0056bb10(&DAT_007fc424);
      return 0xffffffff;
    }
  }
  if (**(int **)(param_1 + 0x450) == 0) {
    iVar2 = FUN_005d5820(*(undefined4 *)(param_1 + 0x120),*(undefined4 *)(param_1 + 0x124),1,1,
                         *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 0x3c) * 4),0,
                         *(int **)(param_1 + 0x450),0,param_2);
    if (iVar2 != 0) {
      FUN_0056bb10(&DAT_007fc3f0);
      return 0xffffffff;
    }
    iVar2 = FUN_005d5cc0(**(undefined4 **)(param_1 + 0x450),0,*(undefined4 **)(param_1 + 0x450) + 1,
                         param_2);
    if (iVar2 != 0) {
      FUN_0056bb10(&DAT_007fc3a8);
      return 0xffffffff;
    }
  }
  return 0;
}

