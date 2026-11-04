
undefined4 *
FUN_004ecad0(undefined4 *param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,
            code *param_5)

{
  char cVar1;
  undefined1 uVar2;
  char *pcVar3;
  undefined1 *puVar4;
  
  while( true ) {
    cVar1 = const_iterator__operator__(&param_3);
    if (cVar1 == '\0') break;
    pcVar3 = (char *)FUN_004d95b0();
    uVar2 = (*param_5)((int)*pcVar3);
    puVar4 = (undefined1 *)FUN_004d95b0();
    *puVar4 = uVar2;
    FUN_004f0ce0();
    FUN_004f0ce0();
  }
  *param_1 = param_4;
  return param_1;
}

