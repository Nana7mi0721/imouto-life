
/* Library Function - Multiple Matches With Different Base Names
    public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __thiscall std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::assign(class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const &,unsigned int,unsigned int)
    public: class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> > & __thiscall std::basic_string<wchar_t,struct
   std::char_traits<wchar_t>,class std::allocator<wchar_t> >::assign(class
   std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class std::allocator<wchar_t> > const
   &,unsigned int,unsigned int)
   
   Library: Visual Studio 2003 Debug */

basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_> * __thiscall
FID_conflict_assign(void *this,
                   basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
                   *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  uint local_8;
  
  uVar2 = FUN_004e5650();
  if (uVar2 < param_2) {
    FUN_0050d50e();
  }
  iVar3 = FUN_004e5650();
  local_8 = iVar3 - param_2;
  if (param_3 < local_8) {
    local_8 = param_3;
  }
  if (this == param_1) {
    FID_conflict_erase(this,param_2 + local_8,DAT_007d0624);
    FID_conflict_erase(this,0,param_2);
  }
  else {
    bVar1 = FID_conflict__Grow(this,local_8,false);
    if (bVar1) {
      uVar2 = local_8;
      pwVar4 = FID_conflict__Myptr(param_1);
      pwVar4 = pwVar4 + param_2;
      pwVar5 = FID_conflict__Myptr(this);
      copy(pwVar5,pwVar4,uVar2);
      FID_conflict__Eos(this,local_8);
    }
  }
  return this;
}

