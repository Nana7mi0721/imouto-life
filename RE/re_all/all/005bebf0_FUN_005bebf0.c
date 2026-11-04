
undefined4 FUN_005bebf0(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  uint local_94;
  uint local_90;
  int local_8c;
  int local_88;
  int local_84;
  undefined4 local_80;
  int local_7c;
  undefined4 local_78;
  uint local_74;
  uint local_70;
  undefined4 local_6c;
  uint local_68;
  undefined4 local_64;
  uint local_60;
  int local_5c;
  int local_58;
  undefined4 local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int local_c;
  
  local_94 = 1;
  local_90 = 0;
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (*(char *)(param_1 + 8) == '\0') {
    return 0;
  }
  if (*(int *)(&DAT_00ee9a58 + *(int *)(param_1 + 4) * 4) == 0) {
    FUN_0056bb10(&DAT_007fc300);
    return 0xffffffff;
  }
  if (*(byte *)(param_1 + 0x19) != 0) {
    if ((*(char *)(param_1 + 9) == '\0') && (0x9fff < DAT_00ee9a3c)) {
      local_94 = (uint)*(byte *)(param_1 + 0x19);
      local_90 = (uint)*(byte *)(param_1 + 0x1a);
      FUN_005d51c0(*(int *)(&DAT_00ee9a58 + *(int *)(param_1 + 4) * 4),&local_94,&local_90,0,param_2
                  );
    }
    else {
      local_94 = 1;
      local_90 = 0;
    }
  }
  piVar5 = (int *)(param_1 + 0x3c);
  local_5c = 0;
  if (*(int *)(param_1 + 0x38) < 1) {
    return 0;
  }
  do {
    *(undefined1 *)(param_1 + 0xd) = 0;
    if ((*(int *)*piVar5 == 0) && (1 < local_94)) {
      FUN_0056d380(&local_88,0,0x2c);
      local_78 = *(undefined4 *)(&DAT_00ee9a58 + *(int *)(param_1 + 4) * 4);
      local_88 = piVar5[5];
      local_84 = piVar5[6];
      local_68 = -(uint)(*(char *)(param_1 + 0xb) != '\0') & 0x20 | 8;
      local_80 = *(undefined4 *)(param_1 + 0x34);
      local_74 = local_94;
      local_7c = (-(uint)(*(char *)(param_1 + 9) != '\0') & 5) + 1;
      local_6c = 0;
      local_60 = -(uint)(*(char *)(param_1 + 9) != '\0') & 4;
      local_64 = 0;
      local_70 = local_90;
      iVar2 = FUN_005d4ee0(&local_88,0,*piVar5,param_2);
      if (iVar2 < 0) {
        FUN_0056bb10(&DAT_007fdafc);
        return 0xffffffff;
      }
    }
    if (*(int *)(*piVar5 + 4) == 0) {
      FUN_0056d380(&local_88,0,0x2c);
      local_78 = *(undefined4 *)(&DAT_00ee9a58 + *(int *)(param_1 + 4) * 4);
      local_88 = piVar5[5];
      local_84 = piVar5[6];
      local_68 = -(uint)(*(char *)(param_1 + 0xb) != '\0') & 0x20 | 8;
      local_80 = *(undefined4 *)(param_1 + 0x34);
      local_6c = 0;
      local_7c = (-(uint)(*(char *)(param_1 + 9) != '\0') & 5) + 1;
      local_64 = 0;
      local_74 = 1;
      local_70 = 0;
      local_60 = -(uint)(*(char *)(param_1 + 9) != '\0') & 4;
      iVar2 = FUN_005d4ee0(&local_88,0,*piVar5 + 4,param_2);
      if (iVar2 < 0) {
        FUN_0056bb10(&DAT_007fc238);
        return 0xffffffff;
      }
    }
    if (*(char *)(param_1 + 0xb) != '\0') {
      iVar2 = (-(uint)(*(char *)(param_1 + 9) != '\0') & 5) + 1;
      local_58 = iVar2;
      if (*(int *)(*piVar5 + 0xc) == 0) {
        uVar3 = FUN_0056e030(*(int *)(param_1 + 0x34) * iVar2 * 4,
                             "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp",
                             0x577e);
        *(undefined4 *)(*piVar5 + 0xc) = uVar3;
        if (*(int *)(*piVar5 + 0xc) == 0) {
          FUN_0056bb10(&DAT_007fdaa0);
          return 0xffffffff;
        }
        FUN_0056d380(*(int *)(*piVar5 + 0xc),0,*(int *)(param_1 + 0x34) * iVar2 * 4);
      }
      local_8c = 0;
      if (iVar2 != 0) {
        do {
          iVar4 = 0;
          iVar2 = local_8c;
          if (0 < *(int *)(param_1 + 0x34)) {
            do {
              if (*(int *)(*(int *)(*piVar5 + 0xc) + (*(int *)(param_1 + 0x34) * iVar2 + iVar4) * 4)
                  == 0) {
                FUN_0056d380(&local_54,0,0x14);
                local_54 = *(undefined4 *)(&DAT_00ee9a58 + *(int *)(param_1 + 4) * 4);
                if (*(char *)(param_1 + 9) == '\0') {
                  local_50 = (-(uint)(1 < local_94) & 2) + 4;
                }
                else {
                  local_50 = 5;
                  local_44 = 1;
                  local_48 = iVar2;
                }
                piVar1 = (int *)*piVar5;
                if (*piVar1 == 0) {
                  iVar2 = piVar1[1];
                }
                else {
                  iVar2 = *piVar1;
                }
                local_4c = iVar4;
                iVar2 = FUN_005d5000(iVar2,&local_54,
                                     piVar1[3] + (*(int *)(param_1 + 0x34) * local_8c + iVar4) * 4,
                                     param_2);
                if (iVar2 < 0) {
                  FUN_0056bca0(&DAT_007fda20,
                               *(undefined4 *)(&DAT_00ee9a58 + *(int *)(param_1 + 4) * 4),piVar5[5],
                               piVar5[6]);
                  return 0xffffffff;
                }
                iVar2 = local_8c;
              }
              iVar4 = iVar4 + 1;
            } while (iVar4 < *(int *)(param_1 + 0x34));
          }
          local_8c = iVar2 + 1;
        } while (local_8c < local_58);
      }
      if (DAT_00a37d84 == 1) {
        if (local_94 < 2) goto LAB_005bf144;
      }
      else if ((DAT_00a37d84 < 2) || (local_94 != 1)) {
LAB_005bf144:
        if (*(int *)(param_1 + 0x28) == 0) {
          if (*(int *)(*piVar5 + 0x10) != 0) {
            FUN_005d4d40(*(int *)(*piVar5 + 0x10),0);
            *(undefined4 *)(*piVar5 + 0x10) = 0;
          }
          if (*(int *)(*piVar5 + 0x14) != 0) {
            iVar2 = 0;
            if (0 < *(int *)(param_1 + 0x34)) {
              do {
                if (*(int *)(*(int *)(*piVar5 + 0x14) + iVar2 * 4) != 0) {
                  FUN_005d4dc0(*(undefined4 *)(*(int *)(*piVar5 + 0x14) + iVar2 * 4),0);
                  *(undefined4 *)(*(int *)(*piVar5 + 0x14) + iVar2 * 4) = 0;
                }
                iVar2 = iVar2 + 1;
              } while (iVar2 < *(int *)(param_1 + 0x34));
            }
            FUN_0056e1d0(*(undefined4 *)(*piVar5 + 0x14));
            *(undefined4 *)(*piVar5 + 0x14) = 0;
          }
          goto LAB_005bf1bb;
        }
      }
      if (*(int *)(*piVar5 + 0x10) != 0) {
        FUN_005d4d40(*(int *)(*piVar5 + 0x10),0);
        *(undefined4 *)(*piVar5 + 0x10) = 0;
      }
      if (*(int *)(*piVar5 + 0x14) != 0) {
        iVar2 = 0;
        if (0 < *(int *)(param_1 + 0x34)) {
          do {
            if (*(int *)(*(int *)(*piVar5 + 0x14) + iVar2 * 4) != 0) {
              FUN_005d4dc0(*(undefined4 *)(*(int *)(*piVar5 + 0x14) + iVar2 * 4),0);
              *(undefined4 *)(*(int *)(*piVar5 + 0x14) + iVar2 * 4) = 0;
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < *(int *)(param_1 + 0x34));
        }
        FUN_0056e1d0(*(undefined4 *)(*piVar5 + 0x14));
        *(undefined4 *)(*piVar5 + 0x14) = 0;
      }
      FUN_0056d380(&local_88,0,0x2c);
      local_88 = piVar5[5];
      local_84 = piVar5[6];
      local_80 = *(undefined4 *)(param_1 + 0x34);
      local_78 = (&DAT_00ee9b1c)[*(int *)(param_1 + 0x2c)];
      local_74 = local_94;
      local_70 = local_90;
      local_7c = 1;
      local_6c = 0;
      local_68 = 0x40;
      local_64 = 0;
      local_60 = 0;
      iVar2 = FUN_005d4ee0(&local_88,0,*piVar5 + 0x10,param_2);
      if (iVar2 < 0) {
        FUN_0056bb10(&DAT_007fd9e0);
        return 0xffffffff;
      }
      if (*(int *)(*piVar5 + 0x14) == 0) {
        uVar3 = FUN_0056e030(*(int *)(param_1 + 0x34) * 4,
                             "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp",
                             0x57e3);
        *(undefined4 *)(*piVar5 + 0x14) = uVar3;
        if (*(int *)(*piVar5 + 0x14) == 0) {
          FUN_0056bb10(&DAT_007fd980);
          return 0xffffffff;
        }
        FUN_0056d380(*(int *)(*piVar5 + 0x14),0,*(int *)(param_1 + 0x34) * 4);
      }
      iVar2 = 0;
      if (0 < *(int *)(param_1 + 0x34)) {
        do {
          FUN_0056d380(&local_18,0,0x18);
          local_18 = (&DAT_00ee9b28)[*(int *)(param_1 + 0x2c)];
          local_14 = (-(uint)(1 < local_94) & 2) + 3;
          local_c = iVar2;
          iVar4 = FUN_005d5060(*(undefined4 *)(*piVar5 + 0x10),&local_18,
                               *(int *)(*piVar5 + 0x14) + iVar2 * 4,param_2);
          if (iVar4 < 0) {
            FUN_0056bb10(&DAT_007fd944);
            return 0xffffffff;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(param_1 + 0x34));
      }
    }
LAB_005bf1bb:
    if (*(int *)(*piVar5 + 8) == 0) {
      FUN_0056d380(&local_40,0,0x18);
      local_40 = *(undefined4 *)(&DAT_00ee9a58 + *(int *)(param_1 + 4) * 4);
      if (*(char *)(param_1 + 9) == '\0') {
        local_34 = *(undefined4 *)(param_1 + 0x34);
        local_3c = 4;
      }
      else {
        local_34 = *(undefined4 *)(param_1 + 0x34);
        local_3c = 9;
        local_38 = 0;
      }
      iVar2 = FUN_005d4fa0(*(undefined4 *)(*piVar5 + 4),&local_40,*piVar5 + 8,param_2);
      if (iVar2 < 0) {
        FUN_0056bca0(&DAT_007fd8c8,*(undefined4 *)(&DAT_00ee9a58 + *(int *)(param_1 + 4) * 4),
                     piVar5[5],piVar5[6]);
        return 0xffffffff;
      }
    }
    if (*(char *)(param_1 + 0xb) != '\0') {
      iVar2 = ((-(uint)(*(char *)(param_1 + 9) != '\0') & 5) + 1) * *(int *)(param_1 + 0x34);
      if (0 < iVar2) {
        iVar4 = 0;
        do {
          if (*(int *)(*(int *)(*piVar5 + 0xc) + iVar4 * 4) != 0) {
            local_24 = 0;
            local_28 = 0;
            local_20 = 0;
            local_1c = 0;
            FUN_005d5380(*(undefined4 *)(*(int *)(*piVar5 + 0xc) + iVar4 * 4),&local_28,param_2);
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar2);
      }
      if ((*(int *)(*piVar5 + 0x14) != 0) && (iVar2 = 0, 0 < *(int *)(param_1 + 0x34))) {
        do {
          FUN_005d53d0(*(undefined4 *)(*(int *)(*piVar5 + 0x14) + iVar2 * 4),1,0x3f800000,0,param_2)
          ;
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(param_1 + 0x34));
      }
    }
    local_5c = local_5c + 1;
    piVar5 = piVar5 + 7;
    if (*(int *)(param_1 + 0x38) <= local_5c) {
      return 0;
    }
  } while( true );
}

