
undefined4 FUN_006bb070(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  undefined4 *puVar12;
  
  if (*(int *)(param_1 + 0xd114) < 1) {
    if (*(void **)(param_1 + 0xd318) != (void *)0x0) {
      _free(*(void **)(param_1 + 0xd318));
      *(undefined4 *)(param_1 + 0xd318) = 0;
      _free(*(void **)(param_1 + 0xd31c));
      *(undefined4 *)(param_1 + 0xd31c) = 0;
      _free(*(void **)(param_1 + 0xd320));
      *(undefined4 *)(param_1 + 0xd320) = 0;
    }
    return 1;
  }
  iVar6 = *(int *)(param_1 + 0xd318);
  if (iVar6 == 0) {
    if (*(char *)(param_1 + 0x368) != '\0') {
      return 1;
    }
    puVar3 = _malloc(*(size_t *)(param_1 + 0xb4));
    *(undefined4 **)(param_1 + 0xd318) = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      return 1;
    }
    uVar9 = *(uint *)(param_1 + 0xb4);
    uVar1 = *(undefined1 *)(param_1 + 0x36b);
    for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar3 = CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,uVar1));
      puVar3 = puVar3 + 1;
    }
    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined1 *)puVar3 = uVar1;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  else {
    piVar10 = *(int **)(param_1 + 0xd8);
    iVar4 = *(int *)(param_1 + 0xe4) + *(int *)(param_1 + 0xe0) + *(int *)(param_1 + 0xdc);
    uVar1 = *(undefined1 *)(param_1 + 0x36b);
    if (0 < iVar4) {
      do {
        iVar2 = *piVar10;
        piVar10 = piVar10 + 1;
        iVar4 = iVar4 + -1;
        *(undefined1 *)(iVar2 + iVar6) = uVar1;
      } while (iVar4 != 0);
    }
  }
  pvVar5 = *(void **)(param_1 + 0xd31c);
  if (*(int *)(param_1 + 0xd114) < 2) {
    if (pvVar5 != (void *)0x0) {
      _free(pvVar5);
      *(undefined4 *)(param_1 + 0xd31c) = 0;
      _free(*(void **)(param_1 + 0xd320));
      *(undefined4 *)(param_1 + 0xd320) = 0;
    }
    return 1;
  }
  if (pvVar5 == (void *)0x0) {
    pvVar5 = _malloc(*(uint *)(param_1 + 4) * *(uint *)(param_1 + 8) +
                     (*(uint *)(param_1 + 8) >> ((byte)(~*(uint *)(param_1 + 0x30) >> 1) & 1)) *
                     (*(uint *)(param_1 + 4) >> ((byte)~*(uint *)(param_1 + 0x30) & 1)) * 2);
    *(void **)(param_1 + 0xd320) = pvVar5;
    pvVar5 = _malloc(*(int *)(param_1 + 0xb4) << 2);
    *(void **)(param_1 + 0xd31c) = pvVar5;
    if ((pvVar5 == (void *)0x0) || (*(int *)(param_1 + 0xd320) == 0)) {
      _free(*(void **)(param_1 + 0xd320));
      *(undefined4 *)(param_1 + 0xd320) = 0;
      _free(*(void **)(param_1 + 0xd31c));
      *(undefined4 *)(param_1 + 0xd31c) = 0;
      return 1;
    }
    *(undefined4 *)(param_1 + 0xd324) = 0;
  }
  iVar6 = *(int *)(param_1 + 0xd114);
  if (*(int *)(param_1 + 0xd324) != (4 < iVar6) + 1) {
    if (iVar6 < 5) {
      *(int *)(param_1 + 0xd328) = *(int *)(param_1 + 4);
      iVar6 = -*(int *)(param_1 + 4);
      *(int *)(param_1 + 0xd330) = iVar6;
      *(int *)(param_1 + 0xd32c) = *(int *)(param_1 + 8);
      *(int *)(param_1 + 0xd334) = (1 - *(int *)(param_1 + 8)) * iVar6 + *(int *)(param_1 + 0xd320);
    }
    else {
      uVar9 = *(uint *)(param_1 + 4);
      uVar8 = *(uint *)(param_1 + 8);
      uVar11 = uVar9 >> ((byte)~*(uint *)(param_1 + 0x30) & 1);
      *(uint *)(param_1 + 0xd328) = uVar9;
      uVar7 = uVar8 >> ((byte)(~*(uint *)(param_1 + 0x30) >> 1) & 1);
      *(uint *)(param_1 + 0xd330) = uVar9;
      *(uint *)(param_1 + 0xd33c) = uVar7;
      *(uint *)(param_1 + 0xd34c) = uVar7;
      iVar6 = uVar9 * uVar8 + *(int *)(param_1 + 0xd320);
      *(uint *)(param_1 + 0xd32c) = uVar8;
      *(int *)(param_1 + 0xd334) = *(int *)(param_1 + 0xd320);
      *(uint *)(param_1 + 0xd338) = uVar11;
      *(uint *)(param_1 + 0xd340) = uVar11;
      *(int *)(param_1 + 0xd344) = iVar6;
      *(uint *)(param_1 + 0xd348) = uVar11;
      *(uint *)(param_1 + 0xd350) = uVar11;
      *(uint *)(param_1 + 0xd354) = uVar7 * uVar11 + iVar6;
      FUN_006b8e40(param_1 + 0xd328,param_1 + 0xd328);
    }
    iVar6 = *(int *)(param_1 + 0xd114);
    *(uint *)(param_1 + 0xd324) = (4 < iVar6) + 1;
  }
  if (iVar6 < 5) {
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x214) * 0x30 + 0xfc + param_1);
    puVar12 = (undefined4 *)(param_1 + 0xd338);
    for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar12 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar12 = puVar12 + 1;
    }
  }
  return 0;
}

