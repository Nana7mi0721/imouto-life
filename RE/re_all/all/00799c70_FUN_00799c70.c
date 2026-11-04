
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

int FUN_00799c70(undefined1 **param_1,int *param_2,int param_3,int *param_4,undefined4 *param_5,
                undefined4 *param_6,uint *param_7,undefined4 *param_8)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  uint uVar8;
  int iVar9;
  byte bVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined1 *puVar14;
  uint *puVar15;
  undefined2 *puVar16;
  int *piVar17;
  undefined4 *puVar18;
  undefined1 **ppuVar19;
  int *piVar20;
  int aiStack_2e0 [4];
  undefined4 *puStack_2d0;
  int iStack_2cc;
  int *piStack_2c8;
  undefined4 uStack_2c4;
  undefined1 local_2b4 [640];
  uint local_34;
  int local_30;
  int local_2c [5];
  undefined1 *local_18 [2];
  int local_10;
  uint local_c;
  int local_8;
  
  puVar3 = param_7;
  iVar2 = (int)param_1;
  local_10 = 0;
  local_8 = 0;
  local_2c[1] = 0;
  local_2c[2] = 0;
  if ((param_4 != (int *)0x0) && (iVar5 = 0, 0 < param_2[1])) {
    puVar18 = (undefined4 *)((int)param_1 + 0x954);
    do {
      *puVar18 = 0;
      iVar5 = iVar5 + 1;
      puVar18 = puVar18 + 0x429;
    } while (iVar5 < param_2[1]);
  }
  if (*(int *)((int)param_1 + 0x2158) < param_2[1]) {
    uStack_2c4 = (int *)((int)param_1 + 0x10a4);
    piStack_2c8 = (undefined4 *)0x799cd4;
    local_8 = FUN_0079a5e0();
  }
  if (((param_2[1] != 1) || (*(int *)((int)param_1 + 0x2158) != 2)) ||
     (local_30 = 1, param_2[3] != *(int *)((int)param_1 + 0x90c) * 1000)) {
    local_30 = 0;
  }
  if ((*(int *)((int)param_1 + 0x954) == 0) && (param_4 = (int *)0x0, 0 < param_2[1])) {
    puVar18 = (undefined4 *)((int)param_1 + 0x914);
    do {
      iVar5 = param_2[4];
      if (iVar5 == 0) {
        puVar18[0x11] = 1;
        *puVar18 = 2;
      }
      else if (iVar5 == 10) {
        puVar18[0x11] = 1;
        *puVar18 = 2;
      }
      else {
        if (iVar5 == 0x14) {
          puVar18[0x11] = 1;
        }
        else if (iVar5 == 0x28) {
          puVar18[0x11] = 2;
        }
        else {
          if (iVar5 != 0x3c) {
            return -0xcb;
          }
          puVar18[0x11] = 3;
        }
        *puVar18 = 4;
      }
      piStack_2c8 = (int *)((param_2[3] >> 10) + 1);
      if (((piStack_2c8 != (undefined4 *)0x8) && (piStack_2c8 != (undefined4 *)0xc)) &&
         (piStack_2c8 != (undefined4 *)0x10)) {
        return -200;
      }
      uStack_2c4 = (int *)param_2[2];
      iStack_2cc = (int)(puVar18 + -0x245);
      puStack_2d0 = (undefined4 *)0x799da4;
      iVar5 = FUN_0079b540();
      param_4 = (int *)((int)param_4 + 1);
      puVar18 = puVar18 + 0x429;
      local_8 = local_8 + iVar5;
    } while ((int)param_4 < param_2[1]);
  }
  if (((*param_2 == 2) && (param_2[1] == 2)) &&
     ((*(int *)((int)param_1 + 0x2154) == 1 || (*(int *)((int)param_1 + 0x2158) == 1)))) {
    *(undefined4 *)((int)param_1 + 0x2148) = 0;
    *(undefined4 *)((int)param_1 + 0x2150) = 0;
    puVar18 = (undefined4 *)((int)param_1 + 0x980);
    puVar13 = (undefined4 *)((int)param_1 + 0x1a24);
    for (iVar5 = 0x4b; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar13 = *puVar18;
      puVar18 = puVar18 + 1;
      puVar13 = puVar13 + 1;
    }
  }
  *(int *)((int)param_1 + 0x2154) = *param_2;
  *(int *)((int)param_1 + 0x2158) = param_2[1];
  if ((48000 < param_2[2]) || (param_2[2] < 8000)) {
    return -200;
  }
  if ((param_3 != 1) && (*(int *)((int)param_1 + 0x954) == 0)) {
    param_4 = (int *)0x0;
    if (0 < param_2[1]) {
      piVar20 = (int *)((int)param_1 + 0x958);
      do {
        iVar5 = 0;
        if (0 < *piVar20) {
          piVar17 = piVar20 + 3;
          do {
            uStack_2c4 = (int *)0x1;
            piStack_2c8 = param_5;
            iStack_2cc = 0x799e90;
            iVar6 = FUN_007a2130();
            *piVar17 = iVar6;
            iVar5 = iVar5 + 1;
            piVar17 = piVar17 + 1;
          } while (iVar5 < *piVar20);
        }
        uStack_2c4 = (int *)0x1;
        piStack_2c8 = param_5;
        iStack_2cc = 0x799eaa;
        iVar5 = FUN_007a2130();
        piVar20[6] = iVar5;
        param_4 = (int *)((int)param_4 + 1);
        piVar20 = piVar20 + 0x429;
      } while ((int)param_4 < param_2[1]);
    }
    iVar5 = 0;
    if (0 < param_2[1]) {
      piVar20 = (int *)((int)param_1 + 0x958);
      do {
        puVar15 = (uint *)(piVar20 + 7);
        *puVar15 = 0;
        piVar20[8] = 0;
        piVar20[9] = 0;
        if (piVar20[6] != 0) {
          if (*piVar20 == 1) {
            *puVar15 = 1;
          }
          else {
            piStack_2c8 = *(int **)(&DAT_008377ac + *piVar20 * 4);
            uStack_2c4 = (int *)0x8;
            iStack_2cc = (int)param_5;
            puStack_2d0 = (undefined4 *)0x799f26;
            iVar6 = FUN_007a2170();
            iVar11 = 0;
            if (0 < *piVar20) {
              do {
                bVar10 = (byte)iVar11;
                iVar11 = iVar11 + 1;
                *puVar15 = iVar6 + 1 >> (bVar10 & 0x1f) & 1;
                puVar15 = puVar15 + 1;
              } while (iVar11 < *piVar20);
            }
          }
        }
        iVar5 = iVar5 + 1;
        piVar20 = piVar20 + 0x429;
      } while (iVar5 < param_2[1]);
    }
    if ((param_3 == 0) && (puVar18 = (undefined4 *)0x0, 0 < *(int *)((int)param_1 + 0x958))) {
      param_4 = (int *)((int)param_1 + 0x1a18);
      do {
        iVar5 = param_2[1];
        iVar6 = 0;
        if (0 < iVar5) {
          do {
            iVar11 = (int)puVar18 + iVar6 * 0x429;
            if (*(int *)((int)param_1 + 0x974 + iVar11 * 4) != 0) {
              if ((iVar5 == 2) && (iVar6 == 0)) {
                uStack_2c4 = local_2c + 1;
                piStack_2c8 = param_5;
                iStack_2cc = 0x799fc5;
                FUN_0079b420();
                if (*param_4 == 0) {
                  uStack_2c4 = &local_10;
                  piStack_2c8 = param_5;
                  iStack_2cc = 0x799fdd;
                  FUN_0079b520();
                }
              }
              if (((int)puVar18 < 1) || (*(int *)((int)param_1 + 0x970 + iVar11 * 4) == 0)) {
                uStack_2c4 = (int *)0x0;
              }
              else {
                uStack_2c4 = (int *)0x2;
              }
              piStack_2c8 = (undefined4 *)0x1;
              puStack_2d0 = param_5;
              iVar5 = (int)param_1 + iVar6 * 0x10a4;
              aiStack_2e0[2] = 0x79a01d;
              aiStack_2e0[3] = iVar5;
              iStack_2cc = (int)puVar18;
              FUN_0079b110();
              aiStack_2e0[1] = (int)*(char *)(iVar5 + 0xace);
              aiStack_2e0[2] = *(undefined4 *)(iVar5 + 0x918);
              aiStack_2e0[0] = (int)*(char *)(iVar5 + 0xacd);
              FUN_0079af50(param_5,local_2b4);
            }
            iVar5 = param_2[1];
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar5);
        }
        puVar18 = (undefined4 *)((int)puVar18 + 1);
        param_4 = param_4 + 1;
      } while ((int)puVar18 < *(int *)((int)param_1 + 0x958));
    }
  }
  if (param_2[1] != 2) goto LAB_0079a114;
  if ((param_3 != 0) &&
     ((param_3 != 2 || (*(int *)((int)param_1 + 0x974 + *(int *)((int)param_1 + 0x954) * 4) != 1))))
  {
    piVar20 = local_2c;
    psVar7 = (short *)((int)param_1 + 0x2148);
    iVar5 = 2;
    do {
      piVar20 = piVar20 + 1;
      *piVar20 = (int)*psVar7;
      psVar7 = psVar7 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    goto LAB_0079a114;
  }
  uStack_2c4 = local_2c + 1;
  piStack_2c8 = param_5;
  iStack_2cc = 0x79a0cb;
  FUN_0079b420();
  if (param_3 == 0) {
    iVar5 = *(int *)((int)param_1 + 0x1a08 + *(int *)((int)param_1 + 0x954) * 4);
joined_r0x0079a100:
    if (iVar5 == 0) {
      uStack_2c4 = &local_10;
      piStack_2c8 = param_5;
      iStack_2cc = 0x79a10c;
      FUN_0079b520();
      goto LAB_0079a114;
    }
  }
  else if (param_3 == 2) {
    iVar5 = *(int *)((int)param_1 + 0x1a18 + *(int *)((int)param_1 + 0x954) * 4);
    goto joined_r0x0079a100;
  }
  local_10 = 0;
LAB_0079a114:
  if (((param_2[1] == 2) && (local_10 == 0)) && (*(int *)((int)param_1 + 0x215c) == 1)) {
    puVar18 = (undefined4 *)((int)param_1 + 0x15e8);
    for (iVar5 = 0xf0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar18 = 0;
      puVar18 = puVar18 + 1;
    }
    puVar18 = (undefined4 *)((int)param_1 + 0x15a8);
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar18 = 0;
      puVar18 = puVar18 + 1;
    }
    *(undefined4 *)((int)param_1 + 0x19a8) = 100;
    *(undefined1 *)((int)param_1 + 0x19ac) = 10;
    *(undefined4 *)((int)param_1 + 0x20e8) = 0;
    *(undefined4 *)((int)param_1 + 0x19ec) = 1;
  }
  iVar5 = param_2[1];
  local_34 = (uint)(param_2[3] * iVar5 < *param_2 * param_2[2]);
  if (local_34 == 0) {
    iVar6 = (*(int *)((int)param_1 + 0x918) + 2) * iVar5;
  }
  else {
    iVar6 = 0;
  }
  uStack_2c4 = (int *)0x79a1ad;
  iVar6 = -(iVar6 * 2 + 3U & 0xfffffffc);
  if (local_34 == 0) {
    local_18[0] = local_2b4 + iVar6 + -0xc;
    local_18[1] = local_2b4 + *(int *)((int)param_1 + 0x918) * 2 + iVar6 + -8;
  }
  else {
    local_18[0] = (undefined1 *)param_6;
    local_18[1] = (undefined1 *)((int)param_6 + *(int *)((int)param_1 + 0x918) * 2 + 4);
  }
  if (param_3 == 0) {
    local_2c[3] = (uint)(local_10 == 0);
  }
  else if ((*(int *)((int)param_1 + 0x215c) == 0) ||
          (((iVar5 == 2 && (param_3 == 2)) &&
           (*(int *)((int)param_1 + 0x1a18 + *(int *)((int)param_1 + 0x19f8) * 4) == 1)))) {
    local_2c[3] = 1;
  }
  else {
    local_2c[3] = 0;
  }
  param_4 = (int *)0x0;
  if (0 < iVar5) {
    local_2c[4] = 0;
    ppuVar19 = local_18;
    piVar20 = (int *)((int)param_1 + 0x954);
    do {
      if ((local_2c[4] == 0) || (local_2c[3] != 0)) {
        iVar5 = *(int *)((int)param_1 + 0x954) - (int)param_4;
        if (iVar5 < 1) {
          uVar12 = 0;
        }
        else if (param_3 == 2) {
          uVar12 = -(uint)(*(int *)((int)param_1 + 0x970 + (local_2c[4] + iVar5) * 4) != 0) & 2;
        }
        else if ((local_2c[4] < 1) || (uVar12 = 1, *(int *)((int)param_1 + 0x215c) == 0)) {
          uVar12 = 2;
        }
        *(undefined4 **)(local_2b4 + iVar6 + -0x10) = param_8;
        puVar14 = *ppuVar19;
        *(uint *)(local_2b4 + iVar6 + -0x14) = uVar12;
        *(int *)((int)aiStack_2e0 + iVar6 + 0x14) = param_3;
        *(uint **)((int)aiStack_2e0 + iVar6 + 0x10) = &local_c;
        *(undefined1 **)((int)aiStack_2e0 + iVar6 + 0xc) = puVar14 + 4;
        *(undefined4 **)((int)aiStack_2e0 + iVar6 + 8) = param_5;
        *(int **)((int)aiStack_2e0 + iVar6 + 4) = piVar20 + -0x255;
        *(undefined4 *)((int)aiStack_2e0 + iVar6) = 0x79a2c6;
        iVar5 = FUN_0079add0();
        local_8 = local_8 + iVar5;
      }
      else {
        puVar18 = (undefined4 *)*ppuVar19;
        for (uVar12 = (local_c & 0x7fffffff) >> 1; puVar18 = puVar18 + 1, uVar12 != 0;
            uVar12 = uVar12 - 1) {
          *puVar18 = 0;
        }
        for (uVar12 = local_c * 2 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
          *(undefined1 *)puVar18 = 0;
          puVar18 = (undefined4 *)((int)puVar18 + 1);
        }
      }
      param_4 = (int *)((int)param_4 + 1);
      *piVar20 = *piVar20 + 1;
      ppuVar19 = ppuVar19 + 1;
      piVar20 = piVar20 + 0x429;
      local_2c[4] = local_2c[4] + 0x429;
    } while ((int)param_4 < param_2[1]);
  }
  puVar14 = local_18[0];
  if ((*param_2 == 2) && (param_2[1] == 2)) {
    uVar1 = *(undefined4 *)((int)param_1 + 0x90c);
    *(uint *)(local_2b4 + iVar6 + -0x10) = local_c;
    puVar4 = local_18[1];
    *(undefined4 *)(local_2b4 + iVar6 + -0x14) = uVar1;
    puVar14 = local_18[0];
    *(int **)((int)aiStack_2e0 + iVar6 + 0x14) = local_2c + 1;
    *(undefined1 **)((int)aiStack_2e0 + iVar6 + 0x10) = puVar4;
    *(undefined1 **)((int)aiStack_2e0 + iVar6 + 0xc) = puVar14;
    *(int *)((int)aiStack_2e0 + iVar6 + 8) = (int)param_1 + 0x2148;
    *(undefined4 *)((int)aiStack_2e0 + iVar6 + 4) = 0x79a334;
    FUN_0079ab10();
  }
  else {
    *(undefined4 *)local_18[0] = *(undefined4 *)((int)param_1 + 0x214c);
    *(undefined4 *)((int)param_1 + 0x214c) = *(undefined4 *)((int)puVar14 + local_c * 2);
  }
  uVar8 = (int)(local_c * param_2[2]) / (*(short *)((int)param_1 + 0x90c) * 1000);
  *param_7 = uVar8;
  iVar5 = *param_2;
  *(undefined4 *)(local_2b4 + iVar6 + -0x10) = 0x79a38e;
  uVar12 = local_34;
  iVar11 = -((uVar8 & (iVar5 != 2) - 1) * 2 + 3 & 0xfffffffc);
  param_5 = (undefined4 *)(local_2b4 + iVar11 + iVar6 + -0xc);
  if (iVar5 != 2) {
    param_5 = param_6;
  }
  if (local_34 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = (*(int *)((int)param_1 + 0x918) + 2) * param_2[1];
  }
  *(undefined4 *)(local_2b4 + iVar11 + iVar6 + -0x10) = 0x79a3c7;
  iVar5 = -(iVar5 * 2 + 3U & 0xfffffffc);
  if (uVar12 != 0) {
    local_18[0] = local_2b4 + iVar5 + iVar11 + iVar6 + -0xc;
    uVar12 = (*(int *)((int)param_1 + 0x918) + 2) * param_2[1];
    puVar18 = param_6;
    puVar13 = (undefined4 *)(local_2b4 + iVar5 + iVar11 + iVar6 + -0xc);
    for (uVar8 = (uVar12 & 0x7fffffff) >> 1; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar13 = *puVar18;
      puVar18 = puVar18 + 1;
      puVar13 = puVar13 + 1;
    }
    for (uVar12 = uVar12 * 2 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      *(undefined1 *)puVar13 = *(undefined1 *)puVar18;
      puVar18 = (undefined4 *)((int)puVar18 + 1);
      puVar13 = (undefined4 *)((int)puVar13 + 1);
    }
    local_18[1] = local_2b4 + *(int *)((int)param_1 + 0x918) * 2 + iVar5 + iVar11 + iVar6 + -8;
  }
  param_7 = (uint *)((int)param_1 + 0x980);
  param_4 = (int *)0x0;
  param_8 = param_6;
  param_1 = local_18;
  while( true ) {
    iVar9 = *param_2;
    if (param_2[1] <= *param_2) {
      iVar9 = param_2[1];
    }
    if (iVar9 <= (int)param_4) break;
    *(uint *)(local_2b4 + iVar5 + iVar11 + iVar6 + -0x10) = local_c;
    *(undefined1 **)(local_2b4 + iVar5 + iVar11 + iVar6 + -0x14) = *param_1 + 2;
    *(undefined4 **)((int)aiStack_2e0 + iVar5 + iVar11 + iVar6 + 0x14) = param_5;
    *(uint **)((int)aiStack_2e0 + iVar5 + iVar11 + iVar6 + 0x10) = param_7;
    *(undefined4 *)((int)aiStack_2e0 + iVar5 + iVar11 + iVar6 + 0xc) = 0x79a454;
    iVar9 = FUN_0079a970();
    local_8 = local_8 + iVar9;
    if ((*param_2 == 2) && (iVar9 = 0, 0 < (int)*puVar3)) {
      puVar18 = param_8;
      puVar13 = param_5;
      do {
        iVar9 = iVar9 + 1;
        *(undefined2 *)puVar18 = *(undefined2 *)puVar13;
        puVar18 = puVar18 + 1;
        puVar13 = (undefined4 *)((int)puVar13 + 2);
      } while (iVar9 < (int)*puVar3);
    }
    param_4 = (int *)((int)param_4 + 1);
    param_1 = param_1 + 1;
    param_7 = (uint *)((int)param_7 + 0x10a4);
    param_8 = (undefined4 *)((int)param_8 + 2);
  }
  if ((*param_2 == 2) && (param_2[1] == 1)) {
    if (local_30 == 0) {
      iVar5 = 0;
      if (0 < (int)*puVar3) {
        do {
          iVar5 = iVar5 + 1;
          *(undefined2 *)((int)param_6 + 2) = *(undefined2 *)param_6;
          param_6 = param_6 + 1;
        } while (iVar5 < (int)*puVar3);
      }
    }
    else {
      puVar14 = (undefined1 *)((int)local_18[0] + 2);
      *(uint *)(local_2b4 + iVar5 + iVar11 + iVar6 + -0x10) = local_c;
      *(undefined1 **)(local_2b4 + iVar5 + iVar11 + iVar6 + -0x14) = puVar14;
      *(undefined4 **)((int)aiStack_2e0 + iVar5 + iVar11 + iVar6 + 0x14) = param_5;
      *(int *)((int)aiStack_2e0 + iVar5 + iVar11 + iVar6 + 0x10) = iVar2 + 0x1a24;
      *(undefined4 *)((int)aiStack_2e0 + iVar5 + iVar11 + iVar6 + 0xc) = 0x79a4de;
      iVar5 = FUN_0079a970();
      iVar6 = 0;
      local_8 = local_8 + iVar5;
      if (0 < (int)*puVar3) {
        puVar16 = (undefined2 *)((int)param_6 + 2);
        do {
          iVar6 = iVar6 + 1;
          *puVar16 = *(undefined2 *)param_5;
          param_5 = (undefined4 *)((int)param_5 + 2);
          puVar16 = puVar16 + 2;
        } while (iVar6 < (int)*puVar3);
      }
    }
  }
  if (*(int *)(iVar2 + 0x1044) == 2) {
    local_2c[0] = 6;
    local_2c[1] = 4;
    local_2c[2] = 3;
    param_2[5] = local_2c[*(int *)(iVar2 + 0x90c) + -8 >> 2] * *(int *)(iVar2 + 0x904);
  }
  else {
    param_2[5] = 0;
  }
  if (param_3 == 1) {
    iVar5 = 0;
    if (0 < *(int *)(iVar2 + 0x2158)) {
      puVar14 = (undefined1 *)(iVar2 + 0x908);
      do {
        *puVar14 = 10;
        iVar5 = iVar5 + 1;
        puVar14 = puVar14 + 0x10a4;
      } while (iVar5 < *(int *)(iVar2 + 0x2158));
      return local_8;
    }
  }
  else {
    *(int *)(iVar2 + 0x215c) = local_10;
  }
  return local_8;
}

