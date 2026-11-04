
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004c2d50(int param_1)

{
  double local_10;
  
  *(undefined8 *)(param_1 + 0x90) = *(undefined8 *)(param_1 + 0x88);
  if ((*(char *)(param_1 + 0xe2) == '\0') && (*(int *)(param_1 + 0xe8) < 1)) {
    if (((double)DAT_0084b244 * *(double *)(param_1 + 0x80)) / _DAT_00829888 +
        *(double *)(param_1 + 0x88) <= _DAT_007d1ea8) {
      local_10 = ((double)DAT_0084b244 * *(double *)(param_1 + 0x80)) / _DAT_00829888 +
                 *(double *)(param_1 + 0x88);
    }
    else {
      local_10 = _DAT_007d1ea8;
    }
    *(double *)(param_1 + 0x88) = local_10;
  }
  if (0 < *(int *)(param_1 + 0xe8)) {
    *(int *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) - DAT_0084b244;
  }
  if ((*(char *)(param_1 + 0xe1) != '\0') && (DAT_00a14670 != '\0')) {
    *(undefined1 *)(param_1 + 0xe2) = 0;
  }
  return;
}

