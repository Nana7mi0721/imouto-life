
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _localtime
   
   Library: Visual Studio 2003 Release */

tm * __cdecl _localtime(time_t *_Time)

{
  time_t *_Time_00;
  tm *ptVar1;
  int iVar2;
  
  _Time_00 = _Time;
  if ((int)*_Time < 0) {
    return (tm *)0x0;
  }
  ___tzset();
  iVar2 = (int)*_Time_00;
  if ((0x3f480 < iVar2) && (iVar2 < 0x7ffc0b7f)) {
    _Time = (time_t *)(iVar2 - _DAT_0084be70);
    ptVar1 = _gmtime((time_t *)&_Time);
    if (DAT_0084be74 == 0) {
      return ptVar1;
    }
    iVar2 = __isindst(ptVar1);
    if (iVar2 == 0) {
      return ptVar1;
    }
    _Time = (time_t *)((int)_Time - DAT_0084be78);
    ptVar1 = _gmtime((time_t *)&_Time);
    ptVar1->tm_isdst = 1;
    return ptVar1;
  }
  ptVar1 = _gmtime(_Time_00);
  if ((DAT_0084be74 == 0) || (iVar2 = __isindst(ptVar1), iVar2 == 0)) {
    _Time = (time_t *)(ptVar1->tm_sec - _DAT_0084be70);
  }
  else {
    _Time = (time_t *)((ptVar1->tm_sec - DAT_0084be78) - _DAT_0084be70);
    ptVar1->tm_isdst = 1;
  }
  iVar2 = (int)_Time % 0x3c;
  ptVar1->tm_sec = iVar2;
  if (iVar2 < 0) {
    ptVar1->tm_sec = iVar2 + 0x3c;
    _Time = (time_t *)((int)_Time + -0x3c);
  }
  _Time = (time_t *)((int)_Time / 0x3c + ptVar1->tm_min);
  iVar2 = (int)_Time % 0x3c;
  ptVar1->tm_min = iVar2;
  if (iVar2 < 0) {
    ptVar1->tm_min = iVar2 + 0x3c;
    _Time = (time_t *)((int)_Time + -0x3c);
  }
  _Time = (time_t *)((int)_Time / 0x3c + ptVar1->tm_hour);
  iVar2 = (int)_Time % 0x18;
  ptVar1->tm_hour = iVar2;
  if (iVar2 < 0) {
    ptVar1->tm_hour = iVar2 + 0x18;
    _Time = _Time + -3;
  }
  iVar2 = (int)_Time / 0x18;
  if (iVar2 < 1) {
    if (-1 < iVar2) {
      return ptVar1;
    }
    ptVar1->tm_wday = (ptVar1->tm_wday + 7 + iVar2) % 7;
    ptVar1->tm_mday = ptVar1->tm_mday + iVar2;
    if (ptVar1->tm_mday < 1) {
      ptVar1->tm_year = ptVar1->tm_year + -1;
      ptVar1->tm_mday = ptVar1->tm_mday + 0x1f;
      ptVar1->tm_yday = 0x16c;
      ptVar1->tm_mon = 0xb;
      return ptVar1;
    }
  }
  else {
    ptVar1->tm_wday = (ptVar1->tm_wday + iVar2) % 7;
    ptVar1->tm_mday = ptVar1->tm_mday + iVar2;
  }
  ptVar1->tm_yday = ptVar1->tm_yday + iVar2;
  return ptVar1;
}

