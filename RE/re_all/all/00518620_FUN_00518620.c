
undefined4
FUN_00518620(int *param_1,int param_2,int param_3,uint param_4,undefined4 *param_5,
            undefined4 *param_6,undefined4 param_7,undefined4 param_8,int param_9,int param_10)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint *puVar5;
  ushort *puVar6;
  undefined4 *puVar7;
  char *pcVar8;
  byte *pbVar9;
  int local_8c0;
  int local_8bc;
  int local_8b8;
  int local_8b4;
  int local_8b0;
  int local_8ac;
  int *local_8a8;
  int local_8a4;
  uint local_8a0;
  int local_89c;
  int local_898;
  int local_894;
  int local_890;
  int local_88c;
  byte local_888 [1064];
  int local_460;
  int local_45c;
  undefined4 local_458;
  int local_454;
  undefined4 local_450;
  undefined4 local_44c;
  char local_448 [1064];
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  local_8bc = *param_1;
  local_8b8 = param_1[1];
  local_8b4 = param_1[2];
  local_8b0 = param_1[3];
  local_894 = 0;
  if (DAT_00a37d70 == 0) {
    return 0xffffffff;
  }
  if (param_10 == 0) {
    if (DAT_00cc47d0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_4 < 0) {
      return 0xffffffff;
    }
    if ((param_4 & 0x7c000000) != DAT_00cc47f8) {
      return 0xffffffff;
    }
    if (DAT_00cc4800 <= (int)(param_4 & 0xffff)) {
      return 0xffffffff;
    }
    local_8a8 = *(int **)(DAT_00cc47d4 + (param_4 & 0xffff) * 4);
    if (local_8a8 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*local_8a8 * 0x10000 != (param_4 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (local_8a8[4] != 0) {
      return 0xffffffff;
    }
  }
  else {
    if (DAT_00cc47d0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_4 < 0) {
      return 0xffffffff;
    }
    if ((param_4 & 0x7c000000) != DAT_00cc47f8) {
      return 0xffffffff;
    }
    if (DAT_00cc4800 <= (int)(param_4 & 0xffff)) {
      return 0xffffffff;
    }
    local_8a8 = *(int **)(DAT_00cc47d4 + (param_4 & 0xffff) * 4);
    if (local_8a8 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*local_8a8 * 0x10000 != (param_4 & 0x3ff0000)) {
      return 0xffffffff;
    }
  }
  iVar1 = local_8a8[0x13];
  FUN_0056d380(local_888,0,0x440);
  local_14 = param_5[0x10d];
  local_20 = param_5[0x10a];
  local_1c = param_5[0x10b];
  local_18 = param_5[0x10c];
  local_89c = 0;
  local_8a4 = 0;
  local_10 = param_5[0x10e];
  local_c = param_5[0x10f];
  pcVar8 = local_448;
  for (iVar4 = 0x10a; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)pcVar8 = *param_5;
    param_5 = param_5 + 1;
    pcVar8 = pcVar8 + 4;
  }
  if ((((local_448[0] == '\x01') || (local_448[0] == '\x02')) || (local_448[0] == '\x03')) ||
     ((local_448[0] == '\x04' || (local_448[0] == '\x05')))) {
    local_20 = ((int)(local_20 + 3 + (local_20 + 3 >> 0x1f & 3U)) >> 2) * 4;
    local_1c = ((int)(local_1c + 3 + (local_1c + 3 >> 0x1f & 3U)) >> 2) * 4;
    local_890 = 1;
  }
  else {
    local_890 = 0;
  }
  if (param_6 != (undefined4 *)0x0) {
    local_454 = param_6[0x10d];
    local_460 = param_6[0x10a];
    local_45c = param_6[0x10b];
    local_458 = param_6[0x10c];
    uVar3 = param_6[0x10f];
    puVar7 = param_6;
    pbVar9 = local_888;
    for (iVar4 = 0x10a; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined4 *)pbVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      pbVar9 = pbVar9 + 4;
    }
    local_450 = param_6[0x10e];
    local_44c = uVar3;
    if (((local_448[0] == '\x01') || (local_448[0] == '\x02')) ||
       ((local_448[0] == '\x03' || ((local_448[0] == '\x04' || (local_448[0] == '\x05')))))) {
      local_460 = ((int)(local_460 + 3 + (local_460 + 3 >> 0x1f & 3U)) >> 2) * 4;
      local_45c = ((int)(local_45c + 3 + (local_45c + 3 >> 0x1f & 3U)) >> 2) * 4;
      local_894 = 1;
    }
    else {
      local_894 = 0;
    }
  }
  if ((local_c != 0) != (*(char *)(iVar1 + 9) != '\0')) {
    return 0xffffffff;
  }
  if (local_890 != 0) {
    local_8bc = ((int)(local_8bc + 3 + (local_8bc + 3 >> 0x1f & 3U)) >> 2) * 4;
    local_8b8 = ((int)(local_8b8 + 3 + (local_8b8 + 3 >> 0x1f & 3U)) >> 2) * 4;
    local_8b4 = ((int)(local_8b4 + 3 + (local_8b4 + 3 >> 0x1f & 3U)) >> 2) * 4;
    local_8b0 = ((int)(local_8b0 + 3 + (local_8b0 + 3 >> 0x1f & 3U)) >> 2) * 4;
  }
  local_8c0 = local_8b4 - local_8bc;
  local_8ac = local_8b0 - local_8b8;
  iVar4 = 0;
  if (local_8c0 < 1) {
    return 0;
  }
  if (local_8ac < 1) {
    return 0;
  }
  local_8a0 = 0;
  local_898 = 0;
  local_88c = 0;
  if (*(char *)(iVar1 + 8) == '\0') {
    local_8a0 = (uint)(local_890 != 0);
    if ((local_454 != 0) && (local_894 != 0)) {
      local_898 = 1;
    }
  }
  else {
    if (local_454 == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = (uint)local_888[0];
    }
    FUN_00568a60(iVar1,local_448[0],&local_8a0,uVar2,&local_898);
  }
  if ((local_8a0 == 1) && (iVar4 = FUN_00546d90(local_448,0), iVar4 == 0)) {
    local_89c = 1;
  }
  if ((local_898 == 1) && (local_88c = FUN_00546d90(local_888,0), local_88c == 0)) {
    local_8a4 = 1;
  }
  if ((iVar4 < 0) || (local_88c < 0)) {
    FUN_0056bb10(&DAT_007d54b4);
LAB_00518d1a:
    if (local_89c != 0) {
      FUN_005421c0(local_448);
    }
    if (local_8a4 != 0) {
      FUN_005421c0(local_888);
    }
    return 0xffffffff;
  }
  if (*(char *)(iVar1 + 8) != '\0') {
    iVar1 = FUN_00568a40(&local_8bc,param_2,param_3,param_4,local_448,local_888,param_7,param_8,
                         param_9,param_10);
    if (iVar1 < 0) goto LAB_00518d1a;
    goto LAB_00518cd9;
  }
  iVar4 = local_8ac;
  if (param_9 == 1) {
    if (*(int *)(iVar1 + 0x38) < local_8c0 + param_2) {
      local_8c0 = *(int *)(iVar1 + 0x38) - param_2;
    }
    if (*(int *)(iVar1 + 0x3c) < local_8ac + param_3) {
      iVar4 = *(int *)(iVar1 + 0x3c) - param_3;
    }
    if ((local_8c0 < 1) || (iVar4 < 1)) goto LAB_00518d1a;
    uVar2 = -(uint)(local_454 != 0) & (uint)local_888;
  }
  else {
    if (local_8a8[0x18] < local_8c0 + param_2) {
      local_8c0 = local_8a8[0x18] - param_2;
    }
    if (local_8a8[0x19] < local_8ac + param_3) {
      iVar4 = local_8a8[0x19] - param_3;
    }
    if ((local_8c0 < 1) || (iVar4 < 1)) goto LAB_00518d1a;
    param_3 = local_8a8[0x15] + param_3;
    param_2 = local_8a8[0x14] + param_2;
    uVar2 = -(uint)(local_454 != 0) & (uint)local_888;
  }
  FUN_00581490(local_448,uVar2,iVar1 + 0x34,local_8bc,local_8b8,local_8c0,iVar4,param_2,param_3,
               param_8);
  if ((*(char *)(iVar1 + 0x18) != '\x01') || (*(int *)(*(int *)(iVar1 + 0x48) + 0x3c) == 0))
  goto LAB_00518cd9;
  uVar3 = FUN_00581c90(*(char *)(iVar1 + 0x14) != '\x10',*(undefined1 *)(iVar1 + 10),0,
                       DAT_00a37f50 >> 0x10 & 0xff,DAT_00a37f50 >> 8 & 0xff,DAT_00a37f50 & 0xff,0xff
                      );
  uVar2 = FUN_005440f0(uVar3);
  iVar1 = *(int *)(iVar1 + 0x48);
  iVar4 = 0;
  if (*(int *)(iVar1 + 0x20) == 1) {
    uVar2 = uVar2 & 0xffffff;
    puVar5 = (uint *)(*(int *)(iVar1 + 0x3c) + 8);
    do {
      if ((puVar5[-2] & 0xffffff) == uVar2) break;
      if ((puVar5[-1] & 0xffffff) == uVar2) goto LAB_00518cbf;
      if ((*puVar5 & 0xffffff) == uVar2) goto LAB_00518cc4;
      if ((puVar5[1] & 0xffffff) == uVar2) goto LAB_00518cc9;
      iVar4 = iVar4 + 4;
      puVar5 = puVar5 + 4;
    } while (iVar4 < 0x100);
  }
  else {
    uVar2 = uVar2 & 0xffff;
    puVar6 = (ushort *)(*(int *)(iVar1 + 0x3c) + 4);
    do {
      if (puVar6[-2] == uVar2) break;
      if (puVar6[-1] == uVar2) goto LAB_00518cbf;
      if (*puVar6 == uVar2) goto LAB_00518cc4;
      if (puVar6[1] == uVar2) goto LAB_00518cc9;
      iVar4 = iVar4 + 4;
      puVar6 = puVar6 + 4;
    } while (iVar4 < 0x100);
  }
LAB_00518ccc:
  if (iVar4 == 0x100) {
    iVar4 = 0;
  }
  *(int *)(iVar1 + 0x1c) = iVar4;
LAB_00518cd9:
  if (local_89c != 0) {
    FUN_005421c0(local_448);
  }
  if (local_8a4 != 0) {
    FUN_005421c0(local_888);
  }
  return 0;
LAB_00518cbf:
  iVar4 = iVar4 + 1;
  goto LAB_00518ccc;
LAB_00518cc4:
  iVar4 = iVar4 + 2;
  goto LAB_00518ccc;
LAB_00518cc9:
  iVar4 = iVar4 + 3;
  goto LAB_00518ccc;
}

