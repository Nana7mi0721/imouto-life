
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005efde0(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float *pfVar7;
  uint uVar8;
  int iVar9;
  float local_1ac;
  float local_1a8 [5];
  undefined4 local_194;
  undefined4 local_190;
  float local_18c;
  float local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  float local_178;
  undefined4 local_174;
  undefined4 local_170;
  float local_16c;
  float local_168;
  undefined4 local_164;
  undefined4 local_160;
  float local_15c;
  float local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  float local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  float local_138;
  undefined4 local_134;
  undefined4 local_130;
  float local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  float local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  float local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  float local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined1 local_80 [128];
  
  iVar9 = 0;
  uVar8 = 0;
  iVar6 = FUN_00567b30();
  if ((((iVar6 != 0) && (DAT_00cc47d0 != 0)) && (uVar2 = *(uint *)(param_1 + 8), -1 < (int)uVar2))
     && (((uVar2 & 0x7c000000) == DAT_00cc47f8 && ((int)(uVar2 & 0xffff) < DAT_00cc4800)))) {
    piVar3 = *(int **)(DAT_00cc47d4 + (uVar2 & 0xffff) * 4);
    if ((piVar3 != (int *)0x0) && ((*piVar3 * 0x10000 == (uVar2 & 0x3ff0000) && (piVar3[4] == 0))))
    {
      if (param_2 == 2) {
        iVar9 = 0;
      }
      else if (param_2 == 4) {
        iVar9 = 1;
      }
      else if (param_2 == 8) {
        iVar9 = 2;
      }
      piVar1 = &DAT_00dda4ac + iVar9;
      if ((int)(&DAT_00dda4ac)[iVar9] < 0) {
        iVar6 = FUN_005ee300(0);
        *piVar1 = iVar6;
        if (iVar6 < 0) {
          FUN_005764b0((&PTR_s_DownScaleX2_pso_00a05678)[iVar9],0xffffffff,0x7ffd,local_80,0x80,
                       0x4b0);
          FUN_0056bca0(&DAT_00802650,local_80);
          return 0xffffffff;
        }
        FUN_00580830(iVar6,piVar1);
      }
      FUN_005ee540();
      if (param_2 == 2) {
        uVar8 = 1;
        local_1ac = 0.0;
        local_1a8[0] = 0.0;
        local_1a8[1] = 0.0;
        local_1a8[2] = 0.0;
      }
      else if (param_2 == 4) {
        uVar8 = 4;
        local_1ac = _DAT_007d5340;
        local_1a8[0] = _DAT_007d5340;
        local_1a8[1] = 0.0;
        local_1a8[2] = 0.0;
        local_1a8[3] = 1.0;
        local_188 = 1.0;
        local_17c = 0x3f800000;
        local_178 = 1.0;
        local_1a8[4] = _DAT_007d5340;
        local_18c = _DAT_007d5340;
        local_194 = 0;
        local_190 = 0;
        local_184 = 0;
        local_180 = 0;
        local_174 = 0;
        local_170 = 0;
      }
      else if (param_2 == 8) {
        uVar8 = 0x10;
        local_1ac = _DAT_00802734;
        local_1a8[0] = _DAT_00802734;
        local_1a8[1] = 0.0;
        local_1a8[2] = 0.0;
        local_1a8[3] = _DAT_007d5340;
        local_1a8[4] = _DAT_00802734;
        local_194 = 0;
        local_190 = 0;
        local_18c = 1.0;
        local_188 = _DAT_00802734;
        local_184 = 0;
        local_180 = 0;
        local_17c = _DAT_00802730;
        local_13c = _DAT_00802730;
        local_fc = _DAT_00802730;
        local_e8 = _DAT_00802730;
        local_d8 = _DAT_00802730;
        local_c8 = _DAT_00802730;
        local_bc = _DAT_00802730;
        local_b8 = _DAT_00802730;
        local_178 = _DAT_00802734;
        local_16c = _DAT_00802734;
        local_12c = _DAT_00802734;
        local_ec = _DAT_00802734;
        local_174 = 0;
        local_170 = 0;
        local_164 = 0;
        local_160 = 0;
        local_154 = 0;
        local_150 = 0;
        local_144 = 0;
        local_140 = 0;
        local_134 = 0;
        local_130 = 0;
        local_124 = 0;
        local_120 = 0;
        local_114 = 0;
        local_110 = 0;
        local_104 = 0;
        local_100 = 0;
        local_f4 = 0;
        local_f0 = 0;
        local_e4 = 0;
        local_e0 = 0;
        local_d4 = 0;
        local_d0 = 0;
        local_c4 = 0;
        local_c0 = 0;
        local_b4 = 0;
        local_b0 = 0;
        local_168 = _DAT_007d5340;
        local_15c = _DAT_007d5340;
        local_158 = _DAT_007d5340;
        local_148 = _DAT_007d5340;
        local_138 = _DAT_007d5340;
        local_11c = _DAT_007d5340;
        local_dc = _DAT_007d5340;
        local_14c = 0x3f800000;
        local_128 = 0x3f800000;
        local_118 = 0x3f800000;
        local_10c = 0x3f800000;
        local_108 = 0x3f800000;
        local_f8 = 0x3f800000;
        local_cc = 0x3f800000;
      }
      fVar4 = (float)*(int *)(piVar3[0x13] + 0x50);
      iVar9 = 0;
      fVar5 = (float)*(int *)(piVar3[0x13] + 0x54);
      if (3 < uVar8) {
        iVar6 = (uVar8 - 4 >> 2) + 1;
        iVar9 = iVar6 * 4;
        pfVar7 = local_1a8;
        do {
          iVar6 = iVar6 + -1;
          pfVar7[-1] = pfVar7[-1] / fVar4;
          *pfVar7 = *pfVar7 / fVar5;
          pfVar7[3] = pfVar7[3] / fVar4;
          pfVar7[4] = pfVar7[4] / fVar5;
          pfVar7[7] = pfVar7[7] / fVar4;
          pfVar7[8] = pfVar7[8] / fVar5;
          pfVar7[0xb] = pfVar7[0xb] / fVar4;
          pfVar7[0xc] = pfVar7[0xc] / fVar5;
          pfVar7 = pfVar7 + 0x10;
        } while (iVar6 != 0);
      }
      if (iVar9 < (int)uVar8) {
        iVar6 = uVar8 - iVar9;
        pfVar7 = local_1a8 + iVar9 * 4;
        do {
          iVar6 = iVar6 + -1;
          pfVar7[-1] = pfVar7[-1] / fVar4;
          *pfVar7 = *pfVar7 / fVar5;
          pfVar7 = pfVar7 + 4;
        } while (iVar6 != 0);
      }
      FUN_0059cb80(&DAT_00ddb600,3,1,0,&local_1ac,uVar8,0);
      FUN_00516d40(*piVar1);
      FUN_005ee5d0(param_2,0);
      FUN_005ee580();
      FUN_0059cc80(&DAT_00ddb600,3,1,0,uVar8);
      return 0;
    }
  }
  return 0xffffffff;
}

