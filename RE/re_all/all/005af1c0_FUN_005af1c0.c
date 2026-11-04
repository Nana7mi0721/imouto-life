
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005af1c0(float param_1,float param_2,float param_3,float param_4,float param_5,
                 float param_6,float param_7,float param_8,int param_9,char param_10)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  float *pfVar10;
  float *pfVar11;
  int iVar12;
  int iVar13;
  float *pfVar14;
  float *pfVar15;
  float10 fVar16;
  float10 fVar17;
  float10 fVar18;
  float local_a0;
  float local_9c;
  float local_98;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_4c [4];
  undefined4 local_3c;
  float local_38 [7];
  float local_1c [7];
  
  FUN_0059bcf0(*(undefined4 *)**(undefined4 **)(param_9 + 0x74));
  FUN_005a0d80(0,0,1,1);
  fVar5 = DAT_00e79684;
  fVar8 = DAT_00a380b8;
  fVar3 = param_6 - param_2;
  fVar2 = param_5 - param_1;
  fVar4 = 0.0;
  if (param_10 == '\0') {
    iVar12 = 0;
    fVar1 = (param_3 - param_1) - (param_7 - param_5);
    if (fVar1 < 0.0) {
      fVar1 = -fVar1;
    }
    if (fVar1 < 1.0) {
      fVar1 = (param_4 - param_2) - (param_8 - param_6);
      if (fVar1 < 0.0) {
        fVar1 = -fVar1;
      }
      if (fVar1 < 1.0) {
        iVar12 = 1;
      }
    }
    fVar1 = fVar2 - (param_7 - param_3);
    if (fVar1 < 0.0) {
      fVar1 = -fVar1;
    }
    if (fVar1 < 1.0) {
      fVar1 = fVar3 - (param_8 - param_4);
      if (fVar1 < 0.0) {
        fVar1 = -fVar1;
      }
      if (fVar1 < 1.0) {
        iVar12 = iVar12 + 1;
      }
    }
    if (iVar12 != 2) {
      if (_DAT_007d5924 <= *(float *)(param_9 + 0x38)) {
        local_7c = ((*(float *)(param_9 + 0x68) - *(float *)(param_9 + 0x38)) /
                   (*(float *)(param_9 + 0x60) - *(float *)(param_9 + 0x30))) * (float)_DAT_007fcbb8
        ;
      }
      else {
        local_7c = fVar4;
      }
      if (*(float *)(param_9 + 0x68) <= (float)_DAT_007d9b90) {
        local_8c = ((*(float *)(param_9 + 0x68) - *(float *)(param_9 + 0x38)) /
                   (*(float *)(param_9 + 0x60) - *(float *)(param_9 + 0x30))) * (float)_DAT_007fcbb0
        ;
      }
      else {
        local_8c = fVar4;
      }
      if (_DAT_007d5924 <= *(float *)(param_9 + 0x3c)) {
        local_98 = ((*(float *)(param_9 + 0x6c) - *(float *)(param_9 + 0x3c)) /
                   (*(float *)(param_9 + 100) - *(float *)(param_9 + 0x34))) * (float)_DAT_007fcbb8;
      }
      else {
        local_98 = fVar4;
      }
      if (*(float *)(param_9 + 0x6c) <= (float)_DAT_007d9b90) {
        fVar4 = ((*(float *)(param_9 + 0x6c) - *(float *)(param_9 + 0x3c)) /
                (*(float *)(param_9 + 100) - *(float *)(param_9 + 0x34))) * (float)_DAT_007fcbb0;
      }
      local_4c[0] = _DAT_007d103c;
      local_4c[1] = 1.0;
      local_4c[2] = (float)_DAT_007fcbac;
      local_4c[3] = (float)_DAT_007d5504;
      local_3c = _DAT_007fcba8;
      fVar16 = (float10)FUN_0056d670((param_5 - param_3) * (param_5 - param_3) +
                                     (param_6 - param_4) * (param_6 - param_4));
      fVar17 = (float10)FUN_0056d670((param_7 - param_1) * (param_7 - param_1) +
                                     (param_8 - param_2) * (param_8 - param_2));
      fVar18 = (float10)FUN_0056d670((float)(DAT_00a381b8 * DAT_00a381b8 +
                                            DAT_00a381b4 * DAT_00a381b4));
      iVar12 = 5;
      pfVar10 = local_4c;
      do {
        if (*pfVar10 <=
            (float)((float10)(double)(fVar17 + (float10)(double)fVar16) / (fVar18 + fVar18))) break;
        iVar12 = iVar12 + -1;
        pfVar10 = pfVar10 + 1;
      } while (0 < iVar12);
      pfVar10 = (float *)&DAT_00ee2310;
      iVar12 = 8;
      fVar6 = (float)_DAT_007fcba0;
      local_88 = param_1;
      local_84 = param_2;
      local_80 = param_3;
      local_9c = param_4;
      fVar7 = *(float *)(param_9 + 0x68) + local_8c;
      fVar1 = *(float *)(param_9 + 0x38);
      local_78 = *(float *)(param_9 + 0x3c) + local_98;
      fVar4 = (*(float *)(param_9 + 0x6c) + fVar4) - local_78;
      do {
        iVar13 = 8;
        local_98 = local_88;
        local_8c = local_84;
        local_a0 = *(float *)(param_9 + 0x38) + local_7c;
        pfVar11 = pfVar10;
        do {
          pfVar11[2] = fVar8;
          *pfVar11 = local_98;
          pfVar11[4] = fVar5;
          pfVar10 = pfVar11 + 7;
          iVar13 = iVar13 + -1;
          pfVar11[1] = local_8c;
          pfVar11[3] = 1.0;
          pfVar11[5] = local_a0;
          pfVar11[6] = local_78;
          local_a0 = (fVar7 - (fVar1 + local_7c)) / fVar6 + local_a0;
          local_98 = (local_80 - local_88) / fVar6 + local_98;
          local_8c = local_8c + (local_9c - local_84) / fVar6;
          pfVar11 = pfVar10;
        } while (iVar13 != 0);
        iVar12 = iVar12 + -1;
        local_78 = local_78 + fVar4 / fVar6;
        local_88 = local_88 + fVar2 / fVar6;
        local_84 = local_84 + fVar3 / fVar6;
        local_80 = local_80 + (param_7 - param_3) / fVar6;
        local_9c = local_9c + (param_8 - param_4) / fVar6;
      } while (iVar12 != 0);
      FUN_005af060(&DAT_00ee2310,8);
      return;
    }
  }
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
     (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
    if (DAT_00e79678 != 0) {
      FUN_005a7ce0();
      if (DAT_00e79680 == 4) {
        uVar9 = (int)DAT_00e79678 / 3;
      }
      else if (DAT_00e79680 == 2) {
        uVar9 = (int)DAT_00e79678 / 2;
      }
      else if (DAT_00e79680 == 6) {
        uVar9 = DAT_00e79678 - 2;
      }
      else if (DAT_00e79680 == 5) {
        uVar9 = DAT_00e79678 - 2;
      }
      else if (DAT_00e79680 == 3) {
        uVar9 = DAT_00e79678 - 1;
      }
      else {
        uVar9 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
      }
      iVar12 = DAT_00e7967c + DAT_00e79674 * 3;
      FUN_005d3b40(DAT_00e79680,uVar9,*(undefined4 *)(&DAT_00e39a5c + iVar12 * 4),
                   *(undefined4 *)(&DAT_007da3e8 + iVar12 * 4));
      DAT_00a37de4 = DAT_00a37de4 + 1;
    }
    DAT_00e79678 = 0;
    DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
    DAT_00e79674 = 0;
    DAT_00e79680 = 4;
  }
  pfVar11 = DAT_00e39a58;
  *DAT_00e39a58 = param_1;
  pfVar11[0x19] = fVar5;
  pfVar11[4] = fVar5;
  pfVar11[7] = param_3;
  pfVar11[0x23] = param_3;
  pfVar10 = pfVar11 + 0x1c;
  pfVar11[0xe] = param_5;
  *pfVar10 = param_5;
  pfVar11[0x15] = param_7;
  pfVar11[1] = param_2;
  pfVar11[8] = param_4;
  pfVar11[0x24] = param_4;
  pfVar11[0xf] = param_6;
  pfVar11[0x1d] = param_6;
  pfVar11[0x16] = param_8;
  fVar5 = (float)_DAT_007d8138;
  fVar4 = *(float *)(param_9 + 0x38) + fVar5 / (float)*(int *)(*(int *)(param_9 + 0x74) + 0x14);
  pfVar11[5] = fVar4;
  pfVar11[0x13] = fVar4;
  pfVar11[0x21] = fVar4;
  fVar4 = *(float *)(param_9 + 0x48) - fVar5 / (float)*(int *)(*(int *)(param_9 + 0x74) + 0x14);
  pfVar11[0xc] = fVar4;
  pfVar11[0x1a] = fVar4;
  pfVar11[0x28] = fVar4;
  fVar4 = fVar5 / (float)*(int *)(*(int *)(param_9 + 0x74) + 0x18) + *(float *)(param_9 + 0x3c);
  pfVar11[6] = fVar4;
  pfVar11[0xd] = fVar4;
  pfVar11[0x29] = fVar4;
  fVar4 = *(float *)(param_9 + 0x5c) - fVar5 / (float)*(int *)(*(int *)(param_9 + 0x74) + 0x18);
  pfVar11[2] = fVar8;
  pfVar11[9] = fVar8;
  pfVar11[0x10] = fVar8;
  pfVar11[0x17] = fVar8;
  pfVar11[0x1e] = fVar8;
  pfVar11[0x14] = fVar4;
  pfVar11[0x25] = fVar8;
  pfVar11[0x1b] = fVar4;
  pfVar11[0x22] = fVar4;
  if ((fVar3 * (param_3 - param_1) - (param_4 - param_2) * fVar2 <= 0.0) &&
     ((param_4 - param_8) * (param_5 - param_7) - (param_6 - param_8) * (param_3 - param_7) <= 0.0))
  {
    pfVar14 = pfVar11 + 7;
    pfVar15 = local_38;
    for (iVar12 = 7; iVar12 != 0; iVar12 = iVar12 + -1) {
      *pfVar15 = *pfVar14;
      pfVar14 = pfVar14 + 1;
      pfVar15 = pfVar15 + 1;
    }
    pfVar14 = pfVar10;
    pfVar15 = local_1c;
    for (iVar12 = 7; iVar12 != 0; iVar12 = iVar12 + -1) {
      *pfVar15 = *pfVar14;
      pfVar14 = pfVar14 + 1;
      pfVar15 = pfVar15 + 1;
    }
    pfVar14 = pfVar11 + 0xe;
    pfVar15 = pfVar11 + 7;
    for (iVar12 = 7; iVar12 != 0; iVar12 = iVar12 + -1) {
      *pfVar15 = *pfVar14;
      pfVar14 = pfVar14 + 1;
      pfVar15 = pfVar15 + 1;
    }
    pfVar14 = pfVar11 + 0x23;
    for (iVar12 = 7; iVar12 != 0; iVar12 = iVar12 + -1) {
      *pfVar10 = *pfVar14;
      pfVar14 = pfVar14 + 1;
      pfVar10 = pfVar10 + 1;
    }
    pfVar10 = local_38;
    pfVar14 = pfVar11 + 0xe;
    for (iVar12 = 7; iVar12 != 0; iVar12 = iVar12 + -1) {
      *pfVar14 = *pfVar10;
      pfVar10 = pfVar10 + 1;
      pfVar14 = pfVar14 + 1;
    }
    pfVar10 = local_1c;
    pfVar11 = pfVar11 + 0x23;
    for (iVar12 = 7; iVar12 != 0; iVar12 = iVar12 + -1) {
      *pfVar11 = *pfVar10;
      pfVar10 = pfVar10 + 1;
      pfVar11 = pfVar11 + 1;
    }
  }
  DAT_00e39a58 = DAT_00e39a58 + 0x2a;
  DAT_00e79678 = DAT_00e79678 + 6;
  return;
}

