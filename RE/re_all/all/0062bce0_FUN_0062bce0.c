
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __fastcall FUN_0062bce0(int *param_1)

{
  float fVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined1 uVar5;
  float local_2c4;
  float local_2c0;
  float local_2bc;
  float local_2b8;
  float local_2b4;
  float local_2b0;
  float local_2ac;
  float local_2a8;
  float local_2a4;
  float local_2a0;
  float local_29c;
  float local_298;
  float local_294;
  undefined4 local_290;
  float local_28c;
  float local_288;
  float local_284;
  float local_280;
  float local_27c;
  float local_278;
  float local_274;
  float local_270;
  undefined4 local_268;
  undefined4 local_264;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined4 local_254;
  int local_250;
  int local_24c;
  int local_248;
  int local_244;
  int local_240;
  int local_23c;
  int local_238;
  int local_234;
  float local_230;
  int local_22c;
  int local_228;
  int local_224;
  float local_220;
  int local_21c;
  int local_218;
  int local_214;
  float local_210;
  int local_20c;
  int local_208;
  int local_204;
  float local_200;
  int local_1fc;
  int local_1f8;
  int local_1f4;
  int local_1f0;
  int local_1ec;
  int local_1e8;
  int local_1e4;
  float local_1e0;
  float local_1dc;
  float local_1d8;
  float local_1d0;
  float local_1cc;
  float local_1c8;
  float local_1c0;
  float local_1bc;
  float local_1b8;
  float local_1b0;
  float local_1ac;
  float local_1a8;
  float local_1a0;
  float local_19c;
  float local_198;
  float local_190;
  float local_18c;
  float local_188;
  float local_180;
  float local_17c;
  float local_178;
  float local_170;
  float local_16c;
  float local_168;
  float local_160;
  float local_15c;
  float local_158;
  float local_150;
  float local_14c;
  float local_148;
  float local_140;
  float local_13c;
  float local_138;
  float local_130;
  float local_12c;
  float local_128;
  undefined1 local_120 [16];
  undefined1 local_110 [16];
  undefined1 local_100 [16];
  undefined1 local_f0 [32];
  undefined1 local_d0 [16];
  undefined1 local_c0 [16];
  undefined1 local_b0 [16];
  undefined1 local_a0 [16];
  undefined1 local_90 [16];
  undefined1 local_80 [16];
  undefined1 local_70 [16];
  undefined1 local_60 [16];
  undefined1 local_50 [16];
  undefined1 local_40 [16];
  undefined1 local_30 [16];
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  if ((char)param_1[0x58] == '\0') goto LAB_0062c9fd;
  *(undefined1 *)(param_1 + 0x57) = 0;
  FUN_0062dec0(0,0,0,0);
  FUN_0062deb0();
  *(undefined1 *)(param_1 + 0x58) = 0;
  switch(*param_1) {
  case 1:
    param_1[0x3d] = param_1[0x15];
    param_1[0x3e] = param_1[0x16];
    param_1[0x3f] = param_1[0x17];
    param_1[0x40] = param_1[0x18];
    param_1[0x41] = param_1[0x29];
    param_1[0x42] = param_1[0x2a];
    param_1[0x43] = param_1[0x2b];
    param_1[0x44] = param_1[0x2c];
    local_2c4 = (float)param_1[0x3f] - (float)param_1[0x43];
    local_2c0 = (float)param_1[0x3e] - (float)param_1[0x42];
    local_2bc = (float)param_1[0x3d] - (float)param_1[0x41];
    FUN_005fc500(&local_2bc,&local_2c0,&local_2c4);
    uVar5 = 0;
    param_1[0x45] = local_1f0;
    param_1[0x46] = local_1ec;
    param_1[0x47] = local_1e8;
    param_1[0x48] = local_1e4;
    *(undefined1 *)(param_1 + 0x57) = 0;
    FUN_0062dec0(0,0,0,0);
    FUN_0062deb0();
    param_1[0x53] = 0x3f800000;
    param_1[0x54] = 0;
    param_1[0x55] = 0;
    param_1[0x56] = 0;
    if (((_DAT_007d5344 <= (float)param_1[0x53]) && (_DAT_007d5344 <= (float)param_1[0x54])) &&
       ((_DAT_007d5344 <= (float)param_1[0x55] && (_DAT_007d5344 <= (float)param_1[0x56])))) {
      uVar5 = 1;
    }
    *(undefined1 *)(param_1 + 0x4d) = uVar5;
    return uVar5;
  case 2:
    local_2bc = -(float)param_1[3];
    local_2c0 = -(float)param_1[2];
    local_2b8 = -(float)param_1[1];
    FUN_005fc500(&local_2b8,&local_2c0,&local_2bc);
    local_2b8 = (float)param_1[7] - (float)param_1[3];
    local_2bc = (float)param_1[6] - (float)param_1[2];
    local_2c0 = (float)param_1[5] - (float)param_1[1];
    FUN_005fc500(&local_2c0,&local_2bc,&local_2b8);
    local_2c4 = local_298 * local_274 + local_294 * local_270 + local_278 * local_29c;
    if (local_2c4 <= _DAT_007d5344) {
      *(byte *)(param_1 + 0x52) = *(byte *)(param_1 + 0x52) | 1;
      local_2c4 = 0.0;
    }
    else {
      fVar1 = local_298 * local_298 + local_294 * local_294 + local_29c * local_29c;
      if (fVar1 <= local_2c4) {
        local_278 = local_278 - local_29c;
        *(ushort *)(param_1 + 0x52) = *(ushort *)(param_1 + 0x52) | 2;
        local_2c4 = 1.0;
        local_274 = local_274 - local_298;
        local_270 = local_270 - local_294;
      }
      else {
        local_2c4 = local_2c4 / fVar1;
        FUN_0060fe40(&local_150,&local_29c,&local_2c4);
        local_278 = local_278 - local_150;
        *(byte *)(param_1 + 0x52) = *(byte *)(param_1 + 0x52) | 3;
        local_274 = local_274 - local_14c;
        local_270 = local_270 - local_148;
      }
    }
    param_1[0x53] = (int)(_DAT_00804108 - local_2c4);
    param_1[0x54] = (int)local_2c4;
    param_1[0x55] = 0;
    param_1[0x56] = 0;
    FUN_0060fe40(&local_1c0,&local_29c,&local_2c4);
    local_2b8 = local_1b8 + (float)param_1[3];
    local_2bc = local_1bc + (float)param_1[2];
    local_2c0 = local_1c0 + (float)param_1[1];
    FUN_005fc500(&local_2c0,&local_2bc,&local_2b8);
    local_2b8 = (float)param_1[0x1b] - (float)param_1[0x17];
    local_2bc = (float)param_1[0x1a] - (float)param_1[0x16];
    local_2c0 = (float)param_1[0x19] - (float)param_1[0x15];
    FUN_005fc500(&local_2c0,&local_2bc,&local_2b8);
    FUN_0060fe40(&local_160,local_120,&local_2c4);
    local_2b0 = local_158 + (float)param_1[0x17];
    local_2b4 = local_15c + (float)param_1[0x16];
    local_2ac = local_160 + (float)param_1[0x15];
    FUN_005fc500(&local_2ac,&local_2b4,&local_2b0);
    param_1[0x3d] = (int)local_200;
    param_1[0x3e] = local_1fc;
    param_1[0x3f] = local_1f8;
    param_1[0x40] = local_1f4;
    local_2ac = (float)param_1[0x2f] - (float)param_1[0x2b];
    local_2b4 = (float)param_1[0x2e] - (float)param_1[0x2a];
    local_2b0 = (float)param_1[0x2d] - (float)param_1[0x29];
    FUN_005fc500(&local_2b0,&local_2b4,&local_2ac);
    FUN_0060fe40(&local_1a0,local_110,&local_2c4);
    local_2b8 = local_198 + (float)param_1[0x2b];
    local_2bc = local_19c + (float)param_1[0x2a];
    local_2c0 = local_1a0 + (float)param_1[0x29];
    FUN_005fc500(&local_2c0,&local_2bc,&local_2b8);
    param_1[0x41] = (int)local_220;
    param_1[0x42] = local_21c;
    param_1[0x43] = local_218;
    param_1[0x44] = local_214;
    local_2ac = (float)param_1[0x3f] - (float)param_1[0x43];
    local_2b4 = (float)param_1[0x3e] - (float)param_1[0x42];
    local_2b0 = (float)param_1[0x3d] - (float)param_1[0x41];
    FUN_005fc500(&local_2b0,&local_2b4,&local_2ac);
    param_1[0x45] = local_240;
    param_1[0x46] = local_23c;
    param_1[0x47] = local_238;
    param_1[0x48] = local_234;
    if ((3 < *param_1) && ((*(byte *)(param_1 + 0x52) & 8) == 0)) {
      FUN_0062b940(3);
    }
    if ((2 < *param_1) && ((*(byte *)(param_1 + 0x52) & 4) == 0)) {
      FUN_0062b940(2);
    }
    if ((1 < *param_1) && ((*(byte *)(param_1 + 0x52) & 2) == 0)) {
      FUN_0062b940(1);
    }
    if ((0 < *param_1) && ((*(byte *)(param_1 + 0x52) & 1) == 0)) {
      FUN_0062b940(0);
    }
    if ((((_DAT_007d5344 <= (float)param_1[0x53]) && (_DAT_007d5344 <= (float)param_1[0x54])) &&
        (_DAT_007d5344 <= (float)param_1[0x55])) && (_DAT_007d5344 <= (float)param_1[0x56])) {
      *(undefined1 *)(param_1 + 0x4d) = 1;
      return 1;
    }
    goto LAB_0062c989;
  case 3:
    local_29c = 0.0;
    local_298 = 0.0;
    local_294 = 0.0;
    local_290 = 0;
    FUN_0062cc90(&local_29c,param_1 + 1,param_1 + 5,param_1 + 9,param_1 + 0x4e);
    local_2ac = (float)param_1[0x1f] * (float)param_1[0x55];
    local_2b4 = (float)param_1[0x1e] * (float)param_1[0x55];
    local_2b0 = (float)param_1[0x1d] * (float)param_1[0x55];
    FUN_005fc500(&local_2b0,&local_2b4,&local_2ac);
    local_2b8 = (float)param_1[0x1b] * (float)param_1[0x54];
    local_2bc = (float)param_1[0x1a] * (float)param_1[0x54];
    local_2c0 = (float)param_1[0x19] * (float)param_1[0x54];
    FUN_005fc500(&local_2c0,&local_2bc,&local_2b8);
    local_2c4 = (float)param_1[0x17] * (float)param_1[0x53];
    local_284 = (float)param_1[0x16] * (float)param_1[0x53];
    local_280 = (float)param_1[0x53] * (float)param_1[0x15];
    FUN_005fc500(&local_280,&local_284,&local_2c4);
    local_27c = local_128 + local_178;
    local_288 = local_12c + local_17c;
    local_28c = local_130 + local_180;
    FUN_005fc500(&local_28c,&local_288,&local_27c);
    local_2a8 = local_138 + local_1c8;
    local_2a4 = local_13c + local_1cc;
    local_2a0 = local_140 + local_1d0;
    FUN_005fc500(&local_2a0,&local_2a4,&local_2a8);
    param_1[0x3d] = (int)local_230;
    param_1[0x3e] = local_22c;
    param_1[0x3f] = local_228;
    param_1[0x40] = local_224;
    local_2a0 = (float)param_1[0x33] * (float)param_1[0x55];
    local_2a4 = (float)param_1[0x32] * (float)param_1[0x55];
    local_2a8 = (float)param_1[0x55] * (float)param_1[0x31];
    FUN_005fc500(&local_2a8,&local_2a4,&local_2a0);
    local_28c = (float)param_1[0x2f] * (float)param_1[0x54];
    local_288 = (float)param_1[0x2e] * (float)param_1[0x54];
    local_27c = (float)param_1[0x2d] * (float)param_1[0x54];
    FUN_005fc500(&local_27c,&local_288,&local_28c);
    local_280 = (float)param_1[0x2b] * (float)param_1[0x53];
    local_284 = (float)param_1[0x2a] * (float)param_1[0x53];
    local_2ac = (float)param_1[0x29] * (float)param_1[0x53];
    FUN_005fc500(&local_2ac,&local_284,&local_280);
    local_2b4 = local_1a8 + local_188;
    local_2b0 = local_1ac + local_18c;
    local_2b8 = local_1b0 + local_190;
    FUN_005fc500(&local_2b8,&local_2b0,&local_2b4);
    local_2bc = local_168 + local_1d8;
    local_2c0 = local_16c + local_1dc;
    local_2c4 = local_170 + local_1e0;
    FUN_005fc500(&local_2c4,&local_2c0,&local_2bc);
    param_1[0x41] = (int)local_210;
    param_1[0x42] = local_20c;
    param_1[0x43] = local_208;
    param_1[0x44] = local_204;
    local_2a0 = (float)param_1[0x3f] - (float)param_1[0x43];
    local_2a4 = (float)param_1[0x3e] - (float)param_1[0x42];
    local_2a8 = (float)param_1[0x3d] - (float)param_1[0x41];
    FUN_005fc500(&local_2a8,&local_2a4,&local_2a0);
    param_1[0x45] = local_250;
    param_1[0x46] = local_24c;
    param_1[0x47] = local_248;
    param_1[0x48] = local_244;
LAB_0062c702:
    FUN_0062b9c0(param_1 + 0x52);
    if ((((_DAT_007d5344 <= (float)param_1[0x53]) && (_DAT_007d5344 <= (float)param_1[0x54])) &&
        (_DAT_007d5344 <= (float)param_1[0x55])) && (_DAT_007d5344 <= (float)param_1[0x56])) {
      *(undefined1 *)(param_1 + 0x4d) = 1;
      return 1;
    }
LAB_0062c989:
    *(undefined1 *)(param_1 + 0x4d) = 0;
    return 0;
  case 4:
    local_254 = 0;
    local_25c = 0;
    local_268 = 0;
    FUN_005fc500(&local_268,&local_25c,&local_254);
    cVar2 = FUN_0062d550(&local_29c,param_1 + 1,param_1 + 5,param_1 + 9,param_1 + 0xd,param_1 + 0x4e
                        );
    if (cVar2 != '\0') {
      uVar3 = FUN_0060fe40(local_100,param_1 + 0x21,param_1 + 0x56);
      uVar3 = FUN_0060fe40(local_40,param_1 + 0x1d,param_1 + 0x55,uVar3);
      uVar3 = FUN_0060fe40(local_c0,param_1 + 0x19,param_1 + 0x54,uVar3);
      uVar3 = FUN_0060fe40(local_60,param_1 + 0x15,param_1 + 0x53,uVar3);
      uVar3 = FUN_0060f480(local_a0,uVar3);
      uVar3 = FUN_0060f480(local_20,uVar3);
      piVar4 = (int *)FUN_0060f480(local_80,uVar3);
      param_1[0x3d] = *piVar4;
      param_1[0x3e] = piVar4[1];
      param_1[0x3f] = piVar4[2];
      param_1[0x40] = piVar4[3];
      uVar3 = FUN_0060fe40(local_f0,param_1 + 0x35,param_1 + 0x56);
      uVar3 = FUN_0060fe40(local_d0,param_1 + 0x31,param_1 + 0x55,uVar3);
      uVar3 = FUN_0060fe40(local_b0,param_1 + 0x2d,param_1 + 0x54,uVar3);
      uVar3 = FUN_0060fe40(local_90,param_1 + 0x29,param_1 + 0x53,uVar3);
      uVar3 = FUN_0060f480(local_70,uVar3);
      uVar3 = FUN_0060f480(local_50,uVar3);
      piVar4 = (int *)FUN_0060f480(local_30,uVar3);
      param_1[0x41] = *piVar4;
      param_1[0x42] = piVar4[1];
      param_1[0x43] = piVar4[2];
      param_1[0x44] = piVar4[3];
      piVar4 = (int *)FUN_005fc590(local_10,param_1 + 0x3d,param_1 + 0x41);
      param_1[0x45] = *piVar4;
      param_1[0x46] = piVar4[1];
      param_1[0x47] = piVar4[2];
      param_1[0x48] = piVar4[3];
      goto LAB_0062c702;
    }
    if ((char)param_1[0x57] == '\0') {
      *(undefined1 *)(param_1 + 0x4d) = 1;
      local_260 = 0;
      local_258 = 0;
      local_264 = 0;
      FUN_005fc530(&local_264,&local_258,&local_260);
      return (char)param_1[0x4d];
    }
  }
  *(undefined1 *)(param_1 + 0x4d) = 0;
LAB_0062c9fd:
  return (char)param_1[0x4d];
}

