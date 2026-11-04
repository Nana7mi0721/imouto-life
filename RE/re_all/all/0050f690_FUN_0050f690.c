
void FUN_0050f690(FILETIME *param_1,uint *param_2)

{
  _FILETIME local_18;
  _SYSTEMTIME local_10;
  
  FileTimeToLocalFileTime(param_1,&local_18);
  FileTimeToSystemTime(&local_18,&local_10);
  *param_2 = (uint)local_10.wYear;
  param_2[1] = (uint)local_10.wMonth;
  param_2[2] = (uint)local_10.wDay;
  param_2[3] = (uint)local_10.wHour;
  param_2[4] = (uint)local_10.wMinute;
  param_2[5] = (uint)local_10.wSecond;
  return;
}

