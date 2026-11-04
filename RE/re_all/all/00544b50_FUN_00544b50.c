
int FUN_00544b50(BITMAPINFO *param_1,void *param_2,HBITMAP param_3,int param_4)

{
  RGBQUAD *pRVar1;
  RGBQUAD *pRVar2;
  ushort uVar3;
  WORD WVar4;
  RGBQUAD RVar5;
  RGBQUAD RVar6;
  BYTE BVar7;
  BYTE BVar8;
  BYTE BVar9;
  int iVar10;
  byte bVar11;
  int iVar12;
  uint uVar13;
  HDC hdc;
  HGDIOBJ h;
  DWORD DVar14;
  int iVar15;
  BITMAPINFO *pBVar16;
  LONG *pLVar17;
  DWORD cLines;
  char cVar18;
  uint uVar19;
  undefined1 local_44 [8];
  int local_3c;
  uint local_38;
  undefined4 local_30;
  BITMAPINFO local_2c;
  
  iVar10 = (int)param_3;
  FUN_0056d380(param_3,0,0x440);
  pBVar16 = param_1;
  *(LONG *)(iVar10 + 0x428) = (param_1->bmiHeader).biWidth;
  iVar12 = (param_1->bmiHeader).biHeight;
  if (iVar12 < 0) {
    iVar12 = -iVar12;
  }
  *(int *)(iVar10 + 0x42c) = iVar12;
  if ((((-1 < (param_1->bmiHeader).biHeight) || (uVar3 = (param_1->bmiHeader).biBitCount, uVar3 < 9)
       ) || ((uVar3 != 0x10 && ((uVar3 != 0x18 && (uVar3 != 0x20)))))) ||
     ((DVar14 = (param_1->bmiHeader).biCompression, DVar14 != 0 && (DVar14 != 3)))) {
    hdc = CreateCompatibleDC((HDC)0x0);
    FUN_0056d380(&local_2c,0,0x28);
    local_2c.bmiHeader.biHeight = (pBVar16->bmiHeader).biHeight;
    local_2c.bmiHeader.biWidth = (pBVar16->bmiHeader).biWidth;
    local_2c.bmiHeader.biSize = 0x28;
    if (local_2c.bmiHeader.biHeight < 0) {
      local_2c.bmiHeader.biHeight = -local_2c.bmiHeader.biHeight;
    }
    local_2c.bmiHeader.biHeight = -local_2c.bmiHeader.biHeight;
    local_2c.bmiHeader.biPlanes = 1;
    local_2c.bmiHeader.biBitCount = 0x18;
    local_2c.bmiHeader.biCompression = 0;
    param_3 = CreateDIBSection(hdc,&local_2c,0,&param_1,(HANDLE)0x0,0);
    if ((param_3 == (HBITMAP)0x0) || (param_1 == (BITMAPINFO *)0x0)) {
      FUN_0056bb10(&DAT_007d5e44);
      DeleteDC(hdc);
      return -1;
    }
    GetObjectA(param_3,0x18,local_44);
    uVar13 = local_38 & 0x80000003;
    if ((int)uVar13 < 0) {
      uVar13 = (uVar13 - 1 | 0xfffffffc) + 1;
    }
    if (uVar13 == 0) {
      iVar12 = 0;
    }
    else {
      iVar12 = 4 - uVar13;
    }
    local_38 = local_38 + iVar12;
    iVar12 = local_3c;
    if (local_3c < 0) {
      iVar12 = -local_3c;
    }
    h = SelectObject(hdc,param_3);
    DVar14 = (pBVar16->bmiHeader).biHeight;
    cLines = DVar14;
    if (((int)DVar14 < 0) && (cLines = -DVar14, (int)DVar14 < 0)) {
      DVar14 = -DVar14;
    }
    SetDIBitsToDevice(hdc,0,0,(pBVar16->bmiHeader).biWidth,DVar14,0,0,0,cLines,param_2,pBVar16,0);
    SelectObject(hdc,h);
    DeleteDC(hdc);
    iVar15 = FUN_0056e030(iVar12 * local_38,"..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp"
                          ,0x950);
    *(int *)(iVar10 + 0x434) = iVar15;
    if (iVar15 == 0) {
      FUN_0056bb10(&DAT_007d5eb0);
      return -1;
    }
    FUN_0056d420(iVar15,local_30,iVar12 * local_38);
    DeleteObject(param_3);
    FUN_00544560(iVar10);
    *(uint *)(iVar10 + 0x430) = local_38;
    return 1;
  }
  if (DVar14 == 3) {
    bVar11 = (byte)(param_1->bmiHeader).biBitCount;
    *(byte *)(iVar10 + 5) = bVar11;
    bVar11 = bVar11 >> 3;
    *(byte *)(iVar10 + 4) = bVar11;
    uVar13 = (uint)bVar11 * *(int *)(iVar10 + 0x428);
    uVar19 = uVar13 & 0x80000003;
    pRVar1 = param_1->bmiColors;
    *(uint *)(iVar10 + 0x430) = uVar13;
    if ((int)uVar19 < 0) {
      uVar19 = (uVar19 - 1 | 0xfffffffc) + 1;
    }
    if (uVar19 == 0) {
      iVar12 = 0;
    }
    else {
      iVar12 = 4 - uVar19;
    }
    *(uint *)(iVar10 + 0x430) = uVar13 + iVar12;
    RVar5.rgbBlue = pRVar1->rgbBlue;
    RVar5.rgbGreen = pRVar1->rgbGreen;
    RVar5.rgbRed = pRVar1->rgbRed;
    RVar5.rgbReserved = pRVar1->rgbReserved;
    iVar12 = 0;
    uVar13 = 1;
    do {
      if ((uVar13 & (uint)RVar5) != 0) break;
      iVar12 = iVar12 + 1;
      uVar13 = uVar13 * 2;
    } while (iVar12 < 0x20);
    cVar18 = '\0';
    *(char *)(iVar10 + 0xc) = (char)iVar12;
    if (iVar12 < 0x20) {
      RVar6.rgbBlue = pRVar1->rgbBlue;
      RVar6.rgbGreen = pRVar1->rgbGreen;
      RVar6.rgbRed = pRVar1->rgbRed;
      RVar6.rgbReserved = pRVar1->rgbReserved;
      cVar18 = '\0';
      do {
        if ((uVar13 & (uint)RVar6) == 0) break;
        iVar12 = iVar12 + 1;
        cVar18 = cVar18 + '\x01';
        uVar13 = uVar13 * 2;
      } while (iVar12 < 0x20);
    }
    *(char *)(iVar10 + 8) = cVar18;
    BVar7 = pRVar1->rgbGreen;
    BVar8 = pRVar1->rgbRed;
    BVar9 = pRVar1->rgbReserved;
    pBVar16 = param_1 + 1;
    pRVar2 = (RGBQUAD *)(iVar10 + 0x10);
    pRVar2->rgbBlue = pRVar1->rgbBlue;
    pRVar2->rgbGreen = BVar7;
    pRVar2->rgbRed = BVar8;
    pRVar2->rgbReserved = BVar9;
    uVar13 = 1;
    iVar12 = 0;
    do {
      if ((uVar13 & (pBVar16->bmiHeader).biSize) != 0) break;
      iVar12 = iVar12 + 1;
      uVar13 = uVar13 * 2;
    } while (iVar12 < 0x20);
    cVar18 = '\0';
    *(char *)(iVar10 + 0xd) = (char)iVar12;
    if (iVar12 < 0x20) {
      cVar18 = '\0';
      do {
        if ((uVar13 & (pBVar16->bmiHeader).biSize) == 0) break;
        iVar12 = iVar12 + 1;
        cVar18 = cVar18 + '\x01';
        uVar13 = uVar13 * 2;
      } while (iVar12 < 0x20);
    }
    *(char *)(iVar10 + 9) = cVar18;
    pLVar17 = &param_1[1].bmiHeader.biWidth;
    *(DWORD *)(iVar10 + 0x14) = (pBVar16->bmiHeader).biSize;
    uVar13 = 1;
    iVar12 = 0;
    do {
      if ((uVar13 & *pLVar17) != 0) break;
      iVar12 = iVar12 + 1;
      uVar13 = uVar13 * 2;
    } while (iVar12 < 0x20);
    cVar18 = '\0';
    *(char *)(iVar10 + 0xe) = (char)iVar12;
    if (iVar12 < 0x20) {
      cVar18 = '\0';
      do {
        if ((uVar13 & *pLVar17) == 0) break;
        iVar12 = iVar12 + 1;
        cVar18 = cVar18 + '\x01';
        uVar13 = uVar13 * 2;
      } while (iVar12 < 0x20);
    }
    *(char *)(iVar10 + 10) = cVar18;
    *(LONG *)(iVar10 + 0x18) = *pLVar17;
    *(undefined1 *)(iVar10 + 0xb) = 0;
    *(undefined1 *)(iVar10 + 0xf) = 0;
    *(undefined4 *)(iVar10 + 0x1c) = 0;
    FUN_00544840(iVar10);
    if (param_4 != 1) {
      *(void **)(iVar10 + 0x434) = param_2;
      return param_4;
    }
    iVar12 = FUN_0056e030(*(int *)(iVar10 + 0x42c) * *(int *)(iVar10 + 0x430),
                          "..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0x9a5);
    *(int *)(iVar10 + 0x434) = iVar12;
    if (iVar12 == 0) {
      return -1;
    }
    FUN_0056d420(iVar12,param_2,*(int *)(iVar10 + 0x42c) * *(int *)(iVar10 + 0x430));
    return 1;
  }
  if (DVar14 != 0) {
    return -1;
  }
  if ((uVar3 != 0x10) && (uVar3 != 0x18)) {
    return -1;
  }
  bVar11 = (byte)(param_1->bmiHeader).biBitCount;
  *(byte *)(iVar10 + 5) = bVar11;
  bVar11 = bVar11 >> 3;
  *(byte *)(iVar10 + 4) = bVar11;
  uVar13 = (uint)bVar11 * *(int *)(iVar10 + 0x428);
  uVar19 = uVar13 & 0x80000003;
  *(uint *)(iVar10 + 0x430) = uVar13;
  if ((int)uVar19 < 0) {
    uVar19 = (uVar19 - 1 | 0xfffffffc) + 1;
  }
  if (uVar19 == 0) {
    iVar12 = 0;
  }
  else {
    iVar12 = 4 - uVar19;
  }
  *(uint *)(iVar10 + 0x430) = uVar13 + iVar12;
  WVar4 = (param_1->bmiHeader).biBitCount;
  if (WVar4 == 0x10) {
    *(undefined1 *)(iVar10 + 8) = 5;
    *(undefined1 *)(iVar10 + 0xc) = 10;
    *(undefined4 *)(iVar10 + 0x10) = 0x7c00;
    *(undefined1 *)(iVar10 + 9) = 5;
    *(undefined1 *)(iVar10 + 0xd) = 5;
    *(undefined4 *)(iVar10 + 0x14) = 0x3e0;
    *(undefined1 *)(iVar10 + 10) = 5;
    *(undefined4 *)(iVar10 + 0x18) = 0x1f;
  }
  else {
    if (WVar4 != 0x18) goto LAB_00544e1a;
    *(undefined1 *)(iVar10 + 8) = 8;
    *(undefined1 *)(iVar10 + 0xc) = 0x10;
    *(undefined4 *)(iVar10 + 0x10) = 0xff0000;
    *(undefined1 *)(iVar10 + 9) = 8;
    *(undefined1 *)(iVar10 + 0xd) = 8;
    *(undefined4 *)(iVar10 + 0x14) = 0xff00;
    *(undefined1 *)(iVar10 + 10) = 8;
    *(undefined4 *)(iVar10 + 0x18) = 0xff;
  }
  *(undefined1 *)(iVar10 + 0xe) = 0;
LAB_00544e1a:
  *(undefined1 *)(iVar10 + 0xb) = 0;
  *(undefined1 *)(iVar10 + 0xf) = 0;
  *(undefined4 *)(iVar10 + 0x1c) = 0;
  FUN_00544840(iVar10);
  if (param_4 != 1) {
    *(void **)(iVar10 + 0x434) = param_2;
    return param_4;
  }
  iVar12 = FUN_0056e030(*(int *)(iVar10 + 0x42c) * *(int *)(iVar10 + 0x430),
                        "..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0x9da);
  *(int *)(iVar10 + 0x434) = iVar12;
  if (iVar12 == 0) {
    return -1;
  }
  FUN_0056d420(iVar12,param_2,*(int *)(iVar10 + 0x42c) * *(int *)(iVar10 + 0x430));
  return 1;
}

