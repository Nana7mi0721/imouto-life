
uint FUN_0054f980(uint param_1)

{
  char cVar1;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  
  uVar12 = 0;
  uVar14 = (param_1 & 0xffffefff) - 1;
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if (DAT_00a72a60 == 0) {
    uVar12 = FUN_0056a010();
    return uVar12;
  }
  if (((((int)uVar14 < -1) || (DAT_00a74b80 <= (int)uVar14)) && (DAT_00a74b80 != 0)) &&
     ((param_1 & 0x1000) == 0)) {
    return 0;
  }
  if (((uVar14 != 0xffffffff) && (DAT_00a74b80 != 0)) && ((int)uVar14 < DAT_00a74b80)) {
    iVar13 = uVar14 * 0x4d4;
    cVar2 = (char)iVar13 + -0x7c;
    if (uVar14 < 0x10) {
      FUN_0056a470(uVar14);
    }
    if (*(int *)(&DAT_00a74bcc + iVar13) < 0) {
      uVar12 = 2;
    }
    else if (0 < *(int *)(&DAT_00a74bcc + iVar13)) {
      uVar12 = 4;
    }
    if (*(int *)(&DAT_00a74bd0 + iVar13) < 0) {
      uVar12 = uVar12 | 8;
    }
    else if (0 < *(int *)(&DAT_00a74bd0 + iVar13)) {
      uVar12 = uVar12 | 1;
    }
    uVar5 = (&DAT_00a74bec)[uVar14 * 0x135];
    if (uVar5 < 0x4651) {
      if (uVar5 == 18000) {
        uVar12 = uVar12 | 1;
      }
      else if (uVar5 < 0x2329) {
        if (uVar5 == 9000) {
          uVar12 = uVar12 | 4;
        }
        else if (uVar5 == 0) {
          uVar12 = uVar12 | 8;
        }
        else if (uVar5 == 0x1194) {
          uVar12 = uVar12 | 0xc;
        }
      }
      else if (uVar5 == 0x34bc) {
        uVar12 = uVar12 | 5;
      }
    }
    else if (uVar5 == 0x57e4) {
      uVar12 = uVar12 | 3;
    }
    else if (uVar5 == 27000) {
      uVar12 = uVar12 | 2;
    }
    else if (uVar5 == 0x7b0c) {
      uVar12 = uVar12 | 10;
    }
    pbVar3 = &DAT_00a74bfd + iVar13;
    iVar13 = 4;
    do {
      cVar1 = (char)pbVar3;
      if ((pbVar3[-1] & 0x80) == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1 << ((-0x75 - cVar2) + cVar1 & 0x1fU);
      }
      if ((*pbVar3 & 0x80) == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = 1 << ((-0x74 - cVar2) + cVar1 & 0x1fU);
      }
      if ((pbVar3[1] & 0x80) == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = 1 << ((-0x73 - cVar2) + cVar1 & 0x1fU);
      }
      if ((pbVar3[2] & 0x80) == 0) {
        uVar8 = 0;
      }
      else {
        uVar8 = 1 << ((-0x72 - cVar2) + cVar1 & 0x1fU);
      }
      if ((pbVar3[3] & 0x80) == 0) {
        uVar9 = 0;
      }
      else {
        uVar9 = 1 << ((-0x71 - cVar2) + cVar1 & 0x1fU);
      }
      if ((pbVar3[4] & 0x80) == 0) {
        uVar10 = 0;
      }
      else {
        uVar10 = 1 << ((-0x70 - cVar2) + cVar1 & 0x1fU);
      }
      uVar12 = uVar12 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10;
      pbVar3 = pbVar3 + 6;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
  }
  if ((param_1 & 0x1000) != 0) {
    if (DAT_00a828c8 != 1) {
      DAT_00a828c8 = 1;
      FUN_0056a240(1);
      DAT_00a828c8 = 0;
    }
    uVar5 = 1;
    puVar11 = &DAT_00a72b70 + (((int)uVar14 < 0) - 1 & uVar14) * 0x80;
    iVar13 = 0x20;
    do {
      iVar4 = 0;
      do {
        if ((0 < (int)puVar11[iVar4]) && (((&DAT_00a72a6c)[puVar11[iVar4]] & 0x80) != 0)) {
          uVar12 = uVar12 | uVar5;
          break;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4);
      uVar5 = uVar5 * 2;
      puVar11 = puVar11 + 4;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
  }
  return uVar12;
}

