
int FUN_005b8410(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_3) {
    do {
      iVar1 = FUN_005d2910(*param_1,param_1[1],0,param_2);
      if (iVar1 != 0) {
        return iVar2 + -1;
      }
      iVar2 = iVar2 + 1;
      param_1 = param_1 + 2;
      param_2 = param_2 + 4;
    } while (iVar2 < param_3);
  }
  return 0;
}

