
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d9250(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 uVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  uint uVar10;
  int unaff_ESI;
  byte *pbVar11;
  byte *pbVar12;
  int iVar13;
  ushort in_FPUControlWord;
  longlong lVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  undefined4 uVar17;
  int *local_550;
  byte *pbStack_54c;
  int *local_548;
  byte *pbStack_544;
  byte *pbStack_540;
  uint uStack_53c;
  uint local_538;
  int iStack_534;
  uint uStack_530;
  uint uStack_52c;
  undefined1 auStack_528 [4];
  undefined1 auStack_524 [4];
  uint uStack_520;
  ushort uStack_51c;
  ushort uStack_518;
  ushort uStack_514;
  uint uStack_504;
  undefined4 uStack_500;
  int iStack_4fc;
  int iStack_4f8;
  byte *pbStack_4f4;
  int iStack_4f0;
  byte *pbStack_4ec;
  int iStack_4e8;
  int iStack_4e4;
  undefined8 uStack_4e0;
  undefined8 uStack_4d8;
  undefined4 uStack_4d0;
  undefined4 uStack_4cc;
  undefined4 uStack_4c8;
  undefined4 uStack_4c4;
  uint uStack_4c0;
  undefined1 auStack_4bc [16];
  undefined1 auStack_4ac [12];
  undefined4 uStack_4a0;
  undefined4 uStack_49c;
  undefined1 uStack_440;
  undefined1 uStack_43f;
  undefined1 uStack_43e;
  undefined1 uStack_43c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_538 = 0;
  local_550 = (int *)0x0;
  local_548 = (int *)0x0;
  if ((((param_2 == 0) || (*(int *)(unaff_ESI + 0x620) != 0)) || (*(int *)(unaff_ESI + 0x61c) == 1))
     && ((param_1 == 0 || (*(int *)(unaff_ESI + 0x618) != 0)))) {
    return 0;
  }
  if (*(int *)(unaff_ESI + 0x598) < *(int *)(unaff_ESI + 0x5c0)) {
    do {
      do {
        if (local_550 != (int *)0x0) {
          (**(code **)(*local_550 + 8))(local_550);
          local_550 = (int *)0x0;
        }
        iVar5 = (**(code **)(**(int **)(unaff_ESI + 0x56c) + 0x24))
                          (*(int **)(unaff_ESI + 0x56c),0xfffffffc,0,0,&local_538,&uStack_504,
                           &local_550);
        if (iVar5 != 0) goto LAB_005d95c8;
      } while ((local_538 & 0x20) != 0);
      if ((local_538 & 2) != 0) goto LAB_005d95c8;
      if (local_550 == (int *)0x0) goto LAB_005d95dc;
      lVar14 = __alldiv(*(undefined4 *)(unaff_ESI + 0x638),*(undefined4 *)(unaff_ESI + 0x63c),4,0);
      uStack_4d8 = lVar14 + CONCAT44(uStack_500,uStack_504);
      uStack_4e0 = __alldiv((ulonglong)*(uint *)(unaff_ESI + 0x580) * 0x1000,
                            *(undefined4 *)(unaff_ESI + 0x584),0);
      puVar9 = auStack_4bc;
      puVar16 = &uStack_4e0;
      puVar15 = &uStack_4d8;
      FUN_0056d6c0();
      uStack_4e0._0_4_ = 0x89680000;
      uStack_4e0._4_4_ = 9;
      FUN_0056d730(auStack_4bc,&uStack_4e0,&uStack_4d8,puVar15,puVar16,puVar9);
      *(undefined4 *)(unaff_ESI + 0x594) = uStack_500;
      *(uint *)(unaff_ESI + 0x590) = uStack_504;
      *(int *)(unaff_ESI + 0x598) = (int)uStack_4d8;
    } while ((int)uStack_4d8 < *(int *)(unaff_ESI + 0x5c0));
    iVar5 = (**(code **)(*local_550 + 0xa0))();
    if (iVar5 == 0) {
      iVar5 = (**(code **)(*local_548 + 0xc))(local_548,&iStack_534,auStack_524,auStack_528);
      if (iVar5 == 0) {
        uVar10 = (*(uint *)(unaff_ESI + 0x578) >> 1) + 7 & 0xfffffff8;
        pbVar11 = (byte *)((*(uint *)(unaff_ESI + 0x57c) + 0xf >> 4) * *(int *)(unaff_ESI + 0x608) *
                           0x10 + iStack_534);
        pbStack_54c = pbVar11 + ((*(uint *)(unaff_ESI + 0x57c) >> 1) + 7 >> 3) * uVar10 * 8;
        FUN_0056d420();
        uStack_520 = *(uint *)(unaff_ESI + 0x60c) & 7;
        uStack_52c = *(uint *)(unaff_ESI + 0x60c) >> 3;
        pbStack_540 = *(byte **)(unaff_ESI + 0x5fc);
        uStack_530 = 0;
        pbStack_544 = pbVar11;
        if (*(int *)(unaff_ESI + 0x610) != 0) {
          pbStack_54c = pbStack_54c + -(int)pbVar11;
          do {
            pbVar7 = pbStack_54c + (int)pbStack_544;
            pbVar11 = pbStack_540;
            pbVar8 = pbVar7;
            pbVar12 = pbStack_544;
            if (uStack_52c != 0) {
              uStack_53c = uStack_52c;
              do {
                *pbVar11 = *pbVar12;
                pbVar11[1] = *pbVar8;
                pbVar11[2] = pbVar8[(int)(pbStack_544 + (1 - (int)pbVar7))];
                pbVar11[3] = pbVar8[1];
                pbVar11[4] = pbVar12[2];
                pbVar11[5] = pbVar8[2];
                pbVar11[6] = pbVar12[3];
                pbVar11[7] = pbVar8[3];
                pbVar11[8] = pbVar12[4];
                pbVar11[9] = pbVar8[4];
                pbVar11[10] = pbVar12[5];
                pbVar11[0xb] = pbVar8[5];
                pbVar11[0xc] = pbVar12[6];
                pbVar11[0xd] = pbVar8[6];
                pbVar11[0xe] = pbVar12[7];
                pbVar11[0xf] = pbVar8[7];
                pbVar11 = pbVar11 + 0x10;
                pbVar12 = pbVar12 + 8;
                pbVar8 = pbVar8 + 8;
                uStack_53c = uStack_53c - 1;
              } while (uStack_53c != 0);
              uStack_53c = 0;
            }
            if (uStack_520 != 0) {
              uStack_53c = uStack_520;
              do {
                *pbVar11 = *pbVar12;
                pbVar11[1] = *pbVar8;
                pbVar11 = pbVar11 + 2;
                pbVar12 = pbVar12 + 1;
                pbVar8 = pbVar8 + 1;
                uStack_53c = uStack_53c - 1;
              } while (uStack_53c != 0);
            }
            pbStack_540 = pbStack_540 + *(int *)(unaff_ESI + 0x614);
            uStack_530 = uStack_530 + 1;
            pbStack_544 = pbStack_544 + uVar10;
          } while (uStack_530 < *(uint *)(unaff_ESI + 0x610));
        }
        iVar5 = (**(code **)(*local_548 + 0x10))(local_548);
        if (iVar5 == 0) goto LAB_005d95f9;
      }
    }
LAB_005d95c8:
    if (local_550 != (int *)0x0) {
      (**(code **)(*local_550 + 8))(local_550);
      local_550 = (int *)0x0;
    }
LAB_005d95dc:
    if (local_548 != (int *)0x0) {
      (**(code **)(*local_548 + 8))(local_548);
    }
    return 0xffffffff;
  }
LAB_005d95f9:
  if ((param_2 != 0) && (*(int *)(unaff_ESI + 0x61c) == 0)) {
    iVar5 = thunk_FUN_00568c60();
    if (199 < iVar5) {
      puVar1 = (undefined4 *)(unaff_ESI + 0x528);
      if (*(int *)(unaff_ESI + 0x528) == -1) {
        FUN_005193b0(auStack_4ac);
        FUN_005194a0(auStack_4ac,0x20,0,0);
        uStack_4a0 = 1;
        uStack_49c = 8;
        uVar6 = FUN_005243b0(auStack_4ac,*(undefined4 *)(unaff_ESI + 0x600),
                             *(undefined4 *)(unaff_ESI + 0x604),0,0,0,0,param_3);
        *puVar1 = uVar6;
        FUN_00580830(uVar6,puVar1);
      }
      puVar2 = (undefined4 *)(unaff_ESI + 0x52c);
      if (*(int *)(unaff_ESI + 0x52c) == -1) {
        FUN_005193b0(auStack_4ac);
        FUN_005194a0(auStack_4ac,0x20,0,0);
        uStack_4a0 = 2;
        uStack_49c = 8;
        uVar6 = FUN_005243b0(auStack_4ac,*(undefined4 *)(unaff_ESI + 0x60c),
                             *(undefined4 *)(unaff_ESI + 0x610),0,0,0,0,param_3);
        *puVar2 = uVar6;
        FUN_00580830(uVar6,puVar2);
      }
      uVar17 = 0x440;
      puVar9 = &uStack_440;
      uVar6 = 0;
      FUN_0056d380();
      uStack_10 = *(undefined4 *)(unaff_ESI + 0x608);
      uStack_4c8 = *(undefined4 *)(unaff_ESI + 0x600);
      uStack_4c4 = *(undefined4 *)(unaff_ESI + 0x604);
      uStack_c = *(undefined4 *)(unaff_ESI + 0x5f8);
      uStack_4d0 = 0;
      uStack_4cc = 0;
      uStack_440 = 0;
      uStack_43c = 1;
      uStack_43f = 1;
      uStack_43e = 8;
      uStack_18 = uStack_4c8;
      uStack_14 = uStack_4c4;
      FUN_00518620(&uStack_4d0,0,0,*puVar1,&uStack_440,0,0,0,0,param_3,puVar9,uVar6,uVar17);
      uStack_10 = *(undefined4 *)(unaff_ESI + 0x614);
      uStack_4c8 = *(undefined4 *)(unaff_ESI + 0x60c);
      uStack_4c4 = *(undefined4 *)(unaff_ESI + 0x610);
      uStack_c = *(undefined4 *)(unaff_ESI + 0x5fc);
      uStack_4d0 = 0;
      uStack_4cc = 0;
      uStack_440 = 0;
      uStack_43c = 2;
      uStack_43f = 2;
      uStack_43e = 8;
      uStack_18 = uStack_4c8;
      uStack_14 = uStack_4c4;
      FUN_00518620(&uStack_4d0,0,0,*puVar2,&uStack_440,0,0,0,0,param_3);
      *(undefined4 *)(unaff_ESI + 0x620) = 1;
    }
  }
  if ((param_1 != 0) && (*(int *)(unaff_ESI + 0x618) == 0)) {
    pbVar11 = *(byte **)(unaff_ESI + 0x600);
    pbStack_540 = *(byte **)(unaff_ESI + 0x5fc);
    puVar9 = *(undefined1 **)(unaff_ESI + 0x510);
    pbVar8 = *(byte **)(unaff_ESI + 0x5f8);
    pbVar12 = (byte *)(*(int *)(unaff_ESI + 0x60c) * 2);
    if ((pbVar11 == pbVar12) && (*(int *)(unaff_ESI + 0x604) == *(int *)(unaff_ESI + 0x610) * 2)) {
      uStack_53c = *(int *)(unaff_ESI + 0x608) * 2 - (int)pbVar11;
      iStack_4f0 = *(int *)(unaff_ESI + 0x614) + *(int *)(unaff_ESI + 0x60c) * -2;
      iVar5 = *(int *)(unaff_ESI + 0x50c);
      uStack_4c0 = *(uint *)(unaff_ESI + 0x600) >> 1;
      uStack_530 = (iVar5 + (int)pbVar11 * -2) * 2;
      pbStack_54c = (byte *)(*(uint *)(unaff_ESI + 0x604) >> 1);
      if (pbStack_54c != (byte *)0x0) {
        do {
          if (uStack_4c0 != 0) {
            uStack_52c = uStack_4c0;
            do {
              iStack_4fc = (&DAT_00a50ef8)[pbStack_540[1]];
              iVar13 = (&DAT_00a512f8)[*pbStack_540] + (&DAT_00a516f8)[pbStack_540[1]];
              pbStack_544 = (byte *)(&DAT_00a51af8)[*pbStack_540];
              iStack_4e4 = (&DAT_00a51ef8)[*pbVar8];
              iStack_4e8 = (&DAT_00a51ef8)[pbVar8[1]];
              uStack_520 = (&DAT_00a51ef8)[pbVar8[*(int *)(unaff_ESI + 0x608)]];
              iVar3 = (&DAT_00a51ef8)[pbVar8[*(int *)(unaff_ESI + 0x608) + 1]];
              puVar9[2] = (&DAT_00a524f8)[iStack_4e4 + iStack_4fc >> 0xe];
              puVar9[1] = (&DAT_00a524f8)[iStack_4e4 + iVar13 >> 0xe];
              *puVar9 = (&DAT_00a524f8)[(int)(pbStack_544 + iStack_4e4) >> 0xe];
              puVar9[3] = 0xff;
              puVar9[6] = (&DAT_00a524f8)[iStack_4e8 + iStack_4fc >> 0xe];
              puVar9[5] = (&DAT_00a524f8)[iStack_4e8 + iVar13 >> 0xe];
              puVar9[4] = (&DAT_00a524f8)[(int)(pbStack_544 + iStack_4e8) >> 0xe];
              puVar9[7] = 0xff;
              puVar9[iVar5 + 2] = (&DAT_00a524f8)[(int)(uStack_520 + iStack_4fc) >> 0xe];
              puVar9[iVar5 + 1] = (&DAT_00a524f8)[(int)(uStack_520 + iVar13) >> 0xe];
              puVar9[iVar5] = (&DAT_00a524f8)[(int)(pbStack_544 + uStack_520) >> 0xe];
              puVar9[iVar5 + 3] = 0xff;
              puVar9[iVar5 + 6] = (&DAT_00a524f8)[iStack_4fc + iVar3 >> 0xe];
              puVar9[iVar5 + 5] = (&DAT_00a524f8)[iVar13 + iVar3 >> 0xe];
              puVar9[iVar5 + 4] = (&DAT_00a524f8)[(int)(pbStack_544 + iVar3) >> 0xe];
              puVar9[iVar5 + 7] = 0xff;
              pbStack_540 = pbStack_540 + 2;
              puVar9 = puVar9 + 8;
              pbVar8 = pbVar8 + 2;
              uStack_52c = uStack_52c - 1;
            } while (uStack_52c != 0);
            uStack_52c = 0;
          }
          pbStack_540 = pbStack_540 + iStack_4f0;
          pbVar8 = pbVar8 + uStack_53c;
          puVar9 = puVar9 + uStack_530;
          pbStack_54c = (byte *)((int)pbStack_54c - 1);
        } while (pbStack_54c != (byte *)0x0);
        pbVar12 = (byte *)0x0;
      }
    }
    else {
      uStack_53c = *(int *)(unaff_ESI + 0x608) - (int)pbVar11;
      uStack_530 = *(int *)(unaff_ESI + 0x50c) + (int)pbVar11 * -4;
      pbStack_54c = (byte *)0x0;
      pbVar12 = pbStack_54c;
      if (*(int *)(unaff_ESI + 0x604) != 0) {
        do {
          uVar10 = 0;
          if (*(int *)(unaff_ESI + 0x600) != 0) {
            iStack_4f0 = (int)pbStack_54c / 2;
            do {
              pbVar11 = (byte *)(*(int *)(unaff_ESI + 0x614) * iStack_4f0 + ((int)uVar10 / 2) * 2 +
                                *(int *)(unaff_ESI + 0x5fc));
              uStack_514 = in_FPUControlWord | 0xc00;
              pbStack_4ec = (byte *)(int)ROUND((float)(int)(pbVar11[1] - 0x80) *
                                               (float)_DAT_00801c40 +
                                               (float)(int)(*pbVar8 - 0x10) * (float)_DAT_00801c48);
              uStack_51c = in_FPUControlWord | 0xc00;
              pbStack_4f4 = (byte *)(int)ROUND(((float)(int)(*pbVar8 - 0x10) * (float)_DAT_00801c48
                                               - (float)(int)(*pbVar11 - 0x80) *
                                                 (float)_DAT_00801c38) -
                                               (float)(int)(pbVar11[1] - 0x80) *
                                               (float)_DAT_00801c30);
              uStack_518 = in_FPUControlWord | 0xc00;
              iStack_4f8 = (int)ROUND((float)(int)(*pbVar8 - 0x10) * (float)_DAT_00801c48 +
                                      (float)(int)(*pbVar11 - 0x80) * (float)_DAT_00801c28);
              uVar4 = (undefined1)iStack_4f8;
              if ((int)pbStack_4ec < 0) {
                pbStack_540 = (byte *)0x0;
              }
              else {
                pbStack_540 = pbStack_4ec;
                if (0xff < (int)pbStack_4ec) {
                  pbStack_540 = (byte *)0xff;
                }
              }
              if ((int)pbStack_4f4 < 0) {
                pbStack_544 = (byte *)0x0;
              }
              else {
                pbStack_544 = pbStack_4f4;
                if (0xff < (int)pbStack_4f4) {
                  pbStack_544 = (byte *)0xff;
                }
              }
              if (iStack_4f8 < 0) {
                uVar4 = 0;
              }
              else if (0xff < iStack_4f8) {
                uVar4 = 0xff;
              }
              puVar9[2] = pbStack_540._0_1_;
              puVar9[1] = pbStack_544._0_1_;
              *puVar9 = uVar4;
              puVar9[3] = 0xff;
              uVar10 = uVar10 + 1;
              puVar9 = puVar9 + 4;
              pbVar8 = pbVar8 + 1;
            } while (uVar10 < *(uint *)(unaff_ESI + 0x600));
          }
          pbStack_54c = pbStack_54c + 1;
          puVar9 = puVar9 + uStack_530;
          pbVar8 = pbVar8 + uStack_53c;
          pbVar12 = pbStack_54c;
        } while (pbStack_54c < *(byte **)(unaff_ESI + 0x604));
      }
    }
    pbStack_54c = pbVar12;
    *(undefined4 *)(unaff_ESI + 0x618) = 1;
  }
  if (local_550 != (int *)0x0) {
    (**(code **)(*local_550 + 8))(local_550);
    local_550 = (int *)0x0;
  }
  if (local_548 != (int *)0x0) {
    (**(code **)(*local_548 + 8))(local_548);
  }
  return 0;
}

