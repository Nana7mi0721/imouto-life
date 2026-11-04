
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005cc6a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            )

{
  short sVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  float *pfVar11;
  short *psVar12;
  uint uVar13;
  float fVar14;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  float local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (1 < param_5) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    if (DAT_00f3a070 != 0) {
      iVar8 = FUN_0051c840(0,40000);
      iVar6 = DAT_00a37f74;
      if (-1 < iVar8) {
        if (DAT_00ef7314 != 0) {
          FUN_005bc5b0(0,0);
        }
        if (((DAT_00a3d360 != 0) || (DAT_00ef72cc != 0)) || (DAT_00ef72c8 != 0x20)) {
          FUN_005bcf50();
        }
        iVar8 = DAT_00a381a0;
        fVar7 = DAT_00a380b8;
        local_10 = DAT_00a38194;
        local_c = DAT_00a38198;
        local_8 = DAT_00a3819c;
        local_4 = DAT_00a381a0;
        FUN_00544000(param_4,&local_1c,&local_20,&local_24);
        uVar10 = DAT_00f07344 >> 0x10 & 0xff;
        if (DAT_00a37dcc == 0) {
          uVar13 = (uVar10 * local_24) / 0xff << 8 | ((DAT_00f07344 >> 8 & 0xff) * local_20) / 0xff;
          uVar10 = (DAT_00f07344 & 0xff) * local_1c;
        }
        else {
          uVar13 = (uVar10 * local_1c) / 0xff << 8 | ((DAT_00f07344 >> 8 & 0xff) * local_20) / 0xff;
          uVar10 = (DAT_00f07344 & 0xff) * local_24;
        }
        local_18 = (float)(iVar8 * 10);
        fVar14 = (float)(uVar13 << 8 | uVar10 / 0xff | DAT_00f07344 & 0xff000000);
        iVar9 = FUN_0051c840(1,local_18);
        iVar8 = DAT_00a37f78;
        if (iVar9 < 0) {
          return 0xffffffff;
        }
        FUN_0056d380(DAT_00a37f78,0,local_18);
        FUN_0051a320(param_1,param_2,param_3,param_5,iVar8);
        iVar9 = 0;
        local_28 = local_c;
        if (local_c < local_4) {
          fVar3 = (float)_DAT_00829898;
          psVar12 = (short *)(iVar8 + 4 + local_c * 10);
          do {
            if (psVar12[2] != 0) {
              fVar2 = (float)local_28;
              fVar5 = fVar3;
              if (((psVar12[2] & 0xcU) == 0) || (sVar1 = *psVar12, psVar12[1] <= sVar1)) {
                param_5 = (int)psVar12[-2];
                if (param_5 < local_10) {
                  param_5 = local_10;
                }
                iVar8 = (int)psVar12[-1];
                if (local_8 + -1 < (int)psVar12[-1]) {
                  iVar8 = local_8 + -1;
                }
                pfVar11 = (float *)(iVar6 + iVar9 * 0x14);
                *pfVar11 = (float)param_5 + fVar3;
                pfVar11[1] = fVar2 + fVar3;
                pfVar11[3] = 1.0;
                local_18 = fVar2;
              }
              else {
                param_5 = (int)psVar12[-2];
                if (param_5 < local_10) {
                  param_5 = local_10;
                }
                local_14 = local_8 + -1;
                iVar8 = (int)sVar1;
                if (local_14 < sVar1) {
                  iVar8 = local_14;
                }
                pfVar11 = (float *)(iVar6 + iVar9 * 0x14);
                local_18 = (float)(iVar8 + 1);
                pfVar11[4] = fVar14;
                pfVar11[2] = fVar7;
                *pfVar11 = (float)param_5 + fVar3;
                fVar4 = fVar2 + fVar3;
                pfVar11[1] = fVar4;
                pfVar11[3] = 1.0;
                pfVar11 = (float *)(iVar6 + (iVar9 + 1) * 0x14);
                iVar9 = iVar9 + 2;
                pfVar11[4] = fVar14;
                pfVar11[2] = fVar7;
                *pfVar11 = (float)(int)local_18 + fVar3;
                pfVar11[1] = fVar4;
                pfVar11[3] = 1.0;
                if (1999 < iVar9) {
                  FUN_005cba60(0,2,iVar6,iVar9,1);
                  fVar5 = (float)_DAT_00829898;
                  iVar9 = 0;
                }
                param_5 = (int)psVar12[1];
                if (param_5 < local_10) {
                  param_5 = local_10;
                }
                iVar8 = (int)psVar12[-1];
                if (local_14 < psVar12[-1]) {
                  iVar8 = local_14;
                }
                pfVar11 = (float *)(iVar6 + iVar9 * 0x14);
                *pfVar11 = (float)param_5 + fVar5;
                pfVar11[1] = fVar4;
                pfVar11[3] = 1.0;
              }
              param_5 = iVar8 + 1;
              pfVar11[4] = fVar14;
              pfVar11[2] = fVar7;
              pfVar11 = (float *)(iVar6 + (iVar9 + 1) * 0x14);
              *pfVar11 = (float)param_5 + fVar5;
              iVar9 = iVar9 + 2;
              pfVar11[1] = fVar2 + fVar3;
              pfVar11[2] = fVar7;
              pfVar11[3] = 1.0;
              pfVar11[4] = fVar14;
              fVar3 = fVar5;
              if (1999 < iVar9) {
                FUN_005cba60(0,2,iVar6,iVar9,1);
                fVar3 = (float)_DAT_00829898;
                iVar9 = 0;
              }
            }
            local_28 = local_28 + 1;
            psVar12 = psVar12 + 5;
          } while (local_28 < local_4);
          if (iVar9 != 0) {
            FUN_005cba60(0,2,iVar6,iVar9,1);
          }
        }
        return 0;
      }
    }
  }
  return 0xffffffff;
}

