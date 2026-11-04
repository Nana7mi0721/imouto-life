
void FUN_006894f0(int *param_1,char param_2,int param_3,int *param_4)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined1 *puVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  int iVar12;
  undefined1 *puVar13;
  int iStack_524;
  int local_520;
  int iStack_51c;
  int *piStack_518;
  int iStack_510;
  char acStack_508 [256];
  int aiStack_408 [258];
  
  if ((param_3 < 0) || (3 < param_3)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x34;
    *(int *)(*param_1 + 0x18) = param_3;
    (**(code **)*param_1)(param_1);
  }
  if (param_2 == '\0') {
    local_520 = param_1[param_3 + 0x2c];
  }
  else {
    local_520 = param_1[param_3 + 0x28];
  }
  if (local_520 == 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x34;
    *(int *)(*param_1 + 0x18) = param_3;
    (**(code **)*param_1)(param_1);
  }
  if (*param_4 == 0) {
    iVar2 = (**(code **)param_1[1])(param_1,1,0x590);
    *param_4 = iVar2;
  }
  param_4 = (int *)*param_4;
  iVar2 = 0;
  param_4[0x23] = local_520;
  iStack_524 = 1;
  do {
    bVar1 = *(byte *)(iStack_524 + local_520);
    uVar5 = (uint)bVar1;
    if (0x100 < (int)(iVar2 + uVar5)) {
      *(undefined4 *)(*param_1 + 0x14) = 9;
      (**(code **)*param_1)(param_1);
    }
    if (uVar5 != 0) {
      cVar8 = (char)iStack_524;
      pcVar11 = acStack_508 + iVar2;
      for (uVar4 = (uint)(bVar1 >> 2); uVar4 != 0; uVar4 = uVar4 - 1) {
        *(uint *)pcVar11 = CONCAT22(CONCAT11(cVar8,cVar8),CONCAT11(cVar8,cVar8));
        pcVar11 = pcVar11 + 4;
      }
      iVar2 = iVar2 + uVar5;
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar11 = cVar8;
        pcVar11 = pcVar11 + 1;
      }
    }
    iStack_524 = iStack_524 + 1;
  } while (iStack_524 < 0x11);
  acStack_508[iVar2] = '\0';
  iVar12 = 0;
  iVar10 = 0;
  iVar9 = (int)acStack_508[0];
  while (acStack_508[0] != '\0') {
    if (acStack_508[iVar10] == iVar9) {
      piVar3 = aiStack_408 + iVar10 + 1;
      do {
        cVar8 = acStack_508[iVar10 + 1];
        iVar10 = iVar10 + 1;
        *piVar3 = iVar12;
        piVar3 = piVar3 + 1;
        iVar12 = iVar12 + 1;
      } while (cVar8 == iVar9);
    }
    if (1 << ((byte)iVar9 & 0x1f) <= iVar12) {
      *(undefined4 *)(*param_1 + 0x14) = 9;
      (**(code **)*param_1)(param_1);
    }
    iVar12 = iVar12 << 1;
    iVar9 = iVar9 + 1;
    acStack_508[0] = acStack_508[iVar10];
  }
  iVar10 = 0;
  iVar12 = 1;
  piVar3 = param_4;
  do {
    piVar6 = piVar3 + 1;
    if (*(char *)(iVar12 + local_520) == '\0') {
      *piVar6 = -1;
    }
    else {
      piVar3[0x13] = iVar10 - aiStack_408[iVar10 + 1];
      iVar10 = iVar10 + (uint)*(byte *)(iVar12 + local_520);
      *piVar6 = aiStack_408[iVar10];
    }
    iVar12 = iVar12 + 1;
    piVar3 = piVar6;
  } while (iVar12 < 0x11);
  iVar12 = 0;
  param_4[0x11] = 0xfffff;
  piVar3 = param_4 + 0x24;
  for (iVar10 = 0x100; iVar10 != 0; iVar10 = iVar10 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  iStack_524 = 0;
  iVar10 = 1;
  iStack_510 = 7;
  do {
    iStack_51c = 1;
    if (*(char *)(local_520 + iVar10) != '\0') {
      puVar13 = (undefined1 *)(iVar12 + 0x11 + local_520);
      piStack_518 = aiStack_408 + iVar12 + 1;
      iVar9 = 1 << ((byte)iStack_510 & 0x1f);
      do {
        iVar12 = *piStack_518 << ((byte)iStack_510 & 0x1f);
        if (0 < iVar9) {
          puVar7 = (undefined1 *)(iVar12 + 0x490 + (int)param_4);
          piVar3 = param_4 + iVar12 + 0x24;
          iVar12 = iVar9;
          do {
            *piVar3 = iVar10;
            *puVar7 = *puVar13;
            piVar3 = piVar3 + 1;
            puVar7 = puVar7 + 1;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
        iStack_51c = iStack_51c + 1;
        iVar12 = iStack_524 + 1;
        piStack_518 = piStack_518 + 1;
        puVar13 = puVar13 + 1;
        iStack_524 = iVar12;
      } while (iStack_51c <= (int)(uint)*(byte *)(local_520 + iVar10));
    }
    iVar10 = iVar10 + 1;
    iStack_510 = iStack_510 + -1;
  } while (-1 < iStack_510);
  if ((param_2 != '\0') && (iVar12 = 0, 0 < iVar2)) {
    do {
      if (0xf < *(byte *)(local_520 + 0x11 + iVar12)) {
        *(undefined4 *)(*param_1 + 0x14) = 9;
        (**(code **)*param_1)(param_1);
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < iVar2);
  }
  return;
}

