
/* Library Function - Multiple Matches With Different Base Names
    public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __thiscall std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::assign(unsigned short
   const *,unsigned int)
    public: class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> > & __thiscall std::basic_string<wchar_t,struct
   std::char_traits<wchar_t>,class std::allocator<wchar_t> >::assign(wchar_t const *,unsigned int)
   
   Library: Visual Studio 2003 Debug */

basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
* __thiscall FID_conflict_assign(void *this,ushort *param_1,uint param_2)

{
  bool bVar1;
  wchar_t *pwVar2;
  uint uVar3;
  
  bVar1 = FID_conflict__Inside(this,param_1);
  if (bVar1) {
    pwVar2 = FID_conflict__Myptr(this);
    this = FID_conflict_assign(this,this,(int)param_1 - (int)pwVar2 >> 1,param_2);
  }
  else {
    bVar1 = FID_conflict__Grow(this,param_2,false);
    if (bVar1) {
      uVar3 = param_2;
      pwVar2 = FID_conflict__Myptr(this);
      copy(pwVar2,param_1,uVar3);
      FID_conflict__Eos(this,param_2);
    }
  }
  return this;
}

