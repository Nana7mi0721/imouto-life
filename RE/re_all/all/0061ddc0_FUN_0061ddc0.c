
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0061ddc0(int *param_1,float *param_2,float *param_3,undefined4 param_4)

{
  int iVar1;
  float *local_98;
  float local_94;
  float local_90 [5];
  float local_7c;
  float local_78;
  float local_74;
  undefined4 uStack_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_10;
  float local_c;
  float local_8;
  
  local_94 = param_3[2] - param_2[2];
  local_98 = (float *)(param_3[1] - param_2[1]);
  local_6c = *param_3 - *param_2;
  FUN_005fc500(&local_6c,&local_98,&local_94);
  local_64 = local_74 * _DAT_007d589c;
  local_68 = local_78 * _DAT_007d589c;
  local_90[4] = local_7c * _DAT_007d589c;
  FUN_005fc500(local_90 + 4,&local_68,&local_64);
  local_90[4] = param_2[2] + param_3[2];
  local_68 = param_3[1] + param_2[1];
  local_64 = *param_2 + *param_3;
  FUN_005fc500(&local_64,&local_68,local_90 + 4);
  local_6c = local_74 * _DAT_007d589c;
  local_94 = local_78 * _DAT_007d589c;
  local_98 = (float *)(local_7c * _DAT_007d589c);
  FUN_005fc500(&local_98,&local_94,&local_6c);
  local_90[0] = 1.0;
  local_90[1] = 1.0;
  local_90[2] = 1.0;
  local_90[3] = 0.0;
  local_94 = 0.0;
  local_34 = 0;
  local_98 = local_90;
  local_24 = 0;
  do {
    iVar1 = 0;
    do {
      local_54 = 0;
      local_40 = local_90[0] * local_20;
      local_3c = local_90[1] * local_1c;
      local_38 = local_90[2] * local_18;
      local_60 = local_90[0] * local_20 + local_10;
      local_5c = local_90[1] * local_1c + local_c;
      local_58 = local_90[2] * local_18 + local_8;
      local_90[iVar1 % 3] = local_90[iVar1 % 3] * _DAT_007d5340;
      local_30 = local_90[0] * local_20;
      local_2c = local_90[1] * local_1c;
      local_28 = local_90[2] * local_18;
      local_50 = local_30 + local_10;
      local_4c = local_2c + local_c;
      local_44 = local_24;
      local_48 = local_28 + local_8;
      (**(code **)(*param_1 + 4))(&local_60,&local_50,param_4);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 3);
    local_7c = -1.0;
    uStack_70 = 0;
    local_90[0] = -1.0;
    local_78 = -1.0;
    local_90[3] = 0.0;
    local_74 = -1.0;
    local_90[1] = -1.0;
    local_90[2] = -1.0;
    if ((int)local_94 < 3) {
      *local_98 = *local_98 * _DAT_007d5340;
    }
    local_94 = (float)((int)local_94 + 1);
    local_98 = local_98 + 1;
  } while ((int)local_94 < 4);
  return;
}

