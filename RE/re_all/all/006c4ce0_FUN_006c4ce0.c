
undefined4 * FUN_006c4ce0(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  if (param_2 + 1 < param_2) {
    return (undefined4 *)0x0;
  }
  puVar1 = _malloc(param_2 + 1);
  if (puVar1 != (undefined4 *)0x0) {
    puVar3 = puVar1;
    for (uVar2 = param_2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = *param_1;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    }
    for (uVar2 = param_2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar3 = *(undefined1 *)param_1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
    *(undefined1 *)((int)puVar1 + param_2) = 0;
  }
  return puVar1;
}

