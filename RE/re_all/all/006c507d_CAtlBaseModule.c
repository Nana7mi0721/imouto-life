
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    public: __thiscall ATL::CAtlBaseModule::CAtlBaseModule(void)
   
   Library: Visual Studio 2003 Release */

CAtlBaseModule * __thiscall ATL::CAtlBaseModule::CAtlBaseModule(CAtlBaseModule *this)

{
  long lVar1;
  _OSVERSIONINFOA local_9c;
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  _ATL_BASE_MODULE70::_ATL_BASE_MODULE70((_ATL_BASE_MODULE70 *)this);
  *(undefined4 *)(this + 8) = 0x400000;
  *(undefined4 *)(this + 4) = 0x400000;
  *(undefined4 *)this = 0x3c;
  this[0xc] = (CAtlBaseModule)0x0;
  _memset(&local_9c,0,0x94);
  local_9c.dwOSVersionInfoSize = 0x94;
  GetVersionExA(&local_9c);
  if (local_9c.dwPlatformId == 2) {
    if (local_9c.dwMajorVersion < 5) goto LAB_006c50f7;
  }
  else if ((local_9c.dwPlatformId != 1) ||
          ((local_9c.dwMajorVersion < 5 &&
           ((local_9c.dwMajorVersion != 4 || (local_9c.dwMinorVersion == 0)))))) goto LAB_006c50f7;
  this[0xc] = (CAtlBaseModule)0x1;
LAB_006c50f7:
  *(undefined4 *)(this + 0x10) = 0x710;
  *(undefined **)(this + 0x14) = &DAT_00832668;
  lVar1 = CComCriticalSection::Init((CComCriticalSection *)(this + 0x18));
  if (lVar1 < 0) {
    DAT_00a192ac = 1;
  }
  return this;
}

