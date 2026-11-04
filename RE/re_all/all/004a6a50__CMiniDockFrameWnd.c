
/* Library Function - Single Match
    public: virtual __thiscall CMiniDockFrameWnd::~CMiniDockFrameWnd(void)
   
   Library: Visual Studio 2003 Debug */

void __thiscall CMiniDockFrameWnd::~CMiniDockFrameWnd(CMiniDockFrameWnd *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007b0418;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_004dc3f0(this);
  local_8 = 0xffffffff;
  FUN_004788e0();
  ExceptionList = local_10;
  return;
}

