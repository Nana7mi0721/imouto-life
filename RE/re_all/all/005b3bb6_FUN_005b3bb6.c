
undefined4
FUN_005b3bb6(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,int param_6,
            int param_7,int param_8,int param_9,int param_10,int param_11,undefined4 param_12,
            uint param_13)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  uint uVar4;
  float fVar5;
  uint unaff_EDI;
  
  iVar3 = FUN_005d35f0();
  if ((iVar3 != 0) && (DAT_00e79688 != 1)) {
    FUN_005d3930();
    DAT_00e79688 = 1;
    DAT_00e399fc = unaff_EDI;
  }
  if (DAT_00f3a04c == unaff_EDI) {
    if ((DAT_00e39a4c != unaff_EDI) && (DAT_00f3a04c != unaff_EDI)) goto LAB_005b3c07;
  }
  else {
    if (DAT_00e39a4c == unaff_EDI) {
      if (DAT_00e39a54 == unaff_EDI) goto LAB_005b3c45;
    }
    else {
LAB_005b3c07:
      if ((DAT_00e39a54 == unaff_EDI) && (FUN_00568ca0(), DAT_00dda46c != unaff_EDI)) {
        FUN_00584d70();
      }
    }
    DAT_00e39a1c = 1;
    if (DAT_00e39a4c != unaff_EDI) {
      DAT_00e39a18 = 1;
    }
    DAT_00e39a00 = 1;
    DAT_00e39a4c = unaff_EDI;
  }
