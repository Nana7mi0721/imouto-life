
int FUN_00646b30(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  DAT_00f3fa3c = DAT_00f3fa3c + 1;
  iVar2 = (*(code *)PTR_FUN_00a06264)(param_1 + 3 + param_2);
  if (iVar2 == 0) {
    return 0;
  }
  iVar1 = ((param_2 - iVar2) - 4U & param_2 - 1U) + 4 + iVar2;
  *(int *)(iVar1 + -4) = iVar2;
  return iVar1;
}

