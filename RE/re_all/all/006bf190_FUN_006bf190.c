
void FUN_006bf190(int param_1,int param_2,undefined4 param_3,int *param_4,int param_5,int param_6)

{
  int iVar1;
  
  if (0 < param_5) {
    do {
      iVar1 = *(int *)(param_6 + *param_4 * 4);
      FUN_006bf160(iVar1 + param_1,iVar1 + param_2,param_3);
      param_4 = param_4 + 1;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
  }
  return;
}

