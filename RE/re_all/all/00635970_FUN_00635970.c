
void __thiscall
FUN_00635970(int *param_1,float *param_2,float *param_3,float *param_4,undefined1 param_5,
            undefined1 param_6,float param_7,float param_8,undefined4 param_9,char param_10)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  float local_a8;
  float local_a4;
  int local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  undefined4 uStack_7c;
  float local_78;
  float local_74;
  float local_70;
  undefined4 uStack_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_44;
  float fStack_40;
  float fStack_3c;
  undefined4 uStack_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  undefined1 local_10 [16];
  
  local_9c = *param_3 * param_4[1] - param_3[1] * *param_4;
  local_a8 = param_3[2] * *param_4 - param_4[2] * *param_3;
  local_a4 = param_3[1] * param_4[2] - param_3[2] * param_4[1];
  FUN_005fc500(&local_a4,&local_a8,&local_9c);
  local_9c = param_8 - param_7;
  local_a0 = __ftol();
  if (local_a0 == 0) {
    local_a0 = 1;
  }
  fVar2 = (float10)fsin((float10)param_7);
  local_a4 = (float)fVar2;
  fVar2 = (float10)fcos((float10)param_7);
  local_a8 = (float)fVar2;
  FUN_0060fe40(&local_78,local_10,&param_6);
  local_60 = local_70 * local_a4;
  local_5c = local_74 * local_a4;
  local_a4 = local_78 * local_a4;
  FUN_005fc500(&local_a4,&local_5c,&local_60);
  FUN_0060fe40(&local_88,param_4,&param_5);
  local_68 = local_80 * local_a8;
  local_58 = local_84 * local_a8;
  local_a8 = local_88 * local_a8;
  FUN_005fc500(&local_a8,&local_58,&local_68);
  local_34 = local_18 + param_2[2];
  local_64 = local_1c + param_2[1];
  local_98 = local_20 + *param_2;
  FUN_005fc500(&local_98,&local_64,&local_34);
  local_8c = local_28 + local_4c;
  local_94 = local_2c + local_50;
  local_90 = local_30 + local_54;
  FUN_005fc500(&local_90,&local_94,&local_8c);
  if (param_10 != '\0') {
    (**(code **)(*param_1 + 4))(param_2,&local_44,param_9);
  }
  local_a8 = 1.4013e-45;
  if (0 < local_a0) {
    local_90 = (float)local_a0;
    do {
      fVar1 = local_a8;
      fVar2 = ((float10)(int)local_a8 * (float10)local_9c) / (float10)local_90 + (float10)param_7;
      fVar3 = (float10)fsin(fVar2);
      local_a8 = (float)fVar3;
      fVar2 = (float10)fcos(fVar2);
      local_a4 = (float)fVar2;
      FUN_0060fe40(&local_54,local_10,&param_6);
      local_78 = local_54 * local_a8;
      local_74 = local_50 * local_a8;
      uStack_6c = 0;
      local_70 = local_4c * local_a8;
      FUN_0060fe40(&local_30,param_4,&param_5);
      local_94 = local_28 * local_a4 + param_2[2];
      local_8c = local_2c * local_a4 + param_2[1];
      local_98 = local_30 * local_a4 + *param_2;
      FUN_005fc500(&local_98,&local_8c,&local_94);
      FUN_0060f480(&local_88,&local_20,&local_78);
      (**(code **)(*param_1 + 4))(&local_44,&local_88,param_9);
      local_44 = local_88;
      fStack_3c = local_80;
      local_a8 = (float)((int)fVar1 + 1);
      fStack_40 = local_84;
      uStack_38 = uStack_7c;
    } while ((int)local_a8 <= local_a0);
  }
  if (param_10 != '\0') {
    (**(code **)(*param_1 + 4))(param_2,&local_44,param_9);
  }
  return;
}

