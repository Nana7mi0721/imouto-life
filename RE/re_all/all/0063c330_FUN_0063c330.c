
void __fastcall FUN_0063c330(int param_1)

{
  float10 fVar1;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  undefined1 local_90 [16];
  undefined1 local_80 [16];
  undefined1 local_70 [64];
  undefined1 local_30 [48];
  
  FUN_005fc650((float *)(param_1 + 4),param_1 + 0x14,param_1 + 0x24,param_1 + 8,param_1 + 0x18,
               param_1 + 0x28,param_1 + 0xc,param_1 + 0x1c,param_1 + 0x2c);
  local_d4 = *(float *)(param_1 + 0x2c) * *(float *)(param_1 + 0x19c);
  local_ac = *(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x198);
  local_cc = *(float *)(param_1 + 0x24) * *(float *)(param_1 + 0x194);
  local_94 = *(float *)(param_1 + 0x1c) * *(float *)(param_1 + 0x19c);
  local_c4 = *(float *)(param_1 + 0x18) * *(float *)(param_1 + 0x198);
  local_a4 = *(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x194);
  local_bc = *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0x19c);
  local_98 = *(float *)(param_1 + 8) * *(float *)(param_1 + 0x198);
  local_b4 = *(float *)(param_1 + 4) * *(float *)(param_1 + 0x194);
  FUN_005fc650(&local_b4,&local_98,&local_bc,&local_a4,&local_c4,&local_94,&local_cc,&local_ac,
               &local_d4);
  fVar1 = (float10)FUN_005fccf0(local_70);
  local_9c = (float)fVar1;
  fVar1 = (float10)FUN_005fccd0(local_70);
  local_d8 = (float)fVar1;
  fVar1 = (float10)FUN_005fccb0(local_70);
  local_d0 = (float)fVar1;
  fVar1 = (float10)FUN_005fccf0(local_80);
  local_c8 = (float)fVar1;
  fVar1 = (float10)FUN_005fccd0(local_80);
  local_c0 = (float)fVar1;
  fVar1 = (float10)FUN_005fccb0(local_80);
  local_b8 = (float)fVar1;
  fVar1 = (float10)FUN_005fccf0(local_90);
  local_b0 = (float)fVar1;
  fVar1 = (float10)FUN_005fccd0(local_90);
  local_a8 = (float)fVar1;
  fVar1 = (float10)FUN_005fccb0(local_90);
  local_a0 = (float)fVar1;
  FUN_005fcc50(&local_a0,&local_a8,&local_b0,&local_b8,&local_c0,&local_c8,&local_d0,&local_d8,
               &local_9c);
  FUN_005fc5f0(local_30);
  return;
}

