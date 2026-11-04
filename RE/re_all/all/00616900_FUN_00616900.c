
void __thiscall FUN_00616900(int param_1,float *param_2)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  float10 fVar6;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  undefined1 local_20 [32];
  
  pfVar2 = param_2;
  iVar5 = -1;
  fVar1 = param_2[0x14];
  iVar3 = 0;
  pfVar4 = (float *)(param_1 + 0x54);
  do {
    if (*pfVar4 < fVar1) {
      fVar1 = *pfVar4;
      iVar5 = iVar3;
    }
    iVar3 = iVar3 + 1;
    pfVar4 = pfVar4 + 0x29;
  } while (iVar3 < 4);
  local_50 = 0.0;
  local_54 = 0.0;
  local_58 = 0.0;
  param_2 = (float *)0x0;
  if (iVar5 != 0) {
    local_4c = pfVar2[2] - *(float *)(param_1 + 0xb0);
    local_48 = pfVar2[1] - *(float *)(param_1 + 0xac);
    local_44 = *pfVar2 - *(float *)(param_1 + 0xa8);
    FUN_005fc500(&local_44,&local_48,&local_4c);
    local_44 = *(float *)(param_1 + 0x1f8) - *(float *)(param_1 + 0x154);
    local_48 = *(float *)(param_1 + 500) - *(float *)(param_1 + 0x150);
    local_4c = *(float *)(param_1 + 0x1f0) - *(float *)(param_1 + 0x14c);
    FUN_005fc500(&local_4c,&local_48,&local_44);
    local_44 = local_2c * local_40 - local_3c * local_30;
    local_48 = local_38 * local_30 - local_28 * local_40;
    local_4c = local_3c * local_28 - local_38 * local_2c;
    FUN_005fc500(&local_4c,&local_48,&local_44);
    fVar6 = (float10)FUN_005fcc30(local_20);
    local_50 = (float)fVar6;
  }
  if (iVar5 != 1) {
    local_44 = pfVar2[2] - *(float *)(param_1 + 0xc);
    local_48 = pfVar2[1] - *(float *)(param_1 + 8);
    local_4c = *pfVar2 - *(float *)(param_1 + 4);
    FUN_005fc500(&local_4c,&local_48,&local_44);
    local_44 = *(float *)(param_1 + 0x1f8) - *(float *)(param_1 + 0x154);
    local_48 = *(float *)(param_1 + 500) - *(float *)(param_1 + 0x150);
    local_4c = *(float *)(param_1 + 0x1f0) - *(float *)(param_1 + 0x14c);
    FUN_005fc500(&local_4c,&local_48,&local_44);
    local_44 = local_3c * local_30 - local_2c * local_40;
    local_48 = local_28 * local_40 - local_38 * local_30;
    local_4c = local_2c * local_38 - local_28 * local_3c;
    FUN_005fc500(&local_4c,&local_48,&local_44);
    fVar6 = (float10)FUN_005fcc30(local_20);
    local_54 = (float)fVar6;
  }
  if (iVar5 != 2) {
    local_44 = pfVar2[2] - *(float *)(param_1 + 0xc);
    local_48 = pfVar2[1] - *(float *)(param_1 + 8);
    local_4c = *pfVar2 - *(float *)(param_1 + 4);
    FUN_005fc500(&local_4c,&local_48,&local_44);
    local_44 = *(float *)(param_1 + 0x1f8) - *(float *)(param_1 + 0xb0);
    local_48 = *(float *)(param_1 + 500) - *(float *)(param_1 + 0xac);
    local_4c = *(float *)(param_1 + 0x1f0) - *(float *)(param_1 + 0xa8);
    FUN_005fc500(&local_4c,&local_48,&local_44);
    FUN_006170e0(local_20,&local_30);
    fVar6 = (float10)FUN_005fcc30(local_20);
    local_58 = (float)fVar6;
  }
  if (iVar5 != 3) {
    local_44 = pfVar2[2] - *(float *)(param_1 + 0xc);
    local_48 = pfVar2[1] - *(float *)(param_1 + 8);
    local_4c = *pfVar2 - *(float *)(param_1 + 4);
    FUN_005fc500(&local_4c,&local_48,&local_44);
    FUN_005fc590(&local_30,param_1 + 0x14c,param_1 + 0xa8);
    FUN_006170e0(local_20,&local_30);
    fVar6 = (float10)FUN_005fcc30(local_20);
    param_2 = (float *)(float)fVar6;
  }
  FUN_00617120(&local_50,&local_54,&local_58,&param_2);
  FUN_00617150(local_20);
  FUN_00617180();
  return;
}

