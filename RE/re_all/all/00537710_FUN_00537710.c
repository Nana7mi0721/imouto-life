
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00537710(int param_1,int param_2,int param_3,float param_4,float param_5,int param_6,
                int param_7,double param_8,double param_9,int param_10,float param_11,float param_12
                ,double param_13,short *param_14,uint param_15,int param_16,undefined4 param_17,
                int param_18,int param_19,uint param_20,int param_21,int param_22,
                undefined4 *param_23,int *param_24,int param_25,uint param_26,uint *param_27,
                int param_28)

{
  undefined1 *puVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  double dVar8;
  short sVar9;
  byte bVar12;
  byte bVar11;
  byte bVar10;
  undefined1 uVar13;
  undefined2 uVar14;
  int iVar15;
  float fVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  char *pcVar21;
  ushort *puVar22;
  undefined4 uVar23;
  float fVar24;
  uint *puVar25;
  undefined2 *puVar26;
  byte bVar27;
  byte bVar28;
  byte bVar29;
  uint uVar30;
  int iVar31;
  uint uVar32;
  uint uVar33;
  short sVar34;
  uint uVar35;
  byte *pbVar36;
  float10 fVar37;
  float10 fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  ushort *local_1d0;
  ushort *local_1cc;
  float local_1c8;
  float local_1c4;
  float local_1c0;
  float local_1bc;
  short local_1b8;
  ushort *local_1b4;
  int local_1b0;
  byte local_1a9;
  undefined8 local_1a8;
  byte local_19a;
  byte local_199;
  ushort *local_198;
  byte local_191;
  float local_190;
  float local_18c;
  float local_188;
  float local_184;
  int local_180;
  int local_17c;
  int local_178;
  undefined1 *local_174;
  double local_170;
  double local_168;
  float local_15c;
  uint local_158;
  uint local_154;
  uint local_150;
  uint local_14c;
  float local_148;
  float local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  float local_130;
  float local_12c;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  uint *local_100;
  uint local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  float local_ec;
  uint local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  double local_d0;
  int local_c8;
  int local_c4;
  float local_c0;
  float local_bc;
  double local_b8;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  float local_98;
  float local_94;
  int local_90;
  uint *local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  double local_78;
  int local_6c;
  undefined4 local_68;
  int local_64;
  int local_60;
  int local_58;
  int local_54;
  undefined4 local_50;
  undefined4 *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  
  local_bc = 0.0;
  local_c0 = 1.0;
  local_1b0 = param_19;
  local_98 = 0.0;
  local_180 = 0;
  local_94 = 0.0;
  local_c4 = 0;
  local_8c = (uint *)0x0;
  local_d4 = 0;
  local_e8 = 0;
  local_9c = 0;
  local_90 = 0;
  if ((*(int *)(param_19 + 0x93628) != 0) && (iVar15 = FUN_00567b30(), iVar15 == 0)) {
    DAT_00a38118 = 0;
    return -1;
  }
  DAT_00a38118 = 1;
  if (param_23 != (undefined4 *)0x0) {
    *param_23 = 0;
    param_23[1] = 0;
  }
  if (param_24 != (int *)0x0) {
    *param_24 = 0;
  }
  if ((param_16 == 0) && (*(int *)(param_19 + 0x93628) != 0)) {
    if (param_7 == 0) {
      param_8 = 1.0;
      param_9 = 1.0;
    }
  }
  else {
    param_6 = 1;
    if (param_7 != 0) {
      DAT_00a38118 = 0;
      return -1;
    }
    if (param_10 != 0) {
      DAT_00a38118 = 0;
      return -1;
    }
    param_8 = 1.0;
    param_9 = 1.0;
  }
  if (param_10 == 0) {
    param_11 = 0.0;
    param_12 = 0.0;
  }
  else {
    fVar38 = (float10)param_13;
    if (param_22 == 1) {
      fVar38 = fVar38 + (float10)_DAT_007d54e8;
    }
    local_190 = (float)fVar38;
    FUN_0056d4d0(local_190,&local_bc,&local_c0);
  }
  uVar3 = *(ushort *)(param_19 + 0x93166);
  if (uVar3 == 0) {
LAB_0053792a:
    if (param_22 == 0) goto LAB_005378e3;
    local_d0 = param_9;
  }
  else {
    if (param_22 != 0) {
      if (param_6 == 0) {
        local_190 = (float)uVar3 * (float)param_9;
        local_98 = -local_190 * (float)_DAT_00804a60;
      }
      else {
        local_190 = (float)(uint)uVar3;
        iVar15 = FUN_0050e240((double)(int)local_190 * param_9);
        local_9c = -(iVar15 / 2);
      }
      goto LAB_0053792a;
    }
    if (param_6 == 0) {
      local_190 = (float)uVar3 * (float)param_9;
      local_94 = -local_190 * (float)_DAT_00804a60;
    }
    else {
      local_190 = (float)(uint)uVar3;
      iVar15 = FUN_0050e240((double)(int)local_190 * param_9);
      local_90 = -(iVar15 / 2);
    }
LAB_005378e3:
    local_d0 = param_8;
  }
  if (DAT_00a37d78 == 1) {
    uVar30 = 0xff000000;
  }
  else {
    iVar15 = FUN_00581c90(DAT_00a37e70 != 0x10,0,0);
    uVar30 = ((0 >> (8U - *(char *)(iVar15 + 10) & 0x1f)) << (*(byte *)(iVar15 + 0xe) & 0x1f)) +
             ((0 >> (8U - *(char *)(iVar15 + 9) & 0x1f)) << (*(byte *)(iVar15 + 0xd) & 0x1f)) +
             ((0 >> (8U - *(char *)(iVar15 + 8) & 0x1f)) << (*(byte *)(iVar15 + 0xc) & 0x1f)) +
             *(int *)(iVar15 + 0x20);
  }
  local_ec = (float)~uVar30;
  if (DAT_00a37d78 == 1) {
    local_15c = (float)(param_15 >> 0x10 & 0xff);
    local_174 = (undefined1 *)(param_15 >> 8 & 0xff);
    local_154 = param_15 & 0xff;
LAB_00537a78:
    uVar30 = param_20 >> 0x10 & 0xff;
    local_150 = param_20 >> 8 & 0xff;
    local_1cc = (ushort *)(param_20 & 0xff);
  }
  else {
    iVar15 = FUN_00581c90(DAT_00a37e70 != 0x10,0,0);
    local_15c = (float)((((*(uint *)(iVar15 + 0x10) & param_15) >> (*(byte *)(iVar15 + 0xc) & 0x1f))
                        * 0xff) / ((1 << (*(byte *)(iVar15 + 8) & 0x1f)) - 1U));
    local_174 = (undefined1 *)
                ((((*(uint *)(iVar15 + 0x14) & param_15) >> (*(byte *)(iVar15 + 0xd) & 0x1f)) * 0xff
                 ) / ((1 << (*(byte *)(iVar15 + 9) & 0x1f)) - 1U));
    local_154 = (((*(uint *)(iVar15 + 0x18) & param_15) >> (*(byte *)(iVar15 + 0xe) & 0x1f)) * 0xff)
                / ((1 << (*(byte *)(iVar15 + 10) & 0x1f)) - 1U);
    if (DAT_00a37d78 == 1) goto LAB_00537a78;
    iVar15 = FUN_00581c90(DAT_00a37e70 != 0x10,0,0);
    uVar30 = (((*(uint *)(iVar15 + 0x10) & param_20) >> (*(byte *)(iVar15 + 0xc) & 0x1f)) * 0xff) /
             ((1 << (*(byte *)(iVar15 + 8) & 0x1f)) - 1U);
    local_150 = (((*(uint *)(iVar15 + 0x14) & param_20) >> (*(byte *)(iVar15 + 0xd) & 0x1f)) * 0xff)
                / ((1 << (*(byte *)(iVar15 + 9) & 0x1f)) - 1U);
    local_1cc = (ushort *)
                ((((*(uint *)(iVar15 + 0x18) & param_20) >> (*(byte *)(iVar15 + 0xe) & 0x1f)) * 0xff
                 ) / ((1 << (*(byte *)(iVar15 + 10) & 0x1f)) - 1U));
  }
  if ((_DAT_00a38114 & 0xffffff) != 0xffffff) {
    uVar35 = _DAT_00a38114 >> 0x10 & 0xff;
    local_15c = (float)((int)((int)local_15c * uVar35) / 0xff);
    local_190 = (float)(_DAT_00a38114 >> 8 & 0xff);
    local_174 = (undefined1 *)(((int)local_174 * (int)local_190) / 0xff);
    local_154 = (int)(local_154 * (_DAT_00a38114 & 0xff)) / 0xff;
    uVar30 = (int)(uVar30 * uVar35) / 0xff;
    local_150 = (int)(local_150 * (int)local_190) / 0xff;
    local_1cc = (ushort *)((int)((int)local_1cc * (_DAT_00a38114 & 0xff)) / 0xff);
    if (DAT_00a37d78 == 1) {
      param_15 = (((uint)local_15c | 0xffffff00) << 8 | (uint)local_174) << 8 | local_154;
    }
    else {
      iVar15 = FUN_00581c90(DAT_00a37e70 != 0x10,0,0);
      param_15 = ((uint)((byte)local_154 >> (8U - *(char *)(iVar15 + 10) & 0x1f)) <<
                 (*(byte *)(iVar15 + 0xe) & 0x1f)) +
                 ((uint)((byte)local_174 >> (8U - *(char *)(iVar15 + 9) & 0x1f)) <<
                 (*(byte *)(iVar15 + 0xd) & 0x1f)) +
                 ((uint)(local_15c._0_1_ >> (8U - *(char *)(iVar15 + 8) & 0x1f)) <<
                 (*(byte *)(iVar15 + 0xc) & 0x1f)) + *(int *)(iVar15 + 0x20);
      if (DAT_00a37d78 != 1) {
        iVar15 = FUN_00581c90(DAT_00a37e70 != 0x10,0,0);
        param_20 = ((uint)((byte)local_1cc >> (8U - *(char *)(iVar15 + 10) & 0x1f)) <<
                   (*(byte *)(iVar15 + 0xe) & 0x1f)) +
                   ((uint)((byte)local_150 >> (8U - *(char *)(iVar15 + 9) & 0x1f)) <<
                   (*(byte *)(iVar15 + 0xd) & 0x1f)) +
                   (((uVar30 & 0xff) >> (8U - *(char *)(iVar15 + 8) & 0x1f)) <<
                   (*(byte *)(iVar15 + 0xc) & 0x1f)) + *(int *)(iVar15 + 0x20);
        goto LAB_00537d40;
      }
    }
    param_20 = ((uVar30 | 0xffffff00) << 8 | local_150) << 8 | (uint)local_1cc;
  }
LAB_00537d40:
  param_15 = param_15 & (uint)local_ec;
  param_20 = param_20 & (uint)local_ec;
  local_14c = (((uint)local_15c | 0xffffff00) << 8 | (uint)local_174) << 8 | local_154;
  local_174 = (undefined1 *)(((uVar30 | 0xffffff00) << 8 | local_150) << 8 | (uint)local_1cc);
  if ((param_14 == (short *)0x0) || (*param_14 == 0)) {
    DAT_00a38118 = 0;
    return 0;
  }
  if (param_21 < 0) {
    param_21 = FUN_0050e220();
  }
  if (param_21 < 0x401) {
    local_100 = (uint *)&DAT_00a4eef8;
  }
  else {
    local_c4 = 1;
    local_100 = (uint *)FUN_0056e030(param_21 * 4,
                                     "..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",0x1f01);
    if (local_100 == (uint *)0x0) {
      DAT_00a38118 = 0;
      return -1;
    }
    local_8c = local_100;
  }
  if (param_16 != 0) {
    local_180 = *(int *)(*(int *)(param_16 + 0x14) + 0xc);
  }
  if (param_22 == 1) {
    if (*(int *)(param_19 + 0x9317c) == 0) {
      local_144 = (float)(uint)*(ushort *)(param_19 + 0x93164);
      local_78 = (double)(int)local_144 * param_8;
    }
    else {
      local_144 = *(float *)(param_19 + 0x93180);
      local_78 = (double)(int)local_144 * param_8;
    }
  }
  else {
    if (*(int *)(param_19 + 0x9317c) == 0) {
      local_144 = (float)(uint)*(ushort *)(param_19 + 0x93164);
    }
    else {
      local_144 = *(float *)(param_19 + 0x93180);
    }
    local_78 = (double)(int)local_144 * param_9;
  }
  FUN_005374a0(param_19,param_14,&local_144);
  if (param_1 == 1) {
    local_148 = 0.0;
    if (*(int *)(param_19 + 0x93628) == 1) {
      iVar15 = FUN_00516930();
      if (iVar15 == 0) {
        local_148 = _DAT_007d5550;
      }
      else {
        local_148 = 0.0;
      }
    }
    fVar16 = (float)_DAT_00a38114;
    local_184 = (float)_DAT_00a38114;
    if (((*(byte *)(param_19 + 0x93184) & 1) == 0) &&
       (uVar30 = local_14c & 0xffffff, _DAT_00a38114 != uVar30)) {
      _DAT_00a38114 = uVar30;
      if (DAT_00a37d78 == 0) {
        FUN_00581200();
      }
      else {
        FUN_00567b70();
      }
    }
    fVar38 = (float10)0;
    local_168 = (double)fVar38;
    local_b8 = (double)fVar38;
    local_190 = 0.0;
    local_170 = (double)fVar38;
    if (0 < (int)local_144) {
      do {
        local_1b0 = param_19;
        fVar16 = (float)FUN_00536b30(param_19,*local_100,&local_1b0,&local_150,&local_154,1,0);
        local_15c = fVar16;
        if (fVar16 != 0.0) {
          if (param_19 == local_1b0) {
            if (param_6 == 0) {
              local_18c = local_98 + param_4;
              local_188 = local_94 + param_5;
            }
            else {
              local_178 = local_9c + param_2;
              local_17c = local_90 + param_3;
            }
          }
          else {
            local_178 = param_2;
            local_17c = param_3;
            iVar15 = param_2;
            if (param_22 == 0) {
              if (param_6 != 0) {
                iVar15 = FUN_0050e240((double)((float)(int)local_150 * (float)param_8));
                goto LAB_00538111;
              }
              local_18c = (float)(int)local_150 * (float)param_8 + local_18c;
              local_188 = (float)(int)local_154 * (float)param_9 + local_188;
            }
            else if (param_6 == 0) {
              local_18c = (float)(int)local_154 * (float)param_9 + local_18c;
              local_188 = (float)(int)local_150 * (float)param_8 + local_188;
            }
            else {
              iVar15 = FUN_0050e240((double)((float)(int)local_154 * (float)param_9));
LAB_00538111:
              local_178 = iVar15 + param_2;
              local_17c = FUN_0050e240();
              local_17c = local_17c + param_3;
              iVar15 = iVar15 + param_2;
            }
            iVar18 = local_17c;
            uVar3 = *(ushort *)(local_1b0 + 0x93166);
            if (uVar3 != 0) {
              if (param_22 == 0) {
                if (param_6 == 0) {
                  local_188 = local_188 - (float)uVar3 * (float)param_9 * (float)_DAT_00804a60;
                }
                else {
                  iVar15 = FUN_0050e240();
                  local_17c = iVar18 - iVar15 / 2;
                }
              }
              else if (param_6 == 0) {
                local_18c = local_18c - (float)uVar3 * (float)param_9 * (float)_DAT_00804a60;
              }
              else {
                iVar18 = FUN_0050e240();
                local_178 = iVar15 - iVar18 / 2;
              }
            }
          }
          if (*(char *)((int)fVar16 + 5) == '\0') {
            local_6c = *(int *)((int)fVar16 + 0x18) * (uint)*(ushort *)(local_1b0 + 0x9316a);
            local_158 = *(int *)((int)fVar16 + 0x14) * (uint)*(ushort *)(local_1b0 + 0x9316a);
            if (*(int *)(local_1b0 + 0x93628) == 1) {
              local_158 = local_158 + 1;
              local_6c = local_6c + 1;
            }
            local_f4 = *(ushort *)((int)fVar16 + 0xc) + local_158;
            local_f0 = (uint)*(ushort *)((int)fVar16 + 0xe) + local_6c;
            local_fc = local_158;
            local_f8 = local_6c;
          }
          iVar18 = local_6c;
          iVar15 = *(int *)(local_1b0 + 0x90d90);
          uVar30 = *local_100;
          if (uVar30 != 10) {
            if (uVar30 != 0x20) {
              if (uVar30 != DAT_00a4ba9c) {
                if (*(short *)((int)fVar16 + 0xc) == 0) {
                  if (*(short *)((int)fVar16 + 0xe) == 0) goto switchD_0053850e_caseD_4;
                }
                if ((*(int *)(local_1b0 + 0x93628) == 1) || (*(char *)((int)fVar16 + 5) != '\0')) {
                  local_c8 = DAT_00a380d8;
                  local_198 = DAT_00a380d4;
                  local_68 = DAT_00a380dc;
                  if ((DAT_00a380d4 != (ushort *)0xffffffff) && (DAT_00a380e8 == 0)) {
                    FUN_005270f0(0xffffffff);
                  }
                  fVar40 = (float)param_8;
                  fVar24 = (float)param_9;
                  if (param_10 == 0) {
                    if (param_22 == 1) {
                      if (*(char *)((int)fVar16 + 5) == '\0') {
                        local_88 = DAT_00a38194;
                        local_84 = DAT_00a38198;
                        local_80 = DAT_00a3819c;
                        local_7c = DAT_00a381a0;
                        FUN_00515880(*(undefined4 *)(local_1b0 + 0x931b0),&local_ec);
                        if (param_7 == 0) {
                          if (param_6 == 0) {
                            fVar24 = ((float)*(ushort *)(local_1b0 + 0x93164) +
                                     (local_18c - (float)local_170)) -
                                     ((float)(int)*(short *)((int)fVar16 + 8) - 1.0);
                            fVar40 = (float)local_168 + local_188 +
                                     ((float)(int)*(short *)((int)fVar16 + 6) - 1.0);
                            fVar41 = fVar24 - ((float)*(ushort *)((int)fVar16 + 0xe) +
                                              (float)_DAT_00829868);
                            fVar39 = (float)_DAT_00829868 + (float)*(ushort *)((int)fVar16 + 0xc) +
                                     fVar40;
                            if ((*(byte *)(local_1b0 + 0x93184) & 1) != 0) {
                              uVar23 = FUN_0052a120(local_158 - 1,iVar18 + -1,
                                                    *(ushort *)((int)fVar16 + 0xc) + 2,
                                                    *(ushort *)((int)fVar16 + 0xe) + 2);
                              uVar30 = (uint)local_174 & 0xffffff;
                              if (_DAT_00a38114 != uVar30) {
                                _DAT_00a38114 = uVar30;
                                if (DAT_00a37d78 == 0) {
                                  FUN_00581200();
                                }
                                else {
                                  FUN_00567b70();
                                }
                              }
                              if ((param_28 == 0) || (param_28 == 2)) {
                                fVar5 = fVar41 + local_148;
                                fVar6 = fVar39 + local_148;
                                fVar7 = local_148 + fVar24;
                                local_1a8 = (double)CONCAT44(local_1a8._4_4_,fVar7);
                                FUN_00520750(fVar7,local_148 + fVar40,fVar7,fVar6,fVar5,fVar6,fVar5,
                                             local_148 + fVar40,uVar23);
                              }
                              FUN_00515700(uVar23);
                              uVar30 = local_14c & 0xffffff;
                              if (_DAT_00a38114 != uVar30) {
                                _DAT_00a38114 = uVar30;
                                if (DAT_00a37d78 == 0) {
                                  FUN_00581200();
                                }
                                else {
                                  FUN_00567b70();
                                }
                              }
                            }
                            uVar23 = FUN_0052a120(local_158 - 1,iVar18 + -1,
                                                  *(ushort *)((int)fVar16 + 0xc) + 2,
                                                  *(ushort *)((int)fVar16 + 0xe) + 2);
                            if ((param_28 == 0) || (param_28 == 1)) {
                              fVar40 = local_148 + fVar40;
                              fVar41 = fVar41 + local_148;
                              fVar39 = fVar39 + local_148;
                              fVar24 = local_148 + fVar24;
                              local_1a8 = (double)CONCAT44(local_1a8._4_4_,fVar24);
                              goto LAB_0053d3cf;
                            }
                            goto LAB_0053d3e4;
                          }
                          iVar17 = FUN_0050e240(local_170);
                          iVar17 = (((uint)*(ushort *)(local_1b0 + 0x93164) -
                                    (int)*(short *)((int)fVar16 + 8)) + local_178) - iVar17;
                          iVar15 = FUN_0050e240(local_168);
                          local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar17 + iVar18);
                          local_a8 = (int)*(short *)((int)fVar16 + 6) + iVar15 + local_17c;
                          iVar19 = local_a8 - local_158;
                          iVar18 = (iVar17 - local_64) + iVar18;
                          iVar15 = iVar19 + (int)local_ec;
                          local_ac = (iVar17 - (uint)*(ushort *)((int)fVar16 + 0xe)) + -1;
                          local_a0 = (uint)*(ushort *)((int)fVar16 + 0xc) + local_a8;
                          local_a4 = iVar17 + 1;
                          FUN_00514e10(&local_ac,&local_88);
                          FUN_005217e0(local_ac,local_a8,local_a4,local_a0);
                          if ((*(byte *)(local_1b0 + 0x93184) & 1) != 0) {
                            uVar30 = (uint)local_174 & 0xffffff;
                            if (_DAT_00a38114 != uVar30) {
                              _DAT_00a38114 = uVar30;
                              if (DAT_00a37d78 == 0) {
                                FUN_00581200();
                              }
                              else {
                                FUN_00567b70();
                              }
                            }
                            if ((param_28 == 0) || (param_28 == 2)) {
                              fVar16 = (float)iVar18 + local_148;
                              fVar24 = (float)(iVar15 - ((int)local_ec >> 1)) + local_148;
                              FUN_00520750(local_148 + (float)(int)(float)local_1a8,
                                           local_148 + (float)iVar19,
                                           local_148 + (float)(int)(float)local_1a8,fVar24,fVar16,
                                           fVar24,fVar16,local_148 + (float)iVar19,
                                           *(undefined4 *)(local_1b0 + 0x931b4));
                            }
                            uVar30 = local_14c & 0xffffff;
                            if (_DAT_00a38114 != uVar30) {
                              _DAT_00a38114 = uVar30;
                              if (DAT_00a37d78 == 0) {
                                FUN_00581200();
                              }
                              else {
                                FUN_00567b70();
                              }
                            }
                          }
                          if ((param_28 == 0) || (param_28 == 1)) {
                            fVar16 = (float)iVar18 + local_148;
                            fVar24 = (float)iVar15 + local_148;
                            FUN_00520750(local_148 + (float)(int)(float)local_1a8,
                                         local_148 + (float)iVar19,
                                         local_148 + (float)(int)(float)local_1a8,fVar24,fVar16,
                                         fVar24,fVar16,local_148 + (float)iVar19,
                                         *(undefined4 *)(local_1b0 + 0x931b0));
                          }
                          FUN_005217e0(local_88,local_84);
                        }
                        else if (param_6 == 0) {
                          fVar24 = local_18c + (float)local_170 +
                                   ((float)*(ushort *)(local_1b0 + 0x93164) -
                                   ((float)(int)*(short *)((int)fVar16 + 8) - 1.0)) * (float)param_8
                          ;
                          fVar40 = local_188 + (float)local_168 +
                                   ((float)(int)*(short *)((int)fVar16 + 6) - 1.0) * (float)param_9;
                          fVar41 = fVar24 - ((float)*(ushort *)((int)fVar16 + 0xe) +
                                            (float)_DAT_00829868) * (float)param_8;
                          fVar39 = ((float)_DAT_00829868 + (float)*(ushort *)((int)fVar16 + 0xc)) *
                                   (float)param_9 + fVar40;
                          if ((*(byte *)(local_1b0 + 0x93184) & 1) != 0) {
                            uVar23 = FUN_0052a120(local_158 - 1,iVar18 + -1,
                                                  *(ushort *)((int)fVar16 + 0xc) + 2,
                                                  *(ushort *)((int)fVar16 + 0xe) + 2);
                            uVar30 = (uint)local_174 & 0xffffff;
                            if (_DAT_00a38114 != uVar30) {
                              _DAT_00a38114 = uVar30;
                              if (DAT_00a37d78 == 0) {
                                FUN_00581200();
                              }
                              else {
                                FUN_00567b70();
                              }
                            }
                            if ((param_28 == 0) || (param_28 == 2)) {
                              fVar5 = local_148 + fVar40;
                              local_1a8 = (double)CONCAT44(local_1a8._4_4_,fVar5);
                              fVar6 = fVar41 + local_148;
                              fVar7 = fVar39 + local_148;
                              FUN_00520750(local_148 + fVar24,fVar5,local_148 + fVar24,fVar7,fVar6,
                                           fVar7,fVar6,fVar5,uVar23);
                            }
                            FUN_00515700(uVar23);
                            uVar30 = local_14c & 0xffffff;
                            if (_DAT_00a38114 != uVar30) {
                              _DAT_00a38114 = uVar30;
                              if (DAT_00a37d78 == 0) {
                                FUN_00581200();
                              }
                              else {
                                FUN_00567b70();
                              }
                            }
                          }
                          uVar23 = FUN_0052a120(local_158 - 1,iVar18 + -1,
                                                *(ushort *)((int)fVar16 + 0xc) + 2,
                                                *(ushort *)((int)fVar16 + 0xe) + 2);
                          if ((param_28 == 0) || (param_28 == 1)) {
                            fVar40 = local_148 + fVar40;
                            local_1a8 = (double)CONCAT44(local_1a8._4_4_,fVar40);
                            fVar41 = fVar41 + local_148;
                            fVar39 = fVar39 + local_148;
                            fVar24 = local_148 + fVar24;
LAB_0053d3cf:
                            FUN_00520750(fVar24,fVar40,fVar24,fVar39,fVar41,fVar39,fVar41,fVar40,
                                         CONCAT44(1,uVar23));
                          }
LAB_0053d3e4:
                          FUN_00515700();
                        }
                        else {
                          fVar40 = (float)param_8;
                          fVar24 = ((float)local_178 - (float)local_170) +
                                   (float)(int)(((uint)*(ushort *)(local_1b0 + 0x93164) -
                                                (int)*(short *)((int)fVar16 + 8)) + 1) * fVar40;
                          fVar39 = (float)local_17c + (float)local_168 +
                                   (float)(*(short *)((int)fVar16 + 6) + -1) * (float)param_9;
                          fVar41 = fVar24 + (float)(int)(-2 - (uint)*(ushort *)((int)fVar16 + 0xe))
                                            * fVar40;
                          fVar5 = fVar39 + (float)(*(ushort *)((int)fVar16 + 0xc) + 2) *
                                           (float)param_9;
                          local_1a8 = (double)fVar24;
                          FUN_0050e240((double)((float)(*(ushort *)((int)fVar16 + 0xe) + 2) * fVar40
                                               ));
                          local_ac = FUN_0050e270();
                          local_ac = local_ac + -1;
                          local_a8 = FUN_0050e270();
                          local_a8 = local_a8 + -1;
                          local_a4 = FUN_0050e270();
                          local_a4 = local_a4 + 1;
                          local_a0 = FUN_0050e270();
                          local_a0 = local_a0 + 1;
                          FUN_00514e10(&local_ac,&local_88);
                          FUN_005217e0(local_ac,local_a8,local_a4,local_a0);
                          if ((*(byte *)(local_1b0 + 0x93184) & 1) != 0) {
                            uVar23 = FUN_0052a120(local_158 - 1,iVar18 + -1,
                                                  *(ushort *)((int)fVar16 + 0xc) + 2,
                                                  *(ushort *)((int)fVar16 + 0xe) + 2);
                            uVar30 = (uint)local_174 & 0xffffff;
                            if (_DAT_00a38114 != uVar30) {
                              _DAT_00a38114 = uVar30;
                              if (DAT_00a37d78 == 0) {
                                FUN_00581200();
                              }
                              else {
                                FUN_00567b70();
                              }
                            }
                            if ((param_28 == 0) || (param_28 == 2)) {
                              fVar40 = local_148 + fVar39;
                              local_1a8 = (double)CONCAT44(local_1a8._4_4_,fVar40);
                              fVar6 = fVar41 + local_148;
                              fVar7 = fVar5 + local_148;
                              FUN_00520750(local_148 + fVar24,fVar40,local_148 + fVar24,fVar7,fVar6,
                                           fVar7,fVar6,fVar40,uVar23);
                            }
                            FUN_00515700(uVar23);
                            uVar30 = local_14c & 0xffffff;
                            if (_DAT_00a38114 != uVar30) {
                              _DAT_00a38114 = uVar30;
                              if (DAT_00a37d78 == 0) {
                                FUN_00581200();
                              }
                              else {
                                FUN_00567b70();
                              }
                            }
                          }
                          uVar23 = FUN_0052a120(local_158 - 1,iVar18 + -1,
                                                *(ushort *)((int)fVar16 + 0xc) + 2,
                                                *(ushort *)((int)fVar16 + 0xe) + 2);
                          if ((param_28 == 0) || (param_28 == 1)) {
                            fVar39 = local_148 + fVar39;
                            local_1a8 = (double)CONCAT44(local_1a8._4_4_,fVar39);
                            fVar41 = fVar41 + local_148;
                            fVar5 = fVar5 + local_148;
                            FUN_00520750(local_148 + fVar24,fVar39,local_148 + fVar24,fVar5,fVar41,
                                         fVar5,fVar41,fVar39,uVar23);
                          }
                          FUN_00515700();
                          FUN_005217e0(local_88,local_84,local_80,local_7c);
                        }
                      }
                      else if (param_7 == 0) {
                        if (param_6 == 0) {
                          uVar3 = *(ushort *)((int)fVar16 + 0xe);
                          uVar4 = *(ushort *)((int)fVar16 + 0xc);
                          fVar41 = ((float)*(ushort *)(local_1b0 + 0x93164) +
                                   (local_18c - (float)local_170)) -
                                   (float)(int)*(short *)((int)fVar16 + 8);
                          fVar16 = (float)(int)*(short *)((int)fVar16 + 6) +
                                   (float)local_168 + local_188;
                          uVar30 = local_14c & 0xffffff;
                          if (_DAT_00a38114 != uVar30) {
                            _DAT_00a38114 = uVar30;
                            if (DAT_00a37d78 == 0) {
                              FUN_00581200();
                            }
                            else {
                              FUN_00567b70();
                            }
                          }
                          if ((param_28 == 0) || (param_28 == 1)) {
                            local_1d0 = (ushort *)(local_148 + fVar16);
                            fVar40 = (fVar41 - (float)uVar3) + local_148;
                            fVar16 = (float)uVar4 + fVar16 + local_148;
                            fVar41 = local_148 + fVar41;
                            goto LAB_0053c7d2;
                          }
                        }
                        else {
                          iVar15 = FUN_0050e240(local_170);
                          iVar15 = (((uint)*(ushort *)(local_1b0 + 0x93164) -
                                    (int)*(short *)((int)fVar16 + 8)) + local_178) - iVar15;
                          iVar18 = FUN_0050e240();
                          uVar3 = *(ushort *)((int)fVar16 + 0xe);
                          iVar18 = (int)*(short *)((int)fVar16 + 6) + iVar18 + local_17c;
                          uVar4 = *(ushort *)((int)fVar16 + 0xc);
                          uVar30 = local_14c & 0xffffff;
                          if (_DAT_00a38114 != uVar30) {
                            _DAT_00a38114 = uVar30;
                            if (DAT_00a37d78 == 0) {
                              FUN_00581200();
                            }
                            else {
                              FUN_00567b70();
                            }
                          }
                          if ((param_28 == 0) || (param_28 == 1)) {
                            local_1d0 = (ushort *)(local_148 + (float)iVar18);
                            fVar40 = (float)(int)(iVar15 - (uint)uVar3) + local_148;
                            fVar16 = (float)(int)((uint)uVar4 + iVar18) + local_148;
                            fVar41 = local_148 + (float)iVar15;
LAB_0053c7d2:
                            FUN_00520750(fVar41,local_1d0,fVar41,fVar16,fVar40,fVar16,fVar40,
                                         local_1d0);
                          }
                        }
                      }
                      else if (param_6 == 0) {
                        uVar3 = *(ushort *)((int)fVar16 + 0xe);
                        uVar4 = *(ushort *)((int)fVar16 + 0xc);
                        uVar30 = local_14c & 0xffffff;
                        fVar41 = (local_18c - (float)local_170) +
                                 (float)(int)((uint)*(ushort *)(local_1b0 + 0x93164) -
                                             (int)*(short *)((int)fVar16 + 8)) * fVar40;
                        fVar16 = local_188 + (float)local_168 +
                                 (float)(int)*(short *)((int)fVar16 + 6) * fVar24;
                        if (_DAT_00a38114 != uVar30) {
                          _DAT_00a38114 = uVar30;
                          if (DAT_00a37d78 == 0) {
                            FUN_00581200();
                          }
                          else {
                            FUN_00567b70();
                          }
                        }
                        if ((param_28 == 0) || (param_28 == 1)) {
                          local_1d0 = (ushort *)(local_148 + fVar16);
                          fVar40 = (fVar41 - fVar40 * (float)uVar3) + local_148;
                          fVar16 = (float)uVar4 * fVar24 + fVar16 + local_148;
                          fVar41 = local_148 + fVar41;
                          goto LAB_0053c7d2;
                        }
                      }
                      else {
                        uVar3 = *(ushort *)((int)fVar16 + 0xe);
                        uVar4 = *(ushort *)((int)fVar16 + 0xc);
                        uVar30 = local_14c & 0xffffff;
                        fVar41 = ((float)local_178 - (float)local_170) +
                                 (float)(int)((uint)*(ushort *)(local_1b0 + 0x93164) -
                                             (int)*(short *)((int)fVar16 + 8)) * fVar40;
                        fVar16 = (float)local_17c + (float)local_168 +
                                 (float)(int)*(short *)((int)fVar16 + 6) * fVar24;
                        if (_DAT_00a38114 != uVar30) {
                          _DAT_00a38114 = uVar30;
                          if (DAT_00a37d78 == 0) {
                            FUN_00581200();
                          }
                          else {
                            FUN_00567b70();
                          }
                        }
                        if ((param_28 == 0) || (param_28 == 1)) {
                          fVar39 = local_148 + fVar16;
                          fVar40 = (fVar41 - fVar40 * (float)uVar3) + local_148;
                          fVar16 = (float)uVar4 * fVar24 + fVar16 + local_148;
                          fVar41 = local_148 + fVar41;
                          FUN_00520750(fVar41,fVar39,fVar41,fVar16,fVar40,fVar16,fVar40,fVar39);
                        }
                      }
                    }
                    else if (param_7 == 0) {
                      if (*(char *)((int)fVar16 + 5) == '\0') {
                        if ((*(byte *)(local_1b0 + 0x93184) & 1) != 0) {
                          uVar30 = (uint)local_174 & 0xffffff;
                          if (_DAT_00a38114 != uVar30) {
                            _DAT_00a38114 = uVar30;
                            if (DAT_00a37d78 == 0) {
                              FUN_00581200();
                            }
                            else {
                              FUN_00567b70();
                            }
                          }
                          if ((param_28 == 0) || (param_28 == 2)) {
                            if (param_6 == 0) {
                              FUN_0052a380(((float)(int)*(short *)((int)fVar16 + 6) +
                                           (float)local_168 + local_18c) - 1.0,
                                           ((float)(int)*(short *)((int)fVar16 + 8) +
                                           (float)local_170 + local_188) - 1.0,local_158 - 1,
                                           iVar18 + -1,*(ushort *)((int)fVar16 + 0xc) + 2,
                                           *(ushort *)((int)fVar16 + 0xe) + 2,
                                           *(undefined4 *)(local_1b0 + 0x931b4),1);
                            }
                            else {
                              iVar15 = FUN_0050e240(SUB84(local_170,0),
                                                    (int)((ulonglong)local_170 >> 0x20),local_158,
                                                    iVar18,*(undefined2 *)((int)fVar16 + 0xc),
                                                    *(undefined2 *)((int)fVar16 + 0xe),
                                                    *(undefined4 *)(local_1b0 + 0x931b4));
                              iVar15 = FUN_0050e240(SUB84(local_168,0),
                                                    (int)((ulonglong)local_168 >> 0x20),
                                                    (int)*(short *)((int)fVar16 + 8) +
                                                    iVar15 + local_17c);
                              FUN_00526e30((int)*(short *)((int)fVar16 + 6) + iVar15 + local_178);
                            }
                          }
                          uVar30 = local_14c & 0xffffff;
                          if (_DAT_00a38114 != uVar30) {
                            _DAT_00a38114 = uVar30;
                            if (DAT_00a37d78 == 0) {
                              FUN_00581200();
                            }
                            else {
                              FUN_00567b70();
                            }
                          }
                        }
                        if ((param_28 == 0) || (param_28 == 1)) {
                          if (param_6 == 0) {
                            FUN_0052a380(((float)(int)*(short *)((int)fVar16 + 6) +
                                         (float)local_168 + local_18c) - 1.0,
                                         ((float)(int)*(short *)((int)fVar16 + 8) +
                                         (float)local_170 + local_188) - 1.0,local_158 - 1,
                                         iVar18 + -1,*(ushort *)((int)fVar16 + 0xc) + 2,
                                         *(ushort *)((int)fVar16 + 0xe) + 2,
                                         *(undefined4 *)(local_1b0 + 0x931b0),1);
                          }
                          else {
                            iVar15 = FUN_0050e240(SUB84(local_170,0),
                                                  (int)((ulonglong)local_170 >> 0x20),local_158,
                                                  iVar18,*(undefined2 *)((int)fVar16 + 0xc),
                                                  *(undefined2 *)((int)fVar16 + 0xe),
                                                  *(undefined4 *)(local_1b0 + 0x931b0));
                            iVar15 = FUN_0050e240(SUB84(local_168,0),
                                                  (int)((ulonglong)local_168 >> 0x20),
                                                  (int)*(short *)((int)fVar16 + 8) +
                                                  iVar15 + local_17c);
                            FUN_00526e30((int)*(short *)((int)fVar16 + 6) + iVar15 + local_178);
                          }
                        }
                      }
                      else {
                        uVar30 = local_14c & 0xffffff;
                        if (_DAT_00a38114 != uVar30) {
                          _DAT_00a38114 = uVar30;
                          if (DAT_00a37d78 == 0) {
                            FUN_00581200();
                          }
                          else {
                            FUN_00567b70();
                          }
                        }
                        if ((param_28 == 0) || (param_28 == 1)) {
                          if (param_6 == 0) {
                            FUN_0051ecb0((float)(int)*(short *)((int)fVar16 + 6) +
                                         (float)local_168 + local_18c,
                                         (float)(int)*(short *)((int)fVar16 + 8) +
                                         (float)local_170 + local_188);
                          }
                          else {
                            iVar15 = FUN_0050e240(SUB84(local_170,0),
                                                  (int)((ulonglong)local_170 >> 0x20));
                            iVar15 = FUN_0050e240(SUB84(local_168,0),
                                                  (int)((ulonglong)local_168 >> 0x20),
                                                  (int)*(short *)((int)fVar16 + 8) +
                                                  iVar15 + local_17c);
                            FUN_0051e930((int)*(short *)((int)fVar16 + 6) + iVar15 + local_178);
                          }
                        }
                      }
                    }
                    else if (*(char *)((int)fVar16 + 5) == '\0') {
                      if (param_6 == 0) {
                        uVar3 = *(ushort *)((int)fVar16 + 0xe);
                        fVar41 = local_18c + (float)local_168 +
                                 (float)(*(short *)((int)fVar16 + 6) + -1) * fVar40;
                        local_1c0 = local_188 + (float)local_170 +
                                    (float)(*(short *)((int)fVar16 + 8) + -1) * fVar24;
                        local_1bc = fVar41 + (float)(*(ushort *)((int)fVar16 + 0xc) + 2) * fVar40;
                      }
                      else {
                        uVar3 = *(ushort *)((int)fVar16 + 0xe);
                        fVar41 = (float)local_178 + (float)local_168 +
                                 (float)(*(short *)((int)fVar16 + 6) + -1) * fVar40;
                        local_1c0 = (float)local_17c + (float)local_170 +
                                    (float)(*(short *)((int)fVar16 + 8) + -1) * fVar24;
                        local_1bc = fVar41 + (float)(*(ushort *)((int)fVar16 + 0xc) + 2) * fVar40;
                      }
                      local_1d0 = (ushort *)(uVar3 + 2);
                      local_1a8 = (double)CONCAT44(local_1a8._4_4_,fVar41);
                      fVar24 = (float)(int)local_1d0 * fVar24 + local_1c0;
                      if ((*(byte *)(local_1b0 + 0x93184) & 1) != 0) {
                        uVar30 = (uint)local_174 & 0xffffff;
                        if (_DAT_00a38114 != uVar30) {
                          _DAT_00a38114 = uVar30;
                          if (DAT_00a37d78 == 0) {
                            FUN_00581200();
                          }
                          else {
                            FUN_00567b70();
                          }
                        }
                        if ((param_28 == 0) || (param_28 == 2)) {
                          FUN_0052a430((float)local_1a8,local_1c0,local_1bc,fVar24,local_158 - 1,
                                       iVar18 + -1,*(ushort *)((int)fVar16 + 0xc) + 2,
                                       *(ushort *)((int)fVar16 + 0xe) + 2);
                          uVar30 = local_14c & 0xffffff;
                          if (_DAT_00a38114 != uVar30) {
                            _DAT_00a38114 = uVar30;
                            if (DAT_00a37d78 == 0) {
                              FUN_00581200();
                            }
                            else {
                              FUN_00567b70();
                            }
                          }
                        }
                      }
                      if ((param_28 == 0) || (param_28 == 1)) {
                        if (param_6 == 0) {
                          uVar4 = *(ushort *)((int)fVar16 + 0xe);
                          uVar3 = *(ushort *)((int)fVar16 + 0xc);
                        }
                        else {
                          uVar4 = *(ushort *)((int)fVar16 + 0xe);
                          uVar3 = *(ushort *)((int)fVar16 + 0xc);
                        }
                        FUN_0052a430((float)local_1a8,local_1c0,local_1bc,fVar24,local_158 - 1,
                                     iVar18 + -1,uVar3 + 2,uVar4 + 2);
                      }
                    }
                    else {
                      if (param_6 == 0) {
                        uVar3 = *(ushort *)((int)fVar16 + 0xe);
                        fVar41 = local_18c + (float)local_168 +
                                 (float)(int)*(short *)((int)fVar16 + 6) * fVar40;
                        local_1c0 = local_188 + (float)local_170 +
                                    (float)(int)*(short *)((int)fVar16 + 8) * fVar24;
                        local_1bc = fVar41 + (float)*(ushort *)((int)fVar16 + 0xc) * fVar40;
                      }
                      else {
                        uVar3 = *(ushort *)((int)fVar16 + 0xe);
                        fVar41 = (float)local_178 + (float)local_168 +
                                 (float)(int)*(short *)((int)fVar16 + 6) * fVar40;
                        local_1c0 = (float)local_17c + (float)local_170 +
                                    (float)(int)*(short *)((int)fVar16 + 8) * fVar24;
                        local_1bc = fVar41 + (float)*(ushort *)((int)fVar16 + 0xc) * fVar40;
                      }
                      local_1d0 = (ushort *)(uint)uVar3;
                      local_1a8 = (double)CONCAT44(local_1a8._4_4_,fVar41);
                      uVar30 = local_14c & 0xffffff;
                      if (_DAT_00a38114 != uVar30) {
                        _DAT_00a38114 = uVar30;
                        if (DAT_00a37d78 == 0) {
                          FUN_00581200();
                        }
                        else {
                          FUN_00567b70();
                        }
                      }
                      if ((param_28 == 0) || (param_28 == 1)) {
                        FUN_0051f460((float)local_1a8,local_1c0,local_1bc,
                                     (float)(int)local_1d0 * fVar24 + local_1c0);
                      }
                    }
                  }
                  else {
                    cVar2 = *(char *)((int)fVar16 + 5);
                    iVar15 = (int)*(short *)((int)fVar16 + 6);
                    fVar41 = (float)local_168;
                    if (param_22 == 1) {
                      if (cVar2 == '\0') {
                        fVar41 = fVar41 / fVar24 + ((float)iVar15 - 1.0);
                        local_1c4 = (fVar41 - param_11) * fVar24;
                        fVar39 = (float)local_170 / fVar40 +
                                 ((float)(int)*(short *)((int)fVar16 + 8) - 1.0);
                        local_1d0 = (ushort *)((fVar39 - param_12) * fVar40);
                        local_1c8 = (((float)*(ushort *)((int)fVar16 + 0xc) + (float)_DAT_00829868 +
                                     fVar41) - param_11) * fVar24;
                        local_1cc = (ushort *)
                                    (fVar40 * (((float)*(ushort *)((int)fVar16 + 0xe) +
                                                (float)_DAT_00829868 + fVar39) - param_12));
                      }
                      else {
                        fVar41 = (float)iVar15 + fVar41 / fVar24;
                        local_1c4 = (fVar41 - param_11) * fVar24;
                        fVar39 = (float)(int)*(short *)((int)fVar16 + 8) + (float)local_170 / fVar40
                        ;
                        local_1d0 = (ushort *)((fVar39 - param_12) * fVar40);
                        local_1c8 = (((float)*(ushort *)((int)fVar16 + 0xc) + fVar41) - param_11) *
                                    fVar24;
                        local_1cc = (ushort *)
                                    (fVar40 * (((float)*(ushort *)((int)fVar16 + 0xe) + fVar39) -
                                              param_12));
                      }
                    }
                    else {
                      if (cVar2 == '\0') {
                        fVar41 = fVar41 / fVar40 + ((float)iVar15 - 1.0);
                        fVar5 = (float)local_170 / fVar24 +
                                ((float)(int)*(short *)((int)fVar16 + 8) - 1.0);
                        fVar39 = (float)*(ushort *)((int)fVar16 + 0xc) + (float)_DAT_00829868 +
                                 fVar41;
                        fVar16 = (float)*(ushort *)((int)fVar16 + 0xe) + (float)_DAT_00829868 +
                                 fVar5;
                      }
                      else {
                        fVar41 = (float)iVar15 + fVar41 / fVar40;
                        fVar5 = (float)(int)*(short *)((int)fVar16 + 8) + (float)local_170 / fVar24;
                        fVar39 = (float)*(ushort *)((int)fVar16 + 0xc) + fVar41;
                        fVar16 = (float)*(ushort *)((int)fVar16 + 0xe) + fVar5;
                      }
                      local_1c4 = (fVar41 - param_11) * fVar40;
                      local_1c8 = (fVar39 - param_11) * fVar40;
                      local_1d0 = (ushort *)((fVar5 - param_12) * fVar24);
                      local_1cc = (ushort *)(fVar24 * (fVar16 - param_12));
                    }
                    fVar5 = local_bc * local_1c4;
                    local_1a8 = (double)CONCAT44(local_1a8._4_4_,fVar5);
                    local_1c4 = local_c0 * local_1c4;
                    fVar39 = (float)local_1d0 * local_bc;
                    fVar16 = (float)local_1d0 * local_c0;
                    fVar41 = local_1c8 * local_bc;
                    local_1c8 = local_1c8 * local_c0;
                    fVar40 = (float)local_1cc * local_bc;
                    fVar24 = (float)local_1cc * local_c0;
                    if (param_6 != 0) {
                      local_18c = local_148 + (float)local_178;
                      local_188 = local_148 + (float)local_17c;
                    }
                    if (cVar2 == '\0') {
                      local_4c = &local_140;
                      local_140 = (IMAGE_RICH_HEADER *)(local_18c + (local_1c4 - fVar39));
                      local_50 = 1;
                      local_13c = local_188 + fVar5 + fVar16;
                      local_130 = local_18c + (local_1c8 - fVar39);
                      local_12c = local_188 + fVar41 + fVar16;
                      local_120 = local_18c + (local_1c4 - fVar40);
                      local_11c = local_188 + fVar24 + fVar5;
                      local_110 = (local_1c8 - fVar40) + local_18c;
                      local_10c = fVar41 + fVar24 + local_188;
                      fVar16 = (float)(int)(local_fc - 1) * *(float *)(local_1b0 + 0x9360c);
                      local_134 = (float)(local_f8 + -1) * *(float *)(local_1b0 + 0x93610);
                      fVar24 = (float)(local_f4 + 1) * *(float *)(local_1b0 + 0x9360c);
                      local_114 = (float)(local_f0 + 1) * *(float *)(local_1b0 + 0x93610);
                      local_48 = *(undefined4 *)(local_1b0 + 0x931b0);
                      local_44 = 1;
                      local_124 = local_134;
                      local_104 = local_114;
                      if ((*(byte *)(local_1b0 + 0x93184) & 1) != 0) {
                        uVar30 = (uint)local_174 & 0xffffff;
                        local_138 = fVar16 + (float)_DAT_00804a60;
                        local_128 = fVar24 + (float)_DAT_00804a60;
                        local_118 = local_138;
                        local_108 = local_128;
                        if (_DAT_00a38114 != uVar30) {
                          _DAT_00a38114 = uVar30;
                          if (DAT_00a37d78 == 0) {
                            FUN_00581200();
                          }
                          else {
                            FUN_00567b70();
                          }
                        }
                        if ((param_28 == 0) || (param_28 == 2)) {
                          FUN_0051ba30();
                        }
                        uVar30 = local_14c & 0xffffff;
                        if (_DAT_00a38114 != uVar30) {
                          _DAT_00a38114 = uVar30;
                          if (DAT_00a37d78 == 0) {
                            FUN_00581200();
                          }
                          else {
                            FUN_00567b70();
                          }
                        }
                      }
                      local_138 = fVar16;
                      local_128 = fVar24;
                      local_118 = fVar16;
                      local_108 = fVar24;
                      if ((param_28 == 0) || (param_28 == 1)) {
                        FUN_0051ba30();
                      }
                    }
                    else {
                      uVar30 = local_14c & 0xffffff;
                      if (_DAT_00a38114 != uVar30) {
                        _DAT_00a38114 = uVar30;
                        if (DAT_00a37d78 == 0) {
                          FUN_00581200();
                        }
                        else {
                          FUN_00567b70();
                        }
                      }
                      if ((param_28 == 0) || (param_28 == 1)) {
                        fVar6 = (float)local_1a8;
                        fVar5 = local_188 + (float)local_1a8 + fVar24;
                        local_1a8 = (double)CONCAT44(local_1a8._4_4_,fVar5);
                        FUN_00520750(local_18c + (local_1c4 - fVar39),fVar16 + fVar6 + local_188,
                                     local_18c + (local_1c8 - fVar39),local_188 + fVar16 + fVar41,
                                     local_18c + (local_1c8 - fVar40),local_188 + fVar41 + fVar24,
                                     local_18c + (local_1c4 - fVar40),fVar5);
                      }
                    }
                  }
                  if (local_198 != (ushort *)0xffffffff) {
                    if (DAT_00a380e8 == 0) {
                      FUN_005270f0(local_198);
                    }
                  }
                }
                else if (param_16 != 0) {
                  bVar28 = (byte)param_15;
                  bVar10 = (byte)(param_15 >> 8);
                  bVar11 = (byte)(param_15 >> 0x10);
                  bVar27 = (byte)param_20;
                  bVar12 = (byte)(param_20 >> 8);
                  bVar29 = (byte)(param_20 >> 0x10);
                  if (param_22 == 1) {
                    iVar17 = FUN_0050e240(local_170);
                    iVar17 = ((((uint)*(ushort *)(local_1b0 + 0x93164) -
                               (uint)*(ushort *)((int)fVar16 + 0xe)) -
                              (int)*(short *)((int)fVar16 + 8)) + local_178) - iVar17;
                    local_e4 = iVar17;
                    local_dc = FUN_0050e240(local_170);
                    local_dc = (((uint)*(ushort *)(local_1b0 + 0x93164) -
                                (int)*(short *)((int)fVar16 + 8)) + local_178) - local_dc;
                    iVar18 = FUN_0050e240(local_168);
                    local_e0 = (int)*(short *)((int)fVar16 + 6) + iVar18 + local_17c;
                    iVar19 = FUN_0050e240();
                    iVar18 = local_e0;
                    local_d8 = (int)*(short *)((int)fVar16 + 6) +
                               (uint)*(ushort *)((int)fVar16 + 0xc) + local_17c + iVar19;
                    local_58 = local_dc;
                    local_60 = iVar17;
                    local_54 = local_d8;
                    FUN_00514e10(&local_e4,param_17);
                    iVar17 = local_e0;
                    if (local_dc != local_e4) {
                      if (local_d8 != local_e0) {
                        local_fc = local_fc + (local_e0 - iVar18);
                        local_f8 = local_f8 + (local_dc - local_58);
                        local_f4 = local_f4 + (local_d8 - local_54);
                        local_f0 = local_f0 + (local_e4 - local_60);
                        uVar35 = local_f4 - local_fc;
                        local_1a8 = (double)(CONCAT44(local_1a8._4_4_,local_f0 - local_f8) &
                                            0xffffffff0000ffff);
                        iVar18 = FUN_005167e0();
                        local_1c0._0_2_ = (short)uVar35;
                        uVar30 = (int)local_fc >> 0x1f;
                        if (iVar18 == 8) {
                          iVar15 = *(int *)(*(int *)(param_16 + 0x14) + 0xc);
                          iVar18 = *(int *)(local_1b0 + 0x90d90);
                          local_198 = *(ushort **)(local_1b0 + 0x90d8c);
                          pbVar36 = (byte *)(iVar15 * iVar17 + *(int *)(param_16 + 0xc) + local_dc);
                          iVar15 = -1 - iVar15 * uVar35;
                          pcVar21 = (char *)((int)local_198 + local_fc + iVar18 * local_f8);
                          if (*(int *)(local_1b0 + 0x93184) == 0) {
                            uVar32 = local_fc & 0x80000007;
                            local_140 = &DAT_00400080;
                            local_13c = 1.469413e-39;
                            local_138 = 3.67353e-40;
                            local_134 = 9.18383e-41;
                            local_130 = 2.0078125;
                            local_12c = 2.52682e-29;
                            local_128 = 1.5050001e-36;
                            local_124 = 2.3511322e-38;
                            if ((int)uVar32 < 0) {
                              uVar32 = (uVar32 - 1 | 0xfffffff8) + 1;
                            }
                            local_1d0 = (ushort *)
                                        (((int)(local_fc + (uVar30 & 7)) >> 3) + iVar18 * local_f8 +
                                        (int)local_198);
                            iVar18 = iVar18 - (uVar35 + 7 >> 3);
                            uVar3 = *(ushort *)((int)&local_140 + uVar32 * 2);
                            if (param_18 == 0) {
                              do {
                                sVar34 = local_1c0._0_2_;
                                do {
                                  uVar4 = *local_1d0;
                                  if ((uVar3 & uVar4) == 0) {
                                    bVar27 = 0;
                                  }
                                  else {
                                    bVar27 = bVar28;
                                  }
                                  *pbVar36 = bVar27;
                                  pbVar36 = pbVar36 + local_180;
                                  sVar9 = 0;
                                  if (sVar34 != 1) {
                                    if ((*(ushort *)((int)&local_140 + uVar32 * 2 + 2) & uVar4) == 0
                                       ) {
                                      bVar27 = 0;
                                    }
                                    else {
                                      bVar27 = bVar28;
                                    }
                                    *pbVar36 = bVar27;
                                    pbVar36 = pbVar36 + local_180;
                                    sVar9 = 0;
                                    if (sVar34 != 2) {
                                      if ((*(ushort *)((int)&local_13c + uVar32 * 2) & uVar4) == 0)
                                      {
                                        bVar27 = 0;
                                      }
                                      else {
                                        bVar27 = bVar28;
                                      }
                                      *pbVar36 = bVar27;
                                      pbVar36 = pbVar36 + local_180;
                                      sVar9 = 0;
                                      if (sVar34 != 3) {
                                        if ((*(ushort *)((int)&local_13c + uVar32 * 2 + 2) & uVar4)
                                            == 0) {
                                          bVar27 = 0;
                                        }
                                        else {
                                          bVar27 = bVar28;
                                        }
                                        *pbVar36 = bVar27;
                                        pbVar36 = pbVar36 + local_180;
                                        sVar9 = 0;
                                        if (sVar34 != 4) {
                                          if ((*(ushort *)((int)&local_138 + uVar32 * 2) & uVar4) ==
                                              0) {
                                            bVar27 = 0;
                                          }
                                          else {
                                            bVar27 = bVar28;
                                          }
                                          *pbVar36 = bVar27;
                                          pbVar36 = pbVar36 + local_180;
                                          sVar9 = 0;
                                          if (sVar34 != 5) {
                                            if ((*(ushort *)((int)&local_138 + uVar32 * 2 + 2) &
                                                uVar4) == 0) {
                                              bVar27 = 0;
                                            }
                                            else {
                                              bVar27 = bVar28;
                                            }
                                            *pbVar36 = bVar27;
                                            pbVar36 = pbVar36 + local_180;
                                            sVar9 = 0;
                                            if (sVar34 != 6) {
                                              if ((*(ushort *)((int)&local_134 + uVar32 * 2) & uVar4
                                                  ) == 0) {
                                                bVar27 = 0;
                                              }
                                              else {
                                                bVar27 = bVar28;
                                              }
                                              *pbVar36 = bVar27;
                                              pbVar36 = pbVar36 + local_180;
                                              sVar9 = 0;
                                              if (sVar34 != 7) {
                                                if ((*(ushort *)((int)&local_134 + uVar32 * 2 + 2) &
                                                    uVar4) == 0) {
                                                  bVar27 = 0;
                                                }
                                                else {
                                                  bVar27 = bVar28;
                                                }
                                                *pbVar36 = bVar27;
                                                pbVar36 = pbVar36 + local_180;
                                                sVar9 = sVar34 + -8;
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                  sVar34 = sVar9;
                                  local_1d0 = (ushort *)((int)local_1d0 + 1);
                                } while (sVar34 != 0);
                                local_1d0 = (ushort *)((int)local_1d0 + iVar18);
                                pbVar36 = pbVar36 + iVar15;
                                iVar17 = (int)(float)local_1a8 + 0xffff;
                                local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar17);
                              } while ((short)iVar17 != 0);
                            }
                            else {
                              do {
                                sVar34 = local_1c0._0_2_;
                                do {
                                  uVar4 = *local_1d0;
                                  if ((uVar3 & uVar4) != 0) {
                                    *pbVar36 = bVar28;
                                  }
                                  pbVar36 = pbVar36 + local_180;
                                  sVar9 = 0;
                                  if (sVar34 != 1) {
                                    if ((*(ushort *)((int)&local_140 + uVar32 * 2 + 2) & uVar4) != 0
                                       ) {
                                      *pbVar36 = bVar28;
                                    }
                                    pbVar36 = pbVar36 + local_180;
                                    sVar9 = 0;
                                    if (sVar34 != 2) {
                                      if ((*(ushort *)((int)&local_13c + uVar32 * 2) & uVar4) != 0)
                                      {
                                        *pbVar36 = bVar28;
                                      }
                                      pbVar36 = pbVar36 + local_180;
                                      sVar9 = 0;
                                      if (sVar34 != 3) {
                                        if ((*(ushort *)((int)&local_13c + uVar32 * 2 + 2) & uVar4)
                                            != 0) {
                                          *pbVar36 = bVar28;
                                        }
                                        pbVar36 = pbVar36 + local_180;
                                        sVar9 = 0;
                                        if (sVar34 != 4) {
                                          if ((*(ushort *)((int)&local_138 + uVar32 * 2) & uVar4) !=
                                              0) {
                                            *pbVar36 = bVar28;
                                          }
                                          pbVar36 = pbVar36 + local_180;
                                          sVar9 = 0;
                                          if (sVar34 != 5) {
                                            if ((*(ushort *)((int)&local_138 + uVar32 * 2 + 2) &
                                                uVar4) != 0) {
                                              *pbVar36 = bVar28;
                                            }
                                            pbVar36 = pbVar36 + local_180;
                                            sVar9 = 0;
                                            if (sVar34 != 6) {
                                              if ((*(ushort *)((int)&local_134 + uVar32 * 2) & uVar4
                                                  ) != 0) {
                                                *pbVar36 = bVar28;
                                              }
                                              pbVar36 = pbVar36 + local_180;
                                              sVar9 = 0;
                                              if (sVar34 != 7) {
                                                if ((*(ushort *)((int)&local_134 + uVar32 * 2 + 2) &
                                                    uVar4) != 0) {
                                                  *pbVar36 = bVar28;
                                                }
                                                pbVar36 = pbVar36 + local_180;
                                                sVar9 = sVar34 + -8;
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                  sVar34 = sVar9;
                                  local_1d0 = (ushort *)((int)local_1d0 + 1);
                                } while (sVar34 != 0);
                                local_1d0 = (ushort *)((int)local_1d0 + iVar18);
                                pbVar36 = pbVar36 + iVar15;
                                iVar17 = (int)(float)local_1a8 + 0xffff;
                                local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar17);
                              } while ((short)iVar17 != 0);
                            }
                          }
                          else if (*(int *)(local_1b0 + 0x93184) == 1) {
                            iVar17 = (int)(float)local_1a8;
                            if (param_18 == 0) {
                              do {
                                sVar34 = local_1c0._0_2_;
                                do {
                                  if (*pcVar21 == '\0') {
                                    bVar29 = 0;
                                  }
                                  else {
                                    bVar29 = bVar28;
                                    if (*pcVar21 != '\x01') {
                                      bVar29 = bVar27;
                                    }
                                  }
                                  *pbVar36 = bVar29;
                                  sVar34 = sVar34 + -1;
                                  pbVar36 = pbVar36 + local_180;
                                  pcVar21 = pcVar21 + 1;
                                } while (sVar34 != 0);
                                pbVar36 = pbVar36 + iVar15;
                                pcVar21 = pcVar21 + (iVar18 - uVar35);
                                iVar17 = iVar17 + 0xffff;
                              } while ((short)iVar17 != 0);
                            }
                            else {
                              do {
                                sVar34 = local_1c0._0_2_;
                                do {
                                  if (*pcVar21 != '\0') {
                                    bVar29 = bVar28;
                                    if (*pcVar21 != '\x01') {
                                      bVar29 = bVar27;
                                    }
                                    *pbVar36 = bVar29;
                                  }
                                  sVar34 = sVar34 + -1;
                                  pbVar36 = pbVar36 + local_180;
                                  pcVar21 = pcVar21 + 1;
                                } while (sVar34 != 0);
                                pbVar36 = pbVar36 + iVar15;
                                pcVar21 = pcVar21 + (iVar18 - uVar35);
                                iVar17 = iVar17 + 0xffff;
                              } while ((short)iVar17 != 0);
                            }
                          }
                        }
                        else if (iVar18 == 0x10) {
                          iVar17 = iVar17 * local_180;
                          iVar18 = *(int *)(param_16 + 0xc);
                          puVar26 = (undefined2 *)(iVar18 + local_dc * 2 + iVar17);
                          local_198 = *(ushort **)(local_1b0 + 0x90d8c);
                          pbVar36 = (byte *)((int)local_198 + local_fc + iVar15 * local_f8);
                          iVar19 = iVar15 - uVar35;
                          iVar31 = uVar35 * local_180;
                          iVar20 = -2 - iVar31;
                          switch(*(undefined4 *)(local_1b0 + 0x93184)) {
                          case 0:
                            uVar32 = local_fc & 0x80000007;
                            if ((int)uVar32 < 0) {
                              uVar32 = (uVar32 - 1 | 0xfffffff8) + 1;
                            }
                            local_1cc = (ushort *)
                                        ((int)local_198 +
                                        iVar15 * local_f8 + ((int)(local_fc + (uVar30 & 7)) >> 3));
                            iVar15 = iVar15 - (uVar35 + 7 >> 3);
                            local_140 = &DAT_00400080;
                            local_13c = 1.469413e-39;
                            local_138 = 3.67353e-40;
                            local_134 = 9.18383e-41;
                            local_130 = 2.0078125;
                            local_12c = 2.52682e-29;
                            local_128 = 1.5050001e-36;
                            local_124 = 2.3511322e-38;
                            uVar3 = *(ushort *)((int)&local_140 + uVar32 * 2);
                            if (param_18 == 0) {
                              do {
                                sVar34 = local_1c0._0_2_;
                                do {
                                  uVar4 = *local_1cc;
                                  if ((uVar4 & uVar3) == 0) {
                                    uVar14 = 0;
                                  }
                                  else {
                                    uVar14 = (undefined2)param_15;
                                  }
                                  *puVar26 = uVar14;
                                  puVar26 = (undefined2 *)((int)puVar26 + local_180);
                                  sVar9 = 0;
                                  if (sVar34 != 1) {
                                    if ((*(ushort *)((int)&local_140 + uVar32 * 2 + 2) & uVar4) == 0
                                       ) {
                                      uVar14 = 0;
                                    }
                                    else {
                                      uVar14 = (undefined2)param_15;
                                    }
                                    *puVar26 = uVar14;
                                    puVar26 = (undefined2 *)((int)puVar26 + local_180);
                                    sVar9 = 0;
                                    if (sVar34 != 2) {
                                      if ((*(ushort *)((int)&local_13c + uVar32 * 2) & uVar4) == 0)
                                      {
                                        uVar14 = 0;
                                      }
                                      else {
                                        uVar14 = (undefined2)param_15;
                                      }
                                      *puVar26 = uVar14;
                                      puVar26 = (undefined2 *)((int)puVar26 + local_180);
                                      sVar9 = 0;
                                      if (sVar34 != 3) {
                                        if ((*(ushort *)((int)&local_13c + uVar32 * 2 + 2) & uVar4)
                                            == 0) {
                                          uVar14 = 0;
                                        }
                                        else {
                                          uVar14 = (undefined2)param_15;
                                        }
                                        *puVar26 = uVar14;
                                        puVar26 = (undefined2 *)((int)puVar26 + local_180);
                                        sVar9 = 0;
                                        if (sVar34 != 4) {
                                          if ((*(ushort *)((int)&local_138 + uVar32 * 2) & uVar4) ==
                                              0) {
                                            uVar14 = 0;
                                          }
                                          else {
                                            uVar14 = (undefined2)param_15;
                                          }
                                          *puVar26 = uVar14;
                                          puVar26 = (undefined2 *)((int)puVar26 + local_180);
                                          sVar9 = 0;
                                          if (sVar34 != 5) {
                                            if ((*(ushort *)((int)&local_138 + uVar32 * 2 + 2) &
                                                uVar4) == 0) {
                                              uVar14 = 0;
                                            }
                                            else {
                                              uVar14 = (undefined2)param_15;
                                            }
                                            *puVar26 = uVar14;
                                            puVar26 = (undefined2 *)((int)puVar26 + local_180);
                                            sVar9 = 0;
                                            if (sVar34 != 6) {
                                              if ((*(ushort *)((int)&local_134 + uVar32 * 2) & uVar4
                                                  ) == 0) {
                                                uVar14 = 0;
                                              }
                                              else {
                                                uVar14 = (undefined2)param_15;
                                              }
                                              *puVar26 = uVar14;
                                              puVar26 = (undefined2 *)((int)puVar26 + local_180);
                                              sVar9 = 0;
                                              if (sVar34 != 7) {
                                                if ((*(ushort *)((int)&local_134 + uVar32 * 2 + 2) &
                                                    uVar4) == 0) {
                                                  uVar14 = 0;
                                                }
                                                else {
                                                  uVar14 = (undefined2)param_15;
                                                }
                                                *puVar26 = uVar14;
                                                puVar26 = (undefined2 *)((int)puVar26 + local_180);
                                                sVar9 = sVar34 + -8;
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                  sVar34 = sVar9;
                                  local_1cc = (ushort *)((int)local_1cc + 1);
                                } while (sVar34 != 0);
                                local_1cc = (ushort *)((int)local_1cc + iVar15);
                                puVar26 = (undefined2 *)((int)puVar26 + iVar20);
                                iVar18 = (int)(float)local_1a8 + 0xffff;
                                local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar18);
                              } while ((short)iVar18 != 0);
                            }
                            else {
                              do {
                                sVar34 = local_1c0._0_2_;
                                do {
                                  uVar4 = *local_1cc;
                                  if ((uVar4 & uVar3) != 0) {
                                    *puVar26 = (undefined2)param_15;
                                  }
                                  puVar26 = (undefined2 *)((int)puVar26 + local_180);
                                  sVar9 = 0;
                                  if (sVar34 != 1) {
                                    if ((*(ushort *)((int)&local_140 + uVar32 * 2 + 2) & uVar4) != 0
                                       ) {
                                      *puVar26 = (undefined2)param_15;
                                    }
                                    puVar26 = (undefined2 *)((int)puVar26 + local_180);
                                    sVar9 = 0;
                                    if (sVar34 != 2) {
                                      if ((*(ushort *)((int)&local_13c + uVar32 * 2) & uVar4) != 0)
                                      {
                                        *puVar26 = (undefined2)param_15;
                                      }
                                      puVar26 = (undefined2 *)((int)puVar26 + local_180);
                                      sVar9 = 0;
                                      if (sVar34 != 3) {
                                        if ((*(ushort *)((int)&local_13c + uVar32 * 2 + 2) & uVar4)
                                            != 0) {
                                          *puVar26 = (undefined2)param_15;
                                        }
                                        puVar26 = (undefined2 *)((int)puVar26 + local_180);
                                        sVar9 = 0;
                                        if (sVar34 != 4) {
                                          if ((*(ushort *)((int)&local_138 + uVar32 * 2) & uVar4) !=
                                              0) {
                                            *puVar26 = (undefined2)param_15;
                                          }
                                          puVar26 = (undefined2 *)((int)puVar26 + local_180);
                                          sVar9 = 0;
                                          if (sVar34 != 5) {
                                            if ((*(ushort *)((int)&local_138 + uVar32 * 2 + 2) &
                                                uVar4) != 0) {
                                              *puVar26 = (undefined2)param_15;
                                            }
                                            puVar26 = (undefined2 *)((int)puVar26 + local_180);
                                            sVar9 = 0;
                                            if (sVar34 != 6) {
                                              if ((*(ushort *)((int)&local_134 + uVar32 * 2) & uVar4
                                                  ) != 0) {
                                                *puVar26 = (undefined2)param_15;
                                              }
                                              puVar26 = (undefined2 *)((int)puVar26 + local_180);
                                              sVar9 = 0;
                                              if (sVar34 != 7) {
                                                if ((*(ushort *)((int)&local_134 + uVar32 * 2 + 2) &
                                                    uVar4) != 0) {
                                                  *puVar26 = (undefined2)param_15;
                                                }
                                                puVar26 = (undefined2 *)((int)puVar26 + local_180);
                                                sVar9 = sVar34 + -8;
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                  sVar34 = sVar9;
                                  local_1cc = (ushort *)((int)local_1cc + 1);
                                } while (sVar34 != 0);
                                local_1cc = (ushort *)((int)local_1cc + iVar15);
                                puVar26 = (undefined2 *)((int)puVar26 + iVar20);
                                iVar18 = (int)(float)local_1a8 + 0xffff;
                                local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar18);
                              } while ((short)iVar18 != 0);
                            }
                            break;
                          case 1:
                            iVar15 = (int)(float)local_1a8;
                            if (param_18 == 0) {
                              do {
                                sVar34 = local_1c0._0_2_;
                                do {
                                  if (*pbVar36 == 0) {
                                    uVar14 = 0;
                                  }
                                  else {
                                    uVar14 = (undefined2)param_15;
                                    if (*pbVar36 != 1) {
                                      uVar14 = (undefined2)param_20;
                                    }
                                  }
                                  *puVar26 = uVar14;
                                  sVar34 = sVar34 + -1;
                                  puVar26 = (undefined2 *)((int)puVar26 + local_180);
                                  pbVar36 = pbVar36 + 1;
                                } while (sVar34 != 0);
                                puVar26 = (undefined2 *)((int)puVar26 + iVar20);
                                pbVar36 = pbVar36 + iVar19;
                                iVar15 = iVar15 + 0xffff;
                              } while ((short)iVar15 != 0);
                            }
                            else {
                              do {
                                sVar34 = local_1c0._0_2_;
                                do {
                                  if (*pbVar36 != 0) {
                                    uVar14 = (undefined2)param_15;
                                    if (*pbVar36 != 1) {
                                      uVar14 = (undefined2)param_20;
                                    }
                                    *puVar26 = uVar14;
                                  }
                                  sVar34 = sVar34 + -1;
                                  puVar26 = (undefined2 *)((int)puVar26 + local_180);
                                  pbVar36 = pbVar36 + 1;
                                } while (sVar34 != 0);
                                puVar26 = (undefined2 *)((int)puVar26 + iVar20);
                                pbVar36 = pbVar36 + iVar19;
                                iVar15 = iVar15 + 0xffff;
                              } while ((short)iVar15 != 0);
                            }
                            break;
                          case 2:
                          case 0x12:
                          case 0x22:
                            puVar25 = (uint *)(iVar18 + local_dc * 4 + iVar17);
                            if (param_18 == 0) {
                              do {
                                sVar34 = local_1c0._0_2_;
                                do {
                                  if (*pbVar36 == 0) {
                                    *puVar25 = 0;
                                  }
                                  else {
                                    *puVar25 = (uint)*pbVar36 << 0x14 | param_15 & 0xffff;
                                  }
                                  sVar34 = sVar34 + -1;
                                  puVar25 = (uint *)((int)puVar25 + local_180);
                                  pbVar36 = pbVar36 + 1;
                                } while (sVar34 != 0);
                                puVar25 = (uint *)((int)puVar25 + (-4 - iVar31));
                                pbVar36 = pbVar36 + iVar19;
                                iVar15 = (int)(float)local_1a8 + 0xffff;
                                local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar15);
                              } while ((short)iVar15 != 0);
                            }
                            else {
                              do {
                                sVar34 = local_1c0._0_2_;
                                do {
                                  if (*pbVar36 != 0) {
                                    *puVar25 = (uint)*pbVar36 << 0x14 | param_15 & 0xffff;
                                  }
                                  sVar34 = sVar34 + -1;
                                  puVar25 = (uint *)((int)puVar25 + local_180);
                                  pbVar36 = pbVar36 + 1;
                                } while (sVar34 != 0);
                                puVar25 = (uint *)((int)puVar25 + (-4 - iVar31));
                                pbVar36 = pbVar36 + iVar19;
                                iVar15 = (int)(float)local_1a8 + 0xffff;
                                local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar15);
                              } while ((short)iVar15 != 0);
                            }
                            break;
                          case 3:
                          case 0x13:
                          case 0x23:
                            local_19a = (byte)(param_15 >> 0xb) & 0x1f;
                            uVar30 = param_15 >> 5;
                            local_198._1_3_ = (undefined3)((uint)local_198 >> 8);
                            local_198 = (ushort *)
                                        (CONCAT31(local_198._1_3_,(char)uVar30) & 0xffffff3f);
                            local_199 = (byte)(param_20 >> 0xb) & 0x1f;
                            local_191 = (byte)(param_20 >> 5) & 0x3f;
                            local_1a9 = bVar27 & 0x1f;
                            puVar25 = (uint *)(iVar18 + local_dc * 4 + iVar17);
                            if (param_18 == 0) {
                              do {
                                local_1c4 = (float)(uVar35 & 0xffff);
                                do {
                                  bVar28 = *pbVar36;
                                  bVar27 = bVar28 & 0xf;
                                  if (bVar27 == 0) {
                                    if ((bVar28 & 0xf0) == 0) {
                                      *puVar25 = 0;
                                    }
                                    else {
                                      *puVar25 = (bVar28 & 0xf0) << 0x10 | param_20;
                                    }
                                  }
                                  else if (bVar27 == 0xf) {
                                    *puVar25 = param_15 & 0xffff | 0xff0000;
                                  }
                                  else {
                                    bVar28 = (bVar28 >> 4) * ('\x0f' - bVar27) + bVar28 * '\x10';
                                    *(byte *)((int)puVar25 + 2) = bVar28;
                                    uVar32 = ((*pbVar36 & 0xf) << 0xc) / (uint)bVar28;
                                    *(ushort *)puVar25 =
                                         ((short)(((uint)local_19a - (uint)local_199) * uVar32 >> 8)
                                         + (ushort)local_199) * 0x800 |
                                         ((short)(((uVar30 & 0x3f) - (uint)local_191) * uVar32 >> 8)
                                         + (ushort)local_191) * 0x20 |
                                         (short)(((param_15 & 0x1f) - (uint)local_1a9) * uVar32 >> 8
                                                ) + (ushort)local_1a9;
                                  }
                                  local_1c4 = (float)((int)local_1c4 + 0xffff);
                                  puVar25 = (uint *)((int)puVar25 + local_180);
                                  pbVar36 = pbVar36 + 1;
                                } while (SUB42(local_1c4,0) != 0);
                                puVar25 = (uint *)((int)puVar25 + (-4 - iVar31));
                                pbVar36 = pbVar36 + iVar19;
                                iVar15 = (int)(float)local_1a8 + 0xffff;
                                local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar15);
                              } while ((short)iVar15 != 0);
                            }
                            else {
                              do {
                                local_1c4 = (float)(uVar35 & 0xffff);
                                do {
                                  bVar28 = *pbVar36;
                                  bVar27 = bVar28 & 0xf;
                                  if (bVar27 == 0) {
                                    if ((bVar28 & 0xf0) != 0) {
                                      uVar32 = (bVar28 & 0xf0) << 0x10 | param_20;
                                      goto LAB_00538e4d;
                                    }
                                  }
                                  else if (bVar27 == 0xf) {
                                    uVar32 = param_15 & 0xffff | 0xff0000;
LAB_00538e4d:
                                    *puVar25 = uVar32;
                                  }
                                  else {
                                    bVar28 = (bVar28 >> 4) * ('\x0f' - bVar27) + bVar28 * '\x10';
                                    *(byte *)((int)puVar25 + 2) = bVar28;
                                    uVar32 = ((*pbVar36 & 0xf) << 0xc) / (uint)bVar28;
                                    *(ushort *)puVar25 =
                                         ((short)(((uint)local_19a - (uint)local_199) * uVar32 >> 8)
                                         + (ushort)local_199) * 0x800 |
                                         ((short)(((uVar30 & 0x3f) - (uint)local_191) * uVar32 >> 8)
                                         + (ushort)local_191) * 0x20 |
                                         (short)(((param_15 & 0x1f) - (uint)local_1a9) * uVar32 >> 8
                                                ) + (ushort)local_1a9;
                                  }
                                  local_1c4 = (float)((int)local_1c4 + 0xffff);
                                  puVar25 = (uint *)((int)puVar25 + local_180);
                                  pbVar36 = pbVar36 + 1;
                                } while (SUB42(local_1c4,0) != 0);
                                puVar25 = (uint *)((int)puVar25 + (-4 - iVar31));
                                pbVar36 = pbVar36 + iVar19;
                                iVar15 = (int)(float)local_1a8 + 0xffff;
                                local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar15);
                              } while ((short)iVar15 != 0);
                            }
                          }
                        }
                        else if (iVar18 == 0x20) {
                          puVar25 = (uint *)(iVar17 * local_180 + local_dc * 4 +
                                            *(int *)(param_16 + 0xc));
                          local_198 = *(ushort **)(local_1b0 + 0x90d8c);
                          pbVar36 = (byte *)((int)local_198 + local_fc + iVar15 * local_f8);
                          iVar18 = iVar15 - uVar35;
                          iVar17 = -4 - uVar35 * local_180;
                          switch(*(undefined4 *)(local_1b0 + 0x93184)) {
                          case 0:
                            uVar32 = local_fc & 0x80000007;
                            if ((int)uVar32 < 0) {
                              uVar32 = (uVar32 - 1 | 0xfffffff8) + 1;
                            }
                            local_1cc = (ushort *)
                                        ((int)local_198 +
                                        iVar15 * local_f8 + ((int)(local_fc + (uVar30 & 7)) >> 3));
                            iVar15 = iVar15 - (uVar35 + 7 >> 3);
                            local_140 = &DAT_00400080;
                            local_13c = 1.469413e-39;
                            local_138 = 3.67353e-40;
                            local_134 = 9.18383e-41;
                            local_130 = 2.0078125;
                            local_12c = 2.52682e-29;
                            local_128 = 1.5050001e-36;
                            local_124 = 2.3511322e-38;
                            if (param_18 == 0) {
                              uVar3 = *(ushort *)((int)&local_140 + uVar32 * 2);
                              do {
                                sVar34 = local_1c0._0_2_;
                                do {
                                  uVar4 = *local_1cc;
                                  *puVar25 = -(uint)((uVar3 & uVar4) != 0) & param_15;
                                  puVar25 = (uint *)((int)puVar25 + local_180);
                                  sVar9 = 0;
                                  if (sVar34 != 1) {
                                    *puVar25 = -(uint)((*(ushort *)
                                                         ((int)&local_140 + uVar32 * 2 + 2) & uVar4)
                                                      != 0) & param_15;
                                    puVar25 = (uint *)((int)puVar25 + local_180);
                                    sVar9 = 0;
                                    if (sVar34 != 2) {
                                      *puVar25 = -(uint)((*(ushort *)((int)&local_13c + uVar32 * 2)
                                                         & uVar4) != 0) & param_15;
                                      puVar25 = (uint *)((int)puVar25 + local_180);
                                      sVar9 = 0;
                                      if (sVar34 != 3) {
                                        *puVar25 = -(uint)((*(ushort *)
                                                             ((int)&local_13c + uVar32 * 2 + 2) &
                                                           uVar4) != 0) & param_15;
                                        puVar25 = (uint *)((int)puVar25 + local_180);
                                        sVar9 = 0;
                                        if (sVar34 != 4) {
                                          *puVar25 = -(uint)((*(ushort *)
                                                               ((int)&local_138 + uVar32 * 2) &
                                                             uVar4) != 0) & param_15;
                                          puVar25 = (uint *)((int)puVar25 + local_180);
                                          sVar9 = 0;
                                          if (sVar34 != 5) {
                                            *puVar25 = -(uint)((*(ushort *)
                                                                 ((int)&local_138 + uVar32 * 2 + 2)
                                                               & uVar4) != 0) & param_15;
                                            puVar25 = (uint *)((int)puVar25 + local_180);
                                            sVar9 = 0;
                                            if (sVar34 != 6) {
                                              *puVar25 = -(uint)((*(ushort *)
                                                                   ((int)&local_134 + uVar32 * 2) &
                                                                 uVar4) != 0) & param_15;
                                              puVar25 = (uint *)((int)puVar25 + local_180);
                                              sVar9 = 0;
                                              if (sVar34 != 7) {
                                                *puVar25 = -(uint)((*(ushort *)
                                                                     ((int)&local_134 +
                                                                     uVar32 * 2 + 2) & uVar4) != 0)
                                                           & param_15;
                                                puVar25 = (uint *)((int)puVar25 + local_180);
                                                sVar9 = sVar34 + -8;
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                  sVar34 = sVar9;
                                  local_1cc = (ushort *)((int)local_1cc + 1);
                                } while (sVar34 != 0);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                local_1cc = (ushort *)((int)local_1cc + iVar15);
                                iVar18 = (int)(float)local_1a8 + 0xffff;
                                local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar18);
                              } while ((short)iVar18 != 0);
                            }
                            else {
                              uVar3 = *(ushort *)((int)&local_140 + uVar32 * 2);
                              do {
                                sVar34 = local_1c0._0_2_;
                                do {
                                  uVar4 = *local_1cc;
                                  if ((uVar3 & uVar4) != 0) {
                                    *puVar25 = param_15;
                                  }
                                  puVar25 = (uint *)((int)puVar25 + local_180);
                                  sVar9 = 0;
                                  if (sVar34 != 1) {
                                    if ((*(ushort *)((int)&local_140 + uVar32 * 2 + 2) & uVar4) != 0
                                       ) {
                                      *puVar25 = param_15;
                                    }
                                    puVar25 = (uint *)((int)puVar25 + local_180);
                                    sVar9 = 0;
                                    if (sVar34 != 2) {
                                      if ((*(ushort *)((int)&local_13c + uVar32 * 2) & uVar4) != 0)
                                      {
                                        *puVar25 = param_15;
                                      }
                                      puVar25 = (uint *)((int)puVar25 + local_180);
                                      sVar9 = 0;
                                      if (sVar34 != 3) {
                                        if ((*(ushort *)((int)&local_13c + uVar32 * 2 + 2) & uVar4)
                                            != 0) {
                                          *puVar25 = param_15;
                                        }
                                        puVar25 = (uint *)((int)puVar25 + local_180);
                                        sVar9 = 0;
                                        if (sVar34 != 4) {
                                          if ((*(ushort *)((int)&local_138 + uVar32 * 2) & uVar4) !=
                                              0) {
                                            *puVar25 = param_15;
                                          }
                                          puVar25 = (uint *)((int)puVar25 + local_180);
                                          sVar9 = 0;
                                          if (sVar34 != 5) {
                                            if ((*(ushort *)((int)&local_138 + uVar32 * 2 + 2) &
                                                uVar4) != 0) {
                                              *puVar25 = param_15;
                                            }
                                            puVar25 = (uint *)((int)puVar25 + local_180);
                                            sVar9 = 0;
                                            if (sVar34 != 6) {
                                              if ((*(ushort *)((int)&local_134 + uVar32 * 2) & uVar4
                                                  ) != 0) {
                                                *puVar25 = param_15;
                                              }
                                              puVar25 = (uint *)((int)puVar25 + local_180);
                                              sVar9 = 0;
                                              if (sVar34 != 7) {
                                                if ((*(ushort *)((int)&local_134 + uVar32 * 2 + 2) &
                                                    uVar4) != 0) {
                                                  *puVar25 = param_15;
                                                }
                                                puVar25 = (uint *)((int)puVar25 + local_180);
                                                sVar9 = sVar34 + -8;
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                  sVar34 = sVar9;
                                  local_1cc = (ushort *)((int)local_1cc + 1);
                                } while (sVar34 != 0);
                                local_1cc = (ushort *)((int)local_1cc + iVar15);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                iVar18 = (int)(float)local_1a8 + 0xffff;
                                local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar18);
                              } while ((short)iVar18 != 0);
                            }
                            break;
                          case 1:
                            iVar15 = (int)(float)local_1a8;
                            if (param_18 == 0) {
                              do {
                                sVar34 = local_1c0._0_2_;
                                do {
                                  if (*pbVar36 == 0) {
                                    uVar30 = 0;
                                  }
                                  else if (*pbVar36 == 1) {
                                    uVar30 = param_15;
                                  }
                                  else {
                                    uVar30 = param_20 & 0xffffff;
                                  }
                                  *puVar25 = uVar30;
                                  sVar34 = sVar34 + -1;
                                  puVar25 = (uint *)((int)puVar25 + local_180);
                                  pbVar36 = pbVar36 + 1;
                                } while (sVar34 != 0);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                pbVar36 = pbVar36 + iVar18;
                                iVar15 = iVar15 + 0xffff;
                              } while ((short)iVar15 != 0);
                            }
                            else {
                              do {
                                sVar34 = local_1c0._0_2_;
                                do {
                                  if (*pbVar36 != 0) {
                                    uVar30 = param_15;
                                    if (*pbVar36 != 1) {
                                      uVar30 = param_20 & 0xffffff;
                                    }
                                    *puVar25 = uVar30;
                                  }
                                  sVar34 = sVar34 + -1;
                                  puVar25 = (uint *)((int)puVar25 + local_180);
                                  pbVar36 = pbVar36 + 1;
                                } while (sVar34 != 0);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                pbVar36 = pbVar36 + iVar18;
                                iVar15 = iVar15 + 0xffff;
                              } while ((short)iVar15 != 0);
                            }
                            break;
                          case 2:
                          case 0x12:
                          case 0x22:
                            iVar15 = (int)(float)local_1a8;
                            if (param_18 == 0) {
                              do {
                                sVar34 = local_1c0._0_2_;
                                do {
                                  if (*pbVar36 == 0) {
                                    *puVar25 = 0;
                                  }
                                  else {
                                    *puVar25 = (uint)*pbVar36 << 0x1c | param_15;
                                  }
                                  sVar34 = sVar34 + -1;
                                  puVar25 = (uint *)((int)puVar25 + local_180);
                                  pbVar36 = pbVar36 + 1;
                                } while (sVar34 != 0);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                pbVar36 = pbVar36 + iVar18;
                                iVar15 = iVar15 + 0xffff;
                              } while ((short)iVar15 != 0);
                            }
                            else {
                              do {
                                sVar34 = local_1c0._0_2_;
                                do {
                                  if (*pbVar36 != 0) {
                                    *puVar25 = (uint)*pbVar36 << 0x1c | param_15;
                                  }
                                  sVar34 = sVar34 + -1;
                                  puVar25 = (uint *)((int)puVar25 + local_180);
                                  pbVar36 = pbVar36 + 1;
                                } while (sVar34 != 0);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                pbVar36 = pbVar36 + iVar18;
                                iVar15 = iVar15 + 0xffff;
                              } while ((short)iVar15 != 0);
                            }
                            break;
                          case 3:
                          case 0x13:
                          case 0x23:
                            local_1a9 = bVar29;
                            local_19a = bVar11;
                            local_199 = bVar10;
                            local_191 = bVar12;
                            if (param_18 == 0) {
                              do {
                                local_1c4 = (float)(uVar35 & 0xffff);
                                do {
                                  bVar28 = *pbVar36;
                                  if ((bVar28 & 0xf) == 0) {
                                    if ((bVar28 & 0xf0) == 0) {
                                      *puVar25 = 0;
                                    }
                                    else {
                                      *puVar25 = (bVar28 & 0xfffffff0) << 0x18 | param_20;
                                    }
                                  }
                                  else if ((bVar28 & 0xf) == 0xf) {
                                    *puVar25 = param_15 | 0xff000000;
                                  }
                                  else {
                                    uVar30 = ((0xf - (bVar28 & 0xf)) * (uint)(bVar28 >> 4) +
                                             (uint)bVar28 * 0x10) * 0x1000000;
                                    *puVar25 = uVar30;
                                    local_198 = (ushort *)
                                                (((*pbVar36 & 0xf) << 0xc) /
                                                (uint)*(byte *)((int)puVar25 + 3));
                                    *puVar25 = ((((uint)bVar11 - (uint)bVar29) * (int)local_198 &
                                                0xffffff00) + (uint)bVar29 * 0x100) * 0x100 |
                                               (((uint)bVar10 - (uint)bVar12) * (int)local_198 &
                                               0xffffff00) + (uint)bVar12 * 0x100 |
                                               (((param_15 & 0xff) - (param_20 & 0xff)) *
                                                (int)local_198 >> 8) + (param_20 & 0xff) | uVar30;
                                  }
                                  local_1c4 = (float)((int)local_1c4 + 0xffff);
                                  puVar25 = (uint *)((int)puVar25 + local_180);
                                  pbVar36 = pbVar36 + 1;
                                } while (SUB42(local_1c4,0) != 0);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                pbVar36 = pbVar36 + iVar18;
                                iVar15 = (int)(float)local_1a8 + 0xffff;
                                local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar15);
                              } while ((short)iVar15 != 0);
                            }
                            else {
                              do {
                                local_1c4 = (float)(uVar35 & 0xffff);
                                do {
                                  bVar28 = *pbVar36;
                                  if ((bVar28 & 0xf) == 0) {
                                    if ((bVar28 & 0xf0) != 0) {
                                      uVar30 = (bVar28 & 0xfffffff0) << 0x18 | param_20;
                                      goto LAB_00538635;
                                    }
                                  }
                                  else if ((bVar28 & 0xf) == 0xf) {
                                    uVar30 = param_15 | 0xff000000;
LAB_00538635:
                                    *puVar25 = uVar30;
                                  }
                                  else {
                                    uVar30 = ((0xf - (bVar28 & 0xf)) * (uint)(bVar28 >> 4) +
                                             (uint)bVar28 * 0x10) * 0x1000000;
                                    *puVar25 = uVar30;
                                    local_198 = (ushort *)
                                                (((*pbVar36 & 0xf) << 0xc) /
                                                (uint)*(byte *)((int)puVar25 + 3));
                                    *puVar25 = ((((uint)bVar11 - (uint)bVar29) * (int)local_198 &
                                                0xffffff00) + (uint)bVar29 * 0x100) * 0x100 |
                                               (((uint)bVar10 - (uint)bVar12) * (int)local_198 &
                                               0xffffff00) + (uint)bVar12 * 0x100 |
                                               (((param_15 & 0xff) - (param_20 & 0xff)) *
                                                (int)local_198 >> 8) + (param_20 & 0xff) | uVar30;
                                  }
                                  local_1c4 = (float)((int)local_1c4 + 0xffff);
                                  puVar25 = (uint *)((int)puVar25 + local_180);
                                  pbVar36 = pbVar36 + 1;
                                } while (SUB42(local_1c4,0) != 0);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                pbVar36 = pbVar36 + iVar18;
                                iVar15 = (int)(float)local_1a8 + 0xffff;
                                local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar15);
                              } while ((short)iVar15 != 0);
                            }
                          }
                        }
                      }
                    }
                  }
                  else {
                    iVar18 = FUN_0050e240(local_168);
                    iVar19 = (int)*(short *)((int)fVar16 + 6) + iVar18 + local_178;
                    iVar18 = FUN_0050e240();
                    iVar17 = (int)*(short *)((int)fVar16 + 8) + iVar18 + local_17c;
                    uVar3 = *(ushort *)((int)fVar16 + 0xc);
                    local_dc = (uint)uVar3 + iVar19;
                    uVar4 = *(ushort *)((int)fVar16 + 0xe);
                    local_d8 = (uint)uVar4 + iVar17;
                    local_e4 = iVar19;
                    local_e0 = iVar17;
                    FUN_00514e10(&local_e4,param_17);
                    iVar18 = local_e0;
                    if (local_dc != local_e4) {
                      if (local_d8 != local_e0) {
                        local_fc = local_fc + (local_e4 - iVar19);
                        local_f8 = local_f8 + (local_e0 - iVar17);
                        local_f0 = local_f0 + ((local_d8 - (uint)uVar4) - iVar17);
                        local_f4 = local_f4 + ((local_dc - (uint)uVar3) - iVar19);
                        uVar30 = local_f4 - local_fc;
                        local_1bc = (float)(local_f0 - local_f8 & 0xffff);
                        iVar17 = FUN_005167e0();
                        local_1b8 = (short)uVar30;
                        uVar35 = (int)local_fc >> 0x1f;
                        if (iVar17 == 8) {
                          pbVar36 = (byte *)(iVar18 * local_180 + *(int *)(param_16 + 0xc) +
                                            local_e4);
                          iVar18 = iVar15 - uVar30;
                          iVar17 = *(int *)(local_1b0 + 0x90d8c) + iVar15 * local_f8;
                          local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar18);
                          pcVar21 = (char *)(local_fc + iVar17);
                          if (*(int *)(local_1b0 + 0x93184) == 0) {
                            uVar32 = local_fc & 0x80000007;
                            if ((int)uVar32 < 0) {
                              uVar32 = (uVar32 - 1 | 0xfffffff8) + 1;
                            }
                            if (uVar32 == 0) {
                              local_198 = (ushort *)(((int)(local_fc + (uVar35 & 7)) >> 3) + iVar17)
                              ;
                              iVar15 = iVar15 + (uVar30 + 0xf >> 4) * -2;
                              iVar18 = local_180 - (uVar30 & 0xfffffff0);
                              local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar15);
                              puVar22 = local_198;
                              if (param_18 == 1) {
                                do {
                                  sVar34 = local_1b8;
                                  do {
                                    uVar3 = *puVar22;
                                    if ((char)uVar3 < '\0') {
                                      *pbVar36 = bVar28;
                                    }
                                    sVar9 = 0;
                                    if (sVar34 != 1) {
                                      if ((uVar3 & 0x40) != 0) {
                                        pbVar36[1] = bVar28;
                                      }
                                      sVar9 = 0;
                                      if (sVar34 != 2) {
                                        if ((uVar3 & 0x20) != 0) {
                                          pbVar36[2] = bVar28;
                                        }
                                        sVar9 = 0;
                                        if (sVar34 != 3) {
                                          if ((uVar3 & 0x10) != 0) {
                                            pbVar36[3] = bVar28;
                                          }
                                          sVar9 = 0;
                                          if (sVar34 != 4) {
                                            if ((uVar3 & 8) != 0) {
                                              pbVar36[4] = bVar28;
                                            }
                                            sVar9 = 0;
                                            if (sVar34 != 5) {
                                              if ((uVar3 & 4) != 0) {
                                                pbVar36[5] = bVar28;
                                              }
                                              sVar9 = 0;
                                              if (sVar34 != 6) {
                                                if ((uVar3 & 2) != 0) {
                                                  pbVar36[6] = bVar28;
                                                }
                                                sVar9 = 0;
                                                if (sVar34 != 7) {
                                                  if ((uVar3 & 1) != 0) {
                                                    pbVar36[7] = bVar28;
                                                  }
                                                  sVar9 = 0;
                                                  if (sVar34 != 8) {
                                                    if ((uVar3 & 0x8000) != 0) {
                                                      pbVar36[8] = bVar28;
                                                    }
                                                    sVar9 = 0;
                                                    if (sVar34 != 9) {
                                                      if ((uVar3 & 0x4000) != 0) {
                                                        pbVar36[9] = bVar28;
                                                      }
                                                      sVar9 = 0;
                                                      if (sVar34 != 10) {
                                                        if ((uVar3 & 0x2000) != 0) {
                                                          pbVar36[10] = bVar28;
                                                        }
                                                        sVar9 = 0;
                                                        if (sVar34 != 0xb) {
                                                          if ((uVar3 & 0x1000) != 0) {
                                                            pbVar36[0xb] = bVar28;
                                                          }
                                                          sVar9 = 0;
                                                          if (sVar34 != 0xc) {
                                                            if ((uVar3 & 0x800) != 0) {
                                                              pbVar36[0xc] = bVar28;
                                                            }
                                                            sVar9 = 0;
                                                            if (sVar34 != 0xd) {
                                                              if ((uVar3 & 0x400) != 0) {
                                                                pbVar36[0xd] = bVar28;
                                                              }
                                                              sVar9 = 0;
                                                              if (sVar34 != 0xe) {
                                                                if ((uVar3 & 0x200) != 0) {
                                                                  pbVar36[0xe] = bVar28;
                                                                }
                                                                sVar9 = 0;
                                                                if (sVar34 != 0xf) {
                                                                  if ((uVar3 & 0x100) != 0) {
                                                                    pbVar36[0xf] = bVar28;
                                                                  }
                                                                  pbVar36 = pbVar36 + 0x10;
                                                                  sVar9 = sVar34 + -0x10;
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                    sVar34 = sVar9;
                                    puVar22 = puVar22 + 1;
                                  } while (sVar34 != 0);
                                  puVar22 = (ushort *)((int)puVar22 + iVar15);
                                  pbVar36 = pbVar36 + iVar18;
                                  local_1bc = (float)((int)local_1bc + 0xffff);
                                } while (SUB42(local_1bc,0) != 0);
                              }
                              else {
                                do {
                                  sVar34 = local_1b8;
                                  do {
                                    uVar3 = *local_198;
                                    if ((char)uVar3 < '\0') {
                                      bVar27 = bVar28;
                                    }
                                    else {
                                      bVar27 = 0;
                                    }
                                    *pbVar36 = bVar27;
                                    sVar9 = 0;
                                    if (sVar34 != 1) {
                                      if ((uVar3 & 0x40) == 0) {
                                        bVar27 = 0;
                                      }
                                      else {
                                        bVar27 = bVar28;
                                      }
                                      pbVar36[1] = bVar27;
                                      sVar9 = 0;
                                      if (sVar34 != 2) {
                                        if ((uVar3 & 0x20) == 0) {
                                          bVar27 = 0;
                                        }
                                        else {
                                          bVar27 = bVar28;
                                        }
                                        pbVar36[2] = bVar27;
                                        sVar9 = 0;
                                        if (sVar34 != 3) {
                                          if ((uVar3 & 0x10) == 0) {
                                            bVar27 = 0;
                                          }
                                          else {
                                            bVar27 = bVar28;
                                          }
                                          pbVar36[3] = bVar27;
                                          sVar9 = 0;
                                          if (sVar34 != 4) {
                                            if ((uVar3 & 8) == 0) {
                                              bVar27 = 0;
                                            }
                                            else {
                                              bVar27 = bVar28;
                                            }
                                            pbVar36[4] = bVar27;
                                            sVar9 = 0;
                                            if (sVar34 != 5) {
                                              if ((uVar3 & 4) == 0) {
                                                bVar27 = 0;
                                              }
                                              else {
                                                bVar27 = bVar28;
                                              }
                                              pbVar36[5] = bVar27;
                                              sVar9 = 0;
                                              if (sVar34 != 6) {
                                                if ((uVar3 & 2) == 0) {
                                                  bVar27 = 0;
                                                }
                                                else {
                                                  bVar27 = bVar28;
                                                }
                                                pbVar36[6] = bVar27;
                                                sVar9 = 0;
                                                if (sVar34 != 7) {
                                                  if ((uVar3 & 1) == 0) {
                                                    bVar27 = 0;
                                                  }
                                                  else {
                                                    bVar27 = bVar28;
                                                  }
                                                  pbVar36[7] = bVar27;
                                                  sVar9 = 0;
                                                  if (sVar34 != 8) {
                                                    if ((uVar3 & 0x8000) == 0) {
                                                      bVar27 = 0;
                                                    }
                                                    else {
                                                      bVar27 = bVar28;
                                                    }
                                                    pbVar36[8] = bVar27;
                                                    sVar9 = 0;
                                                    if (sVar34 != 9) {
                                                      if ((uVar3 & 0x4000) == 0) {
                                                        bVar27 = 0;
                                                      }
                                                      else {
                                                        bVar27 = bVar28;
                                                      }
                                                      pbVar36[9] = bVar27;
                                                      sVar9 = 0;
                                                      if (sVar34 != 10) {
                                                        if ((uVar3 & 0x2000) == 0) {
                                                          bVar27 = 0;
                                                        }
                                                        else {
                                                          bVar27 = bVar28;
                                                        }
                                                        pbVar36[10] = bVar27;
                                                        sVar9 = 0;
                                                        if (sVar34 != 0xb) {
                                                          if ((uVar3 & 0x1000) == 0) {
                                                            bVar27 = 0;
                                                          }
                                                          else {
                                                            bVar27 = bVar28;
                                                          }
                                                          pbVar36[0xb] = bVar27;
                                                          sVar9 = 0;
                                                          if (sVar34 != 0xc) {
                                                            if ((uVar3 & 0x800) == 0) {
                                                              bVar27 = 0;
                                                            }
                                                            else {
                                                              bVar27 = bVar28;
                                                            }
                                                            pbVar36[0xc] = bVar27;
                                                            sVar9 = 0;
                                                            if (sVar34 != 0xd) {
                                                              if ((uVar3 & 0x400) == 0) {
                                                                bVar27 = 0;
                                                              }
                                                              else {
                                                                bVar27 = bVar28;
                                                              }
                                                              pbVar36[0xd] = bVar27;
                                                              sVar9 = 0;
                                                              if (sVar34 != 0xe) {
                                                                if ((uVar3 & 0x200) == 0) {
                                                                  bVar27 = 0;
                                                                }
                                                                else {
                                                                  bVar27 = bVar28;
                                                                }
                                                                pbVar36[0xe] = bVar27;
                                                                sVar9 = 0;
                                                                if (sVar34 != 0xf) {
                                                                  if ((uVar3 & 0x100) == 0) {
                                                                    bVar27 = 0;
                                                                  }
                                                                  else {
                                                                    bVar27 = bVar28;
                                                                  }
                                                                  pbVar36[0xf] = bVar27;
                                                                  pbVar36 = pbVar36 + 0x10;
                                                                  sVar9 = sVar34 + -0x10;
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                    sVar34 = sVar9;
                                    local_198 = local_198 + 1;
                                  } while (sVar34 != 0);
                                  local_198 = (ushort *)((int)local_198 + iVar15);
                                  pbVar36 = pbVar36 + iVar18;
                                  local_1bc = (float)((int)local_1bc + 0xffff);
                                } while (SUB42(local_1bc,0) != 0);
                              }
                            }
                            else {
                              local_198 = (ushort *)(((int)(local_fc + (uVar35 & 7)) >> 3) + iVar17)
                              ;
                              local_140 = &DAT_00400080;
                              local_13c = 1.469413e-39;
                              iVar18 = (iVar15 - (uint)((uVar30 & 7) != 0)) - (uVar30 >> 3);
                              iVar15 = local_180 - (uVar30 & 0xfffffff8);
                              local_138 = 3.67353e-40;
                              local_134 = 9.18383e-41;
                              local_130 = 2.0078125;
                              local_12c = 2.52682e-29;
                              local_128 = 1.5050001e-36;
                              local_124 = 2.3511322e-38;
                              local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar18);
                              if (param_18 == 0) {
                                uVar3 = *(ushort *)((int)&local_140 + uVar32 * 2);
                                sVar34 = local_1b8;
                                while( true ) {
                                  do {
                                    uVar4 = *local_198;
                                    if ((uVar3 & uVar4) == 0) {
                                      bVar27 = 0;
                                    }
                                    else {
                                      bVar27 = bVar28;
                                    }
                                    *pbVar36 = bVar27;
                                    sVar9 = 0;
                                    if (sVar34 != 1) {
                                      if ((*(ushort *)((int)&local_140 + uVar32 * 2 + 2) & uVar4) ==
                                          0) {
                                        bVar27 = 0;
                                      }
                                      else {
                                        bVar27 = bVar28;
                                      }
                                      pbVar36[1] = bVar27;
                                      sVar9 = 0;
                                      if (sVar34 != 2) {
                                        if ((*(ushort *)((int)&local_13c + uVar32 * 2) & uVar4) == 0
                                           ) {
                                          bVar27 = 0;
                                        }
                                        else {
                                          bVar27 = bVar28;
                                        }
                                        pbVar36[2] = bVar27;
                                        sVar9 = 0;
                                        if (sVar34 != 3) {
                                          if ((*(ushort *)((int)&local_13c + uVar32 * 2 + 2) & uVar4
                                              ) == 0) {
                                            bVar27 = 0;
                                          }
                                          else {
                                            bVar27 = bVar28;
                                          }
                                          pbVar36[3] = bVar27;
                                          sVar9 = 0;
                                          if (sVar34 != 4) {
                                            if ((*(ushort *)((int)&local_138 + uVar32 * 2) & uVar4)
                                                == 0) {
                                              bVar27 = 0;
                                            }
                                            else {
                                              bVar27 = bVar28;
                                            }
                                            pbVar36[4] = bVar27;
                                            sVar9 = 0;
                                            if (sVar34 != 5) {
                                              if ((*(ushort *)((int)&local_138 + uVar32 * 2 + 2) &
                                                  uVar4) == 0) {
                                                bVar27 = 0;
                                              }
                                              else {
                                                bVar27 = bVar28;
                                              }
                                              pbVar36[5] = bVar27;
                                              sVar9 = 0;
                                              if (sVar34 != 6) {
                                                if ((*(ushort *)((int)&local_134 + uVar32 * 2) &
                                                    uVar4) == 0) {
                                                  bVar27 = 0;
                                                }
                                                else {
                                                  bVar27 = bVar28;
                                                }
                                                pbVar36[6] = bVar27;
                                                sVar9 = 0;
                                                if (sVar34 != 7) {
                                                  if ((*(ushort *)((int)&local_134 + uVar32 * 2 + 2)
                                                      & uVar4) == 0) {
                                                    bVar27 = 0;
                                                  }
                                                  else {
                                                    bVar27 = bVar28;
                                                  }
                                                  pbVar36[7] = bVar27;
                                                  pbVar36 = pbVar36 + 8;
                                                  sVar9 = sVar34 + -8;
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                    sVar34 = sVar9;
                                    local_198 = (ushort *)((int)local_198 + 1);
                                  } while (sVar34 != 0);
                                  local_198 = (ushort *)((int)local_198 + iVar18);
                                  pbVar36 = pbVar36 + iVar15;
                                  local_1bc = (float)((int)local_1bc + 0xffff);
                                  if (SUB42(local_1bc,0) == 0) break;
                                  sVar34 = local_1b8;
                                }
                              }
                              else {
                                uVar3 = *(ushort *)((int)&local_140 + uVar32 * 2);
                                puVar22 = local_198;
                                do {
                                  sVar34 = local_1b8;
                                  do {
                                    uVar4 = *puVar22;
                                    if ((uVar3 & uVar4) != 0) {
                                      *pbVar36 = bVar28;
                                    }
                                    sVar9 = 0;
                                    if (sVar34 != 1) {
                                      if ((*(ushort *)((int)&local_140 + uVar32 * 2 + 2) & uVar4) !=
                                          0) {
                                        pbVar36[1] = bVar28;
                                      }
                                      sVar9 = 0;
                                      if (sVar34 != 2) {
                                        if ((*(ushort *)((int)&local_13c + uVar32 * 2) & uVar4) != 0
                                           ) {
                                          pbVar36[2] = bVar28;
                                        }
                                        sVar9 = 0;
                                        if (sVar34 != 3) {
                                          if ((*(ushort *)((int)&local_13c + uVar32 * 2 + 2) & uVar4
                                              ) != 0) {
                                            pbVar36[3] = bVar28;
                                          }
                                          sVar9 = 0;
                                          if (sVar34 != 4) {
                                            if ((*(ushort *)((int)&local_138 + uVar32 * 2) & uVar4)
                                                != 0) {
                                              pbVar36[4] = bVar28;
                                            }
                                            sVar9 = 0;
                                            if (sVar34 != 5) {
                                              if ((*(ushort *)((int)&local_138 + uVar32 * 2 + 2) &
                                                  uVar4) != 0) {
                                                pbVar36[5] = bVar28;
                                              }
                                              sVar9 = 0;
                                              if (sVar34 != 6) {
                                                if ((*(ushort *)((int)&local_134 + uVar32 * 2) &
                                                    uVar4) != 0) {
                                                  pbVar36[6] = bVar28;
                                                }
                                                sVar9 = 0;
                                                if (sVar34 != 7) {
                                                  if ((*(ushort *)((int)&local_134 + uVar32 * 2 + 2)
                                                      & uVar4) != 0) {
                                                    pbVar36[7] = bVar28;
                                                  }
                                                  pbVar36 = pbVar36 + 8;
                                                  sVar9 = sVar34 + -8;
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                    sVar34 = sVar9;
                                    puVar22 = (ushort *)((int)puVar22 + 1);
                                  } while (sVar34 != 0);
                                  puVar22 = (ushort *)((int)puVar22 + iVar18);
                                  pbVar36 = pbVar36 + iVar15;
                                  local_1bc = (float)((int)local_1bc + 0xffff);
                                } while (SUB42(local_1bc,0) != 0);
                              }
                            }
                          }
                          else if (*(int *)(local_1b0 + 0x93184) == 1) {
                            if (param_18 == 0) {
                              do {
                                sVar34 = local_1b8;
                                do {
                                  if (*pcVar21 == '\0') {
                                    bVar29 = 0;
                                  }
                                  else {
                                    bVar29 = bVar28;
                                    if (*pcVar21 != '\x01') {
                                      bVar29 = bVar27;
                                    }
                                  }
                                  *pbVar36 = bVar29;
                                  sVar34 = sVar34 + -1;
                                  pbVar36 = pbVar36 + 1;
                                  pcVar21 = pcVar21 + 1;
                                } while (sVar34 != 0);
                                pcVar21 = pcVar21 + iVar18;
                                local_1bc = (float)((int)local_1bc + 0xffff);
                                pbVar36 = pbVar36 + (local_180 - uVar30);
                              } while (SUB42(local_1bc,0) != 0);
                            }
                            else {
                              do {
                                sVar34 = local_1b8;
                                do {
                                  if (*pcVar21 != '\0') {
                                    bVar29 = bVar28;
                                    if (*pcVar21 != '\x01') {
                                      bVar29 = bVar27;
                                    }
                                    *pbVar36 = bVar29;
                                  }
                                  sVar34 = sVar34 + -1;
                                  pbVar36 = pbVar36 + 1;
                                  pcVar21 = pcVar21 + 1;
                                } while (sVar34 != 0);
                                pcVar21 = pcVar21 + iVar18;
                                local_1bc = (float)((int)local_1bc + 0xffff);
                                pbVar36 = pbVar36 + (local_180 - uVar30);
                              } while (SUB42(local_1bc,0) != 0);
                            }
                          }
                        }
                        else if (iVar17 == 0x10) {
                          local_198 = *(ushort **)(local_1b0 + 0x90d8c);
                          iVar17 = uVar30 * 2;
                          if ((*(uint *)(local_1b0 + 0x93184) & 2) == 0) {
                            iVar19 = local_e4 * 2;
                          }
                          else {
                            iVar19 = local_e4 * 4;
                            iVar17 = uVar30 * 4;
                          }
                          puVar25 = (uint *)(iVar18 * local_180 + *(int *)(param_16 + 0xc) + iVar19)
                          ;
                          iVar17 = local_180 - iVar17;
                          iVar19 = iVar15 * local_f8;
                          pbVar36 = (byte *)((int)local_198 + local_fc + iVar19);
                          iVar18 = iVar15 - uVar30;
                          local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar18);
                          switch(*(uint *)(local_1b0 + 0x93184)) {
                          case 0:
                            uVar32 = local_fc & 0x80000007;
                            if ((int)uVar32 < 0) {
                              uVar32 = (uVar32 - 1 | 0xfffffff8) + 1;
                            }
                            if (uVar32 == 0) {
                              local_1cc = (ushort *)
                                          ((int)local_198 +
                                          iVar19 + ((int)(local_fc + (uVar35 & 7)) >> 3));
                              iVar15 = ((uVar30 >> 4) * -2 - (-(uint)((uVar30 & 0xf) != 0) & 2)) +
                                       iVar15;
                              local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar15);
                              iVar18 = local_180 + (uVar30 & 0xfffffff0) * -2;
                              if (param_18 == 0) {
                                do {
                                  uVar35 = uVar30 & 0xffff;
                                  do {
                                    uVar3 = *local_1cc;
                                    uVar14 = (undefined2)param_15;
                                    if (-1 < (char)uVar3) {
                                      uVar14 = 0;
                                    }
                                    uVar32 = uVar35 + 0xffff;
                                    *(undefined2 *)puVar25 = uVar14;
                                    if ((short)uVar32 != 0) {
                                      uVar14 = (undefined2)param_15;
                                      if ((uVar3 & 0x40) == 0) {
                                        uVar14 = 0;
                                      }
                                      uVar32 = uVar35 + 0x1fffe;
                                      *(undefined2 *)((int)puVar25 + 2) = uVar14;
                                      if ((short)uVar32 != 0) {
                                        uVar14 = (undefined2)param_15;
                                        if ((uVar3 & 0x20) == 0) {
                                          uVar14 = 0;
                                        }
                                        uVar32 = uVar35 + 0x2fffd;
                                        *(undefined2 *)(puVar25 + 1) = uVar14;
                                        if ((short)uVar32 != 0) {
                                          uVar14 = (undefined2)param_15;
                                          if ((uVar3 & 0x10) == 0) {
                                            uVar14 = 0;
                                          }
                                          uVar32 = uVar35 + 0x3fffc;
                                          *(undefined2 *)((int)puVar25 + 6) = uVar14;
                                          if ((short)uVar32 != 0) {
                                            uVar14 = (undefined2)param_15;
                                            if ((uVar3 & 8) == 0) {
                                              uVar14 = 0;
                                            }
                                            uVar32 = uVar35 + 0x4fffb;
                                            *(undefined2 *)(puVar25 + 2) = uVar14;
                                            if ((short)uVar32 != 0) {
                                              uVar14 = (undefined2)param_15;
                                              if ((uVar3 & 4) == 0) {
                                                uVar14 = 0;
                                              }
                                              uVar32 = uVar35 + 0x5fffa;
                                              *(undefined2 *)((int)puVar25 + 10) = uVar14;
                                              if ((short)uVar32 != 0) {
                                                uVar14 = (undefined2)param_15;
                                                if ((uVar3 & 2) == 0) {
                                                  uVar14 = 0;
                                                }
                                                uVar32 = uVar35 + 0x6fff9;
                                                *(undefined2 *)(puVar25 + 3) = uVar14;
                                                if ((short)uVar32 != 0) {
                                                  uVar14 = (undefined2)param_15;
                                                  if ((uVar3 & 1) == 0) {
                                                    uVar14 = 0;
                                                  }
                                                  uVar32 = uVar35 + 0x7fff8;
                                                  *(undefined2 *)((int)puVar25 + 0xe) = uVar14;
                                                  if ((short)uVar32 != 0) {
                                                    uVar14 = (undefined2)param_15;
                                                    if ((uVar3 & 0x8000) == 0) {
                                                      uVar14 = 0;
                                                    }
                                                    uVar32 = uVar35 + 0x8fff7;
                                                    *(undefined2 *)(puVar25 + 4) = uVar14;
                                                    if ((short)uVar32 != 0) {
                                                      uVar14 = (undefined2)param_15;
                                                      if ((uVar3 & 0x4000) == 0) {
                                                        uVar14 = 0;
                                                      }
                                                      uVar32 = uVar35 + 0x9fff6;
                                                      *(undefined2 *)((int)puVar25 + 0x12) = uVar14;
                                                      if ((short)uVar32 != 0) {
                                                        uVar14 = (undefined2)param_15;
                                                        if ((uVar3 & 0x2000) == 0) {
                                                          uVar14 = 0;
                                                        }
                                                        uVar32 = uVar35 + 0xafff5;
                                                        *(undefined2 *)(puVar25 + 5) = uVar14;
                                                        if ((short)uVar32 != 0) {
                                                          uVar14 = (undefined2)param_15;
                                                          if ((uVar3 & 0x1000) == 0) {
                                                            uVar14 = 0;
                                                          }
                                                          uVar32 = uVar35 + 0xbfff4;
                                                          *(undefined2 *)((int)puVar25 + 0x16) =
                                                               uVar14;
                                                          if ((short)uVar32 != 0) {
                                                            uVar14 = (undefined2)param_15;
                                                            if ((uVar3 & 0x800) == 0) {
                                                              uVar14 = 0;
                                                            }
                                                            uVar32 = uVar35 + 0xcfff3;
                                                            *(undefined2 *)(puVar25 + 6) = uVar14;
                                                            if ((short)uVar32 != 0) {
                                                              uVar14 = (undefined2)param_15;
                                                              if ((uVar3 & 0x400) == 0) {
                                                                uVar14 = 0;
                                                              }
                                                              uVar32 = uVar35 + 0xdfff2;
                                                              *(undefined2 *)((int)puVar25 + 0x1a) =
                                                                   uVar14;
                                                              if ((short)uVar32 != 0) {
                                                                uVar14 = (undefined2)param_15;
                                                                if ((uVar3 & 0x200) == 0) {
                                                                  uVar14 = 0;
                                                                }
                                                                uVar32 = uVar35 + 0xefff1;
                                                                *(undefined2 *)(puVar25 + 7) =
                                                                     uVar14;
                                                                if ((short)uVar32 != 0) {
                                                                  if ((uVar3 & 0x100) == 0) {
                                                                    uVar14 = 0;
                                                                  }
                                                                  else {
                                                                    uVar14 = (undefined2)param_15;
                                                                  }
                                                                  *(undefined2 *)
                                                                   ((int)puVar25 + 0x1e) = uVar14;
                                                                  puVar25 = puVar25 + 8;
                                                                  uVar32 = uVar35 + 0xffff0;
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                    local_1cc = local_1cc + 1;
                                    uVar35 = uVar32;
                                  } while ((short)uVar32 != 0);
                                  local_1cc = (ushort *)((int)local_1cc + iVar15);
                                  puVar25 = (uint *)((int)puVar25 + iVar18);
                                  local_1bc = (float)((int)local_1bc + 0xffff);
                                } while (SUB42(local_1bc,0) != 0);
                              }
                              else {
                                do {
                                  sVar34 = local_1b8;
                                  do {
                                    uVar3 = *local_1cc;
                                    if ((char)uVar3 < '\0') {
                                      *(undefined2 *)puVar25 = (undefined2)param_15;
                                    }
                                    sVar9 = 0;
                                    if (sVar34 != 1) {
                                      if ((uVar3 & 0x40) != 0) {
                                        *(undefined2 *)((int)puVar25 + 2) = (undefined2)param_15;
                                      }
                                      sVar9 = 0;
                                      if (sVar34 != 2) {
                                        if ((uVar3 & 0x20) != 0) {
                                          *(undefined2 *)(puVar25 + 1) = (undefined2)param_15;
                                        }
                                        sVar9 = 0;
                                        if (sVar34 != 3) {
                                          if ((uVar3 & 0x10) != 0) {
                                            *(undefined2 *)((int)puVar25 + 6) = (undefined2)param_15
                                            ;
                                          }
                                          sVar9 = 0;
                                          if (sVar34 != 4) {
                                            if ((uVar3 & 8) != 0) {
                                              *(undefined2 *)(puVar25 + 2) = (undefined2)param_15;
                                            }
                                            sVar9 = 0;
                                            if (sVar34 != 5) {
                                              if ((uVar3 & 4) != 0) {
                                                *(undefined2 *)((int)puVar25 + 10) =
                                                     (undefined2)param_15;
                                              }
                                              sVar9 = 0;
                                              if (sVar34 != 6) {
                                                if ((uVar3 & 2) != 0) {
                                                  *(undefined2 *)(puVar25 + 3) =
                                                       (undefined2)param_15;
                                                }
                                                sVar9 = 0;
                                                if (sVar34 != 7) {
                                                  if ((uVar3 & 1) != 0) {
                                                    *(undefined2 *)((int)puVar25 + 0xe) =
                                                         (undefined2)param_15;
                                                  }
                                                  sVar9 = 0;
                                                  if (sVar34 != 8) {
                                                    if ((uVar3 & 0x8000) != 0) {
                                                      *(undefined2 *)(puVar25 + 4) =
                                                           (undefined2)param_15;
                                                    }
                                                    sVar9 = 0;
                                                    if (sVar34 != 9) {
                                                      if ((uVar3 & 0x4000) != 0) {
                                                        *(undefined2 *)((int)puVar25 + 0x12) =
                                                             (undefined2)param_15;
                                                      }
                                                      sVar9 = 0;
                                                      if (sVar34 != 10) {
                                                        if ((uVar3 & 0x2000) != 0) {
                                                          *(undefined2 *)(puVar25 + 5) =
                                                               (undefined2)param_15;
                                                        }
                                                        sVar9 = 0;
                                                        if (sVar34 != 0xb) {
                                                          if ((uVar3 & 0x1000) != 0) {
                                                            *(undefined2 *)((int)puVar25 + 0x16) =
                                                                 (undefined2)param_15;
                                                          }
                                                          sVar9 = 0;
                                                          if (sVar34 != 0xc) {
                                                            if ((uVar3 & 0x800) != 0) {
                                                              *(undefined2 *)(puVar25 + 6) =
                                                                   (undefined2)param_15;
                                                            }
                                                            sVar9 = 0;
                                                            if (sVar34 != 0xd) {
                                                              if ((uVar3 & 0x400) != 0) {
                                                                *(undefined2 *)((int)puVar25 + 0x1a)
                                                                     = (undefined2)param_15;
                                                              }
                                                              sVar9 = 0;
                                                              if (sVar34 != 0xe) {
                                                                if ((uVar3 & 0x200) != 0) {
                                                                  *(undefined2 *)(puVar25 + 7) =
                                                                       (undefined2)param_15;
                                                                }
                                                                sVar9 = 0;
                                                                if (sVar34 != 0xf) {
                                                                  if ((uVar3 & 0x100) != 0) {
                                                                    *(undefined2 *)
                                                                     ((int)puVar25 + 0x1e) =
                                                                         (undefined2)param_15;
                                                                  }
                                                                  puVar25 = puVar25 + 8;
                                                                  sVar9 = sVar34 + -0x10;
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                    sVar34 = sVar9;
                                    local_1cc = local_1cc + 1;
                                  } while (sVar34 != 0);
                                  local_1cc = (ushort *)((int)local_1cc + iVar15);
                                  puVar25 = (uint *)((int)puVar25 + iVar18);
                                  local_1bc = (float)((int)local_1bc + 0xffff);
                                } while (SUB42(local_1bc,0) != 0);
                              }
                            }
                            else {
                              puVar22 = (ushort *)
                                        ((int)local_198 +
                                        iVar19 + ((int)(local_fc + (uVar35 & 7)) >> 3));
                              local_140 = &DAT_00400080;
                              local_13c = 1.469413e-39;
                              local_138 = 3.67353e-40;
                              iVar18 = (iVar15 - (uint)((uVar30 & 7) != 0)) - (uVar30 >> 3);
                              iVar15 = local_180 + (uVar30 & 0xfffffff8) * -2;
                              local_134 = 9.18383e-41;
                              local_130 = 2.0078125;
                              local_12c = 2.52682e-29;
                              local_128 = 1.5050001e-36;
                              local_124 = 2.3511322e-38;
                              local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar18);
                              if (param_18 == 0) {
                                uVar3 = *(ushort *)((int)&local_140 + uVar32 * 2);
                                do {
                                  sVar34 = local_1b8;
                                  do {
                                    uVar4 = *puVar22;
                                    uVar14 = (undefined2)param_15;
                                    if ((uVar4 & uVar3) == 0) {
                                      uVar14 = 0;
                                    }
                                    *(undefined2 *)puVar25 = uVar14;
                                    sVar9 = 0;
                                    if (sVar34 != 1) {
                                      uVar14 = (undefined2)param_15;
                                      if ((*(ushort *)((int)&local_140 + uVar32 * 2 + 2) & uVar4) ==
                                          0) {
                                        uVar14 = 0;
                                      }
                                      *(undefined2 *)((int)puVar25 + 2) = uVar14;
                                      sVar9 = 0;
                                      if (sVar34 != 2) {
                                        uVar14 = (undefined2)param_15;
                                        if ((*(ushort *)((int)&local_13c + uVar32 * 2) & uVar4) == 0
                                           ) {
                                          uVar14 = 0;
                                        }
                                        *(undefined2 *)(puVar25 + 1) = uVar14;
                                        sVar9 = 0;
                                        if (sVar34 != 3) {
                                          uVar14 = (undefined2)param_15;
                                          if ((*(ushort *)((int)&local_13c + uVar32 * 2 + 2) & uVar4
                                              ) == 0) {
                                            uVar14 = 0;
                                          }
                                          *(undefined2 *)((int)puVar25 + 6) = uVar14;
                                          sVar9 = 0;
                                          if (sVar34 != 4) {
                                            uVar14 = (undefined2)param_15;
                                            if ((*(ushort *)((int)&local_138 + uVar32 * 2) & uVar4)
                                                == 0) {
                                              uVar14 = 0;
                                            }
                                            *(undefined2 *)(puVar25 + 2) = uVar14;
                                            sVar9 = 0;
                                            if (sVar34 != 5) {
                                              uVar14 = (undefined2)param_15;
                                              if ((*(ushort *)((int)&local_138 + uVar32 * 2 + 2) &
                                                  uVar4) == 0) {
                                                uVar14 = 0;
                                              }
                                              *(undefined2 *)((int)puVar25 + 10) = uVar14;
                                              sVar9 = 0;
                                              if (sVar34 != 6) {
                                                uVar14 = (undefined2)param_15;
                                                if ((*(ushort *)((int)&local_134 + uVar32 * 2) &
                                                    uVar4) == 0) {
                                                  uVar14 = 0;
                                                }
                                                *(undefined2 *)(puVar25 + 3) = uVar14;
                                                sVar9 = 0;
                                                if (sVar34 != 7) {
                                                  if ((*(ushort *)((int)&local_134 + uVar32 * 2 + 2)
                                                      & uVar4) == 0) {
                                                    uVar14 = 0;
                                                  }
                                                  else {
                                                    uVar14 = (undefined2)param_15;
                                                  }
                                                  *(undefined2 *)((int)puVar25 + 0xe) = uVar14;
                                                  puVar25 = puVar25 + 4;
                                                  sVar9 = sVar34 + -8;
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                    sVar34 = sVar9;
                                    puVar22 = (ushort *)((int)puVar22 + 1);
                                  } while (sVar34 != 0);
                                  puVar22 = (ushort *)((int)puVar22 + iVar18);
                                  puVar25 = (uint *)((int)puVar25 + iVar15);
                                  local_1bc = (float)((int)local_1bc + 0xffff);
                                } while (SUB42(local_1bc,0) != 0);
                              }
                              else {
                                uVar3 = *(ushort *)((int)&local_140 + uVar32 * 2);
                                do {
                                  sVar34 = local_1b8;
                                  do {
                                    uVar4 = *puVar22;
                                    if ((uVar4 & uVar3) != 0) {
                                      *(undefined2 *)puVar25 = (undefined2)param_15;
                                    }
                                    sVar9 = 0;
                                    if (sVar34 != 1) {
                                      if ((*(ushort *)((int)&local_140 + uVar32 * 2 + 2) & uVar4) !=
                                          0) {
                                        *(undefined2 *)((int)puVar25 + 2) = (undefined2)param_15;
                                      }
                                      sVar9 = 0;
                                      if (sVar34 != 2) {
                                        if ((*(ushort *)((int)&local_13c + uVar32 * 2) & uVar4) != 0
                                           ) {
                                          *(undefined2 *)(puVar25 + 1) = (undefined2)param_15;
                                        }
                                        sVar9 = 0;
                                        if (sVar34 != 3) {
                                          if ((*(ushort *)((int)&local_13c + uVar32 * 2 + 2) & uVar4
                                              ) != 0) {
                                            *(undefined2 *)((int)puVar25 + 6) = (undefined2)param_15
                                            ;
                                          }
                                          sVar9 = 0;
                                          if (sVar34 != 4) {
                                            if ((*(ushort *)((int)&local_138 + uVar32 * 2) & uVar4)
                                                != 0) {
                                              *(undefined2 *)(puVar25 + 2) = (undefined2)param_15;
                                            }
                                            sVar9 = 0;
                                            if (sVar34 != 5) {
                                              if ((*(ushort *)((int)&local_138 + uVar32 * 2 + 2) &
                                                  uVar4) != 0) {
                                                *(undefined2 *)((int)puVar25 + 10) =
                                                     (undefined2)param_15;
                                              }
                                              sVar9 = 0;
                                              if (sVar34 != 6) {
                                                if ((*(ushort *)((int)&local_134 + uVar32 * 2) &
                                                    uVar4) != 0) {
                                                  *(undefined2 *)(puVar25 + 3) =
                                                       (undefined2)param_15;
                                                }
                                                sVar9 = 0;
                                                if (sVar34 != 7) {
                                                  if ((*(ushort *)((int)&local_134 + uVar32 * 2 + 2)
                                                      & uVar4) != 0) {
                                                    *(undefined2 *)((int)puVar25 + 0xe) =
                                                         (undefined2)param_15;
                                                  }
                                                  puVar25 = puVar25 + 4;
                                                  sVar9 = sVar34 + -8;
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                    sVar34 = sVar9;
                                    puVar22 = (ushort *)((int)puVar22 + 1);
                                  } while (sVar34 != 0);
                                  puVar22 = (ushort *)((int)puVar22 + iVar18);
                                  puVar25 = (uint *)((int)puVar25 + iVar15);
                                  local_1bc = (float)((int)local_1bc + 0xffff);
                                } while (SUB42(local_1bc,0) != 0);
                              }
                            }
                            break;
                          case 1:
                            if (param_18 == 0) {
                              do {
                                sVar34 = local_1b8;
                                do {
                                  if (*pbVar36 == 0) {
                                    uVar14 = 0;
                                  }
                                  else {
                                    uVar14 = (undefined2)param_15;
                                    if (*pbVar36 != 1) {
                                      uVar14 = (undefined2)param_20;
                                    }
                                  }
                                  *(undefined2 *)puVar25 = uVar14;
                                  sVar34 = sVar34 + -1;
                                  puVar25 = (uint *)((int)puVar25 + 2);
                                  pbVar36 = pbVar36 + 1;
                                } while (sVar34 != 0);
                                pbVar36 = pbVar36 + iVar18;
                                local_1bc = (float)((int)local_1bc + 0xffff);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                              } while (SUB42(local_1bc,0) != 0);
                            }
                            else {
                              do {
                                sVar34 = local_1b8;
                                do {
                                  if (*pbVar36 != 0) {
                                    uVar14 = (undefined2)param_15;
                                    if (*pbVar36 != 1) {
                                      uVar14 = (undefined2)param_20;
                                    }
                                    *(undefined2 *)puVar25 = uVar14;
                                  }
                                  sVar34 = sVar34 + -1;
                                  puVar25 = (uint *)((int)puVar25 + 2);
                                  pbVar36 = pbVar36 + 1;
                                } while (sVar34 != 0);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                pbVar36 = pbVar36 + iVar18;
                                local_1bc = (float)((int)local_1bc + 0xffff);
                              } while (SUB42(local_1bc,0) != 0);
                            }
                            break;
                          case 2:
                          case 0x12:
                          case 0x22:
                            if (param_18 == 0) {
                              do {
                                sVar34 = local_1b8;
                                do {
                                  if (*pbVar36 == 0) {
                                    *puVar25 = 0;
                                  }
                                  else {
                                    *puVar25 = (uint)*pbVar36 << 0x14 | param_15 & 0xffff;
                                  }
                                  sVar34 = sVar34 + -1;
                                  puVar25 = puVar25 + 1;
                                  pbVar36 = pbVar36 + 1;
                                } while (sVar34 != 0);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                pbVar36 = pbVar36 + iVar18;
                                local_1bc = (float)((int)local_1bc + 0xffff);
                              } while (SUB42(local_1bc,0) != 0);
                            }
                            else {
                              do {
                                sVar34 = local_1b8;
                                do {
                                  if (*pbVar36 != 0) {
                                    *puVar25 = (uint)*pbVar36 << 0x14 | param_15 & 0xffff;
                                  }
                                  sVar34 = sVar34 + -1;
                                  puVar25 = puVar25 + 1;
                                  pbVar36 = pbVar36 + 1;
                                } while (sVar34 != 0);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                pbVar36 = pbVar36 + iVar18;
                                local_1bc = (float)((int)local_1bc + 0xffff);
                              } while (SUB42(local_1bc,0) != 0);
                            }
                            break;
                          case 3:
                          case 0x13:
                          case 0x23:
                            uVar35 = param_15 >> 0xb;
                            local_198._1_3_ = (undefined3)((uint)local_198 >> 8);
                            local_198 = (ushort *)
                                        (CONCAT31(local_198._1_3_,(char)uVar35) & 0xffffff1f);
                            local_19a = (byte)(param_15 >> 5) & 0x3f;
                            local_191 = bVar28 & 0x1f;
                            uVar32 = param_20 >> 0xb;
                            local_1b4._0_1_ = (byte)uVar32 & 0x1f;
                            local_199 = (byte)(param_20 >> 5) & 0x3f;
                            local_1a9 = bVar27 & 0x1f;
                            if (param_18 == 0) {
                              do {
                                local_1d0 = (ushort *)(uVar30 & 0xffff);
                                do {
                                  bVar28 = *pbVar36;
                                  bVar27 = bVar28 & 0xf;
                                  if (bVar27 == 0) {
                                    if ((bVar28 & 0xf0) == 0) {
                                      *puVar25 = 0;
                                    }
                                    else {
                                      *puVar25 = (bVar28 & 0xf0) << 0x10 | param_20;
                                    }
                                  }
                                  else if (bVar27 == 0xf) {
                                    *puVar25 = param_15 & 0xffff | 0xff0000;
                                  }
                                  else {
                                    bVar28 = ('\x0f' - bVar27) * (bVar28 >> 4) + bVar28 * '\x10';
                                    *(byte *)((int)puVar25 + 2) = bVar28;
                                    uVar33 = ((*pbVar36 & 0xf) << 0xc) / (uint)bVar28;
                                    *(ushort *)puVar25 =
                                         ((short)(((uVar35 & 0x1f) - (uVar32 & 0x1f)) * uVar33 >> 8)
                                         + (ushort)(byte)local_1b4) * 0x800 |
                                         ((short)(((uint)local_19a - (uint)local_199) * uVar33 >> 8)
                                         + (ushort)local_199) * 0x20 |
                                         (short)(((uint)local_191 - (uint)local_1a9) * uVar33 >> 8)
                                         + (ushort)local_1a9;
                                  }
                                  local_1d0 = (ushort *)((int)local_1d0 + 0xffff);
                                  puVar25 = puVar25 + 1;
                                  pbVar36 = pbVar36 + 1;
                                } while ((short)local_1d0 != 0);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                pbVar36 = pbVar36 + iVar18;
                                local_1bc = (float)((int)local_1bc + 0xffff);
                              } while (SUB42(local_1bc,0) != 0);
                            }
                            else {
                              do {
                                local_1d0 = (ushort *)(uVar30 & 0xffff);
                                do {
                                  bVar28 = *pbVar36;
                                  bVar27 = bVar28 & 0xf;
                                  if (bVar27 == 0) {
                                    if ((bVar28 & 0xf0) != 0) {
                                      uVar33 = (bVar28 & 0xf0) << 0x10 | param_20;
                                      goto LAB_0053a7f4;
                                    }
                                  }
                                  else if (bVar27 == 0xf) {
                                    uVar33 = param_15 & 0xffff | 0xff0000;
LAB_0053a7f4:
                                    *puVar25 = uVar33;
                                  }
                                  else {
                                    bVar28 = ('\x0f' - bVar27) * (bVar28 >> 4) + bVar28 * '\x10';
                                    *(byte *)((int)puVar25 + 2) = bVar28;
                                    uVar33 = ((*pbVar36 & 0xf) << 0xc) / (uint)bVar28;
                                    *(ushort *)puVar25 =
                                         ((short)(((uVar35 & 0x1f) - (uVar32 & 0x1f)) * uVar33 >> 8)
                                         + (ushort)(byte)local_1b4) * 0x800 |
                                         ((short)(((uint)local_19a - (uint)local_199) * uVar33 >> 8)
                                         + (ushort)local_199) * 0x20 |
                                         (short)(((uint)local_191 - (uint)local_1a9) * uVar33 >> 8)
                                         + (ushort)local_1a9;
                                  }
                                  local_1d0 = (ushort *)((int)local_1d0 + 0xffff);
                                  puVar25 = puVar25 + 1;
                                  pbVar36 = pbVar36 + 1;
                                } while ((short)local_1d0 != 0);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                pbVar36 = pbVar36 + iVar18;
                                local_1bc = (float)((int)local_1bc + 0xffff);
                              } while (SUB42(local_1bc,0) != 0);
                            }
                          }
                        }
                        else if (iVar17 == 0x20) {
                          puVar25 = (uint *)(iVar18 * local_180 + local_e4 * 4 +
                                            *(int *)(param_16 + 0xc));
                          iVar19 = *(int *)(local_1b0 + 0x90d8c) + iVar15 * local_f8;
                          pbVar36 = (byte *)(iVar19 + local_fc);
                          iVar18 = iVar15 - uVar30;
                          local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar18);
                          iVar17 = local_180 + uVar30 * -4;
                          switch(*(undefined4 *)(local_1b0 + 0x93184)) {
                          case 0:
                            uVar32 = local_fc & 0x80000007;
                            if ((int)uVar32 < 0) {
                              uVar32 = (uVar32 - 1 | 0xfffffff8) + 1;
                            }
                            if (uVar32 == 0) {
                              local_1b4 = (ushort *)(((int)(local_fc + (uVar35 & 7)) >> 3) + iVar19)
                              ;
                              iVar15 = ((uVar30 >> 4) * -2 - (-(uint)((uVar30 & 0xf) != 0) & 2)) +
                                       iVar15;
                              local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar15);
                              iVar18 = local_180 + (uVar30 & 0xfffffff0) * -4;
                              if (param_18 == 0) {
                                do {
                                  sVar34 = local_1b8;
                                  do {
                                    uVar3 = *local_1b4;
                                    *puVar25 = -(uint)((uVar3 & 0x80) != 0) & param_15;
                                    sVar9 = 0;
                                    if (sVar34 != 1) {
                                      puVar25[1] = -(uint)((uVar3 & 0x40) != 0) & param_15;
                                      sVar9 = 0;
                                      if (sVar34 != 2) {
                                        puVar25[2] = -(uint)((uVar3 & 0x20) != 0) & param_15;
                                        sVar9 = 0;
                                        if (sVar34 != 3) {
                                          puVar25[3] = -(uint)((uVar3 & 0x10) != 0) & param_15;
                                          sVar9 = 0;
                                          if (sVar34 != 4) {
                                            puVar25[4] = -(uint)((uVar3 & 8) != 0) & param_15;
                                            sVar9 = 0;
                                            if (sVar34 != 5) {
                                              puVar25[5] = -(uint)((uVar3 & 4) != 0) & param_15;
                                              sVar9 = 0;
                                              if (sVar34 != 6) {
                                                puVar25[6] = -(uint)((uVar3 & 2) != 0) & param_15;
                                                sVar9 = 0;
                                                if (sVar34 != 7) {
                                                  puVar25[7] = -(uint)((uVar3 & 1) != 0) & param_15;
                                                  sVar9 = 0;
                                                  if (sVar34 != 8) {
                                                    puVar25[8] = -(uint)((uVar3 & 0x8000) != 0) &
                                                                 param_15;
                                                    sVar9 = 0;
                                                    if (sVar34 != 9) {
                                                      puVar25[9] = -(uint)((uVar3 & 0x4000) != 0) &
                                                                   param_15;
                                                      sVar9 = 0;
                                                      if (sVar34 != 10) {
                                                        puVar25[10] = -(uint)((uVar3 & 0x2000) != 0)
                                                                      & param_15;
                                                        sVar9 = 0;
                                                        if (sVar34 != 0xb) {
                                                          puVar25[0xb] = -(uint)((uVar3 & 0x1000) !=
                                                                                0) & param_15;
                                                          sVar9 = 0;
                                                          if (sVar34 != 0xc) {
                                                            puVar25[0xc] = -(uint)((uVar3 & 0x800)
                                                                                  != 0) & param_15;
                                                            sVar9 = 0;
                                                            if (sVar34 != 0xd) {
                                                              puVar25[0xd] = -(uint)((uVar3 & 0x400)
                                                                                    != 0) & param_15
                                                              ;
                                                              sVar9 = 0;
                                                              if (sVar34 != 0xe) {
                                                                puVar25[0xe] = -(uint)((uVar3 & 
                                                  0x200) != 0) & param_15;
                                                  sVar9 = 0;
                                                  if (sVar34 != 0xf) {
                                                    puVar25[0xf] = -(uint)((uVar3 & 0x100) != 0) &
                                                                   param_15;
                                                    puVar25 = puVar25 + 0x10;
                                                    sVar9 = sVar34 + -0x10;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                    sVar34 = sVar9;
                                    local_1b4 = local_1b4 + 1;
                                  } while (sVar34 != 0);
                                  local_1b4 = (ushort *)((int)local_1b4 + iVar15);
                                  puVar25 = (uint *)((int)puVar25 + iVar18);
                                  local_1bc = (float)((int)local_1bc + 0xffff);
                                } while (SUB42(local_1bc,0) != 0);
                              }
                              else {
                                do {
                                  uVar35 = uVar30 & 0xffff;
                                  do {
                                    uVar3 = *local_1b4;
                                    if ((char)uVar3 < '\0') {
                                      *puVar25 = param_15;
                                    }
                                    uVar32 = uVar35 + 0xffff;
                                    if ((short)uVar32 != 0) {
                                      if ((uVar3 & 0x40) != 0) {
                                        puVar25[1] = param_15;
                                      }
                                      uVar32 = uVar35 + 0x1fffe;
                                      if ((short)uVar32 != 0) {
                                        if ((uVar3 & 0x20) != 0) {
                                          puVar25[2] = param_15;
                                        }
                                        uVar32 = uVar35 + 0x2fffd;
                                        if ((short)uVar32 != 0) {
                                          if ((uVar3 & 0x10) != 0) {
                                            puVar25[3] = param_15;
                                          }
                                          uVar32 = uVar35 + 0x3fffc;
                                          if ((short)uVar32 != 0) {
                                            if ((uVar3 & 8) != 0) {
                                              puVar25[4] = param_15;
                                            }
                                            uVar32 = uVar35 + 0x4fffb;
                                            if ((short)uVar32 != 0) {
                                              if ((uVar3 & 4) != 0) {
                                                puVar25[5] = param_15;
                                              }
                                              uVar32 = uVar35 + 0x5fffa;
                                              if ((short)uVar32 != 0) {
                                                if ((uVar3 & 2) != 0) {
                                                  puVar25[6] = param_15;
                                                }
                                                uVar32 = uVar35 + 0x6fff9;
                                                if ((short)uVar32 != 0) {
                                                  if ((uVar3 & 1) != 0) {
                                                    puVar25[7] = param_15;
                                                  }
                                                  uVar32 = uVar35 + 0x7fff8;
                                                  if ((short)uVar32 != 0) {
                                                    if ((uVar3 & 0x8000) != 0) {
                                                      puVar25[8] = param_15;
                                                    }
                                                    uVar32 = uVar35 + 0x8fff7;
                                                    if ((short)uVar32 != 0) {
                                                      if ((uVar3 & 0x4000) != 0) {
                                                        puVar25[9] = param_15;
                                                      }
                                                      uVar32 = uVar35 + 0x9fff6;
                                                      if ((short)uVar32 != 0) {
                                                        if ((uVar3 & 0x2000) != 0) {
                                                          puVar25[10] = param_15;
                                                        }
                                                        uVar32 = uVar35 + 0xafff5;
                                                        if ((short)uVar32 != 0) {
                                                          if ((uVar3 & 0x1000) != 0) {
                                                            puVar25[0xb] = param_15;
                                                          }
                                                          uVar32 = uVar35 + 0xbfff4;
                                                          if ((short)uVar32 != 0) {
                                                            if ((uVar3 & 0x800) != 0) {
                                                              puVar25[0xc] = param_15;
                                                            }
                                                            uVar32 = uVar35 + 0xcfff3;
                                                            if ((short)uVar32 != 0) {
                                                              if ((uVar3 & 0x400) != 0) {
                                                                puVar25[0xd] = param_15;
                                                              }
                                                              uVar32 = uVar35 + 0xdfff2;
                                                              if ((short)uVar32 != 0) {
                                                                if ((uVar3 & 0x200) != 0) {
                                                                  puVar25[0xe] = param_15;
                                                                }
                                                                uVar32 = uVar35 + 0xefff1;
                                                                if ((short)uVar32 != 0) {
                                                                  if ((uVar3 & 0x100) != 0) {
                                                                    puVar25[0xf] = param_15;
                                                                  }
                                                                  puVar25 = puVar25 + 0x10;
                                                                  uVar32 = uVar35 + 0xffff0;
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                    local_1b4 = local_1b4 + 1;
                                    uVar35 = uVar32;
                                  } while ((short)uVar32 != 0);
                                  local_1b4 = (ushort *)((int)local_1b4 + iVar15);
                                  puVar25 = (uint *)((int)puVar25 + iVar18);
                                  local_1bc = (float)((int)local_1bc + 0xffff);
                                } while (SUB42(local_1bc,0) != 0);
                              }
                            }
                            else {
                              local_1b4 = (ushort *)(((int)(local_fc + (uVar35 & 7)) >> 3) + iVar19)
                              ;
                              local_140 = &DAT_00400080;
                              local_13c = 1.469413e-39;
                              local_138 = 3.67353e-40;
                              iVar18 = (iVar15 - (uint)((uVar30 & 7) != 0)) - (uVar30 >> 3);
                              iVar15 = local_180 + (uVar30 & 0xfffffff8) * -4;
                              local_134 = 9.18383e-41;
                              local_130 = 2.0078125;
                              local_12c = 2.52682e-29;
                              local_128 = 1.5050001e-36;
                              local_124 = 2.3511322e-38;
                              local_1a8 = (double)CONCAT44(local_1a8._4_4_,iVar18);
                              if (param_18 == 0) {
                                do {
                                  sVar34 = local_1b8;
                                  do {
                                    uVar3 = *local_1b4;
                                    *puVar25 = -(uint)((*(ushort *)((int)&local_140 + uVar32 * 2) &
                                                       uVar3) != 0) & param_15;
                                    sVar9 = 0;
                                    if (sVar34 != 1) {
                                      puVar25[1] = -(uint)((*(ushort *)
                                                             ((int)&local_140 + uVar32 * 2 + 2) &
                                                           uVar3) != 0) & param_15;
                                      sVar9 = 0;
                                      if (sVar34 != 2) {
                                        puVar25[2] = -(uint)((*(ushort *)
                                                               ((int)&local_13c + uVar32 * 2) &
                                                             uVar3) != 0) & param_15;
                                        sVar9 = 0;
                                        if (sVar34 != 3) {
                                          puVar25[3] = -(uint)((*(ushort *)
                                                                 ((int)&local_13c + uVar32 * 2 + 2)
                                                               & uVar3) != 0) & param_15;
                                          sVar9 = 0;
                                          if (sVar34 != 4) {
                                            puVar25[4] = -(uint)((*(ushort *)
                                                                   ((int)&local_138 + uVar32 * 2) &
                                                                 uVar3) != 0) & param_15;
                                            sVar9 = 0;
                                            if (sVar34 != 5) {
                                              puVar25[5] = -(uint)((*(ushort *)
                                                                     ((int)&local_138 +
                                                                     uVar32 * 2 + 2) & uVar3) != 0)
                                                           & param_15;
                                              sVar9 = 0;
                                              if (sVar34 != 6) {
                                                puVar25[6] = -(uint)((*(ushort *)
                                                                       ((int)&local_134 + uVar32 * 2
                                                                       ) & uVar3) != 0) & param_15;
                                                sVar9 = 0;
                                                if (sVar34 != 7) {
                                                  puVar25[7] = -(uint)((*(ushort *)
                                                                         ((int)&local_134 +
                                                                         uVar32 * 2 + 2) & uVar3) !=
                                                                      0) & param_15;
                                                  puVar25 = puVar25 + 8;
                                                  sVar9 = sVar34 + -8;
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                    sVar34 = sVar9;
                                    local_1b4 = (ushort *)((int)local_1b4 + 1);
                                  } while (sVar34 != 0);
                                  local_1b4 = (ushort *)((int)local_1b4 + iVar18);
                                  puVar25 = (uint *)((int)puVar25 + iVar15);
                                  local_1bc = (float)((int)local_1bc + 0xffff);
                                } while (SUB42(local_1bc,0) != 0);
                              }
                              else {
                                do {
                                  sVar34 = local_1b8;
                                  do {
                                    uVar3 = *local_1b4;
                                    if ((*(ushort *)((int)&local_140 + uVar32 * 2) & uVar3) != 0) {
                                      *puVar25 = param_15;
                                    }
                                    sVar9 = 0;
                                    if (sVar34 != 1) {
                                      if ((*(ushort *)((int)&local_140 + uVar32 * 2 + 2) & uVar3) !=
                                          0) {
                                        puVar25[1] = param_15;
                                      }
                                      sVar9 = 0;
                                      if (sVar34 != 2) {
                                        if ((*(ushort *)((int)&local_13c + uVar32 * 2) & uVar3) != 0
                                           ) {
                                          puVar25[2] = param_15;
                                        }
                                        sVar9 = 0;
                                        if (sVar34 != 3) {
                                          if ((*(ushort *)((int)&local_13c + uVar32 * 2 + 2) & uVar3
                                              ) != 0) {
                                            puVar25[3] = param_15;
                                          }
                                          sVar9 = 0;
                                          if (sVar34 != 4) {
                                            if ((*(ushort *)((int)&local_138 + uVar32 * 2) & uVar3)
                                                != 0) {
                                              puVar25[4] = param_15;
                                            }
                                            sVar9 = 0;
                                            if (sVar34 != 5) {
                                              if ((*(ushort *)((int)&local_138 + uVar32 * 2 + 2) &
                                                  uVar3) != 0) {
                                                puVar25[5] = param_15;
                                              }
                                              sVar9 = 0;
                                              if (sVar34 != 6) {
                                                if ((*(ushort *)((int)&local_134 + uVar32 * 2) &
                                                    uVar3) != 0) {
                                                  puVar25[6] = param_15;
                                                }
                                                sVar9 = 0;
                                                if (sVar34 != 7) {
                                                  if ((*(ushort *)((int)&local_134 + uVar32 * 2 + 2)
                                                      & uVar3) != 0) {
                                                    puVar25[7] = param_15;
                                                  }
                                                  puVar25 = puVar25 + 8;
                                                  sVar9 = sVar34 + -8;
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                    sVar34 = sVar9;
                                    local_1b4 = (ushort *)((int)local_1b4 + 1);
                                  } while (sVar34 != 0);
                                  local_1b4 = (ushort *)((int)local_1b4 + iVar18);
                                  puVar25 = (uint *)((int)puVar25 + iVar15);
                                  local_1bc = (float)((int)local_1bc + 0xffff);
                                } while (SUB42(local_1bc,0) != 0);
                              }
                            }
                            break;
                          case 1:
                            if (param_18 == 0) {
                              do {
                                sVar34 = local_1b8;
                                do {
                                  if (*pbVar36 == 0) {
                                    uVar30 = 0;
                                  }
                                  else if (*pbVar36 == 1) {
                                    uVar30 = param_15;
                                  }
                                  else {
                                    uVar30 = param_20 & 0xffffff;
                                  }
                                  *puVar25 = uVar30;
                                  sVar34 = sVar34 + -1;
                                  puVar25 = puVar25 + 1;
                                  pbVar36 = pbVar36 + 1;
                                } while (sVar34 != 0);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                local_1bc = (float)((int)local_1bc + 0xffff);
                                pbVar36 = pbVar36 + iVar18;
                              } while (SUB42(local_1bc,0) != 0);
                            }
                            else {
                              do {
                                sVar34 = local_1b8;
                                do {
                                  if (*pbVar36 != 0) {
                                    uVar30 = param_15;
                                    if (*pbVar36 != 1) {
                                      uVar30 = param_20 & 0xffffff;
                                    }
                                    *puVar25 = uVar30;
                                  }
                                  sVar34 = sVar34 + -1;
                                  puVar25 = puVar25 + 1;
                                  pbVar36 = pbVar36 + 1;
                                } while (sVar34 != 0);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                local_1bc = (float)((int)local_1bc + 0xffff);
                                pbVar36 = pbVar36 + iVar18;
                              } while (SUB42(local_1bc,0) != 0);
                            }
                            break;
                          case 2:
                          case 0x12:
                          case 0x22:
                            if (param_18 == 0) {
                              do {
                                sVar34 = local_1b8;
                                do {
                                  if (*pbVar36 == 0) {
                                    *puVar25 = 0;
                                  }
                                  else {
                                    *puVar25 = (uint)*pbVar36 << 0x1c | param_15;
                                  }
                                  sVar34 = sVar34 + -1;
                                  puVar25 = puVar25 + 1;
                                  pbVar36 = pbVar36 + 1;
                                } while (sVar34 != 0);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                local_1bc = (float)((int)local_1bc + 0xffff);
                                pbVar36 = pbVar36 + iVar18;
                              } while (SUB42(local_1bc,0) != 0);
                            }
                            else {
                              do {
                                sVar34 = local_1b8;
                                do {
                                  if (*pbVar36 != 0) {
                                    *puVar25 = (uint)*pbVar36 << 0x1c | param_15;
                                  }
                                  sVar34 = sVar34 + -1;
                                  puVar25 = puVar25 + 1;
                                  pbVar36 = pbVar36 + 1;
                                } while (sVar34 != 0);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                local_1bc = (float)((int)local_1bc + 0xffff);
                                pbVar36 = pbVar36 + iVar18;
                              } while (SUB42(local_1bc,0) != 0);
                            }
                            break;
                          case 3:
                          case 0x13:
                          case 0x23:
                            local_198 = (ushort *)CONCAT31(local_198._1_3_,bVar12);
                            local_19a = bVar10;
                            local_199 = bVar11;
                            if (param_18 == 0) {
                              do {
                                local_1d0 = (ushort *)(uVar30 & 0xffff);
                                do {
                                  bVar28 = *pbVar36;
                                  if ((bVar28 & 0xf) == 0) {
                                    if ((bVar28 & 0xf0) == 0) {
                                      *puVar25 = 0;
                                    }
                                    else {
                                      *puVar25 = (bVar28 & 0xfffffff0) << 0x18 | param_20;
                                    }
                                  }
                                  else if ((bVar28 & 0xf) == 0xf) {
                                    *puVar25 = param_15 | 0xff000000;
                                  }
                                  else {
                                    uVar32 = ((0xf - (bVar28 & 0xf)) * (uint)(bVar28 >> 4) +
                                             (uint)bVar28 * 0x10) * 0x1000000;
                                    *puVar25 = uVar32;
                                    uVar35 = ((*pbVar36 & 0xf) << 0xc) /
                                             (uint)*(byte *)((int)puVar25 + 3);
                                    *puVar25 = ((((uint)bVar11 - (uint)bVar29) * uVar35 & 0xffffff00
                                                ) + (uint)bVar29 * 0x100) * 0x100 |
                                               (((uint)bVar10 - (uint)bVar12) * uVar35 & 0xffffff00)
                                               + (uint)bVar12 * 0x100 |
                                               (((param_15 & 0xff) - (param_20 & 0xff)) * uVar35 >>
                                               8) + (param_20 & 0xff) | uVar32;
                                  }
                                  local_1d0 = (ushort *)((int)local_1d0 + 0xffff);
                                  puVar25 = puVar25 + 1;
                                  pbVar36 = pbVar36 + 1;
                                } while ((short)local_1d0 != 0);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                pbVar36 = pbVar36 + iVar18;
                                local_1bc = (float)((int)local_1bc + 0xffff);
                              } while (SUB42(local_1bc,0) != 0);
                            }
                            else {
                              do {
                                local_1d0 = (ushort *)(uVar30 & 0xffff);
                                do {
                                  bVar28 = *pbVar36;
                                  if ((bVar28 & 0xf) == 0) {
                                    if ((bVar28 & 0xf0) != 0) {
                                      *puVar25 = (bVar28 & 0xfffffff0) << 0x18 | param_20;
                                    }
                                  }
                                  else if ((bVar28 & 0xf) == 0xf) {
                                    *puVar25 = param_15 | 0xff000000;
                                  }
                                  else {
                                    uVar32 = ((0xf - (bVar28 & 0xf)) * (uint)(bVar28 >> 4) +
                                             (uint)bVar28 * 0x10) * 0x1000000;
                                    *puVar25 = uVar32;
                                    uVar35 = ((*pbVar36 & 0xf) << 0xc) /
                                             (uint)*(byte *)((int)puVar25 + 3);
                                    *puVar25 = ((((uint)bVar11 - (uint)bVar29) * uVar35 & 0xffffff00
                                                ) + (uint)bVar29 * 0x100) * 0x100 |
                                               (((uint)bVar10 - (uint)bVar12) * uVar35 & 0xffffff00)
                                               + (uint)bVar12 * 0x100 |
                                               (((param_15 & 0xff) - (param_20 & 0xff)) * uVar35 >>
                                               8) + (param_20 & 0xff) | uVar32;
                                  }
                                  local_1d0 = (ushort *)((int)local_1d0 + 0xffff);
                                  puVar25 = puVar25 + 1;
                                  pbVar36 = pbVar36 + 1;
                                } while ((short)local_1d0 != 0);
                                puVar25 = (uint *)((int)puVar25 + iVar17);
                                pbVar36 = pbVar36 + iVar18;
                                local_1bc = (float)((int)local_1bc + 0xffff);
                              } while (SUB42(local_1bc,0) != 0);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
switchD_0053850e_caseD_4:
        if ((param_25 == 0) || (param_26 <= local_e8)) {
          fVar38 = (float10)local_170;
          fVar16 = (float)local_168;
          fVar24 = local_15c;
        }
        else {
          puVar1 = (undefined1 *)(local_e8 * 0x20 + param_25);
          *puVar1 = 0;
          puVar1[1] = 0;
          puVar1[2] = 0;
          if (DAT_00aba24c == 0) {
            FUN_0057a980();
          }
          iVar15 = DAT_00aba24c;
          if (DAT_00aba24c == 0) {
            FUN_0057a980();
          }
          iVar18 = DAT_00aba24c;
          if (DAT_00aba250 == 0) {
            FUN_0057a980();
          }
          puVar25 = local_100;
          uVar23 = thunk_FUN_005736c0(*local_100,DAT_00aba250,iVar18,iVar15);
          uVar13 = thunk_FUN_00573310(uVar23);
          puVar1[0xd] = uVar13;
          if (param_6 == 0) {
            local_1c8 = local_18c + (float)local_168;
            fVar37 = (float10)local_188;
          }
          else {
            local_1c8 = (float)local_178 + (float)local_168;
            fVar37 = (float10)local_17c;
          }
          fVar16 = (float)local_168;
          fVar38 = (float10)local_170;
          if (*puVar25 == 10) {
            fVar40 = 0.0;
          }
          else {
            if (local_15c == 0.0) {
              iVar15 = *(int *)(local_1b0 + 0x93178);
            }
            else {
              iVar15 = (int)*(short *)((int)local_15c + 10) + *(int *)(local_1b0 + 0x93178);
              local_c8 = iVar15;
            }
            fVar40 = (float)iVar15 * (float)local_d0;
          }
          fVar41 = (float)local_78;
          fVar24 = local_15c;
          local_100 = puVar25;
          local_15c = fVar41;
          if (param_22 == 1) {
            *(float *)(puVar1 + 0x14) = local_1c8;
            *(float *)(puVar1 + 0x10) = (float)(fVar37 + fVar38);
            *(float *)(puVar1 + 0x1c) = fVar40;
            *(float *)(puVar1 + 0x18) = fVar41;
          }
          else {
            *(float *)(puVar1 + 0x10) = local_1c8;
            *(float *)(puVar1 + 0x14) = (float)(fVar37 + fVar38);
            *(float *)(puVar1 + 0x18) = fVar40;
            *(float *)(puVar1 + 0x1c) = fVar41;
          }
        }
        local_e8 = local_e8 + 1;
        if (*local_100 == 10) {
          local_d4 = local_d4 + 1;
          local_168 = 0.0;
          fVar16 = 0.0;
          fVar38 = fVar38 + (float10)local_78;
          local_170 = (double)fVar38;
        }
        else {
          if (fVar24 == 0.0) {
            iVar15 = *(int *)(local_1b0 + 0x93178);
          }
          else {
            iVar15 = (int)*(short *)((int)fVar24 + 10) + *(int *)(local_1b0 + 0x93178);
            local_c8 = iVar15;
          }
          fVar16 = (float)iVar15 * (float)local_d0 + fVar16;
          local_168 = (double)fVar16;
        }
        if ((float)local_b8 < fVar16) {
          local_b8 = (double)fVar16;
        }
        local_190 = (float)((int)local_190 + 1);
        local_100 = local_100 + 1;
      } while ((int)local_190 < (int)local_144);
      fVar16 = local_184;
    }
    local_184 = (float)(uint)*(ushort *)(local_1b0 + 0x93164);
    uVar30 = (uint)fVar16 & 0xffffff;
    local_170 = (double)((float10)(int)local_184 * (float10)local_d0 + fVar38);
    if (_DAT_00a38114 != uVar30) {
      _DAT_00a38114 = uVar30;
      if (DAT_00a37d78 == 0) {
        FUN_00581200();
      }
      else {
        FUN_00567b70();
      }
    }
  }
  else {
    fVar38 = (float10)0;
    local_168 = (double)fVar38;
    local_b8 = (double)fVar38;
    local_170 = (double)fVar38;
    if (0 < (int)local_144) {
      local_174 = (undefined1 *)(param_25 + 2);
      local_ec = local_144;
      do {
        local_15c = 0.0;
        if (*local_100 != 10) {
          local_15c = (float)FUN_00536b30(param_19,*local_100,&local_1b0,&local_150,&local_154,1,0);
        }
        if (param_19 == local_1b0) {
          if (param_6 == 0) {
            local_18c = local_98 + param_4;
            local_188 = local_94 + param_5;
          }
          else {
            local_178 = local_9c + param_2;
            local_17c = local_90 + param_3;
          }
        }
        else {
          local_178 = param_2;
          local_17c = param_3;
          if (param_22 == 0) {
            fVar16 = (float)(int)local_150 * (float)param_8;
            if (param_6 == 0) {
              local_184 = (float)(int)local_154 * (float)param_9;
              goto LAB_0053e055;
            }
            iVar15 = FUN_0050e240((double)fVar16);
LAB_0053e00e:
            local_178 = iVar15 + param_2;
            local_17c = FUN_0050e240();
            local_17c = local_17c + param_3;
            iVar15 = iVar15 + param_2;
          }
          else {
            fVar16 = (float)(int)local_154 * (float)param_9;
            if (param_6 != 0) {
              iVar15 = FUN_0050e240((double)fVar16);
              goto LAB_0053e00e;
            }
            local_184 = (float)(int)local_150 * (float)param_8;
LAB_0053e055:
            local_18c = fVar16 + local_18c;
            local_188 = local_184 + local_188;
            iVar15 = param_2;
          }
          iVar18 = local_17c;
          uVar3 = *(ushort *)(local_1b0 + 0x93166);
          if (uVar3 != 0) {
            if (param_22 == 0) {
              if (param_6 == 0) {
                local_184 = (float)uVar3 * (float)param_9;
                local_188 = local_188 - local_184 * (float)_DAT_00804a60;
              }
              else {
                local_184 = (float)(uint)uVar3;
                iVar15 = FUN_0050e240();
                local_17c = iVar18 - iVar15 / 2;
              }
            }
            else if (param_6 == 0) {
              local_184 = (float)uVar3 * (float)param_9;
              local_18c = local_18c - local_184 * (float)_DAT_00804a60;
            }
            else {
              local_184 = (float)(uint)uVar3;
              iVar18 = FUN_0050e240();
              local_178 = iVar15 - iVar18 / 2;
            }
          }
        }
        if ((param_25 == 0) || (param_26 <= local_e8)) {
          fVar16 = (float)local_168;
          fVar38 = (float10)local_170;
        }
        else {
          local_174[-2] = 0;
          local_174[-1] = 0;
          *local_174 = 0;
          if (DAT_00aba24c == 0) {
            FUN_0057a980();
          }
          iVar15 = DAT_00aba24c;
          if (DAT_00aba24c == 0) {
            FUN_0057a980();
          }
          iVar18 = DAT_00aba24c;
          if (DAT_00aba250 == 0) {
            FUN_0057a980();
          }
          uVar23 = thunk_FUN_005736c0(*local_100,DAT_00aba250,iVar18,iVar15);
          uVar13 = thunk_FUN_00573310(uVar23);
          local_174[0xb] = uVar13;
          if (param_6 == 0) {
            local_144 = local_18c + (float)local_168;
            fVar37 = (float10)local_188;
          }
          else {
            local_144 = (float)local_178 + (float)local_168;
            fVar37 = (float10)local_17c;
          }
          fVar16 = (float)local_168;
          fVar38 = (float10)local_170;
          if (*local_100 == 10) {
            fVar24 = 0.0;
          }
          else {
            if (local_15c == 0.0) {
              fVar24 = *(float *)(local_1b0 + 0x93178);
            }
            else {
              fVar24 = (float)((int)*(short *)((int)local_15c + 10) + *(int *)(local_1b0 + 0x93178))
              ;
              local_184 = fVar24;
            }
            fVar24 = (float)(int)fVar24 * (float)local_d0;
          }
          local_190 = (float)local_78;
          if (param_22 == 1) {
            *(float *)(local_174 + 0x12) = local_144;
            *(float *)(local_174 + 0xe) = (float)(fVar37 + fVar38);
            *(float *)(local_174 + 0x1a) = fVar24;
            *(float *)(local_174 + 0x16) = local_190;
          }
          else {
            *(float *)(local_174 + 0xe) = local_144;
            *(float *)(local_174 + 0x12) = (float)(fVar37 + fVar38);
            *(float *)(local_174 + 0x16) = fVar24;
            *(float *)(local_174 + 0x1a) = local_190;
          }
        }
        local_174 = local_174 + 0x20;
        local_e8 = local_e8 + 1;
        if (*local_100 == 10) {
          local_d4 = local_d4 + 1;
          local_168 = 0.0;
          fVar16 = 0.0;
          fVar38 = fVar38 + (float10)local_78;
          local_170 = (double)fVar38;
        }
        else {
          if (local_15c == 0.0) {
            fVar24 = *(float *)(local_1b0 + 0x93178);
          }
          else {
            fVar24 = (float)((int)*(short *)((int)local_15c + 10) + *(int *)(local_1b0 + 0x93178));
            local_184 = fVar24;
          }
          fVar16 = (float)(int)fVar24 * (float)local_d0 + fVar16;
          local_168 = (double)fVar16;
        }
        if ((float)local_b8 < fVar16) {
          local_b8 = (double)fVar16;
        }
        local_100 = local_100 + 1;
        local_ec = (float)((int)local_ec + -1);
      } while (local_ec != 0.0);
    }
    local_184 = (float)(uint)*(ushort *)(local_1b0 + 0x93164);
    local_170 = (double)((float10)(int)local_184 * (float10)local_d0 + fVar38);
  }
  if (param_23 != (undefined4 *)0x0) {
    if (param_22 == 1) {
      uVar23 = FUN_0050e240(local_170);
      dVar8 = local_b8;
    }
    else {
      uVar23 = FUN_0050e240(local_b8);
      dVar8 = local_170;
    }
    *param_23 = uVar23;
    uVar23 = FUN_0050e240(dVar8);
    param_23[1] = uVar23;
  }
  if (param_24 != (int *)0x0) {
    *param_24 = local_d4 + 1;
  }
  if (param_27 != (uint *)0x0) {
    *param_27 = local_e8;
  }
  if (local_c4 != 0) {
    FUN_0056e1d0();
  }
  DAT_00a38118 = 0;
  return (int)ROUND(local_b8);
}

