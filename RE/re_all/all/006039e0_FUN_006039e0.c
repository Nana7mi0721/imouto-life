
undefined4 __thiscall FUN_006039e0(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = FUN_00603760();
  if (iVar1 == 0) {
    uVar2 = FUN_00603770();
    *param_1 = uVar2;
  }
  else {
    uVar2 = FUN_00603770();
    FUN_00603790(uVar2);
  }
  iVar1 = FUN_00603770();
  if (iVar1 == 0) {
    uVar2 = FUN_00603760();
    param_1[1] = uVar2;
  }
  else {
    uVar2 = FUN_00603760();
    FUN_00603780(uVar2);
  }
  uVar2 = FUN_0060ef20();
  FUN_00603800(param_2);
  param_1[2] = param_1[2] + -1;
  return uVar2;
}

