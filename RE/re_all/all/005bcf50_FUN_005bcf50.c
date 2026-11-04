
void __fastcall FUN_005bcf50(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  
  DAT_00ef72cc = 0;
  DAT_00a3d360 = 0;
  if (((param_1 & 0x200) == 0) || (DAT_00a38de0 != 0)) {
    if (DAT_00f07614 == 1) {
      uVar9 = 0;
LAB_005bcf9c:
      FUN_005bb060(uVar9);
    }
  }
  else if (DAT_00a3d258 == 0) {
    if (DAT_00f07614 == 0) {
      uVar9 = 1;
      goto LAB_005bcf9c;
    }
  }
  else {
    FUN_00524c30();
  }
  if (DAT_00a38de4 != 0) {
    DAT_00a38de4 = 0;
    FUN_005b9a40(&DAT_00a38de8);
  }
  if ((DAT_00a38e3c == 0) != DAT_00f07670) {
    FUN_005b9c00((uint)(DAT_00a38e3c == 0));
  }
  if ((DAT_00a38e40 == 0) != DAT_00f07674) {
    FUN_005b9c80((uint)(DAT_00a38e40 == 0));
  }
  if ((DAT_00a380f4 == 0) && ((param_1 & 0x400) != 0)) {
    iVar1 = 1;
  }
  else {
    iVar1 = 0;
  }
  if (iVar1 != DAT_00f07618) {
    FUN_005b9b80(iVar1);
  }
  if ((param_1 & 0x800) == 0) {
    iVar1 = DAT_00a37fb0;
    uVar4 = DAT_00a37fb4;
    iVar5 = DAT_00a37fb8;
    iVar7 = DAT_00a37fbc;
  }
  else {
    iVar1 = DAT_00a37fc0;
    uVar4 = DAT_00a37fc4;
    iVar5 = DAT_00a37fc8;
    iVar7 = DAT_00a37fcc;
  }
  if (iVar1 == 0) {
    if (DAT_00f13214 != 0) {
      FUN_005b9210(0);
    }
    if ((DAT_00f13218 != 0) && (DAT_00f3a070 != 0)) {
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      DAT_00f13210 = 1;
      DAT_00f13218 = 0;
      DAT_00ef72cc = 1;
    }
  }
  else {
    if (DAT_00f13214 != iVar1) {
      FUN_005b9210(iVar1);
    }
    if ((DAT_00f13218 == 1) != uVar4) {
      FUN_005b9270(uVar4);
    }
    if (DAT_00f1321c != iVar5) {
      FUN_005b92d0(iVar5);
    }
    if (DAT_00f130ec != iVar7) {
      FUN_005b9330(iVar7);
    }
  }
  if (DAT_00f130e0 != DAT_00a37fd8) {
    FUN_005b9390(DAT_00a37fd8);
  }
  if ((param_1 & 0x80) == 0) {
    if (DAT_00f07360 == 0) goto LAB_005bd139;
    iVar1 = 0;
  }
  else {
    if (DAT_00f07360 == DAT_00a380a0) goto LAB_005bd139;
    iVar1 = DAT_00a380a0;
  }
  FUN_005badf0(iVar1);
LAB_005bd139:
  if ((param_1 & 0x100) == 0) {
    uVar6 = 0;
    uVar4 = 0;
    if (((param_1 & 0x8000) != 0) && ((param_1 & 1) != 0)) {
      uVar2 = param_1 >> 0x11 & 1;
      uVar3 = param_1 >> 0x10 & 1;
      if ((uVar2 != 0) || (uVar3 != 0)) {
        if (((DAT_00a380cc == 0) || (DAT_00a380cc == 8)) &&
           (((param_1 & 2) != 0 || (DAT_00a380bc != 1)))) {
          uVar4 = uVar3;
          uVar6 = uVar2;
        }
        else {
          uVar4 = 1;
        }
      }
    }
    if (DAT_00ef72ec != DAT_00a3811c) {
      FUN_005bc340(DAT_00a3811c);
    }
    if (((DAT_00ef72e0 != DAT_00a380cc) || (DAT_00ef72d4 != uVar6)) || (DAT_00ef72d0 != uVar4)) {
      FUN_005bc2c0(DAT_00a380cc,uVar6,uVar4);
    }
    if ((DAT_00ef72d8 != DAT_00a380ec) || (DAT_00ef72dc != DAT_00a380f0)) {
      FUN_005bc420(DAT_00a380ec,DAT_00a380f0);
    }
    if (((DAT_00ef72e4 != 0) || (DAT_00ef72e8 != 0)) || ((DAT_00a37dc8 != 0 && (DAT_00f136e8 == 0)))
       ) {
      FUN_005bbac0();
    }
  }
  if (DAT_00f07678 != DAT_00a380bc) {
    FUN_005bb1f0(DAT_00a380bc);
  }
  if (DAT_00f0767c != DAT_00a380c0) {
    FUN_005bb0b0(DAT_00a380c0,0xffffffff);
  }
  if ((param_1 & 0x4000) == 0) {
    if ((DAT_00f130e4 != 1) && (DAT_00f3a070 != 0)) {
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      DAT_00f130dc = 1;
      DAT_00f130e4 = 1;
      DAT_00ef72cc = 1;
    }
  }
  else {
    if (DAT_00f130e4 == 2) {
      iVar1 = 2;
    }
    else if (DAT_00f130e4 == 3) {
      iVar1 = 1;
    }
    else {
      iVar1 = 0;
    }
    if (iVar1 != DAT_00a37fdc) {
      FUN_005b9d00(DAT_00a37fdc);
    }
  }
  if (DAT_00a38d34 == 0) {
    FUN_005bad70(DAT_00a38d30,&DAT_00a38d38);
    DAT_00a38d34 = 1;
    DAT_00ef72cc = 1;
  }
  if ((param_1 & 0x1000) == 0) {
    iVar1 = 0;
    piVar8 = &DAT_00f076cc;
    do {
      if ((piVar8[-1] != 3) || (*piVar8 != 3)) {
        FUN_005ba760(3,iVar1);
      }
      piVar8 = piVar8 + 0xd;
      iVar1 = iVar1 + 1;
    } while ((int)piVar8 < 0xf0779c);
    DAT_00ef72c8 = param_1;
    return;
  }
  iVar1 = 0;
  piVar8 = &DAT_00f076cc;
  do {
    iVar5 = (&DAT_00a37fe0)[iVar1];
    if (iVar5 == (&DAT_00a38020)[iVar1]) {
      if ((piVar8[-1] != iVar5) || (*piVar8 != (&DAT_00a38020)[iVar1])) {
        FUN_005ba760(iVar5,iVar1);
      }
    }
    else {
      if (piVar8[-1] != iVar5) {
        FUN_005ba900(iVar5,iVar1);
      }
      if (*piVar8 != (&DAT_00a38020)[iVar1]) {
        FUN_005baa30((&DAT_00a38020)[iVar1],iVar1);
      }
    }
    piVar8 = piVar8 + 0xd;
    iVar1 = iVar1 + 1;
  } while ((int)piVar8 < 0xf07a0c);
  DAT_00ef72c8 = param_1;
  return;
}

