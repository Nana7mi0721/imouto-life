
/* Library Function - Single Match
    public: virtual __thiscall CBitmapButton::~CBitmapButton(void)
   
   Library: Visual Studio 2003 Debug */

void __thiscall CBitmapButton::~CBitmapButton(CBitmapButton *this)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007af749;
  local_10 = ExceptionList;
  local_8 = 3;
  ExceptionList = &local_10;
  FUN_004ce950(this);
  local_8._0_1_ = 2;
  FUN_004ce950();
  local_8._0_1_ = 1;
  FUN_004ce780();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_004cc250();
  local_8 = 0xffffffff;
  FUN_004ce950();
  ExceptionList = local_10;
  return;
}

