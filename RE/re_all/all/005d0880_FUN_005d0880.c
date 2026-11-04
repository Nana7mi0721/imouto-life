
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d0880(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  DAT_00ef7324 = 1;
  DAT_00ef72e8 = 1;
  if (DAT_00ef7314 != 0) {
    DAT_00ef72e4 = 1;
  }
  DAT_00ef72cc = 1;
  DAT_00ef7314 = 0;
  DAT_00ef7318 = 0;
  DAT_00ef72d0 = 0;
  DAT_00ef72d4 = 0;
  DAT_00f07334 = 0;
  FUN_005bc2c0(DAT_00ef72e0,0,0);
  FUN_005bc340(DAT_00ef72ec);
  FUN_005bc3b0(DAT_00ef72f0);
  FUN_005bb0b0(DAT_00f0767c,0xffffffff);
  puVar5 = &DAT_00f076cc;
  iVar7 = 0;
  do {
    uVar1 = puVar5[1];
    uVar2 = *puVar5;
    iVar4 = FUN_005ba900(puVar5[-1],iVar7);
    if ((-1 < iVar4) && (iVar4 = FUN_005baa30(uVar2,iVar7), -1 < iVar4)) {
      FUN_005bab60(uVar1,iVar7);
    }
    puVar5 = puVar5 + 0xd;
    iVar7 = iVar7 + 1;
  } while ((int)puVar5 < 0xf07a0c);
  FUN_005bad70(DAT_00f138e0,&DAT_00f138e4);
  if ((DAT_00f3a070 != 0) && (DAT_00ef7324 != 0)) {
    FUN_005d2cf0(DAT_00f13674);
  }
  uVar1 = DAT_00f07360;
  if ((DAT_00f3a070 != 0) && (DAT_00ef7324 != 0)) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    DAT_00ef72cc = 1;
  }
  uVar2 = DAT_00f07364;
  DAT_00f07360 = uVar1;
  if ((DAT_00f3a070 != 0) && (DAT_00ef7324 != 0)) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    DAT_00ef72cc = 1;
  }
  DAT_00f07364 = uVar2;
  FUN_005bae90(DAT_00f07368);
  FUN_005bafc0(_DAT_00f0736c,_DAT_00f07370);
  fVar3 = _DAT_00f07374;
  if ((DAT_00f3a070 != 0) && ((NAN(_DAT_00f07374) || (DAT_00ef7324 != 0)))) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    _DAT_00f07374 = fVar3;
    FUN_005baf50();
    DAT_00ef72cc = 1;
  }
  FUN_00521bf0(&DAT_00a38290);
  FUN_00521cd0(&DAT_00a38358);
  FUN_00524ad0(&DAT_00a38420);
  FUN_00521d40(&DAT_00a38718);
  FUN_005b9d80(&DAT_00f07378);
  uVar1 = DAT_00f07614;
  if ((DAT_00f3a070 != 0) && (DAT_00ef7324 != 0)) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    DAT_00ef72cc = 1;
  }
  iVar7 = 0;
  piVar6 = &DAT_00f073a4;
  DAT_00f07614 = uVar1;
  do {
    if (*piVar6 != 0) {
      FUN_005b97c0(iVar7,piVar6);
      FUN_005b9980(iVar7,(&DAT_00f0738c)[iVar7]);
    }
    piVar6 = piVar6 + 0x1a;
    iVar7 = iVar7 + 1;
  } while ((int)piVar6 < 0xf07614);
  DAT_00ef7324 = 0;
  FUN_005cb6f0();
  return 0;
}

