
undefined4 FUN_0050f6f0(undefined1 *param_1,undefined4 *param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  HDC pHVar2;
  int iVar3;
  HGDIOBJ h;
  HWND pHVar4;
  int iVar5;
  uint uVar6;
  HDC unaff_EBX;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  bool bVar10;
  uint uVar11;
  undefined1 *puVar12;
  HDC hDC;
  undefined1 local_8e4;
  undefined1 local_8e3;
  undefined1 local_8e2;
  undefined1 local_8e1;
  undefined4 local_8e0;
  undefined4 local_8dc;
  HDC local_8d8;
  uint local_8d4;
  undefined4 local_8d0;
  int local_8cc;
  HDC local_8c8;
  uint local_8c4;
  undefined4 local_8c0;
  undefined4 local_8bc;
  int local_8b8;
  int local_8b4;
  undefined4 local_8b0;
  int local_8ac;
  uint local_8a8;
  undefined4 local_8a4;
  undefined4 local_8a0;
  int local_89c;
  int local_898;
  BITMAPINFO local_894;
  undefined1 local_868 [1064];
  undefined1 local_440 [1088];
  
  uVar11 = (uint)((*(uint *)(&DAT_007d48b4 + DAT_00a20c04 * 4) & 0xc00000) != 0);
  local_8c4 = uVar11;
  pHVar2 = GetDC((HWND)0x0);
  if ((DAT_00a20c10 == 0) || (pHVar4 = DAT_00a20bf0, DAT_00a20bf0 == (HWND)0x0)) {
    pHVar4 = DAT_00a20bec;
  }
  local_8d8 = pHVar2;
  local_8c8 = GetDC(pHVar4);
  local_8c0 = DAT_00a20c20;
  local_8e0 = 0;
  local_8dc = 0;
  local_8bc = DAT_00a20c24;
  FUN_005167a0(&local_8b0,&local_8b4);
  uVar6 = DAT_00a37f50;
  local_8cc = local_8b4;
  local_8d0 = local_8b0;
  local_8a8 = DAT_00a37f50 >> 0x10 & 0xff | (DAT_00a37f50 & 0xff) << 0x10 | DAT_00a37f50 & 0xff00;
  if (param_3 != 0) {
    if ((DAT_00a20c10 == 0) || (pHVar4 = DAT_00a20bf0, DAT_00a20bf0 == (HWND)0x0)) {
      pHVar4 = DAT_00a20bec;
    }
    hDC = (HDC)0x1;
    (*DAT_00aba1c0)(pHVar4,pHVar2,&local_8c0,&local_8d0,param_3,&local_8e0,local_8a8,&local_8e4);
    goto LAB_0051013d;
  }
  if ((param_1 != (undefined1 *)0x0) && (param_2 != (undefined4 *)0x0)) {
    iVar3 = FUN_00542120(param_1,*param_2,param_2[1],param_2[2],param_2[3],local_440);
    if (iVar3 < 0) {
      return 0xffffffff;
    }
    param_1 = local_440;
  }
  if ((DAT_00a2e488 != *(int *)(param_1 + 0x428)) || (DAT_00a2e48c != *(int *)(param_1 + 0x42c))) {
    if (DAT_00a2e480 != (HBITMAP)0x0) {
      DeleteObject(DAT_00a2e480);
      DAT_00a2e480 = (HBITMAP)0x0;
    }
    FUN_0056d380(&local_894,0,0x2c);
    local_894.bmiHeader.biWidth = *(LONG *)(param_1 + 0x428);
    local_894.bmiHeader.biHeight = -*(int *)(param_1 + 0x42c);
    local_894.bmiHeader.biSize = 0x2c;
    if (uVar11 != 0) {
      local_894.bmiHeader.biHeight = local_894.bmiHeader.biHeight - DAT_00a20bfc;
    }
    local_894.bmiHeader.biBitCount = 0x20;
    local_894.bmiHeader.biPlanes = 1;
    if ((DAT_00a20c10 == 0) || (pHVar4 = DAT_00a20bf0, DAT_00a20bf0 == (HWND)0x0)) {
      pHVar4 = DAT_00a20bec;
    }
    pHVar2 = GetDC(pHVar4);
    DAT_00a2e480 = CreateDIBSection(pHVar2,&local_894,0,&DAT_00a2e484,(HANDLE)0x0,0);
    if ((DAT_00a20c10 == 0) || (pHVar4 = DAT_00a20bf0, DAT_00a20bf0 == (HWND)0x0)) {
      pHVar4 = DAT_00a20bec;
    }
    ReleaseDC(pHVar4,pHVar2);
    FUN_00544500(&DAT_00a2e490);
    FUN_0056d380(DAT_00a2e484,0,*(int *)(param_1 + 0x428) * local_894.bmiHeader.biHeight * -4);
    DAT_00a2e488 = *(int *)(param_1 + 0x428);
    DAT_00a2e48c = *(int *)(param_1 + 0x42c);
  }
  puVar9 = DAT_00a2e484;
  if (uVar11 != 0) {
    puVar9 = DAT_00a2e484 + *(int *)(param_1 + 0x428) * DAT_00a20bfc;
  }
  local_898 = *(int *)(param_1 + 0x42c);
  puVar8 = *(uint **)(param_1 + 0x434);
  local_8a4 = 0;
  local_8a0 = 0;
  local_89c = *(int *)(param_1 + 0x428);
  if (param_4 == 0) {
    if (DAT_00a2e8c8 < 0x108) {
      if (local_8c4 != 0) {
        FUN_0056d3b0(DAT_00a2e484,uVar6 & 0xffffff,DAT_00a20bfc * local_89c);
      }
      FUN_005444a0(local_868);
      FUN_00549b20(puVar9,*(int *)(param_1 + 0x428) * 4,local_868,puVar8,
                   *(undefined4 *)(param_1 + 0x430),param_1,0,0,0,local_8e0,local_8dc,&local_8a4,0,0
                   ,0,0,0,0,0,0);
    }
    else {
      local_8ac = (int)(local_89c + (local_89c >> 0x1f & 3U)) >> 2;
      local_8b8 = local_89c + local_8ac * -4;
      if (*(int *)(param_1 + 0x1c) == 0) {
        if (((*(int *)(param_1 + 0x10) == 0xff0000) && (*(int *)(param_1 + 0x14) == 0xff00)) &&
           (*(int *)(param_1 + 0x18) == 0xff)) {
          iVar3 = *(int *)(param_1 + 0x430);
          for (iVar7 = local_898; iVar7 != 0; iVar7 = iVar7 + -1) {
            for (iVar5 = *(int *)(param_1 + 0x428); iVar5 != 0; iVar5 = iVar5 + -1) {
              if ((*puVar8 & 0xffffff) == (uVar6 & 0xffffff)) {
                *puVar9 = 0;
              }
              else {
                *puVar9 = *puVar8 | 0xff000000;
              }
              puVar8 = puVar8 + 1;
              puVar9 = puVar9 + 1;
            }
            puVar8 = (uint *)((int)puVar8 + iVar3 + local_89c * -4);
          }
        }
        else {
          if (((*(int *)(param_1 + 0x10) != 0xf800) || (*(int *)(param_1 + 0x14) != 0x7e0)) ||
             (*(int *)(param_1 + 0x18) != 0x1f)) goto LAB_0050fc8d;
          local_8d4 = *(int *)(param_1 + 0x430) + local_89c * -2;
          uVar11 = ((uVar6 >> 3 & 0x1f0000 | uVar6 & 0xfc00) >> 2 | uVar6 & 0xf8) >> 3;
          for (iVar3 = local_898; iVar7 = local_8ac, iVar3 != 0; iVar3 = iVar3 + -1) {
            for (; iVar7 != 0; iVar7 = iVar7 + -1) {
              uVar6 = (uint)(ushort)*puVar8;
              if (uVar6 == uVar11) {
                *puVar9 = 0;
              }
              else {
                *puVar9 = (((uVar6 & 0xfffff800 | 0xffff0000) * 8 | uVar6 & 0x7e0) * 4 |
                          uVar6 & 0x1f) * 8;
              }
              if (*(ushort *)((int)puVar8 + 2) == uVar11) {
                puVar9[1] = 0;
              }
              else {
                uVar6 = (uint)*(ushort *)((int)puVar8 + 2);
                puVar9[1] = (((uVar6 & 0xfffff800 | 0xffff0000) * 8 | uVar6 & 0x7e0) * 4 |
                            uVar6 & 0x1f) * 8;
              }
              if ((ushort)puVar8[1] == uVar11) {
                puVar9[2] = 0;
              }
              else {
                uVar6 = (uint)(ushort)puVar8[1];
                puVar9[2] = (((uVar6 & 0xfffff800 | 0xffff0000) * 8 | uVar6 & 0x7e0) * 4 |
                            uVar6 & 0x1f) * 8;
              }
              if (*(ushort *)((int)puVar8 + 6) == uVar11) {
                puVar9[3] = 0;
              }
              else {
                uVar6 = (uint)*(ushort *)((int)puVar8 + 6);
                puVar9[3] = (((uVar6 & 0xfffff800 | 0xffff0000) * 8 | uVar6 & 0x7e0) * 4 |
                            uVar6 & 0x1f) * 8;
              }
              puVar8 = puVar8 + 2;
              puVar9 = puVar9 + 4;
            }
            for (iVar7 = local_8b8; iVar7 != 0; iVar7 = iVar7 + -1) {
              uVar6 = (uint)(ushort)*puVar8;
              if (uVar6 == uVar11) {
                *puVar9 = 0;
              }
              else {
                *puVar9 = (((uVar6 & 0xfffff800 | 0xffff0000) * 8 | uVar6 & 0x7e0) * 4 |
                          uVar6 & 0x1f) * 8;
              }
              puVar8 = (uint *)((int)puVar8 + 2);
              puVar9 = puVar9 + 1;
            }
            puVar8 = (uint *)((int)puVar8 + local_8d4);
          }
        }
      }
      else {
LAB_0050fc8d:
        FUN_00549b20(puVar9,local_89c * 4,&DAT_00a2e490,puVar8,*(undefined4 *)(param_1 + 0x430),
                     param_1,0,0,0,local_8e0,local_8dc,&local_8a4,0,0,0,0,0,0,0,0);
        for (iVar3 = DAT_00a2e48c * DAT_00a2e488; iVar3 != 0; iVar3 = iVar3 + -1) {
          if ((*puVar9 & 0xffffff) == (uVar6 & 0xffffff)) {
            *puVar9 = 0;
          }
          else {
            *(byte *)((int)puVar9 + 3) = 0xff;
          }
          puVar9 = puVar9 + 1;
        }
      }
    }
  }
  else {
    bVar10 = DAT_00a2e47c == 0;
    if (((*(int *)(param_1 + 0x1c) == -0x1000000) && (*(int *)(param_1 + 0x10) == 0xff0000)) &&
       ((*(int *)(param_1 + 0x14) == 0xff00 && (*(int *)(param_1 + 0x18) == 0xff)))) {
      iVar3 = *(int *)(param_1 + 0x430) + local_89c * -4;
      local_8d4 = uVar6 & 0xffffff;
      if (param_5 == 0) {
        iVar7 = local_898;
        if (bVar10) {
          for (; iVar7 != 0; iVar7 = iVar7 + -1) {
            for (iVar5 = *(int *)(param_1 + 0x428); iVar5 != 0; iVar5 = iVar5 + -1) {
              uVar11 = *puVar8;
              if (((uVar11 & 0xffffff) == local_8d4) || (*(byte *)((int)puVar8 + 3) == 0)) {
                *puVar9 = 0;
              }
              else if (*(byte *)((int)puVar8 + 3) == 0xff) {
                *puVar9 = uVar11;
              }
              else {
                *(byte *)puVar9 = (byte)((uVar11 & 0xff) * (uint)*(byte *)((int)puVar8 + 3) >> 8);
                *(byte *)((int)puVar9 + 1) =
                     (byte)((uint)*(byte *)((int)puVar8 + 1) * (uint)*(byte *)((int)puVar8 + 3) >> 8
                           );
                *(byte *)((int)puVar9 + 2) =
                     (byte)((uint)*(byte *)((int)puVar8 + 2) * (uint)*(byte *)((int)puVar8 + 3) >> 8
                           );
                *(byte *)((int)puVar9 + 3) = *(byte *)((int)puVar8 + 3);
              }
              puVar8 = puVar8 + 1;
              puVar9 = puVar9 + 1;
            }
            puVar8 = (uint *)((int)puVar8 + iVar3);
          }
        }
        else {
          for (; iVar7 != 0; iVar7 = iVar7 + -1) {
            for (iVar5 = *(int *)(param_1 + 0x428); iVar5 != 0; iVar5 = iVar5 + -1) {
              if (*(byte *)((int)puVar8 + 3) == 0) {
                *puVar9 = 0;
              }
              else if (*(byte *)((int)puVar8 + 3) == 0xff) {
                *puVar9 = *puVar8;
              }
              else {
                *(byte *)puVar9 =
                     (byte)((uint)(byte)*puVar8 * (uint)*(byte *)((int)puVar8 + 3) >> 8);
                *(byte *)((int)puVar9 + 1) =
                     (byte)((uint)*(byte *)((int)puVar8 + 1) * (uint)*(byte *)((int)puVar8 + 3) >> 8
                           );
                *(byte *)((int)puVar9 + 2) =
                     (byte)((uint)*(byte *)((int)puVar8 + 2) * (uint)*(byte *)((int)puVar8 + 3) >> 8
                           );
                *(byte *)((int)puVar9 + 3) = *(byte *)((int)puVar8 + 3);
              }
              puVar8 = puVar8 + 1;
              puVar9 = puVar9 + 1;
            }
            puVar8 = (uint *)((int)puVar8 + iVar3);
          }
        }
      }
      else {
        iVar7 = local_898;
        if (bVar10) {
          for (; iVar7 != 0; iVar7 = iVar7 + -1) {
            for (iVar5 = *(int *)(param_1 + 0x428); iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar9 = -(uint)((*puVar8 & 0xffffff) != local_8d4) & *puVar8;
              puVar8 = puVar8 + 1;
              puVar9 = puVar9 + 1;
            }
            puVar8 = (uint *)((int)puVar8 + iVar3);
          }
        }
        else {
          for (; iVar7 != 0; iVar7 = iVar7 + -1) {
            for (iVar5 = *(int *)(param_1 + 0x428); iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar9 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar9 = puVar9 + 1;
            }
            puVar8 = (uint *)((int)puVar8 + iVar3);
          }
        }
      }
    }
    else {
      FUN_00549b20(puVar9,local_89c * 4,&DAT_00a2e490,puVar8,*(undefined4 *)(param_1 + 0x430),
                   param_1,0,0,0,local_8e0,local_8dc,&local_8a4,0,bVar10,uVar6,0,0,0,0,0);
      if ((param_5 == 0) && (iVar3 = DAT_00a2e48c * DAT_00a2e488, iVar3 != 0)) {
        do {
          bVar1 = *(byte *)((int)puVar9 + 3);
          if (bVar1 == 0) {
            *puVar9 = 0;
          }
          else if (bVar1 != 0xff) {
            uVar11 = (uint)bVar1;
            *(byte *)puVar9 = (byte)((byte)*puVar9 * uVar11 >> 8);
            *(byte *)((int)puVar9 + 1) = (byte)(*(byte *)((int)puVar9 + 1) * uVar11 >> 8);
            *(byte *)((int)puVar9 + 2) = (byte)(*(byte *)((int)puVar9 + 2) * uVar11 >> 8);
          }
          iVar3 = iVar3 + -1;
          puVar9 = puVar9 + 1;
        } while (iVar3 != 0);
      }
    }
  }
  pHVar2 = CreateCompatibleDC(local_8c8);
  h = SelectObject(pHVar2,DAT_00a2e480);
  if (local_8c4 != 0) {
    local_8cc = local_8cc + DAT_00a20bfc;
  }
  pHVar4 = DAT_00a20bf0;
  if ((param_4 == 0) && (DAT_00a2e8c8 < 0x108)) {
    if ((DAT_00a20c10 == 0) || (DAT_00a20bf0 == (HWND)0x0)) {
      pHVar4 = DAT_00a20bec;
    }
    hDC = (HDC)0x1;
    puVar12 = (undefined1 *)0x0;
    uVar11 = local_8a8;
  }
  else {
    local_8e4 = 0;
    local_8e3 = 0;
    local_8e2 = 0xff;
    local_8e1 = 1;
    if ((DAT_00a20c10 == 0) || (DAT_00a20bf0 == (HWND)0x0)) {
      pHVar4 = DAT_00a20bec;
    }
    hDC = (HDC)0x2;
    puVar12 = &local_8e4;
    uVar11 = 0;
  }
  (*DAT_00aba1c0)(pHVar4,local_8d8,&local_8c0,&local_8d0,pHVar2,&local_8e0,uVar11,puVar12);
  SelectObject(pHVar2,h);
  DeleteDC(pHVar2);
LAB_0051013d:
  if ((DAT_00a20c10 == 0) || (pHVar4 = DAT_00a20bf0, DAT_00a20bf0 == (HWND)0x0)) {
    pHVar4 = DAT_00a20bec;
  }
  ReleaseDC(pHVar4,unaff_EBX);
  ReleaseDC((HWND)0x0,hDC);
  return 0;
}

