
undefined4 FUN_005422c0(char *param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined2 *puVar8;
  undefined4 *puVar9;
  undefined1 *puVar10;
  undefined2 *puVar11;
  undefined4 *puVar12;
  uint uVar13;
  int iVar14;
  int local_8;
  
  pcVar5 = param_1;
  if (*param_1 != '\0') {
    return 0xffffffff;
  }
  local_8 = *(int *)(param_1 + 0x42c);
  iVar3 = *(int *)(param_1 + 0x428);
  uVar6 = local_8 / 2;
  switch(param_1[4]) {
  case '\x01':
    uVar13 = 0;
    if (uVar6 != 0) {
      do {
        param_1 = (char *)(local_8 + -1);
        puVar7 = (undefined1 *)(*(int *)(pcVar5 + 0x430) * uVar13 + *(int *)(pcVar5 + 0x434));
        puVar10 = (undefined1 *)((int)param_1 * *(int *)(pcVar5 + 0x430) + *(int *)(pcVar5 + 0x434))
        ;
        if (iVar3 != 0) {
          iVar14 = iVar3;
          do {
            uVar1 = *puVar7;
            *puVar7 = *puVar10;
            *puVar10 = uVar1;
            puVar7 = puVar7 + 1;
            puVar10 = puVar10 + 1;
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
        }
        uVar13 = uVar13 + 1;
        local_8 = (int)param_1;
      } while (uVar13 < uVar6);
      return 0;
    }
    break;
  case '\x02':
    param_1 = (char *)0x0;
    if (uVar6 != 0) {
      do {
        local_8 = local_8 + -1;
        puVar8 = (undefined2 *)(*(int *)(pcVar5 + 0x430) * (int)param_1 + *(int *)(pcVar5 + 0x434));
        puVar11 = (undefined2 *)(local_8 * *(int *)(pcVar5 + 0x430) + *(int *)(pcVar5 + 0x434));
        if (iVar3 != 0) {
          iVar14 = iVar3;
          do {
            uVar2 = *puVar8;
            *puVar8 = *puVar11;
            *puVar11 = uVar2;
            puVar8 = puVar8 + 1;
            puVar11 = puVar11 + 1;
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
        }
        param_1 = (char *)((int)param_1 + 1);
      } while (param_1 < uVar6);
      return 0;
    }
    break;
  case '\x03':
    param_1 = (char *)0x0;
    if (uVar6 != 0) {
      do {
        local_8 = local_8 + -1;
        puVar8 = (undefined2 *)(*(int *)(pcVar5 + 0x430) * (int)param_1 + *(int *)(pcVar5 + 0x434));
        puVar11 = (undefined2 *)(local_8 * *(int *)(pcVar5 + 0x430) + *(int *)(pcVar5 + 0x434));
        if (iVar3 != 0) {
          iVar14 = iVar3;
          do {
            uVar2 = *puVar8;
            uVar1 = *(undefined1 *)(puVar8 + 1);
            *puVar8 = *puVar11;
            *(undefined1 *)(puVar8 + 1) = *(undefined1 *)(puVar11 + 1);
            *puVar11 = uVar2;
            *(undefined1 *)(puVar11 + 1) = uVar1;
            puVar8 = (undefined2 *)((int)puVar8 + 3);
            puVar11 = (undefined2 *)((int)puVar11 + 3);
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
        }
        param_1 = (char *)((int)param_1 + 1);
      } while (param_1 < uVar6);
      return 0;
    }
    break;
  case '\x04':
    param_1 = (char *)0x0;
    if (uVar6 != 0) {
      do {
        local_8 = local_8 + -1;
        puVar9 = (undefined4 *)(*(int *)(pcVar5 + 0x430) * (int)param_1 + *(int *)(pcVar5 + 0x434));
        puVar12 = (undefined4 *)(local_8 * *(int *)(pcVar5 + 0x430) + *(int *)(pcVar5 + 0x434));
        if (iVar3 != 0) {
          iVar14 = iVar3;
          do {
            uVar4 = *puVar9;
            *puVar9 = *puVar12;
            *puVar12 = uVar4;
            puVar9 = puVar9 + 1;
            puVar12 = puVar12 + 1;
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
        }
        param_1 = (char *)((int)param_1 + 1);
      } while (param_1 < uVar6);
    }
  }
  return 0;
}

