
void FUN_00690860(int *param_1,char param_2,int param_3,int *param_4)

{
  undefined4 *puVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  int iVar12;
  undefined4 *puVar13;
  int iStack_518;
  int local_514;
  char acStack_508 [260];
  int aiStack_404 [257];
  
  if ((param_3 < 0) || (3 < param_3)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x34;
    *(int *)(*param_1 + 0x18) = param_3;
    (**(code **)*param_1)(param_1);
  }
  if (param_2 == '\0') {
    local_514 = param_1[param_3 + 0x22];
  }
  else {
    local_514 = param_1[param_3 + 0x1e];
  }
  if (local_514 == 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x34;
    *(int *)(*param_1 + 0x18) = param_3;
    (**(code **)*param_1)(param_1);
  }
  if (*param_4 == 0) {
    iVar3 = (**(code **)param_1[1])(param_1,1,0x500);
    *param_4 = iVar3;
  }
  iVar3 = *param_4;
  iVar9 = 0;
  iStack_518 = 1;
  do {
    bVar2 = *(byte *)(iStack_518 + local_514);
    uVar6 = (uint)bVar2;
    if (0x100 < (int)(iVar9 + uVar6)) {
      *(undefined4 *)(*param_1 + 0x14) = 9;
      (**(code **)*param_1)(param_1);
    }
    if (uVar6 != 0) {
      cVar7 = (char)iStack_518;
      pcVar11 = acStack_508 + iVar9;
      for (uVar5 = (uint)(bVar2 >> 2); uVar5 != 0; uVar5 = uVar5 - 1) {
        *(uint *)pcVar11 = CONCAT22(CONCAT11(cVar7,cVar7),CONCAT11(cVar7,cVar7));
        pcVar11 = pcVar11 + 4;
      }
      iVar9 = iVar9 + uVar6;
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar11 = cVar7;
        pcVar11 = pcVar11 + 1;
      }
    }
    iStack_518 = iStack_518 + 1;
  } while (iStack_518 < 0x11);
  acStack_508[iVar9] = '\0';
  iVar12 = 0;
  iVar10 = 0;
  iVar8 = (int)acStack_508[0];
  while (acStack_508[0] != '\0') {
    if (acStack_508[iVar10] == iVar8) {
      piVar4 = aiStack_404 + iVar10;
      do {
        cVar7 = acStack_508[iVar10 + 1];
        iVar10 = iVar10 + 1;
        *piVar4 = iVar12;
        piVar4 = piVar4 + 1;
        iVar12 = iVar12 + 1;
      } while (cVar7 == iVar8);
    }
    if (1 << ((byte)iVar8 & 0x1f) <= iVar12) {
      *(undefined4 *)(*param_1 + 0x14) = 9;
      (**(code **)*param_1)(param_1);
    }
    iVar12 = iVar12 << 1;
    iVar8 = iVar8 + 1;
    acStack_508[0] = acStack_508[iVar10];
  }
  puVar1 = (undefined4 *)(iVar3 + 0x400);
  puVar13 = puVar1;
  for (iVar12 = 0x40; iVar12 != 0; iVar12 = iVar12 + -1) {
    *puVar13 = 0;
    puVar13 = puVar13 + 1;
  }
  iVar12 = 0;
  if (0 < iVar9) {
    piVar4 = aiStack_404;
    do {
      uVar6 = (uint)*(byte *)(local_514 + 0x11 + iVar12);
      if (((int)((-(uint)(param_2 != '\0') & 0xffffff10) + 0xff) < (int)uVar6) ||
         (*(char *)(uVar6 + (int)puVar1) != '\0')) {
        *(undefined4 *)(*param_1 + 0x14) = 9;
        (**(code **)*param_1)(param_1);
      }
      cVar7 = acStack_508[iVar12];
      iVar12 = iVar12 + 1;
      *(int *)(iVar3 + uVar6 * 4) = *piVar4;
      piVar4 = piVar4 + 1;
      *(char *)(uVar6 + (int)puVar1) = cVar7;
    } while (iVar12 < iVar9);
  }
  return;
}

