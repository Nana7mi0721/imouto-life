
undefined4 FUN_00682190(int *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 *puVar3;
  int *piVar4;
  char cVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 *puVar10;
  byte *pbVar11;
  int iVar12;
  
  piVar4 = param_1;
  puVar3 = (undefined4 *)param_1[6];
  iVar12 = puVar3[1];
  puVar10 = (undefined1 *)*puVar3;
  if (iVar12 == 0) {
    cVar5 = (*(code *)puVar3[3])(param_1);
    if (cVar5 == '\0') {
      return 0;
    }
    iVar12 = puVar3[1];
    puVar10 = (undefined1 *)*puVar3;
  }
  iVar12 = iVar12 + -1;
  uVar1 = *puVar10;
  pbVar11 = puVar10 + 1;
  if (iVar12 == 0) {
    cVar5 = (*(code *)puVar3[3])(param_1);
    if (cVar5 == '\0') {
      return 0;
    }
    iVar12 = puVar3[1];
    pbVar11 = (byte *)*puVar3;
  }
  uVar7 = (uint)CONCAT11(uVar1,*pbVar11);
  param_1 = (int *)iVar12;
  do {
    uVar7 = uVar7 - 2;
    pbVar11 = pbVar11 + 1;
    iVar12 = (int)param_1 + -1;
    if ((int)uVar7 < 1) {
      if (uVar7 != 0) {
        *(undefined4 *)(*piVar4 + 0x14) = 0xc;
        (**(code **)*piVar4)(piVar4);
      }
      puVar3[1] = iVar12;
      *puVar3 = pbVar11;
      return 1;
    }
    if (iVar12 == 0) {
      cVar5 = (*(code *)puVar3[3])(piVar4);
      if (cVar5 == '\0') {
        return 0;
      }
      iVar12 = puVar3[1];
      pbVar11 = (byte *)*puVar3;
    }
    param_1 = (int *)(iVar12 + -1);
    bVar6 = *pbVar11;
    uVar8 = (uint)bVar6;
    pbVar11 = pbVar11 + 1;
    if (param_1 == (int *)0x0) {
      cVar5 = (*(code *)puVar3[3])(piVar4);
      if (cVar5 == '\0') {
        return 0;
      }
      param_1 = (int *)puVar3[1];
      pbVar11 = (byte *)*puVar3;
    }
    bVar2 = *pbVar11;
    uVar9 = (uint)bVar2;
    *(undefined4 *)(*piVar4 + 0x14) = 0x51;
    *(uint *)(*piVar4 + 0x18) = uVar8;
    *(uint *)(*piVar4 + 0x1c) = uVar9;
    (**(code **)(*piVar4 + 4))(piVar4,1);
    if (0x1f < bVar6) {
      *(undefined4 *)(*piVar4 + 0x14) = 0x1d;
      *(uint *)(*piVar4 + 0x18) = uVar8;
      (**(code **)*piVar4)(piVar4);
    }
    if (bVar6 < 0x10) {
      *(byte *)(uVar8 + 0xcb + (int)piVar4) = bVar2 & 0xf;
      bVar6 = (byte)((int)uVar9 >> 4);
      *(byte *)(uVar8 + 0xdb + (int)piVar4) = bVar6;
      if (bVar6 < *(byte *)(uVar8 + 0xcb + (int)piVar4)) {
        *(undefined4 *)(*piVar4 + 0x14) = 0x1e;
        *(uint *)(*piVar4 + 0x18) = uVar9;
        (**(code **)*piVar4)(piVar4);
      }
    }
    else {
      *(byte *)(uVar8 + 0xdb + (int)piVar4) = bVar2;
    }
  } while( true );
}

