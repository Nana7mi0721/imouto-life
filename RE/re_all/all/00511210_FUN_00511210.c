
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00511210(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  LONG LVar4;
  int *piVar5;
  LONG LVar6;
  uint uVar7;
  int iVar8;
  int cy;
  HWND hWndInsertAfter;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 uStack_2c;
  int local_28;
  undefined4 uStack_24;
  tagRECT local_20;
  tagRECT local_10;
  
  uVar7 = 0;
  if (DAT_00a20bec == (HWND)0x0) {
    return 0;
  }
  if (DAT_00a20c10 == 1) {
    return 0;
  }
  GetWindowRect(DAT_00a20bec,&local_10);
  GetClientRect(DAT_00a20bec,&local_20);
  local_30 = local_20.right - local_20.left;
  local_28 = local_20.bottom - local_20.top;
  if (DAT_00a20c10 == 1) {
    GetClientRect(DAT_00a20bec,(LPRECT)&DAT_00a20c30);
    ClientToScreen(DAT_00a20bec,(LPPOINT)&DAT_00a20c30);
    ClientToScreen(DAT_00a20bec,(LPPOINT)&DAT_00a20c38);
    if (DAT_00a20c40 == 1) {
      FUN_0050f160(1);
    }
    else {
      FUN_0050f160(0);
    }
    goto LAB_0051174d;
  }
  FUN_0050e6b0();
  if (DAT_00a20c40 == 1) {
    FUN_0056bb10();
    local_3c = 0;
    if ((DAT_00a2e478 == 1) || (DAT_00a2e47c == 1)) {
      local_3c = 0x80000;
    }
    if (DAT_00a20c48 == 1) {
      uVar7 = 0x10000;
    }
    if (DAT_00a2d7f8 == 1) {
      uVar7 = uVar7 | 0x10000000;
    }
    if (DAT_00a2d798 == 1) {
      uVar7 = uVar7 | 0x40000;
    }
    SetWindowLongW(DAT_00a20bec,-0x14,*(int *)(&DAT_007d48e4 + DAT_00a20c04 * 4) + local_3c);
    SetWindowLongW(DAT_00a20bec,-0x10,*(int *)(&DAT_007d48b4 + DAT_00a20c04 * 4) + uVar7);
    if (DAT_00a2d7bc == 1) {
      iVar3 = DAT_00a2d7b8;
      iVar1 = DAT_00a2d7b4;
    }
    else if (DAT_00a2d7b0 == 1) {
      iVar3 = local_28;
      iVar1 = local_30;
    }
    else {
      FUN_0050e8d0(&local_28,&local_30);
      iVar1 = FUN_0050e240((double)local_38 * (double)CONCAT44(uStack_24,local_28));
      iVar3 = FUN_0050e240((double)local_34 * (double)CONCAT44(uStack_2c,local_30));
      iVar8 = FUN_0050ef60();
      iVar3 = iVar3 + iVar8;
    }
    FUN_0050ef60();
    local_20.left = 0;
    local_20.top = 0;
    local_20.right = iVar1;
    local_20.bottom = iVar3;
    AdjustWindowRectEx(&local_20,*(int *)(&DAT_007d48b4 + DAT_00a20c04 * 4) + uVar7,0,
                       *(int *)(&DAT_007d48e4 + DAT_00a20c04 * 4) + local_3c);
    _DAT_00a2d7e8 = -local_20.left;
    _DAT_00a2d7ec = local_20.right - iVar1;
    _DAT_00a2d7f0 = -local_20.top;
    _DAT_00a2d7f4 = local_20.bottom - iVar3;
    if (DAT_00a37ef8 == 0) {
      FUN_00567fe0();
    }
    iVar8 = local_20.right - local_20.left;
    piVar5 = (int *)((-(uint)(DAT_00a37eec != 0) & _DAT_00a37ef0) * 0x130 + DAT_00a37ef8);
    cy = local_20.bottom - local_20.top;
    local_28 = piVar5[5];
    iVar3 = *piVar5;
    iVar1 = piVar5[1];
    if (param_1 == 0) {
      local_20.right = iVar8 + local_10.left;
      local_20.bottom = local_10.top + cy;
    }
    else {
      local_10.left = (piVar5[4] - iVar8) / 2 + iVar3;
      local_20.right = local_20.right + local_10.left;
      iVar2 = (local_28 - cy) / 2 + iVar1;
      local_10.left = local_20.left + local_10.left;
      local_10.top = local_20.top + iVar2;
      local_20.bottom = local_20.bottom + iVar2;
    }
    local_20.left = local_10.left;
    local_20.top = local_10.top;
    if (DAT_00a20c08 == 0) {
      if (DAT_00a2d7cc == 1) {
        local_10.top = DAT_00a2d7c8;
        local_10.left = DAT_00a2d7c4;
      }
      SetWindowPos(DAT_00a20bec,(HWND)0xfffffffe,local_10.left,local_10.top,iVar8,cy,
                   -(uint)(DAT_00a20c0c != 0) & 0x10);
      if (DAT_00a2d7cc == 1) {
        LVar4 = DAT_00a2d7c4;
        LVar6 = DAT_00a2d7c8;
      }
      else {
        LVar4 = local_20.left;
        LVar6 = local_20.top;
      }
      hWndInsertAfter = (HWND)0x0;
    }
    else {
      LVar6 = local_10.top;
      LVar4 = local_10.left;
      if (DAT_00a2d7cc == 1) {
        LVar6 = DAT_00a2d7c8;
        LVar4 = DAT_00a2d7c4;
      }
      hWndInsertAfter = *(HWND *)(&DAT_0084c6bc + DAT_00a20c08 * 4);
    }
    SetWindowPos(DAT_00a20bec,hWndInsertAfter,LVar4,LVar6,iVar8,cy,-(uint)(DAT_00a20c0c != 0) & 0x10
                );
    GetClientRect(DAT_00a20bec,(LPRECT)&DAT_00a20c30);
    ClientToScreen(DAT_00a20bec,(LPPOINT)&DAT_00a20c30);
    ClientToScreen(DAT_00a20bec,(LPPOINT)&DAT_00a20c38);
    if (DAT_00a20c30 < iVar3) {
      iVar3 = -DAT_00a20c30;
      local_20.left = local_20.left + iVar3;
      local_20.right = local_20.right + iVar3;
      DAT_00a20c38 = DAT_00a20c38 + iVar3;
      DAT_00a20c30 = 0;
      if (DAT_00a20c34 < iVar1) goto LAB_00511617;
LAB_00511631:
      if (DAT_00a2d7cc == 1) {
        LVar4 = DAT_00a2d7c4;
        LVar6 = DAT_00a2d7c8;
      }
      else {
        LVar4 = local_20.left;
        LVar6 = local_20.top;
      }
      SetWindowPos(DAT_00a20bec,*(HWND *)(&DAT_0084c6bc + DAT_00a20c08 * 4),LVar4,LVar6,iVar8,cy,
                   -(uint)(DAT_00a20c0c != 0) & 0x10);
    }
    else if (DAT_00a20c34 < iVar1) {
LAB_00511617:
      iVar3 = -DAT_00a20c34;
      local_20.top = local_20.top + iVar3;
      local_20.bottom = local_20.bottom + iVar3;
      DAT_00a20c3c = DAT_00a20c3c + iVar3;
      DAT_00a20c34 = 0;
      goto LAB_00511631;
    }
    FUN_0050f160();
    FUN_0056bb10(&DAT_007d4da8);
  }
  else {
    FUN_0056bb10();
    SetWindowLongW(DAT_00a20bec,-0x14,*(LONG *)(&DAT_007d4944 + DAT_00a20c04 * 4));
    SetWindowLongW(DAT_00a20bec,-0x10,*(LONG *)(&DAT_007d4914 + DAT_00a20c04 * 4));
    DAT_00a20c30 = 0;
    DAT_00a20c34 = 0;
    DAT_00a20c38 = local_38;
    DAT_00a20c3c = local_34;
    ShowWindow(DAT_00a20bec,5);
    UpdateWindow(DAT_00a20bec);
    SetWindowPos(DAT_00a20bec,(HWND)0xffffffff,0,0,local_38,local_34,8);
    FUN_0050f160();
    FUN_0056bb10(&DAT_007d4da8);
  }
  if (DAT_00a20c0c == 0) {
    SetActiveWindow(DAT_00a20bec);
  }
LAB_0051174d:
  PostMessageW(DAT_00a20bec,0x20,(WPARAM)DAT_00a20bec,0);
  return 0;
}