LAB_005b3c45:
  if (((DAT_00a3d360 != unaff_EDI) || (DAT_00e39a00 != unaff_EDI)) || (DAT_00e399fc != 0x20)) {
    FUN_005a7f60();
  }
  fVar1 = DAT_00a380b8;
  FUN_00544000(param_12,&param_1,&param_2,&param_3);
  fVar5 = (float)((((DAT_00e79684 >> 0x10 & 0xff) * param_1) / 0xff << 8 |
                  ((DAT_00e79684 >> 8 & 0xff) * param_2) / 0xff) << 8 |
                  ((DAT_00e79684 & 0xff) * param_3) / 0xff | DAT_00e79684 & 0xff000000);
  if (param_13 == unaff_EDI) {
    if (DAT_00dda46c != unaff_EDI) {
      FUN_00584d70();
    }
    if (((DAT_00e79674 != unaff_EDI) || (DAT_00e79680 != 2)) ||
       (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 6))) {
      if (DAT_00e79678 != unaff_EDI) {
        FUN_005a7ce0();
        if (DAT_00e79680 == 4) {
          uVar4 = (int)DAT_00e79678 / 3;
        }
        else if (DAT_00e79680 == 2) {
          uVar4 = (int)DAT_00e79678 / 2;
        }
        else if ((DAT_00e79680 == 6) || (DAT_00e79680 == 5)) {
          uVar4 = DAT_00e79678 - 2;
        }
        else if (DAT_00e79680 == 3) {
          uVar4 = DAT_00e79678 - 1;
        }
        else {
          uVar4 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
        }
        iVar3 = DAT_00e7967c + DAT_00e79674 * 3;
        FUN_005d3b40(DAT_00e79680,uVar4,*(undefined4 *)(&DAT_00e39a5c + iVar3 * 4),
                     *(undefined4 *)(&DAT_007da3e8 + iVar3 * 4));
        DAT_00a37de4 = DAT_00a37de4 + 1;
        unaff_EDI = 0;
      }
      DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
      DAT_00e79680 = 2;
      DAT_00e79674 = unaff_EDI;
      DAT_00e79678 = unaff_EDI;
    }
    pfVar2 = DAT_00e39a58;
    DAT_00e39a58[0x1d] = fVar5;
    pfVar2[0x18] = fVar5;
    pfVar2[0x13] = fVar5;
    pfVar2[0xe] = fVar5;
    *pfVar2 = (float)param_6;
    pfVar2[9] = fVar5;
    pfVar2[4] = fVar5;
    pfVar2[2] = fVar1;
    pfVar2[7] = fVar1;
    pfVar2[0xc] = fVar1;
    pfVar2[1] = (float)param_7;
    pfVar2[0x11] = fVar1;
    pfVar2[0x16] = fVar1;
    pfVar2[0x1b] = fVar1;
    pfVar2[5] = (float)param_8;
    pfVar2[6] = (float)param_9;
    pfVar2[0xb] = (float)param_9;
    pfVar2[10] = (float)param_8;
    pfVar2[0xf] = (float)param_10;
    pfVar2[0x10] = (float)param_11;
    pfVar2[0x15] = (float)param_11;
    pfVar2[0x14] = (float)param_10;
    pfVar2[0x19] = (float)param_6;
    pfVar2[0x1a] = (float)param_7;
    DAT_00e39a58 = DAT_00e39a58 + 0x1e;
    DAT_00e79678 = DAT_00e79678 + 6;
    return 0;
  }
  if (DAT_00dda46c != unaff_EDI) {
    FUN_00584d70();
  }
  if ((DAT_00e79674 == unaff_EDI) && (DAT_00e79680 == 4)) {
    if (*(int *)(&DAT_007da368 + DAT_00e7967c * 4) <= (int)(DAT_00e79678 + 3)) {
      unaff_EDI = 0;
      goto LAB_005b3d28;
    }
    unaff_EDI = 0;
  }
  else {
LAB_005b3d28:
    if (DAT_00e79678 != unaff_EDI) {
      FUN_005a7ce0();
      if (DAT_00e79680 == 4) {
        uVar4 = (int)DAT_00e79678 / 3;
      }
      else if (DAT_00e79680 == 2) {
        uVar4 = (int)DAT_00e79678 / 2;
      }
      else if (DAT_00e79680 == 6) {
        uVar4 = DAT_00e79678 - 2;
      }
      else if (DAT_00e79680 == 5) {
        uVar4 = DAT_00e79678 - 2;
      }
      else if (DAT_00e79680 == 3) {
        uVar4 = DAT_00e79678 - 1;
      }
      else {
        uVar4 = ~-(uint)(DAT_00e79680 != 1) & DAT_00e79678;
      }
      iVar3 = DAT_00e7967c + DAT_00e79674 * 3;
      FUN_005d3b40(DAT_00e79680,uVar4,*(undefined4 *)(&DAT_00e39a5c + iVar3 * 4),
                   *(undefined4 *)(&DAT_007da3e8 + iVar3 * 4));
      DAT_00a37de4 = DAT_00a37de4 + 1;
      unaff_EDI = 0;
    }
    DAT_00e39a58 = *(float **)(&DAT_00e39a5c + DAT_00e7967c * 4);
    DAT_00e79680 = 4;
    DAT_00e79674 = unaff_EDI;
    DAT_00e79678 = unaff_EDI;
  }
  pfVar2 = DAT_00e39a58;
  DAT_00e39a58[4] = fVar5;
  *pfVar2 = (float)param_6;
  pfVar2[1] = (float)param_7;
  if (DAT_00a37fdc == unaff_EDI) {
LAB_005b3eae:
    pfVar2[5] = (float)param_8;
    pfVar2[6] = (float)param_9;
    pfVar2[10] = (float)param_10;
    param_9 = param_11;
  }
  else {
    if (DAT_00a37fdc - unaff_EDI == 1) {
      if (0 < (param_8 - param_6) * (param_11 - param_7) -
              (param_10 - param_6) * (param_9 - param_7)) goto LAB_005b3eae;
    }
    else {
      if (DAT_00a37fdc - unaff_EDI != 2) goto LAB_005b3eca;
      if ((param_8 - param_6) * (param_11 - param_7) - (param_10 - param_6) * (param_9 - param_7) <
          0) goto LAB_005b3eae;
    }
    pfVar2[5] = (float)param_10;
    pfVar2[6] = (float)param_11;
    pfVar2[10] = (float)param_8;
  }
  pfVar2[0xb] = (float)param_9;
LAB_005b3eca:
  pfVar2[2] = fVar1;
  pfVar2[7] = fVar1;
  pfVar2[0xc] = fVar1;
  DAT_00e39a58 = DAT_00e39a58 + 0xf;
  DAT_00e79678 = DAT_00e79678 + 3;
  return 0;
}

