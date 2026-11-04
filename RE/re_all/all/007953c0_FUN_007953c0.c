
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_007953c0(int param_1,int *param_2,float *param_3,float *param_4,float *param_5,float *param_6)

{
  float *pfVar1;
  float fVar2;
  bool bVar3;
  char cVar4;
  float *pfVar5;
  float10 fVar6;
  float local_94;
  float local_90;
  int local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  int local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  int local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_10;
  float local_c;
  float local_8;
  
  pfVar5 = *(float **)(param_1 + 0x60);
  local_8c = 0;
  local_68 = 0;
  local_78 = *param_3;
  local_74 = param_3[1];
  local_70 = param_3[2];
  local_6c = param_3[3];
  local_88 = *param_3;
  local_84 = param_3[1];
  local_80 = param_3[2];
  local_7c = param_3[3];
  if (*param_4 < local_78) {
    local_78 = *param_4;
  }
  if (param_4[1] < local_74) {
    local_74 = param_4[1];
  }
  if (param_4[2] < local_70) {
    local_70 = param_4[2];
  }
  if (local_88 < *param_4) {
    local_88 = *param_4;
  }
  if (local_84 < param_4[1]) {
    local_84 = param_4[1];
  }
  if (local_80 < param_4[2]) {
    local_80 = param_4[2];
  }
  local_78 = local_78 + *param_5;
  local_74 = local_74 + param_5[1];
  local_70 = local_70 + param_5[2];
  local_88 = local_88 + *param_6;
  local_84 = local_84 + param_6[1];
  local_80 = local_80 + param_6[2];
  local_64 = param_4[2] - param_3[2];
  local_90 = param_4[1] - param_3[1];
  local_94 = *param_4 - *param_3;
  local_50 = param_1;
  FUN_005fc500(&local_94,&local_90,&local_64);
  fVar6 = (float10)FUN_005fcc30(&local_60);
  local_94 = (float)((float10)_DAT_00804108 / SQRT(fVar6));
  FUN_0061a860(&local_94);
  local_94 = param_4[2] - param_3[2];
  local_90 = param_4[1] - param_3[1];
  local_64 = *param_4 - *param_3;
  FUN_005fc500(&local_64,&local_90,&local_94);
  local_94 = local_10 * local_60 + local_5c * local_c + local_58 * local_8;
  if (local_60 == _DAT_007d5344) {
    local_20 = 1e+18;
  }
  else {
    local_20 = _DAT_00804108 / local_60;
  }
  if (local_5c == _DAT_007d5344) {
    local_1c = _DAT_008048f0;
  }
  else {
    local_1c = _DAT_00804108 / local_5c;
  }
  if (local_58 == _DAT_007d5344) {
    local_18 = _DAT_008048f0;
  }
  else {
    local_18 = _DAT_00804108 / local_58;
  }
  local_2c = (uint)(local_20 < (float)_DAT_007d0a60);
  local_28 = (uint)(local_1c < (float)_DAT_007d0a60);
  local_24 = (uint)(local_18 < (float)_DAT_007d0a60);
  if (0 < *(int *)(local_50 + 0x38)) {
    do {
      local_90 = 1.0;
      local_68 = local_68 + 1;
      local_40 = pfVar5[3];
      local_4c = *pfVar5 + *param_5;
      local_30 = pfVar5[7];
      local_48 = pfVar5[1] + param_5[1];
      bVar3 = true;
      local_44 = pfVar5[2] + param_5[2];
      local_3c = pfVar5[4] + *param_6;
      local_38 = pfVar5[5] + param_6[1];
      local_34 = pfVar5[6] + param_6[2];
      if ((pfVar5[4] < local_78) || (local_88 < *pfVar5)) {
        bVar3 = false;
      }
      if ((pfVar5[6] < local_70) || (local_80 < pfVar5[2])) {
        bVar3 = false;
      }
      if (((pfVar5[5] < local_74) || (local_84 < pfVar5[1])) || (!bVar3)) {
        cVar4 = '\0';
      }
      else {
        cVar4 = FUN_00614950(param_3,&local_20,&local_2c,&local_4c,&local_90,0,local_94);
      }
      fVar2 = pfVar5[8];
      if (fVar2 == -NAN) {
        if (cVar4 != '\0') {
          (**(code **)(*param_2 + 4))(pfVar5[9],pfVar5[10]);
          goto LAB_0079580b;
        }
LAB_0079580f:
        if (fVar2 == -NAN) goto LAB_00795829;
        pfVar1 = pfVar5 + 8;
        pfVar5 = pfVar5 + (int)*pfVar1 * 0x10;
        local_8c = local_8c + (int)*pfVar1;
      }
      else {
LAB_0079580b:
        if (cVar4 == '\0') goto LAB_0079580f;
LAB_00795829:
        pfVar5 = pfVar5 + 0x10;
        local_8c = local_8c + 1;
      }
    } while (local_8c < *(int *)(local_50 + 0x38));
  }
  if (DAT_00f488d8 < local_68) {
    DAT_00f488d8 = local_68;
  }
  return;
}

