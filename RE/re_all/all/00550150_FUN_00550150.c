
undefined4 FUN_00550150(uint *param_1)

{
  _SYSTEMTIME local_10;
  
  GetLocalTime(&local_10);
  *param_1 = (uint)local_10.wYear;
  param_1[1] = (uint)local_10.wMonth;
  param_1[2] = (uint)local_10.wDay;
  param_1[3] = (uint)local_10.wHour;
  param_1[4] = (uint)local_10.wMinute;
  param_1[5] = (uint)local_10.wSecond;
  return 0;
}

