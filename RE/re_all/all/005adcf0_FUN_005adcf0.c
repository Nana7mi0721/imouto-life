
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005adcf0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,uint param_11,undefined4 param_12)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
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
  uint uVar36;
  float *pfVar37;
  float *pfVar38;
  bool bVar39;
  int local_a4;
  uint local_98;
  int local_90;
  float local_54;
  float local_50;
  float local_48;
  float local_3c;
  float local_30;
  
  if ((((param_1 == param_5) && (param_3 == param_7)) && (param_2 == param_4)) &&
     (param_6 == param_8)) {
    uVar34 = FUN_005a9a90(param_1,param_2,param_7,param_8,(float)param_1,(float)param_2,
                          (float)param_7,(float)param_8,param_9,param_10,param_11,1);
    return uVar34;
  }
  if ((DAT_00ddb374 == 0) && (DAT_00a380d4 < 1)) {
    fVar1 = (float)_DAT_00804a60;
    uVar34 = FUN_005b56c0((float)param_1 - fVar1,(float)param_2 - fVar1,(float)param_3 - fVar1,
                          (float)param_4 - fVar1,(float)param_5 - fVar1,(float)param_6 - fVar1,
                          (float)param_7 - fVar1,(float)param_8 - fVar1,param_9,param_10,param_11,
                          param_12);
    return uVar34;
  }
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (((DAT_00e79688 == 0) && (iVar35 = FUN_005d35f0(), iVar35 != 0)) && (DAT_00e79688 != 1)) {
    FUN_005d3930();
    DAT_00e79688 = 1;
    DAT_00e399fc = 0;
  }
  local_98 = param_11 | 0x8002;
  if (*(char *)(*(int *)(param_9 + 0x4c) + 10) != '\0') {
    local_98 = param_11 | 0x18002;
  }
  if (*(char *)(*(int *)(param_9 + 0x4c) + 0x12) != '\0') {
    local_98 = local_98 | 0x20000;
  }
  if (DAT_00e39a4c != *(int *)**(undefined4 **)(param_9 + 0x100)) {
    FUN_0059bcf0(*(int *)**(undefined4 **)(param_9 + 0x100));
  }
  if (((DAT_00a3d360 != 0) || (DAT_00e39a00 != 0)) || (DAT_00e399fc != local_98)) {
    FUN_005a7f60();
  }
  fVar33 = DAT_00e79684;
  fVar31 = DAT_00a380b8;
  fVar1 = *(float *)(param_9 + 0x68);
  fVar2 = *(float *)(param_9 + 0x6c);
  fVar9 = (float)(param_3 - param_1) / fVar1;
  fVar11 = (float)(param_5 - param_1) / fVar2;
  fVar10 = (float)(param_6 - param_2) / fVar2;
  fVar8 = (float)(param_4 - param_2) / fVar1;
  fVar13 = (float)(param_5 - param_7) / -fVar1;
  fVar15 = (float)(param_3 - param_7) / -fVar2;
  fVar14 = (float)(param_4 - param_8) / -fVar2;
  fVar12 = (float)(param_6 - param_8) / -fVar1;
  fVar23 = (float)_DAT_00804a60;
  fVar22 = (float)param_1 - fVar23;
  fVar24 = (float)param_2 - fVar23;
  fVar25 = (float)param_7 - fVar23;
  fVar23 = (float)param_8 - fVar23;
  local_a4 = *(int *)(param_9 + 0x88);
  bVar39 = false;
  if ((param_10 == 0) || (bVar39 = *(int *)(param_10 + 0x88) != local_a4, param_10 == 0)) {
    param_10 = 0;
  }
  else {
    param_10 = param_10 + 0x8c;
  }
  if (DAT_00e7967c == 1) {
    local_90 = 0;
    pfVar38 = (float *)(param_9 + 0xc0);
    while( true ) {
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
         (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
        if (DAT_00e79678 != 0) {
          FUN_005a7ce0();
          if (DAT_00e79680 == 4) {
            uVar36 = (int)DAT_00e79678 / 3;
          }
          else if (DAT_00e79680 == 2) {
            uVar36 = (int)DAT_00e79678 / 2;
          }
          else if (DAT_00e79680 == 6) {
            uVar36 = DAT_00e79678 - 2;
          }
          else if (DAT_00e79680 == 5) {
            uVar36 = DAT_00e79678 - 2;
          }
          else if (DAT_00e79680 == 3) {
            uVar36 = DAT_00e79678 - 1;
          }
          else {
            uVar36 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
          }
          iVar35 = DAT_00e7967c + DAT_00e79674 * 3;
          FUN_005d3b40(DAT_00e79680,uVar36,*(undefined4 *)(&DAT_00e39a5c + iVar35 * 4),
                       *(undefined4 *)(&DAT_007da3e8 + iVar35 * 4));
          DAT_00a37de4 = DAT_00a37de4 + 1;
        }
        DAT_00e79678 = 0;
        DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
        DAT_00e79674 = 0;
        DAT_00e79680 = 4;
      }
      pfVar37 = DAT_00e39a58;
      DAT_00e39a58[4] = fVar33;
      pfVar37[0xb] = fVar33;
      pfVar37[0x12] = fVar33;
      pfVar37[0x19] = fVar33;
      pfVar37[0x20] = fVar33;
      pfVar37[0x27] = fVar33;
      if (*(char *)(pfVar38 + 0xf) == '\0') {
        fVar3 = pfVar38[-1] - fVar1;
        local_54 = fVar3 * fVar13 + (*pfVar38 - fVar2) * fVar15 + fVar25;
        fVar3 = (*pfVar38 - fVar2) * fVar14 + fVar3 * fVar12 + fVar23;
      }
      else {
        local_54 = *pfVar38 * fVar11 + pfVar38[-1] * fVar9 + fVar22;
        fVar3 = *pfVar38 * fVar10 + pfVar38[-1] * fVar8 + fVar24;
      }
      if (*(char *)((int)pfVar38 + 0x3d) == '\0') {
        local_48 = (pfVar38[3] - fVar1) * fVar13 + (pfVar38[4] - fVar2) * fVar15 + fVar25;
        fVar21 = (pfVar38[4] - fVar2) * fVar14 + (pfVar38[3] - fVar1) * fVar12 + fVar23;
      }
      else {
        local_48 = pfVar38[3] * fVar9 + pfVar38[4] * fVar11 + fVar22;
        fVar21 = pfVar38[4] * fVar10 + pfVar38[3] * fVar8 + fVar24;
      }
      if (*(char *)((int)pfVar38 + 0x3e) == '\0') {
        local_3c = (pfVar38[7] - fVar1) * fVar13 + (pfVar38[8] - fVar2) * fVar15 + fVar25;
        fVar20 = (pfVar38[8] - fVar2) * fVar14 + (pfVar38[7] - fVar1) * fVar12 + fVar23;
      }
      else {
        local_3c = pfVar38[7] * fVar9 + pfVar38[8] * fVar11 + fVar22;
        fVar20 = pfVar38[8] * fVar10 + pfVar38[7] * fVar8 + fVar24;
      }
      if (*(char *)((int)pfVar38 + 0x3f) == '\0') {
        local_30 = fVar25 + (pfVar38[0xc] - fVar2) * fVar15 + (pfVar38[0xb] - fVar1) * fVar13;
        fVar19 = fVar12 * (pfVar38[0xb] - fVar1) + (pfVar38[0xc] - fVar2) * fVar14 + fVar23;
      }
      else {
        local_30 = fVar9 * pfVar38[0xb] + fVar11 * pfVar38[0xc] + fVar22;
        fVar19 = fVar10 * pfVar38[0xc] + fVar8 * pfVar38[0xb] + fVar24;
      }
      fVar18 = (fVar20 - fVar3) * (local_48 - local_54) - (fVar21 - fVar3) * (local_3c - local_54);
      bVar39 = NAN(_DAT_007d5344);
      bVar5 = fVar18 < _DAT_007d5344;
      bVar6 = fVar18 == _DAT_007d5344;
      *pfVar37 = local_54;
      pfVar37[1] = fVar3;
      if ((NAN(fVar18) || bVar39) || bVar5 == bVar6) {
        pfVar37[7] = local_48;
        pfVar37[8] = fVar21;
        pfVar37[0xe] = local_3c;
        pfVar37[0xf] = fVar20;
        pfVar37[0x15] = local_30;
        pfVar37[0x16] = fVar19;
        pfVar37[0x1c] = local_3c;
        pfVar37[0x1d] = fVar20;
        pfVar37[0x23] = local_48;
        pfVar37[0x24] = fVar21;
        pfVar37[5] = pfVar38[1];
        pfVar37[6] = pfVar38[2];
        pfVar37[0xc] = pfVar38[5];
        pfVar37[0xd] = pfVar38[6];
        pfVar37[0x13] = pfVar38[9];
        pfVar37[0x14] = pfVar38[10];
        pfVar37[0x1a] = pfVar38[0xd];
        pfVar37[0x1b] = pfVar38[0xe];
        pfVar37[0x21] = pfVar38[9];
        pfVar37[0x22] = pfVar38[10];
        pfVar37[0x28] = pfVar38[5];
        fVar3 = pfVar38[6];
      }
      else {
        pfVar37[7] = local_3c;
        pfVar37[8] = fVar20;
        pfVar37[0xe] = local_48;
        pfVar37[0xf] = fVar21;
        pfVar37[0x15] = local_30;
        pfVar37[0x16] = fVar19;
        pfVar37[0x1c] = local_48;
        pfVar37[0x1d] = fVar21;
        pfVar37[0x23] = local_3c;
        pfVar37[0x24] = fVar20;
        pfVar37[5] = pfVar38[1];
        pfVar37[6] = pfVar38[2];
        pfVar37[0xc] = pfVar38[9];
        pfVar37[0xd] = pfVar38[10];
        pfVar37[0x13] = pfVar38[5];
        pfVar37[0x14] = pfVar38[6];
        pfVar37[0x1a] = pfVar38[0xd];
        pfVar37[0x1b] = pfVar38[0xe];
        pfVar37[0x21] = pfVar38[5];
        pfVar37[0x22] = pfVar38[6];
        pfVar37[0x28] = pfVar38[9];
        fVar3 = pfVar38[10];
      }
      pfVar37[0x29] = fVar3;
      pfVar37[2] = fVar31;
      pfVar37[9] = fVar31;
      pfVar37[0x10] = fVar31;
      pfVar37[0x17] = fVar31;
      pfVar37[0x1e] = fVar31;
      pfVar37[0x25] = fVar31;
      DAT_00e39a58 = DAT_00e39a58 + 0x2a;
      DAT_00e79678 = DAT_00e79678 + 6;
      local_90 = local_90 + 1;
      if (local_a4 <= local_90) break;
      pfVar37 = pfVar38 + 0x2e;
      pfVar38 = pfVar38 + 0x1e;
      FUN_0059bcf0(**(undefined4 **)*pfVar37);
      FUN_005a0d80(0,0,1,1);
    }
  }
  else if ((DAT_00e7967c == 2) && (0 < local_a4)) {
    pfVar38 = (float *)(param_10 + 0x34);
    pfVar37 = (float *)(param_9 + 0xc0);
    do {
      FUN_0059bcf0(**(undefined4 **)pfVar37[0x10]);
      puVar4 = (undefined4 *)pfVar38[0x10];
      FUN_0059bd80(*(undefined4 *)*puVar4,puVar4[5],puVar4[6]);
      if (DAT_00e39a1c != 0) {
        FUN_005a0d80(0,0,1,1);
      }
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
         (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
        if (DAT_00e79678 != 0) {
          FUN_005a7ce0();
          if (DAT_00e79680 == 4) {
            uVar36 = (int)DAT_00e79678 / 3;
          }
          else if (DAT_00e79680 == 2) {
            uVar36 = (int)DAT_00e79678 / 2;
          }
          else if (DAT_00e79680 == 6) {
            uVar36 = DAT_00e79678 - 2;
          }
          else if (DAT_00e79680 == 5) {
            uVar36 = DAT_00e79678 - 2;
          }
          else if (DAT_00e79680 == 3) {
            uVar36 = DAT_00e79678 - 1;
          }
          else {
            uVar36 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
          }
          iVar35 = DAT_00e7967c + DAT_00e79674 * 3;
          FUN_005d3b40(DAT_00e79680,uVar36,*(undefined4 *)(&DAT_00e39a5c + iVar35 * 4),
                       *(undefined4 *)(&DAT_007da3e8 + iVar35 * 4));
          DAT_00a37de4 = DAT_00a37de4 + 1;
        }
        DAT_00e79678 = 0;
        DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
        DAT_00e79674 = 0;
        DAT_00e79680 = 4;
      }
      pfVar32 = DAT_00e39a58;
      DAT_00e39a58[4] = fVar33;
      pfVar32[0xe] = fVar33;
      pfVar32[0x18] = fVar33;
      pfVar32[0x22] = fVar33;
      pfVar32[0x2c] = fVar33;
      pfVar32[0x36] = fVar33;
      if (*(char *)(pfVar37 + 0xf) == '\0') {
        fVar3 = pfVar37[-1] - fVar1;
        local_54 = fVar25 + fVar15 * (*pfVar37 - fVar2) + fVar13 * fVar3;
        local_50 = fVar23 + fVar12 * fVar3 + fVar14 * (*pfVar37 - fVar2);
      }
      else {
        local_54 = fVar11 * *pfVar37 + pfVar37[-1] * fVar9 + fVar22;
        local_50 = fVar10 * *pfVar37 + pfVar37[-1] * fVar8 + fVar24;
      }
      fVar3 = (float)_DAT_00a380e0;
      fVar21 = ((pfVar37[-1] - pfVar38[-1]) + fVar3) * _DAT_00e39a44;
      fVar20 = (float)_DAT_00a380e4;
      fVar19 = ((*pfVar37 - *pfVar38) + fVar20) * _DAT_00e39a48;
      if (*(char *)((int)pfVar37 + 0x3d) == '\0') {
        local_48 = (pfVar37[3] - fVar1) * fVar13 + (pfVar37[4] - fVar2) * fVar15 + fVar25;
        fVar18 = (pfVar37[4] - fVar2) * fVar14 + (pfVar37[3] - fVar1) * fVar12 + fVar23;
      }
      else {
        local_48 = fVar9 * pfVar37[3] + fVar11 * pfVar37[4] + fVar22;
        fVar18 = fVar10 * pfVar37[4] + fVar8 * pfVar37[3] + fVar24;
      }
      fVar26 = ((pfVar37[3] - pfVar38[-1]) + fVar3) * _DAT_00e39a44;
      fVar27 = ((pfVar37[4] - *pfVar38) + fVar20) * _DAT_00e39a48;
      if (*(char *)((int)pfVar37 + 0x3e) == '\0') {
        local_3c = (pfVar37[7] - fVar1) * fVar13 + (pfVar37[8] - fVar2) * fVar15 + fVar25;
        fVar17 = (pfVar37[8] - fVar2) * fVar14 + (pfVar37[7] - fVar1) * fVar12 + fVar23;
      }
      else {
        local_3c = pfVar37[7] * fVar9 + pfVar37[8] * fVar11 + fVar22;
        fVar17 = pfVar37[8] * fVar10 + pfVar37[7] * fVar8 + fVar24;
      }
      fVar28 = ((pfVar37[7] - pfVar38[-1]) + fVar3) * _DAT_00e39a44;
      fVar29 = ((pfVar37[8] - *pfVar38) + fVar20) * _DAT_00e39a48;
      if (*(char *)((int)pfVar37 + 0x3f) == '\0') {
        local_30 = (pfVar37[0xc] - fVar2) * fVar15 + (pfVar37[0xb] - fVar1) * fVar13 + fVar25;
        fVar16 = (pfVar37[0xb] - fVar1) * fVar12 + fVar14 * (pfVar37[0xc] - fVar2) + fVar23;
      }
      else {
        local_30 = pfVar37[0xb] * fVar9 + pfVar37[0xc] * fVar11 + fVar22;
        fVar16 = pfVar37[0xc] * fVar10 + pfVar37[0xb] * fVar8 + fVar24;
      }
      fVar3 = ((pfVar37[0xb] - pfVar38[-1]) + fVar3) * _DAT_00e39a44;
      fVar20 = ((pfVar37[0xc] - *pfVar38) + fVar20) * _DAT_00e39a48;
      fVar30 = (fVar17 - local_50) * (local_48 - local_54) -
               (fVar18 - local_50) * (local_3c - local_54);
      bVar5 = NAN(_DAT_007d5344);
      bVar6 = fVar30 < _DAT_007d5344;
      bVar7 = fVar30 == _DAT_007d5344;
      *pfVar32 = local_54;
      pfVar32[1] = local_50;
      if ((NAN(fVar30) || bVar5) || bVar6 == bVar7) {
        pfVar32[10] = local_48;
        pfVar32[0xb] = fVar18;
        pfVar32[0x14] = local_3c;
        pfVar32[0x15] = fVar17;
        pfVar32[0x1e] = local_30;
        pfVar32[0x1f] = fVar16;
        pfVar32[0x28] = local_3c;
        pfVar32[0x29] = fVar17;
        pfVar32[0x32] = local_48;
        pfVar32[0x33] = fVar18;
        if (DAT_00a380e8 == 1) {
          pfVar32[6] = _DAT_00e39a44 * ((local_54 - pfVar38[-1]) - (float)_DAT_00a380e0);
          pfVar32[7] = ((local_50 - *pfVar38) - (float)_DAT_00a380e4) * _DAT_00e39a48;
          pfVar32[0x10] = ((local_48 - pfVar38[-1]) - (float)_DAT_00a380e0) * _DAT_00e39a44;
          pfVar32[0x11] = ((fVar18 - *pfVar38) - (float)_DAT_00a380e4) * _DAT_00e39a48;
          pfVar32[0x1a] = ((local_3c - pfVar38[-1]) - (float)_DAT_00a380e0) * _DAT_00e39a44;
          pfVar32[0x1b] = ((fVar17 - *pfVar38) - (float)_DAT_00a380e4) * _DAT_00e39a48;
          pfVar32[0x24] = ((local_30 - pfVar38[-1]) - (float)_DAT_00a380e0) * _DAT_00e39a44;
          pfVar32[0x25] = _DAT_00e39a48 * ((fVar16 - *pfVar38) - (float)_DAT_00a380e4);
          pfVar32[0x2e] = _DAT_00e39a44 * ((local_3c - pfVar38[-1]) - (float)_DAT_00a380e0);
          pfVar32[0x2f] = _DAT_00e39a48 * ((fVar17 - *pfVar38) - (float)_DAT_00a380e4);
          pfVar32[0x38] = ((local_48 - pfVar38[-1]) - (float)_DAT_00a380e0) * _DAT_00e39a44;
          fVar27 = ((fVar18 - *pfVar38) - (float)_DAT_00a380e4) * _DAT_00e39a48;
        }
        else {
          pfVar32[6] = fVar21;
          pfVar32[7] = fVar19;
          pfVar32[0x10] = fVar26;
          pfVar32[0x11] = fVar27;
          pfVar32[0x1a] = fVar28;
          pfVar32[0x1b] = fVar29;
          pfVar32[0x24] = fVar3;
          pfVar32[0x25] = fVar20;
          pfVar32[0x2e] = fVar28;
          pfVar32[0x2f] = fVar29;
          pfVar32[0x38] = fVar26;
        }
        pfVar32[0x39] = fVar27;
        pfVar32[8] = pfVar37[1];
        pfVar32[9] = pfVar37[2];
        pfVar32[0x12] = pfVar37[5];
        pfVar32[0x13] = pfVar37[6];
        pfVar32[0x1c] = pfVar37[9];
        pfVar32[0x1d] = pfVar37[10];
        pfVar32[0x26] = pfVar37[0xd];
        pfVar32[0x27] = pfVar37[0xe];
        pfVar32[0x30] = pfVar37[9];
        pfVar32[0x31] = pfVar37[10];
        pfVar32[0x3a] = pfVar37[5];
        fVar3 = pfVar37[6];
      }
      else {
        pfVar32[10] = local_3c;
        pfVar32[0xb] = fVar17;
        pfVar32[0x14] = local_48;
        pfVar32[0x15] = fVar18;
        pfVar32[0x1e] = local_30;
        pfVar32[0x1f] = fVar16;
        pfVar32[0x28] = local_48;
        pfVar32[0x29] = fVar18;
        pfVar32[0x32] = local_3c;
        pfVar32[0x33] = fVar17;
        if (DAT_00a380e8 == 1) {
          pfVar32[6] = _DAT_00e39a44 * ((local_54 - pfVar38[-1]) - (float)_DAT_00a380e0);
          pfVar32[7] = ((local_50 - *pfVar38) - (float)_DAT_00a380e4) * _DAT_00e39a48;
          pfVar32[0x10] = ((local_3c - pfVar38[-1]) - (float)_DAT_00a380e0) * _DAT_00e39a44;
          pfVar32[0x11] = ((fVar17 - *pfVar38) - (float)_DAT_00a380e4) * _DAT_00e39a48;
          pfVar32[0x1a] = ((local_48 - pfVar38[-1]) - (float)_DAT_00a380e0) * _DAT_00e39a44;
          pfVar32[0x1b] = ((fVar18 - *pfVar38) - (float)_DAT_00a380e4) * _DAT_00e39a48;
          pfVar32[0x24] = ((local_30 - pfVar38[-1]) - (float)_DAT_00a380e0) * _DAT_00e39a44;
          pfVar32[0x25] = _DAT_00e39a48 * ((fVar16 - *pfVar38) - (float)_DAT_00a380e4);
          pfVar32[0x2e] = _DAT_00e39a44 * ((local_48 - pfVar38[-1]) - (float)_DAT_00a380e0);
          pfVar32[0x2f] = _DAT_00e39a48 * ((fVar18 - *pfVar38) - (float)_DAT_00a380e4);
          pfVar32[0x38] = ((local_3c - pfVar38[-1]) - (float)_DAT_00a380e0) * _DAT_00e39a44;
          fVar29 = ((fVar17 - *pfVar38) - (float)_DAT_00a380e4) * _DAT_00e39a48;
        }
        else {
          pfVar32[6] = fVar21;
          pfVar32[7] = fVar19;
          pfVar32[0x10] = fVar28;
          pfVar32[0x11] = fVar29;
          pfVar32[0x1a] = fVar26;
          pfVar32[0x1b] = fVar27;
          pfVar32[0x24] = fVar3;
          pfVar32[0x25] = fVar20;
          pfVar32[0x2e] = fVar26;
          pfVar32[0x2f] = fVar27;
          pfVar32[0x38] = fVar28;
        }
        pfVar32[0x39] = fVar29;
        pfVar32[8] = pfVar37[1];
        pfVar32[9] = pfVar37[2];
        pfVar32[0x12] = pfVar37[9];
        pfVar32[0x13] = pfVar37[10];
        pfVar32[0x1c] = pfVar37[5];
        pfVar32[0x1d] = pfVar37[6];
        pfVar32[0x26] = pfVar37[0xd];
        pfVar32[0x27] = pfVar37[0xe];
        pfVar32[0x30] = pfVar37[5];
        pfVar32[0x31] = pfVar37[6];
        pfVar32[0x3a] = pfVar37[9];
        fVar3 = pfVar37[10];
      }
      pfVar32[0x3b] = fVar3;
      pfVar32[2] = fVar31;
      pfVar32[0xc] = fVar31;
      pfVar32[0x16] = fVar31;
      pfVar32[0x20] = fVar31;
      pfVar32[0x2a] = fVar31;
      pfVar32[0x34] = fVar31;
      DAT_00e39a58 = DAT_00e39a58 + 0x3c;
      DAT_00e79678 = DAT_00e79678 + 6;
      if (!bVar39) {
        pfVar38 = pfVar38 + 0x1e;
      }
      pfVar37 = pfVar37 + 0x1e;
      local_a4 = local_a4 + -1;
    } while (local_a4 != 0);
  }
  return 0;
}

