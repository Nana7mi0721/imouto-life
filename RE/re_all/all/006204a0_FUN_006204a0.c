
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_006204a0(undefined4 param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  float10 fVar12;
  float *pfVar13;
  float local_c0;
  int local_bc;
  int local_b8;
  undefined1 local_b4 [4];
  int local_b0 [3];
  undefined1 local_a4;
  undefined1 local_a0 [4];
  undefined4 local_9c;
  int local_98;
  undefined4 local_94;
  undefined1 local_90;
  float local_8c;
  float local_88 [2];
  int local_80 [8];
  float local_60;
  float local_5c;
  float local_58;
  float local_50;
  float local_4c;
  float local_48;
  undefined1 local_40 [16];
  int local_30 [4];
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  if ((DAT_00f3f7d0 & 1) == 0) {
    DAT_00f3f7d0 = DAT_00f3f7d0 | 1;
    _DAT_00f3f7d8 = 0x3f800000;
    _DAT_00f3f7dc = 0;
    _DAT_00f3f7e0 = 0;
    _DAT_00f3f7e4 = 0;
    _DAT_00f3f7e8 = 0;
    _DAT_00f3f7ec = 0x3f800000;
    _DAT_00f3f7f0 = 0;
    _DAT_00f3f7f4 = 0;
    _DAT_00f3f7f8 = 0;
    _DAT_00f3f7fc = 0;
    _DAT_00f3f800 = 0x3f800000;
    _DAT_00f3f804 = 0;
    _atexit((_func_4879 *)&DAT_00620ad0);
  }
  iVar7 = *(int *)(param_2 + 4);
  if (iVar7 < 2) {
    return (int *)**(undefined4 **)(param_2 + 0xc);
  }
  if (iVar7 <= param_3) {
    FUN_006201c0(param_1,param_2);
    return (int *)**(undefined4 **)(param_2 + 0xc);
  }
  piVar9 = (int *)**(undefined4 **)(param_2 + 0xc);
  piVar11 = local_80;
  for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar11 = *piVar9;
    piVar9 = piVar9 + 1;
    piVar11 = piVar11 + 1;
  }
  iVar6 = 1;
  if (1 < iVar7) {
    do {
      FUN_006219f0(local_80,*(undefined4 *)(*(int *)(param_2 + 0xc) + iVar6 * 4),local_80);
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar7);
  }
  piVar9 = local_80;
  piVar11 = local_30;
  for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar11 = *piVar9;
    piVar9 = piVar9 + 1;
    piVar11 = piVar11 + 1;
  }
  uVar2 = FUN_0060f480(local_40,local_30,local_20);
  local_bc = 0x3f000000;
  FUN_0060fe40(&local_60,uVar2,&local_bc);
  iVar7 = 2;
  do {
    FUN_00614ef0();
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  local_bc = *(int *)(param_2 + 4);
  iVar7 = 0;
  local_b8 = -1;
  local_80[0] = 0;
  local_80[1] = 0;
  local_80[2] = 0;
  local_80[3] = 0;
  local_80[4] = 0;
  local_80[5] = 0;
  if (0 < local_bc) {
    do {
      iVar6 = *(int *)(*(int *)(param_2 + 0xc) + iVar7 * 4);
      uVar2 = FUN_0060f480(local_10,iVar6,iVar6 + 0x10);
      local_88[1] = 0.5;
      FUN_0060fe40(&local_50,uVar2,local_88 + 1);
      local_8c = local_48 - local_58;
      local_88[0] = local_4c - local_5c;
      local_c0 = local_50 - local_60;
      FUN_005fc500(&local_c0,local_88,&local_8c);
      iVar6 = 0;
      puVar8 = &DAT_00f3f7d8;
      do {
        fVar12 = (float10)FUN_005fcc30(puVar8);
        iVar3 = (uint)((float10)_DAT_007d5344 < fVar12) + iVar6;
        puVar8 = puVar8 + 0x10;
        iVar6 = iVar6 + 2;
        local_80[iVar3] = local_80[iVar3] + 1;
      } while ((int)puVar8 < 0xf3f808);
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(param_2 + 4));
  }
  iVar7 = 0;
  piVar9 = local_80;
  do {
    if ((0 < *piVar9) && (0 < piVar9[1])) {
      local_c0 = (float)(*piVar9 - piVar9[1]);
      iVar6 = __ftol();
      if (iVar6 < local_bc) {
        local_bc = iVar6;
        local_b8 = iVar7;
      }
    }
    iVar7 = iVar7 + 1;
    piVar9 = piVar9 + 2;
  } while (iVar7 < 3);
  if (local_b8 < 0) {
    iVar7 = *(int *)(param_2 + 4) / 2 + 1;
    if (local_b0[1] < iVar7) {
      uVar2 = FUN_00621de0(iVar7);
      FUN_00621db0(0,local_b0[0],uVar2);
      FUN_0060b970(0,local_b0[0]);
      FUN_007932e0();
      local_a4 = 1;
      local_b0[2] = uVar2;
      local_b0[1] = iVar7;
    }
    iVar7 = *(int *)(param_2 + 4) / 2;
    if (local_98 < iVar7) {
      uVar2 = FUN_00621de0(iVar7);
      FUN_00621db0(0,local_9c,uVar2);
      FUN_0060b970(0,local_9c);
      FUN_007932e0();
      local_90 = 1;
      local_94 = uVar2;
      local_98 = iVar7;
    }
    iVar7 = *(int *)(param_2 + 4);
    uVar10 = 0;
    if (0 < iVar7) {
      do {
        iVar6 = *(int *)(param_2 + 0xc);
        uVar4 = uVar10 & 1;
        iVar3 = local_b0[uVar4 * 5];
        if (iVar3 == local_b0[uVar4 * 5 + 1]) {
          if (iVar3 == 0) {
            iVar3 = 1;
          }
          else {
            iVar3 = iVar3 * 2;
          }
          FUN_0078e010(iVar3);
        }
        puVar1 = (undefined4 *)(local_b0[uVar4 * 5 + 2] + local_b0[uVar4 * 5] * 4);
        if (puVar1 != (undefined4 *)0x0) {
          *puVar1 = *(undefined4 *)(iVar6 + uVar10 * 4);
        }
        uVar10 = uVar10 + 1;
        local_b0[uVar4 * 5] = local_b0[uVar4 * 5] + 1;
      } while ((int)uVar10 < iVar7);
    }
  }
  else {
    iVar7 = local_80[local_b8 * 2];
    if (local_b0[1] < iVar7) {
      if (iVar7 == 0) {
        local_b0[2] = 0;
      }
      else {
        local_b0[2] = FUN_00646b30(iVar7 * 4,0x10);
      }
      FUN_00621db0(0,local_b0[0],local_b0[2]);
      FUN_0060b970(0,local_b0[0]);
      FUN_007932e0();
      local_a4 = 1;
      local_b0[1] = iVar7;
    }
    iVar7 = local_80[local_b8 * 2 + 1];
    if (local_98 < iVar7) {
      if (iVar7 == 0) {
        local_94 = 0;
      }
      else {
        local_94 = FUN_00646b30(iVar7 * 4,0x10);
      }
      FUN_00621db0(0,local_9c,local_94);
      FUN_0060b970(0,local_9c);
      FUN_007932e0();
      local_90 = 1;
      local_98 = iVar7;
    }
    local_c0 = 0.0;
    FUN_00614e30(0,&local_c0);
    iVar6 = 0;
    local_c0 = 0.0;
    FUN_00614e30(0,&local_c0);
    iVar7 = *(int *)(param_2 + 4);
    if (0 < iVar7) {
      do {
        pfVar13 = &local_60;
        uVar2 = FUN_00621a50(local_10);
        uVar2 = FUN_005fc590(local_40,uVar2,pfVar13);
        fVar12 = (float10)FUN_005fcc30(uVar2);
        if ((float10)_DAT_007d5344 <= fVar12) {
          iVar3 = *(int *)(param_2 + 0xc);
        }
        else {
          iVar3 = *(int *)(param_2 + 0xc);
        }
        FUN_00621c70(iVar6 * 4 + iVar3);
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar7);
    }
  }
  piVar5 = (int *)FUN_00620a90(param_1,0,0);
  piVar9 = local_30;
  piVar11 = piVar5;
  for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar11 = *piVar9;
    piVar9 = piVar9 + 1;
    piVar11 = piVar11 + 1;
  }
  iVar7 = FUN_006204a0(param_1,local_b4,param_3);
  piVar5[9] = iVar7;
  iVar7 = FUN_006204a0(param_1,local_a0,param_3);
  piVar5[10] = iVar7;
  *(int **)(piVar5[9] + 0x20) = piVar5;
  *(int **)(piVar5[10] + 0x20) = piVar5;
  FUN_00614830(local_b4,0x14,2,FUN_0061ea60);
  return piVar5;
}

