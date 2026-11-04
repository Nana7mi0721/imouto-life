
undefined4 FUN_006c07f0(undefined4 param_1,undefined4 *param_2,int *param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  void *_Memory;
  int iVar3;
  
  uVar2 = FUN_006a8360(param_1);
  iVar1 = *param_3;
  iVar3 = *param_4;
  _Memory = (void *)*param_2;
  if (iVar3 <= iVar1) {
    if (0xfffffff < iVar3) {
      return 0xffffff7f;
    }
    iVar3 = iVar3 * 2 + 1;
    _Memory = _realloc(_Memory,iVar3 * 4);
    if (_Memory == (void *)0x0) {
      return 0xffffff7f;
    }
  }
  *(undefined4 *)((int)_Memory + iVar1 * 4) = uVar2;
  *param_2 = _Memory;
  *param_3 = iVar1 + 1;
  *param_4 = iVar3;
  return 0;
}

