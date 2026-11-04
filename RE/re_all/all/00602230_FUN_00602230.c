
int __thiscall FUN_00602230(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x28))(param_2);
  if (iVar1 < 0) {
    (**(code **)(*param_1 + 0x2c))();
    return iVar1;
  }
  iVar1 = (**(code **)(*param_1 + 0x20))(param_2);
  if (iVar1 == 0) {
    param_1[6] = (int)param_2;
    (**(code **)(*param_2 + 4))(param_2);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_2);
    if (-1 < iVar1) {
      if (param_1 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = param_1 + 3;
      }
      iVar1 = (**(code **)(*param_2 + 0x10))(param_2,piVar2,param_2);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*param_1 + 0x30))(param_2);
        if (-1 < iVar1) {
          return iVar1;
        }
        (**(code **)(*param_2 + 0x14))(param_2);
      }
    }
  }
  else if (((-1 < iVar1) || (iVar1 == -0x7fffbffb)) || (iVar1 == -0x7ff8ffa9)) {
    iVar1 = -0x7ffbfdd6;
  }
  (**(code **)(*param_1 + 0x2c))();
  piVar2 = (int *)param_1[6];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    param_1[6] = 0;
  }
  return iVar1;
}

