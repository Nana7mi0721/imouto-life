
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006b5c10(int param_1,int *param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  int *piVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  int local_20;
  int local_14;
  
  uVar4 = param_1;
  piVar1 = (int *)*param_2;
  iVar2 = piVar1[3];
  iVar3 = piVar1[2];
  uVar5 = (piVar1[1] - *piVar1) / iVar3;
  piVar6 = (int *)FUN_006ac620(param_1,param_4 * 4);
  if (0 < param_4) {
    param_1 = param_4;
    piVar14 = piVar6;
    do {
      puVar7 = (undefined4 *)FUN_006ac620(uVar4,uVar5 * 4);
      *piVar14 = (int)puVar7;
      for (uVar9 = uVar5 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      piVar14 = piVar14 + 1;
      for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(undefined1 *)puVar7 = 0;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  param_1 = 0;
  if (0 < (int)uVar5) {
    local_14 = 0;
    do {
      iVar10 = *piVar1;
      if (0 < param_4) {
        piVar14 = piVar6;
        local_20 = param_4;
        do {
          iVar13 = 0;
          if (0 < iVar3) {
            puVar11 = (uint *)(*(int *)((param_3 - (int)piVar6) + (int)piVar14) +
                              (iVar10 + local_14) * 4);
            iVar15 = iVar3;
            do {
              uVar9 = (int)*puVar11 >> 0x1f;
              iVar8 = (*puVar11 ^ uVar9) - uVar9;
              if (iVar13 < iVar8) {
                iVar13 = iVar8;
              }
              puVar11 = puVar11 + 1;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
          }
          iVar15 = __ftol();
          iVar8 = 0;
          if (0 < iVar2 + -1) {
            piVar12 = piVar1 + 0x286;
            do {
              if ((iVar13 <= piVar12[-0x40]) && ((*piVar12 < 0 || (iVar15 < *piVar12)))) break;
              iVar8 = iVar8 + 1;
              piVar12 = piVar12 + 1;
            } while (iVar8 < iVar2 + -1);
          }
          iVar13 = *piVar14;
          piVar14 = piVar14 + 1;
          *(int *)(iVar13 + param_1 * 4) = iVar8;
          local_20 = local_20 + -1;
        } while (local_20 != 0);
      }
      param_1 = param_1 + 1;
      local_14 = local_14 + iVar3;
    } while (param_1 < (int)uVar5);
  }
  param_2[10] = param_2[10] + 1;
  return;
}

