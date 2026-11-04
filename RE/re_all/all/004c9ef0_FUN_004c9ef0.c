
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004c9ef0(int param_1)

{
  int local_10;
  int local_c;
  
  if ((DAT_00a18aa0 != -1) && (*(int *)(param_1 + 4) != -1)) {
    *(int *)(param_1 + 0x20) =
         *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x18) * 8 + DAT_00a18aa4 / DAT_0084b244;
    *(int *)(param_1 + 0x24) =
         *(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x1c) * 8 + DAT_00a18aa8 / DAT_0084b244;
    if (DAT_00a18b28 == 0) {
      local_c = 0;
    }
    else {
      local_c = (DAT_00a17ebc * -2) / DAT_00a18b28;
    }
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x20) + local_c + _DAT_00a180f8;
    if (DAT_00a18b28 == 0) {
      local_10 = 0;
    }
    else {
      local_10 = (DAT_00a17ec0 * -2) / DAT_00a18b28;
    }
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x24) + local_10 + _DAT_00a180fc;
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + *(int *)(param_1 + 0x18) * 8;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x1c) * 8;
    if (*(int *)(param_1 + 0x18) * 8 < *(int *)(param_1 + 0x28)) {
      *(int *)(param_1 + 0x20) =
           *(int *)(param_1 + 0x20) -
           (*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x28) % (*(int *)(param_1 + 0x18) << 3));
    }
    if (*(int *)(param_1 + 0x1c) * 8 < *(int *)(param_1 + 0x2c)) {
      *(int *)(param_1 + 0x24) =
           *(int *)(param_1 + 0x24) -
           (*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x2c) % (*(int *)(param_1 + 0x1c) << 3));
    }
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) % (*(int *)(param_1 + 0x18) << 3);
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) % (*(int *)(param_1 + 0x1c) << 3);
  }
  return;
}

