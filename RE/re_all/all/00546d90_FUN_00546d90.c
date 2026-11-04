
undefined4 FUN_00546d90(char *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint3 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  byte *pbVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  ushort *puVar19;
  int iVar20;
  byte *pbVar21;
  uint uVar22;
  int iVar23;
  byte *pbVar24;
  byte *pbVar25;
  uint uVar26;
  byte *local_80;
  undefined4 *local_7c;
  byte *local_78;
  int local_70;
  undefined4 *local_6c;
  undefined4 *local_60;
  byte *local_5c;
  byte *local_58;
  int local_50;
  int local_4c;
  undefined4 *local_48;
  undefined4 *local_44;
  undefined4 *local_40;
  byte *local_3c;
  int local_34;
  undefined4 *local_30;
  byte *local_28;
  undefined4 *local_24;
  int local_20;
  byte local_18 [4];
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  byte local_10 [5];
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  if (*param_1 == '\0') {
    return 0;
  }
  iVar5 = *(int *)(param_1 + 0x428);
  iVar7 = iVar5 * 4;
  iVar9 = *(int *)(param_1 + 0x42c) * iVar7;
  local_20 = (-(uint)(*(int *)(param_1 + 0x43c) != 0) & 5) + 1;
  iVar10 = FUN_0056e030(iVar9 * local_20,"..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",
                        0x15c8);
  if (iVar10 == 0) {
    return 0xffffffff;
  }
  iVar23 = (int)(*(int *)(param_1 + 0x428) + (*(int *)(param_1 + 0x428) >> 0x1f & 3U)) >> 2;
  iVar20 = (int)(*(int *)(param_1 + 0x42c) + (*(int *)(param_1 + 0x42c) >> 0x1f & 3U)) >> 2;
  if (local_20 != 0) {
    local_60 = (undefined4 *)(iVar10 + 8 + iVar7);
    iVar11 = iVar5 * -4 + -5;
    local_70 = iVar10;
    do {
      puVar19 = *(ushort **)(param_1 + 0x434);
      switch(*param_1) {
      case '\x01':
        if (iVar20 != 0) {
          local_6c = (undefined4 *)(local_70 + 8);
          local_80 = (byte *)(iVar5 * 0xc + 8 + local_70);
          local_7c = (undefined4 *)(local_70 + 8 + iVar5 * 8);
          local_78 = (byte *)local_60;
          local_50 = iVar20;
          do {
            if (iVar23 != 0) {
              local_3c = (byte *)local_6c;
              local_10[3] = 0xff;
              local_9 = 0xff;
              local_5 = 0xff;
              local_40 = (undefined4 *)local_78;
              local_44 = local_7c;
              local_48 = (undefined4 *)local_80;
              local_4c = iVar23;
              do {
                uVar3 = *puVar19;
                uVar15 = ((uVar3 & 0x1f) * 0xff) / 0x1f;
                uVar22 = ((uVar3 >> 5 & 0x3f) * 0xff) / 0x3f;
                local_10[1] = (char)uVar22;
                uVar12 = ((uint)(uVar3 >> 0xb) * 0xff) / 0x1f;
                local_10[2] = (char)uVar12;
                uVar4 = puVar19[1];
                uVar26 = ((uVar4 & 0x1f) * 0xff) / 0x1f;
                local_10[4] = (char)uVar26;
                uVar17 = ((uVar4 >> 5 & 0x3f) * 0xff) / 0x3f;
                local_b = (char)uVar17;
                uVar18 = ((uint)(uVar4 >> 0xb) * 0xff) / 0x1f;
                local_a = (char)uVar18;
                local_10[0] = (char)uVar15;
                if (puVar19[1] < uVar3) {
                  local_8 = (char)((ulonglong)
                                   ((longlong)(int)((uVar26 & 0xff) + (uVar15 & 0xff) * 2) *
                                   0x55555556) >> 0x20);
                  local_7 = (char)(((uVar17 & 0xff) + (uVar22 & 0xff) * 2) / 3);
                  local_6 = (char)(((uVar18 & 0xff) + (uVar12 & 0xff) * 2) / 3);
                  local_4 = (char)(((uVar15 & 0xff) + (uVar26 & 0xff) * 2) / 3);
                  local_3 = (char)(((uVar22 & 0xff) + (uVar17 & 0xff) * 2) / 3);
                  local_2 = (char)(((uVar12 & 0xff) + (uVar18 & 0xff) * 2) / 3);
                  local_1 = 0xff;
                }
                else {
                  local_7 = (undefined1)(((uVar17 & 0xff) + (uVar22 & 0xff)) / 2);
                  local_8 = (undefined1)(((uVar26 & 0xff) + (uVar15 & 0xff)) / 2);
                  local_4 = local_8;
                  local_6 = (undefined1)(((uVar18 & 0xff) + (uVar12 & 0xff)) / 2);
                  local_3 = local_7;
                  local_2 = local_6;
                  local_1 = 0;
                }
                uVar15 = *(uint *)(puVar19 + 2);
                *(undefined4 *)((int)local_3c + -8) =
                     *(undefined4 *)(local_18 + (uVar15 & 3) * 4 + 8);
                *(undefined4 *)((int)local_3c + -4) =
                     *(undefined4 *)(local_18 + (uVar15 >> 2 & 3) * 4 + 8);
                *(undefined4 *)local_3c = *(undefined4 *)(local_18 + (uVar15 >> 4 & 3) * 4 + 8);
                *(undefined4 *)((int)local_3c + 4) =
                     *(undefined4 *)(local_18 + (uVar15 >> 6 & 3) * 4 + 8);
                local_40[-2] = *(undefined4 *)(local_18 + (uVar15 >> 8 & 3) * 4 + 8);
                local_40[-1] = *(undefined4 *)(local_18 + (uVar15 >> 10 & 3) * 4 + 8);
                *local_40 = *(undefined4 *)(local_18 + (uVar15 >> 0xc & 3) * 4 + 8);
                local_40[1] = *(undefined4 *)(local_18 + (uVar15 >> 0xe & 3) * 4 + 8);
                local_44[-2] = *(undefined4 *)(local_18 + (uVar15 >> 0x10 & 3) * 4 + 8);
                local_44[-1] = *(undefined4 *)(local_18 + (uVar15 >> 0x12 & 3) * 4 + 8);
                *local_44 = *(undefined4 *)(local_18 + (uVar15 >> 0x14 & 3) * 4 + 8);
                local_44[1] = *(undefined4 *)(local_18 + (uVar15 >> 0x16 & 3) * 4 + 8);
                local_48[-2] = *(undefined4 *)(local_18 + (uVar15 >> 0x18 & 3) * 4 + 8);
                local_48[-1] = *(undefined4 *)(local_18 + (uVar15 >> 0x1a & 3) * 4 + 8);
                uVar6 = *(undefined4 *)(local_18 + (uVar15 >> 0x1e) * 4 + 8);
                *local_48 = *(undefined4 *)(local_18 + (uVar15 >> 0x1c & 3) * 4 + 8);
                local_48[1] = uVar6;
                local_3c = (byte *)((int)local_3c + 0x10);
                local_40 = local_40 + 4;
                local_44 = local_44 + 4;
                local_48 = local_48 + 4;
                puVar19 = puVar19 + 4;
                local_4c = local_4c + -1;
              } while (local_4c != 0);
            }
            local_6c = local_6c + iVar5 * 4;
            local_78 = (byte *)((int)local_78 + iVar5 * 4 * 4);
            local_7c = local_7c + iVar5 * 4;
            local_80 = (byte *)((int)local_80 + iVar5 * 4 * 4);
            local_50 = local_50 + -1;
          } while (local_50 != 0);
        }
        break;
      case '\x02':
        if (iVar20 != 0) {
          local_78 = (byte *)(iVar11 + (int)local_60);
          local_58 = (byte *)(local_70 + 3 + iVar5 * 0xc);
          local_5c = (byte *)(local_70 + 3 + iVar5 * 8);
          local_80 = (byte *)((int)local_60 + -5);
          local_30 = (undefined4 *)iVar20;
          do {
            if (iVar23 != 0) {
              iVar16 = iVar5 * -0xc + -3;
              local_10[3] = 0xff;
              local_9 = 0xff;
              local_5 = 0xff;
              local_1 = 0xff;
              pbVar14 = local_58;
              pbVar21 = local_78;
              pbVar24 = local_80;
              pbVar25 = local_5c;
              local_34 = iVar23;
              do {
                uVar3 = *puVar19;
                uVar15 = ((uVar3 & 0x1f) * 0xff) / 0x1f;
                local_10[0] = (char)uVar15;
                uVar22 = ((uVar3 >> 5 & 0x3f) * 0xff) / 0x3f;
                local_10[1] = (char)uVar22;
                uVar12 = ((uint)(uVar3 >> 0xb) * 0xff) / 0x1f;
                uVar3 = puVar19[1];
                local_10[2] = (char)uVar12;
                uVar26 = ((uVar3 & 0x1f) * 0xff) / 0x1f;
                local_10[4] = (char)uVar26;
                uVar17 = ((uVar3 >> 5 & 0x3f) * 0xff) / 0x3f;
                local_b = (char)uVar17;
                uVar18 = ((uint)(uVar3 >> 0xb) * 0xff) / 0x1f;
                uVar26 = uVar26 & 0xff;
                local_a = (char)uVar18;
                uVar15 = uVar15 & 0xff;
                local_8 = (char)((uVar26 + uVar15 * 2) / 3);
                uVar22 = uVar22 & 0xff;
                uVar17 = uVar17 & 0xff;
                uVar18 = uVar18 & 0xff;
                local_7 = (char)((uVar17 + uVar22 * 2) / 3);
                uVar12 = uVar12 & 0xff;
                local_6 = (char)((uVar18 + uVar12 * 2) / 3);
                local_4 = (char)((uVar15 + uVar26 * 2) / 3);
                local_3 = (char)((uVar22 + uVar17 * 2) / 3);
                local_2 = (char)((uVar12 + uVar18 * 2) / 3);
                uVar15 = *(uint *)(puVar19 + 2);
                *(undefined4 *)(pbVar21 + -3) = *(undefined4 *)(local_18 + (uVar15 & 3) * 4 + 8);
                *(undefined4 *)(pbVar21 + 1) = *(undefined4 *)(local_18 + (uVar15 >> 2 & 3) * 4 + 8)
                ;
                *(undefined4 *)(pbVar21 + 5) = *(undefined4 *)(local_18 + (uVar15 >> 4 & 3) * 4 + 8)
                ;
                *(undefined4 *)(pbVar21 + 9) = *(undefined4 *)(local_18 + (uVar15 >> 6 & 3) * 4 + 8)
                ;
                *(undefined4 *)(pbVar24 + -3) =
                     *(undefined4 *)(local_18 + (uVar15 >> 8 & 3) * 4 + 8);
                *(undefined4 *)(pbVar24 + 1) =
                     *(undefined4 *)(local_18 + (uVar15 >> 10 & 3) * 4 + 8);
                *(undefined4 *)(pbVar24 + 5) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0xc & 3) * 4 + 8);
                *(undefined4 *)(pbVar24 + 9) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0xe & 3) * 4 + 8);
                *(undefined4 *)(pbVar25 + -3) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x10 & 3) * 4 + 8);
                *(undefined4 *)(pbVar25 + 1) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x12 & 3) * 4 + 8);
                *(undefined4 *)(pbVar25 + 5) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x14 & 3) * 4 + 8);
                *(undefined4 *)(pbVar25 + 9) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x16 & 3) * 4 + 8);
                *(undefined4 *)(pbVar14 + -3) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x18 & 3) * 4 + 8);
                *(undefined4 *)(pbVar14 + 1) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x1a & 3) * 4 + 8);
                *(undefined4 *)(pbVar14 + 5) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x1c & 3) * 4 + 8);
                *(undefined4 *)(pbVar14 + 9) = *(undefined4 *)(local_18 + (uVar15 >> 0x1e) * 4 + 8);
                uVar15 = *(uint *)(puVar19 + 4);
                *pbVar21 = (byte)(((uVar15 & 0xf) * 0xff) / 0xf);
                pbVar21[4] = (byte)(((uVar15 >> 4 & 0xf) * 0xff) / 0xf);
                pbVar21[8] = (byte)(((uVar15 >> 8 & 0xf) * 0xff) / 0xf);
                pbVar21[0xc] = (byte)(((uVar15 >> 0xc & 0xf) * 0xff) / 0xf);
                *pbVar24 = (byte)(((uVar15 >> 0x10 & 0xf) * 0xff) / 0xf);
                pbVar24[4] = (byte)(((uVar15 >> 0x14 & 0xf) * 0xff) / 0xf);
                pbVar24[8] = (byte)(((uVar15 >> 0x18 & 0xf) * 0xff) / 0xf);
                pbVar24[0xc] = (byte)(((uVar15 >> 0x1c) * 0xff) / 0xf);
                uVar15 = *(uint *)(puVar19 + 6);
                *pbVar25 = (byte)(((uVar15 & 0xf) * 0xff) / 0xf);
                pbVar25[4] = (byte)(((uVar15 >> 4 & 0xf) * 0xff) / 0xf);
                pbVar25[8] = (byte)(((uVar15 >> 8 & 0xf) * 0xff) / 0xf);
                pbVar25[0xc] = (byte)(((uVar15 >> 0xc & 0xf) * 0xff) / 0xf);
                *pbVar14 = (byte)(((uVar15 >> 0x10 & 0xf) * 0xff) / 0xf);
                pbVar14[4] = (byte)(((uVar15 >> 0x14 & 0xf) * 0xff) / 0xf);
                pbVar14[8] = (byte)(((uVar15 >> 0x18 & 0xf) * 0xff) / 0xf);
                pbVar14[0xc] = (byte)(((uVar15 >> 0x1c) * 0xff) / 0xf);
                puVar19 = puVar19 + 8;
                uVar15 = (uint)*pbVar21;
                pbVar14[iVar16] =
                     (byte)((ulonglong)((uint)pbVar14[iVar16] * 0xff) /
                           (ulonglong)(longlong)(int)uVar15);
                pbVar21[-2] = (byte)((ulonglong)((uint)pbVar21[-2] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                uVar22 = (uint)pbVar21[4];
                pbVar21[-1] = (byte)((ulonglong)((uint)pbVar21[-1] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                pbVar21[1] = (byte)((ulonglong)((uint)pbVar21[1] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar21[2] = (byte)((ulonglong)((uint)pbVar21[2] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                uVar15 = (uint)pbVar21[8];
                pbVar21[3] = (byte)((ulonglong)((uint)pbVar21[3] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar21[5] = (byte)((ulonglong)((uint)pbVar21[5] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                pbVar21[6] = (byte)((ulonglong)((uint)pbVar21[6] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                uVar22 = (uint)pbVar21[0xc];
                pbVar21[7] = (byte)((ulonglong)((uint)pbVar21[7] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                pbVar21[9] = (byte)((ulonglong)((uint)pbVar21[9] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar21[10] = (byte)((ulonglong)((uint)pbVar21[10] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar22);
                pbVar21[0xb] = (byte)((ulonglong)((uint)pbVar21[0xb] * 0xff) /
                                     (ulonglong)(longlong)(int)uVar22);
                uVar15 = (uint)*pbVar24;
                pbVar24[-3] = (byte)((ulonglong)((uint)pbVar24[-3] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                pbVar24[-2] = (byte)((ulonglong)((uint)pbVar24[-2] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                uVar22 = (uint)pbVar24[4];
                pbVar24[-1] = (byte)((ulonglong)((uint)pbVar24[-1] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                pbVar24[1] = (byte)((ulonglong)((uint)pbVar24[1] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar24[2] = (byte)((ulonglong)((uint)pbVar24[2] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                uVar15 = (uint)pbVar24[8];
                pbVar24[3] = (byte)((ulonglong)((uint)pbVar24[3] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar24[5] = (byte)((ulonglong)((uint)pbVar24[5] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                pbVar24[6] = (byte)((ulonglong)((uint)pbVar24[6] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                uVar22 = (uint)pbVar24[0xc];
                pbVar24[7] = (byte)((ulonglong)((uint)pbVar24[7] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                pbVar24[9] = (byte)((ulonglong)((uint)pbVar24[9] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar24[10] = (byte)((ulonglong)((uint)pbVar24[10] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar22);
                pbVar24[0xb] = (byte)((ulonglong)((uint)pbVar24[0xb] * 0xff) /
                                     (ulonglong)(longlong)(int)uVar22);
                uVar15 = (uint)*pbVar25;
                pbVar25[-3] = (byte)((ulonglong)((uint)pbVar25[-3] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                pbVar25[-2] = (byte)((ulonglong)((uint)pbVar25[-2] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                uVar22 = (uint)pbVar25[4];
                pbVar25[-1] = (byte)((ulonglong)((uint)pbVar25[-1] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                pbVar25[1] = (byte)((ulonglong)((uint)pbVar25[1] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar25[2] = (byte)((ulonglong)((uint)pbVar25[2] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                uVar15 = (uint)pbVar25[8];
                pbVar25[3] = (byte)((ulonglong)((uint)pbVar25[3] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar25[5] = (byte)((ulonglong)((uint)pbVar25[5] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                pbVar25[6] = (byte)((ulonglong)((uint)pbVar25[6] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                uVar22 = (uint)pbVar25[0xc];
                pbVar25[7] = (byte)((ulonglong)((uint)pbVar25[7] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                pbVar25[9] = (byte)((ulonglong)((uint)pbVar25[9] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar25[10] = (byte)((ulonglong)((uint)pbVar25[10] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar22);
                pbVar25[0xb] = (byte)((ulonglong)((uint)pbVar25[0xb] * 0xff) /
                                     (ulonglong)(longlong)(int)uVar22);
                uVar15 = (uint)*pbVar14;
                pbVar14[-3] = (byte)((ulonglong)((uint)pbVar14[-3] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                pbVar14[-2] = (byte)((ulonglong)((uint)pbVar14[-2] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                uVar22 = (uint)pbVar14[4];
                pbVar14[-1] = (byte)((ulonglong)((uint)pbVar14[-1] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                pbVar14[1] = (byte)((ulonglong)((uint)pbVar14[1] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar14[2] = (byte)((ulonglong)((uint)pbVar14[2] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                uVar15 = (uint)pbVar14[8];
                pbVar21 = pbVar21 + 0x10;
                pbVar24 = pbVar24 + 0x10;
                pbVar25 = pbVar25 + 0x10;
                pbVar14[3] = (byte)((ulonglong)((uint)pbVar14[3] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar14[5] = (byte)((ulonglong)((uint)pbVar14[5] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                pbVar14[6] = (byte)((ulonglong)((uint)pbVar14[6] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                uVar22 = (uint)pbVar14[0xc];
                pbVar14[7] = (byte)((ulonglong)((uint)pbVar14[7] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                pbVar14[9] = (byte)((ulonglong)((uint)pbVar14[9] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar14[10] = (byte)((ulonglong)((uint)pbVar14[10] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar22);
                local_34 = local_34 + -1;
                pbVar14[0xb] = (byte)((ulonglong)((uint)pbVar14[0xb] * 0xff) /
                                     (ulonglong)(longlong)(int)uVar22);
                pbVar14 = pbVar14 + 0x10;
              } while (local_34 != 0);
            }
            iVar16 = iVar5 * 0x10;
            local_78 = local_78 + iVar16;
            local_80 = local_80 + iVar16;
            local_5c = local_5c + iVar16;
            local_58 = local_58 + iVar16;
            local_30 = (undefined4 *)((int)local_30 + -1);
          } while (local_30 != (undefined4 *)0x0);
        }
        break;
      case '\x03':
        if (iVar20 != 0) {
          local_58 = (byte *)(local_70 + 8);
          local_7c = (undefined4 *)(iVar5 * 0xc + 8 + local_70);
          local_6c = (undefined4 *)(local_70 + 8 + iVar5 * 8);
          local_5c = (byte *)local_60;
          local_34 = iVar20;
          do {
            if (iVar23 != 0) {
              local_10[3] = 0xff;
              local_9 = 0xff;
              local_5 = 0xff;
              local_1 = 0xff;
              local_78 = (byte *)local_7c;
              puVar13 = local_6c;
              pbVar14 = local_5c;
              pbVar21 = local_58;
              local_30 = (undefined4 *)iVar23;
              do {
                uVar3 = *puVar19;
                uVar15 = ((uVar3 & 0x1f) * 0xff) / 0x1f;
                local_10[0] = (char)uVar15;
                uVar22 = ((uVar3 >> 5 & 0x3f) * 0xff) / 0x3f;
                local_10[1] = (char)uVar22;
                uVar12 = ((uint)(uVar3 >> 0xb) * 0xff) / 0x1f;
                uVar3 = puVar19[1];
                local_10[2] = (char)uVar12;
                uVar26 = ((uVar3 & 0x1f) * 0xff) / 0x1f;
                local_10[4] = (char)uVar26;
                uVar17 = ((uVar3 >> 5 & 0x3f) * 0xff) / 0x3f;
                local_b = (char)uVar17;
                uVar18 = ((uint)(uVar3 >> 0xb) * 0xff) / 0x1f;
                uVar15 = uVar15 & 0xff;
                local_a = (char)uVar18;
                local_8 = (char)(((uVar26 & 0xff) + uVar15 * 2) / 3);
                local_7 = (char)(((uVar17 & 0xff) + (uVar22 & 0xff) * 2) / 3);
                local_6 = (char)(((uVar18 & 0xff) + (uVar12 & 0xff) * 2) / 3);
                local_4 = (char)((ulonglong)
                                 ((longlong)(int)(uVar15 + (uVar26 & 0xff) * 2) * 0x55555556) >>
                                0x20);
                local_3 = (char)(((uVar22 & 0xff) + (uVar17 & 0xff) * 2) / 3);
                uVar15 = *(uint *)(puVar19 + 2);
                local_2 = (char)((ulonglong)
                                 ((longlong)(int)((uVar12 & 0xff) + (uVar18 & 0xff) * 2) *
                                 0x55555556) >> 0x20);
                *(undefined4 *)((int)pbVar21 + -8) =
                     *(undefined4 *)(local_18 + (uVar15 & 3) * 4 + 8);
                *(undefined4 *)((int)pbVar21 + -4) =
                     *(undefined4 *)(local_18 + (uVar15 >> 2 & 3) * 4 + 8);
                *(undefined4 *)pbVar21 = *(undefined4 *)(local_18 + (uVar15 >> 4 & 3) * 4 + 8);
                *(undefined4 *)((int)pbVar21 + 4) =
                     *(undefined4 *)(local_18 + (uVar15 >> 6 & 3) * 4 + 8);
                *(undefined4 *)((int)pbVar14 + -8) =
                     *(undefined4 *)(local_18 + (uVar15 >> 8 & 3) * 4 + 8);
                *(undefined4 *)((int)pbVar14 + -4) =
                     *(undefined4 *)(local_18 + (uVar15 >> 10 & 3) * 4 + 8);
                *(undefined4 *)pbVar14 = *(undefined4 *)(local_18 + (uVar15 >> 0xc & 3) * 4 + 8);
                *(undefined4 *)((int)pbVar14 + 4) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0xe & 3) * 4 + 8);
                puVar13[-2] = *(undefined4 *)(local_18 + (uVar15 >> 0x10 & 3) * 4 + 8);
                puVar13[-1] = *(undefined4 *)(local_18 + (uVar15 >> 0x12 & 3) * 4 + 8);
                *puVar13 = *(undefined4 *)(local_18 + (uVar15 >> 0x14 & 3) * 4 + 8);
                puVar13[1] = *(undefined4 *)(local_18 + (uVar15 >> 0x16 & 3) * 4 + 8);
                *(undefined4 *)((int)local_78 + -8) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x18 & 3) * 4 + 8);
                *(undefined4 *)((int)local_78 + -4) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x1a & 3) * 4 + 8);
                *(undefined4 *)((int)local_78 + 4) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x1e) * 4 + 8);
                *(undefined4 *)local_78 = *(undefined4 *)(local_18 + (uVar15 >> 0x1c & 3) * 4 + 8);
                uVar15 = *(uint *)(puVar19 + 4);
                *(char *)((int)pbVar21 + -5) = (char)(((uVar15 & 0xf) * 0xff) / 0xf);
                *(char *)((int)pbVar21 + -1) = (char)(((uVar15 >> 4 & 0xf) * 0xff) / 0xf);
                *(char *)((int)pbVar21 + 3) = (char)(((uVar15 >> 8 & 0xf) * 0xff) / 0xf);
                *(char *)((int)pbVar21 + 7) = (char)(((uVar15 >> 0xc & 0xf) * 0xff) / 0xf);
                *(char *)((int)pbVar14 + -5) = (char)(((uVar15 >> 0x10 & 0xf) * 0xff) / 0xf);
                *(char *)((int)pbVar14 + -1) = (char)(((uVar15 >> 0x14 & 0xf) * 0xff) / 0xf);
                *(char *)((int)pbVar14 + 3) = (char)(((uVar15 >> 0x18 & 0xf) * 0xff) / 0xf);
                *(char *)((int)pbVar14 + 7) = (char)(((uVar15 >> 0x1c) * 0xff) / 0xf);
                uVar15 = *(uint *)(puVar19 + 6);
                *(char *)((int)puVar13 + -5) = (char)(((uVar15 & 0xf) * 0xff) / 0xf);
                *(char *)((int)puVar13 + -1) = (char)(((uVar15 >> 4 & 0xf) * 0xff) / 0xf);
                *(char *)((int)puVar13 + 3) = (char)(((uVar15 >> 8 & 0xf) * 0xff) / 0xf);
                *(char *)((int)puVar13 + 7) = (char)(((uVar15 >> 0xc & 0xf) * 0xff) / 0xf);
                *(char *)((int)local_78 + -5) = (char)(((uVar15 >> 0x10 & 0xf) * 0xff) / 0xf);
                *(char *)((int)local_78 + -1) = (char)(((uVar15 >> 0x14 & 0xf) * 0xff) / 0xf);
                *(char *)((int)local_78 + 3) = (char)(((uVar15 >> 0x18 & 0xf) * 0xff) / 0xf);
                *(char *)((int)local_78 + 7) = (char)(((uVar15 >> 0x1c) * 0xff) / 0xf);
                local_78 = (byte *)((int)local_78 + 0x10);
                puVar19 = puVar19 + 8;
                pbVar21 = (byte *)((int)pbVar21 + 0x10);
                pbVar14 = (byte *)((int)pbVar14 + 0x10);
                puVar13 = puVar13 + 4;
                local_30 = (undefined4 *)((int)local_30 + -1);
              } while (local_30 != (undefined4 *)0x0);
            }
            local_58 = (byte *)((int)local_58 + iVar5 * 4 * 4);
            local_5c = (byte *)((int)local_5c + iVar5 * 4 * 4);
            local_6c = local_6c + iVar5 * 4;
            local_7c = local_7c + iVar5 * 4;
            local_34 = local_34 + -1;
          } while (local_34 != 0);
        }
        break;
      case '\x04':
        if (iVar20 != 0) {
          local_58 = (byte *)(iVar11 + (int)local_60);
          local_3c = (byte *)(local_70 + 3 + iVar5 * 8);
          local_28 = (byte *)(local_70 + 3 + iVar5 * 0xc);
          local_5c = (byte *)((int)local_60 + -5);
          local_24 = (undefined4 *)iVar20;
          do {
            if (iVar23 != 0) {
              iVar16 = iVar5 * -0xc + -3;
              local_10[3] = 0xff;
              local_9 = 0xff;
              local_5 = 0xff;
              local_1 = 0xff;
              pbVar14 = local_58;
              pbVar21 = local_3c;
              pbVar24 = local_28;
              pbVar25 = local_5c;
              local_34 = iVar23;
              do {
                uVar3 = *puVar19;
                uVar15 = ((uVar3 & 0x1f) * 0xff) / 0x1f;
                local_10[0] = (char)uVar15;
                uVar22 = ((uVar3 >> 5 & 0x3f) * 0xff) / 0x3f;
                local_10[1] = (char)uVar22;
                uVar12 = ((uint)(uVar3 >> 0xb) * 0xff) / 0x1f;
                uVar3 = puVar19[1];
                local_10[2] = (char)uVar12;
                uVar26 = ((uVar3 & 0x1f) * 0xff) / 0x1f;
                local_10[4] = (char)uVar26;
                uVar17 = ((uVar3 >> 5 & 0x3f) * 0xff) / 0x3f;
                local_b = (char)uVar17;
                uVar18 = ((uint)(uVar3 >> 0xb) * 0xff) / 0x1f;
                uVar26 = uVar26 & 0xff;
                local_a = (char)uVar18;
                uVar15 = uVar15 & 0xff;
                local_8 = (char)((uVar26 + uVar15 * 2) / 3);
                uVar22 = uVar22 & 0xff;
                uVar17 = uVar17 & 0xff;
                uVar18 = uVar18 & 0xff;
                local_7 = (char)((uVar17 + uVar22 * 2) / 3);
                uVar12 = uVar12 & 0xff;
                local_6 = (char)((uVar18 + uVar12 * 2) / 3);
                local_4 = (char)((uVar15 + uVar26 * 2) / 3);
                local_3 = (char)((uVar22 + uVar17 * 2) / 3);
                local_2 = (char)((uVar12 + uVar18 * 2) / 3);
                uVar15 = *(uint *)(puVar19 + 2);
                *(undefined4 *)(pbVar14 + -3) = *(undefined4 *)(local_18 + (uVar15 & 3) * 4 + 8);
                *(undefined4 *)(pbVar14 + 1) = *(undefined4 *)(local_18 + (uVar15 >> 2 & 3) * 4 + 8)
                ;
                *(undefined4 *)(pbVar14 + 5) = *(undefined4 *)(local_18 + (uVar15 >> 4 & 3) * 4 + 8)
                ;
                *(undefined4 *)(pbVar14 + 9) = *(undefined4 *)(local_18 + (uVar15 >> 6 & 3) * 4 + 8)
                ;
                *(undefined4 *)(pbVar25 + -3) =
                     *(undefined4 *)(local_18 + (uVar15 >> 8 & 3) * 4 + 8);
                *(undefined4 *)(pbVar25 + 1) =
                     *(undefined4 *)(local_18 + (uVar15 >> 10 & 3) * 4 + 8);
                *(undefined4 *)(pbVar25 + 5) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0xc & 3) * 4 + 8);
                *(undefined4 *)(pbVar25 + 9) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0xe & 3) * 4 + 8);
                *(undefined4 *)(pbVar21 + -3) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x10 & 3) * 4 + 8);
                *(undefined4 *)(pbVar21 + 1) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x12 & 3) * 4 + 8);
                *(undefined4 *)(pbVar21 + 5) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x14 & 3) * 4 + 8);
                *(undefined4 *)(pbVar21 + 9) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x16 & 3) * 4 + 8);
                *(undefined4 *)(pbVar24 + -3) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x18 & 3) * 4 + 8);
                *(undefined4 *)(pbVar24 + 1) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x1a & 3) * 4 + 8);
                uVar6 = *(undefined4 *)(local_18 + (uVar15 >> 0x1e) * 4 + 8);
                *(undefined4 *)(pbVar24 + 5) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x1c & 3) * 4 + 8);
                *(undefined4 *)(pbVar24 + 9) = uVar6;
                local_18[0] = (byte)puVar19[4];
                local_18[1] = *(byte *)((int)puVar19 + 9);
                uVar15 = (uint)local_18[0];
                uVar22 = (uint)local_18[1];
                if (local_18[1] < local_18[0]) {
                  local_18[2] = (char)((uVar22 + uVar15 * 6) / 7);
                  local_18[3] = (char)((uVar15 * 5 + uVar22 * 2) / 7);
                  local_14 = (char)((uVar22 * 3 + uVar15 * 4) / 7);
                  local_13 = (char)((uVar15 * 3 + uVar22 * 4) / 7);
                  local_12 = (char)((uVar22 * 5 + uVar15 * 2) / 7);
                  local_11 = (char)((uVar15 + uVar22 * 6) / 7);
                }
                else {
                  local_18[2] = (char)((uVar22 + uVar15 * 4) / 5);
                  local_18[3] = (char)((uVar15 * 3 + uVar22 * 2) / 5);
                  local_14 = (char)((uVar22 * 3 + uVar15 * 2) / 5);
                  local_13 = (char)((uVar15 + uVar22 * 4) / 5);
                  local_12 = 0;
                  local_11 = 0xff;
                }
                uVar3 = *(ushort *)((int)puVar19 + 0xb);
                uVar8 = *(uint3 *)(puVar19 + 5);
                *pbVar14 = local_18[uVar8 & 7];
                pbVar14[4] = local_18[uVar8 >> 3 & 7];
                pbVar14[8] = local_18[uVar8 >> 6 & 7];
                pbVar14[0xc] = local_18[uVar3 >> 1 & 7];
                *pbVar25 = local_18[uVar3 >> 4 & 7];
                pbVar25[4] = local_18[uVar3 >> 7 & 7];
                pbVar25[8] = local_18[uVar3 >> 10 & 7];
                pbVar25[0xc] = local_18[uVar3 >> 0xd];
                bVar1 = *(byte *)((int)puVar19 + 0xf);
                bVar2 = (byte)puVar19[7];
                uVar3 = puVar19[7];
                uVar8 = *(uint3 *)((int)puVar19 + 0xd);
                *pbVar21 = local_18[uVar8 & 7];
                pbVar21[4] = local_18[uVar8 >> 3 & 7];
                pbVar21[8] = local_18[uVar8 >> 6 & 7];
                pbVar21[0xc] = local_18[(bVar2 & 0xe) >> 1];
                *pbVar24 = local_18[(bVar2 & 0x70) >> 4];
                pbVar24[4] = local_18[uVar3 >> 7 & 7];
                pbVar24[0xc] = local_18[bVar1 >> 5];
                pbVar24[8] = local_18[(bVar1 & 0x1c) >> 2];
                uVar15 = (uint)*pbVar14;
                puVar19 = puVar19 + 8;
                pbVar24[iVar16] =
                     (byte)((ulonglong)((uint)pbVar24[iVar16] * 0xff) /
                           (ulonglong)(longlong)(int)uVar15);
                pbVar14[-2] = (byte)((ulonglong)((uint)pbVar14[-2] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                uVar22 = (uint)pbVar14[4];
                pbVar14[-1] = (byte)((ulonglong)((uint)pbVar14[-1] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                pbVar14[1] = (byte)((ulonglong)((uint)pbVar14[1] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar14[2] = (byte)((ulonglong)((uint)pbVar14[2] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                uVar15 = (uint)pbVar14[8];
                pbVar14[3] = (byte)((ulonglong)((uint)pbVar14[3] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar14[5] = (byte)((ulonglong)((uint)pbVar14[5] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                pbVar14[6] = (byte)((ulonglong)((uint)pbVar14[6] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                uVar22 = (uint)pbVar14[0xc];
                pbVar14[7] = (byte)((ulonglong)((uint)pbVar14[7] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                pbVar14[9] = (byte)((ulonglong)((uint)pbVar14[9] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar14[10] = (byte)((ulonglong)((uint)pbVar14[10] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar22);
                pbVar14[0xb] = (byte)((ulonglong)((uint)pbVar14[0xb] * 0xff) /
                                     (ulonglong)(longlong)(int)uVar22);
                uVar15 = (uint)*pbVar25;
                pbVar25[-3] = (byte)((ulonglong)((uint)pbVar25[-3] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                pbVar25[-2] = (byte)((ulonglong)((uint)pbVar25[-2] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                uVar22 = (uint)pbVar25[4];
                pbVar25[-1] = (byte)((ulonglong)((uint)pbVar25[-1] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                pbVar25[1] = (byte)((ulonglong)((uint)pbVar25[1] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar25[2] = (byte)((ulonglong)((uint)pbVar25[2] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                uVar15 = (uint)pbVar25[8];
                pbVar25[3] = (byte)((ulonglong)((uint)pbVar25[3] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar25[5] = (byte)((ulonglong)((uint)pbVar25[5] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                pbVar25[6] = (byte)((ulonglong)((uint)pbVar25[6] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                uVar22 = (uint)pbVar25[0xc];
                pbVar25[7] = (byte)((ulonglong)((uint)pbVar25[7] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                pbVar25[9] = (byte)((ulonglong)((uint)pbVar25[9] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar25[10] = (byte)((ulonglong)((uint)pbVar25[10] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar22);
                pbVar25[0xb] = (byte)((ulonglong)((uint)pbVar25[0xb] * 0xff) /
                                     (ulonglong)(longlong)(int)uVar22);
                uVar15 = (uint)*pbVar21;
                pbVar21[-3] = (byte)((ulonglong)((uint)pbVar21[-3] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                pbVar21[-2] = (byte)((ulonglong)((uint)pbVar21[-2] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                uVar22 = (uint)pbVar21[4];
                pbVar21[-1] = (byte)((ulonglong)((uint)pbVar21[-1] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                pbVar21[1] = (byte)((ulonglong)((uint)pbVar21[1] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar21[2] = (byte)((ulonglong)((uint)pbVar21[2] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                uVar15 = (uint)pbVar21[8];
                pbVar21[3] = (byte)((ulonglong)((uint)pbVar21[3] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar21[5] = (byte)((ulonglong)((uint)pbVar21[5] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                pbVar21[6] = (byte)((ulonglong)((uint)pbVar21[6] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                uVar22 = (uint)pbVar21[0xc];
                pbVar21[7] = (byte)((ulonglong)((uint)pbVar21[7] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                pbVar21[9] = (byte)((ulonglong)((uint)pbVar21[9] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar21[10] = (byte)((ulonglong)((uint)pbVar21[10] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar22);
                pbVar21[0xb] = (byte)((ulonglong)((uint)pbVar21[0xb] * 0xff) /
                                     (ulonglong)(longlong)(int)uVar22);
                uVar15 = (uint)*pbVar24;
                pbVar24[-3] = (byte)((ulonglong)((uint)pbVar24[-3] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                pbVar24[-2] = (byte)((ulonglong)((uint)pbVar24[-2] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                uVar22 = (uint)pbVar24[4];
                pbVar24[-1] = (byte)((ulonglong)((uint)pbVar24[-1] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar15);
                pbVar24[1] = (byte)((ulonglong)((uint)pbVar24[1] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar24[2] = (byte)((ulonglong)((uint)pbVar24[2] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                uVar15 = (uint)pbVar24[8];
                pbVar25 = pbVar25 + 0x10;
                pbVar21 = pbVar21 + 0x10;
                pbVar24[3] = (byte)((ulonglong)((uint)pbVar24[3] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar24[5] = (byte)((ulonglong)((uint)pbVar24[5] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                pbVar24[6] = (byte)((ulonglong)((uint)pbVar24[6] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                uVar22 = (uint)pbVar24[0xc];
                pbVar24[7] = (byte)((ulonglong)((uint)pbVar24[7] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar15);
                pbVar24[9] = (byte)((ulonglong)((uint)pbVar24[9] * 0xff) /
                                   (ulonglong)(longlong)(int)uVar22);
                pbVar24[10] = (byte)((ulonglong)((uint)pbVar24[10] * 0xff) /
                                    (ulonglong)(longlong)(int)uVar22);
                pbVar14 = pbVar14 + 0x10;
                local_34 = local_34 + -1;
                pbVar24[0xb] = (byte)((ulonglong)((uint)pbVar24[0xb] * 0xff) /
                                     (ulonglong)(longlong)(int)uVar22);
                pbVar24 = pbVar24 + 0x10;
              } while (local_34 != 0);
            }
            iVar16 = iVar5 * 0x10;
            local_58 = local_58 + iVar16;
            local_5c = local_5c + iVar16;
            local_3c = local_3c + iVar16;
            local_28 = local_28 + iVar16;
            local_24 = (undefined4 *)((int)local_24 + -1);
          } while (local_24 != (undefined4 *)0x0);
        }
        break;
      case '\x05':
        if (iVar20 != 0) {
          local_3c = (byte *)(local_70 + 8);
          local_48 = (undefined4 *)(iVar5 * 0xc + 8 + local_70);
          local_44 = (undefined4 *)(local_70 + 8 + iVar5 * 8);
          local_4c = iVar20;
          local_40 = local_60;
          do {
            if (iVar23 != 0) {
              local_24 = local_40;
              local_10[3] = 0xff;
              local_9 = 0xff;
              local_5 = 0xff;
              local_1 = 0xff;
              local_28 = (byte *)local_44;
              local_30 = local_48;
              pbVar14 = local_3c;
              local_34 = iVar23;
              do {
                uVar3 = *puVar19;
                uVar15 = ((uVar3 & 0x1f) * 0xff) / 0x1f;
                uVar22 = ((uVar3 >> 5 & 0x3f) * 0xff) / 0x3f;
                local_10[1] = (char)uVar22;
                uVar4 = puVar19[1];
                uVar12 = ((uint)(uVar3 >> 0xb) * 0xff) / 0x1f;
                local_10[2] = (char)uVar12;
                uVar26 = ((uVar4 & 0x1f) * 0xff) / 0x1f;
                local_10[4] = (char)uVar26;
                uVar17 = ((uVar4 >> 5 & 0x3f) * 0xff) / 0x3f;
                local_b = (char)uVar17;
                uVar26 = uVar26 & 0xff;
                uVar18 = ((uint)(uVar4 >> 0xb) * 0xff) / 0x1f;
                local_10[0] = (char)uVar15;
                local_a = (char)uVar18;
                uVar15 = uVar15 & 0xff;
                uVar22 = uVar22 & 0xff;
                local_8 = (char)((ulonglong)((longlong)(int)(uVar26 + uVar15 * 2) * 0x55555556) >>
                                0x20);
                local_7 = (char)(((uVar17 & 0xff) + uVar22 * 2) / 3);
                local_6 = (char)(((uVar18 & 0xff) + (uVar12 & 0xff) * 2) / 3);
                local_4 = (char)((uVar15 + uVar26 * 2) / 3);
                local_3 = (char)((uVar22 + (uVar17 & 0xff) * 2) / 3);
                uVar15 = *(uint *)(puVar19 + 2);
                local_2 = (char)(((uVar12 & 0xff) + (uVar18 & 0xff) * 2) / 3);
                *(undefined4 *)((int)pbVar14 + -8) =
                     *(undefined4 *)(local_18 + (uVar15 & 3) * 4 + 8);
                *(undefined4 *)((int)pbVar14 + -4) =
                     *(undefined4 *)(local_18 + (uVar15 >> 2 & 3) * 4 + 8);
                *(undefined4 *)pbVar14 = *(undefined4 *)(local_18 + (uVar15 >> 4 & 3) * 4 + 8);
                *(undefined4 *)((int)pbVar14 + 4) =
                     *(undefined4 *)(local_18 + (uVar15 >> 6 & 3) * 4 + 8);
                local_24[-2] = *(undefined4 *)(local_18 + (uVar15 >> 8 & 3) * 4 + 8);
                local_24[-1] = *(undefined4 *)(local_18 + (uVar15 >> 10 & 3) * 4 + 8);
                *local_24 = *(undefined4 *)(local_18 + (uVar15 >> 0xc & 3) * 4 + 8);
                local_24[1] = *(undefined4 *)(local_18 + (uVar15 >> 0xe & 3) * 4 + 8);
                *(undefined4 *)((int)local_28 + -8) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x10 & 3) * 4 + 8);
                *(undefined4 *)((int)local_28 + -4) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x12 & 3) * 4 + 8);
                *(undefined4 *)local_28 = *(undefined4 *)(local_18 + (uVar15 >> 0x14 & 3) * 4 + 8);
                uVar6 = *(undefined4 *)(local_18 + (uVar15 >> 0x18 & 3) * 4 + 8);
                *(undefined4 *)((int)local_28 + 4) =
                     *(undefined4 *)(local_18 + (uVar15 >> 0x16 & 3) * 4 + 8);
                local_30[-2] = uVar6;
                local_30[-1] = *(undefined4 *)(local_18 + (uVar15 >> 0x1a & 3) * 4 + 8);
                uVar6 = *(undefined4 *)(local_18 + (uVar15 >> 0x1e) * 4 + 8);
                *local_30 = *(undefined4 *)(local_18 + (uVar15 >> 0x1c & 3) * 4 + 8);
                local_30[1] = uVar6;
                local_18[0] = (byte)puVar19[4];
                local_18[1] = *(byte *)((int)puVar19 + 9);
                uVar15 = (uint)local_18[0];
                uVar22 = (uint)local_18[1];
                if (local_18[1] < local_18[0]) {
                  local_18[2] = (char)((uVar22 + uVar15 * 6) / 7);
                  local_18[3] = (char)((uVar15 * 5 + uVar22 * 2) / 7);
                  local_14 = (char)((uVar22 * 3 + uVar15 * 4) / 7);
                  local_13 = (char)((uVar15 * 3 + uVar22 * 4) / 7);
                  local_12 = (char)((uVar22 * 5 + uVar15 * 2) / 7);
                  local_11 = (char)((uVar15 + uVar22 * 6) / 7);
                }
                else {
                  local_18[2] = (char)((uVar22 + uVar15 * 4) / 5);
                  local_18[3] = (char)((uVar15 * 3 + uVar22 * 2) / 5);
                  local_14 = (char)((uVar22 * 3 + uVar15 * 2) / 5);
                  local_13 = (char)((uVar15 + uVar22 * 4) / 5);
                  local_12 = 0;
                  local_11 = 0xff;
                }
                uVar3 = *(ushort *)((int)puVar19 + 0xb);
                uVar8 = *(uint3 *)(puVar19 + 5);
                *(byte *)((int)pbVar14 + -5) = local_18[uVar8 & 7];
                *(byte *)((int)pbVar14 + -1) = local_18[uVar8 >> 3 & 7];
                *(byte *)((int)pbVar14 + 3) = local_18[uVar8 >> 6 & 7];
                *(byte *)((int)pbVar14 + 7) = local_18[uVar3 >> 1 & 7];
                *(byte *)((int)local_24 + -5) = local_18[uVar3 >> 4 & 7];
                *(byte *)((int)local_24 + -1) = local_18[uVar3 >> 7 & 7];
                *(byte *)((int)local_24 + 3) = local_18[uVar3 >> 10 & 7];
                *(byte *)((int)local_24 + 7) = local_18[uVar3 >> 0xd];
                bVar1 = *(byte *)((int)puVar19 + 0xf);
                bVar2 = (byte)puVar19[7];
                uVar3 = puVar19[7];
                uVar8 = *(uint3 *)((int)puVar19 + 0xd);
                *(byte *)((int)local_28 + -5) = local_18[uVar8 & 7];
                *(byte *)((int)local_28 + -1) = local_18[uVar8 >> 3 & 7];
                *(byte *)((int)local_28 + 3) = local_18[uVar8 >> 6 & 7];
                *(byte *)((int)local_28 + 7) = local_18[(bVar2 & 0xe) >> 1];
                *(byte *)((int)local_30 + -5) = local_18[(bVar2 & 0x70) >> 4];
                *(byte *)((int)local_30 + -1) = local_18[uVar3 >> 7 & 7];
                bVar2 = local_18[bVar1 >> 5];
                *(byte *)((int)local_30 + 3) = local_18[(bVar1 & 0x1c) >> 2];
                *(byte *)((int)local_30 + 7) = bVar2;
                local_24 = local_24 + 4;
                local_28 = (byte *)((int)local_28 + 0x10);
                local_30 = local_30 + 4;
                puVar19 = puVar19 + 8;
                pbVar14 = (byte *)((int)pbVar14 + 0x10);
                local_34 = local_34 + -1;
              } while (local_34 != 0);
            }
            local_3c = (byte *)((int)local_3c + iVar5 * 4 * 4);
            local_40 = local_40 + iVar5 * 4;
            local_44 = local_44 + iVar5 * 4;
            local_48 = local_48 + iVar5 * 4;
            local_4c = local_4c + -1;
          } while (local_4c != 0);
        }
      }
      local_70 = local_70 + iVar9;
      local_60 = (undefined4 *)((int)local_60 + iVar9);
      local_20 = local_20 + -1;
    } while (local_20 != 0);
  }
  if (param_2 != 0) {
    FUN_0056e1d0(*(undefined4 *)(param_1 + 0x434));
  }
  *(int *)(param_1 + 0x434) = iVar10;
  FUN_00544500(param_1);
  *(int *)(param_1 + 0x430) = iVar7;
  return 0;
}

