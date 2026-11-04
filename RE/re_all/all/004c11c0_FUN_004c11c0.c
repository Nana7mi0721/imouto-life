
undefined4 * __thiscall FUN_004c11c0(undefined4 *param_1,undefined4 *param_2)

{
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  *param_1 = *param_2;
  FUN_004cb840(param_2 + 1);
  for (local_8 = 0; local_8 < 0xf; local_8 = local_8 + 1) {
    FUN_004cb840(param_2 + local_8 * 7 + 8);
  }
  param_1[0x71] = param_2[0x71];
  for (local_c = 0; local_c < 0xf; local_c = local_c + 1) {
    param_1[local_c + 0x72] = param_2[local_c + 0x72];
  }
  for (local_10 = 0; local_10 < 0xf; local_10 = local_10 + 1) {
    param_1[local_10 + 0x81] = param_2[local_10 + 0x81];
  }
  FUN_004cd5b0(param_2 + 0x90);
  for (local_14 = 0; local_14 < 0xf; local_14 = local_14 + 1) {
    *(undefined1 *)((int)param_1 + local_14 + 0x250) =
         *(undefined1 *)((int)param_2 + local_14 + 0x250);
  }
  param_1[0x98] = param_2[0x98];
  for (local_18 = 0; local_18 < 10000; local_18 = local_18 + 1) {
    param_1[local_18 + 0x99] = param_2[local_18 + 0x99];
  }
  FUN_004f09c0(param_2 + 0x27a9);
  param_1[0x27ad] = param_2[0x27ad];
  param_1[0x27ae] = param_2[0x27ae];
  return param_1;
}

