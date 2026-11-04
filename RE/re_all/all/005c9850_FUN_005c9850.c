
undefined4 FUN_005c9850(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  uint uVar5;
  uint uVar6;
  float fVar7;
  int local_20;
  int local_1c;
  int local_18 [2];
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  local_10 = param_1;
  if (param_3 < param_1) {
    local_10 = param_3;
    param_3 = param_1;
  }
  local_c = param_2;
  if (param_4 < param_2) {
    local_c = param_4;
    param_4 = param_2;
  }
  local_8 = param_3;
  local_4 = param_4;
  FUN_00514e10(&local_10,&DAT_00a38194);
  if ((local_10 != local_8) && (local_c != local_4)) {
    if (DAT_00ef7314 != 0) {
      FUN_005bc5b0(0,0);
    }
    if (((DAT_00a3d360 != 0) || (DAT_00ef72cc != 0)) || (DAT_00ef72c8 != 0x20)) {
      FUN_005bcf50();
    }
    FUN_00544000(param_5,local_18,&local_1c,&local_20);
    fVar3 = DAT_00a380b8;
    uVar5 = DAT_00f07344 >> 0x10 & 0xff;
    if (DAT_00a37dcc == 0) {
      uVar6 = (uVar5 * local_20) / 0xff << 8 | ((DAT_00f07344 >> 8 & 0xff) * local_1c) / 0xff;
      uVar5 = (DAT_00f07344 & 0xff) * local_18[0];
    }
    else {
      uVar6 = (uVar5 * local_18[0]) / 0xff << 8 | ((DAT_00f07344 >> 8 & 0xff) * local_1c) / 0xff;
      uVar5 = (DAT_00f07344 & 0xff) * local_20;
    }
    fVar7 = (float)(uVar6 << 8 | uVar5 / 0xff | DAT_00f07344 & 0xff000000);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    if (((DAT_00f07338 != 0) || (DAT_00f07340 != 4)) ||
       (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <= DAT_00f07334 + 6
       )) {
      FUN_005c3310(0,0);
      DAT_00f07340 = 4;
    }
    pfVar4 = DAT_00f0732c;
    fVar1 = (float)local_10;
    DAT_00f0732c[4] = fVar7;
    pfVar4[9] = fVar7;
    pfVar4[0xe] = fVar7;
    pfVar4[0x13] = fVar7;
    *pfVar4 = fVar1;
    pfVar4[0x18] = fVar7;
    fVar2 = (float)local_c;
    pfVar4[0x1d] = fVar7;
    pfVar4[2] = fVar3;
    pfVar4[7] = fVar3;
    pfVar4[0xc] = fVar3;
    pfVar4[0x11] = fVar3;
    pfVar4[1] = fVar2;
    pfVar4[0x16] = fVar3;
    fVar7 = (float)local_8;
    pfVar4[0x1b] = fVar3;
    pfVar4[5] = fVar7;
    pfVar4[6] = fVar2;
    pfVar4[10] = fVar1;
    fVar3 = (float)local_4;
    pfVar4[0xb] = fVar3;
    pfVar4[0x10] = fVar3;
    pfVar4[0x15] = fVar3;
    pfVar4[0xf] = fVar7;
    pfVar4[0x19] = fVar7;
    pfVar4[0x14] = fVar1;
    pfVar4[0x1a] = fVar2;
    pfVar4[3] = 1.0;
    pfVar4[8] = 1.0;
    pfVar4[0xd] = 1.0;
    pfVar4[0x12] = 1.0;
    pfVar4[0x17] = 1.0;
    pfVar4[0x1c] = 1.0;
    DAT_00f0732c = DAT_00f0732c + 0x1e;
    DAT_00f07334 = DAT_00f07334 + 6;
  }
  return 0;
}

