
undefined4 FUN_006bee30(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar4 = 0;
  iVar6 = param_1 - (int)param_2;
  do {
    uVar1 = FUN_006beed0(*param_2,0);
    puVar2 = _malloc(uVar1 * 2);
    *(undefined4 **)(iVar6 + (int)param_2) = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      if (0 < iVar4) {
        puVar2 = (undefined4 *)(param_1 + (iVar4 + -1) * 4);
        do {
          _free((void *)*puVar2);
          iVar4 = iVar4 + -1;
          puVar2 = puVar2 + -1;
        } while (iVar4 != 0);
      }
      return 0xffffffff;
    }
    puVar5 = (undefined4 *)*param_2;
    for (uVar3 = (uVar1 & 0x7fffffff) >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar2 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar2 = puVar2 + 1;
    }
    param_2 = param_2 + 1;
    iVar4 = iVar4 + 1;
    for (uVar1 = uVar1 * 2 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)puVar2 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
  } while (iVar4 < 0x50);
  return 0;
}

