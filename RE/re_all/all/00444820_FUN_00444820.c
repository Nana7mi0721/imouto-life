
void FUN_00444820(int param_1,int param_2)

{
  int iVar1;
  int local_30;
  int local_2c;
  int local_28;
  int local_20;
  int local_1c;
  int local_18;
  
  iVar1 = FUN_0047a490();
  local_20 = iVar1 * DAT_0084b264 * 2 * 2 + *DAT_00a16718 * -4;
  iVar1 = FUN_0047a4b0();
  local_30 = iVar1 * DAT_0084b264 * 2 * 2 + *DAT_00a1671c * -4;
  if (DAT_00a180f4 == '\0') {
    if (DAT_0084b264 * 2 * param_1 + (*DAT_00a16718 - DAT_0084b264) * -2 < local_20) {
      local_18 = DAT_0084b264 * 2 * param_1 + (*DAT_00a16718 - DAT_0084b264) * -2;
    }
    else {
      local_18 = local_20;
    }
    if (local_18 < 0) {
      local_1c = 0;
    }
    else {
      if (DAT_0084b264 * 2 * param_1 + (*DAT_00a16718 - DAT_0084b264) * -2 < local_20) {
        local_20 = DAT_0084b264 * 2 * param_1 + (*DAT_00a16718 - DAT_0084b264) * -2;
      }
      local_1c = local_20;
    }
    DAT_00a17ebc = local_1c;
  }
  else {
    DAT_00a17ebc = DAT_0084b264 * 2 * param_1 + (*DAT_00a16718 - DAT_0084b264) * -2;
  }
  if (DAT_00a180f5 == '\0') {
    if (DAT_0084b264 * 2 * param_2 + (*DAT_00a1671c - DAT_0084b264) * -2 < local_30) {
      local_28 = DAT_0084b264 * 2 * param_2 + (*DAT_00a1671c - DAT_0084b264) * -2;
    }
    else {
      local_28 = local_30;
    }
    if (local_28 < 0) {
      local_2c = 0;
    }
    else {
      if (DAT_0084b264 * 2 * param_2 + (*DAT_00a1671c - DAT_0084b264) * -2 < local_30) {
        local_30 = DAT_0084b264 * 2 * param_2 + (*DAT_00a1671c - DAT_0084b264) * -2;
      }
      local_2c = local_30;
    }
    DAT_00a17ec0 = local_2c;
  }
  else {
    DAT_00a17ec0 = DAT_0084b264 * 2 * param_2 + (*DAT_00a1671c - DAT_0084b264) * -2;
  }
  return;
}

