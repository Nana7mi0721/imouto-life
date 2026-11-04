
/* Library Function - Multiple Matches With Different Base Names
    protected: void __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::_Tidy(bool,unsigned int)
    protected: void __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::_Tidy(bool,unsigned int)
   
   Library: Visual Studio 2003 Debug */

void __thiscall FID_conflict__Tidy(void *this,bool param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_1) && (7 < *(uint *)((int)this + 0x18))) {
    uVar1 = *(undefined4 *)((int)this + 4);
    if (param_2 != 0) {
      copy((int)this + 4,uVar1,param_2);
    }
    deallocate(uVar1,*(int *)((int)this + 0x18) + 1);
  }
  *(undefined4 *)((int)this + 0x18) = 7;
  FID_conflict__Eos(this,param_2);
  return;
}

