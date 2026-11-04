
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d10d0(void)

{
  float fVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  uint uVar10;
  tagRECT local_4b8;
  int local_4a8;
  int local_4a4;
  float local_4a0;
  uint local_49c;
  float local_498;
  float fStack_494;
  float local_490;
  uint local_48c;
  double local_488;
  undefined1 local_480 [1148];
  
  iVar8 = 0;
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (((DAT_00a21078 == 0) && (DAT_00a24d44 == 0)) && (DAT_00a23d24 != 0)) {
    return 0;
  }
  iVar5 = FUN_0050e7d0();
  if ((iVar5 == 0) && ((DAT_00a37e80 != 1 || (DAT_00a37ec0 != 0)))) {
    FUN_005cfda0();
  }
  iVar5 = DAT_00ef1b48;
  if (DAT_00ef1b48 == 0) {
    local_4b8.left = DAT_00a20c30;
    local_4b8.top = DAT_00a20c34;
    local_4b8.right = (LONG)DAT_00a20c38;
    local_4b8.bottom = DAT_00a20c3c;
  }
  else {
    GetClientRect((HWND)(&DAT_00ee9b7c)[DAT_00ef1b48 * 0x20],&local_4b8);
  }
  iVar7 = local_4b8.right - local_4b8.left;
  iVar6 = local_4b8.bottom - local_4b8.top;
  if ((iVar7 != (&DAT_00ee9b94)[iVar5 * 0x20]) || (iVar6 != (&DAT_00ee9b98)[iVar5 * 0x20])) {
    FUN_005cfda0();
    FUN_005cae60(DAT_00ef1b48,iVar7,iVar6);
  }
  if (DAT_00ef1b58 == 0) goto LAB_005d1532;
  fVar9 = 0.0;
  uVar10 = 0;
  local_4a8 = 0;
  local_4a4 = 0;
  local_4a0 = 0.0;
  local_49c = 0;
  if (DAT_00a37ec0 == 0) {
    local_4b8.left = 0;
    local_4b8.top = 0;
    local_4b8.right = (LONG)DAT_00a37e60;
    local_4b8.bottom = DAT_00a37e64;
  }
  else {
    local_490 = DAT_00a37e60;
    local_48c = DAT_00a37e64;
    local_4b8.top = DAT_00a37ec8;
    local_4b8.right = (LONG)DAT_00a37ecc;
    local_4b8.left = DAT_00a37ec4;
    local_498 = 0.0;
    fStack_494 = 0.0;
    local_4b8.bottom = DAT_00a37ed0;
    FUN_00514e10(&local_4b8,&local_498);
    if (local_4b8.right - local_4b8.left < 1) {
      return 0xffffffff;
    }
    if (local_4b8.bottom - local_4b8.top < 1) {
      return 0xffffffff;
    }
  }
  iVar6 = FUN_0050e7d0();
  if (iVar6 == 1) {
    if (DAT_00ef1b48 != 0) {
      FUN_0050e8d0(&local_498,&local_488);
      local_4a8 = 0;
      local_4a4 = 0;
      fVar9 = (float)FUN_0050e240((double)(int)DAT_00a37e60 * (double)CONCAT44(fStack_494,local_498)
                                  * _DAT_00aaf0f0);
      local_4a0 = fVar9;
      uVar10 = FUN_0050e240((double)(int)DAT_00a37e64 * local_488 * _DAT_00aaf0f8);
      goto LAB_005d1445;
    }
    if (DAT_00a37e78 != 0) {
      local_4b8.left = 0;
      local_4b8.top = 0;
      local_4b8.right = 0x140;
      local_4b8.bottom = 0xf0;
      local_4a8 = 0;
      local_4a4 = 0;
      fVar9 = 8.96831e-43;
      uVar10 = 0x1e0;
      goto LAB_005d1441;
    }
    FUN_0050e8d0(&local_488,&local_498);
    if (((DAT_00a2d804 == 0) || (DAT_00a2d7b0 != 0)) || (DAT_00a2d7bc != 0)) {
      iVar6 = 0;
      local_4a8 = 0;
    }
    else {
      iVar8 = FUN_0050e240((double)(int)DAT_00a37e60 * local_488);
      iVar6 = ((DAT_00a2d810 - DAT_00a2d808) - iVar8) / 2;
      local_4a8 = iVar6;
      iVar8 = FUN_0050e240((double)(int)DAT_00a37e64 * (double)CONCAT44(fStack_494,local_498));
      iVar8 = ((DAT_00a2d814 - DAT_00a2d80c) - iVar8) / 2;
    }
    local_4a4 = iVar8;
    iVar7 = FUN_0050e240((double)(int)DAT_00a37e60 * local_488);
    fVar9 = (float)(iVar7 + iVar6);
    local_4a0 = fVar9;
    iVar6 = FUN_0050e240((double)(int)DAT_00a37e64 * (double)CONCAT44(fStack_494,local_498));
    uVar10 = iVar6 + iVar8;
    local_49c = uVar10;
    if (DAT_00a2d288 != 0) {
      uVar10 = DAT_00a20c3c - DAT_00a20c34;
      local_4a4 = uVar10 - DAT_00a37e64;
      goto LAB_005d1445;
    }
  }
  else {
    if (DAT_00a37e80 != 0) {
      if (DAT_00a37e80 == 1) {
        local_4a8 = 0;
        local_4a4 = 0;
        fVar9 = DAT_00a37e60;
        uVar10 = DAT_00a37e64;
        goto LAB_005d1441;
      }
      if (DAT_00a37e80 != 2) goto LAB_005d1449;
    }
    FUN_00517170();
    local_4a8 = DAT_00a37e9c;
    local_4a4 = DAT_00a37ea0;
    fVar9 = DAT_00a37ea4;
    uVar10 = DAT_00a37ea8;
LAB_005d1441:
    local_4a0 = fVar9;
LAB_005d1445:
    local_49c = uVar10;
  }
LAB_005d1449:
  fVar1 = (float)(&DAT_00ee9b94)[iVar5 * 0x20];
  if ((int)fVar1 < (int)fVar9) {
    local_4b8.right =
         local_4b8.right - (uint)(((int)fVar9 - (int)fVar1) * local_4b8.right) / (uint)fVar9;
    local_4a0 = fVar1;
  }
  uVar2 = (&DAT_00ee9b98)[iVar5 * 0x20];
  if ((int)uVar2 < (int)uVar10) {
    local_4b8.bottom = local_4b8.bottom - ((uVar10 - uVar2) * local_4b8.bottom) / uVar10;
    local_49c = uVar2;
  }
  if ((fVar1 != DAT_00ef1b50) || (uVar2 != DAT_00ef1b54)) {
    local_490 = (float)_DAT_0081ec30;
    local_498 = (float)DAT_00a37ed8 / local_490;
    fStack_494 = (float)DAT_00a37edc / local_490;
    local_490 = (float)DAT_00a37ee0 / local_490;
    local_48c = 0;
    FUN_005d5380((&DAT_00ee9bc4)[iVar5 * 0x20],&local_498,0);
  }
  FUN_005caf30(DAT_00ef1b58,DAT_00ef1b60,&local_4b8,(&DAT_00ee9b90)[iVar5 * 0x20],
               (&DAT_00ee9bc4)[iVar5 * 0x20],&local_4a8,DAT_00a37e84 == 0,0,0,0,0,0,0,0);
LAB_005d1532:
  FUN_00568ca0();
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if ((DAT_00a2e478 == 0) && (DAT_00a2e47c == 0)) {
    if ((&DAT_00ee9b4c)[iVar5 * 0x20] != 0) {
      if (DAT_00a2107c == 0) {
        iVar8 = FUN_005d26c0((&DAT_00ee9b4c)[iVar5 * 0x20],DAT_00a37ebc == 0,0);
        if (iVar8 < 0) {
          return 0xffffffff;
        }
        FUN_005677c0();
        return 0;
      }
      if (DAT_00a37ebc == 0) {
        FUN_005d23e0();
        FUN_005677c0();
        return 0;
      }
    }
  }
  else {
    if (DAT_00a37ebc == 0) {
      FUN_005d23e0();
    }
    uVar4 = DAT_00a38140;
    uVar3 = DAT_00a38120;
    local_4b8.right = (LONG)DAT_00a37e60;
    DAT_00a38120 = 0xfffffffe;
    DAT_00a38140 = 0;
    local_4b8.left = 0;
    local_4b8.top = 0;
    local_4b8.bottom = DAT_00a37e64;
    iVar8 = FUN_005229c0(&local_4b8,local_480,0xffffffff,0xffffffff,0xffffffff,1,0);
    if (iVar8 < 0) {
      return 0xffffffff;
    }
    FUN_0050f6f0(local_480,0,0,0,0);
    FUN_00517420();
    DAT_00a38120 = uVar3;
    DAT_00a38140 = uVar4;
  }
  FUN_005677c0();
  return 0;
}

