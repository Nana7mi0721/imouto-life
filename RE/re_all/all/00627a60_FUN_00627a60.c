
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00627a60(int param_1,int param_2,int param_3,int param_4,undefined4 *param_5)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float local_18c;
  float local_188;
  float local_184;
  float local_180;
  undefined **local_17c;
  float local_178;
  float local_174;
  float local_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  float local_158;
  char local_154;
  int local_150;
  undefined4 local_14c;
  undefined4 local_148;
  float local_144;
  float local_140;
  float local_13c;
  float local_134;
  float local_130;
  float local_12c;
  float local_124;
  float local_120;
  float local_11c;
  undefined1 local_114 [48];
  float local_e4;
  float local_e0;
  float local_dc;
  undefined4 local_d8;
  float local_a4;
  float local_a0;
  float local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined1 local_8c [140];
  
  FUN_0062bbc0();
  local_188 = *(float *)(param_2 + 0x38) - *(float *)(param_1 + 0x38);
  pfVar1 = (float *)(param_1 + 0x30);
  local_184 = *(float *)(param_2 + 0x34) - *(float *)(param_1 + 0x34);
  local_18c = *(float *)(param_2 + 0x30) - *pfVar1;
  FUN_005fc500(&local_18c,&local_184,&local_188);
  local_188 = *(float *)(param_4 + 0x38) - *(float *)(param_3 + 0x38);
  pfVar2 = (float *)(param_3 + 0x30);
  local_184 = *(float *)(param_4 + 0x34) - *(float *)(param_3 + 0x34);
  local_18c = *(float *)(param_4 + 0x30) - *pfVar2;
  FUN_005fc500(&local_18c,&local_184,&local_188);
  local_188 = local_11c - local_12c;
  local_184 = local_120 - local_130;
  local_18c = 0.0;
  local_180 = local_124 - local_134;
  FUN_005fc500(&local_180,&local_184,&local_188);
  local_188 = 0.0;
  local_184 = 0.0;
  FUN_005f5190(local_8c,0x10,3,FUN_0061ddb0);
  FUN_005fc6b0();
  local_180 = 0.0;
  local_14c = 0;
  local_148 = 0;
  FUN_005fc530(&local_148,&local_14c,&local_180);
  local_158 = 1e+18;
  local_154 = '\0';
  local_17c = &PTR_LAB_008046c0;
  FUN_00621e40(*(undefined4 *)(local_150 + 8),*(undefined4 *)(local_150 + 0xc),
               *(undefined4 *)(local_150 + 4),0);
  FUN_0061ddb0();
  FUN_0061ddb0();
  local_94 = 0x5d5e0b6b;
  local_90 = 0;
  FUN_005fc5f0(param_1);
  local_e4 = *pfVar1;
  local_e0 = *(float *)(param_1 + 0x34);
  local_dc = *(float *)(param_1 + 0x38);
  local_d8 = *(undefined4 *)(param_1 + 0x3c);
  FUN_005fc5f0(param_3);
  local_a4 = *pfVar2;
  local_a0 = *(float *)(param_3 + 0x34);
  local_9c = *(float *)(param_3 + 0x38);
  local_98 = *(undefined4 *)(param_3 + 0x3c);
  FUN_00621f30(local_114,&local_17c,0,0);
  if (local_154 != '\0') {
    if (_DAT_007d652c < local_158) {
      do {
        local_184 = (float)((int)local_184 + 1);
        if (0x20 < (int)local_184) {
          return 0;
        }
        local_18c = local_18c -
                    local_158 /
                    (local_178 * local_144 + local_174 * local_140 + local_170 * local_13c);
        if (_DAT_00804108 < local_18c) {
          return 0;
        }
        if (local_18c < _DAT_007d5344) {
          return 0;
        }
        if (local_18c <= local_188) {
          return 0;
        }
        local_188 = local_18c;
        (**(code **)*param_5)(local_18c);
        fVar3 = _DAT_00804108 - local_18c;
        local_e4 = fVar3 * *pfVar1 + local_18c * *(float *)(param_2 + 0x30);
        local_e0 = local_18c * *(float *)(param_2 + 0x34) + fVar3 * *(float *)(param_1 + 0x34);
        local_dc = local_18c * *(float *)(param_2 + 0x38) + fVar3 * *(float *)(param_1 + 0x38);
        local_a4 = local_18c * *(float *)(param_4 + 0x30) + fVar3 * *pfVar2;
        local_a0 = local_18c * *(float *)(param_4 + 0x34) + fVar3 * *(float *)(param_3 + 0x34);
        local_9c = local_18c * *(float *)(param_4 + 0x38) + fVar3 * *(float *)(param_3 + 0x38);
        FUN_00621f30(local_114,&local_17c,0,0);
        if (local_154 == '\0') {
          return 0;
        }
        if (local_158 < _DAT_007d5344) {
          param_5[0x29] = local_18c;
          param_5[0x21] = local_178;
          param_5[0x22] = local_174;
          param_5[0x23] = local_170;
          param_5[0x24] = uStack_16c;
          param_5[0x25] = uStack_168;
          param_5[0x26] = uStack_164;
          param_5[0x27] = uStack_160;
          param_5[0x28] = uStack_15c;
          return 1;
        }
      } while (_DAT_007d652c < local_158);
    }
    if (local_178 * local_144 + local_174 * local_140 + local_170 * local_13c <
        -(float)param_5[0x2b]) {
      param_5[0x29] = local_18c;
      param_5[0x21] = local_178;
      param_5[0x22] = local_174;
      param_5[0x23] = local_170;
      param_5[0x24] = uStack_16c;
      param_5[0x25] = uStack_168;
      param_5[0x26] = uStack_164;
      param_5[0x27] = uStack_160;
      param_5[0x28] = uStack_15c;
      return 1;
    }
  }
  return 0;
}

