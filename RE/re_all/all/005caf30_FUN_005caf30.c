
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005caf30(int *param_1,int *param_2,int param_3,int param_4,int param_5,int param_6,int *param_7,
            int param_8,int *param_9,int param_10)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  float *pfVar7;
  float *pfVar8;
  int iVar9;
  bool bVar10;
  undefined4 uVar11;
  int iStack_274;
  undefined1 auStack_270 [4];
  float fStack_26c;
  float fStack_268;
  float fStack_264;
  float local_260;
  int local_25c [5];
  float fStack_248;
  float fStack_244;
  float fStack_240;
  float fStack_23c;
  float fStack_238;
  float fStack_234;
  float fStack_230;
  float fStack_22c;
  float fStack_228;
  float fStack_224;
  float fStack_220;
  float fStack_21c;
  float fStack_218;
  float fStack_214;
  float fStack_210;
  float fStack_20c;
  float fStack_208;
  float fStack_204;
  float fStack_200;
  float fStack_1fc;
  float fStack_1f8;
  float fStack_1f4;
  float fStack_1f0;
  float fStack_1ec;
  float fStack_1e8;
  float fStack_1e4;
  float fStack_1e0;
  float fStack_1dc;
  int iStack_1d8;
  int iStack_1d4;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  float local_1a4;
  float local_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 auStack_194 [3];
  int iStack_188;
  int iStack_184;
  undefined1 auStack_180 [36];
  int iStack_15c;
  int iStack_158;
  undefined1 local_14c [28];
  float fStack_130;
  float afStack_12c [73];
  undefined1 auStack_8 [4];
  int *piStack_4;
  
  local_25c[0] = 0;
  local_1c8 = 0;
  local_1c4 = 0;
  local_1c0 = 0;
  local_1bc = 0;
  local_1b8 = 0;
  local_1b4 = 0;
  local_1b0 = 0;
  local_1ac = 0;
  local_1a8 = 0;
  local_1a4 = 0.0;
  local_1a0 = 0.0;
  local_25c[1] = 0;
  local_25c[2] = 0;
  local_25c[3] = 0;
  local_260 = 0.0;
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  (**(code **)(*param_1 + 0x28))(param_1,local_14c);
  (**(code **)(*param_2 + 0x28))(param_2,auStack_180);
  if (param_7 != (int *)0x0) {
    (**(code **)(*param_7 + 0x28))(param_7,&iStack_1d8);
  }
  iVar5 = param_10;
  piVar4 = param_7;
  if (piStack_4 == (int *)0x0) {
    local_25c[0] = 0;
    local_25c[1] = 0;
    local_25c[2] = iStack_15c;
    local_25c[3] = iStack_158;
    piStack_4 = local_25c;
  }
  piVar6 = param_2;
  if (param_2 == (int *)0x0) {
    piVar6 = (int *)(auStack_270 + -0x10);
  }
  if (param_10 == 0) {
    fVar1 = (float)iStack_188;
    if (iStack_188 < 0) {
      fVar1 = fVar1 + _DAT_007d4bd8;
    }
    fVar2 = (float)_DAT_00829868;
    fStack_238 = ((float)*piVar6 / fVar1) * fVar2 - 1.0;
    fStack_248 = fStack_238;
    fVar3 = (float)iStack_184;
    if (iStack_184 < 0) {
      fVar3 = fVar3 + _DAT_007d4bd8;
    }
    fStack_234 = -(((float)piVar6[1] / fVar3) * fVar2 - 1.0);
    fStack_244 = fStack_234;
    fStack_220 = ((float)piVar6[2] / fVar1) * fVar2 - 1.0;
    fStack_240 = fStack_220;
    fStack_204 = -(fVar2 * ((float)piVar6[3] / fVar3) - 1.0);
    fStack_23c = fStack_204;
    fStack_218 = (float)iStack_15c;
    if (iStack_15c < 0) {
      fStack_218 = fStack_218 + _DAT_007d4bd8;
    }
    fStack_230 = (float)*piStack_4 / fStack_218;
    fStack_1fc = (float)iStack_158;
    if (iStack_158 < 0) {
      fStack_1fc = fStack_1fc + _DAT_007d4bd8;
    }
    fStack_22c = (float)piStack_4[1] / fStack_1fc;
    fStack_218 = (float)piStack_4[2] / fStack_218;
    fStack_1fc = (float)piStack_4[3] / fStack_1fc;
    if (param_7 != (int *)0x0) {
      piVar6 = param_9;
      if (param_9 == (int *)0x0) {
        local_25c[0] = 0;
        local_25c[1] = 0;
        local_25c[2] = iStack_1d8;
        local_25c[3] = iStack_1d4;
        piVar6 = local_25c;
      }
      fVar1 = (float)iStack_1d8;
      if (iStack_1d8 < 0) {
        fVar1 = fVar1 + _DAT_007d4bd8;
      }
      fStack_26c = (float)*piVar6 / fVar1;
      local_260 = (float)iStack_1d4;
      if (iStack_1d4 < 0) {
        local_260 = local_260 + _DAT_007d4bd8;
      }
      fStack_268 = (float)piVar6[1] / local_260;
      fStack_264 = (float)piVar6[2] / fVar1;
      local_260 = (float)piVar6[3] / local_260;
    }
    fStack_21c = fStack_234;
    fStack_214 = fStack_22c;
    fStack_208 = fStack_238;
    fStack_200 = fStack_230;
    fStack_1f0 = fStack_220;
    fStack_1ec = fStack_204;
    fStack_1e8 = fStack_218;
    fStack_1e4 = fStack_1fc;
    if (param_7 == (int *)0x0) {
      fStack_228 = 0.0;
      fStack_224 = 0.0;
      fStack_210 = 0.0;
      fStack_20c = 0.0;
      fStack_1f8 = 0.0;
      fStack_1f4 = 0.0;
      fStack_1e0 = 0.0;
      fStack_1dc = 0.0;
    }
    else {
      fStack_228 = fStack_26c;
      fStack_224 = fStack_268;
      fStack_210 = fStack_264;
      fStack_20c = fStack_268;
      fStack_1f8 = fStack_26c;
      fStack_1f4 = local_260;
      fStack_1dc = local_260;
      fStack_1e0 = fStack_264;
    }
  }
  else {
    fVar1 = (float)iStack_188;
    if (iStack_188 < 0) {
      fVar1 = fVar1 + _DAT_007d4bd8;
    }
    fVar2 = (float)iStack_184;
    if (iStack_184 < 0) {
      fVar2 = fVar2 + _DAT_007d4bd8;
    }
    iVar9 = 4;
    pfVar7 = (float *)(param_10 + 0x14);
    pfVar8 = afStack_12c;
    do {
      iVar9 = iVar9 + -1;
      pfVar8[-1] = (pfVar7[-5] / fVar1) * (float)_DAT_00829868 - 1.0;
      *pfVar8 = -((pfVar7[-4] / fVar2) * (float)_DAT_00829868 - 1.0);
      pfVar8[1] = *pfVar7;
      pfVar8[2] = pfVar7[1];
      pfVar8[3] = pfVar7[2];
      pfVar8[4] = pfVar7[3];
      pfVar8[5] = pfVar7[4];
      pfVar8[6] = pfVar7[5];
      pfVar8[7] = pfVar7[6];
      pfVar8[8] = pfVar7[7];
      pfVar8[9] = pfVar7[8];
      pfVar8[10] = pfVar7[9];
      pfVar8[0xb] = pfVar7[10];
      pfVar8[0xc] = pfVar7[0xb];
      pfVar8[0xd] = pfVar7[0xc];
      pfVar8[0xe] = pfVar7[0xd];
      pfVar8[0xf] = pfVar7[0xe];
      pfVar8[0x10] = pfVar7[0xf];
      pfVar7 = pfVar7 + 0x15;
      pfVar8 = pfVar8 + 0x12;
    } while (iVar9 != 0);
  }
  FUN_005c31f0((-(uint)(param_10 != 0) & 0xc0) + 0x60);
  FUN_005d5220(DAT_00f07350,0,4,0,auStack_194,0);
  if (iVar5 == 0) {
    uVar11 = 0x60;
    pfVar7 = &fStack_238;
  }
  else {
    uVar11 = 0x120;
    pfVar7 = &fStack_130;
  }
  FUN_0056d420(auStack_194[0],pfVar7,uVar11);
  FUN_005d52a0(DAT_00f07350,0,0);
  FUN_005d2d10(1,&param_1,0);
  FUN_005d2b50(0,1,auStack_8);
  if (param_8 != 0) {
    FUN_005d2b50(1,1,&param_8);
  }
  local_1ac = 0;
  local_1a8 = 0;
  local_1a4 = (float)iStack_188;
  if (iStack_188 < 0) {
    local_1a4 = local_1a4 + _DAT_007d4bd8;
  }
  local_1a0 = (float)iStack_184;
  if (iStack_184 < 0) {
    local_1a0 = local_1a0 + _DAT_007d4bd8;
  }
  uStack_19c = 0;
  uStack_198 = 0x3f800000;
  FUN_005d2d90(1,&local_1ac);
  bVar10 = param_3 != 0;
  FUN_005d2b90(0,1,&DAT_00ef1fa8 + bVar10);
  if (piVar4 != (int *)0x0) {
    FUN_005d2b90(1,1,&DAT_00ef1fa8 + bVar10);
  }
  FUN_005d2d70(DAT_00ef1fb0);
  FUN_005d2d50(DAT_00ef1fb4,0);
  FUN_005d2d30((&DAT_00ef1fb8)[param_4 != 0],&DAT_00f328f8,0xffffffff);
  FUN_005d2cf0(5);
  uVar11 = DAT_00ef72ac;
  if (iVar5 == 0) {
    uVar11 = DAT_00ef72a8;
  }
  FUN_005d2c60(uVar11);
  iVar9 = param_6;
  if (param_6 == 0) {
    iVar9 = DAT_00ef1fc8;
  }
  FUN_005d2b70(iVar9,0,0);
  iVar9 = param_5;
  if ((param_5 == 0) && (iVar9 = DAT_00ef1fc4, iVar5 == 0)) {
    iVar9 = DAT_00ef1fc0;
  }
  FUN_005d2bb0(iVar9,0,0);
  local_25c[4] = (-(uint)(iVar5 != 0) & 0x30) + 0x18;
  FUN_005d2c80(0,1,&DAT_00f07350,local_25c + 4,auStack_270);
  FUN_005d2bf0(4,0);
  DAT_00a37de4 = DAT_00a37de4 + 1;
  FUN_005d2c80(0,1,&DAT_00f13704,&DAT_00f13708,auStack_270);
  FUN_005d2bb0(DAT_00f136f4,0,0);
  FUN_005d2b70(DAT_00f136ec,0,0);
  FUN_005d2c60(DAT_00f13700);
  FUN_005d2cf0(DAT_00f13674);
  FUN_005d2d30(DAT_00f133f0,&DAT_00f328f8,0xffffffff);
  FUN_005d2d50(DAT_00f13248,0);
  FUN_005d2d70(DAT_00f13108);
  FUN_005d2b90(0,1,&DAT_00f07a04);
  if (piVar4 != (int *)0x0) {
    FUN_005d2b90(1,1,&DAT_00f07a08);
  }
  FUN_005bb570();
  FUN_005d2d90(1,&DAT_00f130c4);
  FUN_005d2b50(0,1,&DAT_00f13454);
  if (param_8 != 0) {
    FUN_005d2b50(1,1,&DAT_00f13458);
  }
  return 0;
}

