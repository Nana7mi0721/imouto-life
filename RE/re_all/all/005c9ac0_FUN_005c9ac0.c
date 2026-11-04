
undefined4 FUN_005c9ac0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  float fVar8;
  int local_1c;
  int local_18;
  int local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar5 = param_2;
  iVar4 = param_1;
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (DAT_00ef7314 != 0) {
    if (DAT_00ef7324 == 0) {
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
    }
    DAT_00ef72e8 = 1;
    if (DAT_00ef7314 != 0) {
      DAT_00ef72e4 = 1;
    }
    DAT_00ef7314 = 0;
    DAT_00ef7318 = 0;
    DAT_00ef72cc = 1;
  }
  if (((DAT_00a3d360 != 0) || (DAT_00ef72cc != 0)) || (DAT_00ef72c8 != 0x20)) {
    FUN_005bcf50();
  }
  fVar1 = DAT_00a380b8;
  FUN_00544000(param_5,&local_14,&local_18,&local_1c);
  uVar6 = DAT_00f07344 >> 0x10 & 0xff;
  if (DAT_00a37dcc == 0) {
    uVar7 = (uVar6 * local_1c) / 0xff << 8 | ((DAT_00f07344 >> 8 & 0xff) * local_18) / 0xff;
    uVar6 = (DAT_00f07344 & 0xff) * local_14;
  }
  else {
    uVar7 = (uVar6 * local_14) / 0xff << 8 | ((DAT_00f07344 >> 8 & 0xff) * local_18) / 0xff;
    uVar6 = (DAT_00f07344 & 0xff) * local_1c;
  }
  fVar8 = (float)(uVar7 << 8 | uVar6 / 0xff | DAT_00f07344 & 0xff000000);
  if ((param_3 < param_1) || (param_4 < param_2)) {
    param_1 = param_3;
    param_2 = param_4;
    param_3 = iVar4;
    param_4 = iVar5;
  }
  local_10 = (float)param_1;
  local_c = (float)param_2;
  local_8 = (float)param_3;
  local_4 = (float)param_4;
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (((DAT_00f07338 != 0) || (DAT_00f07340 != 4)) ||
     (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <=
      DAT_00f07334 + 0x18)) {
    FUN_005c3310(0,0);
    DAT_00f07340 = 4;
  }
  pfVar3 = DAT_00f0732c;
  DAT_00f0732c[3] = 1.0;
  pfVar3[4] = fVar8;
  pfVar3[8] = 1.0;
  pfVar3[9] = fVar8;
  pfVar3[0xd] = 1.0;
  pfVar3[0xe] = fVar8;
  pfVar3[0x12] = 1.0;
  pfVar3[0x13] = fVar8;
  pfVar3[0x17] = 1.0;
  pfVar3[0x18] = fVar8;
  pfVar3[0x1c] = 1.0;
  pfVar3[0x1d] = fVar8;
  pfVar3[0x21] = 1.0;
  pfVar3[0x22] = fVar8;
  pfVar3[0x26] = 1.0;
  pfVar3[0x27] = fVar8;
  pfVar3[0x2b] = 1.0;
  pfVar3[0x2c] = fVar8;
  pfVar3[0x30] = 1.0;
  pfVar3[0x31] = fVar8;
  pfVar3[0x35] = 1.0;
  pfVar3[0x36] = fVar8;
  pfVar3[0x3a] = 1.0;
  pfVar3[0x3b] = fVar8;
  pfVar3[0x3f] = 1.0;
  pfVar3[0x40] = fVar8;
  pfVar3[0x44] = 1.0;
  pfVar3[0x45] = fVar8;
  pfVar3[0x49] = 1.0;
  pfVar3[0x4a] = fVar8;
  pfVar3[0x4e] = 1.0;
  pfVar3[0x4f] = fVar8;
  pfVar3[0x53] = 1.0;
  pfVar3[0x54] = fVar8;
  pfVar3[0x58] = 1.0;
  pfVar3[0x59] = fVar8;
  pfVar3[0x5d] = 1.0;
  pfVar3[0x5e] = fVar8;
  pfVar3[0x62] = 1.0;
  pfVar3[99] = fVar8;
  pfVar3[0x67] = 1.0;
  pfVar3[0x68] = fVar8;
  pfVar3[0x6c] = 1.0;
  pfVar3[0x6d] = fVar8;
  pfVar3[0x71] = 1.0;
  pfVar3[0x72] = fVar8;
  pfVar3[0x76] = 1.0;
  pfVar3[0x77] = fVar8;
  pfVar3[2] = fVar1;
  *pfVar3 = local_10;
  pfVar3[7] = fVar1;
  pfVar3[0xc] = fVar1;
  pfVar3[1] = local_c;
  pfVar3[0x11] = fVar1;
  pfVar3[0x16] = fVar1;
  pfVar3[5] = local_8;
  pfVar3[0x1b] = fVar1;
  pfVar3[0x20] = fVar1;
  pfVar3[0x25] = fVar1;
  pfVar3[0x2a] = fVar1;
  pfVar3[0x2f] = fVar1;
  pfVar3[0x34] = fVar1;
  pfVar3[0x39] = fVar1;
  pfVar3[0x3e] = fVar1;
  pfVar3[0x43] = fVar1;
  pfVar3[0x48] = fVar1;
  pfVar3[0x4d] = fVar1;
  pfVar3[0x52] = fVar1;
  pfVar3[0x57] = fVar1;
  pfVar3[0x5c] = fVar1;
  pfVar3[0x61] = fVar1;
  pfVar3[0x66] = fVar1;
  pfVar3[0x6b] = fVar1;
  pfVar3[0x70] = fVar1;
  pfVar3[0x75] = fVar1;
  pfVar3[6] = local_c;
  pfVar3[10] = local_10;
  fVar8 = local_c + 1.0;
  pfVar3[0xb] = fVar8;
  pfVar3[0x10] = fVar8;
  pfVar3[0x15] = fVar8;
  pfVar3[0xf] = local_8;
  pfVar3[0x19] = local_8;
  pfVar3[0x14] = local_10;
  pfVar3[0x1a] = local_c;
  fVar2 = local_8 - 1.0;
  pfVar3[0x1e] = fVar2;
  pfVar3[0x28] = fVar2;
  pfVar3[0x1f] = fVar8;
  pfVar3[0x24] = fVar8;
  pfVar3[0x23] = local_8;
  pfVar3[0x29] = local_4;
  pfVar3[0x2e] = local_4;
  pfVar3[0x33] = local_4;
  pfVar3[0x2d] = local_8;
  pfVar3[0x37] = local_8;
  pfVar3[0x32] = fVar2;
  pfVar3[0x38] = fVar8;
  pfVar3[0x3c] = local_10;
  pfVar3[0x3d] = fVar8;
  fVar1 = local_10 + 1.0;
  pfVar3[0x41] = fVar1;
  pfVar3[0x4b] = fVar1;
  pfVar3[0x55] = fVar1;
  pfVar3[0x42] = fVar8;
  pfVar3[0x56] = fVar8;
  pfVar3[0x46] = local_10;
  pfVar3[0x50] = local_10;
  pfVar3[0x47] = local_4;
  pfVar3[0x4c] = local_4;
  pfVar3[0x51] = local_4;
  pfVar3[0x5a] = fVar1;
  fVar8 = local_4 - 1.0;
  pfVar3[0x5b] = fVar8;
  pfVar3[0x60] = fVar8;
  pfVar3[0x74] = fVar8;
  pfVar3[0x5f] = fVar2;
  pfVar3[0x69] = fVar2;
  pfVar3[0x73] = fVar2;
  pfVar3[100] = fVar1;
  pfVar3[0x6e] = fVar1;
  pfVar3[0x65] = local_4;
  pfVar3[0x6a] = local_4;
  pfVar3[0x6f] = local_4;
  DAT_00f0732c = DAT_00f0732c + 0x78;
  DAT_00f07334 = DAT_00f07334 + 0x18;
  return 0;
}

