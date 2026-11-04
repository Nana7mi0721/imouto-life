
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __thiscall FUN_0078df80(int param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  
  if ((float)(*(int **)(param_1 + 0xb8))[1] == _DAT_007d5344) {
    return 0;
  }
  iVar1 = *param_2;
  cVar2 = (**(code **)(**(int **)(param_1 + 0xb8) + 4))(*(undefined4 *)(iVar1 + 0xbc));
  if (cVar2 != '\0') {
    FUN_0078cb90(*(undefined4 *)(param_1 + 0xc0),param_1 + 0x24,param_1 + 100,iVar1,
                 *(undefined4 *)(iVar1 + 0xc0),iVar1 + 4,*(undefined4 *)(param_1 + 0xb8),
                 *(undefined4 *)(param_1 + 0xbc));
  }
  return 1;
}

