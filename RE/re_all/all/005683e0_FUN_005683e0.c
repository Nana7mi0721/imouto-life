
undefined4 FUN_005683e0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  HWND pHVar4;
  HDC hdc;
  HGDIOBJ pvVar5;
  undefined *puVar6;
  int yDest;
  DWORD w;
  DWORD DVar7;
  DWORD SrcWidth;
  DWORD SrcHeight;
  void *lpBits;
  int local_4c4;
  DWORD local_4c0;
  int local_4bc;
  undefined8 local_4b8;
  DWORD local_4b0;
  DWORD local_4ac;
  double local_4a0;
  undefined4 local_498;
  undefined4 uStack_494;
  DWORD local_490;
  DWORD local_48c;
  BITMAPINFO local_488;
  undefined4 local_45c;
  undefined4 local_458;
  int local_44c;
  undefined1 local_440 [1088];
  
  if (DAT_00a37d78 != 0) {
    if (DAT_00aaf0dc == 1) {
      uVar2 = FUN_005b4960();
      return uVar2;
    }
    if (DAT_00aaf0dc == 2) {
      uVar2 = FUN_005d10d0();
      return uVar2;
    }
    return 0;
  }
  iVar3 = FUN_0050e7d0();
  local_44c = 0;
  if (iVar3 == 1) {
    FUN_0050e8d0(&local_4a0,&local_498);
    FUN_005167a0(&local_4bc,&local_4c4);
    local_4b8 = (double)local_4c4 * (double)CONCAT44(uStack_494,local_498);
    local_4c0 = (DWORD)ROUND(local_4b8);
    DVar7 = local_4c0;
    w = (int)ROUND((double)local_4bc * local_4a0);
    if (DAT_00a2d288 != 0) {
      local_44c = (DAT_00a20c3c - DAT_00a20c34) - local_4c4;
      DVar7 = DAT_00a20c3c - DAT_00a20c34;
    }
  }
  else {
    DVar7 = DAT_00a37e64;
    w = DAT_00a37e60;
  }
  iVar3 = FUN_005813e0(&DAT_00a37df8);
  if (iVar3 == 0) {
    return 0;
  }
  iVar3 = FUN_005813e0(&DAT_00a37e10);
  if (iVar3 == 0) {
    return 0;
  }
  if (DAT_00a37ebc == 0) {
    FUN_005d1a10();
  }
  if ((DAT_00a2e478 != 0) && (DAT_00a2e47c != 0)) {
    if (DAT_00a37ebc == 0) {
      FUN_005d1a10();
    }
    uVar1 = DAT_00a38140;
    uVar2 = DAT_00a38120;
    local_4b0 = DAT_00a37e60;
    DAT_00a38120 = 0xfffffffe;
    DAT_00a38140 = 0;
    local_4b8 = 0.0;
    local_4ac = DAT_00a37e64;
    iVar3 = FUN_005229c0(&local_4b8,local_440,0xffffffff,0xffffffff,0xffffffff,1,0);
    if (iVar3 < 0) {
      return 0xffffffff;
    }
    FUN_0050f6f0(local_440,0,0,0,0);
    FUN_00517420();
    DAT_00a38120 = uVar2;
    DAT_00a38140 = uVar1;
    return 0;
  }
  if (DAT_00a37ec0 == 0) {
    puVar6 = &DAT_00a37df8;
  }
  else {
    local_490 = DAT_00a37e60;
    local_48c = DAT_00a37e64;
    local_4b0 = DAT_00a37ecc;
    local_4b8 = (double)CONCAT44(DAT_00a37ec8,DAT_00a37ec4);
    local_498 = 0;
    uStack_494 = 0;
    local_4ac = DAT_00a37ed0;
    FUN_00514e10(&local_4b8,&local_498);
    if ((int)(local_4b0 - (int)local_4b8) < 1) {
      return 0xffffffff;
    }
    if ((int)(local_4ac - local_4b8._4_4_) < 1) {
      return 0xffffffff;
    }
    FUN_00581340(&local_4b8,&DAT_00a37df8,(int)local_4b8,local_4b8._4_4_,local_4b0 - (int)local_4b8,
                 local_4ac - local_4b8._4_4_);
    FUN_006ea010(&DAT_00a37e10,&local_4b8,&local_498,0,0);
    puVar6 = &DAT_00a37e10;
  }
  FUN_0056d380(&local_488,0,0x38);
  local_488.bmiHeader.biSize = 0x28;
  local_488.bmiHeader.biPlanes = 1;
  local_488.bmiHeader.biHeight = -DAT_00a37e64;
  iVar3 = *(int *)(puVar6 + 0x14);
  local_488.bmiHeader.biBitCount = (WORD)*(byte *)(*(int *)(iVar3 + 0x14) + 5);
  local_488.bmiHeader.biCompression = 3;
  local_488.bmiColors[0] = *(RGBQUAD *)(*(int *)(iVar3 + 0x14) + 0x10);
  local_45c = *(undefined4 *)(*(int *)(iVar3 + 0x14) + 0x14);
  local_458 = *(undefined4 *)(*(int *)(iVar3 + 0x14) + 0x18);
  if (*(char *)(*(int *)(iVar3 + 0x14) + 5) == '\x10') {
    local_488.bmiHeader.biWidth =
         ((int)(DAT_00a37e60 + 7 + ((int)(DAT_00a37e60 + 7) >> 0x1f & 7U)) >> 3) * 2;
  }
  else {
    local_488.bmiHeader.biWidth =
         (int)(DAT_00a37e60 + 3 + ((int)(DAT_00a37e60 + 3) >> 0x1f & 3U)) >> 2;
  }
  local_488.bmiHeader.biWidth = local_488.bmiHeader.biWidth * 4;
  pHVar4 = DAT_00aaf0e8;
  if (DAT_00aaf0e8 == (HWND)0x0) {
    pHVar4 = (HWND)FUN_0050eb30();
  }
  hdc = GetDC(pHVar4);
  if (hdc == (HDC)0x0) {
    return 0;
  }
  iVar3 = FUN_0050e7d0();
  if ((iVar3 == 0) || (DAT_00a37e78 == 0)) {
    iVar3 = FUN_0050e7d0();
    if (iVar3 != 0) {
      DVar7 = DVar7 - local_44c;
      if ((DAT_00a37e60 == w) && (DAT_00a37e64 == DVar7)) {
        SetDIBitsToDevice(hdc,0,0,w,DVar7,0,0,0,DVar7,*(void **)(puVar6 + 0xc),&local_488,0);
        pHVar4 = (HWND)FUN_0050eb30();
        ReleaseDC(pHVar4,hdc);
        return 0;
      }
      lpBits = *(void **)(puVar6 + 0xc);
      SrcWidth = DAT_00a37e60;
      SrcHeight = DAT_00a37e64;
      goto LAB_0056890b;
    }
    if (0 < DAT_00aaf100) {
      DAT_00aaf100 = DAT_00aaf100 + -1;
      FUN_00513550(0,0);
      pvVar5 = GetStockObject(4);
      pvVar5 = SelectObject(hdc,pvVar5);
      Rectangle(hdc,0,0,DAT_00a37e8c,DAT_00a37e90);
      SelectObject(hdc,pvVar5);
    }
    if (DAT_00a37e80 != 0) {
      if (DAT_00a37e80 == 1) {
        SetDIBitsToDevice(hdc,0,0,DAT_00a37e60,DAT_00a37e64,0,0,0,DAT_00a37e64,
                          *(void **)(puVar6 + 0xc),&local_488,0);
        pHVar4 = (HWND)FUN_0050eb30();
        ReleaseDC(pHVar4,hdc);
        return 0;
      }
      if (DAT_00a37e80 != 2) goto LAB_00568916;
    }
    FUN_00517170();
    lpBits = *(void **)(puVar6 + 0xc);
    DVar7 = DAT_00a37ea8 - DAT_00a37ea0;
    w = DAT_00a37ea4 - DAT_00a37e9c;
    iVar3 = DAT_00a37e9c;
    yDest = DAT_00a37ea0;
    SrcWidth = DAT_00a37e60;
    SrcHeight = DAT_00a37e64;
  }
  else {
    lpBits = *(void **)(puVar6 + 0xc);
    DVar7 = 0x1e0;
    w = 0x280;
    SrcWidth = 0x140;
    SrcHeight = 0xf0;
LAB_0056890b:
    iVar3 = 0;
    yDest = 0;
  }
  StretchDIBits(hdc,iVar3,yDest,w,DVar7,0,0,SrcWidth,SrcHeight,lpBits,&local_488,0,0xcc0020);
LAB_00568916:
  pHVar4 = (HWND)FUN_0050eb30();
  ReleaseDC(pHVar4,hdc);
  return 0;
}

