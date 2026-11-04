
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005dd780(int *param_1)

{
  undefined4 uVar1;
  int local_25c;
  float local_254;
  float local_250;
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  float local_23c;
  float local_238;
  float local_234;
  float local_230;
  float local_22c;
  float local_228;
  undefined4 local_224;
  undefined4 local_220;
  undefined4 local_21c;
  undefined4 local_218;
  float local_214;
  float local_210;
  float local_20c;
  float local_208;
  float local_204;
  float local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  float local_1ec;
  float local_1e8;
  float local_1e4;
  float local_1e0;
  float local_1dc;
  float local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  float local_1c4;
  float local_1c0;
  float local_1bc;
  float local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  int local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined2 local_174;
  undefined2 local_172;
  undefined2 local_170;
  undefined2 local_16e;
  undefined2 local_16c;
  undefined2 local_16a;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined2 local_15c;
  undefined2 local_15a;
  undefined2 local_158;
  undefined2 local_156;
  undefined2 local_154;
  undefined2 local_152;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined2 local_144;
  undefined2 local_142;
  undefined2 local_140;
  undefined2 local_13e;
  undefined2 local_13c;
  undefined2 local_13a;
  
  local_25c = 0;
  if ((DAT_00ca39f4 != 0) && (DAT_00f3a154 != 0)) {
    if (DAT_00ca39dc != 0) {
      local_25c = FUN_00519300(DAT_00ca39dc,0);
      if (local_25c == 0) {
        DAT_00ca39dc = 0;
      }
    }
    FUN_005a0bd0(DAT_00f3a168,0);
    FUN_0059d430();
    uVar1 = DAT_00e80b78;
    FUN_0059a710(0);
    FUN_0059b780(0);
    FUN_0059b870(0);
    FUN_0059b8e0(0,0);
    FUN_0059b940(0);
    DAT_00e39a54 = 1;
    FUN_005a0ad0(DAT_00a38194,DAT_00a38198,DAT_00a3819c,DAT_00a381a0);
    DAT_00e39a54 = 0;
    FUN_0056d380(&local_1b4,0,0x1b4);
    local_1b0 = 0;
    local_1a4 = 0;
    local_17c = 0;
    local_174 = 1;
    local_184 = 3;
    local_170 = 2;
    local_16e = 2;
    local_16a = 2;
    if (local_25c == 0) {
      local_1ac = (-(uint)(DAT_00ca39e4 != 0) & 3) + 3;
      local_1b4 = 1;
      local_1a8 = 0;
      local_1a0 = 0xffffffff;
      local_19c = 0xffffffff;
      local_198 = 0xffffffff;
      local_194 = 0xffffffff;
      local_190 = 0xffffffff;
      local_18c = 0xffffffff;
      local_188 = 0xffffffff;
      local_178 = 0xffffffff;
      local_180 = DAT_00f3a150;
      local_172 = 0xffff;
      local_16c = 0xffff;
      local_160 = 0xffffffff;
      local_168 = DAT_00f3a14c;
      local_164 = 1;
      local_15c = 2;
      local_15a = 0xffff;
      local_158 = 2;
      local_156 = 1;
      local_154 = 0xffff;
      local_152 = 2;
      local_148 = 0xffffffff;
      local_150 = 0;
      local_14c = 0;
      local_13e = 2;
      local_13c = 0;
      local_13a = 1;
      local_144 = 2;
      local_142 = 0;
      local_140 = 1;
      FUN_005a7d70(&local_1b4,0,0,0);
    }
    else {
      local_1ac = (-(uint)(DAT_00ca39e4 != 0) & 3) + 3;
      local_180 = DAT_00f3a150;
      local_1b4 = 0;
      local_1a8 = 1;
      local_1a0 = 0xffffffff;
      local_19c = 5;
      local_198 = 6;
      local_194 = 1;
      local_190 = 0xffffffff;
      local_18c = 0xffffffff;
      local_188 = 0xffffffff;
      local_178 = 0xffffffff;
      local_172 = 0xffff;
      local_16c = 0xffff;
      local_160 = 0xffffffff;
      local_168 = *(undefined4 *)**(undefined4 **)(local_25c + 0x100);
      local_164 = 1;
      if (DAT_00ca39e4 == 0) {
        local_15c = 3;
        local_15a = 2;
        local_158 = 10;
      }
      else {
        local_15c = 2;
        local_15a = 0xffff;
        local_158 = 2;
      }
      local_156 = 1;
      local_154 = 0xffff;
      local_152 = 2;
      local_148 = 0xffffffff;
      local_150 = 0;
      local_14c = 0;
      local_13e = 2;
      local_13c = 0;
      local_13a = 1;
      local_144 = 2;
      local_142 = 0;
      local_140 = 1;
      FUN_005a7d70(&local_1b4,0,0,0);
      if ((DAT_00a37dc8 != 0) && (DAT_00ca39e0 != 0)) {
        if (DAT_00ca39e4 == 0) {
          FUN_0059b820((&DAT_00e0313c)[DAT_00ca39e0],0);
        }
        else {
          FUN_0059b820((&DAT_00e0314c)[DAT_00ca39e0],0);
        }
      }
    }
    FUN_0059d430();
    local_1e4 = (float)*param_1;
    local_200 = (float)_DAT_00804a60;
    local_254 = local_1e4 - local_200;
    local_250 = (float)param_1[1] - local_200;
    local_22c = (float)param_1[2] - local_200;
    local_200 = (float)param_1[3] - local_200;
    local_23c = local_1e4 / (float)DAT_00f3a144;
    local_238 = (float)param_1[1] / (float)DAT_00f3a148;
    local_214 = (float)param_1[2] / (float)DAT_00f3a144;
    local_1e8 = (float)param_1[3] / (float)DAT_00f3a148;
    if (local_25c == 0) {
      local_208 = local_238;
      local_1e4 = local_23c;
      local_1e0 = local_1e8;
      local_1bc = local_214;
    }
    else {
      local_1e4 = local_1e4 / (float)*(int *)(*(int *)(local_25c + 0x100) + 0x14);
      local_208 = (float)param_1[1] / (float)*(int *)(*(int *)(local_25c + 0x100) + 0x18);
      local_1bc = (float)param_1[2] / (float)*(int *)(*(int *)(local_25c + 0x100) + 0x14);
      local_1e0 = (float)param_1[3] / (float)*(int *)(*(int *)(local_25c + 0x100) + 0x18);
    }
    local_1cc = 0xffffffff;
    local_1d4 = 0;
    local_1f4 = 0xffffffff;
    local_1fc = 0;
    local_21c = 0xffffffff;
    local_224 = 0;
    local_244 = 0xffffffff;
    local_24c = 0;
    local_1c8 = 0;
    local_1f0 = 0;
    local_1d0 = 0x3f800000;
    local_218 = 0;
    local_1f8 = 0x3f800000;
    local_240 = 0;
    local_220 = 0x3f800000;
    local_248 = 0x3f800000;
    local_234 = local_1e4;
    local_230 = local_208;
    local_228 = local_250;
    local_210 = local_238;
    local_20c = local_1bc;
    local_204 = local_254;
    local_1ec = local_23c;
    local_1dc = local_22c;
    local_1d8 = local_200;
    local_1c4 = local_214;
    local_1c0 = local_1e8;
    local_1b8 = local_1e0;
    FUN_005a0c60(0x2c4);
    FUN_005d3b40(5,2,&local_254,0x28);
    DAT_00a37de4 = DAT_00a37de4 + 1;
    FUN_0059d460();
    FUN_0059d430();
    FUN_0059a710(uVar1);
    FUN_005a0bd0(DAT_00f3a154,0);
    DAT_00e39a54 = 1;
    FUN_005a0ad0(DAT_00a38194,DAT_00a38198,DAT_00a3819c,DAT_00a381a0);
    DAT_00e39a54 = 0;
  }
  return 0;
}

