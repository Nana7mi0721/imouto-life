
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005263e0(float param_1,float param_2,float param_3,float param_4,double param_5,
                 double param_6,double param_7,undefined4 param_8,int param_9,int param_10)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int unaff_EDI;
  int local_58;
  double local_50;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_10;
  float local_8;
  
  FUN_00515880();
  fVar1 = (float)param_7;
  if (fVar1 == 0.0) {
    fVar1 = (float)param_5;
    fVar2 = (float)param_6;
    if ((fVar1 == 1.0) && (fVar2 == 1.0)) {
      FUN_005207b0(param_1 - param_3,param_2 - param_4);
      return;
    }
    param_1 = param_1 - fVar1 * param_3;
    param_2 = param_2 - fVar2 * param_4;
    local_28 = param_1 + (float)local_58 * fVar1;
    local_24 = param_2 + fVar2 * (float)(int)local_50._0_4_;
    local_30 = param_1;
    if (unaff_EDI != 0) {
      local_30 = local_28;
      local_28 = param_1;
    }
    local_2c = param_2;
    if (param_9 != 0) {
      local_2c = local_24;
      local_24 = param_2;
    }
    FUN_0051f460(local_30,local_2c,local_28,local_24);
    return;
  }
  local_1c = (float)param_5;
  local_8 = (float)param_6;
  if ((local_1c == 1.0) && (local_8 == 1.0)) {
    param_3 = (float)local_58 * (float)_DAT_00804a60 - param_3;
    local_44 = (float)_DAT_00804a60 * (float)(int)local_50._0_4_ - param_4;
    local_50 = (double)CONCAT44(local_50._4_4_,fVar1);
    FUN_0056d4d0(fVar1,&local_48,&local_50);
    fVar1 = local_44 * local_48;
    local_44 = local_50._0_4_ * local_44 + param_3 * local_48;
    FUN_0051ff40((param_3 * local_50._0_4_ - fVar1) + param_1,local_44 + param_2,0x3ff0000000000000,
                 param_7);
    return;
  }
  local_20 = local_1c * -param_3;
  local_10 = local_8 * -param_4;
  local_1c = ((float)local_58 - param_3) * local_1c;
  local_8 = local_8 * ((float)(int)local_50._0_4_ - param_4);
  FUN_0056d4d0(fVar1,&local_48,&local_44);
  local_28 = param_1 + (local_20 * local_44 - local_48 * local_10);
  fVar1 = local_48 * local_20;
  local_50 = (double)fVar1;
  local_38 = param_2 + local_44 * local_10 + fVar1;
  local_24 = param_1 + (local_44 * local_1c - local_48 * local_10);
  fVar2 = local_48 * local_1c + local_44 * local_10 + param_2;
  fVar3 = (local_20 * local_44 - local_8 * local_48) + param_1;
  fVar1 = local_44 * local_8 + fVar1 + param_2;
  param_1 = (local_44 * local_1c - local_8 * local_48) + param_1;
  local_34 = local_44 * local_8 + local_48 * local_1c + param_2;
  if (unaff_EDI == 0) {
    local_40 = local_38;
    local_3c = fVar2;
    local_30 = local_28;
    local_2c = local_24;
    if (param_9 == 0) goto LAB_00526909;
    local_40 = fVar1;
    local_3c = local_34;
    local_30 = fVar3;
    local_2c = param_1;
    local_34 = fVar2;
  }
  else {
    if (param_9 != 0) {
      local_40 = local_34;
      local_3c = fVar1;
      fVar1 = fVar2;
      local_34 = local_38;
      local_30 = param_1;
      local_2c = fVar3;
      fVar3 = local_24;
      param_1 = local_28;
      goto LAB_00526909;
    }
    local_40 = fVar2;
    local_3c = local_38;
    local_38 = local_34;
    local_30 = local_24;
    local_2c = local_28;
    local_28 = param_1;
    local_24 = fVar3;
    local_34 = fVar1;
  }
  fVar1 = local_38;
  fVar3 = local_28;
  param_1 = local_24;
LAB_00526909:
  local_24 = param_1;
  local_28 = fVar3;
  local_38 = fVar1;
  if ((param_10 != 0) && (DAT_00a37dd0 == 0)) {
    fVar1 = (float)_DAT_00804a60;
    local_30 = local_30 - fVar1;
    local_40 = local_40 - fVar1;
    local_2c = local_2c - fVar1;
    local_3c = local_3c - fVar1;
    local_24 = local_24 - fVar1;
    local_34 = local_34 - fVar1;
    local_28 = local_28 - fVar1;
    local_38 = local_38 - fVar1;
  }
  FUN_0051cd60(local_30,local_40,local_2c,local_3c,local_24,local_34,local_28,local_38,param_8,1);
  return;
}

