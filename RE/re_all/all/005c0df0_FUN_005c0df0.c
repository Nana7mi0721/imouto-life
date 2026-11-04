
int FUN_005c0df0(HWND param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  tagRECT local_4c;
  int local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  HWND local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar4 = 0;
  iVar5 = -1;
  piVar3 = &DAT_00ee9b48;
  iVar1 = 0;
  do {
    if (DAT_00ee9b44 <= iVar4) break;
    if (*piVar3 == 0) {
      iVar5 = iVar1;
    }
    else {
      iVar4 = iVar4 + 1;
      if ((HWND)piVar3[0xd] == param_1) {
        return iVar1;
      }
    }
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 0x20;
  } while (iVar1 < 0x100);
  if (DAT_00ee9b44 < 0x100) {
    if ((iVar5 == -1) && (iVar5 = 0, DAT_00ee9b48 != 0)) {
      piVar3 = &DAT_00ee9b48;
      do {
        piVar3 = piVar3 + 0x20;
        iVar5 = iVar5 + 1;
      } while (*piVar3 != 0);
    }
    FUN_0056d380(&local_3c,0,0x3c);
    local_34 = 0x3c;
    if (DAT_00a37e74 != 0) {
      local_34 = DAT_00a37e74;
    }
    local_30 = 1;
    local_2c = 0x1c;
    local_28 = 0;
    local_24 = 0;
    local_14 = 2;
    local_18 = 0x30;
    local_10 = param_1;
    local_8 = 0;
    local_4 = 2;
    if (param_2 == 0) {
      GetClientRect(param_1,&local_4c);
      local_3c = local_4c.right - local_4c.left;
      local_38 = local_4c.bottom - local_4c.top;
      local_c = 1;
      FUN_0056bb10(&DAT_007fde90);
    }
    else {
      iVar1 = FUN_0050e7d0();
      if (iVar1 == 1) {
        local_3c = DAT_00a37e60;
        local_38 = DAT_00a37e64;
        local_c = 1;
        FUN_0056bca0(&DAT_007fded0,DAT_00a37e60,DAT_00a37e64);
      }
      else {
        FUN_00522420();
        local_3c = DAT_00a37e8c;
        local_38 = DAT_00a37e90;
        local_c = 0;
        DAT_00ef1b4c = 1;
        FUN_0056bca0(&DAT_007fdea8,DAT_00a37e8c,DAT_00a37e90);
      }
    }
    if ((DAT_00a37d84 < 2) || (DAT_00ee9a3c < 0xa000)) {
      local_1c = 0;
      local_20 = 1;
    }
    else {
      local_20 = DAT_00a37d84;
      local_1c = DAT_00a37d88;
      FUN_005d2a20(local_2c,&local_20,&local_1c,0);
    }
    DAT_00a37d84 = local_20;
    DAT_00a37d88 = local_1c;
    FUN_0056bb10(&PTR_PTR_007fde58);
    piVar3 = &DAT_00ee9b4c + iVar5 * 0x20;
    uVar2 = FUN_005d2340(&local_3c,piVar3);
    if (*piVar3 == 0) {
      FUN_0056bca0("1YWe ",uVar2);
    }
    else {
      FUN_005d2360(param_1,3);
      FUN_0056bb10(&DAT_007d4974);
      FUN_0056bca0(&PTR_PTR_007fdde0,uVar2);
      FUN_005d2730(*piVar3,&DAT_00ee9b50 + iVar5 * 0x80);
      FUN_0056bb10(&PTR_PTR_007fddac);
      iVar1 = FUN_005d2780(*piVar3,&DAT_00ee9b8c + iVar5 * 0x20);
      if (iVar1 == 0) {
        FUN_0056bb10(&DAT_007d4974);
        iVar1 = FUN_005b8480(iVar5);
        if (-1 < iVar1) {
          (&DAT_00ee9b48)[iVar5 * 0x20] = 1;
          DAT_00ee9b44 = DAT_00ee9b44 + 1;
          return iVar5;
        }
      }
      else {
        FUN_0056bca0("1YWe ",iVar1);
      }
    }
    if ((&DAT_00ee9bc0)[iVar5 * 0x20] != 0) {
      FUN_005d1f20((&DAT_00ee9bc0)[iVar5 * 0x20]);
      (&DAT_00ee9bc0)[iVar5 * 0x20] = 0;
    }
    if ((&DAT_00ee9bc4)[iVar5 * 0x20] != 0) {
      FUN_005d1f40((&DAT_00ee9bc4)[iVar5 * 0x20]);
      (&DAT_00ee9bc4)[iVar5 * 0x20] = 0;
    }
    if ((&DAT_00ee9b90)[iVar5 * 0x20] != 0) {
      FUN_005d1ee0((&DAT_00ee9b90)[iVar5 * 0x20]);
      (&DAT_00ee9b90)[iVar5 * 0x20] = 0;
    }
    if ((&DAT_00ee9b8c)[iVar5 * 0x20] != 0) {
      FUN_005d3370((&DAT_00ee9b8c)[iVar5 * 0x20]);
      (&DAT_00ee9b8c)[iVar5 * 0x20] = 0;
    }
    if (*piVar3 != 0) {
      FUN_005d3370(*piVar3);
      *piVar3 = 0;
    }
  }
  return -1;
}

