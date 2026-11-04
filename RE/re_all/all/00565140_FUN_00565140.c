
undefined4 FUN_00565140(int param_1,int param_2,uint param_3,int param_4)

{
  ushort uVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  ushort *puVar13;
  uint uVar14;
  int iVar15;
  bool bVar16;
  bool bVar17;
  int local_40;
  int local_3c;
  int local_34;
  int local_30;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  if ((DAT_00aa700c == 0) || (DAT_00aa7010 == 0)) {
    return 0xffffffff;
  }
  if (DAT_00aa84b4 == -1) {
    local_40 = FUN_00530d70();
  }
  else {
    local_40 = DAT_00aa84b4;
  }
  iVar3 = FUN_00536eb0(local_40);
  uVar4 = FUN_00516960();
  FUN_00516940(0);
  FUN_005162d0(&local_20);
  if (DAT_00aa5ff8 == 0) {
    FUN_00516940(uVar4);
    return 0;
  }
  iVar12 = 0;
  do {
    iVar12 = iVar12 + 1;
  } while ((&DAT_00aa5ff8)[iVar12] != 0);
  FUN_0053e560(&DAT_00aa5ff8,iVar12,local_40,0);
  if (param_1 < local_20) {
    param_1 = local_20;
  }
  if (param_2 < local_1c) {
    param_2 = local_1c;
  }
  iVar10 = 0;
  if (0 < iVar12) {
    puVar13 = (ushort *)&DAT_00aa5ff8;
    do {
      iVar5 = FUN_0053e560(&DAT_00aa5ff8,iVar10,local_40,0);
      iVar6 = FUN_0053e560(puVar13,1,local_40,0);
      if ((DAT_00aa842c <= iVar10) || (uVar7 = DAT_00aa8470, (&DAT_00aa802c)[iVar10] != '\x01')) {
        uVar7 = DAT_00aa8458;
      }
      FUN_00563eb0(iVar5 + param_1,param_2,iVar6 + iVar5 + param_1,iVar3 + param_2,
                   (iVar3 / 10) * 3 + iVar3,uVar7,1);
      if ((*puVar13 & 0xfc00) == 0xd800) {
        iVar10 = iVar10 + 1;
        puVar13 = puVar13 + 1;
      }
      iVar10 = iVar10 + 1;
      puVar13 = puVar13 + 1;
    } while (iVar10 < iVar12);
  }
  if (0 < iVar12) {
    puVar13 = (ushort *)&DAT_00aa5ff8;
    iVar10 = 0;
    do {
      iVar5 = FUN_0053e560(&DAT_00aa5ff8,iVar10,local_40,0);
      FUN_0053e560(puVar13,1,local_40,0);
      if ((iVar10 < DAT_00aa842c) && ((&DAT_00aa802c)[iVar10] == '\x01')) {
        bVar17 = true;
      }
      else {
        bVar17 = false;
      }
      DAT_00aae0d0 = *puVar13;
      bVar16 = (DAT_00aae0d0 & 0xfc00) == 0xd800;
      if (bVar16) {
        DAT_00aae0d2 = (&DAT_00aa5ffa)[iVar10];
        DAT_00aae0d4 = 0;
      }
      else {
        DAT_00aae0d2 = 0;
      }
      if (bVar17) {
        uVar9 = DAT_00aa8464;
        if (DAT_00aa8468 == 0) {
          uVar7 = DAT_00aa8470;
        }
        else {
          uVar7 = DAT_00aa846c;
        }
      }
      else {
        if (DAT_00aa8450 == 0) {
          uVar7 = DAT_00aa8458;
        }
        else {
          uVar7 = DAT_00aa8454;
        }
        uVar9 = DAT_00aa844c;
      }
      FUN_00563c40(iVar5 + param_1,param_2,iVar3 + (iVar3 / 10) * 3,&DAT_00aae0d0,0xffffffff,uVar9,
                   uVar7,local_40,0xffffffff,0,0xffffffff,0xffffffff,0xffffffff,1,0,0);
      if (bVar16) {
        iVar10 = iVar10 + 1;
        puVar13 = puVar13 + 1;
      }
      iVar10 = iVar10 + 1;
      puVar13 = puVar13 + 1;
    } while (iVar10 < iVar12);
  }
  iVar12 = 0;
  iVar10 = 0;
  if (0 < DAT_00aa5ff4) {
    do {
      if ((&DAT_00aa5ff8)[iVar12] == 0) break;
      if (((&DAT_00aa5ff8)[iVar12] & 0xfc00U) == 0xd800) {
        iVar12 = iVar12 + 2;
      }
      else {
        iVar12 = iVar12 + 1;
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < DAT_00aa5ff4);
    if (iVar12 != 0) {
      iVar12 = FUN_0053e560(&DAT_00aa5ff8,iVar12,local_40,0);
      goto LAB_00565474;
    }
  }
  iVar12 = 0;
LAB_00565474:
  iVar12 = iVar12 + param_1;
  if ((DAT_00aa6ffc != 0) && (DAT_00aa84ac == 1)) {
    FUN_00563eb0(iVar12,param_2,iVar12 + 2,iVar3 + param_2,iVar3 + (iVar3 / 10) * 3,DAT_00aa845c,1);
  }
  iVar10 = iVar3 / 0x14;
  local_34 = 0;
  if (iVar10 < 1) {
    iVar10 = 1;
  }
  iVar5 = iVar3 / 10;
  local_3c = 0;
  if (0 < DAT_00aa8028) {
    do {
      iVar6 = FUN_0053e560(&DAT_00aa5ff8 + local_34,
                           *(int *)(&DAT_00aa7028 + local_3c * 4) - local_34,local_40,0);
      if (iVar10 * 4 < iVar6) {
        if ((local_34 < DAT_00aa842c) && ((&DAT_00aa802c)[local_34] == '\x01')) {
          bVar2 = 1;
        }
        else {
          bVar2 = 0;
        }
        FUN_00563eb0(iVar10 * 2 + param_1,iVar3 + iVar5 + param_2,iVar6 + iVar10 * -2 + param_1,
                     (bVar2 + 2) * iVar5 + iVar3 + param_2,iVar3 + iVar5 * 3,DAT_00aa8460,1);
      }
      local_34 = *(int *)(&DAT_00aa7028 + local_3c * 4);
      local_3c = local_3c + 1;
      param_1 = param_1 + iVar6;
    } while (local_3c < DAT_00aa8028);
  }
  if (((param_4 != 0) && (DAT_00aa6ffc != 0)) && (*(int *)(DAT_00aa6ffc + 8) != 0)) {
    iVar10 = iVar3 / 3;
    if ((local_14 - local_1c < (int)((param_3 + 1) * iVar3 + iVar10 * 2)) &&
       (param_3 = ((local_14 + iVar10 * -2) - local_1c) / iVar3 - 1, (int)param_3 < 1)) {
      param_3 = 1;
    }
    iVar5 = 0;
    local_3c = 0;
    local_30 = 0;
    uVar14 = (*(uint *)(DAT_00aa6ffc + 0xc) / param_3) * param_3;
    if (0 < (int)param_3) {
      iVar6 = uVar14 * 4 + 0x18;
      do {
        if (*(uint *)(DAT_00aa6ffc + 8) <= uVar14) break;
        if (*(short *)(*(int *)(DAT_00aa6ffc + iVar6) + DAT_00aa6ffc) != 0) {
          local_30 = local_30 + 1;
        }
        iVar5 = iVar5 + 1;
        FUN_0056d310(&DAT_00aae0d0,0x800,L"%d:%s",iVar5,
                     *(int *)(DAT_00aa6ffc + iVar6) + DAT_00aa6ffc);
        iVar8 = 0;
        uVar1 = DAT_00aae0d0;
        while (uVar1 != 0) {
          iVar8 = iVar8 + 1;
          uVar1 = (&DAT_00aae0d0)[iVar8];
        }
        iVar8 = FUN_0053e560(&DAT_00aae0d0,iVar8,local_40,0);
        if (local_3c < iVar8) {
          local_3c = iVar8;
        }
        uVar14 = uVar14 + 1;
        iVar6 = iVar6 + 4;
      } while (iVar5 < (int)param_3);
    }
    FUN_0056d310(&DAT_00aae0d0,0x800,L"%d/%d",*(int *)(DAT_00aa6ffc + 0xc) + 1,
                 *(undefined4 *)(DAT_00aa6ffc + 8));
    iVar6 = 0;
    uVar1 = DAT_00aae0d0;
    while (uVar1 != 0) {
      iVar6 = iVar6 + 1;
      uVar1 = (&DAT_00aae0d0)[iVar6];
    }
    iVar6 = FUN_0053e560(&DAT_00aae0d0,iVar6,local_40,0);
    if (local_3c < iVar6) {
      local_3c = iVar6;
    }
    if (0 < local_30) {
      local_8 = iVar10 * 2 + local_3c + iVar12;
      iVar8 = iVar3 / 2;
      iVar15 = (iVar5 + 2) * iVar3 + iVar8 + iVar10 * 2 + param_2;
      iVar11 = iVar8 + iVar3 + param_2;
      if (local_14 < iVar15) {
        iVar5 = (iVar5 + 1) * iVar3;
        if (((param_2 + iVar10 * -2) - iVar5) - iVar8 < local_1c) {
          local_14 = iVar15 - local_14;
        }
        else {
          local_14 = (iVar5 - param_2) + iVar8 + iVar10 * 2 + iVar11;
        }
        iVar15 = iVar15 - local_14;
        iVar11 = iVar11 - local_14;
      }
      local_10 = iVar12;
      if (local_18 < local_8) {
        local_10 = iVar12 - (local_8 - local_18);
        local_8 = local_8 - (local_8 - local_18);
      }
      iVar12 = local_10;
      FUN_00526390(local_10,iVar11,local_8,iVar15,DAT_00aa8490,1);
      FUN_00526390(iVar12,iVar11,local_8,iVar15,DAT_00aa848c,0);
      iVar12 = iVar12 + iVar10;
      iVar5 = 0;
      uVar14 = (*(uint *)(DAT_00aa6ffc + 0xc) / param_3) * param_3;
      if (0 < (int)param_3) {
        local_30 = uVar14 * 4 + 0x18;
        iVar8 = iVar11 + iVar10;
        do {
          if (*(uint *)(DAT_00aa6ffc + 8) <= uVar14) break;
          bVar17 = uVar14 == *(uint *)(DAT_00aa6ffc + 0xc);
          if ((bVar17) && (DAT_00aa8484 != 0)) {
            FUN_00526390(local_10 + 1,iVar8,local_8 + -1,iVar3 + iVar8,DAT_00aa8488,1);
          }
          iVar5 = iVar5 + 1;
          FUN_0056d310(&DAT_00aae0d0,0x800,L"%d:%s",iVar5,
                       *(int *)(local_30 + DAT_00aa6ffc) + DAT_00aa6ffc);
          if (bVar17) {
            uVar7 = DAT_00aa847c;
            uVar9 = DAT_00aa8480;
          }
          else {
            uVar7 = DAT_00aa8474;
            uVar9 = DAT_00aa8478;
          }
          iVar15 = 0;
          uVar1 = DAT_00aae0d0;
          while (uVar1 != 0) {
            iVar15 = iVar15 + 1;
            uVar1 = (&DAT_00aae0d0)[iVar15];
          }
          FUN_0053f880(iVar12,iVar8,&DAT_00aae0d0,iVar15,uVar7,local_40,uVar9,0);
          local_30 = local_30 + 4;
          iVar8 = iVar8 + iVar3;
          uVar14 = uVar14 + 1;
        } while (iVar5 < (int)param_3);
      }
      FUN_0056d310(&DAT_00aae0d0,0x800,L"%d/%d",*(int *)(DAT_00aa6ffc + 0xc) + 1,
                   *(undefined4 *)(DAT_00aa6ffc + 8));
      iVar8 = 0;
      uVar1 = DAT_00aae0d0;
      while (uVar1 != 0) {
        iVar8 = iVar8 + 1;
        uVar1 = (&DAT_00aae0d0)[iVar8];
      }
      FUN_0053f880((iVar12 - iVar6) + local_3c,iVar5 * iVar3 + iVar11 + iVar10,&DAT_00aae0d0,iVar8,
                   DAT_00aa8474,local_40,DAT_00aa8478,0);
      uVar7 = DAT_00a20bec;
      uVar9 = (*DAT_00aba12c)(DAT_00a20bec);
      (*DAT_00aba13c)(uVar9,0x17,0,param_3);
      (*DAT_00aba13c)(uVar9,0x16,0,(*(uint *)(DAT_00aa6ffc + 0xc) / param_3) * param_3);
      (*DAT_00aba130)(uVar7,uVar9);
    }
  }
  FUN_00516940(uVar4);
  return 0;
}

