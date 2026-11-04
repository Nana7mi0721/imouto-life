
/* Library Function - Single Match
    ___sbh_alloc_block
   
   Library: Visual Studio 2003 Release */

int * ___sbh_alloc_block(uint *param_1)

{
  uint *puVar1;
  int *piVar2;
  char *pcVar3;
  int *piVar4;
  char cVar5;
  int *piVar6;
  undefined4 uVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  int *piVar14;
  uint uVar15;
  uint local_c;
  int local_8;
  
  uVar9 = (int)param_1 + 0x17U & 0xfffffff0;
  iVar10 = (int)((int)param_1 + 0x17U) >> 4;
  iVar11 = iVar10 + -1;
  puVar12 = DAT_00f48b48 + DAT_00f48b44 * 5;
  if (iVar11 < 0x20) {
    uVar15 = 0xffffffff >> ((byte)iVar11 & 0x1f);
    local_c = 0xffffffff;
  }
  else {
    uVar15 = 0;
    local_c = 0xffffffff >> ((char)iVar10 - 0x21U & 0x1f);
  }
  for (param_1 = DAT_00f48b50;
      (param_1 < puVar12 && ((param_1[1] & local_c) == 0 && (*param_1 & uVar15) == 0));
      param_1 = param_1 + 5) {
  }
  if (param_1 == puVar12) {
    for (param_1 = DAT_00f48b48;
        (param_1 < DAT_00f48b50 && ((param_1[1] & local_c) == 0 && (*param_1 & uVar15) == 0));
        param_1 = param_1 + 5) {
    }
    if (param_1 == DAT_00f48b50) {
      for (; (param_1 < puVar12 && (param_1[2] == 0)); param_1 = param_1 + 5) {
      }
      if (param_1 == puVar12) {
        for (param_1 = DAT_00f48b48; (param_1 < DAT_00f48b50 && (param_1[2] == 0));
            param_1 = param_1 + 5) {
        }
        if ((param_1 == DAT_00f48b50) &&
           (param_1 = (uint *)___sbh_alloc_new_region(), param_1 == (uint *)0x0)) {
          return (int *)0x0;
        }
      }
      uVar7 = ___sbh_alloc_new_group(param_1);
      *(undefined4 *)param_1[4] = uVar7;
      if (*(int *)param_1[4] == -1) {
        return (int *)0x0;
      }
    }
  }
  piVar6 = (int *)param_1[4];
  local_8 = *piVar6;
  if ((local_8 == -1) ||
     ((piVar6[local_8 + 0x31] & local_c) == 0 && (piVar6[local_8 + 0x11] & uVar15) == 0)) {
    local_8 = 0;
    puVar12 = (uint *)(piVar6 + 0x11);
    if ((piVar6[0x31] & local_c) == 0 && (*puVar12 & uVar15) == 0) {
      do {
        puVar1 = puVar12 + 0x21;
        local_8 = local_8 + 1;
        puVar12 = puVar12 + 1;
      } while ((*puVar1 & local_c) == 0 && (*puVar12 & uVar15) == 0);
    }
  }
  piVar4 = piVar6 + local_8 * 0x81 + 0x51;
  iVar10 = 0;
  uVar15 = piVar6[local_8 + 0x11] & uVar15;
  if (uVar15 == 0) {
    uVar15 = piVar6[local_8 + 0x31] & local_c;
    iVar10 = 0x20;
  }
  for (; -1 < (int)uVar15; uVar15 = uVar15 << 1) {
    iVar10 = iVar10 + 1;
  }
  piVar14 = (int *)piVar4[iVar10 * 2 + 1];
  iVar13 = *piVar14 - uVar9;
  iVar11 = (iVar13 >> 4) + -1;
  if (0x3f < iVar11) {
    iVar11 = 0x3f;
  }
  DAT_00f48b50 = param_1;
  if (iVar11 != iVar10) {
    if (piVar14[1] == piVar14[2]) {
      if (iVar10 < 0x20) {
        pcVar3 = (char *)((int)piVar6 + iVar10 + 4);
        uVar15 = ~(0x80000000U >> ((byte)iVar10 & 0x1f));
        piVar6[local_8 + 0x11] = uVar15 & piVar6[local_8 + 0x11];
        *pcVar3 = *pcVar3 + -1;
        if (*pcVar3 == '\0') {
          *param_1 = *param_1 & uVar15;
        }
      }
      else {
        pcVar3 = (char *)((int)piVar6 + iVar10 + 4);
        uVar15 = ~(0x80000000U >> ((byte)iVar10 - 0x20 & 0x1f));
        piVar6[local_8 + 0x31] = piVar6[local_8 + 0x31] & uVar15;
        *pcVar3 = *pcVar3 + -1;
        if (*pcVar3 == '\0') {
          param_1[1] = param_1[1] & uVar15;
        }
      }
    }
    *(int *)(piVar14[2] + 4) = piVar14[1];
    *(int *)(piVar14[1] + 8) = piVar14[2];
    if (iVar13 == 0) goto LAB_00503a0e;
    piVar2 = piVar4 + iVar11 * 2;
    iVar10 = piVar2[1];
    piVar14[2] = (int)piVar2;
    piVar14[1] = iVar10;
    piVar2[1] = (int)piVar14;
    *(int **)(piVar14[1] + 8) = piVar14;
    if (piVar14[1] == piVar14[2]) {
      cVar5 = *(char *)(iVar11 + 4 + (int)piVar6);
      *(char *)(iVar11 + 4 + (int)piVar6) = cVar5 + '\x01';
      bVar8 = (byte)iVar11;
      if (iVar11 < 0x20) {
        if (cVar5 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
        }
        piVar6[local_8 + 0x11] = piVar6[local_8 + 0x11] | 0x80000000U >> (bVar8 & 0x1f);
      }
      else {
        if (cVar5 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
        piVar6[local_8 + 0x31] = piVar6[local_8 + 0x31] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
      }
    }
  }
  if (iVar13 != 0) {
    *piVar14 = iVar13;
    *(int *)(iVar13 + -4 + (int)piVar14) = iVar13;
  }
LAB_00503a0e:
  piVar14 = (int *)((int)piVar14 + iVar13);
  *piVar14 = uVar9 + 1;
  *(uint *)((int)piVar14 + (uVar9 - 4)) = uVar9 + 1;
  iVar10 = *piVar4;
  *piVar4 = iVar10 + 1;
  if (((iVar10 == 0) && (param_1 == DAT_00f48b40)) && (local_8 == DAT_00f48b58)) {
    DAT_00f48b40 = (uint *)0x0;
  }
  *piVar6 = local_8;
  return piVar14 + 1;
}

