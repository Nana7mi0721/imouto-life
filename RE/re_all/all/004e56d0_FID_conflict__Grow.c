
/* Library Function - Multiple Matches With Different Base Names
    protected: bool __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::_Grow(unsigned int,bool)
    protected: bool __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::_Grow(unsigned int,bool)
   
   Library: Visual Studio 2003 Debug */

bool __thiscall FID_conflict__Grow(void *this,uint param_1,bool param_2)

{
  uint uVar1;
  uint local_c;
  
  uVar1 = FID_conflict_max_size(this);
  if (uVar1 < param_1) {
    FUN_0050d54e();
  }
  if (*(uint *)((int)this + 0x18) < param_1) {
    FUN_004eacc0(param_1,*(undefined4 *)((int)this + 0x14));
  }
  else if ((param_2) && (param_1 < 8)) {
    if (param_1 < *(uint *)((int)this + 0x14)) {
      local_c = param_1;
    }
    else {
      local_c = *(uint *)((int)this + 0x14);
    }
    FID_conflict__Tidy(this,true,local_c);
  }
  else if (param_1 == 0) {
    FID_conflict__Eos(this,0);
  }
  return param_1 != 0;
}

