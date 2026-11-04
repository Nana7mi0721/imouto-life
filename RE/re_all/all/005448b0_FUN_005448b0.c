
HBITMAP FUN_005448b0(BITMAPINFO *param_1,void *param_2,int param_3,int param_4)

{
  RGBQUAD *pRVar1;
  byte bVar2;
  ushort uVar3;
  int DestWidth;
  BYTE BVar4;
  BYTE BVar5;
  BYTE BVar6;
  HDC hdc;
  int iVar7;
  BITMAPINFO *lpbmi;
  HBITMAP h;
  HGDIOBJ h_00;
  DWORD h_01;
  DWORD cLines;
  int SrcHeight;
  void *local_1c;
  undefined1 local_18 [12];
  int local_c;
  
  hdc = CreateCompatibleDC((HDC)0x0);
  if ((param_4 == 0) ||
     ((*(byte *)(param_4 + 5) != 0x10 &&
      ((*(byte *)(param_4 + 5) < 0x19 || ((param_1->bmiHeader).biBitCount == 0x18)))))) {
    uVar3 = (param_1->bmiHeader).biBitCount;
    if (uVar3 < 9) {
      iVar7 = (1 << ((byte)uVar3 & 0x1f)) * 4;
    }
    else {
      iVar7 = 0;
    }
  }
  else {
    iVar7 = 0xc;
  }
  lpbmi = (BITMAPINFO *)
          FUN_0056e030(iVar7 + 0x28,"..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0x845);
  if (lpbmi == (BITMAPINFO *)0x0) {
    FUN_0056bb10(&DAT_007d5e68);
    DeleteDC(hdc);
    return (HBITMAP)0x0;
  }
  FUN_0056d380(lpbmi,0,0x28);
  (lpbmi->bmiHeader).biSize = 0x28;
  (lpbmi->bmiHeader).biWidth = (param_1->bmiHeader).biWidth;
  iVar7 = (param_1->bmiHeader).biHeight;
  if (iVar7 < 0) {
    iVar7 = -iVar7;
  }
  (lpbmi->bmiHeader).biHeight = -iVar7;
  (lpbmi->bmiHeader).biPlanes = 1;
  if (param_4 == 0) {
LAB_005449e0:
    if ((param_1->bmiHeader).biBitCount == 8) {
      (lpbmi->bmiHeader).biBitCount = 8;
      (lpbmi->bmiHeader).biCompression = (param_1->bmiHeader).biCompression;
      FUN_0056d420(lpbmi->bmiColors,param_1->bmiColors,0x400);
    }
    else {
      (lpbmi->bmiHeader).biBitCount = 0x18;
      (lpbmi->bmiHeader).biCompression = 0;
      if (param_4 != 0) {
        FUN_00544560(param_4);
      }
    }
  }
  else {
    bVar2 = *(byte *)(param_4 + 5);
    if (bVar2 == 0x10) {
      if ((DAT_00a52a4c == 1) || (DAT_00a52a50 != 0)) goto LAB_005449e0;
    }
    else if ((bVar2 < 0x19) || ((param_1->bmiHeader).biBitCount == 0x18)) {
      if (bVar2 == 0x20) {
        (lpbmi->bmiHeader).biBitCount = 0x18;
        FUN_00544560(param_4);
      }
      (lpbmi->bmiHeader).biCompression = 0;
      (lpbmi->bmiHeader).biBitCount = (ushort)*(byte *)(param_4 + 5);
      goto LAB_00544a26;
    }
    pRVar1 = (RGBQUAD *)(param_4 + 0x10);
    BVar4 = pRVar1->rgbGreen;
    BVar5 = pRVar1->rgbRed;
    BVar6 = pRVar1->rgbReserved;
    lpbmi->bmiColors[0].rgbBlue = pRVar1->rgbBlue;
    lpbmi->bmiColors[0].rgbGreen = BVar4;
    lpbmi->bmiColors[0].rgbRed = BVar5;
    lpbmi->bmiColors[0].rgbReserved = BVar6;
    lpbmi[1].bmiHeader.biSize = *(DWORD *)(param_4 + 0x14);
    lpbmi[1].bmiHeader.biWidth = *(LONG *)(param_4 + 0x18);
    (lpbmi->bmiHeader).biCompression = 3;
    (lpbmi->bmiHeader).biBitCount = (ushort)*(byte *)(param_4 + 5);
  }
LAB_00544a26:
  h = CreateDIBSection(hdc,lpbmi,0,&local_1c,(HANDLE)0x0,0);
  if (h == (HBITMAP)0x0) {
    FUN_0056bb10(&DAT_007d5e44);
    FUN_0056e1d0(lpbmi);
    DeleteDC(hdc);
    return (HBITMAP)0x0;
  }
  FUN_0056e1d0(lpbmi);
  GetObjectA(h,0x18,local_18);
  local_c = ((int)(local_c + 3 + (local_c + 3 >> 0x1f & 3U)) >> 2) * 4;
  if (local_1c == (void *)0x0) {
    FUN_0056bb10(&DAT_007d5e24);
    return (HBITMAP)0x0;
  }
  h_00 = SelectObject(hdc,h);
  if (param_3 == 0) {
    h_01 = (param_1->bmiHeader).biHeight;
    cLines = h_01;
    if (((int)h_01 < 0) && (cLines = -h_01, (int)h_01 < 0)) {
      h_01 = -h_01;
    }
    SetDIBitsToDevice(hdc,0,0,(param_1->bmiHeader).biWidth,h_01,0,0,0,cLines,param_2,param_1,0);
  }
  else {
    iVar7 = (param_1->bmiHeader).biHeight;
    SrcHeight = iVar7;
    if (iVar7 < 0) {
      SrcHeight = -iVar7;
    }
    DestWidth = (param_1->bmiHeader).biWidth;
    StretchDIBits(hdc,0,0,DestWidth,iVar7,DestWidth + -1,0,-DestWidth,SrcHeight,param_2,param_1,0,
                  0xcc0020);
  }
  SelectObject(hdc,h_00);
  DeleteDC(hdc);
  return h;
}

