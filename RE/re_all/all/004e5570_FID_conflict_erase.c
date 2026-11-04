
/* Library Function - Multiple Matches With Different Base Names
    public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __thiscall std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::erase(unsigned
   int,unsigned int)
    public: class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> > & __thiscall std::basic_string<wchar_t,struct
   std::char_traits<wchar_t>,class std::allocator<wchar_t> >::erase(unsigned int,unsigned int)
   
   Library: Visual Studio 2003 Debug */

basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_> * __thiscall
FID_conflict_erase(void *this,uint param_1,uint param_2)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  int iVar3;
  
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_0050d50e();
  }
  if (*(int *)((int)this + 0x14) - param_1 < param_2) {
    param_2 = *(int *)((int)this + 0x14) - param_1;
  }
  if (param_2 != 0) {
    iVar3 = (*(int *)((int)this + 0x14) - param_1) - param_2;
    pwVar1 = FID_conflict__Myptr(this);
    pwVar1 = pwVar1 + param_1 + param_2;
    pwVar2 = FID_conflict__Myptr(this);
    move(pwVar2 + param_1,pwVar1,iVar3);
    FID_conflict__Eos(this,*(int *)((int)this + 0x14) - param_2);
  }
  return this;
}

