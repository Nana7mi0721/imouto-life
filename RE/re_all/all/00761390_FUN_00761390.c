
void FUN_00761390(uint param_1,int *param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ushort uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int *local_34;
  int local_30;
  int *local_2c;
  int local_28;
  undefined4 local_14;
  int local_8;
  
  if (*(int *)(*(int *)(param_1 + 0x14) + 0x24) == 1) {
    return;
  }
  if (*(int *)(*(int *)(param_1 + 0x14) + 0x2c) == 1) {
    return;
  }
  if (param_2 == (int *)0x0) {
    local_2c = *(int **)(param_1 + 4);
    local_28 = *(int *)(param_1 + 8);
    iVar5 = 0;
    local_34 = param_2;
LAB_007613fc:
    local_30 = iVar5;
  }
  else {
    piVar1 = (int *)*param_2;
    local_2c = (int *)param_2[2];
    if ((int)local_2c < (int)piVar1) {
      local_34 = local_2c;
      local_2c = piVar1;
    }
    else {
      local_34 = piVar1;
    }
    iVar5 = param_2[1];
    local_30 = param_2[3];
    if (iVar5 <= local_30) {
      local_28 = local_30;
      goto LAB_007613fc;
    }
    local_28 = iVar5;
  }
  FUN_00514e10(&local_34,&DAT_00dca3e4);
  iVar5 = DAT_00dca3f8;
  uVar14 = (int)local_2c - (int)local_34;
  local_8 = local_28 - local_30;
  if (uVar14 == 0) {
    return;
  }
  if (local_8 == 0) {
    return;
  }
  iVar11 = *(int *)(param_1 + 0x14);
  uVar6 = (uint)*(byte *)(*(int *)(iVar11 + 0x14) + 4);
  iVar10 = *(int *)(iVar11 + 0xc) - uVar6 * uVar14;
  puVar3 = (uint *)(*(int *)(iVar11 + 0xc) * local_30 + uVar6 * (int)local_34 +
                   *(int *)(param_1 + 0xc));
  param_1 = uVar14;
  if (*(int *)(iVar11 + 0x20) == 0) {
    if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
      param_3 = ((param_3 >> 5 & 0x3f) * (DAT_00dca3fc >> 8 & 0xff) & 0xffffff07 |
                (param_3 & 0x1f) * (DAT_00dca3fc & 0xff) >> 5) >> 3 |
                (param_3 >> 8 & 0xfffff8) * (DAT_00dca3fc >> 0x10 & 0xff) & 0xfffff800;
    }
    switch(DAT_00dca3f4) {
    case 0:
switchD_007618e4_caseD_0:
      do {
        uVar6 = uVar14 >> 1;
        if (uVar6 != 0) {
          for (; uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar3 = param_3 | param_3 << 0x10;
            puVar3 = puVar3 + 1;
          }
        }
        if ((uVar14 & 1) != 0) {
          *(ushort *)puVar3 = (ushort)param_3;
          puVar3 = (uint *)((int)puVar3 + 2);
        }
        puVar3 = (uint *)((int)puVar3 + iVar10);
        local_8 = local_8 + -1;
      } while (local_8 != 0);
      return;
    case 1:
      if (DAT_00dca3f8 == 0xff) goto switchD_007618e4_caseD_0;
      if (DAT_00dca3f8 != 0) {
        while( true ) {
          while( true ) {
            uVar9 = (ushort)*puVar3;
            *(ushort *)puVar3 =
                 ((uVar9 >> 5 & 0x3f) +
                 *(short *)(&DAT_00d4a6e0 +
                           ((param_3 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar5 * 0x800)) *
                 0x20 | ((uVar9 >> 0xb) +
                        *(short *)(&DAT_00d4a6e0 +
                                  ((param_3 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar5 * 0x800)) *
                        0x800 |
                 (uVar9 & 0x1f) +
                 *(short *)(&DAT_00d4a6e0 + ((param_3 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar5 * 0x800)
            ;
            param_1 = param_1 - 1;
            if (param_1 == 0) break;
            puVar3 = (uint *)((int)puVar3 + 2);
          }
          local_8 = local_8 + -1;
          if (local_8 == 0) break;
          puVar3 = (uint *)((int)puVar3 + 2 + iVar10);
          param_1 = uVar14;
        }
        return;
      }
      break;
    case 2:
      if (DAT_00dca3f8 != 0) {
        iVar5 = DAT_00dca3f8 * 0x100;
        iVar11 = DAT_00dca3f8 * 0x100;
        iVar2 = DAT_00dca3f8 * 0x100;
        do {
          param_1 = uVar14;
          do {
            uVar9 = (*(short *)(&DAT_00d0a2e0 + iVar5 + (param_3 >> 0xb)) * 0x40 +
                    *(short *)(&DAT_00d0a2e0 + iVar11 + (param_3 >> 5 & 0x3f))) * 0x20 +
                    *(short *)(&DAT_00d0a2e0 + iVar2 + (param_3 & 0x1f));
            puVar4 = (uint *)((int)puVar3 + 2);
            uVar12 = ((ushort)*puVar3 & 0xf7def7df) + (uVar9 & 0xf7def7df);
            uVar6 = uVar12 & 0x8210820;
            *(ushort *)puVar3 =
                 (short)uVar6 - (short)(uVar6 >> 5) | ((ushort)*puVar3 | uVar9) & 0x820 |
                 (ushort)uVar12;
            param_1 = param_1 - 1;
            puVar3 = puVar4;
          } while (param_1 != 0);
          puVar3 = (uint *)((int)puVar4 + iVar10);
          local_8 = local_8 + -1;
        } while (local_8 != 0);
        return;
      }
      break;
    case 3:
      if (DAT_00dca3f8 != 0) {
        iVar5 = DAT_00dca3f8 * 0x100;
        iVar11 = DAT_00dca3f8 * 0x100;
        iVar2 = DAT_00dca3f8 * 0x100;
        do {
          uVar6 = uVar14;
          do {
            puVar4 = (uint *)((int)puVar3 + 2);
            uVar13 = ((ushort)*puVar3 | 0x8210820) -
                     ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar5 + (param_3 >> 0xb)) * 0x40 +
                               *(short *)(&DAT_00d0a2e0 + iVar11 + (param_3 >> 5 & 0x3f))) * 0x20 +
                              *(short *)(&DAT_00d0a2e0 + iVar2 + (param_3 & 0x1f))) & 0xf7def7df);
            uVar12 = uVar13 & 0x8210820;
            uVar6 = uVar6 - 1;
            *(ushort *)puVar3 = (short)uVar12 - (short)(uVar12 >> 5) & (ushort)uVar13;
            puVar3 = puVar4;
          } while (uVar6 != 0);
          puVar3 = (uint *)((int)puVar4 + iVar10);
          local_8 = local_8 + -1;
        } while (local_8 != 0);
        return;
      }
      break;
    case 4:
      do {
        param_1 = uVar14;
        do {
          uVar6 = (uint)(ushort)*puVar3;
          *(ushort *)puVar3 =
               (ushort)((uVar6 & 0x7e0) * (param_3 & 0x7e0) >> 0xb) & 0x7e0 |
               (ushort)((uVar6 & 0xf800) * (param_3 & 0xf800) >> 0x10) & 0xf800 |
               (ushort)((uVar6 & 0x1f) * (param_3 & 0x1f) >> 5);
          puVar3 = (uint *)((int)puVar3 + 2);
          param_1 = param_1 - 1;
        } while (param_1 != 0);
        puVar3 = (uint *)((int)puVar3 + iVar10);
        local_8 = local_8 + -1;
      } while (local_8 != 0);
      return;
    case 10:
      uVar6 = ~param_3 & 0xffff;
      while( true ) {
        while( true ) {
          uVar9 = (ushort)*puVar3;
          *(ushort *)puVar3 =
               ((uVar9 >> 5 & 0x3f) +
               *(short *)(&DAT_00d4a6e0 +
                         ((uVar6 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar5 * 0x800)) * 0x20 |
               ((uVar9 >> 0xb) +
               *(short *)(&DAT_00d4a6e0 +
                         ((uVar6 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar5 * 0x800)) * 0x800 |
               (uVar9 & 0x1f) +
               *(short *)(&DAT_00d4a6e0 + ((~param_3 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar5 * 0x800);
          param_1 = param_1 - 1;
          if (param_1 == 0) break;
          puVar3 = (uint *)((int)puVar3 + 2);
        }
        local_8 = local_8 + -1;
        if (local_8 == 0) break;
        puVar3 = (uint *)((int)puVar3 + 2 + iVar10);
        param_1 = uVar14;
      }
      break;
    case 0xb:
      do {
        param_1 = uVar14;
        do {
          uVar9 = (ushort)*puVar3;
          uVar6 = uVar9 >> 5 & 0x3f;
          puVar4 = (uint *)((int)puVar3 + 2);
          *(ushort *)puVar3 =
               ((uVar9 >> 5 & 0x3f) +
               *(short *)(&DAT_00d4a6e0 +
                         ((uVar6 * (param_3 >> 5 & 0x3f) >> 6) - uVar6) * 4 + iVar5 * 0x800)) * 0x20
               | ((uVar9 >> 0xb) +
                 *(short *)(&DAT_00d4a6e0 +
                           (((uint)(uVar9 >> 0xb) * (param_3 >> 0xb) >> 5) - (uint)(uVar9 >> 0xb)) *
                           4 + iVar5 * 0x800)) * 0x800 |
               (uVar9 & 0x1f) +
               *(short *)(&DAT_00d4a6e0 +
                         (((uVar9 & 0x1f) * (param_3 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                         iVar5 * 0x800);
          param_1 = param_1 - 1;
          puVar3 = puVar4;
        } while (param_1 != 0);
        puVar3 = (uint *)((int)puVar4 + iVar10);
        local_8 = local_8 + -1;
      } while (local_8 != 0);
      return;
    }
  }
  else if (*(int *)(iVar11 + 0x20) == 1) {
    if ((DAT_00dca3fc & 0xffffff) == 0xffffff) {
      uVar6 = (uint)param_3._2_1_;
      uVar12 = param_3 & 0xff;
    }
    else {
      iVar5 = (DAT_00dca3fc >> 0x10 & 0xff) * (uint)param_3._2_1_;
      iVar11 = (param_3 & 0xff) * (DAT_00dca3fc & 0xff);
      uVar6 = iVar5 >> 8;
      uVar12 = iVar11 >> 8;
      param_3 = CONCAT31(CONCAT12(param_3._3_1_,
                                  CONCAT11((char)((uint)iVar5 >> 8),
                                           (char)((param_3 >> 8 & 0xff) * (DAT_00dca3fc >> 8 & 0xff)
                                                 >> 8))),(char)((uint)iVar11 >> 8));
    }
    switch(DAT_00dca3f4) {
    case 0:
switchD_00761506_caseD_0:
      do {
        for (uVar6 = uVar14; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar3 = param_3;
          puVar3 = puVar3 + 1;
        }
        puVar3 = (uint *)((int)puVar3 + iVar10);
        local_8 = local_8 + -1;
      } while (local_8 != 0);
      return;
    case 1:
      if (DAT_00dca3f8 == 0xff) goto switchD_00761506_caseD_0;
      if (DAT_00dca3f8 != 0) {
        uVar13 = uVar14;
        while( true ) {
          do {
            *(byte *)puVar3 =
                 (byte)((uVar12 - (byte)*puVar3) * DAT_00dca3f8 + (uint)(byte)*puVar3 * 0x100 >> 8);
            *(byte *)((int)puVar3 + 1) =
                 (byte)(((uint)param_3._1_1_ - (uint)*(byte *)((int)puVar3 + 1)) * DAT_00dca3f8 +
                        (uint)*(byte *)((int)puVar3 + 1) * 0x100 >> 8);
            *(byte *)((int)puVar3 + 2) =
                 (byte)((uVar6 - *(byte *)((int)puVar3 + 2)) * DAT_00dca3f8 +
                        (uint)*(byte *)((int)puVar3 + 2) * 0x100 >> 8);
            puVar3 = puVar3 + 1;
            uVar13 = uVar13 - 1;
          } while (uVar13 != 0);
          puVar3 = (uint *)((int)puVar3 + iVar10);
          local_8 = local_8 + -1;
          if (local_8 == 0) break;
          uVar13 = uVar14;
        }
        return;
      }
      break;
    case 2:
      if (DAT_00dca3f8 != 0) {
        iVar5 = DAT_00dca3f8 * 0x100;
        iVar11 = DAT_00dca3f8 * 0x100;
        iVar2 = DAT_00dca3f8 * 0x100;
        do {
          param_1 = uVar14;
          do {
            local_14._0_2_ =
                 CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar11 + (uint)param_3._1_1_),
                          *(undefined1 *)(&DAT_00d0a2e0 + iVar5 + uVar12));
            local_14._0_3_ =
                 CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar2 + uVar6),(undefined2)local_14);
            local_14 = (uint)(uint3)local_14;
            uVar7 = (*puVar3 & 0xfefeff) + (local_14 & 0xfefeff);
            uVar13 = uVar7 & 0x1010100;
            *puVar3 = uVar13 - (uVar13 >> 8) | (*puVar3 | local_14) & 0x10100 | uVar7;
            puVar3 = puVar3 + 1;
            param_1 = param_1 - 1;
          } while (param_1 != 0);
          puVar3 = (uint *)((int)puVar3 + iVar10);
          local_8 = local_8 + -1;
        } while (local_8 != 0);
        return;
      }
      break;
    case 3:
      if (DAT_00dca3f8 != 0) {
        iVar5 = DAT_00dca3f8 * 0x100;
        iVar11 = DAT_00dca3f8 * 0x100;
        iVar2 = DAT_00dca3f8 * 0x100;
        do {
          uVar13 = uVar14;
          do {
            uVar7 = local_14;
            local_14._0_2_ =
                 CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar11 + (uint)param_3._1_1_),
                          *(undefined1 *)(&DAT_00d0a2e0 + iVar5 + uVar12));
            local_14._3_1_ = SUB41(uVar7,3);
            local_14._0_3_ =
                 CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar2 + uVar6),(undefined2)local_14);
            uVar8 = (*puVar3 | 0x1010100) - (local_14 & 0xfefefeff);
            uVar7 = uVar8 & 0x1010100;
            *puVar3 = uVar7 - (uVar7 >> 8) & uVar8;
            puVar3 = puVar3 + 1;
            uVar13 = uVar13 - 1;
          } while (uVar13 != 0);
          puVar3 = (uint *)((int)puVar3 + iVar10);
          local_8 = local_8 + -1;
        } while (local_8 != 0);
        return;
      }
      break;
    case 4:
      do {
        uVar13 = uVar14;
        do {
          *(byte *)puVar3 = (byte)((byte)*puVar3 * uVar12 >> 8);
          *(byte *)((int)puVar3 + 1) =
               (byte)((uint)*(byte *)((int)puVar3 + 1) * (uint)param_3._1_1_ >> 8);
          *(byte *)((int)puVar3 + 2) = (byte)(*(byte *)((int)puVar3 + 2) * uVar6 >> 8);
          puVar3 = puVar3 + 1;
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
        puVar3 = (uint *)((int)puVar3 + iVar10);
        local_8 = local_8 + -1;
      } while (local_8 != 0);
      return;
    case 10:
      uVar13 = uVar14;
      while( true ) {
        do {
          *(byte *)puVar3 =
               (byte)(((uint)(byte)~(byte)uVar12 - (uint)(byte)*puVar3) * DAT_00dca3f8 +
                      (uint)(byte)*puVar3 * 0x100 >> 8);
          *(byte *)((int)puVar3 + 1) =
               (byte)(((uint)(byte)~param_3._1_1_ - (uint)*(byte *)((int)puVar3 + 1)) * DAT_00dca3f8
                      + (uint)*(byte *)((int)puVar3 + 1) * 0x100 >> 8);
          *(byte *)((int)puVar3 + 2) =
               (byte)(((uint)(byte)~(byte)uVar6 - (uint)*(byte *)((int)puVar3 + 2)) * DAT_00dca3f8 +
                      (uint)*(byte *)((int)puVar3 + 2) * 0x100 >> 8);
          puVar3 = puVar3 + 1;
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
        puVar3 = (uint *)((int)puVar3 + iVar10);
        local_8 = local_8 + -1;
        if (local_8 == 0) break;
        uVar13 = uVar14;
      }
      return;
    case 0xb:
      uVar13 = uVar14;
      while( true ) {
        do {
          uVar7 = (uint)(byte)*puVar3;
          uVar8 = (uint)*(byte *)((int)puVar3 + 1);
          *(byte *)puVar3 =
               (byte)((((int)(uVar7 * uVar12) >> 8) - uVar7) * DAT_00dca3f8 + uVar7 * 0x100 >> 8);
          uVar7 = (uint)*(byte *)((int)puVar3 + 2);
          *(byte *)((int)puVar3 + 1) =
               (byte)((((int)(uVar8 * param_3._1_1_) >> 8) - uVar8) * DAT_00dca3f8 + uVar8 * 0x100
                     >> 8);
          *(byte *)((int)puVar3 + 2) =
               (byte)((((int)(uVar7 * uVar6) >> 8) - uVar7) * DAT_00dca3f8 + uVar7 * 0x100 >> 8);
          puVar3 = puVar3 + 1;
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
        puVar3 = (uint *)((int)puVar3 + iVar10);
        local_8 = local_8 + -1;
        if (local_8 == 0) break;
        uVar13 = uVar14;
      }
      return;
    }
  }
  return;
}

