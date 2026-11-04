
/* Library Function - Single Match
    public: long __thiscall ATL::CComCriticalSection::Init(void)
   
   Library: Visual Studio 2003 Debug */

long __thiscall ATL::CComCriticalSection::Init(CComCriticalSection *this)

{
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_007d2290;
  puStack_10 = &LAB_004ffb7c;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  InitializeCriticalSection((LPCRITICAL_SECTION)this);
  ExceptionList = local_14;
  return 0;
}

