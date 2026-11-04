
undefined4 FUN_0050f210(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int *unaff_EBX;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  double local_18;
  tagRECT local_10;
  
  if (DAT_00a20c40 == 0) {
    iVar1 = FUN_00517290(param_1,param_2,&local_28,&local_24);
    if (iVar1 < 0) {
      if (unaff_EBX != (int *)0x0) {
        *unaff_EBX = param_1;
      }
      if (param_3 != (int *)0x0) {
        *param_3 = param_2;
        return 0;
      }
    }
    else {
      if (unaff_EBX != (int *)0x0) {
        *unaff_EBX = local_28;
      }
      if (param_3 != (int *)0x0) {
        *param_3 = local_24;
      }
    }
  }
  else {
    param_1 = param_1 - DAT_00a20c30;
    if (DAT_00a2d288 == 0) {
      iVar1 = 0;
    }
    else {
      GetWindowRect(DAT_00a2d28c,&local_10);
      iVar1 = local_10.bottom - local_10.top;
    }
    param_2 = param_2 - (DAT_00a20c34 + iVar1);
    FUN_0050e8d0(&local_18,&local_10);
    if (((DAT_00a2d804 != 0) && (DAT_00a2d7b0 == 0)) && (DAT_00a2d7bc == 0)) {
      FUN_005167a0(&local_1c,&local_20);
      iVar1 = FUN_0050e240((double)local_1c * local_18);
      param_1 = param_1 - ((DAT_00a2d810 - DAT_00a2d808) - iVar1) / 2;
      iVar1 = FUN_0050e240((double)local_20 * (double)local_10._0_8_);
      param_2 = param_2 - ((DAT_00a2d814 - DAT_00a2d80c) - iVar1) / 2;
    }
    if (unaff_EBX != (int *)0x0) {
      *unaff_EBX = (int)ROUND((double)param_1 / local_18);
    }
    if (param_3 != (int *)0x0) {
      *param_3 = (int)ROUND((double)param_2 / (double)local_10._0_8_);
      return 0;
    }
  }
  return 0;
}

