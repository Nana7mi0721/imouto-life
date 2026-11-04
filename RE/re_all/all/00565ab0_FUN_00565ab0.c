
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined4 FUN_00565ab0(void)

{
  ushort *puVar1;
  int *piVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  ushort *puVar9;
  undefined2 *puVar10;
  int iVar11;
  int iVar12;
  ushort *puVar13;
  int unaff_EDI;
  uint uVar14;
  int iVar15;
  undefined8 uVar16;
  int iStack_1020;
  int iStack_101c;
  ushort local_1018;
  undefined2 local_1016;
  undefined2 local_1014;
  int iStack_1010;
  int iStack_100c;
  undefined1 auStack_1008 [2020];
  undefined1 auStack_824 [16];
  undefined1 auStack_814 [16];
  undefined2 auStack_804 [1024];
  undefined4 uStack_4;
  
  iVar15 = DAT_00a20bec;
  uStack_4 = 0x565aba;
  local_1018 = 0;
  local_1016 = 0;
  local_1014 = 0;
  switch(DAT_00aa701c) {
  case 1:
    if ((DAT_00a20bec != 0) && (iVar5 = (*DAT_00aba12c)(DAT_00a20bec), iVar5 != 0)) {
      FUN_0056d380(&DAT_00aa5ff8,0,0x400);
      FUN_0056d380(&DAT_00aa67fa,0,0x400);
      (*DAT_00aba14c)(iVar5,8,&DAT_00aa67fa,0x400);
      (*DAT_00aba13c)(iVar5,0x15,4,0);
      (*DAT_00aba130)(iVar15,iVar5);
    }
    DAT_00aa701c = DAT_00aa701c + 1;
  case 2:
    iVar15 = DAT_00a20bec;
    uVar8 = (*DAT_00aba12c)(DAT_00a20bec);
    (*DAT_00aba140)(uVar8,0);
    (*DAT_00aba130)(iVar15,uVar8);
    DAT_00aa701c = DAT_00aa701c + 1;
  case 3:
    iVar15 = DAT_00a20bec;
    uVar8 = (*DAT_00aba12c)(DAT_00a20bec);
    (*DAT_00aba140)(uVar8,1);
    (*DAT_00aba130)(iVar15,uVar8);
    DAT_00aa701c = DAT_00aa701c + 1;
  case 4:
    iVar15 = DAT_00a20bec;
    if ((DAT_00a20bec != 0) && (iVar5 = (*DAT_00aba12c)(DAT_00a20bec), iVar5 != 0)) {
      (*DAT_00aba140)(iVar5,1);
      iVar6 = 0;
      sVar3 = DAT_00aa67fa;
      while (sVar3 != 0) {
        iVar6 = iVar6 + 1;
        sVar3 = (&DAT_00aa67fa)[iVar6];
      }
      (*DAT_00aba150)(iVar5,9,&DAT_00aa67fa,iVar6,0,0);
      (*DAT_00aba130)(iVar15,iVar5);
    }
    DAT_00aa701c = 0;
  }
  if (DAT_00aa84b0 != 0xffffffff) {
    if (((((int)DAT_00aa84b0 < 0) || ((DAT_00aa84b0 & 0x7c000000) != 0x24000000)) ||
        (uVar14 = DAT_00aa84b0 & 0xffff, 0xff < uVar14)) ||
       ((iVar15 = uVar14 * 0x5c, (&DAT_00aa84b8)[uVar14 * 0x17] == 0 ||
        ((&DAT_00aa84bc)[uVar14 * 0x17] * 0x10000 != (DAT_00aa84b0 & 0x3ff0000))))) {
      return 0xffffffff;
    }
    if (*(int *)(&DAT_00aa84c0 + iVar15) == 0) {
      if ((DAT_00aa7014 != 0) || (DAT_00aa7018 != 0)) {
        iStack_1020 = 0;
        if (DAT_00aba24c == 0) {
          FUN_0057a980();
        }
        iVar5 = DAT_00aba24c;
        if (DAT_00aba250 == 0) {
          FUN_0057a980();
        }
        FUN_005764b0(*(undefined4 *)(&DAT_00aa84e0 + iVar15),0xffffffff,DAT_00aba250,
                     *(undefined4 *)(&DAT_00aa84e4 + iVar15),*(undefined4 *)(&DAT_00aa84e8 + iVar15)
                     ,iVar5);
        if (DAT_00aba24c == 0) {
          FUN_0057a980();
        }
        iVar5 = FUN_005773c0(DAT_00aba24c,*(undefined4 *)(&DAT_00aa84e4 + iVar15));
        if (DAT_00aba24c == 0) {
          FUN_0057a980();
        }
        iVar6 = DAT_00aba24c;
        if (DAT_00aba250 == 0) {
          FUN_0057a980();
        }
        FUN_005764b0(&DAT_00aa5ff8,0xffffffff,DAT_00aba250,auStack_1008,0x801,iVar6);
        if (DAT_00aba24c == 0) {
          FUN_0057a980();
        }
        iVar6 = FUN_005773c0(DAT_00aba24c,auStack_1008);
        iStack_101c = 0x10000;
        if ((DAT_00aa7014 == 0) || (iVar6 + iVar5 <= *(int *)(&DAT_00aa84cc + iVar15))) {
          iVar5 = iStack_1020;
        }
        else {
          iStack_101c = *(int *)(&DAT_00aa84cc + iVar15) - iVar5;
          iVar5 = 1;
        }
        if ((DAT_00aa7018 == 0) || (iVar6 <= DAT_00aa7018)) {
          if (iVar5 == 0) goto LAB_00565f3e;
        }
        else if (DAT_00aa7018 < iStack_101c) {
          iStack_101c = DAT_00aa7018;
        }
        iVar5 = (*DAT_00aba12c)(DAT_00a20bec);
        iStack_1010 = iVar5;
        if (iVar5 != 0) {
          FUN_0056d380(auStack_804,0,0x802);
          (*DAT_00aba14c)(iVar5,8,auStack_804,0x400);
          if (DAT_00aba24c == 0) {
            FUN_0057a980();
          }
          iVar6 = DAT_00aba24c;
          if (DAT_00aba250 == 0) {
            FUN_0057a980();
          }
          FUN_005764b0(auStack_814,0xffffffff,DAT_00aba250,&local_1018,0x801,iVar6);
          if (DAT_00aba24c == 0) {
            FUN_0057a980();
          }
          iVar6 = FUN_005773c0(DAT_00aba24c,&local_1018);
          if (iStack_101c < iVar6) {
            iVar5 = 0;
            if (0 < iVar6) {
              iVar12 = 1;
              iVar11 = 2;
              do {
                if (DAT_00aba24c == 0) {
                  FUN_0057a980();
                }
                iVar7 = thunk_FUN_00572b40(auStack_1008 + iVar5 + -0x10,DAT_00aba24c);
                if (iVar7 == 2) {
                  if (unaff_EDI < iVar11) break;
                  iVar5 = iVar5 + 2;
                  iVar11 = iVar11 + 2;
                  iVar12 = iVar12 + 2;
                }
                else {
                  if (unaff_EDI < iVar12) break;
                  iVar5 = iVar5 + 1;
                  iVar11 = iVar11 + 1;
                  iVar12 = iVar12 + 1;
                }
              } while (iVar5 < iVar6);
            }
            auStack_1008[iVar5 + -0x10] = 0;
            if (DAT_00aba250 == 0) {
              FUN_0057a980();
            }
            iVar5 = DAT_00aba250;
            if (DAT_00aba24c == 0) {
              FUN_0057a980();
            }
            FUN_005764b0(&local_1018,0xffffffff,DAT_00aba24c,auStack_814,0x802,iVar5);
            (*DAT_00aba13c)(0,0x15,4,0);
            uVar8 = FUN_0050e220(auStack_824,0,0);
            (*DAT_00aba150)(0,9,auStack_824,uVar8);
            iVar5 = iStack_1020;
          }
          (*DAT_00aba130)(DAT_00a20bec,iVar5);
        }
      }
LAB_00565f3e:
      iVar5 = *(int *)(&DAT_00aa84c0 + iVar15);
      iVar6 = iStack_1010;
      do {
        if ((iVar5 != 0) || (iStack_1010 = iVar6, iVar5 = FUN_00564a10(&local_1018,1), iVar5 == 0))
        {
          return 0;
        }
        FUN_00564700();
        switch(local_1018) {
        case 3:
          iVar5 = *(int *)(&DAT_00aa84d0 + iVar15);
          if (iVar5 != -1) {
            iVar6 = *(int *)(&DAT_00aa84d4 + iVar15);
            if (iVar6 < iVar5) {
              iVar11 = iVar5;
              iVar5 = iVar6;
            }
            else {
              iVar11 = iVar6;
            }
            iVar6 = (iVar11 - iVar5) * 2;
            iVar11 = FUN_0056e030(iVar6 + 2,
                                  "..\\..\\..\\..\\Source\\Library\\Main\\DxInputString.cpp",0x1036)
            ;
            if (iVar11 != 0) {
              FUN_0056d420(iVar11,*(int *)(&DAT_00aa84e0 + iVar15) + iVar5 * 2,iVar6);
              *(undefined2 *)(iVar11 + iVar6) = 0;
              FUN_0050ebd0(iVar11);
              FUN_0056e1d0(iVar11);
            }
          }
          break;
        default:
switchD_00565f91_caseD_4:
          FUN_00563b90();
          if ((*(int *)(&DAT_00aa84f4 + iVar15) == 0) ||
             ((0x2f < local_1018 && (local_1018 < 0x3a)))) {
LAB_00566979:
            if (DAT_00aba24c == 0) {
              FUN_0057a980();
            }
            iVar11 = DAT_00aba24c;
            if (DAT_00aba250 == 0) {
              FUN_0057a980();
            }
            FUN_005764b0(&local_1018,0xffffffff,DAT_00aba250,auStack_1008,0x801,iVar11);
            if (DAT_00aba24c == 0) {
              FUN_0057a980();
            }
            iVar11 = FUN_005773c0(DAT_00aba24c,auStack_1008);
            iStack_100c = iVar11;
            if (DAT_00aba24c == 0) {
              FUN_0057a980();
            }
            iVar12 = DAT_00aba24c;
            if (DAT_00aba250 == 0) {
              FUN_0057a980();
            }
            FUN_005764b0(*(undefined4 *)(&DAT_00aa84e0 + iVar15),0xffffffff,DAT_00aba250,
                         *(undefined4 *)(&DAT_00aa84e4 + iVar15),
                         *(undefined4 *)(&DAT_00aa84e8 + iVar15),iVar12);
            if (DAT_00aba24c == 0) {
              FUN_0057a980();
            }
            iStack_101c = FUN_005773c0(DAT_00aba24c,*(undefined4 *)(&DAT_00aa84e4 + iVar15));
            if ((((*(int *)(&DAT_00aa84f0 + iVar15) == 0) || (iVar11 == 1)) &&
                ((*(int *)(&DAT_00aa84f8 + iVar15) == 0 || (iVar11 != 1)))) &&
               (((DAT_00aa849c != 1 || (iStack_101c + iVar11 <= *(int *)(&DAT_00aa84cc + iVar15)))
                || (*(int *)(&DAT_00aa84dc + iVar15) + iVar5 <= *(int *)(&DAT_00aa84c8 + iVar15)))))
            {
              if (*(int *)(&DAT_00aa84cc + iVar15) < iStack_101c + iVar11) {
                do {
                  iVar11 = 0;
                  if (0 < *(int *)(&DAT_00aa84c8 + iVar15)) {
                    do {
                      iVar6 = 2 - (uint)((*(ushort *)(*(int *)(&DAT_00aa84e0 + iVar15) + iVar11 * 2)
                                         & 0xfc00) != 0xd800);
                      iVar11 = iVar11 + iVar6;
                      iStack_1010 = iVar6;
                    } while (iVar11 < *(int *)(&DAT_00aa84c8 + iVar15));
                  }
                  iVar12 = 0;
                  if (0 < iVar6) {
                    puVar10 = (undefined2 *)
                              (*(int *)(&DAT_00aa84e0 + iVar15) + (iVar11 - iVar6) * 2);
                    do {
                      auStack_804[iVar12] = *puVar10;
                      iVar12 = iVar12 + 1;
                      puVar10 = puVar10 + 1;
                    } while (iVar12 < iVar6);
                  }
                  auStack_804[iVar6] = 0;
                  if (DAT_00aba24c == 0) {
                    FUN_0057a980();
                  }
                  iVar12 = DAT_00aba24c;
                  if (DAT_00aba250 == 0) {
                    FUN_0057a980();
                  }
                  FUN_005764b0(auStack_804,0xffffffff,DAT_00aba250,auStack_1008,0x801,iVar12);
                  if (DAT_00aba24c == 0) {
                    FUN_0057a980();
                  }
                  iVar12 = FUN_005773c0(DAT_00aba24c,auStack_1008);
                  iStack_101c = iStack_101c - iVar12;
                  *(undefined2 *)(*(int *)(&DAT_00aa84e0 + iVar15) + (iVar11 - iVar6) * 2) = 0;
                  *(int *)(&DAT_00aa84c8 + iVar15) = *(int *)(&DAT_00aa84c8 + iVar15) - iVar6;
                  if (*(int *)(&DAT_00aa84dc + iVar15) == iVar11) {
                    *(int *)(&DAT_00aa84dc + iVar15) = *(int *)(&DAT_00aa84dc + iVar15) - iVar6;
                  }
                } while (*(int *)(&DAT_00aa84cc + iVar15) < iStack_101c + iStack_100c);
              }
              iVar6 = *(int *)(&DAT_00aa84dc + iVar15);
              FUN_0056d460(*(int *)(&DAT_00aa84e0 + iVar15) + (iVar6 + iVar5) * 2,
                           *(int *)(&DAT_00aa84e0 + iVar15) + iVar6 * 2,
                           (*(int *)(&DAT_00aa84c8 + iVar15) - iVar6) * 2 + 2);
              FUN_0056d460(*(int *)(&DAT_00aa84e0 + iVar15) + *(int *)(&DAT_00aa84dc + iVar15) * 2,
                           &local_1018,iVar5 * 2);
              *(int *)(&DAT_00aa84dc + iVar15) = *(int *)(&DAT_00aa84dc + iVar15) + iVar5;
              *(int *)(&DAT_00aa84c8 + iVar15) = *(int *)(&DAT_00aa84c8 + iVar15) + iVar5;
            }
          }
          else if (local_1018 == 0x2d) {
            if (*(int *)(&DAT_00aa84dc + iVar15) == 0) goto LAB_00566979;
          }
          else if (((local_1018 == 0x2e) &&
                   (iVar11 = FUN_0056d0d0(*(undefined4 *)(&DAT_00aa84e0 + iVar15),0x2e), iVar11 == 0
                   )) && (local_1018 == 0x2e)) goto LAB_00566979;
          break;
        case 8:
          if (*(int *)(&DAT_00aa84d0 + iVar15) == -1) {
            if (0 < *(int *)(&DAT_00aa84dc + iVar15)) {
              iVar5 = 1;
              if (1 < *(int *)(&DAT_00aa84dc + iVar15)) {
                iVar5 = FUN_005646a0();
                iVar5 = 2 - (uint)(iVar5 != 2);
              }
              iVar6 = *(int *)(&DAT_00aa84e0 + iVar15);
              iVar11 = *(int *)(&DAT_00aa84dc + iVar15) - iVar5;
              sVar3 = *(short *)(iVar6 + iVar11 * 2);
              *(int *)(&DAT_00aa84dc + iVar15) = iVar11;
              FUN_0056d460(iVar6 + iVar11 * 2,iVar6 + (iVar11 + iVar5) * 2,
                           (*(int *)(&DAT_00aa84c8 + iVar15) - iVar11) * 2);
              *(int *)(&DAT_00aa84c8 + iVar15) = *(int *)(&DAT_00aa84c8 + iVar15) - iVar5;
              if ((sVar3 == 10) &&
                 (iVar5 = *(int *)(&DAT_00aa84d8 + iVar15),
                 *(int *)(&DAT_00aa84dc + iVar15) <= iVar5)) {
                while (0 < iVar5) {
                  iVar5 = *(int *)(&DAT_00aa84d8 + iVar15);
                  iVar6 = 1;
                  if (iVar5 < 2) {
LAB_005664c6:
                    if (*(short *)(*(int *)(&DAT_00aa84e0 + iVar15) + -2 + iVar5 * 2) == 10) break;
                  }
                  else {
                    iVar6 = FUN_005646a0();
                    iVar6 = 2 - (uint)(iVar6 != 2);
                    if (iVar6 == 1) goto LAB_005664c6;
                  }
                  iVar5 = iVar5 - iVar6;
                  *(int *)(&DAT_00aa84d8 + iVar15) = iVar5;
                }
              }
            }
          }
          else {
LAB_0056640f:
            FUN_00563b90();
          }
          break;
        case 9:
          break;
        case 0xd:
          if (*(int *)(&DAT_00aa84fc + iVar15) != 0) {
            local_1018 = 10;
            goto switchD_00565f91_caseD_4;
          }
          *(undefined4 *)(&DAT_00aa84c0 + iVar15) = 1;
          DAT_00aa84b0 = 0xffffffff;
          break;
        case 0x10:
          if (*(int *)(&DAT_00aa84d0 + iVar15) == -1) {
            iVar5 = *(int *)(&DAT_00aa84dc + iVar15);
            if (iVar5 != *(int *)(&DAT_00aa84c8 + iVar15)) {
              iVar6 = *(int *)(&DAT_00aa84e0 + iVar15);
              iVar11 = 2 - (uint)((*(ushort *)(iVar6 + iVar5 * 2) & 0xfc00) != 0xd800);
              FUN_0056d460(iVar6 + iVar5 * 2,iVar6 + (iVar5 + iVar11) * 2,
                           (*(int *)(&DAT_00aa84c8 + iVar15) - iVar5) * 2);
              *(int *)(&DAT_00aa84c8 + iVar15) = *(int *)(&DAT_00aa84c8 + iVar15) - iVar11;
            }
          }
          else {
            iVar5 = FUN_0054f8b0(0x2a);
            if ((iVar5 != 0) || (iVar5 = FUN_0054f8b0(0x36), iVar5 != 0))
            goto switchD_00565f91_caseD_18;
            FUN_00563b90();
          }
          break;
        case 0x16:
          iVar5 = FUN_0050eb50(0);
          if (iVar5 != -1) {
            uVar8 = FUN_0050eb50(0);
            puVar9 = (ushort *)
                     FUN_0056e030(uVar8,"..\\..\\..\\..\\Source\\Library\\Main\\DxInputString.cpp",
                                  0x1049);
            if (puVar9 != (ushort *)0x0) {
              FUN_0050eb50(puVar9);
              uVar4 = *puVar9;
              puVar13 = puVar9;
              while (uVar4 != 0) {
                uVar4 = *puVar13;
                if ((uVar4 & 0xfc00) == 0xd800) {
                  FUN_00563ac0(uVar4);
                  puVar1 = puVar13 + 1;
                  puVar13 = puVar13 + 1;
                  FUN_00563ac0(*puVar1);
                }
                else if ((*(int *)(&DAT_00aa84fc + iVar15) != 0) ||
                        ((uVar4 != 0xd && (uVar4 != 10)))) {
                  FUN_00563ac0(uVar4);
                }
                puVar13 = puVar13 + 1;
                uVar4 = *puVar13;
              }
              FUN_0056e1d0(puVar9);
            }
          }
          break;
        case 0x18:
switchD_00565f91_caseD_18:
          iVar5 = *(int *)(&DAT_00aa84d0 + iVar15);
          if (iVar5 != -1) {
            iVar6 = *(int *)(&DAT_00aa84d4 + iVar15);
            if (iVar6 < iVar5) {
              iVar11 = iVar5;
              iVar5 = iVar6;
            }
            else {
              iVar11 = iVar6;
            }
            iVar6 = (iVar11 - iVar5) * 2;
            iVar11 = FUN_0056e030(iVar6 + 2,
                                  "..\\..\\..\\..\\Source\\Library\\Main\\DxInputString.cpp",0x1018)
            ;
            if (iVar11 != 0) {
              FUN_0056d420(iVar11,*(int *)(&DAT_00aa84e0 + iVar15) + iVar5 * 2,iVar6);
              *(undefined2 *)(iVar11 + iVar6) = 0;
              FUN_0050ebd0(iVar11);
              FUN_0056e1d0(iVar11);
            }
            goto LAB_0056640f;
          }
          break;
        case 0x19:
          iVar5 = FUN_0054f8b0(0x1d);
          if ((iVar5 == 0) && (iVar5 = FUN_0054f8b0(0x9d), iVar5 == 0)) {
            iVar5 = *(int *)(&DAT_00aa84dc + iVar15);
            if (iVar5 < *(int *)(&DAT_00aa84c8 + iVar15)) {
              do {
                if (*(short *)(*(int *)(&DAT_00aa84e0 + iVar15) +
                              *(int *)(&DAT_00aa84dc + iVar15) * 2) == 10) break;
                iVar6 = 1;
                if ((*(ushort *)
                      (*(int *)(&DAT_00aa84e0 + iVar15) + *(int *)(&DAT_00aa84dc + iVar15) * 2) &
                    0xfc00) == 0xd800) {
                  iVar6 = 2;
                }
                *(int *)(&DAT_00aa84dc + iVar15) = *(int *)(&DAT_00aa84dc + iVar15) + iVar6;
              } while (*(int *)(&DAT_00aa84dc + iVar15) < *(int *)(&DAT_00aa84c8 + iVar15));
            }
            iVar6 = FUN_0054f8b0(0x2a);
            if ((iVar6 == 0) && (iVar6 = FUN_0054f8b0(0x36), iVar6 == 0)) {
              *(undefined4 *)(&DAT_00aa84d0 + iVar15) = 0xffffffff;
              *(undefined4 *)(&DAT_00aa84d4 + iVar15) = 0xffffffff;
            }
            else if (*(int *)(&DAT_00aa84d0 + iVar15) == -1) {
              *(int *)(&DAT_00aa84d0 + iVar15) = iVar5;
              *(undefined4 *)(&DAT_00aa84d4 + iVar15) = *(undefined4 *)(&DAT_00aa84dc + iVar15);
            }
            else {
LAB_0056604a:
              *(undefined4 *)(&DAT_00aa84d4 + iVar15) = *(undefined4 *)(&DAT_00aa84dc + iVar15);
            }
          }
          else {
            iVar5 = FUN_0054f8b0(0x2a);
            if ((iVar5 == 0) && (iVar5 = FUN_0054f8b0(0x36), iVar5 == 0)) {
              *(undefined4 *)(&DAT_00aa84d0 + iVar15) = 0xffffffff;
              *(undefined4 *)(&DAT_00aa84d4 + iVar15) = 0xffffffff;
              *(undefined4 *)(&DAT_00aa84dc + iVar15) = *(undefined4 *)(&DAT_00aa84c8 + iVar15);
            }
            else if (*(int *)(&DAT_00aa84d0 + iVar15) == -1) {
              *(undefined4 *)(&DAT_00aa84d0 + iVar15) = *(undefined4 *)(&DAT_00aa84dc + iVar15);
              *(undefined4 *)(&DAT_00aa84d4 + iVar15) = *(undefined4 *)(&DAT_00aa84c8 + iVar15);
              *(undefined4 *)(&DAT_00aa84dc + iVar15) = *(undefined4 *)(&DAT_00aa84c8 + iVar15);
            }
            else {
              *(undefined4 *)(&DAT_00aa84d4 + iVar15) = *(undefined4 *)(&DAT_00aa84c8 + iVar15);
              *(undefined4 *)(&DAT_00aa84dc + iVar15) = *(undefined4 *)(&DAT_00aa84c8 + iVar15);
            }
          }
          break;
        case 0x1a:
          iVar5 = FUN_0054f8b0(0x1d);
          if ((iVar5 == 0) && (iVar5 = FUN_0054f8b0(0x9d), iVar5 == 0)) {
            iVar5 = *(int *)(&DAT_00aa84dc + iVar15);
            if (0 < iVar5) {
              do {
                iVar6 = 1;
                if (1 < *(int *)(&DAT_00aa84dc + iVar15)) {
                  iVar6 = FUN_005646a0();
                  iVar6 = 2 - (uint)(iVar6 != 2);
                }
                *(int *)(&DAT_00aa84dc + iVar15) = *(int *)(&DAT_00aa84dc + iVar15) - iVar6;
                iVar6 = *(int *)(&DAT_00aa84dc + iVar15);
              } while ((0 < iVar6) &&
                      (*(short *)(*(int *)(&DAT_00aa84e0 + iVar15) + iVar6 * 2) != 10));
              if (*(short *)(*(int *)(&DAT_00aa84e0 + iVar15) + iVar6 * 2) == 10) {
                *(int *)(&DAT_00aa84dc + iVar15) = iVar6 + 1;
              }
              iVar6 = FUN_0054f8b0(0x2a);
              if ((iVar6 == 0) && (iVar6 = FUN_0054f8b0(0x36), iVar6 == 0)) {
                *(undefined4 *)(&DAT_00aa84d0 + iVar15) = 0xffffffff;
                *(undefined4 *)(&DAT_00aa84d4 + iVar15) = 0xffffffff;
              }
              else {
                if (*(int *)(&DAT_00aa84d0 + iVar15) == -1) {
                  *(int *)(&DAT_00aa84d0 + iVar15) = iVar5;
                  goto LAB_0056604a;
                }
LAB_005667f3:
                *(undefined4 *)(&DAT_00aa84d4 + iVar15) = *(undefined4 *)(&DAT_00aa84dc + iVar15);
              }
            }
          }
          else {
            iVar5 = FUN_0054f8b0(0x2a);
            if ((iVar5 == 0) && (iVar5 = FUN_0054f8b0(0x36), iVar5 == 0)) {
              *(undefined4 *)(&DAT_00aa84d0 + iVar15) = 0xffffffff;
              *(undefined4 *)(&DAT_00aa84d4 + iVar15) = 0xffffffff;
              *(undefined4 *)(&DAT_00aa84dc + iVar15) = 0;
            }
            else {
              *(undefined4 *)(&DAT_00aa84d4 + iVar15) = 0;
              if (*(int *)(&DAT_00aa84d0 + iVar15) == -1) {
                *(undefined4 *)(&DAT_00aa84d0 + iVar15) = *(undefined4 *)(&DAT_00aa84dc + iVar15);
              }
              *(undefined4 *)(&DAT_00aa84dc + iVar15) = 0;
            }
          }
          break;
        case 0x1b:
          if (*(int *)(&DAT_00aa84ec + iVar15) != 0) {
            *(undefined4 *)(&DAT_00aa84c4 + iVar15) = 1;
            *(undefined4 *)(&DAT_00aa84c0 + iVar15) = 1;
            DAT_00aa84b0 = 0xffffffff;
          }
          break;
        case 0x1c:
          if (*(int *)(&DAT_00aa84dc + iVar15) < *(int *)(&DAT_00aa84c8 + iVar15)) {
            iVar5 = 1;
            if ((*(ushort *)
                  (*(int *)(&DAT_00aa84e0 + iVar15) + *(int *)(&DAT_00aa84dc + iVar15) * 2) & 0xfc00
                ) == 0xd800) {
              iVar5 = 2;
            }
            iVar6 = FUN_0054f8b0(0x2a);
            if ((iVar6 == 0) && (iVar6 = FUN_0054f8b0(0x36), iVar6 == 0)) {
              *(int *)(&DAT_00aa84dc + iVar15) = *(int *)(&DAT_00aa84dc + iVar15) + iVar5;
              *(undefined4 *)(&DAT_00aa84d0 + iVar15) = 0xffffffff;
              *(undefined4 *)(&DAT_00aa84d4 + iVar15) = 0xffffffff;
            }
            else {
              iVar6 = *(int *)(&DAT_00aa84dc + iVar15);
              if (*(int *)(&DAT_00aa84d0 + iVar15) == -1) {
                *(int *)(&DAT_00aa84d0 + iVar15) = iVar6;
              }
              *(int *)(&DAT_00aa84dc + iVar15) = *(int *)(&DAT_00aa84dc + iVar15) + iVar5;
              *(int *)(&DAT_00aa84d4 + iVar15) = iVar6 + iVar5;
            }
          }
          break;
        case 0x1d:
          if (0 < *(int *)(&DAT_00aa84dc + iVar15)) {
            iVar5 = 1;
            if ((1 < *(int *)(&DAT_00aa84dc + iVar15)) && (iVar6 = FUN_005646a0(), iVar6 == 2)) {
              iVar5 = 2;
            }
            sVar3 = *(short *)(*(int *)(&DAT_00aa84e0 + iVar15) +
                              (*(int *)(&DAT_00aa84dc + iVar15) - iVar5) * 2);
            iVar6 = FUN_0054f8b0(0x2a);
            if ((iVar6 == 0) && (iVar6 = FUN_0054f8b0(0x36), iVar6 == 0)) {
              *(undefined4 *)(&DAT_00aa84d0 + iVar15) = 0xffffffff;
              *(undefined4 *)(&DAT_00aa84d4 + iVar15) = 0xffffffff;
            }
            else if (*(int *)(&DAT_00aa84d0 + iVar15) == -1) {
              *(int *)(&DAT_00aa84d0 + iVar15) = *(int *)(&DAT_00aa84dc + iVar15);
              *(int *)(&DAT_00aa84d4 + iVar15) = *(int *)(&DAT_00aa84dc + iVar15) - iVar5;
            }
            else {
              *(int *)(&DAT_00aa84d4 + iVar15) = *(int *)(&DAT_00aa84dc + iVar15) - iVar5;
            }
            *(int *)(&DAT_00aa84dc + iVar15) = *(int *)(&DAT_00aa84dc + iVar15) - iVar5;
            iVar5 = *(int *)(&DAT_00aa84dc + iVar15);
            if ((sVar3 == 10) && (iVar5 <= *(int *)(&DAT_00aa84d8 + iVar15))) {
              *(int *)(&DAT_00aa84d8 + iVar15) = iVar5;
              while (0 < iVar5) {
                iVar5 = *(int *)(&DAT_00aa84d8 + iVar15);
                iVar6 = 1;
                if (iVar5 < 2) {
LAB_005665a8:
                  if (*(short *)(*(int *)(&DAT_00aa84e0 + iVar15) + -2 + iVar5 * 2) == 10) break;
                }
                else {
                  iVar6 = FUN_005646a0();
                  iVar6 = 2 - (uint)(iVar6 != 2);
                  if (iVar6 == 1) goto LAB_005665a8;
                }
                iVar5 = iVar5 - iVar6;
                *(int *)(&DAT_00aa84d8 + iVar15) = iVar5;
              }
            }
          }
          break;
        case 0x1e:
          iStack_1020 = *(int *)(&DAT_00aa84dc + iVar15);
          if (0 < iStack_1020) {
            iVar5 = *(int *)(&DAT_00aa84e0 + iVar15);
            if (*(short *)(iVar5 + -2 + iStack_1020 * 2) == 10) {
              if (iStack_1020 == 1) {
                *(undefined4 *)(&DAT_00aa84dc + iVar15) = 0;
              }
              else {
                if (*(short *)(iVar5 + -4 + iStack_1020 * 2) == 10) {
                  iVar5 = iStack_1020 + -1;
                }
                else {
                  *(int *)(&DAT_00aa84dc + iVar15) = iStack_1020 + -1;
                  do {
                    iVar6 = 1;
                    if (1 < *(int *)(&DAT_00aa84dc + iVar15)) {
                      uVar16 = FUN_005646a0();
                      iVar5 = (int)((ulonglong)uVar16 >> 0x20);
                      iVar6 = 2 - (uint)((int)uVar16 != 2);
                    }
                    piVar2 = (int *)(&DAT_00aa84dc + iVar15);
                    *piVar2 = *piVar2 - iVar6;
                  } while ((-1 < *piVar2) &&
                          (*(short *)(iVar5 + *(int *)(&DAT_00aa84dc + iVar15) * 2) != 10));
                  iVar5 = *(int *)(&DAT_00aa84dc + iVar15) + 1;
                }
                *(int *)(&DAT_00aa84dc + iVar15) = iVar5;
              }
              if (*(int *)(&DAT_00aa84dc + iVar15) < *(int *)(&DAT_00aa84d8 + iVar15)) {
                *(int *)(&DAT_00aa84d8 + iVar15) = *(int *)(&DAT_00aa84dc + iVar15);
              }
            }
            else {
              iVar11 = 0;
              iVar6 = 0;
              do {
                iVar12 = iVar6;
                iVar6 = 1;
                if (1 < *(int *)(&DAT_00aa84dc + iVar15) - iVar11) {
                  uVar16 = FUN_005646a0();
                  iVar5 = (int)((ulonglong)uVar16 >> 0x20);
                  iVar6 = 2 - (uint)((int)uVar16 != 2);
                }
                iVar11 = iVar11 + iVar6;
              } while ((-1 < *(int *)(&DAT_00aa84dc + iVar15) - iVar11) &&
                      (iVar6 = iVar12 + 1,
                      *(short *)(iVar5 + (*(int *)(&DAT_00aa84dc + iVar15) - iVar11) * 2) != 10));
              if (*(int *)(&DAT_00aa84dc + iVar15) - iVar11 < 0) {
                iVar5 = FUN_0054f8b0(0x2a);
                if ((iVar5 == 0) && (iVar5 = FUN_0054f8b0(0x36), iVar5 == 0)) {
                  *(undefined4 *)(&DAT_00aa84d0 + iVar15) = 0xffffffff;
                  *(undefined4 *)(&DAT_00aa84d4 + iVar15) = 0xffffffff;
                }
                break;
              }
              *(int *)(&DAT_00aa84dc + iVar15) = *(int *)(&DAT_00aa84dc + iVar15) - iVar11;
              do {
                iVar6 = 1;
                if (1 < *(int *)(&DAT_00aa84dc + iVar15)) {
                  uVar16 = FUN_005646a0();
                  iVar5 = (int)((ulonglong)uVar16 >> 0x20);
                  iVar6 = 2 - (uint)((int)uVar16 != 2);
                }
                *(int *)(&DAT_00aa84dc + iVar15) = *(int *)(&DAT_00aa84dc + iVar15) - iVar6;
                iVar6 = *(int *)(&DAT_00aa84dc + iVar15);
              } while ((0 < iVar6) && (*(short *)(iVar5 + iVar6 * 2) != 10));
              if (iVar6 != 0) {
                *(int *)(&DAT_00aa84dc + iVar15) = iVar6 + 1;
              }
              if (*(int *)(&DAT_00aa84dc + iVar15) < *(int *)(&DAT_00aa84d8 + iVar15)) {
                *(int *)(&DAT_00aa84d8 + iVar15) = *(int *)(&DAT_00aa84dc + iVar15);
              }
              if (0 < iVar12) {
                iVar6 = 0;
                do {
                  if (*(short *)(iVar5 + *(int *)(&DAT_00aa84dc + iVar15) * 2) == 10) break;
                  iVar11 = 1;
                  if ((*(ushort *)(iVar5 + *(int *)(&DAT_00aa84dc + iVar15) * 2) & 0xfc00) == 0xd800
                     ) {
                    iVar11 = 2;
                  }
                  *(int *)(&DAT_00aa84dc + iVar15) = *(int *)(&DAT_00aa84dc + iVar15) + iVar11;
                  iVar6 = iVar6 + 1;
                } while (iVar6 < iVar12);
              }
            }
            iVar5 = FUN_0054f8b0(0x2a);
            if ((iVar5 == 0) && (iVar5 = FUN_0054f8b0(0x36), iVar5 == 0)) {
              *(undefined4 *)(&DAT_00aa84d0 + iVar15) = 0xffffffff;
              *(undefined4 *)(&DAT_00aa84d4 + iVar15) = 0xffffffff;
            }
            else {
LAB_005667db:
              if (*(int *)(&DAT_00aa84d0 + iVar15) != -1) goto LAB_005667f3;
              *(int *)(&DAT_00aa84d0 + iVar15) = iStack_1020;
              *(undefined4 *)(&DAT_00aa84d4 + iVar15) = *(undefined4 *)(&DAT_00aa84dc + iVar15);
            }
          }
          break;
        case 0x1f:
          iStack_1020 = *(int *)(&DAT_00aa84dc + iVar15);
          if (iStack_1020 < *(int *)(&DAT_00aa84c8 + iVar15)) {
            iVar11 = 0;
            iVar5 = iStack_1020;
            iVar6 = 0;
            do {
              iVar12 = iVar6;
              iVar6 = 1;
              if (1 < iVar5) {
                iVar5 = FUN_005646a0();
                iVar6 = 2 - (uint)(iVar5 != 2);
              }
              iVar11 = iVar11 + iVar6;
              iVar5 = *(int *)(&DAT_00aa84dc + iVar15) - iVar11;
              iVar6 = iVar12 + 1;
            } while ((0 < iVar5) && (*(short *)(*(int *)(&DAT_00aa84e0 + iVar15) + iVar5 * 2) != 10)
                    );
            if (*(int *)(&DAT_00aa84dc + iVar15) == iVar11) {
              iVar6 = iVar12 + 2;
            }
            iVar5 = 0;
            if (*(int *)(&DAT_00aa84dc + iVar15) < *(int *)(&DAT_00aa84c8 + iVar15)) {
              do {
                if (*(short *)(*(int *)(&DAT_00aa84e0 + iVar15) +
                              (*(int *)(&DAT_00aa84dc + iVar15) + iVar5) * 2) == 10) break;
                iVar11 = 1;
                if ((*(ushort *)
                      (*(int *)(&DAT_00aa84e0 + iVar15) +
                      (*(int *)(&DAT_00aa84dc + iVar15) + iVar5) * 2) & 0xfc00) == 0xd800) {
                  iVar11 = 2;
                }
                iVar5 = iVar5 + iVar11;
              } while (*(int *)(&DAT_00aa84dc + iVar15) + iVar5 < *(int *)(&DAT_00aa84c8 + iVar15));
            }
            if (iVar5 + *(int *)(&DAT_00aa84dc + iVar15) == *(int *)(&DAT_00aa84c8 + iVar15)) {
              iVar5 = FUN_0054f8b0(0x2a);
              if ((iVar5 == 0) && (iVar5 = FUN_0054f8b0(0x36), iVar5 == 0)) {
                *(undefined4 *)(&DAT_00aa84d0 + iVar15) = 0xffffffff;
                *(undefined4 *)(&DAT_00aa84d4 + iVar15) = 0xffffffff;
              }
            }
            else {
              iVar11 = 0;
              *(int *)(&DAT_00aa84dc + iVar15) = iVar5 + *(int *)(&DAT_00aa84dc + iVar15) + 1;
              if (0 < iVar6 + -1) {
                do {
                  if ((*(int *)(&DAT_00aa84c8 + iVar15) <= *(int *)(&DAT_00aa84dc + iVar15)) ||
                     (*(short *)(*(int *)(&DAT_00aa84e0 + iVar15) +
                                *(int *)(&DAT_00aa84dc + iVar15) * 2) == 10)) break;
                  iVar5 = 1;
                  if ((*(ushort *)
                        (*(int *)(&DAT_00aa84e0 + iVar15) + *(int *)(&DAT_00aa84dc + iVar15) * 2) &
                      0xfc00) == 0xd800) {
                    iVar5 = 2;
                  }
                  *(int *)(&DAT_00aa84dc + iVar15) = *(int *)(&DAT_00aa84dc + iVar15) + iVar5;
                  iVar11 = iVar11 + 1;
                } while (iVar11 < iVar6 + -1);
              }
              iVar5 = FUN_0054f8b0(0x2a);
              if ((iVar5 != 0) || (iVar5 = FUN_0054f8b0(0x36), iVar5 != 0)) goto LAB_005667db;
              *(undefined4 *)(&DAT_00aa84d0 + iVar15) = 0xffffffff;
              *(undefined4 *)(&DAT_00aa84d4 + iVar15) = 0xffffffff;
            }
          }
        }
        iVar5 = *(int *)(&DAT_00aa84c0 + iVar15);
        iVar6 = iStack_1010;
      } while( true );
    }
  }
  return 0;
}

