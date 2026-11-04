
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2
FUN_005e18d0(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,int *param_6,
            int *param_7)

{
  float fVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  undefined1 uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  int local_4;
  
  piVar3 = (int *)param_6[2];
  iVar4 = *piVar3;
  fVar1 = (float)piVar3[4];
  iVar10 = *param_6;
  iVar5 = param_6[1];
  if (*(char *)((int)param_6 + 0x5d) == '\0') {
    fVar6 = (float)_DAT_007d5348;
    if ((!NAN(fVar1) && !NAN(fVar6)) && fVar1 < fVar6 != (fVar1 == fVar6)) {
      return 0;
    }
    local_44 = (float)piVar3[1];
    local_40 = (float)piVar3[2];
    local_3c = (float)piVar3[3];
    local_38 = (float)piVar3[4];
    local_24 = (float)piVar3[9];
    local_20 = (float)piVar3[10];
    local_1c = (float)piVar3[0xb];
    local_18 = (float)piVar3[0xc];
    local_34 = (float)piVar3[5];
    local_30 = (float)piVar3[6];
    local_2c = (float)piVar3[7];
    local_28 = (float)piVar3[8];
    local_14 = (float)piVar3[0xd];
    local_10 = (float)piVar3[0xe];
    local_c = (float)piVar3[0xf];
    local_8 = (float)piVar3[0x10];
  }
  else {
    fVar1 = fVar1 * (float)param_6[0x1b];
    fVar6 = (float)_DAT_007d5348;
    if ((!NAN(fVar1) && !NAN(fVar6)) && fVar1 < fVar6 != (fVar1 == fVar6)) {
      return 0;
    }
    local_44 = (float)piVar3[1] * (float)param_6[0x18];
    local_40 = (float)piVar3[2] * (float)param_6[0x19];
    local_3c = (float)piVar3[3] * (float)param_6[0x1a];
    local_38 = (float)piVar3[4] * (float)param_6[0x1b];
    local_24 = (float)piVar3[9] * (float)param_6[0x20];
    local_20 = (float)piVar3[10] * (float)param_6[0x21];
    local_1c = (float)piVar3[0xb] * (float)param_6[0x22];
    local_18 = (float)piVar3[0xc] * (float)param_6[0x23];
    local_14 = (float)piVar3[0xd] * (float)param_6[0x24];
    local_10 = (float)piVar3[0xe] * (float)param_6[0x25];
    local_c = (float)piVar3[0xf] * (float)param_6[0x26];
    local_8 = (float)piVar3[0x10] * (float)param_6[0x27];
    local_34 = (float)piVar3[5] * (float)param_6[0x1c];
    local_30 = (float)piVar3[6] * (float)param_6[0x1d];
    local_2c = (float)piVar3[7] * (float)param_6[0x1e];
    local_28 = (float)piVar3[8] * (float)param_6[0x1f];
  }
  local_4 = piVar3[0x11];
  FUN_0056d420(&DAT_00a38e2c,piVar3 + 0x12,0x10);
  DAT_00a38de4 = 1;
  DAT_00e39a00 = 1;
  FUN_005a7a00(&local_44);
  if (DAT_00a3810c == 0) {
    uVar7 = *(undefined1 *)(iVar5 + 0x49);
  }
  else {
    uVar7 = 0;
  }
  FUN_0059a970(uVar7);
  param_5[4] = 0;
  param_5[9] = -1;
  param_5[10] = -1;
  param_5[0xb] = -1;
  *param_5 = piVar3[100];
  param_5[2] = piVar3[0x65];
  param_5[1] = piVar3[0x66];
  iVar8 = param_6[0x2d];
  if (iVar8 == -1) {
    iVar8 = piVar3[0x68];
  }
  param_5[5] = (int)ROUND((float)param_6[0x28] * (float)iVar8) << 0x18 | 0xffffff;
  if (DAT_00a3810c == 0) {
    uVar9 = param_6[0x2c];
    if (uVar9 == 0xffffffff) {
      uVar9 = piVar3[0x67];
    }
    if (0xe < uVar9) goto switchD_005e1b4c_caseD_7;
  }
  else {
    uVar9 = 0;
  }
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch((&DAT_005e1f54)[uVar9]) {
  case 0:
    param_5[3] = 0;
    param_5[6] = DAT_00e796a8;
    param_5[7] = DAT_00e796ac;
    iVar10 = DAT_00e796b0;
    goto LAB_005e1c31;
  case 1:
    param_5[3] = 1;
    cVar2 = *(char *)(*(int *)(iVar10 + 8) + 0x24e);
    param_5[7] = 6;
    param_5[8] = 1;
    param_5[6] = (-(uint)(cVar2 != '\0') & 0xfffffffd) + 5;
    break;
  case 2:
    param_5[3] = 1;
    cVar2 = *(char *)(*(int *)(iVar10 + 8) + 0x24e);
    param_5[7] = 2;
    param_5[8] = 1;
    param_5[6] = (-(uint)(cVar2 != '\0') & 0xfffffffd) + 5;
    break;
  case 3:
    param_5[3] = 1;
    cVar2 = *(char *)(*(int *)(iVar10 + 8) + 0x24e);
    param_5[7] = 2;
    param_5[8] = 3;
    param_5[6] = (-(uint)(cVar2 != '\0') & 0xfffffffd) + 5;
    break;
  case 4:
    param_5[6] = 1;
    param_5[7] = 3;
    goto LAB_005e1c2e;
  case 5:
    param_5[6] = 5;
    param_5[7] = 6;
    goto LAB_005e1c2e;
  case 6:
    param_5[6] = 2;
    param_5[7] = 1;
LAB_005e1c2e:
    param_5[3] = 1;
    iVar10 = 1;
LAB_005e1c31:
    param_5[8] = iVar10;
  }
switchD_005e1b4c_caseD_7:
  param_5[0xc] = piVar3[0x16];
  if ((((*(int *)(iVar5 + 0x1c) != 0) || (_DAT_007d56d8 < local_24)) || (_DAT_007d56d8 < local_20))
     || (_DAT_007d56d8 < local_1c)) {
    iVar10 = 1;
  }
  else {
    iVar10 = 0;
  }
  *param_7 = iVar10;
  if ((DAT_00a37dc8 == 0) && ((*(int *)(*piVar3 + 8) == 1 || (*(int *)(*piVar3 + 8) == 2)))) {
    *param_7 = 0;
  }
  FUN_0059a900(*param_7);
  if ((DAT_00a37dc8 == 0) && ((*(int *)(*piVar3 + 8) == 1 || (*(int *)(*piVar3 + 8) == 2)))) {
    FUN_005a0440(1);
    uVar12 = 1;
  }
  else {
    FUN_005a0440(*(undefined4 *)(iVar5 + 0x18));
    uVar12 = *(undefined4 *)(iVar5 + 0x1c);
  }
  FUN_005a0510(uVar12);
  iVar10 = *(int *)(*piVar3 + 8);
  if (((iVar10 == 1) || (iVar10 == 2)) || ((2 < iVar10 && (iVar10 < 9)))) {
    FUN_0059b2b0(0);
  }
  else {
    FUN_00516dc0(DAT_00a38de0 == 0);
  }
  if ((2 < *(int *)(*piVar3 + 8)) && (*(int *)(*piVar3 + 8) < 9)) {
    *param_4 = *param_4 + ((*param_4 / 2) % 0x54) * -2;
    *param_2 = *param_2 + ((*param_2 / 2) % 10) * -2;
    iVar10 = *param_1 + ((*param_1 / 0xf00) % 3) * -0xf00;
    iVar10 = iVar10 + ((iVar10 / 2) % 0x14) * -2;
    uVar9 = iVar10 / 0x28 & 0x80000003;
    if ((int)uVar9 < 0) {
      uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
    }
    iVar10 = iVar10 + uVar9 * -0x28;
    uVar9 = iVar10 / 0xa0 & 0x80000001;
    if ((int)uVar9 < 0) {
      uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;
    }
    uVar9 = iVar10 + uVar9 * -0xa0;
    uVar11 = uVar9 & 0x80000001;
    if ((int)uVar11 < 0) {
      uVar11 = (uVar11 - 1 | 0xfffffffe) + 1;
    }
    *param_1 = uVar9 - uVar11;
    *param_2 = *param_2 + *(int *)(*piVar3 + 8) * 0x38400;
  }
  iVar10 = *(int *)(*piVar3 + 8);
  if ((iVar10 == 1) || (iVar10 == 2)) {
    if (iVar10 == 1) {
      *param_2 = *param_2 + 0x780;
      *param_4 = *param_4 + 0x27600;
      if (piVar3[0x5b] == 2) {
        *param_2 = *param_2 + 0xa0;
        *param_4 = *param_4 + 0x540;
      }
      if ((piVar3[0x5c] == 1) && (*param_7 != 0)) {
        *param_2 = *param_2 + 0x50;
        *param_4 = *param_4 + 0x2a0;
      }
    }
    else if (iVar10 == 2) {
      *param_2 = *param_2 + 0xb40;
      *param_4 = *param_4 + 0x29580;
      if (-1 < piVar3[0x5a]) {
        if (piVar3[0x5d] == 2) {
          *param_2 = *param_2 + 0x140;
          *param_4 = *param_4 + 0xa80;
        }
        else if (piVar3[0x5d] == 1) {
          *param_2 = *param_2 + 0x280;
          *param_4 = *param_4 + 0x1500;
        }
      }
    }
  }
  if (1 < *(int *)(iVar4 + 0x60)) {
    *param_2 = *param_2 + *(int *)(iVar4 + 0x80) * 0xf00 + 0xf00;
    *param_4 = *param_4 + *(int *)(iVar4 + 0x80) * 0x3f00 + 0x3f00;
  }
  if (*(int *)(iVar4 + 0x168) != 0) {
    *param_1 = *param_1 + 0xa0;
    *param_2 = *param_2 + 0x14;
    *param_3 = *param_3 + 4;
    *param_4 = *param_4 + 0xa8;
  }
  if (*param_7 != 0) {
    *param_1 = *param_1 + 1;
    *param_2 = *param_2 + 1;
    *param_4 = *param_4 + 1;
  }
  if (piVar3[0x37] != 0) {
    *param_2 = *param_2 + 0x28;
    *param_4 = *param_4 + 0x150;
  }
  return 1;
}

