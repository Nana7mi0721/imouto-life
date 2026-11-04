
undefined4 FUN_005fcd90(LPCWSTR param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  iVar1 = lstrlenW(param_1);
  uVar4 = iVar1 * 2 + 2;
  puVar2 = (undefined4 *)(*DAT_00aba194)(uVar4);
  *param_2 = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    return 0x8007000e;
  }
  for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar2 = *(undefined4 *)param_1;
    param_1 = param_1 + 2;
    puVar2 = puVar2 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(char *)puVar2 = (char)*param_1;
    param_1 = (LPCWSTR)((int)param_1 + 1);
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  return 0;
}

