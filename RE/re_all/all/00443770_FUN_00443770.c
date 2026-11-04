
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00443770(int param_1)

{
  short sVar1;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  if ((*(char *)(param_1 + 0xbf) == '\0') && (*(char *)(param_1 + 0x54) == '\0')) {
    sVar1 = **(short **)(&DAT_00a166f8 + *(short *)(param_1 + 0x5a) * 4);
  }
  else {
    sVar1 = **(short **)(&DAT_00a166dc + *(short *)(param_1 + 0x5a) * 4);
  }
  local_8 = sVar1 * DAT_0084b244;
  if (*(int *)(param_1 + 0x3c) < DAT_0084b264 * 2 * *(int *)(param_1 + 0x2c)) {
    if (*(int *)(param_1 + 0x3c) + local_8 < DAT_0084b264 * 2 * *(int *)(param_1 + 0x2c)) {
      local_10 = *(int *)(param_1 + 0x3c) + local_8;
    }
    else {
      local_10 = DAT_0084b264 * 2 * *(int *)(param_1 + 0x2c);
    }
    *(int *)(param_1 + 0x3c) = local_10;
  }
  if (DAT_0084b264 * 2 * *(int *)(param_1 + 0x28) < *(int *)(param_1 + 0x38)) {
    if (DAT_0084b264 * 2 * *(int *)(param_1 + 0x28) < *(int *)(param_1 + 0x38) - local_8) {
      local_14 = *(int *)(param_1 + 0x38) - local_8;
    }
    else {
      local_14 = DAT_0084b264 * 2 * *(int *)(param_1 + 0x28);
    }
    *(int *)(param_1 + 0x38) = local_14;
  }
  if (*(int *)(param_1 + 0x38) < DAT_0084b264 * 2 * *(int *)(param_1 + 0x28)) {
    if (*(int *)(param_1 + 0x38) + local_8 < DAT_0084b264 * 2 * *(int *)(param_1 + 0x28)) {
      local_18 = *(int *)(param_1 + 0x38) + local_8;
    }
    else {
      local_18 = DAT_0084b264 * 2 * *(int *)(param_1 + 0x28);
    }
    *(int *)(param_1 + 0x38) = local_18;
  }
  if (DAT_0084b264 * 2 * *(int *)(param_1 + 0x2c) < *(int *)(param_1 + 0x3c)) {
    if (DAT_0084b264 * 2 * *(int *)(param_1 + 0x2c) < *(int *)(param_1 + 0x3c) - local_8) {
      local_1c = *(int *)(param_1 + 0x3c) - local_8;
    }
    else {
      local_1c = DAT_0084b264 * 2 * *(int *)(param_1 + 0x2c);
    }
    *(int *)(param_1 + 0x3c) = local_1c;
  }
  if ((DAT_0084b264 * 2 * *(int *)(param_1 + 0x28) < *(int *)(param_1 + 0x38)) &&
     (DAT_0084b264 * 2 * *(int *)(param_1 + 0x2c) == *(int *)(param_1 + 0x3c))) {
    *(undefined1 *)(param_1 + 0xbb) = 0;
  }
  if ((DAT_0084b264 * 2 * *(int *)(param_1 + 0x28) == *(int *)(param_1 + 0x38)) &&
     (DAT_0084b264 * 2 * *(int *)(param_1 + 0x2c) == *(int *)(param_1 + 0x3c))) {
    *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + DAT_0084b244;
  }
  if (*(char *)(param_1 + 0xac) == '\0') {
    if (*(char *)(param_1 + 0xad) != '\0') {
      *(double *)(param_1 + 0x140) =
           (double)DAT_0084b244 * _DAT_007d0a70 + *(double *)(param_1 + 0x140);
    }
  }
  else {
    *(double *)(param_1 + 0x140) = (double)DAT_0084b244 + *(double *)(param_1 + 0x140);
  }
  return;
}

