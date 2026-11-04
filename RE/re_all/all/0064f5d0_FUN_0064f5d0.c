
void FUN_0064f5d0(int *param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  
  if (*param_1 != 0) {
    FUN_006507e0(*param_1);
  }
  iVar1 = FUN_006507d0(param_3 * 8);
  *param_1 = iVar1;
  if (iVar1 != 0) {
    while (param_3 != 0) {
      param_3 = param_3 + -1;
      *(undefined8 *)(*param_1 + param_3 * 8) = param_2;
    }
  }
  return;
}

