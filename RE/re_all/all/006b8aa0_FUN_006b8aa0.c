
undefined4 FUN_006b8aa0(int *param_1,undefined4 *param_2)

{
  undefined4 *_Memory;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 local_40 [64];
  
  iVar1 = param_2[0xf];
  _Memory = _calloc(1,0x78);
  if (_Memory == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  puVar3 = param_2;
  puVar4 = _Memory + 4;
  for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_006b88f0(local_40,param_2);
  iVar1 = FUN_006b9360(local_40,*(undefined4 *)(iVar1 + 4));
  _Memory[2] = iVar1;
  if (iVar1 == 0) {
    _free(_Memory);
    return 0xfffffff6;
  }
  *_Memory = FUN_006b8b50;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[5] = (int)&PTR_FUN_00831d60;
  param_1[3] = 0;
  *param_1 = (int)(_Memory + 4);
  _Memory[0x13] = _Memory;
  return 0;
}

