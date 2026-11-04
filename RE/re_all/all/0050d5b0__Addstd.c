
/* Library Function - Single Match
    public: void __thiscall std::ios_base::_Addstd(void)
   
   Library: Visual Studio 2003 Release */

void __thiscall std::ios_base::_Addstd(ios_base *this)

{
  ios_base *piVar1;
  
  FUN_0050d92b(2);
  *(undefined4 *)(this + 4) = 1;
  do {
    piVar1 = *(ios_base **)(*(int *)(this + 4) * 4 + 0xa200b4);
    if ((piVar1 == (ios_base *)0x0) || (piVar1 == this)) break;
    *(int *)(this + 4) = *(int *)(this + 4) + 1;
  } while (*(uint *)(this + 4) < 8);
  *(ios_base **)(*(int *)(this + 4) * 4 + 0xa200b4) = this;
  (&DAT_00a200dc)[*(int *)(this + 4)] = (&DAT_00a200dc)[*(int *)(this + 4)] + '\x01';
  FUN_0050d94e();
  return;
}

