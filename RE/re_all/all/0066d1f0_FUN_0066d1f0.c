
uint FUN_0066d1f0(int param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  undefined2 *puVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  ushort uVar8;
  short sVar9;
  short sVar10;
  int iVar11;
  int iVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  byte bVar15;
  byte bVar16;
  undefined2 uVar17;
  int iVar18;
  byte *pbVar19;
  uint uVar20;
  undefined4 uVar21;
  uint uVar22;
  uint uVar23;
  int iVar24;
  undefined4 uVar25;
  byte local_b;
  byte local_a;
  
  iVar12 = param_1;
  iVar24 = 0;
  iVar18 = *(int *)(param_1 + 0x2dc);
  if (iVar18 == 0) {
    if (*(int *)(param_1 + 0x18c) == 0) {
      *(undefined4 *)(param_1 + 0x2dc) = 100000;
      *(undefined4 *)(param_1 + 0x18c) = 100000;
    }
    else {
      uVar25 = FUN_0066b1d0(*(int *)(param_1 + 0x18c));
      *(undefined4 *)(param_1 + 0x2dc) = uVar25;
    }
  }
  else if (*(int *)(param_1 + 0x18c) == 0) {
    uVar25 = FUN_0066b1d0(iVar18);
    *(undefined4 *)(param_1 + 0x18c) = uVar25;
  }
  else {
    iVar24 = FUN_0066dd10(iVar18,*(int *)(param_1 + 0x18c));
  }
  *(byte *)(param_1 + 0x326) = *(byte *)(param_1 + 0x326) | 1;
  if (iVar24 == 0) {
    uVar20 = *(uint *)(param_1 + 0x7c) & 0xffffdfff;
  }
  else {
    uVar20 = *(uint *)(param_1 + 0x7c) | 0x2000;
  }
  *(uint *)(param_1 + 0x7c) = uVar20;
  if (((uVar20 & 0x40000) != 0) && ((uVar20 & 0x80) == 0)) {
    *(undefined2 *)(param_1 + 0x150) = 0;
    *(uint *)(param_1 + 0x7c) = uVar20 & 0xfd7ffeff;
    *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) & 0xffffdfff;
  }
  iVar18 = FUN_0066b220(*(undefined4 *)(param_1 + 0x18c));
  if (iVar18 == 0) {
    *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) & 0xff7fffff;
    *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) & 0xffffdfff;
  }
  if ((*(uint *)(param_1 + 0x7c) & 0x600000) != 0) {
    FUN_0066abe0(param_1);
  }
  uVar20 = *(uint *)(param_1 + 0x7c);
  if ((uVar20 & 0x100) == 0) {
    if (((((uVar20 & 0x80) != 0) && ((uVar20 & 0x4000) != 0)) &&
        (sVar9 = *(short *)(param_1 + 0x16a), sVar9 == *(short *)(param_1 + 0x16c))) &&
       (sVar9 == *(short *)(param_1 + 0x16e))) {
      *(short *)(param_1 + 0x170) = sVar9;
      *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 0x800;
    }
  }
  else if ((*(byte *)(param_1 + 0x157) & 2) == 0) {
    *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 0x800;
  }
  if (*(char *)(param_1 + 0x157) == '\x03') {
    FUN_0066dd50();
  }
  else {
    FUN_0066de40(param_1);
  }
  uVar20 = *(uint *)(param_1 + 0x7c);
  if ((((uVar20 & 0x200) != 0) && ((uVar20 & 0x80) != 0)) &&
     (((uVar20 & 0x100) == 0 && (*(char *)(param_1 + 0x158) != '\x10')))) {
    *(short *)(param_1 + 0x16a) = (short)((*(ushort *)(param_1 + 0x16a) + 0x81) * 0xff >> 0x10);
    *(short *)(param_1 + 0x16c) = (short)((*(ushort *)(param_1 + 0x16c) + 0x81) * 0xff >> 0x10);
    *(short *)(param_1 + 0x16e) = (short)((*(ushort *)(param_1 + 0x16e) + 0x81) * 0xff >> 0x10);
    *(short *)(param_1 + 0x170) = (short)((*(ushort *)(param_1 + 0x170) + 0x81) * 0xff >> 0x10);
  }
  if ((((uVar20 & 0x4000400) != 0) && ((uVar20 & 0x80) != 0)) &&
     (((uVar20 & 0x100) == 0 && (*(char *)(param_1 + 0x158) == '\x10')))) {
    *(short *)(param_1 + 0x16a) = *(short *)(param_1 + 0x16a) * 0x101;
    *(short *)(param_1 + 0x16c) = *(short *)(param_1 + 0x16c) * 0x101;
    *(short *)(param_1 + 0x16e) = *(short *)(param_1 + 0x16e) * 0x101;
    *(short *)(param_1 + 0x170) = *(short *)(param_1 + 0x170) * 0x101;
  }
  *(undefined4 *)(param_1 + 0x172) = *(undefined4 *)(param_1 + 0x168);
  *(undefined4 *)(param_1 + 0x176) = *(undefined4 *)(param_1 + 0x16c);
  *(undefined2 *)(param_1 + 0x17a) = *(undefined2 *)(param_1 + 0x170);
  if (((((uVar20 & 0x2000) == 0) &&
       (((uVar20 & 0x600000) == 0 ||
        ((iVar18 = FUN_0066b220(*(undefined4 *)(param_1 + 0x2dc)), iVar18 == 0 &&
         (iVar18 = FUN_0066b220(*(undefined4 *)(param_1 + 0x18c)), iVar18 == 0)))))) &&
      (((*(byte *)(param_1 + 0x7c) & 0x80) == 0 ||
       (((iVar18 = FUN_0066b220(*(undefined4 *)(param_1 + 0x2dc)), iVar18 == 0 &&
         (iVar18 = FUN_0066b220(*(undefined4 *)(param_1 + 0x18c)), iVar18 == 0)) &&
        ((*(char *)(param_1 + 0x162) != '\x03' ||
         (iVar18 = FUN_0066b220(*(undefined4 *)(param_1 + 0x164)), iVar18 == 0)))))))) &&
     (((*(uint *)(param_1 + 0x7c) & 0x800000) == 0 ||
      (iVar18 = FUN_0066b220(*(undefined4 *)(param_1 + 0x18c)), iVar18 == 0)))) {
    if (((*(byte *)(param_1 + 0x7c) & 0x80) == 0) || (*(char *)(param_1 + 0x157) != '\x03'))
    goto LAB_0066dc2e;
    bVar15 = *(byte *)(param_1 + 0x16c);
    bVar16 = *(byte *)(param_1 + 0x16a);
    uVar8 = *(ushort *)(param_1 + 0x150);
    iVar18 = 0;
    bVar5 = *(byte *)(param_1 + 0x16e);
    if (uVar8 != 0) {
      pbVar19 = (byte *)(*(int *)(param_1 + 0x144) + 2);
      do {
        bVar6 = *(byte *)(*(int *)(param_1 + 0x1b4) + iVar18);
        if (bVar6 == 0) {
          *(ushort *)(pbVar19 + -2) = CONCAT11(bVar15,bVar16);
          *pbVar19 = bVar5;
        }
        else if (bVar6 != 0xff) {
          uVar20 = (0xff - (uint)bVar6) * (uint)bVar16 + 0x80 + (uint)pbVar19[-2] * (uint)bVar6 &
                   0xffff;
          pbVar19[-2] = (byte)((uVar20 >> 8) + uVar20 >> 8);
          uVar20 = (uint)*(byte *)(*(int *)(param_1 + 0x1b4) + iVar18);
          uVar20 = (0xff - uVar20) * (uint)bVar15 + 0x80 + pbVar19[-1] * uVar20 & 0xffff;
          pbVar19[-1] = (byte)((uVar20 >> 8) + uVar20 >> 8);
          uVar20 = (uint)*(byte *)(*(int *)(param_1 + 0x1b4) + iVar18);
          uVar20 = (0xff - uVar20) * (uint)bVar5 + 0x80 + *pbVar19 * uVar20 & 0xffff;
          *pbVar19 = (byte)((uVar20 >> 8) + uVar20 >> 8);
        }
        iVar18 = iVar18 + 1;
        pbVar19 = pbVar19 + 3;
      } while (iVar18 < (int)(uint)uVar8);
    }
    uVar20 = *(uint *)(param_1 + 0x7c) & 0xffffff7f;
  }
  else {
    FUN_0066b4e0(param_1,*(undefined1 *)(param_1 + 0x158));
    uVar20 = *(uint *)(param_1 + 0x7c);
    if ((uVar20 & 0x80) == 0) {
      if ((*(char *)(param_1 + 0x157) != '\x03') ||
         (((uVar20 & 0x1000) != 0 && ((uVar20 & 0x600000) != 0)))) goto LAB_0066dc2e;
      uVar20 = (uint)*(ushort *)(param_1 + 0x148);
      if (uVar20 != 0) {
        pbVar19 = (byte *)(*(int *)(param_1 + 0x144) + 2);
        do {
          pbVar19[-2] = *(byte *)((uint)pbVar19[-2] + *(int *)(param_1 + 400));
          pbVar19[-1] = *(byte *)((uint)pbVar19[-1] + *(int *)(param_1 + 400));
          uVar20 = uVar20 - 1;
          *pbVar19 = *(byte *)((uint)*pbVar19 + *(int *)(param_1 + 400));
          pbVar19 = pbVar19 + 3;
        } while (uVar20 != 0);
      }
      uVar20 = *(uint *)(param_1 + 0x7c) & 0xffffdfff;
    }
    else {
      if ((uVar20 & 0x600000) != 0) {
        FUN_006687b0(param_1,s_libpng_does_not_support_gamma_ba_00a0c6f8);
      }
      if (*(char *)(param_1 + 0x157) != '\x03') {
        uVar25 = 100000;
        cVar7 = *(char *)(param_1 + 0x162);
        uVar21 = 100000;
        if (cVar7 == '\x01') {
          uVar25 = *(undefined4 *)(param_1 + 0x18c);
        }
        else if (cVar7 == '\x02') {
          uVar25 = FUN_0066b1d0(*(undefined4 *)(param_1 + 0x2dc));
          uVar21 = FUN_0066b240(*(undefined4 *)(param_1 + 0x2dc),*(undefined4 *)(param_1 + 0x18c));
        }
        else if (cVar7 == '\x03') {
          uVar25 = FUN_0066b1d0(*(undefined4 *)(param_1 + 0x164));
          uVar21 = FUN_0066b240(*(undefined4 *)(param_1 + 0x164),*(undefined4 *)(param_1 + 0x18c));
        }
        else {
          FUN_00668620(param_1,s_invalid_background_gamma_type_00a0c6d8);
        }
        iVar18 = FUN_0066b220(uVar25);
        iVar24 = FUN_0066b220(uVar21);
        if (iVar18 != 0) {
          uVar17 = FUN_0066b350(param_1,*(undefined2 *)(param_1 + 0x170),uVar25);
          *(undefined2 *)(param_1 + 0x17a) = uVar17;
        }
        if (iVar24 != 0) {
          uVar17 = FUN_0066b350(param_1,*(undefined2 *)(param_1 + 0x170),uVar21);
          *(undefined2 *)(param_1 + 0x170) = uVar17;
        }
        sVar9 = *(short *)(param_1 + 0x16a);
        if (((sVar9 == *(short *)(param_1 + 0x16c)) && (sVar9 == *(short *)(param_1 + 0x16e))) &&
           (sVar10 = *(short *)(param_1 + 0x170), sVar9 == sVar10)) {
          uVar17 = *(undefined2 *)(param_1 + 0x17a);
          *(short *)(param_1 + 0x16e) = sVar10;
          *(undefined2 *)(param_1 + 0x178) = uVar17;
          *(undefined2 *)(param_1 + 0x176) = uVar17;
          *(undefined2 *)(param_1 + 0x174) = uVar17;
          *(short *)(param_1 + 0x16c) = sVar10;
          *(short *)(param_1 + 0x16a) = sVar10;
          *(undefined1 *)(param_1 + 0x162) = 1;
        }
        else {
          if (iVar18 != 0) {
            uVar17 = FUN_0066b350(param_1,sVar9,uVar25);
            *(undefined2 *)(param_1 + 0x174) = uVar17;
            uVar17 = FUN_0066b350(param_1,*(undefined2 *)(param_1 + 0x16c),uVar25);
            *(undefined2 *)(param_1 + 0x176) = uVar17;
            uVar17 = FUN_0066b350(param_1,*(undefined2 *)(param_1 + 0x16e),uVar25);
            *(undefined2 *)(param_1 + 0x178) = uVar17;
          }
          if (iVar24 != 0) {
            uVar17 = FUN_0066b350(param_1,*(undefined2 *)(param_1 + 0x16a),uVar21);
            *(undefined2 *)(param_1 + 0x16a) = uVar17;
            uVar17 = FUN_0066b350(param_1,*(undefined2 *)(param_1 + 0x16c),uVar21);
            *(undefined2 *)(param_1 + 0x16c) = uVar17;
            uVar17 = FUN_0066b350(param_1,*(undefined2 *)(param_1 + 0x16e),uVar21);
            *(undefined2 *)(param_1 + 0x16e) = uVar17;
          }
          *(undefined1 *)(param_1 + 0x162) = 1;
        }
        goto LAB_0066dc2e;
      }
      iVar18 = *(int *)(param_1 + 0x144);
      uVar8 = *(ushort *)(param_1 + 0x148);
      cVar7 = *(char *)(param_1 + 0x162);
      if (cVar7 == '\x02') {
        iVar24 = *(int *)(param_1 + 400);
        puVar1 = (ushort *)(param_1 + 0x16a);
        puVar2 = (ushort *)(param_1 + 0x16c);
        puVar3 = (ushort *)(param_1 + 0x16e);
        param_1._0_2_ =
             CONCAT11(*(undefined1 *)((uint)*puVar2 + iVar24),
                      *(undefined1 *)((uint)*puVar1 + iVar24));
        bVar15 = *(byte *)((uint)*puVar3 + iVar24);
        iVar24 = *(int *)(iVar12 + 0x19c);
        bVar16 = *(byte *)(iVar24 + (uint)*puVar1);
        local_b = *(byte *)(iVar24 + (uint)*puVar2);
        local_a = *(byte *)(iVar24 + (uint)*puVar3);
      }
      else {
        if (cVar7 == '\x01') {
          uVar25 = *(undefined4 *)(param_1 + 0x18c);
LAB_0066d775:
          uVar21 = 100000;
        }
        else if (cVar7 == '\x02') {
          uVar25 = FUN_0066b1d0(*(undefined4 *)(param_1 + 0x2dc));
          uVar21 = FUN_0066b240(*(undefined4 *)(param_1 + 0x2dc),*(undefined4 *)(param_1 + 0x18c));
        }
        else {
          if (cVar7 != '\x03') {
            uVar25 = 100000;
            goto LAB_0066d775;
          }
          uVar25 = FUN_0066b1d0(*(undefined4 *)(param_1 + 0x164));
          uVar21 = FUN_0066b240(*(undefined4 *)(param_1 + 0x164),*(undefined4 *)(param_1 + 0x18c));
        }
        iVar24 = FUN_0066b220(uVar21);
        if (iVar24 == 0) {
          bVar15 = *(byte *)(param_1 + 0x16e);
          param_1._0_2_ =
               CONCAT11(*(undefined1 *)(param_1 + 0x16c),*(undefined1 *)(param_1 + 0x16a));
        }
        else {
          uVar13 = FUN_0066b290(*(undefined2 *)(param_1 + 0x16a),uVar21);
          uVar14 = FUN_0066b290(*(undefined2 *)(param_1 + 0x16c),uVar21);
          puVar4 = (undefined2 *)(param_1 + 0x16e);
          param_1._0_2_ = CONCAT11(uVar14,uVar13);
          bVar15 = FUN_0066b290(*puVar4,uVar21);
        }
        iVar24 = FUN_0066b220(uVar25);
        if (iVar24 == 0) {
          local_b = *(byte *)(iVar12 + 0x16c);
          bVar16 = *(byte *)(iVar12 + 0x16a);
          local_a = *(byte *)(iVar12 + 0x16e);
        }
        else {
          bVar16 = FUN_0066b290(*(undefined2 *)(iVar12 + 0x16a),uVar25);
          local_b = FUN_0066b290(*(undefined2 *)(iVar12 + 0x16c),uVar25);
          local_a = FUN_0066b290(*(undefined2 *)(iVar12 + 0x16e),uVar25);
        }
      }
      iVar24 = 0;
      if (uVar8 != 0) {
        pbVar19 = (byte *)(iVar18 + 2);
        do {
          if ((iVar24 < (int)(uint)*(ushort *)(iVar12 + 0x150)) &&
             (bVar5 = *(byte *)(*(int *)(iVar12 + 0x1b4) + iVar24), bVar5 != 0xff)) {
            if (bVar5 == 0) {
              *(undefined2 *)(pbVar19 + -2) = (undefined2)param_1;
              *pbVar19 = bVar15;
            }
            else {
              uVar20 = (uint)*(byte *)((uint)pbVar19[-2] + *(int *)(iVar12 + 0x19c)) * (uint)bVar5 +
                       0x80 + (0xff - (uint)bVar5) * (uint)bVar16 & 0xffff;
              pbVar19[-2] = *(byte *)(((int)((uVar20 >> 8) + uVar20) >> 8 & 0xffU) +
                                     *(int *)(iVar12 + 0x198));
              uVar20 = (uint)*(byte *)(*(int *)(iVar12 + 0x1b4) + iVar24);
              uVar20 = *(byte *)((uint)pbVar19[-1] + *(int *)(iVar12 + 0x19c)) * uVar20 + 0x80 +
                       (0xff - uVar20) * (uint)local_b & 0xffff;
              pbVar19[-1] = *(byte *)(((int)((uVar20 >> 8) + uVar20) >> 8 & 0xffU) +
                                     *(int *)(iVar12 + 0x198));
              uVar20 = (uint)*(byte *)(*(int *)(iVar12 + 0x1b4) + iVar24);
              uVar20 = *(byte *)((uint)*pbVar19 + *(int *)(iVar12 + 0x19c)) * uVar20 + 0x80 +
                       (0xff - uVar20) * (uint)local_a & 0xffff;
              *pbVar19 = *(byte *)(((int)((uVar20 >> 8) + uVar20) >> 8 & 0xffU) +
                                  *(int *)(iVar12 + 0x198));
            }
          }
          else {
            pbVar19[-2] = *(byte *)((uint)pbVar19[-2] + *(int *)(iVar12 + 400));
            pbVar19[-1] = *(byte *)((uint)pbVar19[-1] + *(int *)(iVar12 + 400));
            *pbVar19 = *(byte *)((uint)*pbVar19 + *(int *)(iVar12 + 400));
          }
          iVar24 = iVar24 + 1;
          pbVar19 = pbVar19 + 3;
        } while (iVar24 < (int)(uint)uVar8);
      }
      uVar20 = *(uint *)(iVar12 + 0x7c) & 0xffffdf7f;
    }
  }
  *(uint *)(iVar12 + 0x7c) = uVar20;
