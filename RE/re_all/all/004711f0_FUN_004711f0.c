
void __thiscall
FUN_004711f0(byte *param_1,byte param_2,byte param_3,byte param_4,byte param_5,byte param_6,
            byte param_7,byte param_8,byte param_9)

{
  uint local_18;
  byte local_11;
  uint local_10;
  byte local_9;
  uint local_8;
  
  local_8 = (uint)param_2 + (uint)param_3 * 2 + (uint)param_4 * 4 + (uint)param_5 * 8 +
            (uint)param_6 * 0x10 + (uint)param_7 * 0x20 + (uint)param_8 * 0x40 +
            (uint)param_9 * 0x80;
  if (local_8 == *param_1) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    if (0xef < *(int *)(param_1 + 4)) {
      local_9 = param_1[4];
      FUN_004cd800(&local_9);
      local_10 = (uint)*param_1;
      FUN_004ce160(&local_10);
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = 0;
      param_1[7] = 0;
    }
  }
  else {
    if (*(int *)(param_1 + 4) != 0) {
      local_11 = param_1[4];
      FUN_004cd800(&local_11);
      local_18 = (uint)*param_1;
      FUN_004ce160(&local_18);
    }
    *param_1 = (byte)local_8;
    param_1[4] = 1;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
  }
  return;
}

