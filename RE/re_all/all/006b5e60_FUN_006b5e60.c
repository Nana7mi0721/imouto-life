
int * FUN_006b5e60(int param_1,int *param_2,int *param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  int local_24;
  int local_1c;
  int local_14;
  
  piVar1 = (int *)*param_2;
  iVar2 = piVar1[3];
  iVar3 = piVar1[2];
  uVar4 = (piVar1[1] - *piVar1) / iVar3;
  piVar5 = (int *)FUN_006ac620(param_1,4);
  puVar6 = (undefined4 *)FUN_006ac620(param_1,uVar4 * 4);
  *piVar5 = (int)puVar6;
  for (uVar8 = uVar4 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  local_14 = 0;
  for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
    *(undefined1 *)puVar6 = 0;
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  param_1 = *piVar1 / param_4;
  if (0 < (int)uVar4) {
    do {
      iVar9 = 0;
      local_24 = 0;
      local_1c = 0;
      if (0 < iVar3) {
        iVar12 = param_1 * 4;
        do {
          uVar8 = (int)*(uint *)(iVar12 + *param_3) >> 0x1f;
          iVar7 = (*(uint *)(iVar12 + *param_3) ^ uVar8) - uVar8;
          if (local_24 < iVar7) {
            local_24 = iVar7;
          }
          if (1 < param_4) {
            iVar7 = param_4 + -1;
            piVar10 = param_3;
            do {
              piVar10 = piVar10 + 1;
              uVar8 = *(uint *)(*piVar10 + iVar12);
              uVar11 = (int)uVar8 >> 0x1f;
              if (iVar9 < (int)((uVar8 ^ uVar11) - uVar11)) {
                uVar8 = *(uint *)(*piVar10 + iVar12);
                uVar11 = (int)uVar8 >> 0x1f;
                iVar9 = (uVar8 ^ uVar11) - uVar11;
              }
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
          param_1 = param_1 + 1;
          local_1c = local_1c + param_4;
          iVar12 = iVar12 + 4;
        } while (local_1c < iVar3);
      }
      iVar12 = 0;
      if (0 < iVar2 + -1) {
        piVar10 = piVar1 + 0x286;
        do {
          if ((local_24 <= piVar10[-0x40]) && (iVar9 <= *piVar10)) break;
          iVar12 = iVar12 + 1;
          piVar10 = piVar10 + 1;
        } while (iVar12 < iVar2 + -1);
      }
      local_14 = local_14 + 1;
      *(int *)(*piVar5 + -4 + local_14 * 4) = iVar12;
    } while (local_14 < (int)uVar4);
  }
  param_2[10] = param_2[10] + 1;
  return piVar5;
}

