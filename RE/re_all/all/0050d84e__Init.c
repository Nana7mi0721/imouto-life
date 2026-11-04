
/* Library Function - Single Match
    protected: void __thiscall std::ios_base::_Init(void)
   
   Library: Visual Studio 2003 Release */

void __thiscall std::ios_base::_Init(ios_base *this)

{
  locale *this_00;
  undefined4 uVar1;
  
  this_00 = operator_new(4);
  if (this_00 == (locale *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = locale::locale(this_00);
  }
  *(undefined4 *)(this + 0x24) = uVar1;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0x201;
  *(undefined4 *)(this + 0x14) = 6;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  clear(this,0,false);
  return;
}

