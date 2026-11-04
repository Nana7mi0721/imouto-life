
undefined4 FUN_006c4c20(undefined4 *param_1,uint param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (0x7ffffffe < param_2) {
    return 0xffffff7f;
  }
  uVar4 = param_2 + 1;
  if ((uVar4 & 0x3fffffff) != uVar4) {
    return 0xffffff7f;
  }
  pvVar2 = (void *)param_1[1];
  iVar1 = param_1[2];
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)((int)pvVar2 + iVar1 * 4);
  }
  pvVar2 = _realloc(pvVar2,uVar4 * 4);
  if (pvVar2 == (void *)0x0) {
    return 0xffffff7f;
  }
  *(undefined4 *)((int)pvVar2 + param_2 * 4) = uVar3;
  param_1[1] = pvVar2;
  if ((uVar4 & 0x3fffffff) != uVar4) {
    return 0xffffff7f;
  }
  pvVar2 = (void *)*param_1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)((int)pvVar2 + iVar1 * 4);
  }
  pvVar2 = _realloc(pvVar2,uVar4 * 4);
  if (pvVar2 == (void *)0x0) {
    return 0xffffff7f;
  }
  *(undefined4 *)((int)pvVar2 + param_2 * 4) = uVar3;
  *param_1 = pvVar2;
  return 0;
}

