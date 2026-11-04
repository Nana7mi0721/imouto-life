
void FUN_006a9610(undefined4 param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  uVar2 = FUN_006a8360(param_1);
  iVar1 = *param_3;
  *param_3 = iVar1 + 1;
  if ((void *)*param_2 == (void *)0x0) {
    pvVar3 = _malloc(4);
    *param_2 = pvVar3;
    *(undefined4 *)((int)pvVar3 + *param_3 * 4 + -4) = uVar2;
    return;
  }
  pvVar3 = _realloc((void *)*param_2,(iVar1 + 1) * 4);
  *param_2 = pvVar3;
  *(undefined4 *)((int)pvVar3 + *param_3 * 4 + -4) = uVar2;
  return;
}

