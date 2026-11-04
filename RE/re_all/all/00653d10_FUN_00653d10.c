
undefined4 FUN_00653d10(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int *piVar4;
  uint *puVar5;
  ushort *puVar6;
  int iVar7;
  uint uVar8;
  undefined2 *puVar9;
  undefined4 uVar10;
  char *pcVar11;
  int iVar12;
  ushort *puVar13;
  undefined2 extraout_var;
  uint uVar14;
  ushort uVar15;
  uint uVar16;
  ushort *puVar17;
  ushort uVar18;
  bool bVar19;
  undefined8 uVar20;
  int local_18;
  uint uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  ushort *puStack_8;
  uint uStack_4;
  
  puVar6 = param_1;
  local_18 = -1;
  puVar17 = param_1 + 0xc;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 10) = *(undefined4 *)(param_1 + 0xe);
  iVar7 = FUN_00655f20(param_1,*(undefined4 *)puVar17,*(undefined4 *)(param_1 + 0xe));
  if (iVar7 == 0) {
    return 0;
  }
  (**(code **)(puVar6 + 0x11a))(puVar6);
  puVar6[0xe0] = puVar6[0xe0] + 1;
  uVar10 = *(undefined4 *)(puVar6 + 0xe);
  uVar3 = *(undefined4 *)puVar17;
  uVar8 = FUN_00655fd0(puVar6,uVar3,uVar10,&param_1,puVar17);
  uVar18 = (ushort)uVar8;
  if (uVar18 == 0) {
    FUN_006512e0(*(undefined4 *)(puVar6 + 0x13a),"TIFFReadDirectory",
                 s_Failed_to_read_directory_at_offs_00a09fcc,uVar3,uVar10);
    return 0;
  }
  FUN_00655b40(puVar6,param_1,uVar8);
  if (uVar18 != 0) {
    puVar17 = param_1;
    uVar15 = 1;
    do {
      puStack_8 = puVar17 + 0xc;
      if (uVar15 < uVar18) {
        iVar7 = (uVar8 & 0xffff) - (uint)uVar15;
        puVar13 = puStack_8;
        do {
          if (*puVar17 == *puVar13) {
            *puVar13 = 0;
          }
          puVar13 = puVar13 + 0xc;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      bVar19 = uVar15 < uVar18;
      puVar17 = puStack_8;
      uVar15 = uVar15 + 1;
    } while (bVar19);
  }
  *(uint *)(puVar6 + 6) = *(uint *)(puVar6 + 6) & 0xffefffbf;
  FUN_0064e340(puVar6);
  FUN_0064e540(puVar6);
  FUN_0064e1d0(puVar6,0x11c,1);
  puVar9 = (undefined2 *)FUN_00655b90(puVar6,param_1,uVar8,0x115);
  if (puVar9 != (undefined2 *)0x0) {
    iVar7 = FUN_00656680(puVar6,puVar9,0);
    if (iVar7 == 0) goto LAB_006548c7;
    *puVar9 = 0;
  }
  puVar9 = (undefined2 *)FUN_00655b90(puVar6,param_1,uVar8,0x103);
  if (puVar9 == (undefined2 *)0x0) {
    iVar7 = FUN_0064e1d0(puVar6,0x103,1);
    if (iVar7 == 0) goto LAB_006548c7;
  }
  else {
    iVar7 = FUN_00654a90(puVar6,puVar9,&uStack_14);
    if (iVar7 == 1) {
      iVar7 = FUN_006556b0(puVar6,puVar9,&uStack_14);
    }
    if (iVar7 != 0) {
      FUN_00655980(puVar6,iVar7,"TIFFReadDirectory",s_Compression_00a0636c,0);
      goto LAB_006548c7;
    }
    iVar7 = FUN_0064e1d0(puVar6,0x103,uStack_14 & 0xffff);
    if (iVar7 == 0) goto LAB_006548c7;
    *puVar9 = 0;
  }
  uVar15 = 0;
  puVar17 = param_1;
  if (uVar18 != 0) {
    do {
      if ((*puVar17 != 0) && (FUN_00655bc0(puVar6,*puVar17,&local_18), local_18 == -1)) {
        FUN_00653460(*(undefined4 *)(puVar6 + 0x13a),"TIFFReadDirectory",
                     s_Unknown_field_with_tag__d__0x_x__00a09f9c,*puVar17,*puVar17);
        uVar10 = FUN_00653860(puVar6,*puVar17,puVar17[1],1);
        iVar7 = FUN_00653570(puVar6,uVar10);
        if (iVar7 == 0) {
          FUN_00653460(*(undefined4 *)(puVar6 + 0x13a),"TIFFReadDirectory",
                       s_Registering_anonymous_field_with_00a09f64,*puVar17,*puVar17);
          *puVar17 = 0;
        }
        else {
          FUN_00655bc0(puVar6,CONCAT22(extraout_var,*puVar17),&local_18);
        }
      }
      uVar1 = *puVar17;
      if (uVar1 == 0) goto switchD_00653fef_caseD_102;
      uVar2 = *(ushort *)(*(int *)(*(int *)(puVar6 + 0x148) + local_18 * 4) + 0x18);
      if (uVar2 == 0) {
LAB_00654055:
        *puVar17 = 0;
      }
      else {
        uVar14 = (uint)uVar1;
        if (0x11c < uVar14) {
          if (uVar14 < 0x153) {
            if (uVar14 != 0x152) {
              switch(uVar14 - 0x142) {
              case 0:
              case 1:
                break;
              case 2:
              case 3:
                goto switchD_00653fef_caseD_111;
              default:
                goto switchD_00653fef_caseD_102;
              }
            }
          }
          else if ((uVar14 < 0x80e5) || (0x80e6 < uVar14)) goto switchD_00653fef_caseD_102;
switchD_00653fef_caseD_100:
          iVar7 = FUN_00656680(puVar6,puVar17,0);
          if (iVar7 != 0) goto LAB_00654055;
          goto LAB_006548c7;
        }
        if (uVar14 == 0x11c) goto switchD_00653fef_caseD_100;
        switch(uVar1) {
        case 0x100:
        case 0x101:
        case 0x116:
          goto switchD_00653fef_caseD_100;
        case 0x111:
        case 0x117:
switchD_00653fef_caseD_111:
          *(uint *)(puVar6 + (uint)(uVar2 >> 5) * 2 + 0x14) =
               *(uint *)(puVar6 + (uint)(uVar2 >> 5) * 2 + 0x14) | 1 << ((byte)uVar2 & 0x1f);
        }
      }
switchD_00653fef_caseD_102:
      uVar15 = uVar15 + 1;
      puVar17 = puVar17 + 0xc;
    } while (uVar15 < uVar18);
  }
  if ((puVar6[0x2c] == 6) && (puVar6[0x3f] == 2)) {
    iVar7 = FUN_0065f680(puVar6);
    if (iVar7 == 0) goto LAB_006548c7;
    iVar7 = FUN_00655b90(puVar6,param_1,uVar8,0x111);
    if ((((iVar7 != 0) && (*(int *)(iVar7 + 8) == 1)) && (*(int *)(iVar7 + 0xc) == 0)) &&
       (((iVar7 = FUN_00655b90(puVar6,param_1,uVar8,0x117), iVar7 != 0 && (*(int *)(iVar7 + 8) == 1)
         ) && (*(int *)(iVar7 + 0xc) == 0)))) {
      puVar6[0x3f] = 1;
      FUN_00653460(*(undefined4 *)(puVar6 + 0x13a),"TIFFReadDirectory",
                   s_Planarconfig_tag_value_assumed_i_00a09f10);
    }
  }
  if ((*(uint *)(puVar6 + 0x14) & 2) == 0) {
    FUN_00655ef0(puVar6,s_ImageLength_00a09a40);
    goto LAB_006548c7;
  }
  if ((*(uint *)(puVar6 + 0x14) & 4) == 0) {
    uVar10 = FUN_00652780();
    *(undefined4 *)(puVar6 + 0x54) = uVar10;
    *(undefined4 *)(puVar6 + 0x22) = *(undefined4 *)(puVar6 + 0x1c);
    *(undefined4 *)(puVar6 + 0x24) = *(undefined4 *)(puVar6 + 0x32);
    *(undefined4 *)(puVar6 + 0x26) = *(undefined4 *)(puVar6 + 0x20);
    uVar14 = *(uint *)(puVar6 + 6) & 0xfffffbff;
  }
  else {
    uVar10 = FUN_006514d0(puVar6);
    *(undefined4 *)(puVar6 + 0x54) = uVar10;
    uVar14 = *(uint *)(puVar6 + 6) | 0x400;
  }
  uVar16 = *(uint *)(puVar6 + 0x54);
  *(uint *)(puVar6 + 6) = uVar14;
  if (uVar16 == 0) {
    pcVar11 = s_tiles_00a09f08;
    if ((uVar14 & 0x400) == 0) {
      pcVar11 = s_strips_00a09f00;
    }
    FUN_006512e0(*(undefined4 *)(puVar6 + 0x13a),"TIFFReadDirectory",
                 s_Cannot_handle_zero_number_of__s_00a09ee0,pcVar11);
    goto LAB_006548c7;
  }
  *(uint *)(puVar6 + 0x52) = uVar16;
  if (puVar6[0x3f] == 2) {
    *(uint *)(puVar6 + 0x52) = uVar16 / puVar6[0x31];
  }
  if ((*(uint *)(puVar6 + 0x14) & 0x2000000) == 0) {
    if (((puVar6[0x2c] != 6) || ((*(uint *)(puVar6 + 6) & 0x400) != 0)) || (uVar16 != 1)) {
      pcVar11 = s_TileOffsets_00a097d4;
      if ((*(uint *)(puVar6 + 6) & 0x400) == 0) {
        pcVar11 = s_StripOffsets_00a0999c;
      }
      FUN_00655ef0(puVar6,pcVar11);
      goto LAB_006548c7;
    }
    *(uint *)(puVar6 + 0x14) = *(uint *)(puVar6 + 0x14) | 0x2000000;
  }
  puStack_8 = (ushort *)0x0;
  puVar17 = param_1;
  if (uVar18 != 0) {
    do {
      uVar15 = *puVar17;
      if (uVar15 < 0x12e) {
        if (uVar15 == 0x12d) {
LAB_00654336:
          iVar7 = 1 << ((byte)puVar6[0x2a] & 0x1f);
          uStack_14 = 0;
          if (((uVar15 == 0x12d) && (*(int *)(puVar17 + 4) == iVar7)) &&
             (*(int *)(puVar17 + 6) == 0)) {
            iVar12 = iVar7;
            iVar7 = 0;
          }
          else {
            iVar12 = iVar7 * 3;
          }
          if ((*(int *)(puVar17 + 4) == iVar12) && (*(int *)(puVar17 + 6) == 0)) {
            iVar12 = FUN_00654cb0(puVar6,puVar17,&uStack_14);
            if (iVar12 == 0) {
              FUN_0064e1d0(puVar6,*puVar17,uStack_14,uStack_14 + iVar7 * 2,uStack_14 + iVar7 * 4);
              FUN_006507e0(uStack_14);
              goto LAB_006542c8;
            }
          }
          else {
            iVar12 = 1;
          }
          iVar7 = FUN_00653820(puVar6,*puVar17);
          if (iVar7 == 0) {
            pcVar11 = s_unknown_tagname_00a09ed0;
          }
          else {
            pcVar11 = *(char **)(iVar7 + 0x1c);
          }
          FUN_00655980(puVar6,iVar12,"TIFFReadDirectory",pcVar11,1);
        }
        else {
          if (uVar15 < 0x112) {
            if (uVar15 != 0x111) {
              if (uVar15 != 0) {
                if (uVar15 != 0xff) {
                  if (uVar15 == 0x102) goto LAB_00654412;
                  goto LAB_006542bc;
                }
                iVar7 = FUN_00654a90(puVar6,puVar17,&uStack_4);
                if (iVar7 == 0) {
                  if ((uStack_4 & 0xffff) == 2) {
                    FUN_0064e1d0(puVar6,0xfe,1);
                  }
                  else if ((uStack_4 & 0xffff) == 3) {
                    FUN_0064e1d0(puVar6,0xfe,2);
                  }
                }
              }
              goto LAB_006542c8;
            }
LAB_00654326:
            uVar10 = *(undefined4 *)(puVar6 + 0x54);
            puVar13 = puVar6 + 0x56;
          }
          else {
            if (uVar15 != 0x117) {
              if ((0x117 < uVar15) && (uVar15 < 0x11a)) goto LAB_00654412;
              goto LAB_006542bc;
            }
LAB_00654304:
            uVar10 = *(undefined4 *)(puVar6 + 0x54);
            puVar13 = puVar6 + 0x58;
          }
          iVar7 = FUN_0065a290(puVar6,puVar17,uVar10,puVar13);
LAB_0065431e:
          if (iVar7 == 0) goto LAB_006548c7;
        }
      }
      else {
        if (uVar15 < 0x154) {
          if (uVar15 == 0x153) {
LAB_00654412:
            iVar7 = FUN_00654a90(puVar6,puVar17,&uStack_10);
            if (iVar7 == 1) {
              iVar7 = FUN_006556b0(puVar6,puVar17,&uStack_10);
            }
            if (iVar7 == 0) {
              iVar7 = FUN_0064e1d0(puVar6,*puVar17,uStack_10 & 0xffff);
              goto LAB_0065431e;
            }
            iVar12 = FUN_00653820(puVar6,*puVar17);
            if (iVar12 == 0) {
              pcVar11 = s_unknown_tagname_00a09ed0;
            }
            else {
              pcVar11 = *(char **)(iVar12 + 0x1c);
            }
            FUN_00655980(puVar6,iVar7,"TIFFReadDirectory",pcVar11,0);
            goto LAB_006548c7;
          }
          if (uVar15 == 0x140) goto LAB_00654336;
          if (uVar15 == 0x144) goto LAB_00654326;
          if (uVar15 == 0x145) goto LAB_00654304;
        }
        else if (0x153 < uVar15) {
          if (uVar15 < 0x156) {
            if ((*(uint *)(puVar17 + 4) == (uint)puVar6[0x31]) && (*(int *)(puVar17 + 6) == 0)) {
              iVar7 = FUN_006551f0(puVar6,puVar17,&uStack_c);
              if (iVar7 == 0) {
                uVar14 = *(uint *)(puVar6 + 6);
                *(uint *)(puVar6 + 6) = uVar14 | 0x400000;
                iVar7 = FUN_0064e1d0(puVar6,*puVar17,uStack_c);
                *(uint *)(puVar6 + 6) = uVar14;
                FUN_006507e0(uStack_c);
                goto LAB_0065431e;
              }
            }
            else {
              iVar7 = 1;
            }
            iVar12 = FUN_00653820(puVar6,*puVar17);
            if (iVar12 == 0) {
              pcVar11 = s_unknown_tagname_00a09ed0;
            }
            else {
              pcVar11 = *(char **)(iVar12 + 0x1c);
            }
            FUN_00655980(puVar6,iVar7,"TIFFReadDirectory",pcVar11,0);
            goto LAB_006548c7;
          }
          if (uVar15 == 0x80e4) goto LAB_00654412;
        }
LAB_006542bc:
        FUN_00656680(puVar6,puVar17,1);
      }
LAB_006542c8:
      puVar17 = puVar17 + 0xc;
      puStack_8 = (ushort *)((int)puStack_8 + 1);
    } while ((ushort)puStack_8 < uVar18);
  }
  if (puVar6[0x2c] == 6) {
    if ((*(uint *)(puVar6 + 0x14) & 0x100) == 0) {
      FUN_00653460(*(undefined4 *)(puVar6 + 0x13a),"TIFFReadDirectory",
                   s_Photometric_tag_is_missing__assu_00a09e9c);
      iVar7 = FUN_0064e1d0(puVar6,0x106,6);
      if (iVar7 == 0) goto LAB_006548c7;
    }
    else if (puVar6[0x2d] == 2) {
      puVar6[0x2d] = 6;
      FUN_00653460(*(undefined4 *)(puVar6 + 0x13a),"TIFFReadDirectory",
                   s_Photometric_tag_value_assumed_in_00a09e4c);
    }
    if ((puVar6[0x14] & 0x40) == 0) {
      FUN_00653460(*(undefined4 *)(puVar6 + 0x13a),"TIFFReadDirectory",
                   s_BitsPerSample_tag_is_missing__as_00a09e10);
      iVar7 = FUN_0064e1d0(puVar6,0x102,8);
      if (iVar7 == 0) goto LAB_006548c7;
    }
    if ((*(uint *)(puVar6 + 0x14) & 0x10000) == 0) {
      if (puVar6[0x2d] == 2) {
        FUN_00653460(*(undefined4 *)(puVar6 + 0x13a),"TIFFReadDirectory",
                     s_SamplesPerPixel_tag_is_missing__a_00a09dc4);
        iVar7 = FUN_0064e1d0(puVar6,0x115,3);
        if (iVar7 == 0) goto LAB_006548c7;
      }
      uVar18 = puVar6[0x2d];
      if (uVar18 == 6) {
        FUN_00653460(*(undefined4 *)(puVar6 + 0x13a),"TIFFReadDirectory",
                     s_SamplesPerPixel_tag_is_missing__a_00a09d78);
        iVar7 = FUN_0064e1d0(puVar6,0x115,3);
      }
      else {
        if ((uVar18 != 0) && (uVar18 != 1)) goto LAB_0065466c;
        iVar7 = FUN_0064e1d0(puVar6,0x115,1);
      }
      if (iVar7 == 0) goto LAB_006548c7;
    }
  }
LAB_0065466c:
  if ((puVar6[0x2d] == 3) && ((*(uint *)(puVar6 + 0x14) & 0x4000000) == 0)) {
    if (puVar6[0x2a] < 8) {
LAB_006546fe:
      FUN_00655ef0(puVar6,s_Colormap_00a09d6c);
      goto LAB_006548c7;
    }
    if (puVar6[0x31] == 3) {
      puVar6[0x2d] = 2;
    }
    else {
      if (puVar6[0x2a] < 8) goto LAB_006546fe;
      puVar6[0x2d] = 1;
    }
  }
  if (puVar6[0x2c] == 6) goto LAB_00654823;
  if ((*(uint *)(puVar6 + 0x14) & 0x1000000) == 0) {
    if (((puVar6[0x3f] == 1) && (1 < *(uint *)(puVar6 + 0x54))) ||
       ((puVar6[0x3f] == 2 && (*(uint *)(puVar6 + 0x54) != (uint)puVar6[0x31])))) {
      FUN_00655ef0(puVar6,s_StripByteCounts_00a09960);
      goto LAB_006548c7;
    }
    FUN_00653460(*(undefined4 *)(puVar6 + 0x13a),"TIFFReadDirectory",
                 s_TIFF_directory_is_missing_requir_00a09d10);
LAB_0065480d:
    iVar7 = FUN_00655c50(puVar6,param_1,uVar8);
  }
  else {
    if (((*(int *)(puVar6 + 0x54) == 1) && (iVar7 = FUN_0065f680(puVar6), iVar7 != 0)) &&
       (**(int **)(puVar6 + 0x56) != 0 || (*(int **)(puVar6 + 0x56))[1] != 0)) {
      if (**(int **)(puVar6 + 0x58) == 0 && (*(int **)(puVar6 + 0x58))[1] == 0) {
LAB_006547ed:
        FUN_00653460(*(undefined4 *)(puVar6 + 0x13a),"TIFFReadDirectory",
                     s_Bogus__StripByteCounts__field__i_00a09cc4);
        goto LAB_0065480d;
      }
      if (puVar6[0x2c] == 1) {
        uVar20 = (**(code **)(puVar6 + 0x144))(*(undefined4 *)(puVar6 + 0x13a));
        puVar5 = *(uint **)(puVar6 + 0x56);
        uVar16 = ((int)((ulonglong)uVar20 >> 0x20) - puVar5[1]) - (uint)((uint)uVar20 < *puVar5);
        uVar14 = (*(uint **)(puVar6 + 0x58))[1];
        if ((uVar16 < uVar14) ||
           ((uVar16 <= uVar14 && ((uint)uVar20 - *puVar5 < **(uint **)(puVar6 + 0x58)))))
        goto LAB_006547ed;
      }
      if ((*(int *)(puVar6 + 4) == 0) && (puVar6[0x2c] == 1)) {
        uVar20 = FUN_00652ae0(puVar6);
        uVar20 = __allmul(uVar20,*(undefined4 *)(puVar6 + 0x1e),0);
        uVar16 = (uint)((ulonglong)uVar20 >> 0x20);
        uVar14 = (*(uint **)(puVar6 + 0x58))[1];
        if ((uVar14 <= uVar16) && ((uVar14 < uVar16 || (**(uint **)(puVar6 + 0x58) < (uint)uVar20)))
           ) goto LAB_006547ed;
      }
    }
    if (((puVar6[0x3f] != 1) || (*(uint *)(puVar6 + 0x54) < 3)) || (puVar6[0x2c] != 1))
    goto LAB_00654823;
    piVar4 = *(int **)(puVar6 + 0x58);
    if (((*piVar4 == piVar4[2]) && (piVar4[1] == piVar4[3])) ||
       ((*piVar4 == 0 && piVar4[1] == 0 || (piVar4[2] == 0 && piVar4[3] == 0)))) goto LAB_00654823;
    FUN_00653460(*(undefined4 *)(puVar6 + 0x13a),"TIFFReadDirectory",
                 s_Wrong__StripByteCounts__field__i_00a09c78);
    iVar7 = FUN_00655c50(puVar6,param_1,uVar8);
  }
  if (iVar7 < 0) {
LAB_006548c7:
    if (param_1 != (ushort *)0x0) {
      FUN_006507e0(param_1);
    }
    return 0;
  }
LAB_00654823:
  if (param_1 != (ushort *)0x0) {
    FUN_006507e0(param_1);
    param_1 = (ushort *)0x0;
  }
  if ((*(uint *)(puVar6 + 0x14) & 0x80000) == 0) {
    if (puVar6[0x2a] < 0x10) {
      puVar6[0x35] = (short)(1 << ((byte)puVar6[0x2a] & 0x1f)) - 1;
    }
    else {
      puVar6[0x35] = 0xffff;
    }
  }
  uVar8 = *(uint *)(puVar6 + 0x54);
  if (1 < uVar8) {
    puVar5 = *(uint **)(puVar6 + 0x56);
    puVar6[0x5a] = 1;
    puVar6[0x5b] = 0;
    uVar14 = 1;
    do {
      if ((puVar5[3] < puVar5[1]) || ((puVar5[3] <= puVar5[1] && (puVar5[2] < *puVar5)))) {
        puVar6[0x5a] = 0;
        puVar6[0x5b] = 0;
        break;
      }
      uVar14 = uVar14 + 1;
      puVar5 = puVar5 + 2;
    } while (uVar14 < uVar8);
  }
  (**(code **)(puVar6 + 0xfc))(puVar6);
  if ((((puVar6[0x3f] == 1) && (*(int *)(puVar6 + 0x54) == 1)) && (puVar6[0x2c] == 1)) &&
     ((*(uint *)(puVar6 + 6) & 0x8400) == 0x8000)) {
    iVar7 = FUN_0065f680(puVar6);
    if (iVar7 == 0) {
      return 0;
    }
    if (*(int *)(puVar6 + 0x58) == 0) {
      return 0;
    }
    FUN_0065a3d0(puVar6);
  }
  *(uint *)(puVar6 + 6) = *(uint *)(puVar6 + 6) & 0xffdffff7;
  puVar6[0xde] = 0xffff;
  puVar6[0xdf] = 0xffff;
  puVar6[0xe2] = 0xffff;
  puVar6[0xe3] = 0xffff;
  puVar6[0xf4] = 0xffff;
  puVar6[0xf5] = 0xffff;
  puVar6[0xf6] = 0xffff;
  puVar6[0xf7] = 0xffff;
  puVar6[0xf8] = 0xffff;
  puVar6[0xf9] = 0xffff;
  iVar7 = FUN_00652c80(puVar6);
  *(int *)(puVar6 + 0x122) = iVar7;
  if (iVar7 == 0) {
    FUN_006512e0(*(undefined4 *)(puVar6 + 0x13a),"TIFFReadDirectory",
                 s_Cannot_handle_zero_scanline_size_00a09c54);
    return 0;
  }
  if ((*(uint *)(puVar6 + 6) & 0x400) == 0) {
    iVar7 = FUN_00652a30(puVar6);
    if (iVar7 == 0) {
      FUN_006512e0(*(undefined4 *)(puVar6 + 0x13a),"TIFFReadDirectory",
                   s_Cannot_handle_zero_strip_size_00a09c14);
      return 0;
    }
  }
  else {
    iVar7 = FUN_00651870();
    *(int *)(puVar6 + 0xf8) = iVar7;
    if (iVar7 == 0) {
      FUN_006512e0(*(undefined4 *)(puVar6 + 0x13a),"TIFFReadDirectory",
                   s_Cannot_handle_zero_tile_size_00a09c34);
      return 0;
    }
  }
  return 1;
}

