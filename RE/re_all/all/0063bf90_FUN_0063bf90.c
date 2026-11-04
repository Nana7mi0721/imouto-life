
void __thiscall FUN_0063bf90(int param_1,float *param_2)

{
  float *pfVar1;
  undefined4 uVar2;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  undefined1 local_90 [48];
  undefined1 local_60 [48];
  undefined1 local_30 [48];
  
  if ((*(byte *)(param_1 + 200) & 3) == 0) {
    *(float *)(param_1 + 0x44) = *param_2;
    *(float *)(param_1 + 0x48) = param_2[1];
    *(float *)(param_1 + 0x4c) = param_2[2];
    *(float *)(param_1 + 0x50) = param_2[3];
    *(float *)(param_1 + 0x54) = param_2[4];
    *(float *)(param_1 + 0x58) = param_2[5];
    *(float *)(param_1 + 0x5c) = param_2[6];
    *(float *)(param_1 + 0x60) = param_2[7];
    *(float *)(param_1 + 100) = param_2[8];
    *(float *)(param_1 + 0x68) = param_2[9];
    *(float *)(param_1 + 0x6c) = param_2[10];
    *(float *)(param_1 + 0x70) = param_2[0xb];
    *(float *)(param_1 + 0x74) = param_2[0xc];
    *(float *)(param_1 + 0x78) = param_2[0xd];
    *(float *)(param_1 + 0x7c) = param_2[0xe];
    *(float *)(param_1 + 0x80) = param_2[0xf];
  }
  else {
    *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x30);
    *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x34);
    *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0x3c);
    *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_1 + 0x40);
  }
  *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_1 + 0x130);
  *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 0x134);
  *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x138);
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x13c);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x140);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x144);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x148);
  pfVar1 = (float *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x14c);
  *pfVar1 = *param_2;
  *(float *)(param_1 + 8) = param_2[1];
  *(float *)(param_1 + 0xc) = param_2[2];
  *(float *)(param_1 + 0x10) = param_2[3];
  *(float *)(param_1 + 0x14) = param_2[4];
  *(float *)(param_1 + 0x18) = param_2[5];
  *(float *)(param_1 + 0x1c) = param_2[6];
  *(float *)(param_1 + 0x20) = param_2[7];
  *(float *)(param_1 + 0x24) = param_2[8];
  *(float *)(param_1 + 0x28) = param_2[9];
  *(float *)(param_1 + 0x2c) = param_2[10];
  *(float *)(param_1 + 0x30) = param_2[0xb];
  *(float *)(param_1 + 0x34) = param_2[0xc];
  *(float *)(param_1 + 0x38) = param_2[0xd];
  *(float *)(param_1 + 0x3c) = param_2[0xe];
  *(float *)(param_1 + 0x40) = param_2[0xf];
  FUN_005fcc50(pfVar1,param_1 + 0x14,param_1 + 0x24,param_1 + 8,param_1 + 0x18,param_1 + 0x28,
               param_1 + 0xc,param_1 + 0x1c,param_1 + 0x2c);
  local_9c = *(float *)(param_1 + 0x2c) * *(float *)(param_1 + 0x19c);
  local_ac = *(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x198);
  local_94 = *(float *)(param_1 + 0x24) * *(float *)(param_1 + 0x194);
  local_a4 = *(float *)(param_1 + 0x1c) * *(float *)(param_1 + 0x19c);
  local_98 = *(float *)(param_1 + 0x18) * *(float *)(param_1 + 0x198);
  local_b4 = *(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x194);
  local_b0 = *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0x19c);
  local_a8 = *(float *)(param_1 + 8) * *(float *)(param_1 + 0x198);
  local_a0 = *(float *)(param_1 + 0x194) * *pfVar1;
  FUN_005fcc50(&local_a0,&local_a8,&local_b0,&local_b4,&local_98,&local_a4,&local_94,&local_ac,
               &local_9c);
  uVar2 = FUN_005fc790(local_30,local_60,local_90);
  FUN_005fc5f0(uVar2);
  return;
}

