
int FUN_0067abc0(int *param_1,int param_2)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  byte bVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  undefined2 uVar14;
  uint uVar15;
  uint local_3c;
  uint local_38;
  byte *local_34;
  uint local_30;
  uint local_2c;
  char local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  byte *local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  undefined1 local_10;
  byte bStack_f;
  ushort uStack_e;
  char local_8;
  byte bStack_7;
  ushort uStack_6;
  
  if ((((param_1 != (int *)0x0) && (puVar1 = (uint *)param_1[7], puVar1 != (uint *)0x0)) &&
      (param_1[3] != 0)) && ((*param_1 != 0 || (param_1[1] == 0)))) {
    if (*puVar1 == 0xb) {
      *puVar1 = 0xc;
    }
    local_24 = (byte *)param_1[3];
    pbVar13 = (byte *)*param_1;
    local_3c = puVar1[0xe];
    local_2c = param_1[4];
    uVar15 = param_1[1];
    uVar12 = puVar1[0xf];
    uVar6 = *puVar1;
    local_1c = 0;
    if (uVar6 < 0x1f) {
      local_38 = uVar15;
      local_34 = pbVar13;
      local_20 = local_2c;
      local_18 = uVar15;
      do {
        switch((&switchD_0067ac4e::switchdataD_0067c344)[uVar6]) {
        case (undefined *)0x67ac55:
          if (puVar1[2] == 0) {
            *puVar1 = 0xc;
          }
          else {
            for (; uVar12 < 0x10; uVar12 = uVar12 + 8) {
              if (uVar15 == 0) goto LAB_0067c1f8;
              uVar15 = uVar15 - 1;
              local_3c = local_3c + ((uint)*pbVar13 << ((byte)uVar12 & 0x1f));
              pbVar13 = pbVar13 + 1;
              local_38 = uVar15;
              local_34 = pbVar13;
            }
            if (((puVar1[2] & 2) == 0) || (local_3c != 0x8b1f)) {
              puVar1[4] = 0;
              if (puVar1[8] != 0) {
                *(undefined4 *)(puVar1[8] + 0x30) = 0xffffffff;
              }
              if (((puVar1[2] & 1) == 0) ||
                 (((local_3c & 0xff) * 0x100 + (local_3c >> 8)) % 0x1f != 0)) {
                param_1[6] = (int)s_incorrect_header_check_00a0db34;
              }
              else {
                if (((byte)local_3c & 0xf) == 8) {
                  uVar12 = uVar12 - 4;
                  local_3c = local_3c >> 4;
                  uVar6 = (local_3c & 0xf) + 8;
                  if (puVar1[9] == 0) {
                    puVar1[9] = uVar6;
                  }
                  else if (puVar1[9] < uVar6) {
                    param_1[6] = (int)s_invalid_window_size_00a0db4c;
                    break;
                  }
                  uVar12 = 0;
                  puVar1[5] = 1 << (sbyte)uVar6;
                  uVar6 = FUN_0067c870(0,0,0);
                  puVar1[6] = uVar6;
                  param_1[0xc] = uVar6;
                  *puVar1 = (uint)(~(byte)(local_3c >> 8) & 2 | 9);
                  local_3c = 0;
                  goto LAB_0067c188;
                }
                param_1[6] = (int)s_unknown_compression_method_00a0db60;
              }
              break;
            }
            uVar12 = 0;
            uVar6 = FUN_0067c560(0,0,0);
            puVar1[6] = uVar6;
            local_28 = '\x1f';
            local_27 = 0x8b;
            uVar6 = FUN_0067c560(puVar1[6],&local_28,2);
            puVar1[6] = uVar6;
            local_3c = 0;
            *puVar1 = 1;
          }
          goto LAB_0067c188;
        case (undefined *)0x67adbf:
          for (; uVar12 < 0x10; uVar12 = uVar12 + 8) {
            if (uVar15 == 0) goto LAB_0067c1f8;
            uVar15 = uVar15 - 1;
            local_3c = local_3c + ((uint)*pbVar13 << ((byte)uVar12 & 0x1f));
            pbVar13 = pbVar13 + 1;
            local_38 = uVar15;
            local_34 = pbVar13;
          }
          puVar1[4] = local_3c;
          if ((char)local_3c == '\b') {
            if ((local_3c & 0xe000) == 0) {
              if ((uint *)puVar1[8] != (uint *)0x0) {
                *(uint *)puVar1[8] = local_3c >> 8 & 1;
              }
              if ((puVar1[4] & 0x200) != 0) {
                local_27 = (undefined1)(local_3c >> 8);
                local_28 = (char)local_3c;
                uVar6 = FUN_0067c560(puVar1[6],&local_28,2);
                puVar1[6] = uVar6;
              }
              uVar12 = 0;
              *puVar1 = 2;
              local_3c = 0;
              do {
                if (uVar15 == 0) goto LAB_0067c1f8;
                uVar15 = uVar15 - 1;
                bVar9 = (byte)uVar12;
                uVar12 = uVar12 + 8;
                local_3c = local_3c + ((uint)*pbVar13 << (bVar9 & 0x1f));
                pbVar13 = pbVar13 + 1;
                local_38 = uVar15;
joined_r0x0067ae6e:
              } while (uVar12 < 0x20);
              if (puVar1[8] != 0) {
                *(uint *)(puVar1[8] + 4) = local_3c;
              }
              if ((puVar1[4] & 0x200) != 0) {
                local_28 = (char)local_3c;
                local_25 = (undefined1)(local_3c >> 0x18);
                local_27 = (undefined1)(local_3c >> 8);
                local_26 = (undefined1)(local_3c >> 0x10);
                uVar6 = FUN_0067c560(puVar1[6],&local_28,4);
                puVar1[6] = uVar6;
              }
              uVar12 = 0;
              *puVar1 = 3;
              local_3c = 0;
              do {
                if (uVar15 == 0) goto LAB_0067c1f8;
                bVar9 = (byte)uVar12;
                uVar15 = uVar15 - 1;
                uVar12 = uVar12 + 8;
                local_3c = local_3c + ((uint)*pbVar13 << (bVar9 & 0x1f));
                pbVar13 = pbVar13 + 1;
                local_38 = uVar15;
                local_34 = pbVar13;
joined_r0x0067aef6:
              } while (uVar12 < 0x10);
              if (puVar1[8] != 0) {
                *(uint *)(puVar1[8] + 8) = local_3c & 0xff;
                *(uint *)(puVar1[8] + 0xc) = local_3c >> 8;
              }
              if ((puVar1[4] & 0x200) != 0) {
                local_28 = (char)local_3c;
                local_27 = (undefined1)(local_3c >> 8);
                uVar6 = FUN_0067c560(puVar1[6],&local_28,2);
                puVar1[6] = uVar6;
              }
              uVar12 = 0;
              *puVar1 = 4;
              local_3c = 0;
              goto switchD_0067ac4e_caseD_67af7c;
            }
            param_1[6] = (int)s_unknown_header_flags_set_00a0db18;
          }
          else {
            param_1[6] = (int)s_unknown_compression_method_00a0db60;
          }
          break;
        case (undefined *)0x67ae6b:
          goto joined_r0x0067ae6e;
        case (undefined *)0x67aef3:
          goto joined_r0x0067aef6;
        case (undefined *)0x67af7c:
switchD_0067ac4e_caseD_67af7c:
          if ((puVar1[4] & 0x400) == 0) {
            if (puVar1[8] != 0) {
              *(undefined4 *)(puVar1[8] + 0x10) = 0;
            }
          }
          else {
            for (; uVar12 < 0x10; uVar12 = uVar12 + 8) {
              if (uVar15 == 0) goto LAB_0067c1f8;
              uVar15 = uVar15 - 1;
              local_3c = local_3c + ((uint)*pbVar13 << ((byte)uVar12 & 0x1f));
              pbVar13 = pbVar13 + 1;
              local_38 = uVar15;
              local_34 = pbVar13;
            }
            puVar1[0x10] = local_3c;
            if (puVar1[8] != 0) {
              *(uint *)(puVar1[8] + 0x14) = local_3c;
            }
            if ((puVar1[4] & 0x200) != 0) {
              local_28 = (char)local_3c;
              local_27 = (undefined1)(local_3c >> 8);
              uVar6 = FUN_0067c560(puVar1[6],&local_28,2);
              puVar1[6] = uVar6;
            }
            uVar12 = 0;
            local_3c = 0;
          }
          *puVar1 = 5;
        case (undefined *)0x67b00f:
          if ((puVar1[4] & 0x400) == 0) {
LAB_0067b0c5:
            puVar1[0x10] = 0;
            *puVar1 = 6;
switchD_0067ac4e_caseD_67b0d2:
            if ((puVar1[4] & 0x800) == 0) {
              if (puVar1[8] != 0) {
                *(undefined4 *)(puVar1[8] + 0x1c) = 0;
              }
LAB_0067b177:
              puVar1[0x10] = 0;
              *puVar1 = 7;
switchD_0067ac4e_caseD_67b184:
              if ((puVar1[4] & 0x1000) == 0) {
                if (puVar1[8] != 0) {
                  *(undefined4 *)(puVar1[8] + 0x24) = 0;
                }
LAB_0067b229:
                *puVar1 = 8;
switchD_0067ac4e_caseD_67b22f:
                if ((puVar1[4] & 0x200) != 0) {
                  for (; uVar12 < 0x10; uVar12 = uVar12 + 8) {
                    if (uVar15 == 0) goto LAB_0067c1f8;
                    uVar15 = uVar15 - 1;
                    local_3c = local_3c + ((uint)*pbVar13 << ((byte)uVar12 & 0x1f));
                    pbVar13 = pbVar13 + 1;
                    local_38 = uVar15;
                    local_34 = pbVar13;
                  }
                  if (local_3c != (puVar1[6] & 0xffff)) {
                    param_1[6] = (int)s_header_crc_mismatch_00a0db04;
                    break;
                  }
                  uVar12 = 0;
                  local_3c = 0;
                }
                if (puVar1[8] != 0) {
                  *(uint *)(puVar1[8] + 0x2c) = (int)puVar1[4] >> 9 & 1;
                  *(undefined4 *)(puVar1[8] + 0x30) = 1;
                }
                uVar6 = FUN_0067c560(0,0,0);
                puVar1[6] = uVar6;
                param_1[0xc] = uVar6;
                *puVar1 = 0xb;
                goto LAB_0067c188;
              }
              if (uVar15 != 0) {
                uVar6 = 0;
                do {
                  bVar9 = pbVar13[uVar6];
                  uVar6 = uVar6 + 1;
                  uVar11 = puVar1[8];
                  if (((uVar11 != 0) && (local_14 = *(uint *)(uVar11 + 0x24), local_14 != 0)) &&
                     (puVar1[0x10] < *(uint *)(uVar11 + 0x28))) {
                    *(byte *)(local_14 + puVar1[0x10]) = bVar9;
                    puVar1[0x10] = puVar1[0x10] + 1;
                  }
                } while ((bVar9 != 0) && (uVar6 < uVar15));
                if ((puVar1[4] & 0x200) != 0) {
                  uVar11 = FUN_0067c560(puVar1[6],pbVar13,uVar6);
                  puVar1[6] = uVar11;
                }
                uVar15 = uVar15 - uVar6;
                pbVar13 = pbVar13 + uVar6;
                local_38 = uVar15;
                local_34 = pbVar13;
                if (bVar9 == 0) goto LAB_0067b229;
              }
            }
            else if (uVar15 != 0) {
              uVar6 = 0;
              do {
                bVar9 = pbVar13[uVar6];
                uVar6 = uVar6 + 1;
                uVar11 = puVar1[8];
                if (((uVar11 != 0) && (local_14 = *(uint *)(uVar11 + 0x1c), local_14 != 0)) &&
                   (puVar1[0x10] < *(uint *)(uVar11 + 0x20))) {
                  *(byte *)(local_14 + puVar1[0x10]) = bVar9;
                  puVar1[0x10] = puVar1[0x10] + 1;
                }
              } while ((bVar9 != 0) && (uVar6 < uVar15));
              if ((puVar1[4] & 0x200) != 0) {
                uVar11 = FUN_0067c560(puVar1[6],pbVar13,uVar6);
                puVar1[6] = uVar11;
              }
              uVar15 = uVar15 - uVar6;
              pbVar13 = pbVar13 + uVar6;
              local_38 = uVar15;
              local_34 = pbVar13;
              if (bVar9 == 0) goto LAB_0067b177;
            }
          }
          else {
            local_30 = puVar1[0x10];
            if (uVar15 < puVar1[0x10]) {
              local_30 = uVar15;
            }
            if (local_30 != 0) {
              uVar6 = puVar1[8];
              if (uVar6 != 0) {
                local_14 = *(uint *)(uVar6 + 0x10);
                if (local_14 != 0) {
                  iVar5 = *(int *)(uVar6 + 0x14) - puVar1[0x10];
                  uVar15 = local_30;
                  if (*(uint *)(uVar6 + 0x18) < local_30 + iVar5) {
                    uVar15 = *(uint *)(uVar6 + 0x18) - iVar5;
                  }
                  pbVar13 = local_34;
                  pbVar4 = (byte *)(local_14 + iVar5);
                  for (uVar6 = uVar15 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                    *(undefined4 *)pbVar4 = *(undefined4 *)pbVar13;
                    pbVar13 = pbVar13 + 4;
                    pbVar4 = pbVar4 + 4;
                  }
                  for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
                    *pbVar4 = *pbVar13;
                    pbVar13 = pbVar13 + 1;
                    pbVar4 = pbVar4 + 1;
                  }
                  pbVar13 = local_34;
                  uVar15 = local_38;
                }
              }
              if ((puVar1[4] & 0x200) != 0) {
                uVar6 = FUN_0067c560(puVar1[6],pbVar13,local_30);
                puVar1[6] = uVar6;
              }
              uVar15 = uVar15 - local_30;
              pbVar13 = pbVar13 + local_30;
              puVar1[0x10] = puVar1[0x10] - local_30;
              local_38 = uVar15;
              local_34 = pbVar13;
            }
            if (puVar1[0x10] == 0) goto LAB_0067b0c5;
          }
LAB_0067c1f8:
          uVar6 = local_20;
          param_1[3] = (int)local_24;
          param_1[4] = local_2c;
          *param_1 = (int)pbVar13;
          param_1[1] = local_38;
          puVar1[0xe] = local_3c;
          puVar1[0xf] = uVar12;
          if (((puVar1[10] == 0) &&
              (((local_20 == param_1[4] || (0x1c < (int)*puVar1)) ||
               ((0x19 < (int)*puVar1 && (param_2 == 4)))))) ||
             (iVar5 = FUN_0067c400(param_1,param_1[3],local_20 - param_1[4]), iVar5 == 0)) {
            local_18 = local_18 - param_1[1];
            iVar5 = uVar6 - param_1[4];
            param_1[2] = param_1[2] + local_18;
            param_1[5] = param_1[5] + iVar5;
            puVar1[7] = puVar1[7] + iVar5;
            if ((puVar1[2] != 0) && (iVar5 != 0)) {
              if (puVar1[4] == 0) {
                uVar6 = FUN_0067c870(puVar1[6],param_1[3] - iVar5,iVar5);
              }
              else {
                uVar6 = FUN_0067c560(puVar1[6],param_1[3] - iVar5);
              }
              puVar1[6] = uVar6;
              param_1[0xc] = uVar6;
            }
            uVar6 = *puVar1;
            if ((uVar6 == 0x13) || (uVar6 == 0xe)) {
              iVar7 = 0x100;
            }
            else {
              iVar7 = 0;
            }
            param_1[0xb] = ((uVar6 != 0xb) - 1 & 0x80) + iVar7 + (-(uint)(puVar1[1] != 0) & 0x40) +
                           puVar1[0xf];
            if (((local_18 != 0) || (iVar5 != 0)) && (param_2 != 4)) {
              return local_1c;
            }
            if (local_1c == 0) {
              return -5;
            }
            return local_1c;
          }
          *puVar1 = 0x1e;
switchD_0067ac4e_caseD_67c25f:
          return -4;
        case (undefined *)0x67b0d2:
          goto switchD_0067ac4e_caseD_67b0d2;
        case (undefined *)0x67b184:
          goto switchD_0067ac4e_caseD_67b184;
        case (undefined *)0x67b22f:
          goto switchD_0067ac4e_caseD_67b22f;
        case (undefined *)0x67b2ce:
          for (; uVar12 < 0x20; uVar12 = uVar12 + 8) {
            if (uVar15 == 0) goto LAB_0067c1f8;
            uVar15 = uVar15 - 1;
            local_3c = local_3c + ((uint)*pbVar13 << ((byte)uVar12 & 0x1f));
            pbVar13 = pbVar13 + 1;
            local_38 = uVar15;
            local_34 = pbVar13;
          }
          uVar6 = ((local_3c & 0xff) * 0x10000 + (local_3c & 0xff00)) * 0x100 +
                  (local_3c >> 0x10 & 0xff) * 0x100 + (local_3c >> 0x18);
          uVar12 = 0;
          puVar1[6] = uVar6;
          param_1[0xc] = uVar6;
          local_3c = 0;
          *puVar1 = 10;
          goto LAB_0067b343;
        case (undefined *)0x67b33f:
LAB_0067b343:
          if (puVar1[3] == 0) {
            param_1[1] = uVar15;
            param_1[3] = (int)local_24;
            param_1[4] = local_2c;
            *param_1 = (int)pbVar13;
            puVar1[0xf] = uVar12;
            puVar1[0xe] = local_3c;
            return 2;
          }
          uVar6 = FUN_0067c870(0,0,0);
          puVar1[6] = uVar6;
          param_1[0xc] = uVar6;
          *puVar1 = 0xb;
switchD_0067ac4e_caseD_67b36c:
          if ((param_2 != 5) && (param_2 != 6)) {
switchD_0067ac4e_caseD_67b386:
            if (puVar1[1] == 0) {
              if (uVar12 < 3) {
                do {
                  if (uVar15 == 0) goto LAB_0067c1f8;
                  uVar15 = uVar15 - 1;
                  bVar9 = (byte)uVar12;
                  uVar12 = uVar12 + 8;
                  local_3c = local_3c + ((uint)*pbVar13 << (bVar9 & 0x1f));
                  pbVar13 = pbVar13 + 1;
                  local_38 = uVar15;
                } while (uVar12 < 3);
                local_34 = pbVar13;
              }
              puVar1[1] = local_3c & 1;
              switch(local_3c >> 1 & 3) {
              case 0:
                local_3c = local_3c >> 3;
                *puVar1 = 0xd;
                uVar12 = uVar12 - 3;
                break;
              case 1:
                FUN_0067c3d0(puVar1);
                *puVar1 = 0x13;
                if (param_2 == 6) {
                  local_3c = local_3c >> 3;
                  uVar12 = uVar12 - 3;
                  goto LAB_0067c1f8;
                }
                local_3c = local_3c >> 3;
                uVar12 = uVar12 - 3;
                break;
              case 2:
                local_3c = local_3c >> 3;
                *puVar1 = 0x10;
                uVar12 = uVar12 - 3;
                break;
              case 3:
                param_1[6] = (int)s_invalid_block_type_00a0daf0;
                *puVar1 = 0x1d;
              default:
                local_3c = local_3c >> 3;
                uVar12 = uVar12 - 3;
              }
            }
            else {
              *puVar1 = 0x1a;
              local_3c = local_3c >> (sbyte)(uVar12 & 7);
              uVar12 = uVar12 - (uVar12 & 7);
            }
            goto LAB_0067c188;
          }
          goto LAB_0067c1f8;
        case (undefined *)0x67b36c:
          goto switchD_0067ac4e_caseD_67b36c;
        case (undefined *)0x67b386:
          goto switchD_0067ac4e_caseD_67b386;
        case (undefined *)0x67b471:
          local_3c = local_3c >> (sbyte)(uVar12 & 7);
          uVar12 = uVar12 - (uVar12 & 7);
          if (uVar12 < 0x20) {
            do {
              if (uVar15 == 0) goto LAB_0067c1f8;
              uVar15 = uVar15 - 1;
              bVar9 = (byte)uVar12;
              uVar12 = uVar12 + 8;
              local_3c = local_3c + ((uint)*pbVar13 << (bVar9 & 0x1f));
              pbVar13 = pbVar13 + 1;
              local_38 = uVar15;
            } while (uVar12 < 0x20);
            local_34 = pbVar13;
          }
          if ((local_3c & 0xffff) == ~local_3c >> 0x10) {
            puVar1[0x10] = local_3c & 0xffff;
            uVar12 = 0;
            local_3c = 0;
            *puVar1 = 0xe;
            if (param_2 != 6) goto switchD_0067ac4e_caseD_67b4ef;
            goto LAB_0067c1f8;
          }
          param_1[6] = (int)s_invalid_stored_block_lengths_00a0dad0;
          break;
        case (undefined *)0x67b4ef:
switchD_0067ac4e_caseD_67b4ef:
          *puVar1 = 0xf;
        case (undefined *)0x67b4f5:
          local_30 = puVar1[0x10];
          if (local_30 == 0) {
LAB_0067bc7b:
            *puVar1 = 0xb;
            goto LAB_0067c188;
          }
          if (uVar15 < local_30) {
            local_30 = uVar15;
          }
          if (local_2c < local_30) {
            local_30 = local_2c;
          }
          if (local_30 != 0) {
            pbVar13 = local_34;
            pbVar4 = local_24;
            for (uVar6 = local_30 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
              *(undefined4 *)pbVar4 = *(undefined4 *)pbVar13;
              pbVar13 = pbVar13 + 4;
              pbVar4 = pbVar4 + 4;
            }
            for (uVar6 = local_30 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
              *pbVar4 = *pbVar13;
              pbVar13 = pbVar13 + 1;
              pbVar4 = pbVar4 + 1;
            }
            uVar15 = local_38 - local_30;
            pbVar13 = local_34 + local_30;
            local_2c = local_2c - local_30;
            local_24 = local_24 + local_30;
            puVar1[0x10] = puVar1[0x10] - local_30;
            local_38 = uVar15;
            local_34 = pbVar13;
            goto LAB_0067c188;
          }
          goto LAB_0067c1f8;
        case (undefined *)0x67b579:
          if (uVar12 < 0xe) {
            do {
              if (uVar15 == 0) goto LAB_0067c1f8;
              uVar15 = uVar15 - 1;
              bVar9 = (byte)uVar12;
              uVar12 = uVar12 + 8;
              local_3c = local_3c + ((uint)*pbVar13 << (bVar9 & 0x1f));
              pbVar13 = pbVar13 + 1;
              local_38 = uVar15;
            } while (uVar12 < 0xe);
            local_34 = pbVar13;
          }
          uVar12 = uVar12 - 0xe;
          uVar6 = local_3c >> 10;
          puVar1[0x18] = (local_3c & 0x1f) + 0x101;
          puVar1[0x19] = (local_3c >> 5 & 0x1f) + 1;
          local_3c = local_3c >> 0xe;
          puVar1[0x17] = (uVar6 & 0xf) + 4;
          if ((puVar1[0x18] < 0x11f) && (puVar1[0x19] < 0x1f)) {
            puVar1[0x1a] = 0;
            *puVar1 = 0x11;
            goto switchD_0067ac4e_caseD_67b603;
          }
          param_1[6] = (int)s_too_many_length_or_distance_symb_00a0da90;
          break;
        case (undefined *)0x67b603:
switchD_0067ac4e_caseD_67b603:
          if (puVar1[0x1a] < puVar1[0x17]) {
            do {
              for (; uVar12 < 3; uVar12 = uVar12 + 8) {
                if (uVar15 == 0) goto LAB_0067c1f8;
                uVar15 = uVar15 - 1;
                local_3c = local_3c + ((uint)*pbVar13 << ((byte)uVar12 & 0x1f));
                pbVar13 = pbVar13 + 1;
                local_38 = uVar15;
                local_34 = pbVar13;
              }
              uVar12 = uVar12 - 3;
              *(ushort *)
               ((int)puVar1 + (uint)*(ushort *)(&DAT_0081f9d4 + puVar1[0x1a] * 2) * 2 + 0x70) =
                   (ushort)local_3c & 7;
              uVar6 = puVar1[0x1a];
              puVar1[0x1a] = uVar6 + 1;
              local_3c = local_3c >> 3;
            } while (uVar6 + 1 < puVar1[0x17]);
          }
          uVar6 = puVar1[0x1a];
          while (uVar6 < 0x13) {
            *(undefined2 *)
             ((int)puVar1 + (uint)*(ushort *)(&DAT_0081f9d4 + puVar1[0x1a] * 2) * 2 + 0x70) = 0;
            uVar6 = puVar1[0x1a] + 1;
            puVar1[0x1a] = uVar6;
          }
          puVar1[0x13] = (uint)(puVar1 + 0x14c);
          puVar1[0x1b] = (uint)(puVar1 + 0x14c);
          puVar1[0x15] = 7;
          local_1c = FUN_0067efd0(0,puVar1 + 0x1c,0x13,puVar1 + 0x1b,puVar1 + 0x15,puVar1 + 0xbc);
          if (local_1c == 0) {
            puVar1[0x1a] = 0;
            *puVar1 = 0x12;
            goto switchD_0067ac4e_caseD_67b70b;
          }
          param_1[6] = (int)s_invalid_code_lengths_set_00a0dab4;
          break;
        case (undefined *)0x67b70b:
switchD_0067ac4e_caseD_67b70b:
          local_14 = puVar1[0x19] + puVar1[0x18];
          if (puVar1[0x1a] < local_14) {
            do {
              uVar6 = (1 << ((byte)puVar1[0x15] & 0x1f)) - 1;
              local_30 = *(uint *)(puVar1[0x13] + (uVar6 & local_3c) * 4);
              local_10 = (undefined1)local_30;
              bStack_f = (byte)(local_30 >> 8);
              uStack_e = (ushort)(local_30 >> 0x10);
              local_30 = local_30 >> 8;
              if (uVar12 < (local_30 & 0xff)) {
                do {
                  if (local_38 == 0) goto LAB_0067c1f8;
                  local_38 = local_38 - 1;
                  bVar9 = (byte)uVar12;
                  uVar12 = uVar12 + 8;
                  local_3c = local_3c + ((uint)*pbVar13 << (bVar9 & 0x1f));
                  pbVar13 = pbVar13 + 1;
                  local_30 = *(uint *)(puVar1[0x13] + (uVar6 & local_3c) * 4);
                  local_10 = (undefined1)local_30;
                  bStack_f = (byte)(local_30 >> 8);
                  uStack_e = (ushort)(local_30 >> 0x10);
                  local_30 = local_30 >> 8;
                  local_34 = pbVar13;
                } while (uVar12 < (local_30 & 0xff));
              }
              bVar9 = (byte)local_30;
              if (uStack_e < 0x10) {
                uVar12 = uVar12 - (local_30 & 0xff);
                local_3c = local_3c >> (bVar9 & 0x1f);
                *(ushort *)((int)puVar1 + puVar1[0x1a] * 2 + 0x70) = uStack_e;
                puVar1[0x1a] = puVar1[0x1a] + 1;
              }
              else {
                if (uStack_e == 0x10) {
                  uVar6 = (local_30 & 0xff) + 2;
                  if (uVar12 < uVar6) {
                    do {
                      if (local_38 == 0) goto LAB_0067c1f8;
                      local_38 = local_38 - 1;
                      bVar8 = (byte)uVar12;
                      uVar12 = uVar12 + 8;
                      local_3c = local_3c + ((uint)*pbVar13 << (bVar8 & 0x1f));
                      pbVar13 = pbVar13 + 1;
                    } while (uVar12 < uVar6);
                    local_34 = pbVar13;
                  }
                  local_3c = local_3c >> (bVar9 & 0x1f);
                  uVar12 = uVar12 - (local_30 & 0xff);
                  if (puVar1[0x1a] == 0) {
                    param_1[6] = (int)s_invalid_bit_length_repeat_00a0da74;
                    *puVar1 = 0x1d;
                    uVar15 = local_38;
                    goto LAB_0067b97b;
                  }
                  uVar14 = *(undefined2 *)((int)puVar1 + puVar1[0x1a] * 2 + 0x6e);
                  uVar6 = local_3c & 3;
                  local_3c = local_3c >> 2;
                  iVar5 = uVar6 + 3;
                  uVar12 = uVar12 - 2;
                }
                else {
                  if (uStack_e == 0x11) {
                    uVar6 = (local_30 & 0xff) + 3;
                    if (uVar12 < uVar6) {
                      do {
                        if (local_38 == 0) goto LAB_0067c1f8;
                        local_38 = local_38 - 1;
                        bVar8 = (byte)uVar12;
                        uVar12 = uVar12 + 8;
                        local_3c = local_3c + ((uint)*pbVar13 << (bVar8 & 0x1f));
                        pbVar13 = pbVar13 + 1;
                      } while (uVar12 < uVar6);
                      local_34 = pbVar13;
                    }
                    local_3c = local_3c >> (bVar9 & 0x1f);
                    iVar7 = -3;
                    iVar5 = (local_3c & 7) + 3;
                    local_3c = local_3c >> 3;
                  }
                  else {
                    uVar6 = (local_30 & 0xff) + 7;
                    if (uVar12 < uVar6) {
                      do {
                        if (local_38 == 0) goto LAB_0067c1f8;
                        local_38 = local_38 - 1;
                        bVar8 = (byte)uVar12;
                        uVar12 = uVar12 + 8;
                        local_3c = local_3c + ((uint)*pbVar13 << (bVar8 & 0x1f));
                        pbVar13 = pbVar13 + 1;
                      } while (uVar12 < uVar6);
                      local_34 = pbVar13;
                    }
                    local_3c = local_3c >> (bVar9 & 0x1f);
                    iVar7 = -7;
                    iVar5 = (local_3c & 0x7f) + 0xb;
                    local_3c = local_3c >> 7;
                  }
                  local_30 = local_30 & 0xff;
                  uVar14 = 0;
                  uVar12 = uVar12 + (iVar7 - local_30);
                }
                if (local_14 < puVar1[0x1a] + iVar5) {
                  param_1[6] = (int)s_invalid_bit_length_repeat_00a0da74;
                  *puVar1 = 0x1d;
                  break;
                }
                if (iVar5 != 0) {
                  do {
                    *(undefined2 *)((int)puVar1 + puVar1[0x1a] * 2 + 0x70) = uVar14;
                    iVar5 = iVar5 + -1;
                    puVar1[0x1a] = puVar1[0x1a] + 1;
                  } while (iVar5 != 0);
                }
              }
              local_14 = puVar1[0x19] + puVar1[0x18];
            } while (puVar1[0x1a] < local_14);
            uVar15 = local_38;
          }
LAB_0067b97b:
          if (*puVar1 != 0x1d) {
            if ((short)puVar1[0x9c] == 0) {
              param_1[6] = (int)s_invalid_code____missing_end_of_b_00a0da4c;
            }
            else {
              puVar1[0x13] = (uint)(puVar1 + 0x14c);
              puVar1[0x1b] = (uint)(puVar1 + 0x14c);
              puVar1[0x15] = 9;
              local_1c = FUN_0067efd0(1,puVar1 + 0x1c,puVar1[0x18],puVar1 + 0x1b,puVar1 + 0x15,
                                      puVar1 + 0xbc);
              if (local_1c == 0) {
                puVar1[0x14] = puVar1[0x1b];
                puVar1[0x16] = 6;
                local_1c = FUN_0067efd0(2,(int)puVar1 + puVar1[0x18] * 2 + 0x70,puVar1[0x19],
                                        puVar1 + 0x1b,puVar1 + 0x16,puVar1 + 0xbc);
                if (local_1c == 0) {
                  *puVar1 = 0x13;
                  if (param_2 != 6) goto switchD_0067ac4e_caseD_67ba44;
                  goto LAB_0067c1f8;
                }
                param_1[6] = (int)s_invalid_distances_set_00a0da18;
              }
              else {
                param_1[6] = (int)s_invalid_literal_lengths_set_00a0da30;
              }
            }
            break;
          }
          goto LAB_0067c188;
        case (undefined *)0x67ba44:
switchD_0067ac4e_caseD_67ba44:
          *puVar1 = 0x14;
        case (undefined *)0x67ba4a:
          if ((5 < uVar15) && (0x101 < local_2c)) {
            param_1[4] = local_2c;
            param_1[3] = (int)local_24;
            *param_1 = (int)pbVar13;
            param_1[1] = uVar15;
            puVar1[0xe] = local_3c;
            puVar1[0xf] = uVar12;
            FUN_0067eb30(param_1,local_20);
            uVar12 = puVar1[0xf];
            local_24 = (byte *)param_1[3];
            local_2c = param_1[4];
            pbVar13 = (byte *)*param_1;
            uVar15 = param_1[1];
            local_3c = puVar1[0xe];
            local_38 = uVar15;
            local_34 = pbVar13;
            if (*puVar1 == 0xb) {
              puVar1[0x6f1] = 0xffffffff;
            }
            goto LAB_0067c188;
          }
          puVar1[0x6f1] = 0;
          uVar6 = (1 << ((byte)puVar1[0x15] & 0x1f)) - 1;
          uVar11 = puVar1[0x13];
          uVar3 = *(uint *)(uVar11 + (uVar6 & local_3c) * 4);
          local_10 = (undefined1)uVar3;
          bStack_f = (byte)(uVar3 >> 8);
          uStack_e = (ushort)(uVar3 >> 0x10);
          uVar10 = uVar12;
          if (uVar12 < (uVar3 >> 8 & 0xff)) {
            do {
              if (uVar15 == 0) goto LAB_0067c1f8;
              uVar15 = uVar15 - 1;
              bVar9 = (byte)uVar12;
              uVar12 = uVar12 + 8;
              local_3c = local_3c + ((uint)*pbVar13 << (bVar9 & 0x1f));
              pbVar13 = pbVar13 + 1;
              uVar3 = *(uint *)(uVar11 + (uVar6 & local_3c) * 4);
              local_10 = (undefined1)uVar3;
              bStack_f = (byte)(uVar3 >> 8);
              uStack_e = (ushort)(uVar3 >> 0x10);
              uVar10 = uVar12;
              local_38 = uVar15;
              local_34 = pbVar13;
            } while (uVar12 < (uVar3 >> 8 & 0xff));
          }
          cVar2 = (char)uVar3;
          if (cVar2 != '\0') {
            if ((uVar3 & 0xf0) == 0) {
              bStack_7 = (byte)(uVar3 >> 8);
              uStack_6 = (ushort)(uVar3 >> 0x10);
              uVar6 = uVar3 >> 8 & 0xff;
              uVar3 = *(uint *)(uVar11 + ((((1 << (cVar2 + bStack_f & 0x1f)) - 1U & local_3c) >>
                                          (bStack_f & 0x1f)) + (uint)uStack_e) * 4);
              local_10 = (undefined1)uVar3;
              bStack_f = (byte)(uVar3 >> 8);
              uStack_e = (ushort)(uVar3 >> 0x10);
              uVar12 = uVar10;
              local_8 = cVar2;
              if (uVar10 < (uVar3 >> 8 & 0xff) + uVar6) {
                do {
                  if (local_38 == 0) goto LAB_0067c1f8;
                  local_38 = local_38 - 1;
                  uVar10 = uVar12 + 8;
                  local_3c = local_3c + ((uint)*pbVar13 << ((byte)uVar12 & 0x1f));
                  pbVar13 = pbVar13 + 1;
                  uVar3 = *(uint *)(uVar11 + ((((1 << (cVar2 + bStack_7 & 0x1f)) - 1U & local_3c) >>
                                              (bStack_7 & 0x1f)) + (uint)uStack_6) * 4);
                  local_10 = (undefined1)uVar3;
                  bStack_f = (byte)(uVar3 >> 8);
                  uStack_e = (ushort)(uVar3 >> 0x10);
                  uVar12 = uVar10;
                  local_34 = pbVar13;
                } while (uVar10 < (uVar3 >> 8 & 0xff) + uVar6);
              }
              local_3c = local_3c >> (bStack_7 & 0x1f);
              uVar10 = uVar10 - uVar6;
              puVar1[0x6f1] = uVar6;
              uVar15 = local_38;
            }
          }
          uVar6 = CONCAT21(uStack_e,bStack_f) & 0xff;
          local_3c = local_3c >> (bStack_f & 0x1f);
          uVar12 = uVar10 - uVar6;
          puVar1[0x6f1] = puVar1[0x6f1] + uVar6;
          puVar1[0x10] = (uint)uStack_e;
          if ((char)uVar3 == '\0') {
            *puVar1 = 0x19;
            goto LAB_0067c188;
          }
          if ((uVar3 & 0x20) != 0) {
            puVar1[0x6f1] = 0xffffffff;
            goto LAB_0067bc7b;
          }
          if ((uVar3 & 0x40) != 0) {
            param_1[6] = (int)s_invalid_literal_length_code_00a0d9fc;
            break;
          }
          puVar1[0x12] = uVar3 & 0xf;
          *puVar1 = 0x15;
switchD_0067ac4e_caseD_67bcaa:
          uVar6 = puVar1[0x12];
          if (uVar6 != 0) {
            if (uVar12 < uVar6) {
              do {
                if (uVar15 == 0) goto LAB_0067c1f8;
                uVar15 = uVar15 - 1;
                bVar9 = (byte)uVar12;
                uVar12 = uVar12 + 8;
                local_3c = local_3c + ((uint)*pbVar13 << (bVar9 & 0x1f));
                pbVar13 = pbVar13 + 1;
                local_38 = uVar15;
              } while (uVar12 < uVar6);
              local_34 = pbVar13;
            }
            puVar1[0x10] = puVar1[0x10] + ((1 << ((byte)uVar6 & 0x1f)) - 1U & local_3c);
            uVar6 = puVar1[0x12];
            local_3c = local_3c >> ((byte)uVar6 & 0x1f);
            uVar12 = uVar12 - uVar6;
            puVar1[0x6f1] = puVar1[0x6f1] + uVar6;
          }
          *puVar1 = 0x16;
          puVar1[0x6f2] = puVar1[0x10];
switchD_0067ac4e_caseD_67bd28:
          local_14 = (1 << ((byte)puVar1[0x16] & 0x1f)) - 1;
          uVar6 = *(uint *)(puVar1[0x14] + (local_14 & local_3c) * 4);
          local_10 = (undefined1)uVar6;
          bStack_f = (byte)(uVar6 >> 8);
          uStack_e = (ushort)(uVar6 >> 0x10);
          uVar11 = uVar12;
          if (uVar12 < (uVar6 >> 8 & 0xff)) {
            do {
              if (uVar15 == 0) goto LAB_0067c1f8;
              uVar15 = uVar15 - 1;
              bVar9 = (byte)uVar12;
              uVar12 = uVar12 + 8;
              local_3c = local_3c + ((uint)*pbVar13 << (bVar9 & 0x1f));
              pbVar13 = pbVar13 + 1;
              uVar6 = *(uint *)(puVar1[0x14] + (local_14 & local_3c) * 4);
              local_10 = (undefined1)uVar6;
              bStack_f = (byte)(uVar6 >> 8);
              uStack_e = (ushort)(uVar6 >> 0x10);
              local_38 = uVar15;
            } while (uVar12 < (uVar6 >> 8 & 0xff));
            uVar11 = uVar12;
            local_34 = pbVar13;
          }
          if ((uVar6 & 0xf0) == 0) {
            local_8 = (char)uVar6;
            bStack_7 = (byte)(uVar6 >> 8);
            uStack_6 = (ushort)(uVar6 >> 0x10);
            uVar15 = uVar6 >> 8 & 0xff;
            uVar6 = *(uint *)(puVar1[0x14] +
                             ((((1 << (local_8 + bStack_f & 0x1f)) - 1U & local_3c) >>
                              (bStack_f & 0x1f)) + (uint)uStack_e) * 4);
            local_10 = (undefined1)uVar6;
            bStack_f = (byte)(uVar6 >> 8);
            uStack_e = (ushort)(uVar6 >> 0x10);
            uVar12 = uVar11;
            if (uVar11 < (uVar6 >> 8 & 0xff) + uVar15) {
              do {
                if (local_38 == 0) goto LAB_0067c1f8;
                local_38 = local_38 - 1;
                uVar11 = uVar12 + 8;
                local_3c = local_3c + ((uint)*pbVar13 << ((byte)uVar12 & 0x1f));
                pbVar13 = pbVar13 + 1;
                uVar6 = *(uint *)(puVar1[0x14] +
                                 ((((1 << (local_8 + bStack_7 & 0x1f)) - 1U & local_3c) >>
                                  (bStack_7 & 0x1f)) + (uint)uStack_6) * 4);
                local_10 = (undefined1)uVar6;
                bStack_f = (byte)(uVar6 >> 8);
                uStack_e = (ushort)(uVar6 >> 0x10);
                uVar12 = uVar11;
              } while (uVar11 < (uVar6 >> 8 & 0xff) + uVar15);
              local_34 = pbVar13;
            }
            uVar11 = uVar11 - uVar15;
            local_3c = local_3c >> (bStack_7 & 0x1f);
            puVar1[0x6f1] = puVar1[0x6f1] + uVar15;
            uVar15 = local_38;
          }
          uVar12 = CONCAT21(uStack_e,bStack_f) & 0xff;
          puVar1[0x6f1] = puVar1[0x6f1] + uVar12;
          uVar12 = uVar11 - uVar12;
          local_3c = local_3c >> (bStack_f & 0x1f);
          if ((uVar6 & 0x40) != 0) {
            param_1[6] = (int)s_invalid_distance_code_00a0d9e4;
            break;
          }
          *puVar1 = 0x17;
          puVar1[0x11] = (uint)uStack_e;
          puVar1[0x12] = uVar6 & 0xf;
switchD_0067ac4e_caseD_67bec3:
          uVar6 = puVar1[0x12];
          if (uVar6 != 0) {
            if (uVar12 < uVar6) {
              do {
                if (uVar15 == 0) goto LAB_0067c1f8;
                uVar15 = uVar15 - 1;
                bVar9 = (byte)uVar12;
                uVar12 = uVar12 + 8;
                local_3c = local_3c + ((uint)*pbVar13 << (bVar9 & 0x1f));
                pbVar13 = pbVar13 + 1;
                local_38 = uVar15;
              } while (uVar12 < uVar6);
              local_34 = pbVar13;
            }
            local_14 = 1;
            puVar1[0x11] = puVar1[0x11] + ((1 << ((byte)uVar6 & 0x1f)) - 1U & local_3c);
            uVar6 = puVar1[0x12];
            local_3c = local_3c >> ((byte)uVar6 & 0x1f);
            uVar12 = uVar12 - uVar6;
            puVar1[0x6f1] = puVar1[0x6f1] + uVar6;
          }
          *puVar1 = 0x18;
switchD_0067ac4e_caseD_67bf36:
          if (local_2c != 0) {
            local_30 = puVar1[0x11];
            if (local_20 - local_2c < local_30) {
              local_30 = local_30 - (local_20 - local_2c);
              if ((puVar1[0xb] < local_30) && (puVar1[0x6f0] != 0)) {
                param_1[6] = (int)s_invalid_distance_too_far_back_00a0d9c4;
                break;
              }
              uVar6 = puVar1[0xc];
              if (uVar6 < local_30) {
                local_30 = local_30 - uVar6;
                pbVar4 = (byte *)((puVar1[0xd] + puVar1[10]) - local_30);
              }
              else {
                pbVar4 = (byte *)((puVar1[0xd] - local_30) + uVar6);
              }
              local_14 = puVar1[0x10];
              if (local_14 < local_30) {
                local_30 = local_14;
              }
            }
            else {
              pbVar4 = local_24 + -local_30;
              local_30 = puVar1[0x10];
              local_14 = local_30;
            }
            if (local_2c < local_30) {
              local_30 = local_2c;
            }
            local_2c = local_2c - local_30;
            puVar1[0x10] = local_14 - local_30;
            do {
              *local_24 = *pbVar4;
              local_24 = local_24 + 1;
              pbVar4 = pbVar4 + 1;
              local_30 = local_30 - 1;
            } while (local_30 != 0);
            if (puVar1[0x10] == 0) {
              *puVar1 = 0x14;
            }
            goto LAB_0067c188;
          }
          goto LAB_0067c1f8;
        case (undefined *)0x67bcaa:
          goto switchD_0067ac4e_caseD_67bcaa;
        case (undefined *)0x67bd28:
          goto switchD_0067ac4e_caseD_67bd28;
        case (undefined *)0x67bec3:
          goto switchD_0067ac4e_caseD_67bec3;
        case (undefined *)0x67bf36:
          goto switchD_0067ac4e_caseD_67bf36;
        case (undefined *)0x67c00a:
          if (local_2c == 0) goto LAB_0067c1f8;
          *local_24 = (byte)puVar1[0x10];
          local_24 = local_24 + 1;
          local_2c = local_2c - 1;
          *puVar1 = 0x14;
          goto LAB_0067c188;
        case (undefined *)0x67c038:
          if (puVar1[2] != 0) {
            for (; uVar12 < 0x20; uVar12 = uVar12 + 8) {
              if (uVar15 == 0) goto LAB_0067c1f8;
              uVar15 = uVar15 - 1;
              local_3c = local_3c + ((uint)*pbVar13 << ((byte)uVar12 & 0x1f));
              pbVar13 = pbVar13 + 1;
              local_38 = uVar15;
              local_34 = pbVar13;
            }
            local_20 = local_20 - local_2c;
            param_1[5] = param_1[5] + local_20;
            puVar1[7] = puVar1[7] + local_20;
            if (local_20 != 0) {
              if (puVar1[4] == 0) {
                uVar6 = FUN_0067c870(puVar1[6],(int)local_24 - local_20,local_20);
              }
              else {
                uVar6 = FUN_0067c560(puVar1[6],(int)local_24 - local_20);
              }
              puVar1[6] = uVar6;
              param_1[0xc] = uVar6;
            }
            local_20 = local_2c;
            uVar6 = local_3c;
            if (puVar1[4] == 0) {
              local_14 = ((local_3c & 0xff) * 0x10000 + (local_3c & 0xff00)) * 0x100;
              uVar6 = local_14 + (local_3c >> 0x10 & 0xff) * 0x100 + (local_3c >> 0x18);
            }
            if (uVar6 != puVar1[6]) {
              param_1[6] = (int)s_incorrect_data_check_00a0d9ac;
              break;
            }
            uVar12 = 0;
            local_3c = 0;
          }
          *puVar1 = 0x1b;
        case (undefined *)0x67c129:
          if ((puVar1[2] != 0) && (puVar1[4] != 0)) {
            for (; uVar12 < 0x20; uVar12 = uVar12 + 8) {
              if (uVar15 == 0) goto LAB_0067c1f8;
              uVar15 = uVar15 - 1;
              local_3c = local_3c + ((uint)*pbVar13 << ((byte)uVar12 & 0x1f));
              pbVar13 = pbVar13 + 1;
              local_38 = uVar15;
              local_34 = pbVar13;
            }
            if (local_3c != puVar1[7]) {
              param_1[6] = (int)s_incorrect_length_check_00a0d994;
              break;
            }
            local_3c = 0;
            uVar12 = 0;
          }
          *puVar1 = 0x1c;
switchD_0067ac4e_caseD_67c1e6:
          local_1c = 1;
          goto LAB_0067c1f8;
        case (undefined *)0x67c1e6:
          goto switchD_0067ac4e_caseD_67c1e6;
        case (undefined *)0x67c1f0:
          local_1c = -3;
          goto LAB_0067c1f8;
        case (undefined *)0x67c25f:
          goto switchD_0067ac4e_caseD_67c25f;
        }
        *puVar1 = 0x1d;
LAB_0067c188:
        uVar6 = *puVar1;
        if (0x1e < uVar6) {
          return -2;
        }
      } while( true );
    }
  }
  return -2;
}

