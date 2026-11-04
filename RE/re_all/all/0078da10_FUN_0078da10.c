
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0078da10(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  float10 fVar3;
  float local_200;
  float local_1fc;
  float local_1f8;
  undefined4 local_1f4;
  float local_1f0 [5];
  undefined1 local_1dc [4];
  float local_1d8;
  float local_1d4;
  float local_1d0;
  float local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined1 local_1b4 [48];
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined1 local_174 [48];
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined1 local_134 [16];
  undefined1 local_124 [16];
  undefined1 local_114 [48];
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined1 local_d4 [16];
  undefined **local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  float local_a4;
  undefined1 local_70 [64];
  undefined1 local_30 [32];
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_005f5190(local_1b4,0x10,3,FUN_0061ddb0);
  FUN_005f5190(local_174,0x10,3,FUN_0061ddb0);
  FUN_005fc5f0(param_3);
  local_184 = *(undefined4 *)(param_3 + 0x30);
  local_180 = *(undefined4 *)(param_3 + 0x34);
  local_17c = *(undefined4 *)(param_3 + 0x38);
  local_178 = *(undefined4 *)(param_3 + 0x3c);
  FUN_005fc5f0(param_4);
  local_1f0[0] = 1.0;
  local_144 = *(undefined4 *)(param_4 + 0x30);
  local_140 = *(undefined4 *)(param_4 + 0x34);
  local_13c = *(undefined4 *)(param_4 + 0x38);
  local_138 = *(undefined4 *)(param_4 + 0x3c);
  uVar1 = FUN_005fc590(&local_200,&local_144,&local_184);
  local_1d8 = _DAT_00804108 / local_1f0[0];
  FUN_0060fe40(local_124,uVar1,&local_1d8);
  FUN_00645df0(local_1b4,local_174,&local_1d4,local_1dc);
  uVar1 = FUN_0060fe40(local_124,&local_1d4,local_1dc,local_1f0);
  puVar2 = (undefined4 *)FUN_00619f50(&local_200,uVar1);
  local_1c4 = *puVar2;
  local_1c0 = puVar2[1];
  local_1bc = puVar2[2];
  local_1b8 = puVar2[3];
  local_1f0[1] = 0.0;
  local_1f0[2] = 0.0;
  local_1f0[3] = 0.0;
  local_1f0[4] = 0.0;
  FUN_005f5190(local_114,0x10,3,FUN_0061ddb0);
  FUN_005fc6b0();
  local_e4 = 0;
  local_e0 = 0;
  local_dc = 0;
  local_d8 = 0;
  FUN_0061abb0(&local_200);
  local_1d0 = local_1fc;
  local_1d4 = local_200;
  local_1cc = local_1f8;
  local_1c8 = local_1f4;
  FUN_0061a350(&local_1d4);
  FUN_006102f0(local_114,local_1f0 + 1,&local_1c4,0x3f800000,local_134,local_d4);
  local_c4 = &PTR_LAB_00837428;
  FUN_0061ce50(param_3);
  FUN_0061ce50(param_4);
  local_c = param_5;
  local_8 = param_6;
  local_4 = param_2;
  local_c4 = &PTR_LAB_00837430;
  local_10 = param_1;
  FUN_005fc590(local_1f0 + 1,local_30,local_70);
  FUN_00628a40(&local_200);
  if (local_200 == _DAT_007d5344) {
    local_c0 = _DAT_008048f0;
  }
  else {
    local_c0 = _DAT_00804108 / local_200;
  }
  if (local_1fc == _DAT_007d5344) {
    local_bc = _DAT_008048f0;
  }
  else {
    local_bc = _DAT_00804108 / local_1fc;
  }
  if (local_1f8 == _DAT_007d5344) {
    local_b8 = _DAT_008048f0;
  }
  else {
    local_b8 = _DAT_00804108 / local_1f8;
  }
  local_b0 = (uint)(local_c0 < (float)_DAT_007d0a60);
  local_ac = (uint)(local_bc < (float)_DAT_007d0a60);
  local_a8 = (uint)(local_b8 < (float)_DAT_007d0a60);
  fVar3 = (float10)FUN_005fcc30(local_1f0 + 1);
  local_a4 = (float)fVar3;
  (**(code **)(**(int **)(param_1 + 0x4c) + 0x14))
            (&local_184,&local_144,&local_c4,local_134,local_d4);
  return;
}

