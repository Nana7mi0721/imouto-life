
undefined4 FUN_006826b0(int *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  char cVar7;
  ushort uVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  byte *pbVar12;
  int iVar13;
  uint uVar14;
  ushort *puVar15;
  undefined4 *puVar16;
  int iStack_18;
  int iStack_c;
  int *piStack_8;
  
  piVar6 = param_1;
  puVar3 = (undefined4 *)param_1[6];
  iVar13 = puVar3[1];
  puVar11 = (undefined1 *)*puVar3;
  if (iVar13 == 0) {
    cVar7 = (*(code *)puVar3[3])(param_1);
    if (cVar7 == '\0') {
      return 0;
    }
    iVar13 = puVar3[1];
    puVar11 = (undefined1 *)*puVar3;
  }
  iVar13 = iVar13 + -1;
  uVar1 = *puVar11;
  puVar11 = puVar11 + 1;
  if (iVar13 == 0) {
    cVar7 = (*(code *)puVar3[3])(param_1);
    if (cVar7 == '\0') {
      return 0;
    }
    iVar13 = puVar3[1];
    puVar11 = (undefined1 *)*puVar3;
  }
  param_1 = (int *)(iVar13 + -1);
  pbVar12 = puVar11 + 1;
  iVar13 = CONCAT11(uVar1,*puVar11) - 2;
  do {
    if (iVar13 < 1) {
      if (iVar13 != 0) {
        *(undefined4 *)(*piVar6 + 0x14) = 0xc;
        (**(code **)*piVar6)(piVar6);
      }
      *puVar3 = pbVar12;
      puVar3[1] = param_1;
      return 1;
    }
    iVar13 = iVar13 + -1;
    if (param_1 == (int *)0x0) {
      cVar7 = (*(code *)puVar3[3])(piVar6);
      if (cVar7 == '\0') {
        return 0;
      }
      param_1 = (int *)puVar3[1];
      pbVar12 = (byte *)*puVar3;
    }
    bVar2 = *pbVar12;
    param_1 = (int *)((int)param_1 + -1);
    *(undefined4 *)(*piVar6 + 0x14) = 0x53;
    uVar14 = bVar2 & 0xf;
    *(uint *)(*piVar6 + 0x18) = uVar14;
    iVar9 = (int)(uint)bVar2 >> 4;
    *(int *)(*piVar6 + 0x1c) = iVar9;
    pbVar12 = pbVar12 + 1;
    (**(code **)(*piVar6 + 4))(piVar6,1);
    if (3 < uVar14) {
      *(undefined4 *)(*piVar6 + 0x14) = 0x20;
      *(uint *)(*piVar6 + 0x18) = uVar14;
      (**(code **)*piVar6)(piVar6);
    }
    if (piVar6[uVar14 + 0x24] == 0) {
      iVar10 = FUN_00684870(piVar6);
      piVar6[uVar14 + 0x24] = iVar10;
    }
    puVar4 = (undefined4 *)piVar6[uVar14 + 0x24];
    if (iVar9 == 0) {
      if (0x3f < iVar13) goto LAB_00682830;
      puVar16 = puVar4;
      for (iVar10 = 0x20; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar16 = 0x10001;
        puVar16 = puVar16 + 1;
      }
      iStack_18 = iVar13;
    }
    else if (iVar13 < 0x80) {
      puVar16 = puVar4;
      for (iVar10 = 0x20; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar16 = 0x10001;
        puVar16 = puVar16 + 1;
      }
      iStack_18 = iVar13 >> 1;
    }
    else {
LAB_00682830:
      iStack_18 = 0x40;
    }
    switch(iStack_18) {
    case 4:
      piStack_8 = (int *)&DAT_0082309c;
      break;
    default:
      piStack_8 = (int *)&DAT_00822c00;
      break;
    case 9:
      piStack_8 = (int *)&DAT_00823038;
      break;
    case 0x10:
      piStack_8 = (int *)&DAT_00822fb8;
      break;
    case 0x19:
      piStack_8 = (int *)&DAT_00822f14;
      break;
    case 0x24:
      piStack_8 = (int *)&DAT_00822e44;
      break;
    case 0x31:
      piStack_8 = (int *)&DAT_00822d40;
    }
    iStack_c = 0;
    if (0 < iStack_18) {
      do {
        if (iVar9 == 0) {
          if (param_1 == (int *)0x0) {
            cVar7 = (*(code *)puVar3[3])(piVar6);
            if (cVar7 == '\0') {
              return 0;
            }
            param_1 = (int *)puVar3[1];
            pbVar12 = (byte *)*puVar3;
          }
          uVar8 = (ushort)*pbVar12;
        }
        else {
          if (param_1 == (int *)0x0) {
            cVar7 = (*(code *)puVar3[3])(piVar6);
            if (cVar7 == '\0') {
              return 0;
            }
            param_1 = (int *)puVar3[1];
            pbVar12 = (byte *)*puVar3;
          }
          bVar2 = *pbVar12;
          param_1 = (int *)((int)param_1 + -1);
          pbVar12 = pbVar12 + 1;
          if (param_1 == (int *)0x0) {
            cVar7 = (*(code *)puVar3[3])(piVar6);
            if (cVar7 == '\0') {
              return 0;
            }
            param_1 = (int *)puVar3[1];
            pbVar12 = (byte *)*puVar3;
          }
          uVar8 = CONCAT11(bVar2,*pbVar12);
        }
        param_1 = (int *)((int)param_1 + -1);
        pbVar12 = pbVar12 + 1;
        iVar10 = *piStack_8;
        piStack_8 = piStack_8 + 1;
        *(ushort *)((int)puVar4 + iVar10 * 2) = uVar8;
        iStack_c = iStack_c + 1;
      } while (iStack_c < iStack_18);
    }
    if (1 < *(int *)(*piVar6 + 0x68)) {
      puVar15 = (ushort *)(puVar4 + 1);
      iVar10 = 8;
      do {
        iVar5 = *piVar6;
        *(uint *)(iVar5 + 0x18) = (uint)puVar15[-2];
        *(uint *)(iVar5 + 0x1c) = (uint)puVar15[-1];
        *(uint *)(iVar5 + 0x20) = (uint)*puVar15;
        *(uint *)(iVar5 + 0x24) = (uint)puVar15[1];
        *(uint *)(iVar5 + 0x28) = (uint)puVar15[2];
        *(uint *)(iVar5 + 0x2c) = (uint)puVar15[3];
        *(uint *)(iVar5 + 0x30) = (uint)puVar15[4];
        *(uint *)(iVar5 + 0x34) = (uint)puVar15[5];
        *(undefined4 *)(*piVar6 + 0x14) = 0x5f;
        (**(code **)(*piVar6 + 4))(piVar6,2);
        puVar15 = puVar15 + 8;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    iVar13 = iVar13 - iStack_18;
    if (iVar9 != 0) {
      iVar13 = iVar13 - iStack_18;
    }
  } while( true );
}

