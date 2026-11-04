
void FUN_00670ad0(int *param_1,int param_2,int param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  byte *pbVar11;
  char *pcVar12;
  byte *pbVar13;
  undefined1 *puVar14;
  int iVar15;
  uint local_4;
  
  iVar15 = param_2;
  iVar7 = *param_1;
  if ((char)param_1[2] == '\0') {
    if (param_3 == 0) {
      uVar9 = 0;
    }
    else {
      uVar9 = (uint)*(ushort *)(param_3 + 8);
    }
    bVar8 = *(byte *)((int)param_1 + 9);
    if (bVar8 < 8) {
      if (bVar8 == 1) {
        pcVar12 = (char *)(iVar7 + -1 + param_2);
        uVar9 = (uVar9 & 1) * 0xff;
        pbVar11 = (byte *)((iVar7 - 1U >> 3) + param_2);
        iVar10 = 7 - (iVar7 - 1U & 7);
        if (iVar7 != 0) {
          param_2 = iVar7;
          do {
            *pcVar12 = -((*pbVar11 >> ((byte)iVar10 & 0x1f) & 1) != 0);
            if (iVar10 == 7) {
              iVar10 = 0;
              pbVar11 = pbVar11 + -1;
            }
            else {
              iVar10 = iVar10 + 1;
            }
            pcVar12 = pcVar12 + -1;
            param_2 = param_2 + -1;
          } while (param_2 != 0);
        }
      }
      else if (bVar8 == 2) {
        uVar9 = (uVar9 & 3) * 0x55;
        pbVar11 = (byte *)(iVar7 + -1 + param_2);
        pbVar13 = (byte *)((iVar7 - 1U >> 2) + param_2);
        iVar10 = (3 - (iVar7 - 1U & 3)) * 2;
        if (iVar7 != 0) {
          param_2 = iVar7;
          do {
            bVar8 = *pbVar13 >> ((byte)iVar10 & 0x1f) & 3;
            *pbVar11 = ((bVar8 << 2 | bVar8) << 2 | bVar8) << 2 | bVar8;
            if (iVar10 == 6) {
              iVar10 = 0;
              pbVar13 = pbVar13 + -1;
            }
            else {
              iVar10 = iVar10 + 2;
            }
            pbVar11 = pbVar11 + -1;
            param_2 = param_2 + -1;
          } while (param_2 != 0);
        }
      }
      else if (bVar8 == 4) {
        uVar9 = (uVar9 & 0xf) * 0x11;
        pbVar13 = (byte *)((iVar7 - 1U >> 1) + param_2);
        iVar10 = (iVar7 - 1U & 1) * -4 + 4;
        pbVar11 = (byte *)(iVar7 + -1 + param_2);
        if (iVar7 != 0) {
          param_2 = iVar7;
          do {
            bVar8 = *pbVar13 >> ((byte)iVar10 & 0x1f);
            *pbVar11 = bVar8 << 4 | bVar8 & 0xf;
            if (iVar10 == 4) {
              iVar10 = 0;
              pbVar13 = pbVar13 + -1;
            }
            else {
              iVar10 = 4;
            }
            pbVar11 = pbVar11 + -1;
            param_2 = param_2 + -1;
          } while (param_2 != 0);
        }
      }
      *(undefined1 *)((int)param_1 + 9) = 8;
      *(undefined1 *)((int)param_1 + 0xb) = 8;
      param_1[1] = iVar7;
    }
    if (param_3 == 0) {
      return;
    }
    if (*(char *)((int)param_1 + 9) == '\b') {
      pbVar11 = (byte *)(iVar7 + -1 + iVar15);
      puVar14 = (undefined1 *)(iVar15 + -1 + iVar7 * 2);
      if (iVar7 != 0) {
        iVar15 = iVar7;
        do {
          if ((uint)*pbVar11 == (uVar9 & 0xff)) {
            *puVar14 = 0;
          }
          else {
            *puVar14 = 0xff;
          }
          puVar14[-1] = *pbVar11;
          puVar14 = puVar14 + -2;
          pbVar11 = pbVar11 + -1;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
        *(undefined1 *)(param_1 + 2) = 4;
        *(undefined1 *)((int)param_1 + 10) = 2;
        bVar8 = *(char *)((int)param_1 + 9) << 1;
        goto LAB_00670ea4;
      }
    }
    else if (*(char *)((int)param_1 + 9) == '\x10') {
      pbVar11 = (byte *)(param_1[1] + -1 + iVar15);
      puVar14 = (undefined1 *)(iVar15 + -1 + param_1[1] * 2);
      if (iVar7 != 0) {
        iVar15 = iVar7;
        do {
          if (((uint)pbVar11[-1] == uVar9 >> 8) && ((uint)*pbVar11 == (uVar9 & 0xff))) {
            *puVar14 = 0;
            puVar14[-1] = 0;
          }
          else {
            *puVar14 = 0xff;
            puVar14[-1] = 0xff;
          }
          puVar14[-2] = *pbVar11;
          puVar14[-3] = pbVar11[-1];
          puVar14 = puVar14 + -4;
          pbVar11 = pbVar11 + -2;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
    }
    *(undefined1 *)(param_1 + 2) = 4;
    *(undefined1 *)((int)param_1 + 10) = 2;
    bVar8 = *(char *)((int)param_1 + 9) << 1;
  }
  else {
    if ((char)param_1[2] != '\x02') {
      return;
    }
    if (param_3 == 0) {
      return;
    }
    if (*(char *)((int)param_1 + 9) == '\b') {
      cVar1 = *(char *)(param_3 + 2);
      cVar2 = *(char *)(param_3 + 4);
      cVar3 = *(char *)(param_3 + 6);
      pcVar12 = (char *)(param_1[1] + -1 + param_2);
      puVar14 = (undefined1 *)(param_2 + -1 + iVar7 * 4);
      if (iVar7 != 0) {
        iVar15 = iVar7;
        do {
          if (((pcVar12[-2] == cVar1) && (pcVar12[-1] == cVar2)) && (*pcVar12 == cVar3)) {
            *puVar14 = 0;
          }
          else {
            *puVar14 = 0xff;
          }
          puVar14[-1] = *pcVar12;
          puVar14[-2] = pcVar12[-1];
          puVar14[-3] = pcVar12[-2];
          puVar14 = puVar14 + -4;
          pcVar12 = pcVar12 + -3;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
    }
    else if (*(char *)((int)param_1 + 9) == '\x10') {
      cVar1 = *(char *)(param_3 + 5);
      cVar2 = *(char *)(param_3 + 3);
      cVar3 = *(char *)(param_3 + 7);
      cVar4 = *(char *)(param_3 + 2);
      cVar5 = *(char *)(param_3 + 4);
      cVar6 = *(char *)(param_3 + 6);
      pcVar12 = (char *)(param_1[1] + -1 + param_2);
      puVar14 = (undefined1 *)(param_2 + -1 + iVar7 * 8);
      if (iVar7 != 0) {
        iVar15 = iVar7;
        do {
          if ((((pcVar12[-5] == cVar2) && (pcVar12[-4] == cVar4)) &&
              ((pcVar12[-3] == cVar1 && ((pcVar12[-2] == cVar5 && (pcVar12[-1] == cVar3)))))) &&
             (*pcVar12 == cVar6)) {
            *puVar14 = 0;
            puVar14[-1] = 0;
          }
          else {
            *puVar14 = 0xff;
            puVar14[-1] = 0xff;
          }
          puVar14[-2] = *pcVar12;
          puVar14[-3] = pcVar12[-1];
          puVar14[-4] = pcVar12[-2];
          puVar14[-5] = pcVar12[-3];
          puVar14[-6] = pcVar12[-4];
          puVar14[-7] = pcVar12[-5];
          puVar14 = puVar14 + -8;
          pcVar12 = pcVar12 + -6;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
    }
    *(undefined1 *)(param_1 + 2) = 6;
    *(undefined1 *)((int)param_1 + 10) = 4;
    bVar8 = *(char *)((int)param_1 + 9) << 2;
  }
LAB_00670ea4:
  *(byte *)((int)param_1 + 0xb) = bVar8;
  if (bVar8 < 8) {
    param_1[1] = (uint)bVar8 * iVar7 + 7 >> 3;
    return;
  }
  param_1[1] = (uint)(bVar8 >> 3) * iVar7;
  return;
}

