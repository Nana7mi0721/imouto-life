
void FUN_006baeb0(undefined4 *param_1,undefined4 *param_2)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int *piVar11;
  byte *pbVar12;
  int local_4;
  
  iVar6 = (int)param_1;
  puVar1 = (uint *)((int)param_1 + 0x30);
  puVar10 = (undefined4 *)((int)param_1 + 0xcb08);
  piVar7 = (int *)((int)param_1 + 0x54);
  param_1 = (undefined4 *)0x3;
  param_2[0x2f0] = 4 << ((byte)(~*puVar1 >> 1) & 1);
  puVar9 = param_2 + 0x80;
  for (iVar4 = 0xc0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar9 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar9 = puVar9 + 1;
  }
  puVar10 = (undefined4 *)(iVar6 + 0xce08);
  puVar9 = param_2 + 0x200;
  for (iVar4 = 0xc0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar9 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar9 = puVar9 + 1;
  }
  iVar5 = *(int *)(iVar6 + 0xd8);
  piVar11 = (int *)(iVar6 + 0xdc);
  piVar8 = param_2 + 0x2c3;
  iVar4 = iVar5 + *(int *)(iVar6 + 0xb4) * 4;
  do {
    piVar8[-3] = iVar5;
    *piVar8 = iVar4;
    iVar3 = *piVar11;
    piVar8 = piVar8 + 1;
    piVar11 = piVar11 + 1;
    iVar5 = iVar5 + iVar3 * 4;
    iVar4 = iVar4 + (iVar3 - *piVar7) * 4;
    param_1 = (undefined4 *)((int)param_1 + -1);
    piVar7 = piVar7 + 8;
  } while (param_1 != (undefined4 *)0x0);
  iVar4 = 0;
  param_1 = param_2 + 0x2cc;
  do {
    local_4 = 0;
    if (*(char *)(iVar6 + 0x36a) != '\0') {
      pbVar12 = (byte *)(iVar6 + 0x36b);
      puVar10 = param_1;
      do {
        iVar5 = 0;
        puVar9 = puVar10;
        do {
          puVar10 = puVar9 + 1;
          iVar3 = iVar5 + 0xdc;
          iVar5 = iVar5 + 1;
          *puVar9 = *(undefined4 *)(iVar6 + (iVar3 + (iVar4 + (uint)*pbVar12 * 3) * 2) * 4);
          puVar9 = puVar10;
        } while (iVar5 < 2);
        local_4 = local_4 + 1;
        pbVar12 = pbVar12 + 1;
      } while (local_4 < (int)(uint)*(byte *)(iVar6 + 0x36a));
    }
    iVar4 = iVar4 + 1;
    param_1 = param_1 + 6;
  } while (iVar4 < 3);
  puVar10 = param_2 + 0x2e4;
  for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  cVar2 = *(char *)(*(byte *)(iVar6 + 0x36b) + 0xc970 + iVar6);
  param_2[0x2f1] = (uint)(cVar2 != '\0');
  if (cVar2 != '\0') {
    FUN_006bdad0(param_2 + 0x40,cVar2);
  }
  iVar4 = FUN_006bb070(iVar6);
  if (iVar4 == 0) {
    param_2[0x2f2] = *(undefined4 *)(iVar6 + 0xd114);
    for (iVar6 = 0x20; iVar6 != 0; iVar6 = iVar6 + -1) {
      *param_2 = 0;
      param_2 = param_2 + 1;
    }
    return;
  }
  param_2[0x2f2] = 0;
  puVar10 = (undefined4 *)(*(int *)(iVar6 + 0x214) * 0x30 + 0xec + iVar6);
  puVar9 = (undefined4 *)(iVar6 + 0xd328);
  for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar9 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar9 = puVar9 + 1;
  }
  for (iVar6 = 0x20; iVar6 != 0; iVar6 = iVar6 + -1) {
    *param_2 = 0;
    param_2 = param_2 + 1;
  }
  return;
}

