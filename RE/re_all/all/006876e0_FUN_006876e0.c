
void FUN_006876e0(int *param_1,int param_2,undefined4 *param_3,int param_4,uint param_5)

{
  size_t _Size;
  void *pvVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar6 = *(undefined4 **)(param_2 + 0x50);
  if ((puVar6 == (undefined4 *)0x0) || (*(int *)(param_2 + 0x54) < (int)(param_4 + param_5))) {
    uVar3 = *(uint *)(param_2 + 0x54);
    _Size = param_4 + 0x10000 + param_5;
    *(size_t *)(param_2 + 0x54) = _Size;
    pvVar1 = _malloc(_Size);
    *(void **)(param_2 + 0x50) = pvVar1;
    if (pvVar1 == (void *)0x0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x43;
      (**(code **)*param_1)(param_1);
    }
    if ((puVar6 != (undefined4 *)0x0) && (uVar3 != 0)) {
      puVar4 = puVar6;
      puVar5 = *(undefined4 **)(param_2 + 0x50);
      for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
      _free(puVar6);
    }
  }
  puVar6 = (undefined4 *)(param_4 + *(int *)(param_2 + 0x50));
  for (uVar3 = param_5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar6 = *param_3;
    param_3 = param_3 + 1;
    puVar6 = puVar6 + 1;
  }
  for (param_5 = param_5 & 3; param_5 != 0; param_5 = param_5 - 1) {
    *(undefined1 *)puVar6 = *(undefined1 *)param_3;
    param_3 = (undefined4 *)((int)param_3 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  return;
}

