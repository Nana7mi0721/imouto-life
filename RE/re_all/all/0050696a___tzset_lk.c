
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __tzset_lk
   
   Library: Visual Studio 2003 Release */

void __tzset_lk(void)

{
  char cVar1;
  char cVar2;
  UINT CodePage;
  char *_Str1;
  int iVar3;
  size_t sVar4;
  long lVar5;
  DWORD DVar6;
  char *_Str;
  int local_20 [3];
  undefined1 local_14 [8];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_007d4010;
  uStack_c = 0x506976;
  __lock(7);
  CodePage = DAT_00a1fe10;
  local_8 = (undefined *)0x0;
  DAT_00a1fef4 = 0;
  DAT_0084bf14 = 0xffffffff;
  DAT_0084bf08 = 0xffffffff;
  _Str1 = (char *)__getenv_lk(&DAT_007d400c);
  if ((_Str1 == (char *)0x0) || (*_Str1 == '\0')) {
    if (DAT_00a1fef8 != (char *)0x0) {
      _free(DAT_00a1fef8);
      DAT_00a1fef8 = (char *)0x0;
    }
    DVar6 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_00a1fe48);
    if (DVar6 != 0xffffffff) {
      DAT_00a1fef4 = 1;
      _DAT_0084be70 = DAT_00a1fe48 * 0x3c;
      if (DAT_00a1fe8e != 0) {
        _DAT_0084be70 = _DAT_0084be70 + DAT_00a1fe9c * 0x3c;
      }
      if ((DAT_00a1fee2 == 0) || (DAT_00a1fef0 == 0)) {
        DAT_0084be74 = 0;
        DAT_0084be78 = 0;
      }
      else {
        DAT_0084be74 = 1;
        DAT_0084be78 = (DAT_00a1fef0 - DAT_00a1fe9c) * 0x3c;
      }
      iVar3 = WideCharToMultiByte(CodePage,0,(LPCWSTR)&DAT_00a1fe4c,-1,PTR_DAT_0084bf00,0x3f,
                                  (LPCSTR)0x0,local_20);
      if ((iVar3 == 0) || (local_20[0] != 0)) {
        *PTR_DAT_0084bf00 = 0;
      }
      else {
        PTR_DAT_0084bf00[0x3f] = 0;
      }
      iVar3 = WideCharToMultiByte(CodePage,0,(LPCWSTR)&DAT_00a1fea0,-1,PTR_DAT_0084bf04,0x3f,
                                  (LPCSTR)0x0,local_20);
      if ((iVar3 == 0) || (local_20[0] != 0)) {
        *PTR_DAT_0084bf04 = 0;
      }
      else {
        PTR_DAT_0084bf04[0x3f] = 0;
      }
    }
  }
  else {
    if (DAT_00a1fef8 != (char *)0x0) {
      iVar3 = _strcmp(_Str1,DAT_00a1fef8);
      if (iVar3 == 0) goto LAB_00506b6e;
      if (DAT_00a1fef8 != (char *)0x0) {
        _free(DAT_00a1fef8);
      }
    }
    sVar4 = _strlen(_Str1);
    DAT_00a1fef8 = _malloc(sVar4 + 1);
    if (DAT_00a1fef8 != (char *)0x0) {
      FUN_004fd700(DAT_00a1fef8,_Str1);
      local_8 = (undefined *)0xffffffff;
      FUN_00506b85();
      _strncpy(PTR_DAT_0084bf00,_Str1,3);
      PTR_DAT_0084bf00[3] = 0;
      _Str = _Str1 + 3;
      cVar1 = *_Str;
      if (cVar1 == '-') {
        _Str = _Str1 + 4;
      }
      lVar5 = _atol(_Str);
      _DAT_0084be70 = lVar5 * 0xe10;
      for (; (cVar2 = *_Str, cVar2 == '+' || (('/' < cVar2 && (cVar2 < ':')))); _Str = _Str + 1) {
      }
      if (*_Str == ':') {
        _Str = _Str + 1;
        lVar5 = _atol(_Str);
        _DAT_0084be70 = _DAT_0084be70 + lVar5 * 0x3c;
        for (; ('/' < *_Str && (*_Str < ':')); _Str = _Str + 1) {
        }
        if (*_Str == ':') {
          _Str = _Str + 1;
          lVar5 = _atol(_Str);
          _DAT_0084be70 = _DAT_0084be70 + lVar5;
          for (; ('/' < *_Str && (*_Str < ':')); _Str = _Str + 1) {
          }
        }
      }
      if (cVar1 == '-') {
        _DAT_0084be70 = -_DAT_0084be70;
      }
      DAT_0084be74 = (int)*_Str;
      if (DAT_0084be74 == 0) {
        *PTR_DAT_0084bf04 = 0;
        return;
      }
      _strncpy(PTR_DAT_0084bf04,_Str,3);
      PTR_DAT_0084bf04[3] = 0;
      return;
    }
  }
LAB_00506b6e:
  __local_unwind2(local_14,0xffffffff);
  return;
}

