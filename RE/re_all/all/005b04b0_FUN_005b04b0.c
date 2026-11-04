
undefined4 FUN_005b04b0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  float fVar9;
  int local_1c;
  int local_18;
  int local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar6 = param_2;
  iVar1 = param_1;
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if (((DAT_00e79688 == 0) && (iVar7 = FUN_005d35f0(), iVar7 != 0)) && (DAT_00e79688 != 1)) {
    FUN_005d3930();
    DAT_00e79688 = 1;
    DAT_00e399fc = 0;
  }
  if ((DAT_00e39a4c != 0) && (DAT_00f3a04c != 0)) {
    if ((DAT_00e39a54 == 0) && (FUN_00568ca0(0), DAT_00dda46c != 0)) {
      FUN_00584d70();
    }
    DAT_00e39a1c = 1;
    if (DAT_00e39a4c != 0) {
      DAT_00e39a18 = 1;
    }
    DAT_00e39a00 = 1;
    DAT_00e39a4c = 0;
  }
  if (((DAT_00a3d360 != 0) || (DAT_00e39a00 != 0)) || (DAT_00e399fc != 0x20)) {
    FUN_005a7f60();
  }
  fVar2 = DAT_00a380b8;
  FUN_00544000(param_5,&local_1c,&local_18,&local_14);
  fVar9 = (float)((((DAT_00e79684 >> 0x10 & 0xff) * local_1c) / 0xff << 8 |
                  ((DAT_00e79684 >> 8 & 0xff) * local_18) / 0xff) << 8 |
                  ((DAT_00e79684 & 0xff) * local_14) / 0xff | DAT_00e79684 & 0xff000000);
  if ((param_3 < param_1) || (param_4 < param_2)) {
    param_1 = param_3;
    param_2 = param_4;
    param_3 = iVar1;
    param_4 = iVar6;
  }
  local_10 = (float)param_1;
  local_c = (float)param_2;
  local_8 = (float)param_3;
  local_4 = (float)param_4;
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (((DAT_00e79674 != 0) || (DAT_00e79680 != 4)) ||
     (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 0x18))) {
    if (DAT_00e79678 != 0) {
      FUN_005a7ce0();
      if (DAT_00e79680 == 4) {
        uVar8 = (int)DAT_00e79678 / 3;
      }
      else if (DAT_00e79680 == 2) {
        uVar8 = (int)DAT_00e79678 / 2;
      }
      else if ((DAT_00e79680 == 6) || (DAT_00e79680 == 5)) {
        uVar8 = DAT_00e79678 - 2;
      }
      else if (DAT_00e79680 == 3) {
        uVar8 = DAT_00e79678 - 1;
      }
      else {
        uVar8 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
      }
      iVar1 = DAT_00e7967c + DAT_00e79674 * 3;
      FUN_005d3b40(DAT_00e79680,uVar8,*(undefined4 *)(&DAT_00e39a5c + iVar1 * 4),
                   *(undefined4 *)(&DAT_007da3e8 + iVar1 * 4));
      DAT_00a37de4 = DAT_00a37de4 + 1;
    }
    DAT_00e79678 = 0;
    DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
    DAT_00e79674 = 0;
    DAT_00e79680 = 4;
  }
  pfVar5 = DAT_00e39a58;
  *DAT_00e39a58 = local_10;
  pfVar5[4] = fVar9;
  pfVar5[9] = fVar9;
  pfVar5[1] = local_c;
  pfVar5[0xe] = fVar9;
  pfVar5[0x13] = fVar9;
  pfVar5[5] = local_8;
  pfVar5[0x18] = fVar9;
  pfVar5[0x1d] = fVar9;
  pfVar5[6] = local_c;
  pfVar5[0x22] = fVar9;
  pfVar5[0x27] = fVar9;
  pfVar5[10] = local_10;
  pfVar5[0x2c] = fVar9;
  pfVar5[0x31] = fVar9;
  pfVar5[0x36] = fVar9;
  fVar4 = local_c + 1.0;
  pfVar5[0x3b] = fVar9;
  pfVar5[0x40] = fVar9;
  pfVar5[0x45] = fVar9;
  pfVar5[0x4a] = fVar9;
  pfVar5[0x4f] = fVar9;
  pfVar5[0x54] = fVar9;
  pfVar5[0xb] = fVar4;
  pfVar5[0x59] = fVar9;
  pfVar5[0x10] = fVar4;
  pfVar5[0x5e] = fVar9;
  pfVar5[0x15] = fVar4;
  pfVar5[99] = fVar9;
  pfVar5[0x68] = fVar9;
  pfVar5[0xf] = local_8;
  pfVar5[0x6d] = fVar9;
  pfVar5[0x19] = local_8;
  pfVar5[0x72] = fVar9;
  pfVar5[0x77] = fVar9;
  pfVar5[0x14] = local_10;
  pfVar5[2] = fVar2;
  pfVar5[7] = fVar2;
  pfVar5[0x1a] = local_c;
  pfVar5[0xc] = fVar2;
  pfVar5[0x11] = fVar2;
  fVar3 = local_8 - 1.0;
  pfVar5[0x16] = fVar2;
  pfVar5[0x1b] = fVar2;
  pfVar5[0x20] = fVar2;
  pfVar5[0x25] = fVar2;
  pfVar5[0x2a] = fVar2;
  pfVar5[0x2f] = fVar2;
  pfVar5[0x34] = fVar2;
  pfVar5[0x39] = fVar2;
  pfVar5[0x3e] = fVar2;
  pfVar5[0x43] = fVar2;
  pfVar5[0x48] = fVar2;
  pfVar5[0x4d] = fVar2;
  pfVar5[0x52] = fVar2;
  pfVar5[0x57] = fVar2;
  pfVar5[0x5c] = fVar2;
  pfVar5[0x61] = fVar2;
  pfVar5[0x66] = fVar2;
  pfVar5[0x6b] = fVar2;
  pfVar5[0x70] = fVar2;
  pfVar5[0x75] = fVar2;
  pfVar5[0x1e] = fVar3;
  pfVar5[0x28] = fVar3;
  pfVar5[0x1f] = fVar4;
  pfVar5[0x24] = fVar4;
  pfVar5[0x23] = local_8;
  pfVar5[0x29] = local_4;
  pfVar5[0x2e] = local_4;
  pfVar5[0x33] = local_4;
  pfVar5[0x2d] = local_8;
  pfVar5[0x37] = local_8;
  pfVar5[0x32] = fVar3;
  pfVar5[0x38] = fVar4;
  pfVar5[0x3c] = local_10;
  pfVar5[0x3d] = fVar4;
  fVar2 = local_10 + 1.0;
  pfVar5[0x41] = fVar2;
  pfVar5[0x4b] = fVar2;
  pfVar5[0x55] = fVar2;
  pfVar5[0x42] = fVar4;
  pfVar5[0x56] = fVar4;
  pfVar5[0x46] = local_10;
  pfVar5[0x50] = local_10;
  pfVar5[0x47] = local_4;
  pfVar5[0x4c] = local_4;
  pfVar5[0x51] = local_4;
  pfVar5[0x5a] = fVar2;
  fVar9 = local_4 - 1.0;
  pfVar5[0x5b] = fVar9;
  pfVar5[0x60] = fVar9;
  pfVar5[0x74] = fVar9;
  pfVar5[0x5f] = fVar3;
  pfVar5[0x69] = fVar3;
  pfVar5[0x73] = fVar3;
  pfVar5[100] = fVar2;
  pfVar5[0x6e] = fVar2;
  pfVar5[0x65] = local_4;
  pfVar5[0x6a] = local_4;
  pfVar5[0x6f] = local_4;
  DAT_00e39a58 = DAT_00e39a58 + 0x78;
  DAT_00e79678 = DAT_00e79678 + 0x18;
  return 0;
}

