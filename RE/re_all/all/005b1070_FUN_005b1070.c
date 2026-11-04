
undefined4
FUN_005b1070(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int param_6)

{
  float *pfVar1;
  short sVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  short *local_28;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (1 < param_6) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    if ((DAT_00f3a04c != 0) && (iVar6 = FUN_0051c840(0,40000), iVar4 = DAT_00a37f74, -1 < iVar6)) {
      FUN_0059d430();
      if (DAT_00e39a4c != 0) {
        FUN_0059bcf0(0);
      }
      if (((DAT_00a3d360 != 0) || (DAT_00e39a00 != 0)) || (DAT_00e399fc != 0x20)) {
        FUN_005a7f60();
      }
      iVar8 = DAT_00a381a0;
      fVar5 = DAT_00a380b8;
      local_10 = DAT_00a38194;
      local_c = DAT_00a38198;
      local_8 = DAT_00a3819c;
      local_4 = DAT_00a381a0;
      FUN_00544000(param_5,&local_1c,&local_18,&local_14);
      fVar9 = (float)((((DAT_00e79684 >> 0x10 & 0xff) * local_1c) / 0xff << 8 |
                      ((DAT_00e79684 >> 8 & 0xff) * local_18) / 0xff) << 8 |
                      ((DAT_00e79684 & 0xff) * local_14) / 0xff | DAT_00e79684 & 0xff000000);
      FUN_005a7ce0();
      iVar7 = FUN_0051c840(1,iVar8 * 10);
      iVar6 = DAT_00a37f78;
      if (-1 < iVar7) {
        FUN_0056d380(DAT_00a37f78,0,iVar8 * 10);
        iVar8 = FUN_0051ab60(param_1,param_2,param_3,param_4,param_6,iVar6);
        if (-1 < iVar8) {
          iVar8 = 0;
          local_20 = local_c;
          if (local_c < local_4) {
            local_28 = (short *)(iVar6 + 4 + local_c * 10);
            do {
              if (local_28[2] != 0) {
                fVar3 = (float)local_20;
                if (((local_28[2] & 0xcU) == 0) || (sVar2 = *local_28, local_28[1] <= sVar2)) {
                  param_6 = (int)local_28[-2];
                  if (param_6 < local_10) {
                    param_6 = local_10;
                  }
                  iVar6 = (int)local_28[-1];
                  if (local_8 + -1 < (int)local_28[-1]) {
                    iVar6 = local_8 + -1;
                  }
                  pfVar1 = (float *)(iVar4 + iVar8 * 0x14);
                  pfVar1[4] = fVar9;
                  *pfVar1 = (float)param_6;
                  pfVar1[2] = fVar5;
                  pfVar1[1] = fVar3;
                  pfVar1[3] = 1.0;
                  pfVar1 = (float *)(iVar4 + (iVar8 + 1) * 0x14);
                  iVar8 = iVar8 + 2;
                  *pfVar1 = (float)(iVar6 + 1);
                  pfVar1[4] = fVar9;
                  pfVar1[2] = fVar5;
                  pfVar1[1] = fVar3;
                  pfVar1[3] = 1.0;
                  if (1999 < iVar8) {
                    FUN_005d3b40(2,iVar8 / 2,iVar4,0x14);
                    DAT_00a37de4 = DAT_00a37de4 + 1;
                    iVar8 = 0;
                  }
                }
                else {
                  param_6 = (int)local_28[-2];
                  if (param_6 < local_10) {
                    param_6 = local_10;
                  }
                  iVar7 = local_8 + -1;
                  iVar6 = (int)sVar2;
                  if (iVar7 < sVar2) {
                    iVar6 = iVar7;
                  }
                  pfVar1 = (float *)(iVar4 + iVar8 * 0x14);
                  pfVar1[4] = fVar9;
                  *pfVar1 = (float)param_6;
                  pfVar1[2] = fVar5;
                  pfVar1[1] = fVar3;
                  pfVar1[3] = 1.0;
                  pfVar1 = (float *)(iVar4 + (iVar8 + 1) * 0x14);
                  iVar8 = iVar8 + 2;
                  *pfVar1 = (float)(iVar6 + 1);
                  pfVar1[4] = fVar9;
                  pfVar1[2] = fVar5;
                  pfVar1[1] = fVar3;
                  pfVar1[3] = 1.0;
                  if (1999 < iVar8) {
                    FUN_005d3b40(2,iVar8 / 2,iVar4,0x14);
                    DAT_00a37de4 = DAT_00a37de4 + 1;
                    iVar8 = 0;
                  }
                  param_6 = (int)local_28[1];
                  if (param_6 < local_10) {
                    param_6 = local_10;
                  }
                  iVar6 = (int)local_28[-1];
                  if (iVar7 < local_28[-1]) {
                    iVar6 = iVar7;
                  }
                  pfVar1 = (float *)(iVar4 + iVar8 * 0x14);
                  pfVar1[4] = fVar9;
                  *pfVar1 = (float)param_6;
                  pfVar1[2] = fVar5;
                  pfVar1[1] = fVar3;
                  pfVar1[3] = 1.0;
                  pfVar1 = (float *)(iVar4 + (iVar8 + 1) * 0x14);
                  iVar8 = iVar8 + 2;
                  *pfVar1 = (float)(iVar6 + 1);
                  pfVar1[4] = fVar9;
                  pfVar1[2] = fVar5;
                  pfVar1[1] = fVar3;
                  pfVar1[3] = 1.0;
                  if (1999 < iVar8) {
                    FUN_005d3b40(2,iVar8 / 2,iVar4,0x14);
                    DAT_00a37de4 = DAT_00a37de4 + 1;
                    iVar8 = 0;
                  }
                }
              }
              local_20 = local_20 + 1;
              local_28 = local_28 + 5;
            } while (local_20 < local_4);
            if (iVar8 != 0) {
              FUN_005d3b40(2,iVar8 / 2,iVar4,0x14);
              DAT_00a37de4 = DAT_00a37de4 + 1;
            }
          }
          return 0;
        }
      }
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

