
undefined4 *
FUN_004eca80(undefined4 *param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  while (cVar1 = const_iterator__operator__(&param_3), cVar1 != '\0') {
    uVar2 = FUN_004d95b0(param_4);
    cVar1 = FUN_004ec8f0(uVar2);
    if (cVar1 != '\0') break;
    FUN_004f0cc0();
  }
  *param_1 = param_2;
  return param_1;
}

