
undefined4 __thiscall FUN_00561500(undefined4 param_1,uint param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *in_EAX;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  int unaff_EDI;
  undefined4 local_8;
  
  FUN_0055fa80(param_1);
  if (in_EAX != (undefined4 *)0x0) {
    *in_EAX = local_8;
  }
  if ((param_3 == 0) && (iVar3 = FUN_005606e0(param_1), iVar3 == 1)) {
    return 1;
  }
  FUN_0055e7e0(param_1);
  if (((*(uint *)(unaff_EDI + 0x120c) != param_2) &&
      (((*(uint *)(unaff_EDI + 0x120c) ^ param_2) & 2) != 0)) &&
     (*(char *)(unaff_EDI + 0x24d7) == '\x01')) {
    *(undefined1 *)(unaff_EDI + 0x24d7) = 0;
    *(undefined4 *)(unaff_EDI + 0x24c0) = 0;
    *(undefined4 *)(unaff_EDI + 0x24cc) = 0;
    *(undefined1 *)(unaff_EDI + 0x24d6) = 0;
    *(undefined4 *)(unaff_EDI + 0x24bc) = 0;
    *(undefined4 *)(unaff_EDI + 0x24b8) = 0;
    *(undefined1 *)(unaff_EDI + 0x24d4) = 0;
  }
  if ((param_3 == 1) && (*(undefined1 *)(unaff_EDI + 0x24d7) = 0, *(int *)(unaff_EDI + 0x24cc) != 0)
     ) {
    *(undefined4 *)(unaff_EDI + 0x24c0) = 0;
    *(undefined4 *)(unaff_EDI + 0x24cc) = 0;
    *(undefined1 *)(unaff_EDI + 0x24d6) = 0;
    *(undefined4 *)(unaff_EDI + 0x24bc) = 0;
    *(undefined4 *)(unaff_EDI + 0x24b8) = 0;
    *(undefined1 *)(unaff_EDI + 0x24d4) = 0;
  }
  *(uint *)(unaff_EDI + 0x120c) = param_2;
  FUN_00561320(param_1,0);
  piVar1 = (int *)(unaff_EDI + 0xc4);
  pcVar4 = (char *)(unaff_EDI + 0x25d4);
  puVar6 = (undefined4 *)(unaff_EDI + 0x2568);
  param_3 = 8;
  do {
    if (*pcVar4 == '\0') {
      uVar2 = *puVar6;
      if (*piVar1 != 0) {
        *(undefined4 *)(unaff_EDI + 0xcc) = uVar2;
        *(undefined4 *)(unaff_EDI + 0xd0) = uVar2;
        *(undefined4 *)(unaff_EDI + 0xd4) = uVar2;
        *(undefined4 *)(unaff_EDI + 0xd8) = uVar2;
        *(undefined4 *)(unaff_EDI + 0xdc) = uVar2;
        *(undefined4 *)(unaff_EDI + 0xe0) = uVar2;
        *(undefined4 *)(unaff_EDI + 0xe4) = uVar2;
        *(undefined4 *)(unaff_EDI + 0xe8) = uVar2;
        FUN_00551a70(piVar1);
      }
    }
    else {
      uVar2 = puVar6[0x1f];
      if (*piVar1 != 0) {
        *(undefined4 *)(unaff_EDI + 0xcc) = uVar2;
        *(undefined4 *)(unaff_EDI + 0xd0) = uVar2;
        *(undefined4 *)(unaff_EDI + 0xd4) = uVar2;
        *(undefined4 *)(unaff_EDI + 0xd8) = uVar2;
        *(undefined4 *)(unaff_EDI + 0xdc) = uVar2;
        *(undefined4 *)(unaff_EDI + 0xe0) = uVar2;
        *(undefined4 *)(unaff_EDI + 0xe4) = uVar2;
        *(undefined4 *)(unaff_EDI + 0xe8) = uVar2;
        FUN_00551a70(piVar1);
      }
      *pcVar4 = '\0';
    }
    puVar6 = puVar6 + 1;
    pcVar4 = pcVar4 + 1;
    param_3 = param_3 + -1;
  } while (param_3 != 0);
  if (*(char *)(unaff_EDI + 0x25dc) == '\0') {
    iVar3 = *(int *)(unaff_EDI + 0x25a8);
    if (*piVar1 != 0) {
      if (iVar3 < -10000) {
        iVar3 = -10000;
      }
      else if (10000 < iVar3) {
        iVar3 = 10000;
      }
      *(int *)(unaff_EDI + 200) = iVar3;
      FUN_00551a70(piVar1);
    }
  }
  else {
    iVar3 = *(int *)(unaff_EDI + 0x2604);
    if (*piVar1 != 0) {
      if (iVar3 < -10000) {
        iVar3 = -10000;
      }
      else if (10000 < iVar3) {
        iVar3 = 10000;
      }
      *(int *)(unaff_EDI + 200) = iVar3;
      FUN_00551a70(piVar1);
    }
    *(undefined1 *)(unaff_EDI + 0x25dc) = 0;
  }
  if (*(char *)(unaff_EDI + 0x25dd) == '\0') {
    iVar3 = *(int *)(unaff_EDI + 0x25ac);
  }
  else {
    iVar3 = *(int *)(unaff_EDI + 0x2608);
    *(undefined1 *)(unaff_EDI + 0x25dd) = 0;
  }
  if (*(int *)(unaff_EDI + 0x25cc) != 0) {
    iVar3 = (int)ROUND(*(float *)(unaff_EDI + 0x25d0) * (float)iVar3);
  }
  if (*piVar1 != 0) {
    if (iVar3 == 0) {
      *(undefined4 *)(unaff_EDI + 0xec) = 0xffffffff;
    }
    else {
      *(int *)(unaff_EDI + 0xec) = iVar3;
    }
    if (DAT_00a83c64 == 0) {
      FUN_0057e970(piVar1,iVar3);
    }
  }
  if (*(int *)(unaff_EDI + 0x40) != 0) {
    if (*(char *)(unaff_EDI + 0x25de) == '\0') {
      iVar3 = unaff_EDI + 0x25b0;
    }
    else {
      iVar3 = unaff_EDI + 0x260c;
      *(undefined1 *)(unaff_EDI + 0x25de) = 0;
    }
    if (*(char *)(unaff_EDI + 0x25df) == '\0') {
      uVar2 = *(undefined4 *)(unaff_EDI + 0x25bc);
    }
    else {
      uVar2 = *(undefined4 *)(unaff_EDI + 0x2618);
      *(undefined1 *)(unaff_EDI + 0x25df) = 0;
    }
    if (*(char *)(unaff_EDI + 0x25e0) == '\0') {
      iVar5 = unaff_EDI + 0x25c0;
    }
    else {
      iVar5 = unaff_EDI + 0x261c;
      *(undefined1 *)(unaff_EDI + 0x25e0) = 0;
    }
    FUN_0055d430(piVar1,iVar3);
    FUN_0055d560(piVar1,uVar2);
    FUN_0055d630(piVar1,iVar5);
    if (((*(int *)(unaff_EDI + 0x134) != 0) && (*piVar1 != 0)) &&
       ((*(int *)(unaff_EDI + 0x180) != 0 &&
        ((DAT_00a83c64 != 0 || (iVar3 = FUN_0057efd0(piVar1,0), -1 < iVar3)))))) {
      *(undefined4 *)(unaff_EDI + 0x180) = 0;
    }
  }
  return 0;
}

