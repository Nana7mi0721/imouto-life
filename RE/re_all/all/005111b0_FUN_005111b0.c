
undefined4 FUN_005111b0(undefined4 *param_1)

{
  int iVar1;
  tagRECT local_10;
  
  if (DAT_00a2d288 == 0) {
    iVar1 = 0;
  }
  else {
    GetWindowRect(DAT_00a2d28c,&local_10);
    iVar1 = local_10.bottom - local_10.top;
  }
  *param_1 = DAT_00a20c30;
  param_1[1] = DAT_00a20c34;
  param_1[2] = DAT_00a20c38;
  param_1[3] = DAT_00a20c3c;
  param_1[1] = param_1[1] + iVar1;
  param_1[3] = param_1[3] + iVar1;
  return 0;
}

