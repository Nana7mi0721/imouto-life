
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005c9f80(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  uint uVar6;
  uint uVar7;
  float fVar8;
  uint uVar9;
  int local_10;
  int local_c;
  int local_8 [2];
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if ((param_3 != param_1) || (param_4 != param_2)) {
    if (DAT_00ef7314 != 0) {
      if ((DAT_00ef7324 == 0) && (FUN_00568ca0(0), DAT_00dda46c != 0)) {
        FUN_00584d70();
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
    fVar4 = DAT_00a380b8;
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    if (((DAT_00f07338 == 1) || (DAT_00f07340 != 2)) ||
       (*(int *)(&DAT_007fcd58 + *(int *)(&DAT_007fcd90 + (DAT_00f0733c + DAT_00f07338 * 3) * 4) * 4
                ) <= DAT_00f07334 + 2)) {
      FUN_005c3310(0,0);
      DAT_00f07340 = 2;
    }
    pfVar5 = DAT_00f0732c;
    FUN_00544000(param_5,local_8,&local_c,&local_10);
    uVar6 = DAT_00f07344;
    if (DAT_00a37dcc == 0) {
      uVar7 = ((DAT_00f07344 >> 0x10 & 0xff) * local_10) / 0xff << 8 |
              ((DAT_00f07344 >> 8 & 0xff) * local_c) / 0xff;
      uVar9 = (DAT_00f07344 & 0xff) * local_8[0];
    }
    else {
      uVar7 = ((DAT_00f07344 >> 0x10 & 0xff) * local_8[0]) / 0xff << 8 |
              ((DAT_00f07344 >> 8 & 0xff) * local_c) / 0xff;
      uVar9 = (DAT_00f07344 & 0xff) * local_10;
    }
    pfVar5[3] = 1.0;
    pfVar5[8] = 1.0;
    fVar2 = (float)_DAT_00804a60;
    fVar1 = (float)param_1 + fVar2;
    *pfVar5 = fVar1;
    fVar8 = (float)(uVar7 << 8 | uVar9 / 0xff | uVar6 & 0xff000000);
    fVar3 = (float)param_2 + fVar2;
    pfVar5[4] = fVar8;
    pfVar5[9] = fVar8;
    pfVar5[2] = fVar4;
    pfVar5[1] = fVar3;
    pfVar5[7] = fVar4;
    fVar4 = (float)param_3 + fVar2;
    pfVar5[5] = fVar4;
    fVar2 = (float)param_4 + fVar2;
    pfVar5[6] = fVar2;
    fVar8 = (float)_DAT_00829898;
    if (param_1 == param_3) {
      if (param_2 < param_4) {
        pfVar5[1] = fVar3 - fVar8;
        pfVar5[6] = fVar2 - fVar8;
      }
      else {
        pfVar5[1] = fVar3 + fVar8;
        pfVar5[6] = fVar2 + fVar8;
      }
    }
    if (param_2 == param_4) {
      if (param_1 < param_3) {
        *pfVar5 = fVar1 - fVar8;
        pfVar5[5] = fVar4 - fVar8;
      }
      else {
        *pfVar5 = fVar1 + fVar8;
        pfVar5[5] = fVar8 + fVar4;
      }
    }
    DAT_00f0732c = DAT_00f0732c + 10;
    DAT_00f07334 = DAT_00f07334 + 2;
  }
  return 0;
}

