
uint FUN_00681e50(int *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  undefined1 *puVar10;
  byte *pbVar11;
  byte *pbVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  int *piStack_c;
  int *piStack_8;
  
  piVar5 = param_1;
  puVar4 = (undefined4 *)param_1[6];
  puVar10 = (undefined1 *)*puVar4;
  iVar13 = puVar4[1];
  if (*(char *)(param_1[0x6b] + 0xd) == '\0') {
    *(undefined4 *)(*param_1 + 0x14) = 0x3c;
    _strncpy((char *)(*param_1 + 0x18),&DAT_00a0dc2c,0x50);
    (**(code **)*param_1)(param_1);
  }
  if (iVar13 == 0) {
    uVar6 = (*(code *)puVar4[3])(param_1);
    if ((char)uVar6 == '\0') goto LAB_00682185;
    puVar10 = (undefined1 *)*puVar4;
    iVar13 = puVar4[1];
  }
  iVar13 = iVar13 + -1;
  uVar1 = *puVar10;
  puVar10 = puVar10 + 1;
  if (iVar13 == 0) {
    uVar6 = (*(code *)puVar4[3])(param_1);
    if ((char)uVar6 == '\0') goto LAB_00682185;
    puVar10 = (undefined1 *)*puVar4;
    iVar13 = puVar4[1];
  }
  uVar2 = *puVar10;
  iVar13 = iVar13 + -1;
  pbVar11 = puVar10 + 1;
  if (iVar13 == 0) {
    uVar6 = (*(code *)puVar4[3])(param_1);
    if ((char)uVar6 == '\0') goto LAB_00682185;
    pbVar11 = (byte *)*puVar4;
    iVar13 = puVar4[1];
  }
  uVar7 = (uint)*pbVar11;
  *(undefined4 *)(*param_1 + 0x14) = 0x69;
  iVar13 = iVar13 + -1;
  *(uint *)(*param_1 + 0x18) = uVar7;
  pbVar11 = pbVar11 + 1;
  (**(code **)(*param_1 + 4))(param_1,1);
  if ((((uint)CONCAT11(uVar1,uVar2) != uVar7 * 2 + 6) || (4 < uVar7)) ||
     ((uVar7 == 0 && (*(char *)((int)param_1 + 0xc9) == '\0')))) {
    *(undefined4 *)(*param_1 + 0x14) = 0xc;
    (**(code **)*param_1)(param_1);
  }
  param_1[0x4c] = uVar7;
  param_1 = (int *)0x0;
  if (uVar7 != 0) {
    piStack_8 = piVar5 + 0x4d;
    do {
      if (iVar13 == 0) {
        uVar6 = (*(code *)puVar4[3])(piVar5);
        if ((char)uVar6 == '\0') goto LAB_00682185;
        pbVar11 = (byte *)*puVar4;
        iVar13 = puVar4[1];
      }
      iVar13 = iVar13 + -1;
      uVar6 = (uint)*pbVar11;
      pbVar11 = pbVar11 + 1;
      iVar8 = 0;
      if (0 < (int)param_1) {
        piStack_c = piVar5 + 0x4d;
LAB_00681faa:
        if (uVar6 != *(uint *)*piStack_c) goto code_r0x00681fb4;
        iVar8 = *(int *)piVar5[0x4d];
        if (1 < (int)param_1) {
          piVar9 = piVar5 + 0x4e;
          iVar14 = (int)param_1 + -1;
          do {
            if (iVar8 < *(int *)*piVar9) {
              iVar8 = *(int *)*piVar9;
            }
            piVar9 = piVar9 + 1;
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
        }
        uVar6 = iVar8 + 1;
      }
LAB_00681fed:
      puVar15 = (uint *)piVar5[0x31];
      iVar8 = 0;
      if (0 < piVar5[9]) {
        do {
          if (uVar6 == *puVar15) goto LAB_0068201e;
          iVar8 = iVar8 + 1;
          puVar15 = puVar15 + 0x16;
        } while (iVar8 < piVar5[9]);
      }
      *(undefined4 *)(*piVar5 + 0x14) = 4;
      *(uint *)(*piVar5 + 0x18) = uVar6;
      (**(code **)*piVar5)(piVar5);
LAB_0068201e:
      *piStack_8 = (int)puVar15;
      if (iVar13 == 0) {
        uVar6 = (*(code *)puVar4[3])(piVar5);
        if ((char)uVar6 == '\0') goto LAB_00682185;
        pbVar11 = (byte *)*puVar4;
        iVar13 = puVar4[1];
      }
      bVar3 = *pbVar11;
      iVar13 = iVar13 + -1;
      puVar15[6] = bVar3 & 0xf;
      puVar15[5] = (int)(uint)bVar3 >> 4;
      iVar8 = *piVar5;
      pbVar11 = pbVar11 + 1;
      *(uint *)(iVar8 + 0x18) = *puVar15;
      *(uint *)(iVar8 + 0x1c) = puVar15[5];
      *(uint *)(iVar8 + 0x20) = puVar15[6];
      *(undefined4 *)(*piVar5 + 0x14) = 0x6a;
      (**(code **)(*piVar5 + 4))(piVar5,1);
      param_1 = (int *)((int)param_1 + 1);
      piStack_8 = piStack_8 + 1;
    } while ((int)param_1 < (int)uVar7);
  }
  if (iVar13 == 0) {
    uVar6 = (*(code *)puVar4[3])(piVar5);
    if ((char)uVar6 == '\0') goto LAB_00682185;
    pbVar11 = (byte *)*puVar4;
    iVar13 = puVar4[1];
  }
  iVar13 = iVar13 + -1;
  pbVar12 = pbVar11 + 1;
  piVar5[0x5e] = (uint)*pbVar11;
  if (iVar13 == 0) {
    uVar6 = (*(code *)puVar4[3])(piVar5);
    if ((char)uVar6 == '\0') goto LAB_00682185;
    pbVar12 = (byte *)*puVar4;
    iVar13 = puVar4[1];
  }
  iVar13 = iVar13 + -1;
  pbVar11 = pbVar12 + 1;
  piVar5[0x5f] = (uint)*pbVar12;
  if (iVar13 == 0) {
    uVar6 = (*(code *)puVar4[3])(piVar5);
    if ((char)uVar6 == '\0') {
LAB_00682185:
      return uVar6 & 0xffffff00;
    }
    pbVar11 = (byte *)*puVar4;
    iVar13 = puVar4[1];
  }
  bVar3 = *pbVar11;
  piVar5[0x61] = bVar3 & 0xf;
  iVar8 = *piVar5;
  piVar5[0x60] = (int)(uint)bVar3 >> 4;
  *(int *)(iVar8 + 0x18) = piVar5[0x5e];
  *(int *)(iVar8 + 0x1c) = piVar5[0x5f];
  *(int *)(iVar8 + 0x20) = piVar5[0x60];
  *(int *)(iVar8 + 0x24) = piVar5[0x61];
  *(undefined4 *)(*piVar5 + 0x14) = 0x6b;
  (**(code **)(*piVar5 + 4))(piVar5,1);
  *(undefined4 *)(piVar5[0x6b] + 0x10) = 0;
  if (uVar7 != 0) {
    piVar5[0x1f] = piVar5[0x1f] + 1;
  }
  *puVar4 = pbVar11 + 1;
  puVar4[1] = iVar13 + -1;
  return 1;
code_r0x00681fb4:
  iVar8 = iVar8 + 1;
  piStack_c = piStack_c + 1;
  if ((int)param_1 <= iVar8) goto LAB_00681fed;
  goto LAB_00681faa;
}

