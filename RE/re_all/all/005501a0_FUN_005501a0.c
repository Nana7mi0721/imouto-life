
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005501a0(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  DWORD DVar5;
  int iVar6;
  BOOL BVar7;
  bool bVar8;
  tagMSG *ptVar9;
  tagMSG *ptVar10;
  int local_4c;
  tagPOINT local_40;
  tagMSG local_38;
  tagMSG tStack_1c;
  
  local_38.hwnd = (HWND)0x0;
  local_38.message = 0;
  local_38.wParam = 0;
  local_38.lParam = 0;
  local_38.time = 0;
  local_38.pt.x = 0;
  local_38.pt.y = 0;
  bVar3 = false;
  if (DAT_00a828cc != 0) {
    return 0;
  }
  DAT_00a238e8 = 1;
  if ((((((DAT_00a2d84c != 0) && (DAT_00a21078 != 0)) && (DAT_00a2107c == 0)) &&
       ((DAT_00a20c40 != 0 && (DAT_00a2d854 == 0)))) &&
      (GetCursorPos(&local_40), DAT_00a20c30 < local_40.x)) &&
     (((local_40.x <= DAT_00a20c38 && (DAT_00a20c34 < local_40.y)) && (local_40.y <= DAT_00a20c3c)))
     ) {
    DAT_00a2d854 = 1;
    ClipCursor((RECT *)&DAT_00a20c30);
  }
  if (DAT_00a49738 == 0) {
    if (DAT_00a20bec == (HWND)0x0) goto LAB_005506a5;
    if (DAT_00a20c10 == 0) {
      if (((DAT_00a2108c == 1) && (DAT_00a20c48 == 1)) &&
         (DVar5 = GetCurrentThreadId(), DAT_00a20c1c == DVar5)) {
        DAT_00a2108c = 0;
        FUN_00511770(DAT_00a20c40 != 1);
        if (DAT_00a20c4c != (code *)0x0) {
          (*DAT_00a20c4c)(DAT_00a20c50);
        }
      }
      local_4c = 0;
      bVar4 = false;
      while ((((DAT_00a21064 == 0 && (DAT_00a218c4 == 0)) &&
              ((DAT_00a24d40 == 0 && ((DAT_00a21078 == 0 || (DAT_00a2107c == 1)))))) ||
             ((!bVar3 && (DAT_00a21060 == 0))))) {
        if ((!bVar4) && (((DAT_00a21078 == 0 || (DAT_00a2107c == 1)) && (DAT_00a24d40 == 0)))) {
          bVar4 = true;
          _DAT_00a21084 = FUN_00550060(0);
          _DAT_00a21080 = 1;
        }
        bVar3 = true;
        if (((DAT_00a21078 == 0) || (DAT_00a2107c == 1)) &&
           ((DAT_00a24d40 == 0 &&
            ((Sleep(1), DAT_00a21070 == 1 && (iVar6 = FUN_00550060(0), 0x40 < iVar6 - _DAT_00a21074)
             ))))) {
          if (DAT_00a23d24 == 0) {
            FUN_00527180();
          }
          _DAT_00a21074 = FUN_00550060(0);
          DAT_00a21070 = 0;
        }
        bVar8 = true;
        do {
          BVar7 = PeekMessageW(&tStack_1c,(HWND)0x0,0,0,0);
          if (BVar7 == 0) {
            BVar7 = PeekMessageW(&local_38,(HWND)0xffffffff,0,0,1);
            if ((BVar7 != 0) || (BVar7 = PeekMessageW(&local_38,DAT_00a20bec,0,0,1), BVar7 != 0)) {
              bVar8 = true;
              goto LAB_0055042e;
            }
            bVar8 = false;
          }
          else {
            PeekMessageW(&tStack_1c,(HWND)0x0,0,0,1);
            ptVar9 = &tStack_1c;
            ptVar10 = &local_38;
            for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
              ptVar10->hwnd = ptVar9->hwnd;
              ptVar9 = (tagMSG *)&ptVar9->message;
              ptVar10 = (tagMSG *)&ptVar10->message;
            }
LAB_0055042e:
            if ((DAT_00a2ea90 == (HWND)0x0) ||
               (BVar7 = IsDialogMessageW(DAT_00a2ea90,&local_38), BVar7 == 0)) {
              if ((local_38.message == 0x1c) && (DAT_00a20c40 == 1)) {
                DAT_00a21078 = local_38.wParam & 0xffff;
              }
              if (DAT_00a21060 != 0) goto LAB_005505bb;
              if (local_38.message == 0x12) {
                DAT_00a21060 = 1;
                FUN_0052ea30();
              }
              iVar6 = TranslateAcceleratorW(DAT_00a20bec,DAT_00a24d54,&local_38);
              if (iVar6 == 0) {
                TranslateMessage(&local_38);
                DispatchMessageW(&local_38);
              }
            }
            bVar3 = false;
          }
          if ((DAT_00a2ea90 != (HWND)0x0) &&
             (BVar7 = PeekMessageW(&local_38,DAT_00a2ea90,0,0,1), BVar7 != 0)) {
            IsDialogMessageW(DAT_00a2ea90,&local_38);
          }
          iVar6 = 0;
          if (0 < DAT_00a2ea80) {
            do {
              BVar7 = PeekMessageW(&local_38,(HWND)(&DAT_00a2e8f0)[iVar6],0,0,1);
              if (BVar7 != 0) {
                TranslateMessage(&local_38);
                DispatchMessageW(&local_38);
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 < DAT_00a2ea80);
          }
        } while (bVar8);
        if (((DAT_00a21078 == 0) || (DAT_00a2107c == 1)) && (DAT_00a24d40 == 0)) {
          FUN_0056dd00();
          FUN_0057bf50(1);
          if (DAT_00a20bf4 < 2) {
            FUN_00560e70();
            FUN_0055e6d0();
            FUN_0055c6b0();
          }
          FUN_005619b0();
          FUN_00567620();
          FUN_0057fe80();
          Sleep(0x18);
        }
        if (((DAT_00a21060 != 0) || (DVar5 = GetCurrentThreadId(), DAT_00a20c1c != DVar5)) ||
           ((local_4c = local_4c + 1, DAT_00a21098 != 0 && (9 < local_4c)))) break;
      }
LAB_005505bb:
      DVar5 = GetCurrentThreadId();
      if ((DAT_00a20c1c == DVar5) && (DAT_00a24d78 == 0)) {
        FUN_00511bd0();
      }
    }
    if (DAT_00a21064 == 0) {
      while (DAT_00a218c4 != 0) {
        iVar6 = DAT_00a218c8 * 4;
        iVar1 = DAT_00a218c8 * 4;
        iVar2 = DAT_00a218c8 * 4;
        DAT_00a218c8 = DAT_00a218c8 + 1 & 0x800001ff;
        if ((int)DAT_00a218c8 < 0) {
          DAT_00a218c8 = (DAT_00a218c8 - 1 | 0xfffffe00) + 1;
        }
        DAT_00a218c4 = DAT_00a218c4 + -1;
        FUN_00510df0(*(undefined4 *)(&DAT_00a218d0 + iVar6),*(undefined4 *)(&DAT_00a220d0 + iVar1),
                     *(undefined4 *)(&DAT_00a228d0 + iVar2),0);
      }
    }
  }
  if (DAT_00a20bf4 < 2) {
    FUN_00560e70();
    FUN_0055e6d0();
    FUN_0055c6b0();
  }
  FUN_005619b0();
  FUN_00567620();
  if (DAT_00a21060 == 0) {
    FUN_0057fe80();
  }
  FUN_0055b950();
  FUN_0054f860(0);
  FUN_0054fe20();
  FUN_0057bf50(1);
  FUN_0056dd00();
  DAT_00a828cc = 1;
  FUN_00565ab0();
  DAT_00a828cc = 0;
LAB_005506a5:
  DAT_00a238e8 = 0;
  return (DAT_00a21060 != 1) - 1;
}

