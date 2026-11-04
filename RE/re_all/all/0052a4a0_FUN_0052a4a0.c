
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0052a4a0(uint param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar6;
  uint uVar7;
  undefined8 uVar5;
  undefined8 uVar8;
  float local_84;
  int *local_80;
  int *local_7c;
  int *local_78;
  int *local_74;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  float local_54;
  float local_50;
  float local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [64];
  
  local_78 = (int *)0x0;
  local_7c = (int *)0x0;
  local_80 = (int *)0x0;
  if (DAT_00a37d70 == 0) {
    return 0xffffffff;
  }
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if (DAT_00a38108 == 0) {
    local_78 = (int *)0x0;
    if (DAT_00cc47d0 != 0) {
      if ((((-1 < (int)param_1) && ((param_1 & 0x7c000000) == DAT_00cc47f8)) &&
          ((int)(param_1 & 0xffff) < DAT_00cc4800)) &&
         (local_78 = *(int **)(DAT_00cc47d4 + (param_1 & 0xffff) * 4), local_78 != (int *)0x0)) {
        if (*local_78 * 0x10000 != (param_1 & 0x3ff0000)) {
          return 0xffffffff;
        }
        if (local_78[4] != 0) {
          return 0xffffffff;
        }
        if (*(char *)(local_78[0x13] + 0xb) == '\0') {
          return 0xffffffff;
        }
      }
      goto LAB_0052a5b8;
    }
LAB_0052a601:
    local_74 = (int *)0x0;
    if (((((DAT_00cc79c0 == 0) || ((int)DAT_00a38120 < 0)) ||
         ((DAT_00a38120 & 0x7c000000) != DAT_00cc79e8)) ||
        ((DAT_00cc79f0 <= (int)(DAT_00a38120 & 0xffff) ||
         (local_80 = *(int **)(DAT_00cc79c4 + (DAT_00a38120 & 0xffff) * 4), local_80 == (int *)0x0))
        )) || ((*local_80 * 0x10000 != (DAT_00a38120 & 0x3ff0000) || (local_80[4] != 0)))) {
      local_80 = (int *)0x0;
    }
  }
  else {
    if (DAT_00cc79c0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_1 < 0) {
      return 0xffffffff;
    }
    if ((param_1 & 0x7c000000) != DAT_00cc79e8) {
      return 0xffffffff;
    }
    if (DAT_00cc79f0 <= (int)(param_1 & 0xffff)) {
      return 0xffffffff;
    }
    local_7c = *(int **)(DAT_00cc79c4 + (param_1 & 0xffff) * 4);
    if (local_7c == (int *)0x0) {
      return 0xffffffff;
    }
    if (*local_7c * 0x10000 != (param_1 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (local_7c[4] != 0) {
      return 0xffffffff;
    }
LAB_0052a5b8:
    if (((((DAT_00cc47d0 == 0) || ((int)DAT_00a38120 < 0)) ||
         (((DAT_00a38120 & 0x7c000000) != DAT_00cc47f8 ||
          ((DAT_00cc4800 <= (int)(DAT_00a38120 & 0xffff) ||
           (local_74 = *(int **)(DAT_00cc47d4 + (DAT_00a38120 & 0xffff) * 4), local_74 == (int *)0x0
           )))))) || (*local_74 * 0x10000 != (DAT_00a38120 & 0x3ff0000))) || (local_74[4] != 0))
    goto LAB_0052a601;
  }
  if ((((param_1 != 0xfffffffc) && (param_1 != 0xfffffffe)) &&
      ((param_1 != 0xfffffffd && ((param_1 != 0xfffffff0 && (local_7c == (int *)0x0)))))) &&
     (((int)param_1 < 0 ||
      (((param_1 & 0x7c000000) != 0x4000000 || (iVar4 = FUN_00580500(), iVar4 == 0)))))) {
    return 0xffffffff;
  }
  if (DAT_00a38120 == 0xfffffffc) {
    if (DAT_00a37d78 == 1) {
      FUN_00567e80();
    }
    FUN_00522bc0();
  }
  if (DAT_00a3810c != 0) {
    FUN_0052b930();
  }
  local_44 = DAT_00ca39f0;
  FUN_0057b060();
  if ((DAT_00a38108 == 0) && (DAT_00ca39ec != 0)) {
    uVar5 = CONCAT44(&local_64,&local_84);
    uVar6 = param_1;
    FUN_00515880();
    FUN_0057ab80(1,local_84,local_64,uVar6,uVar5);
  }
  uVar2 = DAT_00a38160;
  uVar1 = DAT_00a38140;
  uVar6 = DAT_00a38120;
  DAT_00a38120 = param_1;
  DAT_00a38140 = 0;
  DAT_00a38160 = 0;
  FUN_00515880();
  FUN_00567d60();
  if (DAT_00a37d78 == 0) {
    if (DAT_00ca39f4 == 0) {
      if (local_78 == (int *)0x0) {
        DAT_00a37e58 = (int *)&DAT_00a37df8;
      }
      else {
        if (*(int *)(local_78[0x27] + 0x2c) == 1) {
          return 0xffffffff;
        }
        DAT_00a37e58 = local_78 + 0x22;
      }
    }
    else {
      DAT_00a37e58 = &DAT_00ca3a00;
    }
  }
  else {
    FUN_00567dc0(param_1,uVar1,uVar2,local_78,local_74,local_7c,local_80);
  }
  local_80 = (int *)0x0;
  local_7c = (int *)0x0;
  uVar5 = CONCAT44(&local_7c,&local_80);
  uVar7 = param_1;
  FUN_00515880();
  FUN_00515880(uVar6,&local_64,&local_84,uVar7,uVar5);
  uVar3 = DAT_00a3818c;
  uVar2 = DAT_00a38188;
  uVar1 = DAT_00a38184;
  if (DAT_00a38590 == 0) {
    uVar8 = CONCAT44(local_7c,local_80);
    uVar5 = 0;
  }
  else {
    if (DAT_00a38108 != 0) {
      local_48 = DAT_00a38190;
      FUN_005217e0(0,0,local_80,local_7c);
      DAT_00a38190 = local_48;
      DAT_00a38184 = uVar1;
      DAT_00a38188 = uVar2;
      DAT_00a3818c = uVar3;
      goto LAB_0052a879;
    }
    uVar8 = CONCAT44(DAT_00a38190,DAT_00a3818c);
    uVar5 = CONCAT44(DAT_00a38188,DAT_00a38184);
  }
  FUN_005217e0(uVar5,uVar8);
LAB_0052a879:
  if (DAT_00a38590 == 0) {
    _DAT_00a384f8 = 0x3ff0000000000000;
    FUN_00524b70();
    FUN_00585060();
    FUN_00521b80(local_40);
    _DAT_00a3d350 = (double)DAT_00a381b4 * _DAT_00804a60;
    _DAT_00a3d358 = (double)DAT_00a381b8 * _DAT_00804a60;
    FUN_005221c0(_DAT_00a3d350,_DAT_00a3d358);
    local_84 = (float)(DAT_00a381b8 / 2);
    local_74 = (int *)((float)(int)local_84 / (float)_DAT_007d5908);
    local_70 = (float)DAT_00a381b4 * (float)_DAT_00804a60;
    local_6c = (float)_DAT_00804a60 * (float)DAT_00a381b8;
    local_68 = -(float)local_74;
    local_4c = local_68 + (float)_DAT_00802e18;
    local_60 = 0;
    local_5c = 0x3f800000;
    local_58 = 0;
    local_54 = local_70;
    local_50 = local_6c;
    FUN_005277c0(local_70,local_6c,local_68,local_70,local_6c,local_4c,0,0x3f800000,0);
    _DAT_00a38500 = _DAT_007d5900;
    DAT_00a384e0 = 0;
    FUN_00524b70();
    local_84 = (float)local_74 * (float)_DAT_00829898 + (float)_DAT_007d0a60;
    FUN_00528e90(local_84,(float)_DAT_007d58f8 + (float)local_74);
  }
  FUN_0057b060();
  if (DAT_00a38108 != 0) {
    DAT_00a38108 = 0;
    DAT_00a3810c = 1;
    DAT_00a38110 = param_1;
  }
  FUN_00567de0();
  return 0;
}

