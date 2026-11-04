
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f8370(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  uVar2 = FUN_006a8360(param_1);
  iVar1 = *param_3;
  *param_3 = iVar1 + 1;
  if (param_2 == (int *)0x0) {
    _DAT_00000000 = _malloc(4);
    *(undefined4 *)((int)_DAT_00000000 + *param_3 * 4 + -4) = uVar2;
    return;
  }
  pvVar3 = _realloc((void *)*param_2,(iVar1 + 1) * 4);
  *param_2 = (int)pvVar3;
  *(undefined4 *)(*param_2 + -4 + *param_3 * 4) = uVar2;
  return;
}

