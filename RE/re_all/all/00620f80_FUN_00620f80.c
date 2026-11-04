
undefined4 * __thiscall FUN_00620f80(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)param_1[1];
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)FUN_00646b30(0x2c,0x10);
  }
  else {
    param_1[1] = 0;
  }
  puVar1[8] = 0;
  puVar1[10] = 0;
  puVar1[9] = param_3;
  puVar3 = puVar1;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_2;
    param_2 = param_2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_00620c20(param_1,*param_1,puVar1);
  param_1[3] = param_1[3] + 1;
  return puVar1;
}

