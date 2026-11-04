
undefined4 FUN_0050f410(int param_1,int param_2)

{
  int iVar1;
  int local_24;
  int local_20;
  int local_1c;
  double local_18;
  double local_10;
  double local_8;
  
  if (DAT_00a20c40 == 0) {
    iVar1 = FUN_00517340(param_1,param_2,&local_1c,&local_20);
    if (-1 < iVar1) {
      param_1 = local_1c;
      param_2 = local_20;
    }
  }
  else {
    FUN_005167a0(&local_24);
    FUN_0050e8d0(&local_18,&local_10);
    local_24 = (int)ROUND((double)local_24 * local_18);
    local_20 = (int)ROUND((double)local_20 * local_10);
    param_1 = (int)ROUND((double)param_1 * local_18);
    local_8 = (double)param_2 * local_10;
    local_1c = (int)ROUND(local_8);
    if (param_1 < 0) {
      param_1 = 0;
    }
    else if (local_24 < param_1) {
      param_1 = local_24;
    }
    if (local_1c < 0) {
      param_2 = 0;
    }
    else {
      param_2 = local_1c;
      if (local_20 < local_1c) {
        param_2 = local_20;
      }
    }
    if (DAT_00a20c40 != 0) {
      param_1 = param_1 + DAT_00a20c30;
      param_2 = param_2 + DAT_00a20c34;
      if (((DAT_00a2d804 != 0) && (DAT_00a2d7b0 == 0)) && (DAT_00a2d7bc == 0)) {
        SetCursorPos(param_1 + ((DAT_00a2d810 - DAT_00a2d808) - local_24) / 2,
                     param_2 + ((DAT_00a2d814 - DAT_00a2d80c) - local_20) / 2);
        return 0;
      }
    }
  }
  SetCursorPos(param_1,param_2);
  return 0;
}

