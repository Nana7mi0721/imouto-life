
void FUN_00677290(int param_1)

{
  undefined1 local_8 [8];
  
  local_8[5] = 10;
  local_8[7] = 10;
  local_8[0] = 0x89;
  local_8[1] = 0x50;
  local_8[2] = 0x4e;
  local_8[3] = 0x47;
  local_8[4] = 0xd;
  local_8[6] = 0x1a;
  *(undefined4 *)(param_1 + 0x2c4) = 0x12;
  FUN_00671060(param_1,local_8 + *(byte *)(param_1 + 0x15d),8 - (uint)*(byte *)(param_1 + 0x15d));
  if (*(byte *)(param_1 + 0x15d) < 3) {
    *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 0x1000;
  }
  return;
}

