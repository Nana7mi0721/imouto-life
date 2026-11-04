
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00511c90(void)

{
  double dVar1;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_44;
  undefined4 uStack_40;
  int local_3c;
  undefined4 uStack_38;
  int local_34;
  tagRECT local_30;
  tagRECT local_20;
  tagRECT local_10;
  
  if (DAT_00a20c10 == 1) {
    return 0;
  }
  FUN_0050e6b0();
  FUN_0050e8d0(&local_44,&local_30);
  dVar1 = (double)local_3c * (double)CONCAT44(uStack_40,local_44);
  local_44 = (int)ROUND(dVar1);
  local_30._0_8_ = (double)local_34 * (double)local_30._0_8_;
  _local_3c = CONCAT44((int)((ulonglong)dVar1 >> 0x20),(int)ROUND((double)local_30._0_8_));
  GetWindowRect(DAT_00a20bec,&local_20);
  BVar2 = GetClientRect(DAT_00a20bec,&local_10);
  if (BVar2 == 0) {
    return 0;
  }
  DAT_00a20c38 = DAT_00a20c30 + local_10.right;
  iVar3 = local_10.right - local_10.left;
  DAT_00a20c3c = DAT_00a20c34 + local_10.bottom;
  iVar4 = local_10.bottom - local_10.top;
  local_20.bottom = local_20.bottom - iVar4;
  local_20.right = local_20.right - iVar3;
  if (DAT_00a2d7b0 == 1) {
    if (DAT_00a2d7bc == 1) goto LAB_00511dc6;
LAB_00511df8:
    if (local_44 < iVar3) {
      iVar3 = local_44;
    }
    if (local_3c < iVar4) {
      iVar4 = local_3c;
    }
    if (DAT_00a2d7e4 != 0) {
      if (iVar3 < DAT_00a2d7dc) {
        iVar3 = DAT_00a2d7dc;
      }
      if (iVar4 < DAT_00a2d7e0) {
        iVar4 = DAT_00a2d7e0;
      }
    }
    if (DAT_00a2d7d8 == 0) goto LAB_00511e4e;
    if (DAT_00a2d7d0 < iVar3) {
      iVar3 = DAT_00a2d7d0;
    }
    iVar5 = DAT_00a2d7d4;
    if (iVar4 <= DAT_00a2d7d4) goto LAB_00511e4e;
  }
  else {
    if (DAT_00a2d7bc == 1) {
LAB_00511dc6:
      iVar3 = DAT_00a2d7b4;
      iVar4 = DAT_00a2d7b8;
      if ((DAT_00a2d798 == 1) || (DAT_00a2d7b0 == 1)) {
        if (DAT_00a49734 == 0) {
          DAT_00a2d7bc = 0;
        }
        else {
          DAT_00a2d7c0 = 1;
        }
      }
      goto LAB_00511df8;
    }
    if (iVar3 != local_44) {
      iVar3 = local_44;
    }
    iVar5 = local_3c;
    if (iVar4 == local_3c) goto LAB_00511e4e;
  }
  iVar4 = iVar5;
LAB_00511e4e:
  local_20.right = local_20.right + iVar3;
  if (DAT_00a2d288 == 0) {
    iVar3 = 0;
  }
  else {
    GetWindowRect(DAT_00a2d28c,&local_30);
    iVar3 = local_30.bottom - local_30.top;
  }
  local_20.bottom = local_20.bottom + iVar3 + iVar4;
  if (DAT_00a2d7cc == 1) {
    iVar3 = DAT_00a2d7c4 - local_20.left;
    iVar4 = DAT_00a2d7c8 - local_20.top;
    local_20.left = local_20.left + iVar3;
    local_20.top = local_20.top + iVar4;
    local_20.right = local_20.right + iVar3;
    local_20.bottom = local_20.bottom + iVar4;
    if ((DAT_00a49734 == 0) && (DAT_00a37ee8 == 0)) {
      DAT_00a2d7cc = 0;
    }
    if ((DAT_00a2e478 == 1) || (DAT_00a2e47c == 1)) {
      FUN_005167a0(&local_34,&local_3c);
      local_20.right = local_34 + local_20.left;
      local_20.bottom = local_3c + local_20.top;
      if ((*(uint *)(&DAT_007d48b4 + DAT_00a20c04 * 4) & 0xc00000) != 0) {
        local_20.bottom = local_20.bottom + DAT_00a20bfc;
      }
    }
  }
  else if (DAT_00a2d804 != 0) {
    local_20.left = DAT_00a2d818;
    local_20.top = DAT_00a2d81c;
    local_20.right = DAT_00a2d820;
    local_20.bottom = DAT_00a2d824;
    DAT_00a2d828 = DAT_00a2d818;
    DAT_00a2d82c = DAT_00a2d81c;
    _DAT_00a2d830 = DAT_00a2d820;
    _DAT_00a2d834 = DAT_00a2d824;
  }
  MoveWindow(DAT_00a20bec,local_20.left,local_20.top,local_20.right - local_20.left,
             local_20.bottom - local_20.top,1);
  if (((DAT_00a20c40 == 1) && (DAT_00a2d7f8 == 0)) && (DAT_00a2d7fc == 0)) {
    DAT_00a2d7f8 = 1;
    FUN_00511210(1);
  }
  return 0;
}

