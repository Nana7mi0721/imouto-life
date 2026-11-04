
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0063b590(int param_1,float param_2,int param_3)

{
  float *pfVar1;
  float10 fVar2;
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
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  undefined1 local_48 [8];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined1 local_10 [16];
  
  local_78 = param_2 * *(float *)(param_1 + 0x138);
  pfVar1 = (float *)(param_1 + 0x140);
  local_74 = param_2 * *(float *)(param_1 + 0x134);
  local_70 = param_2 * *(float *)(param_1 + 0x130);
  FUN_005fc500(&local_70,&local_74,&local_78);
  local_6c = local_18 + *(float *)(param_1 + 0x3c);
  local_68 = local_1c + *(float *)(param_1 + 0x38);
  local_64 = local_20 + *(float *)(param_1 + 0x34);
  FUN_005fc500(&local_64,&local_68,&local_6c);
  *(undefined4 *)(param_3 + 0x30) = local_40;
  *(undefined4 *)(param_3 + 0x34) = local_3c;
  *(undefined4 *)(param_3 + 0x38) = local_38;
  *(undefined4 *)(param_3 + 0x3c) = local_34;
  fVar2 = (float10)FUN_005fcc30(pfVar1);
  local_78 = (float)SQRT(fVar2);
  if ((float10)_DAT_007d97a0 < SQRT(fVar2) * (float10)param_2) {
    local_78 = _DAT_007d97a0 / param_2;
  }
  if (_DAT_007d652c <= local_78) {
    fVar2 = (float10)fsin((float10)local_78 * (float10)param_2 * (float10)_DAT_007d589c);
    fVar2 = fVar2 / (float10)local_78;
    local_64 = (float)(fVar2 * (float10)*(float *)(param_1 + 0x148));
    local_68 = (float)(fVar2 * (float10)*(float *)(param_1 + 0x144));
    local_6c = (float)(fVar2 * (float10)*pfVar1);
    FUN_005fc500(&local_6c,&local_68,&local_64);
  }
  else {
    local_6c = param_2 * _DAT_007d589c -
               param_2 * param_2 * param_2 * local_78 * local_78 * _DAT_0080480c;
    local_64 = local_6c * *(float *)(param_1 + 0x148);
    local_68 = local_6c * *(float *)(param_1 + 0x144);
    local_6c = local_6c * *pfVar1;
    FUN_005fc500(&local_6c,&local_68,&local_64);
  }
  fVar2 = (float10)fcos((float10)local_78 * (float10)param_2 * (float10)_DAT_007d589c);
  local_64 = (float)fVar2;
  FUN_0061a080(local_50,local_4c,local_48,&local_64);
  FUN_0061abb0(&local_40);
  local_30 = local_40;
  local_2c = local_3c;
  local_28 = local_38;
  local_24 = local_34;
  FUN_0061a150(&local_60,local_10,&local_30);
  fVar2 = (float10)FUN_0061a2f0(&local_60);
  fVar2 = (float10)_DAT_00804108 / SQRT(fVar2);
  local_60 = (float)((float10)local_60 * fVar2);
  local_5c = (float)((float10)local_5c * fVar2);
  local_58 = (float)((float10)local_58 * fVar2);
  local_54 = (float)((float10)local_54 * fVar2);
  FUN_0061a350(&local_60);
  return;
}

