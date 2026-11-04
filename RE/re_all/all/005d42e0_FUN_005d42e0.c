
/* WARNING: Removing unreachable block (ram,0x005d4a42) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d42e0(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  HWND pHVar4;
  HDC hDC;
  HBRUSH hbr;
  undefined4 uVar5;
  longlong lVar6;
  tagRECT *lpRect;
  int local_4d8;
  int local_4d4;
  int local_4d0;
  int local_4cc;
  int local_4c8;
  int local_4c4;
  RECT local_4c0;
  tagRECT local_4b0;
  double local_4a0;
  int local_498;
  int local_494;
  undefined4 local_490;
  undefined4 local_48c;
  int local_488;
  int local_484;
  undefined1 local_480 [1148];
  
  FUN_005167a0(&local_4c4);
  local_490 = 0;
  local_48c = 0;
  local_488 = DAT_00a37e60;
  local_484 = DAT_00a37e64;
  iVar3 = FUN_0050e7d0();
  if (iVar3 == 1) {
    if (DAT_00aaf0e8 == 0) {
      FUN_0050e8d0(&local_4b0);
      if (((DAT_00a2d804 == 0) || (DAT_00a2d7b0 != 0)) || (DAT_00a2d7bc != 0)) {
        local_4d8 = 0;
        local_4d4 = 0;
        local_4d0 = (int)ROUND((double)local_4c4 * (double)CONCAT44(local_4b0.top,local_4b0.left));
        local_4c0._0_8_ = (double)local_4c8 * local_4a0;
        local_4cc = (int)ROUND((double)local_4c0._0_8_);
      }
      else {
        iVar3 = FUN_0050e240((double)DAT_00a37e60 * (double)CONCAT44(local_4b0.top,local_4b0.left));
        local_4d8 = ((DAT_00a2d810 - DAT_00a2d808) - iVar3) / 2;
        iVar3 = FUN_0050e240((double)DAT_00a37e64 * local_4a0);
        local_4d4 = ((DAT_00a2d814 - DAT_00a2d80c) - iVar3) / 2;
        local_4d0 = FUN_0050e240((double)local_4c4 * (double)CONCAT44(local_4b0.top,local_4b0.left))
        ;
        local_4d0 = local_4d0 + local_4d8;
        local_4cc = FUN_0050e240((double)local_4c8 * local_4a0);
        local_4cc = local_4cc + local_4d4;
        iVar3 = local_4d8 - DAT_00a2d808;
        if (iVar3 < 0) {
          iVar3 = -iVar3;
        }
        if (iVar3 < 2) {
          local_4d8 = DAT_00a2d808;
        }
        iVar3 = local_4d0 - DAT_00a2d810;
        if (iVar3 < 0) {
          iVar3 = -iVar3;
        }
        if (iVar3 < 2) {
          local_4d0 = DAT_00a2d810;
        }
        iVar3 = local_4d4 - DAT_00a2d80c;
        if (iVar3 < 0) {
          iVar3 = -iVar3;
        }
        if (iVar3 < 2) {
          local_4d4 = DAT_00a2d80c;
        }
        iVar3 = local_4cc - DAT_00a2d814;
        if (iVar3 < 0) {
          iVar3 = -iVar3;
        }
        if (iVar3 < 2) {
          local_4cc = DAT_00a2d814;
        }
      }
      if (DAT_00a2d288 != 0) {
        local_4d4 = (DAT_00a20c3c - DAT_00a20c34) - local_4c8;
        local_4cc = DAT_00a20c3c - DAT_00a20c34;
      }
    }
    else {
      local_4d8 = 0;
      local_4d4 = 0;
      local_4d0 = (int)ROUND((double)local_4c4 * _DAT_00a2d7a0 * _DAT_00aaf0f0);
      local_4a0 = (double)local_4c8 * _DAT_00a2d7a8 * _DAT_00aaf0f8;
      local_4cc = (int)ROUND(local_4a0);
    }
  }
  else {
    local_4d8 = 0;
    local_4d4 = 0;
    local_4d0 = DAT_00a37e60;
    local_4cc = DAT_00a37e64;
  }
  FUN_00568ca0();
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  FUN_0059d460();
  if ((DAT_00a2e478 != 0) || (DAT_00a2e47c != 0)) {
    if (DAT_00a37ebc == 0) {
      FUN_005d1a10();
    }
    uVar2 = DAT_00a38140;
    uVar5 = DAT_00a38120;
    local_4c0.right = DAT_00a37e60;
    DAT_00a38120 = 0xfffffffe;
    DAT_00a38140 = 0;
    local_4c0.left = 0;
    local_4c0.top = 0;
    local_4c0.bottom = DAT_00a37e64;
    iVar3 = FUN_005229c0(&local_4c0,local_480,0xffffffff,0xffffffff,0xffffffff,1,0);
    if (iVar3 < 0) {
      return 0xffffffff;
    }
    FUN_0050f6f0(local_480,0,0,0,0);
    FUN_00517420();
    DAT_00a38120 = uVar5;
    DAT_00a38140 = uVar2;
    return 0;
  }
  iVar3 = FUN_0050e7d0();
  if ((iVar3 == 1) && (DAT_00a37e78 != 0)) {
    local_4d8 = 0;
    local_4d4 = 0;
    local_4d0 = 0x280;
    local_4cc = 0x1e0;
    local_490 = 0;
    local_48c = 0;
    local_488 = 0x140;
    local_484 = 0xf0;
  }
  if (DAT_00ddb5c4 != 0) {
    if (DAT_00a37ec0 == 0) {
      local_4c0._0_8_ = 0.0;
      local_4c0.right = DAT_00a37e60;
      local_4c0.bottom = DAT_00a37e64;
    }
    else {
      local_498 = DAT_00a37e60;
      local_494 = DAT_00a37e64;
      local_4c0.right = DAT_00a37ecc;
      local_4c0.top = DAT_00a37ec8;
      local_4c0.left = DAT_00a37ec4;
      local_4a0 = 0.0;
      local_4c0.bottom = DAT_00a37ed0;
      FUN_00514e10(&local_4c0);
      if (local_4c0.right - local_4c0.left < 1) {
        return 0xffffffff;
      }
      if (local_4c0.bottom - local_4c0.top < 1) {
        return 0xffffffff;
      }
    }
    iVar3 = FUN_0050e7d0();
    if (iVar3 == 0) {
      if (DAT_00a37e80 == 0) {
LAB_005d483c:
        iVar3 = FUN_005d3e00();
        if (iVar3 < 0) {
          FUN_0056bca0();
          return 0xffffffff;
        }
      }
      else if (DAT_00a37e80 == 1) {
        iVar3 = FUN_005d3850(DAT_00ddb5c4,&local_4c0,DAT_00ddb5b4,0);
        if (iVar3 != 0) {
          FUN_0056bca0(&PTR_LAB_007ffa60,iVar3);
          return 0xffffffff;
        }
      }
      else if (DAT_00a37e80 == 2) goto LAB_005d483c;
    }
    else {
      iVar3 = FUN_005d3850(DAT_00ddb5c4,&local_4c0,DAT_00ddb5b4,0);
      if (iVar3 != 0) {
        FUN_0056bca0(&PTR_LAB_007ffac0,iVar3);
        return 0xffffffff;
      }
    }
  }
  if (DAT_00f3a054 == (int *)0x0) {
    return 0;
  }
  local_4a0 = (double)FUN_00550090();
  if (DAT_00a2107c != 0) goto LAB_005d4a0a;
  iVar3 = FUN_0050e7d0();
  if (iVar3 == 0) {
    iVar3 = *DAT_00f3a054;
    uVar5 = FUN_0050eb30(0,0);
    iVar3 = (**(code **)(iVar3 + 0xc))(DAT_00f3a054,0,0,uVar5);
    if (iVar3 != 0) {
      return 0xffffffff;
    }
    goto LAB_005d4a0a;
  }
  iVar3 = DAT_00aaf0e8;
  if (DAT_00aaf0e8 == 0) {
    iVar3 = FUN_0050eb30();
  }
  iVar3 = (**(code **)(*DAT_00f3a054 + 0xc))(DAT_00f3a054,&local_490,&local_4d8,iVar3,0);
  if (iVar3 != 0) {
    return 0xffffffff;
  }
  if ((((DAT_00aaf0e8 != 0) || (DAT_00a2d288 != 0)) || (DAT_00a2d804 == 0)) ||
     ((DAT_00a2d7b0 != 0 || (DAT_00a2d7bc != 0)))) goto LAB_005d4a0a;
  if (DAT_00a2e474 == 0) {
    if (DAT_00ddb5e8 < 1) goto LAB_005d4a0a;
  }
  else {
    DAT_00a2e474 = 0;
    DAT_00ddb5e8 = 3;
  }
  lpRect = &local_4b0;
  DAT_00ddb5e8 = DAT_00ddb5e8 + -1;
  pHVar4 = (HWND)FUN_0050eb30();
  GetClientRect(pHVar4,lpRect);
  if (((local_4b0.left == local_4d8) && (local_4b0.top == local_4d4)) &&
     ((local_4b0.right == local_4d0 && (local_4b0.bottom == local_4cc)))) goto LAB_005d4a0a;
  bVar1 = false;
  pHVar4 = (HWND)FUN_0050eb30();
  hDC = GetDC(pHVar4);
  if (DAT_00a37ed4 == 1) {
    hbr = CreateSolidBrush((DAT_00a37ee0 << 8 | DAT_00a37edc) << 8 | DAT_00a37ed8);
    if (hbr == (HBRUSH)0x0) goto LAB_005d48ff;
    bVar1 = true;
  }
  else {
LAB_005d48ff:
    hbr = GetStockObject(4);
  }
  if (local_4b0.top != local_4d4) {
    local_4c0.top = local_4b0.top;
    local_4c0.left = local_4b0.left;
    local_4c0.right = local_4b0.right;
    local_4c0.bottom = local_4d4;
    FillRect(hDC,&local_4c0,hbr);
  }
  if (local_4b0.bottom != local_4cc) {
    local_4c0.top = local_4cc;
    local_4c0.left = local_4b0.left;
    local_4c0.right = local_4b0.right;
    local_4c0.bottom = local_4b0.bottom;
    FillRect(hDC,&local_4c0,hbr);
  }
  if (local_4b0.left != local_4d8) {
    local_4c0.top = local_4d4;
    local_4c0.left = local_4b0.left;
    local_4c0.right = local_4d8;
    local_4c0.bottom = local_4cc;
    FillRect(hDC,&local_4c0,hbr);
  }
  if (local_4b0.right != local_4d0) {
    local_4c0.top = local_4d4;
    local_4c0.left = local_4d0;
    local_4c0.right = local_4b0.right;
    local_4c0.bottom = local_4cc;
    FillRect(hDC,&local_4c0,hbr);
  }
  if (bVar1) {
    DeleteObject(hbr);
  }
  pHVar4 = (HWND)FUN_0050eb30();
  ReleaseDC(pHVar4,hDC);
LAB_005d4a0a:
  lVar6 = FUN_00550090();
  lVar6 = lVar6 - (longlong)local_4a0;
  iVar3 = FUN_0050e8a0();
  if (((iVar3 == 0) || (DAT_00a37ebc != 0)) || (499 < lVar6)) {
    return 0;
  }
  FUN_005d1a10();
  return 0;
}

