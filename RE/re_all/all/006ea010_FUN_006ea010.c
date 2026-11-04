
void FUN_006ea010(int param_1,uint param_2,int *param_3,int param_4,int param_5)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  ushort uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  ushort uVar17;
  uint uVar18;
  byte *pbVar19;
  bool bVar20;
  undefined8 uVar21;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  uint local_74;
  int local_60;
  uint local_5c;
  int local_58;
  uint local_50;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  uint local_2c;
  byte *local_28;
  int local_24;
  byte *local_20;
  uint *local_1c;
  uint *local_18;
  uint local_14;
  uint *local_10;
  uint *local_c;
  int local_8;
  
  local_5c = 0;
  local_28 = (byte *)0x0;
  if (*(int *)(*(int *)(param_2 + 0x14) + 0x18) == 0) {
    param_4 = 0;
  }
  local_7c = param_3[2];
  iVar5 = *param_3;
  if (local_7c < iVar5) {
    local_2c = -1;
    local_84 = local_7c;
    local_7c = iVar5;
  }
  else {
    local_2c = 1;
    local_84 = iVar5;
  }
  iVar4 = local_84;
  iVar5 = param_3[1];
  iVar6 = param_3[3];
  if (iVar6 < iVar5) {
    local_60 = -1;
    local_78 = iVar5;
    iVar5 = iVar6;
  }
  else {
    local_60 = 1;
    local_78 = iVar6;
  }
  uVar2 = local_7c - local_84;
  iVar6 = local_78 - iVar5;
  if ((uVar2 != 0) && (iVar6 != 0)) {
    local_80 = iVar5;
    if ((uVar2 == *(uint *)(param_2 + 4)) &&
       (((iVar6 == *(int *)(param_2 + 8) && (local_2c == 1)) && (local_60 == 1)))) {
      FUN_006c8cc0(param_1,param_2,local_84,iVar5,param_4,param_5);
      return;
    }
    uVar3 = (uVar2 * 0x10000) / *(uint *)(param_2 + 4);
    local_38 = (uint)(iVar6 * 0x10000) / *(uint *)(param_2 + 8);
    local_34 = uVar3;
    FUN_00514e10(&local_84,&DAT_00dca3e4);
    uVar2 = local_2c;
    iVar6 = (local_84 - iVar4) * 0x10000;
    iVar4 = iVar6 / (int)uVar3;
    local_74 = iVar6 % (int)uVar3;
    local_44 = local_7c - local_84;
    local_24 = local_78 - local_80;
    iVar6 = (local_80 - iVar5) * 0x10000;
    iVar5 = iVar6 / (int)local_38;
    local_40 = uVar3 - local_74;
    local_14 = local_38 - iVar6 % (int)local_38;
    if ((local_44 != 0) && (local_24 != 0)) {
      iVar6 = *(int *)(param_2 + 0x14);
      local_58 = local_2c;
      uVar3 = (uint)*(byte *)(*(int *)(iVar6 + 0x14) + 4);
      if (local_2c == 1) {
        local_2c = uVar3;
        iVar13 = iVar4;
      }
      else {
        local_74 = uVar3;
        local_2c = ~uVar3 + 1;
        iVar13 = (*(int *)(param_2 + 4) - iVar4) + -1;
      }
      if (local_60 == 1) {
        local_3c = *(int *)(iVar6 + 0xc);
        iVar12 = iVar5;
      }
      else {
        local_3c = ~*(uint *)(iVar6 + 0xc) + 1;
        iVar12 = (*(int *)(param_2 + 8) - iVar5) + -1;
      }
      local_10 = (uint *)(*(int *)(param_2 + 0xc) + iVar13 * uVar3 + iVar12 * *(uint *)(iVar6 + 0xc)
                         );
      if (param_5 != 0) {
        if (uVar2 == 1) {
          local_58 = 1;
          local_28 = (byte *)(*(int *)(param_5 + 0xc) + iVar4);
        }
        else {
          local_28 = (byte *)(*(int *)(param_5 + 0xc) + -1 + (*(int *)(param_2 + 4) - iVar4));
          local_58 = -1;
        }
        uVar2 = *(uint *)(*(int *)(param_5 + 0x14) + 0xc);
        local_5c = uVar2;
        if (local_60 != 1) {
          iVar5 = (*(int *)(param_2 + 8) - iVar5) + -1;
          local_5c = ~uVar2 + 1;
        }
        local_28 = (byte *)((int)local_28 + iVar5 * uVar2);
      }
      local_48 = *(int *)(*(int *)(param_1 + 0x14) + 0xc);
      uVar2 = (uint)*(byte *)(*(int *)(*(int *)(param_1 + 0x14) + 0x14) + 4);
      local_50 = *(uint *)(iVar6 + 0x1c);
      local_1c = (uint *)(local_48 * local_80 + uVar2 * local_84 + *(int *)(param_1 + 0xc));
      iVar5 = local_48 - uVar2 * local_44;
      if (*(int *)(iVar6 + 0x24) == 1) {
        FUN_0056d420(&DAT_00f400d8,*(undefined4 *)(iVar6 + 0x3c),
                     ((uint)(*(int *)(iVar6 + 0x20) != 0) * 2 + 2) * *(int *)(iVar6 + 0x28));
      }
      iVar4 = DAT_00dca3f8;
      uVar2 = *(uint *)(*(int *)(param_2 + 0x14) + 0x1c);
      iVar6 = *(int *)(*(int *)(param_2 + 0x14) + 0x3c);
      uVar18 = DAT_00dca3fc >> 0x10 & 0xff;
      uVar3 = DAT_00dca3fc >> 8 & 0xff;
      uVar11 = DAT_00dca3fc & 0xff;
      param_2 = *(uint *)(param_2 + 0x14);
      if (*(int *)(param_2 + 0x20) == 0) {
        if (*(int *)(param_2 + 0x24) == 1) {
          switch(DAT_00dca3f4) {
          case 0:
switchD_006f83a4_caseD_0:
            if (param_5 == 0) {
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                local_18 = local_1c;
                if (param_4 == 0) {
                  do {
                    puVar7 = local_18;
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    while( true ) {
                      uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                      *(ushort *)local_18 =
                           (*(short *)(&DAT_00d0a2e0 + uVar18 * 0x100 + (uint)(uVar17 >> 0xb)) << 6
                           | *(ushort *)(&DAT_00d0a2e0 + uVar3 * 0x100 + (uVar17 >> 5 & 0x3f))) << 5
                           | *(ushort *)(&DAT_00d0a2e0 + uVar11 * 0x100 + (uVar17 & 0x1f));
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_18 = (uint *)((int)puVar7 + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006f8aa5:
                puVar7 = local_18;
                local_c = local_10;
                local_8 = local_44;
                param_3 = (int *)local_40;
                do {
                  if ((byte)*local_c == uVar2) {
                    do {
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f8b45;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                      *(ushort *)local_18 =
                           (*(short *)(&DAT_00d0a2e0 + uVar18 * 0x100 + (uint)(uVar17 >> 0xb)) << 6
                           | *(ushort *)(&DAT_00d0a2e0 + uVar3 * 0x100 + (uVar17 >> 5 & 0x3f))) << 5
                           | *(ushort *)(&DAT_00d0a2e0 + uVar11 * 0x100 + (uVar17 & 0x1f));
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f8b45;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (param_4 == 0) {
                do {
                  iVar4 = local_44;
                  iVar13 = local_40;
                  puVar7 = local_10;
LAB_006f8a40:
                  uVar17 = *(ushort *)(iVar6 + (uint)(byte)*puVar7 * 2);
                  iVar12 = iVar13;
                  while( true ) {
                    *(ushort *)local_1c = uVar17;
                    local_1c = (uint *)((int)local_1c + 2);
                    iVar4 = iVar4 + -1;
                    if (iVar4 == 0) break;
                    iVar13 = iVar12 + -0x10000;
                    bVar20 = iVar12 < 0x10000;
                    iVar12 = iVar13;
                    if (iVar13 == 0 || bVar20) goto LAB_006f8a58;
                  }
                  local_1c = (uint *)((int)local_1c + iVar5);
                  bVar20 = local_14 < 0x10000;
                  local_14 = local_14 - 0x10000;
                  if (bVar20 || local_14 == 0) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      bVar20 = SCARRY4(local_14,local_38);
                      local_14 = local_14 + local_38;
                    } while (bVar20 != (int)local_14 < 0);
                  }
                  local_24 = local_24 + -1;
                  if (local_24 == 0) {
                    return;
                  }
                } while( true );
              }
LAB_006f89c7:
              iVar4 = local_44;
              iVar13 = local_40;
              puVar7 = local_10;
              do {
                iVar12 = iVar13;
                if ((byte)*puVar7 == local_50) {
                  do {
                    local_1c = (uint *)((int)local_1c + 2);
                    iVar4 = iVar4 + -1;
                    if (iVar4 == 0) goto LAB_006f8a04;
                    iVar13 = iVar12 + -0x10000;
                    bVar20 = 0xffff < iVar12;
                    iVar12 = iVar13;
                  } while (iVar13 != 0 && bVar20);
                }
                else {
                  uVar17 = *(ushort *)(iVar6 + (uint)(byte)*puVar7 * 2);
                  do {
                    *(ushort *)local_1c = uVar17;
                    local_1c = (uint *)((int)local_1c + 2);
                    iVar4 = iVar4 + -1;
                    if (iVar4 == 0) goto LAB_006f8a04;
                    iVar13 = iVar12 + -0x10000;
                    bVar20 = 0xffff < iVar12;
                    iVar12 = iVar13;
                  } while (iVar13 != 0 && bVar20);
                }
                do {
                  puVar7 = (uint *)((int)puVar7 + local_2c);
                  bVar20 = SCARRY4(iVar13,local_34);
                  iVar13 = iVar13 + local_34;
                } while (bVar20 != iVar13 < 0);
              } while( true );
            }
            if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
              if (param_4 == 0) {
                do {
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_20 = local_28;
                  local_18 = local_1c;
                  local_c = local_10;
                  while( true ) {
                    uVar17 = (ushort)*local_18;
                    uVar10 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    bVar1 = (&DAT_00dca2e0)[*local_20];
                    uVar2 = uVar17 & 0x1f;
                    *(ushort *)local_18 =
                         (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                  (uVar17 >> 5 & 0x3f)) * (uint)bVar1 + (uVar17 & 0xffffffe0) * 8 >>
                                 3) & 0x7e0 |
                         ((*(short *)(&DAT_00d0a2e0 + uVar18 * 0x100 + (uint)(uVar10 >> 0xb)) -
                          (uVar17 >> 0xb)) * (ushort)bVar1 + (uVar17 >> 3 & 0x1f00)) * 8 & 0xf800 |
                         (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] - uVar2) *
                                  (uint)bVar1 + uVar2 * 0x100 >> 8);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_c = (uint *)((int)local_c + local_2c);
                      local_20 = local_20 + local_58;
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  for (local_14 = local_14 - 0x10000; (int)local_14 < 1;
                      local_14 = local_14 + local_38) {
                    local_10 = (uint *)((int)local_10 + local_3c);
                    local_28 = local_28 + local_5c;
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006f86a6:
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              local_20 = local_28;
              local_18 = local_1c;
              local_c = local_10;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f87ee;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar17 = (ushort)*puVar7;
                    uVar10 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    bVar1 = (&DAT_00dca2e0)[*local_20];
                    uVar8 = uVar17 & 0x1f;
                    *(ushort *)local_18 =
                         (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                  (uVar17 >> 5 & 0x3f)) * (uint)bVar1 + (uVar17 & 0xffffffe0) * 8 >>
                                 3) & 0x7e0 |
                         ((*(short *)(&DAT_00d0a2e0 + uVar18 * 0x100 + (uint)(uVar10 >> 0xb)) -
                          (uVar17 >> 0xb)) * (ushort)bVar1 + (uVar17 >> 3 & 0x1f00)) * 8 & 0xf800 |
                         (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] - uVar8) *
                                  (uint)bVar1 + uVar8 * 0x100 >> 8);
                    puVar7 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f87ee;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                do {
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                  param_3 = (int *)((int)param_3 + local_34);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if (param_4 == 0) {
              do {
                local_c = local_10;
                local_20 = local_28;
                local_8 = local_44;
                param_3 = (int *)local_40;
                local_18 = local_1c;
                while( true ) {
                  uVar11 = (uint)(ushort)*local_18;
                  uVar18 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                  uVar2 = (uint)*(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                  uVar3 = uVar11 << 8;
                  *(ushort *)local_18 =
                       (ushort)(((uVar2 & 0xf800) - (uVar11 & 0xf800)) * uVar18 +
                                (uVar3 & 0xfff80000) >> 8) & 0xf800 |
                       (ushort)(((uVar2 & 0x7e0) - (uVar11 & 0x7e0)) * uVar18 + (uVar3 & 0xffffe000)
                               >> 8) & 0x7e0 |
                       (ushort)(((uVar2 & 0x1f) - (uVar11 & 0x1f)) * uVar18 + (uVar3 & 0x1f00) >> 8)
                  ;
                  local_18 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) break;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  if ((int)param_3 < 1) {
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      local_c = (uint *)((int)local_c + local_2c);
                      local_20 = local_20 + local_58;
                    } while ((int)param_3 < 1);
                  }
                }
                local_1c = (uint *)((int)local_1c + local_48);
                local_14 = local_14 - 0x10000;
                if ((int)local_14 < 1) {
                  do {
                    local_14 = local_14 + local_38;
                    local_10 = (uint *)((int)local_10 + local_3c);
                    local_28 = local_28 + local_5c;
                  } while ((int)local_14 < 1);
                }
                local_24 = local_24 + -1;
              } while (local_24 != 0);
              return;
            }
LAB_006f83f1:
            local_c = local_10;
            local_20 = local_28;
            local_8 = local_44;
            puVar7 = local_1c;
            param_3 = (int *)local_40;
            local_18 = local_1c;
            do {
              if ((byte)*local_c == uVar2) {
                do {
                  puVar7 = (uint *)((int)puVar7 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006f84fe;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  local_18 = puVar7;
                } while (0 < (int)param_3);
              }
              else {
                do {
                  uVar18 = (uint)(ushort)*puVar7;
                  uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                  uVar3 = (uint)*(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                  uVar11 = uVar18 << 8;
                  *(ushort *)local_18 =
                       (ushort)(((uVar3 & 0xf800) - (uVar18 & 0xf800)) * uVar8 +
                                (uVar11 & 0xfff80000) >> 8) & 0xf800 |
                       (ushort)(((uVar3 & 0x7e0) - (uVar18 & 0x7e0)) * uVar8 + (uVar11 & 0xffffe000)
                               >> 8) & 0x7e0 |
                       (ushort)(((uVar3 & 0x1f) - (uVar18 & 0x1f)) * uVar8 + (uVar11 & 0x1f00) >> 8)
                  ;
                  puVar7 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006f84fe;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  local_18 = puVar7;
                } while (0 < (int)param_3);
              }
              do {
                param_3 = (int *)((int)param_3 + local_34);
                local_c = (uint *)((int)local_c + local_2c);
                local_20 = local_20 + local_58;
              } while ((int)param_3 < 1);
            } while( true );
          case 1:
            if (DAT_00dca3f8 == 0xff) goto switchD_006f83a4_caseD_0;
            if (DAT_00dca3f8 != 0) {
              if (param_5 != 0) {
                if ((DAT_00dca3fc & 0xffffff) == 0xffffff) {
                  local_20 = local_28;
                  iVar5 = DAT_00dca3f8;
                  if (param_4 == 0) {
                    do {
                      local_20 = local_28;
                      local_c = local_10;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      local_18 = local_1c;
                      while( true ) {
                        uVar11 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                        uVar3 = (uint)(ushort)*local_18;
                        uVar2 = (uint)*(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                        *(ushort *)local_18 =
                             (ushort)(((uVar2 & 0x7e0) - (uVar3 & 0x7e0)) * uVar11 * DAT_00dca3f8 +
                                      (uVar3 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                             (ushort)(((uVar2 & 0xf800) - (uVar3 & 0xf800)) * uVar11 * DAT_00dca3f8
                                      + (uVar3 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                             (ushort)(((uVar2 & 0x1f) - (uVar3 & 0x1f)) * uVar11 * DAT_00dca3f8 +
                                      (uVar3 & 0x1f) * 0x10000 >> 0x10);
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        if ((int)param_3 < 1) {
                          do {
                            local_c = (uint *)((int)local_c + local_2c);
                            local_20 = local_20 + local_58;
                            param_3 = (int *)((int)param_3 + local_34);
                          } while ((int)param_3 < 1);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_14 = local_14 + local_38;
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_28 = local_28 + local_5c;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_006f8c92:
                  local_28 = local_20;
                  local_c = local_10;
                  local_8 = local_44;
                  puVar7 = local_1c;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                  do {
                    if ((byte)*local_c == uVar2) {
                      do {
                        puVar7 = (uint *)((int)puVar7 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f8dc3;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        uVar11 = (uint)(ushort)*puVar7;
                        uVar18 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                        uVar3 = (uint)*(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                        *(ushort *)local_18 =
                             (ushort)(((uVar3 & 0x7e0) - (uVar11 & 0x7e0)) * uVar18 * iVar5 +
                                      (uVar11 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                             (ushort)(((uVar3 & 0xf800) - (uVar11 & 0xf800)) * uVar18 * iVar5 +
                                      (uVar11 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                             (ushort)(((uVar3 & 0x1f) - (uVar11 & 0x1f)) * uVar18 * iVar5 +
                                      (uVar11 & 0x1f) * 0x10000 >> 0x10);
                        puVar7 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        iVar5 = DAT_00dca3f8;
                        if (local_8 == 0) goto LAB_006f8dc3;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    do {
                      local_20 = local_20 + local_58;
                      param_3 = (int *)((int)param_3 + local_34);
                      local_c = (uint *)((int)local_c + local_2c);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                local_18 = local_1c;
                iVar5 = DAT_00dca3f8;
                if (param_4 == 0) {
                  local_c = local_10;
                  local_20 = local_28;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  while( true ) {
                    while( true ) {
                      uVar17 = (ushort)*local_18;
                      uVar2 = (uint)uVar17;
                      uVar10 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                      uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      *(ushort *)local_18 =
                           (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                    (uVar17 >> 5 & 0x3f)) * uVar8 * DAT_00dca3f8 +
                                    (uVar2 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                           (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                    (uint)(uVar17 >> 0xb)) * uVar8 * DAT_00dca3f8 +
                                    (uVar2 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                           (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                    (uVar2 & 0x1f)) * uVar8 * DAT_00dca3f8 + uVar2 * 0x10000 >> 0x10
                                   ) & 0x1f;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                          local_20 = local_20 + local_58;
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_20 = local_28;
                    local_18 = local_1c;
                    local_c = local_10;
                  }
                  return;
                }
LAB_006f8f90:
                puVar7 = local_18;
                local_8 = local_44;
                param_3 = (int *)local_40;
                local_20 = local_28;
                local_c = local_10;
                do {
                  if ((byte)*local_c == uVar2) {
                    do {
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f90da;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar17 = (ushort)*local_18;
                      uVar8 = (uint)uVar17;
                      uVar10 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                      uVar14 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      *(ushort *)local_18 =
                           (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                    (uVar17 >> 5 & 0x3f)) * uVar14 * iVar5 +
                                    (uVar8 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                           (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                    (uint)(uVar17 >> 0xb)) * uVar14 * iVar5 +
                                    (uVar8 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                           (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                    (uVar8 & 0x1f)) * uVar14 * iVar5 + uVar8 * 0x10000 >> 0x10) &
                           0x1f;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      iVar5 = DAT_00dca3f8;
                      if (local_8 == 0) goto LAB_006f90da;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_c = (uint *)((int)local_c + local_2c);
                    local_20 = local_20 + local_58;
                    param_3 = (int *)((int)param_3 + local_34);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                local_c = local_10;
                if (param_4 == 0) {
                  do {
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_18 = local_1c;
                    while( true ) {
                      uVar17 = (ushort)*local_18;
                      uVar10 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                      *(ushort *)local_18 =
                           ((uVar17 >> 5 & 0x3f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                     (uVar17 >> 5 & 0x3f)) * 4 + iVar4 * 0x800)) * 0x20 |
                           ((uVar17 >> 0xb) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                     (uint)(uVar17 >> 0xb)) * 4 + iVar4 * 0x800)) * 0x800 |
                           (uVar17 & 0x1f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                     (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006f9546:
                local_10 = local_c;
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                local_18 = local_1c;
                do {
                  if ((byte)*local_c == uVar2) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f9648;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar17 = (ushort)*puVar7;
                      uVar10 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                      *(ushort *)local_18 =
                           ((uVar17 >> 5 & 0x3f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                     (uVar17 >> 5 & 0x3f)) * 4 + iVar4 * 0x800)) * 0x20 |
                           ((uVar17 >> 0xb) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                     (uint)(uVar17 >> 0xb)) * 4 + iVar4 * 0x800)) * 0x800 |
                           (uVar17 & 0x1f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                     (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f9648;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_c = (uint *)((int)local_c + local_2c);
                    param_3 = (int *)((int)param_3 + local_34);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (param_4 == 0) {
                do {
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                  while( true ) {
                    uVar17 = (ushort)*local_18;
                    uVar10 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    *(ushort *)local_18 =
                         ((uVar17 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar10 >> 5 & 0x3f) - (uVar17 >> 5 & 0x3f)) * 4 + iVar4 * 0x800
                                   )) * 0x20 |
                         ((uVar17 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uint)(uVar10 >> 0xb) - (uint)(uVar17 >> 0xb)) * 4 +
                                   iVar4 * 0x800)) * 0x800 |
                         (uVar17 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar10 & 0x1f) - (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_14 = local_14 + local_38;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006f9300:
              local_c = local_10;
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              local_18 = local_1c;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f93e2;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    uVar10 = (ushort)*puVar7;
                    *(ushort *)local_18 =
                         ((uVar10 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar17 >> 5 & 0x3f) - (uVar10 >> 5 & 0x3f)) * 4 + iVar4 * 0x800
                                   )) * 0x20 |
                         ((uVar10 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uint)(uVar17 >> 0xb) - (uint)(uVar10 >> 0xb)) * 4 +
                                   iVar4 * 0x800)) * 0x800 |
                         (uVar10 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar17 & 0x1f) - (uVar10 & 0x1f)) * 4 + iVar4 * 0x800);
                    puVar7 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f93e2;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                } while ((int)param_3 < 1);
              } while( true );
            }
            break;
          case 2:
            if (DAT_00dca3f8 != 0) {
              if (param_5 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  local_18 = local_1c;
                  if (param_4 == 0) {
                    do {
                      puVar7 = local_18;
                      local_c = local_10;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      while( true ) {
                        uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                        uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                            iVar4 * 0x100 +
                                            (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)])
                                  * 0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar4 * 0x100 +
                                                     (&DAT_00d0a2e0)
                                                     [uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)])) * 0x20
                                 + *(short *)(&DAT_00d0a2e0 +
                                             iVar4 * 0x100 +
                                             (&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)]);
                        uVar2 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                        uVar8 = uVar2 & 0x8210820;
                        *(ushort *)local_18 =
                             (short)uVar8 - (short)(uVar8 >> 5) |
                             (uVar17 | (ushort)*local_18) & 0x820 | (ushort)uVar2;
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                            param_3 = (int *)((int)param_3 + local_34)) {
                          local_c = (uint *)((int)local_c + local_2c);
                        }
                      }
                      local_18 = (uint *)((int)puVar7 + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_14 = local_14 + local_38;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_006f9fd2:
                  puVar7 = local_18;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_c = local_10;
                  do {
                    if ((byte)*local_c == uVar2) {
                      do {
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006fa0d8;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                        uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                            iVar4 * 0x100 +
                                            (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)])
                                  * 0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar4 * 0x100 +
                                                     (&DAT_00d0a2e0)
                                                     [uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)])) * 0x20
                                 + *(short *)(&DAT_00d0a2e0 +
                                             iVar4 * 0x100 +
                                             (&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)]);
                        uVar8 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                        uVar14 = uVar8 & 0x8210820;
                        *(ushort *)local_18 =
                             (short)uVar14 - (short)(uVar14 >> 5) |
                             (uVar17 | (ushort)*local_18) & 0x820 | (ushort)uVar8;
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006fa0d8;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    do {
                      local_c = (uint *)((int)local_c + local_2c);
                      param_3 = (int *)((int)param_3 + local_34);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                if (param_4 == 0) {
                  do {
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_18 = local_1c;
                    while( true ) {
                      uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                      uVar17 = (*(short *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)(uVar17 >> 0xb)) *
                                0x40 + *(short *)(&DAT_00d0a2e0 +
                                                 iVar4 * 0x100 + (uVar17 >> 5 & 0x3f))) * 0x20 +
                               *(short *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uVar17 & 0x1f));
                      uVar3 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                      uVar2 = uVar3 & 0x8210820;
                      *(ushort *)local_18 =
                           (short)uVar2 - (short)(uVar2 >> 5) | (uVar17 | (ushort)*local_18) & 0x820
                           | (ushort)uVar3;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006f9da7:
                local_c = local_10;
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                local_18 = local_1c;
                do {
                  if ((byte)*local_c == uVar2) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f9e78;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                      uVar17 = (*(short *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)(uVar17 >> 0xb)) *
                                0x40 + *(short *)(&DAT_00d0a2e0 +
                                                 iVar4 * 0x100 + (uVar17 >> 5 & 0x3f))) * 0x20 +
                               *(short *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uVar17 & 0x1f));
                      uVar11 = ((ushort)*puVar7 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                      uVar3 = uVar11 & 0x8210820;
                      *(ushort *)local_18 =
                           (short)uVar3 - (short)(uVar3 >> 5) | (uVar17 | (ushort)*local_18) & 0x820
                           | (ushort)uVar11;
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f9e78;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                local_18 = local_1c;
                local_c = local_10;
                if (param_4 == 0) {
                  local_20 = local_28;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  while( true ) {
                    while( true ) {
                      uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                      uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                          iVar4 * 0x100 +
                                          ((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] *
                                           uVar2 >> 8)) * 0x40 +
                               *(short *)(&DAT_00d0a2e0 +
                                         iVar4 * 0x100 +
                                         ((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] *
                                          uVar2 >> 8))) * 0x20 +
                               *(short *)(&DAT_00d0a2e0 +
                                         iVar4 * 0x100 +
                                         ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] * uVar2
                                         >> 8));
                      uVar2 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                      uVar8 = uVar2 & 0x8210820;
                      *(ushort *)local_18 =
                           (short)uVar8 - (short)(uVar8 >> 5) | (uVar17 | (ushort)*local_18) & 0x820
                           | (ushort)uVar2;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_20 = local_20 + local_58;
                        local_c = (uint *)((int)local_c + local_2c);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    local_c = local_10;
                    local_20 = local_28;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_18 = local_1c;
                  }
                  return;
                }
LAB_006f9aa0:
                puVar7 = local_18;
                local_8 = local_44;
                param_3 = (int *)local_40;
                local_20 = local_28;
                local_c = local_10;
                do {
                  if ((byte)*local_c == uVar2) {
                    do {
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f9bc4;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                      uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                          iVar4 * 0x100 +
                                          ((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] *
                                           uVar8 >> 8)) * 0x40 +
                               *(short *)(&DAT_00d0a2e0 +
                                         iVar4 * 0x100 +
                                         ((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] *
                                          uVar8 >> 8))) * 0x20 +
                               *(short *)(&DAT_00d0a2e0 +
                                         iVar4 * 0x100 +
                                         ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] * uVar8
                                         >> 8));
                      uVar8 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                      uVar14 = uVar8 & 0x8210820;
                      *(ushort *)local_18 =
                           (short)uVar14 - (short)(uVar14 >> 5) |
                           (uVar17 | (ushort)*local_18) & 0x820 | (ushort)uVar8;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f9bc4;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_c = (uint *)((int)local_c + local_2c);
                    local_20 = local_20 + local_58;
                    param_3 = (int *)((int)param_3 + local_34);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              local_18 = local_1c;
              if (param_4 == 0) {
                do {
                  puVar7 = local_18;
                  local_20 = local_28;
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  while( true ) {
                    uVar2 = (uint)*(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                        iVar4 * 0x100 + ((uVar2 & 0xf800) * uVar3 >> 0x13)) * 0x40 +
                             *(short *)(&DAT_00d0a2e0 +
                                       iVar4 * 0x100 + ((uVar2 & 0x7e0) * uVar3 >> 0xd))) * 0x20 +
                             *(short *)(&DAT_00d0a2e0 +
                                       iVar4 * 0x100 + ((uVar2 & 0x1f) * uVar3 >> 8));
                    uVar3 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                    uVar2 = uVar3 & 0x8210820;
                    *(ushort *)local_18 =
                         (short)uVar2 - (short)(uVar2 >> 5) | (uVar17 | (ushort)*local_18) & 0x820 |
                         (ushort)uVar3;
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                        local_20 = local_20 + local_58;
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_18 = (uint *)((int)puVar7 + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006f97f0:
              puVar7 = local_18;
              local_20 = local_28;
              local_c = local_10;
              local_8 = local_44;
              param_3 = (int *)local_40;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f98ed;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar3 = (uint)*(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    uVar11 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                        iVar4 * 0x100 + ((uVar3 & 0xf800) * uVar11 >> 0x13)) * 0x40
                             + *(short *)(&DAT_00d0a2e0 +
                                         iVar4 * 0x100 + ((uVar3 & 0x7e0) * uVar11 >> 0xd))) * 0x20
                             + *(short *)(&DAT_00d0a2e0 +
                                         iVar4 * 0x100 + ((uVar3 & 0x1f) * uVar11 >> 8));
                    uVar11 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                    uVar3 = uVar11 & 0x8210820;
                    *(ushort *)local_18 =
                         (short)uVar3 - (short)(uVar3 >> 5) | (uVar17 | (ushort)*local_18) & 0x820 |
                         (ushort)uVar11;
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f98ed;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                } while ((int)param_3 < 1);
              } while( true );
            }
            break;
          case 3:
            if (param_5 == 0) {
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                local_18 = local_1c;
                if (param_4 == 0) {
                  do {
                    puVar7 = local_18;
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    while( true ) {
                      uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                      uVar8 = ((ushort)*local_18 | 0x8210820) -
                              ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                   iVar4 * 0x100 +
                                                   (&DAT_00d0a2e0)
                                                   [uVar18 * 0x100 + (uint)(uVar17 >> 0xb)]) * 0x40
                                        + *(short *)(&DAT_00d0a2e0 +
                                                    iVar4 * 0x100 +
                                                    (&DAT_00d0a2e0)
                                                    [uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)])) * 0x20
                                       + *(short *)(&DAT_00d0a2e0 +
                                                   iVar4 * 0x100 +
                                                   (&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)]
                                                   )) & 0xf7def7df);
                      uVar2 = uVar8 & 0x8210820;
                      *(ushort *)local_18 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar8;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                      }
                    }
                    local_18 = (uint *)((int)puVar7 + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006fab10:
                puVar7 = local_18;
                local_8 = local_44;
                param_3 = (int *)local_40;
                local_c = local_10;
                do {
                  if ((byte)*local_c == uVar2) {
                    do {
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006fabef;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                      uVar14 = ((ushort)*local_18 | 0x8210820) -
                               ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                    iVar4 * 0x100 +
                                                    (&DAT_00d0a2e0)
                                                    [uVar18 * 0x100 + (uint)(uVar17 >> 0xb)]) * 0x40
                                         + *(short *)(&DAT_00d0a2e0 +
                                                     iVar4 * 0x100 +
                                                     (&DAT_00d0a2e0)
                                                     [uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)])) * 0x20
                                        + *(short *)(&DAT_00d0a2e0 +
                                                    iVar4 * 0x100 +
                                                    (&DAT_00d0a2e0)
                                                    [uVar11 * 0x100 + (uVar17 & 0x1f)])) &
                               0xf7def7df);
                      uVar8 = uVar14 & 0x8210820;
                      *(ushort *)local_18 = (short)uVar8 - (short)(uVar8 >> 5) & (ushort)uVar14;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006fabef;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_c = (uint *)((int)local_c + local_2c);
                    param_3 = (int *)((int)param_3 + local_34);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (param_4 == 0) {
                if (DAT_00dca3f8 == 0xff) {
                  uVar2 = 0xffffff;
                  do {
                    local_8 = local_44;
                    iVar6 = local_40;
                    puVar7 = local_10;
                    while( true ) {
                      uVar2 = (CONCAT22((short)(uVar2 >> 0x10),(ushort)*local_1c) | 0x8210820) -
                              (*(uint *)(&DAT_00f400d8 + (uint)(byte)*puVar7 * 2) & 0xf7def7df);
                      uVar3 = uVar2 & 0x8210820;
                      uVar2 = uVar2 & uVar3 - (uVar3 >> 5);
                      *(ushort *)local_1c = (ushort)uVar2;
                      local_1c = (uint *)((int)local_1c + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      iVar4 = iVar6 + -0x10000;
                      bVar20 = iVar6 < 0x10000;
                      iVar6 = iVar4;
                      if (iVar4 == 0 || bVar20) {
                        do {
                          puVar7 = (uint *)((int)puVar7 + local_2c);
                          bVar20 = SCARRY4(iVar4,local_34);
                          iVar4 = iVar4 + local_34;
                          iVar6 = iVar4;
                        } while (bVar20 != iVar4 < 0);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + iVar5);
                    bVar20 = local_14 < 0x10000;
                    local_14 = local_14 - 0x10000;
                    if (bVar20 || local_14 == 0) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        bVar20 = SCARRY4(local_14,local_38);
                        local_14 = local_14 + local_38;
                      } while (bVar20 != (int)local_14 < 0);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
                do {
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
LAB_006faa2a:
                  puVar9 = puVar7;
                  while( true ) {
                    uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    puVar7 = (uint *)((int)puVar9 + 2);
                    uVar3 = ((ushort)*puVar9 | 0x8210820) -
                            ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                 iVar4 * 0x100 + (uint)(uVar17 >> 0xb)) * 0x40 +
                                      *(short *)(&DAT_00d0a2e0 +
                                                iVar4 * 0x100 + (uVar17 >> 5 & 0x3f))) * 0x20 +
                                     *(short *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uVar17 & 0x1f))) &
                            0xf7def7df);
                    uVar2 = uVar3 & 0x8210820;
                    *(ushort *)puVar9 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar3;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    puVar9 = puVar7;
                    if ((int)param_3 < 1) goto LAB_006faaa2;
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_14 = local_14 + local_38;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                  if (local_24 == 0) {
                    return;
                  }
                } while( true );
              }
              if (DAT_00dca3f8 == 0xff) {
                uVar2 = 0xffffff;
                do {
                  local_8 = local_44;
                  iVar6 = local_40;
                  puVar7 = local_10;
                  while( true ) {
                    if ((byte)*puVar7 != local_50) {
                      uVar2 = (CONCAT22((short)(uVar2 >> 0x10),(ushort)*local_1c) | 0x8210820) -
                              (*(uint *)(&DAT_00f400d8 + (uint)(byte)*puVar7 * 2) & 0xf7def7df);
                      uVar3 = uVar2 & 0x8210820;
                      uVar2 = uVar2 & uVar3 - (uVar3 >> 5);
                      *(ushort *)local_1c = (ushort)uVar2;
                    }
                    local_1c = (uint *)((int)local_1c + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    iVar4 = iVar6 + -0x10000;
                    bVar20 = iVar6 < 0x10000;
                    iVar6 = iVar4;
                    if (iVar4 == 0 || bVar20) {
                      do {
                        puVar7 = (uint *)((int)puVar7 + local_2c);
                        bVar20 = SCARRY4(iVar4,local_34);
                        iVar4 = iVar4 + local_34;
                        iVar6 = iVar4;
                      } while (bVar20 != iVar4 < 0);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + iVar5);
                  bVar20 = local_14 < 0x10000;
                  local_14 = local_14 - 0x10000;
                  if (bVar20 || local_14 == 0) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      bVar20 = SCARRY4(local_14,local_38);
                      local_14 = local_14 + local_38;
                    } while (bVar20 != (int)local_14 < 0);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006fa890:
              local_c = local_10;
              local_8 = local_44;
              param_3 = (int *)local_40;
              puVar7 = local_1c;
              do {
                puVar9 = puVar7;
                if ((byte)*local_c == uVar2) {
                  do {
                    puVar9 = (uint *)((int)puVar9 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fa944;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    puVar9 = (uint *)((int)puVar7 + 2);
                    uVar11 = ((ushort)*puVar7 | 0x8210820) -
                             ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                  iVar4 * 0x100 + (uint)(uVar17 >> 0xb)) * 0x40 +
                                       *(short *)(&DAT_00d0a2e0 +
                                                 iVar4 * 0x100 + (uVar17 >> 5 & 0x3f))) * 0x20 +
                                      *(short *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uVar17 & 0x1f))) &
                             0xf7def7df);
                    uVar3 = uVar11 & 0x8210820;
                    *(ushort *)puVar7 = (short)uVar3 - (short)(uVar3 >> 5) & (ushort)uVar11;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fa944;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    puVar7 = puVar9;
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                } while ((int)param_3 < 1);
                puVar7 = puVar9;
              } while( true );
            }
            if ((DAT_00dca3fc & 0xffffff) == 0xffffff) {
              if (param_4 == 0) {
                local_18 = local_1c;
                do {
                  puVar7 = local_18;
                  local_20 = local_28;
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  while( true ) {
                    uVar2 = (uint)*(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar3 = ((ushort)*local_18 | 0x8210820) -
                            ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                 iVar4 * 0x100 + ((uVar2 & 0xf800) * uVar3 >> 0x13))
                                       * 0x40 + *(short *)(&DAT_00d0a2e0 +
                                                          iVar4 * 0x100 +
                                                          ((uVar2 & 0x7e0) * uVar3 >> 0xd))) * 0x20
                                     + *(short *)(&DAT_00d0a2e0 +
                                                 iVar4 * 0x100 + ((uVar2 & 0x1f) * uVar3 >> 8))) &
                            0xf7def7df);
                    uVar2 = uVar3 & 0x8210820;
                    *(ushort *)local_18 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar3;
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                        local_20 = local_20 + local_58;
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_18 = (uint *)((int)puVar7 + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
              local_20 = local_28;
              puVar7 = local_10;
              do {
                local_28 = local_20;
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar9 = local_1c;
                local_18 = local_1c;
                local_c = puVar7;
                while ((byte)*local_c == uVar2) {
                  do {
                    puVar9 = (uint *)((int)puVar9 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fa36e;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar9;
                  } while (0 < (int)param_3);
LAB_006fa350:
                  do {
                    local_c = (uint *)((int)local_c + local_2c);
                    param_3 = (int *)((int)param_3 + local_34);
                    local_20 = local_20 + local_58;
                  } while ((int)param_3 < 1);
                  puVar7 = local_10;
                }
                while( true ) {
                  uVar3 = (uint)*(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                  uVar11 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                  uVar11 = ((ushort)*local_18 | 0x8210820) -
                           ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                iVar4 * 0x100 + ((uVar3 & 0xf800) * uVar11 >> 0x13))
                                      * 0x40 + *(short *)(&DAT_00d0a2e0 +
                                                         iVar4 * 0x100 +
                                                         ((uVar3 & 0x7e0) * uVar11 >> 0xd))) * 0x20
                                    + *(short *)(&DAT_00d0a2e0 +
                                                iVar4 * 0x100 + ((uVar3 & 0x1f) * uVar11 >> 8))) &
                           0xf7def7df);
                  uVar3 = uVar11 & 0x8210820;
                  *(ushort *)local_18 = (short)uVar3 - (short)(uVar3 >> 5) & (ushort)uVar11;
                  puVar9 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) break;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  local_18 = puVar9;
                  if ((int)param_3 < 1) goto LAB_006fa350;
                }
                puVar7 = local_10;
LAB_006fa36e:
                local_1c = (uint *)((int)local_1c + local_48);
                local_14 = local_14 - 0x10000;
                if ((int)local_14 < 1) {
                  do {
                    local_14 = local_14 + local_38;
                    puVar7 = (uint *)((int)puVar7 + local_3c);
                    local_28 = local_28 + local_5c;
                  } while ((int)local_14 < 1);
                  local_10 = puVar7;
                }
                local_24 = local_24 + -1;
                local_20 = local_28;
                if (local_24 == 0) {
                  return;
                }
              } while( true );
            }
            local_18 = local_1c;
            local_c = local_10;
            if (param_4 == 0) {
              local_20 = local_28;
              local_8 = local_44;
              param_3 = (int *)local_40;
              while( true ) {
                while( true ) {
                  uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                  uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                  uVar8 = ((ushort)*local_18 | 0x8210820) -
                          ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                               iVar4 * 0x100 +
                                               ((&DAT_00d0a2e0)
                                                [uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] * uVar2 >>
                                               8)) * 0x40 +
                                    *(short *)(&DAT_00d0a2e0 +
                                              iVar4 * 0x100 +
                                              ((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)]
                                               * uVar2 >> 8))) * 0x20 +
                                   *(short *)(&DAT_00d0a2e0 +
                                             iVar4 * 0x100 +
                                             ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] *
                                              uVar2 >> 8))) & 0xf7def7df);
                  uVar2 = uVar8 & 0x8210820;
                  *(ushort *)local_18 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar8;
                  local_18 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) break;
                  for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                      param_3 = (int *)((int)param_3 + local_34)) {
                    local_20 = local_20 + local_58;
                    local_c = (uint *)((int)local_c + local_2c);
                  }
                }
                local_1c = (uint *)((int)local_1c + local_48);
                local_14 = local_14 - 0x10000;
                if ((int)local_14 < 1) {
                  do {
                    local_10 = (uint *)((int)local_10 + local_3c);
                    local_14 = local_14 + local_38;
                    local_28 = local_28 + local_5c;
                  } while ((int)local_14 < 1);
                }
                local_24 = local_24 + -1;
                local_c = local_10;
                local_20 = local_28;
                if (local_24 == 0) break;
                local_8 = local_44;
                param_3 = (int *)local_40;
                local_18 = local_1c;
              }
              return;
            }
LAB_006fa510:
            puVar7 = local_18;
            local_8 = local_44;
            param_3 = (int *)local_40;
            local_20 = local_28;
            local_c = local_10;
            do {
              if ((byte)*local_c == uVar2) {
                do {
                  local_18 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006fa624;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              else {
                do {
                  uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                  uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                  uVar14 = ((ushort)*local_18 | 0x8210820) -
                           ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                iVar4 * 0x100 +
                                                ((&DAT_00d0a2e0)
                                                 [uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] * uVar8 >>
                                                8)) * 0x40 +
                                     *(short *)(&DAT_00d0a2e0 +
                                               iVar4 * 0x100 +
                                               ((&DAT_00d0a2e0)
                                                [uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] * uVar8 >> 8)
                                               )) * 0x20 +
                                    *(short *)(&DAT_00d0a2e0 +
                                              iVar4 * 0x100 +
                                              ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] *
                                               uVar8 >> 8))) & 0xf7def7df);
                  uVar8 = uVar14 & 0x8210820;
                  *(ushort *)local_18 = (short)uVar8 - (short)(uVar8 >> 5) & (ushort)uVar14;
                  local_18 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006fa624;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              do {
                local_c = (uint *)((int)local_c + local_2c);
                local_20 = local_20 + local_58;
                param_3 = (int *)((int)param_3 + local_34);
              } while ((int)param_3 < 1);
            } while( true );
          case 4:
            local_18 = local_1c;
            if (param_5 == 0) {
              if ((DAT_00dca3fc & 0xffffff) == 0xffffff) {
                if (param_4 == 0) {
                  do {
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_18 = local_1c;
                    while( true ) {
                      uVar2 = (uint)*(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                      uVar3 = (uint)(ushort)*local_18;
                      *(ushort *)local_18 =
                           (ushort)((uVar2 & 0x7e0) * (uVar3 & 0x7e0) >> 0xb) & 0x7e0 |
                           (ushort)((uVar2 & 0xf800) * (uVar3 & 0xf800) >> 0x10) & 0xf800 |
                           (ushort)((uVar2 & 0x1f) * (uVar3 & 0x1f) >> 5);
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006fb2a4:
                local_c = local_10;
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                local_18 = local_1c;
                do {
                  if ((byte)*local_c == uVar2) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006fb369;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar3 = (uint)*(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                      uVar11 = (uint)(ushort)*puVar7;
                      *(ushort *)local_18 =
                           (ushort)((uVar3 & 0x7e0) * (uVar11 & 0x7e0) >> 0xb) & 0x7e0 |
                           (ushort)((uVar3 & 0xf800) * (uVar11 & 0xf800) >> 0x10) & 0xf800 |
                           (ushort)((uVar3 & 0x1f) * (uVar11 & 0x1f) >> 5);
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006fb369;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              local_c = local_10;
              if (param_4 == 0) {
                do {
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                  while( true ) {
                    uVar17 = (ushort)*local_18;
                    uVar10 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    *(ushort *)local_18 =
                         (ushort)((uVar17 >> 5 & 0x3f) *
                                  (&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] >> 1) &
                         0x7e0 | (uVar17 >> 5 & 0x7c0) *
                                 *(short *)(&DAT_00d0a2e0 + uVar18 * 0x100 + (uint)(uVar10 >> 0xb))
                                 & 0xf800 |
                         (ushort)((uVar17 & 0x1f) *
                                  (&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] >> 5);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_c = (uint *)((int)local_c + local_2c);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_14 = local_14 + local_38;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006fb4b0:
              local_10 = local_c;
              local_8 = local_44;
              param_3 = (int *)local_40;
              puVar7 = local_1c;
              local_18 = local_1c;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fb598;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar17 = (ushort)*puVar7;
                    uVar10 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    *(ushort *)local_18 =
                         (ushort)((uVar17 >> 5 & 0x3f) *
                                  (&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] >> 1) &
                         0x7e0 | (uVar17 >> 5 & 0x7c0) *
                                 *(short *)(&DAT_00d0a2e0 + uVar18 * 0x100 + (uint)(uVar10 >> 0xb))
                                 & 0xf800 |
                         (ushort)((uVar17 & 0x1f) *
                                  (&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] >> 5);
                    puVar7 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fb598;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                do {
                  local_c = (uint *)((int)local_c + local_2c);
                  param_3 = (int *)((int)param_3 + local_34);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
              local_c = local_10;
              if (param_4 == 0) {
                local_20 = local_28;
                local_8 = local_44;
                param_3 = (int *)local_40;
                while( true ) {
                  while( true ) {
                    uVar17 = (ushort)*local_18;
                    uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar10 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    *(ushort *)local_18 =
                         (ushort)((uVar17 >> 5 & 0x3f) *
                                  (&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] * uVar2 >> 9
                                 ) & 0x7e0 |
                         (ushort)((uint)(uVar17 >> 0xb) *
                                  (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] * uVar2 >>
                                 2) & 0xf800 |
                         (ushort)((uVar17 & 0x1f) *
                                  (&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] * uVar2 >> 0xd);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_20 = local_20 + local_58;
                      local_c = (uint *)((int)local_c + local_2c);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_14 = local_14 + local_38;
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                  local_c = local_10;
                  local_20 = local_28;
                  if (local_24 == 0) break;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                }
                return;
              }
LAB_006fafe6:
              local_8 = local_44;
              param_3 = (int *)local_40;
              puVar7 = local_1c;
              local_20 = local_28;
              local_18 = local_1c;
              local_c = local_10;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fb0ee;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar17 = (ushort)*puVar7;
                    uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar10 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    *(ushort *)local_18 =
                         (ushort)((uVar17 >> 5 & 0x3f) *
                                  (&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] * uVar8 >> 9
                                 ) & 0x7e0 |
                         (ushort)((uint)(uVar17 >> 0xb) *
                                  (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] * uVar8 >>
                                 2) & 0xf800 |
                         (ushort)((uVar17 & 0x1f) *
                                  (&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] * uVar8 >> 0xd);
                    puVar7 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fb0ee;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                do {
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                  param_3 = (int *)((int)param_3 + local_34);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if (param_4 == 0) {
              do {
                local_20 = local_28;
                local_c = local_10;
                local_8 = local_44;
                param_3 = (int *)local_40;
                local_18 = local_1c;
                while( true ) {
                  uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                  uVar10 = (ushort)*local_18;
                  uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                  *(ushort *)local_18 =
                       (ushort)((int)((uVar17 >> 5 & 0x3f) * (uVar10 >> 5 & 0x3f) * uVar2) >> 9) &
                       0x7e0 | (ushort)((int)((uint)(uVar17 >> 0xb) * (uint)(uVar10 >> 0xb) * uVar2)
                                       >> 2) & 0xf800 |
                       (ushort)((int)((uVar17 & 0x1f) * (uVar10 & 0x1f) * uVar2) >> 0xd);
                  local_18 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) break;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  if ((int)param_3 < 1) {
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      local_c = (uint *)((int)local_c + local_2c);
                      local_20 = local_20 + local_58;
                    } while ((int)param_3 < 1);
                  }
                }
                local_1c = (uint *)((int)local_1c + local_48);
                local_14 = local_14 - 0x10000;
                if ((int)local_14 < 1) {
                  do {
                    local_14 = local_14 + local_38;
                    local_10 = (uint *)((int)local_10 + local_3c);
                    local_28 = local_28 + local_5c;
                  } while ((int)local_14 < 1);
                }
                local_24 = local_24 + -1;
              } while (local_24 != 0);
              return;
            }
LAB_006fad77:
            local_20 = local_28;
            local_c = local_10;
            local_8 = local_44;
            param_3 = (int *)local_40;
            puVar7 = local_1c;
            local_18 = local_1c;
            do {
              if ((byte)*local_c == uVar2) {
                do {
                  puVar7 = (uint *)((int)puVar7 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006fae58;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  local_18 = puVar7;
                } while (0 < (int)param_3);
              }
              else {
                do {
                  uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                  uVar10 = (ushort)*puVar7;
                  uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                  *(ushort *)local_18 =
                       (ushort)((int)((uVar17 >> 5 & 0x3f) * (uVar10 >> 5 & 0x3f) * uVar3) >> 9) &
                       0x7e0 | (ushort)((int)((uint)(uVar17 >> 0xb) * (uint)(uVar10 >> 0xb) * uVar3)
                                       >> 2) & 0xf800 |
                       (ushort)((int)((uVar17 & 0x1f) * (uVar10 & 0x1f) * uVar3) >> 0xd);
                  puVar7 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006fae58;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  local_18 = puVar7;
                } while (0 < (int)param_3);
              }
              do {
                param_3 = (int *)((int)param_3 + local_34);
                local_c = (uint *)((int)local_c + local_2c);
                local_20 = local_20 + local_58;
              } while ((int)param_3 < 1);
            } while( true );
          case 10:
            if (param_5 != 0) {
              if ((DAT_00dca3fc & 0xffffff) == 0xffffff) {
                local_20 = local_28;
                iVar5 = DAT_00dca3f8;
                if (param_4 == 0) {
                  do {
                    local_20 = local_28;
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_18 = local_1c;
                    while( true ) {
                      uVar11 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar3 = (uint)(ushort)*local_18;
                      uVar2 = (uint)(ushort)~*(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                      *(ushort *)local_18 =
                           (ushort)(((uVar2 & 0xf800) - (uVar3 & 0xf800)) * uVar11 * DAT_00dca3f8 +
                                    (uVar3 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                           (ushort)(((uVar2 & 0x7e0) - (uVar3 & 0x7e0)) * uVar11 * DAT_00dca3f8 +
                                    (uVar3 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                           (ushort)(((uVar2 & 0x1f) - (uVar3 & 0x1f)) * uVar11 * DAT_00dca3f8 +
                                    (uVar3 & 0x1f) * 0x10000 >> 0x10);
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                        local_20 = local_20 + local_58;
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006fc3b4:
                local_28 = local_20;
                local_c = local_10;
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                local_18 = local_1c;
                do {
                  if ((byte)*local_c == uVar2) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006fc4e6;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar11 = (uint)(ushort)*puVar7;
                      uVar18 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar3 = (uint)(ushort)~*(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                      *(ushort *)local_18 =
                           (ushort)(((uVar3 & 0xf800) - (uVar11 & 0xf800)) * uVar18 * iVar5 +
                                    (uVar11 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                           (ushort)(((uVar3 & 0x7e0) - (uVar11 & 0x7e0)) * uVar18 * iVar5 +
                                    (uVar11 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                           (ushort)(((uVar3 & 0x1f) - (uVar11 & 0x1f)) * uVar18 * iVar5 +
                                    (uVar11 & 0x1f) * 0x10000 >> 0x10);
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      iVar5 = DAT_00dca3f8;
                      if (local_8 == 0) goto LAB_006fc4e6;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_20 = local_20 + local_58;
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              local_18 = local_1c;
              iVar5 = DAT_00dca3f8;
              if (param_4 == 0) {
                local_c = local_10;
                local_20 = local_28;
                local_8 = local_44;
                param_3 = (int *)local_40;
                while( true ) {
                  while( true ) {
                    uVar17 = (ushort)*local_18;
                    uVar2 = (uint)uVar17;
                    uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar10 = ~*(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    *(ushort *)local_18 =
                         (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                  (uVar17 >> 5 & 0x3f)) * uVar8 * DAT_00dca3f8 +
                                  (uVar2 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                         (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                  (uint)(uVar17 >> 0xb)) * uVar8 * DAT_00dca3f8 +
                                  (uVar2 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                         (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                  (uVar2 & 0x1f)) * uVar8 * DAT_00dca3f8 + uVar2 * 0x10000 >> 0x10)
                         & 0x1f;
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                        local_20 = local_20 + local_58;
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                  if (local_24 == 0) break;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_20 = local_28;
                  local_18 = local_1c;
                  local_c = local_10;
                }
                return;
              }
LAB_006fc6c0:
              puVar7 = local_18;
              local_8 = local_44;
              param_3 = (int *)local_40;
              local_20 = local_28;
              local_c = local_10;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fc813;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar17 = (ushort)*local_18;
                    uVar8 = (uint)uVar17;
                    uVar14 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar10 = ~*(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    *(ushort *)local_18 =
                         (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                  (uVar17 >> 5 & 0x3f)) * uVar14 * iVar5 +
                                  (uVar8 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                         (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                  (uint)(uVar17 >> 0xb)) * uVar14 * iVar5 +
                                  (uVar8 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                         (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                  (uVar8 & 0x1f)) * uVar14 * iVar5 + uVar8 * 0x10000 >> 0x10) & 0x1f
                    ;
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    iVar5 = DAT_00dca3f8;
                    if (local_8 == 0) goto LAB_006fc813;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                  param_3 = (int *)((int)param_3 + local_34);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
              local_c = local_10;
              if (param_4 == 0) {
                do {
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                  while( true ) {
                    uVar17 = (ushort)*local_18;
                    uVar10 = ~*(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    *(ushort *)local_18 =
                         ((uVar17 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                   (uVar17 >> 5 & 0x3f)) * 4 + iVar4 * 0x800)) * 0x20 |
                         ((uVar17 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                   (uint)(uVar17 >> 0xb)) * 4 + iVar4 * 0x800)) * 0x800 |
                         (uVar17 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                   (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_c = (uint *)((int)local_c + local_2c);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_14 = local_14 + local_38;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006fccb0:
              local_10 = local_c;
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              local_18 = local_1c;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fcdc8;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar17 = (ushort)*puVar7;
                    uVar10 = ~*(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    *(ushort *)local_18 =
                         ((uVar17 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                   (uVar17 >> 5 & 0x3f)) * 4 + iVar4 * 0x800)) * 0x20 |
                         ((uVar17 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                   (uint)(uVar17 >> 0xb)) * 4 + iVar4 * 0x800)) * 0x800 |
                         (uVar17 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                   (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                    puVar7 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fcdc8;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                do {
                  local_c = (uint *)((int)local_c + local_2c);
                  param_3 = (int *)((int)param_3 + local_34);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if (param_4 == 0) {
              do {
                local_c = local_10;
                local_8 = local_44;
                param_3 = (int *)local_40;
                local_18 = local_1c;
                while( true ) {
                  uVar17 = (ushort)*local_18;
                  uVar10 = ~*(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                  *(ushort *)local_18 =
                       ((uVar17 >> 5 & 0x3f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((uVar10 >> 5 & 0x3f) - (uVar17 >> 5 & 0x3f)) * 4 + iVar4 * 0x800))
                       * 0x20 | ((uVar17 >> 0xb) +
                                *(short *)(&DAT_00d4a6e0 +
                                          ((uint)(uVar10 >> 0xb) - (uint)(uVar17 >> 0xb)) * 4 +
                                          iVar4 * 0x800)) * 0x800 |
                       (uVar17 & 0x1f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((uVar10 & 0x1f) - (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                  local_18 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) break;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  if ((int)param_3 < 1) {
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      local_c = (uint *)((int)local_c + local_2c);
                    } while ((int)param_3 < 1);
                  }
                }
                local_1c = (uint *)((int)local_1c + local_48);
                local_14 = local_14 - 0x10000;
                if ((int)local_14 < 1) {
                  do {
                    local_10 = (uint *)((int)local_10 + local_3c);
                    local_14 = local_14 + local_38;
                  } while ((int)local_14 < 1);
                }
                local_24 = local_24 + -1;
              } while (local_24 != 0);
              return;
            }
LAB_006fca50:
            local_c = local_10;
            local_8 = local_44;
            puVar7 = local_1c;
            param_3 = (int *)local_40;
            local_18 = local_1c;
            do {
              if ((byte)*local_c == uVar2) {
                do {
                  puVar7 = (uint *)((int)puVar7 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006fcb42;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
                local_18 = puVar7;
              }
              else {
                do {
                  uVar17 = (ushort)*puVar7;
                  uVar10 = ~*(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                  *(ushort *)local_18 =
                       ((uVar17 >> 5 & 0x3f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((uVar10 >> 5 & 0x3f) - (uVar17 >> 5 & 0x3f)) * 4 + iVar4 * 0x800))
                       * 0x20 | ((uVar17 >> 0xb) +
                                *(short *)(&DAT_00d4a6e0 +
                                          ((uint)(uVar10 >> 0xb) - (uint)(uVar17 >> 0xb)) * 4 +
                                          iVar4 * 0x800)) * 0x800 |
                       (uVar17 & 0x1f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((uVar10 & 0x1f) - (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                  puVar7 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006fcb42;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  local_18 = puVar7;
                } while (0 < (int)param_3);
              }
              do {
                param_3 = (int *)((int)param_3 + local_34);
                local_c = (uint *)((int)local_c + local_2c);
              } while ((int)param_3 < 1);
            } while( true );
          case 0xb:
            if (param_5 != 0) {
              if ((DAT_00dca3fc & 0xffffff) == 0xffffff) {
                local_18 = local_1c;
                local_c = local_10;
                if (param_4 == 0) {
                  local_8 = local_44;
                  local_20 = local_28;
                  param_3 = (int *)local_40;
                  while( true ) {
                    while( true ) {
                      uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar17 = (ushort)*local_18;
                      uVar18 = (uint)uVar17;
                      uVar10 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                      uVar11 = uVar18 & 0x1f;
                      uVar2 = uVar17 >> 5 & 0x3f;
                      *(ushort *)local_18 =
                           (ushort)((int)((((int)((uVar10 >> 5 & 0x3f) * uVar2) >> 6) - uVar2) *
                                          uVar3 * DAT_00dca3f8 + (uVar18 & 0x7e0) * 0x800) >> 0xb) &
                           0x7e0 | (ushort)((int)((((int)((uint)(uVar10 >> 0xb) *
                                                         (uint)(uVar17 >> 0xb)) >> 5) -
                                                  (uint)(uVar17 >> 0xb)) * uVar3 * DAT_00dca3f8 +
                                                 (uVar18 & 0xfffff800) * 0x20) >> 5) & 0xf800 |
                           (ushort)((((int)((uVar10 & 0x1f) * uVar11) >> 5) - uVar11) * uVar3 *
                                    DAT_00dca3f8 + uVar11 * 0x10000 >> 0x10);
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                        local_20 = local_20 + local_58;
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_20 = local_28;
                    local_18 = local_1c;
                    local_c = local_10;
                  }
                  return;
                }
                local_20 = local_28;
                iVar5 = DAT_00dca3f8;
LAB_006fb724:
                local_28 = local_20;
                local_c = local_10;
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                local_18 = local_1c;
                do {
                  if ((byte)*local_c == uVar2) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006fb865;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar17 = (ushort)*puVar7;
                      uVar8 = (uint)uVar17;
                      uVar11 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar10 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                      uVar18 = uVar8 & 0x1f;
                      uVar3 = uVar17 >> 5 & 0x3f;
                      *(ushort *)local_18 =
                           (ushort)((int)((((int)((uVar10 >> 5 & 0x3f) * uVar3) >> 6) - uVar3) *
                                          uVar11 * iVar5 + (uVar8 & 0x7e0) * 0x800) >> 0xb) & 0x7e0
                           | (ushort)((int)((((int)((uint)(uVar10 >> 0xb) * (uint)(uVar17 >> 0xb))
                                             >> 5) - (uint)(uVar17 >> 0xb)) * uVar11 * iVar5 +
                                           (uVar8 & 0xfffff800) * 0x20) >> 5) & 0xf800 |
                           (ushort)((((int)((uVar10 & 0x1f) * uVar18) >> 5) - uVar18) * uVar11 *
                                    iVar5 + uVar18 * 0x10000 >> 0x10);
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      iVar5 = DAT_00dca3f8;
                      if (local_8 == 0) goto LAB_006fb865;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_20 = local_20 + local_58;
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              local_18 = local_1c;
              iVar5 = DAT_00dca3f8;
              if (param_4 == 0) {
                local_c = local_10;
                local_20 = local_28;
                local_8 = local_44;
                param_3 = (int *)local_40;
                while( true ) {
                  while( true ) {
                    uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    uVar10 = (ushort)*local_18;
                    uVar2 = (uint)uVar10;
                    uVar14 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar8 = uVar10 >> 5 & 0x3f;
                    *(ushort *)local_18 =
                         (ushort)((((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] * uVar8 >>
                                   6) - uVar8) * uVar14 * DAT_00dca3f8 +
                                  (uVar2 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                         (ushort)((((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] *
                                    (uint)(uVar10 >> 0xb) >> 5) - (uint)(uVar10 >> 0xb)) * uVar14 *
                                  DAT_00dca3f8 + (uVar2 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                         (ushort)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] *
                                    (uVar2 & 0x1f) >> 5) - (uVar2 & 0x1f)) * uVar14 * DAT_00dca3f8 +
                                  uVar2 * 0x10000 >> 0x10) & 0x1f;
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                        local_20 = local_20 + local_58;
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_14 = local_14 + local_38;
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                  local_c = local_10;
                  local_20 = local_28;
                  if (local_24 == 0) break;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                }
                return;
              }
LAB_006fba60:
              puVar7 = local_18;
              local_8 = local_44;
              param_3 = (int *)local_40;
              local_20 = local_28;
              local_c = local_10;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fbbd3;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar17 = (ushort)*local_18;
                    uVar8 = (uint)uVar17;
                    uVar10 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    uVar15 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar14 = uVar17 >> 5 & 0x3f;
                    *(ushort *)local_18 =
                         (ushort)((((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] * uVar14
                                   >> 6) - uVar14) * uVar15 * iVar5 + (uVar8 & 0xffffffe0) * 0x800
                                 >> 0xb) & 0x7e0 |
                         (ushort)((((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] *
                                    (uint)(uVar17 >> 0xb) >> 5) - (uint)(uVar17 >> 0xb)) * uVar15 *
                                  iVar5 + (uVar8 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                         (ushort)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] *
                                    (uVar8 & 0x1f) >> 5) - (uVar8 & 0x1f)) * uVar15 * iVar5 +
                                  uVar8 * 0x10000 >> 0x10) & 0x1f;
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    iVar5 = DAT_00dca3f8;
                    if (local_8 == 0) goto LAB_006fbbd3;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                  param_3 = (int *)((int)param_3 + local_34);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if ((DAT_00dca3fc & 0xffffff) == 0xffffff) {
              if (param_4 == 0) {
                do {
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                  while( true ) {
                    uVar17 = (ushort)*local_18;
                    uVar10 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    uVar2 = uVar17 >> 5 & 0x3f;
                    *(ushort *)local_18 =
                         ((uVar17 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((int)((uVar10 >> 5 & 0x3f) * uVar2) >> 6) - uVar2) * 4 +
                                   iVar4 * 0x800)) * 0x20 |
                         ((uVar17 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((int)((uint)(uVar10 >> 0xb) * (uint)(uVar17 >> 0xb)) >> 5) -
                                   (uint)(uVar17 >> 0xb)) * 4 + iVar4 * 0x800)) * 0x800 |
                         (uVar17 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((int)((uVar10 & 0x1f) * (uVar17 & 0x1f)) >> 5) -
                                   (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006fbe20:
              local_c = local_10;
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              local_18 = local_1c;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fbf2a;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar17 = (ushort)*puVar7;
                    uVar10 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                    uVar3 = uVar17 >> 5 & 0x3f;
                    *(ushort *)local_18 =
                         ((uVar17 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((int)((uVar10 >> 5 & 0x3f) * uVar3) >> 6) - uVar3) * 4 +
                                   iVar4 * 0x800)) * 0x20 |
                         ((uVar17 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((int)((uint)(uVar10 >> 0xb) * (uint)(uVar17 >> 0xb)) >> 5) -
                                   (uint)(uVar17 >> 0xb)) * 4 + iVar4 * 0x800)) * 0x800 |
                         (uVar17 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((int)((uVar10 & 0x1f) * (uVar17 & 0x1f)) >> 5) -
                                   (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                    puVar7 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fbf2a;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                } while ((int)param_3 < 1);
              } while( true );
            }
            local_c = local_10;
            if (param_4 == 0) {
              do {
                local_c = local_10;
                local_8 = local_44;
                param_3 = (int *)local_40;
                local_18 = local_1c;
                while( true ) {
                  uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                  uVar10 = (ushort)*local_18;
                  uVar2 = uVar10 >> 5 & 0x3f;
                  *(ushort *)local_18 =
                       ((uVar10 >> 5 & 0x3f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 (((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] * uVar2 >>
                                  6) - uVar2) * 4 + iVar4 * 0x800)) * 0x20 |
                       ((uVar10 >> 0xb) +
                       *(short *)(&DAT_00d4a6e0 +
                                 (((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] *
                                   (uint)(uVar10 >> 0xb) >> 5) - (uint)(uVar10 >> 0xb)) * 4 +
                                 iVar4 * 0x800)) * 0x800 |
                       (uVar10 & 0x1f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 (((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] *
                                   (uVar10 & 0x1f) >> 5) - (uVar10 & 0x1f)) * 4 + iVar4 * 0x800);
                  local_18 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) break;
                  for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                      param_3 = (int *)((int)param_3 + local_34)) {
                    local_c = (uint *)((int)local_c + local_2c);
                  }
                }
                local_1c = (uint *)((int)local_1c + local_48);
                local_14 = local_14 - 0x10000;
                if ((int)local_14 < 1) {
                  do {
                    local_10 = (uint *)((int)local_10 + local_3c);
                    local_14 = local_14 + local_38;
                  } while ((int)local_14 < 1);
                }
                local_24 = local_24 + -1;
              } while (local_24 != 0);
              return;
            }
LAB_006fc0b0:
            local_10 = local_c;
            local_8 = local_44;
            puVar7 = local_1c;
            param_3 = (int *)local_40;
            local_18 = local_1c;
            do {
              if ((byte)*local_c == uVar2) {
                do {
                  puVar7 = (uint *)((int)puVar7 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006fc1d8;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  local_18 = puVar7;
                } while (0 < (int)param_3);
              }
              else {
                do {
                  uVar17 = *(ushort *)(iVar6 + (uint)(byte)*local_c * 2);
                  uVar10 = (ushort)*puVar7;
                  uVar8 = uVar10 >> 5 & 0x3f;
                  *(ushort *)local_18 =
                       ((uVar10 >> 5 & 0x3f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 (((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] * uVar8 >>
                                  6) - uVar8) * 4 + iVar4 * 0x800)) * 0x20 |
                       ((uVar10 >> 0xb) +
                       *(short *)(&DAT_00d4a6e0 +
                                 (((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] *
                                   (uint)(uVar10 >> 0xb) >> 5) - (uint)(uVar10 >> 0xb)) * 4 +
                                 iVar4 * 0x800)) * 0x800 |
                       (uVar10 & 0x1f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 (((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] *
                                   (uVar10 & 0x1f) >> 5) - (uVar10 & 0x1f)) * 4 + iVar4 * 0x800);
                  puVar7 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006fc1d8;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  local_18 = puVar7;
                } while (0 < (int)param_3);
              }
              do {
                local_c = (uint *)((int)local_c + local_2c);
                param_3 = (int *)((int)param_3 + local_34);
              } while ((int)param_3 < 1);
            } while( true );
          }
        }
        else {
          switch(DAT_00dca3f4) {
          case 0:
switchD_006fcf65_caseD_0:
            if (param_5 == 0) {
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (*(int *)(param_2 + 0x2c) != 1) {
                  if (param_4 == 0) {
                    do {
                      local_c = local_10;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      puVar7 = local_1c;
LAB_006fe4d9:
                      puVar9 = puVar7;
                      while( true ) {
                        uVar17 = (ushort)*local_c;
                        puVar7 = (uint *)((int)puVar9 + 2);
                        *(ushort *)puVar9 =
                             (*(short *)(&DAT_00d0a2e0 + uVar18 * 0x100 + (uint)(uVar17 >> 0xb)) <<
                              6 | *(ushort *)(&DAT_00d0a2e0 + uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)))
                             << 5 | *(ushort *)(&DAT_00d0a2e0 + uVar11 * 0x100 + (uVar17 & 0x1f));
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        puVar9 = puVar7;
                        if ((int)param_3 < 1) goto LAB_006fe530;
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_14 = local_14 + local_38;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                      if (local_24 == 0) {
                        return;
                      }
                    } while( true );
                  }
LAB_006fe3f0:
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  do {
                    puVar9 = puVar7;
                    if ((ushort)*local_c == uVar2) {
                      do {
                        puVar7 = (uint *)((int)puVar7 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006fe488;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        uVar17 = (ushort)*local_c;
                        puVar7 = (uint *)((int)puVar9 + 2);
                        *(ushort *)puVar9 =
                             (*(short *)(&DAT_00d0a2e0 + uVar18 * 0x100 + (uint)(uVar17 >> 0xb)) <<
                              6 | *(ushort *)(&DAT_00d0a2e0 + uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)))
                             << 5 | *(ushort *)(&DAT_00d0a2e0 + uVar11 * 0x100 + (uVar17 & 0x1f));
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006fe488;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        puVar9 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      local_c = (uint *)((int)local_c + local_2c);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                if (param_4 == 0) {
                  do {
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_18 = local_1c;
                    while( true ) {
                      uVar17 = (ushort)*local_c;
                      uVar10 = (ushort)*local_18;
                      uVar2 = uVar10 & 0x1f;
                      *(ushort *)local_18 =
                           (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] -
                                    (uVar10 >> 5 & 0x3f)) * (uint)*(byte *)((int)local_c + 2) +
                                    (uVar10 & 0xffffffe0) * 8 >> 3) & 0x7e0 |
                           ((*(short *)(&DAT_00d0a2e0 + uVar18 * 0x100 + (uint)(uVar17 >> 0xb)) -
                            (uVar10 >> 0xb)) * (ushort)*(byte *)((int)local_c + 2) +
                           (uVar10 >> 3 & 0x1f00)) * 8 & 0xf800 |
                           (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] - uVar2) *
                                    (uint)*(byte *)((int)local_c + 2) + uVar2 * 0x100 >> 8);
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006fe0e0:
                local_c = local_10;
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                local_18 = local_1c;
                do {
                  if (*(byte *)((int)local_c + 2) == 0) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006fe252;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else {
                    puVar9 = puVar7;
                    if (*(byte *)((int)local_c + 2) == 0xff) {
                      do {
                        uVar17 = (ushort)*local_c;
                        puVar7 = (uint *)((int)puVar9 + 2);
                        *(ushort *)puVar9 =
                             (*(short *)(&DAT_00d0a2e0 + uVar18 * 0x100 + (uint)(uVar17 >> 0xb)) <<
                              6 | *(ushort *)(&DAT_00d0a2e0 + uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)))
                             << 5 | *(ushort *)(&DAT_00d0a2e0 + uVar11 * 0x100 + (uVar17 & 0x1f));
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006fe252;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        puVar9 = puVar7;
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        uVar17 = (ushort)*local_c;
                        uVar10 = (ushort)*puVar7;
                        uVar2 = uVar10 & 0x1f;
                        *(ushort *)local_18 =
                             (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] -
                                      (uVar10 >> 5 & 0x3f)) * (uint)*(byte *)((int)local_c + 2) +
                                      (uVar10 & 0xffffffe0) * 8 >> 3) & 0x7e0 |
                             ((*(short *)(&DAT_00d0a2e0 + uVar18 * 0x100 + (uint)(uVar17 >> 0xb)) -
                              (uVar10 >> 0xb)) * (ushort)*(byte *)((int)local_c + 2) +
                             (uVar10 >> 3 & 0x1f00)) * 8 & 0xf800 |
                             (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] - uVar2) *
                                      (uint)*(byte *)((int)local_c + 2) + uVar2 * 0x100 >> 8);
                        puVar7 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006fe252;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
                    }
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (*(int *)(param_2 + 0x2c) != 1) {
                if (param_4 == 0) {
                  do {
                    iVar6 = local_44;
                    iVar4 = local_40;
                    puVar7 = local_10;
LAB_006fe06f:
                    uVar2 = *puVar7;
                    iVar13 = iVar4;
                    while( true ) {
                      *(ushort *)local_1c = (ushort)uVar2;
                      local_1c = (uint *)((int)local_1c + 2);
                      iVar6 = iVar6 + -1;
                      if (iVar6 == 0) break;
                      iVar4 = iVar13 + -0x10000;
                      bVar20 = iVar13 < 0x10000;
                      iVar13 = iVar4;
                      if (iVar4 == 0 || bVar20) goto LAB_006fe087;
                    }
                    local_1c = (uint *)((int)local_1c + iVar5);
                    bVar20 = local_14 < 0x10000;
                    local_14 = local_14 - 0x10000;
                    if (bVar20 || local_14 == 0) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        bVar20 = SCARRY4(local_14,local_38);
                        local_14 = local_14 + local_38;
                      } while (bVar20 != (int)local_14 < 0);
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) {
                      return;
                    }
                  } while( true );
                }
LAB_006fdfe7:
                iVar6 = local_44;
                iVar4 = local_40;
                puVar7 = local_10;
                do {
                  uVar2 = *puVar7;
                  iVar13 = iVar4;
                  if ((ushort)uVar2 == (ushort)local_50) {
                    do {
                      local_1c = (uint *)((int)local_1c + 2);
                      iVar6 = iVar6 + -1;
                      if (iVar6 == 0) goto LAB_006fe02f;
                      iVar4 = iVar13 + -0x10000;
                      bVar20 = 0xffff < iVar13;
                      iVar13 = iVar4;
                    } while (iVar4 != 0 && bVar20);
                  }
                  else {
                    do {
                      *(ushort *)local_1c = (ushort)uVar2;
                      local_1c = (uint *)((int)local_1c + 2);
                      iVar6 = iVar6 + -1;
                      if (iVar6 == 0) goto LAB_006fe02f;
                      iVar4 = iVar13 + -0x10000;
                      bVar20 = 0xffff < iVar13;
                      iVar13 = iVar4;
                    } while (iVar4 != 0 && bVar20);
                  }
                  do {
                    puVar7 = (uint *)((int)puVar7 + local_2c);
                    bVar20 = SCARRY4(iVar4,local_34);
                    iVar4 = iVar4 + local_34;
                  } while (bVar20 != iVar4 < 0);
                } while( true );
              }
              if (param_4 == 0) {
                do {
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                  while( true ) {
                    uVar3 = (uint)(ushort)*local_18;
                    uVar2 = (uint)(ushort)*local_c;
                    *(ushort *)local_18 =
                         (ushort)(((uVar2 & 0xf800) - (uVar3 & 0xf800)) *
                                  (uint)*(byte *)((int)local_c + 2) + (uVar3 & 0xfffff800) * 0x100
                                 >> 8) & 0xf800 |
                         (ushort)(((uVar2 & 0x7e0) - (uVar3 & 0x7e0)) *
                                  (uint)*(byte *)((int)local_c + 2) + (uVar3 & 0xffffffe0) * 0x100
                                 >> 8) & 0x7e0 |
                         (ushort)(((uVar2 & 0x1f) - (uVar3 & 0x1f)) *
                                  (uint)*(byte *)((int)local_c + 2) + (uVar3 & 0x1f) * 0x100 >> 8);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006fdd30:
              local_c = local_10;
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              local_18 = local_1c;
              do {
                if (*(byte *)((int)local_c + 2) == 0) {
                  do {
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fde66;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                else if (*(byte *)((int)local_c + 2) == 0xff) {
                  do {
                    *(ushort *)puVar7 = (ushort)*local_c;
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fde66;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar3 = (uint)(ushort)*puVar7;
                    uVar2 = (uint)(ushort)*local_c;
                    *(ushort *)local_18 =
                         (ushort)(((uVar2 & 0xf800) - (uVar3 & 0xf800)) *
                                  (uint)*(byte *)((int)local_c + 2) + (uVar3 & 0xfffff800) * 0x100
                                 >> 8) & 0xf800 |
                         (ushort)(((uVar2 & 0x7e0) - (uVar3 & 0x7e0)) *
                                  (uint)*(byte *)((int)local_c + 2) + (uVar3 & 0xffffffe0) * 0x100
                                 >> 8) & 0x7e0 |
                         (ushort)(((uVar2 & 0x1f) - (uVar3 & 0x1f)) *
                                  (uint)*(byte *)((int)local_c + 2) + (uVar3 & 0x1f) * 0x100 >> 8);
                    puVar7 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fde66;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
              if (*(int *)(param_2 + 0x2c) != 1) {
                local_20 = local_28;
                if (param_4 == 0) {
                  do {
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_20 = local_28;
                    local_18 = local_1c;
                    local_c = local_10;
                    while( true ) {
                      uVar17 = (ushort)*local_18;
                      bVar1 = (&DAT_00dca2e0)[*local_20];
                      uVar10 = (ushort)*local_c;
                      uVar2 = uVar17 & 0x1f;
                      *(ushort *)local_18 =
                           (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                    (uVar17 >> 5 & 0x3f)) * (uint)bVar1 + (uVar17 & 0xffffffe0) * 8
                                   >> 3) & 0x7e0 |
                           ((*(short *)(&DAT_00d0a2e0 + uVar18 * 0x100 + (uint)(uVar10 >> 0xb)) -
                            (uVar17 >> 0xb)) * (ushort)bVar1 + (uVar17 >> 3 & 0x1f00)) * 8 & 0xf800
                           | (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] - uVar2) *
                                      (uint)bVar1 + uVar2 * 0x100 >> 8);
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          local_20 = local_20 + local_58;
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006fda10:
                local_28 = local_20;
                local_c = local_10;
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                local_18 = local_1c;
                do {
                  if ((ushort)*local_c == uVar2) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006fdb4e;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                    local_18 = puVar7;
                  }
                  else {
                    do {
                      uVar17 = (ushort)*puVar7;
                      bVar1 = (&DAT_00dca2e0)[*local_20];
                      uVar10 = (ushort)*local_c;
                      uVar8 = uVar17 & 0x1f;
                      *(ushort *)local_18 =
                           (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                    (uVar17 >> 5 & 0x3f)) * (uint)bVar1 + (uVar17 & 0xffffffe0) * 8
                                   >> 3) & 0x7e0 |
                           ((*(short *)(&DAT_00d0a2e0 + uVar18 * 0x100 + (uint)(uVar10 >> 0xb)) -
                            (uVar17 >> 0xb)) * (ushort)bVar1 + (uVar17 >> 3 & 0x1f00)) * 8 & 0xf800
                           | (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] - uVar8) *
                                      (uint)bVar1 + uVar8 * 0x100 >> 8);
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006fdb4e;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_20 = local_20 + local_58;
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              local_20 = local_28;
              if (param_4 == 0) {
                do {
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_20 = local_28;
                  local_18 = local_1c;
                  local_c = local_10;
                  while( true ) {
                    uVar17 = (ushort)*local_c;
                    uVar10 = (ushort)*local_18;
                    uVar2 = (uint)uVar10;
                    uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    *(ushort *)local_18 =
                         (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] -
                                  (uVar10 >> 5 & 0x3f)) * uVar8 * (uint)*(byte *)((int)local_c + 2)
                                  + (uVar2 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                         (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] -
                                  (uint)(uVar10 >> 0xb)) * uVar8 * (uint)*(byte *)((int)local_c + 2)
                                  + (uVar2 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                         (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] -
                                  (uVar2 & 0x1f)) * uVar8 * (uint)*(byte *)((int)local_c + 2) +
                                  (uVar2 & 0x1f) * 0x10000 >> 0x10);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        local_20 = local_20 + local_58;
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_14 = local_14 + local_38;
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006fd626:
              local_28 = local_20;
              local_c = local_10;
              local_8 = local_44;
              param_3 = (int *)local_40;
              local_18 = local_1c;
              do {
                if (*(byte *)((int)local_c + 2) == 0) {
                  do {
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fd838;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else if (*(byte *)((int)local_c + 2) == 0xff) {
                  do {
                    uVar17 = (ushort)*local_c;
                    uVar10 = (ushort)*local_18;
                    bVar1 = (&DAT_00dca2e0)[*local_20];
                    uVar2 = uVar10 & 0x1f;
                    *(ushort *)local_18 =
                         (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] -
                                  (uVar10 >> 5 & 0x3f)) * (uint)bVar1 + (uVar10 & 0xffffffe0) * 8 >>
                                 3) & 0x7e0 |
                         ((*(short *)(&DAT_00d0a2e0 + uVar18 * 0x100 + (uint)(uVar17 >> 0xb)) -
                          (uVar10 >> 0xb)) * (ushort)bVar1 + (uVar10 >> 3 & 0x1f00)) * 8 & 0xf800 |
                         (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] - uVar2) *
                                  (uint)bVar1 + uVar2 * 0x100 >> 8);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fd838;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar17 = (ushort)*local_c;
                    uVar10 = (ushort)*local_18;
                    uVar2 = (uint)uVar10;
                    uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    *(ushort *)local_18 =
                         (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] -
                                  (uVar10 >> 5 & 0x3f)) * uVar8 * (uint)*(byte *)((int)local_c + 2)
                                  + (uVar2 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                         (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] -
                                  (uint)(uVar10 >> 0xb)) * uVar8 * (uint)*(byte *)((int)local_c + 2)
                                  + (uVar2 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                         (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] -
                                  (uVar2 & 0x1f)) * uVar8 * (uint)*(byte *)((int)local_c + 2) +
                                  (uVar2 & 0x1f) * 0x10000 >> 0x10);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fd838;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                } while ((int)param_3 < 1);
              } while( true );
            }
            if (*(int *)(param_2 + 0x2c) != 1) {
              if (param_4 == 0) {
                do {
                  local_20 = local_28;
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                  while( true ) {
                    uVar11 = (uint)(ushort)*local_18;
                    uVar2 = (uint)(ushort)*local_c;
                    uVar18 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar3 = uVar11 << 8;
                    *(ushort *)local_18 =
                         (ushort)(((uVar2 & 0xf800) - (uVar11 & 0xf800)) * uVar18 +
                                  (uVar3 & 0xfff80000) >> 8) & 0xf800 |
                         (ushort)(((uVar2 & 0x7e0) - (uVar11 & 0x7e0)) * uVar18 +
                                  (uVar3 & 0xffffe000) >> 8) & 0x7e0 |
                         (ushort)(((uVar2 & 0x1f) - (uVar11 & 0x1f)) * uVar18 + (uVar3 & 0x1f00) >>
                                 8);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                        local_20 = local_20 + local_58;
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006fd367:
              local_20 = local_28;
              local_c = local_10;
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              local_18 = local_1c;
              do {
                if ((ushort)*local_c == uVar2) {
                  do {
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fd47a;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar18 = (uint)(ushort)*puVar7;
                    uVar3 = (uint)(ushort)*local_c;
                    uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar11 = uVar18 << 8;
                    *(ushort *)local_18 =
                         (ushort)(((uVar3 & 0xf800) - (uVar18 & 0xf800)) * uVar8 +
                                  (uVar11 & 0xfff80000) >> 8) & 0xf800 |
                         (ushort)(((uVar3 & 0x7e0) - (uVar18 & 0x7e0)) * uVar8 +
                                  (uVar11 & 0xffffe000) >> 8) & 0x7e0 |
                         (ushort)(((uVar3 & 0x1f) - (uVar18 & 0x1f)) * uVar8 + (uVar11 & 0x1f00) >>
                                 8);
                    puVar7 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fd47a;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                } while ((int)param_3 < 1);
              } while( true );
            }
            if (param_4 == 0) {
              do {
                local_20 = local_28;
                local_c = local_10;
                local_8 = local_44;
                param_3 = (int *)local_40;
                local_18 = local_1c;
                while( true ) {
                  uVar11 = (uint)(ushort)*local_18;
                  uVar2 = (uint)(ushort)*local_c;
                  uVar18 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                  uVar3 = uVar11 << 0x10;
                  *(ushort *)local_18 =
                       (ushort)(((uVar2 & 0xf800) - (uVar11 & 0xf800)) * uVar18 *
                                (uint)*(byte *)((int)local_c + 2) + (uVar3 & 0xf8000000) >> 0x10) &
                       0xf800 | (ushort)(((uVar2 & 0x7e0) - (uVar11 & 0x7e0)) * uVar18 *
                                         (uint)*(byte *)((int)local_c + 2) + (uVar3 & 0xffe00000) >>
                                        0x10) & 0x7e0 |
                       (ushort)(((uVar2 & 0x1f) - (uVar11 & 0x1f)) * uVar18 *
                                (uint)*(byte *)((int)local_c + 2) + (uVar3 & 0x1f0000) >> 0x10);
                  local_18 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) break;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  if ((int)param_3 < 1) {
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      local_c = (uint *)((int)local_c + local_2c);
                      local_20 = local_20 + local_58;
                    } while ((int)param_3 < 1);
                  }
                }
                local_1c = (uint *)((int)local_1c + local_48);
                local_14 = local_14 - 0x10000;
                if ((int)local_14 < 1) {
                  do {
                    local_14 = local_14 + local_38;
                    local_10 = (uint *)((int)local_10 + local_3c);
                    local_28 = local_28 + local_5c;
                  } while ((int)local_14 < 1);
                }
                local_24 = local_24 + -1;
              } while (local_24 != 0);
              return;
            }
            local_20 = local_28;
LAB_006fcfc0:
            local_28 = local_20;
            local_c = local_10;
            local_8 = local_44;
            param_3 = (int *)local_40;
            local_18 = local_1c;
            do {
              if (*(byte *)((int)local_c + 2) == 0) {
                do {
                  local_18 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006fd1aa;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              else if (*(byte *)((int)local_c + 2) == 0xff) {
                do {
                  uVar11 = (uint)(ushort)*local_18;
                  uVar2 = (uint)(ushort)*local_c;
                  uVar18 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                  uVar3 = uVar11 << 8;
                  *(ushort *)local_18 =
                       (ushort)(((uVar2 & 0xf800) - (uVar11 & 0xf800)) * uVar18 +
                                (uVar3 & 0xfff80000) >> 8) & 0xf800 |
                       (ushort)(((uVar2 & 0x7e0) - (uVar11 & 0x7e0)) * uVar18 + (uVar3 & 0xffffe000)
                               >> 8) & 0x7e0 |
                       (ushort)(((uVar2 & 0x1f) - (uVar11 & 0x1f)) * uVar18 + (uVar3 & 0x1f00) >> 8)
                  ;
                  local_18 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006fd1aa;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              else {
                do {
                  uVar11 = (uint)(ushort)*local_18;
                  uVar2 = (uint)(ushort)*local_c;
                  uVar18 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                  uVar3 = uVar11 << 0x10;
                  *(ushort *)local_18 =
                       (ushort)(((uVar2 & 0xf800) - (uVar11 & 0xf800)) * uVar18 *
                                (uint)*(byte *)((int)local_c + 2) + (uVar3 & 0xf8000000) >> 0x10) &
                       0xf800 | (ushort)(((uVar2 & 0x7e0) - (uVar11 & 0x7e0)) * uVar18 *
                                         (uint)*(byte *)((int)local_c + 2) + (uVar3 & 0xffe00000) >>
                                        0x10) & 0x7e0 |
                       (ushort)(((uVar2 & 0x1f) - (uVar11 & 0x1f)) * uVar18 *
                                (uint)*(byte *)((int)local_c + 2) + (uVar3 & 0x1f0000) >> 0x10);
                  local_18 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006fd1aa;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              do {
                param_3 = (int *)((int)param_3 + local_34);
                local_c = (uint *)((int)local_c + local_2c);
                local_20 = local_20 + local_58;
              } while ((int)param_3 < 1);
            } while( true );
          case 1:
            if (DAT_00dca3f8 == 0xff) goto switchD_006fcf65_caseD_0;
            if (DAT_00dca3f8 != 0) {
              if (param_5 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (*(int *)(param_2 + 0x2c) != 1) {
                    local_c = local_10;
                    if (param_4 == 0) {
                      do {
                        local_8 = local_44;
                        param_3 = (int *)local_40;
                        local_18 = local_1c;
                        local_c = local_10;
                        while( true ) {
                          uVar17 = (ushort)*local_18;
                          uVar10 = (ushort)*local_c;
                          *(ushort *)local_18 =
                               ((uVar17 >> 5 & 0x3f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                         (uVar17 >> 5 & 0x3f)) * 4 + iVar4 * 0x800)) * 0x20 |
                               ((uVar17 >> 0xb) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                         (uint)(uVar17 >> 0xb)) * 4 + iVar4 * 0x800)) * 0x800 |
                               (uVar17 & 0x1f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                         (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                          local_18 = (uint *)((int)local_18 + 2);
                          local_8 = local_8 + -1;
                          if (local_8 == 0) break;
                          for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                              param_3 = (int *)((int)param_3 + local_34)) {
                            local_c = (uint *)((int)local_c + local_2c);
                          }
                        }
                        local_1c = (uint *)((int)local_1c + local_48);
                        for (local_14 = local_14 - 0x10000; (int)local_14 < 1;
                            local_14 = local_14 + local_38) {
                          local_10 = (uint *)((int)local_10 + local_3c);
                        }
                        local_24 = local_24 + -1;
                      } while (local_24 != 0);
                      return;
                    }
LAB_006ffe51:
                    local_10 = local_c;
                    local_8 = local_44;
                    puVar7 = local_1c;
                    param_3 = (int *)local_40;
                    local_18 = local_1c;
                    do {
                      if ((ushort)*local_c == uVar2) {
                        do {
                          puVar7 = (uint *)((int)puVar7 + 2);
                          local_8 = local_8 + -1;
                          if (local_8 == 0) goto LAB_006fff58;
                          param_3 = (int *)((int)param_3 + -0x10000);
                          local_18 = puVar7;
                        } while (0 < (int)param_3);
                      }
                      else {
                        do {
                          uVar17 = (ushort)*puVar7;
                          uVar10 = (ushort)*local_c;
                          *(ushort *)local_18 =
                               ((uVar17 >> 5 & 0x3f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                         (uVar17 >> 5 & 0x3f)) * 4 + iVar4 * 0x800)) * 0x20 |
                               ((uVar17 >> 0xb) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                         (uint)(uVar17 >> 0xb)) * 4 + iVar4 * 0x800)) * 0x800 |
                               (uVar17 & 0x1f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                         (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                          puVar7 = (uint *)((int)local_18 + 2);
                          local_8 = local_8 + -1;
                          if (local_8 == 0) goto LAB_006fff58;
                          param_3 = (int *)((int)param_3 + -0x10000);
                          local_18 = puVar7;
                        } while (0 < (int)param_3);
                      }
                      do {
                        local_c = (uint *)((int)local_c + local_2c);
                        param_3 = (int *)((int)param_3 + local_34);
                      } while ((int)param_3 < 1);
                    } while( true );
                  }
                  if (param_4 == 0) {
                    local_8 = local_44;
                    local_18 = local_1c;
                    local_c = local_10;
                    param_3 = (int *)local_40;
                    while( true ) {
                      while( true ) {
                        uVar17 = (ushort)*local_c;
                        uVar10 = (ushort)*local_18;
                        uVar2 = (uint)uVar10;
                        *(ushort *)local_18 =
                             (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] -
                                      (uVar10 >> 5 & 0x3f)) * (uint)*(byte *)((int)local_c + 2) *
                                      DAT_00dca3f8 + (uVar2 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                             (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] -
                                      (uint)(uVar10 >> 0xb)) * (uint)*(byte *)((int)local_c + 2) *
                                      DAT_00dca3f8 + (uVar2 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                             (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] -
                                      (uVar2 & 0x1f)) * (uint)*(byte *)((int)local_c + 2) *
                                      DAT_00dca3f8 + uVar2 * 0x10000 >> 0x10) & 0x1f;
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                            param_3 = (int *)((int)param_3 + local_34)) {
                          local_c = (uint *)((int)local_c + local_2c);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_14 = local_14 + local_38;
                          local_10 = (uint *)((int)local_10 + local_3c);
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                      if (local_24 == 0) break;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      local_18 = local_1c;
                      local_c = local_10;
                    }
                    return;
                  }
                  iVar5 = DAT_00dca3f8;
LAB_006ffa75:
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  local_18 = local_1c;
                  do {
                    if (*(byte *)((int)local_c + 2) == 0) {
                      do {
                        puVar7 = (uint *)((int)puVar7 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006ffc7a;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
LAB_006ffc60:
                      puVar7 = local_18;
                    }
                    else {
                      if (*(byte *)((int)local_c + 2) == 0xff) {
                        do {
                          uVar17 = (ushort)*puVar7;
                          uVar10 = (ushort)*local_c;
                          *(ushort *)local_18 =
                               ((uVar17 >> 5 & 0x3f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                         (uVar17 >> 5 & 0x3f)) * 4 + iVar4 * 0x800)) * 0x20 |
                               ((uVar17 >> 0xb) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                         (uint)(uVar17 >> 0xb)) * 4 + iVar4 * 0x800)) * 0x800 |
                               (uVar17 & 0x1f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                         (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                          puVar7 = (uint *)((int)local_18 + 2);
                          local_8 = local_8 + -1;
                          if (local_8 == 0) goto LAB_006ffc75;
                          param_3 = (int *)((int)param_3 + -0x10000);
                          local_18 = puVar7;
                        } while (0 < (int)param_3);
                        iVar5 = DAT_00dca3f8;
                        goto LAB_006ffc60;
                      }
                      do {
                        uVar17 = (ushort)*puVar7;
                        uVar2 = (uint)uVar17;
                        uVar10 = (ushort)*local_c;
                        *(ushort *)local_18 =
                             (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                      (uVar17 >> 5 & 0x3f)) * (uint)*(byte *)((int)local_c + 2) *
                                      iVar5 + (uVar2 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                             (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                      (uint)(uVar17 >> 0xb)) * (uint)*(byte *)((int)local_c + 2) *
                                      iVar5 + (uVar2 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                             (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                      (uVar2 & 0x1f)) * (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                      uVar2 * 0x10000 >> 0x10) & 0x1f;
                        puVar7 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006ffc75;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        iVar5 = DAT_00dca3f8;
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      local_c = (uint *)((int)local_c + local_2c);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                if (*(int *)(param_2 + 0x2c) != 1) {
                  if (param_4 == 0) {
                    do {
                      local_c = local_10;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      local_18 = local_1c;
                      while( true ) {
                        uVar17 = (ushort)*local_18;
                        uVar10 = (ushort)*local_c;
                        *(ushort *)local_18 =
                             ((uVar17 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar10 >> 5 & 0x3f) - (uVar17 >> 5 & 0x3f)) * 4 +
                                       iVar4 * 0x800)) * 0x20 |
                             ((uVar17 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uint)(uVar10 >> 0xb) - (uint)(uVar17 >> 0xb)) * 4 +
                                       iVar4 * 0x800)) * 0x800 |
                             (uVar17 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar10 & 0x1f) - (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        if ((int)param_3 < 1) {
                          do {
                            param_3 = (int *)((int)param_3 + local_34);
                            local_c = (uint *)((int)local_c + local_2c);
                          } while ((int)param_3 < 1);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_14 = local_14 + local_38;
                          local_10 = (uint *)((int)local_10 + local_3c);
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_006ff820:
                  local_c = local_10;
                  local_8 = local_44;
                  puVar7 = local_1c;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                  do {
                    if ((ushort)*local_c == uVar2) {
                      do {
                        puVar7 = (uint *)((int)puVar7 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006ff904;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        uVar17 = (ushort)*local_c;
                        uVar10 = (ushort)*puVar7;
                        *(ushort *)local_18 =
                             ((uVar10 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar17 >> 5 & 0x3f) - (uVar10 >> 5 & 0x3f)) * 4 +
                                       iVar4 * 0x800)) * 0x20 |
                             ((uVar10 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uint)(uVar17 >> 0xb) - (uint)(uVar10 >> 0xb)) * 4 +
                                       iVar4 * 0x800)) * 0x800 |
                             (uVar10 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar17 & 0x1f) - (uVar10 & 0x1f)) * 4 + iVar4 * 0x800);
                        puVar7 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006ff904;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      local_c = (uint *)((int)local_c + local_2c);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                if (param_4 == 0) {
                  do {
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_18 = local_1c;
                    while( true ) {
                      uVar3 = (uint)(ushort)*local_18;
                      uVar2 = (uint)(ushort)*local_c;
                      *(ushort *)local_18 =
                           (ushort)(((uVar2 & 0xf800) - (uVar3 & 0xf800)) *
                                    (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                    (uVar3 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                           (ushort)(((uVar2 & 0x7e0) - (uVar3 & 0x7e0)) *
                                    (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                    (uVar3 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                           (ushort)(((uVar2 & 0x1f) - (uVar3 & 0x1f)) *
                                    (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                    (uVar3 & 0x1f) * 0x10000 >> 0x10);
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
                iVar5 = DAT_00dca3f8;
LAB_006ff4b0:
                local_c = local_10;
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                local_18 = local_1c;
                do {
                  if (*(byte *)((int)local_c + 2) == 0) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006ff66a;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                    local_18 = puVar7;
                  }
                  else if (*(byte *)((int)local_c + 2) == 0xff) {
                    do {
                      uVar17 = (ushort)*puVar7;
                      uVar10 = (ushort)*local_c;
                      puVar7 = (uint *)((int)local_18 + 2);
                      *(ushort *)local_18 =
                           ((uVar17 >> 5 & 0x3f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((uVar10 >> 5 & 0x3f) - (uVar17 >> 5 & 0x3f)) * 4 +
                                     iVar4 * 0x800)) * 0x20 |
                           ((uVar17 >> 0xb) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((uint)(uVar10 >> 0xb) - (uint)(uVar17 >> 0xb)) * 4 +
                                     iVar4 * 0x800)) * 0x800 |
                           (uVar17 & 0x1f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((uVar10 & 0x1f) - (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006ff665;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                    iVar5 = DAT_00dca3f8;
                  }
                  else {
                    do {
                      uVar3 = (uint)(ushort)*puVar7;
                      uVar2 = (uint)(ushort)*local_c;
                      *(ushort *)local_18 =
                           (ushort)(((uVar2 & 0xf800) - (uVar3 & 0xf800)) *
                                    (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                    (uVar3 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                           (ushort)(((uVar2 & 0x7e0) - (uVar3 & 0x7e0)) *
                                    (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                    (uVar3 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                           (ushort)(((uVar2 & 0x1f) - (uVar3 & 0x1f)) *
                                    (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                    (uVar3 & 0x1f) * 0x10000 >> 0x10);
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006ff665;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (*(int *)(param_2 + 0x2c) != 1) {
                  local_18 = local_1c;
                  local_c = local_10;
                  iVar5 = DAT_00dca3f8;
                  if (param_4 == 0) {
                    local_20 = local_28;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    while( true ) {
                      while( true ) {
                        uVar17 = (ushort)*local_18;
                        uVar8 = (uint)uVar17;
                        uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                        uVar10 = (ushort)*local_c;
                        *(ushort *)local_18 =
                             (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                      (uVar17 >> 5 & 0x3f)) * uVar2 * DAT_00dca3f8 +
                                      (uVar8 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                             (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                      (uint)(uVar17 >> 0xb)) * uVar2 * DAT_00dca3f8 +
                                      (uVar8 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                             (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                      (uVar8 & 0x1f)) * uVar2 * DAT_00dca3f8 + uVar8 * 0x10000 >>
                                     0x10) & 0x1f;
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        if ((int)param_3 < 1) {
                          do {
                            param_3 = (int *)((int)param_3 + local_34);
                            local_c = (uint *)((int)local_c + local_2c);
                            local_20 = local_20 + local_58;
                          } while ((int)param_3 < 1);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_14 = local_14 + local_38;
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_28 = local_28 + local_5c;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                      if (local_24 == 0) break;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      local_20 = local_28;
                      local_18 = local_1c;
                      local_c = local_10;
                    }
                    return;
                  }
LAB_006ff160:
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  local_20 = local_28;
                  local_18 = local_1c;
                  local_c = local_10;
                  do {
                    if ((ushort)*local_c == uVar2) {
                      do {
                        puVar7 = (uint *)((int)puVar7 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006ff2a3;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        uVar17 = (ushort)*puVar7;
                        uVar14 = (uint)uVar17;
                        uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                        uVar10 = (ushort)*local_c;
                        *(ushort *)local_18 =
                             (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                      (uVar17 >> 5 & 0x3f)) * uVar8 * iVar5 +
                                      (uVar14 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                             (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                      (uint)(uVar17 >> 0xb)) * uVar8 * iVar5 +
                                      (uVar14 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                             (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                      (uVar14 & 0x1f)) * uVar8 * iVar5 + uVar14 * 0x10000 >> 0x10) &
                             0x1f;
                        puVar7 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        iVar5 = DAT_00dca3f8;
                        if (local_8 == 0) goto LAB_006ff2a3;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    do {
                      local_c = (uint *)((int)local_c + local_2c);
                      local_20 = local_20 + local_58;
                      param_3 = (int *)((int)param_3 + local_34);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                local_20 = local_28;
                if (param_4 == 0) {
                  local_8 = local_44;
                  local_18 = local_1c;
                  local_c = local_10;
                  param_3 = (int *)local_40;
                  while( true ) {
                    while( true ) {
                      uVar17 = (ushort)*local_18;
                      uVar2 = (uint)uVar17;
                      uVar10 = (ushort)*local_c;
                      uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      *(ushort *)local_18 =
                           (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                    (uVar17 >> 5 & 0x3f)) * uVar8 *
                                    (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                    (uVar2 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                           (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                    (uint)(uVar17 >> 0xb)) * uVar8 *
                                    (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                    (uVar2 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                           (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                  (uVar2 & 0x1f)) * uVar8 * (uint)*(byte *)((int)local_c + 2) *
                                  DAT_00dca3f8 + uVar2 * 0x1000000 >> 0x18) & 0x1f;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                          local_20 = local_20 + local_58;
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_20 = local_28;
                    local_18 = local_1c;
                    local_c = local_10;
                  }
                  return;
                }
                iVar5 = DAT_00dca3f8;
LAB_006fed00:
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                local_20 = local_28;
                local_18 = local_1c;
                local_c = local_10;
                do {
                  if (*(byte *)((int)local_c + 2) == 0) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006fef46;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else if (*(byte *)((int)local_c + 2) == 0xff) {
                    do {
                      uVar17 = (ushort)*puVar7;
                      uVar2 = (uint)uVar17;
                      uVar10 = (ushort)*local_c;
                      uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      *(ushort *)local_18 =
                           (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                    (uVar17 >> 5 & 0x3f)) * uVar8 * iVar5 +
                                    (uVar2 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                           (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                    (uint)(uVar17 >> 0xb)) * uVar8 * iVar5 +
                                    (uVar2 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                           (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                    (uVar2 & 0x1f)) * uVar8 * iVar5 + uVar2 * 0x10000 >> 0x10) &
                           0x1f;
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006fef3e;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar17 = (ushort)*local_c;
                      uVar10 = (ushort)*puVar7;
                      uVar2 = (uint)uVar10;
                      uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      *(ushort *)local_18 =
                           (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] -
                                    (uVar10 >> 5 & 0x3f)) * uVar8 *
                                    (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                    (uVar2 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                           (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] -
                                    (uint)(uVar10 >> 0xb)) * uVar8 *
                                    (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                    (uVar2 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                           (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] -
                                  (uVar2 & 0x1f)) * uVar8 * (uint)*(byte *)((int)local_c + 2) *
                                  iVar5 + uVar2 * 0x1000000 >> 0x18) & 0x1f;
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006fef3e;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_20 = local_20 + local_58;
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              local_18 = local_1c;
              if (*(int *)(param_2 + 0x2c) != 1) {
                local_c = local_10;
                if (param_4 == 0) {
                  local_8 = local_44;
                  local_20 = local_28;
                  param_3 = (int *)local_40;
                  while( true ) {
                    while( true ) {
                      uVar3 = (uint)(ushort)*local_18;
                      uVar2 = (uint)(ushort)*local_c;
                      uVar11 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      *(ushort *)local_18 =
                           (ushort)(((uVar2 & 0x7e0) - (uVar3 & 0x7e0)) * uVar11 * DAT_00dca3f8 +
                                    (uVar3 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                           (ushort)(((uVar2 & 0xf800) - (uVar3 & 0xf800)) * uVar11 * DAT_00dca3f8 +
                                    (uVar3 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                           (ushort)(((uVar2 & 0x1f) - (uVar3 & 0x1f)) * uVar11 * DAT_00dca3f8 +
                                    (uVar3 & 0x1f) * 0x10000 >> 0x10);
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                        local_20 = local_20 + local_58;
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_20 = local_28;
                    local_18 = local_1c;
                    local_c = local_10;
                  }
                  return;
                }
                iVar5 = DAT_00dca3f8;
LAB_006fe9e5:
                local_20 = local_28;
                local_c = local_10;
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                local_18 = local_1c;
                do {
                  if ((ushort)*local_c == uVar2) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006feb08;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar11 = (uint)(ushort)*puVar7;
                      uVar3 = (uint)(ushort)*local_c;
                      uVar18 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      *(ushort *)local_18 =
                           (ushort)(((uVar3 & 0x7e0) - (uVar11 & 0x7e0)) * uVar18 * iVar5 +
                                    (uVar11 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                           (ushort)(((uVar3 & 0xf800) - (uVar11 & 0xf800)) * uVar18 * iVar5 +
                                    (uVar11 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                           (ushort)(((uVar3 & 0x1f) - (uVar11 & 0x1f)) * uVar18 * iVar5 +
                                    (uVar11 & 0x1f) * 0x10000 >> 0x10);
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      iVar5 = DAT_00dca3f8;
                      if (local_8 == 0) goto LAB_006feb08;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                    local_20 = local_20 + local_58;
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (param_4 == 0) {
                local_8 = local_44;
                local_c = local_10;
                local_20 = local_28;
                param_3 = (int *)local_40;
                while( true ) {
                  while( true ) {
                    uVar17 = (ushort)*local_c;
                    uVar10 = (ushort)*local_18;
                    uVar2 = (uint)uVar10;
                    uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    *(ushort *)local_18 =
                         (ushort)(((uVar17 >> 5 & 0x3f) - (uVar10 >> 5 & 0x3f)) * uVar3 *
                                  (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                  (uVar2 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                         (ushort)(((uint)(uVar17 >> 0xb) - (uint)(uVar10 >> 0xb)) * uVar3 *
                                  (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                  (uVar2 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                         (ushort)(byte)(((uVar17 & 0x1f) - (uVar2 & 0x1f)) * uVar3 *
                                        (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                        (uVar2 & 0x1f) * 0x1000000 >> 0x18);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_c = (uint *)((int)local_c + local_2c);
                      local_20 = local_20 + local_58;
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                  if (local_24 == 0) break;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_20 = local_28;
                  local_18 = local_1c;
                  local_c = local_10;
                }
                return;
              }
              local_20 = local_28;
              iVar5 = DAT_00dca3f8;
              puVar7 = local_10;
LAB_006fe5e0:
              local_28 = local_20;
              local_8 = local_44;
              param_3 = (int *)local_40;
              local_18 = local_1c;
              local_c = puVar7;
              do {
                if (*(byte *)((int)local_c + 2) == 0) {
                  do {
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fe7f3;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else if (*(byte *)((int)local_c + 2) == 0xff) {
                  do {
                    uVar3 = (uint)(ushort)*local_18;
                    uVar2 = (uint)(ushort)*local_c;
                    uVar11 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    *(ushort *)local_18 =
                         (ushort)(((uVar2 & 0x7e0) - (uVar3 & 0x7e0)) * uVar11 * iVar5 +
                                  (uVar3 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                         (ushort)(((uVar2 & 0xf800) - (uVar3 & 0xf800)) * uVar11 * iVar5 +
                                  (uVar3 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                         (ushort)(((uVar2 & 0x1f) - (uVar3 & 0x1f)) * uVar11 * iVar5 +
                                  (uVar3 & 0x1f) * 0x10000 >> 0x10);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fe7eb;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar17 = (ushort)*local_c;
                    uVar10 = (ushort)*local_18;
                    uVar2 = (uint)uVar10;
                    uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    *(ushort *)local_18 =
                         (ushort)(((uVar17 >> 5 & 0x3f) - (uVar10 >> 5 & 0x3f)) * uVar3 *
                                  (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                  (uVar2 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                         (ushort)(((uint)(uVar17 >> 0xb) - (uint)(uVar10 >> 0xb)) * uVar3 *
                                  (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                  (uVar2 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                         (ushort)(byte)(((uVar17 & 0x1f) - (uVar2 & 0x1f)) * uVar3 *
                                        (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                        (uVar2 & 0x1f) * 0x1000000 >> 0x18);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006fe7eb;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                } while ((int)param_3 < 1);
                puVar7 = local_10;
              } while( true );
            }
            break;
          case 2:
            if (DAT_00dca3f8 != 0) {
              if (param_5 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  local_18 = local_1c;
                  if (*(int *)(param_2 + 0x2c) != 1) {
                    if (param_4 == 0) {
                      do {
                        puVar7 = local_18;
                        local_c = local_10;
                        local_8 = local_44;
                        param_3 = (int *)local_40;
                        while( true ) {
                          uVar17 = (ushort)*local_c;
                          uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                              iVar4 * 0x100 +
                                              (&DAT_00d0a2e0)
                                              [uVar18 * 0x100 + (uint)(uVar17 >> 0xb)]) * 0x40 +
                                   *(short *)(&DAT_00d0a2e0 +
                                             iVar4 * 0x100 +
                                             (&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)]))
                                   * 0x20 + *(short *)(&DAT_00d0a2e0 +
                                                      iVar4 * 0x100 +
                                                      (&DAT_00d0a2e0)
                                                      [uVar11 * 0x100 + (uVar17 & 0x1f)]);
                          uVar2 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                          uVar8 = uVar2 & 0x8210820;
                          *(ushort *)local_18 =
                               (short)uVar8 - (short)(uVar8 >> 5) |
                               (uVar17 | (ushort)*local_18) & 0x820 | (ushort)uVar2;
                          local_18 = (uint *)((int)local_18 + 2);
                          local_8 = local_8 + -1;
                          if (local_8 == 0) break;
                          param_3 = (int *)((int)param_3 + -0x10000);
                          if ((int)param_3 < 1) {
                            do {
                              param_3 = (int *)((int)param_3 + local_34);
                              local_c = (uint *)((int)local_c + local_2c);
                            } while ((int)param_3 < 1);
                          }
                        }
                        local_18 = (uint *)((int)puVar7 + local_48);
                        local_14 = local_14 - 0x10000;
                        if ((int)local_14 < 1) {
                          do {
                            local_10 = (uint *)((int)local_10 + local_3c);
                            local_14 = local_14 + local_38;
                          } while ((int)local_14 < 1);
                        }
                        local_24 = local_24 + -1;
                      } while (local_24 != 0);
                      return;
                    }
LAB_007016a0:
                    puVar7 = local_18;
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    do {
                      if ((ushort)*local_c == uVar2) {
                        do {
                          local_18 = (uint *)((int)local_18 + 2);
                          local_8 = local_8 + -1;
                          if (local_8 == 0) goto LAB_0070178a;
                          param_3 = (int *)((int)param_3 + -0x10000);
                        } while (0 < (int)param_3);
                      }
                      else {
                        do {
                          uVar17 = (ushort)*local_c;
                          uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                              iVar4 * 0x100 +
                                              (&DAT_00d0a2e0)
                                              [uVar18 * 0x100 + (uint)(uVar17 >> 0xb)]) * 0x40 +
                                   *(short *)(&DAT_00d0a2e0 +
                                             iVar4 * 0x100 +
                                             (&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)]))
                                   * 0x20 + *(short *)(&DAT_00d0a2e0 +
                                                      iVar4 * 0x100 +
                                                      (&DAT_00d0a2e0)
                                                      [uVar11 * 0x100 + (uVar17 & 0x1f)]);
                          uVar8 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                          uVar14 = uVar8 & 0x8210820;
                          *(ushort *)local_18 =
                               (short)uVar14 - (short)(uVar14 >> 5) |
                               (uVar17 | (ushort)*local_18) & 0x820 | (ushort)uVar8;
                          local_18 = (uint *)((int)local_18 + 2);
                          local_8 = local_8 + -1;
                          if (local_8 == 0) goto LAB_0070178a;
                          param_3 = (int *)((int)param_3 + -0x10000);
                        } while (0 < (int)param_3);
                      }
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                      } while ((int)param_3 < 1);
                    } while( true );
                  }
                  if (param_4 == 0) {
                    do {
                      puVar7 = local_18;
                      local_c = local_10;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      while( true ) {
                        uVar2 = (uint)(ushort)*local_c;
                        uVar8 = (uint)*(byte *)((int)local_c + 2);
                        uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                            iVar4 * 0x100 +
                                            (&DAT_00d0a2e0)
                                            [uVar18 * 0x100 + ((uVar2 & 0xf800) * uVar8 >> 0x13)]) *
                                  0x40 + *(short *)(&DAT_00d0a2e0 +
                                                   iVar4 * 0x100 +
                                                   (&DAT_00d0a2e0)
                                                   [uVar3 * 0x100 + ((uVar2 & 0x7e0) * uVar8 >> 0xd)
                                                   ])) * 0x20 +
                                 *(short *)(&DAT_00d0a2e0 +
                                           iVar4 * 0x100 +
                                           (&DAT_00d0a2e0)
                                           [uVar11 * 0x100 + ((uVar2 & 0x1f) * uVar8 >> 8)]);
                        uVar2 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                        uVar8 = uVar2 & 0x8210820;
                        *(ushort *)local_18 =
                             (short)uVar8 - (short)(uVar8 >> 5) |
                             (uVar17 | (ushort)*local_18) & 0x820 | (ushort)uVar2;
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        if ((int)param_3 < 1) {
                          do {
                            param_3 = (int *)((int)param_3 + local_34);
                            local_c = (uint *)((int)local_c + local_2c);
                          } while ((int)param_3 < 1);
                        }
                      }
                      local_18 = (uint *)((int)puVar7 + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_14 = local_14 + local_38;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_00701375:
                  puVar7 = local_18;
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  do {
                    if (*(byte *)((int)local_c + 2) == 0) {
                      do {
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_00701519;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else if (*(byte *)((int)local_c + 2) == 0xff) {
                      do {
                        uVar17 = (ushort)*local_c;
                        uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                            iVar4 * 0x100 +
                                            (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)])
                                  * 0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar4 * 0x100 +
                                                     (&DAT_00d0a2e0)
                                                     [uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)])) * 0x20
                                 + *(short *)(&DAT_00d0a2e0 +
                                             iVar4 * 0x100 +
                                             (&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)]);
                        uVar2 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                        uVar8 = uVar2 & 0x8210820;
                        *(ushort *)local_18 =
                             (short)uVar8 - (short)(uVar8 >> 5) |
                             (uVar17 | (ushort)*local_18) & 0x820 | (ushort)uVar2;
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_00701519;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        uVar2 = (uint)(ushort)*local_c;
                        uVar8 = (uint)*(byte *)((int)local_c + 2);
                        uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                            iVar4 * 0x100 +
                                            (&DAT_00d0a2e0)
                                            [uVar18 * 0x100 + ((uVar2 & 0xf800) * uVar8 >> 0x13)]) *
                                  0x40 + *(short *)(&DAT_00d0a2e0 +
                                                   iVar4 * 0x100 +
                                                   (&DAT_00d0a2e0)
                                                   [uVar3 * 0x100 + ((uVar2 & 0x7e0) * uVar8 >> 0xd)
                                                   ])) * 0x20 +
                                 *(short *)(&DAT_00d0a2e0 +
                                           iVar4 * 0x100 +
                                           (&DAT_00d0a2e0)
                                           [uVar11 * 0x100 + ((uVar2 & 0x1f) * uVar8 >> 8)]);
                        uVar2 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                        uVar8 = uVar2 & 0x8210820;
                        *(ushort *)local_18 =
                             (short)uVar8 - (short)(uVar8 >> 5) |
                             (uVar17 | (ushort)*local_18) & 0x820 | (ushort)uVar2;
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_00701519;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      local_c = (uint *)((int)local_c + local_2c);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                if (*(int *)(param_2 + 0x2c) != 1) {
                  if (param_4 == 0) {
                    do {
                      local_c = local_10;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      local_18 = local_1c;
                      while( true ) {
                        uVar17 = (ushort)*local_c;
                        uVar17 = (*(short *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)(uVar17 >> 0xb))
                                  * 0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar4 * 0x100 + (uVar17 >> 5 & 0x3f))) * 0x20 +
                                 *(short *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uVar17 & 0x1f));
                        uVar3 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                        uVar2 = uVar3 & 0x8210820;
                        *(ushort *)local_18 =
                             (short)uVar2 - (short)(uVar2 >> 5) |
                             (uVar17 | (ushort)*local_18) & 0x820 | (ushort)uVar3;
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        if ((int)param_3 < 1) {
                          do {
                            param_3 = (int *)((int)param_3 + local_34);
                            local_c = (uint *)((int)local_c + local_2c);
                          } while ((int)param_3 < 1);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_14 = local_14 + local_38;
                          local_10 = (uint *)((int)local_10 + local_3c);
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_00701130:
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  local_18 = local_1c;
                  do {
                    if ((ushort)*local_c == uVar2) {
                      do {
                        puVar7 = (uint *)((int)puVar7 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_00701204;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        uVar17 = (ushort)*local_c;
                        uVar17 = (*(short *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)(uVar17 >> 0xb))
                                  * 0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar4 * 0x100 + (uVar17 >> 5 & 0x3f))) * 0x20 +
                                 *(short *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uVar17 & 0x1f));
                        uVar11 = ((ushort)*puVar7 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                        uVar3 = uVar11 & 0x8210820;
                        *(ushort *)local_18 =
                             (short)uVar3 - (short)(uVar3 >> 5) | (uVar17 | (ushort)*puVar7) & 0x820
                             | (ushort)uVar11;
                        puVar7 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_00701204;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      local_c = (uint *)((int)local_c + local_2c);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                if (param_4 == 0) {
                  do {
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_18 = local_1c;
                    while( true ) {
                      uVar2 = (uint)(ushort)*local_c;
                      uVar3 = (uint)*(byte *)((int)local_c + 2);
                      uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                          iVar4 * 0x100 + ((uVar2 & 0xf800) * uVar3 >> 0x13)) * 0x40
                               + *(short *)(&DAT_00d0a2e0 +
                                           iVar4 * 0x100 + ((uVar2 & 0x7e0) * uVar3 >> 0xd))) * 0x20
                               + *(short *)(&DAT_00d0a2e0 +
                                           iVar4 * 0x100 + ((uVar2 & 0x1f) * uVar3 >> 8));
                      uVar3 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                      uVar2 = uVar3 & 0x8210820;
                      *(ushort *)local_18 =
                           (short)uVar2 - (short)(uVar2 >> 5) | (uVar17 | (ushort)*local_18) & 0x820
                           | (ushort)uVar3;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_00700e40:
                local_c = local_10;
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                do {
                  if (*(byte *)((int)local_c + 2) == 0) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00700fb9;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else if (*(byte *)((int)local_c + 2) == 0xff) {
                    do {
                      uVar17 = (ushort)*local_c;
                      uVar17 = (*(short *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)(uVar17 >> 0xb)) *
                                0x40 + *(short *)(&DAT_00d0a2e0 +
                                                 iVar4 * 0x100 + (uVar17 >> 5 & 0x3f))) * 0x20 +
                               *(short *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uVar17 & 0x1f));
                      uVar3 = ((ushort)*puVar7 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                      uVar2 = uVar3 & 0x8210820;
                      *(ushort *)puVar7 =
                           (short)uVar2 - (short)(uVar2 >> 5) | (uVar17 | (ushort)*puVar7) & 0x820 |
                           (ushort)uVar3;
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00700fb9;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar2 = (uint)(ushort)*local_c;
                      uVar3 = (uint)*(byte *)((int)local_c + 2);
                      uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                          iVar4 * 0x100 + ((uVar2 & 0xf800) * uVar3 >> 0x13)) * 0x40
                               + *(short *)(&DAT_00d0a2e0 +
                                           iVar4 * 0x100 + ((uVar2 & 0x7e0) * uVar3 >> 0xd))) * 0x20
                               + *(short *)(&DAT_00d0a2e0 +
                                           iVar4 * 0x100 + ((uVar2 & 0x1f) * uVar3 >> 8));
                      uVar3 = ((ushort)*puVar7 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                      uVar2 = uVar3 & 0x8210820;
                      *(ushort *)puVar7 =
                           (short)uVar2 - (short)(uVar2 >> 5) | (uVar17 | (ushort)*puVar7) & 0x820 |
                           (ushort)uVar3;
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00700fb9;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                local_18 = local_1c;
                if (*(int *)(param_2 + 0x2c) != 1) {
                  local_20 = local_28;
                  if (param_4 == 0) {
                    do {
                      puVar7 = local_18;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      local_20 = local_28;
                      local_c = local_10;
                      while( true ) {
                        uVar17 = (ushort)*local_c;
                        uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                        uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                            iVar4 * 0x100 +
                                            ((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)]
                                             * uVar2 >> 8)) * 0x40 +
                                 *(short *)(&DAT_00d0a2e0 +
                                           iVar4 * 0x100 +
                                           ((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] *
                                            uVar2 >> 8))) * 0x20 +
                                 *(short *)(&DAT_00d0a2e0 +
                                           iVar4 * 0x100 +
                                           ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] *
                                            uVar2 >> 8));
                        uVar2 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                        uVar8 = uVar2 & 0x8210820;
                        *(ushort *)local_18 =
                             (short)uVar8 - (short)(uVar8 >> 5) |
                             (uVar17 | (ushort)*local_18) & 0x820 | (ushort)uVar2;
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        if ((int)param_3 < 1) {
                          do {
                            local_20 = local_20 + local_58;
                            param_3 = (int *)((int)param_3 + local_34);
                            local_c = (uint *)((int)local_c + local_2c);
                          } while ((int)param_3 < 1);
                        }
                      }
                      local_18 = (uint *)((int)puVar7 + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_14 = local_14 + local_38;
                          local_28 = local_28 + local_5c;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_00700b50:
                  puVar7 = local_18;
                  local_28 = local_20;
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  do {
                    if ((ushort)*local_c == uVar2) {
                      do {
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_00700c7e;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        uVar17 = (ushort)*local_c;
                        uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                        uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                            iVar4 * 0x100 +
                                            ((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)]
                                             * uVar8 >> 8)) * 0x40 +
                                 *(short *)(&DAT_00d0a2e0 +
                                           iVar4 * 0x100 +
                                           ((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] *
                                            uVar8 >> 8))) * 0x20 +
                                 *(short *)(&DAT_00d0a2e0 +
                                           iVar4 * 0x100 +
                                           ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] *
                                            uVar8 >> 8));
                        uVar8 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                        uVar14 = uVar8 & 0x8210820;
                        *(ushort *)local_18 =
                             (short)uVar14 - (short)(uVar14 >> 5) |
                             (uVar17 | (ushort)*local_18) & 0x820 | (ushort)uVar8;
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_00700c7e;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    do {
                      local_20 = local_20 + local_58;
                      param_3 = (int *)((int)param_3 + local_34);
                      local_c = (uint *)((int)local_c + local_2c);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                local_20 = local_28;
                if (param_4 == 0) {
                  do {
                    puVar7 = local_18;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_20 = local_28;
                    local_c = local_10;
                    while( true ) {
                      uVar17 = (ushort)*local_c;
                      uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                          iVar4 * 0x100 +
                                          ((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] *
                                           uVar2 * (uint)*(byte *)((int)local_c + 2) >> 0x10)) *
                                0x40 + *(short *)(&DAT_00d0a2e0 +
                                                 iVar4 * 0x100 +
                                                 ((&DAT_00d0a2e0)
                                                  [uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] * uVar2 *
                                                  (uint)*(byte *)((int)local_c + 2) >> 0x10))) *
                               0x20 + *(short *)(&DAT_00d0a2e0 +
                                                iVar4 * 0x100 +
                                                ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] *
                                                 uVar2 * (uint)*(byte *)((int)local_c + 2) >> 0x10))
                      ;
                      uVar2 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                      uVar8 = uVar2 & 0x8210820;
                      *(ushort *)local_18 =
                           (short)uVar8 - (short)(uVar8 >> 5) | (uVar17 | (ushort)*local_18) & 0x820
                           | (ushort)uVar2;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          local_20 = local_20 + local_58;
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_18 = (uint *)((int)puVar7 + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_00700766:
                puVar7 = local_18;
                local_28 = local_20;
                local_c = local_10;
                local_8 = local_44;
                param_3 = (int *)local_40;
                do {
                  if (*(byte *)((int)local_c + 2) == 0) {
                    do {
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00700978;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else if (*(byte *)((int)local_c + 2) == 0xff) {
                    do {
                      uVar17 = (ushort)*local_c;
                      uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                          iVar4 * 0x100 +
                                          ((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] *
                                           uVar2 >> 8)) * 0x40 +
                               *(short *)(&DAT_00d0a2e0 +
                                         iVar4 * 0x100 +
                                         ((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] *
                                          uVar2 >> 8))) * 0x20 +
                               *(short *)(&DAT_00d0a2e0 +
                                         iVar4 * 0x100 +
                                         ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] * uVar2
                                         >> 8));
                      uVar2 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                      uVar8 = uVar2 & 0x8210820;
                      *(ushort *)local_18 =
                           (short)uVar8 - (short)(uVar8 >> 5) | (uVar17 | (ushort)*local_18) & 0x820
                           | (ushort)uVar2;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00700978;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar17 = (ushort)*local_c;
                      uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                          iVar4 * 0x100 +
                                          ((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] *
                                           uVar2 * (uint)*(byte *)((int)local_c + 2) >> 0x10)) *
                                0x40 + *(short *)(&DAT_00d0a2e0 +
                                                 iVar4 * 0x100 +
                                                 ((&DAT_00d0a2e0)
                                                  [uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] * uVar2 *
                                                  (uint)*(byte *)((int)local_c + 2) >> 0x10))) *
                               0x20 + *(short *)(&DAT_00d0a2e0 +
                                                iVar4 * 0x100 +
                                                ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] *
                                                 uVar2 * (uint)*(byte *)((int)local_c + 2) >> 0x10))
                      ;
                      uVar2 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                      uVar8 = uVar2 & 0x8210820;
                      *(ushort *)local_18 =
                           (short)uVar8 - (short)(uVar8 >> 5) | (uVar17 | (ushort)*local_18) & 0x820
                           | (ushort)uVar2;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00700978;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                    local_20 = local_20 + local_58;
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (*(int *)(param_2 + 0x2c) != 1) {
                if (param_4 == 0) {
                  do {
                    local_20 = local_28;
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_18 = local_1c;
                    while( true ) {
                      uVar2 = (uint)(ushort)*local_c;
                      uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                          iVar4 * 0x100 + ((uVar2 & 0xf800) * uVar3 >> 0x13)) * 0x40
                               + *(short *)(&DAT_00d0a2e0 +
                                           iVar4 * 0x100 + ((uVar2 & 0x7e0) * uVar3 >> 0xd))) * 0x20
                               + *(short *)(&DAT_00d0a2e0 +
                                           iVar4 * 0x100 + ((uVar2 & 0x1f) * uVar3 >> 8));
                      uVar3 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                      uVar2 = uVar3 & 0x8210820;
                      *(ushort *)local_18 =
                           (short)uVar2 - (short)(uVar2 >> 5) | (uVar17 | (ushort)*local_18) & 0x820
                           | (ushort)uVar3;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                          local_20 = local_20 + local_58;
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_007004b0:
                local_c = local_10;
                local_20 = local_28;
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                local_18 = local_1c;
                do {
                  if ((ushort)*local_c == uVar2) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_007005b8;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar3 = (uint)(ushort)*local_c;
                      uVar11 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                          iVar4 * 0x100 + ((uVar3 & 0xf800) * uVar11 >> 0x13)) *
                                0x40 + *(short *)(&DAT_00d0a2e0 +
                                                 iVar4 * 0x100 + ((uVar3 & 0x7e0) * uVar11 >> 0xd)))
                               * 0x20 + *(short *)(&DAT_00d0a2e0 +
                                                  iVar4 * 0x100 + ((uVar3 & 0x1f) * uVar11 >> 8));
                      uVar11 = ((ushort)*puVar7 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                      uVar3 = uVar11 & 0x8210820;
                      *(ushort *)local_18 =
                           (short)uVar3 - (short)(uVar3 >> 5) | (uVar17 | (ushort)*puVar7) & 0x820 |
                           (ushort)uVar11;
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_007005b8;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                    local_20 = local_20 + local_58;
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (param_4 == 0) {
                local_18 = local_1c;
                do {
                  puVar7 = local_18;
                  local_c = local_10;
                  local_20 = local_28;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  while( true ) {
                    uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar2 = (uint)(ushort)*local_c;
                    uVar11 = (uint)*(byte *)((int)local_c + 2);
                    uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                        iVar4 * 0x100 + ((uVar2 & 0xf800) * uVar3 * uVar11 >> 0x1b))
                              * 0x40 + *(short *)(&DAT_00d0a2e0 +
                                                 iVar4 * 0x100 +
                                                 ((uVar2 & 0x7e0) * uVar3 * uVar11 >> 0x15))) * 0x20
                             + *(short *)(&DAT_00d0a2e0 +
                                         iVar4 * 0x100 + ((uVar2 & 0x1f) * uVar3 * uVar11 >> 0x10));
                    uVar3 = ((ushort)*local_18 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                    uVar2 = uVar3 & 0x8210820;
                    *(ushort *)local_18 =
                         (short)uVar2 - (short)(uVar2 >> 5) | (uVar17 | (ushort)*local_18) & 0x820 |
                         (ushort)uVar3;
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                        local_20 = local_20 + local_58;
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_18 = (uint *)((int)puVar7 + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
              local_20 = local_28;
LAB_00700117:
              local_28 = local_20;
              local_c = local_10;
              local_8 = local_44;
              param_3 = (int *)local_40;
              puVar7 = local_1c;
              do {
                if (*(byte *)((int)local_c + 2) == 0) {
                  do {
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_007002e8;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else if (*(byte *)((int)local_c + 2) == 0xff) {
                  do {
                    uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar2 = (uint)(ushort)*local_c;
                    uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                        iVar4 * 0x100 + ((uVar2 & 0xf800) * uVar3 >> 0x13)) * 0x40 +
                             *(short *)(&DAT_00d0a2e0 +
                                       iVar4 * 0x100 + ((uVar2 & 0x7e0) * uVar3 >> 0xd))) * 0x20 +
                             *(short *)(&DAT_00d0a2e0 +
                                       iVar4 * 0x100 + ((uVar2 & 0x1f) * uVar3 >> 8));
                    uVar3 = ((ushort)*puVar7 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                    uVar2 = uVar3 & 0x8210820;
                    *(ushort *)puVar7 =
                         (short)uVar2 - (short)(uVar2 >> 5) | (uVar17 | (ushort)*puVar7) & 0x820 |
                         (ushort)uVar3;
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_007002e8;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar2 = (uint)(ushort)*local_c;
                    uVar17 = (*(short *)(&DAT_00d0a2e0 +
                                        iVar4 * 0x100 +
                                        ((uVar2 & 0xf800) * uVar3 *
                                         (uint)*(byte *)((int)local_c + 2) >> 0x1b)) * 0x40 +
                             *(short *)(&DAT_00d0a2e0 +
                                       iVar4 * 0x100 +
                                       ((uVar2 & 0x7e0) * uVar3 * (uint)*(byte *)((int)local_c + 2)
                                       >> 0x15))) * 0x20 +
                             *(short *)(&DAT_00d0a2e0 +
                                       iVar4 * 0x100 +
                                       ((uVar2 & 0x1f) * uVar3 * (uint)*(byte *)((int)local_c + 2)
                                       >> 0x10));
                    uVar3 = ((ushort)*puVar7 & 0xf7def7df) + (uVar17 & 0xf7def7df);
                    uVar2 = uVar3 & 0x8210820;
                    *(ushort *)puVar7 =
                         (short)uVar2 - (short)(uVar2 >> 5) | (uVar17 | (ushort)*puVar7) & 0x820 |
                         (ushort)uVar3;
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_007002e8;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                } while ((int)param_3 < 1);
              } while( true );
            }
            break;
          case 3:
            if (DAT_00dca3f8 != 0) {
              if (param_5 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  local_18 = local_1c;
                  if (*(int *)(param_2 + 0x2c) != 1) {
                    if (param_4 == 0) {
                      do {
                        puVar7 = local_18;
                        local_c = local_10;
                        local_8 = local_44;
                        param_3 = (int *)local_40;
                        while( true ) {
                          uVar17 = (ushort)*local_c;
                          uVar8 = ((ushort)*local_18 | 0x8210820) -
                                  ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                       iVar4 * 0x100 +
                                                       (&DAT_00d0a2e0)
                                                       [uVar18 * 0x100 + (uint)(uVar17 >> 0xb)]) *
                                             0x40 + *(short *)(&DAT_00d0a2e0 +
                                                              iVar4 * 0x100 +
                                                              (&DAT_00d0a2e0)
                                                              [uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)]
                                                              )) * 0x20 +
                                           *(short *)(&DAT_00d0a2e0 +
                                                     iVar4 * 0x100 +
                                                     (&DAT_00d0a2e0)
                                                     [uVar11 * 0x100 + (uVar17 & 0x1f)])) &
                                  0xf7def7df);
                          uVar2 = uVar8 & 0x8210820;
                          *(ushort *)local_18 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar8;
                          local_18 = (uint *)((int)local_18 + 2);
                          local_8 = local_8 + -1;
                          if (local_8 == 0) break;
                          param_3 = (int *)((int)param_3 + -0x10000);
                          if ((int)param_3 < 1) {
                            do {
                              param_3 = (int *)((int)param_3 + local_34);
                              local_c = (uint *)((int)local_c + local_2c);
                            } while ((int)param_3 < 1);
                          }
                        }
                        local_18 = (uint *)((int)puVar7 + local_48);
                        local_14 = local_14 - 0x10000;
                        if ((int)local_14 < 1) {
                          do {
                            local_10 = (uint *)((int)local_10 + local_3c);
                            local_14 = local_14 + local_38;
                          } while ((int)local_14 < 1);
                        }
                        local_24 = local_24 + -1;
                      } while (local_24 != 0);
                      return;
                    }
LAB_00702e56:
                    puVar7 = local_18;
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    do {
                      if ((ushort)*local_c == uVar2) {
                        do {
                          local_18 = (uint *)((int)local_18 + 2);
                          local_8 = local_8 + -1;
                          if (local_8 == 0) goto LAB_00702f29;
                          param_3 = (int *)((int)param_3 + -0x10000);
                        } while (0 < (int)param_3);
                      }
                      else {
                        do {
                          uVar17 = (ushort)*local_c;
                          uVar14 = ((ushort)*local_18 | 0x8210820) -
                                   ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                        iVar4 * 0x100 +
                                                        (&DAT_00d0a2e0)
                                                        [uVar18 * 0x100 + (uint)(uVar17 >> 0xb)]) *
                                              0x40 + *(short *)(&DAT_00d0a2e0 +
                                                               iVar4 * 0x100 +
                                                               (&DAT_00d0a2e0)
                                                               [uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)
                                                               ])) * 0x20 +
                                            *(short *)(&DAT_00d0a2e0 +
                                                      iVar4 * 0x100 +
                                                      (&DAT_00d0a2e0)
                                                      [uVar11 * 0x100 + (uVar17 & 0x1f)])) &
                                   0xf7def7df);
                          uVar8 = uVar14 & 0x8210820;
                          *(ushort *)local_18 = (short)uVar8 - (short)(uVar8 >> 5) & (ushort)uVar14;
                          local_18 = (uint *)((int)local_18 + 2);
                          local_8 = local_8 + -1;
                          if (local_8 == 0) goto LAB_00702f29;
                          param_3 = (int *)((int)param_3 + -0x10000);
                        } while (0 < (int)param_3);
                      }
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                      } while ((int)param_3 < 1);
                    } while( true );
                  }
                  if (param_4 == 0) {
                    do {
                      puVar7 = local_18;
                      local_c = local_10;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      while( true ) {
                        uVar2 = (uint)(ushort)*local_c;
                        uVar8 = (uint)*(byte *)((int)local_c + 2);
                        uVar8 = ((ushort)*local_18 | 0x8210820) -
                                ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                     iVar4 * 0x100 +
                                                     (&DAT_00d0a2e0)
                                                     [uVar18 * 0x100 +
                                                      ((uVar2 & 0xf800) * uVar8 >> 0x13)]) * 0x40 +
                                          *(short *)(&DAT_00d0a2e0 +
                                                    iVar4 * 0x100 +
                                                    (&DAT_00d0a2e0)
                                                    [uVar3 * 0x100 +
                                                     ((uVar2 & 0x7e0) * uVar8 >> 0xd)])) * 0x20 +
                                         *(short *)(&DAT_00d0a2e0 +
                                                   iVar4 * 0x100 +
                                                   (&DAT_00d0a2e0)
                                                   [uVar11 * 0x100 + ((uVar2 & 0x1f) * uVar8 >> 8)])
                                         ) & 0xf7def7df);
                        uVar2 = uVar8 & 0x8210820;
                        *(ushort *)local_18 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar8;
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        if ((int)param_3 < 1) {
                          do {
                            param_3 = (int *)((int)param_3 + local_34);
                            local_c = (uint *)((int)local_c + local_2c);
                          } while ((int)param_3 < 1);
                        }
                      }
                      local_18 = (uint *)((int)puVar7 + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_14 = local_14 + local_38;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_00702b64:
                  puVar7 = local_18;
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  do {
                    if (*(byte *)((int)local_c + 2) == 0) {
                      do {
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_00702ce9;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else if (*(byte *)((int)local_c + 2) == 0xff) {
                      do {
                        uVar17 = (ushort)*local_c;
                        uVar8 = ((ushort)*local_18 | 0x8210820) -
                                ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                     iVar4 * 0x100 +
                                                     (&DAT_00d0a2e0)
                                                     [uVar18 * 0x100 + (uint)(uVar17 >> 0xb)]) *
                                           0x40 + *(short *)(&DAT_00d0a2e0 +
                                                            iVar4 * 0x100 +
                                                            (&DAT_00d0a2e0)
                                                            [uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)]))
                                          * 0x20 + *(short *)(&DAT_00d0a2e0 +
                                                             iVar4 * 0x100 +
                                                             (&DAT_00d0a2e0)
                                                             [uVar11 * 0x100 + (uVar17 & 0x1f)])) &
                                0xf7def7df);
                        uVar2 = uVar8 & 0x8210820;
                        *(ushort *)local_18 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar8;
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_00702ce9;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        uVar2 = (uint)(ushort)*local_c;
                        uVar8 = (uint)*(byte *)((int)local_c + 2);
                        uVar8 = ((ushort)*local_18 | 0x8210820) -
                                ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                     iVar4 * 0x100 +
                                                     (&DAT_00d0a2e0)
                                                     [uVar18 * 0x100 +
                                                      ((uVar2 & 0xf800) * uVar8 >> 0x13)]) * 0x40 +
                                          *(short *)(&DAT_00d0a2e0 +
                                                    iVar4 * 0x100 +
                                                    (&DAT_00d0a2e0)
                                                    [uVar3 * 0x100 +
                                                     ((uVar2 & 0x7e0) * uVar8 >> 0xd)])) * 0x20 +
                                         *(short *)(&DAT_00d0a2e0 +
                                                   iVar4 * 0x100 +
                                                   (&DAT_00d0a2e0)
                                                   [uVar11 * 0x100 + ((uVar2 & 0x1f) * uVar8 >> 8)])
                                         ) & 0xf7def7df);
                        uVar2 = uVar8 & 0x8210820;
                        *(ushort *)local_18 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar8;
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_00702ce9;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      local_c = (uint *)((int)local_c + local_2c);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                uVar3 = 0;
                if (*(int *)(param_2 + 0x2c) != 1) {
                  if (param_4 == 0) {
                    if (DAT_00dca3f8 == 0xff) {
                      uVar2 = 0;
                      do {
                        local_8 = local_44;
                        iVar6 = local_40;
                        puVar7 = local_10;
                        while( true ) {
                          uVar3 = (CONCAT22((short)(uVar3 >> 0x10),(ushort)*local_1c) | 0x8210820) -
                                  (CONCAT22((short)(uVar2 >> 0x10),(ushort)*puVar7) & 0xf7def7df);
                          uVar2 = uVar3 & 0x8210820;
                          uVar2 = uVar2 - (uVar2 >> 5);
                          uVar3 = uVar3 & uVar2;
                          *(ushort *)local_1c = (ushort)uVar3;
                          local_1c = (uint *)((int)local_1c + 2);
                          local_8 = local_8 + -1;
                          if (local_8 == 0) break;
                          iVar4 = iVar6 + -0x10000;
                          bVar20 = iVar6 < 0x10000;
                          iVar6 = iVar4;
                          if (iVar4 == 0 || bVar20) {
                            do {
                              puVar7 = (uint *)((int)puVar7 + local_2c);
                              bVar20 = SCARRY4(iVar4,local_34);
                              iVar4 = iVar4 + local_34;
                              iVar6 = iVar4;
                            } while (bVar20 != iVar4 < 0);
                          }
                        }
                        local_1c = (uint *)((int)local_1c + iVar5);
                        uVar2 = local_14 - 0x10000;
                        if (local_14 < 0x10000 || uVar2 == 0) {
                          do {
                            local_10 = (uint *)((int)local_10 + local_3c);
                            bVar20 = SCARRY4(uVar2,local_38);
                            uVar2 = uVar2 + local_38;
                          } while (bVar20 != (int)uVar2 < 0);
                        }
                        local_24 = local_24 + -1;
                        local_14 = uVar2;
                      } while (local_24 != 0);
                      return;
                    }
                    do {
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      puVar7 = local_1c;
                      puVar9 = local_10;
LAB_00702a7b:
                      puVar16 = puVar7;
                      while( true ) {
                        uVar17 = (ushort)*puVar9;
                        puVar7 = (uint *)((int)puVar16 + 2);
                        uVar3 = ((ushort)*puVar16 | 0x8210820) -
                                ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                     iVar4 * 0x100 + (uint)(uVar17 >> 0xb)) * 0x40 +
                                          *(short *)(&DAT_00d0a2e0 +
                                                    iVar4 * 0x100 + (uVar17 >> 5 & 0x3f))) * 0x20 +
                                         *(short *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uVar17 & 0x1f))
                                         ) & 0xf7def7df);
                        uVar2 = uVar3 & 0x8210820;
                        *(ushort *)puVar16 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar3;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        puVar16 = puVar7;
                        if ((int)param_3 < 1) goto LAB_00702af1;
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_14 = local_14 + local_38;
                          local_10 = (uint *)((int)local_10 + local_3c);
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                      if (local_24 == 0) {
                        return;
                      }
                    } while( true );
                  }
                  if (DAT_00dca3f8 == 0xff) {
                    do {
                      local_8 = local_44;
                      iVar6 = local_40;
                      puVar7 = local_10;
                      while( true ) {
                        if ((ushort)*puVar7 != local_50) {
                          uVar3 = (CONCAT22((short)(uVar3 >> 0x10),(ushort)*local_1c) | 0x8210820) -
                                  ((ushort)*puVar7 & 0xf7def7df);
                          uVar2 = uVar3 & 0x8210820;
                          uVar3 = uVar3 & uVar2 - (uVar2 >> 5);
                          *(ushort *)local_1c = (ushort)uVar3;
                        }
                        local_1c = (uint *)((int)local_1c + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        iVar4 = iVar6 + -0x10000;
                        bVar20 = iVar6 < 0x10000;
                        iVar6 = iVar4;
                        if (iVar4 == 0 || bVar20) {
                          do {
                            puVar7 = (uint *)((int)puVar7 + local_2c);
                            bVar20 = SCARRY4(iVar4,local_34);
                            iVar4 = iVar4 + local_34;
                            iVar6 = iVar4;
                          } while (bVar20 != iVar4 < 0);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + iVar5);
                      bVar20 = local_14 < 0x10000;
                      local_14 = local_14 - 0x10000;
                      if (bVar20 || local_14 == 0) {
                        do {
                          local_10 = (uint *)((int)local_10 + local_3c);
                          bVar20 = SCARRY4(local_14,local_38);
                          local_14 = local_14 + local_38;
                        } while (bVar20 != (int)local_14 < 0);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_007028e0:
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  puVar9 = local_10;
                  do {
                    puVar16 = puVar7;
                    if ((ushort)*puVar9 == uVar2) {
                      do {
                        puVar7 = (uint *)((int)puVar7 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_00702997;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        uVar17 = (ushort)*puVar9;
                        puVar7 = (uint *)((int)puVar16 + 2);
                        uVar11 = ((ushort)*puVar16 | 0x8210820) -
                                 ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                      iVar4 * 0x100 + (uint)(uVar17 >> 0xb)) * 0x40
                                           + *(short *)(&DAT_00d0a2e0 +
                                                       iVar4 * 0x100 + (uVar17 >> 5 & 0x3f))) * 0x20
                                          + *(short *)(&DAT_00d0a2e0 +
                                                      iVar4 * 0x100 + (uVar17 & 0x1f))) & 0xf7def7df
                                 );
                        uVar3 = uVar11 & 0x8210820;
                        *(ushort *)puVar16 = (short)uVar3 - (short)(uVar3 >> 5) & (ushort)uVar11;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_00702997;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        puVar16 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      puVar9 = (uint *)((int)puVar9 + local_2c);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                if (param_4 == 0) {
                  do {
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    puVar7 = local_1c;
LAB_0070273b:
                    puVar9 = puVar7;
                    while( true ) {
                      uVar2 = (uint)(ushort)*local_c;
                      uVar3 = (uint)*(byte *)((int)local_c + 2);
                      puVar7 = (uint *)((int)puVar9 + 2);
                      uVar3 = ((ushort)*puVar9 | 0x8210820) -
                              ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                   iVar4 * 0x100 +
                                                   ((uVar2 & 0xf800) * uVar3 >> 0x13)) * 0x40 +
                                        *(short *)(&DAT_00d0a2e0 +
                                                  iVar4 * 0x100 + ((uVar2 & 0x7e0) * uVar3 >> 0xd)))
                                        * 0x20 + *(short *)(&DAT_00d0a2e0 +
                                                           iVar4 * 0x100 +
                                                           ((uVar2 & 0x1f) * uVar3 >> 8))) &
                              0xf7def7df);
                      uVar2 = uVar3 & 0x8210820;
                      *(ushort *)puVar9 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar3;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      puVar9 = puVar7;
                      if ((int)param_3 < 1) goto LAB_007027d0;
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) {
                      return;
                    }
                  } while( true );
                }
LAB_00702592:
                local_c = local_10;
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                do {
                  if (*(byte *)((int)local_c + 2) == 0) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_007026e7;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    puVar9 = puVar7;
                    if (*(byte *)((int)local_c + 2) == 0xff) {
                      do {
                        uVar17 = (ushort)*local_c;
                        puVar7 = (uint *)((int)puVar9 + 2);
                        uVar3 = ((ushort)*puVar9 | 0x8210820) -
                                ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                     iVar4 * 0x100 + (uint)(uVar17 >> 0xb)) * 0x40 +
                                          *(short *)(&DAT_00d0a2e0 +
                                                    iVar4 * 0x100 + (uVar17 >> 5 & 0x3f))) * 0x20 +
                                         *(short *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uVar17 & 0x1f))
                                         ) & 0xf7def7df);
                        uVar2 = uVar3 & 0x8210820;
                        *(ushort *)puVar9 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar3;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_007026e7;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        puVar9 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        uVar2 = (uint)(ushort)*local_c;
                        uVar3 = (uint)*(byte *)((int)local_c + 2);
                        uVar3 = ((ushort)*puVar7 | 0x8210820) -
                                ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                     iVar4 * 0x100 +
                                                     ((uVar2 & 0xf800) * uVar3 >> 0x13)) * 0x40 +
                                          *(short *)(&DAT_00d0a2e0 +
                                                    iVar4 * 0x100 + ((uVar2 & 0x7e0) * uVar3 >> 0xd)
                                                    )) * 0x20 +
                                         *(short *)(&DAT_00d0a2e0 +
                                                   iVar4 * 0x100 + ((uVar2 & 0x1f) * uVar3 >> 8))) &
                                0xf7def7df);
                        uVar2 = uVar3 & 0x8210820;
                        *(ushort *)puVar7 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar3;
                        puVar7 = (uint *)((int)puVar7 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_007026e7;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                local_18 = local_1c;
                if (*(int *)(param_2 + 0x2c) != 1) {
                  if (param_4 == 0) {
                    do {
                      puVar7 = local_18;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      local_20 = local_28;
                      local_c = local_10;
                      while( true ) {
                        uVar17 = (ushort)*local_c;
                        uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                        uVar8 = ((ushort)*local_18 | 0x8210820) -
                                ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                     iVar4 * 0x100 +
                                                     ((&DAT_00d0a2e0)
                                                      [uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] *
                                                      uVar2 >> 8)) * 0x40 +
                                          *(short *)(&DAT_00d0a2e0 +
                                                    iVar4 * 0x100 +
                                                    ((&DAT_00d0a2e0)
                                                     [uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] * uVar2
                                                    >> 8))) * 0x20 +
                                         *(short *)(&DAT_00d0a2e0 +
                                                   iVar4 * 0x100 +
                                                   ((&DAT_00d0a2e0)
                                                    [uVar11 * 0x100 + (uVar17 & 0x1f)] * uVar2 >> 8)
                                                   )) & 0xf7def7df);
                        uVar2 = uVar8 & 0x8210820;
                        *(ushort *)local_18 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar8;
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        if ((int)param_3 < 1) {
                          do {
                            local_20 = local_20 + local_58;
                            param_3 = (int *)((int)param_3 + local_34);
                            local_c = (uint *)((int)local_c + local_2c);
                          } while ((int)param_3 < 1);
                        }
                      }
                      local_18 = (uint *)((int)puVar7 + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_14 = local_14 + local_38;
                          local_28 = local_28 + local_5c;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
                  local_20 = local_28;
                  puVar7 = local_10;
                  do {
                    puVar9 = local_18;
                    local_28 = local_20;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_c = puVar7;
                    while ((ushort)*local_c == uVar2) {
                      do {
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_007023be;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
LAB_007023a0:
                      do {
                        local_c = (uint *)((int)local_c + local_2c);
                        param_3 = (int *)((int)param_3 + local_34);
                        local_20 = local_20 + local_58;
                      } while ((int)param_3 < 1);
                      puVar7 = local_10;
                    }
                    while( true ) {
                      uVar17 = (ushort)*local_c;
                      uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar14 = ((ushort)*local_18 | 0x8210820) -
                               ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                    iVar4 * 0x100 +
                                                    ((&DAT_00d0a2e0)
                                                     [uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] *
                                                     uVar8 >> 8)) * 0x40 +
                                         *(short *)(&DAT_00d0a2e0 +
                                                   iVar4 * 0x100 +
                                                   ((&DAT_00d0a2e0)
                                                    [uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] * uVar8
                                                   >> 8))) * 0x20 +
                                        *(short *)(&DAT_00d0a2e0 +
                                                  iVar4 * 0x100 +
                                                  ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)]
                                                   * uVar8 >> 8))) & 0xf7def7df);
                      uVar8 = uVar14 & 0x8210820;
                      *(ushort *)local_18 = (short)uVar8 - (short)(uVar8 >> 5) & (ushort)uVar14;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) goto LAB_007023a0;
                    }
                    puVar7 = local_10;
LAB_007023be:
                    local_18 = (uint *)((int)puVar9 + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        puVar7 = (uint *)((int)puVar7 + local_3c);
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                      local_10 = puVar7;
                    }
                    local_24 = local_24 + -1;
                    local_20 = local_28;
                    if (local_24 == 0) {
                      return;
                    }
                  } while( true );
                }
                local_20 = local_28;
                if (param_4 == 0) {
                  do {
                    puVar7 = local_18;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_20 = local_28;
                    local_c = local_10;
                    while( true ) {
                      uVar17 = (ushort)*local_c;
                      uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar8 = ((ushort)*local_18 | 0x8210820) -
                              ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                   iVar4 * 0x100 +
                                                   ((&DAT_00d0a2e0)
                                                    [uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] * uVar2
                                                    * (uint)*(byte *)((int)local_c + 2) >> 0x10)) *
                                         0x40 + *(short *)(&DAT_00d0a2e0 +
                                                          iVar4 * 0x100 +
                                                          ((&DAT_00d0a2e0)
                                                           [uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] *
                                                           uVar2 * (uint)*(byte *)((int)local_c + 2)
                                                          >> 0x10))) * 0x20 +
                                       *(short *)(&DAT_00d0a2e0 +
                                                 iVar4 * 0x100 +
                                                 ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)]
                                                  * uVar2 * (uint)*(byte *)((int)local_c + 2) >>
                                                 0x10))) & 0xf7def7df);
                      uVar2 = uVar8 & 0x8210820;
                      *(ushort *)local_18 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar8;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          local_20 = local_20 + local_58;
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_18 = (uint *)((int)puVar7 + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_00701f07:
                puVar7 = local_18;
                local_28 = local_20;
                local_c = local_10;
                local_8 = local_44;
                param_3 = (int *)local_40;
                do {
                  if (*(byte *)((int)local_c + 2) == 0) {
                    do {
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_007020e8;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else if (*(byte *)((int)local_c + 2) == 0xff) {
                    do {
                      uVar17 = (ushort)*local_c;
                      uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar8 = ((ushort)*local_18 | 0x8210820) -
                              ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                   iVar4 * 0x100 +
                                                   ((&DAT_00d0a2e0)
                                                    [uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] * uVar2
                                                   >> 8)) * 0x40 +
                                        *(short *)(&DAT_00d0a2e0 +
                                                  iVar4 * 0x100 +
                                                  ((&DAT_00d0a2e0)
                                                   [uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] * uVar2 >>
                                                  8))) * 0x20 +
                                       *(short *)(&DAT_00d0a2e0 +
                                                 iVar4 * 0x100 +
                                                 ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)]
                                                  * uVar2 >> 8))) & 0xf7def7df);
                      uVar2 = uVar8 & 0x8210820;
                      *(ushort *)local_18 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar8;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_007020e8;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar17 = (ushort)*local_c;
                      uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar8 = ((ushort)*local_18 | 0x8210820) -
                              ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                   iVar4 * 0x100 +
                                                   ((&DAT_00d0a2e0)
                                                    [uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] * uVar2
                                                    * (uint)*(byte *)((int)local_c + 2) >> 0x10)) *
                                         0x40 + *(short *)(&DAT_00d0a2e0 +
                                                          iVar4 * 0x100 +
                                                          ((&DAT_00d0a2e0)
                                                           [uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] *
                                                           uVar2 * (uint)*(byte *)((int)local_c + 2)
                                                          >> 0x10))) * 0x20 +
                                       *(short *)(&DAT_00d0a2e0 +
                                                 iVar4 * 0x100 +
                                                 ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)]
                                                  * uVar2 * (uint)*(byte *)((int)local_c + 2) >>
                                                 0x10))) & 0xf7def7df);
                      uVar2 = uVar8 & 0x8210820;
                      *(ushort *)local_18 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar8;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_007020e8;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                    local_20 = local_20 + local_58;
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (*(int *)(param_2 + 0x2c) != 1) {
                if (param_4 == 0) {
                  do {
                    local_20 = local_28;
                    local_c = local_10;
                    local_8 = local_44;
                    puVar7 = local_1c;
                    param_3 = (int *)local_40;
LAB_00701ddf:
                    puVar9 = puVar7;
                    while( true ) {
                      uVar2 = (uint)(ushort)*local_c;
                      uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      puVar7 = (uint *)((int)puVar9 + 2);
                      uVar3 = ((ushort)*puVar9 | 0x8210820) -
                              ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                   iVar4 * 0x100 +
                                                   ((uVar2 & 0xf800) * uVar3 >> 0x13)) * 0x40 +
                                        *(short *)(&DAT_00d0a2e0 +
                                                  iVar4 * 0x100 + ((uVar2 & 0x7e0) * uVar3 >> 0xd)))
                                        * 0x20 + *(short *)(&DAT_00d0a2e0 +
                                                           iVar4 * 0x100 +
                                                           ((uVar2 & 0x1f) * uVar3 >> 8))) &
                              0xf7def7df);
                      uVar2 = uVar3 & 0x8210820;
                      *(ushort *)puVar9 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar3;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      puVar9 = puVar7;
                      if ((int)param_3 < 1) goto LAB_00701e76;
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) {
                      return;
                    }
                  } while( true );
                }
LAB_00701c90:
                local_c = local_10;
                local_20 = local_28;
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                do {
                  puVar9 = puVar7;
                  if ((ushort)*local_c == uVar2) {
                    do {
                      puVar9 = (uint *)((int)puVar9 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00701d7e;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar3 = (uint)(ushort)*local_c;
                      uVar11 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      puVar9 = (uint *)((int)puVar7 + 2);
                      uVar11 = ((ushort)*puVar7 | 0x8210820) -
                               ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                    iVar4 * 0x100 +
                                                    ((uVar3 & 0xf800) * uVar11 >> 0x13)) * 0x40 +
                                         *(short *)(&DAT_00d0a2e0 +
                                                   iVar4 * 0x100 + ((uVar3 & 0x7e0) * uVar11 >> 0xd)
                                                   )) * 0x20 +
                                        *(short *)(&DAT_00d0a2e0 +
                                                  iVar4 * 0x100 + ((uVar3 & 0x1f) * uVar11 >> 8))) &
                               0xf7def7df);
                      uVar3 = uVar11 & 0x8210820;
                      *(ushort *)puVar7 = (short)uVar3 - (short)(uVar3 >> 5) & (ushort)uVar11;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00701d7e;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      puVar7 = puVar9;
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                    local_20 = local_20 + local_58;
                  } while ((int)param_3 < 1);
                  puVar7 = puVar9;
                } while( true );
              }
              if (param_4 == 0) {
                local_18 = local_1c;
                do {
                  puVar7 = local_18;
                  local_c = local_10;
                  local_20 = local_28;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
LAB_00701b4b:
                  while( true ) {
                    uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar2 = (uint)(ushort)*local_c;
                    uVar11 = (uint)*(byte *)((int)local_c + 2);
                    puVar9 = (uint *)((int)local_18 + 2);
                    uVar3 = ((ushort)*local_18 | 0x8210820) -
                            ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                 iVar4 * 0x100 +
                                                 ((uVar2 & 0xf800) * uVar3 * uVar11 >> 0x1b)) * 0x40
                                      + *(short *)(&DAT_00d0a2e0 +
                                                  iVar4 * 0x100 +
                                                  ((uVar2 & 0x7e0) * uVar3 * uVar11 >> 0x15))) *
                                      0x20 + *(short *)(&DAT_00d0a2e0 +
                                                       iVar4 * 0x100 +
                                                       ((uVar2 & 0x1f) * uVar3 * uVar11 >> 0x10))) &
                            0xf7def7df);
                    uVar2 = uVar3 & 0x8210820;
                    *(ushort *)local_18 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar3;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar9;
                    if ((int)param_3 < 1) goto LAB_00701c00;
                  }
                  local_18 = (uint *)((int)puVar7 + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                  if (local_24 == 0) {
                    return;
                  }
                } while( true );
              }
              local_20 = local_28;
LAB_00701930:
              local_28 = local_20;
              local_c = local_10;
              local_8 = local_44;
              param_3 = (int *)local_40;
              puVar7 = local_1c;
              do {
                if (*(byte *)((int)local_c + 2) == 0) {
                  do {
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_00701ad8;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  puVar9 = puVar7;
                  if (*(byte *)((int)local_c + 2) == 0xff) {
                    do {
                      uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar2 = (uint)(ushort)*local_c;
                      puVar7 = (uint *)((int)puVar9 + 2);
                      uVar3 = ((ushort)*puVar9 | 0x8210820) -
                              ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                   iVar4 * 0x100 +
                                                   ((uVar2 & 0xf800) * uVar3 >> 0x13)) * 0x40 +
                                        *(short *)(&DAT_00d0a2e0 +
                                                  iVar4 * 0x100 + ((uVar2 & 0x7e0) * uVar3 >> 0xd)))
                                        * 0x20 + *(short *)(&DAT_00d0a2e0 +
                                                           iVar4 * 0x100 +
                                                           ((uVar2 & 0x1f) * uVar3 >> 8))) &
                              0xf7def7df);
                      uVar2 = uVar3 & 0x8210820;
                      *(ushort *)puVar9 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar3;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00701ad8;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      puVar9 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar2 = (uint)(ushort)*local_c;
                      puVar7 = (uint *)((int)puVar9 + 2);
                      uVar3 = ((ushort)*puVar9 | 0x8210820) -
                              ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                                   iVar4 * 0x100 +
                                                   ((uVar2 & 0xf800) * uVar3 *
                                                    (uint)*(byte *)((int)local_c + 2) >> 0x1b)) *
                                         0x40 + *(short *)(&DAT_00d0a2e0 +
                                                          iVar4 * 0x100 +
                                                          ((uVar2 & 0x7e0) * uVar3 *
                                                           (uint)*(byte *)((int)local_c + 2) >> 0x15
                                                          ))) * 0x20 +
                                       *(short *)(&DAT_00d0a2e0 +
                                                 iVar4 * 0x100 +
                                                 ((uVar2 & 0x1f) * uVar3 *
                                                  (uint)*(byte *)((int)local_c + 2) >> 0x10))) &
                              0xf7def7df);
                      uVar2 = uVar3 & 0x8210820;
                      *(ushort *)puVar9 = (short)uVar2 - (short)(uVar2 >> 5) & (ushort)uVar3;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00701ad8;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      puVar9 = puVar7;
                    } while (0 < (int)param_3);
                  }
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                } while ((int)param_3 < 1);
              } while( true );
            }
            break;
          case 4:
            if (param_5 == 0) {
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (*(int *)(param_2 + 0x2c) != 1) {
                  if (param_4 == 0) {
                    do {
                      local_c = local_10;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      local_18 = local_1c;
                      while( true ) {
                        uVar17 = (ushort)*local_18;
                        uVar10 = (ushort)*local_c;
                        *(ushort *)local_18 =
                             (ushort)((uVar17 >> 5 & 0x3f) *
                                      (&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] >> 1) &
                             0x7e0 | (uVar17 >> 5 & 0x7c0) *
                                     *(short *)(&DAT_00d0a2e0 +
                                               uVar18 * 0x100 + (uint)(uVar10 >> 0xb)) & 0xf800 |
                             (ushort)((uVar17 & 0x1f) *
                                      (&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] >> 5);
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        if ((int)param_3 < 1) {
                          do {
                            param_3 = (int *)((int)param_3 + local_34);
                            local_c = (uint *)((int)local_c + local_2c);
                          } while ((int)param_3 < 1);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_14 = local_14 + local_38;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_00704442:
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  local_18 = local_1c;
                  do {
                    if ((ushort)*local_c == uVar2) {
                      do {
                        puVar7 = (uint *)((int)puVar7 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_00704512;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                      local_18 = puVar7;
                    }
                    else {
                      do {
                        uVar17 = (ushort)*puVar7;
                        uVar10 = (ushort)*local_c;
                        *(ushort *)local_18 =
                             (ushort)((uVar17 >> 5 & 0x3f) *
                                      (&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] >> 1) &
                             0x7e0 | (uVar17 >> 5 & 0x7c0) *
                                     *(short *)(&DAT_00d0a2e0 +
                                               uVar18 * 0x100 + (uint)(uVar10 >> 0xb)) & 0xf800 |
                             (ushort)((uVar17 & 0x1f) *
                                      (&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] >> 5);
                        puVar7 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_00704512;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      local_c = (uint *)((int)local_c + local_2c);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                if (param_4 == 0) {
                  do {
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_18 = local_1c;
                    while( true ) {
                      uVar17 = (ushort)*local_c;
                      uVar10 = (ushort)*local_18;
                      *(ushort *)local_18 =
                           (ushort)((uVar10 >> 5 & 0x3f) *
                                    (&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] *
                                    (uint)*(byte *)((int)local_c + 2) >> 9) & 0x7e0 |
                           (ushort)((uint)(uVar10 >> 0xb) *
                                    (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] *
                                    (uint)*(byte *)((int)local_c + 2) >> 2) & 0xf800 |
                           (ushort)((uVar10 & 0x1f) *
                                    (&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] *
                                    (uint)*(byte *)((int)local_c + 2) >> 0xd);
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_00704160:
                local_c = local_10;
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                local_18 = local_1c;
                do {
                  if (*(byte *)((int)local_c + 2) == 0) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_007042d2;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else if (*(byte *)((int)local_c + 2) == 0xff) {
                    do {
                      uVar17 = (ushort)*puVar7;
                      uVar10 = (ushort)*local_c;
                      *(ushort *)local_18 =
                           (ushort)((uVar17 >> 5 & 0x3f) *
                                    (&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] >> 1) &
                           0x7e0 | (uVar17 >> 5 & 0x7c0) *
                                   *(short *)(&DAT_00d0a2e0 + uVar18 * 0x100 + (uint)(uVar10 >> 0xb)
                                             ) & 0xf800 |
                           (ushort)((uVar17 & 0x1f) *
                                    (&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] >> 5);
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_007042d2;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar17 = (ushort)*puVar7;
                      uVar10 = (ushort)*local_c;
                      *(ushort *)local_18 =
                           (ushort)((uVar17 >> 5 & 0x3f) *
                                    (&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] *
                                    (uint)*(byte *)((int)local_c + 2) >> 9) & 0x7e0 |
                           (ushort)((uint)(uVar17 >> 0xb) *
                                    (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] *
                                    (uint)*(byte *)((int)local_c + 2) >> 2) & 0xf800 |
                           (ushort)((uVar17 & 0x1f) *
                                    (&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] *
                                    (uint)*(byte *)((int)local_c + 2) >> 0xd);
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_007042d2;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (*(int *)(param_2 + 0x2c) != 1) {
                if (param_4 == 0) {
                  do {
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    puVar7 = local_1c;
                    while( true ) {
                      uVar3 = (uint)(ushort)*local_c;
                      uVar2 = (uint)(ushort)*puVar7;
                      *(ushort *)puVar7 =
                           (ushort)((uVar2 & 0xf800) * (uVar3 & 0xf800) >> 0x10) & 0xf800 |
                           (ushort)((uVar2 & 0x7e0) * (uVar3 & 0x7e0) >> 0xb) & 0x7e0 |
                           (ushort)((uVar2 & 0x1f) * (uVar3 & 0x1f) >> 5);
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_00703f40:
                local_c = local_10;
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                do {
                  if ((ushort)*local_c == uVar2) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00704006;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar3 = (uint)(ushort)*puVar7;
                      uVar11 = (uint)(ushort)*local_c;
                      *(ushort *)puVar7 =
                           (ushort)((uVar3 & 0xf800) * (uVar11 & 0xf800) >> 0x10) & 0xf800 |
                           (ushort)((uVar3 & 0x7e0) * (uVar11 & 0x7e0) >> 0xb) & 0x7e0 |
                           (ushort)((uVar3 & 0x1f) * (uVar11 & 0x1f) >> 5);
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00704006;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (param_4 == 0) {
                do {
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                  while( true ) {
                    uVar17 = (ushort)*local_18;
                    uVar10 = (ushort)*local_c;
                    uVar2 = (uint)*(byte *)((int)local_c + 2);
                    *(ushort *)local_18 =
                         (ushort)((int)((uVar17 >> 5 & 0x3f) * (uVar10 >> 5 & 0x3f) * uVar2) >> 9) &
                         0x7e0 | (ushort)((int)((uint)(uVar17 >> 0xb) * (uint)(uVar10 >> 0xb) *
                                               uVar2) >> 2) & 0xf800 |
                         (ushort)((int)((uVar17 & 0x1f) * (uVar10 & 0x1f) * uVar2) >> 0xd);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_00703c80:
              local_c = local_10;
              local_8 = local_44;
              param_3 = (int *)local_40;
              puVar7 = local_1c;
              do {
                if (*(byte *)((int)local_c + 2) == 0) {
                  do {
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_00703dc8;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else if (*(byte *)((int)local_c + 2) == 0xff) {
                  do {
                    uVar3 = (uint)(ushort)*local_c;
                    uVar2 = (uint)(ushort)*puVar7;
                    *(ushort *)puVar7 =
                         (ushort)((uVar2 & 0xf800) * (uVar3 & 0xf800) >> 0x10) & 0xf800 |
                         (ushort)((uVar2 & 0x7e0) * (uVar3 & 0x7e0) >> 0xb) & 0x7e0 |
                         (ushort)((uVar2 & 0x1f) * (uVar3 & 0x1f) >> 5);
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_00703dc8;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar17 = (ushort)*local_c;
                    uVar10 = (ushort)*puVar7;
                    *(ushort *)puVar7 =
                         (ushort)((int)((uVar10 >> 5 & 0x3f) * (uVar17 >> 5 & 0x3f) *
                                       (uint)*(byte *)((int)local_c + 2)) >> 9) & 0x7e0 |
                         (ushort)((int)((uint)(uVar10 >> 0xb) * (uint)(uVar17 >> 0xb) *
                                       (uint)*(byte *)((int)local_c + 2)) >> 2) & 0xf800 |
                         (ushort)((int)((uVar10 & 0x1f) * (uVar17 & 0x1f) *
                                       (uint)*(byte *)((int)local_c + 2)) >> 0xd);
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_00703dc8;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
              if (*(int *)(param_2 + 0x2c) != 1) {
                if (param_4 == 0) {
                  do {
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_20 = local_28;
                    local_18 = local_1c;
                    local_c = local_10;
                    while( true ) {
                      uVar17 = (ushort)*local_18;
                      uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar10 = (ushort)*local_c;
                      *(ushort *)local_18 =
                           (ushort)((uVar17 >> 5 & 0x3f) *
                                    (&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] * uVar2 >>
                                   9) & 0x7e0 |
                           (ushort)((uint)(uVar17 >> 0xb) *
                                    (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] * uVar2
                                   >> 2) & 0xf800 |
                           (ushort)((uVar17 & 0x1f) *
                                    (&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] * uVar2 >> 0xd
                                   );
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          local_20 = local_20 + local_58;
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
                local_20 = local_28;
                puVar7 = local_10;
                do {
                  local_28 = local_20;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar9 = local_1c;
                  local_18 = local_1c;
                  local_c = puVar7;
                  while ((ushort)*local_c == uVar2) {
                    do {
                      puVar9 = (uint *)((int)puVar9 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00703ace;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar9;
                    } while (0 < (int)param_3);
LAB_00703ab0:
                    do {
                      local_c = (uint *)((int)local_c + local_2c);
                      param_3 = (int *)((int)param_3 + local_34);
                      local_20 = local_20 + local_58;
                    } while ((int)param_3 < 1);
                    puVar7 = local_10;
                  }
                  while( true ) {
                    uVar17 = (ushort)*puVar9;
                    uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar10 = (ushort)*local_c;
                    *(ushort *)local_18 =
                         (ushort)((uVar17 >> 5 & 0x3f) *
                                  (&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] * uVar8 >> 9
                                 ) & 0x7e0 |
                         (ushort)((uint)(uVar17 >> 0xb) *
                                  (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] * uVar8 >>
                                 2) & 0xf800 |
                         (ushort)((uVar17 & 0x1f) *
                                  (&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] * uVar8 >> 0xd);
                    puVar9 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar9;
                    if ((int)param_3 < 1) goto LAB_00703ab0;
                  }
                  puVar7 = local_10;
LAB_00703ace:
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      puVar7 = (uint *)((int)puVar7 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                    local_10 = puVar7;
                  }
                  local_24 = local_24 + -1;
                  local_20 = local_28;
                  if (local_24 == 0) {
                    return;
                  }
                } while( true );
              }
              local_20 = local_28;
              if (param_4 == 0) {
                do {
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_20 = local_28;
                  local_18 = local_1c;
                  local_c = local_10;
                  while( true ) {
                    uVar17 = (ushort)*local_18;
                    uVar10 = (ushort)*local_c;
                    uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    *(ushort *)local_18 =
                         (ushort)((uVar17 >> 5 & 0x3f) *
                                  (&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] * uVar2 *
                                  (uint)*(byte *)((int)local_c + 2) >> 0x11) & 0x7e0 |
                         (ushort)((uint)(uVar17 >> 0xb) *
                                  (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] * uVar2 *
                                  (uint)*(byte *)((int)local_c + 2) >> 10) & 0xf800 |
                         (ushort)((uVar17 & 0x1f) *
                                  (&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] * uVar2 *
                                  (uint)*(byte *)((int)local_c + 2) >> 0x15);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        local_20 = local_20 + local_58;
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_14 = local_14 + local_38;
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_00703665:
              local_28 = local_20;
              local_c = local_10;
              local_8 = local_44;
              param_3 = (int *)local_40;
              local_18 = local_1c;
              do {
                if (*(byte *)((int)local_c + 2) == 0) {
                  do {
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_00703818;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else if (*(byte *)((int)local_c + 2) == 0xff) {
                  do {
                    uVar17 = (ushort)*local_c;
                    uVar10 = (ushort)*local_18;
                    uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    *(ushort *)local_18 =
                         (ushort)((uVar10 >> 5 & 0x3f) *
                                  (&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] * uVar2 >> 9
                                 ) & 0x7e0 |
                         (ushort)((uint)(uVar10 >> 0xb) *
                                  (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] * uVar2 >>
                                 2) & 0xf800 |
                         (ushort)((uVar10 & 0x1f) *
                                  (&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] * uVar2 >> 0xd);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_00703818;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar17 = (ushort)*local_18;
                    uVar10 = (ushort)*local_c;
                    uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    *(ushort *)local_18 =
                         (ushort)((uVar17 >> 5 & 0x3f) *
                                  (&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] * uVar2 *
                                  (uint)*(byte *)((int)local_c + 2) >> 0x11) & 0x7e0 |
                         (ushort)((uint)(uVar17 >> 0xb) *
                                  (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] * uVar2 *
                                  (uint)*(byte *)((int)local_c + 2) >> 10) & 0xf800 |
                         (ushort)((uVar17 & 0x1f) *
                                  (&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] * uVar2 *
                                  (uint)*(byte *)((int)local_c + 2) >> 0x15);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_00703818;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                } while ((int)param_3 < 1);
              } while( true );
            }
            if (*(int *)(param_2 + 0x2c) != 1) {
              if (param_4 == 0) {
                do {
                  local_20 = local_28;
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                  while( true ) {
                    uVar17 = (ushort)*local_18;
                    uVar10 = (ushort)*local_c;
                    uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    *(ushort *)local_18 =
                         (ushort)((int)((uVar17 >> 5 & 0x3f) * (uVar10 >> 5 & 0x3f) * uVar2) >> 9) &
                         0x7e0 | (ushort)((int)((uint)(uVar17 >> 0xb) * (uint)(uVar10 >> 0xb) *
                                               uVar2) >> 2) & 0xf800 |
                         (ushort)((int)((uVar17 & 0x1f) * (uVar10 & 0x1f) * uVar2) >> 0xd);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                        local_20 = local_20 + local_58;
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_007033f2:
              local_c = local_10;
              local_20 = local_28;
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              local_18 = local_1c;
              do {
                if ((ushort)*local_c == uVar2) {
                  do {
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_007034da;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                  local_18 = puVar7;
                }
                else {
                  do {
                    uVar17 = (ushort)*local_c;
                    uVar10 = (ushort)*puVar7;
                    uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    *(ushort *)local_18 =
                         (ushort)((int)((uVar10 >> 5 & 0x3f) * (uVar17 >> 5 & 0x3f) * uVar3) >> 9) &
                         0x7e0 | (ushort)((int)((uint)(uVar10 >> 0xb) * (uint)(uVar17 >> 0xb) *
                                               uVar3) >> 2) & 0xf800 |
                         (ushort)((int)((uVar10 & 0x1f) * (uVar17 & 0x1f) * uVar3) >> 0xd);
                    puVar7 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_007034da;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                } while ((int)param_3 < 1);
              } while( true );
            }
            local_20 = local_28;
            if (param_4 == 0) {
              do {
                local_c = local_10;
                local_20 = local_28;
                local_8 = local_44;
                param_3 = (int *)local_40;
                local_18 = local_1c;
                while( true ) {
                  uVar17 = (ushort)*local_18;
                  uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                  uVar10 = (ushort)*local_c;
                  *(ushort *)local_18 =
                       (ushort)((int)((uVar17 >> 5 & 0x3f) * (uVar10 >> 5 & 0x3f) * uVar2 *
                                     (uint)*(byte *)((int)local_c + 2)) >> 0x11) & 0x7e0 |
                       (ushort)((int)((uint)(uVar17 >> 0xb) * (uint)(uVar10 >> 0xb) * uVar2 *
                                     (uint)*(byte *)((int)local_c + 2)) >> 10) & 0xf800 |
                       (ushort)((int)((uVar17 & 0x1f) * (uVar10 & 0x1f) * uVar2 *
                                     (uint)*(byte *)((int)local_c + 2)) >> 0x15);
                  local_18 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) break;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  if ((int)param_3 < 1) {
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      local_c = (uint *)((int)local_c + local_2c);
                      local_20 = local_20 + local_58;
                    } while ((int)param_3 < 1);
                  }
                }
                local_1c = (uint *)((int)local_1c + local_48);
                local_14 = local_14 - 0x10000;
                if ((int)local_14 < 1) {
                  do {
                    local_14 = local_14 + local_38;
                    local_10 = (uint *)((int)local_10 + local_3c);
                    local_28 = local_28 + local_5c;
                  } while ((int)local_14 < 1);
                }
                local_24 = local_24 + -1;
              } while (local_24 != 0);
              return;
            }
LAB_007030c0:
            local_28 = local_20;
            local_c = local_10;
            local_8 = local_44;
            param_3 = (int *)local_40;
            puVar7 = local_1c;
            do {
              if (*(byte *)((int)local_c + 2) == 0) {
                do {
                  puVar7 = (uint *)((int)puVar7 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_00703258;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              else if (*(byte *)((int)local_c + 2) == 0xff) {
                do {
                  uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                  uVar17 = (ushort)*local_c;
                  uVar10 = (ushort)*puVar7;
                  *(ushort *)puVar7 =
                       (ushort)((int)((uVar10 >> 5 & 0x3f) * (uVar17 >> 5 & 0x3f) * uVar2) >> 9) &
                       0x7e0 | (ushort)((int)((uint)(uVar10 >> 0xb) * (uint)(uVar17 >> 0xb) * uVar2)
                                       >> 2) & 0xf800 |
                       (ushort)((int)((uVar10 & 0x1f) * (uVar17 & 0x1f) * uVar2) >> 0xd);
                  puVar7 = (uint *)((int)puVar7 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_00703258;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              else {
                do {
                  uVar17 = (ushort)*local_c;
                  uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                  uVar10 = (ushort)*puVar7;
                  *(ushort *)puVar7 =
                       (ushort)((int)((uVar10 >> 5 & 0x3f) * (uVar17 >> 5 & 0x3f) * uVar2 *
                                     (uint)*(byte *)((int)local_c + 2)) >> 0x11) & 0x7e0 |
                       (ushort)((int)((uint)(uVar10 >> 0xb) * (uint)(uVar17 >> 0xb) * uVar2 *
                                     (uint)*(byte *)((int)local_c + 2)) >> 10) & 0xf800 |
                       (ushort)((int)((uVar10 & 0x1f) * (uVar17 & 0x1f) * uVar2 *
                                     (uint)*(byte *)((int)local_c + 2)) >> 0x15);
                  puVar7 = (uint *)((int)puVar7 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_00703258;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              do {
                param_3 = (int *)((int)param_3 + local_34);
                local_c = (uint *)((int)local_c + local_2c);
                local_20 = local_20 + local_58;
              } while ((int)param_3 < 1);
            } while( true );
          case 10:
            if (param_5 != 0) {
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (*(int *)(param_2 + 0x2c) != 1) {
                  local_18 = local_1c;
                  local_c = local_10;
                  iVar5 = DAT_00dca3f8;
                  if (param_4 == 0) {
                    local_20 = local_28;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    while( true ) {
                      while( true ) {
                        uVar17 = (ushort)*local_18;
                        uVar8 = (uint)uVar17;
                        uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                        uVar10 = ~(ushort)*local_c;
                        *(ushort *)local_18 =
                             (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                      (uVar17 >> 5 & 0x3f)) * uVar2 * DAT_00dca3f8 +
                                      (uVar8 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                             (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                      (uint)(uVar17 >> 0xb)) * uVar2 * DAT_00dca3f8 +
                                      (uVar8 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                             (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                      (uVar8 & 0x1f)) * uVar2 * DAT_00dca3f8 + uVar8 * 0x10000 >>
                                     0x10) & 0x1f;
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        if ((int)param_3 < 1) {
                          do {
                            param_3 = (int *)((int)param_3 + local_34);
                            local_c = (uint *)((int)local_c + local_2c);
                            local_20 = local_20 + local_58;
                          } while ((int)param_3 < 1);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_14 = local_14 + local_38;
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_28 = local_28 + local_5c;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                      if (local_24 == 0) break;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      local_20 = local_28;
                      local_18 = local_1c;
                      local_c = local_10;
                    }
                    return;
                  }
LAB_00706f60:
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  local_20 = local_28;
                  local_18 = local_1c;
                  local_c = local_10;
                  do {
                    if ((ushort)*local_c == uVar2) {
                      do {
                        puVar7 = (uint *)((int)puVar7 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_007070a3;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        uVar17 = (ushort)*puVar7;
                        uVar14 = (uint)uVar17;
                        uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                        uVar10 = ~(ushort)*local_c;
                        *(ushort *)local_18 =
                             (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                      (uVar17 >> 5 & 0x3f)) * uVar8 * iVar5 +
                                      (uVar14 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                             (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                      (uint)(uVar17 >> 0xb)) * uVar8 * iVar5 +
                                      (uVar14 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                             (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                      (uVar14 & 0x1f)) * uVar8 * iVar5 + uVar14 * 0x10000 >> 0x10) &
                             0x1f;
                        puVar7 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        iVar5 = DAT_00dca3f8;
                        if (local_8 == 0) goto LAB_007070a3;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    do {
                      local_c = (uint *)((int)local_c + local_2c);
                      local_20 = local_20 + local_58;
                      param_3 = (int *)((int)param_3 + local_34);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                local_20 = local_28;
                if (param_4 == 0) {
                  local_8 = local_44;
                  local_18 = local_1c;
                  local_c = local_10;
                  param_3 = (int *)local_40;
                  while( true ) {
                    while( true ) {
                      uVar17 = (ushort)*local_18;
                      uVar2 = (uint)uVar17;
                      uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar10 = ~(ushort)*local_c;
                      *(ushort *)local_18 =
                           (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                    (uVar17 >> 5 & 0x3f)) * uVar8 *
                                    (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                    (uVar2 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                           (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                    (uint)(uVar17 >> 0xb)) * uVar8 *
                                    (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                    (uVar2 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                           (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                  (uVar2 & 0x1f)) * uVar8 * (uint)*(byte *)((int)local_c + 2) *
                                  DAT_00dca3f8 + uVar2 * 0x1000000 >> 0x18) & 0x1f;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                          local_20 = local_20 + local_58;
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_20 = local_28;
                    local_18 = local_1c;
                    local_c = local_10;
                  }
                  return;
                }
                iVar5 = DAT_00dca3f8;
LAB_00706af7:
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                local_20 = local_28;
                local_18 = local_1c;
                local_c = local_10;
                do {
                  if (*(byte *)((int)local_c + 2) == 0) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00706d3a;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else if (*(byte *)((int)local_c + 2) == 0xff) {
                    do {
                      uVar10 = ~(ushort)*local_c;
                      uVar17 = (ushort)*puVar7;
                      uVar2 = (uint)uVar17;
                      uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      *(ushort *)local_18 =
                           (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                    (uVar17 >> 5 & 0x3f)) * uVar8 * iVar5 +
                                    (uVar2 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                           (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                    (uint)(uVar17 >> 0xb)) * uVar8 * iVar5 +
                                    (uVar2 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                           (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                    (uVar2 & 0x1f)) * uVar8 * iVar5 + uVar2 * 0x10000 >> 0x10) &
                           0x1f;
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00706d32;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar10 = ~(ushort)*local_c;
                      uVar17 = (ushort)*puVar7;
                      uVar2 = (uint)uVar17;
                      uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      *(ushort *)local_18 =
                           (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                    (uVar17 >> 5 & 0x3f)) * uVar8 *
                                    (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                    (uVar2 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                           (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                    (uint)(uVar17 >> 0xb)) * uVar8 *
                                    (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                    (uVar2 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                           (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                  (uVar2 & 0x1f)) * uVar8 * (uint)*(byte *)((int)local_c + 2) *
                                  iVar5 + uVar2 * 0x1000000 >> 0x18) & 0x1f;
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00706d32;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_20 = local_20 + local_58;
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              local_18 = local_1c;
              if (*(int *)(param_2 + 0x2c) != 1) {
                local_c = local_10;
                if (param_4 == 0) {
                  local_8 = local_44;
                  local_20 = local_28;
                  param_3 = (int *)local_40;
                  while( true ) {
                    while( true ) {
                      uVar3 = (uint)(ushort)*local_18;
                      uVar11 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar2 = (uint)(ushort)~(ushort)*local_c;
                      *(ushort *)local_18 =
                           (ushort)(((uVar2 & 0xf800) - (uVar3 & 0xf800)) * uVar11 * DAT_00dca3f8 +
                                    (uVar3 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                           (ushort)(((uVar2 & 0x7e0) - (uVar3 & 0x7e0)) * uVar11 * DAT_00dca3f8 +
                                    (uVar3 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                           (ushort)(((uVar2 & 0x1f) - (uVar3 & 0x1f)) * uVar11 * DAT_00dca3f8 +
                                    (uVar3 & 0x1f) * 0x10000 >> 0x10);
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                        local_20 = local_20 + local_58;
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_20 = local_28;
                    local_18 = local_1c;
                    local_c = local_10;
                  }
                  return;
                }
                iVar5 = DAT_00dca3f8;
LAB_007067d7:
                local_20 = local_28;
                local_c = local_10;
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                local_18 = local_1c;
                do {
                  if ((ushort)*local_c == uVar2) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_007068f8;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar11 = (uint)(ushort)*puVar7;
                      uVar18 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar3 = (uint)(ushort)~(ushort)*local_c;
                      *(ushort *)local_18 =
                           (ushort)(((uVar3 & 0xf800) - (uVar11 & 0xf800)) * uVar18 * iVar5 +
                                    (uVar11 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                           (ushort)(((uVar3 & 0x7e0) - (uVar11 & 0x7e0)) * uVar18 * iVar5 +
                                    (uVar11 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                           (ushort)(((uVar3 & 0x1f) - (uVar11 & 0x1f)) * uVar18 * iVar5 +
                                    (uVar11 & 0x1f) * 0x10000 >> 0x10);
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      iVar5 = DAT_00dca3f8;
                      if (local_8 == 0) goto LAB_007068f8;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                    local_20 = local_20 + local_58;
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (param_4 == 0) {
                local_8 = local_44;
                local_c = local_10;
                local_20 = local_28;
                param_3 = (int *)local_40;
                while( true ) {
                  while( true ) {
                    uVar17 = (ushort)*local_18;
                    uVar2 = (uint)uVar17;
                    uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar10 = ~(ushort)*local_c;
                    *(ushort *)local_18 =
                         (ushort)(((uVar10 >> 5 & 0x3f) - (uVar17 >> 5 & 0x3f)) * uVar3 *
                                  (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                  (uVar2 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                         (ushort)(((uint)(uVar10 >> 0xb) - (uint)(uVar17 >> 0xb)) * uVar3 *
                                  (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                  (uVar2 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                         (ushort)(byte)(((uVar10 & 0x1f) - (uVar2 & 0x1f)) * uVar3 *
                                        (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                        (uVar2 & 0x1f) * 0x1000000 >> 0x18);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_c = (uint *)((int)local_c + local_2c);
                      local_20 = local_20 + local_58;
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                  if (local_24 == 0) break;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_20 = local_28;
                  local_18 = local_1c;
                  local_c = local_10;
                }
                return;
              }
              local_20 = local_28;
              iVar5 = DAT_00dca3f8;
              puVar7 = local_10;
LAB_007063c7:
              local_28 = local_20;
              local_8 = local_44;
              param_3 = (int *)local_40;
              local_18 = local_1c;
              local_c = puVar7;
              do {
                if (*(byte *)((int)local_c + 2) == 0) {
                  do {
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_007065d6;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else if (*(byte *)((int)local_c + 2) == 0xff) {
                  do {
                    uVar3 = (uint)(ushort)*local_18;
                    uVar11 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar2 = (uint)(ushort)~(ushort)*local_c;
                    *(ushort *)local_18 =
                         (ushort)(((uVar2 & 0xf800) - (uVar3 & 0xf800)) * uVar11 * iVar5 +
                                  (uVar3 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                         (ushort)(((uVar2 & 0x7e0) - (uVar3 & 0x7e0)) * uVar11 * iVar5 +
                                  (uVar3 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                         (ushort)(((uVar2 & 0x1f) - (uVar3 & 0x1f)) * uVar11 * iVar5 +
                                  (uVar3 & 0x1f) * 0x10000 >> 0x10);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_007065ce;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar17 = (ushort)*local_18;
                    uVar2 = (uint)uVar17;
                    uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar10 = ~(ushort)*local_c;
                    *(ushort *)local_18 =
                         (ushort)(((uVar10 >> 5 & 0x3f) - (uVar17 >> 5 & 0x3f)) * uVar3 *
                                  (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                  (uVar2 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                         (ushort)(((uint)(uVar10 >> 0xb) - (uint)(uVar17 >> 0xb)) * uVar3 *
                                  (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                  (uVar2 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                         (ushort)(byte)(((uVar10 & 0x1f) - (uVar2 & 0x1f)) * uVar3 *
                                        (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                        (uVar2 & 0x1f) * 0x1000000 >> 0x18);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_007065ce;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                } while ((int)param_3 < 1);
                puVar7 = local_10;
              } while( true );
            }
            if ((DAT_00dca3fc & 0xffffff) == 0xffffff) {
              if (*(int *)(param_2 + 0x2c) != 1) {
                if (param_4 == 0) {
                  do {
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_18 = local_1c;
                    while( true ) {
                      uVar17 = (ushort)*local_18;
                      uVar10 = ~(ushort)*local_c;
                      *(ushort *)local_18 =
                           ((uVar17 >> 5 & 0x3f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((uVar10 >> 5 & 0x3f) - (uVar17 >> 5 & 0x3f)) * 4 +
                                     iVar4 * 0x800)) * 0x20 |
                           ((uVar17 >> 0xb) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((uint)(uVar10 >> 0xb) - (uint)(uVar17 >> 0xb)) * 4 +
                                     iVar4 * 0x800)) * 0x800 |
                           (uVar17 & 0x1f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((uVar10 & 0x1f) - (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_00707650:
                local_c = local_10;
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                local_18 = local_1c;
                do {
                  if ((ushort)*local_c == uVar2) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00707744;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar17 = (ushort)*puVar7;
                      uVar10 = ~(ushort)*local_c;
                      *(ushort *)local_18 =
                           ((uVar17 >> 5 & 0x3f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((uVar10 >> 5 & 0x3f) - (uVar17 >> 5 & 0x3f)) * 4 +
                                     iVar4 * 0x800)) * 0x20 |
                           ((uVar17 >> 0xb) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((uint)(uVar10 >> 0xb) - (uint)(uVar17 >> 0xb)) * 4 +
                                     iVar4 * 0x800)) * 0x800 |
                           (uVar17 & 0x1f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((uVar10 & 0x1f) - (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00707744;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (param_4 == 0) {
                do {
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                  while( true ) {
                    uVar3 = (uint)(ushort)*local_18;
                    uVar2 = (uint)(ushort)~(ushort)*local_c;
                    *(ushort *)local_18 =
                         (ushort)(((uVar2 & 0x7e0) - (uVar3 & 0x7e0)) *
                                  (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                  (uVar3 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                         (ushort)(((uVar2 & 0xf800) - (uVar3 & 0xf800)) *
                                  (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                  (uVar3 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                         (ushort)(((uVar2 & 0x1f) - (uVar3 & 0x1f)) *
                                  (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                  (uVar3 & 0x1f) * 0x10000 >> 0x10);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_c = (uint *)((int)local_c + local_2c);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
              iVar5 = DAT_00dca3f8;
LAB_007072c0:
              local_c = local_10;
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              local_18 = local_1c;
              do {
                if (*(byte *)((int)local_c + 2) == 0) {
                  do {
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_0070748a;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                  local_18 = puVar7;
                }
                else if (*(byte *)((int)local_c + 2) == 0xff) {
                  do {
                    uVar10 = ~(ushort)*local_c;
                    uVar17 = (ushort)*puVar7;
                    puVar7 = (uint *)((int)local_18 + 2);
                    *(ushort *)local_18 =
                         ((uVar17 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar10 >> 5 & 0x3f) - (uVar17 >> 5 & 0x3f)) * 4 + iVar4 * 0x800
                                   )) * 0x20 |
                         ((uVar17 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uint)(uVar10 >> 0xb) - (uint)(uVar17 >> 0xb)) * 4 +
                                   iVar4 * 0x800)) * 0x800 |
                         (uVar17 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar10 & 0x1f) - (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_00707485;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                  iVar5 = DAT_00dca3f8;
                }
                else {
                  do {
                    uVar3 = (uint)(ushort)*puVar7;
                    uVar2 = (uint)(ushort)~(ushort)*local_c;
                    *(ushort *)local_18 =
                         (ushort)(((uVar2 & 0x7e0) - (uVar3 & 0x7e0)) *
                                  (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                  (uVar3 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                         (ushort)(((uVar2 & 0xf800) - (uVar3 & 0xf800)) *
                                  (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                  (uVar3 & 0xfffff800) * 0x10000 >> 0x10) & 0xf800 |
                         (ushort)(((uVar2 & 0x1f) - (uVar3 & 0x1f)) *
                                  (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                  (uVar3 & 0x1f) * 0x10000 >> 0x10);
                    puVar7 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_00707485;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if (*(int *)(param_2 + 0x2c) == 1) {
              if (param_4 == 0) {
                local_8 = local_44;
                local_18 = local_1c;
                local_c = local_10;
                param_3 = (int *)local_40;
                while( true ) {
                  while( true ) {
                    uVar17 = (ushort)*local_18;
                    uVar2 = (uint)uVar17;
                    uVar10 = ~(ushort)*local_c;
                    *(ushort *)local_18 =
                         (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                  (uVar17 >> 5 & 0x3f)) * (uint)*(byte *)((int)local_c + 2) *
                                  DAT_00dca3f8 + (uVar2 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                         (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                  (uint)(uVar17 >> 0xb)) * (uint)*(byte *)((int)local_c + 2) *
                                  DAT_00dca3f8 + (uVar2 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                         (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                  (uVar2 & 0x1f)) * (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8
                                  + uVar2 * 0x10000 >> 0x10) & 0x1f;
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_c = (uint *)((int)local_c + local_2c);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                  if (local_24 == 0) break;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                  local_c = local_10;
                }
                return;
              }
              iVar5 = DAT_00dca3f8;
LAB_007078b6:
              local_c = local_10;
              local_8 = local_44;
              param_3 = (int *)local_40;
              puVar7 = local_1c;
              local_18 = local_1c;
              do {
                if (*(byte *)((int)local_c + 2) == 0) {
                  do {
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_00707aba;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
LAB_00707aa0:
                  puVar7 = local_18;
                }
                else {
                  if (*(byte *)((int)local_c + 2) == 0xff) {
                    do {
                      uVar10 = ~(ushort)*local_c;
                      uVar17 = (ushort)*puVar7;
                      *(ushort *)local_18 =
                           ((uVar17 >> 5 & 0x3f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                     (uVar17 >> 5 & 0x3f)) * 4 + iVar4 * 0x800)) * 0x20 |
                           ((uVar17 >> 0xb) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                     (uint)(uVar17 >> 0xb)) * 4 + iVar4 * 0x800)) * 0x800 |
                           (uVar17 & 0x1f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                     (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00707ab5;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                    iVar5 = DAT_00dca3f8;
                    goto LAB_00707aa0;
                  }
                  do {
                    uVar17 = (ushort)*puVar7;
                    uVar2 = (uint)uVar17;
                    uVar10 = ~(ushort)*local_c;
                    *(ushort *)local_18 =
                         (ushort)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                  (uVar17 >> 5 & 0x3f)) * (uint)*(byte *)((int)local_c + 2) * iVar5
                                  + (uVar2 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                         (ushort)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                  (uint)(uVar17 >> 0xb)) * (uint)*(byte *)((int)local_c + 2) * iVar5
                                  + (uVar2 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                         (ushort)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                  (uVar2 & 0x1f)) * (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                  uVar2 * 0x10000 >> 0x10) & 0x1f;
                    puVar7 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_00707ab5;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                } while ((int)param_3 < 1);
              } while( true );
            }
            local_c = local_10;
            if (param_4 != 0) {
LAB_00707ca0:
              local_10 = local_c;
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              local_18 = local_1c;
              do {
                if ((ushort)*local_c == uVar2) {
                  do {
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_00707da9;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar17 = (ushort)*puVar7;
                    uVar10 = ~(ushort)*local_c;
                    *(ushort *)local_18 =
                         ((uVar17 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                                   (uVar17 >> 5 & 0x3f)) * 4 + iVar4 * 0x800)) * 0x20 |
                         ((uVar17 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                                   (uint)(uVar17 >> 0xb)) * 4 + iVar4 * 0x800)) * 0x800 |
                         (uVar17 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] -
                                   (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                    puVar7 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_00707da9;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                do {
                  local_c = (uint *)((int)local_c + local_2c);
                  param_3 = (int *)((int)param_3 + local_34);
                } while ((int)param_3 < 1);
              } while( true );
            }
            do {
              local_8 = local_44;
              param_3 = (int *)local_40;
              local_18 = local_1c;
              local_c = local_10;
              while( true ) {
                uVar17 = (ushort)*local_18;
                uVar10 = ~(ushort)*local_c;
                *(ushort *)local_18 =
                     ((uVar17 >> 5 & 0x3f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] -
                               (uVar17 >> 5 & 0x3f)) * 4 + iVar4 * 0x800)) * 0x20 |
                     ((uVar17 >> 0xb) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] -
                               (uint)(uVar17 >> 0xb)) * 4 + iVar4 * 0x800)) * 0x800 |
                     (uVar17 & 0x1f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] - (uVar17 & 0x1f))
                               * 4 + iVar4 * 0x800);
                local_18 = (uint *)((int)local_18 + 2);
                local_8 = local_8 + -1;
                if (local_8 == 0) break;
                for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                    param_3 = (int *)((int)param_3 + local_34)) {
                  local_c = (uint *)((int)local_c + local_2c);
                }
              }
              local_1c = (uint *)((int)local_1c + local_48);
              for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38)
              {
                local_10 = (uint *)((int)local_10 + local_3c);
              }
              local_24 = local_24 + -1;
            } while (local_24 != 0);
            break;
          case 0xb:
            if (param_5 == 0) {
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (*(int *)(param_2 + 0x2c) != 1) {
                  if (param_4 == 0) {
                    do {
                      local_c = local_10;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      local_18 = local_1c;
                      while( true ) {
                        uVar17 = (ushort)*local_c;
                        uVar10 = (ushort)*local_18;
                        uVar2 = uVar10 >> 5 & 0x3f;
                        *(ushort *)local_18 =
                             ((uVar10 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] *
                                         uVar2 >> 6) - uVar2) * 4 + iVar4 * 0x800)) * 0x20 |
                             ((uVar10 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] *
                                         (uint)(uVar10 >> 0xb) >> 5) - (uint)(uVar10 >> 0xb)) * 4 +
                                       iVar4 * 0x800)) * 0x800 |
                             (uVar10 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] *
                                         (uVar10 & 0x1f) >> 5) - (uVar10 & 0x1f)) * 4 +
                                       iVar4 * 0x800);
                        local_18 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        if ((int)param_3 < 1) {
                          do {
                            param_3 = (int *)((int)param_3 + local_34);
                            local_c = (uint *)((int)local_c + local_2c);
                          } while ((int)param_3 < 1);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_14 = local_14 + local_38;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_007060d0:
                  local_c = local_10;
                  local_8 = local_44;
                  puVar7 = local_1c;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                  do {
                    if ((ushort)*local_c == uVar2) {
                      do {
                        puVar7 = (uint *)((int)puVar7 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_007061f2;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        uVar17 = (ushort)*local_c;
                        uVar10 = (ushort)*puVar7;
                        uVar8 = uVar10 >> 5 & 0x3f;
                        *(ushort *)local_18 =
                             ((uVar10 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] *
                                         uVar8 >> 6) - uVar8) * 4 + iVar4 * 0x800)) * 0x20 |
                             ((uVar10 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] *
                                         (uint)(uVar10 >> 0xb) >> 5) - (uint)(uVar10 >> 0xb)) * 4 +
                                       iVar4 * 0x800)) * 0x800 |
                             (uVar10 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] *
                                         (uVar10 & 0x1f) >> 5) - (uVar10 & 0x1f)) * 4 +
                                       iVar4 * 0x800);
                        puVar7 = (uint *)((int)local_18 + 2);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_007061f2;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      local_c = (uint *)((int)local_c + local_2c);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                local_c = local_10;
                if (param_4 == 0) {
                  local_8 = local_44;
                  local_18 = local_1c;
                  param_3 = (int *)local_40;
                  while( true ) {
                    while( true ) {
                      uVar17 = (ushort)*local_c;
                      uVar10 = (ushort)*local_18;
                      uVar8 = (uint)uVar10;
                      uVar2 = uVar10 >> 5 & 0x3f;
                      *(ushort *)local_18 =
                           (ushort)((((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] * uVar2
                                     >> 6) - uVar2) * (uint)*(byte *)((int)local_c + 2) *
                                    DAT_00dca3f8 + (uVar8 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                           (ushort)((((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] *
                                      (uint)(uVar10 >> 0xb) >> 5) - (uint)(uVar10 >> 0xb)) *
                                    (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                    (uVar8 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                           (ushort)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] *
                                      (uVar8 & 0x1f) >> 5) - (uVar8 & 0x1f)) *
                                    (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                    uVar8 * 0x10000 >> 0x10) & 0x1f;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_18 = local_1c;
                    local_c = local_10;
                  }
                  return;
                }
                iVar5 = DAT_00dca3f8;
LAB_00705ca5:
                local_c = local_10;
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                local_18 = local_1c;
                do {
                  if (*(byte *)((int)local_c + 2) == 0) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00705ec8;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else if (*(byte *)((int)local_c + 2) == 0xff) {
                    do {
                      uVar17 = (ushort)*puVar7;
                      uVar10 = (ushort)*local_c;
                      uVar2 = uVar17 >> 5 & 0x3f;
                      *(ushort *)local_18 =
                           ((uVar17 >> 5 & 0x3f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     (((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] * uVar2
                                      >> 6) - uVar2) * 4 + iVar4 * 0x800)) * 0x20 |
                           ((uVar17 >> 0xb) +
                           *(short *)(&DAT_00d4a6e0 +
                                     (((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] *
                                       (uint)(uVar17 >> 0xb) >> 5) - (uint)(uVar17 >> 0xb)) * 4 +
                                     iVar4 * 0x800)) * 0x800 |
                           (uVar17 & 0x1f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     (((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] *
                                       (uVar17 & 0x1f) >> 5) - (uVar17 & 0x1f)) * 4 + iVar4 * 0x800)
                      ;
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00705ec3;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                    iVar5 = DAT_00dca3f8;
                  }
                  else {
                    do {
                      uVar17 = (ushort)*puVar7;
                      uVar8 = (uint)uVar17;
                      uVar10 = (ushort)*local_c;
                      uVar2 = uVar17 >> 5 & 0x3f;
                      *(ushort *)local_18 =
                           (ushort)((((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] * uVar2
                                     >> 6) - uVar2) * (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                    (uVar8 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                           (ushort)((((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] *
                                      (uint)(uVar17 >> 0xb) >> 5) - (uint)(uVar17 >> 0xb)) *
                                    (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                    (uVar8 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                           (ushort)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] *
                                      (uVar8 & 0x1f) >> 5) - (uVar8 & 0x1f)) *
                                    (uint)*(byte *)((int)local_c + 2) * iVar5 + uVar8 * 0x10000 >>
                                   0x10) & 0x1f;
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00705ec3;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (*(int *)(param_2 + 0x2c) != 1) {
                if (param_4 == 0) {
                  do {
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_18 = local_1c;
                    while( true ) {
                      uVar17 = (ushort)*local_18;
                      uVar10 = (ushort)*local_c;
                      uVar2 = uVar17 >> 5 & 0x3f;
                      *(ushort *)local_18 =
                           ((uVar17 >> 5 & 0x3f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     (((int)((uVar10 >> 5 & 0x3f) * uVar2) >> 6) - uVar2) * 4 +
                                     iVar4 * 0x800)) * 0x20 |
                           ((uVar17 >> 0xb) +
                           *(short *)(&DAT_00d4a6e0 +
                                     (((int)((uint)(uVar10 >> 0xb) * (uint)(uVar17 >> 0xb)) >> 5) -
                                     (uint)(uVar17 >> 0xb)) * 4 + iVar4 * 0x800)) * 0x800 |
                           (uVar17 & 0x1f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     (((int)((uVar10 & 0x1f) * (uVar17 & 0x1f)) >> 5) -
                                     (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_00705a10:
                local_c = local_10;
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                local_18 = local_1c;
                do {
                  if ((ushort)*local_c == uVar2) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00705b14;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar17 = (ushort)*puVar7;
                      uVar10 = (ushort)*local_c;
                      uVar3 = uVar17 >> 5 & 0x3f;
                      *(ushort *)local_18 =
                           ((uVar17 >> 5 & 0x3f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     (((int)((uVar10 >> 5 & 0x3f) * uVar3) >> 6) - uVar3) * 4 +
                                     iVar4 * 0x800)) * 0x20 |
                           ((uVar17 >> 0xb) +
                           *(short *)(&DAT_00d4a6e0 +
                                     (((int)((uint)(uVar10 >> 0xb) * (uint)(uVar17 >> 0xb)) >> 5) -
                                     (uint)(uVar17 >> 0xb)) * 4 + iVar4 * 0x800)) * 0x800 |
                           (uVar17 & 0x1f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     (((int)((uVar10 & 0x1f) * (uVar17 & 0x1f)) >> 5) -
                                     (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00705b14;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (param_4 == 0) {
                do {
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                  while( true ) {
                    uVar3 = (uint)(ushort)*local_18;
                    uVar2 = (uint)(ushort)*local_c;
                    uVar11 = uVar3 & 0x1f;
                    *(ushort *)local_18 =
                         (ushort)((((uVar3 & 0xf800) * (uVar2 & 0xf800) >> 0x1b) -
                                  (uint)(ushort)((ushort)*local_18 >> 0xb)) *
                                  (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                  (uVar3 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                         (ushort)((((uVar2 & 0x7e0) * (uVar3 & 0x7e0) >> 0xb) - (uVar3 & 0x7e0)) *
                                  (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                  (uVar3 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                         (ushort)((((uVar2 & 0x1f) * uVar11 >> 5) - uVar11) *
                                  (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                  uVar11 * 0x10000 >> 0x10);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_c = (uint *)((int)local_c + local_2c);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
              iVar5 = DAT_00dca3f8;
LAB_00705655:
              local_c = local_10;
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              local_18 = local_1c;
              do {
                if (*(byte *)((int)local_c + 2) == 0) {
                  do {
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_0070583a;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                else if (*(byte *)((int)local_c + 2) == 0xff) {
                  do {
                    uVar17 = (ushort)*puVar7;
                    uVar10 = (ushort)*local_c;
                    uVar2 = uVar17 >> 5 & 0x3f;
                    puVar7 = (uint *)((int)local_18 + 2);
                    *(ushort *)local_18 =
                         ((uVar17 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((int)((uVar10 >> 5 & 0x3f) * uVar2) >> 6) - uVar2) * 4 +
                                   iVar4 * 0x800)) * 0x20 |
                         ((uVar17 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((int)((uint)(uVar10 >> 0xb) * (uint)(uVar17 >> 0xb)) >> 5) -
                                   (uint)(uVar17 >> 0xb)) * 4 + iVar4 * 0x800)) * 0x800 |
                         (uVar17 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((int)((uVar10 & 0x1f) * (uVar17 & 0x1f)) >> 5) -
                                   (uVar17 & 0x1f)) * 4 + iVar4 * 0x800);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_00705835;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                  iVar5 = DAT_00dca3f8;
                }
                else {
                  do {
                    uVar3 = (uint)(ushort)*puVar7;
                    uVar2 = (uint)(ushort)*local_c;
                    uVar11 = uVar3 & 0x1f;
                    *(ushort *)local_18 =
                         (ushort)((((uVar3 & 0xf800) * (uVar2 & 0xf800) >> 0x1b) -
                                  (uint)(ushort)((ushort)*puVar7 >> 0xb)) *
                                  (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                  (uVar3 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                         (ushort)((((uVar2 & 0x7e0) * (uVar3 & 0x7e0) >> 0xb) - (uVar3 & 0x7e0)) *
                                  (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                  (uVar3 & 0xffffffe0) * 0x10000 >> 0x10) & 0x7e0 |
                         (ushort)((((uVar2 & 0x1f) * uVar11 >> 5) - uVar11) *
                                  (uint)*(byte *)((int)local_c + 2) * iVar5 + uVar11 * 0x10000 >>
                                 0x10);
                    puVar7 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_00705835;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
              if (*(int *)(param_2 + 0x2c) != 1) {
                local_18 = local_1c;
                local_c = local_10;
                iVar5 = DAT_00dca3f8;
                if (param_4 == 0) {
                  local_20 = local_28;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  while( true ) {
                    while( true ) {
                      uVar17 = (ushort)*local_c;
                      uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar10 = (ushort)*local_18;
                      uVar14 = (uint)uVar10;
                      uVar2 = uVar10 >> 5 & 0x3f;
                      *(ushort *)local_18 =
                           (ushort)((((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] * uVar2
                                     >> 6) - uVar2) * uVar8 * DAT_00dca3f8 +
                                    (uVar14 & 0xffffffe0) * 0x800 >> 0xb) & 0x7e0 |
                           (ushort)((((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] *
                                      (uint)(uVar10 >> 0xb) >> 5) - (uint)(uVar10 >> 0xb)) * uVar8 *
                                    DAT_00dca3f8 + (uVar14 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                           (ushort)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] *
                                      (uVar14 & 0x1f) >> 5) - (uVar14 & 0x1f)) * uVar8 *
                                    DAT_00dca3f8 + uVar14 * 0x10000 >> 0x10) & 0x1f;
                      local_18 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_20 = local_20 + local_58;
                        local_c = (uint *)((int)local_c + local_2c);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    local_c = local_10;
                    local_20 = local_28;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_18 = local_1c;
                  }
                  return;
                }
LAB_007052d4:
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                local_20 = local_28;
                local_18 = local_1c;
                local_c = local_10;
                do {
                  if ((ushort)*local_c == uVar2) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + 2);
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_00705433;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                    local_18 = puVar7;
                  }
                  else {
                    do {
                      uVar17 = (ushort)*local_c;
                      uVar14 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar10 = (ushort)*puVar7;
                      uVar15 = (uint)uVar10;
                      uVar8 = uVar10 >> 5 & 0x3f;
                      *(ushort *)local_18 =
                           (ushort)((((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] * uVar8
                                     >> 6) - uVar8) * uVar14 * iVar5 + (uVar15 & 0xffffffe0) * 0x800
                                   >> 0xb) & 0x7e0 |
                           (ushort)((((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] *
                                      (uint)(uVar10 >> 0xb) >> 5) - (uint)(uVar10 >> 0xb)) * uVar14
                                    * iVar5 + (uVar15 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                           (ushort)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] *
                                      (uVar15 & 0x1f) >> 5) - (uVar15 & 0x1f)) * uVar14 * iVar5 +
                                    uVar15 * 0x10000 >> 0x10) & 0x1f;
                      puVar7 = (uint *)((int)local_18 + 2);
                      local_8 = local_8 + -1;
                      iVar5 = DAT_00dca3f8;
                      if (local_8 == 0) goto LAB_00705433;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_c = (uint *)((int)local_c + local_2c);
                    local_20 = local_20 + local_58;
                    param_3 = (int *)((int)param_3 + local_34);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              local_20 = local_28;
              if (param_4 == 0) {
                local_8 = local_44;
                local_18 = local_1c;
                local_c = local_10;
                param_3 = (int *)local_40;
                while( true ) {
                  while( true ) {
                    uVar17 = (ushort)*local_c;
                    uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar10 = (ushort)*local_18;
                    uVar14 = (uint)uVar10;
                    uVar2 = uVar10 >> 5 & 0x3f;
                    *(ushort *)local_18 =
                         (ushort)((((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar17 >> 5 & 0x3f)] * uVar2 >>
                                   6) - uVar2) * uVar8 * (uint)*(byte *)((int)local_c + 2) *
                                  DAT_00dca3f8 + (uVar14 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                         (ushort)((((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar17 >> 0xb)] *
                                    (uint)(uVar10 >> 0xb) >> 5) - (uint)(uVar10 >> 0xb)) * uVar8 *
                                  (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                  (uVar14 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                         (byte)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar17 & 0x1f)] *
                                  (uVar14 & 0x1f) >> 5) - (uVar14 & 0x1f)) * uVar8 *
                                (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                uVar14 * 0x1000000 >> 0x18) & 0x1f;
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_20 = local_20 + local_58;
                      local_c = (uint *)((int)local_c + local_2c);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_14 = local_14 + local_38;
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                  local_c = local_10;
                  local_20 = local_28;
                  if (local_24 == 0) break;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                }
                return;
              }
              iVar5 = DAT_00dca3f8;
LAB_00704e15:
              local_8 = local_44;
              param_3 = (int *)local_40;
              puVar7 = local_1c;
              local_20 = local_28;
              local_18 = local_1c;
              local_c = local_10;
              do {
                if (*(byte *)((int)local_c + 2) == 0) {
                  do {
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_00705093;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                else if (*(byte *)((int)local_c + 2) == 0xff) {
                  do {
                    uVar17 = (ushort)*puVar7;
                    uVar14 = (uint)uVar17;
                    uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar10 = (ushort)*local_c;
                    uVar2 = uVar17 >> 5 & 0x3f;
                    *(ushort *)local_18 =
                         (ushort)((((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] * uVar2 >>
                                   6) - uVar2) * uVar8 * iVar5 + (uVar14 & 0xffffffe0) * 0x800 >>
                                 0xb) & 0x7e0 |
                         (ushort)((((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] *
                                    (uint)(uVar17 >> 0xb) >> 5) - (uint)(uVar17 >> 0xb)) * uVar8 *
                                  iVar5 + (uVar14 & 0xfffff800) * 0x20 >> 5) & 0xf800 |
                         (ushort)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] *
                                    (uVar14 & 0x1f) >> 5) - (uVar14 & 0x1f)) * uVar8 * iVar5 +
                                  uVar14 * 0x10000 >> 0x10) & 0x1f;
                    puVar7 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_0070508e;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar17 = (ushort)*puVar7;
                    uVar14 = (uint)uVar17;
                    uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar10 = (ushort)*local_c;
                    uVar2 = uVar17 >> 5 & 0x3f;
                    *(ushort *)local_18 =
                         (ushort)((((&DAT_00d0a2e0)[uVar3 * 0x100 + (uVar10 >> 5 & 0x3f)] * uVar2 >>
                                   6) - uVar2) * uVar8 * (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                  (uVar14 & 0xffffffe0) * 0x80000 >> 0x13) & 0x7e0 |
                         (ushort)((((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)(uVar10 >> 0xb)] *
                                    (uint)(uVar17 >> 0xb) >> 5) - (uint)(uVar17 >> 0xb)) * uVar8 *
                                  (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                  (uVar14 & 0xfffff800) * 0x2000 >> 0xd) & 0xf800 |
                         (byte)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uVar10 & 0x1f)] *
                                  (uVar14 & 0x1f) >> 5) - (uVar14 & 0x1f)) * uVar8 *
                                (uint)*(byte *)((int)local_c + 2) * iVar5 + uVar14 * 0x1000000 >>
                               0x18) & 0x1f;
                    puVar7 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_0070508e;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                do {
                  local_20 = local_20 + local_58;
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                } while ((int)param_3 < 1);
              } while( true );
            }
            local_18 = local_1c;
            if (*(int *)(param_2 + 0x2c) != 1) {
              iVar5 = DAT_00dca3f8;
              if (param_4 == 0) {
                do {
                  local_20 = local_28;
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                  while( true ) {
                    uVar17 = (ushort)*local_18;
                    uVar2 = (uint)uVar17;
                    uVar10 = (ushort)*local_c;
                    uVar18 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar3 = uVar2 & 0x1f;
                    uVar11 = uVar17 >> 5 & 0x3f;
                    *(ushort *)local_18 =
                         (ushort)((int)((((int)((uVar10 >> 5 & 0x3f) * uVar11) >> 6) - uVar11) *
                                        uVar18 * DAT_00dca3f8 + (uVar2 & 0x7e0) * 0x800) >> 0xb) &
                         0x7e0 | (ushort)((int)((((int)((uint)(uVar10 >> 0xb) *
                                                       (uint)(uVar17 >> 0xb)) >> 5) -
                                                (uint)(uVar17 >> 0xb)) * uVar18 * DAT_00dca3f8 +
                                               (uVar2 & 0xfffff800) * 0x20) >> 5) & 0xf800 |
                         (ushort)((((int)((uVar10 & 0x1f) * uVar3) >> 5) - uVar3) * uVar18 *
                                  DAT_00dca3f8 + uVar3 * 0x10000 >> 0x10);
                    local_18 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_c = (uint *)((int)local_c + local_2c);
                      local_20 = local_20 + local_58;
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_00704af0:
              local_20 = local_28;
              local_c = local_10;
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              local_18 = local_1c;
              do {
                if ((ushort)*local_c == uVar2) {
                  do {
                    puVar7 = (uint *)((int)puVar7 + 2);
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_00704c28;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar17 = (ushort)*puVar7;
                    uVar3 = (uint)uVar17;
                    uVar10 = (ushort)*local_c;
                    uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    uVar11 = uVar3 & 0x1f;
                    uVar18 = uVar17 >> 5 & 0x3f;
                    *(ushort *)local_18 =
                         (ushort)((int)((((int)((uVar10 >> 5 & 0x3f) * uVar18) >> 6) - uVar18) *
                                        uVar8 * iVar5 + (uVar3 & 0x7e0) * 0x800) >> 0xb) & 0x7e0 |
                         (ushort)((int)((((int)((uint)(uVar10 >> 0xb) * (uint)(uVar17 >> 0xb)) >> 5)
                                        - (uint)(uVar17 >> 0xb)) * uVar8 * iVar5 +
                                       (uVar3 & 0xfffff800) * 0x20) >> 5) & 0xf800 |
                         (ushort)((((int)((uVar10 & 0x1f) * uVar11) >> 5) - uVar11) * uVar8 * iVar5
                                  + uVar11 * 0x10000 >> 0x10);
                    puVar7 = (uint *)((int)local_18 + 2);
                    local_8 = local_8 + -1;
                    iVar5 = DAT_00dca3f8;
                    if (local_8 == 0) goto LAB_00704c28;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                } while ((int)param_3 < 1);
              } while( true );
            }
            if (param_4 == 0) {
              local_8 = local_44;
              local_c = local_10;
              local_20 = local_28;
              param_3 = (int *)local_40;
              while( true ) {
                while( true ) {
                  uVar17 = (ushort)*local_c;
                  uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                  uVar10 = (ushort)*local_18;
                  uVar2 = (uint)uVar10;
                  uVar11 = uVar10 >> 5 & 0x3f;
                  uVar18 = uVar2 & 0x1f;
                  *(ushort *)local_18 =
                       (ushort)((int)((((int)((uVar17 >> 5 & 0x3f) * uVar11) >> 6) - uVar11) * uVar3
                                      * (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                     (uVar2 & 0x7e0) * 0x80000) >> 0x13) & 0x7e0 |
                       (ushort)((int)((((int)((uint)(uVar17 >> 0xb) * (uint)(uVar10 >> 0xb)) >> 5) -
                                      (uint)(uVar10 >> 0xb)) * uVar3 *
                                      (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                     (uVar2 & 0xfffff800) * 0x2000) >> 0xd) & 0xf800 |
                       (short)(char)((((int)((uVar17 & 0x1f) * uVar18) >> 5) - uVar18) * uVar3 *
                                     (uint)*(byte *)((int)local_c + 2) * DAT_00dca3f8 +
                                     uVar18 * 0x1000000 >> 0x18);
                  local_18 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) break;
                  for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                      param_3 = (int *)((int)param_3 + local_34)) {
                    local_c = (uint *)((int)local_c + local_2c);
                    local_20 = local_20 + local_58;
                  }
                }
                local_1c = (uint *)((int)local_1c + local_48);
                local_14 = local_14 - 0x10000;
                if ((int)local_14 < 1) {
                  do {
                    local_14 = local_14 + local_38;
                    local_10 = (uint *)((int)local_10 + local_3c);
                    local_28 = local_28 + local_5c;
                  } while ((int)local_14 < 1);
                }
                local_24 = local_24 + -1;
                if (local_24 == 0) break;
                local_8 = local_44;
                param_3 = (int *)local_40;
                local_20 = local_28;
                local_18 = local_1c;
                local_c = local_10;
              }
              return;
            }
            local_20 = local_28;
            iVar5 = DAT_00dca3f8;
            puVar7 = local_10;
LAB_007046a0:
            local_28 = local_20;
            local_8 = local_44;
            param_3 = (int *)local_40;
            local_18 = local_1c;
            local_c = puVar7;
            do {
              if (*(byte *)((int)local_c + 2) == 0) {
                do {
                  local_18 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_007048d6;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              else if (*(byte *)((int)local_c + 2) == 0xff) {
                do {
                  uVar17 = (ushort)*local_18;
                  uVar2 = (uint)uVar17;
                  uVar10 = (ushort)*local_c;
                  uVar18 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                  uVar3 = uVar2 & 0x1f;
                  uVar11 = uVar17 >> 5 & 0x3f;
                  *(ushort *)local_18 =
                       (ushort)((int)((((int)((uVar10 >> 5 & 0x3f) * uVar11) >> 6) - uVar11) *
                                      uVar18 * iVar5 + (uVar2 & 0x7e0) * 0x800) >> 0xb) & 0x7e0 |
                       (ushort)((int)((((int)((uint)(uVar10 >> 0xb) * (uint)(uVar17 >> 0xb)) >> 5) -
                                      (uint)(uVar17 >> 0xb)) * uVar18 * iVar5 +
                                     (uVar2 & 0xfffff800) * 0x20) >> 5) & 0xf800 |
                       (ushort)((((int)((uVar10 & 0x1f) * uVar3) >> 5) - uVar3) * uVar18 * iVar5 +
                                uVar3 * 0x10000 >> 0x10);
                  local_18 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_007048ce;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  iVar5 = DAT_00dca3f8;
                } while (0 < (int)param_3);
              }
              else {
                do {
                  uVar17 = (ushort)*local_c;
                  uVar10 = (ushort)*local_18;
                  uVar2 = (uint)uVar10;
                  uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                  uVar11 = uVar10 >> 5 & 0x3f;
                  uVar18 = uVar2 & 0x1f;
                  *(ushort *)local_18 =
                       (ushort)((int)((((int)((uVar17 >> 5 & 0x3f) * uVar11) >> 6) - uVar11) * uVar3
                                      * (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                     (uVar2 & 0x7e0) * 0x80000) >> 0x13) & 0x7e0 |
                       (ushort)((int)((((int)((uint)(uVar17 >> 0xb) * (uint)(uVar10 >> 0xb)) >> 5) -
                                      (uint)(uVar10 >> 0xb)) * uVar3 *
                                      (uint)*(byte *)((int)local_c + 2) * iVar5 +
                                     (uVar2 & 0xfffff800) * 0x2000) >> 0xd) & 0xf800 |
                       (short)(char)((((int)((uVar17 & 0x1f) * uVar18) >> 5) - uVar18) * uVar3 *
                                     (uint)*(byte *)((int)local_c + 2) * iVar5 + uVar18 * 0x1000000
                                    >> 0x18);
                  local_18 = (uint *)((int)local_18 + 2);
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_007048ce;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  iVar5 = DAT_00dca3f8;
                } while (0 < (int)param_3);
              }
              do {
                param_3 = (int *)((int)param_3 + local_34);
                local_c = (uint *)((int)local_c + local_2c);
                local_20 = local_20 + local_58;
              } while ((int)param_3 < 1);
              puVar7 = local_10;
            } while( true );
          }
        }
      }
      else if (*(int *)(param_2 + 0x20) == 1) {
        if (*(int *)(param_2 + 0x24) == 1) {
          switch(DAT_00dca3f4) {
          case 0:
switchD_006ea350_caseD_0:
            if (param_5 == 0) {
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (param_4 == 0) {
                  do {
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    puVar7 = local_1c;
                    local_c = local_10;
                    while( true ) {
                      *(byte *)puVar7 =
                           *(byte *)(&DAT_00d0a2e0 +
                                    uVar11 * 0x100 +
                                    (uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4));
                      *(byte *)((int)puVar7 + 1) =
                           *(byte *)(&DAT_00d0a2e0 +
                                    uVar3 * 0x100 +
                                    (uint)*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4));
                      *(byte *)((int)puVar7 + 2) =
                           *(byte *)(&DAT_00d0a2e0 +
                                    uVar18 * 0x100 +
                                    (uint)*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4));
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    for (local_14 = local_14 - 0x10000; (int)local_14 < 1;
                        local_14 = local_14 + local_38) {
                      local_10 = (uint *)((int)local_10 + local_3c);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006ea981:
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                local_c = local_10;
                do {
                  if ((byte)*local_c == uVar2) {
                    do {
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006eaa21;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      *(byte *)puVar7 =
                           *(byte *)(&DAT_00d0a2e0 +
                                    uVar11 * 0x100 +
                                    (uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4));
                      *(byte *)((int)puVar7 + 1) =
                           *(byte *)(&DAT_00d0a2e0 +
                                    uVar3 * 0x100 +
                                    (uint)*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4));
                      *(byte *)((int)puVar7 + 2) =
                           *(byte *)(&DAT_00d0a2e0 +
                                    uVar18 * 0x100 +
                                    (uint)*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4));
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006eaa21;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_c = (uint *)((int)local_c + local_2c);
                    param_3 = (int *)((int)param_3 + local_34);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (param_4 == 0) {
                do {
                  iVar4 = local_44;
                  iVar13 = local_40;
                  puVar7 = local_10;
LAB_006ea921:
                  uVar2 = *(uint *)(iVar6 + (uint)(byte)*puVar7 * 4);
                  iVar12 = iVar13;
                  while( true ) {
                    *local_1c = uVar2;
                    local_1c = local_1c + 1;
                    iVar4 = iVar4 + -1;
                    if (iVar4 == 0) break;
                    iVar13 = iVar12 + -0x10000;
                    bVar20 = iVar12 < 0x10000;
                    iVar12 = iVar13;
                    if (iVar13 == 0 || bVar20) goto LAB_006ea937;
                  }
                  local_1c = (uint *)((int)local_1c + iVar5);
                  bVar20 = local_14 < 0x10000;
                  local_14 = local_14 - 0x10000;
                  if (bVar20 || local_14 == 0) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      bVar20 = SCARRY4(local_14,local_38);
                      local_14 = local_14 + local_38;
                    } while (bVar20 != (int)local_14 < 0);
                  }
                  local_24 = local_24 + -1;
                  if (local_24 == 0) {
                    return;
                  }
                } while( true );
              }
LAB_006ea8aa:
              iVar4 = local_44;
              iVar13 = local_40;
              puVar7 = local_10;
              do {
                iVar12 = iVar13;
                if ((byte)*puVar7 == local_50) {
                  do {
                    local_1c = local_1c + 1;
                    iVar4 = iVar4 + -1;
                    if (iVar4 == 0) goto LAB_006ea8e5;
                    iVar13 = iVar12 + -0x10000;
                    bVar20 = 0xffff < iVar12;
                    iVar12 = iVar13;
                  } while (iVar13 != 0 && bVar20);
                }
                else {
                  uVar2 = *(uint *)(iVar6 + (uint)(byte)*puVar7 * 4);
                  do {
                    *local_1c = uVar2;
                    local_1c = local_1c + 1;
                    iVar4 = iVar4 + -1;
                    if (iVar4 == 0) goto LAB_006ea8e5;
                    iVar13 = iVar12 + -0x10000;
                    bVar20 = 0xffff < iVar12;
                    iVar12 = iVar13;
                  } while (iVar13 != 0 && bVar20);
                }
                do {
                  puVar7 = (uint *)((int)puVar7 + local_2c);
                  bVar20 = SCARRY4(iVar13,local_34);
                  iVar13 = iVar13 + local_34;
                } while (bVar20 != iVar13 < 0);
              } while( true );
            }
            if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
              if (param_4 == 0) {
                do {
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  local_20 = local_28;
                  local_c = local_10;
                  while( true ) {
                    *(byte *)puVar7 =
                         (byte)(((&DAT_00d0a2e0)
                                 [uVar11 * 0x100 + (uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4)
                                 ] - (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                                (uint)(byte)*puVar7 * 0x100 >> 8);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)(((&DAT_00d0a2e0)
                                 [uVar3 * 0x100 +
                                  (uint)*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4)] -
                                (uint)*(byte *)((int)puVar7 + 1)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                                (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)(((&DAT_00d0a2e0)
                                 [uVar18 * 0x100 +
                                  (uint)*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4)] -
                                (uint)*(byte *)((int)puVar7 + 2)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                                (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_c = (uint *)((int)local_c + local_2c);
                      local_20 = local_20 + local_58;
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  for (local_14 = local_14 - 0x10000; (int)local_14 < 1;
                      local_14 = local_14 + local_38) {
                    local_10 = (uint *)((int)local_10 + local_3c);
                    local_28 = local_28 + local_5c;
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006ea5e3:
              local_8 = local_44;
              param_3 = (int *)local_40;
              puVar7 = local_1c;
              local_20 = local_28;
              local_c = local_10;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ea6fe;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    *(byte *)puVar7 =
                         (byte)(((&DAT_00d0a2e0)
                                 [uVar11 * 0x100 + (uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4)
                                 ] - (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                                (uint)(byte)*puVar7 * 0x100 >> 8);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)(((&DAT_00d0a2e0)
                                 [uVar3 * 0x100 +
                                  (uint)*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4)] -
                                (uint)*(byte *)((int)puVar7 + 1)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                                (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)(((&DAT_00d0a2e0)
                                 [uVar18 * 0x100 +
                                  (uint)*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4)] -
                                (uint)*(byte *)((int)puVar7 + 2)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                                (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ea6fe;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                  param_3 = (int *)((int)param_3 + local_34);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if (param_4 == 0) {
              do {
                local_20 = local_28;
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                puVar9 = local_10;
                while( true ) {
                  *(byte *)puVar7 =
                       (byte)(((uint)*(byte *)(iVar6 + (uint)(byte)*puVar9 * 4) -
                              (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                              (uint)(byte)*puVar7 * 0x100 >> 8);
                  *(byte *)((int)puVar7 + 1) =
                       (byte)(((uint)*(byte *)(iVar6 + 1 + (uint)(byte)*puVar9 * 4) -
                              (uint)*(byte *)((int)puVar7 + 1)) *
                              (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                              (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                  *(byte *)((int)puVar7 + 2) =
                       (byte)(((uint)*(byte *)(iVar6 + 2 + (uint)(byte)*puVar9 * 4) -
                              (uint)*(byte *)((int)puVar7 + 2)) *
                              (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                              (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) break;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  if ((int)param_3 < 1) {
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      puVar9 = (uint *)((int)puVar9 + local_2c);
                      local_20 = local_20 + local_58;
                    } while ((int)param_3 < 1);
                  }
                }
                local_1c = (uint *)((int)local_1c + local_48);
                local_14 = local_14 - 0x10000;
                if ((int)local_14 < 1) {
                  do {
                    local_14 = local_14 + local_38;
                    local_10 = (uint *)((int)local_10 + local_3c);
                    local_28 = local_28 + local_5c;
                  } while ((int)local_14 < 1);
                }
                local_24 = local_24 + -1;
              } while (local_24 != 0);
              return;
            }
LAB_006ea397:
            local_20 = local_28;
            local_8 = local_44;
            puVar7 = local_1c;
            param_3 = (int *)local_40;
            puVar9 = local_10;
            do {
              if ((byte)*puVar9 == uVar2) {
                do {
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006ea475;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              else {
                do {
                  *(byte *)puVar7 =
                       (byte)(((uint)*(byte *)(iVar6 + (uint)(byte)*puVar9 * 4) -
                              (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                              (uint)(byte)*puVar7 * 0x100 >> 8);
                  *(byte *)((int)puVar7 + 1) =
                       (byte)(((uint)*(byte *)(iVar6 + 1 + (uint)(byte)*puVar9 * 4) -
                              (uint)*(byte *)((int)puVar7 + 1)) *
                              (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                              (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                  *(byte *)((int)puVar7 + 2) =
                       (byte)(((uint)*(byte *)(iVar6 + 2 + (uint)(byte)*puVar9 * 4) -
                              (uint)*(byte *)((int)puVar7 + 2)) *
                              (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                              (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006ea475;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              do {
                param_3 = (int *)((int)param_3 + local_34);
                puVar9 = (uint *)((int)puVar9 + local_2c);
                local_20 = local_20 + local_58;
              } while ((int)param_3 < 1);
            } while( true );
          case 1:
            if (DAT_00dca3f8 == 0xff) goto switchD_006ea350_caseD_0;
            if (DAT_00dca3f8 != 0) {
              if (param_5 != 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  local_18 = local_1c;
                  iVar5 = DAT_00dca3f8;
                  if (param_4 == 0) {
                    local_c = local_10;
                    local_20 = local_28;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    while( true ) {
                      while( true ) {
                        *(byte *)local_18 =
                             (byte)(((&DAT_00d0a2e0)
                                     [uVar11 * 0x100 +
                                      (uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4)] -
                                    (uint)(byte)*local_18) * (uint)(byte)(&DAT_00dca2e0)[*local_20]
                                    * DAT_00dca3f8 + (uint)(byte)*local_18 * 0x10000 >> 0x10);
                        *(byte *)((int)local_18 + 1) =
                             (byte)(((&DAT_00d0a2e0)
                                     [uVar3 * 0x100 +
                                      (uint)*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4)] -
                                    (uint)*(byte *)((int)local_18 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)local_18 + 1) * 0x10000 >> 0x10);
                        *(byte *)((int)local_18 + 2) =
                             (byte)(((&DAT_00d0a2e0)
                                     [uVar18 * 0x100 +
                                      (uint)*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4)] -
                                    (uint)*(byte *)((int)local_18 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)local_18 + 2) * 0x10000 >> 0x10);
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                            param_3 = (int *)((int)param_3 + local_34)) {
                          local_c = (uint *)((int)local_c + local_2c);
                          local_20 = local_20 + local_58;
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      for (local_14 = local_14 - 0x10000; (int)local_14 < 1;
                          local_14 = local_14 + local_38) {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_28 = local_28 + local_5c;
                      }
                      local_24 = local_24 + -1;
                      if (local_24 == 0) break;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      local_20 = local_28;
                      local_18 = local_1c;
                      local_c = local_10;
                    }
                    return;
                  }
LAB_006eae30:
                  puVar7 = local_18;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_20 = local_28;
                  local_c = local_10;
                  do {
                    if ((byte)*local_c == uVar2) {
                      do {
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006eaf6a;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        *(byte *)local_18 =
                             (byte)(((&DAT_00d0a2e0)
                                     [uVar11 * 0x100 +
                                      (uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4)] -
                                    (uint)(byte)*local_18) * (uint)(byte)(&DAT_00dca2e0)[*local_20]
                                    * iVar5 + (uint)(byte)*local_18 * 0x10000 >> 0x10);
                        *(byte *)((int)local_18 + 1) =
                             (byte)(((&DAT_00d0a2e0)
                                     [uVar3 * 0x100 +
                                      (uint)*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4)] -
                                    (uint)*(byte *)((int)local_18 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)local_18 + 1) * 0x10000 >> 0x10);
                        *(byte *)((int)local_18 + 2) =
                             (byte)(((&DAT_00d0a2e0)
                                     [uVar18 * 0x100 +
                                      (uint)*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4)] -
                                    (uint)*(byte *)((int)local_18 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)local_18 + 2) * 0x10000 >> 0x10);
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        iVar5 = DAT_00dca3f8;
                        if (local_8 == 0) goto LAB_006eaf6a;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    do {
                      local_c = (uint *)((int)local_c + local_2c);
                      local_20 = local_20 + local_58;
                      param_3 = (int *)((int)param_3 + local_34);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                local_c = local_10;
                if (param_4 == 0) {
                  local_8 = local_44;
                  local_20 = local_28;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  while( true ) {
                    while( true ) {
                      *(byte *)puVar7 =
                           (byte)(((uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4) -
                                  (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  DAT_00dca3f8 + (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)(((uint)*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4) -
                                  (uint)*(byte *)((int)puVar7 + 1)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)(((uint)*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4) -
                                  (uint)*(byte *)((int)puVar7 + 2)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                        local_20 = local_20 + local_58;
                      }
                    }
                    puVar7 = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_20 = local_28;
                    local_1c = puVar7;
                    local_c = local_10;
                  }
                  return;
                }
                local_20 = local_28;
                iVar5 = DAT_00dca3f8;
LAB_006eab67:
                local_28 = local_20;
                local_c = local_10;
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                do {
                  if ((byte)*local_c == uVar2) {
                    do {
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006eac69;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      *(byte *)puVar7 =
                           (byte)(((uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4) -
                                  (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  iVar5 + (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)(((uint)*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4) -
                                  (uint)*(byte *)((int)puVar7 + 1)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)(((uint)*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4) -
                                  (uint)*(byte *)((int)puVar7 + 2)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      iVar5 = DAT_00dca3f8;
                      if (local_8 == 0) goto LAB_006eac69;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_20 = local_20 + local_58;
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                local_18 = local_1c;
                iVar5 = DAT_00dca3f8;
                if (param_4 == 0) {
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  while( true ) {
                    while( true ) {
                      *(byte *)local_18 =
                           (byte)(((&DAT_00d0a2e0)
                                   [uVar11 * 0x100 +
                                    (uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4)] -
                                  (uint)(byte)*local_18) * DAT_00dca3f8 +
                                  (uint)(byte)*local_18 * 0x100 >> 8);
                      *(byte *)((int)local_18 + 1) =
                           (byte)(((&DAT_00d0a2e0)
                                   [uVar3 * 0x100 +
                                    (uint)*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4)] -
                                  (uint)*(byte *)((int)local_18 + 1)) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)local_18 + 1) * 0x100 >> 8);
                      *(byte *)((int)local_18 + 2) =
                           (byte)(((&DAT_00d0a2e0)
                                   [uVar18 * 0x100 +
                                    (uint)*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4)] -
                                  (uint)*(byte *)((int)local_18 + 2)) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)local_18 + 2) * 0x100 >> 8);
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    for (local_14 = local_14 - 0x10000; (int)local_14 < 1;
                        local_14 = local_14 + local_38) {
                      local_10 = (uint *)((int)local_10 + local_3c);
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_18 = local_1c;
                    local_c = local_10;
                  }
                  return;
                }
LAB_006eb366:
                puVar7 = local_18;
                local_8 = local_44;
                param_3 = (int *)local_40;
                local_c = local_10;
                do {
                  if ((byte)*local_c == uVar2) {
                    do {
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006eb45d;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      *(byte *)local_18 =
                           (byte)(((&DAT_00d0a2e0)
                                   [uVar11 * 0x100 +
                                    (uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4)] -
                                  (uint)(byte)*local_18) * iVar5 + (uint)(byte)*local_18 * 0x100 >>
                                 8);
                      *(byte *)((int)local_18 + 1) =
                           (byte)(((&DAT_00d0a2e0)
                                   [uVar3 * 0x100 +
                                    (uint)*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4)] -
                                  (uint)*(byte *)((int)local_18 + 1)) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)local_18 + 1) * 0x100 >> 8);
                      *(byte *)((int)local_18 + 2) =
                           (byte)(((&DAT_00d0a2e0)
                                   [uVar18 * 0x100 +
                                    (uint)*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4)] -
                                  (uint)*(byte *)((int)local_18 + 2)) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)local_18 + 2) * 0x100 >> 8);
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      iVar5 = DAT_00dca3f8;
                      if (local_8 == 0) goto LAB_006eb45d;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_c = (uint *)((int)local_c + local_2c);
                    param_3 = (int *)((int)param_3 + local_34);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              iVar5 = DAT_00dca3f8;
              if (param_4 == 0) {
                do {
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  puVar9 = local_10;
                  while( true ) {
                    *(byte *)puVar7 =
                         (byte)(((uint)*(byte *)(iVar6 + (uint)(byte)*puVar9 * 4) -
                                (uint)(byte)*puVar7) * DAT_00dca3f8 + (uint)(byte)*puVar7 * 0x100 >>
                               8);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)(((uint)*(byte *)(iVar6 + 1 + (uint)(byte)*puVar9 * 4) -
                                (uint)*(byte *)((int)puVar7 + 1)) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)(((uint)*(byte *)(iVar6 + 2 + (uint)(byte)*puVar9 * 4) -
                                (uint)*(byte *)((int)puVar7 + 2)) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        puVar9 = (uint *)((int)puVar9 + local_2c);
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006eb165:
              local_8 = local_44;
              puVar7 = local_1c;
              puVar9 = local_10;
              param_3 = (int *)local_40;
              do {
                if ((byte)*puVar9 == uVar2) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006eb224;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    *(byte *)puVar7 =
                         (byte)(((uint)*(byte *)(iVar6 + (uint)(byte)*puVar9 * 4) -
                                (uint)(byte)*puVar7) * iVar5 + (uint)(byte)*puVar7 * 0x100 >> 8);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)(((uint)*(byte *)(iVar6 + 1 + (uint)(byte)*puVar9 * 4) -
                                (uint)*(byte *)((int)puVar7 + 1)) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)(((uint)*(byte *)(iVar6 + 2 + (uint)(byte)*puVar9 * 4) -
                                (uint)*(byte *)((int)puVar7 + 2)) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    iVar5 = DAT_00dca3f8;
                    if (local_8 == 0) goto LAB_006eb224;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  puVar9 = (uint *)((int)puVar9 + local_2c);
                  param_3 = (int *)((int)param_3 + local_34);
                } while ((int)param_3 < 1);
              } while( true );
            }
            break;
          case 2:
            if (DAT_00dca3f8 != 0) {
              if (param_5 != 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  local_18 = local_1c;
                  local_c = local_10;
                  iVar5 = DAT_00dca3f8;
                  if (param_4 == 0) {
                    local_20 = local_28;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    while( true ) {
                      while( true ) {
                        uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                        pbVar19 = (byte *)(iVar6 + (uint)(byte)*local_c * 4);
                        param_2._0_2_ =
                             CONCAT11((char)((&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)pbVar19[1]] *
                                             uVar2 * DAT_00dca3f8 >> 0x10),
                                      (char)((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)*pbVar19] *
                                             uVar2 * DAT_00dca3f8 >> 0x10));
                        param_2._0_3_ =
                             CONCAT12((char)((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)pbVar19[2]] *
                                             uVar2 * DAT_00dca3f8 >> 0x10),(undefined2)param_2);
                        param_2 = (uint)(uint3)param_2;
                        uVar2 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                        uVar8 = uVar2 & 0x1010100;
                        *local_18 = uVar8 - (uVar8 >> 8) | (param_2 | *local_18) & 0x10100 | uVar2;
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                            param_3 = (int *)((int)param_3 + local_34)) {
                          local_20 = local_20 + local_58;
                          local_c = (uint *)((int)local_c + local_2c);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_14 = local_14 + local_38;
                          local_28 = local_28 + local_5c;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                      local_c = local_10;
                      local_20 = local_28;
                      if (local_24 == 0) break;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      local_18 = local_1c;
                    }
                    return;
                  }
LAB_006eb8b0:
                  puVar7 = local_18;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_20 = local_28;
                  local_c = local_10;
                  do {
                    if ((byte)*local_c == uVar2) {
                      do {
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006eb9d3;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                        pbVar19 = (byte *)(iVar6 + (uint)(byte)*local_c * 4);
                        param_2._0_2_ =
                             CONCAT11((char)((&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)pbVar19[1]] *
                                             uVar8 * iVar5 >> 0x10),
                                      (char)((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)*pbVar19] *
                                             uVar8 * iVar5 >> 0x10));
                        param_2._0_3_ =
                             CONCAT12((char)((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)pbVar19[2]] *
                                             uVar8 * iVar5 >> 0x10),(undefined2)param_2);
                        param_2 = (uint)(uint3)param_2;
                        uVar8 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                        uVar14 = uVar8 & 0x1010100;
                        *local_18 = uVar14 - (uVar14 >> 8) | (param_2 | *local_18) & 0x10100 | uVar8
                        ;
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        iVar5 = DAT_00dca3f8;
                        if (local_8 == 0) goto LAB_006eb9d3;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    do {
                      local_c = (uint *)((int)local_c + local_2c);
                      local_20 = local_20 + local_58;
                      param_3 = (int *)((int)param_3 + local_34);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                local_20 = local_28;
                iVar5 = DAT_00dca3f8;
                if (param_4 == 0) {
                  do {
                    local_20 = local_28;
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_18 = local_1c;
                    while( true ) {
                      uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      iVar5 = iVar6 + (uint)(byte)*local_c * 4;
                      param_2._0_2_ =
                           CONCAT11((char)(*(byte *)(iVar5 + 1) * uVar2 * DAT_00dca3f8 >> 0x10),
                                    (char)(*(byte *)(iVar6 + (uint)(byte)*local_c * 4) * uVar2 *
                                           DAT_00dca3f8 >> 0x10));
                      param_2 = (uint)CONCAT12((char)(*(byte *)(iVar5 + 2) * uVar2 * DAT_00dca3f8 >>
                                                     0x10),(undefined2)param_2);
                      uVar3 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                      uVar2 = uVar3 & 0x1010100;
                      *local_18 = uVar2 - (uVar2 >> 8) | (param_2 | *local_18) & 0x10100 | uVar3;
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                        local_20 = local_20 + local_58;
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006eb616:
                local_28 = local_20;
                local_c = local_10;
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                local_18 = local_1c;
                do {
                  if ((byte)*local_c == uVar2) {
                    do {
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006eb713;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      iVar4 = iVar6 + (uint)(byte)*local_c * 4;
                      param_2._0_2_ =
                           CONCAT11((char)(*(byte *)(iVar4 + 1) * uVar3 * iVar5 >> 0x10),
                                    (char)(*(byte *)(iVar6 + (uint)(byte)*local_c * 4) * uVar3 *
                                           iVar5 >> 0x10));
                      param_2 = (uint)CONCAT12((char)(*(byte *)(iVar4 + 2) * uVar3 * iVar5 >> 0x10),
                                               (undefined2)param_2);
                      uVar11 = (param_2 & 0xfefeff) + (*puVar7 & 0xfefeff);
                      uVar3 = uVar11 & 0x1010100;
                      *local_18 = uVar3 - (uVar3 >> 8) | (param_2 | *puVar7) & 0x10100 | uVar11;
                      puVar7 = local_18 + 1;
                      local_8 = local_8 + -1;
                      iVar5 = DAT_00dca3f8;
                      if (local_8 == 0) goto LAB_006eb713;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_20 = local_20 + local_58;
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                local_18 = local_1c;
                if (param_4 == 0) {
                  do {
                    puVar7 = local_18;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_c = local_10;
                    while( true ) {
                      pbVar19 = (byte *)(iVar6 + (uint)(byte)*local_c * 4);
                      param_2._0_2_ =
                           CONCAT11(*(undefined1 *)
                                     (&DAT_00d0a2e0 +
                                     iVar4 * 0x100 +
                                     (&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)pbVar19[1]]),
                                    *(undefined1 *)
                                     (&DAT_00d0a2e0 +
                                     iVar4 * 0x100 +
                                     (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)*pbVar19]));
                      param_2 = (uint)CONCAT12(*(undefined1 *)
                                                (&DAT_00d0a2e0 +
                                                iVar4 * 0x100 +
                                                (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)pbVar19[2]]),
                                               (undefined2)param_2);
                      uVar2 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                      uVar8 = uVar2 & 0x1010100;
                      *local_18 = uVar8 - (uVar8 >> 8) | (param_2 | *local_18) & 0x10100 | uVar2;
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                      }
                    }
                    local_18 = (uint *)((int)puVar7 + local_48);
                    for (local_14 = local_14 - 0x10000; (int)local_14 < 1;
                        local_14 = local_14 + local_38) {
                      local_10 = (uint *)((int)local_10 + local_3c);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006ebdb0:
                puVar7 = local_18;
                local_8 = local_44;
                param_3 = (int *)local_40;
                local_c = local_10;
                do {
                  if ((byte)*local_c == uVar2) {
                    do {
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006ebe9f;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      pbVar19 = (byte *)(iVar6 + (uint)(byte)*local_c * 4);
                      param_2._0_2_ =
                           CONCAT11(*(undefined1 *)
                                     (&DAT_00d0a2e0 +
                                     iVar4 * 0x100 +
                                     (&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)pbVar19[1]]),
                                    *(undefined1 *)
                                     (&DAT_00d0a2e0 +
                                     iVar4 * 0x100 +
                                     (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)*pbVar19]));
                      param_2 = (uint)CONCAT12(*(undefined1 *)
                                                (&DAT_00d0a2e0 +
                                                iVar4 * 0x100 +
                                                (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)pbVar19[2]]),
                                               (undefined2)param_2);
                      uVar8 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                      uVar14 = uVar8 & 0x1010100;
                      *local_18 = uVar14 - (uVar14 >> 8) | (param_2 | *local_18) & 0x10100 | uVar8;
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006ebe9f;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_c = (uint *)((int)local_c + local_2c);
                    param_3 = (int *)((int)param_3 + local_34);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (param_4 == 0) {
                do {
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                  while( true ) {
                    iVar5 = iVar6 + (uint)(byte)*local_c * 4;
                    param_2._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)*(byte *)(iVar5 + 1)),
                                  *(undefined1 *)
                                   (&DAT_00d0a2e0 +
                                   iVar4 * 0x100 + (uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4)
                                   ));
                    param_2._0_3_ =
                         CONCAT12(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)*(byte *)(iVar5 + 2)),
                                  (undefined2)param_2);
                    param_2 = (uint)(uint3)param_2;
                    uVar3 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                    uVar2 = uVar3 & 0x1010100;
                    *local_18 = uVar2 - (uVar2 >> 8) | (param_2 | *local_18) & 0x10100 | uVar3;
                    local_18 = local_18 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_14 = local_14 + local_38;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006ebbb1:
              local_c = local_10;
              local_8 = local_44;
              param_3 = (int *)local_40;
              puVar7 = local_1c;
              local_18 = local_1c;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ebc69;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    pbVar19 = (byte *)(iVar6 + (uint)(byte)*local_c * 4);
                    param_2._0_2_ =
                         CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)pbVar19[1]),
                                  *(undefined1 *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)*pbVar19));
                    param_2._0_3_ =
                         CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)pbVar19[2]),
                                  (undefined2)param_2);
                    param_2 = (uint)(uint3)param_2;
                    uVar11 = (param_2 & 0xfefeff) + (*puVar7 & 0xfefeff);
                    uVar3 = uVar11 & 0x1010100;
                    *local_18 = uVar3 - (uVar3 >> 8) | (param_2 | *puVar7) & 0x10100 | uVar11;
                    puVar7 = local_18 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ebc69;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                } while ((int)param_3 < 1);
              } while( true );
            }
            break;
          case 3:
            if (param_5 != 0) {
              if ((DAT_00dca3fc & 0xffffff) == 0xffffff) {
                if (param_4 == 0) {
                  local_8 = local_44;
                  local_c = local_10;
                  local_20 = local_28;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  while( true ) {
                    while( true ) {
                      uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      iVar5 = iVar6 + (uint)(byte)*local_c * 4;
                      param_2._0_2_ =
                           CONCAT11((char)(*(byte *)(iVar5 + 1) * uVar2 * DAT_00dca3f8 >> 0x10),
                                    (char)(*(byte *)(iVar6 + (uint)(byte)*local_c * 4) * uVar2 *
                                           DAT_00dca3f8 >> 0x10));
                      param_2 = CONCAT22(CONCAT11(param_2._3_1_,
                                                  (char)(*(byte *)(iVar5 + 2) * uVar2 * DAT_00dca3f8
                                                        >> 0x10)),(undefined2)param_2);
                      uVar3 = (*puVar7 | 0x1010100) - (param_2 & 0xfefefeff);
                      uVar2 = uVar3 & 0x1010100;
                      *puVar7 = uVar2 - (uVar2 >> 8) & uVar3;
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                          local_20 = local_20 + local_58;
                        } while ((int)param_3 < 1);
                      }
                    }
                    puVar7 = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_20 = local_28;
                    local_1c = puVar7;
                    local_c = local_10;
                  }
                  return;
                }
                local_20 = local_28;
                iVar5 = DAT_00dca3f8;
                puVar7 = local_10;
                do {
                  local_28 = local_20;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar9 = local_1c;
                  local_c = puVar7;
                  while ((byte)*local_c == uVar2) {
                    do {
                      puVar9 = puVar9 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006ec121;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
LAB_006ec103:
                    do {
                      local_c = (uint *)((int)local_c + local_2c);
                      param_3 = (int *)((int)param_3 + local_34);
                      local_20 = local_20 + local_58;
                    } while ((int)param_3 < 1);
                    puVar7 = local_10;
                  }
                  while( true ) {
                    uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    iVar4 = iVar6 + (uint)(byte)*local_c * 4;
                    param_2._0_2_ =
                         CONCAT11((char)(*(byte *)(iVar4 + 1) * uVar3 * iVar5 >> 0x10),
                                  (char)(*(byte *)(iVar6 + (uint)(byte)*local_c * 4) * uVar3 * iVar5
                                        >> 0x10));
                    param_2 = CONCAT22(CONCAT11(param_2._3_1_,
                                                (char)(*(byte *)(iVar4 + 2) * uVar3 * iVar5 >> 0x10)
                                               ),(undefined2)param_2);
                    uVar11 = (*puVar9 | 0x1010100) - (param_2 & 0xfefefeff);
                    uVar3 = uVar11 & 0x1010100;
                    *puVar9 = uVar3 - (uVar3 >> 8) & uVar11;
                    puVar9 = puVar9 + 1;
                    local_8 = local_8 + -1;
                    iVar5 = DAT_00dca3f8;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) goto LAB_006ec103;
                  }
                  puVar7 = local_10;
LAB_006ec121:
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      puVar7 = (uint *)((int)puVar7 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                    local_10 = puVar7;
                  }
                  local_24 = local_24 + -1;
                  local_20 = local_28;
                  if (local_24 == 0) {
                    return;
                  }
                } while( true );
              }
              local_18 = local_1c;
              local_c = local_10;
              iVar5 = DAT_00dca3f8;
              if (param_4 == 0) {
                local_20 = local_28;
                local_8 = local_44;
                param_3 = (int *)local_40;
                while( true ) {
                  while( true ) {
                    uVar2 = param_2;
                    uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    pbVar19 = (byte *)(iVar6 + (uint)(byte)*local_c * 4);
                    param_2._0_2_ =
                         CONCAT11((char)((&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)pbVar19[1]] * uVar8 *
                                         DAT_00dca3f8 >> 0x10),
                                  (char)((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)*pbVar19] * uVar8 *
                                         DAT_00dca3f8 >> 0x10));
                    param_2._3_1_ = SUB41(uVar2,3);
                    param_2._0_3_ =
                         CONCAT12((char)((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)pbVar19[2]] * uVar8
                                         * DAT_00dca3f8 >> 0x10),(undefined2)param_2);
                    uVar8 = (*local_18 | 0x1010100) - (param_2 & 0xfefefeff);
                    uVar2 = uVar8 & 0x1010100;
                    *local_18 = uVar2 - (uVar2 >> 8) & uVar8;
                    local_18 = local_18 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_20 = local_20 + local_58;
                      local_c = (uint *)((int)local_c + local_2c);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_14 = local_14 + local_38;
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                  local_c = local_10;
                  local_20 = local_28;
                  if (local_24 == 0) break;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                }
                return;
              }
LAB_006ec2c0:
              puVar7 = local_18;
              local_8 = local_44;
              param_3 = (int *)local_40;
              local_20 = local_28;
              local_c = local_10;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    local_18 = local_18 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ec3d3;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar8 = param_2;
                    uVar14 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    pbVar19 = (byte *)(iVar6 + (uint)(byte)*local_c * 4);
                    param_2._0_2_ =
                         CONCAT11((char)((&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)pbVar19[1]] * uVar14
                                         * iVar5 >> 0x10),
                                  (char)((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)*pbVar19] * uVar14 *
                                         iVar5 >> 0x10));
                    param_2._3_1_ = SUB41(uVar8,3);
                    param_2._0_3_ =
                         CONCAT12((char)((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)pbVar19[2]] * uVar14
                                         * iVar5 >> 0x10),(undefined2)param_2);
                    uVar14 = (*local_18 | 0x1010100) - (param_2 & 0xfefefeff);
                    uVar8 = uVar14 & 0x1010100;
                    *local_18 = uVar8 - (uVar8 >> 8) & uVar14;
                    local_18 = local_18 + 1;
                    local_8 = local_8 + -1;
                    iVar5 = DAT_00dca3f8;
                    if (local_8 == 0) goto LAB_006ec3d3;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                  param_3 = (int *)((int)param_3 + local_34);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
              local_18 = local_1c;
              if (param_4 == 0) {
                do {
                  puVar7 = local_18;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_c = local_10;
                  while( true ) {
                    pbVar19 = (byte *)(iVar6 + (uint)(byte)*local_c * 4);
                    param_2._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 +
                                   iVar4 * 0x100 + (&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)pbVar19[1]]
                                   ),*(undefined1 *)
                                      (&DAT_00d0a2e0 +
                                      iVar4 * 0x100 +
                                      (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)*pbVar19]));
                    param_2 = CONCAT22(CONCAT11(param_2._3_1_,
                                                *(undefined1 *)
                                                 (&DAT_00d0a2e0 +
                                                 iVar4 * 0x100 +
                                                 (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)pbVar19[2]])
                                               ),(undefined2)param_2);
                    uVar2 = (*local_18 | 0x1010100) - (param_2 & 0xfefefeff);
                    uVar8 = uVar2 & 0x1010100;
                    *local_18 = uVar8 - (uVar8 >> 8) & uVar2;
                    local_18 = local_18 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_c = (uint *)((int)local_c + local_2c);
                    }
                  }
                  local_18 = (uint *)((int)puVar7 + local_48);
                  for (local_14 = local_14 - 0x10000; (int)local_14 < 1;
                      local_14 = local_14 + local_38) {
                    local_10 = (uint *)((int)local_10 + local_3c);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006ec9b0:
              puVar7 = local_18;
              local_8 = local_44;
              param_3 = (int *)local_40;
              local_c = local_10;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    local_18 = local_18 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006eca8e;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    pbVar19 = (byte *)(iVar6 + (uint)(byte)*local_c * 4);
                    param_2._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 +
                                   iVar4 * 0x100 + (&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)pbVar19[1]]
                                   ),*(undefined1 *)
                                      (&DAT_00d0a2e0 +
                                      iVar4 * 0x100 +
                                      (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)*pbVar19]));
                    param_2 = CONCAT22(CONCAT11(param_2._3_1_,
                                                *(undefined1 *)
                                                 (&DAT_00d0a2e0 +
                                                 iVar4 * 0x100 +
                                                 (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)pbVar19[2]])
                                               ),(undefined2)param_2);
                    uVar8 = (*local_18 | 0x1010100) - (param_2 & 0xfefefeff);
                    uVar14 = uVar8 & 0x1010100;
                    *local_18 = uVar14 - (uVar14 >> 8) & uVar8;
                    local_18 = local_18 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006eca8e;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  local_c = (uint *)((int)local_c + local_2c);
                  param_3 = (int *)((int)param_3 + local_34);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if (param_4 == 0) {
              if (DAT_00dca3f8 != 0xff) {
                do {
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  while( true ) {
                    uVar2 = param_2;
                    iVar5 = iVar6 + (uint)(byte)*local_c * 4;
                    param_2._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)*(byte *)(iVar5 + 1)),
                                  *(undefined1 *)
                                   (&DAT_00d0a2e0 +
                                   iVar4 * 0x100 + (uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4)
                                   ));
                    param_2._3_1_ = SUB41(uVar2,3);
                    param_2._0_3_ =
                         CONCAT12(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)*(byte *)(iVar5 + 2)),
                                  (undefined2)param_2);
                    uVar3 = (*puVar7 | 0x1010100) - (param_2 & 0xfefefeff);
                    uVar2 = uVar3 & 0x1010100;
                    *puVar7 = uVar2 - (uVar2 >> 8) & uVar3;
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_14 = local_14 + local_38;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
              if (DAT_00a2e8cc != 1) {
                do {
                  local_8 = local_44;
                  iVar6 = local_40;
                  puVar7 = local_10;
                  while( true ) {
                    uVar3 = (*local_1c | 0x1010100) -
                            (*(uint *)(&DAT_00f400d8 + (uint)(byte)*puVar7 * 4) & 0xfefeff);
                    uVar2 = uVar3 & 0x1010100;
                    *local_1c = uVar3 & uVar2 - (uVar2 >> 8);
                    local_1c = local_1c + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    iVar4 = iVar6 + -0x10000;
                    bVar20 = iVar6 < 0x10000;
                    iVar6 = iVar4;
                    if (iVar4 == 0 || bVar20) {
                      do {
                        puVar7 = (uint *)((int)puVar7 + local_2c);
                        bVar20 = SCARRY4(iVar4,local_34);
                        iVar4 = iVar4 + local_34;
                        iVar6 = iVar4;
                      } while (bVar20 != iVar4 < 0);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + iVar5);
                  bVar20 = local_14 < 0x10000;
                  local_14 = local_14 - 0x10000;
                  if (bVar20 || local_14 == 0) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      bVar20 = SCARRY4(local_14,local_38);
                      local_14 = local_14 + local_38;
                    } while (bVar20 != (int)local_14 < 0);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
              do {
                iVar6 = local_44;
                iVar4 = local_40;
                puVar7 = local_10;
LAB_006ec7da:
                uVar2 = *(uint *)(&DAT_00f400d8 + (uint)(byte)*puVar7 * 4);
                iVar13 = iVar4;
                while( true ) {
                  uVar21 = psubusb((ulonglong)*local_1c,(ulonglong)uVar2);
                  *local_1c = (uint)uVar21;
                  local_1c = local_1c + 1;
                  iVar6 = iVar6 + -1;
                  if (iVar6 == 0) break;
                  iVar4 = iVar13 + -0x10000;
                  bVar20 = iVar13 < 0x10000;
                  iVar13 = iVar4;
                  if (iVar4 == 0 || bVar20) goto LAB_006ec7fc;
                }
                local_1c = (uint *)((int)local_1c + iVar5);
                bVar20 = local_14 < 0x10000;
                local_14 = local_14 - 0x10000;
                if (bVar20 || local_14 == 0) {
                  do {
                    local_10 = (uint *)((int)local_10 + local_3c);
                    bVar20 = SCARRY4(local_14,local_38);
                    local_14 = local_14 + local_38;
                  } while (bVar20 != (int)local_14 < 0);
                }
                local_24 = local_24 + -1;
                if (local_24 == 0) {
                  return;
                }
              } while( true );
            }
            if (DAT_00dca3f8 != 0xff) {
LAB_006ec6c4:
              local_c = local_10;
              local_8 = local_44;
              param_3 = (int *)local_40;
              puVar7 = local_1c;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ec772;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar3 = param_2;
                    pbVar19 = (byte *)(iVar6 + (uint)(byte)*local_c * 4);
                    param_2._0_2_ =
                         CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)pbVar19[1]),
                                  *(undefined1 *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)*pbVar19));
                    param_2._3_1_ = SUB41(uVar3,3);
                    param_2._0_3_ =
                         CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)pbVar19[2]),
                                  (undefined2)param_2);
                    uVar11 = (*puVar7 | 0x1010100) - (param_2 & 0xfefefeff);
                    uVar3 = uVar11 & 0x1010100;
                    *puVar7 = uVar3 - (uVar3 >> 8) & uVar11;
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ec772;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if (DAT_00a2e8cc != 1) {
              do {
                local_8 = local_44;
                iVar6 = local_40;
                puVar7 = local_10;
                while( true ) {
                  if ((byte)*puVar7 != local_50) {
                    uVar3 = (*local_1c | 0x1010100) -
                            (*(uint *)(&DAT_00f400d8 + (uint)(byte)*puVar7 * 4) & 0xfefeff);
                    uVar2 = uVar3 & 0x1010100;
                    *local_1c = uVar3 & uVar2 - (uVar2 >> 8);
                  }
                  local_1c = local_1c + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) break;
                  iVar4 = iVar6 + -0x10000;
                  bVar20 = iVar6 < 0x10000;
                  iVar6 = iVar4;
                  if (iVar4 == 0 || bVar20) {
                    do {
                      puVar7 = (uint *)((int)puVar7 + local_2c);
                      bVar20 = SCARRY4(iVar4,local_34);
                      iVar4 = iVar4 + local_34;
                      iVar6 = iVar4;
                    } while (bVar20 != iVar4 < 0);
                  }
                }
                local_1c = (uint *)((int)local_1c + iVar5);
                bVar20 = local_14 < 0x10000;
                local_14 = local_14 - 0x10000;
                if (bVar20 || local_14 == 0) {
                  do {
                    local_10 = (uint *)((int)local_10 + local_3c);
                    bVar20 = SCARRY4(local_14,local_38);
                    local_14 = local_14 + local_38;
                  } while (bVar20 != (int)local_14 < 0);
                }
                local_24 = local_24 + -1;
              } while (local_24 != 0);
              return;
            }
LAB_006ec5b9:
            iVar6 = local_44;
            iVar4 = local_40;
            puVar7 = local_10;
            do {
              while( true ) {
                iVar13 = iVar4;
                if ((byte)*puVar7 != local_50) break;
                do {
                  local_1c = local_1c + 1;
                  iVar6 = iVar6 + -1;
                  if (iVar6 == 0) goto LAB_006ec608;
                  iVar4 = iVar13 + -0x10000;
                  bVar20 = 0xffff < iVar13;
                  iVar13 = iVar4;
                } while (iVar4 != 0 && bVar20);
                do {
                  puVar7 = (uint *)((int)puVar7 + local_2c);
                  bVar20 = SCARRY4(iVar4,local_34);
                  iVar4 = iVar4 + local_34;
                } while (bVar20 != iVar4 < 0);
              }
              uVar2 = *(uint *)(&DAT_00f400d8 + (uint)(byte)*puVar7 * 4);
              do {
                uVar21 = psubusb((ulonglong)*local_1c,(ulonglong)uVar2);
                *local_1c = (uint)uVar21;
                local_1c = local_1c + 1;
                iVar6 = iVar6 + -1;
                if (iVar6 == 0) goto LAB_006ec608;
                iVar4 = iVar13 + -0x10000;
                bVar20 = 0xffff < iVar13;
                iVar13 = iVar4;
              } while (iVar4 != 0 && bVar20);
              do {
                puVar7 = (uint *)((int)puVar7 + local_2c);
                bVar20 = SCARRY4(iVar4,local_34);
                iVar4 = iVar4 + local_34;
              } while (bVar20 != iVar4 < 0);
            } while( true );
          case 4:
            if (param_5 == 0) {
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                local_c = local_10;
                if (param_4 == 0) {
                  do {
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_18 = local_1c;
                    local_c = local_10;
                    while( true ) {
                      *(byte *)local_18 =
                           (byte)((uint)(byte)*local_18 *
                                  (&DAT_00d0a2e0)
                                  [uVar11 * 0x100 +
                                   (uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4)] >> 8);
                      *(byte *)((int)local_18 + 1) =
                           (byte)((uint)*(byte *)((int)local_18 + 1) *
                                  (&DAT_00d0a2e0)
                                  [uVar3 * 0x100 +
                                   (uint)*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4)] >> 8);
                      *(byte *)((int)local_18 + 2) =
                           (byte)((uint)*(byte *)((int)local_18 + 2) *
                                  (&DAT_00d0a2e0)
                                  [uVar18 * 0x100 +
                                   (uint)*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4)] >> 8);
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    for (local_14 = local_14 - 0x10000; (int)local_14 < 1;
                        local_14 = local_14 + local_38) {
                      local_10 = (uint *)((int)local_10 + local_3c);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006ed273:
                local_10 = local_c;
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                local_18 = local_1c;
                do {
                  if ((byte)*local_c == uVar2) {
                    do {
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006ed338;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      *(byte *)local_18 =
                           (byte)((uint)(byte)*puVar7 *
                                  (&DAT_00d0a2e0)
                                  [uVar11 * 0x100 +
                                   (uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4)] >> 8);
                      *(byte *)((int)local_18 + 1) =
                           (byte)((uint)*(byte *)((int)local_18 + 1) *
                                  (&DAT_00d0a2e0)
                                  [uVar3 * 0x100 +
                                   (uint)*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4)] >> 8);
                      *(byte *)((int)local_18 + 2) =
                           (byte)((uint)*(byte *)((int)local_18 + 2) *
                                  (&DAT_00d0a2e0)
                                  [uVar18 * 0x100 +
                                   (uint)*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4)] >> 8);
                      puVar7 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006ed338;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar7;
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_c = (uint *)((int)local_c + local_2c);
                    param_3 = (int *)((int)param_3 + local_34);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (param_4 == 0) {
                do {
                  local_8 = local_44;
                  puVar9 = local_1c;
                  puVar7 = local_10;
                  iVar5 = local_40;
                  while( true ) {
                    *(byte *)puVar9 =
                         (byte)((uint)*(byte *)(iVar6 + (uint)(byte)*puVar7 * 4) *
                                (uint)(byte)*puVar9 >> 8);
                    *(byte *)((int)puVar9 + 1) =
                         (byte)((uint)*(byte *)(iVar6 + 1 + (uint)(byte)*puVar7 * 4) *
                                (uint)*(byte *)((int)puVar9 + 1) >> 8);
                    *(byte *)((int)puVar9 + 2) =
                         (byte)((uint)*(byte *)(iVar6 + 2 + (uint)(byte)*puVar7 * 4) *
                                (uint)*(byte *)((int)puVar9 + 2) >> 8);
                    puVar9 = puVar9 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (iVar5 = iVar5 + -0x10000; iVar5 < 1; iVar5 = iVar5 + local_34) {
                      puVar7 = (uint *)((int)puVar7 + local_2c);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006ed0c1:
              local_8 = local_44;
              puVar7 = local_1c;
              puVar9 = local_10;
              iVar5 = local_40;
              do {
                if ((byte)*puVar9 == uVar2) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ed165;
                    iVar5 = iVar5 + -0x10000;
                  } while (0 < iVar5);
                }
                else {
                  do {
                    *(byte *)puVar7 =
                         (byte)((uint)*(byte *)(iVar6 + (uint)(byte)*puVar9 * 4) *
                                (uint)(byte)*puVar7 >> 8);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((uint)*(byte *)(iVar6 + 1 + (uint)(byte)*puVar9 * 4) *
                                (uint)*(byte *)((int)puVar7 + 1) >> 8);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((uint)*(byte *)(iVar6 + 2 + (uint)(byte)*puVar9 * 4) *
                                (uint)*(byte *)((int)puVar7 + 2) >> 8);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ed165;
                    iVar5 = iVar5 + -0x10000;
                  } while (0 < iVar5);
                }
                do {
                  iVar5 = iVar5 + local_34;
                  puVar9 = (uint *)((int)puVar9 + local_2c);
                } while (iVar5 < 1);
              } while( true );
            }
            if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
              local_18 = local_1c;
              if (param_4 == 0) {
                do {
                  puVar7 = local_18;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_20 = local_28;
                  local_c = local_10;
                  while( true ) {
                    *(byte *)local_18 =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (&DAT_00d0a2e0)
                                [uVar11 * 0x100 + (uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4)]
                                * (uint)(byte)*local_18 >> 0x10);
                    *(byte *)((int)local_18 + 1) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (&DAT_00d0a2e0)
                                [uVar3 * 0x100 +
                                 (uint)*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4)] *
                                (uint)*(byte *)((int)local_18 + 1) >> 0x10);
                    *(byte *)((int)local_18 + 2) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (&DAT_00d0a2e0)
                                [uVar18 * 0x100 +
                                 (uint)*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4)] *
                                (uint)*(byte *)((int)local_18 + 2) >> 0x10);
                    local_18 = local_18 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        local_20 = local_20 + local_58;
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_18 = (uint *)((int)puVar7 + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_14 = local_14 + local_38;
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006ece23:
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              local_20 = local_28;
              local_18 = local_1c;
              local_c = local_10;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ecf1e;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    *(byte *)local_18 =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (&DAT_00d0a2e0)
                                [uVar11 * 0x100 + (uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4)]
                                * (uint)(byte)*local_18 >> 0x10);
                    *(byte *)((int)local_18 + 1) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (&DAT_00d0a2e0)
                                [uVar3 * 0x100 +
                                 (uint)*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4)] *
                                (uint)*(byte *)((int)local_18 + 1) >> 0x10);
                    *(byte *)((int)local_18 + 2) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (&DAT_00d0a2e0)
                                [uVar18 * 0x100 +
                                 (uint)*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4)] *
                                (uint)*(byte *)((int)local_18 + 2) >> 0x10);
                    puVar7 = local_18 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ecf1e;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    local_18 = puVar7;
                  } while (0 < (int)param_3);
                }
                do {
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                  param_3 = (int *)((int)param_3 + local_34);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if (param_4 == 0) {
              do {
                local_8 = local_44;
                puVar7 = local_1c;
                puVar9 = local_10;
                param_3 = (int *)local_40;
                pbVar19 = local_28;
                while( true ) {
                  *(byte *)puVar7 =
                       (byte)((uint)*(byte *)(iVar6 + (uint)(byte)*puVar9 * 4) *
                              (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * (uint)(byte)*puVar7 >> 0x10);
                  *(byte *)((int)puVar7 + 1) =
                       (byte)((uint)*(byte *)(iVar6 + 1 + (uint)(byte)*puVar9 * 4) *
                              (uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              (uint)*(byte *)((int)puVar7 + 1) >> 0x10);
                  *(byte *)((int)puVar7 + 2) =
                       (byte)((uint)*(byte *)(iVar6 + 2 + (uint)(byte)*puVar9 * 4) *
                              (uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              (uint)*(byte *)((int)puVar7 + 2) >> 0x10);
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) break;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  if ((int)param_3 < 1) {
                    do {
                      puVar9 = (uint *)((int)puVar9 + local_2c);
                      pbVar19 = pbVar19 + local_58;
                      param_3 = (int *)((int)param_3 + local_34);
                    } while ((int)param_3 < 1);
                  }
                }
                local_1c = (uint *)((int)local_1c + local_48);
                local_14 = local_14 - 0x10000;
                if ((int)local_14 < 1) {
                  do {
                    local_14 = local_14 + local_38;
                    local_10 = (uint *)((int)local_10 + local_3c);
                    local_28 = local_28 + local_5c;
                  } while ((int)local_14 < 1);
                }
                local_24 = local_24 + -1;
              } while (local_24 != 0);
              return;
            }
LAB_006ecc10:
            local_8 = local_44;
            puVar7 = local_1c;
            puVar9 = local_10;
            param_3 = (int *)local_40;
            pbVar19 = local_28;
            do {
              if ((byte)*puVar9 == uVar2) {
                do {
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006eccd8;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              else {
                do {
                  *(byte *)puVar7 =
                       (byte)((uint)*(byte *)(iVar6 + (uint)(byte)*puVar9 * 4) *
                              (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * (uint)(byte)*puVar7 >> 0x10);
                  *(byte *)((int)puVar7 + 1) =
                       (byte)((uint)*(byte *)(iVar6 + 1 + (uint)(byte)*puVar9 * 4) *
                              (uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              (uint)*(byte *)((int)puVar7 + 1) >> 0x10);
                  *(byte *)((int)puVar7 + 2) =
                       (byte)((uint)*(byte *)(iVar6 + 2 + (uint)(byte)*puVar9 * 4) *
                              (uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              (uint)*(byte *)((int)puVar7 + 2) >> 0x10);
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006eccd8;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              do {
                puVar9 = (uint *)((int)puVar9 + local_2c);
                pbVar19 = pbVar19 + local_58;
                param_3 = (int *)((int)param_3 + local_34);
              } while ((int)param_3 < 1);
            } while( true );
          case 10:
            if (param_5 != 0) {
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                local_18 = local_1c;
                iVar5 = DAT_00dca3f8;
                if (param_4 == 0) {
                  local_c = local_10;
                  local_20 = local_28;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  while( true ) {
                    while( true ) {
                      *(byte *)local_18 =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar11 * 0x100 +
                                                  (uint)(byte)~*(byte *)(iVar6 + (uint)(byte)*
                                                  local_c * 4)) - (uint)(byte)*local_18) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                  (uint)(byte)*local_18 * 0x10000 >> 0x10);
                      *(byte *)((int)local_18 + 1) =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar3 * 0x100 +
                                                  (uint)(byte)~*(byte *)(iVar6 + 1 +
                                                                        (uint)(byte)*local_c * 4)) -
                                  (uint)*(byte *)((int)local_18 + 1)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)local_18 + 1) * 0x10000 >> 0x10);
                      *(byte *)((int)local_18 + 2) =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar18 * 0x100 +
                                                  (uint)(byte)~*(byte *)(iVar6 + 2 +
                                                                        (uint)(byte)*local_c * 4)) -
                                  (uint)*(byte *)((int)local_18 + 2)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)local_18 + 2) * 0x10000 >> 0x10);
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                        local_20 = local_20 + local_58;
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    for (local_14 = local_14 - 0x10000; (int)local_14 < 1;
                        local_14 = local_14 + local_38) {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_20 = local_28;
                    local_18 = local_1c;
                    local_c = local_10;
                  }
                  return;
                }
LAB_006ee320:
                puVar7 = local_18;
                local_8 = local_44;
                param_3 = (int *)local_40;
                local_20 = local_28;
                local_c = local_10;
                do {
                  if ((byte)*local_c == uVar2) {
                    do {
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006ee46a;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      *(byte *)local_18 =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar11 * 0x100 +
                                                  (uint)(byte)~*(byte *)(iVar6 + (uint)(byte)*
                                                  local_c * 4)) - (uint)(byte)*local_18) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] * iVar5 +
                                  (uint)(byte)*local_18 * 0x10000 >> 0x10);
                      *(byte *)((int)local_18 + 1) =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar3 * 0x100 +
                                                  (uint)(byte)~*(byte *)(iVar6 + 1 +
                                                                        (uint)(byte)*local_c * 4)) -
                                  (uint)*(byte *)((int)local_18 + 1)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)local_18 + 1) * 0x10000 >> 0x10);
                      *(byte *)((int)local_18 + 2) =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar18 * 0x100 +
                                                  (uint)(byte)~*(byte *)(iVar6 + 2 +
                                                                        (uint)(byte)*local_c * 4)) -
                                  (uint)*(byte *)((int)local_18 + 2)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)local_18 + 2) * 0x10000 >> 0x10);
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      iVar5 = DAT_00dca3f8;
                      if (local_8 == 0) goto LAB_006ee46a;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_c = (uint *)((int)local_c + local_2c);
                    local_20 = local_20 + local_58;
                    param_3 = (int *)((int)param_3 + local_34);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              local_c = local_10;
              if (param_4 == 0) {
                local_8 = local_44;
                local_20 = local_28;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                while( true ) {
                  while( true ) {
                    *(byte *)puVar7 =
                         (byte)(((uint)(byte)~*(byte *)(iVar6 + (uint)(byte)*local_c * 4) -
                                (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                DAT_00dca3f8 + (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)(((uint)(byte)~*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4) -
                                (uint)*(byte *)((int)puVar7 + 1)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)(((uint)(byte)~*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4) -
                                (uint)*(byte *)((int)puVar7 + 2)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_c = (uint *)((int)local_c + local_2c);
                      local_20 = local_20 + local_58;
                    }
                  }
                  puVar7 = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                  if (local_24 == 0) break;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_20 = local_28;
                  local_1c = puVar7;
                  local_c = local_10;
                }
                return;
              }
              local_20 = local_28;
              iVar5 = DAT_00dca3f8;
LAB_006ee030:
              local_28 = local_20;
              local_c = local_10;
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ee149;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    *(byte *)puVar7 =
                         (byte)(((uint)(byte)~*(byte *)(iVar6 + (uint)(byte)*local_c * 4) -
                                (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                iVar5 + (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)(((uint)(byte)~*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4) -
                                (uint)*(byte *)((int)puVar7 + 1)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)(((uint)(byte)~*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4) -
                                (uint)*(byte *)((int)puVar7 + 2)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    iVar5 = DAT_00dca3f8;
                    if (local_8 == 0) goto LAB_006ee149;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  local_20 = local_20 + local_58;
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
              local_18 = local_1c;
              iVar5 = DAT_00dca3f8;
              if (param_4 == 0) {
                local_c = local_10;
                local_8 = local_44;
                param_3 = (int *)local_40;
                while( true ) {
                  while( true ) {
                    *(byte *)local_18 =
                         (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                uVar11 * 0x100 +
                                                (uint)(byte)~*(byte *)(iVar6 + (uint)(byte)*local_c
                                                                               * 4)) -
                                (uint)(byte)*local_18) * DAT_00dca3f8 +
                                (uint)(byte)*local_18 * 0x100 >> 8);
                    *(byte *)((int)local_18 + 1) =
                         (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                uVar3 * 0x100 +
                                                (uint)(byte)~*(byte *)(iVar6 + 1 +
                                                                      (uint)(byte)*local_c * 4)) -
                                (uint)*(byte *)((int)local_18 + 1)) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)local_18 + 1) * 0x100 >> 8);
                    *(byte *)((int)local_18 + 2) =
                         (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                uVar18 * 0x100 +
                                                (uint)(byte)~*(byte *)(iVar6 + 2 +
                                                                      (uint)(byte)*local_c * 4)) -
                                (uint)*(byte *)((int)local_18 + 2)) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)local_18 + 2) * 0x100 >> 8);
                    local_18 = local_18 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_c = (uint *)((int)local_c + local_2c);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  for (local_14 = local_14 - 0x10000; (int)local_14 < 1;
                      local_14 = local_14 + local_38) {
                    local_10 = (uint *)((int)local_10 + local_3c);
                  }
                  local_24 = local_24 + -1;
                  if (local_24 == 0) break;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                  local_c = local_10;
                }
                return;
              }
LAB_006ee8a0:
              puVar7 = local_18;
              local_8 = local_44;
              param_3 = (int *)local_40;
              local_c = local_10;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    local_18 = local_18 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ee9ad;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    *(byte *)local_18 =
                         (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                uVar11 * 0x100 +
                                                (uint)(byte)~*(byte *)(iVar6 + (uint)(byte)*local_c
                                                                               * 4)) -
                                (uint)(byte)*local_18) * iVar5 + (uint)(byte)*local_18 * 0x100 >> 8)
                    ;
                    *(byte *)((int)local_18 + 1) =
                         (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                uVar3 * 0x100 +
                                                (uint)(byte)~*(byte *)(iVar6 + 1 +
                                                                      (uint)(byte)*local_c * 4)) -
                                (uint)*(byte *)((int)local_18 + 1)) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)local_18 + 1) * 0x100 >> 8);
                    *(byte *)((int)local_18 + 2) =
                         (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                uVar18 * 0x100 +
                                                (uint)(byte)~*(byte *)(iVar6 + 2 +
                                                                      (uint)(byte)*local_c * 4)) -
                                (uint)*(byte *)((int)local_18 + 2)) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)local_18 + 2) * 0x100 >> 8);
                    local_18 = local_18 + 1;
                    local_8 = local_8 + -1;
                    iVar5 = DAT_00dca3f8;
                    if (local_8 == 0) goto LAB_006ee9ad;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  local_c = (uint *)((int)local_c + local_2c);
                  param_3 = (int *)((int)param_3 + local_34);
                } while ((int)param_3 < 1);
              } while( true );
            }
            iVar5 = DAT_00dca3f8;
            if (param_4 == 0) {
              do {
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                puVar9 = local_10;
                while( true ) {
                  *(byte *)puVar7 =
                       (byte)(((uint)(byte)~*(byte *)(iVar6 + (uint)(byte)*puVar9 * 4) -
                              (uint)(byte)*puVar7) * DAT_00dca3f8 + (uint)(byte)*puVar7 * 0x100 >> 8
                             );
                  *(byte *)((int)puVar7 + 1) =
                       (byte)(((uint)(byte)~*(byte *)(iVar6 + 1 + (uint)(byte)*puVar9 * 4) -
                              (uint)*(byte *)((int)puVar7 + 1)) * DAT_00dca3f8 +
                              (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                  *(byte *)((int)puVar7 + 2) =
                       (byte)(((uint)(byte)~*(byte *)(iVar6 + 2 + (uint)(byte)*puVar9 * 4) -
                              (uint)*(byte *)((int)puVar7 + 2)) * DAT_00dca3f8 +
                              (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) break;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  if ((int)param_3 < 1) {
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      puVar9 = (uint *)((int)puVar9 + local_2c);
                    } while ((int)param_3 < 1);
                  }
                }
                local_1c = (uint *)((int)local_1c + local_48);
                local_14 = local_14 - 0x10000;
                if ((int)local_14 < 1) {
                  do {
                    local_14 = local_14 + local_38;
                    local_10 = (uint *)((int)local_10 + local_3c);
                  } while ((int)local_14 < 1);
                }
                local_24 = local_24 + -1;
              } while (local_24 != 0);
              return;
            }
LAB_006ee675:
            local_8 = local_44;
            puVar7 = local_1c;
            puVar9 = local_10;
            param_3 = (int *)local_40;
            do {
              if ((byte)*puVar9 == uVar2) {
                do {
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006ee744;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              else {
                do {
                  *(byte *)puVar7 =
                       (byte)(((uint)(byte)~*(byte *)(iVar6 + (uint)(byte)*puVar9 * 4) -
                              (uint)(byte)*puVar7) * iVar5 + (uint)(byte)*puVar7 * 0x100 >> 8);
                  *(byte *)((int)puVar7 + 1) =
                       (byte)(((uint)(byte)~*(byte *)(iVar6 + 1 + (uint)(byte)*puVar9 * 4) -
                              (uint)*(byte *)((int)puVar7 + 1)) * DAT_00dca3f8 +
                              (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                  *(byte *)((int)puVar7 + 2) =
                       (byte)(((uint)(byte)~*(byte *)(iVar6 + 2 + (uint)(byte)*puVar9 * 4) -
                              (uint)*(byte *)((int)puVar7 + 2)) * DAT_00dca3f8 +
                              (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  iVar5 = DAT_00dca3f8;
                  if (local_8 == 0) goto LAB_006ee744;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              do {
                puVar9 = (uint *)((int)puVar9 + local_2c);
                param_3 = (int *)((int)param_3 + local_34);
              } while ((int)param_3 < 1);
            } while( true );
          case 0xb:
            if (param_5 != 0) {
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                local_18 = local_1c;
                iVar5 = DAT_00dca3f8;
                if (param_4 == 0) {
                  local_c = local_10;
                  local_20 = local_28;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  while( true ) {
                    while( true ) {
                      uVar2 = (uint)(byte)*local_18;
                      *(byte *)local_18 =
                           (byte)((((&DAT_00d0a2e0)
                                    [uVar11 * 0x100 +
                                     (uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4)] * uVar2 >> 8
                                   & 0xff) - uVar2) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  DAT_00dca3f8 + uVar2 * 0x10000 >> 0x10);
                      uVar2 = (uint)*(byte *)((int)local_18 + 1);
                      *(byte *)((int)local_18 + 1) =
                           (byte)((((&DAT_00d0a2e0)
                                    [uVar3 * 0x100 +
                                     (uint)*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4)] * uVar2
                                    >> 8 & 0xff) - uVar2) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  DAT_00dca3f8 + uVar2 * 0x10000 >> 0x10);
                      uVar2 = (uint)*(byte *)((int)local_18 + 2);
                      *(byte *)((int)local_18 + 2) =
                           (byte)((((&DAT_00d0a2e0)
                                    [uVar18 * 0x100 +
                                     (uint)*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4)] * uVar2
                                    >> 8 & 0xff) - uVar2) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  DAT_00dca3f8 + uVar2 * 0x10000 >> 0x10);
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                        local_20 = local_20 + local_58;
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    for (local_14 = local_14 - 0x10000; (int)local_14 < 1;
                        local_14 = local_14 + local_38) {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_20 = local_28;
                    local_18 = local_1c;
                    local_c = local_10;
                  }
                  return;
                }
LAB_006ed7b0:
                puVar7 = local_18;
                local_8 = local_44;
                param_3 = (int *)local_40;
                local_20 = local_28;
                local_c = local_10;
                do {
                  if ((byte)*local_c == uVar2) {
                    do {
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006ed903;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar8 = (uint)(byte)*local_18;
                      *(byte *)local_18 =
                           (byte)((((&DAT_00d0a2e0)
                                    [uVar11 * 0x100 +
                                     (uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4)] * uVar8 >> 8
                                   & 0xff) - uVar8) * (uint)(byte)(&DAT_00dca2e0)[*local_20] * iVar5
                                  + uVar8 * 0x10000 >> 0x10);
                      uVar8 = (uint)*(byte *)((int)local_18 + 1);
                      *(byte *)((int)local_18 + 1) =
                           (byte)((((&DAT_00d0a2e0)
                                    [uVar3 * 0x100 +
                                     (uint)*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4)] * uVar8
                                    >> 8 & 0xff) - uVar8) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  DAT_00dca3f8 + uVar8 * 0x10000 >> 0x10);
                      uVar8 = (uint)*(byte *)((int)local_18 + 2);
                      *(byte *)((int)local_18 + 2) =
                           (byte)((((&DAT_00d0a2e0)
                                    [uVar18 * 0x100 +
                                     (uint)*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4)] * uVar8
                                    >> 8 & 0xff) - uVar8) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  DAT_00dca3f8 + uVar8 * 0x10000 >> 0x10);
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      iVar5 = DAT_00dca3f8;
                      if (local_8 == 0) goto LAB_006ed903;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_c = (uint *)((int)local_c + local_2c);
                    local_20 = local_20 + local_58;
                    param_3 = (int *)((int)param_3 + local_34);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              local_c = local_10;
              if (param_4 == 0) {
                local_8 = local_44;
                local_20 = local_28;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                while( true ) {
                  while( true ) {
                    uVar2 = (uint)(byte)*puVar7;
                    *(byte *)puVar7 =
                         (byte)((((int)(*(byte *)(iVar6 + (uint)(byte)*local_c * 4) * uVar2) >> 8) -
                                uVar2) * (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                uVar2 * 0x10000 >> 0x10);
                    uVar2 = (uint)*(byte *)((int)puVar7 + 1);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((((int)(*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4) * uVar2) >>
                                 8) - uVar2) * (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8
                                + uVar2 * 0x10000 >> 0x10);
                    uVar2 = (uint)*(byte *)((int)puVar7 + 2);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((((int)(*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4) * uVar2) >>
                                 8) - uVar2) * (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8
                                + uVar2 * 0x10000 >> 0x10);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_c = (uint *)((int)local_c + local_2c);
                      local_20 = local_20 + local_58;
                    }
                  }
                  puVar7 = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                  if (local_24 == 0) break;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_20 = local_28;
                  local_1c = puVar7;
                  local_c = local_10;
                }
                return;
              }
              local_20 = local_28;
              iVar5 = DAT_00dca3f8;
LAB_006ed4a0:
              local_28 = local_20;
              local_c = local_10;
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ed5c9;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar3 = (uint)(byte)*puVar7;
                    *(byte *)puVar7 =
                         (byte)((((int)(*(byte *)(iVar6 + (uint)(byte)*local_c * 4) * uVar3) >> 8) -
                                uVar3) * (uint)(byte)(&DAT_00dca2e0)[*local_20] * iVar5 +
                                uVar3 * 0x10000 >> 0x10);
                    uVar3 = (uint)*(byte *)((int)puVar7 + 1);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((((int)(*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4) * uVar3) >>
                                 8) - uVar3) * (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8
                                + uVar3 * 0x10000 >> 0x10);
                    uVar3 = (uint)*(byte *)((int)puVar7 + 2);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((((int)(*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4) * uVar3) >>
                                 8) - uVar3) * (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8
                                + uVar3 * 0x10000 >> 0x10);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    iVar5 = DAT_00dca3f8;
                    if (local_8 == 0) goto LAB_006ed5c9;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  local_20 = local_20 + local_58;
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
              local_18 = local_1c;
              iVar5 = DAT_00dca3f8;
              if (param_4 == 0) {
                local_c = local_10;
                local_8 = local_44;
                param_3 = (int *)local_40;
                while( true ) {
                  while( true ) {
                    uVar2 = (uint)(byte)*local_18;
                    *(byte *)local_18 =
                         (byte)((((&DAT_00d0a2e0)
                                  [uVar11 * 0x100 +
                                   (uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4)] * uVar2 >> 8 &
                                 0xff) - uVar2) * DAT_00dca3f8 + uVar2 * 0x100 >> 8);
                    uVar2 = (uint)*(byte *)((int)local_18 + 1);
                    *(byte *)((int)local_18 + 1) =
                         (byte)((((&DAT_00d0a2e0)
                                  [uVar3 * 0x100 +
                                   (uint)*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4)] * uVar2 >>
                                  8 & 0xff) - uVar2) * DAT_00dca3f8 + uVar2 * 0x100 >> 8);
                    uVar2 = (uint)*(byte *)((int)local_18 + 2);
                    *(byte *)((int)local_18 + 2) =
                         (byte)((((&DAT_00d0a2e0)
                                  [uVar18 * 0x100 +
                                   (uint)*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4)] * uVar2 >>
                                  8 & 0xff) - uVar2) * DAT_00dca3f8 + uVar2 * 0x100 >> 8);
                    local_18 = local_18 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_c = (uint *)((int)local_c + local_2c);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  for (local_14 = local_14 - 0x10000; (int)local_14 < 1;
                      local_14 = local_14 + local_38) {
                    local_10 = (uint *)((int)local_10 + local_3c);
                  }
                  local_24 = local_24 + -1;
                  if (local_24 == 0) break;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_18 = local_1c;
                  local_c = local_10;
                }
                return;
              }
LAB_006edd56:
              puVar7 = local_18;
              local_8 = local_44;
              param_3 = (int *)local_40;
              local_c = local_10;
              do {
                if ((byte)*local_c == uVar2) {
                  do {
                    local_18 = local_18 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ede64;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar8 = (uint)(byte)*local_18;
                    *(byte *)local_18 =
                         (byte)((((&DAT_00d0a2e0)
                                  [uVar11 * 0x100 +
                                   (uint)*(byte *)(iVar6 + (uint)(byte)*local_c * 4)] * uVar8 >> 8 &
                                 0xff) - uVar8) * iVar5 + uVar8 * 0x100 >> 8);
                    uVar8 = (uint)*(byte *)((int)local_18 + 1);
                    *(byte *)((int)local_18 + 1) =
                         (byte)((((&DAT_00d0a2e0)
                                  [uVar3 * 0x100 +
                                   (uint)*(byte *)(iVar6 + 1 + (uint)(byte)*local_c * 4)] * uVar8 >>
                                  8 & 0xff) - uVar8) * DAT_00dca3f8 + uVar8 * 0x100 >> 8);
                    uVar8 = (uint)*(byte *)((int)local_18 + 2);
                    *(byte *)((int)local_18 + 2) =
                         (byte)((((&DAT_00d0a2e0)
                                  [uVar18 * 0x100 +
                                   (uint)*(byte *)(iVar6 + 2 + (uint)(byte)*local_c * 4)] * uVar8 >>
                                  8 & 0xff) - uVar8) * DAT_00dca3f8 + uVar8 * 0x100 >> 8);
                    local_18 = local_18 + 1;
                    local_8 = local_8 + -1;
                    iVar5 = DAT_00dca3f8;
                    if (local_8 == 0) goto LAB_006ede64;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  local_c = (uint *)((int)local_c + local_2c);
                  param_3 = (int *)((int)param_3 + local_34);
                } while ((int)param_3 < 1);
              } while( true );
            }
            iVar5 = DAT_00dca3f8;
            if (param_4 == 0) {
              do {
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                puVar9 = local_10;
                while( true ) {
                  uVar2 = (uint)(byte)*puVar7;
                  *(byte *)puVar7 =
                       (byte)((((int)(*(byte *)(iVar6 + (uint)(byte)*puVar9 * 4) * uVar2) >> 8) -
                              uVar2) * DAT_00dca3f8 + uVar2 * 0x100 >> 8);
                  uVar2 = (uint)*(byte *)((int)puVar7 + 1);
                  *(byte *)((int)puVar7 + 1) =
                       (byte)((((int)(*(byte *)(iVar6 + 1 + (uint)(byte)*puVar9 * 4) * uVar2) >> 8)
                              - uVar2) * DAT_00dca3f8 + uVar2 * 0x100 >> 8);
                  uVar2 = (uint)*(byte *)((int)puVar7 + 2);
                  *(byte *)((int)puVar7 + 2) =
                       (byte)((((int)(*(byte *)(iVar6 + 2 + (uint)(byte)*puVar9 * 4) * uVar2) >> 8)
                              - uVar2) * DAT_00dca3f8 + uVar2 * 0x100 >> 8);
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) break;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  if ((int)param_3 < 1) {
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      puVar9 = (uint *)((int)puVar9 + local_2c);
                    } while ((int)param_3 < 1);
                  }
                }
                local_1c = (uint *)((int)local_1c + local_48);
                local_14 = local_14 - 0x10000;
                if ((int)local_14 < 1) {
                  do {
                    local_14 = local_14 + local_38;
                    local_10 = (uint *)((int)local_10 + local_3c);
                  } while ((int)local_14 < 1);
                }
                local_24 = local_24 + -1;
              } while (local_24 != 0);
              return;
            }
LAB_006edb15:
            local_8 = local_44;
            puVar7 = local_1c;
            puVar9 = local_10;
            param_3 = (int *)local_40;
            do {
              if ((byte)*puVar9 == uVar2) {
                do {
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006edbf4;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              else {
                do {
                  uVar3 = (uint)(byte)*puVar7;
                  *(byte *)puVar7 =
                       (byte)((((int)(*(byte *)(iVar6 + (uint)(byte)*puVar9 * 4) * uVar3) >> 8) -
                              uVar3) * iVar5 + uVar3 * 0x100 >> 8);
                  uVar3 = (uint)*(byte *)((int)puVar7 + 1);
                  *(byte *)((int)puVar7 + 1) =
                       (byte)((((int)(*(byte *)(iVar6 + 1 + (uint)(byte)*puVar9 * 4) * uVar3) >> 8)
                              - uVar3) * DAT_00dca3f8 + uVar3 * 0x100 >> 8);
                  uVar3 = (uint)*(byte *)((int)puVar7 + 2);
                  *(byte *)((int)puVar7 + 2) =
                       (byte)((((int)(*(byte *)(iVar6 + 2 + (uint)(byte)*puVar9 * 4) * uVar3) >> 8)
                              - uVar3) * DAT_00dca3f8 + uVar3 * 0x100 >> 8);
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  iVar5 = DAT_00dca3f8;
                  if (local_8 == 0) goto LAB_006edbf4;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              do {
                puVar9 = (uint *)((int)puVar9 + local_2c);
                param_3 = (int *)((int)param_3 + local_34);
              } while ((int)param_3 < 1);
            } while( true );
          }
        }
        else {
          switch(DAT_00dca3f4) {
          case 0:
switchD_006eeb3f_caseD_0:
            if (param_5 == 0) {
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (*(int *)(param_2 + 0x2c) != 1) {
                  if (param_4 == 0) {
                    do {
                      local_8 = local_44;
                      puVar7 = local_10;
                      param_3 = (int *)local_40;
                      puVar9 = local_1c;
                      while( true ) {
                        *(byte *)puVar9 =
                             *(byte *)(&DAT_00d0a2e0 + uVar11 * 0x100 + (uint)(byte)*puVar7);
                        *(byte *)((int)puVar9 + 1) =
                             *(byte *)(&DAT_00d0a2e0 +
                                      uVar3 * 0x100 + (uint)*(byte *)((int)puVar7 + 1));
                        *(byte *)((int)puVar9 + 2) =
                             *(byte *)(&DAT_00d0a2e0 +
                                      uVar18 * 0x100 + (uint)*(byte *)((int)puVar7 + 2));
                        puVar9 = puVar9 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        if ((int)param_3 < 1) {
                          do {
                            puVar7 = (uint *)((int)puVar7 + local_2c);
                            param_3 = (int *)((int)param_3 + local_34);
                          } while ((int)param_3 < 1);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_14 = local_14 + local_38;
                          local_10 = (uint *)((int)local_10 + local_3c);
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_006efbc3:
                  local_8 = local_44;
                  puVar7 = local_1c;
                  param_3 = (int *)local_40;
                  puVar9 = local_10;
                  do {
                    if (*puVar9 == uVar2) {
                      do {
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006efc3f;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        *(byte *)puVar7 =
                             *(byte *)(&DAT_00d0a2e0 + uVar11 * 0x100 + (uint)(byte)*puVar9);
                        *(byte *)((int)puVar7 + 1) =
                             *(byte *)(&DAT_00d0a2e0 +
                                      uVar3 * 0x100 + (uint)*(byte *)((int)puVar9 + 1));
                        *(byte *)((int)puVar7 + 2) =
                             *(byte *)(&DAT_00d0a2e0 +
                                      uVar18 * 0x100 + (uint)*(byte *)((int)puVar9 + 2));
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006efc3f;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      puVar9 = (uint *)((int)puVar9 + local_2c);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                if (param_4 == 0) {
                  do {
                    local_8 = local_44;
                    puVar7 = local_1c;
                    param_3 = (int *)local_40;
                    puVar9 = local_10;
                    while( true ) {
                      *(byte *)puVar7 =
                           (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*puVar9] -
                                  (uint)(byte)*puVar7) * (uint)*(byte *)((int)puVar9 + 3) +
                                  (uint)(byte)*puVar7 * 0x100 >> 8);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)*(byte *)((int)puVar9 + 1)]
                                  - (uint)*(byte *)((int)puVar7 + 1)) *
                                  (uint)*(byte *)((int)puVar9 + 3) +
                                  (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)(((&DAT_00d0a2e0)
                                   [uVar18 * 0x100 + (uint)*(byte *)((int)puVar9 + 2)] -
                                  (uint)*(byte *)((int)puVar7 + 2)) *
                                  (uint)*(byte *)((int)puVar9 + 3) +
                                  (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          puVar9 = (uint *)((int)puVar9 + local_2c);
                          param_3 = (int *)((int)param_3 + local_34);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006ef970:
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                puVar9 = local_10;
                do {
                  if (*(byte *)((int)puVar9 + 3) == 0) {
                    do {
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006efa82;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else if (*(byte *)((int)puVar9 + 3) == 0xff) {
                    do {
                      *(byte *)puVar7 =
                           *(byte *)(&DAT_00d0a2e0 + uVar11 * 0x100 + (uint)(byte)*puVar9);
                      *(byte *)((int)puVar7 + 1) =
                           *(byte *)(&DAT_00d0a2e0 +
                                    uVar3 * 0x100 + (uint)*(byte *)((int)puVar9 + 1));
                      *(byte *)((int)puVar7 + 2) =
                           *(byte *)(&DAT_00d0a2e0 +
                                    uVar18 * 0x100 + (uint)*(byte *)((int)puVar9 + 2));
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006efa82;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      *(byte *)puVar7 =
                           (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*puVar9] -
                                  (uint)(byte)*puVar7) * (uint)*(byte *)((int)puVar9 + 3) +
                                  (uint)(byte)*puVar7 * 0x100 >> 8);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)*(byte *)((int)puVar9 + 1)]
                                  - (uint)*(byte *)((int)puVar7 + 1)) *
                                  (uint)*(byte *)((int)puVar9 + 3) +
                                  (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)(((&DAT_00d0a2e0)
                                   [uVar18 * 0x100 + (uint)*(byte *)((int)puVar9 + 2)] -
                                  (uint)*(byte *)((int)puVar7 + 2)) *
                                  (uint)*(byte *)((int)puVar9 + 3) +
                                  (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006efa82;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    puVar9 = (uint *)((int)puVar9 + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (*(int *)(param_2 + 0x2c) != 1) {
                if (param_4 == 0) {
                  do {
                    iVar6 = local_44;
                    iVar4 = local_40;
                    puVar7 = local_10;
LAB_006ef912:
                    uVar2 = *puVar7;
                    iVar13 = iVar4;
                    while( true ) {
                      *local_1c = uVar2;
                      local_1c = local_1c + 1;
                      iVar6 = iVar6 + -1;
                      if (iVar6 == 0) break;
                      iVar4 = iVar13 + -0x10000;
                      bVar20 = iVar13 < 0x10000;
                      iVar13 = iVar4;
                      if (iVar4 == 0 || bVar20) goto LAB_006ef924;
                    }
                    local_1c = (uint *)((int)local_1c + iVar5);
                    bVar20 = local_14 < 0x10000;
                    local_14 = local_14 - 0x10000;
                    if (bVar20 || local_14 == 0) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        bVar20 = SCARRY4(local_14,local_38);
                        local_14 = local_14 + local_38;
                      } while (bVar20 != (int)local_14 < 0);
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) {
                      return;
                    }
                  } while( true );
                }
LAB_006ef8a0:
                iVar6 = local_44;
                iVar4 = local_40;
                puVar7 = local_10;
                do {
                  uVar2 = *puVar7;
                  iVar13 = iVar4;
                  if (uVar2 == local_50) {
                    do {
                      local_1c = local_1c + 1;
                      iVar6 = iVar6 + -1;
                      if (iVar6 == 0) goto LAB_006ef8d6;
                      iVar4 = iVar13 + -0x10000;
                      bVar20 = 0xffff < iVar13;
                      iVar13 = iVar4;
                    } while (iVar4 != 0 && bVar20);
                  }
                  else {
                    do {
                      *local_1c = uVar2;
                      local_1c = local_1c + 1;
                      iVar6 = iVar6 + -1;
                      if (iVar6 == 0) goto LAB_006ef8d6;
                      iVar4 = iVar13 + -0x10000;
                      bVar20 = 0xffff < iVar13;
                      iVar13 = iVar4;
                    } while (iVar4 != 0 && bVar20);
                  }
                  do {
                    puVar7 = (uint *)((int)puVar7 + local_2c);
                    bVar20 = SCARRY4(iVar4,local_34);
                    iVar4 = iVar4 + local_34;
                  } while (bVar20 != iVar4 < 0);
                } while( true );
              }
              if (param_4 == 0) {
                do {
                  local_8 = local_44;
                  puVar7 = local_10;
                  puVar9 = local_1c;
                  iVar5 = local_40;
                  while( true ) {
                    *(byte *)puVar9 =
                         (byte)(((uint)(byte)*puVar7 - (uint)(byte)*puVar9) *
                                (uint)*(byte *)((int)puVar7 + 3) + (uint)(byte)*puVar9 * 0x100 >> 8)
                    ;
                    *(byte *)((int)puVar9 + 1) =
                         (byte)(((uint)*(byte *)((int)puVar7 + 1) - (uint)*(byte *)((int)puVar9 + 1)
                                ) * (uint)*(byte *)((int)puVar7 + 3) +
                                (uint)*(byte *)((int)puVar9 + 1) * 0x100 >> 8);
                    *(byte *)((int)puVar9 + 2) =
                         (byte)(((uint)*(byte *)((int)puVar7 + 2) - (uint)*(byte *)((int)puVar9 + 2)
                                ) * (uint)*(byte *)((int)puVar7 + 3) +
                                (uint)*(byte *)((int)puVar9 + 2) * 0x100 >> 8);
                    puVar9 = puVar9 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    iVar5 = iVar5 + -0x10000;
                    if (iVar5 < 1) {
                      do {
                        iVar5 = iVar5 + local_34;
                        puVar7 = (uint *)((int)puVar7 + local_2c);
                      } while (iVar5 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006ef6a0:
              local_8 = local_44;
              puVar7 = local_1c;
              puVar9 = local_10;
              iVar5 = local_40;
              do {
                if (*(byte *)((int)puVar9 + 3) == 0) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ef776;
                    iVar5 = iVar5 + -0x10000;
                  } while (0 < iVar5);
                }
                else if (*(byte *)((int)puVar9 + 3) == 0xff) {
                  do {
                    *puVar7 = *puVar9;
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ef776;
                    iVar5 = iVar5 + -0x10000;
                  } while (0 < iVar5);
                }
                else {
                  do {
                    *(byte *)puVar7 =
                         (byte)(((uint)(byte)*puVar9 - (uint)(byte)*puVar7) *
                                (uint)*(byte *)((int)puVar9 + 3) + (uint)(byte)*puVar7 * 0x100 >> 8)
                    ;
                    *(byte *)((int)puVar7 + 1) =
                         (byte)(((uint)*(byte *)((int)puVar9 + 1) - (uint)*(byte *)((int)puVar7 + 1)
                                ) * (uint)*(byte *)((int)puVar9 + 3) +
                                (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)(((uint)*(byte *)((int)puVar9 + 2) - (uint)*(byte *)((int)puVar7 + 2)
                                ) * (uint)*(byte *)((int)puVar9 + 3) +
                                (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ef776;
                    iVar5 = iVar5 + -0x10000;
                  } while (0 < iVar5);
                }
                do {
                  iVar5 = iVar5 + local_34;
                  puVar9 = (uint *)((int)puVar9 + local_2c);
                } while (iVar5 < 1);
              } while( true );
            }
            if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
              if (*(int *)(param_2 + 0x2c) != 1) {
                if (param_4 == 0) {
                  do {
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    puVar7 = local_1c;
                    local_20 = local_28;
                    local_c = local_10;
                    while( true ) {
                      *(byte *)puVar7 =
                           (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] -
                                  (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                                  (uint)(byte)*puVar7 * 0x100 >> 8);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)(((&DAT_00d0a2e0)
                                   [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] -
                                  (uint)*(byte *)((int)puVar7 + 1)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                                  (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)(((&DAT_00d0a2e0)
                                   [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] -
                                  (uint)*(byte *)((int)puVar7 + 2)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                                  (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          local_20 = local_20 + local_58;
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
                local_20 = local_28;
                puVar7 = local_10;
                do {
                  local_28 = local_20;
                  local_8 = local_44;
                  puVar9 = local_1c;
                  param_3 = (int *)local_40;
                  local_c = puVar7;
                  while (*local_c == uVar2) {
                    do {
                      puVar9 = puVar9 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006ef4f1;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
LAB_006ef4d3:
                    do {
                      local_c = (uint *)((int)local_c + local_2c);
                      param_3 = (int *)((int)param_3 + local_34);
                      local_20 = local_20 + local_58;
                    } while ((int)param_3 < 1);
                    puVar7 = local_10;
                  }
                  while( true ) {
                    *(byte *)puVar9 =
                         (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] -
                                (uint)(byte)*puVar9) * (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                                (uint)(byte)*puVar9 * 0x100 >> 8);
                    *(byte *)((int)puVar9 + 1) =
                         (byte)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)]
                                - (uint)*(byte *)((int)puVar9 + 1)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                                (uint)*(byte *)((int)puVar9 + 1) * 0x100 >> 8);
                    *(byte *)((int)puVar9 + 2) =
                         (byte)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)]
                                - (uint)*(byte *)((int)puVar9 + 2)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                                (uint)*(byte *)((int)puVar9 + 2) * 0x100 >> 8);
                    puVar9 = puVar9 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) goto LAB_006ef4d3;
                  }
                  puVar7 = local_10;
LAB_006ef4f1:
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      puVar7 = (uint *)((int)puVar7 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                    local_10 = puVar7;
                  }
                  local_24 = local_24 + -1;
                  local_20 = local_28;
                  if (local_24 == 0) {
                    return;
                  }
                } while( true );
              }
              local_20 = local_28;
              if (param_4 == 0) {
                do {
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_10;
                  puVar9 = local_1c;
                  local_20 = local_28;
                  while( true ) {
                    *(byte *)puVar9 =
                         (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*puVar7] -
                                (uint)(byte)*puVar9) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (uint)*(byte *)((int)puVar7 + 3) + (uint)(byte)*puVar9 * 0x10000 >>
                               0x10);
                    *(byte *)((int)puVar9 + 1) =
                         (byte)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)*(byte *)((int)puVar7 + 1)] -
                                (uint)*(byte *)((int)puVar9 + 1)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (uint)*(byte *)((int)puVar7 + 3) +
                                (uint)*(byte *)((int)puVar9 + 1) * 0x10000 >> 0x10);
                    *(byte *)((int)puVar9 + 2) =
                         (byte)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)*(byte *)((int)puVar7 + 2)]
                                - (uint)*(byte *)((int)puVar9 + 2)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (uint)*(byte *)((int)puVar7 + 3) +
                                (uint)*(byte *)((int)puVar9 + 2) * 0x10000 >> 0x10);
                    puVar9 = puVar9 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_20 = local_20 + local_58;
                      puVar7 = (uint *)((int)puVar7 + local_2c);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_14 = local_14 + local_38;
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006ef090:
              local_28 = local_20;
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              puVar9 = local_10;
              do {
                if (*(byte *)((int)puVar9 + 3) == 0) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ef25b;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else if (*(byte *)((int)puVar9 + 3) == 0xff) {
                  do {
                    *(byte *)puVar7 =
                         (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*puVar9] -
                                (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                                (uint)(byte)*puVar7 * 0x100 >> 8);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)*(byte *)((int)puVar9 + 1)] -
                                (uint)*(byte *)((int)puVar7 + 1)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                                (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)*(byte *)((int)puVar9 + 2)]
                                - (uint)*(byte *)((int)puVar7 + 2)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] +
                                (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ef25b;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    *(byte *)puVar7 =
                         (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*puVar9] -
                                (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (uint)*(byte *)((int)puVar9 + 3) + (uint)(byte)*puVar7 * 0x10000 >>
                               0x10);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)*(byte *)((int)puVar9 + 1)] -
                                (uint)*(byte *)((int)puVar7 + 1)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (uint)*(byte *)((int)puVar9 + 3) +
                                (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)(((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)*(byte *)((int)puVar9 + 2)]
                                - (uint)*(byte *)((int)puVar7 + 2)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (uint)*(byte *)((int)puVar9 + 3) +
                                (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006ef25b;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  local_20 = local_20 + local_58;
                  param_3 = (int *)((int)param_3 + local_34);
                  puVar9 = (uint *)((int)puVar9 + local_2c);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if (*(int *)(param_2 + 0x2c) != 1) {
              if (param_4 == 0) {
                do {
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  puVar9 = local_10;
                  pbVar19 = local_28;
                  while( true ) {
                    *(byte *)puVar7 =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                                ((uint)(byte)*puVar9 - (uint)(byte)*puVar7) +
                                (uint)(byte)*puVar7 * 0x100 >> 8);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                                ((uint)*(byte *)((int)puVar9 + 1) - (uint)*(byte *)((int)puVar7 + 1)
                                ) + (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                                ((uint)*(byte *)((int)puVar9 + 2) - (uint)*(byte *)((int)puVar7 + 2)
                                ) + (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        puVar9 = (uint *)((int)puVar9 + local_2c);
                        pbVar19 = pbVar19 + local_58;
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006eee72:
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              puVar9 = local_10;
              pbVar19 = local_28;
              do {
                if (*puVar9 == uVar2) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006eef38;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    *(byte *)puVar7 =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                                ((uint)(byte)*puVar9 - (uint)(byte)*puVar7) +
                                (uint)(byte)*puVar7 * 0x100 >> 8);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                                ((uint)*(byte *)((int)puVar9 + 1) - (uint)*(byte *)((int)puVar7 + 1)
                                ) + (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                                ((uint)*(byte *)((int)puVar9 + 2) - (uint)*(byte *)((int)puVar7 + 2)
                                ) + (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006eef38;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  puVar9 = (uint *)((int)puVar9 + local_2c);
                  pbVar19 = pbVar19 + local_58;
                } while ((int)param_3 < 1);
              } while( true );
            }
            if (param_4 == 0) {
              do {
                local_8 = local_44;
                puVar7 = local_10;
                puVar9 = local_1c;
                param_3 = (int *)local_40;
                pbVar19 = local_28;
                while( true ) {
                  *(byte *)puVar9 =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              ((uint)(byte)*puVar7 - (uint)(byte)*puVar9) *
                              (uint)*(byte *)((int)puVar7 + 3) + (uint)(byte)*puVar9 * 0x10000 >>
                             0x10);
                  *(byte *)((int)puVar9 + 1) =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              ((uint)*(byte *)((int)puVar7 + 1) - (uint)*(byte *)((int)puVar9 + 1))
                              * (uint)*(byte *)((int)puVar7 + 3) +
                              (uint)*(byte *)((int)puVar9 + 1) * 0x10000 >> 0x10);
                  *(byte *)((int)puVar9 + 2) =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              ((uint)*(byte *)((int)puVar7 + 2) - (uint)*(byte *)((int)puVar9 + 2))
                              * (uint)*(byte *)((int)puVar7 + 3) +
                              (uint)*(byte *)((int)puVar9 + 2) * 0x10000 >> 0x10);
                  puVar9 = puVar9 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) break;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  if ((int)param_3 < 1) {
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      puVar7 = (uint *)((int)puVar7 + local_2c);
                      pbVar19 = pbVar19 + local_58;
                    } while ((int)param_3 < 1);
                  }
                }
                local_1c = (uint *)((int)local_1c + local_48);
                local_14 = local_14 - 0x10000;
                if ((int)local_14 < 1) {
                  do {
                    local_14 = local_14 + local_38;
                    local_10 = (uint *)((int)local_10 + local_3c);
                    local_28 = local_28 + local_5c;
                  } while ((int)local_14 < 1);
                }
                local_24 = local_24 + -1;
              } while (local_24 != 0);
              return;
            }
LAB_006eeb90:
            local_8 = local_44;
            puVar7 = local_1c;
            puVar9 = local_10;
            pbVar19 = local_28;
            param_3 = (int *)local_40;
            do {
              if (*(byte *)((int)puVar9 + 3) == 0) {
                do {
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006eed02;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              else if (*(byte *)((int)puVar9 + 3) == 0xff) {
                do {
                  *(byte *)puVar7 =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              ((uint)(byte)*puVar9 - (uint)(byte)*puVar7) +
                              (uint)(byte)*puVar7 * 0x100 >> 8);
                  *(byte *)((int)puVar7 + 1) =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              ((uint)*(byte *)((int)puVar9 + 1) - (uint)*(byte *)((int)puVar7 + 1))
                              + (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                  *(byte *)((int)puVar7 + 2) =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              ((uint)*(byte *)((int)puVar9 + 2) - (uint)*(byte *)((int)puVar7 + 2))
                              + (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006eed02;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              else {
                do {
                  *(byte *)puVar7 =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              ((uint)(byte)*puVar9 - (uint)(byte)*puVar7) *
                              (uint)*(byte *)((int)puVar9 + 3) + (uint)(byte)*puVar7 * 0x10000 >>
                             0x10);
                  *(byte *)((int)puVar7 + 1) =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              ((uint)*(byte *)((int)puVar9 + 1) - (uint)*(byte *)((int)puVar7 + 1))
                              * (uint)*(byte *)((int)puVar9 + 3) +
                              (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                  *(byte *)((int)puVar7 + 2) =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              ((uint)*(byte *)((int)puVar9 + 2) - (uint)*(byte *)((int)puVar7 + 2))
                              * (uint)*(byte *)((int)puVar9 + 3) +
                              (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006eed02;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              do {
                param_3 = (int *)((int)param_3 + local_34);
                puVar9 = (uint *)((int)puVar9 + local_2c);
                pbVar19 = pbVar19 + local_58;
              } while ((int)param_3 < 1);
            } while( true );
          case 1:
            if (DAT_00dca3f8 == 0xff) goto switchD_006eeb3f_caseD_0;
            if (DAT_00dca3f8 != 0) {
              if (param_5 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (*(int *)(param_2 + 0x2c) != 1) {
                    iVar5 = DAT_00dca3f8;
                    if (param_4 == 0) {
                      do {
                        local_c = local_10;
                        local_8 = local_44;
                        param_3 = (int *)local_40;
                        puVar7 = local_1c;
                        while( true ) {
                          *(byte *)puVar7 =
                               (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] -
                                      (uint)(byte)*puVar7) * DAT_00dca3f8 +
                                      (uint)(byte)*puVar7 * 0x100 >> 8);
                          *(byte *)((int)puVar7 + 1) =
                               (byte)(((&DAT_00d0a2e0)
                                       [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] -
                                      (uint)*(byte *)((int)puVar7 + 1)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                          *(byte *)((int)puVar7 + 2) =
                               (byte)(((&DAT_00d0a2e0)
                                       [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] -
                                      (uint)*(byte *)((int)puVar7 + 2)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                          puVar7 = puVar7 + 1;
                          local_8 = local_8 + -1;
                          if (local_8 == 0) break;
                          for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                              param_3 = (int *)((int)param_3 + local_34)) {
                            local_c = (uint *)((int)local_c + local_2c);
                          }
                        }
                        local_1c = (uint *)((int)local_1c + local_48);
                        local_14 = local_14 - 0x10000;
                        if ((int)local_14 < 1) {
                          do {
                            local_10 = (uint *)((int)local_10 + local_3c);
                            local_14 = local_14 + local_38;
                          } while ((int)local_14 < 1);
                        }
                        local_24 = local_24 + -1;
                      } while (local_24 != 0);
                      return;
                    }
LAB_006f1180:
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    puVar7 = local_1c;
                    local_c = local_10;
                    do {
                      if (*local_c == uVar2) {
                        do {
                          puVar7 = puVar7 + 1;
                          local_8 = local_8 + -1;
                          if (local_8 == 0) goto LAB_006f1260;
                          param_3 = (int *)((int)param_3 + -0x10000);
                        } while (0 < (int)param_3);
                      }
                      else {
                        do {
                          *(byte *)puVar7 =
                               (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] -
                                      (uint)(byte)*puVar7) * iVar5 + (uint)(byte)*puVar7 * 0x100 >>
                                     8);
                          *(byte *)((int)puVar7 + 1) =
                               (byte)(((&DAT_00d0a2e0)
                                       [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] -
                                      (uint)*(byte *)((int)puVar7 + 1)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                          *(byte *)((int)puVar7 + 2) =
                               (byte)(((&DAT_00d0a2e0)
                                       [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] -
                                      (uint)*(byte *)((int)puVar7 + 2)) * DAT_00dca3f8 +
                                      (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                          puVar7 = puVar7 + 1;
                          local_8 = local_8 + -1;
                          iVar5 = DAT_00dca3f8;
                          if (local_8 == 0) goto LAB_006f1260;
                          param_3 = (int *)((int)param_3 + -0x10000);
                        } while (0 < (int)param_3);
                      }
                      do {
                        local_c = (uint *)((int)local_c + local_2c);
                        param_3 = (int *)((int)param_3 + local_34);
                      } while ((int)param_3 < 1);
                    } while( true );
                  }
                  iVar5 = DAT_00dca3f8;
                  if (param_4 == 0) {
                    do {
                      local_c = local_10;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      puVar7 = local_1c;
                      while( true ) {
                        *(byte *)puVar7 =
                             (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] -
                                    (uint)(byte)*puVar7) * (uint)*(byte *)((int)local_c + 3) *
                                    DAT_00dca3f8 + (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                        *(byte *)((int)puVar7 + 1) =
                             (byte)(((&DAT_00d0a2e0)
                                     [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] -
                                    (uint)*(byte *)((int)puVar7 + 1)) *
                                    (uint)*(byte *)((int)local_c + 3) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                        *(byte *)((int)puVar7 + 2) =
                             (byte)(((&DAT_00d0a2e0)
                                     [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] -
                                    (uint)*(byte *)((int)puVar7 + 2)) *
                                    (uint)*(byte *)((int)local_c + 3) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                            param_3 = (int *)((int)param_3 + local_34)) {
                          local_c = (uint *)((int)local_c + local_2c);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_14 = local_14 + local_38;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_006f0e70:
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  local_c = local_10;
                  do {
                    if (*(byte *)((int)local_c + 3) == 0) {
                      do {
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f1010;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else if (*(byte *)((int)local_c + 3) == 0xff) {
                      do {
                        *(byte *)puVar7 =
                             (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] -
                                    (uint)(byte)*puVar7) * iVar5 + (uint)(byte)*puVar7 * 0x100 >> 8)
                        ;
                        *(byte *)((int)puVar7 + 1) =
                             (byte)(((&DAT_00d0a2e0)
                                     [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] -
                                    (uint)*(byte *)((int)puVar7 + 1)) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                        *(byte *)((int)puVar7 + 2) =
                             (byte)(((&DAT_00d0a2e0)
                                     [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] -
                                    (uint)*(byte *)((int)puVar7 + 2)) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f100b;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        iVar5 = DAT_00dca3f8;
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        *(byte *)puVar7 =
                             (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] -
                                    (uint)(byte)*puVar7) * (uint)*(byte *)((int)local_c + 3) * iVar5
                                    + (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                        *(byte *)((int)puVar7 + 1) =
                             (byte)(((&DAT_00d0a2e0)
                                     [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] -
                                    (uint)*(byte *)((int)puVar7 + 1)) *
                                    (uint)*(byte *)((int)local_c + 3) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                        *(byte *)((int)puVar7 + 2) =
                             (byte)(((&DAT_00d0a2e0)
                                     [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] -
                                    (uint)*(byte *)((int)puVar7 + 2)) *
                                    (uint)*(byte *)((int)local_c + 3) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f100b;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        iVar5 = DAT_00dca3f8;
                      } while (0 < (int)param_3);
                    }
                    do {
                      local_c = (uint *)((int)local_c + local_2c);
                      param_3 = (int *)((int)param_3 + local_34);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                if (*(int *)(param_2 + 0x2c) != 1) {
                  if (param_4 == 0) {
                    do {
                      local_8 = local_44;
                      puVar9 = local_1c;
                      iVar5 = local_40;
                      puVar7 = local_10;
                      while( true ) {
                        *(byte *)puVar9 =
                             (byte)(((uint)(byte)*puVar7 - (uint)(byte)*puVar9) * DAT_00dca3f8 +
                                    (uint)(byte)*puVar9 * 0x100 >> 8);
                        *(byte *)((int)puVar9 + 1) =
                             (byte)(((uint)*(byte *)((int)puVar7 + 1) -
                                    (uint)*(byte *)((int)puVar9 + 1)) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar9 + 1) * 0x100 >> 8);
                        *(byte *)((int)puVar9 + 2) =
                             (byte)(((uint)*(byte *)((int)puVar7 + 2) -
                                    (uint)*(byte *)((int)puVar9 + 2)) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar9 + 2) * 0x100 >> 8);
                        puVar9 = puVar9 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        for (iVar5 = iVar5 + -0x10000; iVar5 < 1; iVar5 = iVar5 + local_34) {
                          puVar7 = (uint *)((int)puVar7 + local_2c);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_14 = local_14 + local_38;
                          local_10 = (uint *)((int)local_10 + local_3c);
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
                  iVar5 = DAT_00dca3f8;
LAB_006f0ca2:
                  local_8 = local_44;
                  puVar7 = local_1c;
                  iVar6 = local_40;
                  puVar9 = local_10;
                  do {
                    if (*puVar9 == uVar2) {
                      do {
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f0d45;
                        iVar6 = iVar6 + -0x10000;
                      } while (0 < iVar6);
                    }
                    else {
                      do {
                        *(byte *)puVar7 =
                             (byte)(((uint)(byte)*puVar9 - (uint)(byte)*puVar7) * iVar5 +
                                    (uint)(byte)*puVar7 * 0x100 >> 8);
                        *(byte *)((int)puVar7 + 1) =
                             (byte)(((uint)*(byte *)((int)puVar9 + 1) -
                                    (uint)*(byte *)((int)puVar7 + 1)) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                        *(byte *)((int)puVar7 + 2) =
                             (byte)(((uint)*(byte *)((int)puVar9 + 2) -
                                    (uint)*(byte *)((int)puVar7 + 2)) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        iVar5 = DAT_00dca3f8;
                        if (local_8 == 0) goto LAB_006f0d45;
                        iVar6 = iVar6 + -0x10000;
                      } while (0 < iVar6);
                    }
                    do {
                      iVar6 = iVar6 + local_34;
                      puVar9 = (uint *)((int)puVar9 + local_2c);
                    } while (iVar6 < 1);
                  } while( true );
                }
                iVar5 = DAT_00dca3f8;
                if (param_4 == 0) {
                  do {
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    puVar7 = local_1c;
                    puVar9 = local_10;
                    while( true ) {
                      *(byte *)puVar7 =
                           (byte)(((uint)(byte)*puVar9 - (uint)(byte)*puVar7) *
                                  (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8 +
                                  (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)(((uint)*(byte *)((int)puVar9 + 1) -
                                  (uint)*(byte *)((int)puVar7 + 1)) *
                                  (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)(((uint)*(byte *)((int)puVar9 + 2) -
                                  (uint)*(byte *)((int)puVar7 + 2)) *
                                  (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          puVar9 = (uint *)((int)puVar9 + local_2c);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006f0a12:
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                puVar9 = local_10;
                do {
                  if (*(byte *)((int)puVar9 + 3) == 0) {
                    do {
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f0b59;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else if (*(byte *)((int)puVar9 + 3) == 0xff) {
                    do {
                      *(byte *)puVar7 =
                           (byte)(((uint)(byte)*puVar9 - (uint)(byte)*puVar7) * iVar5 +
                                  (uint)(byte)*puVar7 * 0x100 >> 8);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)(((uint)*(byte *)((int)puVar9 + 1) -
                                  (uint)*(byte *)((int)puVar7 + 1)) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)(((uint)*(byte *)((int)puVar9 + 2) -
                                  (uint)*(byte *)((int)puVar7 + 2)) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f0b54;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      *(byte *)puVar7 =
                           (byte)(((uint)(byte)*puVar9 - (uint)(byte)*puVar7) *
                                  (uint)*(byte *)((int)puVar9 + 3) * iVar5 +
                                  (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)(((uint)*(byte *)((int)puVar9 + 1) -
                                  (uint)*(byte *)((int)puVar7 + 1)) *
                                  (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)(((uint)*(byte *)((int)puVar9 + 2) -
                                  (uint)*(byte *)((int)puVar7 + 2)) *
                                  (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f0b54;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    puVar9 = (uint *)((int)puVar9 + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (*(int *)(param_2 + 0x2c) != 1) {
                  local_c = local_10;
                  iVar5 = DAT_00dca3f8;
                  if (param_4 == 0) {
                    local_20 = local_28;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    puVar7 = local_1c;
                    while( true ) {
                      while( true ) {
                        *(byte *)puVar7 =
                             (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] -
                                    (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                    DAT_00dca3f8 + (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                        *(byte *)((int)puVar7 + 1) =
                             (byte)(((&DAT_00d0a2e0)
                                     [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] -
                                    (uint)*(byte *)((int)puVar7 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                        *(byte *)((int)puVar7 + 2) =
                             (byte)(((&DAT_00d0a2e0)
                                     [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] -
                                    (uint)*(byte *)((int)puVar7 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        if ((int)param_3 < 1) {
                          do {
                            local_20 = local_20 + local_58;
                            param_3 = (int *)((int)param_3 + local_34);
                            local_c = (uint *)((int)local_c + local_2c);
                          } while ((int)param_3 < 1);
                        }
                      }
                      puVar7 = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_14 = local_14 + local_38;
                          local_28 = local_28 + local_5c;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                      local_c = local_10;
                      local_20 = local_28;
                      if (local_24 == 0) break;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      local_1c = puVar7;
                    }
                    return;
                  }
LAB_006f0732:
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  local_20 = local_28;
                  local_c = local_10;
                  do {
                    if (*local_c == uVar2) {
                      do {
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f0849;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        *(byte *)puVar7 =
                             (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] -
                                    (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                    iVar5 + (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                        *(byte *)((int)puVar7 + 1) =
                             (byte)(((&DAT_00d0a2e0)
                                     [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] -
                                    (uint)*(byte *)((int)puVar7 + 1)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                        *(byte *)((int)puVar7 + 2) =
                             (byte)(((&DAT_00d0a2e0)
                                     [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] -
                                    (uint)*(byte *)((int)puVar7 + 2)) *
                                    (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        iVar5 = DAT_00dca3f8;
                        if (local_8 == 0) goto LAB_006f0849;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    do {
                      local_c = (uint *)((int)local_c + local_2c);
                      local_20 = local_20 + local_58;
                      param_3 = (int *)((int)param_3 + local_34);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                local_20 = local_28;
                if (param_4 == 0) {
                  local_8 = local_44;
                  local_18 = local_1c;
                  param_3 = (int *)local_40;
                  puVar7 = local_10;
                  while( true ) {
                    while( true ) {
                      *(byte *)local_18 =
                           (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*puVar7] -
                                  (uint)(byte)*local_18) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  (uint)*(byte *)((int)puVar7 + 3) * DAT_00dca3f8 +
                                  (uint)(byte)*local_18 * 0x1000000 >> 0x18);
                      *(byte *)((int)local_18 + 1) =
                           (byte)(((&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)*(byte *)((int)puVar7 + 1)]
                                  - (uint)*(byte *)((int)local_18 + 1)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  (uint)*(byte *)((int)puVar7 + 3) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)local_18 + 1) * 0x1000000 >> 0x18);
                      *(byte *)((int)local_18 + 2) =
                           (byte)(((&DAT_00d0a2e0)
                                   [uVar18 * 0x100 + (uint)*(byte *)((int)puVar7 + 2)] -
                                  (uint)*(byte *)((int)local_18 + 2)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  (uint)*(byte *)((int)puVar7 + 3) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)local_18 + 2) * 0x1000000 >> 0x18);
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_20 = local_20 + local_58;
                        puVar7 = (uint *)((int)puVar7 + local_2c);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    local_20 = local_28;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    puVar7 = local_10;
                    local_18 = local_1c;
                  }
                  return;
                }
                iVar5 = DAT_00dca3f8;
LAB_006f0347:
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                local_20 = local_28;
                local_c = local_10;
                do {
                  if (*(byte *)((int)local_c + 3) == 0) {
                    do {
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f0556;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else if (*(byte *)((int)local_c + 3) == 0xff) {
                    do {
                      *(byte *)puVar7 =
                           (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] -
                                  (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  iVar5 + (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)(((&DAT_00d0a2e0)
                                   [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] -
                                  (uint)*(byte *)((int)puVar7 + 1)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)(((&DAT_00d0a2e0)
                                   [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] -
                                  (uint)*(byte *)((int)puVar7 + 2)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f0551;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      *(byte *)puVar7 =
                           (byte)(((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] -
                                  (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  (uint)*(byte *)((int)local_c + 3) * iVar5 +
                                  (uint)(byte)*puVar7 * 0x1000000 >> 0x18);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)(((&DAT_00d0a2e0)
                                   [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] -
                                  (uint)*(byte *)((int)puVar7 + 1)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  (uint)*(byte *)((int)local_c + 3) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 1) * 0x1000000 >> 0x18);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)(((&DAT_00d0a2e0)
                                   [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] -
                                  (uint)*(byte *)((int)puVar7 + 2)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  (uint)*(byte *)((int)local_c + 3) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 2) * 0x1000000 >> 0x18);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f0551;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_c = (uint *)((int)local_c + local_2c);
                    local_20 = local_20 + local_58;
                    param_3 = (int *)((int)param_3 + local_34);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (*(int *)(param_2 + 0x2c) != 1) {
                iVar5 = DAT_00dca3f8;
                if (param_4 == 0) {
                  do {
                    local_20 = local_28;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    puVar7 = local_1c;
                    puVar9 = local_10;
                    while( true ) {
                      *(byte *)puVar7 =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  ((uint)(byte)*puVar9 - (uint)(byte)*puVar7) * DAT_00dca3f8 +
                                  (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  ((uint)*(byte *)((int)puVar9 + 1) -
                                  (uint)*(byte *)((int)puVar7 + 1)) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  ((uint)*(byte *)((int)puVar9 + 2) -
                                  (uint)*(byte *)((int)puVar7 + 2)) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          puVar9 = (uint *)((int)puVar9 + local_2c);
                          local_20 = local_20 + local_58;
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006f00d2:
                local_20 = local_28;
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                puVar9 = local_10;
                do {
                  if (*puVar9 == uVar2) {
                    do {
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f01b8;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      *(byte *)puVar7 =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  ((uint)(byte)*puVar9 - (uint)(byte)*puVar7) * iVar5 +
                                  (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  ((uint)*(byte *)((int)puVar9 + 1) -
                                  (uint)*(byte *)((int)puVar7 + 1)) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  ((uint)*(byte *)((int)puVar9 + 2) -
                                  (uint)*(byte *)((int)puVar7 + 2)) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      iVar5 = DAT_00dca3f8;
                      if (local_8 == 0) goto LAB_006f01b8;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    puVar9 = (uint *)((int)puVar9 + local_2c);
                    local_20 = local_20 + local_58;
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (param_4 == 0) {
                local_8 = local_44;
                local_20 = local_28;
                param_3 = (int *)local_40;
                puVar7 = local_10;
                puVar9 = local_1c;
                while( true ) {
                  while( true ) {
                    *(byte *)puVar9 =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                ((uint)(byte)*puVar7 - (uint)(byte)*puVar9) *
                                (uint)*(byte *)((int)puVar7 + 3) * DAT_00dca3f8 +
                                (uint)(byte)*puVar9 * 0x1000000 >> 0x18);
                    *(byte *)((int)puVar9 + 1) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                ((uint)*(byte *)((int)puVar7 + 1) - (uint)*(byte *)((int)puVar9 + 1)
                                ) * (uint)*(byte *)((int)puVar7 + 3) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar9 + 1) * 0x1000000 >> 0x18);
                    *(byte *)((int)puVar9 + 2) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                ((uint)*(byte *)((int)puVar7 + 2) - (uint)*(byte *)((int)puVar9 + 2)
                                ) * (uint)*(byte *)((int)puVar7 + 3) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar9 + 2) * 0x1000000 >> 0x18);
                    puVar9 = puVar9 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        puVar7 = (uint *)((int)puVar7 + local_2c);
                        local_20 = local_20 + local_58;
                      } while ((int)param_3 < 1);
                    }
                  }
                  puVar9 = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                  if (local_24 == 0) break;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_10;
                  local_20 = local_28;
                  local_1c = puVar9;
                }
                return;
              }
              iVar5 = DAT_00dca3f8;
LAB_006efd80:
              local_20 = local_28;
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              puVar9 = local_10;
              do {
                if (*(byte *)((int)puVar9 + 3) == 0) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006eff1f;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else if (*(byte *)((int)puVar9 + 3) == 0xff) {
                  do {
                    *(byte *)puVar7 =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                ((uint)(byte)*puVar9 - (uint)(byte)*puVar7) * iVar5 +
                                (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                ((uint)*(byte *)((int)puVar9 + 1) - (uint)*(byte *)((int)puVar7 + 1)
                                ) * DAT_00dca3f8 + (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >>
                               0x10);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                ((uint)*(byte *)((int)puVar9 + 2) - (uint)*(byte *)((int)puVar7 + 2)
                                ) * DAT_00dca3f8 + (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >>
                               0x10);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006eff1a;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    *(byte *)puVar7 =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                ((uint)(byte)*puVar9 - (uint)(byte)*puVar7) *
                                (uint)*(byte *)((int)puVar9 + 3) * iVar5 +
                                (uint)(byte)*puVar7 * 0x1000000 >> 0x18);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                ((uint)*(byte *)((int)puVar9 + 1) - (uint)*(byte *)((int)puVar7 + 1)
                                ) * (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar7 + 1) * 0x1000000 >> 0x18);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                ((uint)*(byte *)((int)puVar9 + 2) - (uint)*(byte *)((int)puVar7 + 2)
                                ) * (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar7 + 2) * 0x1000000 >> 0x18);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006eff1a;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  puVar9 = (uint *)((int)puVar9 + local_2c);
                  local_20 = local_20 + local_58;
                } while ((int)param_3 < 1);
              } while( true );
            }
            break;
          case 2:
            if (DAT_00dca3f8 != 0) {
              if (param_5 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (*(int *)(param_2 + 0x2c) != 1) {
                    local_18 = local_1c;
                    if (param_4 == 0) {
                      do {
                        puVar7 = local_18;
                        local_c = local_10;
                        local_8 = local_44;
                        param_3 = (int *)local_40;
                        while( true ) {
                          param_2._0_2_ =
                               CONCAT11(*(undefined1 *)
                                         (&DAT_00d0a2e0 +
                                         iVar4 * 0x100 +
                                         (&DAT_00d0a2e0)
                                         [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)]),
                                        *(undefined1 *)
                                         (&DAT_00d0a2e0 +
                                         iVar4 * 0x100 +
                                         (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c]));
                          param_2._0_3_ =
                               CONCAT12(*(undefined1 *)
                                         (&DAT_00d0a2e0 +
                                         iVar4 * 0x100 +
                                         (&DAT_00d0a2e0)
                                         [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)]),
                                        (undefined2)param_2);
                          param_2 = (uint)(uint3)param_2;
                          uVar2 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                          uVar8 = uVar2 & 0x1010100;
                          *local_18 = uVar8 - (uVar8 >> 8) | (param_2 | *local_18) & 0x10100 | uVar2
                          ;
                          local_18 = local_18 + 1;
                          local_8 = local_8 + -1;
                          if (local_8 == 0) break;
                          param_3 = (int *)((int)param_3 + -0x10000);
                          if ((int)param_3 < 1) {
                            do {
                              local_c = (uint *)((int)local_c + local_2c);
                              param_3 = (int *)((int)param_3 + local_34);
                            } while ((int)param_3 < 1);
                          }
                        }
                        local_18 = (uint *)((int)puVar7 + local_48);
                        local_14 = local_14 - 0x10000;
                        if ((int)local_14 < 1) {
                          do {
                            local_10 = (uint *)((int)local_10 + local_3c);
                            local_14 = local_14 + local_38;
                          } while ((int)local_14 < 1);
                        }
                        local_24 = local_24 + -1;
                      } while (local_24 != 0);
                      return;
                    }
LAB_006f2862:
                    puVar7 = local_18;
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    do {
                      if (*local_c == uVar2) {
                        do {
                          local_18 = local_18 + 1;
                          local_8 = local_8 + -1;
                          if (local_8 == 0) goto LAB_006f2935;
                          param_3 = (int *)((int)param_3 + -0x10000);
                        } while (0 < (int)param_3);
                      }
                      else {
                        do {
                          param_2._0_2_ =
                               CONCAT11(*(undefined1 *)
                                         (&DAT_00d0a2e0 +
                                         iVar4 * 0x100 +
                                         (&DAT_00d0a2e0)
                                         [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)]),
                                        *(undefined1 *)
                                         (&DAT_00d0a2e0 +
                                         iVar4 * 0x100 +
                                         (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c]));
                          param_2._0_3_ =
                               CONCAT12(*(undefined1 *)
                                         (&DAT_00d0a2e0 +
                                         iVar4 * 0x100 +
                                         (&DAT_00d0a2e0)
                                         [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)]),
                                        (undefined2)param_2);
                          param_2 = (uint)(uint3)param_2;
                          uVar8 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                          uVar14 = uVar8 & 0x1010100;
                          *local_18 = uVar14 - (uVar14 >> 8) | (param_2 | *local_18) & 0x10100 |
                                      uVar8;
                          local_18 = local_18 + 1;
                          local_8 = local_8 + -1;
                          if (local_8 == 0) goto LAB_006f2935;
                          param_3 = (int *)((int)param_3 + -0x10000);
                        } while (0 < (int)param_3);
                      }
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                      } while ((int)param_3 < 1);
                    } while( true );
                  }
                  if (param_4 == 0) {
                    local_18 = local_1c;
                    local_8 = local_44;
                    local_c = local_10;
                    param_3 = (int *)local_40;
                    while( true ) {
                      while( true ) {
                        uVar2 = (uint)*(byte *)((int)local_c + 3);
                        param_2._0_2_ =
                             CONCAT11((char)((&DAT_00d0a2e0)
                                             [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] *
                                             uVar2 * DAT_00dca3f8 >> 0x10),
                                      (char)((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c]
                                             * uVar2 * DAT_00dca3f8 >> 0x10));
                        param_2 = (uint)CONCAT12((char)((&DAT_00d0a2e0)
                                                        [uVar18 * 0x100 +
                                                         (uint)*(byte *)((int)local_c + 2)] * uVar2
                                                        * DAT_00dca3f8 >> 0x10),(undefined2)param_2)
                        ;
                        uVar8 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                        uVar2 = uVar8 & 0x1010100;
                        *local_18 = uVar2 - (uVar2 >> 8) | (param_2 | *local_18) & 0x10100 | uVar8;
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                            param_3 = (int *)((int)param_3 + local_34)) {
                          local_c = (uint *)((int)local_c + local_2c);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_14 = local_14 + local_38;
                          local_10 = (uint *)((int)local_10 + local_3c);
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                      if (local_24 == 0) break;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      local_18 = local_1c;
                      local_c = local_10;
                    }
                    return;
                  }
                  local_18 = local_1c;
                  iVar5 = DAT_00dca3f8;
LAB_006f2510:
                  puVar7 = local_18;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_c = local_10;
                  do {
                    if (*(byte *)((int)local_c + 3) == 0) {
                      do {
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f26c0;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else if (*(byte *)((int)local_c + 3) == 0xff) {
                      do {
                        param_2._0_2_ =
                             CONCAT11(*(undefined1 *)
                                       (&DAT_00d0a2e0 +
                                       iVar4 * 0x100 +
                                       (&DAT_00d0a2e0)
                                       [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)]),
                                      *(undefined1 *)
                                       (&DAT_00d0a2e0 +
                                       iVar4 * 0x100 +
                                       (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c]));
                        param_2._0_3_ =
                             CONCAT12(*(undefined1 *)
                                       (&DAT_00d0a2e0 +
                                       iVar4 * 0x100 +
                                       (&DAT_00d0a2e0)
                                       [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)]),
                                      (undefined2)param_2);
                        param_2 = (uint)(uint3)param_2;
                        uVar2 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                        uVar8 = uVar2 & 0x1010100;
                        *local_18 = uVar8 - (uVar8 >> 8) | (param_2 | *local_18) & 0x10100 | uVar2;
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f26bb;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                      iVar5 = DAT_00dca3f8;
                    }
                    else {
                      do {
                        uVar2 = (uint)*(byte *)((int)local_c + 3);
                        param_2._0_2_ =
                             CONCAT11((char)((&DAT_00d0a2e0)
                                             [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] *
                                             uVar2 * iVar5 >> 0x10),
                                      (char)((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c]
                                             * uVar2 * iVar5 >> 0x10));
                        param_2._0_3_ =
                             CONCAT12((char)((&DAT_00d0a2e0)
                                             [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] *
                                             uVar2 * iVar5 >> 0x10),(undefined2)param_2);
                        param_2 = (uint)(uint3)param_2;
                        uVar2 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                        uVar8 = uVar2 & 0x1010100;
                        *local_18 = uVar8 - (uVar8 >> 8) | (param_2 | *local_18) & 0x10100 | uVar2;
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f26bb;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        iVar5 = DAT_00dca3f8;
                      } while (0 < (int)param_3);
                    }
                    do {
                      local_c = (uint *)((int)local_c + local_2c);
                      param_3 = (int *)((int)param_3 + local_34);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                if (*(int *)(param_2 + 0x2c) != 1) {
                  if (param_4 == 0) {
                    do {
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      puVar7 = local_10;
                      local_18 = local_1c;
                      while( true ) {
                        param_2._0_2_ =
                             CONCAT11(*(undefined1 *)
                                       (&DAT_00d0a2e0 +
                                       iVar4 * 0x100 + (uint)*(byte *)((int)puVar7 + 1)),
                                      *(undefined1 *)
                                       (&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)(byte)*puVar7));
                        param_2._0_3_ =
                             CONCAT12(*(undefined1 *)
                                       (&DAT_00d0a2e0 +
                                       iVar4 * 0x100 + (uint)*(byte *)((int)puVar7 + 2)),
                                      (undefined2)param_2);
                        param_2 = (uint)(uint3)param_2;
                        uVar3 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                        uVar2 = uVar3 & 0x1010100;
                        *local_18 = uVar2 - (uVar2 >> 8) | (param_2 | *local_18) & 0x10100 | uVar3;
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        if ((int)param_3 < 1) {
                          do {
                            param_3 = (int *)((int)param_3 + local_34);
                            puVar7 = (uint *)((int)puVar7 + local_2c);
                          } while ((int)param_3 < 1);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_14 = local_14 + local_38;
                          local_10 = (uint *)((int)local_10 + local_3c);
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_006f2310:
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  puVar9 = local_10;
                  local_18 = local_1c;
                  do {
                    if (*puVar9 == uVar2) {
                      do {
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f23d1;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        param_2._0_2_ =
                             CONCAT11(*(undefined1 *)
                                       (&DAT_00d0a2e0 +
                                       iVar4 * 0x100 + (uint)*(byte *)((int)puVar9 + 1)),
                                      *(undefined1 *)
                                       (&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)(byte)*puVar9));
                        param_2._0_3_ =
                             CONCAT12(*(undefined1 *)
                                       (&DAT_00d0a2e0 +
                                       iVar4 * 0x100 + (uint)*(byte *)((int)puVar9 + 2)),
                                      (undefined2)param_2);
                        param_2 = (uint)(uint3)param_2;
                        uVar11 = (param_2 & 0xfefeff) + (*puVar7 & 0xfefeff);
                        uVar3 = uVar11 & 0x1010100;
                        *local_18 = uVar3 - (uVar3 >> 8) | (param_2 | *local_18) & 0x10100 | uVar11;
                        puVar7 = local_18 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f23d1;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        local_18 = puVar7;
                      } while (0 < (int)param_3);
                    }
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      puVar9 = (uint *)((int)puVar9 + local_2c);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                iVar5 = DAT_00dca3f8;
                if (param_4 == 0) {
                  do {
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    puVar7 = local_10;
                    local_18 = local_1c;
                    while( true ) {
                      uVar2 = (uint)*(byte *)((int)puVar7 + 3);
                      param_2._0_2_ =
                           CONCAT11((char)(*(byte *)((int)puVar7 + 1) * uVar2 * DAT_00dca3f8 >> 0x10
                                          ),(char)((byte)*puVar7 * uVar2 * DAT_00dca3f8 >> 0x10));
                      param_2._0_3_ =
                           CONCAT12((char)(*(byte *)((int)puVar7 + 2) * uVar2 * DAT_00dca3f8 >> 0x10
                                          ),(undefined2)param_2);
                      param_2 = (uint)(uint3)param_2;
                      uVar3 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                      uVar2 = uVar3 & 0x1010100;
                      *local_18 = uVar2 - (uVar2 >> 8) | (param_2 | *local_18) & 0x10100 | uVar3;
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          puVar7 = (uint *)((int)puVar7 + local_2c);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006f2037:
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_10;
                puVar9 = local_1c;
                local_18 = local_1c;
                do {
                  if (*(byte *)((int)puVar7 + 3) == 0) {
                    do {
                      puVar9 = puVar9 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f21a4;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar9;
                    } while (0 < (int)param_3);
                  }
                  else if (*(byte *)((int)puVar7 + 3) == 0xff) {
                    do {
                      param_2._0_2_ =
                           CONCAT11(*(undefined1 *)
                                     (&DAT_00d0a2e0 +
                                     iVar4 * 0x100 + (uint)*(byte *)((int)puVar7 + 1)),
                                    *(undefined1 *)
                                     (&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)(byte)*puVar7));
                      param_2._0_3_ =
                           CONCAT12(*(undefined1 *)
                                     (&DAT_00d0a2e0 +
                                     iVar4 * 0x100 + (uint)*(byte *)((int)puVar7 + 2)),
                                    (undefined2)param_2);
                      param_2 = (uint)(uint3)param_2;
                      uVar3 = (param_2 & 0xfefeff) + (*puVar9 & 0xfefeff);
                      uVar2 = uVar3 & 0x1010100;
                      *local_18 = uVar2 - (uVar2 >> 8) | (param_2 | *puVar9) & 0x10100 | uVar3;
                      puVar9 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f219f;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar9;
                    } while (0 < (int)param_3);
                    iVar5 = DAT_00dca3f8;
                  }
                  else {
                    do {
                      uVar2 = (uint)*(byte *)((int)puVar7 + 3);
                      param_2._0_2_ =
                           CONCAT11((char)(*(byte *)((int)puVar7 + 1) * uVar2 * iVar5 >> 0x10),
                                    (char)((byte)*puVar7 * uVar2 * iVar5 >> 0x10));
                      param_2._0_3_ =
                           CONCAT12((char)(*(byte *)((int)puVar7 + 2) * uVar2 * iVar5 >> 0x10),
                                    (undefined2)param_2);
                      param_2 = (uint)(uint3)param_2;
                      uVar3 = (param_2 & 0xfefeff) + (*puVar9 & 0xfefeff);
                      uVar2 = uVar3 & 0x1010100;
                      *local_18 = uVar2 - (uVar2 >> 8) | (param_2 | *puVar9) & 0x10100 | uVar3;
                      puVar9 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f219f;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                      local_18 = puVar9;
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    puVar7 = (uint *)((int)puVar7 + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                local_18 = local_1c;
                if (*(int *)(param_2 + 0x2c) != 1) {
                  local_20 = local_28;
                  iVar5 = DAT_00dca3f8;
                  if (param_4 == 0) {
                    do {
                      puVar7 = local_18;
                      local_20 = local_28;
                      local_c = local_10;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      while( true ) {
                        uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                        param_2._0_2_ =
                             CONCAT11((char)((&DAT_00d0a2e0)
                                             [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] *
                                             uVar2 * DAT_00dca3f8 >> 0x10),
                                      (char)((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c]
                                             * uVar2 * DAT_00dca3f8 >> 0x10));
                        param_2 = (uint)CONCAT12((char)((&DAT_00d0a2e0)
                                                        [uVar18 * 0x100 +
                                                         (uint)*(byte *)((int)local_c + 2)] * uVar2
                                                        * DAT_00dca3f8 >> 0x10),(undefined2)param_2)
                        ;
                        uVar8 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                        uVar2 = uVar8 & 0x1010100;
                        *local_18 = uVar2 - (uVar2 >> 8) | (param_2 | *local_18) & 0x10100 | uVar8;
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                            param_3 = (int *)((int)param_3 + local_34)) {
                          local_c = (uint *)((int)local_c + local_2c);
                          local_20 = local_20 + local_58;
                        }
                      }
                      local_18 = (uint *)((int)puVar7 + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_14 = local_14 + local_38;
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_28 = local_28 + local_5c;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_006f1d76:
                  puVar7 = local_18;
                  local_28 = local_20;
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  do {
                    if (*local_c == uVar2) {
                      do {
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f1e7a;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                        param_2._0_2_ =
                             CONCAT11((char)((&DAT_00d0a2e0)
                                             [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] *
                                             uVar8 * iVar5 >> 0x10),
                                      (char)((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c]
                                             * uVar8 * iVar5 >> 0x10));
                        param_2 = (uint)CONCAT12((char)((&DAT_00d0a2e0)
                                                        [uVar18 * 0x100 +
                                                         (uint)*(byte *)((int)local_c + 2)] * uVar8
                                                        * iVar5 >> 0x10),(undefined2)param_2);
                        uVar14 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                        uVar8 = uVar14 & 0x1010100;
                        *local_18 = uVar8 - (uVar8 >> 8) | (param_2 | *local_18) & 0x10100 | uVar14;
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        iVar5 = DAT_00dca3f8;
                        if (local_8 == 0) goto LAB_006f1e7a;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    do {
                      local_20 = local_20 + local_58;
                      param_3 = (int *)((int)param_3 + local_34);
                      local_c = (uint *)((int)local_c + local_2c);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                if (param_4 == 0) {
                  local_8 = local_44;
                  local_c = local_10;
                  local_20 = local_28;
                  param_3 = (int *)local_40;
                  while( true ) {
                    while( true ) {
                      uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      uVar2 = (uint)*(byte *)((int)local_c + 3);
                      param_2._0_2_ =
                           CONCAT11((char)((&DAT_00d0a2e0)
                                           [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] *
                                           uVar8 * uVar2 * DAT_00dca3f8 >> 0x18),
                                    (char)((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] *
                                           uVar8 * uVar2 * DAT_00dca3f8 >> 0x18));
                      param_2._0_3_ =
                           CONCAT12((char)((&DAT_00d0a2e0)
                                           [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] *
                                           uVar8 * uVar2 * DAT_00dca3f8 >> 0x18),(undefined2)param_2
                                   );
                      param_2 = (uint)(uint3)param_2;
                      uVar8 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                      uVar2 = uVar8 & 0x1010100;
                      *local_18 = uVar2 - (uVar2 >> 8) | (param_2 | *local_18) & 0x10100 | uVar8;
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                        local_20 = local_20 + local_58;
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_20 = local_28;
                    local_18 = local_1c;
                    local_c = local_10;
                  }
                  return;
                }
                local_20 = local_28;
                iVar5 = DAT_00dca3f8;
LAB_006f19c2:
                puVar7 = local_18;
                local_28 = local_20;
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar9 = local_10;
                do {
                  if (*(byte *)((int)puVar9 + 3) == 0) {
                    do {
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f1bb0;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else if (*(byte *)((int)puVar9 + 3) == 0xff) {
                    do {
                      uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      param_2._0_2_ =
                           CONCAT11((char)((&DAT_00d0a2e0)
                                           [uVar3 * 0x100 + (uint)*(byte *)((int)puVar9 + 1)] *
                                           uVar2 * iVar5 >> 0x10),
                                    (char)((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*puVar9] *
                                           uVar2 * iVar5 >> 0x10));
                      param_2._0_3_ =
                           CONCAT12((char)((&DAT_00d0a2e0)
                                           [uVar18 * 0x100 + (uint)*(byte *)((int)puVar9 + 2)] *
                                           uVar2 * iVar5 >> 0x10),(undefined2)param_2);
                      param_2 = (uint)(uint3)param_2;
                      uVar2 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                      uVar8 = uVar2 & 0x1010100;
                      *local_18 = uVar8 - (uVar8 >> 8) | (param_2 | *local_18) & 0x10100 | uVar2;
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f1bab;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      param_2._0_2_ =
                           CONCAT11((char)((&DAT_00d0a2e0)
                                           [uVar3 * 0x100 + (uint)*(byte *)((int)puVar9 + 1)] *
                                           uVar2 * (uint)*(byte *)((int)puVar9 + 3) * iVar5 >> 0x18)
                                    ,(char)((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*puVar9] *
                                            uVar2 * (uint)*(byte *)((int)puVar9 + 3) * iVar5 >> 0x18
                                           ));
                      param_2._0_3_ =
                           CONCAT12((char)((&DAT_00d0a2e0)
                                           [uVar18 * 0x100 + (uint)*(byte *)((int)puVar9 + 2)] *
                                           uVar2 * (uint)*(byte *)((int)puVar9 + 3) * iVar5 >> 0x18)
                                    ,(undefined2)param_2);
                      param_2 = (uint)(uint3)param_2;
                      uVar2 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                      uVar8 = uVar2 & 0x1010100;
                      *local_18 = uVar8 - (uVar8 >> 8) | (param_2 | *local_18) & 0x10100 | uVar2;
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f1bab;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_20 = local_20 + local_58;
                    param_3 = (int *)((int)param_3 + local_34);
                    puVar9 = (uint *)((int)puVar9 + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (*(int *)(param_2 + 0x2c) != 1) {
                local_18 = local_1c;
                if (param_4 == 0) {
                  local_8 = local_44;
                  local_20 = local_28;
                  param_3 = (int *)local_40;
                  puVar7 = local_10;
                  while( true ) {
                    while( true ) {
                      uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      param_2._0_2_ =
                           CONCAT11((char)(*(byte *)((int)puVar7 + 1) * uVar2 * DAT_00dca3f8 >> 0x10
                                          ),(char)((byte)*puVar7 * uVar2 * DAT_00dca3f8 >> 0x10));
                      param_2._0_3_ =
                           CONCAT12((char)(*(byte *)((int)puVar7 + 2) * uVar2 * DAT_00dca3f8 >> 0x10
                                          ),(undefined2)param_2);
                      param_2 = (uint)(uint3)param_2;
                      uVar3 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                      uVar2 = uVar3 & 0x1010100;
                      *local_18 = uVar2 - (uVar2 >> 8) | (param_2 | *local_18) & 0x10100 | uVar3;
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        puVar7 = (uint *)((int)puVar7 + local_2c);
                        local_20 = local_20 + local_58;
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    puVar7 = local_10;
                    local_20 = local_28;
                    local_18 = local_1c;
                  }
                  return;
                }
                iVar5 = DAT_00dca3f8;
LAB_006f1732:
                local_20 = local_28;
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_10;
                puVar9 = local_1c;
                local_18 = local_1c;
                do {
                  if (*puVar7 == uVar2) {
                    do {
                      puVar9 = puVar9 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f181b;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar9;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar3 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      param_2._0_2_ =
                           CONCAT11((char)(*(byte *)((int)puVar7 + 1) * uVar3 * iVar5 >> 0x10),
                                    (char)((byte)*puVar7 * uVar3 * iVar5 >> 0x10));
                      param_2._0_3_ =
                           CONCAT12((char)(*(byte *)((int)puVar7 + 2) * uVar3 * iVar5 >> 0x10),
                                    (undefined2)param_2);
                      param_2 = (uint)(uint3)param_2;
                      uVar11 = (param_2 & 0xfefeff) + (*puVar9 & 0xfefeff);
                      uVar3 = uVar11 & 0x1010100;
                      *local_18 = uVar3 - (uVar3 >> 8) | (param_2 | *puVar9) & 0x10100 | uVar11;
                      puVar9 = local_18 + 1;
                      local_8 = local_8 + -1;
                      iVar5 = DAT_00dca3f8;
                      if (local_8 == 0) goto LAB_006f181b;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      local_18 = puVar9;
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    puVar7 = (uint *)((int)puVar7 + local_2c);
                    local_20 = local_20 + local_58;
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (param_4 == 0) {
                local_8 = local_44;
                local_18 = local_1c;
                local_20 = local_28;
                param_3 = (int *)local_40;
                puVar7 = local_10;
                while( true ) {
                  while( true ) {
                    iVar5 = (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                            (uint)*(byte *)((int)puVar7 + 3);
                    param_2._0_2_ =
                         CONCAT11((char)((uint)*(byte *)((int)puVar7 + 1) * iVar5 * DAT_00dca3f8 >>
                                        0x18),
                                  (char)((uint)(byte)*puVar7 * iVar5 * DAT_00dca3f8 >> 0x18));
                    param_2._0_3_ =
                         CONCAT12((char)((uint)*(byte *)((int)puVar7 + 2) * iVar5 * DAT_00dca3f8 >>
                                        0x18),(undefined2)param_2);
                    param_2 = (uint)(uint3)param_2;
                    uVar3 = (param_2 & 0xfefeff) + (*local_18 & 0xfefeff);
                    uVar2 = uVar3 & 0x1010100;
                    *local_18 = uVar2 - (uVar2 >> 8) | (param_2 | *local_18) & 0x10100 | uVar3;
                    local_18 = local_18 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        puVar7 = (uint *)((int)puVar7 + local_2c);
                        local_20 = local_20 + local_58;
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                  if (local_24 == 0) break;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_10;
                  local_20 = local_28;
                  local_18 = local_1c;
                }
                return;
              }
              local_20 = local_28;
              iVar5 = DAT_00dca3f8;
LAB_006f13e7:
              local_28 = local_20;
              local_8 = local_44;
              puVar7 = local_10;
              param_3 = (int *)local_40;
              puVar9 = local_1c;
              do {
                if (*(byte *)((int)puVar7 + 3) == 0) {
                  do {
                    puVar9 = puVar9 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f157a;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else if (*(byte *)((int)puVar7 + 3) == 0xff) {
                  do {
                    uVar2 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                    param_2._0_2_ =
                         CONCAT11((char)(*(byte *)((int)puVar7 + 1) * uVar2 * iVar5 >> 0x10),
                                  (char)((byte)*puVar7 * uVar2 * iVar5 >> 0x10));
                    param_2._0_3_ =
                         CONCAT12((char)(*(byte *)((int)puVar7 + 2) * uVar2 * iVar5 >> 0x10),
                                  (undefined2)param_2);
                    param_2 = (uint)(uint3)param_2;
                    uVar3 = (param_2 & 0xfefeff) + (*puVar9 & 0xfefeff);
                    uVar2 = uVar3 & 0x1010100;
                    *puVar9 = uVar2 - (uVar2 >> 8) | (param_2 | *puVar9) & 0x10100 | uVar3;
                    puVar9 = puVar9 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f1575;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    iVar6 = (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                            (uint)*(byte *)((int)puVar7 + 3);
                    param_2._0_2_ =
                         CONCAT11((char)((uint)*(byte *)((int)puVar7 + 1) * iVar6 * iVar5 >> 0x18),
                                  (char)((uint)(byte)*puVar7 * iVar6 * iVar5 >> 0x18));
                    param_2._0_3_ =
                         CONCAT12((char)((uint)*(byte *)((int)puVar7 + 2) * iVar6 * iVar5 >> 0x18),
                                  (undefined2)param_2);
                    param_2 = (uint)(uint3)param_2;
                    uVar3 = (param_2 & 0xfefeff) + (*puVar9 & 0xfefeff);
                    uVar2 = uVar3 & 0x1010100;
                    *puVar9 = uVar2 - (uVar2 >> 8) | (param_2 | *puVar9) & 0x10100 | uVar3;
                    puVar9 = puVar9 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f1575;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  puVar7 = (uint *)((int)puVar7 + local_2c);
                  local_20 = local_20 + local_58;
                } while ((int)param_3 < 1);
              } while( true );
            }
            break;
          case 3:
            if (DAT_00dca3f8 != 0) {
              if (param_5 == 0) {
                if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                  if (*(int *)(param_2 + 0x2c) != 1) {
                    local_18 = local_1c;
                    if (param_4 == 0) {
                      do {
                        puVar7 = local_18;
                        local_c = local_10;
                        local_8 = local_44;
                        param_3 = (int *)local_40;
                        while( true ) {
                          uVar2 = param_2;
                          param_2._0_2_ =
                               CONCAT11(*(undefined1 *)
                                         (&DAT_00d0a2e0 +
                                         iVar4 * 0x100 +
                                         (&DAT_00d0a2e0)
                                         [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)]),
                                        *(undefined1 *)
                                         (&DAT_00d0a2e0 +
                                         iVar4 * 0x100 +
                                         (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c]));
                          param_2._3_1_ = SUB41(uVar2,3);
                          param_2._0_3_ =
                               CONCAT12(*(undefined1 *)
                                         (&DAT_00d0a2e0 +
                                         iVar4 * 0x100 +
                                         (&DAT_00d0a2e0)
                                         [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)]),
                                        (undefined2)param_2);
                          uVar8 = (*local_18 | 0x1010100) - (param_2 & 0xfefefeff);
                          uVar2 = uVar8 & 0x1010100;
                          *local_18 = uVar2 - (uVar2 >> 8) & uVar8;
                          local_18 = local_18 + 1;
                          local_8 = local_8 + -1;
                          if (local_8 == 0) break;
                          param_3 = (int *)((int)param_3 + -0x10000);
                          if ((int)param_3 < 1) {
                            do {
                              local_c = (uint *)((int)local_c + local_2c);
                              param_3 = (int *)((int)param_3 + local_34);
                            } while ((int)param_3 < 1);
                          }
                        }
                        local_18 = (uint *)((int)puVar7 + local_48);
                        local_14 = local_14 - 0x10000;
                        if ((int)local_14 < 1) {
                          do {
                            local_10 = (uint *)((int)local_10 + local_3c);
                            local_14 = local_14 + local_38;
                          } while ((int)local_14 < 1);
                        }
                        local_24 = local_24 + -1;
                      } while (local_24 != 0);
                      return;
                    }
LAB_006f3f50:
                    puVar7 = local_18;
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    do {
                      if (*local_c == uVar2) {
                        do {
                          local_18 = local_18 + 1;
                          local_8 = local_8 + -1;
                          if (local_8 == 0) goto LAB_006f4005;
                          param_3 = (int *)((int)param_3 + -0x10000);
                        } while (0 < (int)param_3);
                      }
                      else {
                        do {
                          uVar8 = param_2;
                          param_2._0_2_ =
                               CONCAT11(*(undefined1 *)
                                         (&DAT_00d0a2e0 +
                                         iVar4 * 0x100 +
                                         (&DAT_00d0a2e0)
                                         [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)]),
                                        *(undefined1 *)
                                         (&DAT_00d0a2e0 +
                                         iVar4 * 0x100 +
                                         (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c]));
                          param_2._3_1_ = SUB41(uVar8,3);
                          param_2._0_3_ =
                               CONCAT12(*(undefined1 *)
                                         (&DAT_00d0a2e0 +
                                         iVar4 * 0x100 +
                                         (&DAT_00d0a2e0)
                                         [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)]),
                                        (undefined2)param_2);
                          uVar14 = (*local_18 | 0x1010100) - (param_2 & 0xfefefeff);
                          uVar8 = uVar14 & 0x1010100;
                          *local_18 = uVar8 - (uVar8 >> 8) & uVar14;
                          local_18 = local_18 + 1;
                          local_8 = local_8 + -1;
                          if (local_8 == 0) goto LAB_006f4005;
                          param_3 = (int *)((int)param_3 + -0x10000);
                        } while (0 < (int)param_3);
                      }
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        local_c = (uint *)((int)local_c + local_2c);
                      } while ((int)param_3 < 1);
                    } while( true );
                  }
                  if (param_4 == 0) {
                    local_18 = local_1c;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    puVar7 = local_10;
                    while( true ) {
                      while( true ) {
                        uVar2 = param_2;
                        uVar8 = (uint)*(byte *)((int)puVar7 + 3);
                        param_2._0_2_ =
                             CONCAT11((char)((&DAT_00d0a2e0)
                                             [uVar3 * 0x100 + (uint)*(byte *)((int)puVar7 + 1)] *
                                             uVar8 * DAT_00dca3f8 >> 0x10),
                                      (char)((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*puVar7] *
                                             uVar8 * DAT_00dca3f8 >> 0x10));
                        param_2._3_1_ = SUB41(uVar2,3);
                        param_2._0_3_ =
                             CONCAT12((char)((&DAT_00d0a2e0)
                                             [uVar18 * 0x100 + (uint)*(byte *)((int)puVar7 + 2)] *
                                             uVar8 * DAT_00dca3f8 >> 0x10),(undefined2)param_2);
                        uVar8 = (*local_18 | 0x1010100) - (param_2 & 0xfefefeff);
                        uVar2 = uVar8 & 0x1010100;
                        *local_18 = uVar2 - (uVar2 >> 8) & uVar8;
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        if ((int)param_3 < 1) {
                          do {
                            param_3 = (int *)((int)param_3 + local_34);
                            puVar7 = (uint *)((int)puVar7 + local_2c);
                          } while ((int)param_3 < 1);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_14 = local_14 + local_38;
                          local_10 = (uint *)((int)local_10 + local_3c);
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                      if (local_24 == 0) break;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      puVar7 = local_10;
                      local_18 = local_1c;
                    }
                    return;
                  }
                  local_18 = local_1c;
                  iVar5 = DAT_00dca3f8;
LAB_006f3c52:
                  puVar7 = local_18;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  local_c = local_10;
                  do {
                    if (*(byte *)((int)local_c + 3) == 0) {
                      do {
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f3dd0;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else if (*(byte *)((int)local_c + 3) == 0xff) {
                      do {
                        uVar2 = param_2;
                        param_2._0_2_ =
                             CONCAT11(*(undefined1 *)
                                       (&DAT_00d0a2e0 +
                                       iVar4 * 0x100 +
                                       (&DAT_00d0a2e0)
                                       [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)]),
                                      *(undefined1 *)
                                       (&DAT_00d0a2e0 +
                                       iVar4 * 0x100 +
                                       (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c]));
                        param_2._3_1_ = SUB41(uVar2,3);
                        param_2._0_3_ =
                             CONCAT12(*(undefined1 *)
                                       (&DAT_00d0a2e0 +
                                       iVar4 * 0x100 +
                                       (&DAT_00d0a2e0)
                                       [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)]),
                                      (undefined2)param_2);
                        uVar8 = (*local_18 | 0x1010100) - (param_2 & 0xfefefeff);
                        uVar2 = uVar8 & 0x1010100;
                        *local_18 = uVar2 - (uVar2 >> 8) & uVar8;
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f3dcb;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                      iVar5 = DAT_00dca3f8;
                    }
                    else {
                      do {
                        uVar2 = param_2;
                        uVar8 = (uint)*(byte *)((int)local_c + 3);
                        param_2._0_2_ =
                             CONCAT11((char)((&DAT_00d0a2e0)
                                             [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] *
                                             uVar8 * iVar5 >> 0x10),
                                      (char)((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c]
                                             * uVar8 * iVar5 >> 0x10));
                        param_2._3_1_ = SUB41(uVar2,3);
                        param_2._0_3_ =
                             CONCAT12((char)((&DAT_00d0a2e0)
                                             [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] *
                                             uVar8 * iVar5 >> 0x10),(undefined2)param_2);
                        uVar8 = (*local_18 | 0x1010100) - (param_2 & 0xfefefeff);
                        uVar2 = uVar8 & 0x1010100;
                        *local_18 = uVar2 - (uVar2 >> 8) & uVar8;
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f3dcb;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        iVar5 = DAT_00dca3f8;
                      } while (0 < (int)param_3);
                    }
                    do {
                      local_c = (uint *)((int)local_c + local_2c);
                      param_3 = (int *)((int)param_3 + local_34);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                if (*(int *)(param_2 + 0x2c) != 1) {
                  if (param_4 == 0) {
                    if (DAT_00dca3f8 != 0xff) {
                      do {
                        local_8 = local_44;
                        param_3 = (int *)local_40;
                        puVar7 = local_10;
                        puVar9 = local_1c;
                        while( true ) {
                          uVar2 = param_2;
                          param_2._0_2_ =
                               CONCAT11(*(undefined1 *)
                                         (&DAT_00d0a2e0 +
                                         iVar4 * 0x100 + (uint)*(byte *)((int)puVar7 + 1)),
                                        *(undefined1 *)
                                         (&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)(byte)*puVar7));
                          param_2._3_1_ = SUB41(uVar2,3);
                          param_2._0_3_ =
                               CONCAT12(*(undefined1 *)
                                         (&DAT_00d0a2e0 +
                                         iVar4 * 0x100 + (uint)*(byte *)((int)puVar7 + 2)),
                                        (undefined2)param_2);
                          uVar3 = (*puVar9 | 0x1010100) - (param_2 & 0xfefefeff);
                          uVar2 = uVar3 & 0x1010100;
                          *puVar9 = uVar2 - (uVar2 >> 8) & uVar3;
                          puVar9 = puVar9 + 1;
                          local_8 = local_8 + -1;
                          if (local_8 == 0) break;
                          param_3 = (int *)((int)param_3 + -0x10000);
                          if ((int)param_3 < 1) {
                            do {
                              param_3 = (int *)((int)param_3 + local_34);
                              puVar7 = (uint *)((int)puVar7 + local_2c);
                            } while ((int)param_3 < 1);
                          }
                        }
                        local_1c = (uint *)((int)local_1c + local_48);
                        local_14 = local_14 - 0x10000;
                        if ((int)local_14 < 1) {
                          do {
                            local_14 = local_14 + local_38;
                            local_10 = (uint *)((int)local_10 + local_3c);
                          } while ((int)local_14 < 1);
                        }
                        local_24 = local_24 + -1;
                      } while (local_24 != 0);
                      return;
                    }
                    if (DAT_00a2e8cc != 1) {
                      do {
                        local_8 = local_44;
                        iVar6 = local_40;
                        puVar7 = local_10;
                        while( true ) {
                          uVar3 = (*local_1c | 0x1010100) - (*puVar7 & 0xfefeff);
                          uVar2 = uVar3 & 0x1010100;
                          *local_1c = uVar3 & uVar2 - (uVar2 >> 8);
                          local_1c = local_1c + 1;
                          local_8 = local_8 + -1;
                          if (local_8 == 0) break;
                          iVar4 = iVar6 + -0x10000;
                          bVar20 = iVar6 < 0x10000;
                          iVar6 = iVar4;
                          if (iVar4 == 0 || bVar20) {
                            do {
                              puVar7 = (uint *)((int)puVar7 + local_2c);
                              bVar20 = SCARRY4(iVar4,local_34);
                              iVar4 = iVar4 + local_34;
                              iVar6 = iVar4;
                            } while (bVar20 != iVar4 < 0);
                          }
                        }
                        local_1c = (uint *)((int)local_1c + iVar5);
                        bVar20 = local_14 < 0x10000;
                        local_14 = local_14 - 0x10000;
                        if (bVar20 || local_14 == 0) {
                          do {
                            local_10 = (uint *)((int)local_10 + local_3c);
                            bVar20 = SCARRY4(local_14,local_38);
                            local_14 = local_14 + local_38;
                          } while (bVar20 != (int)local_14 < 0);
                        }
                        local_24 = local_24 + -1;
                      } while (local_24 != 0);
                      return;
                    }
                    do {
                      iVar6 = local_44;
                      iVar4 = local_40;
                      puVar7 = local_10;
LAB_006f3aa6:
                      uVar2 = *puVar7;
                      iVar13 = iVar4;
                      while( true ) {
                        uVar21 = psubusb((ulonglong)*local_1c,(ulonglong)uVar2);
                        *local_1c = (uint)uVar21;
                        local_1c = local_1c + 1;
                        iVar6 = iVar6 + -1;
                        if (iVar6 == 0) break;
                        iVar4 = iVar13 + -0x10000;
                        bVar20 = iVar13 < 0x10000;
                        iVar13 = iVar4;
                        if (iVar4 == 0 || bVar20) goto LAB_006f3ac0;
                      }
                      local_1c = (uint *)((int)local_1c + iVar5);
                      bVar20 = local_14 < 0x10000;
                      local_14 = local_14 - 0x10000;
                      if (bVar20 || local_14 == 0) {
                        do {
                          local_10 = (uint *)((int)local_10 + local_3c);
                          bVar20 = SCARRY4(local_14,local_38);
                          local_14 = local_14 + local_38;
                        } while (bVar20 != (int)local_14 < 0);
                      }
                      local_24 = local_24 + -1;
                      if (local_24 == 0) {
                        return;
                      }
                    } while( true );
                  }
                  if (DAT_00dca3f8 != 0xff) {
LAB_006f39a7:
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    puVar7 = local_10;
                    puVar9 = local_1c;
                    do {
                      if (*puVar7 == uVar2) {
                        do {
                          puVar9 = puVar9 + 1;
                          local_8 = local_8 + -1;
                          if (local_8 == 0) goto LAB_006f3a44;
                          param_3 = (int *)((int)param_3 + -0x10000);
                        } while (0 < (int)param_3);
                      }
                      else {
                        do {
                          uVar3 = param_2;
                          param_2._0_2_ =
                               CONCAT11(*(undefined1 *)
                                         (&DAT_00d0a2e0 +
                                         iVar4 * 0x100 + (uint)*(byte *)((int)puVar7 + 1)),
                                        *(undefined1 *)
                                         (&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)(byte)*puVar7));
                          param_2._3_1_ = SUB41(uVar3,3);
                          param_2._0_3_ =
                               CONCAT12(*(undefined1 *)
                                         (&DAT_00d0a2e0 +
                                         iVar4 * 0x100 + (uint)*(byte *)((int)puVar7 + 2)),
                                        (undefined2)param_2);
                          uVar11 = (*puVar9 | 0x1010100) - (param_2 & 0xfefefeff);
                          uVar3 = uVar11 & 0x1010100;
                          *puVar9 = uVar3 - (uVar3 >> 8) & uVar11;
                          puVar9 = puVar9 + 1;
                          local_8 = local_8 + -1;
                          if (local_8 == 0) goto LAB_006f3a44;
                          param_3 = (int *)((int)param_3 + -0x10000);
                        } while (0 < (int)param_3);
                      }
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        puVar7 = (uint *)((int)puVar7 + local_2c);
                      } while ((int)param_3 < 1);
                    } while( true );
                  }
                  if (DAT_00a2e8cc != 1) {
                    do {
                      local_8 = local_44;
                      iVar6 = local_40;
                      puVar7 = local_10;
                      while( true ) {
                        if (*puVar7 != local_50) {
                          uVar3 = (*local_1c | 0x1010100) - (*puVar7 & 0xfefeff);
                          uVar2 = uVar3 & 0x1010100;
                          *local_1c = uVar3 & uVar2 - (uVar2 >> 8);
                        }
                        local_1c = local_1c + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        iVar4 = iVar6 + -0x10000;
                        bVar20 = iVar6 < 0x10000;
                        iVar6 = iVar4;
                        if (iVar4 == 0 || bVar20) {
                          do {
                            puVar7 = (uint *)((int)puVar7 + local_2c);
                            bVar20 = SCARRY4(iVar4,local_34);
                            iVar4 = iVar4 + local_34;
                            iVar6 = iVar4;
                          } while (bVar20 != iVar4 < 0);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + iVar5);
                      bVar20 = local_14 < 0x10000;
                      local_14 = local_14 - 0x10000;
                      if (bVar20 || local_14 == 0) {
                        do {
                          local_10 = (uint *)((int)local_10 + local_3c);
                          bVar20 = SCARRY4(local_14,local_38);
                          local_14 = local_14 + local_38;
                        } while (bVar20 != (int)local_14 < 0);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_006f38aa:
                  iVar6 = local_44;
                  iVar4 = local_40;
                  puVar7 = local_10;
                  do {
                    while( true ) {
                      uVar2 = *puVar7;
                      iVar13 = iVar4;
                      if (uVar2 != local_50) break;
                      do {
                        local_1c = local_1c + 1;
                        iVar6 = iVar6 + -1;
                        if (iVar6 == 0) goto LAB_006f38f3;
                        iVar4 = iVar13 + -0x10000;
                        bVar20 = 0xffff < iVar13;
                        iVar13 = iVar4;
                      } while (iVar4 != 0 && bVar20);
                      do {
                        puVar7 = (uint *)((int)puVar7 + local_2c);
                        bVar20 = SCARRY4(iVar4,local_34);
                        iVar4 = iVar4 + local_34;
                      } while (bVar20 != iVar4 < 0);
                    }
                    do {
                      uVar21 = psubusb((ulonglong)*local_1c,(ulonglong)uVar2);
                      *local_1c = (uint)uVar21;
                      local_1c = local_1c + 1;
                      iVar6 = iVar6 + -1;
                      if (iVar6 == 0) goto LAB_006f38f3;
                      iVar4 = iVar13 + -0x10000;
                      bVar20 = 0xffff < iVar13;
                      iVar13 = iVar4;
                    } while (iVar4 != 0 && bVar20);
                    do {
                      puVar7 = (uint *)((int)puVar7 + local_2c);
                      bVar20 = SCARRY4(iVar4,local_34);
                      iVar4 = iVar4 + local_34;
                    } while (bVar20 != iVar4 < 0);
                  } while( true );
                }
                if (param_4 == 0) {
                  local_8 = local_44;
                  puVar7 = local_10;
                  iVar5 = local_40;
                  puVar9 = local_1c;
                  while( true ) {
                    while( true ) {
                      uVar2 = param_2;
                      uVar3 = (uint)*(byte *)((int)puVar7 + 3);
                      param_2._0_2_ =
                           CONCAT11((char)(*(byte *)((int)puVar7 + 1) * uVar3 * DAT_00dca3f8 >> 0x10
                                          ),(char)((byte)*puVar7 * uVar3 * DAT_00dca3f8 >> 0x10));
                      param_2._3_1_ = SUB41(uVar2,3);
                      param_2._0_3_ =
                           CONCAT12((char)(*(byte *)((int)puVar7 + 2) * uVar3 * DAT_00dca3f8 >> 0x10
                                          ),(undefined2)param_2);
                      uVar3 = (*puVar9 | 0x1010100) - (param_2 & 0xfefefeff);
                      uVar2 = uVar3 & 0x1010100;
                      *puVar9 = uVar2 - (uVar2 >> 8) & uVar3;
                      puVar9 = puVar9 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (iVar5 = iVar5 + -0x10000; iVar5 < 1; iVar5 = iVar5 + local_34) {
                        puVar7 = (uint *)((int)puVar7 + local_2c);
                      }
                    }
                    puVar9 = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    puVar7 = local_10;
                    iVar5 = local_40;
                    local_1c = puVar9;
                  }
                  return;
                }
                iVar5 = DAT_00dca3f8;
LAB_006f3630:
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_10;
                puVar9 = local_1c;
                do {
                  if (*(byte *)((int)puVar7 + 3) == 0) {
                    do {
                      puVar9 = puVar9 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f3764;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else if (*(byte *)((int)puVar7 + 3) == 0xff) {
                    do {
                      uVar2 = param_2;
                      param_2._0_2_ =
                           CONCAT11(*(undefined1 *)
                                     (&DAT_00d0a2e0 +
                                     iVar4 * 0x100 + (uint)*(byte *)((int)puVar7 + 1)),
                                    *(undefined1 *)
                                     (&DAT_00d0a2e0 + iVar4 * 0x100 + (uint)(byte)*puVar7));
                      param_2._3_1_ = SUB41(uVar2,3);
                      param_2._0_3_ =
                           CONCAT12(*(undefined1 *)
                                     (&DAT_00d0a2e0 +
                                     iVar4 * 0x100 + (uint)*(byte *)((int)puVar7 + 2)),
                                    (undefined2)param_2);
                      uVar3 = (*puVar9 | 0x1010100) - (param_2 & 0xfefefeff);
                      uVar2 = uVar3 & 0x1010100;
                      *puVar9 = uVar2 - (uVar2 >> 8) & uVar3;
                      puVar9 = puVar9 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f375f;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                    iVar5 = DAT_00dca3f8;
                  }
                  else {
                    do {
                      uVar2 = param_2;
                      uVar3 = (uint)*(byte *)((int)puVar7 + 3);
                      param_2._0_2_ =
                           CONCAT11((char)(*(byte *)((int)puVar7 + 1) * uVar3 * iVar5 >> 0x10),
                                    (char)((byte)*puVar7 * uVar3 * iVar5 >> 0x10));
                      param_2._3_1_ = SUB41(uVar2,3);
                      param_2._0_3_ =
                           CONCAT12((char)(*(byte *)((int)puVar7 + 2) * uVar3 * iVar5 >> 0x10),
                                    (undefined2)param_2);
                      uVar3 = (*puVar9 | 0x1010100) - (param_2 & 0xfefefeff);
                      uVar2 = uVar3 & 0x1010100;
                      *puVar9 = uVar2 - (uVar2 >> 8) & uVar3;
                      puVar9 = puVar9 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f375f;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    puVar7 = (uint *)((int)puVar7 + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                local_18 = local_1c;
                local_20 = local_28;
                if (*(int *)(param_2 + 0x2c) != 1) {
                  iVar5 = DAT_00dca3f8;
                  if (param_4 == 0) {
                    do {
                      puVar7 = local_18;
                      local_c = local_10;
                      local_20 = local_28;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      while( true ) {
                        uVar2 = param_2;
                        uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                        param_2._0_2_ =
                             CONCAT11((char)((&DAT_00d0a2e0)
                                             [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] *
                                             uVar8 * DAT_00dca3f8 >> 0x10),
                                      (char)((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c]
                                             * uVar8 * DAT_00dca3f8 >> 0x10));
                        param_2._3_1_ = SUB41(uVar2,3);
                        param_2._0_3_ =
                             CONCAT12((char)((&DAT_00d0a2e0)
                                             [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] *
                                             uVar8 * DAT_00dca3f8 >> 0x10),(undefined2)param_2);
                        uVar8 = (*local_18 | 0x1010100) - (param_2 & 0xfefefeff);
                        uVar2 = uVar8 & 0x1010100;
                        *local_18 = uVar2 - (uVar2 >> 8) & uVar8;
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                            param_3 = (int *)((int)param_3 + local_34)) {
                          local_c = (uint *)((int)local_c + local_2c);
                          local_20 = local_20 + local_58;
                        }
                      }
                      local_18 = (uint *)((int)puVar7 + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_14 = local_14 + local_38;
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_28 = local_28 + local_5c;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_006f3370:
                  puVar7 = local_18;
                  local_28 = local_20;
                  local_c = local_10;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  do {
                    if (*local_c == uVar2) {
                      do {
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f346a;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        uVar8 = param_2;
                        uVar14 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                        param_2._0_2_ =
                             CONCAT11((char)((&DAT_00d0a2e0)
                                             [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] *
                                             uVar14 * iVar5 >> 0x10),
                                      (char)((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c]
                                             * uVar14 * iVar5 >> 0x10));
                        param_2._3_1_ = SUB41(uVar8,3);
                        param_2._0_3_ =
                             CONCAT12((char)((&DAT_00d0a2e0)
                                             [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] *
                                             uVar14 * iVar5 >> 0x10),(undefined2)param_2);
                        uVar14 = (*local_18 | 0x1010100) - (param_2 & 0xfefefeff);
                        uVar8 = uVar14 & 0x1010100;
                        *local_18 = uVar8 - (uVar8 >> 8) & uVar14;
                        local_18 = local_18 + 1;
                        local_8 = local_8 + -1;
                        iVar5 = DAT_00dca3f8;
                        if (local_8 == 0) goto LAB_006f346a;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    do {
                      local_20 = local_20 + local_58;
                      param_3 = (int *)((int)param_3 + local_34);
                      local_c = (uint *)((int)local_c + local_2c);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                iVar5 = DAT_00dca3f8;
                if (param_4 == 0) {
                  do {
                    puVar7 = local_18;
                    local_20 = local_28;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    puVar9 = local_10;
                    while( true ) {
                      uVar2 = param_2;
                      uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      param_2._0_2_ =
                           CONCAT11((char)((&DAT_00d0a2e0)
                                           [uVar3 * 0x100 + (uint)*(byte *)((int)puVar9 + 1)] *
                                           uVar8 * (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8
                                          >> 0x18),
                                    (char)((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*puVar9] *
                                           uVar8 * (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8
                                          >> 0x18));
                      param_2._3_1_ = SUB41(uVar2,3);
                      param_2._0_3_ =
                           CONCAT12((char)((&DAT_00d0a2e0)
                                           [uVar18 * 0x100 + (uint)*(byte *)((int)puVar9 + 2)] *
                                           uVar8 * (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8
                                          >> 0x18),(undefined2)param_2);
                      uVar8 = (*local_18 | 0x1010100) - (param_2 & 0xfefefeff);
                      uVar2 = uVar8 & 0x1010100;
                      *local_18 = uVar2 - (uVar2 >> 8) & uVar8;
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          puVar9 = (uint *)((int)puVar9 + local_2c);
                          local_20 = local_20 + local_58;
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_18 = (uint *)((int)puVar7 + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006f3001:
                puVar7 = local_18;
                local_28 = local_20;
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar9 = local_10;
                do {
                  if (*(byte *)((int)puVar9 + 3) == 0) {
                    do {
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f31d0;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else if (*(byte *)((int)puVar9 + 3) == 0xff) {
                    do {
                      uVar2 = param_2;
                      uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      param_2._0_2_ =
                           CONCAT11((char)((&DAT_00d0a2e0)
                                           [uVar3 * 0x100 + (uint)*(byte *)((int)puVar9 + 1)] *
                                           uVar8 * iVar5 >> 0x10),
                                    (char)((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*puVar9] *
                                           uVar8 * iVar5 >> 0x10));
                      param_2._3_1_ = SUB41(uVar2,3);
                      param_2._0_3_ =
                           CONCAT12((char)((&DAT_00d0a2e0)
                                           [uVar18 * 0x100 + (uint)*(byte *)((int)puVar9 + 2)] *
                                           uVar8 * iVar5 >> 0x10),(undefined2)param_2);
                      uVar8 = (*local_18 | 0x1010100) - (param_2 & 0xfefefeff);
                      uVar2 = uVar8 & 0x1010100;
                      *local_18 = uVar2 - (uVar2 >> 8) & uVar8;
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f31cb;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar2 = param_2;
                      uVar8 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      param_2._0_2_ =
                           CONCAT11((char)((&DAT_00d0a2e0)
                                           [uVar3 * 0x100 + (uint)*(byte *)((int)puVar9 + 1)] *
                                           uVar8 * (uint)*(byte *)((int)puVar9 + 3) * iVar5 >> 0x18)
                                    ,(char)((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*puVar9] *
                                            uVar8 * (uint)*(byte *)((int)puVar9 + 3) * iVar5 >> 0x18
                                           ));
                      param_2._3_1_ = SUB41(uVar2,3);
                      param_2._0_3_ =
                           CONCAT12((char)((&DAT_00d0a2e0)
                                           [uVar18 * 0x100 + (uint)*(byte *)((int)puVar9 + 2)] *
                                           uVar8 * (uint)*(byte *)((int)puVar9 + 3) * iVar5 >> 0x18)
                                    ,(undefined2)param_2);
                      uVar8 = (*local_18 | 0x1010100) - (param_2 & 0xfefefeff);
                      uVar2 = uVar8 & 0x1010100;
                      *local_18 = uVar2 - (uVar2 >> 8) & uVar8;
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f31cb;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_20 = local_20 + local_58;
                    param_3 = (int *)((int)param_3 + local_34);
                    puVar9 = (uint *)((int)puVar9 + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (*(int *)(param_2 + 0x2c) != 1) {
                if (param_4 == 0) {
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  pbVar19 = local_28;
                  puVar7 = local_10;
                  puVar9 = local_1c;
                  while( true ) {
                    while( true ) {
                      uVar2 = param_2;
                      uVar3 = (uint)(byte)(&DAT_00dca2e0)[*pbVar19];
                      param_2._0_2_ =
                           CONCAT11((char)(*(byte *)((int)puVar7 + 1) * uVar3 * DAT_00dca3f8 >> 0x10
                                          ),(char)((byte)*puVar7 * uVar3 * DAT_00dca3f8 >> 0x10));
                      param_2._3_1_ = SUB41(uVar2,3);
                      param_2._0_3_ =
                           CONCAT12((char)(*(byte *)((int)puVar7 + 2) * uVar3 * DAT_00dca3f8 >> 0x10
                                          ),(undefined2)param_2);
                      uVar3 = (*puVar9 | 0x1010100) - (param_2 & 0xfefefeff);
                      uVar2 = uVar3 & 0x1010100;
                      *puVar9 = uVar2 - (uVar2 >> 8) & uVar3;
                      puVar9 = puVar9 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          puVar7 = (uint *)((int)puVar7 + local_2c);
                          pbVar19 = pbVar19 + local_58;
                        } while ((int)param_3 < 1);
                      }
                    }
                    puVar9 = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    pbVar19 = local_28;
                    puVar7 = local_10;
                    local_1c = puVar9;
                  }
                  return;
                }
                iVar5 = DAT_00dca3f8;
LAB_006f2db0:
                local_20 = local_28;
                local_8 = local_44;
                iVar6 = local_40;
                puVar7 = local_10;
                puVar9 = local_1c;
                do {
                  if (*puVar7 == uVar2) {
                    do {
                      puVar9 = puVar9 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f2e78;
                      iVar6 = iVar6 + -0x10000;
                    } while (0 < iVar6);
                  }
                  else {
                    do {
                      uVar3 = param_2;
                      uVar11 = (uint)(byte)(&DAT_00dca2e0)[*local_20];
                      param_2._0_2_ =
                           CONCAT11((char)(*(byte *)((int)puVar7 + 1) * uVar11 * iVar5 >> 0x10),
                                    (char)((byte)*puVar7 * uVar11 * iVar5 >> 0x10));
                      param_2._3_1_ = SUB41(uVar3,3);
                      param_2._0_3_ =
                           CONCAT12((char)(*(byte *)((int)puVar7 + 2) * uVar11 * iVar5 >> 0x10),
                                    (undefined2)param_2);
                      uVar11 = (*puVar9 | 0x1010100) - (param_2 & 0xfefefeff);
                      uVar3 = uVar11 & 0x1010100;
                      *puVar9 = uVar3 - (uVar3 >> 8) & uVar11;
                      puVar9 = puVar9 + 1;
                      local_8 = local_8 + -1;
                      iVar5 = DAT_00dca3f8;
                      if (local_8 == 0) goto LAB_006f2e78;
                      iVar6 = iVar6 + -0x10000;
                    } while (0 < iVar6);
                  }
                  do {
                    iVar6 = iVar6 + local_34;
                    puVar7 = (uint *)((int)puVar7 + local_2c);
                    local_20 = local_20 + local_58;
                  } while (iVar6 < 1);
                } while( true );
              }
              if (param_4 == 0) {
                local_8 = local_44;
                param_3 = (int *)local_40;
                pbVar19 = local_28;
                puVar7 = local_10;
                puVar9 = local_1c;
                while( true ) {
                  while( true ) {
                    uVar2 = param_2;
                    iVar5 = (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * (uint)*(byte *)((int)puVar7 + 3)
                    ;
                    param_2._0_2_ =
                         CONCAT11((char)((uint)*(byte *)((int)puVar7 + 1) * iVar5 * DAT_00dca3f8 >>
                                        0x18),
                                  (char)((uint)(byte)*puVar7 * iVar5 * DAT_00dca3f8 >> 0x18));
                    param_2._3_1_ = SUB41(uVar2,3);
                    param_2._0_3_ =
                         CONCAT12((char)((uint)*(byte *)((int)puVar7 + 2) * iVar5 * DAT_00dca3f8 >>
                                        0x18),(undefined2)param_2);
                    uVar3 = (*puVar9 | 0x1010100) - (param_2 & 0xfefefeff);
                    uVar2 = uVar3 & 0x1010100;
                    *puVar9 = uVar2 - (uVar2 >> 8) & uVar3;
                    puVar9 = puVar9 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        puVar7 = (uint *)((int)puVar7 + local_2c);
                        pbVar19 = pbVar19 + local_58;
                      } while ((int)param_3 < 1);
                    }
                  }
                  puVar9 = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                  if (local_24 == 0) break;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  pbVar19 = local_28;
                  puVar7 = local_10;
                  local_1c = puVar9;
                }
                return;
              }
              iVar5 = DAT_00dca3f8;
LAB_006f2ac0:
              local_8 = local_44;
              puVar7 = local_10;
              param_3 = (int *)local_40;
              pbVar19 = local_28;
              puVar9 = local_1c;
              do {
                if (*(byte *)((int)puVar7 + 3) == 0) {
                  do {
                    puVar9 = puVar9 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f2c36;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else if (*(byte *)((int)puVar7 + 3) == 0xff) {
                  do {
                    uVar2 = param_2;
                    uVar3 = (uint)(byte)(&DAT_00dca2e0)[*pbVar19];
                    param_2._0_2_ =
                         CONCAT11((char)(*(byte *)((int)puVar7 + 1) * uVar3 * iVar5 >> 0x10),
                                  (char)((byte)*puVar7 * uVar3 * iVar5 >> 0x10));
                    param_2._3_1_ = SUB41(uVar2,3);
                    param_2._0_3_ =
                         CONCAT12((char)(*(byte *)((int)puVar7 + 2) * uVar3 * iVar5 >> 0x10),
                                  (undefined2)param_2);
                    uVar3 = (*puVar9 | 0x1010100) - (param_2 & 0xfefefeff);
                    uVar2 = uVar3 & 0x1010100;
                    *puVar9 = uVar2 - (uVar2 >> 8) & uVar3;
                    puVar9 = puVar9 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f2c31;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar2 = param_2;
                    iVar6 = (uint)(byte)(&DAT_00dca2e0)[*pbVar19] * (uint)*(byte *)((int)puVar7 + 3)
                    ;
                    param_2._0_2_ =
                         CONCAT11((char)((uint)*(byte *)((int)puVar7 + 1) * iVar6 * iVar5 >> 0x18),
                                  (char)((uint)(byte)*puVar7 * iVar6 * iVar5 >> 0x18));
                    param_2._3_1_ = SUB41(uVar2,3);
                    param_2._0_3_ =
                         CONCAT12((char)((uint)*(byte *)((int)puVar7 + 2) * iVar6 * iVar5 >> 0x18),
                                  (undefined2)param_2);
                    uVar3 = (*puVar9 | 0x1010100) - (param_2 & 0xfefefeff);
                    uVar2 = uVar3 & 0x1010100;
                    *puVar9 = uVar2 - (uVar2 >> 8) & uVar3;
                    puVar9 = puVar9 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f2c31;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                  } while (0 < (int)param_3);
                }
                do {
                  puVar7 = (uint *)((int)puVar7 + local_2c);
                  pbVar19 = pbVar19 + local_58;
                  param_3 = (int *)((int)param_3 + local_34);
                } while ((int)param_3 < 1);
              } while( true );
            }
            break;
          case 4:
            if (param_5 == 0) {
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (*(int *)(param_2 + 0x2c) != 1) {
                  if (param_4 == 0) {
                    do {
                      local_c = local_10;
                      local_8 = local_44;
                      puVar7 = local_1c;
                      param_3 = (int *)local_40;
                      while( true ) {
                        *(byte *)puVar7 =
                             (byte)((uint)(byte)*puVar7 *
                                    (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] >> 8);
                        *(byte *)((int)puVar7 + 1) =
                             (byte)((uint)*(byte *)((int)puVar7 + 1) *
                                    (&DAT_00d0a2e0)
                                    [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] >> 8);
                        *(byte *)((int)puVar7 + 2) =
                             (byte)((uint)*(byte *)((int)puVar7 + 2) *
                                    (&DAT_00d0a2e0)
                                    [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] >> 8);
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        param_3 = (int *)((int)param_3 + -0x10000);
                        if ((int)param_3 < 1) {
                          do {
                            local_c = (uint *)((int)local_c + local_2c);
                            param_3 = (int *)((int)param_3 + local_34);
                          } while ((int)param_3 < 1);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_14 = local_14 + local_38;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_006f5146:
                  local_c = local_10;
                  local_8 = local_44;
                  puVar7 = local_1c;
                  param_3 = (int *)local_40;
                  do {
                    if (*local_c == uVar2) {
                      do {
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f51e2;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        *(byte *)puVar7 =
                             (byte)((uint)(byte)*puVar7 *
                                    (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] >> 8);
                        *(byte *)((int)puVar7 + 1) =
                             (byte)((uint)*(byte *)((int)puVar7 + 1) *
                                    (&DAT_00d0a2e0)
                                    [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] >> 8);
                        *(byte *)((int)puVar7 + 2) =
                             (byte)((uint)*(byte *)((int)puVar7 + 2) *
                                    (&DAT_00d0a2e0)
                                    [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] >> 8);
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f51e2;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      local_c = (uint *)((int)local_c + local_2c);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                if (param_4 == 0) {
                  local_18 = local_1c;
                  do {
                    puVar7 = local_18;
                    local_8 = local_44;
                    puVar9 = local_10;
                    param_3 = (int *)local_40;
                    while( true ) {
                      *(byte *)local_18 =
                           (byte)((uint)*(byte *)((int)puVar9 + 3) *
                                  (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*puVar9] *
                                  (uint)(byte)*local_18 >> 0x10);
                      *(byte *)((int)local_18 + 1) =
                           (byte)((uint)*(byte *)((int)puVar9 + 3) *
                                  (&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)*(byte *)((int)puVar9 + 1)]
                                  * (uint)*(byte *)((int)local_18 + 1) >> 0x10);
                      *(byte *)((int)local_18 + 2) =
                           (byte)((uint)*(byte *)((int)puVar9 + 3) *
                                  (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)*(byte *)((int)puVar9 + 2)]
                                  * (uint)*(byte *)((int)local_18 + 2) >> 0x10);
                      local_18 = local_18 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          param_3 = (int *)((int)param_3 + local_34);
                          puVar9 = (uint *)((int)puVar9 + local_2c);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_18 = (uint *)((int)puVar7 + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006f4f03:
                local_c = local_10;
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                do {
                  if (*(byte *)((int)local_c + 3) == 0) {
                    do {
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f5015;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else if (*(byte *)((int)local_c + 3) == 0xff) {
                    do {
                      *(byte *)puVar7 =
                           (byte)((uint)(byte)*puVar7 *
                                  (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] >> 8);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)((uint)*(byte *)((int)puVar7 + 1) *
                                  (&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)]
                                 >> 8);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)((uint)*(byte *)((int)puVar7 + 2) *
                                  (&DAT_00d0a2e0)
                                  [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] >> 8);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f5015;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      *(byte *)puVar7 =
                           (byte)((uint)*(byte *)((int)local_c + 3) *
                                  (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] *
                                  (uint)(byte)*puVar7 >> 0x10);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)((uint)*(byte *)((int)local_c + 3) *
                                  (&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)]
                                  * (uint)*(byte *)((int)puVar7 + 1) >> 0x10);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)((uint)*(byte *)((int)local_c + 3) *
                                  (&DAT_00d0a2e0)
                                  [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] *
                                  (uint)*(byte *)((int)puVar7 + 2) >> 0x10);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f5015;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (*(int *)(param_2 + 0x2c) != 1) {
                if (param_4 == 0) {
                  do {
                    local_8 = local_44;
                    puVar9 = local_1c;
                    puVar7 = local_10;
                    iVar5 = local_40;
                    while( true ) {
                      *(byte *)puVar9 = (byte)((uint)(byte)*puVar7 * (uint)(byte)*puVar9 >> 8);
                      *(byte *)((int)puVar9 + 1) =
                           (byte)((uint)*(byte *)((int)puVar7 + 1) *
                                  (uint)*(byte *)((int)puVar9 + 1) >> 8);
                      *(byte *)((int)puVar9 + 2) =
                           (byte)((uint)*(byte *)((int)puVar7 + 2) *
                                  (uint)*(byte *)((int)puVar9 + 2) >> 8);
                      puVar9 = puVar9 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (iVar5 = iVar5 + -0x10000; iVar5 < 1; iVar5 = iVar5 + local_34) {
                        puVar7 = (uint *)((int)puVar7 + local_2c);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006f4d87:
                local_8 = local_44;
                puVar7 = local_1c;
                iVar5 = local_40;
                puVar9 = local_10;
                do {
                  if (*puVar9 == uVar2) {
                    do {
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f4e00;
                      iVar5 = iVar5 + -0x10000;
                    } while (0 < iVar5);
                  }
                  else {
                    do {
                      *(byte *)puVar7 = (byte)((uint)(byte)*puVar9 * (uint)(byte)*puVar7 >> 8);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)((uint)*(byte *)((int)puVar9 + 1) *
                                  (uint)*(byte *)((int)puVar7 + 1) >> 8);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)((uint)*(byte *)((int)puVar9 + 2) *
                                  (uint)*(byte *)((int)puVar7 + 2) >> 8);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f4e00;
                      iVar5 = iVar5 + -0x10000;
                    } while (0 < iVar5);
                  }
                  do {
                    iVar5 = iVar5 + local_34;
                    puVar9 = (uint *)((int)puVar9 + local_2c);
                  } while (iVar5 < 1);
                } while( true );
              }
              if (param_4 == 0) {
                do {
                  local_8 = local_44;
                  puVar7 = local_10;
                  puVar9 = local_1c;
                  iVar5 = local_40;
                  while( true ) {
                    *(byte *)puVar9 =
                         (byte)((uint)*(byte *)((int)puVar7 + 3) * (uint)(byte)*puVar7 *
                                (uint)(byte)*puVar9 >> 0x10);
                    *(byte *)((int)puVar9 + 1) =
                         (byte)((uint)*(byte *)((int)puVar7 + 1) * (uint)*(byte *)((int)puVar7 + 3)
                                * (uint)*(byte *)((int)puVar9 + 1) >> 0x10);
                    *(byte *)((int)puVar9 + 2) =
                         (byte)((uint)*(byte *)((int)puVar7 + 2) * (uint)*(byte *)((int)puVar7 + 3)
                                * (uint)*(byte *)((int)puVar9 + 2) >> 0x10);
                    puVar9 = puVar9 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (iVar5 = iVar5 + -0x10000; iVar5 < 1; iVar5 = iVar5 + local_34) {
                      puVar7 = (uint *)((int)puVar7 + local_2c);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006f4b75:
              local_8 = local_44;
              puVar7 = local_1c;
              puVar9 = local_10;
              iVar5 = local_40;
              do {
                if (*(byte *)((int)puVar9 + 3) == 0) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f4c61;
                    iVar5 = iVar5 + -0x10000;
                  } while (0 < iVar5);
                }
                else if (*(byte *)((int)puVar9 + 3) == 0xff) {
                  do {
                    *(byte *)puVar7 = (byte)((uint)(byte)*puVar9 * (uint)(byte)*puVar7 >> 8);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((uint)*(byte *)((int)puVar9 + 1) * (uint)*(byte *)((int)puVar7 + 1)
                               >> 8);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((uint)*(byte *)((int)puVar9 + 2) * (uint)*(byte *)((int)puVar7 + 2)
                               >> 8);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f4c61;
                    iVar5 = iVar5 + -0x10000;
                  } while (0 < iVar5);
                }
                else {
                  do {
                    *(byte *)puVar7 =
                         (byte)((uint)*(byte *)((int)puVar9 + 3) * (uint)(byte)*puVar9 *
                                (uint)(byte)*puVar7 >> 0x10);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((uint)*(byte *)((int)puVar9 + 1) * (uint)*(byte *)((int)puVar9 + 3)
                                * (uint)*(byte *)((int)puVar7 + 1) >> 0x10);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((uint)*(byte *)((int)puVar9 + 2) * (uint)*(byte *)((int)puVar9 + 3)
                                * (uint)*(byte *)((int)puVar7 + 2) >> 0x10);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f4c61;
                    iVar5 = iVar5 + -0x10000;
                  } while (0 < iVar5);
                }
                do {
                  iVar5 = iVar5 + local_34;
                  puVar9 = (uint *)((int)puVar9 + local_2c);
                } while (iVar5 < 1);
              } while( true );
            }
            if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
              local_20 = local_28;
              if (*(int *)(param_2 + 0x2c) != 1) {
                if (param_4 == 0) {
                  do {
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    puVar7 = local_1c;
                    local_20 = local_28;
                    local_c = local_10;
                    while( true ) {
                      *(byte *)puVar7 =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] *
                                  (uint)(byte)*puVar7 >> 0x10);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  (&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)]
                                  * (uint)*(byte *)((int)puVar7 + 1) >> 0x10);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  (&DAT_00d0a2e0)
                                  [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] *
                                  (uint)*(byte *)((int)puVar7 + 2) >> 0x10);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      if ((int)param_3 < 1) {
                        do {
                          local_20 = local_20 + local_58;
                          param_3 = (int *)((int)param_3 + local_34);
                          local_c = (uint *)((int)local_c + local_2c);
                        } while ((int)param_3 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006f4914:
                local_28 = local_20;
                local_c = local_10;
                local_8 = local_44;
                puVar7 = local_1c;
                param_3 = (int *)local_40;
                do {
                  if (*local_c == uVar2) {
                    do {
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f49f4;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      *(byte *)puVar7 =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] *
                                  (uint)(byte)*puVar7 >> 0x10);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  (&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)]
                                  * (uint)*(byte *)((int)puVar7 + 1) >> 0x10);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  (&DAT_00d0a2e0)
                                  [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] *
                                  (uint)*(byte *)((int)puVar7 + 2) >> 0x10);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f49f4;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_20 = local_20 + local_58;
                    param_3 = (int *)((int)param_3 + local_34);
                    local_c = (uint *)((int)local_c + local_2c);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (param_4 == 0) {
                local_18 = local_1c;
                do {
                  puVar7 = local_18;
                  local_20 = local_28;
                  local_8 = local_44;
                  puVar9 = local_10;
                  param_3 = (int *)local_40;
                  while( true ) {
                    *(byte *)local_18 =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*puVar9] *
                                (uint)*(byte *)((int)puVar9 + 3) * (uint)(byte)*local_18 >> 0x18);
                    *(byte *)((int)local_18 + 1) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)*(byte *)((int)puVar9 + 1)] *
                                (uint)*(byte *)((int)puVar9 + 3) *
                                (uint)*(byte *)((int)local_18 + 1) >> 0x18);
                    *(byte *)((int)local_18 + 2) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)*(byte *)((int)puVar9 + 2)] *
                                (uint)*(byte *)((int)puVar9 + 3) *
                                (uint)*(byte *)((int)local_18 + 2) >> 0x18);
                    local_18 = local_18 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        puVar9 = (uint *)((int)puVar9 + local_2c);
                        local_20 = local_20 + local_58;
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_18 = (uint *)((int)puVar7 + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006f4610:
              local_c = local_10;
              local_20 = local_28;
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              do {
                if (*(byte *)((int)local_c + 3) == 0) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f4798;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else if (*(byte *)((int)local_c + 3) == 0xff) {
                  do {
                    *(byte *)puVar7 =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] *
                                (uint)(byte)*puVar7 >> 0x10);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] *
                                (uint)*(byte *)((int)puVar7 + 1) >> 0x10);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)]
                                * (uint)*(byte *)((int)puVar7 + 2) >> 0x10);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f4798;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    *(byte *)puVar7 =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] *
                                (uint)*(byte *)((int)local_c + 3) * (uint)(byte)*puVar7 >> 0x18);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] *
                                (uint)*(byte *)((int)local_c + 3) * (uint)*(byte *)((int)puVar7 + 1)
                               >> 0x18);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)]
                                * (uint)*(byte *)((int)local_c + 3) *
                                (uint)*(byte *)((int)puVar7 + 2) >> 0x18);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f4798;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                } while ((int)param_3 < 1);
              } while( true );
            }
            if (*(int *)(param_2 + 0x2c) != 1) {
              if (param_4 == 0) {
                do {
                  local_8 = local_44;
                  puVar7 = local_1c;
                  puVar9 = local_10;
                  pbVar19 = local_28;
                  iVar5 = local_40;
                  while( true ) {
                    *(byte *)puVar7 =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] * (uint)(byte)*puVar9 *
                                (uint)(byte)*puVar7 >> 0x10);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                                (uint)*(byte *)((int)puVar9 + 1) * (uint)*(byte *)((int)puVar7 + 1)
                               >> 0x10);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                                (uint)*(byte *)((int)puVar9 + 2) * (uint)*(byte *)((int)puVar7 + 2)
                               >> 0x10);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    iVar5 = iVar5 + -0x10000;
                    if (iVar5 < 1) {
                      do {
                        iVar5 = iVar5 + local_34;
                        puVar9 = (uint *)((int)puVar9 + local_2c);
                        pbVar19 = pbVar19 + local_58;
                      } while (iVar5 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006f4414:
              local_8 = local_44;
              puVar7 = local_1c;
              puVar9 = local_10;
              iVar5 = local_40;
              pbVar19 = local_28;
              do {
                if (*puVar9 == uVar2) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f44c7;
                    iVar5 = iVar5 + -0x10000;
                  } while (0 < iVar5);
                }
                else {
                  do {
                    *(byte *)puVar7 =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] * (uint)(byte)*puVar9 *
                                (uint)(byte)*puVar7 >> 0x10);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                                (uint)*(byte *)((int)puVar9 + 1) * (uint)*(byte *)((int)puVar7 + 1)
                               >> 0x10);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                                (uint)*(byte *)((int)puVar9 + 2) * (uint)*(byte *)((int)puVar7 + 2)
                               >> 0x10);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f44c7;
                    iVar5 = iVar5 + -0x10000;
                  } while (0 < iVar5);
                }
                do {
                  iVar5 = iVar5 + local_34;
                  puVar9 = (uint *)((int)puVar9 + local_2c);
                  pbVar19 = pbVar19 + local_58;
                } while (iVar5 < 1);
              } while( true );
            }
            if (param_4 == 0) {
              do {
                local_8 = local_44;
                puVar7 = local_10;
                puVar9 = local_1c;
                pbVar19 = local_28;
                iVar5 = local_40;
                while( true ) {
                  *(byte *)puVar9 =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              (uint)*(byte *)((int)puVar7 + 3) * (uint)(byte)*puVar7 *
                              (uint)(byte)*puVar9 >> 0x18);
                  *(byte *)((int)puVar9 + 1) =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              (uint)*(byte *)((int)puVar7 + 1) * (uint)*(byte *)((int)puVar7 + 3) *
                              (uint)*(byte *)((int)puVar9 + 1) >> 0x18);
                  *(byte *)((int)puVar9 + 2) =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              (uint)*(byte *)((int)puVar7 + 2) * (uint)*(byte *)((int)puVar7 + 3) *
                              (uint)*(byte *)((int)puVar9 + 2) >> 0x18);
                  puVar9 = puVar9 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) break;
                  for (iVar5 = iVar5 + -0x10000; iVar5 < 1; iVar5 = iVar5 + local_34) {
                    puVar7 = (uint *)((int)puVar7 + local_2c);
                    pbVar19 = pbVar19 + local_58;
                  }
                }
                local_1c = (uint *)((int)local_1c + local_48);
                local_14 = local_14 - 0x10000;
                if ((int)local_14 < 1) {
                  do {
                    local_14 = local_14 + local_38;
                    local_10 = (uint *)((int)local_10 + local_3c);
                    local_28 = local_28 + local_5c;
                  } while ((int)local_14 < 1);
                }
                local_24 = local_24 + -1;
              } while (local_24 != 0);
              return;
            }
LAB_006f4172:
            local_8 = local_44;
            puVar7 = local_1c;
            puVar9 = local_10;
            pbVar19 = local_28;
            iVar5 = local_40;
            do {
              if (*(byte *)((int)puVar9 + 3) == 0) {
                do {
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006f42c6;
                  iVar5 = iVar5 + -0x10000;
                } while (0 < iVar5);
              }
              else if (*(byte *)((int)puVar9 + 3) == 0xff) {
                do {
                  *(byte *)puVar7 =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] * (uint)(byte)*puVar9 *
                              (uint)(byte)*puVar7 >> 0x10);
                  *(byte *)((int)puVar7 + 1) =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              (uint)*(byte *)((int)puVar9 + 1) * (uint)*(byte *)((int)puVar7 + 1) >>
                             0x10);
                  *(byte *)((int)puVar7 + 2) =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              (uint)*(byte *)((int)puVar9 + 2) * (uint)*(byte *)((int)puVar7 + 2) >>
                             0x10);
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006f42c6;
                  iVar5 = iVar5 + -0x10000;
                } while (0 < iVar5);
              }
              else {
                do {
                  *(byte *)puVar7 =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              (uint)*(byte *)((int)puVar9 + 3) * (uint)(byte)*puVar9 *
                              (uint)(byte)*puVar7 >> 0x18);
                  *(byte *)((int)puVar7 + 1) =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              (uint)*(byte *)((int)puVar9 + 1) * (uint)*(byte *)((int)puVar9 + 3) *
                              (uint)*(byte *)((int)puVar7 + 1) >> 0x18);
                  *(byte *)((int)puVar7 + 2) =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*pbVar19] *
                              (uint)*(byte *)((int)puVar9 + 2) * (uint)*(byte *)((int)puVar9 + 3) *
                              (uint)*(byte *)((int)puVar7 + 2) >> 0x18);
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006f42c6;
                  iVar5 = iVar5 + -0x10000;
                } while (0 < iVar5);
              }
              do {
                iVar5 = iVar5 + local_34;
                puVar9 = (uint *)((int)puVar9 + local_2c);
                pbVar19 = pbVar19 + local_58;
              } while (iVar5 < 1);
            } while( true );
          case 10:
            if (param_5 == 0) {
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (*(int *)(param_2 + 0x2c) != 1) {
                  iVar5 = DAT_00dca3f8;
                  if (param_4 == 0) {
                    do {
                      local_c = local_10;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      puVar7 = local_1c;
                      while( true ) {
                        *(byte *)puVar7 =
                             (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                    uVar11 * 0x100 + (uint)(byte)~(byte)*local_c) -
                                    (uint)(byte)*puVar7) * DAT_00dca3f8 +
                                    (uint)(byte)*puVar7 * 0x100 >> 8);
                        *(byte *)((int)puVar7 + 1) =
                             (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                    uVar3 * 0x100 +
                                                    (uint)(byte)~*(byte *)((int)local_c + 1)) -
                                    (uint)*(byte *)((int)puVar7 + 1)) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                        *(byte *)((int)puVar7 + 2) =
                             (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                    uVar18 * 0x100 +
                                                    (uint)(byte)~*(byte *)((int)local_c + 2)) -
                                    (uint)*(byte *)((int)puVar7 + 2)) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                            param_3 = (int *)((int)param_3 + local_34)) {
                          local_c = (uint *)((int)local_c + local_2c);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_14 = local_14 + local_38;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_006f8132:
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  local_c = local_10;
                  do {
                    if (*local_c == uVar2) {
                      do {
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f8230;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        *(byte *)puVar7 =
                             (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                    uVar11 * 0x100 + (uint)(byte)~(byte)*local_c) -
                                    (uint)(byte)*puVar7) * iVar5 + (uint)(byte)*puVar7 * 0x100 >> 8)
                        ;
                        *(byte *)((int)puVar7 + 1) =
                             (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                    uVar3 * 0x100 +
                                                    (uint)(byte)~*(byte *)((int)local_c + 1)) -
                                    (uint)*(byte *)((int)puVar7 + 1)) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                        *(byte *)((int)puVar7 + 2) =
                             (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                    uVar18 * 0x100 +
                                                    (uint)(byte)~*(byte *)((int)local_c + 2)) -
                                    (uint)*(byte *)((int)puVar7 + 2)) * DAT_00dca3f8 +
                                    (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        iVar5 = DAT_00dca3f8;
                        if (local_8 == 0) goto LAB_006f8230;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    do {
                      local_c = (uint *)((int)local_c + local_2c);
                      param_3 = (int *)((int)param_3 + local_34);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                iVar5 = DAT_00dca3f8;
                if (param_4 == 0) {
                  do {
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    puVar7 = local_1c;
                    while( true ) {
                      *(byte *)puVar7 =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar11 * 0x100 + (uint)(byte)~(byte)*local_c) -
                                  (uint)(byte)*puVar7) * (uint)*(byte *)((int)local_c + 3) *
                                  DAT_00dca3f8 + (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar3 * 0x100 +
                                                  (uint)(byte)~*(byte *)((int)local_c + 1)) -
                                  (uint)*(byte *)((int)puVar7 + 1)) *
                                  (uint)*(byte *)((int)local_c + 3) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar18 * 0x100 +
                                                  (uint)(byte)~*(byte *)((int)local_c + 2)) -
                                  (uint)*(byte *)((int)puVar7 + 2)) *
                                  (uint)*(byte *)((int)local_c + 3) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006f7df0:
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                local_c = local_10;
                do {
                  if (*(byte *)((int)local_c + 3) == 0) {
                    do {
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f7fb0;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else if (*(byte *)((int)local_c + 3) == 0xff) {
                    do {
                      *(byte *)puVar7 =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar11 * 0x100 + (uint)(byte)~(byte)*local_c) -
                                  (uint)(byte)*puVar7) * iVar5 + (uint)(byte)*puVar7 * 0x100 >> 8);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar3 * 0x100 +
                                                  (uint)(byte)~*(byte *)((int)local_c + 1)) -
                                  (uint)*(byte *)((int)puVar7 + 1)) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar18 * 0x100 +
                                                  (uint)(byte)~*(byte *)((int)local_c + 2)) -
                                  (uint)*(byte *)((int)puVar7 + 2)) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f7fab;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      *(byte *)puVar7 =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar11 * 0x100 + (uint)(byte)~(byte)*local_c) -
                                  (uint)(byte)*puVar7) * (uint)*(byte *)((int)local_c + 3) * iVar5 +
                                  (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar3 * 0x100 +
                                                  (uint)(byte)~*(byte *)((int)local_c + 1)) -
                                  (uint)*(byte *)((int)puVar7 + 1)) *
                                  (uint)*(byte *)((int)local_c + 3) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar18 * 0x100 +
                                                  (uint)(byte)~*(byte *)((int)local_c + 2)) -
                                  (uint)*(byte *)((int)puVar7 + 2)) *
                                  (uint)*(byte *)((int)local_c + 3) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f7fab;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_c = (uint *)((int)local_c + local_2c);
                    param_3 = (int *)((int)param_3 + local_34);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (*(int *)(param_2 + 0x2c) != 1) {
                if (param_4 == 0) {
                  do {
                    local_8 = local_44;
                    puVar9 = local_1c;
                    iVar5 = local_40;
                    puVar7 = local_10;
                    while( true ) {
                      *(byte *)puVar9 =
                           (byte)(((uint)(byte)~(byte)*puVar7 - (uint)(byte)*puVar9) * DAT_00dca3f8
                                  + (uint)(byte)*puVar9 * 0x100 >> 8);
                      *(byte *)((int)puVar9 + 1) =
                           (byte)(((uint)(byte)~*(byte *)((int)puVar7 + 1) -
                                  (uint)*(byte *)((int)puVar9 + 1)) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar9 + 1) * 0x100 >> 8);
                      *(byte *)((int)puVar9 + 2) =
                           (byte)(((uint)(byte)~*(byte *)((int)puVar7 + 2) -
                                  (uint)*(byte *)((int)puVar9 + 2)) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar9 + 2) * 0x100 >> 8);
                      puVar9 = puVar9 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (iVar5 = iVar5 + -0x10000; iVar5 < 1; iVar5 = iVar5 + local_34) {
                        puVar7 = (uint *)((int)puVar7 + local_2c);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
                iVar5 = DAT_00dca3f8;
LAB_006f7bf2:
                local_8 = local_44;
                puVar7 = local_1c;
                iVar6 = local_40;
                puVar9 = local_10;
                do {
                  if (*puVar9 == uVar2) {
                    do {
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f7cb4;
                      iVar6 = iVar6 + -0x10000;
                    } while (0 < iVar6);
                  }
                  else {
                    do {
                      *(byte *)puVar7 =
                           (byte)(((uint)(byte)~(byte)*puVar9 - (uint)(byte)*puVar7) * iVar5 +
                                  (uint)(byte)*puVar7 * 0x100 >> 8);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)(((uint)(byte)~*(byte *)((int)puVar9 + 1) -
                                  (uint)*(byte *)((int)puVar7 + 1)) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)(((uint)(byte)~*(byte *)((int)puVar9 + 2) -
                                  (uint)*(byte *)((int)puVar7 + 2)) * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      iVar5 = DAT_00dca3f8;
                      if (local_8 == 0) goto LAB_006f7cb4;
                      iVar6 = iVar6 + -0x10000;
                    } while (0 < iVar6);
                  }
                  do {
                    iVar6 = iVar6 + local_34;
                    puVar9 = (uint *)((int)puVar9 + local_2c);
                  } while (iVar6 < 1);
                } while( true );
              }
              iVar5 = DAT_00dca3f8;
              if (param_4 == 0) {
                do {
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  puVar9 = local_10;
                  while( true ) {
                    *(byte *)puVar7 =
                         (byte)(((uint)(byte)~(byte)*puVar9 - (uint)(byte)*puVar7) *
                                (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8 +
                                (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)(((uint)(byte)~*(byte *)((int)puVar9 + 1) -
                                (uint)*(byte *)((int)puVar7 + 1)) * (uint)*(byte *)((int)puVar9 + 3)
                                * DAT_00dca3f8 + (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10)
                    ;
                    *(byte *)((int)puVar7 + 2) =
                         (byte)(((uint)(byte)~*(byte *)((int)puVar9 + 2) -
                                (uint)*(byte *)((int)puVar7 + 2)) * (uint)*(byte *)((int)puVar9 + 3)
                                * DAT_00dca3f8 + (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10)
                    ;
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        puVar9 = (uint *)((int)puVar9 + local_2c);
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006f7932:
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              puVar9 = local_10;
              do {
                if (*(byte *)((int)puVar9 + 3) == 0) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f7a97;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else if (*(byte *)((int)puVar9 + 3) == 0xff) {
                  do {
                    *(byte *)puVar7 =
                         (byte)(((uint)(byte)~(byte)*puVar9 - (uint)(byte)*puVar7) * iVar5 +
                                (uint)(byte)*puVar7 * 0x100 >> 8);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)(((uint)(byte)~*(byte *)((int)puVar9 + 1) -
                                (uint)*(byte *)((int)puVar7 + 1)) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar7 + 1) * 0x100 >> 8);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)(((uint)(byte)~*(byte *)((int)puVar9 + 2) -
                                (uint)*(byte *)((int)puVar7 + 2)) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar7 + 2) * 0x100 >> 8);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f7a92;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    *(byte *)puVar7 =
                         (byte)(((uint)(byte)~(byte)*puVar9 - (uint)(byte)*puVar7) *
                                (uint)*(byte *)((int)puVar9 + 3) * iVar5 +
                                (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)(((uint)(byte)~*(byte *)((int)puVar9 + 1) -
                                (uint)*(byte *)((int)puVar7 + 1)) * (uint)*(byte *)((int)puVar9 + 3)
                                * DAT_00dca3f8 + (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10)
                    ;
                    *(byte *)((int)puVar7 + 2) =
                         (byte)(((uint)(byte)~*(byte *)((int)puVar9 + 2) -
                                (uint)*(byte *)((int)puVar7 + 2)) * (uint)*(byte *)((int)puVar9 + 3)
                                * DAT_00dca3f8 + (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10)
                    ;
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f7a92;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  puVar9 = (uint *)((int)puVar9 + local_2c);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
              if (*(int *)(param_2 + 0x2c) != 1) {
                local_c = local_10;
                iVar5 = DAT_00dca3f8;
                if (param_4 == 0) {
                  local_20 = local_28;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  while( true ) {
                    while( true ) {
                      *(byte *)puVar7 =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar11 * 0x100 + (uint)(byte)~(byte)*local_c) -
                                  (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  DAT_00dca3f8 + (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar3 * 0x100 +
                                                  (uint)(byte)~*(byte *)((int)local_c + 1)) -
                                  (uint)*(byte *)((int)puVar7 + 1)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar18 * 0x100 +
                                                  (uint)(byte)~*(byte *)((int)local_c + 2)) -
                                  (uint)*(byte *)((int)puVar7 + 2)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_20 = local_20 + local_58;
                        local_c = (uint *)((int)local_c + local_2c);
                      }
                    }
                    puVar7 = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    local_c = local_10;
                    local_20 = local_28;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_1c = puVar7;
                  }
                  return;
                }
LAB_006f7622:
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                local_20 = local_28;
                local_c = local_10;
                do {
                  if (*local_c == uVar2) {
                    do {
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f7753;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      *(byte *)puVar7 =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar11 * 0x100 + (uint)(byte)~(byte)*local_c) -
                                  (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  iVar5 + (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar3 * 0x100 +
                                                  (uint)(byte)~*(byte *)((int)local_c + 1)) -
                                  (uint)*(byte *)((int)puVar7 + 1)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                  uVar18 * 0x100 +
                                                  (uint)(byte)~*(byte *)((int)local_c + 2)) -
                                  (uint)*(byte *)((int)puVar7 + 2)) *
                                  (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                  (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      iVar5 = DAT_00dca3f8;
                      if (local_8 == 0) goto LAB_006f7753;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_c = (uint *)((int)local_c + local_2c);
                    local_20 = local_20 + local_58;
                    param_3 = (int *)((int)param_3 + local_34);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              local_20 = local_28;
              if (param_4 == 0) {
                local_8 = local_44;
                local_18 = local_1c;
                param_3 = (int *)local_40;
                puVar7 = local_10;
                while( true ) {
                  while( true ) {
                    *(byte *)local_18 =
                         (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                uVar11 * 0x100 + (uint)(byte)~(byte)*puVar7) -
                                (uint)(byte)*local_18) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (uint)*(byte *)((int)puVar7 + 3) * DAT_00dca3f8 +
                                (uint)(byte)*local_18 * 0x1000000 >> 0x18);
                    *(byte *)((int)local_18 + 1) =
                         (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                uVar3 * 0x100 +
                                                (uint)(byte)~*(byte *)((int)puVar7 + 1)) -
                                (uint)*(byte *)((int)local_18 + 1)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (uint)*(byte *)((int)puVar7 + 3) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)local_18 + 1) * 0x1000000 >> 0x18);
                    *(byte *)((int)local_18 + 2) =
                         (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                uVar18 * 0x100 +
                                                (uint)(byte)~*(byte *)((int)puVar7 + 2)) -
                                (uint)*(byte *)((int)local_18 + 2)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (uint)*(byte *)((int)puVar7 + 3) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)local_18 + 2) * 0x1000000 >> 0x18);
                    local_18 = local_18 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_20 = local_20 + local_58;
                      puVar7 = (uint *)((int)puVar7 + local_2c);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_14 = local_14 + local_38;
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                  local_20 = local_28;
                  if (local_24 == 0) break;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_10;
                  local_18 = local_1c;
                }
                return;
              }
              iVar5 = DAT_00dca3f8;
LAB_006f7207:
              local_8 = local_44;
              param_3 = (int *)local_40;
              puVar7 = local_1c;
              local_20 = local_28;
              local_c = local_10;
              do {
                if (*(byte *)((int)local_c + 3) == 0) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f7436;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else if (*(byte *)((int)local_c + 3) == 0xff) {
                  do {
                    *(byte *)puVar7 =
                         (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                uVar11 * 0x100 + (uint)(byte)~(byte)*local_c) -
                                (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                iVar5 + (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                uVar3 * 0x100 +
                                                (uint)(byte)~*(byte *)((int)local_c + 1)) -
                                (uint)*(byte *)((int)puVar7 + 1)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                uVar18 * 0x100 +
                                                (uint)(byte)~*(byte *)((int)local_c + 2)) -
                                (uint)*(byte *)((int)puVar7 + 2)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f7431;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    *(byte *)puVar7 =
                         (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                uVar11 * 0x100 + (uint)(byte)~(byte)*local_c) -
                                (uint)(byte)*puVar7) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (uint)*(byte *)((int)local_c + 3) * iVar5 +
                                (uint)(byte)*puVar7 * 0x1000000 >> 0x18);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                uVar3 * 0x100 +
                                                (uint)(byte)~*(byte *)((int)local_c + 1)) -
                                (uint)*(byte *)((int)puVar7 + 1)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (uint)*(byte *)((int)local_c + 3) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar7 + 1) * 0x1000000 >> 0x18);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)(((uint)*(byte *)(&DAT_00d0a2e0 +
                                                uVar18 * 0x100 +
                                                (uint)(byte)~*(byte *)((int)local_c + 2)) -
                                (uint)*(byte *)((int)puVar7 + 2)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (uint)*(byte *)((int)local_c + 3) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar7 + 2) * 0x1000000 >> 0x18);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f7431;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                  } while (0 < (int)param_3);
                }
                do {
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                  param_3 = (int *)((int)param_3 + local_34);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if (*(int *)(param_2 + 0x2c) != 1) {
              if (param_4 == 0) {
                local_8 = local_44;
                local_20 = local_28;
                param_3 = (int *)local_40;
                puVar7 = local_10;
                puVar9 = local_1c;
                while( true ) {
                  while( true ) {
                    *(byte *)puVar9 =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                ((uint)(byte)~(byte)*puVar7 - (uint)(byte)*puVar9) * DAT_00dca3f8 +
                                (uint)(byte)*puVar9 * 0x10000 >> 0x10);
                    *(byte *)((int)puVar9 + 1) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                ((uint)(byte)~*(byte *)((int)puVar7 + 1) -
                                (uint)*(byte *)((int)puVar9 + 1)) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar9 + 1) * 0x10000 >> 0x10);
                    *(byte *)((int)puVar9 + 2) =
                         (byte)(((uint)(byte)~*(byte *)((int)puVar7 + 2) -
                                (uint)*(byte *)((int)puVar9 + 2)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar9 + 2) * 0x10000 >> 0x10);
                    puVar9 = puVar9 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      puVar7 = (uint *)((int)puVar7 + local_2c);
                      local_20 = local_20 + local_58;
                    }
                  }
                  puVar9 = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                  if (local_24 == 0) break;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_10;
                  local_20 = local_28;
                  local_1c = puVar9;
                }
                return;
              }
              iVar5 = DAT_00dca3f8;
LAB_006f6f52:
              local_20 = local_28;
              local_8 = local_44;
              puVar7 = local_10;
              param_3 = (int *)local_40;
              puVar9 = local_1c;
              do {
                if (*puVar7 == uVar2) {
                  do {
                    puVar9 = puVar9 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f7048;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    *(byte *)puVar9 =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                ((uint)(byte)~(byte)*puVar7 - (uint)(byte)*puVar9) * iVar5 +
                                (uint)(byte)*puVar9 * 0x10000 >> 0x10);
                    *(byte *)((int)puVar9 + 1) =
                         (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                ((uint)(byte)~*(byte *)((int)puVar7 + 1) -
                                (uint)*(byte *)((int)puVar9 + 1)) * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar9 + 1) * 0x10000 >> 0x10);
                    *(byte *)((int)puVar9 + 2) =
                         (byte)(((uint)(byte)~*(byte *)((int)puVar7 + 2) -
                                (uint)*(byte *)((int)puVar9 + 2)) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                (uint)*(byte *)((int)puVar9 + 2) * 0x10000 >> 0x10);
                    puVar9 = puVar9 + 1;
                    local_8 = local_8 + -1;
                    iVar5 = DAT_00dca3f8;
                    if (local_8 == 0) goto LAB_006f7048;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  puVar7 = (uint *)((int)puVar7 + local_2c);
                  local_20 = local_20 + local_58;
                } while ((int)param_3 < 1);
              } while( true );
            }
            if (param_4 == 0) {
              local_8 = local_44;
              local_20 = local_28;
              param_3 = (int *)local_40;
              puVar7 = local_10;
              puVar9 = local_1c;
              while( true ) {
                while( true ) {
                  *(byte *)puVar9 =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                              ((uint)(byte)~(byte)*puVar7 - (uint)(byte)*puVar9) *
                              (uint)*(byte *)((int)puVar7 + 3) * DAT_00dca3f8 +
                              (uint)(byte)*puVar9 * 0x1000000 >> 0x18);
                  *(byte *)((int)puVar9 + 1) =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                              ((uint)(byte)~*(byte *)((int)puVar7 + 1) -
                              (uint)*(byte *)((int)puVar9 + 1)) * (uint)*(byte *)((int)puVar7 + 3) *
                              DAT_00dca3f8 + (uint)*(byte *)((int)puVar9 + 1) * 0x1000000 >> 0x18);
                  *(byte *)((int)puVar9 + 2) =
                       (byte)(((uint)(byte)~*(byte *)((int)puVar7 + 2) -
                              (uint)*(byte *)((int)puVar9 + 2)) *
                              (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                              (uint)*(byte *)((int)puVar7 + 3) * DAT_00dca3f8 +
                              (uint)*(byte *)((int)puVar9 + 2) * 0x1000000 >> 0x18);
                  puVar9 = puVar9 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) break;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  if ((int)param_3 < 1) {
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      puVar7 = (uint *)((int)puVar7 + local_2c);
                      local_20 = local_20 + local_58;
                    } while ((int)param_3 < 1);
                  }
                }
                puVar9 = (uint *)((int)local_1c + local_48);
                local_14 = local_14 - 0x10000;
                if ((int)local_14 < 1) {
                  do {
                    local_14 = local_14 + local_38;
                    local_10 = (uint *)((int)local_10 + local_3c);
                    local_28 = local_28 + local_5c;
                  } while ((int)local_14 < 1);
                }
                local_24 = local_24 + -1;
                if (local_24 == 0) break;
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_10;
                local_20 = local_28;
                local_1c = puVar9;
              }
              return;
            }
            iVar5 = DAT_00dca3f8;
LAB_006f6bd0:
            local_20 = local_28;
            local_8 = local_44;
            param_3 = (int *)local_40;
            puVar7 = local_1c;
            puVar9 = local_10;
            do {
              if (*(byte *)((int)puVar9 + 3) == 0) {
                do {
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006f6d8d;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              else if (*(byte *)((int)puVar9 + 3) == 0xff) {
                do {
                  *(byte *)puVar7 =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                              ((uint)(byte)~(byte)*puVar9 - (uint)(byte)*puVar7) * iVar5 +
                              (uint)(byte)*puVar7 * 0x10000 >> 0x10);
                  *(byte *)((int)puVar7 + 1) =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                              ((uint)(byte)~*(byte *)((int)puVar9 + 1) -
                              (uint)*(byte *)((int)puVar7 + 1)) * DAT_00dca3f8 +
                              (uint)*(byte *)((int)puVar7 + 1) * 0x10000 >> 0x10);
                  *(byte *)((int)puVar7 + 2) =
                       (byte)(((uint)(byte)~*(byte *)((int)puVar9 + 2) -
                              (uint)*(byte *)((int)puVar7 + 2)) *
                              (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                              (uint)*(byte *)((int)puVar7 + 2) * 0x10000 >> 0x10);
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006f6d88;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  iVar5 = DAT_00dca3f8;
                } while (0 < (int)param_3);
              }
              else {
                do {
                  *(byte *)puVar7 =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                              ((uint)(byte)~(byte)*puVar9 - (uint)(byte)*puVar7) *
                              (uint)*(byte *)((int)puVar9 + 3) * iVar5 +
                              (uint)(byte)*puVar7 * 0x1000000 >> 0x18);
                  *(byte *)((int)puVar7 + 1) =
                       (byte)((uint)(byte)(&DAT_00dca2e0)[*local_20] *
                              ((uint)(byte)~*(byte *)((int)puVar9 + 1) -
                              (uint)*(byte *)((int)puVar7 + 1)) * (uint)*(byte *)((int)puVar9 + 3) *
                              DAT_00dca3f8 + (uint)*(byte *)((int)puVar7 + 1) * 0x1000000 >> 0x18);
                  *(byte *)((int)puVar7 + 2) =
                       (byte)(((uint)(byte)~*(byte *)((int)puVar9 + 2) -
                              (uint)*(byte *)((int)puVar7 + 2)) *
                              (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                              (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8 +
                              (uint)*(byte *)((int)puVar7 + 2) * 0x1000000 >> 0x18);
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006f6d88;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  iVar5 = DAT_00dca3f8;
                } while (0 < (int)param_3);
              }
              do {
                param_3 = (int *)((int)param_3 + local_34);
                puVar9 = (uint *)((int)puVar9 + local_2c);
                local_20 = local_20 + local_58;
              } while ((int)param_3 < 1);
            } while( true );
          case 0xb:
            if (param_5 == 0) {
              if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
                if (*(int *)(param_2 + 0x2c) != 1) {
                  iVar5 = DAT_00dca3f8;
                  if (param_4 == 0) {
                    do {
                      local_c = local_10;
                      local_8 = local_44;
                      param_3 = (int *)local_40;
                      puVar7 = local_1c;
                      while( true ) {
                        uVar2 = (uint)(byte)*puVar7;
                        *(byte *)puVar7 =
                             (byte)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] * uVar2
                                      >> 8 & 0xff) - uVar2) * DAT_00dca3f8 + uVar2 * 0x100 >> 8);
                        uVar2 = (uint)*(byte *)((int)puVar7 + 1);
                        *(byte *)((int)puVar7 + 1) =
                             (byte)((((&DAT_00d0a2e0)
                                      [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] * uVar2 >>
                                      8 & 0xff) - uVar2) * DAT_00dca3f8 + uVar2 * 0x100 >> 8);
                        uVar2 = (uint)*(byte *)((int)puVar7 + 2);
                        *(byte *)((int)puVar7 + 2) =
                             (byte)((((&DAT_00d0a2e0)
                                      [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] * uVar2
                                      >> 8 & 0xff) - uVar2) * DAT_00dca3f8 + uVar2 * 0x100 >> 8);
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) break;
                        for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                            param_3 = (int *)((int)param_3 + local_34)) {
                          local_c = (uint *)((int)local_c + local_2c);
                        }
                      }
                      local_1c = (uint *)((int)local_1c + local_48);
                      local_14 = local_14 - 0x10000;
                      if ((int)local_14 < 1) {
                        do {
                          local_10 = (uint *)((int)local_10 + local_3c);
                          local_14 = local_14 + local_38;
                        } while ((int)local_14 < 1);
                      }
                      local_24 = local_24 + -1;
                    } while (local_24 != 0);
                    return;
                  }
LAB_006f6937:
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  local_c = local_10;
                  do {
                    if (*local_c == uVar2) {
                      do {
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        if (local_8 == 0) goto LAB_006f6a30;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    else {
                      do {
                        uVar8 = (uint)(byte)*puVar7;
                        *(byte *)puVar7 =
                             (byte)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] * uVar8
                                      >> 8 & 0xff) - uVar8) * iVar5 + uVar8 * 0x100 >> 8);
                        uVar8 = (uint)*(byte *)((int)puVar7 + 1);
                        *(byte *)((int)puVar7 + 1) =
                             (byte)((((&DAT_00d0a2e0)
                                      [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] * uVar8 >>
                                      8 & 0xff) - uVar8) * DAT_00dca3f8 + uVar8 * 0x100 >> 8);
                        uVar8 = (uint)*(byte *)((int)puVar7 + 2);
                        *(byte *)((int)puVar7 + 2) =
                             (byte)((((&DAT_00d0a2e0)
                                      [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] * uVar8
                                      >> 8 & 0xff) - uVar8) * DAT_00dca3f8 + uVar8 * 0x100 >> 8);
                        puVar7 = puVar7 + 1;
                        local_8 = local_8 + -1;
                        iVar5 = DAT_00dca3f8;
                        if (local_8 == 0) goto LAB_006f6a30;
                        param_3 = (int *)((int)param_3 + -0x10000);
                      } while (0 < (int)param_3);
                    }
                    do {
                      local_c = (uint *)((int)local_c + local_2c);
                      param_3 = (int *)((int)param_3 + local_34);
                    } while ((int)param_3 < 1);
                  } while( true );
                }
                iVar5 = DAT_00dca3f8;
                if (param_4 == 0) {
                  do {
                    local_c = local_10;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    puVar7 = local_1c;
                    while( true ) {
                      uVar2 = (uint)(byte)*puVar7;
                      *(byte *)puVar7 =
                           (byte)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] * uVar2
                                    >> 8 & 0xff) - uVar2) * (uint)*(byte *)((int)local_c + 3) *
                                  DAT_00dca3f8 + uVar2 * 0x10000 >> 0x10);
                      uVar2 = (uint)*(byte *)((int)puVar7 + 1);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)((((&DAT_00d0a2e0)
                                    [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] * uVar2 >> 8
                                   & 0xff) - uVar2) * (uint)*(byte *)((int)local_c + 3) *
                                  DAT_00dca3f8 + uVar2 * 0x10000 >> 0x10);
                      uVar2 = (uint)*(byte *)((int)puVar7 + 2);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)((((&DAT_00d0a2e0)
                                    [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] * uVar2 >>
                                    8 & 0xff) - uVar2) * (uint)*(byte *)((int)local_c + 3) *
                                  DAT_00dca3f8 + uVar2 * 0x10000 >> 0x10);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_c = (uint *)((int)local_c + local_2c);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
LAB_006f65d0:
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                local_c = local_10;
                do {
                  if (*(byte *)((int)local_c + 3) == 0) {
                    do {
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f67b0;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else if (*(byte *)((int)local_c + 3) == 0xff) {
                    do {
                      uVar2 = (uint)(byte)*puVar7;
                      *(byte *)puVar7 =
                           (byte)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] * uVar2
                                    >> 8 & 0xff) - uVar2) * iVar5 + uVar2 * 0x100 >> 8);
                      uVar2 = (uint)*(byte *)((int)puVar7 + 1);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)((((&DAT_00d0a2e0)
                                    [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] * uVar2 >> 8
                                   & 0xff) - uVar2) * DAT_00dca3f8 + uVar2 * 0x100 >> 8);
                      uVar2 = (uint)*(byte *)((int)puVar7 + 2);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)((((&DAT_00d0a2e0)
                                    [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] * uVar2 >>
                                    8 & 0xff) - uVar2) * DAT_00dca3f8 + uVar2 * 0x100 >> 8);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f67ab;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar2 = (uint)(byte)*puVar7;
                      *(byte *)puVar7 =
                           (byte)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] * uVar2
                                    >> 8 & 0xff) - uVar2) * (uint)*(byte *)((int)local_c + 3) *
                                  iVar5 + uVar2 * 0x10000 >> 0x10);
                      uVar2 = (uint)*(byte *)((int)puVar7 + 1);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)((((&DAT_00d0a2e0)
                                    [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] * uVar2 >> 8
                                   & 0xff) - uVar2) * (uint)*(byte *)((int)local_c + 3) *
                                  DAT_00dca3f8 + uVar2 * 0x10000 >> 0x10);
                      uVar2 = (uint)*(byte *)((int)puVar7 + 2);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)((((&DAT_00d0a2e0)
                                    [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] * uVar2 >>
                                    8 & 0xff) - uVar2) * (uint)*(byte *)((int)local_c + 3) *
                                  DAT_00dca3f8 + uVar2 * 0x10000 >> 0x10);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f67ab;
                      param_3 = (int *)((int)param_3 + -0x10000);
                      iVar5 = DAT_00dca3f8;
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_c = (uint *)((int)local_c + local_2c);
                    param_3 = (int *)((int)param_3 + local_34);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              if (*(int *)(param_2 + 0x2c) != 1) {
                if (param_4 == 0) {
                  do {
                    local_8 = local_44;
                    puVar7 = local_1c;
                    iVar5 = local_40;
                    puVar9 = local_10;
                    while( true ) {
                      uVar2 = (uint)(byte)*puVar7;
                      *(byte *)puVar7 =
                           (byte)((((int)((byte)*puVar9 * uVar2) >> 8) - uVar2) * DAT_00dca3f8 +
                                  uVar2 * 0x100 >> 8);
                      uVar2 = (uint)*(byte *)((int)puVar7 + 1);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)((((int)(*(byte *)((int)puVar9 + 1) * uVar2) >> 8) - uVar2) *
                                  DAT_00dca3f8 + uVar2 * 0x100 >> 8);
                      uVar2 = (uint)*(byte *)((int)puVar7 + 2);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)((((int)(*(byte *)((int)puVar9 + 2) * uVar2) >> 8) - uVar2) *
                                  DAT_00dca3f8 + uVar2 * 0x100 >> 8);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      iVar5 = iVar5 + -0x10000;
                      if (iVar5 < 1) {
                        do {
                          iVar5 = iVar5 + local_34;
                          puVar9 = (uint *)((int)puVar9 + local_2c);
                        } while (iVar5 < 1);
                      }
                    }
                    local_1c = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_14 = local_14 + local_38;
                        local_10 = (uint *)((int)local_10 + local_3c);
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                  } while (local_24 != 0);
                  return;
                }
                iVar5 = DAT_00dca3f8;
LAB_006f63b2:
                local_8 = local_44;
                puVar7 = local_1c;
                iVar6 = local_40;
                puVar9 = local_10;
                do {
                  if (*puVar9 == uVar2) {
                    do {
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f6479;
                      iVar6 = iVar6 + -0x10000;
                    } while (0 < iVar6);
                  }
                  else {
                    do {
                      uVar3 = (uint)(byte)*puVar7;
                      *(byte *)puVar7 =
                           (byte)((((int)((byte)*puVar9 * uVar3) >> 8) - uVar3) * iVar5 +
                                  uVar3 * 0x100 >> 8);
                      uVar3 = (uint)*(byte *)((int)puVar7 + 1);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)((((int)(*(byte *)((int)puVar9 + 1) * uVar3) >> 8) - uVar3) *
                                  DAT_00dca3f8 + uVar3 * 0x100 >> 8);
                      uVar3 = (uint)*(byte *)((int)puVar7 + 2);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)((((int)(*(byte *)((int)puVar9 + 2) * uVar3) >> 8) - uVar3) *
                                  DAT_00dca3f8 + uVar3 * 0x100 >> 8);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      iVar5 = DAT_00dca3f8;
                      if (local_8 == 0) goto LAB_006f6479;
                      iVar6 = iVar6 + -0x10000;
                    } while (0 < iVar6);
                  }
                  do {
                    iVar6 = iVar6 + local_34;
                    puVar9 = (uint *)((int)puVar9 + local_2c);
                  } while (iVar6 < 1);
                } while( true );
              }
              iVar5 = DAT_00dca3f8;
              if (param_4 == 0) {
                do {
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  puVar9 = local_10;
                  while( true ) {
                    uVar2 = (uint)(byte)*puVar7;
                    *(byte *)puVar7 =
                         (byte)((((int)((byte)*puVar9 * uVar2) >> 8) - uVar2) *
                                (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8 + uVar2 * 0x10000 >>
                               0x10);
                    uVar2 = (uint)*(byte *)((int)puVar7 + 1);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((((int)(*(byte *)((int)puVar9 + 1) * uVar2) >> 8) - uVar2) *
                                (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8 + uVar2 * 0x10000 >>
                               0x10);
                    uVar2 = (uint)*(byte *)((int)puVar7 + 2);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((((int)(*(byte *)((int)puVar9 + 2) * uVar2) >> 8) - uVar2) *
                                (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8 + uVar2 * 0x10000 >>
                               0x10);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        puVar9 = (uint *)((int)puVar9 + local_2c);
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006f60c2:
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              puVar9 = local_10;
              do {
                if (*(byte *)((int)puVar9 + 3) == 0) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f6247;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else if (*(byte *)((int)puVar9 + 3) == 0xff) {
                  do {
                    uVar2 = (uint)(byte)*puVar7;
                    *(byte *)puVar7 =
                         (byte)((((int)((byte)*puVar9 * uVar2) >> 8) - uVar2) * iVar5 +
                                uVar2 * 0x100 >> 8);
                    uVar2 = (uint)*(byte *)((int)puVar7 + 1);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((((int)(*(byte *)((int)puVar9 + 1) * uVar2) >> 8) - uVar2) *
                                DAT_00dca3f8 + uVar2 * 0x100 >> 8);
                    uVar2 = (uint)*(byte *)((int)puVar7 + 2);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((((int)(*(byte *)((int)puVar9 + 2) * uVar2) >> 8) - uVar2) *
                                DAT_00dca3f8 + uVar2 * 0x100 >> 8);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f6242;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar2 = (uint)(byte)*puVar7;
                    *(byte *)puVar7 =
                         (byte)((((int)((byte)*puVar9 * uVar2) >> 8) - uVar2) *
                                (uint)*(byte *)((int)puVar9 + 3) * iVar5 + uVar2 * 0x10000 >> 0x10);
                    uVar2 = (uint)*(byte *)((int)puVar7 + 1);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((((int)(*(byte *)((int)puVar9 + 1) * uVar2) >> 8) - uVar2) *
                                (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8 + uVar2 * 0x10000 >>
                               0x10);
                    uVar2 = (uint)*(byte *)((int)puVar7 + 2);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((((int)(*(byte *)((int)puVar9 + 2) * uVar2) >> 8) - uVar2) *
                                (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8 + uVar2 * 0x10000 >>
                               0x10);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f6242;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  puVar9 = (uint *)((int)puVar9 + local_2c);
                } while ((int)param_3 < 1);
              } while( true );
            }
            if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
              if (*(int *)(param_2 + 0x2c) != 1) {
                local_c = local_10;
                iVar5 = DAT_00dca3f8;
                if (param_4 == 0) {
                  local_20 = local_28;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  while( true ) {
                    while( true ) {
                      uVar2 = (uint)(byte)*puVar7;
                      *(byte *)puVar7 =
                           (byte)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] * uVar2
                                    >> 8 & 0xff) - uVar2) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  DAT_00dca3f8 + uVar2 * 0x10000 >> 0x10);
                      uVar2 = (uint)*(byte *)((int)puVar7 + 1);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)((((&DAT_00d0a2e0)
                                    [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] * uVar2 >> 8
                                   & 0xff) - uVar2) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  DAT_00dca3f8 + uVar2 * 0x10000 >> 0x10);
                      uVar2 = (uint)*(byte *)((int)puVar7 + 2);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)((((&DAT_00d0a2e0)
                                    [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] * uVar2 >>
                                    8 & 0xff) - uVar2) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  DAT_00dca3f8 + uVar2 * 0x10000 >> 0x10);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) break;
                      for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                          param_3 = (int *)((int)param_3 + local_34)) {
                        local_20 = local_20 + local_58;
                        local_c = (uint *)((int)local_c + local_2c);
                      }
                    }
                    puVar7 = (uint *)((int)local_1c + local_48);
                    local_14 = local_14 - 0x10000;
                    if ((int)local_14 < 1) {
                      do {
                        local_10 = (uint *)((int)local_10 + local_3c);
                        local_14 = local_14 + local_38;
                        local_28 = local_28 + local_5c;
                      } while ((int)local_14 < 1);
                    }
                    local_24 = local_24 + -1;
                    local_c = local_10;
                    local_20 = local_28;
                    if (local_24 == 0) break;
                    local_8 = local_44;
                    param_3 = (int *)local_40;
                    local_1c = puVar7;
                  }
                  return;
                }
LAB_006f5da2:
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_1c;
                local_20 = local_28;
                local_c = local_10;
                do {
                  if (*local_c == uVar2) {
                    do {
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      if (local_8 == 0) goto LAB_006f5ed9;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  else {
                    do {
                      uVar8 = (uint)(byte)*puVar7;
                      *(byte *)puVar7 =
                           (byte)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] * uVar8
                                    >> 8 & 0xff) - uVar8) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  iVar5 + uVar8 * 0x10000 >> 0x10);
                      uVar8 = (uint)*(byte *)((int)puVar7 + 1);
                      *(byte *)((int)puVar7 + 1) =
                           (byte)((((&DAT_00d0a2e0)
                                    [uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)] * uVar8 >> 8
                                   & 0xff) - uVar8) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  DAT_00dca3f8 + uVar8 * 0x10000 >> 0x10);
                      uVar8 = (uint)*(byte *)((int)puVar7 + 2);
                      *(byte *)((int)puVar7 + 2) =
                           (byte)((((&DAT_00d0a2e0)
                                    [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] * uVar8 >>
                                    8 & 0xff) - uVar8) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                  DAT_00dca3f8 + uVar8 * 0x10000 >> 0x10);
                      puVar7 = puVar7 + 1;
                      local_8 = local_8 + -1;
                      iVar5 = DAT_00dca3f8;
                      if (local_8 == 0) goto LAB_006f5ed9;
                      param_3 = (int *)((int)param_3 + -0x10000);
                    } while (0 < (int)param_3);
                  }
                  do {
                    local_c = (uint *)((int)local_c + local_2c);
                    local_20 = local_20 + local_58;
                    param_3 = (int *)((int)param_3 + local_34);
                  } while ((int)param_3 < 1);
                } while( true );
              }
              local_20 = local_28;
              if (param_4 == 0) {
                local_8 = local_44;
                local_18 = local_1c;
                param_3 = (int *)local_40;
                puVar7 = local_10;
                while( true ) {
                  while( true ) {
                    uVar2 = (uint)(byte)*local_18;
                    *(byte *)local_18 =
                         (byte)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*puVar7] * uVar2 >> 8
                                 & 0xff) - uVar2) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (uint)*(byte *)((int)puVar7 + 3) * DAT_00dca3f8 + uVar2 * 0x1000000
                               >> 0x18);
                    uVar2 = (uint)*(byte *)((int)local_18 + 1);
                    *(byte *)((int)local_18 + 1) =
                         (byte)((((&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)*(byte *)((int)puVar7 + 1)]
                                  * uVar2 >> 8 & 0xff) - uVar2) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (uint)*(byte *)((int)puVar7 + 3) * DAT_00dca3f8 + uVar2 * 0x1000000
                               >> 0x18);
                    uVar2 = (uint)*(byte *)((int)local_18 + 2);
                    *(byte *)((int)local_18 + 2) =
                         (byte)((((&DAT_00d0a2e0)[uVar18 * 0x100 + (uint)*(byte *)((int)puVar7 + 2)]
                                  * uVar2 >> 8 & 0xff) - uVar2) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (uint)*(byte *)((int)puVar7 + 3) * DAT_00dca3f8 + uVar2 * 0x1000000
                               >> 0x18);
                    local_18 = local_18 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    for (param_3 = (int *)((int)param_3 + -0x10000); (int)param_3 < 1;
                        param_3 = (int *)((int)param_3 + local_34)) {
                      local_20 = local_20 + local_58;
                      puVar7 = (uint *)((int)puVar7 + local_2c);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_14 = local_14 + local_38;
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                  local_20 = local_28;
                  if (local_24 == 0) break;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_10;
                  local_18 = local_1c;
                }
                return;
              }
              iVar5 = DAT_00dca3f8;
LAB_006f5967:
              local_8 = local_44;
              param_3 = (int *)local_40;
              puVar7 = local_1c;
              local_20 = local_28;
              local_c = local_10;
              do {
                if (*(byte *)((int)local_c + 3) == 0) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f5ba6;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else if (*(byte *)((int)local_c + 3) == 0xff) {
                  do {
                    uVar2 = (uint)(byte)*puVar7;
                    *(byte *)puVar7 =
                         (byte)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] * uVar2 >>
                                  8 & 0xff) - uVar2) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                iVar5 + uVar2 * 0x10000 >> 0x10);
                    uVar2 = (uint)*(byte *)((int)puVar7 + 1);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((((&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)]
                                  * uVar2 >> 8 & 0xff) - uVar2) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                uVar2 * 0x10000 >> 0x10);
                    uVar2 = (uint)*(byte *)((int)puVar7 + 2);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((((&DAT_00d0a2e0)
                                  [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] * uVar2 >> 8
                                 & 0xff) - uVar2) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                DAT_00dca3f8 + uVar2 * 0x10000 >> 0x10);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f5ba1;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar2 = (uint)(byte)*puVar7;
                    *(byte *)puVar7 =
                         (byte)((((&DAT_00d0a2e0)[uVar11 * 0x100 + (uint)(byte)*local_c] * uVar2 >>
                                  8 & 0xff) - uVar2) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (uint)*(byte *)((int)local_c + 3) * iVar5 + uVar2 * 0x1000000 >>
                               0x18);
                    uVar2 = (uint)*(byte *)((int)puVar7 + 1);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((((&DAT_00d0a2e0)[uVar3 * 0x100 + (uint)*(byte *)((int)local_c + 1)]
                                  * uVar2 >> 8 & 0xff) - uVar2) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (uint)*(byte *)((int)local_c + 3) * DAT_00dca3f8 + uVar2 * 0x1000000
                               >> 0x18);
                    uVar2 = (uint)*(byte *)((int)puVar7 + 2);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((((&DAT_00d0a2e0)
                                  [uVar18 * 0x100 + (uint)*(byte *)((int)local_c + 2)] * uVar2 >> 8
                                 & 0xff) - uVar2) * (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                                (uint)*(byte *)((int)local_c + 3) * DAT_00dca3f8 + uVar2 * 0x1000000
                               >> 0x18);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f5ba1;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    iVar5 = DAT_00dca3f8;
                  } while (0 < (int)param_3);
                }
                do {
                  local_c = (uint *)((int)local_c + local_2c);
                  local_20 = local_20 + local_58;
                  param_3 = (int *)((int)param_3 + local_34);
                } while ((int)param_3 < 1);
              } while( true );
            }
            local_20 = local_28;
            if (*(int *)(param_2 + 0x2c) != 1) {
              iVar5 = DAT_00dca3f8;
              if (param_4 == 0) {
                do {
                  local_20 = local_28;
                  local_8 = local_44;
                  param_3 = (int *)local_40;
                  puVar7 = local_1c;
                  puVar9 = local_10;
                  while( true ) {
                    uVar2 = (uint)(byte)*puVar7;
                    *(byte *)puVar7 =
                         (byte)((((int)((byte)*puVar9 * uVar2) >> 8) - uVar2) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                uVar2 * 0x10000 >> 0x10);
                    uVar2 = (uint)*(byte *)((int)puVar7 + 1);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((((int)(*(byte *)((int)puVar9 + 1) * uVar2) >> 8) - uVar2) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                uVar2 * 0x10000 >> 0x10);
                    uVar2 = (uint)*(byte *)((int)puVar7 + 2);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((((int)(*(byte *)((int)puVar9 + 2) * uVar2) >> 8) - uVar2) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                uVar2 * 0x10000 >> 0x10);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) break;
                    param_3 = (int *)((int)param_3 + -0x10000);
                    if ((int)param_3 < 1) {
                      do {
                        param_3 = (int *)((int)param_3 + local_34);
                        puVar9 = (uint *)((int)puVar9 + local_2c);
                        local_20 = local_20 + local_58;
                      } while ((int)param_3 < 1);
                    }
                  }
                  local_1c = (uint *)((int)local_1c + local_48);
                  local_14 = local_14 - 0x10000;
                  if ((int)local_14 < 1) {
                    do {
                      local_14 = local_14 + local_38;
                      local_10 = (uint *)((int)local_10 + local_3c);
                      local_28 = local_28 + local_5c;
                    } while ((int)local_14 < 1);
                  }
                  local_24 = local_24 + -1;
                } while (local_24 != 0);
                return;
              }
LAB_006f56c4:
              local_20 = local_28;
              local_8 = local_44;
              puVar7 = local_1c;
              param_3 = (int *)local_40;
              puVar9 = local_10;
              do {
                if (*puVar9 == uVar2) {
                  do {
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    if (local_8 == 0) goto LAB_006f57c5;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                else {
                  do {
                    uVar3 = (uint)(byte)*puVar7;
                    *(byte *)puVar7 =
                         (byte)((((int)((byte)*puVar9 * uVar3) >> 8) - uVar3) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] * iVar5 + uVar3 * 0x10000 >>
                               0x10);
                    uVar3 = (uint)*(byte *)((int)puVar7 + 1);
                    *(byte *)((int)puVar7 + 1) =
                         (byte)((((int)(*(byte *)((int)puVar9 + 1) * uVar3) >> 8) - uVar3) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                uVar3 * 0x10000 >> 0x10);
                    uVar3 = (uint)*(byte *)((int)puVar7 + 2);
                    *(byte *)((int)puVar7 + 2) =
                         (byte)((((int)(*(byte *)((int)puVar9 + 2) * uVar3) >> 8) - uVar3) *
                                (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                                uVar3 * 0x10000 >> 0x10);
                    puVar7 = puVar7 + 1;
                    local_8 = local_8 + -1;
                    iVar5 = DAT_00dca3f8;
                    if (local_8 == 0) goto LAB_006f57c5;
                    param_3 = (int *)((int)param_3 + -0x10000);
                  } while (0 < (int)param_3);
                }
                do {
                  param_3 = (int *)((int)param_3 + local_34);
                  puVar9 = (uint *)((int)puVar9 + local_2c);
                  local_20 = local_20 + local_58;
                } while ((int)param_3 < 1);
              } while( true );
            }
            if (param_4 == 0) {
              local_8 = local_44;
              param_3 = (int *)local_40;
              puVar7 = local_10;
              puVar9 = local_1c;
              while( true ) {
                while( true ) {
                  uVar2 = (uint)(byte)*puVar9;
                  *(byte *)puVar9 =
                       (byte)((((int)((byte)*puVar7 * uVar2) >> 8) - uVar2) *
                              (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                              (uint)*(byte *)((int)puVar7 + 3) * DAT_00dca3f8 + uVar2 * 0x1000000 >>
                             0x18);
                  uVar2 = (uint)*(byte *)((int)puVar9 + 1);
                  *(byte *)((int)puVar9 + 1) =
                       (byte)((((int)(*(byte *)((int)puVar7 + 1) * uVar2) >> 8) - uVar2) *
                              (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                              (uint)*(byte *)((int)puVar7 + 3) * DAT_00dca3f8 + uVar2 * 0x1000000 >>
                             0x18);
                  uVar2 = (uint)*(byte *)((int)puVar9 + 2);
                  *(byte *)((int)puVar9 + 2) =
                       (byte)((((int)(*(byte *)((int)puVar7 + 2) * uVar2) >> 8) - uVar2) *
                              (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                              (uint)*(byte *)((int)puVar7 + 3) * DAT_00dca3f8 + uVar2 * 0x1000000 >>
                             0x18);
                  puVar9 = puVar9 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) break;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  if ((int)param_3 < 1) {
                    do {
                      param_3 = (int *)((int)param_3 + local_34);
                      puVar7 = (uint *)((int)puVar7 + local_2c);
                      local_20 = local_20 + local_58;
                    } while ((int)param_3 < 1);
                  }
                }
                puVar9 = (uint *)((int)local_1c + local_48);
                local_14 = local_14 - 0x10000;
                if ((int)local_14 < 1) {
                  do {
                    local_14 = local_14 + local_38;
                    local_10 = (uint *)((int)local_10 + local_3c);
                    local_28 = local_28 + local_5c;
                  } while ((int)local_14 < 1);
                }
                local_24 = local_24 + -1;
                if (local_24 == 0) break;
                local_8 = local_44;
                param_3 = (int *)local_40;
                puVar7 = local_10;
                local_20 = local_28;
                local_1c = puVar9;
              }
              return;
            }
            iVar5 = DAT_00dca3f8;
LAB_006f5330:
            local_20 = local_28;
            local_8 = local_44;
            puVar7 = local_1c;
            puVar9 = local_10;
            param_3 = (int *)local_40;
            do {
              if (*(byte *)((int)puVar9 + 3) == 0) {
                do {
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006f550d;
                  param_3 = (int *)((int)param_3 + -0x10000);
                } while (0 < (int)param_3);
              }
              else if (*(byte *)((int)puVar9 + 3) == 0xff) {
                do {
                  uVar2 = (uint)(byte)*puVar7;
                  *(byte *)puVar7 =
                       (byte)((((int)((byte)*puVar9 * uVar2) >> 8) - uVar2) *
                              (uint)(byte)(&DAT_00dca2e0)[*local_20] * iVar5 + uVar2 * 0x10000 >>
                             0x10);
                  uVar2 = (uint)*(byte *)((int)puVar7 + 1);
                  *(byte *)((int)puVar7 + 1) =
                       (byte)((((int)(*(byte *)((int)puVar9 + 1) * uVar2) >> 8) - uVar2) *
                              (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                              uVar2 * 0x10000 >> 0x10);
                  uVar2 = (uint)*(byte *)((int)puVar7 + 2);
                  *(byte *)((int)puVar7 + 2) =
                       (byte)((((int)(*(byte *)((int)puVar9 + 2) * uVar2) >> 8) - uVar2) *
                              (uint)(byte)(&DAT_00dca2e0)[*local_20] * DAT_00dca3f8 +
                              uVar2 * 0x10000 >> 0x10);
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006f5508;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  iVar5 = DAT_00dca3f8;
                } while (0 < (int)param_3);
              }
              else {
                do {
                  uVar2 = (uint)(byte)*puVar7;
                  *(byte *)puVar7 =
                       (byte)((((int)((byte)*puVar9 * uVar2) >> 8) - uVar2) *
                              (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                              (uint)*(byte *)((int)puVar9 + 3) * iVar5 + uVar2 * 0x1000000 >> 0x18);
                  uVar2 = (uint)*(byte *)((int)puVar7 + 1);
                  *(byte *)((int)puVar7 + 1) =
                       (byte)((((int)(*(byte *)((int)puVar9 + 1) * uVar2) >> 8) - uVar2) *
                              (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                              (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8 + uVar2 * 0x1000000 >>
                             0x18);
                  uVar2 = (uint)*(byte *)((int)puVar7 + 2);
                  *(byte *)((int)puVar7 + 2) =
                       (byte)((((int)(*(byte *)((int)puVar9 + 2) * uVar2) >> 8) - uVar2) *
                              (uint)(byte)(&DAT_00dca2e0)[*local_20] *
                              (uint)*(byte *)((int)puVar9 + 3) * DAT_00dca3f8 + uVar2 * 0x1000000 >>
                             0x18);
                  puVar7 = puVar7 + 1;
                  local_8 = local_8 + -1;
                  if (local_8 == 0) goto LAB_006f5508;
                  param_3 = (int *)((int)param_3 + -0x10000);
                  iVar5 = DAT_00dca3f8;
                } while (0 < (int)param_3);
              }
              do {
                param_3 = (int *)((int)param_3 + local_34);
                puVar9 = (uint *)((int)puVar9 + local_2c);
                local_20 = local_20 + local_58;
              } while ((int)param_3 < 1);
            } while( true );
          }
        }
      }
    }
  }
  return;
LAB_006fb865:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fb724;
LAB_006fbbd3:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
    local_28 = local_28 + local_5c;
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fba60;
LAB_006fbf2a:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fbe20;
LAB_006fc1d8:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_c = local_10;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fc0b0;
LAB_006fc4e6:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fc3b4;
LAB_006fc813:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
    local_28 = local_28 + local_5c;
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fc6c0;
LAB_006fcdc8:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_c = local_10;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fccb0;
LAB_006fcb42:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fca50;
LAB_006fb369:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fb2a4;
LAB_006fb598:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_c = local_10;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fb4b0;
LAB_006fb0ee:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_10 = (uint *)((int)local_10 + local_3c);
      local_14 = local_14 + local_38;
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fafe6;
LAB_006fae58:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fad77;
LAB_006fabef:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fab10;
LAB_006faaa2:
  do {
    param_3 = (int *)((int)param_3 + local_34);
    local_c = (uint *)((int)local_c + local_2c);
  } while ((int)param_3 < 1);
  goto LAB_006faa2a;
LAB_006fa944:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fa890;
LAB_006fa624:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
    local_28 = local_28 + local_5c;
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fa510;
LAB_006fa0d8:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f9fd2;
LAB_006f9e78:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f9da7;
LAB_006f9bc4:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
    local_28 = local_28 + local_5c;
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f9aa0;
LAB_006f98ed:
  local_18 = (uint *)((int)puVar7 + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f97f0;
LAB_006f8dc3:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f8c92;
LAB_006f90da:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
    local_28 = local_28 + local_5c;
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f8f90;
LAB_006f9648:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_c = local_10;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f9546;
LAB_006f93e2:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f9300;
LAB_006f8b45:
  local_18 = (uint *)((int)puVar7 + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f8aa5;
LAB_006f8a58:
  do {
    puVar7 = (uint *)((int)puVar7 + local_2c);
    bVar20 = SCARRY4(iVar13,local_34);
    iVar13 = iVar13 + local_34;
  } while (bVar20 != iVar13 < 0);
  goto LAB_006f8a40;
LAB_006f8a04:
  local_1c = (uint *)((int)local_1c + iVar5);
  bVar20 = local_14 < 0x10000;
  local_14 = local_14 - 0x10000;
  if (bVar20 || local_14 == 0) {
    do {
      local_10 = (uint *)((int)local_10 + local_3c);
      bVar20 = SCARRY4(local_14,local_38);
      local_14 = local_14 + local_38;
    } while (bVar20 != (int)local_14 < 0);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f89c7;
LAB_006f87ee:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_10 = (uint *)((int)local_10 + local_3c);
      local_14 = local_14 + local_38;
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f86a6;
LAB_006f84fe:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f83f1;
LAB_007061f2:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_007060d0;
LAB_00705ec3:
  iVar5 = DAT_00dca3f8;
LAB_00705ec8:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00705ca5;
LAB_00705b14:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00705a10;
LAB_00705835:
  iVar5 = DAT_00dca3f8;
LAB_0070583a:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00705655;
LAB_00705433:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_10 = (uint *)((int)local_10 + local_3c);
      local_14 = local_14 + local_38;
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_007052d4;
LAB_0070508e:
  iVar5 = DAT_00dca3f8;
LAB_00705093:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_10 = (uint *)((int)local_10 + local_3c);
      local_14 = local_14 + local_38;
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00704e15;
LAB_00704c28:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00704af0;
LAB_007048ce:
  iVar5 = DAT_00dca3f8;
  puVar7 = local_10;
LAB_007048d6:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      puVar7 = (uint *)((int)puVar7 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
    local_10 = puVar7;
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_007046a0;
LAB_007070a3:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_10 = (uint *)((int)local_10 + local_3c);
      local_14 = local_14 + local_38;
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00706f60;
LAB_00706d32:
  iVar5 = DAT_00dca3f8;
LAB_00706d3a:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_10 = (uint *)((int)local_10 + local_3c);
      local_14 = local_14 + local_38;
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00706af7;
LAB_007068f8:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_007067d7;
LAB_007065ce:
  iVar5 = DAT_00dca3f8;
  puVar7 = local_10;
LAB_007065d6:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      puVar7 = (uint *)((int)puVar7 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
    local_10 = puVar7;
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_007063c7;
LAB_00707744:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00707650;
LAB_00707485:
  iVar5 = DAT_00dca3f8;
LAB_0070748a:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_007072c0;
LAB_00707ab5:
  iVar5 = DAT_00dca3f8;
LAB_00707aba:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_007078b6;
LAB_00707da9:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_c = local_10;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00707ca0;
LAB_00704512:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00704442;
LAB_007042d2:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00704160;
LAB_00704006:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00703f40;
LAB_00703dc8:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00703c80;
LAB_00703818:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00703665;
LAB_007034da:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_007033f2;
LAB_00703258:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_007030c0;
LAB_00702f29:
  local_18 = (uint *)((int)puVar7 + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00702e56;
LAB_00702ce9:
  local_18 = (uint *)((int)puVar7 + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00702b64;
LAB_00702af1:
  do {
    param_3 = (int *)((int)param_3 + local_34);
    puVar9 = (uint *)((int)puVar9 + local_2c);
  } while ((int)param_3 < 1);
  goto LAB_00702a7b;
LAB_00702997:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_007028e0;
LAB_007027d0:
  do {
    param_3 = (int *)((int)param_3 + local_34);
    local_c = (uint *)((int)local_c + local_2c);
  } while ((int)param_3 < 1);
  goto LAB_0070273b;
LAB_007026e7:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00702592;
LAB_007020e8:
  local_18 = (uint *)((int)puVar7 + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00701f07;
LAB_00701e76:
  do {
    param_3 = (int *)((int)param_3 + local_34);
    local_c = (uint *)((int)local_c + local_2c);
    local_20 = local_20 + local_58;
  } while ((int)param_3 < 1);
  goto LAB_00701ddf;
LAB_00701d7e:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00701c90;
LAB_00701c00:
  do {
    param_3 = (int *)((int)param_3 + local_34);
    local_c = (uint *)((int)local_c + local_2c);
    local_20 = local_20 + local_58;
  } while ((int)param_3 < 1);
  goto LAB_00701b4b;
LAB_00701ad8:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00701930;
LAB_0070178a:
  local_18 = (uint *)((int)puVar7 + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_007016a0;
LAB_00701519:
  local_18 = (uint *)((int)puVar7 + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00701375;
LAB_00701204:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00701130;
LAB_00700fb9:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00700e40;
LAB_00700c7e:
  local_18 = (uint *)((int)puVar7 + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00700b50;
LAB_00700978:
  local_18 = (uint *)((int)puVar7 + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00700766;
LAB_007005b8:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_007004b0;
LAB_007002e8:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_00700117;
LAB_006fff58:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_c = local_10;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ffe51;
LAB_006ffc75:
  iVar5 = DAT_00dca3f8;
LAB_006ffc7a:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ffa75;
LAB_006ff904:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ff820;
LAB_006ff665:
  iVar5 = DAT_00dca3f8;
LAB_006ff66a:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ff4b0;
LAB_006ff2a3:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_10 = (uint *)((int)local_10 + local_3c);
      local_14 = local_14 + local_38;
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ff160;
LAB_006fef3e:
  iVar5 = DAT_00dca3f8;
LAB_006fef46:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_10 = (uint *)((int)local_10 + local_3c);
      local_14 = local_14 + local_38;
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fed00;
LAB_006feb08:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fe9e5;
LAB_006fe7eb:
  iVar5 = DAT_00dca3f8;
  puVar7 = local_10;
LAB_006fe7f3:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      puVar7 = (uint *)((int)puVar7 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
    local_10 = puVar7;
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fe5e0;
LAB_006fe530:
  do {
    local_c = (uint *)((int)local_c + local_2c);
    param_3 = (int *)((int)param_3 + local_34);
  } while ((int)param_3 < 1);
  goto LAB_006fe4d9;
LAB_006fe488:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fe3f0;
LAB_006fe252:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fe0e0;
LAB_006fe087:
  do {
    puVar7 = (uint *)((int)puVar7 + local_2c);
    bVar20 = SCARRY4(iVar4,local_34);
    iVar4 = iVar4 + local_34;
  } while (bVar20 != iVar4 < 0);
  goto LAB_006fe06f;
LAB_006fe02f:
  local_1c = (uint *)((int)local_1c + iVar5);
  bVar20 = local_14 < 0x10000;
  local_14 = local_14 - 0x10000;
  if (bVar20 || local_14 == 0) {
    do {
      local_10 = (uint *)((int)local_10 + local_3c);
      bVar20 = SCARRY4(local_14,local_38);
      local_14 = local_14 + local_38;
    } while (bVar20 != (int)local_14 < 0);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fdfe7;
LAB_006fde66:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fdd30;
LAB_006fdb4e:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fda10;
LAB_006fd838:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fd626;
LAB_006fd47a:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fd367;
LAB_006fd1aa:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006fcfc0;
LAB_006ed903:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
    local_28 = local_28 + local_5c;
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ed7b0;
LAB_006ed5c9:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ed4a0;
LAB_006ede64:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006edd56;
LAB_006edbf4:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_10 = (uint *)((int)local_10 + local_3c);
      local_14 = local_14 + local_38;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006edb15;
LAB_006ee46a:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
    local_28 = local_28 + local_5c;
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ee320;
LAB_006ee149:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ee030;
LAB_006ee9ad:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ee8a0;
LAB_006ee744:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_10 = (uint *)((int)local_10 + local_3c);
      local_14 = local_14 + local_38;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ee675;
LAB_006ed338:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_c = local_10;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ed273;
LAB_006ed165:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ed0c1;
LAB_006ecf1e:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_10 = (uint *)((int)local_10 + local_3c);
      local_14 = local_14 + local_38;
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ece23;
LAB_006eccd8:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ecc10;
LAB_006ec3d3:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
    local_28 = local_28 + local_5c;
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ec2c0;
LAB_006eca8e:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ec9b0;
LAB_006ec7fc:
  do {
    puVar7 = (uint *)((int)puVar7 + local_2c);
    bVar20 = SCARRY4(iVar4,local_34);
    iVar4 = iVar4 + local_34;
  } while (bVar20 != iVar4 < 0);
  goto LAB_006ec7da;
LAB_006ec772:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ec6c4;
LAB_006ec608:
  local_1c = (uint *)((int)local_1c + iVar5);
  bVar20 = local_14 < 0x10000;
  local_14 = local_14 - 0x10000;
  if (bVar20 || local_14 == 0) {
    do {
      local_10 = (uint *)((int)local_10 + local_3c);
      bVar20 = SCARRY4(local_14,local_38);
      local_14 = local_14 + local_38;
    } while (bVar20 != (int)local_14 < 0);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ec5b9;
LAB_006eb9d3:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
    local_28 = local_28 + local_5c;
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006eb8b0;
LAB_006eb713:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006eb616;
LAB_006ebe9f:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ebdb0;
LAB_006ebc69:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ebbb1;
LAB_006eaf6a:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
    local_28 = local_28 + local_5c;
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006eae30;
LAB_006eac69:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006eab67;
LAB_006eb45d:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006eb366;
LAB_006eb224:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_10 = (uint *)((int)local_10 + local_3c);
      local_14 = local_14 + local_38;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006eb165;
LAB_006eaa21:
  local_1c = (uint *)((int)local_1c + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ea981;
LAB_006ea937:
  do {
    puVar7 = (uint *)((int)puVar7 + local_2c);
    bVar20 = SCARRY4(iVar13,local_34);
    iVar13 = iVar13 + local_34;
  } while (bVar20 != iVar13 < 0);
  goto LAB_006ea921;
LAB_006ea8e5:
  local_1c = (uint *)((int)local_1c + iVar5);
  bVar20 = local_14 < 0x10000;
  local_14 = local_14 - 0x10000;
  if (bVar20 || local_14 == 0) {
    do {
      local_10 = (uint *)((int)local_10 + local_3c);
      bVar20 = SCARRY4(local_14,local_38);
      local_14 = local_14 + local_38;
    } while (bVar20 != (int)local_14 < 0);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ea8aa;
LAB_006ea6fe:
  local_1c = (uint *)((int)local_1c + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
    local_28 = local_28 + local_5c;
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ea5e3;
LAB_006ea475:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ea397;
LAB_006f6a30:
  local_1c = (uint *)((int)local_1c + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f6937;
LAB_006f67ab:
  iVar5 = DAT_00dca3f8;
LAB_006f67b0:
  local_1c = (uint *)((int)local_1c + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f65d0;
LAB_006f6479:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f63b2;
LAB_006f6242:
  iVar5 = DAT_00dca3f8;
LAB_006f6247:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f60c2;
LAB_006f5ed9:
  local_1c = (uint *)((int)local_1c + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
    local_28 = local_28 + local_5c;
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f5da2;
LAB_006f5ba1:
  iVar5 = DAT_00dca3f8;
LAB_006f5ba6:
  local_1c = (uint *)((int)local_1c + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
    local_28 = local_28 + local_5c;
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f5967;
LAB_006f57c5:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f56c4;
LAB_006f5508:
  iVar5 = DAT_00dca3f8;
LAB_006f550d:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f5330;
LAB_006f8230:
  local_1c = (uint *)((int)local_1c + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f8132;
LAB_006f7fab:
  iVar5 = DAT_00dca3f8;
LAB_006f7fb0:
  local_1c = (uint *)((int)local_1c + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f7df0;
LAB_006f7cb4:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f7bf2;
LAB_006f7a92:
  iVar5 = DAT_00dca3f8;
LAB_006f7a97:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f7932;
LAB_006f7753:
  local_1c = (uint *)((int)local_1c + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
    local_28 = local_28 + local_5c;
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f7622;
LAB_006f7431:
  iVar5 = DAT_00dca3f8;
LAB_006f7436:
  local_1c = (uint *)((int)local_1c + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
    local_28 = local_28 + local_5c;
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f7207;
LAB_006f7048:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f6f52;
LAB_006f6d88:
  iVar5 = DAT_00dca3f8;
LAB_006f6d8d:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f6bd0;
LAB_006f51e2:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f5146;
LAB_006f5015:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f4f03;
LAB_006f4e00:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f4d87;
LAB_006f4c61:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f4b75;
LAB_006f49f4:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f4914;
LAB_006f4798:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f4610;
LAB_006f44c7:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f4414;
LAB_006f42c6:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f4172;
LAB_006f4005:
  local_18 = (uint *)((int)puVar7 + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f3f50;
LAB_006f3dcb:
  iVar5 = DAT_00dca3f8;
LAB_006f3dd0:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f3c52;
LAB_006f3ac0:
  do {
    puVar7 = (uint *)((int)puVar7 + local_2c);
    bVar20 = SCARRY4(iVar4,local_34);
    iVar4 = iVar4 + local_34;
  } while (bVar20 != iVar4 < 0);
  goto LAB_006f3aa6;
LAB_006f3a44:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f39a7;
LAB_006f38f3:
  local_1c = (uint *)((int)local_1c + iVar5);
  bVar20 = local_14 < 0x10000;
  local_14 = local_14 - 0x10000;
  if (bVar20 || local_14 == 0) {
    do {
      local_10 = (uint *)((int)local_10 + local_3c);
      bVar20 = SCARRY4(local_14,local_38);
      local_14 = local_14 + local_38;
    } while (bVar20 != (int)local_14 < 0);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f38aa;
LAB_006f375f:
  iVar5 = DAT_00dca3f8;
LAB_006f3764:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f3630;
LAB_006f346a:
  local_18 = (uint *)((int)puVar7 + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f3370;
LAB_006f31cb:
  iVar5 = DAT_00dca3f8;
LAB_006f31d0:
  local_18 = (uint *)((int)puVar7 + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f3001;
LAB_006f2e78:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f2db0;
LAB_006f2c31:
  iVar5 = DAT_00dca3f8;
LAB_006f2c36:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f2ac0;
LAB_006f2935:
  local_18 = (uint *)((int)puVar7 + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f2862;
LAB_006f26bb:
  iVar5 = DAT_00dca3f8;
LAB_006f26c0:
  local_18 = (uint *)((int)puVar7 + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f2510;
LAB_006f23d1:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f2310;
LAB_006f219f:
  iVar5 = DAT_00dca3f8;
LAB_006f21a4:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f2037;
LAB_006f1e7a:
  local_18 = (uint *)((int)puVar7 + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f1d76;
LAB_006f1bab:
  iVar5 = DAT_00dca3f8;
LAB_006f1bb0:
  local_18 = (uint *)((int)puVar7 + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f19c2;
LAB_006f181b:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f1732;
LAB_006f1575:
  iVar5 = DAT_00dca3f8;
LAB_006f157a:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f13e7;
LAB_006f1260:
  local_1c = (uint *)((int)local_1c + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f1180;
LAB_006f100b:
  iVar5 = DAT_00dca3f8;
LAB_006f1010:
  local_1c = (uint *)((int)local_1c + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f0e70;
LAB_006f0d45:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f0ca2;
LAB_006f0b54:
  iVar5 = DAT_00dca3f8;
LAB_006f0b59:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f0a12;
LAB_006f0849:
  local_1c = (uint *)((int)local_1c + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
    local_28 = local_28 + local_5c;
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f0732;
LAB_006f0551:
  iVar5 = DAT_00dca3f8;
LAB_006f0556:
  local_1c = (uint *)((int)local_1c + local_48);
  for (local_14 = local_14 - 0x10000; (int)local_14 < 1; local_14 = local_14 + local_38) {
    local_10 = (uint *)((int)local_10 + local_3c);
    local_28 = local_28 + local_5c;
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f0347;
LAB_006f01b8:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006f00d2;
LAB_006eff1a:
  iVar5 = DAT_00dca3f8;
LAB_006eff1f:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006efd80;
LAB_006efc3f:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006efbc3;
LAB_006efa82:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ef970;
LAB_006ef924:
  do {
    puVar7 = (uint *)((int)puVar7 + local_2c);
    bVar20 = SCARRY4(iVar4,local_34);
    iVar4 = iVar4 + local_34;
  } while (bVar20 != iVar4 < 0);
  goto LAB_006ef912;
LAB_006ef8d6:
  local_1c = (uint *)((int)local_1c + iVar5);
  bVar20 = local_14 < 0x10000;
  local_14 = local_14 - 0x10000;
  if (bVar20 || local_14 == 0) {
    do {
      local_10 = (uint *)((int)local_10 + local_3c);
      bVar20 = SCARRY4(local_14,local_38);
      local_14 = local_14 + local_38;
    } while (bVar20 != (int)local_14 < 0);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ef8a0;
LAB_006ef776:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ef6a0;
LAB_006ef25b:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  local_20 = local_28;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006ef090;
LAB_006eef38:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006eee72;
LAB_006eed02:
  local_1c = (uint *)((int)local_1c + local_48);
  local_14 = local_14 - 0x10000;
  if ((int)local_14 < 1) {
    do {
      local_14 = local_14 + local_38;
      local_10 = (uint *)((int)local_10 + local_3c);
      local_28 = local_28 + local_5c;
    } while ((int)local_14 < 1);
  }
  local_24 = local_24 + -1;
  if (local_24 == 0) {
    return;
  }
  goto LAB_006eeb90;
}

