
int __thiscall FUN_00603a60(int *param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  
  iVar1 = FUN_00603860();
  if (iVar1 == 0) {
    pvVar2 = operator_new(0xc);
    if (pvVar2 == (void *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_0061ddb0();
    }
    if (iVar1 == 0) {
      return 0;
    }
  }
  FUN_006037a0(param_2);
  FUN_00603790(0);
  FUN_00603780(param_1[1]);
  if (param_1[1] == 0) {
    *param_1 = iVar1;
    param_1[1] = iVar1;
    param_1[2] = param_1[2] + 1;
    return iVar1;
  }
  FUN_00603790(iVar1);
  param_1[1] = iVar1;
  param_1[2] = param_1[2] + 1;
  return iVar1;
}

