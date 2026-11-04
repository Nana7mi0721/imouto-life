
undefined4 *
FUN_0066ca40(undefined4 param_1,undefined4 *param_2,int param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  if ((((param_4 < 1) || (param_5 == 0)) || (param_3 < 0)) ||
     ((param_2 == (undefined4 *)0x0 && (0 < param_3)))) {
    FUN_00668620(param_1,s_internal_error__array_realloc_00a0c650);
  }
  if ((0x7fffffff - param_3 < param_4) ||
     (puVar1 = (undefined4 *)FUN_0066ca10(param_1,param_3 + param_4,param_5),
     puVar1 == (undefined4 *)0x0)) {
    return (undefined4 *)0x0;
  }
  if (0 < param_3) {
    puVar3 = puVar1;
    for (uVar2 = (uint)(param_3 * param_5) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = *param_2;
      param_2 = param_2 + 1;
      puVar3 = puVar3 + 1;
    }
    for (uVar2 = param_3 * param_5 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar3 = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  puVar3 = (undefined4 *)(param_3 * param_5 + (int)puVar1);
  for (uVar2 = (uint)(param_4 * param_5) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  for (uVar2 = param_4 * param_5 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  return puVar1;
}

