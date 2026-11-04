
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_006b0200(size_t *param_1,size_t *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  void *pvVar6;
  size_t sVar7;
  size_t *psVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  int iVar14;
  byte bVar15;
  int iVar16;
  undefined4 *puVar17;
  size_t asStack_38 [6];
  int local_14;
  int local_10;
  size_t *local_c;
  int local_8;
  
  puVar2 = param_2;
  puVar1 = param_1;
  iVar3 = 0;
  iVar16 = 0;
  puVar4 = param_1;
  for (iVar14 = 0xe; iVar14 != 0; iVar14 = iVar14 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  iVar14 = param_2[1];
  if (0 < iVar14) {
    do {
      if ('\0' < *(char *)(param_2[2] + iVar3)) {
        iVar16 = iVar16 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar14);
  }
  param_1[1] = iVar14;
  param_1[2] = iVar16;
  *param_1 = *param_2;
  if (0 < iVar16) {
    asStack_38[4] = param_2[1];
    asStack_38[3] = param_2[2];
    asStack_38[2] = 0x6b0252;
    asStack_38[5] = iVar16;
    puVar4 = (undefined4 *)FUN_006afca0();
    asStack_38[5] = 0x6b026c;
    if (puVar4 == (undefined4 *)0x0) {
      asStack_38[5 - iVar16] = (size_t)param_1;
      asStack_38[4 - iVar16] = 0x6b027e;
      FUN_006b0110();
      return 0xffffffff;
    }
    if (0 < iVar16) {
      puVar17 = puVar4;
      local_c = (size_t *)iVar16;
      do {
        asStack_38[5 - iVar16] = *puVar17;
        asStack_38[4 - iVar16] = 0x6b02a7;
        uVar5 = FUN_006b05c0();
        *puVar17 = uVar5;
        *(undefined4 **)((int)asStack_38 + (iVar16 * -4 - (int)puVar4) + 0x18 + (int)puVar17) =
             puVar17;
        puVar17 = puVar17 + 1;
        local_c = (size_t *)((int)local_c + -1);
      } while (local_c != (size_t *)0x0);
    }
    local_c = asStack_38 + (6 - iVar16);
    asStack_38[5 - iVar16] = (size_t)&LAB_006b0620;
    asStack_38[4 - iVar16] = 4;
    asStack_38[3 - iVar16] = iVar16;
    asStack_38[2 - iVar16] = (size_t)local_c;
    asStack_38[1 - iVar16] = 0x6b02d2;
    _qsort((void *)asStack_38[2 - iVar16],asStack_38[3 - iVar16],asStack_38[4 - iVar16],
           (_PtFuncCompare *)asStack_38[5 - iVar16]);
    asStack_38[5 - iVar16] = 0x6b02e2;
    psVar8 = asStack_38 + iVar16 * -2 + 6;
    asStack_38[iVar16 * -2 + 5] = iVar16 * 4;
    asStack_38[iVar16 * -2 + 4] = 0x6b02ee;
    pvVar6 = _malloc(asStack_38[iVar16 * -2 + 5]);
    param_1[5] = (size_t)pvVar6;
    sVar7 = 0;
    if (0 < iVar16) {
      do {
        asStack_38[iVar16 * -2 + ((int)(*local_c - (int)puVar4) >> 2) + 6] = sVar7;
        sVar7 = sVar7 + 1;
        local_c = local_c + 1;
      } while ((int)sVar7 < iVar16);
      if (0 < iVar16) {
        local_14 = iVar16;
        do {
          iVar3 = *psVar8;
          puVar17 = (undefined4 *)
                    (((int)puVar4 - (int)(asStack_38 + iVar16 * -2 + 6)) + (int)psVar8);
          psVar8 = psVar8 + 1;
          *(undefined4 *)(param_1[5] + iVar3 * 4) = *puVar17;
          local_14 = local_14 + -1;
        } while (local_14 != 0);
      }
    }
    asStack_38[iVar16 * -2 + 5] = (size_t)puVar4;
    asStack_38[iVar16 * -2 + 4] = 0x6b035b;
    _free((void *)asStack_38[iVar16 * -2 + 5]);
    asStack_38[iVar16 * -2 + 4] = (size_t)(asStack_38 + iVar16 * -2 + 6);
    asStack_38[iVar16 * -2 + 3] = iVar16;
    asStack_38[iVar16 * -2 + 2] = (size_t)param_2;
    asStack_38[iVar16 * -2 + 1] = 0x6b0366;
    uVar5 = FUN_006afed0();
    param_1[4] = uVar5;
    asStack_38[iVar16 * -2 + 1] = iVar16 * 4;
    asStack_38[iVar16 * -2] = 0x6b0372;
    pvVar6 = _malloc(asStack_38[iVar16 * -2 + 1]);
    param_1[6] = (size_t)pvVar6;
    iVar14 = 0;
    iVar3 = 0;
    if (0 < (int)param_2[1]) {
      param_2 = asStack_38 + iVar16 * -2 + 6;
      do {
        if ('\0' < *(char *)(iVar3 + puVar2[2])) {
          iVar14 = iVar14 + 1;
          *(int *)(param_1[6] + *param_2 * 4) = iVar3;
          param_2 = param_2 + 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)puVar2[1]);
    }
    asStack_38[iVar16 * -2 + 5] = iVar14;
    asStack_38[iVar16 * -2 + 4] = 0x6b03b5;
    pvVar6 = _malloc(asStack_38[iVar16 * -2 + 5]);
    param_1[7] = (size_t)pvVar6;
    iVar3 = 0;
    param_2 = (size_t *)0x0;
    if (0 < (int)puVar2[1]) {
      param_1 = asStack_38 + iVar16 * -2 + 6;
      do {
        if ('\0' < *(char *)(iVar3 + puVar2[2])) {
          *(char *)(puVar1[7] + *param_1) = *(char *)(iVar3 + puVar2[2]);
          param_2 = (size_t *)((int)param_2 + 1);
          param_1 = param_1 + 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)puVar2[1]);
    }
    asStack_38[iVar16 * -2 + 5] = puVar1[2];
    asStack_38[iVar16 * -2 + 4] = 0x6b0403;
    iVar3 = FUN_006afc40();
    puVar1[9] = iVar3 + -4;
    if (iVar3 + -4 < 5) {
      puVar1[9] = 5;
    }
    if (8 < (int)puVar1[9]) {
      puVar1[9] = 8;
    }
    iVar14 = 1 << ((byte)puVar1[9] & 0x1f);
    asStack_38[iVar16 * -2 + 5] = 4;
    asStack_38[iVar16 * -2 + 4] = iVar14;
    asStack_38[iVar16 * -2 + 3] = 0x6b043c;
    pvVar6 = _calloc(asStack_38[iVar16 * -2 + 4],asStack_38[iVar16 * -2 + 5]);
    puVar1[8] = pvVar6;
    iVar3 = 0;
    puVar1[10] = 0;
    if (0 < (int)param_2) {
      do {
        iVar9 = (int)*(char *)(puVar1[7] + iVar3);
        if ((int)puVar1[10] < iVar9) {
          puVar1[10] = iVar9;
        }
        if ((int)*(char *)(puVar1[7] + iVar3) <= (int)puVar1[9]) {
          asStack_38[iVar16 * -2 + 5] = *(undefined4 *)(puVar1[5] + iVar3 * 4);
          asStack_38[iVar16 * -2 + 4] = 0x6b0474;
          uVar10 = FUN_006b05c0();
          bVar15 = *(byte *)(puVar1[7] + iVar3);
          iVar9 = 0;
          if (0 < 1 << ((char)puVar1[9] - bVar15 & 0x1f)) {
            do {
              uVar11 = iVar9 << (bVar15 & 0x1f);
              iVar9 = iVar9 + 1;
              *(int *)(puVar1[8] + (uVar11 | uVar10) * 4) = iVar3 + 1;
              bVar15 = *(byte *)(puVar1[7] + iVar3);
            } while (iVar9 < 1 << ((char)puVar1[9] - bVar15 & 0x1f));
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)param_2);
    }
    uVar5 = puVar1[9];
    uVar10 = 0;
    param_1 = (size_t *)0x0;
    local_8 = 0;
    local_10 = 0;
    if (0 < iVar14) {
      do {
        uVar11 = local_10 << (0x20U - (char)puVar1[9] & 0x1f);
        asStack_38[iVar16 * -2 + 5] = uVar11;
        asStack_38[iVar16 * -2 + 4] = 0x6b0508;
        iVar3 = FUN_006b05c0();
        if (*(int *)(puVar1[8] + iVar3 * 4) == 0) {
          iVar3 = uVar10 + 1;
          if (iVar3 < (int)param_2) {
            puVar12 = (uint *)(puVar1[5] + iVar3 * 4);
            do {
              if (uVar11 < *puVar12) break;
              uVar10 = uVar10 + 1;
              iVar3 = iVar3 + 1;
              puVar12 = puVar12 + 1;
            } while (iVar3 < (int)param_2);
            param_1 = (size_t *)uVar10;
          }
          if (local_8 < (int)param_2) {
            puVar12 = (uint *)(puVar1[5] + local_8 * 4);
            do {
              if (uVar11 < (*puVar12 & -2 << (0x1fU - (char)uVar5 & 0x1f))) break;
              puVar12 = puVar12 + 1;
              local_8 = local_8 + 1;
            } while (local_8 < (int)param_2);
            uVar10 = (uint)param_1;
          }
          uVar13 = (int)param_2 - local_8;
          if (0x7fff < param_1) {
            uVar10 = 0x7fff;
          }
          if (0x7fff < uVar13) {
            uVar13 = 0x7fff;
          }
          asStack_38[iVar16 * -2 + 5] = uVar11;
          asStack_38[iVar16 * -2 + 4] = 0x6b0595;
          iVar3 = FUN_006b05c0();
          *(uint *)(puVar1[8] + iVar3 * 4) = (uVar10 | 0xffff0000) << 0xf | uVar13;
          uVar10 = (uint)param_1;
        }
        local_10 = local_10 + 1;
      } while (local_10 < iVar14);
    }
  }
  return 0;
}

