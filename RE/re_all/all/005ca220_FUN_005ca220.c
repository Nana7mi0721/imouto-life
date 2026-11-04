
undefined4
FUN_005ca220(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            undefined4 param_7,int param_8)

{
  float fVar1;
  float *pfVar2;
  uint uVar3;
  uint uVar4;
  float fVar5;
  int local_10;
  int local_c;
  int local_8 [2];
  
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
  FUN_00544000(param_7,local_8,&local_c,&local_10);
  uVar3 = DAT_00f07344 >> 0x10 & 0xff;
  if (DAT_00a37dcc == 0) {
    uVar4 = (uVar3 * local_10) / 0xff << 8 | ((DAT_00f07344 >> 8 & 0xff) * local_c) / 0xff;
    uVar3 = (DAT_00f07344 & 0xff) * local_8[0];
  }
  else {
    uVar4 = (uVar3 * local_8[0]) / 0xff << 8 | ((DAT_00f07344 >> 8 & 0xff) * local_c) / 0xff;
    uVar3 = (DAT_00f07344 & 0xff) * local_10;
  }
  fVar5 = (float)(uVar4 << 8 | uVar3 / 0xff | DAT_00f07344 & 0xff000000);
  if (param_8 == 0) {
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    if (((DAT_00f07338 != 0) || (DAT_00f07340 != 2)) ||
       (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <= DAT_00f07334 + 6
       )) {
      FUN_005c3310(0,0);
      DAT_00f07340 = 2;
    }
    pfVar2 = DAT_00f0732c;
    DAT_00f0732c[2] = fVar1;
    pfVar2[7] = fVar1;
    pfVar2[0xc] = fVar1;
    pfVar2[0x11] = fVar1;
    *pfVar2 = (float)param_1;
    pfVar2[0x16] = fVar1;
    pfVar2[0x1b] = fVar1;
    pfVar2[4] = fVar5;
    pfVar2[9] = fVar5;
    pfVar2[0xe] = fVar5;
    pfVar2[0x13] = fVar5;
    pfVar2[1] = (float)param_2;
    pfVar2[0x18] = fVar5;
    pfVar2[0x1d] = fVar5;
    pfVar2[5] = (float)param_3;
    pfVar2[6] = (float)param_4;
    pfVar2[0xb] = (float)param_4;
    pfVar2[10] = (float)param_3;
    pfVar2[0xf] = (float)param_5;
    pfVar2[0x10] = (float)param_6;
    pfVar2[0x15] = (float)param_6;
    pfVar2[0x14] = (float)param_5;
    pfVar2[0x19] = (float)param_1;
    pfVar2[0x1a] = (float)param_2;
    pfVar2[3] = 1.0;
    pfVar2[8] = 1.0;
    pfVar2[0xd] = 1.0;
    pfVar2[0x12] = 1.0;
    pfVar2[0x17] = 1.0;
    pfVar2[0x1c] = 1.0;
    DAT_00f0732c = DAT_00f0732c + 0x1e;
    DAT_00f07334 = DAT_00f07334 + 6;
    return 0;
  }
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (((DAT_00f07338 != 0) || (DAT_00f07340 != 4)) ||
     (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + DAT_00f0733c * 4) * 4) <= DAT_00f07334 + 3))
  {
    FUN_005c3310(0,0);
    DAT_00f07340 = 4;
  }
  pfVar2 = DAT_00f0732c;
  DAT_00f0732c[4] = fVar5;
  pfVar2[9] = fVar5;
  *pfVar2 = (float)param_1;
  pfVar2[0xe] = fVar5;
  pfVar2[1] = (float)param_2;
  if (DAT_00a37fdc == 0) {
LAB_005ca46b:
    pfVar2[5] = (float)param_3;
    pfVar2[6] = (float)param_4;
    pfVar2[10] = (float)param_5;
    param_4 = param_6;
  }
  else {
    if (DAT_00a37fdc == 1) {
      if (0 < (param_3 - param_1) * (param_6 - param_2) - (param_5 - param_1) * (param_4 - param_2))
      goto LAB_005ca46b;
    }
    else {
      if (DAT_00a37fdc != 2) goto LAB_005ca487;
      if ((param_3 - param_1) * (param_6 - param_2) - (param_5 - param_1) * (param_4 - param_2) < 0)
      goto LAB_005ca46b;
    }
    pfVar2[5] = (float)param_5;
    pfVar2[6] = (float)param_6;
    pfVar2[10] = (float)param_3;
  }
  pfVar2[0xb] = (float)param_4;
LAB_005ca487:
  pfVar2[2] = fVar1;
  pfVar2[3] = 1.0;
  pfVar2[7] = fVar1;
  pfVar2[0xc] = fVar1;
  pfVar2[8] = 1.0;
  pfVar2[0xd] = 1.0;
  DAT_00f0732c = DAT_00f0732c + 0xf;
  DAT_00f07334 = DAT_00f07334 + 3;
  return 0;
}

