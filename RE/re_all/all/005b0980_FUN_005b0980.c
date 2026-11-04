
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b0980(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  float fVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  float fVar10;
  uint uVar11;
  float local_10;
  int local_c;
  int local_8 [2];
  
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if ((param_3 != param_1) || (param_4 != param_2)) {
    if ((DAT_00e79688 == 0) && ((iVar8 = FUN_005d35f0(), iVar8 != 0 && (DAT_00e79688 != 1)))) {
      FUN_005d3930();
      DAT_00e79688 = 1;
      DAT_00e399fc = 0;
    }
    if ((DAT_00e39a4c != 0) && (FUN_0059bcf0(0), DAT_00e39a4c != 0)) {
      FUN_0059bcf0(0);
    }
    if (((DAT_00a3d360 != 0) || (DAT_00e39a00 != 0)) || (DAT_00e399fc != 0x20)) {
      FUN_005a7f60();
    }
    fVar5 = DAT_00a380b8;
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    if (((DAT_00e79674 == 1) || (DAT_00e79680 != 2)) ||
       (*(int *)(&DAT_007da368 + (DAT_00e7967c + DAT_00e79674 * 3) * 4) <= (int)(DAT_00e79678 + 2)))
    {
      if (DAT_00e79678 != 0) {
        FUN_005a7ce0();
        if (DAT_00e79680 == 4) {
          uVar9 = (int)DAT_00e79678 / 3;
        }
        else if (DAT_00e79680 == 2) {
          uVar9 = (int)DAT_00e79678 / 2;
        }
        else if (DAT_00e79680 == 6) {
          uVar9 = DAT_00e79678 - 2;
        }
        else if (DAT_00e79680 == 5) {
          uVar9 = DAT_00e79678 - 2;
        }
        else if (DAT_00e79680 == 3) {
          uVar9 = DAT_00e79678 - 1;
        }
        else {
          uVar9 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
        }
        iVar8 = DAT_00e7967c + DAT_00e79674 * 3;
        FUN_005d3b40(DAT_00e79680,uVar9,*(undefined4 *)(&DAT_00e39a5c + iVar8 * 4),
                     *(undefined4 *)(&DAT_007da3e8 + iVar8 * 4));
        DAT_00a37de4 = DAT_00a37de4 + 1;
      }
      DAT_00e79678 = 0;
      DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
      DAT_00e79674 = 0;
      DAT_00e79680 = 2;
    }
    pfVar6 = DAT_00e39a58;
    FUN_00544000(param_5,&local_10,&local_c,local_8);
    uVar7 = DAT_00e79684;
    uVar2 = DAT_00e79684 >> 0x10;
    uVar9 = DAT_00e79684 >> 8;
    uVar11 = DAT_00e79684 & 0xff;
    *pfVar6 = (float)param_1;
    pfVar6[1] = (float)param_2;
    fVar1 = (float)param_3;
    pfVar6[5] = fVar1;
    pfVar6[6] = (float)param_4;
    fVar4 = _DAT_007d9b98;
    fVar3 = _DAT_007d5504;
    fVar10 = (float)((((uVar2 & 0xff) * (int)local_10) / 0xff << 8 |
                     ((uVar9 & 0xff) * local_c) / 0xff) << 8 | (uVar11 * local_8[0]) / 0xff |
                    uVar7 & 0xff000000);
    pfVar6[4] = fVar10;
    pfVar6[9] = fVar10;
    pfVar6[2] = fVar5;
    pfVar6[7] = fVar5;
    if (param_1 == param_3) {
      if (param_2 < param_4) {
        local_10 = fVar4;
      }
      else {
        local_10 = fVar3;
      }
      pfVar6[6] = local_10 + (float)param_4;
    }
    if (param_2 == param_4) {
      if (param_1 < param_3) {
        pfVar6[5] = fVar1 + fVar4;
      }
      else {
        pfVar6[5] = fVar1 + fVar3;
      }
    }
    DAT_00e39a58 = DAT_00e39a58 + 10;
    DAT_00e79678 = DAT_00e79678 + 2;
  }
  return 0;
}

