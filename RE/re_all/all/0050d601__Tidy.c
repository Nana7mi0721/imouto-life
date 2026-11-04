
/* Library Function - Single Match
    private: void __thiscall std::ios_base::_Tidy(void)
   
   Library: Visual Studio 2003 Release */

void __thiscall std::ios_base::_Tidy(ios_base *this)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  _Callfns(this,0);
  puVar2 = *(undefined4 **)(this + 0x1c);
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    _free(puVar2);
    puVar2 = puVar1;
  }
  *(undefined4 *)(this + 0x1c) = 0;
  puVar2 = *(undefined4 **)(this + 0x20);
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    _free(puVar2);
    puVar2 = puVar1;
  }
  *(undefined4 *)(this + 0x20) = 0;
  return;
}

