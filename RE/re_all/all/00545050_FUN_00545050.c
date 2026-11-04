
/* WARNING: Removing unreachable block (ram,0x00545544) */
/* WARNING: Removing unreachable block (ram,0x005454d3) */

undefined4 FUN_00545050(undefined4 *param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  WORD WVar3;
  undefined4 uVar4;
  RGBQUAD RVar5;
  ushort uVar6;
  short sVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  HDC hdc;
  HBITMAP h;
  DWORD DVar12;
  uint uVar13;
  byte *pbVar14;
  uint *puVar15;
  uint *puVar16;
  uint uVar17;
  DWORD cLines;
  ushort *puVar18;
  ushort *puVar19;
  uint *puVar20;
  undefined1 *puVar21;
  ushort *puVar22;
  int iVar23;
  int iVar24;
  HGDIOBJ pvVar25;
  bool bVar26;
  undefined *puVar27;
  ushort *local_a0;
  uint *local_9c;
  BITMAPINFO *pBStack_98;
  uint *local_94;
  ushort *puStack_90;
  HGDIOBJ pvStack_8c;
  HDC local_88;
  HBITMAP local_84;
  undefined1 auStack_80 [8];
  int iStack_78;
  int iStack_74;
  undefined4 uStack_6c;
  undefined1 auStack_68 [4];
  int iStack_64;
  int iStack_60;
  byte bStack_5a;
  undefined1 uStack_59;
  undefined2 uStack_58;
  undefined2 uStack_56;
  undefined1 auStack_3c [10];
  undefined4 uStack_32;
  BITMAPINFO BStack_2c;
  
  uVar4 = param_1[6];
  local_9c = (uint *)0x0;
  local_94 = (uint *)0x0;
  local_a0 = (ushort *)0x0;
  local_88 = (HDC)0x0;
  local_84 = (HBITMAP)0x0;
  (*(code *)param_1[1])(uVar4,0,0,2);
  iVar9 = (*(code *)*param_1)(uVar4);
  (*(code *)param_1[1])(uVar4,0,0,0);
  iVar10 = (*(code *)param_1[2])(auStack_3c,0xe,1,uVar4);
  if (iVar10 == 0) {
    return 0xffffffff;
  }
  iVar10 = FUN_0056d3d0(auStack_3c,&DAT_007d5f00,2);
  if (iVar10 != 0) {
    return 0xffffffff;
  }
  iVar10 = (*(code *)param_1[2])(auStack_68,0x2c,1,uVar4);
  if (iVar10 == 0) {
    return 0xffffffff;
  }
  uVar6 = CONCAT11(uStack_59,bStack_5a);
  if (uVar6 < 9) {
    pBStack_98 = (BITMAPINFO *)
                 FUN_0056e050(0x42c,"..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0xaea);
    if (pBStack_98 == (BITMAPINFO *)0x0) {
      return 0xffffffff;
    }
    FUN_0056d420(pBStack_98,auStack_68,0x2c);
    iVar10 = (*(code *)param_1[2])(pBStack_98 + 1,1,(1 << (bStack_5a & 0x1f)) * 4 + -4,uVar4);
LAB_005451d9:
    if (iVar10 == 0) goto LAB_00545f9c;
  }
  else if (((uVar6 == 0x10) || (uVar6 == 0x20)) || (CONCAT22(uStack_56,uStack_58) == 3)) {
    pBStack_98 = (BITMAPINFO *)
                 FUN_0056e050(0x34,"..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0xaf7);
    if (pBStack_98 == (BITMAPINFO *)0x0) {
      return 0xffffffff;
    }
    FUN_0056d420(pBStack_98,auStack_68,0x2c);
    if (CONCAT22(uStack_56,uStack_58) == 3) {
      iVar10 = (*(code *)param_1[2])(pBStack_98 + 1,8,1,uVar4);
      goto LAB_005451d9;
    }
  }
  else {
    pBStack_98 = (BITMAPINFO *)
                 FUN_0056e050(0x2c,"..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0xb06);
    if (pBStack_98 == (BITMAPINFO *)0x0) {
      return 0xffffffff;
    }
    FUN_0056d420(pBStack_98,auStack_68,0x2c);
  }
  (*(code *)param_1[1])(uVar4,uStack_32,0,0);
  uVar13 = (uint)CONCAT11(uStack_59,bStack_5a) * iStack_64;
  iVar10 = (int)(uVar13 + ((int)uVar13 >> 0x1f & 7U)) >> 3;
  uVar13 = uVar13 & 0x80000007;
  bVar26 = uVar13 == 0;
  if ((int)uVar13 < 0) {
    bVar26 = (uVar13 - 1 | 0xfffffff8) == 0xffffffff;
  }
  if (!bVar26) {
    iVar10 = iVar10 + 1;
  }
  iVar23 = (int)(iVar10 + 3 + (iVar10 + 3 >> 0x1f & 3U)) >> 2;
  iVar10 = iVar23 * 4;
  if (iStack_60 < 0) {
    iStack_60 = -iStack_60;
  }
  pvStack_8c = (HGDIOBJ)(iStack_60 * iVar10);
  if (param_3 == 0) {
    iVar11 = (*(code *)*param_1)(uVar4);
    local_9c = (uint *)FUN_0056e030(iVar9 - iVar11,
                                    "..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0xb1d);
    if ((local_9c == (uint *)0x0) ||
       (iVar9 = (*(code *)param_1[2])(local_9c,1,iVar9 - iVar11,uVar4), iVar9 == 0))
    goto LAB_00545f9c;
  }
  DVar12 = (pBStack_98->bmiHeader).biCompression;
  sVar7 = CONCAT11(uStack_59,bStack_5a);
  if (DVar12 == 1) {
    if (param_3 == 0) {
      local_a0 = (ushort *)
                 FUN_0056e030(pvStack_8c,"..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",
                              0xb2c);
      if (local_a0 == (ushort *)0x0) goto LAB_00545f9c;
      FUN_0056d380(local_a0,0,pvStack_8c);
      iVar9 = (pBStack_98->bmiHeader).biHeight;
      if (iVar9 < 0) {
        puVar18 = local_a0;
        local_94 = (uint *)iVar10;
      }
      else {
        puVar18 = (ushort *)((iVar9 + -1) * iVar10 + (int)local_a0);
        local_94 = (uint *)(iVar23 * -4);
      }
      puVar19 = puVar18;
      puVar20 = local_9c;
      while( true ) {
        while( true ) {
          while( true ) {
            bVar1 = *(byte *)((int)puVar20 + 1);
            if ((byte)*puVar20 == 0) break;
            FUN_0056d380(puVar18,bVar1,(byte)*puVar20);
            puVar18 = (ushort *)((int)puVar18 + (uint)(byte)*puVar20);
            puVar20 = (uint *)((int)puVar20 + 2);
          }
          if (bVar1 != 0) break;
          puVar18 = (ushort *)((int)puVar19 + (int)local_94);
          puVar20 = (uint *)((int)puVar20 + 2);
          puVar19 = puVar18;
        }
        if (bVar1 == 1) break;
        if (bVar1 == 2) {
          puVar19 = (ushort *)
                    ((int)puVar19 + (int)(char)*(byte *)((int)puVar20 + 3) * (int)local_94);
          puVar18 = (ushort *)((int)(char)*(byte *)((int)puVar20 + 2) + (int)puVar19);
          puVar20 = puVar20 + 1;
        }
        else {
          FUN_0056d420(puVar18,(byte *)((int)puVar20 + 2),bVar1);
          puVar18 = (ushort *)((int)puVar18 + (uint)*(byte *)((int)puVar20 + 1));
          puVar20 = (uint *)(((uint)(*(byte *)((int)puVar20 + 1) + 1 + (int)puVar20) & 0xfffffffe) +
                            2);
        }
      }
      FUN_0056e1d0(local_9c);
    }
    *(uint *)(param_2 + 0x434) = ~-(uint)(param_3 != 0) & (uint)local_a0;
    *(LONG *)(param_2 + 0x428) = (pBStack_98->bmiHeader).biWidth;
    iVar9 = (pBStack_98->bmiHeader).biHeight;
    if (iVar9 < 0) {
      iVar9 = -iVar9;
    }
    *(int *)(param_2 + 0x42c) = iVar9;
    *(int *)(param_2 + 0x430) = iVar10;
    FUN_00544440(param_2);
    FUN_0056d420(param_2 + 0x28,pBStack_98->bmiColors,0x400);
    puVar21 = (undefined1 *)(param_2 + 0x2b);
    iVar9 = 0x100;
    do {
      *puVar21 = 0;
      puVar21 = puVar21 + 4;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    goto LAB_00546033;
  }
  if (DVar12 == 2) {
    iVar10 = (pBStack_98->bmiHeader).biWidth + 3;
    iVar9 = (pBStack_98->bmiHeader).biHeight;
    iVar10 = (int)(iVar10 + (iVar10 >> 0x1f & 3U)) >> 2;
    puVar18 = (ushort *)(iVar10 * 4);
    if (iVar9 < 0) {
      iVar9 = -iVar9;
    }
    puStack_90 = puVar18;
    if (param_3 == 0) {
      local_a0 = (ushort *)
                 FUN_0056e030(iVar9 * (int)puVar18,
                              "..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0xb8f);
      if (local_a0 == (ushort *)0x0) goto LAB_00545f9c;
      FUN_0056d380(local_a0,0,iVar9 * (int)puVar18);
      iVar9 = (pBStack_98->bmiHeader).biHeight;
      if (iVar9 < 0) {
        puVar19 = local_a0;
        local_94 = (uint *)puVar18;
      }
      else {
        puVar19 = (ushort *)((iVar9 + -1) * (int)puVar18 + (int)local_a0);
        local_94 = (uint *)(iVar10 * -4);
      }
      puVar20 = local_9c;
      puVar22 = puVar19;
LAB_00545498:
      while( true ) {
        for (; bVar1 = (byte)*puVar20, bVar1 != 0; puVar20 = (uint *)((int)puVar20 + 2)) {
          bVar2 = *(byte *)((int)puVar20 + 1);
          bVar8 = bVar2 >> 4;
          for (uVar13 = bVar1 / 2; uVar13 != 0; uVar13 = uVar13 - 1) {
            *puVar22 = CONCAT11(bVar2,bVar8) & 0xfff;
            puVar22 = puVar22 + 1;
          }
          if ((bVar1 & 1) == 0) goto LAB_00545597;
          *(byte *)puVar22 = bVar8;
          puVar22 = (ushort *)((int)puVar22 + 1);
          puVar18 = puStack_90;
        }
        bVar1 = *(byte *)((int)puVar20 + 1);
        uVar13 = (uint)bVar1;
        if (uVar13 != 0) break;
        puVar19 = (ushort *)((int)puVar19 + (int)local_94);
        puVar22 = puVar19;
LAB_00545597:
        puVar20 = (uint *)((int)puVar20 + 2);
        puVar18 = puStack_90;
      }
      if (uVar13 != 1) {
        if (uVar13 == 2) {
          puVar19 = (ushort *)
                    ((int)puVar19 + (int)(char)*(byte *)((int)puVar20 + 3) * (int)local_94);
          puVar22 = (ushort *)((int)(char)*(byte *)((int)puVar20 + 2) + (int)puVar19);
          puVar20 = puVar20 + 1;
          puVar18 = puStack_90;
        }
        else {
          pbVar14 = (byte *)((int)puVar20 + 2);
          for (uVar13 = uVar13 / 2; uVar13 != 0; uVar13 = uVar13 - 1) {
            *(byte *)puVar22 = *pbVar14 >> 4;
            *(byte *)((int)puVar22 + 1) = *pbVar14 & 0xf;
            puVar22 = puVar22 + 1;
            pbVar14 = pbVar14 + 1;
          }
          if ((bVar1 & 1) != 0) {
            *(byte *)puVar22 = *pbVar14 >> 4;
            pbVar14 = pbVar14 + 1;
            puVar22 = (ushort *)((int)puVar22 + 1);
          }
          puVar20 = (uint *)((uint)(pbVar14 + 1) & 0xfffffffe);
          puVar18 = puStack_90;
        }
        goto LAB_00545498;
      }
      FUN_0056e1d0(local_9c);
    }
    *(ushort **)(param_2 + 0x434) = local_a0;
    *(LONG *)(param_2 + 0x428) = (pBStack_98->bmiHeader).biWidth;
    iVar9 = (pBStack_98->bmiHeader).biHeight;
    if (iVar9 < 0) {
      iVar9 = -iVar9;
    }
    *(int *)(param_2 + 0x42c) = iVar9;
    *(ushort **)(param_2 + 0x430) = puVar18;
    FUN_00544440(param_2);
    FUN_0056d420(param_2 + 0x28,pBStack_98->bmiColors,0x40);
    puVar21 = (undefined1 *)(param_2 + 0x2b);
    iVar9 = 0x10;
    do {
      *puVar21 = 0;
      puVar21 = puVar21 + 4;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    goto LAB_00546033;
  }
  if (DVar12 == 0) {
    if ((pBStack_98->bmiHeader).biBitCount == 1) {
      local_a0 = (ushort *)(pBStack_98->bmiHeader).biHeight;
      iVar9 = (pBStack_98->bmiHeader).biWidth;
      if ((int)local_a0 < 0) {
        local_a0 = (ushort *)-(int)local_a0;
      }
      puVar18 = (ushort *)(((int)(iVar9 + 3 + (iVar9 + 3 >> 0x1f & 3U)) >> 2) * 4);
      puStack_90 = puVar18;
      if (param_3 == 0) {
        local_94 = (uint *)FUN_0056e030((int)puVar18 * (int)local_a0,
                                        "..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",
                                        0xc10);
        if (local_94 == (uint *)0x0) goto LAB_00545f9c;
        iVar11 = (int)(iVar9 + (iVar9 >> 0x1f & 7U)) >> 3;
        iVar23 = iVar9 + iVar11 * -8;
        if ((pBStack_98->bmiHeader).biHeight < 1) {
          iVar24 = iVar10 - iVar11;
          puVar20 = local_9c;
        }
        else {
          iVar24 = -(iVar10 + iVar11);
          puVar20 = (uint *)(((int)local_a0 + -1) * iVar10 + (int)local_9c);
        }
        local_84 = (HBITMAP)((int)puVar18 - iVar9);
        puVar16 = local_94;
        do {
          if (iVar11 != 0) {
            iVar9 = iVar11;
            do {
              *(byte *)puVar16 = (byte)*puVar20 >> 7;
              *(byte *)((int)puVar16 + 1) = (byte)*puVar20 >> 6 & 1;
              *(byte *)((int)puVar16 + 2) = (byte)*puVar20 >> 5 & 1;
              *(byte *)((int)puVar16 + 3) = (byte)*puVar20 >> 4 & 1;
              *(byte *)(puVar16 + 1) = (byte)*puVar20 >> 3 & 1;
              *(byte *)((int)puVar16 + 5) = (byte)*puVar20 >> 2 & 1;
              *(byte *)((int)puVar16 + 6) = (byte)*puVar20 >> 1 & 1;
              *(byte *)((int)puVar16 + 7) = (byte)*puVar20 & 1;
              puVar16 = puVar16 + 2;
              puVar20 = (uint *)((int)puVar20 + 1);
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
          if (iVar23 != 0) {
            *(byte *)puVar16 = (byte)*puVar20 >> 7;
            puVar15 = (uint *)((int)puVar16 + 1);
            for (iVar9 = iVar23 + -1; puVar16 = puVar15, iVar9 != 0; iVar9 = iVar9 + -8) {
              *(byte *)puVar15 = (byte)*puVar20 >> 6 & 1;
              puVar16 = (uint *)((int)puVar15 + 1);
              if (iVar9 == 1) break;
              *(byte *)puVar16 = (byte)*puVar20 >> 5 & 1;
              puVar16 = (uint *)((int)puVar15 + 2);
              if (iVar9 == 2) break;
              *(byte *)puVar16 = (byte)*puVar20 >> 4 & 1;
              puVar16 = (uint *)((int)puVar15 + 3);
              if (iVar9 == 3) break;
              *(byte *)puVar16 = (byte)*puVar20 >> 3 & 1;
              puVar16 = puVar15 + 1;
              if (iVar9 == 4) break;
              *(byte *)puVar16 = (byte)*puVar20 >> 2 & 1;
              puVar16 = (uint *)((int)puVar15 + 5);
              if (iVar9 == 5) break;
              *(byte *)puVar16 = (byte)*puVar20 >> 1 & 1;
              puVar16 = (uint *)((int)puVar15 + 6);
              if (iVar9 == 6) break;
              *(byte *)puVar16 = (byte)*puVar20 & 1;
              puVar16 = (uint *)((int)puVar15 + 7);
              puVar20 = (uint *)((int)puVar20 + 1);
              if (iVar9 == 7) break;
              *(byte *)puVar16 = *(byte *)puVar20 >> 7;
              puVar15 = puVar15 + 2;
            }
          }
          puVar16 = (uint *)((int)puVar16 + (int)local_84);
          puVar20 = (uint *)((int)puVar20 + iVar24);
          local_a0 = (ushort *)((int)local_a0 + -1);
        } while (local_a0 != (ushort *)0x0);
        FUN_0056e1d0(local_9c);
        local_9c = local_94;
      }
      *(uint **)(param_2 + 0x434) = local_9c;
      *(LONG *)(param_2 + 0x428) = (pBStack_98->bmiHeader).biWidth;
      iVar9 = (pBStack_98->bmiHeader).biHeight;
      if (iVar9 < 0) {
        iVar9 = -iVar9;
      }
      *(int *)(param_2 + 0x42c) = iVar9;
      *(ushort **)(param_2 + 0x430) = puStack_90;
      FUN_00544440(param_2);
      *(undefined4 *)(param_2 + 0x24) = 0xf;
      FUN_0056d420(param_2 + 0x28,pBStack_98->bmiColors,8);
      *(undefined1 *)(param_2 + 0x2b) = 0;
      *(undefined1 *)(param_2 + 0x2f) = 0;
      goto LAB_00546033;
    }
    if ((pBStack_98->bmiHeader).biBitCount == 4) {
      local_a0 = (ushort *)(pBStack_98->bmiHeader).biHeight;
      iVar9 = (pBStack_98->bmiHeader).biWidth;
      if ((int)local_a0 < 0) {
        local_a0 = (ushort *)-(int)local_a0;
      }
      puStack_90 = (ushort *)(((int)(iVar9 + 3 + (iVar9 + 3 >> 0x1f & 3U)) >> 2) * 4);
      if (param_3 == 0) {
        local_94 = (uint *)FUN_0056e030((int)puStack_90 * (int)local_a0,
                                        "..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",
                                        0xc8a);
        if (local_94 == (uint *)0x0) goto LAB_00545f9c;
        pvStack_8c = (HGDIOBJ)((int)(iVar9 + (iVar9 >> 0x1f & 7U)) >> 3);
        iVar11 = iVar9 + (int)pvStack_8c * -8;
        if ((pBStack_98->bmiHeader).biHeight < 1) {
          puVar20 = local_9c;
        }
        else {
          iVar24 = ((int)local_a0 + -1) * iVar10;
          iVar10 = iVar23 * -4;
          puVar20 = (uint *)(iVar24 + (int)local_9c);
        }
        local_88 = (HDC)(iVar10 - iVar9 / 2);
        puVar16 = local_94;
        do {
          if (pvStack_8c != (HGDIOBJ)0x0) {
            pvVar25 = pvStack_8c;
            do {
              uVar13 = *puVar20 >> 4 & 0xf0f0f0f;
              *(byte *)((int)puVar16 + 2) = (byte)(uVar13 >> 8);
              *(byte *)puVar16 = (byte)uVar13;
              *(byte *)(puVar16 + 1) = (byte)(uVar13 >> 0x10);
              *(byte *)((int)puVar16 + 6) = (byte)(uVar13 >> 0x18);
              uVar13 = *puVar20 & 0xf0f0f0f;
              *(byte *)((int)puVar16 + 3) = (byte)(uVar13 >> 8);
              *(byte *)((int)puVar16 + 1) = (byte)uVar13;
              *(byte *)((int)puVar16 + 5) = (byte)(uVar13 >> 0x10);
              *(byte *)((int)puVar16 + 7) = (byte)(uVar13 >> 0x18);
              puVar16 = puVar16 + 2;
              puVar20 = puVar20 + 1;
              pvVar25 = (HGDIOBJ)((int)pvVar25 + -1);
            } while (pvVar25 != (HGDIOBJ)0x0);
          }
          if (iVar11 != 0) {
            *(byte *)puVar16 = (byte)*puVar20 >> 4;
            puVar15 = (uint *)((int)puVar16 + 1);
            for (iVar10 = iVar11 + -1; puVar16 = puVar15, iVar10 != 0; iVar10 = iVar10 + -2) {
              *(byte *)puVar15 = (byte)*puVar20 & 0xf;
              puVar16 = (uint *)((int)puVar15 + 1);
              puVar20 = (uint *)((int)puVar20 + 1);
              if (iVar10 == 1) break;
              *(byte *)puVar16 = *(byte *)puVar20 >> 4;
              puVar15 = (uint *)((int)puVar15 + 2);
            }
          }
          puVar20 = (uint *)((int)puVar20 + (int)local_88);
          puVar16 = (uint *)((int)puVar16 + ((int)puStack_90 - iVar9));
          local_a0 = (ushort *)((int)local_a0 + -1);
        } while (local_a0 != (ushort *)0x0);
        FUN_0056e1d0(local_9c);
        local_9c = local_94;
      }
      *(uint **)(param_2 + 0x434) = local_9c;
      *(LONG *)(param_2 + 0x428) = (pBStack_98->bmiHeader).biWidth;
      iVar9 = (pBStack_98->bmiHeader).biHeight;
      if (iVar9 < 0) {
        iVar9 = -iVar9;
      }
      *(int *)(param_2 + 0x42c) = iVar9;
      *(ushort **)(param_2 + 0x430) = puStack_90;
      FUN_00544440(param_2);
      *(undefined4 *)(param_2 + 0x24) = 0xf;
      FUN_0056d420(param_2 + 0x28,pBStack_98->bmiColors,0x40);
      puVar21 = (undefined1 *)(param_2 + 0x2b);
      iVar9 = 0x10;
      do {
        *puVar21 = 0;
        puVar21 = puVar21 + 4;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      goto LAB_00546033;
    }
    WVar3 = (pBStack_98->bmiHeader).biBitCount;
    if (((WVar3 != 0x20) && (WVar3 != 0x18)) && (WVar3 != 8)) goto LAB_00545bd1;
    if (param_3 == 0) {
      local_a0 = (ushort *)(pBStack_98->bmiHeader).biHeight;
      if ((int)local_a0 < 1) {
        local_a0 = (ushort *)-(int)local_a0;
      }
      else {
        local_94 = (uint *)FUN_0056e030((int)local_a0 * iVar10,
                                        "..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",
                                        0xcec);
        if (local_94 == (uint *)0x0) goto LAB_00545f9c;
        puVar20 = (uint *)(((int)local_a0 + -1) * iVar10 + (int)local_9c);
        if (0 < (int)local_a0) {
          puVar16 = local_94;
          puStack_90 = local_a0;
          do {
            FUN_0056d420(puVar16,puVar20,iVar10);
            puVar20 = puVar20 + -iVar23;
            puVar16 = puVar16 + iVar23;
            puStack_90 = (ushort *)((int)puStack_90 + -1);
          } while (puStack_90 != (ushort *)0x0);
        }
        FUN_0056e1d0(local_9c);
        local_9c = local_94;
      }
    }
    *(uint **)(param_2 + 0x434) = local_9c;
    *(LONG *)(param_2 + 0x428) = (pBStack_98->bmiHeader).biWidth;
    iVar9 = (pBStack_98->bmiHeader).biHeight;
    if (iVar9 < 0) {
      iVar9 = -iVar9;
    }
    *(int *)(param_2 + 0x42c) = iVar9;
    *(int *)(param_2 + 0x430) = iVar10;
    WVar3 = (pBStack_98->bmiHeader).biBitCount;
    if (WVar3 == 8) {
      FUN_00544440(param_2);
      FUN_0056d420(param_2 + 0x28,pBStack_98->bmiColors,
                   ((-(uint)((pBStack_98->bmiHeader).biBitCount != 8) & 0xffffff10) + 0x100) * 4);
      puVar21 = (undefined1 *)(param_2 + 0x2b);
      iVar9 = 0x100;
      do {
        *puVar21 = 0;
        puVar21 = puVar21 + 4;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      goto LAB_00546033;
    }
    if (WVar3 != 0x18) {
      if (DAT_00a52a48 != 0) {
        uVar13 = (pBStack_98->bmiHeader).biWidth * (int)local_a0;
        uVar17 = 0;
        if (uVar13 != 0) {
          pbVar14 = (byte *)((int)local_9c + 3);
          do {
            if (*pbVar14 != 0) break;
            uVar17 = uVar17 + 1;
            pbVar14 = pbVar14 + 4;
          } while (uVar17 < uVar13);
        }
        if (uVar17 == uVar13) {
          FUN_005444a0();
          goto LAB_00546033;
        }
      }
      FUN_00544500(param_2);
      goto LAB_00546033;
    }
  }
  else {
LAB_00545bd1:
    if ((sVar7 == 0x20) || (sVar7 == 0x10)) {
      if (CONCAT22(uStack_56,uStack_58) == 3) {
        RVar5.rgbBlue = pBStack_98->bmiColors[0].rgbBlue;
        RVar5.rgbGreen = pBStack_98->bmiColors[0].rgbGreen;
        RVar5.rgbRed = pBStack_98->bmiColors[0].rgbRed;
        RVar5.rgbReserved = pBStack_98->bmiColors[0].rgbReserved;
        if (((RVar5 == (RGBQUAD)0xff000000) && (pBStack_98[1].bmiHeader.biSize == 0xff0000)) &&
           (pBStack_98[1].bmiHeader.biWidth == 0xff00)) {
          local_a0 = (ushort *)0x378;
        }
        else if (((RVar5 != (RGBQUAD)0xf800) || (pBStack_98[1].bmiHeader.biSize != 0x7e0)) ||
                (local_a0 = (ushort *)0x235, pBStack_98[1].bmiHeader.biWidth != 0x1f))
        goto LAB_00545db8;
      }
      else {
        if ((sVar7 != 0x10) || (CONCAT22(uStack_56,uStack_58) != 0)) goto LAB_00545c02;
LAB_00545db8:
        local_a0 = (ushort *)0x22b;
      }
      if (param_3 == 0) {
        iVar9 = (pBStack_98->bmiHeader).biHeight;
        if (0 < iVar9) {
          local_94 = (uint *)FUN_0056e030(iVar9 * iVar10,
                                          "..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",
                                          0xd66);
          if (local_94 == (uint *)0x0) goto LAB_00545f9c;
          puVar16 = (uint *)((iVar9 + -1) * iVar10 + (int)local_9c);
          puVar20 = local_94;
          if (0 < iVar9) {
            do {
              FUN_0056d420(puVar20,puVar16,iVar10);
              puVar16 = puVar16 + -iVar23;
              puVar20 = puVar20 + iVar23;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
          FUN_0056e1d0(local_9c);
          local_9c = local_94;
        }
      }
      *(uint **)(param_2 + 0x434) = local_9c;
      *(LONG *)(param_2 + 0x428) = (pBStack_98->bmiHeader).biWidth;
      iVar9 = (pBStack_98->bmiHeader).biHeight;
      if (iVar9 < 0) {
        iVar9 = -iVar9;
      }
      *(int *)(param_2 + 0x42c) = iVar9;
      *(int *)(param_2 + 0x430) = iVar10;
      FUN_005444a0(param_2);
      if (local_a0 == (ushort *)0x22b) {
        *(undefined1 *)(param_2 + 5) = 0x10;
        *(undefined1 *)(param_2 + 4) = 2;
        *(undefined1 *)(param_2 + 6) = 0xf;
        *(undefined4 *)(param_2 + 0x20) = 0x8000;
        *(undefined1 *)(param_2 + 7) = 1;
        *(undefined1 *)(param_2 + 0xc) = 10;
        *(undefined4 *)(param_2 + 0x10) = 0x7c00;
        *(undefined1 *)(param_2 + 8) = 5;
        *(undefined1 *)(param_2 + 0xd) = 5;
        *(undefined4 *)(param_2 + 0x14) = 0x3e0;
        *(undefined1 *)(param_2 + 9) = 5;
        *(undefined1 *)(param_2 + 0xe) = 0;
        *(undefined4 *)(param_2 + 0x18) = 0x1f;
        *(undefined1 *)(param_2 + 10) = 5;
      }
      else if (local_a0 == (ushort *)0x235) {
        *(undefined1 *)(param_2 + 5) = 0x10;
        *(undefined1 *)(param_2 + 4) = 2;
        *(undefined1 *)(param_2 + 6) = 0;
        *(undefined4 *)(param_2 + 0x20) = 0;
        *(undefined1 *)(param_2 + 7) = 0;
        *(undefined1 *)(param_2 + 0xc) = 0xb;
        *(undefined4 *)(param_2 + 0x10) = 0xf800;
        *(undefined1 *)(param_2 + 8) = 5;
        *(undefined1 *)(param_2 + 0xd) = 5;
        *(undefined4 *)(param_2 + 0x14) = 0x7e0;
        *(undefined1 *)(param_2 + 9) = 6;
        *(undefined1 *)(param_2 + 0xe) = 0;
        *(undefined4 *)(param_2 + 0x18) = 0x1f;
        *(undefined1 *)(param_2 + 10) = 5;
      }
      else if (local_a0 == (ushort *)0x378) {
        *(undefined1 *)(param_2 + 5) = 0x20;
        *(undefined1 *)(param_2 + 4) = 4;
        *(undefined1 *)(param_2 + 6) = 0;
        *(undefined4 *)(param_2 + 0x20) = 0xff;
        *(undefined1 *)(param_2 + 7) = 8;
        *(undefined1 *)(param_2 + 0xc) = 0x18;
        *(undefined4 *)(param_2 + 0x10) = 0xff000000;
        *(undefined1 *)(param_2 + 8) = 8;
        *(undefined1 *)(param_2 + 0xd) = 0x10;
        *(undefined4 *)(param_2 + 0x14) = 0xff0000;
        *(undefined1 *)(param_2 + 9) = 8;
        *(undefined1 *)(param_2 + 0xe) = 8;
        *(undefined4 *)(param_2 + 0x18) = 0xff00;
        *(undefined1 *)(param_2 + 10) = 8;
      }
      goto LAB_00546033;
    }
LAB_00545c02:
    if (param_3 == 0) {
      hdc = CreateCompatibleDC((HDC)0x0);
      local_88 = hdc;
      FUN_0056d380(&BStack_2c,0,0x28);
      BStack_2c.bmiHeader.biWidth = (pBStack_98->bmiHeader).biWidth;
      BStack_2c.bmiHeader.biHeight = (pBStack_98->bmiHeader).biHeight;
      BStack_2c.bmiHeader.biSize = 0x28;
      if (BStack_2c.bmiHeader.biHeight < 0) {
        BStack_2c.bmiHeader.biHeight = -BStack_2c.bmiHeader.biHeight;
      }
      BStack_2c.bmiHeader.biHeight = -BStack_2c.bmiHeader.biHeight;
      BStack_2c.bmiHeader.biPlanes = 1;
      BStack_2c.bmiHeader.biBitCount = 0x18;
      BStack_2c.bmiHeader.biCompression = 0;
      h = CreateDIBSection(hdc,&BStack_2c,0,&puStack_90,(HANDLE)0x0,0);
      local_84 = h;
      if ((h == (HBITMAP)0x0) || (puStack_90 == (ushort *)0x0)) {
        puVar27 = &DAT_007d5e44;
      }
      else {
        GetObjectA(h,0x18,auStack_80);
        iStack_74 = ((int)(iStack_74 + 3 + (iStack_74 + 3 >> 0x1f & 3U)) >> 2) * 4;
        iVar9 = iStack_78;
        if (iStack_78 < 0) {
          iVar9 = -iStack_78;
        }
        pvStack_8c = SelectObject(hdc,h);
        DVar12 = (pBStack_98->bmiHeader).biHeight;
        cLines = DVar12;
        if (((int)DVar12 < 0) && (cLines = -DVar12, (int)DVar12 < 0)) {
          DVar12 = -DVar12;
        }
        SetDIBitsToDevice(hdc,0,0,(pBStack_98->bmiHeader).biWidth,DVar12,0,0,0,cLines,local_9c,
                          pBStack_98,0);
        SelectObject(hdc,pvStack_8c);
        DeleteDC(hdc);
        local_88 = (HDC)0x0;
        FUN_0056e1d0(local_9c);
        local_9c = (uint *)FUN_0056e030(iStack_74 * iVar9,
                                        "..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",
                                        0xe08);
        if (local_9c != (uint *)0x0) {
          FUN_0056d420(local_9c,uStack_6c,iStack_74 * iVar9);
          DeleteObject(h);
          *(int *)(param_2 + 0x430) = iStack_74;
          goto LAB_00546008;
        }
        puVar27 = &DAT_007d5eb0;
        local_9c = (uint *)0x0;
      }
      FUN_0056bb10(puVar27);
LAB_00545f9c:
      FUN_0056e1d0(pBStack_98);
      if (local_9c != (uint *)0x0) {
        FUN_0056e1d0(local_9c);
      }
      if (local_94 != (uint *)0x0) {
        FUN_0056e1d0(local_94);
      }
      if (local_84 != (HBITMAP)0x0) {
        DeleteObject(local_84);
      }
      if (local_88 != (HDC)0x0) {
        DeleteDC(local_88);
      }
      return 0xffffffff;
    }
    *(undefined4 *)(param_2 + 0x430) = 0;
LAB_00546008:
    *(uint **)(param_2 + 0x434) = local_9c;
    *(LONG *)(param_2 + 0x428) = (pBStack_98->bmiHeader).biWidth;
    iVar9 = (pBStack_98->bmiHeader).biHeight;
    if (iVar9 < 0) {
      iVar9 = -iVar9;
    }
    *(int *)(param_2 + 0x42c) = iVar9;
  }
  FUN_00544560(param_2);
LAB_00546033:
  FUN_0056e1d0(pBStack_98);
  return 0;
}

