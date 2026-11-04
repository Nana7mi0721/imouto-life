
void FUN_00691ce0(int *param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 local_82c;
  undefined4 uStack_828;
  undefined4 uStack_824;
  undefined4 uStack_820;
  char acStack_81c [20];
  int local_808 [257];
  int local_404 [257];
  
  puVar8 = &local_82c;
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *(undefined1 *)puVar8 = 0;
  param_3[0x100] = 1;
  piVar7 = local_808;
  for (iVar4 = 0x101; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  piVar7 = local_404;
  for (iVar4 = 0x101; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar7 = -1;
    piVar7 = piVar7 + 1;
  }
  while( true ) {
    iVar4 = -1;
    iVar9 = 1000000000;
    iVar5 = 0;
    piVar7 = param_3;
    do {
      iVar6 = *piVar7;
      if ((iVar6 != 0) && (iVar6 <= iVar9)) {
        iVar4 = iVar5;
        iVar9 = iVar6;
      }
      iVar5 = iVar5 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar5 < 0x101);
    iVar9 = -1;
    iVar5 = 1000000000;
    iVar6 = 0;
    piVar7 = param_3;
    do {
      iVar2 = *piVar7;
      if (((iVar2 != 0) && (iVar2 <= iVar5)) && (iVar6 != iVar4)) {
        iVar9 = iVar6;
        iVar5 = iVar2;
      }
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar6 < 0x101);
    if (iVar9 < 0) break;
    iVar5 = local_808[iVar4];
    iVar6 = local_404[iVar4];
    param_3[iVar4] = param_3[iVar4] + param_3[iVar9];
    param_3[iVar9] = 0;
    local_808[iVar4] = iVar5 + 1;
    while (iVar5 = iVar6, -1 < iVar5) {
      local_808[iVar5] = local_808[iVar5] + 1;
      iVar6 = local_404[iVar5];
      iVar4 = iVar5;
    }
    iVar5 = local_808[iVar9];
    local_404[iVar4] = iVar9;
    iVar4 = local_404[iVar9];
    local_808[iVar9] = iVar5 + 1;
    for (; -1 < iVar4; iVar4 = local_404[iVar4]) {
      local_808[iVar4] = local_808[iVar4] + 1;
    }
  }
  piVar7 = local_808;
  iVar4 = 0x101;
  do {
    iVar9 = *piVar7;
    if (iVar9 != 0) {
      if (0x20 < iVar9) {
        *(undefined4 *)(*param_1 + 0x14) = 0x28;
        (**(code **)*param_1)(param_1);
      }
      acStack_81c[iVar9 + -0x10] = acStack_81c[iVar9 + -0x10] + '\x01';
    }
    piVar7 = piVar7 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = 0x20;
  do {
    iVar9 = iVar4;
    cVar3 = acStack_81c[iVar9 + -0x10];
    if (cVar3 != '\0') {
      do {
        cVar1 = acStack_81c[iVar9 + -0x12];
        iVar4 = iVar9 + -2;
        while (cVar1 == '\0') {
          iVar5 = iVar4 + -0x11;
          iVar4 = iVar4 + -1;
          cVar1 = acStack_81c[iVar5];
        }
        acStack_81c[iVar9 + -0x10] = cVar3 + -2;
        acStack_81c[iVar9 + -0x11] = acStack_81c[iVar9 + -0x11] + '\x01';
        acStack_81c[iVar4 + -0xf] = acStack_81c[iVar4 + -0xf] + '\x02';
        acStack_81c[iVar4 + -0x10] = acStack_81c[iVar4 + -0x10] + -1;
        cVar3 = acStack_81c[iVar9 + -0x10];
      } while (cVar3 != '\0');
    }
    iVar4 = iVar9 + -1;
  } while (0x10 < iVar4);
  cVar3 = acStack_81c[iVar9 + -0x11];
  while (cVar3 == '\0') {
    iVar9 = iVar4 + -0x11;
    iVar4 = iVar4 + -1;
    cVar3 = acStack_81c[iVar9];
  }
  iVar9 = 1;
  acStack_81c[iVar4 + -0x10] = acStack_81c[iVar4 + -0x10] + -1;
  *param_2 = local_82c;
  param_2[1] = uStack_828;
  param_2[2] = uStack_824;
  param_2[3] = uStack_820;
  *(char *)(param_2 + 4) = acStack_81c[0];
  iVar4 = 0;
  do {
    iVar5 = 0;
    piVar7 = local_808;
    do {
      if (*piVar7 == iVar9) {
        *(char *)(iVar4 + 0x11 + (int)param_2) = (char)iVar5;
        iVar4 = iVar4 + 1;
      }
      iVar5 = iVar5 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar5 < 0x100);
    iVar9 = iVar9 + 1;
  } while (iVar9 < 0x21);
  *(undefined1 *)((int)param_2 + 0x111) = 0;
  return;
}

