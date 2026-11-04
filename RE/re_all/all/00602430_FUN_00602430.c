
int __thiscall FUN_00602430(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int *local_8;
  int local_4;
  
  iVar2 = param_3;
  local_8 = (int *)0x0;
  if (param_3 != 0) {
    iVar1 = FUN_00603650();
    if (iVar1 == 0) {
      iVar2 = FUN_00602230(param_2,param_3);
      return iVar2;
    }
  }
  local_4 = -0x7ffbfdf9;
  param_3 = 0;
  do {
    if (param_3 == *(byte *)(param_1 + 0x26)) {
      iVar1 = (**(code **)(*param_2 + 0x30))(param_2,&local_8);
    }
    else {
      iVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 0x30))(param_1 + 0xc,&local_8);
    }
    if (-1 < iVar1) {
      iVar1 = FUN_00602350(param_2,iVar2,local_8);
      (**(code **)(*local_8 + 8))(local_8);
      if (-1 < iVar1) {
        return 0;
      }
      if (((iVar1 != -0x7fffbffb) && (iVar1 != -0x7ff8ffa9)) && (iVar1 != -0x7ffbfdd6)) {
        local_4 = iVar1;
      }
    }
    param_3 = param_3 + 1;
  } while ((int)param_3 < 2);
  return local_4;
}

