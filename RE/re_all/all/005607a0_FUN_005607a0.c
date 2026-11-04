
undefined4 FUN_005607a0(uint param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  uint local_34;
  undefined4 local_30;
  uint local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_34 = 0;
  if ((DAT_00a834f0 == 0) || (iVar4 = FUN_0057e0e0(), iVar4 == 0)) {
    return 0xffffffff;
  }
  if (param_2 == 0) {
    if (DAT_00cc4db0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_1 < 0) {
      return 0xffffffff;
    }
    if ((param_1 & 0x7c000000) != DAT_00cc4dd8) {
      return 0xffffffff;
    }
    if (DAT_00cc4de0 <= (int)(param_1 & 0xffff)) {
      return 0xffffffff;
    }
    iVar4 = (param_1 & 0xffff) * 4;
    piVar6 = *(int **)(iVar4 + DAT_00cc4db4);
    if (piVar6 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar6 * 0x10000 != (param_1 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (piVar6[4] != 0) {
      return 0xffffffff;
    }
  }
  else {
    if (DAT_00cc4db0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_1 < 0) {
      return 0xffffffff;
    }
    if ((param_1 & 0x7c000000) != DAT_00cc4dd8) {
      return 0xffffffff;
    }
    if (DAT_00cc4de0 <= (int)(param_1 & 0xffff)) {
      return 0xffffffff;
    }
    iVar4 = (param_1 & 0xffff) * 4;
    piVar6 = *(int **)(iVar4 + DAT_00cc4db4);
    if (piVar6 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar6 * 0x10000 != (param_1 & 0x3ff0000)) {
      return 0xffffffff;
    }
  }
  local_2c = param_1 & 0x7c000000;
  if (piVar6[0x482] != 1) {
    return 0;
  }
  iVar5 = FUN_0055fa80(param_1,piVar6,&local_30,0);
  if (iVar5 == -1) {
    return 0;
  }
  if ((char)piVar6[0x935] == '\0') {
    return 0;
  }
  FUN_0056da60(&DAT_00cc4df4,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x910);
  if (param_2 == 0) {
    if ((((DAT_00cc4db0 == 0) || (local_2c != DAT_00cc4dd8)) ||
        (DAT_00cc4de0 <= (int)(param_1 & 0xffff))) ||
       (((piVar6 = *(int **)(iVar4 + DAT_00cc4db4), piVar6 == (int *)0x0 ||
         (*piVar6 * 0x10000 != (param_1 & 0x3ff0000))) || (piVar6[4] != 0)))) goto LAB_0056094d;
  }
  else if (((DAT_00cc4db0 == 0) || (local_2c != DAT_00cc4dd8)) ||
          ((DAT_00cc4de0 <= (int)(param_1 & 0xffff) ||
           ((piVar6 = *(int **)(iVar4 + DAT_00cc4db4), piVar6 == (int *)0x0 ||
            (*piVar6 * 0x10000 != (param_1 & 0x3ff0000))))))) goto LAB_0056094d;
  FUN_0055c140(param_1,0xffffffff,param_2);
  if (piVar6[0x931] == 0) {
    local_2c = 0xc0;
    iVar4 = 0x60;
  }
  else {
    local_2c = 0xcc0;
    iVar4 = 0xc00;
  }
  if (*(char *)((int)piVar6 + 0x24d5) == '\0') {
    iVar5 = FUN_00551870(local_30);
    if (iVar5 == 0) {
      if (piVar6[0x48a] != -800) goto LAB_00560e55;
      iVar8 = ((piVar6[0x47f] * local_2c >> 8) / (uint)*(ushort *)(piVar6 + 0x480)) *
              (uint)*(ushort *)(piVar6 + 0x480);
      iVar5 = 0;
    }
    else {
      iVar5 = piVar6[0x48a];
      iVar8 = (((uint)piVar6[0x47f] >> 3) / (uint)*(ushort *)(piVar6 + 0x480)) *
              (uint)*(ushort *)(piVar6 + 0x480);
      FUN_00551ca0(local_30,&local_34,0);
      uVar7 = piVar6[0x48a];
      uVar2 = piVar6[0x48b];
      if ((((uVar7 < uVar2) && (local_34 < uVar2)) && (uVar7 < local_34)) ||
         ((uVar2 < uVar7 && ((local_34 < uVar2 || (uVar7 < local_34)))))) goto LAB_0056094d;
      if (uVar7 < uVar2) {
        if (local_34 < uVar7) {
          local_34 = local_34 + piVar6[0x489];
        }
        uVar7 = uVar7 + piVar6[0x489];
      }
      uVar7 = ((uVar7 - local_34) * 0x200) / (uint)piVar6[0x47f];
      if (uVar7 < (uint)(iVar4 * 2)) {
        iVar8 = (((iVar4 * 2 - uVar7) * piVar6[0x47f] >> 9) / (uint)*(ushort *)(piVar6 + 0x480)) *
                (uint)*(ushort *)(piVar6 + 0x480);
      }
    }
    local_28 = iVar8;
    local_24 = iVar5;
    FUN_005518a0(local_30,iVar5,iVar8,&local_20,&local_18,&local_1c,&local_14);
    local_10 = 0;
    local_c = 0;
    local_8 = local_18;
    local_4 = local_14;
    if (iVar8 != 0) {
      while (*(char *)((int)piVar6 + 0x24d5) == '\0') {
        piVar1 = piVar6 + piVar6[0x92e] * 0x128 + 0x48c;
        iVar4 = iVar8;
        if (piVar1[0xc] != -1) {
          iVar5 = (uint)*(ushort *)(piVar6 + 0x480) * piVar1[0xc];
          if ((iVar5 < piVar6[0x930] + iVar8) && (iVar4 = iVar5 - piVar6[0x930], iVar4 < 1)) {
            iVar4 = 0;
          }
        }
        iVar4 = FUN_00550f50(&local_24,piVar1 + 0xd,iVar4);
        bVar3 = false;
        if (iVar4 == 0) {
          iVar4 = FUN_0055c310(piVar6,&local_24,local_34);
          if (iVar4 < 0) {
            bVar3 = true;
          }
        }
        else {
          iVar8 = iVar8 - iVar4;
          piVar6[0x930] = piVar6[0x930] + iVar4;
        }
        if ((((piVar1 == piVar6 + piVar6[0x92e] * 0x128 + 0x48c) && (piVar1[0xc] != -1)) &&
            ((int)((uint)*(ushort *)(piVar6 + 0x480) * piVar1[0xc]) <= piVar6[0x930])) ||
           ((bVar3 || (iVar8 == 0)))) break;
      }
    }
    iVar8 = local_28 - iVar8;
    FUN_00551980(local_30,local_20,local_18,local_1c,local_14);
    if (piVar6[0x48a] == -800) {
      piVar6[0x48a] = iVar8;
      piVar6[0x48b] = 0;
      FUN_0056dac0(&DAT_00cc4df4);
      return 0;
    }
    iVar4 = piVar6[0x489];
    iVar8 = piVar6[0x48a] + iVar8;
    piVar6[0x48a] = iVar8;
    if (iVar4 <= iVar8) {
      piVar6[0x48a] = iVar8 - iVar4;
    }
    uVar7 = (uint)*(ushort *)(piVar6 + 0x480);
    iVar5 = piVar6[0x48a] - ((((piVar6[0x47f] * local_2c >> 8) - 1) + uVar7) / uVar7) * uVar7;
    piVar6[0x48b] = iVar5;
    if (-1 < iVar5) goto LAB_00560e55;
    iVar5 = iVar5 + iVar4;
  }
  else {
    FUN_00551ca0(local_30,&local_34,0);
    uVar7 = piVar6[0x938];
    uVar2 = piVar6[0x937];
    if (((uVar7 < uVar2) && ((local_34 < uVar7 || (uVar2 < local_34)))) ||
       ((uVar2 < local_34 && ((local_34 < uVar7 && (uVar2 < uVar7)))))) {
      FUN_00551830(local_30,0);
      *(undefined1 *)((int)piVar6 + 0x24d5) = 0;
      piVar6[0x930] = 0;
      piVar6[0x933] = 0;
      *(undefined1 *)((int)piVar6 + 0x24d6) = 0;
      piVar6[0x92f] = 0;
      piVar6[0x92e] = 0;
      *(undefined1 *)(piVar6 + 0x935) = 0;
      FUN_0056dac0(&DAT_00cc4df4);
      return 0;
    }
    iVar5 = piVar6[0x48a];
    iVar4 = (((uint)piVar6[0x47f] >> 3) / (uint)*(ushort *)(piVar6 + 0x480)) *
            (uint)*(ushort *)(piVar6 + 0x480);
    FUN_00551ca0(local_30,&local_34,0);
    uVar7 = piVar6[0x48a];
    uVar2 = piVar6[0x48b];
    if ((((uVar7 < uVar2) && (local_34 < uVar2)) && (uVar7 < local_34)) ||
       ((uVar2 < uVar7 && ((local_34 < uVar2 || (uVar7 < local_34)))))) {
LAB_0056094d:
      FUN_0056dac0(&DAT_00cc4df4);
      return 0xffffffff;
    }
    local_24 = iVar5;
    FUN_005518a0(local_30,iVar5,iVar4,&local_20,&local_18,&local_1c,&local_14);
    local_10 = 0;
    local_c = 0;
    local_8 = local_18;
    local_4 = local_14;
    if (iVar4 != 0) {
      FUN_00550eb0(piVar6,&local_24,iVar4);
    }
    FUN_00551980(local_30,local_20,local_18,local_1c,local_14);
    iVar4 = piVar6[0x48a] + iVar4;
    iVar8 = piVar6[0x489];
    piVar6[0x48a] = iVar4;
    if (iVar8 <= iVar4) {
      piVar6[0x48a] = iVar4 - iVar8;
    }
    uVar7 = (uint)*(ushort *)(piVar6 + 0x480);
    iVar5 = piVar6[0x48a] - ((((piVar6[0x47f] * local_2c >> 8) - 1) + uVar7) / uVar7) * uVar7;
    piVar6[0x48b] = iVar5;
    if (-1 < iVar5) goto LAB_00560e55;
    iVar5 = iVar5 + iVar8;
  }
  piVar6[0x48b] = iVar5;
LAB_00560e55:
  FUN_0056dac0(&DAT_00cc4df4);
  return 0;
}

