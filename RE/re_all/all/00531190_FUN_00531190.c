
undefined4
FUN_00531190(int param_1,uint *param_2,uint param_3,int param_4,int param_5,char *param_6,
            int param_7,int param_8,uint param_9,int param_10,uint param_11,int param_12,
            int param_13)

{
  byte *pbVar1;
  undefined4 *puVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  byte bVar12;
  short sVar13;
  uint uVar14;
  int iVar15;
  undefined2 *puVar16;
  short *psVar17;
  ushort *puVar18;
  ushort *puVar19;
  int *piVar20;
  int *piVar21;
  int iVar22;
  byte bVar23;
  uint uVar24;
  uint uVar25;
  char *pcVar26;
  byte *pbVar27;
  int iVar28;
  int iVar29;
  undefined2 *puVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  byte bVar34;
  ushort uVar35;
  int iVar36;
  byte bVar37;
  uint uVar38;
  ushort uVar39;
  char *pcVar40;
  uint *puVar41;
  int iVar42;
  ushort uVar43;
  uint uVar44;
  byte *pbVar45;
  char *pcVar46;
  int iVar47;
  int iVar48;
  bool bVar49;
  uint *local_80;
  byte local_79;
  char *local_6c;
  char *local_60;
  uint local_5c;
  uint local_58;
  byte *local_54;
  byte *local_50;
  ushort *local_48;
  int local_44;
  char *local_3c;
  int local_34;
  uint local_30;
  char *local_28;
  char *local_24;
  int local_20;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if ((char)param_2[1] != '\0') {
    if ((undefined4 *)param_2[7] == (undefined4 *)0x0) {
      piVar21 = (int *)(param_1 + 0x8fd84);
      iVar22 = 0;
      if ((uint *)*piVar21 != param_2) {
        do {
          piVar21 = piVar21 + 1;
          iVar22 = iVar22 + 1;
        } while ((uint *)*piVar21 != param_2);
      }
      *(int *)(param_1 + 0x8fd80) = *(int *)(param_1 + 0x8fd80) + -1;
      iVar33 = *(int *)(param_1 + 0x8fd80) - iVar22;
      if (0 < iVar33) {
        FUN_0056d460(param_1 + 0x8fd84 + iVar22 * 4,param_1 + 0x8fd88 + iVar22 * 4,iVar33 * 4);
      }
    }
    else {
      *(undefined4 *)param_2[7] = 0;
      *(undefined4 *)(param_2[7] + 4) = 0;
    }
    *(undefined1 *)(param_2 + 1) = 0;
  }
  if (param_5 == 1) {
    uVar44 = 4;
  }
  else if (param_5 == 2) {
    uVar44 = 8;
  }
  else if (param_5 == 3) {
    uVar44 = 0x10;
  }
  else {
    uVar44 = 1;
  }
  *param_2 = param_3;
  if (param_4 != 0) {
    *(undefined2 *)((int)param_2 + 6) = 0;
    *(undefined2 *)(param_2 + 2) = 0;
    *(undefined2 *)(param_2 + 3) = 0;
    *(undefined2 *)((int)param_2 + 0xe) = 0;
    sVar13 = (short)(((uVar44 >> 2) + param_12) / uVar44);
    *(short *)((int)param_2 + 10) = sVar13;
    if ((*(byte *)(param_1 + 0x93184) & 1) != 0) {
      *(short *)((int)param_2 + 10) = *(short *)(param_1 + 0x93188) * 2 + sVar13;
    }
    goto LAB_005361b2;
  }
  if (param_6 == (char *)0x0) {
    *(undefined2 *)((int)param_2 + 6) = 0;
    *(undefined2 *)(param_2 + 2) = 0;
    *(undefined2 *)((int)param_2 + 10) = 0;
    *(undefined2 *)(param_2 + 3) = 0;
    *(undefined2 *)((int)param_2 + 0xe) = 0;
    goto LAB_005361b2;
  }
  *(short *)((int)param_2 + 6) = (short)((param_10 + (uVar44 >> 2)) / uVar44);
  *(short *)(param_2 + 3) = (short)(((uVar44 - 1) + param_7) / uVar44);
  *(short *)((int)param_2 + 10) = (short)((param_12 + (uVar44 >> 2)) / uVar44);
  uVar24 = param_8 + param_11 % uVar44;
  *(short *)(param_2 + 2) = (short)(param_11 / uVar44);
  *(short *)((int)param_2 + 0xe) = (short)(((uVar24 - 1) + uVar44) / uVar44);
  uVar25 = *(uint *)(param_1 + 0x93184) & 1;
  if (uVar25 == 0) {
    iVar22 = 0;
    local_34 = 0;
  }
  else {
    iVar22 = *(int *)(param_1 + 0x93188);
    local_34 = iVar22 * 2;
  }
  uVar14 = (uint)*(ushort *)(param_1 + 0x9316a);
  local_20 = param_2[5] * uVar14;
  local_14 = param_2[6] * uVar14;
  if (*(int *)(param_1 + 0x93628) == 0) {
    FUN_0056d380(*(int *)(param_1 + 0x90d90) * local_14 + *(int *)(param_1 + 0x90d8c),0,
                 *(int *)(param_1 + 0x90d90) * uVar14);
  }
  else if (((*(char *)(param_1 + 0x931c1) == '\b') || (*(int *)(param_1 + 0x93600) != 0)) ||
          (uVar25 != 0)) {
    FUN_00542200(param_1 + 0x931bc,local_20,local_14,uVar14,uVar14);
    if ((*(byte *)(param_1 + 0x93184) & 1) != 0) {
      FUN_00542200(param_1 + 0x931bc,*(int *)(param_1 + 0x9318c) + local_20,local_14,
                   *(undefined2 *)(param_1 + 0x9316a),*(undefined2 *)(param_1 + 0x9316a));
    }
  }
  else {
    FUN_00549430(param_1 + 0x931bc,local_20,local_14,uVar14,uVar14,0xff,0xff,0xff,0);
    if ((*(byte *)(param_1 + 0x93184) & 1) != 0) {
      FUN_00549430(param_1 + 0x931bc,*(int *)(param_1 + 0x9318c) + local_20,local_14,
                   *(undefined2 *)(param_1 + 0x9316a),*(undefined2 *)(param_1 + 0x9316a),0xff,0xff,
                   0xff,0);
    }
  }
  if (*(int *)(param_1 + 0x93628) == 1) {
    local_20 = local_20 + 1;
    local_14 = local_14 + 1;
  }
  if ((param_5 == 4) || ((*(int *)(param_1 + 0x93628) == 0 && ((param_5 == 7 || (param_5 == 8))))))
  {
    uVar44 = param_2[3];
    uVar24 = (uint)(ushort)uVar44;
    local_80 = (uint *)(uint)*(ushort *)((int)param_2 + 0xe);
    FUN_0056d380(*(undefined4 *)(param_1 + 0x93198),0,*(undefined4 *)(param_1 + 0x9319c));
    pbVar45 = *(byte **)(param_1 + 0x93198);
    if (param_5 == 4) {
      uVar44 = (uint)(ushort)((ushort)uVar44 >> 1);
      iVar33 = uVar24 + uVar44 * -2;
      if (*(int *)(param_1 + 0x93628) == 0) {
        if (local_80 != (uint *)0x0) {
          do {
            uVar25 = 0;
            if (uVar44 != 0) {
              do {
                pbVar45[uVar25 * 2] = (&DAT_00a4b87c)[(byte)param_6[uVar25] >> 4];
                pbVar45[uVar25 * 2 + 1] = (&DAT_00a4b87c)[(byte)param_6[uVar25] & 0xf];
                uVar25 = uVar25 + 1;
              } while (uVar25 < uVar44);
            }
            if (iVar33 != 0) {
              pbVar45[uVar25 * 2] = (&DAT_00a4b87c)[(byte)param_6[uVar25] >> 4];
            }
            param_6 = param_6 + param_9;
            pbVar45 = pbVar45 + uVar24;
            local_80 = (uint *)((int)local_80 - 1);
          } while (local_80 != (uint *)0x0);
        }
        goto LAB_00531dd7;
      }
      if (local_80 != (uint *)0x0) {
        do {
          uVar25 = 0;
          if (uVar44 != 0) {
            do {
              pbVar45[uVar25 * 2] = (&DAT_00a4b98c)[(byte)param_6[uVar25] >> 4];
              pbVar45[uVar25 * 2 + 1] = (&DAT_00a4b98c)[(byte)param_6[uVar25] & 0xf];
              uVar25 = uVar25 + 1;
            } while (uVar25 < uVar44);
          }
          if (iVar33 != 0) {
            pbVar45[uVar25 * 2] = (&DAT_00a4b98c)[(byte)param_6[uVar25] >> 4];
          }
          param_6 = param_6 + param_9;
          pbVar45 = pbVar45 + uVar24;
          local_80 = (uint *)((int)local_80 - 1);
        } while (local_80 != (uint *)0x0);
      }
      param_5 = 7;
    }
    else {
      if (param_5 == 7) {
        if (local_80 != (uint *)0x0) {
          do {
            if (uVar24 != 0) {
              pbVar27 = pbVar45;
              uVar44 = uVar24;
              do {
                *pbVar27 = pbVar27[(int)param_6 - (int)pbVar45] >> 2;
                pbVar27 = pbVar27 + 1;
                uVar44 = uVar44 - 1;
              } while (uVar44 != 0);
            }
            param_6 = param_6 + param_9;
            pbVar45 = pbVar45 + uVar24;
            local_80 = (uint *)((int)local_80 - 1);
          } while (local_80 != (uint *)0x0);
        }
      }
      else {
        if (param_5 != 8) goto LAB_00531de2;
        if (local_80 != (uint *)0x0) {
          do {
            if (uVar24 != 0) {
              pbVar27 = pbVar45;
              uVar44 = uVar24;
              do {
                *pbVar27 = (&DAT_00a4b88c)[pbVar27[(int)param_6 - (int)pbVar45]];
                pbVar27 = pbVar27 + 1;
                uVar44 = uVar44 - 1;
              } while (uVar44 != 0);
            }
            param_6 = param_6 + param_9;
            pbVar45 = pbVar45 + uVar24;
            local_80 = (uint *)((int)local_80 - 1);
          } while (local_80 != (uint *)0x0);
        }
      }
LAB_00531dd7:
      param_5 = 6;
    }
LAB_00531de2:
    local_6c = *(char **)(param_1 + 0x93198);
    param_9 = uVar24;
  }
  else {
    local_6c = param_6;
    if (1 < uVar44) {
      uVar38 = ((ushort)param_2[3] + 1) / 2;
      uVar14 = uVar38 * 2;
      local_80 = (uint *)(uVar24 / uVar44);
      uVar24 = uVar24 % uVar44;
      uVar25 = uVar14 + 4;
      iVar33 = *(int *)(param_1 + 0x93198);
      FUN_0056d380(iVar33,0,(*(ushort *)((int)param_2 + 0xe) + 2) * uVar25);
      local_6c = (char *)(uVar25 + iVar33);
      iVar33 = (int)param_6 - (param_11 % uVar44) * param_9;
      iVar36 = uVar44 * param_9;
      if (uVar44 == 4) {
        if ((*(int *)(param_1 + 0x93628) == 0) || (*(int *)(param_1 + 0x935fc) == 0x10)) {
          param_5 = 6;
          pcVar26 = local_6c;
          if (local_80 != (uint *)0x0) {
            do {
              if (uVar38 != 0) {
                pbVar45 = (byte *)(param_9 * 3 + iVar33);
                uVar44 = 0;
                do {
                  uVar14 = uVar44 + 1;
                  pcVar26[uVar14 * 2 + -2] =
                       (&DAT_00a4b77c)[*pbVar45 & 0xf0] +
                       (&DAT_00a4b77c)[*(byte *)(uVar44 + iVar33) & 0xf0] +
                       (&DAT_00a4b77c)[pbVar45[param_9 * -2] & 0xf0] +
                       (&DAT_00a4b77c)[pbVar45[-param_9] & 0xf0];
                  bVar12 = *pbVar45;
                  pbVar27 = pbVar45 + param_9 * -2;
                  pbVar1 = pbVar45 + -param_9;
                  pbVar45 = pbVar45 + 1;
                  pcVar26[uVar14 * 2 + -1] =
                       (&DAT_00a4b77c)[bVar12 & 0xf] +
                       (&DAT_00a4b77c)[*(byte *)(uVar44 + iVar33) & 0xf] +
                       (&DAT_00a4b77c)[*pbVar27 & 0xf] + (&DAT_00a4b77c)[*pbVar1 & 0xf];
                  uVar44 = uVar14;
                } while (uVar14 < uVar38);
              }
              pcVar26 = pcVar26 + uVar25;
              iVar33 = iVar33 + iVar36;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
          if (uVar24 != 0) {
            do {
              uVar44 = 0;
              if (uVar38 != 0) {
                do {
                  pcVar26[uVar44 * 2] =
                       pcVar26[uVar44 * 2] + (&DAT_00a4b77c)[*(byte *)(uVar44 + iVar33) & 0xf0];
                  pcVar26[uVar44 * 2 + 1] =
                       pcVar26[uVar44 * 2 + 1] + (&DAT_00a4b77c)[*(byte *)(uVar44 + iVar33) & 0xf];
                  uVar44 = uVar44 + 1;
                } while (uVar44 < uVar38);
              }
              iVar33 = iVar33 + param_9;
              uVar24 = uVar24 - 1;
            } while (uVar24 != 0);
          }
        }
        else {
          param_5 = 7;
          pcVar26 = local_6c;
          if (local_80 != (uint *)0x0) {
            do {
              if (uVar38 != 0) {
                pbVar45 = (byte *)(param_9 * 3 + iVar33);
                uVar44 = 0;
                while( true ) {
                  uVar14 = uVar44 + 1;
                  pcVar26[uVar14 * 2 + -2] =
                       ((&DAT_00a4b77c)[*pbVar45 & 0xf0] + (&DAT_00a4b77c)[pbVar45[-param_9] & 0xf0]
                        + (&DAT_00a4b77c)[*(byte *)(uVar44 + iVar33) & 0xf0] +
                       (&DAT_00a4b77c)[pbVar45[param_9 * -2] & 0xf0]) * '\x04';
                  bVar12 = *pbVar45;
                  pbVar27 = pbVar45 + -param_9;
                  pbVar1 = pbVar45 + param_9 * -2;
                  pbVar45 = pbVar45 + 1;
                  pcVar26[uVar14 * 2 + -1] =
                       ((&DAT_00a4b77c)[bVar12 & 0xf] + (&DAT_00a4b77c)[*pbVar27 & 0xf] +
                        (&DAT_00a4b77c)[*(byte *)(uVar44 + iVar33) & 0xf] +
                       (&DAT_00a4b77c)[*pbVar1 & 0xf]) * '\x04';
                  if (uVar38 <= uVar14) break;
                  uVar44 = uVar14;
                }
              }
              pcVar26 = pcVar26 + uVar25;
              iVar33 = iVar33 + iVar36;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
          if (uVar24 != 0) {
            do {
              uVar44 = 0;
              if (uVar38 != 0) {
                do {
                  pcVar26[uVar44 * 2] =
                       pcVar26[uVar44 * 2] +
                       (&DAT_00a4b77c)[*(byte *)(uVar44 + iVar33) & 0xf0] * '\x04';
                  pcVar26[uVar44 * 2 + 1] =
                       pcVar26[uVar44 * 2 + 1] +
                       (&DAT_00a4b77c)[*(byte *)(uVar44 + iVar33) & 0xf] * '\x04';
                  uVar44 = uVar44 + 1;
                } while (uVar44 < uVar38);
              }
              iVar33 = iVar33 + param_9;
              uVar24 = uVar24 - 1;
            } while (uVar24 != 0);
            param_9 = uVar25;
            goto LAB_00531def;
          }
        }
      }
      else if (uVar44 == 8) {
        local_48 = (ushort *)local_80;
        if ((*(int *)(param_1 + 0x93628) == 0) || (*(int *)(param_1 + 0x935fc) == 0x10)) {
          param_5 = 6;
          pcVar26 = local_6c;
          if (local_80 != (uint *)0x0) {
            do {
              if (uVar38 != 0) {
                pbVar45 = (byte *)(param_9 * 7 + iVar33);
                local_80 = (uint *)pcVar26;
                local_54 = (byte *)uVar14;
                do {
                  *(char *)local_80 =
                       (char)((int)((uint)(byte)(&DAT_00a4b77c)[pbVar45[param_9 * -5]] +
                                    (uint)(byte)(&DAT_00a4b77c)[pbVar45[param_9 * -4]] +
                                    (uint)(byte)(&DAT_00a4b77c)[pbVar45[param_9 * -3]] +
                                    (uint)(byte)(&DAT_00a4b77c)[pbVar45[param_9 * -2]] +
                                    (uint)(byte)(&DAT_00a4b77c)[pbVar45[-param_9]] +
                                    (uint)(byte)(&DAT_00a4b77c)
                                                [*(byte *)((int)local_80 + (iVar33 - (int)pcVar26))]
                                    + (uint)(byte)(&DAT_00a4b77c)[pbVar45[param_9 * -6]] +
                                   (uint)(byte)(&DAT_00a4b77c)[*pbVar45]) >> 2);
                  local_80 = (uint *)((int)local_80 + 1);
                  pbVar45 = pbVar45 + 1;
                  local_54 = (byte *)((int)local_54 - 1);
                } while (local_54 != (byte *)0x0);
              }
              pcVar26 = pcVar26 + uVar25;
              iVar33 = iVar33 + iVar36;
              local_48 = (ushort *)((int)local_48 - 1);
            } while (local_48 != (ushort *)0x0);
          }
          if (uVar24 != 0) {
            if (uVar24 != 0) {
              iVar33 = iVar33 - (int)pcVar26;
              local_80 = (uint *)uVar24;
              do {
                if (uVar38 != 0) {
                  uVar44 = uVar14;
                  pcVar46 = pcVar26;
                  do {
                    *pcVar46 = *pcVar46 + (&DAT_00a4b77c)[(byte)pcVar46[iVar33]];
                    pcVar46 = pcVar46 + 1;
                    uVar44 = uVar44 - 1;
                  } while (uVar44 != 0);
                }
                iVar33 = iVar33 + param_9;
                local_80 = (uint *)((int)local_80 - 1);
              } while (local_80 != (uint *)0x0);
            }
            uVar44 = 0;
            if (uVar38 != 0) {
              do {
                pcVar26[uVar44] = (byte)pcVar26[uVar44] >> 2;
                uVar44 = uVar44 + 1;
              } while (uVar44 < uVar14);
              param_9 = uVar25;
              goto LAB_00531def;
            }
          }
        }
        else {
          param_5 = 7;
          pcVar26 = local_6c;
          if (local_80 != (uint *)0x0) {
            do {
              if (uVar38 != 0) {
                pbVar45 = (byte *)(param_9 * 7 + iVar33);
                local_80 = (uint *)pcVar26;
                local_54 = (byte *)uVar14;
                while( true ) {
                  *(undefined1 *)local_80 =
                       (&DAT_00a4b77c)[pbVar45[param_9 * -5]] +
                       (&DAT_00a4b77c)[pbVar45[param_9 * -4]] +
                       (&DAT_00a4b77c)[pbVar45[param_9 * -3]] +
                       (&DAT_00a4b77c)[pbVar45[param_9 * -2]] + (&DAT_00a4b77c)[pbVar45[-param_9]] +
                       (&DAT_00a4b77c)[*(byte *)((int)local_80 + (iVar33 - (int)pcVar26))] +
                       (&DAT_00a4b77c)[pbVar45[param_9 * -6]] + (&DAT_00a4b77c)[*pbVar45];
                  pbVar45 = pbVar45 + 1;
                  local_54 = (byte *)((int)local_54 - 1);
                  if (local_54 == (byte *)0x0) break;
                  local_80 = (uint *)((int)local_80 + 1);
                }
              }
              pcVar26 = pcVar26 + uVar25;
              iVar33 = iVar33 + iVar36;
              local_48 = (ushort *)((int)local_48 - 1);
            } while (local_48 != (ushort *)0x0);
          }
          if (uVar24 != 0) {
            iVar33 = iVar33 - (int)pcVar26;
            local_80 = (uint *)uVar24;
            do {
              if (uVar38 != 0) {
                uVar44 = uVar14;
                pcVar46 = pcVar26;
                do {
                  *pcVar46 = *pcVar46 + (&DAT_00a4b77c)[(byte)pcVar46[iVar33]];
                  pcVar46 = pcVar46 + 1;
                  uVar44 = uVar44 - 1;
                } while (uVar44 != 0);
              }
              iVar33 = iVar33 + param_9;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
            param_9 = uVar25;
            goto LAB_00531def;
          }
        }
      }
      param_9 = uVar25;
    }
  }
LAB_00531def:
  uVar44 = *(uint *)(param_1 + 0x93184);
  if ((uVar44 & 1) == 0) {
    uVar25 = (uint)(ushort)param_2[3];
    bVar12 = 0;
    uVar24 = (uint)*(ushort *)((int)param_2 + 0xe);
    local_80 = (uint *)uVar24;
    if (*(int *)(param_1 + 0x93628) != 0) {
      iVar22 = *(int *)(param_1 + 0x935ec);
      pbVar45 = (byte *)((uint)*(byte *)(param_1 + 0x931c0) * local_20 + iVar22 * local_14 +
                        *(int *)(param_1 + 0x935f0));
      uVar44 = *(uint *)(param_1 + 0x931cc) | *(uint *)(param_1 + 0x931d0) |
               *(uint *)(param_1 + 0x931d4);
      local_44._0_2_ = (ushort)uVar44;
      switch(param_5) {
      case 0:
        if (*(char *)(param_1 + 0x931c1) == '\b') {
          if (*(int *)(param_1 + 0x931e0) == 0xf) {
            if (uVar24 != 0) {
              do {
                uVar44 = 0;
                if (uVar25 != 0) {
                  do {
                    if ((uVar44 & 7) == 0) {
                      bVar12 = local_6c[uVar44 >> 3];
                    }
                    bVar34 = bVar12 & 0x80;
                    uVar14 = uVar44 + 1;
                    bVar12 = bVar12 * '\x02';
                    pbVar45[uVar44] = -(bVar34 != 0) & 0xf;
                    uVar44 = uVar14;
                  } while (uVar14 < uVar25);
                }
                local_6c = local_6c + param_9;
                pbVar45 = pbVar45 + iVar22;
                uVar24 = uVar24 - 1;
              } while (uVar24 != 0);
            }
          }
          else if (uVar24 != 0) {
            do {
              uVar44 = 0;
              if (uVar25 != 0) {
                do {
                  if ((uVar44 & 7) == 0) {
                    bVar12 = local_6c[uVar44 >> 3];
                  }
                  bVar34 = bVar12 & 0x80;
                  uVar14 = uVar44 + 1;
                  bVar12 = bVar12 * '\x02';
                  pbVar45[uVar44] = -(bVar34 != 0);
                  uVar44 = uVar14;
                } while (uVar14 < uVar25);
              }
              local_6c = local_6c + param_9;
              pbVar45 = pbVar45 + iVar22;
              uVar24 = uVar24 - 1;
            } while (uVar24 != 0);
          }
        }
        else if (*(int *)(param_1 + 0x93600) == 0) {
          if (uVar24 != 0) {
            do {
              uVar44 = 0;
              if (uVar25 != 0) {
                do {
                  if ((uVar44 & 7) == 0) {
                    bVar12 = local_6c[uVar44 >> 3];
                  }
                  if ((char)bVar12 < '\0') {
                    uVar35 = (ushort)*(undefined4 *)(param_1 + 0x931d8);
                  }
                  else {
                    uVar35 = 0;
                  }
                  *(ushort *)(pbVar45 + uVar44 * 2) = uVar35 | (ushort)local_44;
                  uVar44 = uVar44 + 1;
                  bVar12 = bVar12 * '\x02';
                } while (uVar44 < uVar25);
              }
              local_6c = local_6c + param_9;
              pbVar45 = pbVar45 + iVar22;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
        else if (uVar24 != 0) {
          do {
            uVar44 = 0;
            if (uVar25 != 0) {
              do {
                if ((uVar44 & 7) == 0) {
                  bVar12 = local_6c[uVar44 >> 3];
                }
                if ((char)bVar12 < '\0') {
                  *(ushort *)(pbVar45 + uVar44 * 2) =
                       *(ushort *)(param_1 + 0x931d8) | (ushort)local_44;
                }
                else {
                  (pbVar45 + uVar44 * 2)[0] = 0;
                  (pbVar45 + uVar44 * 2)[1] = 0;
                }
                uVar44 = uVar44 + 1;
                bVar12 = bVar12 * '\x02';
              } while (uVar44 < uVar25);
            }
            local_6c = local_6c + param_9;
            pbVar45 = pbVar45 + iVar22;
            local_80 = (uint *)((int)local_80 - 1);
          } while (local_80 != (uint *)0x0);
        }
        break;
      default:
        return 0xffffffff;
      case 5:
        if (*(char *)(param_1 + 0x931c1) == '\b') {
          if (*(int *)(param_1 + 0x931e0) == 0xf) {
            if (uVar24 != 0) {
              do {
                if (uVar25 != 0) {
                  pbVar27 = pbVar45;
                  uVar44 = uVar25;
                  do {
                    uVar44 = uVar44 - 1;
                    *pbVar27 = -(pbVar27[(int)local_6c - (int)pbVar45] != 0) & 0xf;
                    pbVar27 = pbVar27 + 1;
                  } while (uVar44 != 0);
                }
                local_6c = local_6c + param_9;
                pbVar45 = pbVar45 + iVar22;
                local_80 = (uint *)((int)local_80 - 1);
              } while (local_80 != (uint *)0x0);
            }
          }
          else if (uVar24 != 0) {
            do {
              if (uVar25 != 0) {
                pbVar27 = pbVar45;
                uVar44 = uVar25;
                do {
                  uVar44 = uVar44 - 1;
                  *pbVar27 = -(pbVar27[(int)local_6c - (int)pbVar45] != 0);
                  pbVar27 = pbVar27 + 1;
                } while (uVar44 != 0);
              }
              local_6c = local_6c + param_9;
              pbVar45 = pbVar45 + iVar22;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
        else if (*(char *)(param_1 + 0x931c1) == '\x10') {
          uVar35 = *(ushort *)(param_1 + 0x931d8) | (ushort)local_44;
          if (*(int *)(param_1 + 0x93600) == 0) {
            for (; uVar24 != 0; uVar24 = uVar24 - 1) {
              uVar44 = 0;
              if (uVar25 != 0) {
                do {
                  uVar43 = uVar35;
                  if (local_6c[uVar44] == '\0') {
                    uVar43 = (ushort)local_44;
                  }
                  *(ushort *)(pbVar45 + uVar44 * 2) = uVar43;
                  uVar44 = uVar44 + 1;
                } while (uVar44 < uVar25);
              }
              local_6c = local_6c + param_9;
              pbVar45 = pbVar45 + iVar22;
            }
          }
          else {
            for (; uVar24 != 0; uVar24 = uVar24 - 1) {
              uVar44 = 0;
              if (uVar25 != 0) {
                do {
                  uVar43 = uVar35;
                  if (local_6c[uVar44] == '\0') {
                    uVar43 = 0;
                  }
                  *(ushort *)(pbVar45 + uVar44 * 2) = uVar43;
                  uVar44 = uVar44 + 1;
                } while (uVar44 < uVar25);
              }
              local_6c = local_6c + param_9;
              pbVar45 = pbVar45 + iVar22;
            }
          }
        }
        break;
      case 6:
        cVar4 = *(char *)(param_1 + 0x931c1);
        if (cVar4 == '\b') {
          if (*(int *)(param_1 + 0x931e0) == 0xf) {
            if (uVar24 != 0) {
              do {
                if (uVar25 != 0) {
                  uVar44 = uVar25;
                  pbVar27 = pbVar45;
                  do {
                    if (pbVar27[(int)local_6c - (int)pbVar45] == 0) {
                      *pbVar27 = 0;
                    }
                    else {
                      *pbVar27 = pbVar27[(int)local_6c - (int)pbVar45] - 1;
                    }
                    pbVar27 = pbVar27 + 1;
                    uVar44 = uVar44 - 1;
                  } while (uVar44 != 0);
                }
                local_6c = local_6c + param_9;
                pbVar45 = pbVar45 + iVar22;
                local_80 = (uint *)((int)local_80 - 1);
              } while (local_80 != (uint *)0x0);
            }
          }
          else if (uVar24 != 0) {
            do {
              if (uVar25 != 0) {
                uVar44 = uVar25;
                pbVar27 = pbVar45;
                do {
                  if (pbVar27[(int)local_6c - (int)pbVar45] == 0) {
                    *pbVar27 = 0;
                  }
                  else {
                    *pbVar27 = pbVar27[(int)local_6c - (int)pbVar45] * '\x10' - 1;
                  }
                  pbVar27 = pbVar27 + 1;
                  uVar44 = uVar44 - 1;
                } while (uVar44 != 0);
              }
              local_6c = local_6c + param_9;
              pbVar45 = pbVar45 + iVar22;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
        else if ((((*(int *)(param_1 + 0x931d8) == 0xf000) && (*(int *)(param_1 + 0x931cc) == 0xf00)
                  ) && (*(int *)(param_1 + 0x931d0) == 0xf0)) &&
                (*(uint *)(param_1 + 0x931d4) == 0xf)) {
          if (*(int *)(param_1 + 0x93600) == 0) {
            if (uVar24 != 0) {
              do {
                uVar44 = 0;
                if (uVar25 != 0) {
                  do {
                    if (local_6c[uVar44] == 0) {
                      (pbVar45 + uVar44 * 2)[0] = 0xff;
                      (pbVar45 + uVar44 * 2)[1] = 0xf;
                    }
                    else {
                      *(ushort *)(pbVar45 + uVar44 * 2) =
                           (ushort)(byte)local_6c[uVar44] * 0x1000 - 1 | 0xfff;
                    }
                    uVar44 = uVar44 + 1;
                  } while (uVar44 < uVar25);
                }
                local_6c = local_6c + param_9;
                pbVar45 = pbVar45 + iVar22;
                local_80 = (uint *)((int)local_80 - 1);
              } while (local_80 != (uint *)0x0);
            }
          }
          else if (uVar24 != 0) {
            do {
              uVar44 = 0;
              if (uVar25 != 0) {
                do {
                  if (local_6c[uVar44] == '\x10') {
                    (pbVar45 + uVar44 * 2)[0] = 0xff;
                    (pbVar45 + uVar44 * 2)[1] = 0xff;
                  }
                  else if (local_6c[uVar44] == '\0') {
                    (pbVar45 + uVar44 * 2)[0] = 0;
                    (pbVar45 + uVar44 * 2)[1] = 0;
                  }
                  else {
                    uVar24 = (uint)(ushort)(byte)local_6c[uVar44];
                    *(ushort *)(pbVar45 + uVar44 * 2) =
                         (ushort)(((uVar24 << 4 | uVar24) << 4 | uVar24) << 4) |
                         (ushort)(byte)local_6c[uVar44];
                  }
                  uVar44 = uVar44 + 1;
                } while (uVar44 < uVar25);
              }
              local_6c = local_6c + param_9;
              pbVar45 = pbVar45 + iVar22;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
        else if (cVar4 == '\x10') {
          if (*(int *)(param_1 + 0x93600) == 0) {
            if (uVar24 != 0) {
              do {
                uVar44 = 0;
                if (uVar25 != 0) {
                  do {
                    if (local_6c[uVar44] == 0) {
                      *(ushort *)(pbVar45 + uVar44 * 2) = (ushort)local_44;
                    }
                    else {
                      *(ushort *)(pbVar45 + uVar44 * 2) =
                           ((ushort)(byte)local_6c[uVar44] <<
                           (*(char *)(param_1 + 0x931cb) + -4 + *(char *)(param_1 + 0x931c7) & 0x1fU
                           )) - 1 | (ushort)local_44;
                    }
                    uVar44 = uVar44 + 1;
                  } while (uVar44 < uVar25);
                }
                local_6c = local_6c + param_9;
                pbVar45 = pbVar45 + iVar22;
                local_80 = (uint *)((int)local_80 - 1);
              } while (local_80 != (uint *)0x0);
            }
          }
          else {
            cVar4 = *(char *)(param_1 + 0x931cb);
            cVar5 = *(char *)(param_1 + 0x931c7);
            cVar6 = *(char *)(param_1 + 0x931c9);
            cVar7 = *(char *)(param_1 + 0x931c5);
            cVar8 = *(char *)(param_1 + 0x931c8);
            cVar9 = *(char *)(param_1 + 0x931c4);
            cVar10 = *(char *)(param_1 + 0x931ca);
            cVar11 = *(char *)(param_1 + 0x931c6);
            if (uVar24 != 0) {
              do {
                uVar14 = 0;
                uVar44 = uVar24;
                if (uVar25 != 0) {
                  do {
                    cVar3 = local_6c[uVar14];
                    uVar24 = CONCAT31((int3)(uVar44 >> 8),cVar3);
                    if (cVar3 == '\x10') {
                      (pbVar45 + uVar14 * 2)[0] = 0xff;
                      (pbVar45 + uVar14 * 2)[1] = 0xff;
                    }
                    else if (cVar3 == '\0') {
                      (pbVar45 + uVar14 * 2)[0] = 0;
                      (pbVar45 + uVar14 * 2)[1] = 0;
                    }
                    else {
                      uVar35 = (ushort)(byte)local_6c[uVar14];
                      uVar24 = CONCAT22((short)(uVar44 >> 0x10),uVar35) <<
                               ((cVar4 + cVar5) - 4U & 0x1f);
                      *(ushort *)(pbVar45 + uVar14 * 2) =
                           uVar35 << ((cVar10 + cVar11) - 4U & 0x1f) |
                           uVar35 << ((cVar6 + cVar7) - 4U & 0x1f) |
                           uVar35 << ((cVar8 + cVar9) - 4U & 0x1f) | (ushort)uVar24;
                    }
                    uVar14 = uVar14 + 1;
                    uVar44 = uVar24;
                  } while (uVar14 < uVar25);
                }
                local_6c = local_6c + param_9;
                pbVar45 = pbVar45 + iVar22;
                local_80 = (uint *)((int)local_80 - 1);
              } while (local_80 != (uint *)0x0);
            }
          }
        }
        else if (cVar4 == ' ') {
          if (*(int *)(param_1 + 0x93600) == 0) {
            if (uVar24 != 0) {
              do {
                uVar24 = 0;
                if (uVar25 != 0) {
                  do {
                    if (local_6c[uVar24] == 0) {
                      *(uint *)(pbVar45 + uVar24 * 4) = uVar44;
                    }
                    else {
                      *(uint *)(pbVar45 + uVar24 * 4) =
                           ((uint)(byte)local_6c[uVar24] <<
                           (*(char *)(param_1 + 0x931cb) + -4 + *(char *)(param_1 + 0x931c7) & 0x1fU
                           )) - 1 | uVar44;
                    }
                    uVar24 = uVar24 + 1;
                  } while (uVar24 < uVar25);
                }
                local_6c = local_6c + param_9;
                pbVar45 = pbVar45 + iVar22;
                local_80 = (uint *)((int)local_80 - 1);
              } while (local_80 != (uint *)0x0);
            }
          }
          else {
            cVar4 = *(char *)(param_1 + 0x931cb);
            cVar5 = *(char *)(param_1 + 0x931c7);
            cVar6 = *(char *)(param_1 + 0x931c9);
            cVar7 = *(char *)(param_1 + 0x931c5);
            cVar8 = *(char *)(param_1 + 0x931c8);
            cVar9 = *(char *)(param_1 + 0x931c4);
            cVar10 = *(char *)(param_1 + 0x931ca);
            cVar11 = *(char *)(param_1 + 0x931c6);
            if (uVar24 != 0) {
              do {
                uVar44 = 0;
                if (uVar25 != 0) {
                  do {
                    if (local_6c[uVar44] == '\x10') {
                      pbVar27 = pbVar45 + uVar44 * 4;
                      pbVar27[0] = 0xff;
                      pbVar27[1] = 0xff;
                      pbVar27[2] = 0xff;
                      pbVar27[3] = 0xff;
                    }
                    else if (local_6c[uVar44] == '\0') {
                      pbVar27 = pbVar45 + uVar44 * 4;
                      pbVar27[0] = 0;
                      pbVar27[1] = 0;
                      pbVar27[2] = 0;
                      pbVar27[3] = 0;
                    }
                    else {
                      uVar24 = (uint)(byte)local_6c[uVar44];
                      *(uint *)(pbVar45 + uVar44 * 4) =
                           uVar24 << ((cVar10 + cVar11) - 4U & 0x1f) |
                           uVar24 << ((cVar6 + cVar7) - 4U & 0x1f) |
                           uVar24 << ((cVar8 + cVar9) - 4U & 0x1f) |
                           uVar24 << ((cVar4 + cVar5) - 4U & 0x1f);
                    }
                    uVar44 = uVar44 + 1;
                  } while (uVar44 < uVar25);
                }
                local_6c = local_6c + param_9;
                pbVar45 = pbVar45 + iVar22;
                local_80 = (uint *)((int)local_80 - 1);
              } while (local_80 != (uint *)0x0);
            }
          }
        }
        break;
      case 7:
        if (*(char *)(param_1 + 0x931c1) == '\b') {
          if (*(int *)(param_1 + 0x931e0) == 0xf) {
            if (uVar24 != 0) {
              do {
                if (uVar25 != 0) {
                  uVar44 = uVar25;
                  pbVar27 = pbVar45;
                  do {
                    if (pbVar27[(int)local_6c - (int)pbVar45] < 5) {
                      *pbVar27 = 0;
                    }
                    else {
                      *pbVar27 = (pbVar27[(int)local_6c - (int)pbVar45] >> 2) - 1;
                    }
                    pbVar27 = pbVar27 + 1;
                    uVar44 = uVar44 - 1;
                  } while (uVar44 != 0);
                }
                local_6c = local_6c + param_9;
                pbVar45 = pbVar45 + iVar22;
                local_80 = (uint *)((int)local_80 - 1);
              } while (local_80 != (uint *)0x0);
            }
          }
          else if (uVar24 != 0) {
            do {
              if (uVar25 != 0) {
                uVar44 = uVar25;
                pbVar27 = pbVar45;
                do {
                  if (pbVar27[(int)local_6c - (int)pbVar45] == 0) {
                    *pbVar27 = 0;
                  }
                  else {
                    *pbVar27 = pbVar27[(int)local_6c - (int)pbVar45] * '\x04' - 1;
                  }
                  pbVar27 = pbVar27 + 1;
                  uVar44 = uVar44 - 1;
                } while (uVar44 != 0);
              }
              local_6c = local_6c + param_9;
              pbVar45 = pbVar45 + iVar22;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
        else if (*(int *)(param_1 + 0x93600) == 0) {
          if (uVar24 != 0) {
            do {
              uVar24 = 0;
              if (uVar25 != 0) {
                do {
                  if (local_6c[uVar24] == 0) {
                    *(uint *)(pbVar45 + uVar24 * 4) = uVar44;
                  }
                  else {
                    *(uint *)(pbVar45 + uVar24 * 4) =
                         (byte)local_6c[uVar24] - 1 <<
                         (*(char *)(param_1 + 0x931cb) + -6 + *(char *)(param_1 + 0x931c7) & 0x1fU)
                         | uVar44;
                  }
                  uVar24 = uVar24 + 1;
                } while (uVar24 < uVar25);
              }
              local_6c = local_6c + param_9;
              pbVar45 = pbVar45 + iVar22;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
        else {
          cVar4 = *(char *)(param_1 + 0x931cb);
          cVar5 = *(char *)(param_1 + 0x931c7);
          cVar6 = *(char *)(param_1 + 0x931c9);
          cVar7 = *(char *)(param_1 + 0x931c5);
          cVar8 = *(char *)(param_1 + 0x931c8);
          cVar9 = *(char *)(param_1 + 0x931c4);
          cVar10 = *(char *)(param_1 + 0x931ca);
          cVar11 = *(char *)(param_1 + 0x931c6);
          if (uVar24 != 0) {
            do {
              uVar44 = 0;
              if (uVar25 != 0) {
                do {
                  if (local_6c[uVar44] == '@') {
                    pbVar27 = pbVar45 + uVar44 * 4;
                    pbVar27[0] = 0xff;
                    pbVar27[1] = 0xff;
                    pbVar27[2] = 0xff;
                    pbVar27[3] = 0xff;
                  }
                  else if (local_6c[uVar44] == '\0') {
                    pbVar27 = pbVar45 + uVar44 * 4;
                    pbVar27[0] = 0;
                    pbVar27[1] = 0;
                    pbVar27[2] = 0;
                    pbVar27[3] = 0;
                  }
                  else {
                    uVar24 = (uint)(byte)local_6c[uVar44];
                    *(uint *)(pbVar45 + uVar44 * 4) =
                         uVar24 << ((cVar10 + cVar11) - 6U & 0x1f) |
                         uVar24 << ((cVar6 + cVar7) - 6U & 0x1f) |
                         uVar24 << ((cVar8 + cVar9) - 6U & 0x1f) |
                         uVar24 << ((cVar4 + cVar5) - 6U & 0x1f);
                  }
                  uVar44 = uVar44 + 1;
                } while (uVar44 < uVar25);
              }
              local_6c = local_6c + param_9;
              pbVar45 = pbVar45 + iVar22;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
        break;
      case 8:
        if (*(char *)(param_1 + 0x931c1) == '\b') {
          if (*(int *)(param_1 + 0x931e0) == 0xf) {
            if (uVar24 != 0) {
              do {
                if (uVar25 != 0) {
                  pbVar27 = pbVar45;
                  uVar44 = uVar25;
                  do {
                    *pbVar27 = pbVar27[(int)local_6c - (int)pbVar45] >> 4;
                    pbVar27 = pbVar27 + 1;
                    uVar44 = uVar44 - 1;
                  } while (uVar44 != 0);
                }
                local_6c = local_6c + param_9;
                pbVar45 = pbVar45 + iVar22;
                local_80 = (uint *)((int)local_80 - 1);
              } while (local_80 != (uint *)0x0);
            }
          }
          else if (uVar24 != 0) {
            do {
              if (uVar25 != 0) {
                pbVar27 = pbVar45;
                uVar44 = uVar25;
                do {
                  *pbVar27 = pbVar27[(int)local_6c - (int)pbVar45];
                  pbVar27 = pbVar27 + 1;
                  uVar44 = uVar44 - 1;
                } while (uVar44 != 0);
              }
              local_6c = local_6c + param_9;
              pbVar45 = pbVar45 + iVar22;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
        else if (*(int *)(param_1 + 0x93600) == 0) {
          if (uVar24 != 0) {
            do {
              uVar24 = 0;
              if (uVar25 != 0) {
                do {
                  pbVar27 = (byte *)(local_6c + uVar24);
                  uVar24 = uVar24 + 1;
                  *(uint *)(pbVar45 + uVar24 * 4 + -4) =
                       (uint)*pbVar27 <<
                       (*(char *)(param_1 + 0x931c7) + -8 + *(char *)(param_1 + 0x931cb) & 0x1fU) |
                       uVar44;
                } while (uVar24 < uVar25);
              }
              local_6c = local_6c + param_9;
              pbVar45 = pbVar45 + iVar22;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
        else {
          cVar4 = *(char *)(param_1 + 0x931c8);
          cVar5 = *(char *)(param_1 + 0x931c4);
          cVar6 = *(char *)(param_1 + 0x931cb);
          cVar7 = *(char *)(param_1 + 0x931c7);
          cVar8 = *(char *)(param_1 + 0x931c9);
          cVar9 = *(char *)(param_1 + 0x931c5);
          cVar10 = *(char *)(param_1 + 0x931ca);
          cVar11 = *(char *)(param_1 + 0x931c6);
          if (uVar24 != 0) {
            do {
              uVar44 = 0;
              if (uVar25 != 0) {
                do {
                  uVar24 = (uint)(byte)local_6c[uVar44];
                  uVar44 = uVar44 + 1;
                  *(uint *)(pbVar45 + uVar44 * 4 + -4) =
                       uVar24 << ((cVar6 + cVar7) - 8U & 0x1f) |
                       uVar24 << ((cVar4 + cVar5) - 8U & 0x1f) |
                       uVar24 << ((cVar8 + cVar9) - 8U & 0x1f) |
                       uVar24 << ((cVar10 + cVar11) - 8U & 0x1f);
                } while (uVar44 < uVar25);
              }
              local_6c = local_6c + param_9;
              pbVar45 = pbVar45 + iVar22;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
      }
      goto joined_r0x00536134;
    }
    iVar22 = *(int *)(param_1 + 0x90d90);
    pbVar45 = (byte *)(iVar22 * local_14 + *(int *)(param_1 + 0x90d8c));
    switch(uVar44) {
    case 0:
      if (param_5 == 0) {
        if (uVar24 != 0) {
          do {
            FUN_0056d420(pbVar45,local_6c,param_9);
            pbVar45 = pbVar45 + iVar22;
            local_6c = local_6c + param_9;
            uVar24 = uVar24 - 1;
          } while (uVar24 != 0);
        }
      }
      else {
        if (param_5 != 5) {
          return 0xffffffff;
        }
        if (uVar24 != 0) {
          do {
            bVar12 = 0;
            uVar44 = 0;
            bVar34 = 0x80;
            pbVar27 = pbVar45;
            if (uVar25 != 0) {
              do {
                if ((uVar44 != 0) && ((uVar44 & 7) == 0)) {
                  *pbVar27 = bVar12;
                  pbVar27 = pbVar27 + 1;
                  bVar34 = 0x80;
                  bVar12 = 0;
                }
                if (local_6c[uVar44] != '\0') {
                  bVar12 = bVar12 | bVar34;
                }
                uVar44 = uVar44 + 1;
                bVar34 = bVar34 >> 1;
              } while (uVar44 < uVar25);
            }
            local_6c = local_6c + param_9;
            pbVar45 = pbVar45 + iVar22;
            local_80 = (uint *)((int)local_80 - 1);
            *pbVar27 = bVar12;
          } while (local_80 != (uint *)0x0);
        }
      }
      break;
    case 2:
    case 0x12:
    case 0x22:
      if (param_5 != 6) {
        return 0xffffffff;
      }
      if (uVar24 != 0) {
        do {
          if (uVar25 != 0) {
            pcVar26 = local_6c;
            uVar44 = uVar25;
            do {
              if (*pcVar26 != '\0') {
                pcVar26[(int)pbVar45 - (int)local_6c] = *pcVar26 + -1;
              }
              pcVar26 = pcVar26 + 1;
              uVar44 = uVar44 - 1;
            } while (uVar44 != 0);
          }
          local_6c = local_6c + param_9;
          pbVar45 = pbVar45 + iVar22;
          local_80 = (uint *)((int)local_80 - 1);
        } while (local_80 != (uint *)0x0);
      }
    }
  }
  else {
    uVar24 = (uint)(ushort)param_2[3];
    uVar25 = (uint)*(ushort *)((int)param_2 + 0xe);
    iVar33 = *(int *)(param_1 + 0x93188);
    pcVar26 = (char *)((int)&DAT_0084c9ec + iVar33 * 0x51 + 3);
    local_79 = 0;
    local_80 = (uint *)uVar25;
    local_48 = (ushort *)uVar25;
    if (*(int *)(param_1 + 0x93628) == 0) {
      iVar36 = *(int *)(param_1 + 0x90d90);
      switch(uVar44) {
      case 1:
        local_50 = (byte *)((local_14 + iVar22) * iVar36 + *(int *)(param_1 + 0x90d8c) + local_20 +
                           iVar22);
        if (param_5 == 0) {
          if (iVar33 == 1) {
            if (uVar25 != 0) {
              do {
                uVar44 = 0;
                if (uVar24 != 0) {
                  do {
                    if ((uVar44 & 7) == 0) {
                      local_79 = local_6c[uVar44 >> 3];
                    }
                    if ((local_79 & 0x80) != 0) {
                      cVar4 = *(char *)((uVar44 - 1) + (int)local_50);
                      pcVar26 = (char *)(uVar44 + ((int)local_50 - iVar36));
                      pcVar26[iVar36] = '\x01';
                      if (cVar4 != '\x01') {
                        *(undefined1 *)((uVar44 - 1) + (int)local_50) = 2;
                      }
                      if (*(char *)(uVar44 + 1 + (int)local_50) != '\x01') {
                        *(undefined1 *)(uVar44 + 1 + (int)local_50) = 2;
                      }
                      if (*pcVar26 != '\x01') {
                        *pcVar26 = '\x02';
                      }
                      pcVar26 = (char *)(uVar44 + (int)local_50 + iVar36);
                      if (*pcVar26 != '\x01') {
                        *pcVar26 = '\x02';
                      }
                    }
                    local_79 = local_79 << 1;
                    uVar44 = uVar44 + 1;
                  } while ((int)uVar44 < (int)uVar24);
                }
                local_6c = local_6c + param_9;
                local_50 = (byte *)((int)local_50 + iVar36);
                local_80 = (uint *)((int)local_80 - 1);
              } while (local_80 != (uint *)0x0);
            }
          }
          else if (iVar33 < 5) {
            if (uVar25 != 0) {
              do {
                local_5c = 0;
                if (uVar24 != 0) {
                  do {
                    uVar44 = local_5c & 0x80000007;
                    bVar49 = uVar44 == 0;
                    if ((int)uVar44 < 0) {
                      bVar49 = (uVar44 - 1 | 0xfffffff8) == 0xffffffff;
                    }
                    if (bVar49) {
                      local_79 = local_6c[(int)(local_5c + ((int)local_5c >> 0x1f & 7U)) >> 3];
                    }
                    if ((local_79 & 0x80) != 0) {
                      iVar15 = -iVar33;
                      iVar22 = iVar33 + 1;
                      *(undefined1 *)(local_5c + (int)local_50) = 1;
                      if (iVar15 < iVar22) {
                        iVar29 = iVar15 * iVar36 + local_5c + (int)local_50;
                        iVar48 = iVar22 + iVar33;
                        pcVar46 = pcVar26;
                        do {
                          if (iVar15 < iVar22) {
                            iVar28 = iVar15;
                            pcVar40 = pcVar46;
                            do {
                              if ((*pcVar40 != '\0') && (*(char *)(iVar28 + iVar29) != '\x01')) {
                                *(undefined1 *)(iVar28 + iVar29) = 2;
                              }
                              iVar28 = iVar28 + 1;
                              pcVar40 = pcVar40 + 1;
                            } while (iVar28 < iVar22);
                          }
                          iVar29 = iVar29 + iVar36;
                          pcVar46 = pcVar46 + 9;
                          iVar48 = iVar48 + -1;
                        } while (iVar48 != 0);
                      }
                    }
                    local_79 = local_79 << 1;
                    local_5c = local_5c + 1;
                  } while ((int)local_5c < (int)uVar24);
                }
                local_6c = local_6c + param_9;
                local_50 = (byte *)((int)local_50 + iVar36);
                local_80 = (uint *)((int)local_80 - 1);
              } while (local_80 != (uint *)0x0);
            }
          }
          else if (uVar25 != 0) {
            do {
              if (uVar24 != 0) {
                uVar44 = 0;
                do {
                  uVar25 = uVar44 & 0x80000007;
                  bVar49 = uVar25 == 0;
                  if ((int)uVar25 < 0) {
                    bVar49 = (uVar25 - 1 | 0xfffffff8) == 0xffffffff;
                  }
                  if (bVar49) {
                    local_79 = local_6c[(int)(uVar44 + ((int)uVar44 >> 0x1f & 7U)) >> 3];
                  }
                  if ((local_79 & 0x80) != 0) {
                    iVar15 = -iVar33;
                    iVar22 = iVar33 + 1;
                    *(undefined1 *)(uVar44 + (int)local_50) = 1;
                    if (iVar15 < iVar22) {
                      iVar48 = iVar15 * iVar36 + uVar44 + (int)local_50;
                      iVar28 = iVar22 + iVar33;
                      iVar29 = iVar15;
                      do {
                        for (; iVar29 < iVar22; iVar29 = iVar29 + 1) {
                          if (*(char *)(iVar29 + iVar48) != '\x01') {
                            *(undefined1 *)(iVar29 + iVar48) = 2;
                          }
                        }
                        iVar48 = iVar48 + iVar36;
                        iVar28 = iVar28 + -1;
                        iVar29 = iVar15;
                      } while (iVar28 != 0);
                    }
                  }
                  local_79 = local_79 << 1;
                  uVar44 = uVar44 + 1;
                } while ((int)uVar44 < (int)uVar24);
              }
              local_6c = local_6c + param_9;
              local_50 = (byte *)((int)local_50 + iVar36);
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
        else {
          if (param_5 != 5) {
            return 0xffffffff;
          }
          if (iVar33 == 1) {
            if (uVar25 != 0) {
              do {
                iVar22 = 0;
                if (uVar24 != 0) {
                  do {
                    if (local_6c[iVar22] != '\0') {
                      cVar4 = *(char *)(iVar22 + -1 + (int)local_50);
                      pcVar26 = (char *)(iVar22 + ((int)local_50 - iVar36));
                      pcVar26[iVar36] = '\x01';
                      if (cVar4 != '\x01') {
                        *(undefined1 *)(iVar22 + -1 + (int)local_50) = 2;
                      }
                      if (*(char *)(iVar22 + 1 + (int)local_50) != '\x01') {
                        *(undefined1 *)(iVar22 + 1 + (int)local_50) = 2;
                      }
                      if (*pcVar26 != '\x01') {
                        *pcVar26 = '\x02';
                      }
                      pcVar26 = (char *)(iVar22 + (int)local_50 + iVar36);
                      if (*pcVar26 != '\x01') {
                        *pcVar26 = '\x02';
                      }
                    }
                    iVar22 = iVar22 + 1;
                  } while (iVar22 < (int)uVar24);
                }
                local_6c = local_6c + param_9;
                local_50 = (byte *)((int)local_50 + iVar36);
                local_80 = (uint *)((int)local_80 - 1);
              } while (local_80 != (uint *)0x0);
            }
          }
          else if (iVar33 < 5) {
            if (uVar25 != 0) {
              do {
                local_5c = 0;
                if (uVar24 != 0) {
                  do {
                    if (((undefined1 *)((int)local_50 + local_5c))[(int)local_6c - (int)local_50] !=
                        '\0') {
                      iVar15 = -iVar33;
                      iVar22 = iVar33 + 1;
                      *(undefined1 *)((int)local_50 + local_5c) = 1;
                      if (iVar15 < iVar22) {
                        iVar29 = iVar15 * iVar36 + local_5c + (int)local_50;
                        iVar48 = iVar22 + iVar33;
                        pcVar46 = pcVar26;
                        do {
                          if (iVar15 < iVar22) {
                            iVar28 = iVar15;
                            pcVar40 = pcVar46;
                            do {
                              if ((*pcVar40 != '\0') && (*(char *)(iVar28 + iVar29) != '\x01')) {
                                *(undefined1 *)(iVar28 + iVar29) = 2;
                              }
                              iVar28 = iVar28 + 1;
                              pcVar40 = pcVar40 + 1;
                            } while (iVar28 < iVar22);
                          }
                          iVar29 = iVar29 + iVar36;
                          pcVar46 = pcVar46 + 9;
                          iVar48 = iVar48 + -1;
                        } while (iVar48 != 0);
                      }
                    }
                    local_5c = local_5c + 1;
                  } while ((int)local_5c < (int)uVar24);
                }
                local_6c = local_6c + param_9;
                local_50 = (byte *)((int)local_50 + iVar36);
                local_80 = (uint *)((int)local_80 - 1);
              } while (local_80 != (uint *)0x0);
            }
          }
          else if (uVar25 != 0) {
            do {
              iVar22 = 0;
              if (uVar24 != 0) {
                do {
                  if (((undefined1 *)((int)local_50 + iVar22))[(int)local_6c - (int)local_50] !=
                      '\0') {
                    iVar29 = -iVar33;
                    iVar15 = iVar33 + 1;
                    *(undefined1 *)((int)local_50 + iVar22) = 1;
                    if (iVar29 < iVar15) {
                      iVar28 = iVar29 * iVar36 + iVar22 + (int)local_50;
                      iVar47 = iVar15 + iVar33;
                      iVar48 = iVar29;
                      do {
                        for (; iVar48 < iVar15; iVar48 = iVar48 + 1) {
                          if (*(char *)(iVar48 + iVar28) != '\x01') {
                            *(undefined1 *)(iVar48 + iVar28) = 2;
                          }
                        }
                        iVar28 = iVar28 + iVar36;
                        iVar47 = iVar47 + -1;
                        iVar48 = iVar29;
                      } while (iVar47 != 0);
                    }
                  }
                  iVar22 = iVar22 + 1;
                } while (iVar22 < (int)uVar24);
              }
              local_6c = local_6c + param_9;
              local_50 = (byte *)((int)local_50 + iVar36);
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
        break;
      case 3:
      case 0x13:
      case 0x23:
        if (param_5 != 6) {
          return 0xffffffff;
        }
        local_50 = (byte *)((local_14 + iVar22) * iVar36 + *(int *)(param_1 + 0x90d8c) + local_20 +
                           iVar22);
        if (iVar33 == 1) {
          if (uVar25 != 0) {
            do {
              iVar22 = 0;
              if (uVar24 != 0) {
                do {
                  if (local_6c[iVar22] != 0) {
                    iVar33 = (byte)local_6c[iVar22] - 1;
                    pbVar45 = local_50 + (iVar22 - iVar36);
                    pbVar45[iVar36] = pbVar45[iVar36] | (byte)iVar33;
                    iVar33 = iVar33 * 0x10;
                    bVar12 = (byte)iVar33;
                    if ((int)(*pbVar45 & 0xf0) < iVar33) {
                      *pbVar45 = *pbVar45 & 0xf | bVar12;
                    }
                    bVar34 = local_50[iVar36 + iVar22];
                    if ((int)(bVar34 & 0xf0) < iVar33) {
                      local_50[iVar36 + iVar22] = bVar34 & 0xf | bVar12;
                    }
                    if ((int)(local_50[iVar22 + 1] & 0xf0) < iVar33) {
                      local_50[iVar22 + 1] = local_50[iVar22 + 1] & 0xf | bVar12;
                    }
                    if ((int)(local_50[iVar22 + -1] & 0xf0) < iVar33) {
                      local_50[iVar22 + -1] = local_50[iVar22 + -1] & 0xf | bVar12;
                    }
                  }
                  iVar22 = iVar22 + 1;
                } while (iVar22 < (int)uVar24);
              }
              local_6c = local_6c + param_9;
              local_50 = local_50 + iVar36;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
        else if (iVar33 < 5) {
          if (uVar25 != 0) {
            do {
              local_5c = 0;
              if (uVar24 != 0) {
                local_54 = local_50;
                do {
                  if (local_54[(int)local_6c - (int)local_50] != 0) {
                    iVar15 = local_54[(int)local_6c - (int)local_50] - 1;
                    *local_54 = *local_54 | (byte)iVar15;
                    iVar22 = -iVar33;
                    iVar29 = iVar33 + 1;
                    iVar15 = iVar15 * 0x10;
                    if (iVar22 < iVar29) {
                      pbVar45 = local_50 + iVar22 * iVar36 + local_5c;
                      local_80 = (uint *)(iVar29 + iVar33);
                      local_28 = pcVar26;
                      do {
                        if (iVar22 < iVar29) {
                          pcVar46 = local_28;
                          iVar48 = iVar22;
                          do {
                            if ((*pcVar46 != '\0') && ((int)(pbVar45[iVar48] & 0xf0) < iVar15)) {
                              pbVar45[iVar48] = pbVar45[iVar48] & 0xf | (byte)iVar15;
                            }
                            iVar48 = iVar48 + 1;
                            pcVar46 = pcVar46 + 1;
                          } while (iVar48 < iVar29);
                        }
                        local_28 = local_28 + 9;
                        pbVar45 = pbVar45 + iVar36;
                        local_80 = (uint *)((int)local_80 + -1);
                      } while (local_80 != (uint *)0x0);
                    }
                  }
                  local_5c = local_5c + 1;
                  local_54 = local_54 + 1;
                } while ((int)local_5c < (int)uVar24);
              }
              local_50 = local_50 + iVar36;
              local_6c = local_6c + param_9;
              local_48 = (ushort *)((int)local_48 - 1);
            } while (local_48 != (ushort *)0x0);
          }
        }
        else if (uVar25 != 0) {
          do {
            local_5c = 0;
            if (uVar24 != 0) {
              local_54 = local_50;
              do {
                if (local_54[(int)local_6c - (int)local_50] != 0) {
                  iVar15 = local_54[(int)local_6c - (int)local_50] - 1;
                  *local_54 = *local_54 | (byte)iVar15;
                  iVar29 = -iVar33;
                  iVar22 = iVar33 + 1;
                  iVar15 = iVar15 * 0x10;
                  if (iVar29 < iVar22) {
                    pbVar45 = local_50 + iVar29 * iVar36 + local_5c;
                    local_80 = (uint *)(iVar22 + iVar33);
                    iVar48 = iVar29;
                    do {
                      for (; iVar48 < iVar22; iVar48 = iVar48 + 1) {
                        if ((int)(pbVar45[iVar48] & 0xf0) < iVar15) {
                          pbVar45[iVar48] = pbVar45[iVar48] & 0xf | (byte)iVar15;
                        }
                      }
                      pbVar45 = pbVar45 + iVar36;
                      local_80 = (uint *)((int)local_80 + -1);
                      iVar48 = iVar29;
                    } while (local_80 != (uint *)0x0);
                  }
                }
                local_5c = local_5c + 1;
                local_54 = local_54 + 1;
              } while ((int)local_5c < (int)uVar24);
            }
            local_50 = local_50 + iVar36;
            local_6c = local_6c + param_9;
            local_48 = (ushort *)((int)local_48 - 1);
          } while (local_48 != (ushort *)0x0);
        }
      }
    }
    else {
      iVar36 = *(int *)(param_1 + 0x935ec);
      iVar29 = (uint)*(byte *)(param_1 + 0x931c0) * (local_20 + iVar22) +
               (local_14 + iVar22) * iVar36 + *(int *)(param_1 + 0x935f0);
      iVar15 = *(int *)(param_1 + 0x935e4) / 2;
      uVar44 = *(uint *)(param_1 + 0x931d4) | *(uint *)(param_1 + 0x931d0) |
               *(uint *)(param_1 + 0x931cc);
      uVar14 = *(uint *)(param_1 + 0x931d8) | uVar44;
      local_79 = 0;
      uVar43 = (ushort)uVar14;
      uVar35 = (ushort)uVar44;
      local_60 = local_6c;
      local_58 = uVar25;
      local_54 = (byte *)uVar25;
      local_30 = uVar25;
      switch(param_5) {
      case 0:
        if (iVar33 == 1) {
          if (*(char *)(param_1 + 0x931c1) == '\b') {
            if (uVar25 != 0) {
              iVar48 = (iVar15 - iVar36) + 1 + iVar29;
              iVar33 = iVar15 + iVar29 + 1;
              iVar28 = iVar29;
              do {
                iVar33 = iVar33 + iVar36;
                uVar44 = 0;
                if (uVar24 != 0) {
                  do {
                    if ((uVar44 & 7) == 0) {
                      local_79 = local_60[(int)uVar44 >> 3];
                    }
                    if ((local_79 & 0x80) != 0) {
                      *(undefined1 *)(iVar28 + uVar44) = 1;
                      *(undefined1 *)(iVar48 + -1 + uVar44) = 1;
                      *(undefined1 *)(iVar33 + -1 + uVar44) = 1;
                      *(undefined1 *)(iVar48 + -2 + iVar36 + uVar44) = 1;
                      *(undefined1 *)(iVar48 + uVar44 + iVar36) = 1;
                      *(undefined1 *)(iVar48 + -2 + uVar44) = 1;
                      *(undefined1 *)(iVar48 + uVar44) = 1;
                      *(undefined1 *)(iVar33 + -2 + uVar44) = 1;
                      *(undefined1 *)(iVar33 + uVar44) = 1;
                    }
                    local_79 = local_79 << 1;
                    uVar44 = uVar44 + 1;
                  } while ((int)uVar44 < (int)uVar24);
                }
                local_60 = local_60 + param_9;
                iVar28 = iVar28 + iVar36;
                iVar48 = iVar48 + iVar36;
                local_80 = (uint *)((int)local_80 - 1);
              } while (local_80 != (uint *)0x0);
            }
          }
          else if (uVar25 != 0) {
            iVar33 = iVar29;
            do {
              uVar44 = 0;
              if (uVar24 != 0) {
                puVar30 = (undefined2 *)(iVar33 + iVar36 + 2 + iVar15 * 2);
                puVar16 = (undefined2 *)((iVar33 - iVar36) + 2 + iVar15 * 2);
                do {
                  if ((uVar44 & 7) == 0) {
                    local_79 = local_60[(int)uVar44 >> 3];
                  }
                  if ((local_79 & 0x80) != 0) {
                    *(undefined2 *)(iVar33 + uVar44 * 2) = 1;
                    puVar16[-1] = 1;
                    puVar30[-1] = 1;
                    *(undefined2 *)(iVar36 + -4 + (int)puVar16) = 1;
                    *(undefined2 *)(iVar36 + (int)puVar16) = 1;
                    puVar16[-2] = 1;
                    *puVar16 = 1;
                    puVar30[-2] = 1;
                    *puVar30 = 1;
                  }
                  local_79 = local_79 << 1;
                  uVar44 = uVar44 + 1;
                  puVar16 = puVar16 + 1;
                  puVar30 = puVar30 + 1;
                } while ((int)uVar44 < (int)uVar24);
              }
              local_60 = local_60 + param_9;
              iVar33 = iVar33 + iVar36;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
        else if (iVar33 < 5) {
          if (*(char *)(param_1 + 0x931c1) == '\b') {
            if (uVar25 != 0) {
              iVar48 = iVar29;
              do {
                local_5c = 0;
                if (uVar24 != 0) {
                  do {
                    uVar44 = local_5c & 0x80000007;
                    bVar49 = uVar44 == 0;
                    if ((int)uVar44 < 0) {
                      bVar49 = (uVar44 - 1 | 0xfffffff8) == 0xffffffff;
                    }
                    if (bVar49) {
                      local_79 = local_60[(int)(local_5c + ((int)local_5c >> 0x1f & 7U)) >> 3];
                    }
                    if ((local_79 & 0x80) != 0) {
                      iVar47 = -iVar33;
                      iVar28 = iVar33 + 1;
                      *(undefined1 *)(iVar48 + local_5c) = 1;
                      if (iVar47 < iVar28) {
                        iVar42 = iVar47 * iVar36 + iVar48 + iVar15 + local_5c;
                        iVar32 = iVar28 + iVar33;
                        local_3c = pcVar26;
                        do {
                          if (iVar47 < iVar28) {
                            iVar31 = iVar47;
                            pcVar46 = local_3c;
                            do {
                              if ((*pcVar46 != '\0') && (*(char *)(iVar31 + iVar42) == '\0')) {
                                *(undefined1 *)(iVar31 + iVar42) = 1;
                              }
                              iVar31 = iVar31 + 1;
                              pcVar46 = pcVar46 + 1;
                            } while (iVar31 < iVar28);
                          }
                          local_3c = local_3c + 9;
                          iVar42 = iVar42 + iVar36;
                          iVar32 = iVar32 + -1;
                        } while (iVar32 != 0);
                      }
                    }
                    local_79 = local_79 << 1;
                    local_5c = local_5c + 1;
                  } while ((int)local_5c < (int)uVar24);
                }
                local_60 = local_60 + param_9;
                iVar48 = iVar48 + iVar36;
                local_80 = (uint *)((int)local_80 - 1);
              } while (local_80 != (uint *)0x0);
            }
          }
          else if (uVar25 != 0) {
            iVar48 = iVar29;
            do {
              uVar44 = 0;
              if (uVar24 != 0) {
                do {
                  uVar14 = uVar44 & 0x80000007;
                  bVar49 = uVar14 == 0;
                  if ((int)uVar14 < 0) {
                    bVar49 = (uVar14 - 1 | 0xfffffff8) == 0xffffffff;
                  }
                  if (bVar49) {
                    local_79 = local_60[(int)(uVar44 + ((int)uVar44 >> 0x1f & 7U)) >> 3];
                  }
                  if ((local_79 & 0x80) != 0) {
                    iVar28 = -iVar33;
                    iVar47 = iVar33 + 1;
                    *(undefined2 *)(iVar48 + uVar44 * 2) = 1;
                    if (iVar28 < iVar47) {
                      iVar32 = iVar28 * iVar36;
                      local_54 = (byte *)(iVar47 + iVar33);
                      iVar42 = iVar28;
                      pcVar46 = pcVar26;
                      local_80 = (uint *)pcVar26;
                      do {
                        for (; iVar42 < iVar47; iVar42 = iVar42 + 1) {
                          if ((*pcVar46 != '\0') &&
                             (psVar17 = (short *)(iVar48 + (iVar15 + iVar42 + uVar44) * 2 + iVar32),
                             *psVar17 == 0)) {
                            *psVar17 = 1;
                          }
                          pcVar46 = pcVar46 + 1;
                        }
                        iVar32 = iVar32 + iVar36;
                        pcVar46 = (char *)((int)local_80 + 9);
                        local_54 = (byte *)((int)local_54 + -1);
                        iVar42 = iVar28;
                        local_80 = (uint *)pcVar46;
                      } while (local_54 != (byte *)0x0);
                    }
                  }
                  local_79 = local_79 << 1;
                  uVar44 = uVar44 + 1;
                } while ((int)uVar44 < (int)uVar24);
              }
              local_60 = local_60 + param_9;
              iVar48 = iVar48 + iVar36;
              local_48 = (ushort *)((int)local_48 - 1);
            } while (local_48 != (ushort *)0x0);
          }
        }
        else if (*(char *)(param_1 + 0x931c1) == '\b') {
          if (uVar25 != 0) {
            iVar48 = iVar29;
            do {
              uVar44 = 0;
              if (uVar24 != 0) {
                do {
                  uVar14 = uVar44 & 0x80000007;
                  bVar49 = uVar14 == 0;
                  if ((int)uVar14 < 0) {
                    bVar49 = (uVar14 - 1 | 0xfffffff8) == 0xffffffff;
                  }
                  if (bVar49) {
                    local_79 = local_60[(int)(uVar44 + ((int)uVar44 >> 0x1f & 7U)) >> 3];
                  }
                  if ((local_79 & 0x80) != 0) {
                    iVar47 = -iVar33;
                    iVar28 = iVar33 + 1;
                    *(undefined1 *)(iVar48 + uVar44) = 1;
                    if (iVar47 < iVar28) {
                      iVar32 = iVar47 * iVar36 + iVar48 + iVar15 + uVar44;
                      iVar31 = iVar28 + iVar33;
                      iVar42 = iVar47;
                      do {
                        for (; iVar42 < iVar28; iVar42 = iVar42 + 1) {
                          if (*(char *)(iVar42 + iVar32) == '\0') {
                            *(undefined1 *)(iVar42 + iVar32) = 1;
                          }
                        }
                        iVar32 = iVar32 + iVar36;
                        iVar31 = iVar31 + -1;
                        iVar42 = iVar47;
                      } while (iVar31 != 0);
                    }
                  }
                  local_79 = local_79 << 1;
                  uVar44 = uVar44 + 1;
                } while ((int)uVar44 < (int)uVar24);
              }
              local_60 = local_60 + param_9;
              iVar48 = iVar48 + iVar36;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
        else if (uVar25 != 0) {
          iVar48 = iVar29;
          do {
            uVar44 = 0;
            if (uVar24 != 0) {
              do {
                uVar14 = uVar44 & 0x80000007;
                bVar49 = uVar14 == 0;
                if ((int)uVar14 < 0) {
                  bVar49 = (uVar14 - 1 | 0xfffffff8) == 0xffffffff;
                }
                if (bVar49) {
                  local_79 = local_60[(int)(uVar44 + ((int)uVar44 >> 0x1f & 7U)) >> 3];
                }
                if ((local_79 & 0x80) != 0) {
                  iVar28 = -iVar33;
                  iVar47 = iVar33 + 1;
                  *(undefined2 *)(iVar48 + uVar44 * 2) = 1;
                  if (iVar28 < iVar47) {
                    iVar42 = iVar28 * iVar36;
                    local_80 = (uint *)(iVar47 + iVar33);
                    do {
                      if (iVar28 < iVar47) {
                        psVar17 = (short *)(iVar48 + (iVar15 + iVar28 + uVar44) * 2 + iVar42);
                        iVar32 = iVar47 + iVar33;
                        do {
                          if (*psVar17 == 0) {
                            *psVar17 = 1;
                          }
                          psVar17 = psVar17 + 1;
                          iVar32 = iVar32 + -1;
                        } while (iVar32 != 0);
                      }
                      iVar42 = iVar42 + iVar36;
                      local_80 = (uint *)((int)local_80 + -1);
                    } while (local_80 != (uint *)0x0);
                  }
                }
                local_79 = local_79 << 1;
                uVar44 = uVar44 + 1;
              } while ((int)uVar44 < (int)uVar24);
            }
            local_60 = local_60 + param_9;
            iVar48 = iVar48 + iVar36;
            local_54 = (byte *)((int)local_54 - 1);
          } while (local_54 != (byte *)0x0);
        }
        if (*(char *)(param_1 + 0x931c1) == '\b') {
          pcVar26 = (char *)((iVar29 - iVar36 * iVar22) - iVar22);
          if (*(int *)(param_1 + 0x931e0) == 0xf) {
            local_80 = (uint *)(local_34 + uVar25);
            if (0 < (int)local_80) {
              do {
                if (0 < (int)(uVar24 + local_34)) {
                  psVar17 = (short *)(pcVar26 + iVar15 * 2);
                  pcVar46 = pcVar26;
                  iVar22 = uVar24 + local_34;
                  do {
                    if (*pcVar46 == '\0') {
                      *pcVar46 = '\0';
                      pcVar46[iVar15] = -(*psVar17 != 0) & 0xf;
                    }
                    else {
                      *pcVar46 = '\x0f';
                      pcVar46[iVar15] = '\0';
                    }
                    psVar17 = psVar17 + 1;
                    pcVar46 = pcVar46 + 1;
                    iVar22 = iVar22 + -1;
                  } while (iVar22 != 0);
                }
                pcVar26 = pcVar26 + iVar36;
                local_80 = (uint *)((int)local_80 + -1);
              } while (local_80 != (uint *)0x0);
            }
          }
          else {
            local_80 = (uint *)(uVar25 + local_34);
            if (0 < (int)local_80) {
              do {
                if (0 < (int)(local_34 + uVar24)) {
                  psVar17 = (short *)(pcVar26 + iVar15 * 2);
                  pcVar46 = pcVar26;
                  iVar22 = local_34 + uVar24;
                  do {
                    if (*pcVar46 == '\0') {
                      *pcVar46 = '\0';
                      pcVar46[iVar15] = -(*psVar17 != 0);
                    }
                    else {
                      *pcVar46 = -1;
                      pcVar46[iVar15] = '\0';
                    }
                    psVar17 = psVar17 + 1;
                    pcVar46 = pcVar46 + 1;
                    iVar22 = iVar22 + -1;
                  } while (iVar22 != 0);
                }
                pcVar26 = pcVar26 + iVar36;
                local_80 = (uint *)((int)local_80 + -1);
              } while (local_80 != (uint *)0x0);
            }
          }
        }
        else {
          iVar29 = (iVar22 * -2 - iVar36 * iVar22) + iVar29;
          if (*(int *)(param_1 + 0x93600) == 0) {
            local_80 = (uint *)(local_34 + uVar25);
            if (0 < (int)local_80) {
              do {
                iVar22 = 0;
                if (0 < (int)(uVar24 + local_34)) {
                  puVar19 = (ushort *)(iVar29 + iVar15 * 2);
                  do {
                    if (*(short *)(iVar29 + iVar22 * 2) == 0) {
                      *(ushort *)(iVar29 + iVar22 * 2) = uVar35;
                      uVar39 = uVar43;
                      if (*puVar19 == 0) {
                        uVar39 = uVar35;
                      }
                      *puVar19 = uVar39;
                    }
                    else {
                      *(ushort *)(iVar29 + iVar22 * 2) = uVar43;
                      *puVar19 = uVar35;
                    }
                    iVar22 = iVar22 + 1;
                    puVar19 = puVar19 + 1;
                  } while (iVar22 < (int)(uVar24 + local_34));
                }
                iVar29 = iVar29 + iVar36;
                local_80 = (uint *)((int)local_80 + -1);
              } while (local_80 != (uint *)0x0);
            }
          }
          else {
            iVar22 = local_34 + uVar25;
            if (0 < iVar22) {
              do {
                iVar33 = 0;
                if (0 < (int)(uVar24 + local_34)) {
                  puVar19 = (ushort *)(iVar29 + iVar15 * 2);
                  do {
                    if (*(short *)(iVar29 + iVar33 * 2) == 0) {
                      *(undefined2 *)(iVar29 + iVar33 * 2) = 0;
                      *puVar19 = -(ushort)(*puVar19 != 0) & uVar43;
                    }
                    else {
                      *(ushort *)(iVar29 + iVar33 * 2) = uVar43;
                      *puVar19 = 0;
                    }
                    iVar33 = iVar33 + 1;
                    puVar19 = puVar19 + 1;
                  } while (iVar33 < (int)(uVar24 + local_34));
                }
                iVar29 = iVar29 + iVar36;
                iVar22 = iVar22 + -1;
              } while (iVar22 != 0);
            }
          }
        }
        break;
      case 5:
        if (iVar33 == 1) {
          if (*(char *)(param_1 + 0x931c1) == '\b') {
            if (uVar25 != 0) {
              iVar48 = (iVar15 - iVar36) + 1 + iVar29;
              iVar33 = iVar15 + iVar29 + 1;
              iVar28 = iVar29;
              do {
                iVar33 = iVar33 + iVar36;
                iVar47 = 0;
                if (uVar24 != 0) {
                  do {
                    if (((undefined1 *)(iVar28 + iVar47))[(int)local_60 - iVar28] != '\0') {
                      *(undefined1 *)(iVar28 + iVar47) = 1;
                      *(undefined1 *)(iVar48 + -1 + iVar47) = 1;
                      *(undefined1 *)(iVar33 + -1 + iVar47) = 1;
                      *(undefined1 *)(iVar36 + -2 + iVar48 + iVar47) = 1;
                      *(undefined1 *)(iVar48 + iVar47 + iVar36) = 1;
                      *(undefined1 *)(iVar48 + -2 + iVar47) = 1;
                      *(undefined1 *)(iVar48 + iVar47) = 1;
                      *(undefined1 *)(iVar33 + -2 + iVar47) = 1;
                      *(undefined1 *)(iVar33 + iVar47) = 1;
                    }
                    iVar47 = iVar47 + 1;
                  } while (iVar47 < (int)uVar24);
                }
                local_60 = local_60 + param_9;
                iVar28 = iVar28 + iVar36;
                iVar48 = iVar48 + iVar36;
                local_80 = (uint *)((int)local_80 - 1);
              } while (local_80 != (uint *)0x0);
            }
          }
          else if (uVar25 != 0) {
            iVar33 = iVar29;
            do {
              iVar48 = 0;
              if (uVar24 != 0) {
                puVar30 = (undefined2 *)(iVar33 + iVar36 + 2 + iVar15 * 2);
                puVar16 = (undefined2 *)((iVar33 - iVar36) + 2 + iVar15 * 2);
                do {
                  if (local_60[iVar48] != '\0') {
                    *(undefined2 *)(iVar33 + iVar48 * 2) = 1;
                    puVar16[-1] = 1;
                    puVar30[-1] = 1;
                    *(undefined2 *)(iVar36 + -4 + (int)puVar16) = 1;
                    *(undefined2 *)(iVar36 + (int)puVar16) = 1;
                    puVar16[-2] = 1;
                    *puVar16 = 1;
                    puVar30[-2] = 1;
                    *puVar30 = 1;
                  }
                  iVar48 = iVar48 + 1;
                  puVar16 = puVar16 + 1;
                  puVar30 = puVar30 + 1;
                } while (iVar48 < (int)uVar24);
              }
              local_60 = local_60 + param_9;
              iVar33 = iVar33 + iVar36;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
        else if (iVar33 < 5) {
          if (*(char *)(param_1 + 0x931c1) == '\b') {
            if (uVar25 != 0) {
              iVar48 = iVar29;
              do {
                local_5c = 0;
                if (uVar24 != 0) {
                  do {
                    if (((undefined1 *)(iVar48 + local_5c))[(int)local_60 - iVar48] != '\0') {
                      iVar47 = -iVar33;
                      iVar28 = iVar33 + 1;
                      *(undefined1 *)(iVar48 + local_5c) = 1;
                      if (iVar47 < iVar28) {
                        iVar42 = iVar47 * iVar36 + iVar48 + iVar15 + local_5c;
                        iVar32 = iVar28 + iVar33;
                        local_3c = pcVar26;
                        do {
                          if (iVar47 < iVar28) {
                            iVar31 = iVar47;
                            pcVar46 = local_3c;
                            do {
                              if ((*pcVar46 != '\0') && (*(char *)(iVar31 + iVar42) == '\0')) {
                                *(undefined1 *)(iVar31 + iVar42) = 1;
                              }
                              iVar31 = iVar31 + 1;
                              pcVar46 = pcVar46 + 1;
                            } while (iVar31 < iVar28);
                          }
                          local_3c = local_3c + 9;
                          iVar42 = iVar42 + iVar36;
                          iVar32 = iVar32 + -1;
                        } while (iVar32 != 0);
                      }
                    }
                    local_5c = local_5c + 1;
                  } while ((int)local_5c < (int)uVar24);
                }
                local_60 = local_60 + param_9;
                iVar48 = iVar48 + iVar36;
                local_80 = (uint *)((int)local_80 - 1);
              } while (local_80 != (uint *)0x0);
            }
          }
          else if (uVar25 != 0) {
            local_48 = (ushort *)((int)local_6c - iVar15);
            iVar48 = iVar29;
            local_50 = (byte *)uVar25;
            do {
              local_5c = 0;
              if (uVar24 != 0) {
                local_3c = (char *)iVar15;
                do {
                  if (*(char *)((int)local_48 + (int)local_3c) != '\0') {
                    iVar28 = -iVar33;
                    iVar47 = iVar33 + 1;
                    *(undefined2 *)(iVar48 + local_5c * 2) = 1;
                    if (iVar28 < iVar47) {
                      iVar32 = iVar28 * iVar36;
                      local_54 = (byte *)(iVar47 + iVar33);
                      iVar42 = iVar28;
                      pcVar46 = pcVar26;
                      local_80 = (uint *)pcVar26;
                      do {
                        for (; iVar42 < iVar47; iVar42 = iVar42 + 1) {
                          if ((*pcVar46 != '\0') &&
                             (psVar17 = (short *)(iVar48 + ((int)local_3c + iVar42) * 2 + iVar32),
                             *psVar17 == 0)) {
                            *psVar17 = 1;
                          }
                          pcVar46 = pcVar46 + 1;
                        }
                        iVar32 = iVar32 + iVar36;
                        pcVar46 = (char *)((int)local_80 + 9);
                        local_54 = (byte *)((int)local_54 + -1);
                        iVar42 = iVar28;
                        local_80 = (uint *)pcVar46;
                      } while (local_54 != (byte *)0x0);
                    }
                  }
                  local_3c = (char *)((int)local_3c + 1);
                  local_5c = local_5c + 1;
                } while ((int)local_5c < (int)uVar24);
              }
              local_48 = (ushort *)((int)local_48 + param_9);
              iVar48 = iVar48 + iVar36;
              local_50 = (byte *)((int)local_50 - 1);
            } while (local_50 != (byte *)0x0);
          }
        }
        else if (*(char *)(param_1 + 0x931c1) == '\b') {
          if (uVar25 != 0) {
            iVar48 = iVar29;
            do {
              local_5c = 0;
              if (uVar24 != 0) {
                do {
                  if (((undefined1 *)(iVar48 + local_5c))[(int)local_60 - iVar48] != '\0') {
                    iVar47 = -iVar33;
                    iVar28 = iVar33 + 1;
                    *(undefined1 *)(iVar48 + local_5c) = 1;
                    if (iVar47 < iVar28) {
                      iVar32 = iVar47 * iVar36 + iVar48 + iVar15 + local_5c;
                      iVar31 = iVar28 + iVar33;
                      iVar42 = iVar47;
                      do {
                        for (; iVar42 < iVar28; iVar42 = iVar42 + 1) {
                          if (*(char *)(iVar32 + iVar42) == '\0') {
                            *(undefined1 *)(iVar32 + iVar42) = 1;
                          }
                        }
                        iVar32 = iVar32 + iVar36;
                        iVar31 = iVar31 + -1;
                        iVar42 = iVar47;
                      } while (iVar31 != 0);
                    }
                  }
                  local_5c = local_5c + 1;
                } while ((int)local_5c < (int)uVar24);
              }
              local_60 = local_60 + param_9;
              iVar48 = iVar48 + iVar36;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
        else if (uVar25 != 0) {
          iVar48 = iVar29;
          do {
            iVar28 = 0;
            if (uVar24 != 0) {
              do {
                if (local_60[iVar28] != '\0') {
                  iVar47 = -iVar33;
                  iVar42 = iVar33 + 1;
                  *(undefined2 *)(iVar48 + iVar28 * 2) = 1;
                  if (iVar47 < iVar42) {
                    iVar32 = iVar47 * iVar36;
                    local_80 = (uint *)(iVar42 + iVar33);
                    do {
                      if (iVar47 < iVar42) {
                        psVar17 = (short *)(iVar48 + (iVar15 + iVar47 + iVar28) * 2 + iVar32);
                        iVar31 = iVar42 + iVar33;
                        do {
                          if (*psVar17 == 0) {
                            *psVar17 = 1;
                          }
                          psVar17 = psVar17 + 1;
                          iVar31 = iVar31 + -1;
                        } while (iVar31 != 0);
                      }
                      iVar32 = iVar32 + iVar36;
                      local_80 = (uint *)((int)local_80 + -1);
                    } while (local_80 != (uint *)0x0);
                  }
                }
                iVar28 = iVar28 + 1;
              } while (iVar28 < (int)uVar24);
            }
            local_60 = local_60 + param_9;
            iVar48 = iVar48 + iVar36;
            local_54 = (byte *)((int)local_54 - 1);
          } while (local_54 != (byte *)0x0);
        }
        if (*(char *)(param_1 + 0x931c1) == '\b') {
          iVar22 = (iVar29 - iVar36 * iVar22) - iVar22;
          if (*(int *)(param_1 + 0x931e0) == 0xf) {
            iVar33 = uVar25 + local_34;
            if (0 < iVar33) {
              do {
                iVar29 = 0;
                if (0 < (int)(uVar24 + local_34)) {
                  iVar48 = iVar15 + iVar22;
                  do {
                    if (*(char *)(iVar22 + iVar29) == '\0') {
                      *(undefined1 *)(iVar22 + iVar29) = 0;
                      *(byte *)(iVar29 + iVar48) = -(*(char *)(iVar29 + iVar48) != '\0') & 0xf;
                    }
                    else {
                      *(undefined1 *)(iVar22 + iVar29) = 0xf;
                      *(undefined1 *)(iVar29 + iVar48) = 0;
                    }
                    iVar29 = iVar29 + 1;
                  } while (iVar29 < (int)(uVar24 + local_34));
                }
                iVar22 = iVar22 + iVar36;
                iVar33 = iVar33 + -1;
              } while (iVar33 != 0);
            }
          }
          else {
            iVar33 = local_34 + uVar25;
            if (0 < iVar33) {
              do {
                iVar29 = 0;
                if (0 < (int)(uVar24 + local_34)) {
                  iVar48 = iVar15 + iVar22;
                  do {
                    if (*(char *)(iVar22 + iVar29) == '\0') {
                      *(undefined1 *)(iVar22 + iVar29) = 0;
                      *(char *)(iVar29 + iVar48) = -(*(char *)(iVar29 + iVar48) != '\0');
                    }
                    else {
                      *(undefined1 *)(iVar22 + iVar29) = 0xff;
                      *(undefined1 *)(iVar29 + iVar48) = 0;
                    }
                    iVar29 = iVar29 + 1;
                  } while (iVar29 < (int)(uVar24 + local_34));
                }
                iVar22 = iVar22 + iVar36;
                iVar33 = iVar33 + -1;
              } while (iVar33 != 0);
            }
          }
        }
        else {
          iVar29 = (iVar22 * -2 - iVar36 * iVar22) + iVar29;
          if (*(int *)(param_1 + 0x93600) == 0) {
            local_80 = (uint *)(local_34 + uVar25);
            if (0 < (int)local_80) {
              do {
                if (0 < (int)(uVar24 + local_34)) {
                  puVar19 = (ushort *)(iVar29 + iVar15 * 2);
                  iVar22 = 0;
                  do {
                    if (*(short *)(iVar29 + iVar22 * 2) == 0) {
                      *(ushort *)(iVar29 + iVar22 * 2) = uVar35;
                      uVar39 = uVar43;
                      if (*puVar19 == 0) {
                        uVar39 = uVar35;
                      }
                      *puVar19 = uVar39;
                    }
                    else {
                      *(ushort *)(iVar29 + iVar22 * 2) = uVar43;
                      *puVar19 = uVar35;
                    }
                    iVar22 = iVar22 + 1;
                    puVar19 = puVar19 + 1;
                  } while (iVar22 < (int)(uVar24 + local_34));
                }
                iVar29 = iVar29 + iVar36;
                local_80 = (uint *)((int)local_80 + -1);
              } while (local_80 != (uint *)0x0);
            }
          }
          else {
            iVar22 = local_34 + uVar25;
            if (0 < iVar22) {
              do {
                iVar33 = 0;
                if (0 < (int)(uVar24 + local_34)) {
                  puVar19 = (ushort *)(iVar29 + iVar15 * 2);
                  do {
                    if (*(short *)(iVar29 + iVar33 * 2) == 0) {
                      *(undefined2 *)(iVar29 + iVar33 * 2) = 0;
                      *puVar19 = -(ushort)(*puVar19 != 0) & uVar43;
                    }
                    else {
                      *(ushort *)(iVar29 + iVar33 * 2) = uVar43;
                      *puVar19 = 0;
                    }
                    iVar33 = iVar33 + 1;
                    puVar19 = puVar19 + 1;
                  } while (iVar33 < (int)(uVar24 + local_34));
                }
                iVar29 = iVar29 + iVar36;
                iVar22 = iVar22 + -1;
              } while (iVar22 != 0);
            }
          }
        }
        break;
      case 6:
        if (iVar33 == 1) {
          if (*(char *)(param_1 + 0x931c1) == '\b') {
            if (uVar25 != 0) {
              local_44 = iVar15 + iVar29 + 1;
              local_80 = (uint *)((iVar15 - iVar36) + 1 + iVar29);
              local_6c = (char *)iVar29;
              do {
                local_44 = local_44 + iVar36;
                iVar33 = 0;
                if (uVar24 != 0) {
                  puVar19 = (ushort *)((int)local_6c + iVar36 + 2 + iVar15 * 2);
                  puVar18 = (ushort *)(((int)local_6c - iVar36) + 2 + iVar15 * 2);
                  do {
                    bVar12 = ((byte *)((int)local_6c + iVar33))[(int)local_60 - (int)local_6c];
                    uVar44 = (uint)bVar12;
                    if (uVar44 != 0) {
                      *(byte *)((int)local_6c + iVar33) = bVar12;
                      *(char *)(iVar33 + -1 + (int)local_80) =
                           (char)((0x10 - (uint)puVar18[-1]) * uVar44 >> 4) + (char)puVar18[-1];
                      *(char *)(local_44 + -1 + iVar33) =
                           (char)((0x10 - (uint)puVar19[-1]) * uVar44 >> 4) + (char)puVar19[-1];
                      *(char *)(iVar36 + -2 + (int)local_80 + iVar33) =
                           (char)((0x10 - (uint)*(ushort *)((int)puVar18 + iVar36 + -4)) * uVar44 >>
                                 4) + *(char *)((int)puVar18 + iVar36 + -4);
                      *(char *)(iVar36 + (int)local_80 + iVar33) =
                           (char)((0x10 - (uint)*(ushort *)(iVar36 + (int)puVar18)) * uVar44 >> 4) +
                           *(char *)(iVar36 + (int)puVar18);
                      *(char *)(iVar33 + -2 + (int)local_80) =
                           (char)((0x10 - (uint)puVar18[-2]) * uVar44 >> 4) + (char)puVar18[-2];
                      *(char *)(iVar33 + (int)local_80) =
                           (char)((0x10 - (uint)*puVar18) * uVar44 >> 4) + (char)*puVar18;
                      *(char *)(local_44 + -2 + iVar33) =
                           (char)((0x10 - (uint)puVar19[-2]) * uVar44 >> 4) + (char)puVar19[-2];
                      *(char *)(local_44 + iVar33) =
                           (char)((0x10 - (uint)*puVar19) * uVar44 >> 4) + (char)*puVar19;
                    }
                    iVar33 = iVar33 + 1;
                    puVar18 = puVar18 + 1;
                    puVar19 = puVar19 + 1;
                  } while (iVar33 < (int)uVar24);
                }
                local_60 = local_60 + param_9;
                local_80 = (uint *)((int)local_80 + iVar36);
                local_54 = (byte *)((int)local_54 - 1);
                local_6c = (char *)((int)local_6c + iVar36);
              } while (local_54 != (byte *)0x0);
            }
          }
          else if (uVar25 != 0) {
            local_6c = (char *)iVar29;
            do {
              iVar33 = 0;
              if (uVar24 != 0) {
                puVar19 = (ushort *)((int)local_6c + iVar36 + 2 + iVar15 * 2);
                puVar18 = (ushort *)(((int)local_6c - iVar36) + 2 + iVar15 * 2);
                do {
                  uVar44 = (uint)(byte)local_60[iVar33];
                  if (uVar44 != 0) {
                    *(ushort *)((int)local_6c + iVar33 * 2) = (ushort)(byte)local_60[iVar33];
                    puVar18[-1] = (short)((0x10 - (uint)puVar18[-1]) * uVar44 >> 4) + puVar18[-1];
                    puVar19[-1] = (short)((0x10 - (uint)puVar19[-1]) * uVar44 >> 4) + puVar19[-1];
                    uVar43 = *(ushort *)((int)puVar18 + iVar36 + -4);
                    *(ushort *)((int)puVar18 + iVar36 + -4) =
                         (short)((0x10 - (uint)uVar43) * uVar44 >> 4) + uVar43;
                    *(ushort *)(iVar36 + (int)puVar18) =
                         (short)((0x10 - (uint)*(ushort *)(iVar36 + (int)puVar18)) * uVar44 >> 4) +
                         *(ushort *)(iVar36 + (int)puVar18);
                    puVar18[-2] = (short)((0x10 - (uint)puVar18[-2]) * uVar44 >> 4) + puVar18[-2];
                    *puVar18 = (short)((0x10 - (uint)*puVar18) * uVar44 >> 4) + *puVar18;
                    puVar19[-2] = (short)((0x10 - (uint)puVar19[-2]) * uVar44 >> 4) + puVar19[-2];
                    *puVar19 = (short)((0x10 - (uint)*puVar19) * uVar44 >> 4) + *puVar19;
                  }
                  iVar33 = iVar33 + 1;
                  puVar18 = puVar18 + 1;
                  puVar19 = puVar19 + 1;
                } while (iVar33 < (int)uVar24);
              }
              local_60 = local_60 + param_9;
              local_80 = (uint *)((int)local_80 - 1);
              local_6c = (char *)((int)local_6c + iVar36);
            } while (local_80 != (uint *)0x0);
          }
        }
        else if (iVar33 < 5) {
          if (*(char *)(param_1 + 0x931c1) == '\b') {
            if (uVar25 != 0) {
              iVar48 = iVar29;
              do {
                local_5c = 0;
                if (uVar24 != 0) {
                  do {
                    bVar12 = ((byte *)(iVar48 + local_5c))[(int)local_60 - iVar48];
                    if (bVar12 != 0) {
                      iVar47 = -iVar33;
                      iVar28 = iVar33 + 1;
                      *(byte *)(iVar48 + local_5c) = bVar12;
                      if (iVar47 < iVar28) {
                        iVar42 = iVar47 * iVar36 + iVar48 + iVar15 + local_5c;
                        local_80 = (uint *)(iVar28 + iVar33);
                        local_48 = (ushort *)pcVar26;
                        do {
                          if (iVar47 < iVar28) {
                            local_24 = (char *)local_48;
                            iVar32 = iVar47;
                            do {
                              if (*local_24 != '\0') {
                                *(char *)(iVar42 + iVar32) =
                                     (char)(0x100 - (0x10 - (uint)*(byte *)(iVar42 + iVar32)) *
                                                    (0x10 - (uint)bVar12) >> 4);
                              }
                              local_24 = local_24 + 1;
                              iVar32 = iVar32 + 1;
                            } while (iVar32 < iVar28);
                          }
                          local_48 = (ushort *)((int)local_48 + 9);
                          iVar42 = iVar42 + iVar36;
                          local_80 = (uint *)((int)local_80 + -1);
                        } while (local_80 != (uint *)0x0);
                      }
                    }
                    local_5c = local_5c + 1;
                  } while ((int)local_5c < (int)uVar24);
                }
                local_60 = local_60 + param_9;
                iVar48 = iVar48 + iVar36;
                local_54 = (byte *)((int)local_54 - 1);
              } while (local_54 != (byte *)0x0);
            }
          }
          else if (uVar25 != 0) {
            local_50 = (byte *)((int)local_6c - iVar15);
            iVar48 = iVar29;
            local_6c = (char *)uVar25;
            do {
              local_5c = 0;
              if (uVar24 != 0) {
                local_54 = (byte *)iVar15;
                do {
                  bVar12 = *(byte *)((int)local_50 + (int)local_54);
                  if (bVar12 != 0) {
                    iVar28 = -iVar33;
                    *(ushort *)(iVar48 + local_5c * 2) = (ushort)bVar12;
                    if (iVar28 < iVar33 + 1) {
                      iVar47 = iVar28 * iVar36;
                      local_80 = (uint *)(iVar33 + 1 + iVar33);
                      local_24 = pcVar26;
                      do {
                        if (iVar28 < iVar33 + 1) {
                          local_48 = (ushort *)local_24;
                          iVar42 = iVar28;
                          do {
                            if ((char)*local_48 != '\0') {
                              iVar32 = iVar47 + ((int)local_54 + iVar42) * 2;
                              *(short *)(iVar32 + iVar48) =
                                   (short)(0x100 - (0x10 - (uint)*(ushort *)(iVar32 + iVar48)) *
                                                   (0x10 - (uint)bVar12) >> 4);
                            }
                            local_48 = (ushort *)((int)local_48 + 1);
                            iVar42 = iVar42 + 1;
                          } while (iVar42 < iVar33 + 1);
                        }
                        local_24 = local_24 + 9;
                        iVar47 = iVar47 + iVar36;
                        local_80 = (uint *)((int)local_80 + -1);
                      } while (local_80 != (uint *)0x0);
                    }
                  }
                  local_5c = local_5c + 1;
                  local_54 = (byte *)((int)local_54 + 1);
                } while ((int)local_5c < (int)uVar24);
              }
              local_50 = (byte *)((int)local_50 + param_9);
              iVar48 = iVar48 + iVar36;
              local_6c = (char *)((int)local_6c - 1);
            } while (local_6c != (char *)0x0);
          }
        }
        else if (*(char *)(param_1 + 0x931c1) == '\b') {
          if (uVar25 != 0) {
            iVar48 = iVar29;
            do {
              local_5c = 0;
              if (uVar24 != 0) {
                do {
                  bVar12 = ((byte *)(iVar48 + local_5c))[(int)local_60 - iVar48];
                  if (bVar12 != 0) {
                    *(byte *)(iVar48 + local_5c) = bVar12;
                    iVar28 = -iVar33;
                    iVar47 = iVar33 + 1;
                    if (iVar28 < iVar47) {
                      iVar42 = iVar28 * iVar36 + iVar48 + iVar15 + local_5c;
                      local_80 = (uint *)(iVar47 + iVar33);
                      do {
                        if (iVar28 < iVar47) {
                          iVar32 = iVar28;
                          do {
                            *(char *)(iVar32 + iVar42) =
                                 (char)(0x100 - (0x10 - (uint)*(byte *)(iVar32 + iVar42)) *
                                                (0x10 - (uint)bVar12) >> 4);
                            iVar32 = iVar32 + 1;
                          } while (iVar32 < iVar47);
                        }
                        iVar42 = iVar42 + iVar36;
                        local_80 = (uint *)((int)local_80 + -1);
                      } while (local_80 != (uint *)0x0);
                    }
                  }
                  local_5c = local_5c + 1;
                } while ((int)local_5c < (int)uVar24);
              }
              local_60 = local_60 + param_9;
              iVar48 = iVar48 + iVar36;
              local_54 = (byte *)((int)local_54 - 1);
            } while (local_54 != (byte *)0x0);
          }
        }
        else if (uVar25 != 0) {
          iVar48 = iVar29;
          do {
            local_5c = 0;
            if (uVar24 != 0) {
              do {
                bVar12 = local_60[local_5c];
                if (bVar12 != 0) {
                  *(ushort *)(iVar48 + local_5c * 2) = (ushort)bVar12;
                  iVar28 = -iVar33;
                  if (iVar28 < iVar33 + 1) {
                    local_80 = (uint *)(iVar28 * iVar36);
                    local_54 = (byte *)(iVar33 + 1 + iVar33);
                    do {
                      if (iVar28 < iVar33 + 1) {
                        puVar19 = (ushort *)
                                  (iVar48 + (iVar15 + iVar28 + local_5c) * 2 + (int)local_80);
                        iVar47 = iVar33 + 1 + iVar33;
                        do {
                          *puVar19 = (ushort)(0x100 - (0x10 - (uint)*puVar19) *
                                                      (0x10 - (uint)bVar12) >> 4);
                          puVar19 = puVar19 + 1;
                          iVar47 = iVar47 + -1;
                        } while (iVar47 != 0);
                      }
                      local_80 = (uint *)((int)local_80 + iVar36);
                      local_54 = (byte *)((int)local_54 + -1);
                    } while (local_54 != (byte *)0x0);
                  }
                }
                local_5c = local_5c + 1;
              } while ((int)local_5c < (int)uVar24);
            }
            local_60 = local_60 + param_9;
            iVar48 = iVar48 + iVar36;
            local_48 = (ushort *)((int)local_48 - 1);
          } while (local_48 != (ushort *)0x0);
        }
        if (*(char *)(param_1 + 0x931c1) == '\b') {
          local_6c = (char *)((iVar29 - iVar36 * iVar22) - iVar22);
          if (*(int *)(param_1 + 0x931e0) == 0xf) {
            iVar22 = uVar25 + local_34;
            if (0 < iVar22) {
              do {
                if (0 < (int)(uVar24 + local_34)) {
                  pcVar26 = local_6c;
                  iVar33 = uVar24 + local_34;
                  do {
                    cVar4 = *pcVar26;
                    if (cVar4 == '\x10') {
                      *pcVar26 = '\x0f';
LAB_00534a8a:
                      pcVar26[iVar15] = '\0';
                    }
                    else {
                      if (cVar4 == '\0') {
                        *pcVar26 = '\0';
                      }
                      else {
                        *pcVar26 = cVar4 + -1;
                      }
                      if (pcVar26[iVar15] == '\0') goto LAB_00534a8a;
                      pcVar26[iVar15] = pcVar26[iVar15] + -1;
                    }
                    pcVar26 = pcVar26 + 1;
                    iVar33 = iVar33 + -1;
                  } while (iVar33 != 0);
                }
                local_6c = local_6c + iVar36;
                iVar22 = iVar22 + -1;
              } while (iVar22 != 0);
            }
          }
          else {
            iVar22 = uVar25 + local_34;
            if (0 < iVar22) {
              do {
                if (0 < (int)(uVar24 + local_34)) {
                  pcVar26 = local_6c;
                  iVar33 = uVar24 + local_34;
                  do {
                    cVar4 = *pcVar26;
                    if (cVar4 == '\x10') {
                      *pcVar26 = -1;
LAB_00534afa:
                      pcVar26[iVar15] = '\0';
                    }
                    else {
                      if (cVar4 == '\0') {
                        *pcVar26 = '\0';
                      }
                      else {
                        *pcVar26 = cVar4 * '\x10' + -1;
                      }
                      if (pcVar26[iVar15] == '\0') goto LAB_00534afa;
                      pcVar26[iVar15] = pcVar26[iVar15] * '\x10' + -1;
                    }
                    pcVar26 = pcVar26 + 1;
                    iVar33 = iVar33 + -1;
                  } while (iVar33 != 0);
                }
                local_6c = local_6c + iVar36;
                iVar22 = iVar22 + -1;
              } while (iVar22 != 0);
            }
          }
        }
        else {
          bVar12 = (*(char *)(param_1 + 0x931c8) + *(char *)(param_1 + 0x931c4)) - 4;
          bVar34 = (*(char *)(param_1 + 0x931c9) + *(char *)(param_1 + 0x931c5)) - 4;
          bVar23 = (*(char *)(param_1 + 0x931ca) + *(char *)(param_1 + 0x931c6)) - 4;
          iVar29 = (iVar22 * -2 - iVar36 * iVar22) + iVar29;
          bVar37 = (*(char *)(param_1 + 0x931cb) + *(char *)(param_1 + 0x931c7)) - 4;
          if (*(int *)(param_1 + 0x93600) == 0) {
            local_54 = (byte *)(local_34 + uVar25);
            if (0 < (int)local_54) {
              do {
                iVar22 = 0;
                if (0 < (int)(uVar24 + local_34)) {
                  puVar19 = (ushort *)(iVar29 + iVar15 * 2);
                  do {
                    sVar13 = *(short *)(iVar29 + iVar22 * 2);
                    if (sVar13 == 0x10) {
                      *(ushort *)(iVar29 + iVar22 * 2) =
                           (short)(0x10 << (bVar37 & 0x1f)) - 1U | uVar35;
LAB_00534cef:
                      *puVar19 = uVar35;
                    }
                    else {
                      if (sVar13 == 0) {
                        *(ushort *)(iVar29 + iVar22 * 2) = uVar35;
                      }
                      else {
                        *(ushort *)(iVar29 + iVar22 * 2) = (sVar13 << (bVar37 & 0x1f)) - 1U | uVar35
                        ;
                      }
                      if (*puVar19 == 0) goto LAB_00534cef;
                      *puVar19 = (*puVar19 << (bVar37 & 0x1f)) - 1 | uVar35;
                    }
                    iVar22 = iVar22 + 1;
                    puVar19 = puVar19 + 1;
                  } while (iVar22 < (int)(uVar24 + local_34));
                }
                iVar29 = iVar29 + iVar36;
                local_54 = (byte *)((int)local_54 + -1);
              } while (local_54 != (byte *)0x0);
            }
          }
          else {
            local_80 = (uint *)(uVar25 + local_34);
            if (0 < (int)local_80) {
              do {
                iVar22 = 0;
                if (0 < (int)(uVar24 + local_34)) {
                  local_48 = (ushort *)(iVar29 + iVar15 * 2);
                  do {
                    sVar13 = *(short *)(iVar29 + iVar22 * 2);
                    if (sVar13 == 0x10) {
                      *(undefined2 *)(iVar29 + iVar22 * 2) = 0xffff;
                      *local_48 = 0;
                    }
                    else {
                      if (sVar13 != 0) {
                        *(short *)(iVar29 + iVar22 * 2) =
                             sVar13 << (bVar23 & 0x1f) | sVar13 << (bVar34 & 0x1f) |
                             sVar13 << (bVar12 & 0x1f) | sVar13 << (bVar37 & 0x1f);
                      }
                      uVar35 = *local_48;
                      if (uVar35 == 0x10) {
                        *local_48 = 0xffff;
                      }
                      else if (uVar35 != 0) {
                        *local_48 = uVar35 << (bVar23 & 0x1f) | uVar35 << (bVar34 & 0x1f) |
                                    uVar35 << (bVar12 & 0x1f) | uVar35 << (bVar37 & 0x1f);
                      }
                    }
                    iVar22 = iVar22 + 1;
                    local_48 = local_48 + 1;
                  } while (iVar22 < (int)(uVar24 + local_34));
                }
                iVar29 = iVar29 + iVar36;
                local_80 = (uint *)((int)local_80 + -1);
              } while (local_80 != (uint *)0x0);
            }
          }
        }
        break;
      case 7:
        if (iVar33 == 1) {
          if (*(char *)(param_1 + 0x931c1) == '\b') {
            if (uVar25 != 0) {
              iVar48 = (iVar15 - iVar36) + 1 + iVar29;
              iVar33 = iVar15 + iVar29 + 1;
              local_6c = (char *)iVar29;
              do {
                iVar33 = iVar33 + iVar36;
                iVar28 = 0;
                if (uVar24 != 0) {
                  do {
                    bVar12 = ((byte *)((int)local_6c + iVar28))[(int)local_60 - (int)local_6c];
                    uVar38 = (uint)bVar12;
                    if (uVar38 != 0) {
                      *(byte *)((int)local_6c + iVar28) = bVar12;
                      bVar12 = *(byte *)(iVar28 + -1 + iVar48);
                      *(byte *)(iVar28 + -1 + iVar48) =
                           (char)((0x40 - (uint)bVar12) * uVar38 >> 6) + bVar12;
                      bVar12 = *(byte *)(iVar28 + -1 + iVar33);
                      *(byte *)(iVar28 + -1 + iVar33) =
                           (char)((0x40 - (uint)bVar12) * uVar38 >> 6) + bVar12;
                      pbVar45 = (byte *)(iVar28 + -2 + iVar36 + iVar48);
                      *pbVar45 = (char)((0x40 - (uint)*pbVar45) * uVar38 >> 6) + *pbVar45;
                      pbVar45 = (byte *)(iVar28 + iVar36 + iVar48);
                      *pbVar45 = (char)((0x40 - (uint)*pbVar45) * uVar38 >> 6) + *pbVar45;
                      bVar12 = *(byte *)(iVar28 + -2 + iVar48);
                      *(byte *)(iVar28 + -2 + iVar48) =
                           (char)((0x40 - (uint)bVar12) * uVar38 >> 6) + bVar12;
                      *(byte *)(iVar28 + iVar48) =
                           (char)((0x40 - (uint)*(byte *)(iVar28 + iVar48)) * uVar38 >> 6) +
                           *(byte *)(iVar28 + iVar48);
                      bVar12 = *(byte *)(iVar28 + -2 + iVar33);
                      *(byte *)(iVar28 + -2 + iVar33) =
                           (char)((0x40 - (uint)bVar12) * uVar38 >> 6) + bVar12;
                      *(byte *)(iVar28 + iVar33) =
                           (char)((0x40 - (uint)*(byte *)(iVar28 + iVar33)) * uVar38 >> 6) +
                           *(byte *)(iVar28 + iVar33);
                    }
                    iVar28 = iVar28 + 1;
                  } while (iVar28 < (int)uVar24);
                }
                local_60 = local_60 + param_9;
                iVar48 = iVar48 + iVar36;
                local_54 = (byte *)((int)local_54 - 1);
                local_6c = (char *)((int)local_6c + iVar36);
              } while (local_54 != (byte *)0x0);
            }
          }
          else if (uVar25 != 0) {
            iVar33 = iVar29;
            do {
              iVar48 = 0;
              if (uVar24 != 0) {
                piVar21 = (int *)(iVar33 + iVar36 + 4 + iVar15 * 4);
                piVar20 = (int *)((iVar33 - iVar36) + 4 + iVar15 * 4);
                do {
                  uVar38 = (uint)(byte)local_60[iVar48];
                  if (uVar38 != 0) {
                    *(uint *)(iVar33 + iVar48 * 4) = uVar38;
                    piVar20[-1] = ((0x40 - piVar20[-1]) * uVar38 >> 6) + piVar20[-1];
                    piVar21[-1] = ((0x40 - piVar21[-1]) * uVar38 >> 6) + piVar21[-1];
                    iVar28 = *(int *)(iVar36 + -8 + (int)piVar20);
                    *(uint *)(iVar36 + -8 + (int)piVar20) = ((0x40 - iVar28) * uVar38 >> 6) + iVar28
                    ;
                    *(uint *)(iVar36 + (int)piVar20) =
                         ((0x40 - *(int *)(iVar36 + (int)piVar20)) * uVar38 >> 6) +
                         *(int *)(iVar36 + (int)piVar20);
                    piVar20[-2] = ((0x40 - piVar20[-2]) * uVar38 >> 6) + piVar20[-2];
                    *piVar20 = ((0x40 - *piVar20) * uVar38 >> 6) + *piVar20;
                    piVar21[-2] = ((0x40 - piVar21[-2]) * uVar38 >> 6) + piVar21[-2];
                    *piVar21 = ((0x40 - *piVar21) * uVar38 >> 6) + *piVar21;
                  }
                  iVar48 = iVar48 + 1;
                  piVar20 = piVar20 + 1;
                  piVar21 = piVar21 + 1;
                } while (iVar48 < (int)uVar24);
              }
              local_60 = local_60 + param_9;
              iVar33 = iVar33 + iVar36;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
        else if (iVar33 < 5) {
          if (*(char *)(param_1 + 0x931c1) == '\b') {
            if (uVar25 != 0) {
              local_6c = (char *)iVar29;
              do {
                local_5c = 0;
                if (uVar24 != 0) {
                  do {
                    bVar12 = ((byte *)((int)local_6c + local_5c))[(int)local_60 - (int)local_6c];
                    if (bVar12 != 0) {
                      iVar48 = -iVar33;
                      iVar28 = iVar33 + 1;
                      *(byte *)((int)local_6c + local_5c) = bVar12;
                      if (iVar48 < iVar28) {
                        iVar47 = iVar48 * iVar36 + (int)local_6c + iVar15 + local_5c;
                        local_30 = iVar28 + iVar33;
                        local_54 = (byte *)pcVar26;
                        do {
                          if (iVar48 < iVar28) {
                            local_48 = (ushort *)local_54;
                            iVar42 = iVar48;
                            do {
                              if ((char)*local_48 != '\0') {
                                *(byte *)(iVar42 + iVar47) =
                                     (char)((0x40 - (uint)*(byte *)(iVar42 + iVar47)) * (uint)bVar12
                                           >> 6) + *(byte *)(iVar42 + iVar47);
                              }
                              local_48 = (ushort *)((int)local_48 + 1);
                              iVar42 = iVar42 + 1;
                            } while (iVar42 < iVar28);
                          }
                          local_54 = local_54 + 9;
                          iVar47 = iVar47 + iVar36;
                          local_30 = local_30 + -1;
                        } while (local_30 != 0);
                      }
                    }
                    local_5c = local_5c + 1;
                  } while ((int)local_5c < (int)uVar24);
                }
                local_60 = local_60 + param_9;
                local_58 = local_58 - 1;
                local_6c = (char *)((int)local_6c + iVar36);
              } while (local_58 != 0);
            }
          }
          else if (uVar25 != 0) {
            local_50 = (byte *)((int)local_6c - iVar15);
            iVar48 = iVar29;
            do {
              local_5c = 0;
              if (uVar24 != 0) {
                local_30 = iVar15;
                do {
                  uVar38 = (uint)*(byte *)((int)local_50 + local_30);
                  if (uVar38 != 0) {
                    iVar28 = -iVar33;
                    *(uint *)(iVar48 + local_5c * 4) = uVar38;
                    if (iVar28 < iVar33 + 1) {
                      iVar47 = iVar28 * iVar36;
                      local_58 = iVar33 + 1 + iVar33;
                      local_48 = (ushort *)pcVar26;
                      do {
                        if (iVar28 < iVar33 + 1) {
                          local_54 = (byte *)local_48;
                          iVar42 = iVar28;
                          do {
                            if (*local_54 != '\0') {
                              iVar32 = iVar48 + (local_30 + iVar42) * 4;
                              iVar31 = *(int *)(iVar32 + iVar47);
                              *(uint *)(iVar32 + iVar47) = ((0x40 - iVar31) * uVar38 >> 6) + iVar31;
                            }
                            local_54 = local_54 + 1;
                            iVar42 = iVar42 + 1;
                          } while (iVar42 < iVar33 + 1);
                        }
                        local_48 = (ushort *)((int)local_48 + 9);
                        iVar47 = iVar47 + iVar36;
                        local_58 = local_58 + -1;
                      } while (local_58 != 0);
                    }
                  }
                  local_5c = local_5c + 1;
                  local_30 = local_30 + 1;
                } while ((int)local_5c < (int)uVar24);
              }
              local_50 = (byte *)((int)local_50 + param_9);
              iVar48 = iVar48 + iVar36;
              local_80 = (uint *)((int)local_80 - 1);
            } while (local_80 != (uint *)0x0);
          }
        }
        else if (*(char *)(param_1 + 0x931c1) == '\b') {
          if (uVar25 != 0) {
            local_6c = (char *)iVar29;
            do {
              local_5c = 0;
              if (uVar24 != 0) {
                do {
                  bVar12 = ((byte *)((int)local_6c + local_5c))[(int)local_60 - (int)local_6c];
                  if (bVar12 != 0) {
                    iVar48 = -iVar33;
                    iVar28 = iVar33 + 1;
                    *(byte *)((int)local_6c + local_5c) = bVar12;
                    if (iVar48 < iVar28) {
                      iVar42 = iVar48 * iVar36 + (int)local_6c + iVar15 + local_5c;
                      local_58 = iVar28 + iVar33;
                      iVar47 = iVar48;
                      do {
                        for (; iVar47 < iVar28; iVar47 = iVar47 + 1) {
                          *(byte *)(iVar42 + iVar47) =
                               (char)((0x40 - (uint)*(byte *)(iVar42 + iVar47)) * (uint)bVar12 >> 6)
                               + *(byte *)(iVar42 + iVar47);
                        }
                        iVar42 = iVar42 + iVar36;
                        local_58 = local_58 + -1;
                        iVar47 = iVar48;
                      } while (local_58 != 0);
                    }
                  }
                  local_5c = local_5c + 1;
                } while ((int)local_5c < (int)uVar24);
              }
              local_60 = local_60 + param_9;
              local_30 = local_30 - 1;
              local_6c = (char *)((int)local_6c + iVar36);
            } while (local_30 != 0);
          }
        }
        else if (uVar25 != 0) {
          iVar48 = iVar29;
          do {
            local_5c = 0;
            if (uVar24 != 0) {
              do {
                uVar38 = (uint)(byte)local_60[local_5c];
                if (uVar38 != 0) {
                  iVar28 = -iVar33;
                  *(uint *)(iVar48 + local_5c * 4) = uVar38;
                  if (iVar28 < iVar33 + 1) {
                    local_58 = iVar28 * iVar36;
                    local_30 = iVar33 + 1 + iVar33;
                    do {
                      if (iVar28 < iVar33 + 1) {
                        piVar21 = (int *)(iVar48 + (iVar15 + iVar28 + local_5c) * 4 + local_58);
                        iVar47 = iVar33 + 1 + iVar33;
                        do {
                          *piVar21 = ((0x40 - *piVar21) * uVar38 >> 6) + *piVar21;
                          piVar21 = piVar21 + 1;
                          iVar47 = iVar47 + -1;
                        } while (iVar47 != 0);
                      }
                      local_58 = local_58 + iVar36;
                      local_30 = local_30 + -1;
                    } while (local_30 != 0);
                  }
                }
                local_5c = local_5c + 1;
              } while ((int)local_5c < (int)uVar24);
            }
            local_60 = local_60 + param_9;
            iVar48 = iVar48 + iVar36;
            local_80 = (uint *)((int)local_80 - 1);
          } while (local_80 != (uint *)0x0);
        }
        if (*(char *)(param_1 + 0x931c1) == '\b') {
          pbVar45 = (byte *)((iVar29 - iVar36 * iVar22) - iVar22);
          if (*(int *)(param_1 + 0x931e0) == 0xf) {
            local_58 = uVar25 + local_34;
            if (0 < (int)local_58) {
              do {
                if (0 < (int)(uVar24 + local_34)) {
                  pbVar27 = pbVar45;
                  iVar22 = uVar24 + local_34;
                  do {
                    bVar12 = *pbVar27;
                    if (bVar12 == 0x40) {
                      *pbVar27 = 0xf;
LAB_0053553a:
                      pbVar27[iVar15] = 0;
                    }
                    else {
                      if (bVar12 == 0) {
                        *pbVar27 = 0;
                      }
                      else {
                        *pbVar27 = bVar12 >> 2;
                      }
                      if (pbVar27[iVar15] == 0) goto LAB_0053553a;
                      pbVar27[iVar15] = pbVar27[iVar15] >> 2;
                    }
                    pbVar27 = pbVar27 + 1;
                    iVar22 = iVar22 + -1;
                  } while (iVar22 != 0);
                }
                pbVar45 = pbVar45 + iVar36;
                local_58 = local_58 + -1;
              } while (local_58 != 0);
            }
          }
          else {
            iVar22 = local_34 + uVar25;
            if (0 < iVar22) {
              do {
                iVar33 = 0;
                if (0 < (int)(uVar24 + local_34)) {
                  do {
                    pbVar45[iVar33] = (&DAT_0084d0a8)[pbVar45[iVar33]];
                    pbVar45[iVar33 + iVar15] = (&DAT_0084d0a8)[pbVar45[iVar33 + iVar15]];
                    iVar33 = iVar33 + 1;
                  } while (iVar33 < (int)(uVar24 + local_34));
                }
                pbVar45 = pbVar45 + iVar36;
                iVar22 = iVar22 + -1;
              } while (iVar22 != 0);
            }
          }
        }
        else {
          iVar29 = (iVar22 * -4 - iVar36 * iVar22) + iVar29;
          if (*(int *)(param_1 + 0x93600) == 0) {
            local_58 = local_34 + uVar25;
            if (0 < (int)local_58) {
              do {
                iVar22 = 0;
                if (0 < (int)(uVar24 + local_34)) {
                  puVar41 = (uint *)(iVar29 + iVar15 * 4);
                  do {
                    iVar33 = *(int *)(iVar29 + iVar22 * 4);
                    if (iVar33 == 0x40) {
                      *(uint *)(iVar29 + iVar22 * 4) = uVar14;
LAB_0053574f:
                      *puVar41 = uVar44;
                    }
                    else {
                      if (iVar33 == 0) {
                        *(uint *)(iVar29 + iVar22 * 4) = uVar44;
                      }
                      else {
                        *(uint *)(iVar29 + iVar22 * 4) =
                             (uint)(byte)(&DAT_0084d0a8)[iVar33] <<
                             (*(byte *)(param_1 + 0x931cb) & 0x1f) | uVar44;
                      }
                      if (*puVar41 == 0) goto LAB_0053574f;
                      *puVar41 = (uint)(byte)(&DAT_0084d0a8)[*puVar41] <<
                                 (*(byte *)(param_1 + 0x931cb) & 0x1f) | uVar44;
                    }
                    iVar22 = iVar22 + 1;
                    puVar41 = puVar41 + 1;
                  } while (iVar22 < (int)(uVar24 + local_34));
                }
                iVar29 = iVar29 + iVar36;
                local_58 = local_58 + -1;
              } while (local_58 != 0);
            }
          }
          else {
            local_58 = local_34 + uVar25;
            if (0 < (int)local_58) {
              do {
                iVar22 = 0;
                if (0 < (int)(uVar24 + local_34)) {
                  local_80 = (uint *)(iVar29 + iVar15 * 4);
                  do {
                    iVar33 = *(int *)(iVar29 + iVar22 * 4);
                    if (iVar33 == 0x40) {
                      *(undefined4 *)(iVar29 + iVar22 * 4) = 0xffffffff;
                      *local_80 = 0;
                    }
                    else {
                      if (iVar33 != 0) {
                        uVar44 = (uint)(byte)(&DAT_0084d0a8)[iVar33];
                        *(uint *)(iVar29 + iVar22 * 4) =
                             uVar44 << (*(byte *)(param_1 + 0x931cb) & 0x1f) |
                             uVar44 << (*(byte *)(param_1 + 0x931ca) & 0x1f) |
                             uVar44 << (*(byte *)(param_1 + 0x931c9) & 0x1f) |
                             uVar44 << (*(byte *)(param_1 + 0x931c8) & 0x1f);
                      }
                      uVar44 = *local_80;
                      if (uVar44 == 0x40) {
                        *local_80 = 0xffffffff;
                      }
                      else if (uVar44 != 0) {
                        uVar44 = (uint)(byte)(&DAT_0084d0a8)[uVar44];
                        *local_80 = uVar44 << (*(byte *)(param_1 + 0x931cb) & 0x1f) |
                                    uVar44 << (*(byte *)(param_1 + 0x931ca) & 0x1f) |
                                    uVar44 << (*(byte *)(param_1 + 0x931c9) & 0x1f) |
                                    uVar44 << (*(byte *)(param_1 + 0x931c8) & 0x1f);
                      }
                    }
                    iVar22 = iVar22 + 1;
                    local_80 = local_80 + 1;
                  } while (iVar22 < (int)(uVar24 + local_34));
                }
                iVar29 = iVar29 + iVar36;
                local_58 = local_58 + -1;
              } while (local_58 != 0);
            }
          }
        }
        break;
      case 8:
        if (iVar33 == 1) {
          if (*(char *)(param_1 + 0x931c1) == '\b') {
            if (uVar25 != 0) {
              iVar48 = (iVar15 - iVar36) + 1 + iVar29;
              iVar33 = iVar15 + iVar29 + 1;
              local_6c = (char *)iVar29;
              do {
                iVar33 = iVar33 + iVar36;
                iVar28 = 0;
                if (uVar24 != 0) {
                  do {
                    bVar12 = ((byte *)((int)local_6c + iVar28))[(int)local_60 - (int)local_6c];
                    uVar14 = (uint)bVar12;
                    if (uVar14 != 0) {
                      *(byte *)((int)local_6c + iVar28) = bVar12;
                      bVar12 = *(byte *)(iVar28 + -1 + iVar48);
                      *(byte *)(iVar28 + -1 + iVar48) =
                           (char)((0xff - (uint)bVar12) * uVar14 >> 8) + bVar12;
                      bVar12 = *(byte *)(iVar28 + -1 + iVar33);
                      *(byte *)(iVar28 + -1 + iVar33) =
                           (char)((0xff - (uint)bVar12) * uVar14 >> 8) + bVar12;
                      pbVar45 = (byte *)(iVar28 + -2 + iVar36 + iVar48);
                      *pbVar45 = (char)((0xff - (uint)*pbVar45) * uVar14 >> 8) + *pbVar45;
                      pbVar45 = (byte *)(iVar28 + iVar36 + iVar48);
                      *pbVar45 = (char)((0xff - (uint)*pbVar45) * uVar14 >> 8) + *pbVar45;
                      bVar12 = *(byte *)(iVar28 + -2 + iVar48);
                      *(byte *)(iVar28 + -2 + iVar48) =
                           (char)((0xff - (uint)bVar12) * uVar14 >> 8) + bVar12;
                      *(byte *)(iVar28 + iVar48) =
                           (char)((0xff - (uint)*(byte *)(iVar28 + iVar48)) * uVar14 >> 8) +
                           *(byte *)(iVar28 + iVar48);
                      bVar12 = *(byte *)(iVar28 + -2 + iVar33);
                      *(byte *)(iVar28 + -2 + iVar33) =
                           (char)((0xff - (uint)bVar12) * uVar14 >> 8) + bVar12;
                      *(byte *)(iVar28 + iVar33) =
                           (char)((0xff - (uint)*(byte *)(iVar28 + iVar33)) * uVar14 >> 8) +
                           *(byte *)(iVar28 + iVar33);
                    }
                    iVar28 = iVar28 + 1;
                  } while (iVar28 < (int)uVar24);
                }
                local_60 = local_60 + param_9;
                iVar48 = iVar48 + iVar36;
                local_30 = local_30 - 1;
                local_6c = (char *)((int)local_6c + iVar36);
              } while (local_30 != 0);
            }
          }
          else if (uVar25 != 0) {
            iVar33 = iVar29;
            do {
              iVar48 = 0;
              if (uVar24 != 0) {
                piVar21 = (int *)(iVar33 + iVar36 + 4 + iVar15 * 4);
                piVar20 = (int *)((iVar33 - iVar36) + 4 + iVar15 * 4);
                do {
                  uVar14 = (uint)(byte)local_60[iVar48];
                  if (uVar14 != 0) {
                    *(uint *)(iVar33 + iVar48 * 4) = uVar14;
                    piVar20[-1] = ((0xff - piVar20[-1]) * uVar14 >> 8) + piVar20[-1];
                    piVar21[-1] = ((0xff - piVar21[-1]) * uVar14 >> 8) + piVar21[-1];
                    iVar28 = *(int *)(iVar36 + -8 + (int)piVar20);
                    *(uint *)(iVar36 + -8 + (int)piVar20) = ((0xff - iVar28) * uVar14 >> 8) + iVar28
                    ;
                    *(uint *)(iVar36 + (int)piVar20) =
                         ((0xff - *(int *)(iVar36 + (int)piVar20)) * uVar14 >> 8) +
                         *(int *)(iVar36 + (int)piVar20);
                    piVar20[-2] = ((0xff - piVar20[-2]) * uVar14 >> 8) + piVar20[-2];
                    *piVar20 = ((0xff - *piVar20) * uVar14 >> 8) + *piVar20;
                    piVar21[-2] = ((0xff - piVar21[-2]) * uVar14 >> 8) + piVar21[-2];
                    *piVar21 = ((0xff - *piVar21) * uVar14 >> 8) + *piVar21;
                  }
                  iVar48 = iVar48 + 1;
                  piVar20 = piVar20 + 1;
                  piVar21 = piVar21 + 1;
                } while (iVar48 < (int)uVar24);
              }
              local_60 = local_60 + param_9;
              iVar33 = iVar33 + iVar36;
              local_58 = local_58 - 1;
            } while (local_58 != 0);
          }
        }
        else if (iVar33 < 5) {
          if (*(char *)(param_1 + 0x931c1) == '\b') {
            if (uVar25 != 0) {
              local_6c = (char *)iVar29;
              do {
                local_5c = 0;
                if (uVar24 != 0) {
                  do {
                    bVar12 = ((byte *)((int)local_6c + local_5c))[(int)local_60 - (int)local_6c];
                    if (bVar12 != 0) {
                      iVar48 = -iVar33;
                      iVar28 = iVar33 + 1;
                      *(byte *)((int)local_6c + local_5c) = bVar12;
                      if (iVar48 < iVar28) {
                        iVar47 = iVar48 * iVar36 + (int)local_6c + iVar15 + local_5c;
                        local_58 = iVar28 + iVar33;
                        local_54 = (byte *)pcVar26;
                        do {
                          if (iVar48 < iVar28) {
                            local_80 = (uint *)local_54;
                            iVar42 = iVar48;
                            do {
                              if ((char)*local_80 != '\0') {
                                *(byte *)(iVar47 + iVar42) =
                                     (char)((0xff - (uint)*(byte *)(iVar47 + iVar42)) * (uint)bVar12
                                           >> 8) + *(byte *)(iVar47 + iVar42);
                              }
                              local_80 = (uint *)((int)local_80 + 1);
                              iVar42 = iVar42 + 1;
                            } while (iVar42 < iVar28);
                          }
                          local_54 = local_54 + 9;
                          iVar47 = iVar47 + iVar36;
                          local_58 = local_58 + -1;
                        } while (local_58 != 0);
                      }
                    }
                    local_5c = local_5c + 1;
                  } while ((int)local_5c < (int)uVar24);
                }
                local_60 = local_60 + param_9;
                local_30 = local_30 - 1;
                local_6c = (char *)((int)local_6c + iVar36);
              } while (local_30 != 0);
            }
          }
          else if (uVar25 != 0) {
            local_48 = (ushort *)((int)local_6c - iVar15);
            iVar48 = iVar29;
            local_24 = (char *)uVar25;
            do {
              local_5c = 0;
              if (uVar24 != 0) {
                local_30 = iVar15;
                do {
                  uVar14 = (uint)*(byte *)((int)local_48 + local_30);
                  if (uVar14 != 0) {
                    iVar28 = -iVar33;
                    *(uint *)(iVar48 + local_5c * 4) = uVar14;
                    if (iVar28 < iVar33 + 1) {
                      iVar47 = iVar28 * iVar36;
                      local_58 = iVar33 + 1 + iVar33;
                      local_54 = (byte *)pcVar26;
                      do {
                        if (iVar28 < iVar33 + 1) {
                          local_80 = (uint *)local_54;
                          iVar42 = iVar28;
                          do {
                            if ((char)*local_80 != '\0') {
                              iVar32 = iVar48 + (local_30 + iVar42) * 4;
                              iVar31 = *(int *)(iVar32 + iVar47);
                              *(uint *)(iVar32 + iVar47) = ((0xff - iVar31) * uVar14 >> 8) + iVar31;
                            }
                            local_80 = (uint *)((int)local_80 + 1);
                            iVar42 = iVar42 + 1;
                          } while (iVar42 < iVar33 + 1);
                        }
                        local_54 = local_54 + 9;
                        iVar47 = iVar47 + iVar36;
                        local_58 = local_58 + -1;
                      } while (local_58 != 0);
                    }
                  }
                  local_5c = local_5c + 1;
                  local_30 = local_30 + 1;
                } while ((int)local_5c < (int)uVar24);
              }
              local_48 = (ushort *)((int)local_48 + param_9);
              iVar48 = iVar48 + iVar36;
              local_24 = (char *)((int)local_24 - 1);
            } while (local_24 != (char *)0x0);
          }
        }
        else if (*(char *)(param_1 + 0x931c1) == '\b') {
          if (uVar25 != 0) {
            local_6c = (char *)iVar29;
            do {
              local_5c = 0;
              if (uVar24 != 0) {
                do {
                  bVar12 = ((byte *)((int)local_6c + local_5c))[(int)local_60 - (int)local_6c];
                  if (bVar12 != 0) {
                    iVar48 = -iVar33;
                    iVar28 = iVar33 + 1;
                    *(byte *)((int)local_6c + local_5c) = bVar12;
                    if (iVar48 < iVar28) {
                      iVar42 = iVar48 * iVar36 + (int)local_6c + iVar15 + local_5c;
                      local_58 = iVar28 + iVar33;
                      iVar47 = iVar48;
                      do {
                        for (; iVar47 < iVar28; iVar47 = iVar47 + 1) {
                          *(byte *)(iVar47 + iVar42) =
                               (char)((0xff - (uint)*(byte *)(iVar47 + iVar42)) * (uint)bVar12 >> 8)
                               + *(byte *)(iVar47 + iVar42);
                        }
                        iVar42 = iVar42 + iVar36;
                        local_58 = local_58 + -1;
                        iVar47 = iVar48;
                      } while (local_58 != 0);
                    }
                  }
                  local_5c = local_5c + 1;
                } while ((int)local_5c < (int)uVar24);
              }
              local_60 = local_60 + param_9;
              local_30 = local_30 - 1;
              local_6c = (char *)((int)local_6c + iVar36);
            } while (local_30 != 0);
          }
        }
        else if (uVar25 != 0) {
          iVar48 = iVar29;
          do {
            local_5c = 0;
            if (uVar24 != 0) {
              do {
                uVar14 = (uint)(byte)local_60[local_5c];
                if (uVar14 != 0) {
                  iVar28 = -iVar33;
                  *(uint *)(iVar48 + local_5c * 4) = uVar14;
                  if (iVar28 < iVar33 + 1) {
                    local_58 = iVar28 * iVar36;
                    local_30 = iVar33 + 1 + iVar33;
                    do {
                      if (iVar28 < iVar33 + 1) {
                        piVar21 = (int *)(iVar48 + (iVar15 + iVar28 + local_5c) * 4 + local_58);
                        iVar47 = iVar33 + 1 + iVar33;
                        do {
                          *piVar21 = ((0xff - *piVar21) * uVar14 >> 8) + *piVar21;
                          piVar21 = piVar21 + 1;
                          iVar47 = iVar47 + -1;
                        } while (iVar47 != 0);
                      }
                      local_58 = local_58 + iVar36;
                      local_30 = local_30 + -1;
                    } while (local_30 != 0);
                  }
                }
                local_5c = local_5c + 1;
              } while ((int)local_5c < (int)uVar24);
            }
            local_60 = local_60 + param_9;
            iVar48 = iVar48 + iVar36;
            local_80 = (uint *)((int)local_80 - 1);
          } while (local_80 != (uint *)0x0);
        }
        if (*(char *)(param_1 + 0x931c1) == '\b') {
          iVar29 = (iVar22 * -4 - iVar36 * iVar22) + iVar29;
          if ((*(int *)(param_1 + 0x931e0) == 0xf) && (iVar22 = uVar25 + local_34, 0 < iVar22)) {
            do {
              iVar33 = 0;
              if (0 < (int)(uVar24 + local_34)) {
                do {
                  *(byte *)(iVar29 + iVar33) = *(byte *)(iVar29 + iVar33) >> 4;
                  pbVar45 = (byte *)(iVar33 + iVar29 + iVar15);
                  *pbVar45 = *pbVar45 >> 4;
                  iVar33 = iVar33 + 1;
                } while (iVar33 < (int)(uVar24 + local_34));
              }
              iVar29 = iVar29 + iVar36;
              iVar22 = iVar22 + -1;
            } while (iVar22 != 0);
          }
        }
        else {
          iVar29 = (iVar22 * -4 - iVar36 * iVar22) + iVar29;
          if (*(int *)(param_1 + 0x93600) == 0) {
            local_58 = uVar25 + local_34;
            if (0 < (int)local_58) {
              do {
                iVar22 = 0;
                if (0 < (int)(local_34 + uVar24)) {
                  puVar41 = (uint *)(iVar29 + iVar15 * 4);
                  do {
                    iVar33 = iVar22 * 4;
                    iVar22 = iVar22 + 1;
                    *(uint *)(iVar29 + -4 + iVar22 * 4) =
                         *(int *)(iVar29 + iVar33) << (*(byte *)(param_1 + 0x931cb) & 0x1f) | uVar44
                    ;
                    *puVar41 = *puVar41 << (*(byte *)(param_1 + 0x931cb) & 0x1f) | uVar44;
                    puVar41 = puVar41 + 1;
                  } while (iVar22 < (int)(local_34 + uVar24));
                }
                iVar29 = iVar29 + iVar36;
                local_58 = local_58 + -1;
              } while (local_58 != 0);
            }
          }
          else {
            local_58 = uVar25 + local_34;
            if (0 < (int)local_58) {
              do {
                iVar22 = 0;
                if (0 < (int)(local_34 + uVar24)) {
                  puVar41 = (uint *)(iVar29 + iVar15 * 4);
                  do {
                    iVar33 = *(int *)(iVar29 + iVar22 * 4);
                    iVar22 = iVar22 + 1;
                    *(int *)(iVar29 + -4 + iVar22 * 4) =
                         iVar33 << (*(byte *)(param_1 + 0x931ca) & 0x1f) |
                         iVar33 << (*(byte *)(param_1 + 0x931c8) & 0x1f) |
                         iVar33 << (*(byte *)(param_1 + 0x931cb) & 0x1f) |
                         iVar33 << (*(byte *)(param_1 + 0x931c9) & 0x1f);
                    uVar44 = *puVar41;
                    *puVar41 = uVar44 << (*(byte *)(param_1 + 0x931ca) & 0x1f) |
                               uVar44 << (*(byte *)(param_1 + 0x931c8) & 0x1f) |
                               uVar44 << (*(byte *)(param_1 + 0x931cb) & 0x1f) |
                               uVar44 << (*(byte *)(param_1 + 0x931c9) & 0x1f);
                    puVar41 = puVar41 + 1;
                  } while (iVar22 < (int)(local_34 + uVar24));
                }
                iVar29 = iVar29 + iVar36;
                local_58 = local_58 + -1;
              } while (local_58 != 0);
            }
          }
        }
      }
joined_r0x00536134:
      if (param_13 != 0) {
        local_10 = local_20 + -1;
        local_c = local_14 + -1;
        local_8 = (*(ushort *)(param_1 + 0x9316a) - 1) + local_20;
        local_4 = (*(ushort *)(param_1 + 0x9316a) - 1) + local_14;
        FUN_0052f080(param_1,&local_10);
      }
    }
  }
  sVar13 = (short)local_34;
  *(short *)((int)param_2 + 10) = *(short *)((int)param_2 + 10) + sVar13;
  *(short *)(param_2 + 3) = (short)param_2[3] + sVar13;
  *(short *)((int)param_2 + 0xe) = *(short *)((int)param_2 + 0xe) + sVar13;
LAB_005361b2:
  if (param_3 < 0x10000) {
    puVar2 = (undefined4 *)(param_1 + 0xfd80 + param_3 * 8);
    *puVar2 = 1;
    puVar2[1] = param_2;
    param_2[7] = (uint)puVar2;
  }
  else {
    param_2[7] = 0;
    if (*(int *)(param_1 + 0x8fd80) == 0x400) {
      piVar21 = (int *)(param_1 + 0x8fd84);
      iVar22 = 0;
      puVar41 = (uint *)*piVar21;
      while (puVar41 == param_2) {
        piVar21 = piVar21 + 1;
        iVar22 = iVar22 + 1;
        puVar41 = (uint *)*piVar21;
      }
      *(undefined1 *)(*(int *)(param_1 + 0x8fd84 + iVar22 * 4) + 4) = 0;
      *(int *)(param_1 + 0x8fd80) = *(int *)(param_1 + 0x8fd80) + -1;
      iVar33 = *(int *)(param_1 + 0x8fd80) - iVar22;
      if (0 < iVar33) {
        FUN_0056d460(param_1 + 0x8fd84 + iVar22 * 4,param_1 + 0x8fd88 + iVar22 * 4,iVar33 * 4);
      }
    }
    *(uint **)(param_1 + 0x8fd84 + *(int *)(param_1 + 0x8fd80) * 4) = param_2;
    *(int *)(param_1 + 0x8fd80) = *(int *)(param_1 + 0x8fd80) + 1;
  }
  *(undefined1 *)(param_2 + 1) = 1;
  *(undefined1 *)((int)param_2 + 5) = 0;
  return 0;
}

