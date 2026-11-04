
void FUN_006b00c0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1[9] != 0) {
    if ((void *)param_1[8] != (void *)0x0) {
      _free((void *)param_1[8]);
    }
    if ((void *)param_1[2] != (void *)0x0) {
      _free((void *)param_1[2]);
    }
    puVar2 = param_1;
    for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    _free(param_1);
  }
  return;
}

