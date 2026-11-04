
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005ef4b0(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  uint uVar1;
  int *piVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int local_20c;
  int local_208;
  int local_204;
  int local_200;
  float local_1fc;
  float local_1f8;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  float local_1ac;
  float local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  float local_19c;
  float local_198;
  undefined4 local_194;
  undefined4 local_190;
  float local_18c;
  float local_188;
  undefined4 local_184;
  undefined4 local_180;
  float local_17c;
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
  float local_14c;
  float local_148;
  undefined4 local_144;
  undefined4 local_140;
  float local_13c;
  float local_138;
  undefined4 local_134;
  undefined4 local_130;
  float local_12c;
  float local_128;
  undefined4 local_124;
  undefined4 local_120;
  float local_11c;
  float local_118;
  undefined4 local_114;
  undefined4 local_110;
  float local_10c;
  float local_108;
  undefined4 local_104;
  undefined4 local_100;
  float local_fc;
  float local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  float local_ec;
  float local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  float local_dc;
  float local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  float local_cc;
  float local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  float local_bc;
  float local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  float local_ac;
  float local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  float local_44;
  float local_40;
  
  iVar5 = 0;
  iVar4 = FUN_00567b30();
  if (iVar4 == 0) {
    return 0xffffffff;
  }
  if (((((DAT_00cc47d0 == 0) || (uVar1 = *(uint *)(param_1 + 8), (int)uVar1 < 0)) ||
       ((uVar1 & 0x7c000000) != DAT_00cc47f8)) ||
      (((DAT_00cc4800 <= (int)(uVar1 & 0xffff) ||
        (piVar2 = *(int **)(DAT_00cc47d4 + (uVar1 & 0xffff) * 4), piVar2 == (int *)0x0)) ||
       ((*piVar2 * 0x10000 != (uVar1 & 0x3ff0000) || (piVar2[4] != 0)))))) &&
     ((((DAT_00cc79c0 == 0 || (uVar1 = *(uint *)(param_1 + 8), (int)uVar1 < 0)) ||
       (((uVar1 & 0x7c000000) != DAT_00cc79e8 ||
        (((DAT_00cc79f0 <= (int)(uVar1 & 0xffff) ||
          (piVar2 = *(int **)(DAT_00cc79c4 + (uVar1 & 0xffff) * 4), piVar2 == (int *)0x0)) ||
         (*piVar2 * 0x10000 != (uVar1 & 0x3ff0000))))))) || (piVar2[4] != 0)))) {
    return 0xffffffff;
  }
  if (param_2 == 8) {
    iVar5 = 0;
  }
  else if (param_2 == 0x10) {
    iVar5 = 1;
  }
  else if (param_2 == 0x20) {
    iVar5 = 2;
  }
  piVar2 = &DAT_00dda478 + iVar5;
  if ((int)(&DAT_00dda478)[iVar5] < 0) {
    iVar4 = FUN_005ee300(0);
    *piVar2 = iVar4;
    if (iVar4 < 0) {
      FUN_005764b0((&PTR_s_Gauss_08Pixel_PS_pso_008026e7_1_00a0566c)[iVar5],0xffffffff,0x7ffd,
                   &local_ac,0x80,0x4b0);
      FUN_0056bca0(&DAT_00802650,&local_ac);
      return 0xffffffff;
    }
    FUN_00580830(iVar4,piVar2);
  }
  FUN_005159a0(*(undefined4 *)(param_1 + 8),&local_200,&local_204);
  FUN_005ee540();
  local_1fc = (float)local_200;
  local_1f8 = (float)local_204;
  local_1ec = *param_4;
  local_1e8 = param_4[1];
  local_1e4 = param_4[2];
  local_1e0 = param_4[3];
  local_1dc = param_4[4];
  local_1d8 = param_4[5];
  local_1d4 = param_4[6];
  local_1d0 = param_4[7];
  local_1cc = param_4[8];
  local_1c8 = param_4[9];
  local_1c4 = param_4[10];
  local_1c0 = param_4[0xb];
  local_1bc = param_4[0xc];
  local_1b8 = param_4[0xd];
  local_1b4 = param_4[0xe];
  local_1b0 = param_4[0xf];
  if (*(int *)(param_1 + 0x1c) == 0) {
    local_1ac = 0.0 / local_1fc;
    local_1a8 = 0.0;
    local_1a4 = 0;
    local_1a0 = 0;
    local_19c = (float)_DAT_00805398 / local_1fc;
    local_198 = 0.0;
    local_194 = 0;
    local_190 = 0;
    local_18c = (float)_DAT_008026e0 / local_1fc;
    local_188 = 0.0;
    local_184 = 0;
    local_180 = 0;
    local_17c = (float)_DAT_007d0800 / local_1fc;
    local_178 = 0.0;
    local_174 = 0;
    local_170 = 0;
    local_16c = (float)_DAT_007d0a48 / local_1fc;
    local_168 = 0.0;
    local_164 = 0;
    local_160 = 0;
    local_15c = (float)_DAT_007d0a58 / local_1fc;
    local_158 = 0.0;
    local_154 = 0;
    local_150 = 0;
    local_14c = (float)_DAT_008026d8 / local_1fc;
    local_148 = 0.0;
    local_144 = 0;
    local_140 = 0;
    local_13c = (float)_DAT_008026d0 / local_1fc;
    local_138 = 0.0;
    local_134 = 0;
    local_130 = 0;
    local_12c = (float)_DAT_008026c8 / local_1fc;
    local_128 = 0.0;
    local_124 = 0;
    local_120 = 0;
    local_11c = (float)_DAT_008026c0 / local_1fc;
    local_118 = 0.0;
    local_114 = 0;
    local_110 = 0;
    local_10c = (float)_DAT_008026b8 / local_1fc;
    local_108 = 0.0;
    local_104 = 0;
    local_100 = 0;
    local_fc = (float)_DAT_008026b0 / local_1fc;
    local_f8 = 0.0;
    local_f4 = 0;
    local_f0 = 0;
    local_ec = (float)_DAT_008026a8 / local_1fc;
    local_e8 = 0.0;
    local_e4 = 0;
    local_e0 = 0;
    local_dc = (float)_DAT_008026a0 / local_1fc;
    local_d8 = 0.0;
    local_d4 = 0;
    local_d0 = 0;
    local_cc = (float)_DAT_00802698 / local_1fc;
    local_c8 = 0.0;
    local_c4 = 0;
    local_c0 = 0;
    local_bc = (float)_DAT_00802690 / local_1fc;
    local_b8 = 0.0;
    local_b4 = 0;
    local_b0 = 0;
  }
  else if (*(int *)(param_1 + 0x1c) == 1) {
    local_1a8 = 0.0 / local_1f8;
    local_1ac = 0.0;
    local_1a4 = 0;
    local_1a0 = 0;
    local_198 = (float)_DAT_00805398 / local_1f8;
    local_19c = 0.0;
    local_194 = 0;
    local_190 = 0;
    local_188 = (float)_DAT_008026e0 / local_1f8;
    local_18c = 0.0;
    local_184 = 0;
    local_180 = 0;
    local_178 = (float)_DAT_007d0800 / local_1f8;
    local_17c = 0.0;
    local_174 = 0;
    local_170 = 0;
    local_168 = (float)_DAT_007d0a48 / local_1f8;
    local_16c = 0.0;
    local_164 = 0;
    local_160 = 0;
    local_158 = (float)_DAT_007d0a58 / local_1f8;
    local_15c = 0.0;
    local_154 = 0;
    local_150 = 0;
    local_148 = (float)_DAT_008026d8 / local_1f8;
    local_14c = 0.0;
    local_144 = 0;
    local_140 = 0;
    local_138 = (float)_DAT_008026d0 / local_1f8;
    local_13c = 0.0;
    local_134 = 0;
    local_130 = 0;
    local_128 = (float)_DAT_008026c8 / local_1f8;
    local_12c = 0.0;
    local_124 = 0;
    local_120 = 0;
    local_118 = (float)_DAT_008026c0 / local_1f8;
    local_11c = 0.0;
    local_114 = 0;
    local_110 = 0;
    local_108 = (float)_DAT_008026b8 / local_1f8;
    local_10c = 0.0;
    local_104 = 0;
    local_100 = 0;
    local_f8 = (float)_DAT_008026b0 / local_1f8;
    local_fc = 0.0;
    local_f4 = 0;
    local_f0 = 0;
    local_e8 = (float)_DAT_008026a8 / local_1f8;
    local_ec = 0.0;
    local_e4 = 0;
    local_e0 = 0;
    local_d8 = (float)_DAT_008026a0 / local_1f8;
    local_dc = 0.0;
    local_d4 = 0;
    local_d0 = 0;
    local_c8 = (float)_DAT_00802698 / local_1f8;
    local_cc = 0.0;
    local_c4 = 0;
    local_c0 = 0;
    local_b8 = (float)_DAT_00802690 / local_1f8;
    local_bc = 0.0;
    local_b4 = 0;
    local_b0 = 0;
  }
  FUN_0059cb80(&DAT_00ddb600,3,1,0,&local_1fc,0x15,0);
  FUN_00516d40(*piVar2);
  FUN_005ee5d0(1,0);
  FUN_005ee580();
  FUN_0059cc80(&DAT_00ddb600,3,1,0,0x15);
  if (*(int *)(param_1 + 0x1c) == 0) {
    FUN_005159a0(*(undefined4 *)(param_1 + 0x10),&local_208,&local_20c);
    local_98 = (float)*(int *)(param_1 + 0x40);
    local_70 = (float)_DAT_00804a60;
    local_ac = local_98 - local_70;
    fVar3 = (float)*(int *)(param_1 + 0x44) +
            (float)(*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24));
    local_a8 = fVar3 - local_70;
    local_a4 = 0;
    local_a0 = 0x3f800000;
    local_7c = (float)(*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20)) + local_98;
    local_90 = local_7c - local_70;
    local_88 = 0;
    local_84 = 0x3f800000;
    local_70 = (float)local_20c - local_70;
    local_6c = 0;
    local_68 = 0x3f800000;
    local_50 = 0;
    local_4c = 0x3f800000;
    local_98 = local_98 / (float)local_208;
    local_94 = (fVar3 - (float)_DAT_00802e18) / (float)local_20c;
    local_7c = local_7c / (float)local_208;
    local_8c = local_a8;
    local_78 = local_94;
    local_74 = local_ac;
    local_60 = local_98;
    local_5c = local_94;
    local_58 = local_90;
    local_54 = local_70;
    local_44 = local_7c;
    local_40 = local_94;
    local_9c = FUN_00543f40(0xff,0xff,0xff,0xff);
    local_80 = local_9c;
    local_64 = local_9c;
    local_48 = local_9c;
    FUN_00521280(&local_ac,4,5,*(undefined4 *)(param_1 + 0x10),0);
  }
  return 0;
}

