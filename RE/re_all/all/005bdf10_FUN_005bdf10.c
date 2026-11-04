
undefined4
FUN_005bdf10(int param_1,undefined4 param_2,uint *param_3,undefined4 param_4,uint param_5,
            uint param_6,char *param_7,int param_8,int param_9,undefined4 param_10,int param_11,
            int param_12)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  byte bVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  int local_50;
  int local_4c;
  int local_48;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_2c;
  int local_24;
  uint local_18;
  uint local_14;
  undefined4 local_10;
  uint local_c;
  uint local_8;
  undefined4 local_4;
  
  cVar1 = *param_7;
  if (((cVar1 == '\x01') || (cVar1 == '\x03')) || (bVar5 = false, cVar1 == '\x05')) {
    bVar5 = true;
  }
  uVar14 = -(uint)(*(char *)(param_1 + 9) != '\0') & 5;
  if (((*param_3 == 0) && (param_3[2] == param_5)) &&
     ((param_3[1] == 0 &&
      ((param_3[3] == param_6 &&
       (iVar11 = *(int *)(param_1 + 0x34), iVar11 <= *(int *)(param_7 + 0x438))))))) {
    local_50 = *(int *)(param_7 + 0x434);
    if (bVar5) {
      uVar7 = (int)((uint)(byte)param_7[5] * 4) >> 3;
    }
    else {
      uVar7 = (uint)(byte)param_7[4];
    }
    local_4c = 0;
    if (uVar14 != 0xffffffff) {
      do {
        param_3 = (uint *)0x0;
        if (0 < iVar11) {
          uVar15 = param_6;
          uVar18 = param_5;
          do {
            if (bVar5) {
              iVar16 = ((int)(uVar15 + 3 + ((int)(uVar15 + 3) >> 0x1f & 3U)) >> 2) *
                       ((int)(uVar18 + 3 + ((int)(uVar18 + 3) >> 0x1f & 3U)) >> 2) *
                       (uint)(byte)param_7[5] * 2;
            }
            else {
              iVar16 = (byte)param_7[4] * uVar15 * uVar18;
            }
            local_18 = 0;
            local_14 = 0;
            local_10 = 0;
            if (bVar5) {
              local_c = ((int)(uVar18 + 3 + ((int)(uVar18 + 3) >> 0x1f & 3U)) >> 2) * 4;
              local_8 = ((int)(uVar15 + 3 + ((int)(uVar15 + 3) >> 0x1f & 3U)) >> 2) * 4;
            }
            else {
              local_c = uVar18;
              local_8 = uVar15;
            }
            local_4 = 1;
            if (bVar5) {
              iVar8 = ((int)(uVar18 + 3 + ((int)(uVar18 + 3) >> 0x1f & 3U)) >> 2) * uVar7 * 4;
            }
            else {
              iVar8 = uVar18 * uVar7;
            }
            FUN_005d52f0(param_4,iVar11 * local_4c + (int)param_3,&local_18,local_50,iVar8,0,
                         param_12);
            local_50 = local_50 + iVar16;
            uVar18 = (int)uVar18 >> 1;
            uVar15 = (int)uVar15 >> 1;
            if ((int)uVar18 < 1) {
              uVar18 = 1;
            }
            if ((int)uVar15 < 1) {
              uVar15 = 1;
            }
            iVar11 = *(int *)(param_1 + 0x34);
            param_3 = (uint *)((int)param_3 + 1);
          } while ((int)param_3 < iVar11);
        }
        local_4c = local_4c + 1;
      } while (local_4c < (int)(uVar14 + 1));
      return 0;
    }
  }
  else {
    if (bVar5) {
      FUN_0056bb10(&DAT_007fc5e0);
      return 0;
    }
    iVar11 = 1;
    iVar16 = param_3[2] - *param_3;
    local_48 = 1;
    if (1 < iVar16) {
      do {
        iVar11 = iVar11 * 2;
      } while (iVar11 < iVar16);
      local_48 = iVar11;
    }
    iVar11 = 1;
    local_2c = 1;
    if (1 < (int)(param_3[3] - param_3[1])) {
      do {
        iVar11 = iVar11 * 2;
      } while (iVar11 < (int)(param_3[3] - param_3[1]));
      local_2c = iVar11;
    }
    iVar11 = (uint)*(byte *)(param_9 + 4) * local_48;
    iVar16 = iVar11 * local_2c;
    if (param_12 == 0) {
      uVar7 = iVar16 * 2;
      if (DAT_00f2eaac < uVar7) {
        FUN_0056e1d0(DAT_00f2eaa8);
        DAT_00f2eaa8 = 0;
        DAT_00f2eaac = 0;
        DAT_00f2eaa8 = FUN_0056e030(uVar7,
                                    "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp"
                                    ,0xd5b);
        if (DAT_00f2eaa8 == 0) {
          FUN_0056bca0(&DAT_007fd070);
          return 0xffffffff;
        }
        DAT_00f2eaac = uVar7;
      }
      local_50 = DAT_00f2eaa8;
    }
    else {
      local_50 = FUN_0056e030(iVar16 * 2,
                              "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp",
                              0x5502);
      if (local_50 == 0) {
        FUN_0056bb10(&DAT_007fc678);
        return 0xffffffff;
      }
    }
    iVar8 = *(int *)(param_8 + 0x42c);
    iVar2 = *(int *)(param_8 + 0x430);
    iVar3 = *(int *)(param_7 + 0x42c);
    iVar4 = *(int *)(param_7 + 0x430);
    local_4c = 0;
    if (uVar14 != 0xffffffff) {
      local_34 = 0;
      local_38 = 0;
      do {
        local_40 = local_48;
        uVar7 = 0;
        iVar12 = local_48;
        local_3c = local_2c;
        local_24 = local_2c;
        if (0 < *(int *)(param_1 + 0x34)) {
          do {
            iVar6 = local_40;
            bVar13 = (byte)uVar7;
            iVar17 = local_50;
            if (uVar7 == 0) {
              if (((param_11 == 0) || (*(char *)(param_9 + 0xb) == '\0')) ||
                 (*(int *)(param_8 + 0x434) != 0)) {
                uVar9 = 0;
              }
              else {
                uVar9 = 1;
              }
              FUN_00549b20(local_50,iVar11,param_9,*(int *)(param_7 + 0x434) + local_34,
                           *(undefined4 *)(param_7 + 0x430),param_7,
                           *(int *)(param_8 + 0x434) + local_38,*(undefined4 *)(param_8 + 0x430),
                           param_8,0,0,param_2,0,uVar9,*(undefined4 *)(param_1 + 0x1c),DAT_00a52a50,
                           0,param_10,0,0);
            }
            else {
              if ((uVar7 & 1) == 0) {
                iVar10 = iVar16 + local_50;
              }
              else {
                iVar10 = local_50;
                iVar17 = iVar16 + local_50;
              }
              FUN_00542590(param_9,iVar17,iVar11,iVar10,iVar11,0,0,0,0,iVar12,local_24);
            }
            local_18 = *param_3 >> (bVar13 & 0x1f);
            local_c = param_3[2] >> (bVar13 & 0x1f);
            local_14 = param_3[1] >> (bVar13 & 0x1f);
            local_8 = param_3[3] >> (bVar13 & 0x1f);
            local_10 = 0;
            local_4 = 1;
            if (local_c == local_18) {
              local_c = local_18 + 1;
            }
            if (local_8 == local_14) {
              local_8 = local_14 + 1;
            }
            FUN_005d52f0(param_4,uVar7 + local_4c,&local_18,iVar17,iVar11,0,param_12);
            local_40 = local_40 >> 1;
            local_24 = local_3c;
            local_3c = local_3c >> 1;
            if (local_40 == 0) {
              local_40 = 1;
            }
            if (local_3c == 0) {
              local_3c = 1;
            }
            uVar7 = uVar7 + 1;
            iVar12 = iVar6;
          } while ((int)uVar7 < *(int *)(param_1 + 0x34));
        }
        local_38 = local_38 + iVar8 * iVar2;
        local_34 = local_34 + iVar3 * iVar4;
        local_4c = local_4c + 1;
      } while (local_4c < (int)(uVar14 + 1));
    }
    if (param_12 != 0) {
      FUN_0056e1d0(local_50);
    }
  }
  return 0;
}

