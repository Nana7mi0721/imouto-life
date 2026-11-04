
undefined4 FUN_006ac5a0(int *param_1,undefined4 *param_2)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar4 = 0;
  puVar5 = param_2;
  for (iVar3 = 0x1c; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  param_2[0x13] = 0;
  param_2[0x10] = param_1;
  param_2[0x11] = 0;
  if (*param_1 != 0) {
    pvVar1 = _calloc(1,0x48);
    param_2[0x1a] = pvVar1;
    *(undefined4 *)((int)pvVar1 + 4) = 0xc61c3c00;
    do {
      if (iVar4 == 7) {
        *(undefined4 **)((int)pvVar1 + 0x28) = param_2 + 1;
      }
      else {
        pvVar2 = _calloc(1,0x14);
        *(void **)((int)pvVar1 + iVar4 * 4 + 0xc) = pvVar2;
      }
      FUN_00797530(*(undefined4 *)((int)pvVar1 + iVar4 * 4 + 0xc));
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0xf);
  }
  return 0;
}

