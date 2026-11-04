
undefined4 FUN_005ebb70(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  float fVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  float *pfVar12;
  uint uVar13;
  undefined4 *puVar14;
  double *pdVar15;
  float *pfVar16;
  int iVar17;
  undefined4 *puVar18;
  float *pfVar19;
  float *pfVar20;
  float *local_18c;
  float *local_188;
  float *local_184;
  uint local_180;
  int local_17c;
  int local_170;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 local_140;
  double local_138;
  double local_130;
  double local_128;
  double local_120;
  double local_118;
  double local_110;
  int local_108;
  int local_104;
  int local_100;
  uint local_fc;
  int local_f8 [4];
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0 [55];
  
  uVar7 = (uint)*(ushort *)((int)param_2 + 6);
  local_170 = param_2[3];
  iVar3 = *(int *)(param_2[0x49] + 0x10);
  uVar4 = param_2[4];
  pfVar16 = (float *)**(undefined4 **)(param_4 + 0xc);
  if ((char)param_2[0x3e] == '\0') {
    if (param_2[0x3f] == 0) {
      local_104 = FUN_0056e030(local_170 * iVar3,
                               "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxModelD3D11.cpp",
                               0xbc8);
      param_2[0x3f] = local_104;
      if (local_104 == 0) {
        return 0xffffffff;
      }
      piVar5 = (int *)*param_2;
      local_fc = (uint)(*(int *)(piVar5[1] + 0x168) != 0);
      local_18c = (float *)0x2;
      if (piVar5[0x13] < 3) {
        local_18c = (float *)piVar5[0x13];
      }
      piVar11 = (int *)param_2[0x3c];
      local_108 = *(int *)(*piVar5 + 0x1b0);
      iVar9 = piVar5[0x16];
      local_100 = piVar5[0x17];
      uVar13 = param_2[0x42] + 0xfU & 0xfffffff0;
      if (local_170 != 0) {
        local_188 = (float *)local_170;
        do {
          iVar8 = *piVar11 * iVar9 + local_100;
          iVar17 = 0;
          iVar1 = local_108 + *(int *)(iVar8 + 4) * 0x24;
          if (local_fc == 0) {
            local_17c = 0;
          }
          else {
            local_17c = iVar1 + 0xc;
            iVar17 = iVar1 + 0x18;
          }
          if (local_18c < 2) {
            local_180 = 0;
          }
          else {
            local_180 = iVar8 + 0x1c;
          }
          if (local_18c == (float *)0x0) {
            iVar10 = 0;
          }
          else {
            iVar10 = iVar8 + 0x14;
          }
          FUN_005e86d0(&local_104,uVar13,iVar1,iVar8 + 8,iVar8 + 0xc,iVar10,local_180,local_17c,
                       iVar17,0,0,0,0);
          uVar13 = uVar13 + uVar7;
          piVar11 = piVar11 + 1;
          local_188 = (float *)((int)local_188 + -1);
        } while (local_188 != (float *)0x0);
      }
    }
    iVar9 = *(int *)(param_1 + 0x188);
    pfVar12 = (float *)param_2[0x3f];
    local_188 = (float *)(param_2[0x42] + 0xfU & 0xfffffff0);
    local_184 = pfVar16;
    if (iVar9 < 0x36) {
      if (iVar9 != 0) {
        puVar14 = *(undefined4 **)(param_3 + 0x1e8);
        puVar18 = local_e0;
        for (; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar18 = *puVar14;
          puVar14 = puVar14 + 1;
          puVar18 = puVar18 + 1;
        }
      }
      local_17c = local_170;
      if (DAT_00a380c4 == 0) {
        if (local_170 != 0) {
          pfVar19 = local_188 + 5;
          do {
            if (pfVar19[4] == 1.0) {
              pfVar20 = (float *)local_e0[(int)pfVar19[3]];
              if (pfVar16 == (float *)0x0) {
                *pfVar12 = pfVar19[-3] * pfVar20[2] +
                           pfVar20[1] * pfVar19[-4] + *pfVar20 * *local_188 + pfVar20[3];
                pfVar12[1] = pfVar19[-3] * pfVar20[6] +
                             *local_188 * pfVar20[4] + pfVar20[5] * pfVar19[-4] + pfVar20[7];
                fVar2 = pfVar20[9] * pfVar19[-4] + *local_188 * pfVar20[8];
                fVar6 = pfVar19[-3] * pfVar20[10];
              }
              else {
                *pfVar12 = pfVar20[2] * pfVar16[2] + pfVar16[1] * pfVar20[1] + *pfVar20 * *pfVar16 +
                           pfVar20[3];
                pfVar12[1] = pfVar20[6] * pfVar16[2] +
                             pfVar16[1] * pfVar20[5] + pfVar20[4] * *pfVar16 + pfVar20[7];
                fVar2 = pfVar16[1] * pfVar20[9] + pfVar20[8] * *pfVar16;
                fVar6 = pfVar20[10] * pfVar16[2];
              }
              pfVar12[2] = fVar6 + fVar2 + pfVar20[0xb];
              pfVar12[3] = pfVar20[2] * pfVar19[1] + *pfVar19 * pfVar20[1] + *pfVar20 * pfVar19[-1];
              pfVar12[4] = pfVar20[6] * pfVar19[1] +
                           pfVar19[-1] * pfVar20[4] + *pfVar19 * pfVar20[5];
              fVar2 = pfVar19[-1] * pfVar20[8] + *pfVar19 * pfVar20[9];
              fVar6 = pfVar19[1] * pfVar20[10];
            }
            else {
              fVar2 = pfVar19[4];
              pfVar16 = (float *)local_e0[(int)pfVar19[3]];
              local_18c = pfVar19 + 5;
              local_180 = 1;
              local_168 = (double)CONCAT44(pfVar16[1] * fVar2,fVar2 * *pfVar16);
              local_160 = (double)CONCAT44(pfVar16[3] * fVar2,pfVar16[2] * fVar2);
              local_158 = (double)CONCAT44(pfVar16[5] * fVar2,pfVar16[4] * fVar2);
              local_150 = (double)CONCAT44(pfVar16[7] * fVar2,pfVar16[6] * fVar2);
              local_148 = (double)CONCAT44(pfVar16[9] * fVar2,pfVar16[8] * fVar2);
              local_140 = (double)CONCAT44(fVar2 * pfVar16[0xb],pfVar16[10] * fVar2);
              if (1 < uVar4) {
                do {
                  if (*local_18c == -NAN) break;
                  if (local_18c[1] != 0.0) {
                    pfVar16 = (float *)local_e0[(int)*local_18c];
                    FUN_005825a0(&local_168,pfVar16,local_18c[1]);
                  }
                  local_180 = local_180 + 1;
                  local_18c = local_18c + 2;
                } while (local_180 < uVar4);
              }
              if (local_184 == (float *)0x0) {
                *pfVar12 = pfVar16[2] * pfVar19[-3] +
                           *pfVar16 * *local_188 + pfVar16[1] * pfVar19[-4] + pfVar16[3];
                pfVar12[1] = pfVar16[6] * pfVar19[-3] +
                             pfVar16[5] * pfVar19[-4] + pfVar16[4] * *local_188 + pfVar16[7];
                fVar2 = pfVar16[9] * pfVar19[-4] + pfVar16[8] * *local_188;
                fVar6 = pfVar16[10] * pfVar19[-3];
              }
              else {
                *pfVar12 = pfVar16[2] * local_184[2] +
                           *pfVar16 * *local_184 + pfVar16[1] * local_184[1] + pfVar16[3];
                pfVar12[1] = pfVar16[6] * local_184[2] +
                             pfVar16[5] * local_184[1] + pfVar16[4] * *local_184 + pfVar16[7];
                fVar2 = pfVar16[9] * local_184[1] + pfVar16[8] * *local_184;
                fVar6 = pfVar16[10] * local_184[2];
              }
              pfVar12[2] = fVar6 + fVar2 + pfVar16[0xb];
              pfVar12[3] = (float)local_160 * pfVar19[1] +
                           local_168._4_4_ * *pfVar19 + pfVar19[-1] * (float)local_168;
              pfVar12[4] = (float)local_150 * pfVar19[1] +
                           local_158._4_4_ * *pfVar19 + (float)local_158 * pfVar19[-1];
              fVar2 = local_148._4_4_ * *pfVar19 + (float)local_148 * pfVar19[-1];
              fVar6 = (float)local_140 * pfVar19[1];
              pfVar16 = local_184;
            }
            pfVar12[5] = fVar6 + fVar2;
            if (pfVar16 != (float *)0x0) {
              pfVar16 = pfVar16 + 3;
              local_184 = pfVar16;
            }
            pfVar12 = (float *)((int)pfVar12 + iVar3);
            local_188 = (float *)((int)local_188 + uVar7);
            pfVar19 = (float *)((int)pfVar19 + uVar7);
            local_17c = local_17c + -1;
          } while (local_17c != 0);
        }
      }
      else if (local_170 != 0) {
        pfVar19 = local_188 + 5;
        do {
          if (pfVar19[4] == 1.0) {
            pdVar15 = (double *)local_e0[(int)pfVar19[3]];
            if (pfVar16 == (float *)0x0) {
              *pfVar12 = pfVar19[-3] * (float)pdVar15[2] +
                         pfVar19[-4] * (float)pdVar15[1] + *local_188 * (float)*pdVar15 +
                         (float)pdVar15[3];
              pfVar12[1] = pfVar19[-3] * (float)pdVar15[6] +
                           *local_188 * (float)pdVar15[4] + pfVar19[-4] * (float)pdVar15[5] +
                           (float)pdVar15[7];
              fVar6 = *local_188 * (float)pdVar15[8] + pfVar19[-4] * (float)pdVar15[9];
              fVar2 = pfVar19[-3];
            }
            else {
              *pfVar12 = pfVar16[2] * (float)pdVar15[2] +
                         *pfVar16 * (float)*pdVar15 + pfVar16[1] * (float)pdVar15[1] +
                         (float)pdVar15[3];
              pfVar12[1] = pfVar16[2] * (float)pdVar15[6] +
                           pfVar16[1] * (float)pdVar15[5] + *pfVar16 * (float)pdVar15[4] +
                           (float)pdVar15[7];
              fVar6 = pfVar16[1] * (float)pdVar15[9] + *pfVar16 * (float)pdVar15[8];
              fVar2 = pfVar16[2];
            }
            pfVar12[2] = fVar2 * (float)pdVar15[10] + fVar6 + (float)pdVar15[0xb];
            pfVar12[3] = pfVar19[1] * (float)pdVar15[2] +
                         pfVar19[-1] * (float)*pdVar15 + *pfVar19 * (float)pdVar15[1];
            pfVar12[4] = pfVar19[1] * (float)pdVar15[6] +
                         pfVar19[-1] * (float)pdVar15[4] + *pfVar19 * (float)pdVar15[5];
            fVar2 = pfVar19[-1] * (float)pdVar15[8] + *pfVar19 * (float)pdVar15[9];
            fVar6 = pfVar19[1] * (float)pdVar15[10];
          }
          else {
            fVar2 = pfVar19[4];
            pdVar15 = (double *)local_e0[(int)pfVar19[3]];
            local_18c = pfVar19 + 5;
            local_180 = 1;
            local_168 = (double)(fVar2 * (float)*pdVar15);
            local_160 = (double)(fVar2 * (float)pdVar15[1]);
            local_158 = (double)(fVar2 * (float)pdVar15[2]);
            local_150 = (double)(fVar2 * (float)pdVar15[3]);
            local_148 = (double)(fVar2 * (float)pdVar15[4]);
            local_140 = (double)(fVar2 * (float)pdVar15[5]);
            local_138 = (double)(fVar2 * (float)pdVar15[6]);
            local_130 = (double)(fVar2 * (float)pdVar15[7]);
            local_128 = (double)(fVar2 * (float)pdVar15[8]);
            local_120 = (double)(fVar2 * (float)pdVar15[9]);
            local_118 = (double)(fVar2 * (float)pdVar15[10]);
            local_110 = (double)(fVar2 * (float)pdVar15[0xb]);
            if (1 < uVar4) {
              do {
                if (*local_18c == -NAN) break;
                if (local_18c[1] != 0.0) {
                  pdVar15 = (double *)local_e0[(int)*local_18c];
                  FUN_00582640(&local_168,pdVar15,local_18c[1]);
                }
                local_180 = local_180 + 1;
                local_18c = local_18c + 2;
              } while (local_180 < uVar4);
            }
            if (local_184 == (float *)0x0) {
              *pfVar12 = pfVar19[-3] * (float)pdVar15[2] +
                         *local_188 * (float)*pdVar15 + pfVar19[-4] * (float)pdVar15[1] +
                         (float)pdVar15[3];
              pfVar12[1] = pfVar19[-3] * (float)pdVar15[6] +
                           pfVar19[-4] * (float)pdVar15[5] + *local_188 * (float)pdVar15[4] +
                           (float)pdVar15[7];
              fVar6 = pfVar19[-4] * (float)pdVar15[9] + *local_188 * (float)pdVar15[8];
              fVar2 = pfVar19[-3];
            }
            else {
              *pfVar12 = local_184[2] * (float)pdVar15[2] +
                         *local_184 * (float)*pdVar15 + local_184[1] * (float)pdVar15[1] +
                         (float)pdVar15[3];
              pfVar12[1] = local_184[2] * (float)pdVar15[6] +
                           local_184[1] * (float)pdVar15[5] + *local_184 * (float)pdVar15[4] +
                           (float)pdVar15[7];
              fVar6 = local_184[1] * (float)pdVar15[9] + *local_184 * (float)pdVar15[8];
              fVar2 = local_184[2];
            }
            pfVar12[2] = fVar2 * (float)pdVar15[10] + fVar6 + (float)pdVar15[0xb];
            pfVar12[3] = pfVar19[1] * (float)local_158 +
                         *pfVar19 * (float)local_160 + pfVar19[-1] * (float)local_168;
            pfVar12[4] = pfVar19[1] * (float)local_138 +
                         *pfVar19 * (float)local_140 + pfVar19[-1] * (float)local_148;
            fVar2 = *pfVar19 * (float)local_120 + pfVar19[-1] * (float)local_128;
            fVar6 = pfVar19[1] * (float)local_118;
            pfVar16 = local_184;
          }
          pfVar12[5] = fVar6 + fVar2;
          if (pfVar16 != (float *)0x0) {
            pfVar16 = pfVar16 + 3;
            local_184 = pfVar16;
          }
          pfVar12 = (float *)((int)pfVar12 + iVar3);
          local_188 = (float *)((int)local_188 + uVar7);
          pfVar19 = (float *)((int)pfVar19 + uVar7);
          local_17c = local_17c + -1;
        } while (local_17c != 0);
      }
    }
    else if (DAT_00a380c4 == 0) {
      if (local_170 != 0) {
        local_18c = pfVar12 + 5;
        pfVar16 = local_188 + 5;
        do {
          if (pfVar16[4] == 1.0) {
            pfVar19 = *(float **)(*(int *)(param_3 + 0x1e8) + (int)pfVar16[3] * 4);
            if (local_184 == (float *)0x0) {
              pfVar20 = local_188;
            }
            else {
              pfVar20 = local_184;
            }
            FUN_005826d0(pfVar12,pfVar20,pfVar19);
            local_18c[-2] = pfVar19[2] * pfVar16[1] + *pfVar19 * pfVar16[-1] + pfVar19[1] * *pfVar16
            ;
            local_18c[-1] =
                 pfVar19[6] * pfVar16[1] + pfVar19[4] * pfVar16[-1] + pfVar19[5] * *pfVar16;
            *local_18c = pfVar19[10] * pfVar16[1] + pfVar19[8] * pfVar16[-1] + pfVar19[9] * *pfVar16
            ;
          }
          else {
            iVar9 = *(int *)(param_3 + 0x1e8);
            pfVar19 = pfVar16 + 5;
            FUN_005824c0(&local_168,*(undefined4 *)(iVar9 + (int)pfVar16[3] * 4),pfVar16[4]);
            local_180 = 1;
            if (1 < uVar4) {
              do {
                if (*pfVar19 == -NAN) break;
                if (pfVar19[1] != 0.0) {
                  FUN_005825a0(&local_168,*(undefined4 *)(iVar9 + (int)*pfVar19 * 4),pfVar19[1]);
                }
                local_180 = local_180 + 1;
                pfVar19 = pfVar19 + 2;
              } while (local_180 < uVar4);
            }
            if (local_184 == (float *)0x0) {
              *pfVar12 = local_160._4_4_ +
                         (float)local_160 * pfVar16[-3] +
                         local_168._4_4_ * pfVar16[-4] + (float)local_168 * *local_188;
              local_18c[-4] =
                   (float)local_150 * pfVar16[-3] +
                   local_158._4_4_ * pfVar16[-4] + (float)local_158 * *local_188 + local_150._4_4_;
              local_18c[-3] =
                   (float)local_140 * pfVar16[-3] +
                   *local_188 * (float)local_148 + local_148._4_4_ * pfVar16[-4] + local_140._4_4_;
            }
            else {
              *pfVar12 = local_160._4_4_ +
                         (float)local_160 * local_184[2] +
                         local_168._4_4_ * local_184[1] + (float)local_168 * *local_184;
              local_18c[-4] =
                   local_150._4_4_ +
                   (float)local_150 * local_184[2] +
                   (float)local_158 * *local_184 + local_158._4_4_ * local_184[1];
              local_18c[-3] =
                   (float)local_140 * local_184[2] +
                   (float)local_148 * *local_184 + local_148._4_4_ * local_184[1] + local_140._4_4_;
            }
            local_18c[-2] =
                 pfVar16[-1] * (float)local_168 + *pfVar16 * local_168._4_4_ +
                 pfVar16[1] * (float)local_160;
            local_18c[-1] =
                 pfVar16[1] * (float)local_150 +
                 (float)local_158 * pfVar16[-1] + *pfVar16 * local_158._4_4_;
            *local_18c = pfVar16[1] * (float)local_140 +
                         (float)local_148 * pfVar16[-1] + local_148._4_4_ * *pfVar16;
          }
          if (local_184 != (float *)0x0) {
            local_184 = local_184 + 3;
          }
          local_188 = (float *)((int)local_188 + uVar7);
          pfVar16 = (float *)((int)pfVar16 + uVar7);
          local_18c = (float *)((int)local_18c + iVar3);
          pfVar12 = (float *)((int)pfVar12 + iVar3);
          local_170 = local_170 + -1;
        } while (local_170 != 0);
      }
    }
    else if (local_170 != 0) {
      local_18c = pfVar12 + 5;
      pfVar16 = local_188 + 5;
      do {
        if (pfVar16[4] == 1.0) {
          pdVar15 = *(double **)(*(int *)(param_3 + 0x1e8) + (int)pfVar16[3] * 4);
          if (local_184 == (float *)0x0) {
            pfVar19 = local_188;
          }
          else {
            pfVar19 = local_184;
          }
          FUN_00582730(pfVar12,pfVar19,pdVar15);
          local_18c[-2] =
               pfVar16[1] * (float)pdVar15[2] +
               pfVar16[-1] * (float)*pdVar15 + *pfVar16 * (float)pdVar15[1];
          local_18c[-1] =
               pfVar16[1] * (float)pdVar15[6] +
               pfVar16[-1] * (float)pdVar15[4] + *pfVar16 * (float)pdVar15[5];
          *local_18c = pfVar16[1] * (float)pdVar15[10] +
                       pfVar16[-1] * (float)pdVar15[8] + *pfVar16 * (float)pdVar15[9];
        }
        else {
          iVar9 = *(int *)(param_3 + 0x1e8);
          pfVar19 = pfVar16 + 5;
          FUN_00582530(&local_168,*(undefined4 *)(iVar9 + (int)pfVar16[3] * 4),pfVar16[4]);
          local_180 = 1;
          if (1 < uVar4) {
            do {
              if (*pfVar19 == -NAN) break;
              if (pfVar19[1] != 0.0) {
                FUN_00582640(&local_168,*(undefined4 *)(iVar9 + (int)*pfVar19 * 4),pfVar19[1]);
              }
              local_180 = local_180 + 1;
              pfVar19 = pfVar19 + 2;
            } while (local_180 < uVar4);
          }
          if (local_184 == (float *)0x0) {
            *pfVar12 = pfVar16[-4] * (float)local_160 + *local_188 * (float)local_168 +
                       pfVar16[-3] * (float)local_158 + (float)local_150;
            local_18c[-4] =
                 pfVar16[-3] * (float)local_138 +
                 pfVar16[-4] * (float)local_140 + *local_188 * (float)local_148 + (float)local_130;
            fVar6 = *local_188 * (float)local_128 + pfVar16[-4] * (float)local_120;
            fVar2 = pfVar16[-3];
          }
          else {
            *pfVar12 = local_184[1] * (float)local_160 + *local_184 * (float)local_168 +
                       local_184[2] * (float)local_158 + (float)local_150;
            local_18c[-4] =
                 local_184[2] * (float)local_138 +
                 local_184[1] * (float)local_140 + *local_184 * (float)local_148 + (float)local_130;
            fVar6 = *local_184 * (float)local_128 + local_184[1] * (float)local_120;
            fVar2 = local_184[2];
          }
          local_18c[-3] = fVar6 + fVar2 * (float)local_118 + (float)local_110;
          local_18c[-2] =
               pfVar16[-1] * (float)local_168 + *pfVar16 * (float)local_160 +
               pfVar16[1] * (float)local_158;
          local_18c[-1] =
               pfVar16[1] * (float)local_138 +
               (float)local_148 * pfVar16[-1] + *pfVar16 * (float)local_140;
          *local_18c = *pfVar16 * (float)local_120 + pfVar16[-1] * (float)local_128 +
                       pfVar16[1] * (float)local_118;
        }
        if (local_184 != (float *)0x0) {
          local_184 = local_184 + 3;
        }
        local_188 = (float *)((int)local_188 + uVar7);
        pfVar16 = (float *)((int)pfVar16 + uVar7);
        local_18c = (float *)((int)local_18c + iVar3);
        pfVar12 = (float *)((int)pfVar12 + iVar3);
        local_170 = local_170 + -1;
      } while (local_170 != 0);
    }
    *(undefined1 *)(param_2 + 0x3e) = 1;
    local_f8[0] = param_2[0x4a] * iVar3;
    local_f8[3] = (param_2[3] + param_2[0x4a]) * iVar3;
    local_e8 = 1;
    local_e4 = 1;
    local_f8[1] = 0;
    local_f8[2] = 0;
    FUN_005d2dd0(**(undefined4 **)(param_2[0x49] + 0x14),0,local_f8,param_2[0x3f],0,0);
  }
  return 0;
}

