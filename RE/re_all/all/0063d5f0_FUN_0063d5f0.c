
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall
FUN_0063d5f0(int param_1,float param_2,float *param_3,float param_4,int param_5,int param_6,
            undefined4 param_7,int param_8)

{
  float fVar1;
  float *pfVar2;
  undefined4 uVar3;
  float10 fVar4;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined1 local_40 [16];
  undefined1 local_30 [16];
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  if ((*(int *)(param_1 + 0x30) == 0) && (*(char *)(param_1 + 0x24) == '\0')) {
    return (float10)_DAT_007d5344;
  }
  local_88 = *(float *)(param_1 + 8);
  local_74 = *(float *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0x30) != 0) {
    local_88 = -((*(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x1c)) / param_2);
    local_74 = *(float *)(param_1 + 0x10);
  }
  local_74 = local_74 * param_2;
  if (*(int *)(param_6 + 0x44) == 0) {
    local_80 = 0.0;
    local_7c = 0.0;
    local_78 = 0.0;
    FUN_005fc530(&local_78,&local_7c,&local_80);
  }
  else {
    pfVar2 = (float *)FUN_0060f480(local_40,*(int *)(param_6 + 0x44) + 0x140,param_6 + 0x10);
    local_60 = *pfVar2;
    local_5c = pfVar2[1];
    local_58 = pfVar2[2];
    local_54 = pfVar2[3];
  }
  if (*(int *)(param_8 + 0x44) == 0) {
    local_78 = 0.0;
    local_7c = 0.0;
    local_80 = 0.0;
    FUN_005fc530(&local_80,&local_7c,&local_78);
  }
  else {
    pfVar2 = (float *)FUN_0060f480(local_40,*(int *)(param_8 + 0x44) + 0x140,param_8 + 0x10);
    local_50 = *pfVar2;
    local_4c = pfVar2[1];
    local_48 = pfVar2[2];
    local_44 = pfVar2[3];
  }
  local_78 = local_58 - local_48;
  local_7c = local_5c - local_4c;
  local_80 = local_60 - local_50;
  FUN_005fc500(&local_80,&local_7c,&local_78);
  fVar1 = (local_88 -
          (local_70 * *param_3 + local_68 * param_3[2] + local_6c * param_3[1]) *
          *(float *)(param_1 + 0x14)) * *(float *)(param_1 + 0x18);
  if ((fVar1 < _DAT_00804520) && (_DAT_008048f4 < fVar1)) {
    return (float10)_DAT_007d5344;
  }
  param_4 = (*(float *)(param_1 + 0x20) + _DAT_00804108) * fVar1 * param_4;
  if (param_4 <= _DAT_007d5344) {
    local_84 = -local_74;
    if (param_4 < local_84) goto LAB_0063d81d;
  }
  else if (local_74 < param_4) {
    local_84 = local_74;
    goto LAB_0063d81d;
  }
  local_84 = param_4;
LAB_0063d81d:
  local_88 = *(float *)(param_1 + 0x34);
  local_84 = local_84 + local_88;
  if ((_DAT_008048f0 < local_84) || (local_84 < _DAT_0080427c)) {
    local_84 = _DAT_007d5344;
  }
  *(float *)(param_1 + 0x34) = local_84;
  local_84 = local_84 - local_88;
  FUN_0060fe40(local_10,param_3,&local_84);
  local_78 = *param_3 * *(float *)(param_5 + 0x120) +
             *(float *)(param_5 + 0x124) * param_3[1] + *(float *)(param_5 + 0x128) * param_3[2];
  fVar4 = (float10)FUN_005fcc30(param_3);
  local_7c = (float)fVar4;
  fVar4 = (float10)FUN_005fcc30(param_3);
  local_80 = (float)fVar4;
  FUN_005fc500(&local_80,&local_7c,&local_78);
  local_88 = local_84;
  local_70 = 0.0;
  local_6c = 0.0;
  local_68 = 0.0;
  local_64 = 0;
  uVar3 = FUN_0060fe40(local_30,&local_70,&local_88);
  FUN_00612f50(uVar3);
  FUN_0060fe40(local_30,param_6 + 0x20,&local_88);
  uVar3 = FUN_005fc560(local_20,local_40,local_30);
  FUN_00612f50(uVar3);
  fVar4 = (float10)FUN_005fcc30(param_3);
  local_78 = (float)fVar4;
  fVar4 = (float10)FUN_005fcc30(param_3);
  local_7c = (float)fVar4;
  fVar4 = (float10)FUN_005fcc30(param_3);
  local_80 = (float)fVar4;
  FUN_005fc500(&local_80,&local_7c,&local_78);
  local_88 = -local_84;
  local_70 = 0.0;
  local_6c = 0.0;
  local_68 = 0.0;
  local_64 = 0;
  uVar3 = FUN_0060fe40(local_20,&local_70,&local_88);
  FUN_00612f50(uVar3);
  FUN_0060fe40(local_40,param_8 + 0x20,&local_88);
  uVar3 = FUN_005fc560(local_20,local_30,local_40);
  FUN_00612f50(uVar3);
  return (float10)local_84;
}

