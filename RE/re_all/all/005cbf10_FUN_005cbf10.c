
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005cbf10(float param_1,float param_2,float param_3,float param_4,float param_5,
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
  float fVar9;
  float fVar10;
  float *pfVar11;
  float *pfVar12;
  int iVar13;
  int iVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  float local_14 [4];
  undefined4 local_4;
  
  fVar7 = param_6;
  fVar1 = param_5;
  FUN_005bc5b0(*(undefined4 *)(**(int **)(param_9 + 0x74) + 4),
               *(undefined4 *)(**(int **)(param_9 + 0x74) + 8));
  if (DAT_00ef72e8 != 0) {
    FUN_005bbac0();
  }
  fVar8 = DAT_00f07344;
  fVar10 = DAT_00a380b8;
  fVar5 = param_6 - param_2;
  fVar4 = param_5 - param_1;
  if (param_10 == '\0') {
    iVar13 = 0;
    fVar2 = param_7 - param_3;
    fVar3 = param_8 - param_4;
    fVar6 = (param_3 - param_1) - (param_7 - param_5);
    if (fVar6 < 0.0) {
      fVar6 = -fVar6;
    }
    if (fVar6 < 1.0) {
      fVar6 = (param_4 - param_2) - (param_8 - param_6);
      if (fVar6 < 0.0) {
        fVar6 = -fVar6;
      }
      if (fVar6 < 1.0) {
        iVar13 = 1;
      }
    }
    fVar6 = fVar4 - fVar2;
    if (fVar6 < 0.0) {
      fVar6 = -fVar6;
    }
    if (fVar6 < 1.0) {
      fVar6 = fVar5 - fVar3;
      if (fVar6 < 0.0) {
        fVar6 = -fVar6;
      }
      if (fVar6 < 1.0) {
        iVar13 = iVar13 + 1;
      }
    }
    if (iVar13 != 2) {
      if (_DAT_007d5924 <= *(float *)(param_9 + 0x38)) {
        _param_10 = ((*(float *)(param_9 + 0x68) - *(float *)(param_9 + 0x38)) /
                    (*(float *)(param_9 + 0x60) - *(float *)(param_9 + 0x30))) *
                    (float)_DAT_007fcbb8;
      }
      else {
        _param_10 = 0.0;
      }
      if (*(float *)(param_9 + 0x68) <= (float)_DAT_007d9b90) {
        param_5 = ((*(float *)(param_9 + 0x68) - *(float *)(param_9 + 0x38)) /
                  (*(float *)(param_9 + 0x60) - *(float *)(param_9 + 0x30))) * (float)_DAT_007fcbb0;
      }
      else {
        param_5 = 0.0;
      }
      if (_DAT_007d5924 <= *(float *)(param_9 + 0x3c)) {
        param_6 = ((*(float *)(param_9 + 0x6c) - *(float *)(param_9 + 0x3c)) /
                  (*(float *)(param_9 + 100) - *(float *)(param_9 + 0x34))) * (float)_DAT_007fcbb8;
      }
      else {
        param_6 = 0.0;
      }
      fVar6 = 0.0;
      if (*(float *)(param_9 + 0x6c) <= (float)_DAT_007d9b90) {
        fVar6 = ((*(float *)(param_9 + 0x6c) - *(float *)(param_9 + 0x3c)) /
                (*(float *)(param_9 + 100) - *(float *)(param_9 + 0x34))) * (float)_DAT_007fcbb0;
      }
      local_14[0] = _DAT_007d103c;
      local_14[1] = 1.0;
      local_14[2] = (float)_DAT_007fcbac;
      local_14[3] = (float)_DAT_007d5504;
      local_4 = _DAT_007fcba8;
      fVar15 = (float10)FUN_0056d670((fVar1 - param_3) * (fVar1 - param_3) +
                                     (fVar7 - param_4) * (fVar7 - param_4));
      fVar16 = (float10)FUN_0056d670((param_7 - param_1) * (param_7 - param_1) +
                                     (param_8 - param_2) * (param_8 - param_2));
      fVar17 = (float10)FUN_0056d670((float)(DAT_00a381b8 * DAT_00a381b8 +
                                            DAT_00a381b4 * DAT_00a381b4));
      iVar13 = 5;
      pfVar11 = local_14;
      do {
        if (*pfVar11 <=
            (float)((float10)(double)(fVar16 + (float10)(double)fVar15) / (fVar17 + fVar17))) break;
        iVar13 = iVar13 + -1;
        pfVar11 = pfVar11 + 1;
      } while (0 < iVar13);
      pfVar11 = (float *)&DAT_00f32908;
      iVar13 = 8;
      fVar7 = (float)_DAT_007fcba0;
      param_8 = param_1;
      param_7 = param_2;
      param_1 = param_3;
      param_2 = param_4;
      fVar9 = *(float *)(param_9 + 0x68) + param_5;
      fVar1 = *(float *)(param_9 + 0x38);
      param_6 = *(float *)(param_9 + 0x3c) + param_6;
      fVar6 = (fVar6 + *(float *)(param_9 + 0x6c)) - param_6;
      do {
        iVar14 = 8;
        param_4 = param_8;
        param_5 = param_7;
        param_3 = *(float *)(param_9 + 0x38) + _param_10;
        pfVar12 = pfVar11;
        do {
          pfVar12[2] = fVar10;
          *pfVar12 = param_4;
          pfVar12[4] = fVar8;
          pfVar11 = pfVar12 + 7;
          iVar14 = iVar14 + -1;
          pfVar12[1] = param_5;
          pfVar12[3] = 1.0;
          pfVar12[5] = param_3;
          pfVar12[6] = param_6;
          param_3 = (fVar9 - (fVar1 + _param_10)) / fVar7 + param_3;
          param_4 = (param_1 - param_8) / fVar7 + param_4;
          param_5 = param_5 + (param_2 - param_7) / fVar7;
          pfVar12 = pfVar11;
        } while (iVar14 != 0);
        iVar13 = iVar13 + -1;
        param_6 = param_6 + fVar6 / fVar7;
        param_8 = param_8 + fVar4 / fVar7;
        param_7 = param_7 + fVar5 / fVar7;
        param_1 = param_1 + fVar2 / fVar7;
        param_2 = param_2 + fVar3 / fVar7;
      } while (iVar13 != 0);
      FUN_005cbdd0(&DAT_00f32908);
      return;
    }
  }
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (((DAT_00f07338 != 0) || (DAT_00f07340 != 4)) ||
     (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <= DAT_00f07334 + 6))
  {
    FUN_005c3310(0,0);
    DAT_00f07340 = 4;
  }
  pfVar11 = DAT_00f0732c;
  DAT_00f0732c[4] = fVar8;
  pfVar11[0xb] = fVar8;
  pfVar11[0x12] = fVar8;
  pfVar11[0x19] = fVar8;
  pfVar11[0x20] = fVar8;
  pfVar11[0x27] = fVar8;
  fVar7 = (float)_DAT_007d8138 / (float)*(int *)(*(int *)(param_9 + 0x74) + 0x14);
  fVar1 = *(float *)(param_9 + 0x38) + fVar7;
  fVar7 = *(float *)(param_9 + 0x48) - fVar7;
  fVar2 = (float)_DAT_007d8138 / (float)*(int *)(*(int *)(param_9 + 0x74) + 0x18);
  fVar8 = *(float *)(param_9 + 0x3c) + fVar2;
  fVar2 = *(float *)(param_9 + 0x5c) - fVar2;
  if ((0.0 < fVar5 * (param_3 - param_1) - (param_4 - param_2) * fVar4) ||
     (0.0 < (param_4 - param_8) * (param_5 - param_7) - (param_6 - param_8) * (param_3 - param_7)))
  {
    *pfVar11 = param_1;
    pfVar11[1] = param_2;
    pfVar11[7] = param_3;
    pfVar11[8] = param_4;
    pfVar11[0xe] = param_5;
    pfVar11[0xf] = param_6;
    pfVar11[0x15] = param_7;
    pfVar11[0x16] = param_8;
    pfVar11[0x1c] = param_5;
    pfVar11[0x1d] = param_6;
    pfVar11[0x23] = param_3;
    pfVar11[0x24] = param_4;
    pfVar11[5] = fVar1;
    pfVar11[6] = fVar8;
    pfVar11[0xc] = fVar7;
    pfVar11[0xd] = fVar8;
    pfVar11[0x13] = fVar1;
    pfVar11[0x14] = fVar2;
    pfVar11[0x1b] = fVar2;
    pfVar11[0x22] = fVar2;
    pfVar11[0x1a] = fVar7;
    pfVar11[0x28] = fVar7;
    pfVar11[0x21] = fVar1;
    pfVar11[0x29] = fVar8;
  }
  else {
    *pfVar11 = param_1;
    pfVar11[1] = param_2;
    pfVar11[7] = param_5;
    pfVar11[8] = param_6;
    pfVar11[0xe] = param_3;
    pfVar11[0xf] = param_4;
    pfVar11[0x15] = param_7;
    pfVar11[0x16] = param_8;
    pfVar11[0x1c] = param_3;
    pfVar11[0x1d] = param_4;
    pfVar11[0x23] = param_5;
    pfVar11[0x24] = param_6;
    pfVar11[5] = fVar1;
    pfVar11[6] = fVar8;
    pfVar11[0xc] = fVar1;
    pfVar11[0xd] = fVar2;
    pfVar11[0x13] = fVar7;
    pfVar11[0x1a] = fVar7;
    pfVar11[0x21] = fVar7;
    pfVar11[0x14] = fVar8;
    pfVar11[0x22] = fVar8;
    pfVar11[0x1b] = fVar2;
    pfVar11[0x29] = fVar2;
    pfVar11[0x28] = fVar1;
  }
  pfVar11[3] = 1.0;
  pfVar11[2] = fVar10;
  pfVar11[10] = 1.0;
  pfVar11[9] = fVar10;
  pfVar11[0x11] = 1.0;
  pfVar11[0x10] = fVar10;
  pfVar11[0x18] = 1.0;
  pfVar11[0x17] = fVar10;
  pfVar11[0x1f] = 1.0;
  pfVar11[0x1e] = fVar10;
  pfVar11[0x25] = fVar10;
  pfVar11[0x26] = 1.0;
  DAT_00f0732c = DAT_00f0732c + 0x2a;
  DAT_00f07334 = DAT_00f07334 + 6;
  return;
}

