
undefined4 * __thiscall
FUN_004e2df0(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = const_iterator__operator__(&param_4);
  if (cVar1 != '\0') {
    uVar2 = FUN_004ece40(param_4,*(undefined4 *)(param_1 + 8),param_3);
    FUN_004e4160(uVar2,*(undefined4 *)(param_1 + 8));
    *(undefined4 *)(param_1 + 8) = uVar2;
  }
  *param_2 = param_3;
  return param_2;
}

