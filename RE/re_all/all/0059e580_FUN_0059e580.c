
undefined4 FUN_0059e580(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_4;
  iVar1 = param_1;
  if (**(int **)(param_1 + 0x40) == 0) {
    return 0;
  }
  iVar3 = FUN_005d4bb0(**(int **)(param_1 + 0x40),*(int *)(param_1 + 0x34) * param_2,
                       *(int *)(param_1 + 0x34) * param_4,&param_1,0);
  if (iVar3 == 0) {
    FUN_0056d420(param_1,param_3,*(int *)(iVar1 + 0x34) * iVar2);
    FUN_005d4be0(**(undefined4 **)(iVar1 + 0x40));
    return 0;
  }
  FUN_0056bb10(&DAT_007fc374);
  return 0xffffffff;
}