LAB_0066dc2e:
  uVar20 = *(uint *)(iVar12 + 0x7c);
  if ((((uVar20 & 8) != 0) && ((uVar20 & 0x1000) == 0)) && (*(char *)(iVar12 + 0x157) == '\x03')) {
    uVar23 = (uint)*(ushort *)(iVar12 + 0x148);
    iVar18 = 8 - (uint)*(byte *)(iVar12 + 0x1a8);
    uVar20 = uVar20 & 0xfffffff7;
    *(uint *)(iVar12 + 0x7c) = uVar20;
    if (((0 < iVar18) && (iVar18 < 8)) && (uVar23 != 0)) {
      iVar24 = 0;
      uVar22 = uVar23;
      do {
        iVar11 = *(int *)(iVar12 + 0x144);
        pbVar19 = (byte *)(iVar11 + iVar24);
        *pbVar19 = *pbVar19 >> ((byte)iVar18 & 0x1f);
        uVar20 = iVar11 + iVar24;
        iVar24 = iVar24 + 3;
        uVar22 = uVar22 - 1;
      } while (uVar22 != 0);
    }
    iVar18 = 8 - (uint)*(byte *)(iVar12 + 0x1a9);
    if (((0 < iVar18) && (iVar18 < 8)) && (uVar23 != 0)) {
      iVar24 = 0;
      uVar22 = uVar23;
      do {
        iVar11 = *(int *)(iVar12 + 0x144);
        pbVar19 = (byte *)(iVar24 + 1 + iVar11);
        *pbVar19 = *pbVar19 >> ((byte)iVar18 & 0x1f);
        uVar20 = iVar24 + 1 + iVar11;
        iVar24 = iVar24 + 3;
        uVar22 = uVar22 - 1;
      } while (uVar22 != 0);
    }
    iVar18 = 8 - (uint)*(byte *)(iVar12 + 0x1aa);
    if (((0 < iVar18) && (iVar18 < 8)) && (uVar23 != 0)) {
      iVar24 = 0;
      do {
        iVar11 = *(int *)(iVar12 + 0x144);
        pbVar19 = (byte *)(iVar24 + 2 + iVar11);
        *pbVar19 = *pbVar19 >> ((byte)iVar18 & 0x1f);
        uVar20 = iVar24 + 2 + iVar11;
        iVar24 = iVar24 + 3;
        uVar23 = uVar23 - 1;
      } while (uVar23 != 0);
    }
  }
  return uVar20;
}

