
void FUN_00690eb0(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x6c) == '\0') {
    iVar1 = *(int *)(param_1 + 0x3c + param_2 * 4);
    FUN_00690be0(param_1,*(undefined4 *)(iVar1 + param_3 * 4),
                 (int)*(char *)(iVar1 + 0x400 + param_3));
    return;
  }
  iVar1 = *(int *)(param_1 + 0x5c + param_2 * 4);
  *(int *)(iVar1 + param_3 * 4) = *(int *)(iVar1 + param_3 * 4) + 1;
  return;
}

