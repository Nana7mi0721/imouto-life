
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0055f060(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  float fVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int unaff_ESI;
  char *pcVar7;
  int iVar8;
  int local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20 [8];
  
  iVar3 = *(int *)(unaff_ESI + 0x252c) * 0x1b8;
  iVar8 = iVar3 + 0xc4 + unaff_ESI;
  if ((*(int *)(iVar3 + 0xc4 + unaff_ESI) == 0) ||
     ((DAT_00a83c64 == 0 && (iVar3 = FUN_0057ee10(iVar8,&local_2c,0), iVar3 != 2)))) {
    iVar8 = local_2c;
  }
  else {
    iVar8 = *(int *)(iVar8 + 0x54) * (uint)*(ushort *)(iVar8 + 0x3c);
  }
  iVar3 = *(int *)(unaff_ESI + 0x252c) + 1;
  local_24 = 0;
  if (*(int *)(unaff_ESI + 0x70) <= iVar3) {
    iVar3 = 0;
  }
  *(int *)(unaff_ESI + 0x252c) = iVar3;
  piVar1 = (int *)(iVar3 * 0x1b8 + 0xc4 + unaff_ESI);
  if (*(int *)(iVar3 * 0x1b8 + 0xc4 + unaff_ESI) != 0) {
    if (DAT_00a83c64 == 0) {
      iVar3 = FUN_0057e790(piVar1);
    }
    else {
      iVar3 = piVar1[0x14];
    }
    if (iVar3 != -1) {
      if (iVar3 != 0) {
        if (param_1 == 0) {
          return 1;
        }
        FUN_00551830(piVar1,0);
      }
      if (param_1 == 1) {
        iVar8 = 0;
      }
      FUN_00551d10(piVar1,iVar8);
      local_2c = -0x2560 - unaff_ESI;
      fVar4 = (float)(-0x25d4 - unaff_ESI);
      pcVar7 = (char *)(unaff_ESI + 0x25d4);
      puVar5 = local_20;
      puVar6 = (undefined4 *)(unaff_ESI + 0x2568);
      local_28 = fVar4;
      do {
        if (*pcVar7 == '\0') {
          *puVar5 = *puVar6;
        }
        else {
          *puVar5 = puVar6[0x1f];
          *pcVar7 = '\0';
        }
        if ((*piVar1 != 0) && (pcVar7 + (int)fVar4 < (char *)0x8)) {
          *(undefined4 *)(local_2c + (int)puVar6 + (int)piVar1) = *puVar5;
          FUN_00551a70(piVar1);
          fVar4 = local_28;
        }
        pcVar7 = pcVar7 + 1;
        puVar6 = puVar6 + 1;
        puVar5 = puVar5 + 1;
      } while ((int)(pcVar7 + (int)fVar4) < 8);
      if (*(char *)(unaff_ESI + 0x25dc) == '\0') {
        iVar8 = *(int *)(unaff_ESI + 0x25a8);
      }
      else {
        iVar8 = *(int *)(unaff_ESI + 0x2604);
        *(undefined1 *)(unaff_ESI + 0x25dc) = 0;
      }
      if (*piVar1 != 0) {
        if (iVar8 < -10000) {
          iVar8 = -10000;
        }
        else if (10000 < iVar8) {
          iVar8 = 10000;
        }
        piVar1[1] = iVar8;
        FUN_00551a70(piVar1);
      }
      if (*(char *)(unaff_ESI + 0x25dd) == '\0') {
        iVar8 = *(int *)(unaff_ESI + 0x25ac);
      }
      else {
        iVar8 = *(int *)(unaff_ESI + 0x2608);
        *(undefined1 *)(unaff_ESI + 0x25dd) = 0;
      }
      if (*(int *)(unaff_ESI + 0x25cc) != 0) {
        local_28 = (float)iVar8;
        if (iVar8 < 0) {
          local_28 = local_28 + _DAT_007d4bd8;
        }
        local_28 = local_28 * *(float *)(unaff_ESI + 0x25d0);
        iVar8 = (int)ROUND(local_28);
      }
      if (*piVar1 != 0) {
        if (iVar8 == 0) {
          piVar1[10] = -1;
        }
        else {
          piVar1[10] = iVar8;
        }
        if (DAT_00a83c64 == 0) {
          FUN_0057e970(piVar1,iVar8);
        }
      }
      if (*(int *)(unaff_ESI + 0x40) != 0) {
        if (*(char *)(unaff_ESI + 0x25de) == '\0') {
          iVar8 = unaff_ESI + 0x25b0;
        }
        else {
          iVar8 = unaff_ESI + 0x260c;
          *(undefined1 *)(unaff_ESI + 0x25de) = 0;
        }
        if (*(char *)(unaff_ESI + 0x25df) == '\0') {
          uVar2 = *(undefined4 *)(unaff_ESI + 0x25bc);
        }
        else {
          uVar2 = *(undefined4 *)(unaff_ESI + 0x2618);
          *(undefined1 *)(unaff_ESI + 0x25df) = 0;
        }
        if (*(char *)(unaff_ESI + 0x25e0) == '\0') {
          iVar3 = unaff_ESI + 0x25c0;
        }
        else {
          iVar3 = unaff_ESI + 0x261c;
          *(undefined1 *)(unaff_ESI + 0x25e0) = 0;
        }
        FUN_0055d430(piVar1,iVar8);
        FUN_0055d560(piVar1,uVar2);
        FUN_0055d630(piVar1,iVar3);
        if (((piVar1[0x1c] != 0) && (*piVar1 != 0)) && (piVar1[0x2f] != 0)) {
          if ((DAT_00a83c64 == 0) && (iVar8 = FUN_0057efd0(piVar1,0), iVar8 < 0)) {
            return 0;
          }
          piVar1[0x2f] = 0;
        }
      }
      return 0;
    }
  }
  return 0xffffffff;
}

