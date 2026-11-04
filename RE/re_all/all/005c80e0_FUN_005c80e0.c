
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005c80e0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,uint param_11,undefined4 param_12)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float *pfVar32;
  float fVar33;
  undefined4 uVar34;
  int iVar35;
  float *pfVar36;
  int iVar37;
  float *pfVar38;
  bool bVar39;
  uint local_94;
  int local_90;
  float local_54;
  float local_50;
  float local_48;
  float local_3c;
  float local_30;
  
  if ((((param_1 == param_5) && (param_3 == param_7)) && (param_2 == param_4)) &&
     (param_6 == param_8)) {
    uVar34 = FUN_005c4530(param_1,param_2,param_7,param_8,(float)param_1,(float)param_2,
                          (float)param_7,(float)param_8,param_9,param_10,param_11,1);
    return uVar34;
  }
  if ((DAT_00ee9a50 == 0) && (DAT_00a380d4 < 1)) {
    uVar34 = FUN_005d0b50((float)param_1,(float)param_2,(float)param_3,(float)param_4,(float)param_5
                          ,(float)param_6,(float)param_7,(float)param_8,param_9,param_10,param_11,
                          param_12);
    return uVar34;
  }
  local_90 = 0;
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  local_94 = param_11 | 0x8002;
  if (*(char *)(*(int *)(param_9 + 0x4c) + 10) != '\0') {
    local_94 = param_11 | 0x18002;
  }
  if (*(char *)(*(int *)(param_9 + 0x4c) + 0x12) != '\0') {
    local_94 = local_94 | 0x20000;
  }
  if (DAT_00ef7314 != *(int *)(**(int **)(param_9 + 0x100) + 4)) {
    FUN_005bc5b0(*(undefined4 *)(**(int **)(param_9 + 0x100) + 4),
                 *(undefined4 *)(**(int **)(param_9 + 0x100) + 8));
  }
  if (((DAT_00a3d360 != 0) || (DAT_00ef72cc != 0)) || (DAT_00ef72c8 != local_94)) {
    FUN_005bcf50();
  }
  fVar33 = DAT_00f07344;
  fVar31 = DAT_00a380b8;
  fVar1 = *(float *)(param_9 + 0x68);
  fVar2 = *(float *)(param_9 + 0x6c);
  fVar9 = (float)(param_3 - param_1) / fVar1;
  fVar11 = (float)(param_5 - param_1) / fVar2;
  fVar10 = (float)(param_6 - param_2) / fVar2;
  fVar8 = (float)(param_4 - param_2) / fVar1;
  fVar13 = (float)(param_5 - param_7) / -fVar1;
  fVar15 = (float)(param_3 - param_7) / -fVar2;
  iVar37 = 0;
  fVar14 = (float)(param_4 - param_8) / -fVar2;
  iVar35 = *(int *)(param_9 + 0x88);
  fVar12 = (float)(param_6 - param_8) / -fVar1;
  fVar16 = (float)param_1;
  fVar17 = (float)param_2;
  fVar18 = (float)param_7;
  fVar19 = (float)param_8;
  bVar39 = false;
  if ((param_10 != 0) && (bVar39 = *(int *)(param_10 + 0x88) != iVar35, param_10 != 0)) {
    local_90 = param_10 + 0x8c;
  }
  if (DAT_00f0733c == 1) {
    pfVar36 = (float *)(param_9 + 0xc0);
    while( true ) {
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      if (((DAT_00f07338 != 0) || (DAT_00f07340 != 4)) ||
         (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <=
          DAT_00f07334 + 6)) {
        FUN_005c3310(0,0);
        DAT_00f07340 = 4;
      }
      pfVar38 = DAT_00f0732c;
      DAT_00f0732c[4] = fVar33;
      pfVar38[0xb] = fVar33;
      pfVar38[0x12] = fVar33;
      pfVar38[0x19] = fVar33;
      pfVar38[0x20] = fVar33;
      pfVar38[0x27] = fVar33;
      if (*(char *)(pfVar36 + 0xf) == '\0') {
        fVar3 = pfVar36[-1] - fVar1;
        local_54 = fVar3 * fVar13 + (*pfVar36 - fVar2) * fVar15 + fVar18;
        fVar3 = (*pfVar36 - fVar2) * fVar14 + fVar3 * fVar12 + fVar19;
      }
      else {
        local_54 = *pfVar36 * fVar11 + pfVar36[-1] * fVar9 + fVar16;
        fVar3 = *pfVar36 * fVar10 + pfVar36[-1] * fVar8 + fVar17;
      }
      if (*(char *)((int)pfVar36 + 0x3d) == '\0') {
        local_48 = (pfVar36[3] - fVar1) * fVar13 + (pfVar36[4] - fVar2) * fVar15 + fVar18;
        fVar25 = (pfVar36[4] - fVar2) * fVar14 + (pfVar36[3] - fVar1) * fVar12 + fVar19;
      }
      else {
        local_48 = pfVar36[3] * fVar9 + pfVar36[4] * fVar11 + fVar16;
        fVar25 = pfVar36[4] * fVar10 + pfVar36[3] * fVar8 + fVar17;
      }
      if (*(char *)((int)pfVar36 + 0x3e) == '\0') {
        local_3c = (pfVar36[7] - fVar1) * fVar13 + (pfVar36[8] - fVar2) * fVar15 + fVar18;
        fVar24 = (pfVar36[8] - fVar2) * fVar14 + (pfVar36[7] - fVar1) * fVar12 + fVar19;
      }
      else {
        local_3c = pfVar36[7] * fVar9 + pfVar36[8] * fVar11 + fVar16;
        fVar24 = pfVar36[8] * fVar10 + pfVar36[7] * fVar8 + fVar17;
      }
      if (*(char *)((int)pfVar36 + 0x3f) == '\0') {
        local_30 = fVar18 + (pfVar36[0xc] - fVar2) * fVar15 + (pfVar36[0xb] - fVar1) * fVar13;
        fVar23 = fVar12 * (pfVar36[0xb] - fVar1) + (pfVar36[0xc] - fVar2) * fVar14 + fVar19;
      }
      else {
        local_30 = fVar9 * pfVar36[0xb] + fVar11 * pfVar36[0xc] + fVar16;
        fVar23 = fVar10 * pfVar36[0xc] + fVar8 * pfVar36[0xb] + fVar17;
      }
      fVar22 = (fVar24 - fVar3) * (local_48 - local_54) - (fVar25 - fVar3) * (local_3c - local_54);
      bVar39 = NAN(_DAT_007d5344);
      bVar5 = fVar22 < _DAT_007d5344;
      bVar6 = fVar22 == _DAT_007d5344;
      *pfVar38 = local_54;
      pfVar38[1] = fVar3;
      if ((NAN(fVar22) || bVar39) || bVar5 == bVar6) {
        pfVar38[7] = local_48;
        pfVar38[8] = fVar25;
        pfVar38[0xe] = local_3c;
        pfVar38[0xf] = fVar24;
        pfVar38[0x15] = local_30;
        pfVar38[0x16] = fVar23;
        pfVar38[0x1c] = local_3c;
        pfVar38[0x1d] = fVar24;
        pfVar38[0x23] = local_48;
        pfVar38[0x24] = fVar25;
        pfVar38[5] = pfVar36[1];
        pfVar38[6] = pfVar36[2];
        pfVar38[0xc] = pfVar36[5];
        pfVar38[0xd] = pfVar36[6];
        pfVar38[0x13] = pfVar36[9];
        pfVar38[0x14] = pfVar36[10];
        pfVar38[0x1a] = pfVar36[0xd];
        pfVar38[0x1b] = pfVar36[0xe];
        pfVar38[0x21] = pfVar36[9];
        pfVar38[0x22] = pfVar36[10];
        pfVar38[0x28] = pfVar36[5];
        fVar3 = pfVar36[6];
      }
      else {
        pfVar38[7] = local_3c;
        pfVar38[8] = fVar24;
        pfVar38[0xe] = local_48;
        pfVar38[0xf] = fVar25;
        pfVar38[0x15] = local_30;
        pfVar38[0x16] = fVar23;
        pfVar38[0x1c] = local_48;
        pfVar38[0x1d] = fVar25;
        pfVar38[0x23] = local_3c;
        pfVar38[0x24] = fVar24;
        pfVar38[5] = pfVar36[1];
        pfVar38[6] = pfVar36[2];
        pfVar38[0xc] = pfVar36[9];
        pfVar38[0xd] = pfVar36[10];
        pfVar38[0x13] = pfVar36[5];
        pfVar38[0x14] = pfVar36[6];
        pfVar38[0x1a] = pfVar36[0xd];
        pfVar38[0x1b] = pfVar36[0xe];
        pfVar38[0x21] = pfVar36[5];
        pfVar38[0x22] = pfVar36[6];
        pfVar38[0x28] = pfVar36[9];
        fVar3 = pfVar36[10];
      }
      pfVar38[0x29] = fVar3;
      pfVar38[2] = fVar31;
      pfVar38[9] = fVar31;
      pfVar38[3] = 1.0;
      pfVar38[0x10] = fVar31;
      pfVar38[10] = 1.0;
      pfVar38[0x17] = fVar31;
      pfVar38[0x11] = 1.0;
      pfVar38[0x1e] = fVar31;
      pfVar38[0x18] = 1.0;
      pfVar38[0x25] = fVar31;
      pfVar38[0x1f] = 1.0;
      iVar37 = iVar37 + 1;
      pfVar38[0x26] = 1.0;
      DAT_00f0732c = DAT_00f0732c + 0x2a;
      DAT_00f07334 = DAT_00f07334 + 6;
      if (iVar35 <= iVar37) break;
      pfVar38 = pfVar36 + 0x2e;
      pfVar36 = pfVar36 + 0x1e;
      FUN_005bc5b0(*(undefined4 *)(*(int *)*pfVar38 + 4),*(undefined4 *)(*(int *)*pfVar38 + 8));
      FUN_005bbac0();
    }
  }
  else if ((DAT_00f0733c == 2) && (0 < iVar35)) {
    pfVar38 = (float *)(local_90 + 0x34);
    pfVar36 = (float *)(param_9 + 0xc0);
    do {
      FUN_005bc5b0(*(undefined4 *)(*(int *)pfVar36[0x10] + 4),
                   *(undefined4 *)(*(int *)pfVar36[0x10] + 8));
      piVar4 = (int *)pfVar38[0x10];
      FUN_005bc640(*(undefined4 *)(*piVar4 + 4),*(undefined4 *)(*piVar4 + 8),piVar4[5],piVar4[6]);
      if (DAT_00ef72e8 != 0) {
        FUN_005bbac0();
      }
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      if (((DAT_00f07338 != 0) || (DAT_00f07340 != 4)) ||
         (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <=
          DAT_00f07334 + 6)) {
        FUN_005c3310(0,0);
        DAT_00f07340 = 4;
      }
      pfVar32 = DAT_00f0732c;
      DAT_00f0732c[4] = fVar33;
      pfVar32[0xe] = fVar33;
      pfVar32[0x18] = fVar33;
      pfVar32[0x22] = fVar33;
      pfVar32[0x2c] = fVar33;
      pfVar32[0x36] = fVar33;
      if (*(char *)(pfVar36 + 0xf) == '\0') {
        local_54 = fVar18 + fVar15 * (*pfVar36 - fVar2) + fVar13 * (pfVar36[-1] - fVar1);
        local_50 = fVar19 + fVar12 * (pfVar36[-1] - fVar1) + fVar14 * (*pfVar36 - fVar2);
      }
      else {
        local_54 = fVar9 * pfVar36[-1] + *pfVar36 * fVar11 + fVar16;
        local_50 = fVar8 * pfVar36[-1] + *pfVar36 * fVar10 + fVar17;
      }
      fVar3 = (float)_DAT_00a380e0;
      fVar25 = ((pfVar36[-1] - pfVar38[-1]) + fVar3) * _DAT_00ef730c;
      fVar24 = (float)_DAT_00a380e4;
      fVar23 = ((*pfVar36 - *pfVar38) + fVar24) * _DAT_00ef7310;
      if (*(char *)((int)pfVar36 + 0x3d) == '\0') {
        local_48 = (pfVar36[3] - fVar1) * fVar13 + (pfVar36[4] - fVar2) * fVar15 + fVar18;
        fVar22 = (pfVar36[4] - fVar2) * fVar14 + (pfVar36[3] - fVar1) * fVar12 + fVar19;
      }
      else {
        local_48 = pfVar36[3] * fVar9 + pfVar36[4] * fVar11 + fVar16;
        fVar22 = pfVar36[4] * fVar10 + pfVar36[3] * fVar8 + fVar17;
      }
      fVar26 = ((pfVar36[3] - pfVar38[-1]) + fVar3) * _DAT_00ef730c;
      fVar27 = ((pfVar36[4] - *pfVar38) + fVar24) * _DAT_00ef7310;
      if (*(char *)((int)pfVar36 + 0x3e) == '\0') {
        local_3c = (pfVar36[7] - fVar1) * fVar13 + (pfVar36[8] - fVar2) * fVar15 + fVar18;
        fVar21 = (pfVar36[8] - fVar2) * fVar14 + (pfVar36[7] - fVar1) * fVar12 + fVar19;
      }
      else {
        local_3c = pfVar36[7] * fVar9 + pfVar36[8] * fVar11 + fVar16;
        fVar21 = pfVar36[8] * fVar10 + pfVar36[7] * fVar8 + fVar17;
      }
      fVar28 = ((pfVar36[7] - pfVar38[-1]) + fVar3) * _DAT_00ef730c;
      fVar29 = ((pfVar36[8] - *pfVar38) + fVar24) * _DAT_00ef7310;
      if (*(char *)((int)pfVar36 + 0x3f) == '\0') {
        local_30 = (pfVar36[0xc] - fVar2) * fVar15 + (pfVar36[0xb] - fVar1) * fVar13 + fVar18;
        fVar20 = (pfVar36[0xb] - fVar1) * fVar12 + fVar14 * (pfVar36[0xc] - fVar2) + fVar19;
      }
      else {
        local_30 = pfVar36[0xb] * fVar9 + pfVar36[0xc] * fVar11 + fVar16;
        fVar20 = pfVar36[0xc] * fVar10 + pfVar36[0xb] * fVar8 + fVar17;
      }
      fVar3 = ((pfVar36[0xb] - pfVar38[-1]) + fVar3) * _DAT_00ef730c;
      fVar24 = ((pfVar36[0xc] - *pfVar38) + fVar24) * _DAT_00ef7310;
      fVar30 = (fVar21 - local_50) * (local_48 - local_54) -
               (fVar22 - local_50) * (local_3c - local_54);
      bVar5 = NAN(_DAT_007d5344);
      bVar6 = fVar30 < _DAT_007d5344;
      bVar7 = fVar30 == _DAT_007d5344;
      *pfVar32 = local_54;
      pfVar32[1] = local_50;
      if ((NAN(fVar30) || bVar5) || bVar6 == bVar7) {
        pfVar32[10] = local_48;
        pfVar32[0xb] = fVar22;
        pfVar32[0x14] = local_3c;
        pfVar32[0x15] = fVar21;
        pfVar32[0x1e] = local_30;
        pfVar32[0x1f] = fVar20;
        pfVar32[0x28] = local_3c;
        pfVar32[0x29] = fVar21;
        pfVar32[0x32] = local_48;
        pfVar32[0x33] = fVar22;
        if (DAT_00a380e8 == 1) {
          pfVar32[6] = _DAT_00ef730c * ((local_54 - pfVar38[-1]) - (float)_DAT_00a380e0);
          pfVar32[7] = ((local_50 - *pfVar38) - (float)_DAT_00a380e4) * _DAT_00ef7310;
          pfVar32[0x10] = ((local_48 - pfVar38[-1]) - (float)_DAT_00a380e0) * _DAT_00ef730c;
          pfVar32[0x11] = ((fVar22 - *pfVar38) - (float)_DAT_00a380e4) * _DAT_00ef7310;
          pfVar32[0x1a] = ((local_3c - pfVar38[-1]) - (float)_DAT_00a380e0) * _DAT_00ef730c;
          pfVar32[0x1b] = ((fVar21 - *pfVar38) - (float)_DAT_00a380e4) * _DAT_00ef7310;
          pfVar32[0x24] = ((local_30 - pfVar38[-1]) - (float)_DAT_00a380e0) * _DAT_00ef730c;
          pfVar32[0x25] = _DAT_00ef7310 * ((fVar20 - *pfVar38) - (float)_DAT_00a380e4);
          pfVar32[0x2e] = _DAT_00ef730c * ((local_3c - pfVar38[-1]) - (float)_DAT_00a380e0);
          pfVar32[0x2f] = _DAT_00ef7310 * ((fVar21 - *pfVar38) - (float)_DAT_00a380e4);
          pfVar32[0x38] = ((local_48 - pfVar38[-1]) - (float)_DAT_00a380e0) * _DAT_00ef730c;
          fVar27 = ((fVar22 - *pfVar38) - (float)_DAT_00a380e4) * _DAT_00ef7310;
        }
        else {
          pfVar32[6] = fVar25;
          pfVar32[7] = fVar23;
          pfVar32[0x10] = fVar26;
          pfVar32[0x11] = fVar27;
          pfVar32[0x1a] = fVar28;
          pfVar32[0x1b] = fVar29;
          pfVar32[0x24] = fVar3;
          pfVar32[0x25] = fVar24;
          pfVar32[0x2e] = fVar28;
          pfVar32[0x2f] = fVar29;
          pfVar32[0x38] = fVar26;
        }
        pfVar32[0x39] = fVar27;
        pfVar32[8] = pfVar36[1];
        pfVar32[9] = pfVar36[2];
        pfVar32[0x12] = pfVar36[5];
        pfVar32[0x13] = pfVar36[6];
        pfVar32[0x1c] = pfVar36[9];
        pfVar32[0x1d] = pfVar36[10];
        pfVar32[0x26] = pfVar36[0xd];
        pfVar32[0x27] = pfVar36[0xe];
        pfVar32[0x30] = pfVar36[9];
        pfVar32[0x31] = pfVar36[10];
        pfVar32[0x3a] = pfVar36[5];
        fVar3 = pfVar36[6];
      }
      else {
        pfVar32[10] = local_3c;
        pfVar32[0xb] = fVar21;
        pfVar32[0x14] = local_48;
        pfVar32[0x15] = fVar22;
        pfVar32[0x1e] = local_30;
        pfVar32[0x1f] = fVar20;
        pfVar32[0x28] = local_48;
        pfVar32[0x29] = fVar22;
        pfVar32[0x32] = local_3c;
        pfVar32[0x33] = fVar21;
        if (DAT_00a380e8 == 1) {
          pfVar32[6] = _DAT_00ef730c * ((local_54 - pfVar38[-1]) - (float)_DAT_00a380e0);
          pfVar32[7] = ((local_50 - *pfVar38) - (float)_DAT_00a380e4) * _DAT_00ef7310;
          pfVar32[0x10] = ((local_3c - pfVar38[-1]) - (float)_DAT_00a380e0) * _DAT_00ef730c;
          pfVar32[0x11] = ((fVar21 - *pfVar38) - (float)_DAT_00a380e4) * _DAT_00ef7310;
          pfVar32[0x1a] = ((local_48 - pfVar38[-1]) - (float)_DAT_00a380e0) * _DAT_00ef730c;
          pfVar32[0x1b] = ((fVar22 - *pfVar38) - (float)_DAT_00a380e4) * _DAT_00ef7310;
          pfVar32[0x24] = ((local_30 - pfVar38[-1]) - (float)_DAT_00a380e0) * _DAT_00ef730c;
          pfVar32[0x25] = _DAT_00ef7310 * ((fVar20 - *pfVar38) - (float)_DAT_00a380e4);
          pfVar32[0x2e] = _DAT_00ef730c * ((local_48 - pfVar38[-1]) - (float)_DAT_00a380e0);
          pfVar32[0x2f] = _DAT_00ef7310 * ((fVar22 - *pfVar38) - (float)_DAT_00a380e4);
          pfVar32[0x38] = ((local_3c - pfVar38[-1]) - (float)_DAT_00a380e0) * _DAT_00ef730c;
          fVar29 = ((fVar21 - *pfVar38) - (float)_DAT_00a380e4) * _DAT_00ef7310;
        }
        else {
          pfVar32[6] = fVar25;
          pfVar32[7] = fVar23;
          pfVar32[0x10] = fVar28;
          pfVar32[0x11] = fVar29;
          pfVar32[0x1a] = fVar26;
          pfVar32[0x1b] = fVar27;
          pfVar32[0x24] = fVar3;
          pfVar32[0x25] = fVar24;
          pfVar32[0x2e] = fVar26;
          pfVar32[0x2f] = fVar27;
          pfVar32[0x38] = fVar28;
        }
        pfVar32[0x39] = fVar29;
        pfVar32[8] = pfVar36[1];
        pfVar32[9] = pfVar36[2];
        pfVar32[0x12] = pfVar36[9];
        pfVar32[0x13] = pfVar36[10];
        pfVar32[0x1c] = pfVar36[5];
        pfVar32[0x1d] = pfVar36[6];
        pfVar32[0x26] = pfVar36[0xd];
        pfVar32[0x27] = pfVar36[0xe];
        pfVar32[0x30] = pfVar36[5];
        pfVar32[0x31] = pfVar36[6];
        pfVar32[0x3a] = pfVar36[9];
        fVar3 = pfVar36[10];
      }
      pfVar32[0x3b] = fVar3;
      pfVar32[2] = fVar31;
      pfVar32[0xc] = fVar31;
      pfVar32[3] = 1.0;
      pfVar32[0x16] = fVar31;
      pfVar32[0xd] = 1.0;
      pfVar32[0x20] = fVar31;
      pfVar32[0x17] = 1.0;
      pfVar32[0x2a] = fVar31;
      pfVar32[0x21] = 1.0;
      pfVar32[0x34] = fVar31;
      pfVar32[0x2b] = 1.0;
      pfVar32[0x35] = 1.0;
      DAT_00f0732c = DAT_00f0732c + 0x3c;
      DAT_00f07334 = DAT_00f07334 + 6;
      if (!bVar39) {
        pfVar38 = pfVar38 + 0x1e;
      }
      pfVar36 = pfVar36 + 0x1e;
      iVar35 = iVar35 + -1;
    } while (iVar35 != 0);
  }
  return 0;
}

