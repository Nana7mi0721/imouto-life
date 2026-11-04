
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall
FUN_00639640(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int param_5,
            int *param_6,int param_7,int param_8)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  undefined4 *puVar18;
  int *piVar19;
  float *pfVar20;
  undefined4 *puVar21;
  int iVar22;
  float *pfVar23;
  undefined4 *puVar24;
  undefined4 *puVar25;
  float10 fVar26;
  float fStack_248;
  float fStack_244;
  float fStack_240;
  int *piStack_23c;
  int iStack_238;
  int local_234;
  int iStack_230;
  int *piStack_22c;
  int iStack_228;
  int iStack_224;
  int iStack_220;
  int iStack_21c;
  float fStack_218;
  float fStack_214;
  float fStack_210;
  float fStack_20c;
  float fStack_208;
  float fStack_204;
  float fStack_200;
  int iStack_1fc;
  float fStack_1f8;
  int iStack_1f4;
  float fStack_1f0;
  float fStack_1ec;
  float fStack_1e8;
  float fStack_1e4;
  int iStack_1e0;
  float fStack_1dc;
  float fStack_1d8;
  float fStack_1d4;
  float fStack_1d0;
  float fStack_1cc;
  float fStack_1c8;
  float fStack_1c4;
  float fStack_1c0;
  float fStack_1bc;
  float fStack_1b8;
  float fStack_1b4;
  float fStack_1b0;
  float fStack_1a8;
  float fStack_1a4;
  float fStack_1a0;
  float fStack_198;
  float fStack_194;
  float fStack_190;
  float fStack_188;
  float fStack_184;
  float fStack_180;
  float fStack_178;
  float fStack_174;
  float fStack_170;
  float fStack_168;
  float fStack_164;
  float fStack_160;
  float afStack_158 [2];
  int iStack_150;
  float fStack_14c;
  undefined4 uStack_148;
  int iStack_144;
  undefined4 uStack_140;
  int iStack_13c;
  int iStack_138;
  int iStack_134;
  int iStack_130;
  undefined4 uStack_128;
  undefined4 auStack_f0 [60];
  
  if (param_5 + param_7 != 0) {
    local_234 = param_1;
    if (0 < param_7) {
      piVar19 = param_6;
      iVar22 = param_7;
      do {
        (**(code **)(*(int *)*piVar19 + 4))();
        piVar19 = piVar19 + 1;
        iVar22 = iVar22 + -1;
      } while (iVar22 != 0);
    }
    iVar22 = *(int *)(param_1 + 8);
    if (iVar22 == *(int *)(param_1 + 0xc)) {
      iVar14 = iVar22 * 2;
      if (iVar22 == 0) {
        iVar14 = 1;
      }
      FUN_0063ae90(iVar14);
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    pfVar23 = (float *)(iVar22 * 0x68 + *(int *)(param_1 + 0x10));
    if (pfVar23 != (float *)0x0) {
      pfVar20 = afStack_158;
      for (iVar14 = 0x1a; iVar14 != 0; iVar14 = iVar14 + -1) {
        *pfVar23 = *pfVar20;
        pfVar20 = pfVar20 + 1;
        pfVar23 = pfVar23 + 1;
      }
    }
    FUN_006371f0(iVar22 * 0x68 + *(int *)(param_1 + 0x10),0);
    iVar22 = *(int *)(param_1 + 0x80);
    iVar14 = 0;
    if ((iVar22 <= param_7) && (iVar22 < param_7)) {
      FUN_00621d20(param_7);
      do {
        pfVar23 = (float *)(*(int *)(param_1 + 0x88) + iVar22 * 8);
        if (pfVar23 != (float *)0x0) {
          *pfVar23 = fStack_20c;
          pfVar23[1] = fStack_208;
        }
        iVar22 = iVar22 + 1;
      } while (iVar22 < param_7);
    }
    iVar22 = 0;
    *(int *)(param_1 + 0x80) = param_7;
    if (0 < param_7) {
      piStack_23c = param_6;
      do {
        piVar19 = (int *)(*(int *)(param_1 + 0x88) + iVar22 * 8);
        (**(code **)(*(int *)*piStack_23c + 0xc))(piVar19);
        iVar14 = iVar14 + *piVar19;
        iVar22 = iVar22 + 1;
        piStack_23c = piStack_23c + 1;
      } while (iVar22 < param_7);
    }
    iVar22 = *(int *)(param_1 + 0x30);
    if ((iVar22 <= iVar14) && (iVar22 < iVar14)) {
      FUN_0063af40(iVar14);
      iVar15 = iVar22 * 0x88;
      iVar22 = iVar14 - iVar22;
      do {
        puVar24 = (undefined4 *)(iVar15 + *(int *)(param_1 + 0x38));
        if (puVar24 != (undefined4 *)0x0) {
          puVar21 = auStack_f0;
          for (iVar17 = 0x22; iVar17 != 0; iVar17 = iVar17 + -1) {
            *puVar24 = *puVar21;
            puVar21 = puVar21 + 1;
            puVar24 = puVar24 + 1;
          }
        }
        iVar15 = iVar15 + 0x88;
        iVar22 = iVar22 + -1;
      } while (iVar22 != 0);
    }
    *(int *)(param_1 + 0x30) = iVar14;
    iStack_224 = 0;
    iStack_228 = 0;
    if (0 < param_7) {
      piStack_23c = param_6;
      do {
        piStack_22c = (int *)(iStack_228 * 8 + *(int *)(param_1 + 0x88));
        if (*piStack_22c != 0) {
          fStack_244 = (float)(*(int *)(param_1 + 0x38) + iStack_224 * 0x88);
          iStack_220 = *piStack_23c;
          iVar22 = *(int *)(iStack_220 + 0x14);
          iVar14 = *(int *)(iStack_220 + 0x18);
          iStack_230 = iVar14;
          if ((int)*(float *)(iVar22 + 0xd0) < 0) {
            if (((*(int *)(iVar22 + 0xe8) == 2) && (iVar22 != 0)) &&
               (*(float *)(iVar22 + 0x150) != _DAT_007d5344)) {
              fVar2 = *(float *)(param_1 + 8);
              uVar16 = FUN_0061ddb0();
              uVar16 = FUN_0063ac90(uVar16);
              FUN_006371f0(uVar16,iVar22);
              *(float *)(iVar22 + 0xd0) = fVar2;
              fStack_240 = fVar2;
            }
            else {
              fStack_240 = 0.0;
            }
          }
          else {
            fStack_240 = *(float *)(iVar22 + 0xd0);
          }
          fVar2 = fStack_240;
          fStack_248 = *(float *)(iVar14 + 0xd0);
          if ((int)fStack_248 < 0) {
            if (((*(int *)(iVar14 + 0xe8) == 2) && (iVar14 != 0)) &&
               (*(float *)(iVar14 + 0x150) != _DAT_007d5344)) {
              fStack_248 = *(float *)(param_1 + 8);
              uVar16 = FUN_0061ddb0();
              uVar16 = FUN_0063ac90(uVar16);
              FUN_006371f0(uVar16,iVar14);
              *(float *)(iVar14 + 0xd0) = fStack_248;
            }
            else {
              fStack_248 = 0.0;
            }
          }
          fVar3 = fStack_244;
          puVar24 = (undefined4 *)(*(int *)(param_1 + 0x10) + (int)fVar2 * 0x68);
          iStack_238 = 0;
          puVar21 = (undefined4 *)(*(int *)(param_1 + 0x10) + (int)fStack_248 * 0x68);
          if (0 < *piStack_22c) {
            puVar18 = (undefined4 *)((int)fStack_244 + 0x80);
            do {
              puVar25 = puVar18 + -0x20;
              for (iVar14 = 0x22; iVar14 != 0; iVar14 = iVar14 + -1) {
                *puVar25 = 0;
                puVar25 = puVar25 + 1;
              }
              puVar18[-1] = 0xff7fffff;
              *puVar18 = 0x7f7fffff;
              puVar18[-0xb] = 0;
              puVar18[-0xc] = 0;
              puVar18[-6] = fStack_240;
              puVar18[-5] = fStack_248;
              iStack_238 = iStack_238 + 1;
              puVar18 = puVar18 + 0x22;
            } while (iStack_238 < *piStack_22c);
          }
          *puVar24 = 0;
          afStack_158[0] = _DAT_00804108;
          puVar24[1] = 0;
          puVar24[2] = 0;
          puVar24[3] = 0;
          puVar24[4] = 0;
          puVar24[5] = 0;
          puVar24[6] = 0;
          puVar24[7] = 0;
          *puVar21 = 0;
          puVar21[1] = 0;
          puVar21[2] = 0;
          puVar21[3] = 0;
          puVar21[4] = 0;
          puVar21[5] = 0;
          puVar21[6] = 0;
          puVar21[7] = 0;
          afStack_158[0] = afStack_158[0] / *(float *)(param_8 + 0xc);
          afStack_158[1] = *(float *)(param_8 + 0x20);
          iStack_150 = (int)fStack_244 + 0x10;
          iStack_13c = (int)fStack_244 + 0x74;
          uStack_128 = *(undefined4 *)(param_8 + 0x14);
          iStack_144 = (int)fStack_244 + 0x20;
          iStack_134 = (int)fStack_244 + 0x7c;
          iStack_138 = (int)fStack_244 + 0x78;
          iStack_130 = (int)fStack_244 + 0x80;
          fStack_14c = fStack_244;
          uStack_148 = 0;
          uStack_140 = 0x22;
          (**(code **)(*(int *)*piStack_23c + 0x10))(afStack_158);
          iStack_238 = 0;
          if (0 < *piStack_22c) {
            iStack_21c = iVar22 + 0x110;
            iStack_1e0 = iVar22 + 0x120;
            iStack_1fc = iStack_230 + 0x120;
            iStack_1f4 = iStack_230 + 0x110;
            pfVar23 = (float *)((int)fVar3 + 0x18);
            do {
              pfVar20 = pfVar23 + -6;
              iVar14 = *(int *)(iStack_220 + 0x14);
              fVar26 = (float10)FUN_005fcc30(pfVar20);
              fStack_1f8 = (float)fVar26;
              fVar26 = (float10)FUN_005fcc30(pfVar20);
              fStack_1ec = (float)fVar26;
              fVar26 = (float10)FUN_005fcc30(pfVar20);
              fStack_210 = (float)fVar26;
              FUN_005fc500(&fStack_210,&fStack_1ec,&fStack_1f8);
              fStack_244 = fStack_160 * *(float *)(iVar14 + 0x15c);
              fStack_248 = fStack_164 * *(float *)(iVar14 + 0x158);
              fStack_240 = fStack_168 * *(float *)(iVar14 + 0x154);
              FUN_005fc500(&fStack_240,&fStack_248,&fStack_244);
              pfVar1 = pfVar23 + 2;
              pfVar23[6] = fStack_1d8;
              pfVar23[7] = fStack_1d4;
              pfVar23[8] = fStack_1d0;
              pfVar23[9] = fStack_1cc;
              fStack_248 = *(float *)(iStack_220 + 0x18);
              fVar26 = (float10)FUN_005fcc30(pfVar1);
              fStack_1e4 = (float)fVar26;
              fVar26 = (float10)FUN_005fcc30(pfVar1);
              fStack_204 = (float)fVar26;
              fVar26 = (float10)FUN_005fcc30(pfVar1);
              fStack_1dc = (float)fVar26;
              FUN_005fc500(&fStack_1dc,&fStack_204,&fStack_1e4);
              fStack_244 = fStack_170 * *(float *)((int)fStack_248 + 0x15c);
              fStack_240 = fStack_178 * *(float *)((int)fStack_248 + 0x154);
              fStack_248 = fStack_174 * *(float *)((int)fStack_248 + 0x158);
              FUN_005fc500(&fStack_240,&fStack_248,&fStack_244);
              pfVar23[10] = fStack_1c8;
              pfVar23[0xb] = fStack_1c4;
              pfVar23[0xc] = fStack_1c0;
              pfVar23[0xd] = fStack_1bc;
              fStack_240 = *(float *)(iVar22 + 0x150);
              fStack_244 = fStack_240 * *pfVar23;
              fStack_248 = fStack_240 * pfVar23[-1];
              fStack_240 = fStack_240 * pfVar23[-2];
              FUN_005fc500(&fStack_240,&fStack_248,&fStack_244);
              fVar26 = (float10)FUN_005fcc30(pfVar20);
              fStack_1e8 = (float)fVar26;
              fVar26 = (float10)FUN_005fcc30(pfVar20);
              fStack_1f0 = (float)fVar26;
              fVar26 = (float10)FUN_005fcc30(pfVar20);
              fStack_200 = (float)fVar26;
              FUN_005fc500(&fStack_200,&fStack_1f0,&fStack_1e8);
              fStack_240 = *(float *)(iStack_230 + 0x150);
              fStack_244 = fStack_240 * *pfVar23;
              fStack_248 = fStack_240 * pfVar23[-1];
              fStack_240 = fStack_240 * pfVar23[-2];
              FUN_005fc500(&fStack_240,&fStack_248,&fStack_244);
              fVar26 = (float10)FUN_005fcc30(pfVar1);
              fStack_218 = (float)fVar26;
              fVar26 = (float10)FUN_005fcc30(pfVar1);
              fStack_214 = (float)fVar26;
              fVar26 = (float10)FUN_005fcc30(pfVar1);
              fStack_20c = (float)fVar26;
              FUN_005fc500(&fStack_20c,&fStack_214,&fStack_218);
              fStack_244 = _DAT_00804108 /
                           (fStack_194 * pfVar23[3] +
                           fStack_190 * pfVar23[4] +
                           fStack_198 * *pfVar1 +
                           fStack_1a4 * pfVar23[-1] +
                           fStack_1a8 * pfVar23[-2] +
                           fStack_1a0 * *pfVar23 +
                           fStack_1b8 * *pfVar20 +
                           fStack_1b0 * pfVar23[-4] +
                           fStack_1b4 * pfVar23[-5] +
                           fStack_184 * pfVar23[-1] +
                           fStack_188 * pfVar23[-2] + fStack_180 * *pfVar23);
              pfVar23[0x11] = fStack_244;
              fVar2 = *(float *)(iStack_230 + 0x148);
              fVar3 = *(float *)(iStack_230 + 0x138);
              fVar4 = *(float *)(iStack_230 + 0x134);
              fVar5 = *(float *)(iStack_230 + 0x144);
              fVar6 = *(float *)(iStack_230 + 0x130);
              fVar7 = *(float *)(iStack_230 + 0x140);
              fVar8 = *(float *)(iVar22 + 0x148);
              fVar9 = *(float *)(iVar22 + 0x144);
              iStack_238 = iStack_238 + 1;
              fVar10 = *(float *)(iVar22 + 0x134);
              fVar11 = *(float *)(iVar22 + 0x140);
              fVar12 = *(float *)(iVar22 + 0x130);
              fVar13 = *(float *)(iVar22 + 0x138);
              pfVar23[0xf] = 0.0;
              pfVar23[0x17] =
                   pfVar23[0x17] * fStack_244 +
                   -(fVar13 * *pfVar23 +
                     fVar12 * pfVar23[-2] +
                     *pfVar20 * fVar11 +
                     fVar10 * pfVar23[-1] + fVar9 * pfVar23[-5] + fVar8 * pfVar23[-4] +
                    fVar7 * *pfVar1 +
                    ((pfVar23[3] * fVar5 +
                     ((pfVar23[4] * fVar2 - *pfVar23 * fVar3) - fVar4 * pfVar23[-1])) -
                    pfVar23[-2] * fVar6)) * fStack_244;
              pfVar23 = pfVar23 + 0x22;
            } while (iStack_238 < *piStack_22c);
          }
          param_1 = local_234;
        }
        iStack_224 = iStack_224 + *(int *)(*(int *)(param_1 + 0x88) + iStack_228 * 8);
        iStack_228 = iStack_228 + 1;
        piStack_23c = piStack_23c + 1;
      } while (iStack_228 < param_7);
    }
    if (0 < param_5) {
      do {
        FUN_00637c60(*param_4,param_8);
        param_4 = param_4 + 1;
        param_5 = param_5 + -1;
      } while (param_5 != 0);
    }
    iVar22 = *(int *)(param_1 + 0x1c);
    iVar14 = *(int *)(param_1 + 0x58);
    local_234 = *(int *)(param_1 + 0x44);
    if ((iVar14 <= iVar22) && (iVar14 < iVar22)) {
      FUN_0078e010(iVar22);
      do {
        puVar24 = (undefined4 *)(*(int *)(param_1 + 0x60) + iVar14 * 4);
        if (puVar24 != (undefined4 *)0x0) {
          *puVar24 = 0;
        }
        iVar14 = iVar14 + 1;
      } while (iVar14 < iVar22);
    }
    *(int *)(param_1 + 0x58) = iVar22;
    iVar14 = *(int *)(param_1 + 0x6c);
    if (iVar14 <= local_234) {
      if (iVar14 < local_234) {
        FUN_0078e010(local_234);
      }
      for (; iVar14 < local_234; iVar14 = iVar14 + 1) {
        puVar24 = (undefined4 *)(*(int *)(param_1 + 0x74) + iVar14 * 4);
        if (puVar24 != (undefined4 *)0x0) {
          *puVar24 = 0;
        }
      }
    }
    *(int *)(param_1 + 0x6c) = local_234;
    iVar14 = 0;
    if (0 < iVar22) {
      do {
        *(int *)(*(int *)(param_1 + 0x60) + iVar14 * 4) = iVar14;
        iVar14 = iVar14 + 1;
      } while (iVar14 < iVar22);
    }
    iVar22 = 0;
    if (0 < local_234) {
      do {
        *(int *)(*(int *)(param_1 + 0x74) + iVar22 * 4) = iVar22;
        iVar22 = iVar22 + 1;
      } while (iVar22 < local_234);
    }
  }
  return (float10)_DAT_007d5344;
}

