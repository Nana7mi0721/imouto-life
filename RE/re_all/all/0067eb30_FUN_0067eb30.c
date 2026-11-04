
void FUN_0067eb30(int *param_1,uint param_2)

{
  int iVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined1 *puVar12;
  int iVar13;
  undefined1 *puVar14;
  byte *pbVar15;
  byte *pbVar16;
  byte *pbVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  undefined1 *puVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  undefined1 *puVar25;
  uint uVar26;
  byte *local_44;
  undefined1 uStack_6;
  undefined1 uStack_5;
  
  puVar3 = (undefined4 *)param_1[7];
  pbVar15 = (byte *)(*param_1 + -1);
  iVar4 = param_1[4];
  pbVar2 = pbVar15 + param_1[1] + -5;
  puVar22 = (undefined1 *)(param_1[3] + -1);
  iVar13 = iVar4 - param_2;
  uVar19 = puVar3[0xf];
  iVar18 = puVar3[10];
  uVar5 = puVar3[0xb];
  uVar6 = puVar3[0xc];
  iVar21 = puVar3[0xd];
  iVar7 = puVar3[0x13];
  iVar8 = puVar3[0x14];
  uVar9 = puVar3[0x15];
  uVar10 = puVar3[0x16];
  uVar26 = puVar3[0xe];
  puVar24 = puVar22;
  local_44 = pbVar15;
LAB_0067ebc2:
  if (uVar19 < 0xf) {
    pbVar16 = pbVar15 + 1;
    pbVar17 = pbVar15 + 2;
    pbVar15 = pbVar15 + 2;
    uVar26 = uVar26 + ((uint)*pbVar16 << ((byte)uVar19 & 0x1f)) +
             ((uint)*pbVar17 << ((byte)uVar19 + 8 & 0x1f));
    uVar19 = uVar19 + 0x10;
    local_44 = pbVar15;
  }
  uVar11 = *(uint *)(iVar7 + ((1 << ((byte)uVar9 & 0x1f)) - 1U & uVar26) * 4);
  uStack_6 = (undefined1)(uVar11 >> 0x10);
  uStack_5 = (undefined1)(uVar11 >> 0x18);
  uVar26 = uVar26 >> ((byte)(uVar11 >> 8) & 0x1f);
  uVar19 = uVar19 - (uVar11 >> 8 & 0xff);
  while ((uVar11 & 0xff) != 0) {
    if ((uVar11 & 0x10) != 0) {
      param_2 = (uint)CONCAT11(uStack_5,uStack_6);
      uVar11 = uVar11 & 0xf;
      pbVar17 = pbVar15;
      if (uVar11 != 0) {
        if (uVar19 < uVar11) {
          pbVar15 = pbVar15 + 1;
          uVar26 = uVar26 + ((uint)*pbVar15 << ((byte)uVar19 & 0x1f));
          uVar19 = uVar19 + 8;
          local_44 = pbVar15;
        }
        param_2 = param_2 + ((1 << (sbyte)uVar11) - 1U & uVar26);
        uVar26 = uVar26 >> (sbyte)uVar11;
        uVar19 = uVar19 - uVar11;
        pbVar17 = pbVar15;
      }
      if (uVar19 < 0xf) {
        pbVar16 = pbVar17 + 1;
        pbVar15 = pbVar17 + 2;
        pbVar17 = pbVar17 + 2;
        uVar26 = uVar26 + ((uint)*pbVar16 << ((byte)uVar19 & 0x1f)) +
                 ((uint)*pbVar15 << ((byte)uVar19 + 8 & 0x1f));
        uVar19 = uVar19 + 0x10;
        local_44 = pbVar17;
      }
      uVar11 = *(uint *)(iVar8 + ((1 << ((byte)uVar10 & 0x1f)) - 1U & uVar26) * 4);
      uStack_6 = (undefined1)(uVar11 >> 0x10);
      uStack_5 = (undefined1)(uVar11 >> 0x18);
      uVar26 = uVar26 >> ((byte)(uVar11 >> 8) & 0x1f);
      uVar19 = uVar19 - (uVar11 >> 8 & 0xff);
      goto joined_r0x0067ed03;
    }
    if ((uVar11 & 0x40) != 0) {
      if ((uVar11 & 0x20) != 0) {
        *puVar3 = 0xb;
        goto LAB_0067ef78;
      }
      param_1[6] = (int)s_invalid_literal_length_code_00a0d9fc;
      goto LAB_0067ef71;
    }
    uVar11 = *(uint *)(iVar7 + (((1 << ((byte)uVar11 & 0x1f)) - 1U & uVar26) +
                               (uint)CONCAT11(uStack_5,uStack_6)) * 4);
    uStack_6 = (undefined1)(uVar11 >> 0x10);
    uStack_5 = (undefined1)(uVar11 >> 0x18);
    uVar26 = uVar26 >> ((byte)(uVar11 >> 8) & 0x1f);
    uVar19 = uVar19 - (uVar11 >> 8 & 0xff);
  }
  puVar23 = puVar24 + 1;
  *puVar23 = uStack_6;
  goto LAB_0067ef24;
joined_r0x0067ed03:
  pbVar15 = pbVar17;
  if ((uVar11 & 0x10) != 0) goto LAB_0067ed4f;
  if ((uVar11 & 0x40) != 0) {
    param_1[6] = (int)s_invalid_distance_code_00a0d9e4;
LAB_0067ef71:
    *puVar3 = 0x1d;
    goto LAB_0067ef78;
  }
  uVar11 = *(uint *)(iVar8 + (((1 << ((byte)uVar11 & 0x1f)) - 1U & uVar26) +
                             (uint)CONCAT11(uStack_5,uStack_6)) * 4);
  uStack_6 = (undefined1)(uVar11 >> 0x10);
  uStack_5 = (undefined1)(uVar11 >> 0x18);
  uVar26 = uVar26 >> ((byte)(uVar11 >> 8) & 0x1f);
  uVar19 = uVar19 - (uVar11 >> 8 & 0xff);
  goto joined_r0x0067ed03;
LAB_0067ed4f:
  uVar11 = uVar11 & 0xf;
  uVar20 = uVar19;
  if (uVar19 < uVar11) {
    pbVar15 = pbVar17 + 1;
    uVar20 = uVar19 + 8;
    uVar26 = uVar26 + ((uint)*pbVar15 << ((byte)uVar19 & 0x1f));
    local_44 = pbVar15;
    if (uVar20 < uVar11) {
      pbVar15 = pbVar17 + 2;
      uVar26 = uVar26 + ((uint)*pbVar15 << ((byte)uVar20 & 0x1f));
      uVar20 = uVar19 + 0x10;
      local_44 = pbVar15;
    }
  }
  uVar19 = uVar20 - uVar11;
  uVar20 = (uint)CONCAT11(uStack_5,uStack_6) + ((1 << (sbyte)uVar11) - 1U & uVar26);
  uVar26 = uVar26 >> (sbyte)uVar11;
  if (uVar20 <= (uint)((int)puVar24 - (int)(puVar22 + iVar13))) {
    puVar14 = puVar24 + -uVar20;
    do {
      puVar25 = puVar24;
      puVar12 = puVar14;
      puVar25[1] = puVar12[1];
      puVar25[2] = puVar12[2];
      puVar23 = puVar25 + 3;
      *puVar23 = puVar12[3];
      param_2 = param_2 - 3;
      puVar14 = puVar12 + 3;
      puVar24 = puVar23;
    } while (2 < param_2);
    if (param_2 != 0) {
      puVar23 = puVar25 + 4;
      *puVar23 = puVar12[4];
      if (1 < param_2) {
        puVar23 = puVar25 + 5;
        *puVar23 = puVar12[5];
      }
    }
    goto LAB_0067ef24;
  }
  uVar11 = uVar20 - ((int)puVar24 - (int)(puVar22 + iVar13));
  if ((uVar5 < uVar11) && (puVar3[0x6f0] != 0)) {
    param_1[6] = (int)s_invalid_distance_too_far_back_00a0d9c4;
    *puVar3 = 0x1d;
LAB_0067ef78:
    iVar18 = (int)pbVar15 - (uVar19 >> 3);
    iVar21 = uVar19 + (uVar19 >> 3) * -8;
    *param_1 = iVar18 + 1;
    param_1[3] = (int)(puVar24 + 1);
    param_1[1] = (int)(pbVar2 + (5 - iVar18));
    param_1[4] = (int)(puVar22 + iVar4 + -0x101 + (0x101 - (int)puVar24));
    puVar3[0xe] = uVar26 & (1 << ((byte)iVar21 & 0x1f)) - 1U;
    puVar3[0xf] = iVar21;
    return;
  }
  iVar1 = iVar21 + -1;
  if (uVar6 == 0) {
    puVar14 = (undefined1 *)(iVar1 + (iVar18 - uVar11));
    if (uVar11 < param_2) {
      param_2 = param_2 - uVar11;
      do {
        puVar23 = puVar14 + 1;
        puVar14 = puVar14 + 1;
        puVar24 = puVar24 + 1;
        uVar11 = uVar11 - 1;
        *puVar24 = *puVar23;
      } while (uVar11 != 0);
LAB_0067ee7e:
      puVar14 = puVar24 + -uVar20;
    }
  }
  else if (uVar6 < uVar11) {
    puVar14 = (undefined1 *)(iVar1 + (uVar6 - uVar11) + iVar18);
    uVar11 = uVar11 - uVar6;
    if (uVar11 < param_2) {
      param_2 = param_2 - uVar11;
      do {
        puVar23 = puVar14 + 1;
        puVar14 = puVar14 + 1;
        puVar24 = puVar24 + 1;
        uVar11 = uVar11 - 1;
        *puVar24 = *puVar23;
      } while (uVar11 != 0);
      puVar14 = (undefined1 *)(iVar21 + -1);
      if (uVar6 < param_2) {
        param_2 = param_2 - uVar6;
        uVar11 = uVar6;
        do {
          puVar23 = puVar14 + 1;
          puVar14 = puVar14 + 1;
          puVar24 = puVar24 + 1;
          uVar11 = uVar11 - 1;
          *puVar24 = *puVar23;
        } while (uVar11 != 0);
        goto LAB_0067ee7e;
      }
    }
  }
  else {
    puVar14 = (undefined1 *)(iVar1 + (uVar6 - uVar11));
    if (uVar11 < param_2) {
      param_2 = param_2 - uVar11;
      do {
        puVar23 = puVar14 + 1;
        puVar14 = puVar14 + 1;
        puVar24 = puVar24 + 1;
        uVar11 = uVar11 - 1;
        *puVar24 = *puVar23;
      } while (uVar11 != 0);
      goto LAB_0067ee7e;
    }
  }
  if (2 < param_2) {
    uVar11 = param_2 / 3;
    do {
      puVar23 = puVar14 + 2;
      puVar24[1] = puVar14[1];
      puVar14 = puVar14 + 3;
      puVar24[2] = *puVar23;
      puVar24 = puVar24 + 3;
      *puVar24 = *puVar14;
      param_2 = param_2 - 3;
      uVar11 = uVar11 - 1;
    } while (uVar11 != 0);
    pbVar15 = local_44;
  }
  puVar23 = puVar24;
  if (param_2 != 0) {
    puVar23 = puVar24 + 1;
    *puVar23 = puVar14[1];
    if (1 < param_2) {
      puVar23 = puVar24 + 2;
      *puVar23 = puVar14[2];
    }
  }
LAB_0067ef24:
  puVar24 = puVar23;
  if ((pbVar2 <= pbVar15) || (puVar22 + iVar4 + -0x101 <= puVar23)) goto LAB_0067ef78;
  goto LAB_0067ebc2;
}

