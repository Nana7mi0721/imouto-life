
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005c09b0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  int *local_34;
  int *local_30;
  int *local_28;
  
  piVar15 = (int *)0x0;
  local_34 = (int *)0x0;
  local_28 = (int *)0x0;
  local_30 = (int *)0x0;
  if ((DAT_00f24518 == 0) && (iVar5 = FUN_005b7340(), iVar5 == 0)) {
    return 0;
  }
  iVar5 = 1;
  if (((DAT_00ef72d0 != 0) || (DAT_00ef72d4 != 0)) || (DAT_00f13214 != 0)) {
    iVar5 = 0;
  }
  if (iVar5 != DAT_00ef72f0) {
    FUN_005bc3b0(iVar5);
  }
  iVar5 = DAT_00ef72e0;
  if (DAT_00ef72e0 == 0) {
    if (DAT_00a380c8 != 0) {
      iVar5 = 0xe;
    }
    if ((DAT_00ef7314 != 0) && (DAT_00ef72d0 == 1)) {
      iVar5 = 1;
    }
  }
  else if (DAT_00ef72e0 == 3) {
    iVar5 = 0x10;
  }
  uVar10 = (uint)(DAT_00a38104 != 0);
  uVar6 = -(uint)(DAT_00f07360 != 0) & DAT_00f07364;
  iVar5 = *(int *)(&DAT_0085fc20 + iVar5 * 0x28);
  if (DAT_00a3810c == 0) {
    if (DAT_00f07614 == 0) {
      piVar12 = &DAT_00ef44b4 + uVar6;
      puVar8 = (undefined4 *)(&DAT_00f28ef0 + uVar6 * 8);
      piVar14 = &DAT_00ef474c + DAT_00f13670 + iVar5 * 2;
      piVar13 = &DAT_00f29420 + (DAT_00f13670 + iVar5 * 2) * 2;
      goto LAB_005c0c6e;
    }
    uVar7 = -(uint)(DAT_00f0738c != 0) & DAT_00f073a4;
    uVar9 = -(uint)(DAT_00f07390 != 0) & DAT_00f0740c;
    uVar11 = -(uint)(DAT_00f07394 != 0) & DAT_00f07474;
    iVar1 = uVar11 + (uVar9 + uVar7 * 4) * 4;
    if (uVar7 == 3) {
      uVar7 = 2;
    }
    else {
      uVar7 = (uint)(uVar7 != 0);
    }
    if (uVar9 == 3) {
      uVar9 = 2;
    }
    else {
      uVar9 = (uint)(uVar9 != 0);
    }
    if (uVar11 == 3) {
      uVar11 = 2;
    }
    else {
      uVar11 = (uint)(uVar11 != 0);
    }
    iVar2 = uVar6 + uVar10 * 4;
    piVar15 = &DAT_00ef1fcc + iVar2;
    local_34 = (int *)(&DAT_00f24520 + iVar2 * 8);
    iVar3 = (uVar10 * 0x54 +
            (int)*(short *)(&DAT_00f203b4 +
                           ((-(uint)(DAT_00f073a0 != 0) & _DAT_00f075ac) +
                           ((-(uint)(DAT_00f0739c != 0) & _DAT_00f07544) +
                           ((-(uint)(DAT_00f07398 != 0) & _DAT_00f074dc) + iVar1 * 4) * 4) * 4) * 2)
            ) * 7 + iVar5;
    local_30 = &DAT_00f24560 + (DAT_00f13670 + iVar3 * 2) * 2;
    iVar1 = (int)(short)(&DAT_00f223b4)[iVar1] + iVar2 * 0x14;
    local_28 = &DAT_00ef1fec + DAT_00f13670 + iVar3 * 2;
    piVar12 = &DAT_00ef44c4 + iVar1;
    puVar8 = &DAT_00f28f10 + iVar1 * 2;
    iVar5 = ((int)(short)(&DAT_00f22434)[uVar11 + (uVar9 + uVar7 * 3) * 3] + uVar10 * 10) * 7 +
            iVar5;
    piVar14 = &DAT_00ef4784 + DAT_00f13670 + iVar5 * 2;
    piVar13 = &DAT_00f29490 + (DAT_00f13670 + iVar5 * 2) * 2;
    if (((local_34 == (int *)0x0) || (*local_34 == 0)) ||
       ((local_30 == (int *)0x0 || (*local_30 == 0)))) goto LAB_005c0c6e;
    bVar4 = true;
  }
  else {
    piVar14 = &DAT_00ef4744 + DAT_00f13670;
    piVar12 = &DAT_00ef44ac;
    puVar8 = (undefined4 *)&DAT_00f28ee0;
    piVar13 = (int *)(&DAT_00f29410 + DAT_00f13670 * 8);
LAB_005c0c6e:
    bVar4 = false;
  }
  if (((DAT_00a3ce50 < 4) && (DAT_00ee9a30 == 0)) || (!bVar4)) {
    if ((*piVar12 == 0) && (iVar5 = FUN_005b83c0(puVar8,piVar12,1), iVar5 != 0)) goto LAB_005c0d0e;
    iVar5 = *piVar12;
    if (((DAT_00f136f4 != iVar5) || (DAT_00ef7324 != 0)) && (DAT_00f3a070 != 0)) {
      FUN_005d2bb0(iVar5,0,0);
      DAT_00f136f0 = 0;
      DAT_00ef72cc = 1;
      DAT_00f136f4 = iVar5;
    }
    if (*piVar14 != 0) goto LAB_005c0d94;
  }
  else {
    if ((*piVar15 == 0) && (iVar5 = FUN_005b83c0(local_34,piVar15,1), iVar5 != 0)) {
LAB_005c0d0e:
      FUN_0056bca0(&DAT_007fdd30);
      return 0;
    }
    iVar5 = *piVar15;
    if (((DAT_00f136f4 != iVar5) || (DAT_00ef7324 != 0)) && (DAT_00f3a070 != 0)) {
      FUN_005d2bb0(iVar5,0,0);
      DAT_00f136f0 = 0;
      DAT_00ef72cc = 1;
      DAT_00f136f4 = iVar5;
    }
    piVar14 = local_28;
    if (*local_28 != 0) goto LAB_005c0d94;
    piVar13 = local_30;
  }
  iVar5 = FUN_005b8410(piVar13,piVar14,1);
  if (iVar5 != 0) {
    FUN_0056bca0(&DAT_007fdcb0);
    return 0;
  }
LAB_005c0d94:
  iVar5 = *piVar14;
  if (((DAT_00f136ec != iVar5) || (DAT_00ef7324 != 0)) && (DAT_00f3a070 != 0)) {
    FUN_005d2b70(iVar5,0,0);
    DAT_00ef72cc = 1;
    DAT_00f136e8 = 0;
    DAT_00f136ec = iVar5;
  }
  return 1;
}

