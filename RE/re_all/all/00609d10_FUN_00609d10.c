
int __thiscall FUN_00609d10(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 == (int *)0x0) {
    return -0x7fffbffd;
  }
  piVar1 = (int *)param_1[0x24];
  if (*(int *)(param_1[0x23] + 200) != 0) {
    if (piVar1[6] == 0) {
      return 0;
    }
    iVar2 = (**(code **)(*piVar1 + 0x48))(param_2);
    return iVar2;
  }
  if (*(int *)(param_1[0x23] + 0x9c) != piVar1[0x26]) {
    param_2 = (int *)FUN_00609050(param_2);
    if (param_2 == (int *)0x0) {
      return -0x7fff0001;
    }
  }
  iVar2 = (**(code **)(*param_1 + 0x68))(param_2);
  if (iVar2 < 0) {
    if (*(int *)(param_1[0x23] + 0x9c) != *(int *)(param_1[0x24] + 0x98)) {
      (**(code **)(*param_2 + 8))(param_2);
      return iVar2;
    }
  }
  else {
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*(int *)param_1[0x24] + 0x48))(param_2);
    }
    if (*(int *)(param_1[0x23] + 0x9c) != *(int *)(param_1[0x24] + 0x98)) {
      (**(code **)(*param_2 + 8))(param_2);
    }
  }
  return iVar2;
}

