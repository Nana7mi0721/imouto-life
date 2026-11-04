
undefined4 FUN_005b01e0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  uint uVar5;
  float fVar6;
  int local_20;
  int local_1c;
  int local_18 [2];
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (DAT_00f3a04c == 0) {
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
    FUN_0059d430();
    if (DAT_00e39a4c != 0) {
      FUN_0059bcf0(0);
    }
    if (((DAT_00a3d360 != 0) || (DAT_00e39a00 != 0)) || (DAT_00e399fc != 0x20)) {
      FUN_005a7f60();
    }
    FUN_00544000(param_5,&local_20,&local_1c,local_18);
    fVar3 = DAT_00a380b8;
    fVar6 = (float)((((DAT_00e79684 >> 0x10 & 0xff) * local_20) / 0xff << 8 |
                    ((DAT_00e79684 >> 8 & 0xff) * local_1c) / 0xff) << 8 |
                    ((DAT_00e79684 & 0xff) * local_18[0]) / 0xff | DAT_00e79684 & 0xff000000);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
       (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
      if (DAT_00e79678 != 0) {
        FUN_005a7ce0();
        if (DAT_00e79680 == 4) {
          uVar5 = (int)DAT_00e79678 / 3;
        }
        else if (DAT_00e79680 == 2) {
          uVar5 = (int)DAT_00e79678 / 2;
        }
        else if ((DAT_00e79680 == 6) || (DAT_00e79680 == 5)) {
          uVar5 = DAT_00e79678 - 2;
        }
        else if (DAT_00e79680 == 3) {
          uVar5 = DAT_00e79678 - 1;
        }
        else {
          uVar5 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
        }
        iVar1 = DAT_00e7967c + DAT_00e79674 * 3;
        FUN_005d3b40(DAT_00e79680,uVar5,*(undefined4 *)(&DAT_00e39a5c + iVar1 * 4),
                     *(undefined4 *)(&DAT_007da3e8 + iVar1 * 4));
        DAT_00a37de4 = DAT_00a37de4 + 1;
      }
      DAT_00e79678 = 0;
      DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
      DAT_00e79674 = 0;
      DAT_00e79680 = 4;
    }
    pfVar4 = DAT_00e39a58;
    fVar2 = (float)local_10;
    DAT_00e39a58[0x13] = fVar6;
    pfVar4[4] = fVar6;
    pfVar4[2] = fVar3;
    pfVar4[7] = fVar3;
    *pfVar4 = fVar2;
    pfVar4[0xc] = fVar3;
    pfVar4[10] = fVar2;
    pfVar4[0x11] = fVar3;
    pfVar4[0x14] = fVar2;
    pfVar4[0x16] = fVar3;
    fVar6 = (float)local_8;
    pfVar4[0x1b] = fVar3;
    pfVar4[5] = fVar6;
    pfVar4[0xf] = fVar6;
    pfVar4[0x19] = fVar6;
    fVar3 = (float)local_c;
    pfVar4[1] = fVar3;
    pfVar4[6] = fVar3;
    pfVar4[0x1a] = fVar3;
    fVar3 = (float)local_4;
    pfVar4[0xb] = fVar3;
    pfVar4[0x10] = fVar3;
    pfVar4[0x15] = fVar3;
    DAT_00e39a58 = DAT_00e39a58 + 0x1e;
    DAT_00e79678 = DAT_00e79678 + 6;
  }
  return 0;
}

