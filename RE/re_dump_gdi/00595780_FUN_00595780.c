
undefined4 FUN_00595780(int param_1,int param_2,int param_3)

{
  LPCWSTR pszFaceName;
  bool bVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  HFONT pHVar7;
  int *piVar8;
  undefined4 uVar9;
  HDC hdc;
  HGDIOBJ pvVar10;
  DWORD DVar11;
  BITMAPINFO *lpbmi;
  RGBQUAD *pRVar12;
  HBITMAP pHVar13;
  int iVar14;
  code *pcVar15;
  short *psVar16;
  undefined1 *local_8b0;
  int local_8a8;
  int local_898;
  undefined1 *local_894;
  int local_890;
  MAT2 local_884;
  _GLYPHMETRICS local_874;
  tagTEXTMETRICA local_85c;
  undefined1 local_800 [2048];
  
  bVar2 = false;
  local_890 = 0;
  local_898 = 0;
  if (DAT_00a21068 == 1) {
    return 0xffffffff;
  }
  if (*(int *)(param_2 + 0x38) != 0) {
    return 0;
  }
  switch(*(undefined4 *)(param_2 + 0x93184)) {
  case 0:
  case 1:
  case 2:
  case 3:
    local_8a8 = 1;
    break;
  case 0x12:
  case 0x13:
    local_8a8 = 4;
    break;
  case 0x22:
  case 0x23:
    local_8a8 = 8;
  }
  iVar4 = (uint)*(ushort *)(param_2 + 0x93162) * local_8a8;
  do {
    psVar16 = (short *)(param_2 + 0x92f60);
    pvVar10 = *(HGDIOBJ *)(*(int *)(param_2 + 0x30) + 0x10);
    if (pvVar10 != (HGDIOBJ)0x0) {
      DeleteObject(pvVar10);
    }
    if (*psVar16 == 0) {
      pHVar7 = CreateFontW(iVar4 + local_890,0,0,0,(uint)*(ushort *)(param_2 + 0x93160) * 100,
                           (uint)*(byte *)(param_2 + 0x93168),0,0,
                           *(DWORD *)(&DAT_0085e584 + (uint)*(ushort *)(param_2 + 0x9316c) * 4),0,0,
                           3,1,L"ＭＳ ゴシック");
      pcVar15 = CreateFontW_exref;
      *(HFONT *)(*(int *)(param_2 + 0x30) + 0x10) = pHVar7;
      *psVar16 = 0;
    }
    else {
      if (param_3 == 1) {
        if (*psVar16 == 0x40) {
          psVar16 = (short *)(param_2 + 0x92f62);
        }
        iVar5 = FUN_0052fb90(local_800,0x10,psVar16,*(undefined2 *)(param_2 + 0x9316c));
        bVar1 = iVar5 < 0x10;
        if (bVar1) {
          local_8b0 = local_800;
        }
        else {
          iVar5 = FUN_0052fb90(0,0,psVar16,*(undefined2 *)(param_2 + 0x9316c));
          local_8b0 = (undefined1 *)
                      FUN_0056e030(iVar5 << 7,
                                   "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxFontWin.cpp",
                                   0x96);
          iVar5 = FUN_0052fb90(local_8b0,iVar5,psVar16,*(undefined2 *)(param_2 + 0x9316c));
        }
        iVar14 = 0;
        if (0 < iVar5) {
          local_894 = local_8b0;
          do {
            iVar6 = FUN_0056d130(local_894,psVar16);
            if (iVar6 == 0) break;
            local_894 = local_894 + 0x80;
            iVar14 = iVar14 + 1;
          } while (iVar14 < iVar5);
        }
        if (iVar14 == iVar5) {
          *(undefined2 *)(param_2 + 0x9316c) = 0;
        }
        if (!bVar1) {
          FUN_0056e1d0(local_8b0);
        }
      }
      pcVar15 = CreateFontW_exref;
      iVar5 = iVar4 + local_890;
      pszFaceName = (LPCWSTR)(param_2 + 0x92f60);
      pHVar7 = CreateFontW(iVar5,0,0,0,(uint)*(ushort *)(param_2 + 0x93160) * 100,
                           (uint)*(byte *)(param_2 + 0x93168),0,0,
                           *(DWORD *)(&DAT_0085e584 + (uint)*(ushort *)(param_2 + 0x9316c) * 4),0,0,
                           3,1,pszFaceName);
      *(HFONT *)(*(int *)(param_2 + 0x30) + 0x10) = pHVar7;
      if (*(int *)(*(int *)(param_2 + 0x30) + 0x10) == 0) {
        pHVar7 = CreateFontW(iVar5,0,0,0,(uint)*(ushort *)(param_2 + 0x93160) * 100,
                             (uint)*(byte *)(param_2 + 0x93168),0,0,1,0,0,3,1,pszFaceName);
        *(HFONT *)(*(int *)(param_2 + 0x30) + 0x10) = pHVar7;
        if (*(int *)(*(int *)(param_2 + 0x30) + 0x10) == 0) {
          pHVar7 = CreateFontW(iVar5,0,0,0,(uint)*(ushort *)(param_2 + 0x93160) * 100,
                               (uint)*(byte *)(param_2 + 0x93168),0,0,0x80,0,0,3,1,pszFaceName);
          *(HFONT *)(*(int *)(param_2 + 0x30) + 0x10) = pHVar7;
          if (*(int *)(*(int *)(param_2 + 0x30) + 0x10) == 0) {
            FUN_0056bb10(&DAT_007d9d98);
            return 0xffffffff;
          }
        }
      }
    }
    piVar8 = (int *)(*(int *)(param_2 + 0x30) + 0x10);
    if (*piVar8 == 0) {
      uVar9 = (*pcVar15)(iVar4 + local_890,0,0,0,(uint)*(ushort *)(param_2 + 0x93160) * 100,0,0,0,1,
                         0,0,3,1,&DAT_007d9d88);
      *(undefined4 *)(*(int *)(param_2 + 0x30) + 0x10) = uVar9;
      if (*(int *)(*(int *)(param_2 + 0x30) + 0x10) == 0) {
        uVar9 = (*pcVar15)(iVar4 + local_890,0,0,0,(uint)*(ushort *)(param_2 + 0x93160) * 100,0,0,0,
                           1,0,0,3,1,0);
        *(undefined4 *)(*(int *)(param_2 + 0x30) + 0x10) = uVar9;
      }
      piVar8 = (int *)(*(int *)(param_2 + 0x30) + 0x10);
      *(undefined2 *)(param_2 + 0x92f60) = 0;
      if (*piVar8 == 0) {
        FUN_0056bb10(&DAT_007d9d68);
        return 0xffffffff;
      }
    }
    GetObjectW((HANDLE)*piVar8,0x5c,&local_85c);
    FUN_0056cf70((undefined2 *)(param_2 + 0x92f60),0x200,&local_85c.tmWeight);
    hdc = CreateCompatibleDC((HDC)0x0);
    if (hdc == (HDC)0x0) {
      FUN_0056bb10(&DAT_007d9d3c);
      return 0xffffffff;
    }
    pvVar10 = SelectObject(hdc,*(HGDIOBJ *)(*(int *)(param_2 + 0x30) + 0x10));
    GetTextMetricsA(hdc,&local_85c);
    if (bVar2) {
      *(short *)(param_2 + 0x93166) = (short)((local_85c.tmHeight - local_898) / local_8a8);
      goto LAB_00595c51;
    }
    if ((*(int *)(param_1 + 0x10) != 0) ||
       (local_85c.tmInternalLeading + local_85c.tmExternalLeading < 1)) {
      *(undefined2 *)(param_2 + 0x93166) = 0;
LAB_00595c51:
      if (*(char *)(param_2 + 0x93168) == '\0') {
        sVar3 = (short)(local_85c.tmMaxCharWidth / local_8a8) + 4;
      }
      else {
        sVar3 = (short)(((local_85c.tmMaxCharWidth * 0x87) / local_8a8 + 0x21c) / 100);
      }
      *(short *)(param_2 + 0x9316a) = sVar3;
      *(short *)(param_2 + 0x93164) = (short)(local_85c.tmHeight / local_8a8) + 1;
      sVar3 = (short)(local_85c.tmAscent / local_8a8);
      *(short *)(param_2 + 0x93170) = sVar3;
      if (local_8a8 / 2 <= local_85c.tmAscent % local_8a8) {
        *(short *)(param_2 + 0x93170) = sVar3 + 1;
      }
      local_884.eM11.fract = 0;
      local_884.eM11.value = 1;
      local_884.eM12.fract = 0;
      local_884.eM12.value = 0;
      local_884.eM21.fract = 0;
      local_884.eM21.value = 0;
      local_884.eM22.fract = 0;
      local_884.eM22.value = 1;
      FUN_0056d380(&local_874,0,0x14);
      DVar11 = GetGlyphOutlineW(hdc,0x20,1,&local_874,0,(LPVOID)0x0,&local_884);
      if (DVar11 == 0xffffffff) {
        **(undefined4 **)(param_2 + 0x30) = 1;
        *(undefined4 *)(param_2 + 0x935fc) = 0x10;
      }
      *(undefined4 *)(*(int *)(param_2 + 0x30) + 0x14) = 0;
      if ((DAT_00aba1f8 != (code *)0x0) && (iVar4 = (*DAT_00aba1f8)(hdc,0), iVar4 != 0)) {
        uVar9 = FUN_0056e030(iVar4,"..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxFontWin.cpp",
                             0x16e);
        *(undefined4 *)(*(int *)(param_2 + 0x30) + 0x14) = uVar9;
        iVar4 = *(int *)(*(int *)(param_2 + 0x30) + 0x14);
        if (iVar4 == 0) {
          SelectObject(hdc,pvVar10);
          DeleteDC(hdc);
          DeleteObject(*(HGDIOBJ *)(*(int *)(param_2 + 0x30) + 0x10));
          *(undefined4 *)(*(int *)(param_2 + 0x30) + 0x10) = 0;
          uVar9 = FUN_0056bb10(&DAT_007d9cfc);
          return uVar9;
        }
        (*DAT_00aba1f8)(hdc,iVar4);
      }
      *(undefined4 *)(*(int *)(param_2 + 0x30) + 4) = 0;
      *(undefined4 *)(*(int *)(param_2 + 0x30) + 8) = 0;
      *(undefined4 *)(*(int *)(param_2 + 0x30) + 0xc) = 0;
      if (**(int **)(param_2 + 0x30) != 0) {
        switch(*(undefined4 *)(param_2 + 0x93184)) {
        case 2:
        case 0x12:
        case 0x22:
          *(undefined4 *)(param_2 + 0x93184) = 0;
          break;
        case 3:
        case 0x13:
        case 0x23:
          *(undefined4 *)(param_2 + 0x93184) = 1;
        }
        lpbmi = (BITMAPINFO *)
                FUN_0056e050(0x42c,"..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxFontWin.cpp",
                             0x198);
        if (lpbmi == (BITMAPINFO *)0x0) {
          uVar9 = FUN_0056bb10(&DAT_007d9ccc);
          return uVar9;
        }
        (lpbmi->bmiHeader).biSize = 0x28;
        (lpbmi->bmiHeader).biWidth = (uint)*(ushort *)(param_2 + 0x9316a);
        (lpbmi->bmiHeader).biHeight = -(uint)*(ushort *)(param_2 + 0x9316a);
        (lpbmi->bmiHeader).biPlanes = 1;
        (lpbmi->bmiHeader).biBitCount = 8;
        (lpbmi->bmiHeader).biCompression = 0;
        (lpbmi->bmiHeader).biSizeImage =
             (uint)*(ushort *)(param_2 + 0x9316a) * (uint)*(ushort *)(param_2 + 0x9316a);
        pRVar12 = lpbmi->bmiColors;
        iVar4 = 0;
        do {
          pRVar12->rgbRed = (BYTE)iVar4;
          pRVar12->rgbBlue = (BYTE)iVar4;
          pRVar12->rgbReserved = '\0';
          iVar4 = iVar4 + 1;
          pRVar12 = pRVar12 + 1;
        } while (iVar4 < 0x100);
        *(undefined4 *)(*(int *)(param_2 + 0x30) + 8) = 0;
        pHVar13 = CreateDIBSection(hdc,lpbmi,1,(void **)(*(int *)(param_2 + 0x30) + 8),(HANDLE)0x0,0
                                  );
        *(HBITMAP *)(*(int *)(param_2 + 0x30) + 4) = pHVar13;
        GetObjectA(*(HANDLE *)(*(int *)(param_2 + 0x30) + 4),0x18,&local_874);
        *(LONG *)(*(int *)(param_2 + 0x30) + 0xc) = local_874.gmptGlyphOrigin.y;
        FUN_0056e1d0(lpbmi);
      }
      SelectObject(hdc,pvVar10);
      DeleteDC(hdc);
      return 0;
    }
    local_898 = local_85c.tmHeight;
    local_890 = (int)ROUND((float)iVar4 /
                           (1.0 - (float)(local_85c.tmInternalLeading + local_85c.tmExternalLeading)
                                  / (float)local_85c.tmHeight)) - iVar4;
    bVar2 = true;
    SelectObject(hdc,pvVar10);
    DeleteDC(hdc);
    DeleteObject(*(HGDIOBJ *)(*(int *)(param_2 + 0x30) + 0x10));
    *(undefined4 *)(*(int *)(param_2 + 0x30) + 0x10) = 0;
  } while( true );
}

