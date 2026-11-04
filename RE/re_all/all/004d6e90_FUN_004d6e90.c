
undefined4 * FUN_004d6e90(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 extraout_var;
  undefined4 uVar4;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  uVar2 = FUN_004cc870(local_8);
  uVar4 = extraout_var;
  cVar1 = const_iterator__operator__(uVar2);
  if (cVar1 != '\0') {
    uVar2 = FUN_004ce060(local_c);
    cVar1 = const_iterator__operator__(uVar2);
    if (cVar1 != '\0') {
      FUN_004ccc40(uVar4);
      FUN_004cc870(param_1);
      return param_1;
    }
  }
  while (cVar1 = const_iterator__operator__(&param_3), cVar1 != '\0') {
    puVar3 = (undefined4 *)FUN_004e9550(local_10,0);
    FUN_004e7cd0(local_14,*puVar3);
  }
  *param_1 = param_2;
  return param_1;
}

