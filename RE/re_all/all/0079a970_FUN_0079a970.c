
undefined4 FUN_0079a970(int param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar1 = *(int *)(param_1 + 0x11c) - *(int *)(param_1 + 0x124);
  uVar4 = uVar1 * 2;
  puVar5 = param_3;
  puVar6 = (undefined4 *)(param_1 + 0xa8 + *(int *)(param_1 + 0x124) * 2);
  for (uVar1 = (uVar1 & 0x7fffffff) >> 1; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  for (uVar1 = uVar4 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  iVar3 = *(int *)(param_1 + 0x108);
  if (iVar3 == 1) {
    FUN_0079d020(param_1,param_2,param_1 + 0xa8,*(undefined4 *)(param_1 + 0x11c));
    FUN_0079d020(param_1,(undefined1 *)((int)param_2 + *(int *)(param_1 + 0x120) * 2),
                 (undefined1 *)(uVar4 + (int)param_3),param_4 - *(int *)(param_1 + 0x11c));
  }
  else if (iVar3 == 2) {
    FUN_0079d040(param_1,param_2,param_1 + 0xa8,*(undefined4 *)(param_1 + 0x11c));
    FUN_0079d040(param_1,(undefined1 *)((int)param_2 + *(int *)(param_1 + 0x120) * 2),
                 (undefined1 *)(uVar4 + (int)param_3),param_4 - *(int *)(param_1 + 0x11c));
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x11c);
    if (iVar3 == 3) {
      FUN_0079d230(param_1,param_2,(undefined4 *)(param_1 + 0xa8),uVar1);
      FUN_0079d230(param_1,(undefined1 *)((int)param_2 + *(int *)(param_1 + 0x120) * 2),
                   (undefined1 *)(uVar4 + (int)param_3),param_4 - *(int *)(param_1 + 0x11c));
    }
    else {
      puVar5 = (undefined4 *)(param_1 + 0xa8);
      puVar6 = param_2;
      for (uVar2 = (uVar1 & 0x7fffffff) >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      for (iVar3 = (uVar1 & 1) << 1; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      uVar1 = param_4 - *(int *)(param_1 + 0x11c);
      puVar5 = (undefined4 *)(uVar4 + (int)param_3);
      puVar6 = (undefined4 *)((int)param_2 + *(int *)(param_1 + 0x120) * 2);
      for (uVar2 = (uVar1 & 0x7fffffff) >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      for (uVar4 = uVar1 * 2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
    }
  }
  uVar4 = *(uint *)(param_1 + 0x124);
  puVar5 = (undefined4 *)((int)param_3 + (param_4 - uVar4) * 2);
  puVar6 = (undefined4 *)(param_1 + 0xa8);
  for (uVar1 = (uVar4 & 0x7fffffff) >> 1; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  for (uVar4 = uVar4 * 2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  return 0;
}

