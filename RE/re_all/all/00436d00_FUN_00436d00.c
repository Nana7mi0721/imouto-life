
/* WARNING: Removing unreachable block (ram,0x004388ed) */
/* WARNING: Removing unreachable block (ram,0x00438937) */
/* WARNING: Removing unreachable block (ram,0x00438923) */
/* WARNING: Removing unreachable block (ram,0x00438943) */
/* WARNING: Removing unreachable block (ram,0x0043892c) */
/* WARNING: Removing unreachable block (ram,0x0043894f) */
/* WARNING: Removing unreachable block (ram,0x00438935) */
/* WARNING: Removing unreachable block (ram,0x00438959) */
/* WARNING: Removing unreachable block (ram,0x00438966) */
/* WARNING: Removing unreachable block (ram,0x004389cc) */
/* WARNING: Removing unreachable block (ram,0x00438a16) */
/* WARNING: Removing unreachable block (ram,0x00438a0b) */
/* WARNING: Removing unreachable block (ram,0x00438a4d) */
/* WARNING: Removing unreachable block (ram,0x00438a14) */

void FUN_00436d00(void)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  wchar_t *pwVar9;
  uint *puVar10;
  char *pcVar11;
  undefined *puVar12;
  undefined4 uVar13;
  undefined1 *puVar14;
  undefined4 uVar15;
  undefined1 local_114 [4];
  undefined1 local_110 [4];
  undefined1 local_10c [4];
  undefined1 local_108 [4];
  undefined1 local_104 [4];
  undefined1 local_100 [4];
  undefined4 local_fc;
  int local_f8 [3];
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  int local_e0;
  int local_dc;
  undefined1 local_d8 [4];
  undefined1 local_d4 [4];
  undefined1 local_d0 [4];
  undefined1 local_cc [4];
  undefined4 local_c8;
  int local_c4;
  undefined1 local_c0 [4];
  undefined1 local_bc [4];
  undefined4 local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_9c;
  undefined4 local_98;
  undefined4 local_94;
  int local_90;
  int local_8c;
  int local_88;
  undefined *local_84;
  undefined4 local_80;
  int local_7c;
  basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_> local_78 [16];
  int local_68;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c [7];
  int local_20;
  int local_1c;
  int local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad124;
  local_10 = ExceptionList;
  local_11 = '\0';
  local_18 = 0;
  ExceptionList = &local_10;
  do {
    iVar4 = FUN_004cfab0();
    if (iVar4 <= local_18) {
      ExceptionList = local_10;
      return;
    }
    local_1c = 0;
    while( true ) {
      FUN_004cfb40(local_18);
      iVar4 = FUN_004cec90();
      if (iVar4 <= local_1c) break;
      iVar4 = local_1c;
      FUN_004cfb40(local_18);
      local_20 = FUN_004ced20(iVar4);
      piVar5 = (int *)FUN_004ce990(0);
      iVar4 = *piVar5;
      if (iVar4 < 499) {
        if (iVar4 == 0x1f2) {
LAB_00438a87:
          local_a8 = local_1c;
          do {
            if (local_a8 < 0) goto switchD_00436e17_caseD_6c;
            iVar4 = local_a8 + -1;
            local_a8 = iVar4;
            FUN_004cfb40(local_18);
            iVar4 = FUN_004ced20(iVar4);
          } while (*(char *)(iVar4 + 0x10) != *(char *)(local_20 + 0x10));
          FUN_004ce950();
          FUN_004ce970(2);
          puVar7 = (undefined4 *)FUN_004ce990(0);
          *puVar7 = 1;
          piVar5 = (int *)FUN_004ce990(1);
          *piVar5 = local_a8;
          goto switchD_00436e17_caseD_6c;
        }
        if (0xd5 < iVar4) {
          if (iVar4 == 0xfa) {
            FUN_004e9510();
            puVar10 = (uint *)FUN_004ce990(4);
            if (((*puVar10 & 0xf0000) != 0) && (iVar4 = FUN_004cc430(), 1 < iVar4)) {
              puVar10 = (uint *)FUN_004ce990(4);
              local_88 = (int)(*puVar10 & 0xf00) >> 8;
              puVar10 = (uint *)FUN_004ce990(4);
              if ((*puVar10 & 0x10000) != 0) {
                uVar15 = FUN_004cc4c0(1);
                puVar7 = (undefined4 *)FUN_004ccca0(local_100,uVar15);
                local_80 = *puVar7;
                uVar15 = FUN_004ce060(local_104);
                cVar3 = const_iterator__operator__(uVar15);
                if (cVar3 != '\0') {
                  iVar4 = FUN_004d07e0();
                  puVar7 = (undefined4 *)FUN_004ce990(1);
                  *puVar7 = *(undefined4 *)(iVar4 + 0x1c);
                  piVar5 = (int *)FUN_004ce990(2);
                  if ((*piVar5 != -3) && (piVar5 = (int *)FUN_004ce990(3), *piVar5 != -3)) {
                    puVar10 = (uint *)FUN_004ce990(4);
                    *puVar10 = *puVar10 & 0xfffeffff;
                  }
                }
              }
            }
            piVar5 = (int *)FUN_004ce990(1);
            if (((-1 < *piVar5) && (piVar5 = (int *)FUN_004ce990(1), *piVar5 < 1000000)) &&
               (iVar4 = FUN_004cc430(), 1 < iVar4)) {
              piVar5 = (int *)FUN_004ce990(1);
              local_90 = *piVar5;
              puVar10 = (uint *)FUN_004ce990(4);
              local_8c = (int)(*puVar10 & 0xf00) >> 8;
              puVar10 = (uint *)FUN_004ce990(4);
              if (((*puVar10 & 0x20000) != 0) && (iVar4 = FUN_004ccff0(), local_90 < iVar4)) {
                uVar15 = FUN_004cc4c0(2);
                puVar14 = local_108;
                FUN_004cd030(local_90);
                puVar7 = (undefined4 *)FUN_004ccca0(puVar14,uVar15);
                local_80 = *puVar7;
                puVar14 = local_10c;
                FUN_004cd030(local_90);
                uVar15 = FUN_004ce060(puVar14);
                cVar3 = const_iterator__operator__(uVar15);
                if (cVar3 == '\0') goto switchD_00436e17_caseD_6c;
                iVar4 = FUN_004d07e0();
                puVar7 = (undefined4 *)FUN_004ce990(2);
                *puVar7 = *(undefined4 *)(iVar4 + 0x1c);
                piVar5 = (int *)FUN_004ce990(3);
                if (*piVar5 != -3) {
                  puVar10 = (uint *)FUN_004ce990(4);
                  *puVar10 = *puVar10 & 0xfffdffff;
                }
              }
              puVar10 = (uint *)FUN_004ce990(4);
              if (((*puVar10 & 0x40000) != 0) && (iVar4 = FUN_004ccff0(), local_90 < iVar4)) {
                uVar15 = FUN_004cc4c0(3);
                puVar14 = local_110;
                FUN_004cd030(local_90);
                puVar7 = (undefined4 *)FUN_004ccca0(puVar14,uVar15);
                local_80 = *puVar7;
                puVar14 = local_114;
                FUN_004cd030(local_90);
                uVar15 = FUN_004ce060(puVar14);
                cVar3 = const_iterator__operator__(uVar15);
                if (cVar3 == '\0') goto switchD_00436e17_caseD_6c;
                iVar4 = FUN_004d07e0();
                puVar7 = (undefined4 *)FUN_004ce990(3);
                *puVar7 = *(undefined4 *)(iVar4 + 0x1c);
                piVar5 = (int *)FUN_004ce990(2);
                if (*piVar5 != -3) {
                  puVar10 = (uint *)FUN_004ce990(4);
                  *puVar10 = *puVar10 & 0xfffbffff;
                }
              }
            }
            local_84 = (undefined *)0x0;
            puVar10 = (uint *)FUN_004ce990(4);
            iVar4 = (int)(*puVar10 & 0xf00) >> 8;
            if (iVar4 == 0) {
              local_84 = &DAT_00a16538;
            }
            else if (iVar4 == 1) {
              local_84 = &DAT_00a143d8;
            }
            else if (iVar4 == 2) {
              local_84 = &DAT_00a14bb8;
            }
            if (local_84 != (undefined *)0x0) {
              FUN_004ce950();
              puVar7 = (undefined4 *)FUN_004ce990(5);
              cVar3 = FUN_00438d40(*puVar7);
              if (((((cVar3 != '\0') && (piVar5 = (int *)FUN_004ce990(1), *piVar5 < 1000000)) &&
                   (piVar5 = (int *)FUN_004ce990(3), *piVar5 < 1000000)) &&
                  ((puVar10 = (uint *)FUN_004ce990(4), (*puVar10 & 0xf) == 0 &&
                   (piVar5 = (int *)FUN_004ce990(1), -1 < *piVar5)))) &&
                 ((piVar5 = (int *)FUN_004ce990(2), -1 < *piVar5 &&
                  ((piVar5 = (int *)FUN_004ce990(3), -1 < *piVar5 &&
                   (piVar5 = (int *)FUN_004ce990(5), *piVar5 < 1000000000)))))) {
                local_98 = FUN_004ce080();
                puVar7 = (undefined4 *)FUN_004ce990(1);
                local_94 = *puVar7;
                iVar4 = FUN_00477850();
                piVar5 = (int *)FUN_004ce990(1);
                if (*piVar5 < iVar4) {
                  puVar7 = (undefined4 *)FUN_004ce990(1);
                  iVar4 = FUN_00477980(*puVar7);
                  piVar5 = (int *)FUN_004ce990(3);
                  if (*piVar5 < iVar4) {
                    puVar7 = (undefined4 *)FUN_004ce990(3);
                    uVar15 = *puVar7;
                    puVar7 = (undefined4 *)FUN_004ce990(1);
                    FUN_004d0120(*puVar7);
                    piVar5 = (int *)FUN_004ce990(uVar15);
                    local_9c = *piVar5;
                    if ((local_9c / 1000 == 1) &&
                       ((piVar5 = (int *)FUN_004ce990(5), 999999 < *piVar5 ||
                        (puVar10 = (uint *)FUN_004ce990(4), (*puVar10 & 0xf000) != 0x100)))) {
                      FUN_004ce970(5);
                      iVar4 = local_9c % 1000;
                      piVar5 = (int *)FUN_004ce990(1);
                      *piVar5 = iVar4;
                      puVar10 = (uint *)FUN_004ce990(4);
                      uVar2 = *puVar10;
                      piVar5 = (int *)FUN_004ce990(2);
                      *piVar5 = (int)(uVar2 & 0xf0) >> 4;
                      puVar10 = (uint *)FUN_004ce990(4);
                      uVar2 = *puVar10;
                      piVar5 = (int *)FUN_004ce990(3);
                      *piVar5 = (int)(uVar2 & 0xf000) >> 0xc;
                      FUN_004ce970(4);
                      puVar7 = (undefined4 *)FUN_004ce990(0);
                      *puVar7 = local_84;
                      piVar5 = (int *)FUN_004ce990(2);
                      if (*piVar5 < 1000000) {
                        uVar15 = FUN_004ce990(2);
                        puVar7 = (undefined4 *)FUN_004ce990(1);
                        *puVar7 = uVar15;
                      }
                      else {
                        piVar5 = (int *)FUN_004ce990(1);
                        uVar15 = 0xffffffff;
                        iVar4 = local_18;
                        puVar7 = (undefined4 *)FUN_004ce990(2);
                        iVar4 = FUN_004369a0(*puVar7,iVar4,uVar15);
                        *piVar5 = iVar4;
                        if (*piVar5 == 0) {
                          FUN_004ce950();
                          goto switchD_00436e17_caseD_6c;
                        }
                      }
                      piVar5 = (int *)FUN_004ce990(5);
                      if (*piVar5 < 1000000) {
                        uVar15 = FUN_004ce990(5);
                        puVar7 = (undefined4 *)FUN_004ce990(2);
                        *puVar7 = uVar15;
                      }
                      else {
                        piVar5 = (int *)FUN_004ce990(2);
                        uVar15 = 0xffffffff;
                        iVar4 = local_18;
                        puVar7 = (undefined4 *)FUN_004ce990(5);
                        iVar4 = FUN_004369a0(*puVar7,iVar4,uVar15);
                        *piVar5 = iVar4;
                        if (*piVar5 == 0) {
                          FUN_004ce950();
                          goto switchD_00436e17_caseD_6c;
                        }
                      }
                      puVar7 = (undefined4 *)FUN_004ce990(3);
                      uVar15 = *puVar7;
                      puVar7 = (undefined4 *)FUN_004ce990(1);
                      FUN_004d05c0(*puVar7);
                      uVar15 = FUN_004ce990(uVar15);
                      puVar7 = (undefined4 *)FUN_004ce990(3);
                      *puVar7 = uVar15;
                      piVar5 = (int *)FUN_004ce990(3);
                      iVar4 = *piVar5;
                      piVar5 = (int *)FUN_004ce990(0);
                      *piVar5 = iVar4 + 0x3d0f4;
                      piVar5 = (int *)FUN_004ce990(2);
                      puVar7 = (undefined4 *)FUN_004ce990(1);
                      iVar4 = FUN_004717c0(*puVar7);
                      if ((*piVar5 < iVar4) &&
                         (puVar10 = (uint *)FUN_004ce990(4), (int)(*puVar10 & 0xf00) >> 8 != 0)) {
                        puVar7 = (undefined4 *)FUN_004ce990(4);
                        *puVar7 = 1;
                      }
                      puVar7 = (undefined4 *)FUN_004ce990(0);
                      *puVar7 = 1;
                    }
                  }
                }
              }
            }
          }
          else if (iVar4 == 0x191) {
            iVar4 = FUN_004ce080();
            if (0 < iVar4) goto LAB_00436d57;
            local_48 = local_1c;
            FUN_004ce950();
            FUN_004ce970(2);
            do {
              iVar4 = local_48 + 1;
              cVar3 = *(char *)(local_20 + 0x10);
              local_48 = iVar4;
              FUN_004cfb40(local_18);
              iVar4 = FUN_004ced20(iVar4);
            } while (cVar3 != *(char *)(iVar4 + 0x10));
            piVar5 = (int *)FUN_004ce990(1);
            *piVar5 = local_48;
            puVar7 = (undefined4 *)FUN_004ce990(0);
            *puVar7 = 1;
          }
          else if (iVar4 == 0x1a4) {
            iVar4 = FUN_004ce080();
            if (0 < iVar4) goto LAB_00436d57;
            local_4c = local_1c;
            FUN_004ce950();
            FUN_004ce970(2);
            do {
              iVar4 = local_4c + 1;
              cVar3 = *(char *)(local_20 + 0x10);
              local_4c = iVar4;
              FUN_004cfb40(local_18);
              iVar4 = FUN_004ced20(iVar4);
            } while (cVar3 != *(char *)(iVar4 + 0x10));
            piVar5 = (int *)FUN_004ce990(1);
            *piVar5 = local_4c;
            puVar7 = (undefined4 *)FUN_004ce990(0);
            *puVar7 = 1;
            puVar7 = (undefined4 *)FUN_004ce990(0);
            *puVar7 = 420000;
          }
          goto switchD_00436e17_caseD_6c;
        }
        if (iVar4 != 0xd5) {
          switch(iVar4) {
          case 0x6a:
          case 0x6b:
            if ((DAT_00a117a8 == 0) && (iVar4 = FUN_004cc430(), iVar4 != 0)) {
              uVar15 = 0;
              pcVar11 = "MessageBox:";
              FUN_004cc4c0(0);
              iVar4 = FUN_004cbbc0(pcVar11,uVar15);
              if (iVar4 != 0) {
                puVar7 = (undefined4 *)FUN_004ce990(0);
                *puVar7 = 0x67;
              }
            }
            break;
          case 0x6f:
switchD_00436e17_caseD_6f:
            FUN_004ce950();
            FUN_004ce970(9);
            puVar10 = (uint *)FUN_004ce990(1);
            uVar2 = *puVar10;
            puVar10 = (uint *)FUN_004ce990(1);
            *puVar10 = uVar2 & 0xf;
            piVar5 = (int *)FUN_004ce990(1);
            FUN_004ce970(*piVar5 << 1);
            local_40 = 0;
            while (piVar5 = (int *)FUN_004ce990(1), local_40 < *piVar5) {
              piVar5 = (int *)FUN_004ce990(local_40 * 3 + 2);
              if (1099999999 < *piVar5) {
LAB_0043707f:
                local_11 = '\x01';
                break;
              }
              piVar5 = (int *)FUN_004ce990(local_40 << 1);
              uVar15 = 0xffffffff;
              iVar4 = local_18;
              puVar7 = (undefined4 *)FUN_004ce990(local_40 * 3 + 2);
              iVar4 = FUN_004369a0(*puVar7,iVar4,uVar15);
              *piVar5 = iVar4;
              if (*piVar5 == 0) goto LAB_0043707f;
              puVar10 = (uint *)FUN_004ce990(local_40 * 3 + 4);
              if (((*puVar10 & 0x10) == 0) &&
                 (piVar5 = (int *)FUN_004ce990(local_40 * 3 + 3), 999999 < *piVar5)) {
                piVar5 = (int *)FUN_004ce990(local_40 * 2 + 1);
                uVar15 = 0xffffffff;
                iVar4 = local_18;
                puVar7 = (undefined4 *)FUN_004ce990(local_40 * 3 + 3);
                iVar4 = FUN_004369a0(*puVar7,iVar4,uVar15);
                *piVar5 = iVar4;
                if (*piVar5 == 0) {
                  local_11 = '\x01';
                  break;
                }
              }
              else {
                uVar15 = FUN_004ce990(local_40 * 3 + 3);
                puVar7 = (undefined4 *)FUN_004ce990(local_40 * 2 + 1);
                *puVar7 = uVar15;
              }
              puVar10 = (uint *)FUN_004ce990(local_40 * 3 + 4);
              uVar2 = *puVar10;
              puVar10 = (uint *)FUN_004ce990(local_40 + 2);
              *puVar10 = uVar2 & 0xf;
              local_40 = local_40 + 1;
            }
            if (local_11 != '\0') {
              FUN_004ce950();
              goto LAB_00436d57;
            }
            local_3c[0] = -1;
            local_3c[1] = 0xffffffff;
            local_3c[2] = 0xffffffff;
            local_3c[3] = 0xffffffff;
            local_3c[4] = 0xffffffff;
            local_3c[6] = local_1c;
            local_3c[5] = 0;
            do {
              while( true ) {
                while( true ) {
                  do {
                    iVar4 = local_3c[6] + 1;
                    cVar3 = *(char *)(local_20 + 0x10);
                    local_3c[6] = iVar4;
                    FUN_004cfb40(local_18);
                    iVar4 = FUN_004ced20(iVar4);
                  } while (cVar3 != *(char *)(iVar4 + 0x10));
                  uVar15 = 0;
                  iVar4 = local_3c[6];
                  FUN_004cfb40(local_18);
                  FUN_004ced20(iVar4);
                  piVar5 = (int *)FUN_004ce990(uVar15);
                  if (*piVar5 != 0x191) break;
                  local_3c[local_3c[5]] = local_3c[6];
                  piVar5 = (int *)FUN_004ce990(local_3c[5] + 5);
                  *piVar5 = local_3c[6];
                  local_3c[5] = local_3c[5] + 1;
                }
                uVar15 = 0;
                iVar4 = local_3c[6];
                FUN_004cfb40(local_18);
                FUN_004ced20(iVar4);
                piVar5 = (int *)FUN_004ce990(uVar15);
                if (*piVar5 != 0x1a4) break;
                local_3c[local_3c[5]] = local_3c[6];
                local_3c[5] = local_3c[5] + 1;
              }
              uVar15 = 0;
              iVar4 = local_3c[6];
              FUN_004cfb40(local_18);
              FUN_004ced20(iVar4);
              piVar5 = (int *)FUN_004ce990(uVar15);
            } while (*piVar5 != 499);
            for (local_44 = 0; local_44 < 5; local_44 = local_44 + 1) {
              if (local_3c[local_44] != -1) {
                uVar15 = 2;
                iVar4 = local_3c[local_44];
                FUN_004cfb40(local_18);
                FUN_004ced20(iVar4);
                FUN_004ce970(uVar15);
                uVar15 = 0;
                iVar4 = local_3c[local_44];
                FUN_004cfb40(local_18);
                FUN_004ced20(iVar4);
                puVar7 = (undefined4 *)FUN_004ce990(uVar15);
                *puVar7 = 2;
                uVar15 = 1;
                iVar4 = local_3c[local_44];
                FUN_004cfb40(local_18);
                FUN_004ced20(iVar4);
                piVar5 = (int *)FUN_004ce990(uVar15);
                *piVar5 = local_3c[6];
              }
            }
            local_3c[6] = local_1c;
            do {
              do {
                iVar4 = local_3c[6] + 1;
                cVar3 = *(char *)(local_20 + 0x10);
                local_3c[6] = iVar4;
                FUN_004cfb40(local_18);
                iVar4 = FUN_004ced20(iVar4);
              } while (cVar3 != *(char *)(iVar4 + 0x10));
              uVar15 = 0;
              iVar4 = local_3c[6];
              FUN_004cfb40(local_18);
              FUN_004ced20(iVar4);
              piVar5 = (int *)FUN_004ce990(uVar15);
              if (*piVar5 == 0x1a4) break;
              uVar15 = 0;
              iVar4 = local_3c[6];
              FUN_004cfb40(local_18);
              FUN_004ced20(iVar4);
              piVar5 = (int *)FUN_004ce990(uVar15);
            } while (*piVar5 != 499);
            piVar5 = (int *)FUN_004ce990(8);
            *piVar5 = local_3c[6];
            puVar7 = (undefined4 *)FUN_004ce990(0);
            *puVar7 = 1;
            piVar5 = (int *)FUN_004ce990(1);
            if (*piVar5 == 1) {
              piVar5 = (int *)FUN_004ce990(2);
              iVar4 = *piVar5;
              piVar5 = (int *)FUN_004ce990(0);
              *piVar5 = iVar4 + 0x1b198;
            }
            break;
          case 0x79:
            goto switchD_00436e17_caseD_79;
          }
          goto switchD_00436e17_caseD_6c;
        }
        FUN_004ce950();
        FUN_004ce970(3);
        uVar15 = 0;
        puVar12 = &DAT_007ce2dc;
        FUN_004cc4c0(0);
        iVar4 = FUN_004cbbc0(puVar12,uVar15);
        if (iVar4 == DAT_007d0624) {
          puVar7 = (undefined4 *)FUN_004ce990(1);
          *puVar7 = 0xffffffff;
          puVar7 = (undefined4 *)FUN_004ce990(2);
          *puVar7 = 0;
          local_54 = 0;
          local_50 = 0;
          local_68 = -1;
          FUN_004ce850();
          local_8 = 0;
          FUN_004ce850();
          local_8._0_1_ = 1;
          local_54 = 0;
          while( true ) {
            FUN_004cfb40(local_18);
            iVar4 = FUN_004cec90();
            if ((iVar4 <= local_54) || (local_50 == -100)) break;
            if (local_50 == -1) {
              if (local_54 == local_1c) {
                local_50 = -100;
              }
              else {
                piVar5 = (int *)FUN_004ce990(0);
                iVar4 = *piVar5;
                if (iVar4 < 499) {
                  if (iVar4 == 0x1f2) {
LAB_00437d5c:
                    pwVar9 = std::
                             basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>
                             ::back(local_78);
                    puVar7 = (undefined4 *)FUN_004ce060(local_d4);
                    FUN_004ce220(local_d8,*puVar7,pwVar9);
                    FUN_004ce1d0();
                  }
                  else if (iVar4 == 0xaa) {
                    local_b4 = *(char *)(local_20 + 0x10) * 10 + 1;
                    FUN_004ce160(&local_b4);
                    local_b8 = 0xffffffff;
                    puVar7 = &local_b8;
                    puVar8 = (undefined4 *)FUN_004ce060(local_bc);
                    FUN_004ce220(local_c0,*puVar8,puVar7);
                  }
                  else if (iVar4 == 0xb3) {
                    local_c4 = *(char *)(local_20 + 0x10) * 10;
                    FUN_004ce160(&local_c4);
                    local_c8 = 0xffffffff;
                    puVar7 = &local_c8;
                    puVar8 = (undefined4 *)FUN_004ce060(local_cc);
                    FUN_004ce220(local_d0,*puVar8,puVar7);
                  }
                }
                else if ((0x7994f < iVar4) && (iVar4 < 0x79952)) goto LAB_00437d5c;
              }
            }
            else if (local_50 == 0) {
              if (local_54 == local_1c) {
                local_50 = 1;
              }
              else {
                piVar5 = (int *)FUN_004ce990(0);
                iVar4 = *piVar5;
                if (iVar4 < 0xd5) {
                  if (iVar4 == 0xd4) {
                    uVar15 = FUN_004cc4c0(0);
                    uVar13 = 0;
                    iVar4 = local_1c;
                    FUN_004cfb40(local_18);
                    FUN_004ced20(iVar4);
                    uVar13 = FUN_004cc4c0(uVar13);
                    cVar3 = FUN_004ec8f0(uVar13,uVar15);
                    if (cVar3 != '\0') {
                      local_50 = -1;
                      local_68 = local_54;
                    }
                  }
                  else if (iVar4 == 0xaa) {
                    local_ac = *(char *)(local_20 + 0x10) * 10 + 1;
                    FUN_004ce160(&local_ac);
                  }
                  else if (iVar4 == 0xb3) {
                    local_b0 = *(char *)(local_20 + 0x10) * 10;
                    FUN_004ce160(&local_b0);
                  }
                }
                else if ((iVar4 == 0x1f2) || ((0x7994f < iVar4 && (iVar4 < 0x79952)))) {
                  FUN_004ce1d0();
                }
              }
            }
            else if (local_50 == 1) {
              piVar5 = (int *)FUN_004ce990(0);
              iVar4 = *piVar5;
              if (iVar4 < 0xd5) {
                if (iVar4 == 0xd4) {
                  uVar15 = FUN_004cc4c0(0);
                  uVar13 = 0;
                  iVar4 = local_1c;
                  FUN_004cfb40(local_18);
                  FUN_004ced20(iVar4);
                  uVar13 = FUN_004cc4c0(uVar13);
                  cVar3 = FUN_004ec8f0(uVar13,uVar15);
                  if (cVar3 != '\0') {
                    local_50 = -100;
                    local_68 = local_54;
                  }
                }
                else if (iVar4 == 0xaa) {
                  local_dc = *(char *)(local_20 + 0x10) * 10 + 1;
                  FUN_004ce160(&local_dc);
                  pwVar9 = std::
                           basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>
                           ::back(local_78);
                  FUN_004ce160(pwVar9);
                }
                else if (iVar4 == 0xb3) {
                  local_e0 = *(char *)(local_20 + 0x10) * 10;
                  FUN_004ce160(&local_e0);
                  pwVar9 = std::
                           basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>
                           ::back(local_78);
                  FUN_004ce160(pwVar9);
                }
              }
              else if ((iVar4 == 0x1f2) || ((0x7994f < iVar4 && (iVar4 < 0x79952)))) {
                FUN_004ce1d0();
                local_e4 = 0xffffffff;
                FUN_004ce160(&local_e4);
              }
            }
            local_54 = local_54 + 1;
          }
          if (local_68 == -1) {
            FUN_004ce950();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_004ce950();
            local_8 = 0xffffffff;
            FUN_004ce950();
          }
          else {
            local_7c = 0;
            while (iVar4 = FUN_004ce080(), local_7c < iVar4) {
              piVar5 = (int *)FUN_004ce990(2);
              *piVar5 = *piVar5 + 1;
              piVar5 = (int *)FUN_004ce990(local_7c);
              iVar4 = *piVar5 % 10;
              if (iVar4 == -1) {
                local_e8 = 0xffffffff;
                FUN_004ce160(&local_e8);
                local_ec = 0xffffffff;
                FUN_004ce160(&local_ec);
              }
              else if (iVar4 == 0) {
                piVar5 = (int *)FUN_004ce990(local_7c);
                local_f8[2] = *piVar5 / 10;
                FUN_004ce160(local_f8 + 2);
                local_f8[1] = 0;
                FUN_004ce160(local_f8 + 1);
              }
              else if (iVar4 == 1) {
                piVar5 = (int *)FUN_004ce990(local_7c);
                local_f8[0] = *piVar5 / 10;
                FUN_004ce160(local_f8);
                local_fc = 2000000000;
                FUN_004ce160(&local_fc);
              }
              local_7c = local_7c + 1;
            }
            piVar5 = (int *)FUN_004ce990(1);
            *piVar5 = local_68;
            puVar7 = (undefined4 *)FUN_004ce990(0);
            *puVar7 = 1;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_004ce950();
            local_8 = 0xffffffff;
            FUN_004ce950();
          }
          goto switchD_00436e17_caseD_6c;
        }
        FUN_004ce950();
      }
      else {
        if (iVar4 < 0x33468) {
          if (iVar4 < 0x33464) {
            if (iVar4 < 0x33454) {
              if (209999 < iVar4) goto LAB_004375d7;
              if ((0x1b197 < iVar4) && (iVar4 < 0x1b19e)) {
                puVar7 = (undefined4 *)FUN_004ce990(0);
                *puVar7 = 0x6f;
                goto switchD_00436e17_caseD_6f;
              }
            }
            else if ((0x33459 < iVar4) && (iVar4 < 0x3345e)) goto LAB_004375d7;
          }
          else {
LAB_004375d7:
            puVar7 = (undefined4 *)FUN_004ce990(0);
            *puVar7 = 0x79;
switchD_00436e17_caseD_79:
            FUN_004ce950();
            piVar5 = (int *)FUN_004ce990(1);
            if (((*piVar5 != 1100000000) &&
                (puVar10 = (uint *)FUN_004ce990(4), (*puVar10 & 0xff) == 0)) &&
               (puVar10 = (uint *)FUN_004ce990(4), (*puVar10 & 0x10000) == 0)) {
              puVar7 = (undefined4 *)FUN_004ce990(2);
              cVar3 = FUN_00438d40(*puVar7);
              if (cVar3 != '\0') {
                puVar7 = (undefined4 *)FUN_004ce990(3);
                cVar3 = FUN_00438d40(*puVar7);
                if (((cVar3 != '\0') && (piVar5 = (int *)FUN_004ce990(2), *piVar5 < 1000000000)) &&
                   (piVar5 = (int *)FUN_004ce990(3), *piVar5 < 1000000000)) {
                  FUN_004ce970(8);
                  FUN_004ce970(3);
                  piVar5 = (int *)FUN_004ce990(0);
                  uVar15 = 0xffffffff;
                  iVar4 = local_18;
                  puVar7 = (undefined4 *)FUN_004ce990(1);
                  iVar4 = FUN_004369a0(*puVar7,iVar4,uVar15);
                  *piVar5 = iVar4;
                  if (*piVar5 != 0) {
                    piVar5 = (int *)FUN_004ce990(2);
                    if (*piVar5 < 1000000) {
                      uVar15 = FUN_004ce990(2);
                      puVar7 = (undefined4 *)FUN_004ce990(1);
                      *puVar7 = uVar15;
                    }
                    else {
                      piVar5 = (int *)FUN_004ce990(1);
                      uVar15 = 0xffffffff;
                      iVar4 = local_18;
                      puVar7 = (undefined4 *)FUN_004ce990(2);
                      iVar4 = FUN_004369a0(*puVar7,iVar4,uVar15);
                      *piVar5 = iVar4;
                      if (*piVar5 == 0) goto switchD_00436e17_caseD_6c;
                    }
                    piVar5 = (int *)FUN_004ce990(3);
                    if (*piVar5 < 1000000) {
                      uVar15 = FUN_004ce990(3);
                      puVar7 = (undefined4 *)FUN_004ce990(2);
                      *puVar7 = uVar15;
                    }
                    else {
                      piVar5 = (int *)FUN_004ce990(2);
                      uVar15 = 0xffffffff;
                      iVar4 = local_18;
                      puVar7 = (undefined4 *)FUN_004ce990(3);
                      iVar4 = FUN_004369a0(*puVar7,iVar4,uVar15);
                      *piVar5 = iVar4;
                      if (*piVar5 == 0) goto switchD_00436e17_caseD_6c;
                    }
                    puVar10 = (uint *)FUN_004ce990(4);
                    uVar2 = *puVar10;
                    piVar5 = (int *)FUN_004ce990(1);
                    *piVar5 = (int)(uVar2 & 0xf00) >> 8;
                    puVar10 = (uint *)FUN_004ce990(4);
                    uVar2 = *puVar10;
                    piVar5 = (int *)FUN_004ce990(2);
                    *piVar5 = (int)(uVar2 & 0xf000) >> 0xc;
                    puVar7 = (undefined4 *)FUN_004ce990(0);
                    *puVar7 = 1;
                    piVar5 = (int *)FUN_004ce990(2);
                    if (((*piVar5 == 0) || (piVar5 = (int *)FUN_004ce990(2), *piVar5 == 1)) &&
                       (piVar5 = (int *)FUN_004ce990(3), *piVar5 == 0)) {
                      puVar7 = (undefined4 *)FUN_004ce990(0);
                      *puVar7 = 2;
                    }
                    piVar5 = (int *)FUN_004ce990(1);
                    if ((*piVar5 < 4) && (piVar5 = (int *)FUN_004ce990(2), *piVar5 < 3)) {
                      piVar5 = (int *)FUN_004ce990(1);
                      iVar4 = *piVar5;
                      piVar5 = (int *)FUN_004ce990(2);
                      iVar1 = *piVar5;
                      piVar5 = (int *)FUN_004ce990(0);
                      *piVar5 = iVar4 * 10 + 210000 + iVar1;
                    }
                    else {
                      piVar5 = (int *)FUN_004ce990(1);
                      if ((*piVar5 == 4) &&
                         ((piVar5 = (int *)FUN_004ce990(2), *piVar5 < 1000000 &&
                          (piVar5 = (int *)FUN_004ce990(3), *piVar5 < 1000000)))) {
                        piVar5 = (int *)FUN_004ce990(2);
                        if (*piVar5 == 0) {
                          piVar5 = (int *)FUN_004ce990(2);
                          piVar6 = (int *)FUN_004ce990(3);
                          if (*piVar5 + *piVar6 == 0) goto LAB_0043797e;
LAB_004379ac:
                          piVar5 = (int *)FUN_004ce990(1);
                          iVar4 = *piVar5;
                          piVar5 = (int *)FUN_004ce990(2);
                          iVar1 = *piVar5;
                          piVar5 = (int *)FUN_004ce990(0);
                          *piVar5 = iVar4 * 10 + 210000 + iVar1;
                        }
                        else {
LAB_0043797e:
                          piVar5 = (int *)FUN_004ce990(2);
                          if (*piVar5 == 1) {
                            piVar5 = (int *)FUN_004ce990(2);
                            piVar6 = (int *)FUN_004ce990(3);
                            if (*piVar5 != *piVar6) goto LAB_004379ac;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (iVar4 < 0x3347c) {
          if ((0x33477 < iVar4) || ((0x3346d < iVar4 && (iVar4 < 0x33472)))) goto LAB_004375d7;
        }
        else if ((0x7994f < iVar4) && (iVar4 < 0x79952)) goto LAB_00438a87;
switchD_00436e17_caseD_6c:
      }
LAB_00436d57:
      local_1c = local_1c + 1;
    }
    local_18 = local_18 + 1;
  } while( true );
}

