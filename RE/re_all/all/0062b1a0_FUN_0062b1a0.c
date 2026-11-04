
/* WARNING: Removing unreachable block (ram,0x0062b636) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0062b1a0(int param_1,float *param_2,float *param_3,float *param_4,float *param_5,
            undefined4 param_6,float param_7)

{
  char cVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float unaff_ESI;
  float *pfVar5;
  int iVar6;
  float10 fVar7;
  float local_90;
  undefined4 uStack_8c;
  float local_88;
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
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  int local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [12];
  undefined1 auStack_10 [16];
  
  iVar2 = *(int *)(param_1 + 8);
  pfVar5 = (float *)(iVar2 + 0x34);
  local_4c = *(float *)(*(int *)(param_1 + 4) + 0x1c) * *(float *)(*(int *)(param_1 + 4) + 0xc);
  local_48 = *(float *)(iVar2 + 0x5c) - *(float *)(iVar2 + 0x3c);
  local_60 = *(float *)(iVar2 + 0x58) - *(float *)(iVar2 + 0x38);
  local_34 = *(float *)(iVar2 + 0x54) - *pfVar5;
  local_38 = param_1;
  FUN_005fc500(&local_34,&local_60,&local_48);
  local_40 = *(float *)(iVar2 + 0x4c) - *(float *)(iVar2 + 0x3c);
  local_3c = *(float *)(iVar2 + 0x48) - *(float *)(iVar2 + 0x38);
  local_44 = *(float *)(iVar2 + 0x44) - *pfVar5;
  FUN_005fc500(&local_44,&local_3c,&local_40);
  local_78 = local_6c * local_88 - local_84 * local_70;
  local_74 = local_80 * local_70 - local_68 * local_88;
  local_90 = local_68 * local_84 - local_80 * local_6c;
  FUN_005fc500(&local_90,&local_74,&local_78);
  fVar7 = (float10)FUN_005fcc30(&local_5c);
  local_90 = (float)((float10)_DAT_00804108 / SQRT(fVar7));
  FUN_0061a860(&local_90);
  local_90 = param_2[2] - *(float *)(iVar2 + 0x3c);
  local_74 = param_2[1] - *(float *)(iVar2 + 0x38);
  local_78 = *param_2 - *pfVar5;
  FUN_005fc500(&local_78,&local_74,&local_90);
  local_60 = local_5c * local_30 + local_2c * local_58 + local_28 * local_54;
  if (local_60 < _DAT_007d5344) {
    local_60 = local_60 * _DAT_007d5340;
    local_5c = local_5c * _DAT_007d5340;
    local_58 = local_58 * _DAT_007d5340;
    local_54 = local_54 * _DAT_007d5340;
  }
  local_48 = local_4c + param_7;
  if (local_4c <= local_60) {
    return 0;
  }
  uStack_8c = (float)((uint)uStack_8c & 0xffffff);
  if (local_48 <= local_60) {
    return 0;
  }
  local_70 = *param_2;
  local_6c = param_2[1];
  local_68 = param_2[2];
  local_64 = param_2[3];
  local_84 = local_58;
  local_80 = local_54;
  local_88 = local_5c;
  local_7c = local_50;
  cVar1 = FUN_0062b680(pfVar5,&local_88,&local_70);
  if (cVar1 == '\0') {
    iVar6 = 0;
    local_90 = local_48 * local_48;
    iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x48))();
    if (iVar2 < 1) {
      return 0;
    }
    fVar3 = local_84;
    fVar4 = local_88;
    do {
      (**(code **)(**(int **)(local_38 + 8) + 0x4c))(iVar6,auStack_10,auStack_20);
      fVar7 = (float10)FUN_0062af40(auStack_1c,&local_2c,param_2,&local_7c);
      if (fVar7 < (float10)unaff_ESI) {
        uStack_8c = local_74;
        local_88 = local_70;
        fVar3 = local_78;
        fVar4 = local_7c;
      }
      iVar6 = iVar6 + 1;
      iVar2 = (**(code **)(**(int **)((int)local_44 + 8) + 0x48))();
    } while (iVar6 < iVar2);
    local_88 = fVar4;
    local_84 = fVar3;
    if (uStack_8c._3_1_ == '\0') {
      return 0;
    }
  }
  else {
    local_90 = local_54 * local_60;
    local_74 = local_58 * local_60;
    local_78 = local_5c * local_60;
    FUN_005fc500(&local_78,&local_74,&local_90);
    local_44 = param_2[2] - local_80;
    local_3c = param_2[1] - local_84;
    local_40 = *param_2 - local_88;
    FUN_005fc500(&local_40,&local_3c,&local_44);
    local_88 = local_70;
    local_84 = local_6c;
    local_80 = local_68;
    local_7c = local_64;
  }
  fVar4 = local_84;
  fVar3 = local_88;
  local_90 = param_2[2] - local_80;
  local_74 = param_2[1] - local_84;
  local_78 = *param_2 - local_88;
  FUN_005fc500(&local_78,&local_74,&local_90);
  fVar7 = (float10)FUN_005fcc30(&local_70);
  local_90 = (float)fVar7;
  if ((float10)local_4c * (float10)local_4c <= fVar7) {
    return 0;
  }
  *param_4 = local_70;
  param_4[1] = local_6c;
  param_4[2] = local_68;
  param_4[3] = local_64;
  fVar7 = (float10)FUN_005fcc30(param_4);
  fVar7 = (float10)_DAT_00804108 / SQRT(fVar7);
  *param_4 = (float)(fVar7 * (float10)*param_4);
  param_4[1] = (float)(fVar7 * (float10)param_4[1]);
  param_4[2] = (float)(fVar7 * (float10)param_4[2]);
  *param_3 = fVar3;
  param_3[1] = fVar4;
  param_3[2] = local_80;
  param_3[3] = local_7c;
  *param_5 = -(local_4c - SQRT(local_90));
  return 1;
}

