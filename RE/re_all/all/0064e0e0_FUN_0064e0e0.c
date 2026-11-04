
void FUN_0064e0e0(int *param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  if (*param_1 != 0) {
    FUN_006507e0(*param_1);
    *param_1 = 0;
  }
  if (param_2 != 0) {
    uVar2 = param_3 * param_4;
    if ((param_4 != 0) && (uVar2 / param_4 == param_3)) {
      iVar1 = FUN_006507d0(uVar2);
      *param_1 = iVar1;
    }
    if (*param_1 != 0) {
      FUN_00650840(*param_1,param_2,uVar2);
    }
  }
  return;
}

