
void __thiscall FUN_0062aca0(int param_1,int param_2,int *param_3,undefined4 param_4,char param_5)

{
  char cVar1;
  undefined4 uVar2;
  float10 fVar3;
  float *pfVar4;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d4;
  float local_d0;
  float local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a0;
  float local_9c;
  float local_98;
  undefined1 local_90 [16];
  undefined1 local_80 [64];
  undefined1 local_40 [16];
  undefined1 local_30 [48];
  
  local_c4 = 0x3f800000;
  local_e8 = 0.0;
  FUN_005fc590(&local_d4,param_2 + 0x30,param_2 + 0x70);
  fVar3 = (float10)FUN_005fccf0(&local_d4);
  local_f0 = (float)fVar3;
  fVar3 = (float10)FUN_005fccd0(&local_d4);
  local_ec = (float)fVar3;
  fVar3 = (float10)FUN_005fccb0(&local_d4);
  local_f4 = (float)fVar3;
  FUN_005fc500(&local_f4,&local_ec,&local_f0);
  pfVar4 = &local_c0;
  uVar2 = FUN_00623c10(local_30,param_2);
  FUN_005fcd10(uVar2,pfVar4);
  cVar1 = FUN_0062b1a0(local_40,local_80,&local_e4,&local_e8,&local_c4,
                       *(undefined4 *)(param_1 + 0xc));
  if (cVar1 != '\0') {
    if (param_5 != '\0') {
      local_f4 = local_e4 * *(float *)(param_2 + 0x60) +
                 local_e0 * *(float *)(param_2 + 100) + local_dc * *(float *)(param_2 + 0x68);
      fVar3 = (float10)FUN_005fcc30(&local_e4);
      local_ec = (float)fVar3;
      fVar3 = (float10)FUN_005fcc30(&local_e4);
      local_f0 = (float)fVar3;
      FUN_005fc500(&local_f0,&local_ec,&local_f4);
      local_d4 = -local_b0;
      local_d0 = -local_ac;
      local_cc = -local_a8;
      local_a0 = local_b0 * local_e8;
      local_9c = local_ac * local_e8;
      local_c8 = 0;
      local_98 = local_a8 * local_e8;
      FUN_005fc8d0(&local_c0,local_80);
      local_f4 = local_b8 + local_98;
      local_ec = local_bc + local_9c;
      local_f0 = local_a0 + local_c0;
      FUN_005fc500(&local_f0,&local_ec,&local_f4);
      (**(code **)(*param_3 + 0xc))(&local_d4,local_90,local_e8);
      return;
    }
    FUN_005fc8d0(local_90,local_80);
    local_f4 = local_e4 * *(float *)(param_2 + 0x60) +
               local_e0 * *(float *)(param_2 + 100) + local_dc * *(float *)(param_2 + 0x68);
    local_ec = local_e4 * *(float *)(param_2 + 0x50) +
               local_e0 * *(float *)(param_2 + 0x54) + local_dc * *(float *)(param_2 + 0x58);
    fVar3 = (float10)FUN_005fcc30(&local_e4);
    local_f0 = (float)fVar3;
    FUN_005fc500(&local_f0,&local_ec,&local_f4);
    (**(code **)(*param_3 + 0xc))(&local_c0,local_90,local_e8);
  }
  return;
}

