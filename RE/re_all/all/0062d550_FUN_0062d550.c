
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0062d550(float *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,float *param_6)

{
  float *pfVar1;
  float10 fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  float *pfVar6;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar7;
  ushort uVar8;
  bool bVar9;
  float10 fVar10;
  float *pfVar11;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  int local_44;
  int local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  ushort local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_10;
  float local_c;
  float local_8;
  
  local_28 = local_28 & 0xfff0;
  pfVar1 = param_6 + 4;
  *param_6 = *param_1;
  param_6[1] = param_1[1];
  param_6[2] = param_1[2];
  param_6[3] = param_1[3];
  *(ushort *)pfVar1 = *(ushort *)pfVar1 & 0xfff0;
  *(byte *)pfVar1 = *(byte *)pfVar1 | 0xf;
  uVar5 = FUN_005fc590(&local_54,param_4,param_2);
  pfVar11 = &local_84;
  FUN_005fc590(&local_10,param_3,param_2,pfVar11,uVar5);
  FUN_006170e0(pfVar11,uVar5);
  pfVar6 = (float *)FUN_005fc590(&local_54,param_1,param_2);
  pfVar11 = &local_84;
  local_74 = local_84 * *pfVar6 + local_80 * pfVar6[1] + local_7c * pfVar6[2];
  FUN_005fc590(&local_54,param_5,param_2,pfVar11);
  fVar10 = (float10)FUN_005fcc30(pfVar11);
  if ((float10)_DAT_008046f8 <= fVar10 * fVar10) {
    local_70 = 1.4013e-45;
    if ((float10)_DAT_007d5344 <= fVar10 * (float10)local_74) {
      local_70 = 0.0;
    }
  }
  else {
    local_70 = -NAN;
  }
  uVar5 = FUN_005fc590(&local_54,param_5,param_2);
  pfVar11 = &local_84;
  FUN_005fc590(&local_10,param_4,param_2,pfVar11,uVar5);
  FUN_006170e0(pfVar11,uVar5);
  pfVar6 = (float *)FUN_005fc590(&local_54,param_1,param_2);
  pfVar11 = &local_84;
  local_74 = local_84 * *pfVar6 + local_80 * pfVar6[1] + local_7c * pfVar6[2];
  FUN_005fc590(&local_54,param_3,param_2,pfVar11);
  fVar10 = (float10)FUN_005fcc30(pfVar11);
  if ((float10)_DAT_008046f8 <= fVar10 * fVar10) {
    local_3c = 1;
    if ((float10)_DAT_007d5344 <= fVar10 * (float10)local_74) {
      local_3c = 0;
    }
  }
  else {
    local_3c = -1;
  }
  uVar5 = FUN_005fc590(&local_54,param_3,param_2);
  pfVar11 = &local_84;
  FUN_005fc590(&local_10,param_5,param_2,pfVar11,uVar5);
  FUN_006170e0(pfVar11,uVar5);
  pfVar6 = (float *)FUN_005fc590(&local_54,param_1,param_2);
  pfVar11 = &local_84;
  local_74 = local_84 * *pfVar6 + local_80 * pfVar6[1] + local_7c * pfVar6[2];
  FUN_005fc590(&local_54,param_4,param_2,pfVar11);
  fVar10 = (float10)FUN_005fcc30(pfVar11);
  if ((float10)_DAT_008046f8 <= fVar10 * fVar10) {
    local_44 = 1;
    if ((float10)_DAT_007d5344 <= fVar10 * (float10)local_74) {
      local_44 = 0;
    }
  }
  else {
    local_44 = -1;
  }
  uVar5 = FUN_005fc590(&local_54,param_4,param_3);
  pfVar11 = &local_84;
  FUN_005fc590(&local_10,param_5,param_3,pfVar11,uVar5);
  FUN_006170e0(pfVar11,uVar5);
  pfVar6 = (float *)FUN_005fc590(&local_54,param_1,param_3);
  pfVar11 = &local_84;
  local_74 = local_84 * *pfVar6 + local_80 * pfVar6[1] + local_7c * pfVar6[2];
  FUN_005fc590(&local_54,param_2,param_3,pfVar11);
  fVar10 = (float10)FUN_005fcc30(pfVar11);
  if ((float10)_DAT_008046f8 <= fVar10 * fVar10) {
    fVar2 = (float10)local_74;
    local_74 = 1.4013e-45;
    if ((float10)_DAT_007d5344 <= fVar10 * fVar2) {
      local_74 = 0.0;
    }
  }
  else {
    local_74 = -NAN;
  }
  if (((((int)local_70 < 0) || (local_3c < 0)) || (local_44 < 0)) || ((int)local_74 < 0)) {
    *(undefined1 *)(param_6 + 9) = 1;
  }
  else if (((local_70 != 0.0) || (local_3c != 0)) || ((local_44 != 0 || (local_74 != 0.0)))) {
    bVar9 = local_70 != 0.0;
    local_70 = 3.4028235e+38;
    if (bVar9) {
      FUN_0062cc90(param_1,param_2,param_3,param_4,&local_38);
      local_60 = local_30 - param_1[2];
      local_84 = local_38;
      local_80 = local_34;
      local_5c = local_34 - param_1[1];
      local_7c = local_30;
      local_78 = local_2c;
      local_6c = local_38 - *param_1;
      FUN_005fc500(&local_6c,&local_5c,&local_60);
      local_64 = local_7c - param_1[2];
      local_68 = local_80 - param_1[1];
      local_58 = local_84 - *param_1;
      FUN_005fc500(&local_58,&local_68,&local_64);
      fVar3 = local_c * local_50 + local_8 * local_4c + local_10 * local_54;
      if (fVar3 < _DAT_007ff1ec) {
        *param_6 = local_84;
        param_6[1] = local_80;
        param_6[2] = local_7c;
        param_6[3] = local_78;
        *(ushort *)pfVar1 = *(ushort *)pfVar1 & 0xfff0;
        param_6[8] = 0.0;
        uVar8 = (byte)((byte)*(ushort *)pfVar1 ^ (byte)local_28) & 1 ^ *(ushort *)pfVar1;
        param_6[5] = local_24;
        uVar8 = (byte)((byte)uVar8 ^ (byte)local_28) & 2 ^ uVar8;
        param_6[6] = local_20;
        param_6[7] = local_1c;
        *(ushort *)pfVar1 = (byte)((byte)uVar8 ^ (byte)local_28) & 4 ^ uVar8;
        local_70 = fVar3;
      }
    }
    if (local_3c != 0) {
      FUN_0062cc90(param_1,param_2,param_4,param_5,&local_38);
      local_58 = local_30 - param_1[2];
      local_84 = local_38;
      local_80 = local_34;
      local_68 = local_34 - param_1[1];
      local_7c = local_30;
      local_78 = local_2c;
      local_64 = local_38 - *param_1;
      FUN_005fc500(&local_64,&local_68,&local_58);
      local_6c = local_7c - param_1[2];
      local_5c = local_80 - param_1[1];
      local_60 = local_84 - *param_1;
      FUN_005fc500(&local_60,&local_5c,&local_6c);
      fVar3 = local_50 * local_c + local_4c * local_8 + local_54 * local_10;
      if (fVar3 < local_70) {
        *param_6 = local_84;
        param_6[1] = local_80;
        param_6[2] = local_7c;
        param_6[3] = local_78;
        *(ushort *)pfVar1 = *(ushort *)pfVar1 & 0xfff0;
        param_6[5] = local_24;
        param_6[7] = local_20;
        param_6[6] = 0.0;
        param_6[8] = local_1c;
        *(ushort *)pfVar1 = *(ushort *)pfVar1 & 0xfff2 ^ local_28 & 1 | (local_28 & 6) << 1;
        local_70 = fVar3;
      }
    }
    if (local_44 != 0) {
      FUN_0062cc90(param_1,param_2,param_5,param_3,&local_38);
      fVar4 = local_38;
      local_58 = local_30 - param_1[2];
      local_80 = local_34;
      local_7c = local_30;
      local_68 = local_34 - param_1[1];
      local_78 = local_2c;
      local_64 = local_38 - *param_1;
      local_84 = local_38;
      FUN_005fc500(&local_64,&local_68,&local_58);
      local_6c = local_7c - param_1[2];
      local_5c = local_80 - param_1[1];
      local_60 = local_84 - *param_1;
      FUN_005fc500(&local_60,&local_5c,&local_6c);
      fVar3 = local_50 * local_c + local_4c * local_8 + local_54 * local_10;
      if (fVar3 < local_70) {
        *param_6 = fVar4;
        param_6[1] = local_80;
        param_6[2] = local_7c;
        param_6[3] = local_78;
        *(ushort *)pfVar1 = *(ushort *)pfVar1 & 0xfff0;
        param_6[5] = local_24;
        param_6[7] = 0.0;
        param_6[6] = local_1c;
        param_6[8] = local_20;
        *(ushort *)pfVar1 =
             *(ushort *)pfVar1 & 0xfff4 ^ local_28 & 1 | local_28 >> 1 & 2 | (local_28 & 2) << 2;
        local_70 = fVar3;
      }
    }
    uVar7 = 0;
    if (local_74 != 0.0) {
      FUN_0062cc90(param_1,param_3,param_5,param_4,&local_38);
      local_58 = local_30 - param_1[2];
      local_80 = local_34;
      local_7c = local_30;
      local_68 = local_34 - param_1[1];
      local_78 = local_2c;
      local_64 = local_38 - *param_1;
      local_84 = local_38;
      FUN_005fc500(&local_64,&local_68,&local_58);
      local_6c = local_7c - param_1[2];
      local_5c = local_80 - param_1[1];
      local_60 = local_84 - *param_1;
      FUN_005fc500(&local_60,&local_5c,&local_6c);
      fVar10 = (float10)FUN_005fcc30(&local_54);
      uVar7 = extraout_var;
      if (fVar10 < (float10)local_70) {
        *param_6 = local_38;
        param_6[1] = local_80;
        param_6[2] = local_7c;
        param_6[3] = local_78;
        FUN_0062deb0();
        *(ushort *)pfVar1 =
             ((local_28 & 1) << 1 | *(ushort *)pfVar1 & 0xfff1) ^ local_28 & 4 | (local_28 & 2) << 2
        ;
        FUN_0062dec0(0,local_24,local_1c,local_20);
        uVar7 = extraout_var_00;
      }
    }
    return CONCAT31((int3)(CONCAT22(uVar7,*(ushort *)pfVar1) >> 8),1);
  }
  return (uint)local_70 & 0xffffff00;
}

